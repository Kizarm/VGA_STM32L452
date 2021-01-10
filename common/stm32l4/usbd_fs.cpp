/* This file is the part of the Lightweight USB device Stack for STM32 microcontrollers
 *
 * Copyright ©2016 Dmitry Filimonchuk <dmitrystu[at]gmail[dot]com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *   http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include "STM32L4x2.h"
#include "common.h"
#include "core_cm4.h"
#include "usb_bit.h"
#include "usbd.h"

#define USB_PMASIZE 0x400
#define USBD_SOF_DISABLED

#ifndef USB_PMASIZE
#warning PMA memory size is not defined. Use 1k by default
#define USB_PMASIZE 0x400
#endif

#define USB_EP_SWBUF_TX     USB_EP_DTOG_RX
#define USB_EP_SWBUF_RX     USB_EP_DTOG_TX

static inline void EP_TOGGLE_SET(volatile uint16_t * epr, uint16_t bits, uint16_t mask) {
  *(epr) = (*(epr) ^ (bits)) & (USB_EPREG_MASK | (mask));
}
static inline void EP_TX_STALL   (volatile uint16_t * epr) { EP_TOGGLE_SET((epr), USB_EP_TX_STALL,                   USB_EPTX_STAT);}
static inline void EP_RX_STALL   (volatile uint16_t * epr) { EP_TOGGLE_SET((epr), USB_EP_RX_STALL,                   USB_EPRX_STAT);}
static inline void EP_TX_UNSTALL (volatile uint16_t * epr) { EP_TOGGLE_SET((epr), USB_EP_TX_NAK,                     USB_EPTX_STAT | USB_EP_DTOG_TX);}
static inline void EP_RX_UNSTALL (volatile uint16_t * epr) { EP_TOGGLE_SET((epr), USB_EP_RX_VALID,                   USB_EPRX_STAT | USB_EP_DTOG_RX);}
static inline void EP_DTX_UNSTALL(volatile uint16_t * epr) { EP_TOGGLE_SET((epr), USB_EP_TX_VALID,                   USB_EPTX_STAT | USB_EP_DTOG_TX | USB_EP_SWBUF_TX);}
static inline void EP_DRX_UNSTALL(volatile uint16_t * epr) { EP_TOGGLE_SET((epr), USB_EP_RX_VALID | USB_EP_SWBUF_RX, USB_EPRX_STAT | USB_EP_DTOG_RX | USB_EP_SWBUF_RX);}
static inline void EP_TX_VALID   (volatile uint16_t * epr) { EP_TOGGLE_SET((epr), USB_EP_TX_VALID,                   USB_EPTX_STAT);}
static inline void EP_RX_VALID   (volatile uint16_t * epr) { EP_TOGGLE_SET((epr), USB_EP_RX_VALID,                   USB_EPRX_STAT);}

static inline uint32_t STATUS_VAL(const uint32_t x) {
  return USBD_HW_BC | x;
}

typedef struct {
  uint16_t    addr;
  uint16_t    cnt;
} pma_rec;

typedef union pma_table {
  struct {
    pma_rec     tx;
    pma_rec     rx;
  };
  struct {
    pma_rec     tx0;
    pma_rec     tx1;
  };
  struct {
    pma_rec     rx0;
    pma_rec     rx1;
  };
} pma_table;


/** \brief Helper function. Returns pointer to the buffer descriptor table.
 */
inline static pma_table * EPT (uint8_t ep) {
  return reinterpret_cast<pma_table*> ((ep & 0x07) * 8 + USB_PMAADDR);

}

/** \brief Helper function. Returns pointer to the endpoint control register.
 */
inline static volatile uint16_t * EPR (uint8_t ep) {
  return reinterpret_cast<uint16_t*> ((ep & 0x07) * 4 + USB_BASE);
}

static usbd_driver * usbd_driver_instance = 0;

usbd_driver::usbd_driver () {
  usbd_driver_instance = this;
}

/** \brief Helper function. Returns next available PMA buffer.
 *
 * \param sz uint16_t Requested buffer size.
 * \return uint16_t Buffer address for PMA table.
 * \note PMA buffers grown from top to bottom like stack.
 */
static uint16_t get_next_pma (uint16_t sz) {
  unsigned _result = USB_PMASIZE;
  for (int i = 0; i < 8; i++) {
    pma_table *tbl = EPT (i);
    if ( (tbl->rx.addr) && (tbl->rx.addr < _result)) _result = tbl->rx.addr;
    if ( (tbl->tx.addr) && (tbl->tx.addr < _result)) _result = tbl->tx.addr;
  }
  return (_result < (0x020u + sz)) ? 0u : (_result - sz);
}

uint32_t usbd_driver::getinfo (void) {
  if (!RCC.APB1ENR1.B.USBF) return STATUS_VAL (0);
  if (USB_FS.BCDR.B.DPPU)   return STATUS_VAL (USBD_HW_ENABLED | USBD_HW_SPEED_FS);
  return STATUS_VAL (USBD_HW_ENABLED);
}

void usbd_driver::ep_setstall (uint8_t ep, bool stall) {
  volatile uint16_t *reg = EPR (ep);
  /* ISOCHRONOUS endpoint can't be stalled or unstalled */
  if (USB_EP_ISOCHRONOUS == (*reg & USB_EP_T_FIELD)) return;
  /* If it's an IN endpoint */
  if (ep & 0x80) {
    /* DISABLED endpoint can't be stalled or unstalled */
    if (USB_EP_TX_DIS == (*reg & USB_EPTX_STAT)) return;
    if (stall) {
      EP_TX_STALL (reg);
    } else {
      /* if it's a doublebuffered endpoint */
      if ( (USB_EP_KIND | USB_EP_BULK) == (*reg & (USB_EP_T_FIELD | USB_EP_KIND))) {
        /* set endpoint to VALID and clear DTOG_TX & SWBUF_TX */
        EP_DTX_UNSTALL (reg);
      } else {
        /* set endpoint to NAKED and clear DTOG_TX */
        EP_TX_UNSTALL (reg);
      }
    }
  } else {
    if (USB_EP_RX_DIS == (*reg & USB_EPRX_STAT)) return;
    if (stall) {
      EP_RX_STALL (reg);
    } else {
      /* if it's a doublebuffered endpoint */
      if ( (USB_EP_KIND | USB_EP_BULK) == (*reg & (USB_EP_T_FIELD | USB_EP_KIND))) {
        /* set endpoint to VALID, clear DTOG_RX, set SWBUF_RX */
        EP_DRX_UNSTALL (reg);
      } else {
        /* set endpoint to VALID and clear DTOG_RX */
        EP_RX_UNSTALL (reg);
      }
    }
  }
}

bool usbd_driver::ep_isstalled (uint8_t ep) {
  if (ep & 0x80) {
    return (USB_EP_TX_STALL == (USB_EPTX_STAT & *EPR (ep)));
  } else {
    return (USB_EP_RX_STALL == (USB_EPRX_STAT & *EPR (ep)));
  }
}
static void delay_ticks (volatile uint32_t ticks) {
  while (--ticks);
}
void usbd_driver::enable (bool enable) {
  if (enable) {
    RCC.APB1ENR1.B.USBF      = 1u;
    RCC.APB1RSTR1.B.USBFSRST = 1u;
    RCC.APB1RSTR1.B.USBFSRST = 0u;
    USB_FS.CNTR.R = 0u;
    // wait for ready
    delay_ticks (0x2000);
    USB_FS.CNTR.modify([](USB_CNTR_s & r)->auto {
      r.B.CTRM = 1u;
      r.B.RESETM = 1u;
      r.B.ERRM = 1u;
#ifndef USBD_SOF_DISABLED
      r.B.SOFM = 1u;
#endif
      r.B.SUSPM = 1u;
      r.B.WKUPM = 1u;
      return r.R;
    });
    NVIC_EnableIRQ (USB_FS_IRQn);
  } else if (RCC.APB1ENR1.B.USBF) {
    USB_FS.BCDR.R            = 0u;
    RCC.APB1RSTR1.B.USBFSRST = 1u;
    RCC.APB1ENR1.B.USBF      = 1u;
  }
}
// connect jen pripoji odpor na data, ostatni neni asi potreba
uint8_t usbd_driver::connect (bool connect) {
  uint8_t res = usbd_lane_sdp;
#if 0
  USB_FS.BCDR.modify([](USB_BCDR_s & r)->auto {
    r.B.BCDEN = 1u;
    r.B.DCDEN = 1u;
    return r.R;
  });
  if (USB_FS.BCDR.B.DCDET) {
    USB_FS.BCDR.modify([](USB_BCDR_s & r)->auto {
      r.B.BCDEN = 1u;
      r.B.PDEN  = 1u;
      return r.R;
    });    
    if (USB_FS.BCDR.B.PS2DET) {
      res = usbd_lane_unk;
    } else if (USB_FS.BCDR.B.PDET) {
      USB_FS.BCDR.modify([](USB_BCDR_s & r)->auto {
        r.B.BCDEN = 1u;
        r.B.SDEN  = 1u;
        return r.R;
      });    
      if (USB_FS.BCDR.B.SDET) {
        res = usbd_lane_dcp;
      } else {
        res = usbd_lane_cdp;
      }
    } else {
      res = usbd_lane_sdp;
    }
  } else {
    res = usbd_lane_dsc;
  }
#endif // 0    
  if (connect) USB_FS.BCDR.B.DPPU = 1u;
  else         USB_FS.BCDR.R      = 0u;
  return res;
}

void usbd_driver::setaddr (const uint8_t addr) {
  USB_FS.DADDR.modify([=](USB_DADDR_s & r)-> auto {
    r.B.ADD = addr;
    r.B.EF  = 1u;
    return r.R;
  });
  /*
  USB_FS.DADDR.B.EF  = 1u;
  USB_FS.DADDR.B.ADD = addr;
  */
}

bool usbd_driver::ep_config (uint8_t ep, uint8_t eptype, uint16_t epsize) {
  volatile uint16_t *reg = EPR (ep);
  pma_table *tbl = EPT (ep);
  /* epsize should be 16-bit aligned */
  if (epsize & 0x01) epsize++;

  switch (eptype) {
  case USB_EPTYPE_CONTROL:
    *reg = USB_EP_CONTROL | (ep & 0x07);
    break;
  case USB_EPTYPE_ISOCHRONUS:
    *reg = USB_EP_ISOCHRONOUS | (ep & 0x07);
    break;
  case USB_EPTYPE_BULK:
    *reg = USB_EP_BULK | (ep & 0x07);
    break;
  case USB_EPTYPE_BULK | USB_EPTYPE_DBLBUF:
    *reg = USB_EP_BULK | USB_EP_KIND | (ep & 0x07);
    break;
  default:
    *reg = USB_EP_INTERRUPT | (ep & 0x07);
    break;
  }
  /* if it TX or CONTROL endpoint */
  if ( (ep & 0x80) || (eptype == USB_EPTYPE_CONTROL)) {
    uint16_t _pma;
    _pma = get_next_pma (epsize);
    if (_pma == 0) return false;
    tbl->tx.addr = _pma;
    tbl->tx.cnt  = 0;
    if ( (eptype ==  USB_EPTYPE_ISOCHRONUS) ||
         (eptype == (USB_EPTYPE_BULK | USB_EPTYPE_DBLBUF))) {
      _pma = get_next_pma (epsize);
      if (_pma == 0) return false;
      tbl->tx1.addr = _pma;
      tbl->tx1.cnt  = 0;
      EP_DTX_UNSTALL (reg);
    } else {
      EP_TX_UNSTALL (reg);
    }
  }
  if (! (ep & 0x80)) {
    uint16_t _rxcnt;
    uint16_t _pma;
    if (epsize > 62) {
      if (epsize & 0x1F) {
        epsize &= 0x1F;
      } else {
        epsize -= 0x20;
      }
      _rxcnt = 0x8000 | (epsize << 5);
      epsize += 0x20;
    } else {
      _rxcnt = epsize << 9;
    }
    _pma = get_next_pma (epsize);
    if (_pma == 0) return false;
    tbl->rx.addr = _pma;
    tbl->rx.cnt = _rxcnt;
    if ( (eptype ==  USB_EPTYPE_ISOCHRONUS) ||
         (eptype == (USB_EPTYPE_BULK | USB_EPTYPE_DBLBUF))) {
      _pma = get_next_pma (epsize);
      if (_pma == 0) return false;
      tbl->rx0.addr = _pma;
      tbl->rx0.cnt  = _rxcnt;
      EP_DRX_UNSTALL (reg);
    } else {
      EP_RX_UNSTALL (reg);
    }
  }
  return true;
}

void usbd_driver::ep_deconfig (uint8_t ep) {
  pma_table *ept = EPT (ep);
  *EPR (ep) &= ~USB_EPREG_MASK;
  ept->rx.addr = 0;
  ept->rx.cnt  = 0;
  ept->tx.addr = 0;
  ept->tx.cnt  = 0;
}

static uint16_t pma_read (uint8_t *buf, uint16_t blen, pma_rec *rx) {
  uint16_t *pma = reinterpret_cast<uint16_t*> (USB_PMAADDR + rx->addr);
  uint16_t rxcnt = rx->cnt & 0x03FF;
  rx->cnt &= ~0x3FF;

  if (blen > rxcnt) {
    blen = rxcnt;
  }
  rxcnt = blen;
  while (blen) {
    uint16_t _t = *pma;
    *buf++ = _t & 0xFF;
    if (--blen) {
      *buf++ = _t >> 8;
      pma++;
      blen--;
    } else break;
  }
  return rxcnt;
}

int32_t usbd_driver::ep_read (uint8_t ep, void *ptr, uint16_t blen) {
  uint8_t * buf = reinterpret_cast<uint8_t *>(ptr);
  pma_table *tbl = EPT (ep);
  volatile uint16_t *reg = EPR (ep);
  switch (*reg & (USB_EPRX_STAT | USB_EP_T_FIELD | USB_EP_KIND)) {
    /* doublebuffered bulk endpoint */
  case (USB_EP_RX_VALID | USB_EP_BULK | USB_EP_KIND) :
    /* switching SWBUF if EP is NAKED */
    switch (*reg & (USB_EP_DTOG_RX | USB_EP_SWBUF_RX)) {
    case 0:
    case (USB_EP_DTOG_RX | USB_EP_SWBUF_RX) :
      *reg = (*reg & USB_EPREG_MASK) | USB_EP_SWBUF_RX;
    default:
      break;
    }
    if (*reg & USB_EP_SWBUF_RX) {
      return pma_read (buf, blen, & (tbl->rx1));
    } else {
      return pma_read (buf, blen, & (tbl->rx0));
    }
    /* isochronous endpoint */
  case (USB_EP_RX_VALID | USB_EP_ISOCHRONOUS) :
    if (*reg & USB_EP_DTOG_RX) {
      return pma_read (buf, blen, & (tbl->rx1));
    } else {
      return pma_read (buf, blen, & (tbl->rx0));
    }
    /* regular endpoint */
  case (USB_EP_RX_NAK | USB_EP_BULK) :
  case (USB_EP_RX_NAK | USB_EP_CONTROL) :
  case (USB_EP_RX_NAK | USB_EP_INTERRUPT) : {
    int32_t res = pma_read (buf, blen, & (tbl->rx));
    /* setting endpoint to VALID state */
    EP_RX_VALID (reg);
    return res;
  }
  /* invalid or not ready */
  default:
    return -1;
  }
}

static void pma_write (uint8_t *buf, uint16_t blen, pma_rec *tx) {
  uint16_t *pma = reinterpret_cast<uint16_t*> (USB_PMAADDR + tx->addr);
  tx->cnt = blen;
  while (blen > 1) {
    *pma++ = buf[1] << 8 | buf[0];
    buf += 2;
    blen -= 2;
  }
  if (blen) *pma = *buf;
}

int32_t usbd_driver::ep_write (uint8_t ep, void *ptr, uint16_t blen) {
  uint8_t * buf = reinterpret_cast<uint8_t *>(ptr);
  pma_table *tbl = EPT (ep);
  volatile uint16_t *reg = EPR (ep);
  switch (*reg & (USB_EPTX_STAT | USB_EP_T_FIELD | USB_EP_KIND)) {
    /* doublebuffered bulk endpoint */
  case (USB_EP_TX_NAK   | USB_EP_BULK | USB_EP_KIND) :
    if (*reg & USB_EP_SWBUF_TX) {
      pma_write (buf, blen, & (tbl->tx1));
    } else {
      pma_write (buf, blen, & (tbl->tx0));
    }
    *reg = (*reg & USB_EPREG_MASK) | USB_EP_SWBUF_TX;
    break;
    /* isochronous endpoint */
  case (USB_EP_TX_VALID | USB_EP_ISOCHRONOUS) :
    if (! (*reg & USB_EP_DTOG_TX)) {
      pma_write (buf, blen, & (tbl->tx1));
    } else {
      pma_write (buf, blen, & (tbl->tx0));
    }
    break;
    /* regular endpoint */
  case (USB_EP_TX_NAK | USB_EP_BULK) :
  case (USB_EP_TX_NAK | USB_EP_CONTROL) :
  case (USB_EP_TX_NAK | USB_EP_INTERRUPT) :
    pma_write (buf, blen, & (tbl->tx));
    EP_TX_VALID (reg);
    break;
    /* invalid or not ready */
  default:
    return -1;
  }
  return blen;
}

uint16_t usbd_driver::get_frame (void) {
  return USB_FS.FNR.B.FN;
}

void usbd_driver::poll () {
  uint8_t _ep;
  usbd_events _ev;
  USB_ISTR_s _istr;
  _istr.R = USB_FS.ISTR.R;
  _ep = _istr.B.EP_ID;
  if (_istr.B.CTR) {
    volatile uint16_t *reg = EPR (_ep);
    if (*reg & USB_EP_CTR_TX) {
      *reg &= (USB_EPREG_MASK ^ USB_EP_CTR_TX);
      _ep |= 0x80;
      _ev = usbd_evt_eptx;
    } else {
      *reg &= (USB_EPREG_MASK ^ USB_EP_CTR_RX);
      _ev = (*reg & USB_EP_SETUP) ? usbd_evt_epsetup : usbd_evt_eprx;
    }
  } else if (_istr.B.RESET) {
    USB_FS.ISTR.B.RESET = 0u;
    USB_FS.BTABLE.B.BTABLE = 0u;
    for (int i = 0; i < 8; i++) {
      ep_deconfig (i);
    }
    _ev = usbd_evt_reset;
#ifndef USBD_SOF_DISABLED
  } else if (_istr.B.SOF) {
    _ev = usbd_evt_sof;
    USB_FS.ISTR.B.SOF = 0u;
#endif
  } else if (_istr.B.WKUP) {
    _ev = usbd_evt_wkup;
    USB_FS.CNTR.B.FSUSP = 0u;
    USB_FS.ISTR.B.WKUP  = 0u;
  } else if (_istr.B.SUSP) {
    _ev = usbd_evt_susp;
    USB_FS.CNTR.B.FSUSP = 0u;
    USB_FS.ISTR.B.SUSP  = 0u;
  } else if (_istr.B.ERR) {
    _ev = usbd_evt_error;
    USB_FS.ISTR.B.ERR   = 0u;
  } else {
    return;
  }
  evt_handler (_ev, _ep);
}
extern "C" {
  extern void USB_FS_IRQHandler (void);
  void __cxa_pure_virtual () {
  }
};

void USB_FS_IRQHandler (void) {
  if (usbd_driver_instance) usbd_driver_instance->poll ();
}


/*
* */