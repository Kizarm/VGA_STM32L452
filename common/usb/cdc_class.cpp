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
#include <string.h>
#include <wchar.h>
#include "usbd.h"
#include "usb_cdc.h"
#include "cdc_class.h"

#include "led.h"
#include "usart.h"
#include "gpio.h"

#define CDC_EP0_SIZE    0x08
#define CDC_RXD_EP      0x01
#define CDC_TXD_EP      0x81
#define CDC_DATA_SZ     0x40
#define CDC_NTF_EP      0x82
#define CDC_NTF_SZ      0x08

#define CDC_LOOPBACK

struct cdc_config {
  struct usb_config_descriptor        config;
  struct usb_interface_descriptor     comm;
  struct usb_cdc_header_desc          cdc_hdr;
  struct usb_cdc_call_mgmt_desc       cdc_mgmt;
  struct usb_cdc_acm_desc             cdc_acm;
  struct usb_cdc_union_desc           cdc_union;
  struct usb_endpoint_descriptor      comm_ep;
  struct usb_interface_descriptor     data;
  struct usb_endpoint_descriptor      data_eprx;
  struct usb_endpoint_descriptor      data_eptx;
} __attribute__ ( (packed));

static const struct usb_device_descriptor device_desc = {
  .bLength            = sizeof (struct usb_device_descriptor),
  .bDescriptorType    = USB_DTYPE_DEVICE,
  .bcdUSB             = VERSION_BCD (2,0,0),
  .bDeviceClass       = USB_CLASS_CDC,
  .bDeviceSubClass    = USB_SUBCLASS_NONE,
  .bDeviceProtocol    = USB_PROTO_NONE,
  .bMaxPacketSize0    = CDC_EP0_SIZE,
  .idVendor           = 0x0483,
  .idProduct          = 0x5740,
  .bcdDevice          = VERSION_BCD (1,0,0),
  .iManufacturer      = 1,
  .iProduct           = 2,
  .iSerialNumber      = 3,
  .bNumConfigurations = 1,
};

static const struct cdc_config config_desc = {
  .config = {
    .bLength                = sizeof (struct usb_config_descriptor),
    .bDescriptorType        = USB_DTYPE_CONFIGURATION,
    .wTotalLength           = sizeof (struct cdc_config),
    .bNumInterfaces         = 2,
    .bConfigurationValue    = 1,
    .iConfiguration         = NO_DESCRIPTOR,
    .bmAttributes           = USB_CFG_ATTR_RESERVED | USB_CFG_ATTR_SELFPOWERED,
    .bMaxPower              = USB_CFG_POWER_MA (100),
  },
  .comm = {
    .bLength                = sizeof (struct usb_interface_descriptor),
    .bDescriptorType        = USB_DTYPE_INTERFACE,
    .bInterfaceNumber       = 0,
    .bAlternateSetting      = 0,
    .bNumEndpoints          = 1,
    .bInterfaceClass        = USB_CLASS_CDC,
    .bInterfaceSubClass     = USB_CDC_SUBCLASS_ACM,
    .bInterfaceProtocol     = USB_CDC_PROTO_V25TER,
    .iInterface             = NO_DESCRIPTOR,
  },
  .cdc_hdr = {
    .bFunctionLength        = sizeof (struct usb_cdc_header_desc),
    .bDescriptorType        = USB_DTYPE_CS_INTERFACE,
    .bDescriptorSubType     = USB_DTYPE_CDC_HEADER,
    .bcdCDC                 = VERSION_BCD (1,1,0),
  },
  .cdc_mgmt = {
    .bFunctionLength        = sizeof (struct usb_cdc_call_mgmt_desc),
    .bDescriptorType        = USB_DTYPE_CS_INTERFACE,
    .bDescriptorSubType     = USB_DTYPE_CDC_CALL_MANAGEMENT,
    .bmCapabilities         = 0,
    .bDataInterface         = 1,

  },
  .cdc_acm = {
    .bFunctionLength        = sizeof (struct usb_cdc_acm_desc),
    .bDescriptorType        = USB_DTYPE_CS_INTERFACE,
    .bDescriptorSubType     = USB_DTYPE_CDC_ACM,
    .bmCapabilities         = 0,
  },
  .cdc_union = {
    .bFunctionLength        = sizeof (struct usb_cdc_union_desc),
    .bDescriptorType        = USB_DTYPE_CS_INTERFACE,
    .bDescriptorSubType     = USB_DTYPE_CDC_UNION,
    .bMasterInterface0      = 0,
    .bSlaveInterface0       = 1,
  },
  .comm_ep = {
    .bLength                = sizeof (struct usb_endpoint_descriptor),
    .bDescriptorType        = USB_DTYPE_ENDPOINT,
    .bEndpointAddress       = CDC_NTF_EP,
    .bmAttributes           = USB_EPTYPE_INTERRUPT,
    .wMaxPacketSize         = CDC_NTF_SZ,
    .bInterval              = 0xFF,
  },
  .data = {
    .bLength                = sizeof (struct usb_interface_descriptor),
    .bDescriptorType        = USB_DTYPE_INTERFACE,
    .bInterfaceNumber       = 1,
    .bAlternateSetting      = 0,
    .bNumEndpoints          = 2,
    .bInterfaceClass        = USB_CLASS_CDC_DATA,
    .bInterfaceSubClass     = USB_SUBCLASS_NONE,
    .bInterfaceProtocol     = USB_PROTO_NONE,
    .iInterface             = 4,
  },
  .data_eprx = {
    .bLength                = sizeof (struct usb_endpoint_descriptor),
    .bDescriptorType        = USB_DTYPE_ENDPOINT,
    .bEndpointAddress       = CDC_RXD_EP,
    .bmAttributes           = USB_EPTYPE_BULK,
    .wMaxPacketSize         = CDC_DATA_SZ,
    .bInterval              = 0x01,
  },
  .data_eptx = {
    .bLength                = sizeof (struct usb_endpoint_descriptor),
    .bDescriptorType        = USB_DTYPE_ENDPOINT,
    .bEndpointAddress       = CDC_TXD_EP,
    .bmAttributes           = USB_EPTYPE_BULK,
    .wMaxPacketSize         = CDC_DATA_SZ,
    .bInterval              = 0x01,
  },
};
template<const unsigned N> struct w_text {
  uint8_t       len, typ;
  const wchar_t str [N];
}__attribute__((packed));

#define WSTR1 (L"Kizarm Labs.")
#define WSTR2 (L"USB Serial convertor")
#define WSTR3 (L"0001")
#define WSTR4 (L"USB <=> USART")

static const uint8_t str_0[] =  {0x04,0x03,0x09,0x04};
static const w_text<(sizeof WSTR1 >> 1u)> str_1 = {sizeof (str_1) - 2u, USB_DTYPE_STRING, {WSTR1}};
static const w_text<(sizeof WSTR2 >> 1u)> str_2 = {sizeof (str_2) - 2u, USB_DTYPE_STRING, {WSTR2}};
static const w_text<(sizeof WSTR3 >> 1u)> str_3 = {sizeof (str_3) - 2u, USB_DTYPE_STRING, {WSTR3}};
static const w_text<(sizeof WSTR4 >> 1u)> str_4 = {sizeof (str_4) - 2u, USB_DTYPE_STRING, {WSTR4}};

static const usb_string_descriptor * const dtable[] = {
  reinterpret_cast<const usb_string_descriptor *> (& str_0),
  reinterpret_cast<const usb_string_descriptor *> (& str_1),
  reinterpret_cast<const usb_string_descriptor *> (& str_2),
  reinterpret_cast<const usb_string_descriptor *> (& str_3),
  reinterpret_cast<const usb_string_descriptor *> (& str_4),
};

static usb_cdc_line_coding cdc_line = {
  .dwDTERate          = 38400,
  .bCharFormat        = USB_CDC_1_STOP_BITS,
  .bParityType        = USB_CDC_NO_PARITY,
  .bDataBits          = 8,
};

void intr_endpoint::evt_handler (usbd_events event, uint8_t ep) {

}
void loop_endpoint::evt_handler (usbd_events event, uint8_t ep) {
  ifc->handler(event, ep);
}
void cdc_class::handler (usbd_events event, uint8_t ep) {
  unsigned  rlen;
  switch (event) {
  case usbd_evt_eprx:
    rlen = parent->ep_read (CDC_RXD_EP, rxBuf, CDC_DATA_SZ);
    Recv   (rlen);
    break;
  case usbd_evt_eptx:
    usbtx_rdy = 1;
    Send       ();
    break;
  default:
    break;
  }
}

void cdc_class::init() {
  parent->usbd_init  (CDC_EP0_SIZE);
  parent->enable  (true);
  parent->connect (true);
}

usbd_respond cdc_class::if_ctl (usbd_ctlreq * req) {
  if ( ( (USB_REQ_RECIPIENT | USB_REQ_TYPE) & req->bmRequestType) != (USB_REQ_INTERFACE | USB_REQ_CLASS)) return usbd_fail;
  switch (req->bRequest) {
  case USB_CDC_SET_CONTROL_LINE_STATE:
    SetCtrlLineState (req->wValue);
    return usbd_ack;
  case USB_CDC_SET_LINE_CODING:
    memmove (&cdc_line, req->data, sizeof (cdc_line));
    SetLineCode ((uint8_t*)&cdc_line);
    return usbd_ack;
  case USB_CDC_GET_LINE_CODING:
    parent->status.data_ptr = &cdc_line;
    parent->status.data_count = sizeof (cdc_line);
    return usbd_ack;
  default:
    return usbd_fail;
  }
}
usbd_respond cdc_class::if_cfg (uint8_t cfg) {
  switch (cfg) {
  case 0:
    /* deconfiguring device */
    parent->ep_deconfig  (CDC_NTF_EP);
    parent->ep_deconfig  (CDC_TXD_EP);
    parent->ep_deconfig  (CDC_RXD_EP);
    parent->usbd_reg_endpoint (CDC_RXD_EP, 0);
    parent->usbd_reg_endpoint (CDC_TXD_EP, 0);
    return usbd_ack;
  case 1:
    /* configuring device */
    parent->ep_config (CDC_RXD_EP, USB_EPTYPE_BULK, CDC_DATA_SZ);
    parent->ep_config (CDC_TXD_EP, USB_EPTYPE_BULK, CDC_DATA_SZ);
    parent->ep_config (CDC_NTF_EP, USB_EPTYPE_INTERRUPT, CDC_NTF_SZ);
    
    parent->usbd_reg_endpoint (CDC_RXD_EP, &le);
    parent->usbd_reg_endpoint (CDC_TXD_EP, &le);
    parent->usbd_reg_endpoint (CDC_NTF_EP, &ie);
    return usbd_ack;
  default:
    return usbd_fail;
  }
}
usbd_respond cdc_class::if_dsc (usbd_ctlreq *req, void **address, uint16_t *length) {
  const uint8_t dtype = req->wValue >> 8;
  const uint8_t dnumber = req->wValue & 0xFF;
  const void* desc;
  uint16_t len = 0;
  switch (dtype) {
  case USB_DTYPE_DEVICE:
    desc = &device_desc;
    break;
  case USB_DTYPE_CONFIGURATION:
    desc = &config_desc;
    len = sizeof (config_desc);
    break;
  case USB_DTYPE_STRING:
    if (dnumber < 5) {
      desc = dtable[dnumber];
    } else {
      return usbd_fail;
    }
    break;
  default:
    return usbd_fail;
  }
  if (len == 0) {
    len = ((struct usb_header_descriptor*) desc)->bLength;
  }
  *address = (void*) desc;
  *length = len;
  return usbd_ack;
}

uint32_t cdc_class::Down (const char* buf, uint32_t len) {
  /// Pokud neni nastaveno DTR, zahodit data.
  //if (!send_enable) return len;
  
  uint32_t n;
  for (n=0; n<len; n++) {
    if (!tx.Write(buf[n])) break;
  }
  Send ();
  return n;
}
bool cdc_class::Recv (uint32_t len) {
  uint32_t  n, ofs = 0;
  while (len) {
    n = Up ((char*) rxBuf + ofs, len);
    if (!n) return false;
    len -= n;
    ofs += n;
  }
  return true;
}
void cdc_class::Send (void) {
  char* ptr = (char*) txBuf;
  uint32_t n;
  
  if  (!usbtx_rdy) return;
  for (n=0; n<USB_MAX_NON_ISO_SIZE; n++) {
    if (!tx.Read(ptr[n])) break;
  }
  if  (!n)  return;
  int k = parent->ep_write (CDC_TXD_EP, txBuf, n);
  if (k<=0) return;
  usbtx_rdy = 0;
}

bool cdc_class::SetCtrlLineState (uint16_t state) {
  if (state & 1) {
    send_enable = 1;
  }
  else {
    send_enable = 0;
  }
  return true;
}
bool cdc_class::SetLineCode (uint8_t * data) {
#ifdef USE_USART
  usb_cdc_line_coding * line_coding = (usb_cdc_line_coding *) data;
  uint32_t baud = 9600;
  baud = line_coding->dwDTERate;
  if (pusart) pusart->SetBaud (baud);
#endif // USE_USART
  return true;

}

