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
#include <stdbool.h>
#include "usbd.h"

#define _MIN(a, b) ((a) < (b)) ? (a) : (b)

/** \brief Control endpoint 0 event processing callback
 * \param event endpoint event
 */
void usbd_endpoint0::evt_handler (usbd_events event, uint8_t ep) {
  switch (event) {
  case usbd_evt_epsetup:
    /* force switch to setup state */
    parent->status.control_state = usbd_ctl_idle;
    parent->complete_callback = 0;
  case usbd_evt_eprx:
    return parent->usbd_process_eprx (ep);
  case usbd_evt_eptx:
    return parent->usbd_process_eptx (ep);
  default:
    break;
  }
}
extern volatile unsigned g_usb_address_ready;
/** \brief Callback that sets USB device address
 * \param dev pointer to usb device
 * \param req pointer to usb control request data
 * \return none
 */
static void usbd_set_address (usbd_device *dev, usbd_ctlreq *req) {
  dev->setaddr (req->wValue);
  dev->status.device_state = (req->wValue) ? usbd_state_addressed : usbd_state_default;
#if USB_CHECK
  g_usb_address_ready = 1u;
#endif
}
/**********************************************************************************************/
/** \brief Resets USB device state
 * \param dev pointer to usb device
 * \return none
 */
void usbd_device::usbd_process_reset () {
  status.device_state = usbd_state_default;
  status.control_state = usbd_ctl_idle;
  status.device_cfg = 0;
  ep_config (0, USB_EPTYPE_CONTROL, status.ep0size);
  endpoint[0] = &ep0;
  setaddr (0);
}

/** \brief Control transfer completion callback processing
 * \param dev pointer to the usb device
 * \return none
 */
void usbd_device::usbd_process_callback () {
  if (complete_callback) {
    complete_callback (this, (usbd_ctlreq *) status.data_buf);
    complete_callback = 0;
  }
}

/** \brief SET_CONFIG request processing
 * \param dev usbd_device
 * \param config config number from request
 * \return usbd_ack if success
 */
usbd_respond usbd_device::usbd_configure (uint8_t config) {
  if (iface->if_cfg (config) == usbd_ack) {
    status.device_cfg = config;
    status.device_state = (config) ? usbd_state_configured : usbd_state_addressed;
    return usbd_ack;
  }
  return usbd_fail;
}


/** \brief Standard control request processing for device
 * \param dev pointer to usb device
 * \param req pointer to control request
 * \return TRUE if request is handled
 */
usbd_respond usbd_device::usbd_process_devrq (usbd_ctlreq *req) {
  switch (req->bRequest) {
  case USB_STD_CLEAR_FEATURE:
    /* not yet supported */
    break;
  case USB_STD_GET_CONFIG:
    req->data[0] = status.device_cfg;
    return usbd_ack;
  case USB_STD_GET_DESCRIPTOR:
    //if (dev->descriptor_callback) {
      return iface->if_dsc (req, & (status.data_ptr), & (status.data_count));
    //}
    break;
  case USB_STD_GET_STATUS:
    req->data[0] = 0;
    req->data[1] = 0;
    return usbd_ack;
  case USB_STD_SET_ADDRESS:
    if (getinfo() & USBD_HW_ADDRFST) {
      usbd_set_address (this, req);
    } else {
      complete_callback = usbd_set_address;
    }
    return usbd_ack;
  case USB_STD_SET_CONFIG:
    return usbd_configure (req->wValue);
  case USB_STD_SET_DESCRIPTOR:
    /* should be externally handled */
    break;
  case USB_STD_SET_FEATURE:
    /* not yet supported */
    break;
  default:
    break;
  }
  return usbd_fail;
}

/** \brief Standard control request processing for interface
 * \param dev pointer to usb device
 * \param req pointer to control request
 * \return TRUE if request is handled
 */
usbd_respond usbd_device::usbd_process_intrq (usbd_ctlreq *req) {
  switch (req->bRequest) {
  case USB_STD_GET_STATUS:
    req->data[0] = 0;
    req->data[1] = 0;
    return usbd_ack;
  default:
    break;
  }
  return usbd_fail;
}

/** \brief Standard control request processing for endpoint
 * \param dev pointer to usb device
 * \param req pointer to control request
 * \return TRUE if request is handled
 */
usbd_respond usbd_device::usbd_process_eptrq (usbd_ctlreq *req) {
  switch (req->bRequest) {
  case USB_STD_SET_FEATURE:
    ep_setstall (req->wIndex, 1);
    return usbd_ack;
  case USB_STD_CLEAR_FEATURE:
    ep_setstall (req->wIndex, 0);
    return usbd_ack;
  case USB_STD_GET_STATUS:
    req->data[0] = ep_isstalled (req->wIndex) ? 1 : 0;
    req->data[1] = 0;
    return usbd_ack;
  default:
    break;
  }
  return usbd_fail;
}

/** \brief Processing control request
 * \param dev pointer to usb device
 * \param req pointer to usb control request
 * \return TRUE if request is handled
 */
usbd_respond usbd_device::usbd_process_request (usbd_ctlreq *req) {
  // asm volatile ("bkpt 1");
  /* processing control request by callback */
  usbd_respond r = iface->if_ctl (req);
  if (r != usbd_fail) return r;
  /* continuing standard USB requests */
  switch (req->bmRequestType & (USB_REQ_TYPE | USB_REQ_RECIPIENT)) {
  case USB_REQ_STANDARD | USB_REQ_DEVICE:
    return usbd_process_devrq (req);
  case USB_REQ_STANDARD | USB_REQ_INTERFACE:
    return usbd_process_intrq (req);
  case USB_REQ_STANDARD | USB_REQ_ENDPOINT:
    return usbd_process_eptrq (req);
  default:
    break;
  }
  return usbd_fail;
}


/** \brief Control endpoint stall (STALL PID)
 * \param dev pointer to usb device
 * \param ep endpoint number
 */
void usbd_device::usbd_stall_pid (uint8_t ep) {
  ep_setstall (ep & 0x7F, 1);
  ep_setstall (ep | 0x80, 1);
  status.control_state = usbd_ctl_idle;
}


/** \brief Control endpoint TX event processing
 * \param dev pointer to usb device
 * \param ep endpoint number
 */
void usbd_device::usbd_process_eptx (uint8_t ep) {
  int32_t _t;
  char ** dptr = reinterpret_cast<char**> (&status.data_ptr);
  switch (status.control_state) {
  case usbd_ctl_ztxdata:
  case usbd_ctl_txdata:
    _t = _MIN (status.data_count, status.ep0size);
    ep_write (ep, status.data_ptr, _t);
    //dev->status.data_ptr += _t;
    *dptr += _t;
    status.data_count -= _t;
    /* if all data is not sent */
    if (0 != status.data_count) break;
    /* if last packet has a EP0 size and host awaiting for the more data ZLP should be sent*/
    /* if ZLP required, control state will be unchanged, therefore next TX event sends ZLP */
    if (usbd_ctl_txdata == status.control_state || _t != status.ep0size) {
      status.control_state = usbd_ctl_lastdata; /* no ZLP required */
    }
    break;
  case usbd_ctl_lastdata:
    status.control_state = usbd_ctl_statusout;
    break;
  case usbd_ctl_statusin:
    status.control_state = usbd_ctl_idle;
    return usbd_process_callback ();
  default:
    /* unexpected TX completion */
    /* just skipping it */
    break;
  }
}

/** \brief Control endpoint RX event processing
 * \param dev pointer to usb device
 * \param ep endpoint number
 */
void usbd_device::usbd_process_eprx (uint8_t ep) {
  uint16_t _t;
  usbd_ctlreq * const req = (usbd_ctlreq * const) status.data_buf;
  char ** dptr = reinterpret_cast<char**> (&status.data_ptr);
  switch (status.control_state) {
  case usbd_ctl_idle:
    /* read SETUP packet, send STALL_PID if incorrect packet length */
    if (0x08 !=  ep_read (ep, req, status.data_maxsize)) {
      return usbd_stall_pid (ep);
    }
    status.data_ptr = req->data;
    status.data_count = req->wLength;
    /* processing request with no payload data*/
    if ((req->bmRequestType & USB_REQ_DEVTOHOST) || (0 == req->wLength)) break;
    /* checking available memory for DATA OUT stage */
    if (req->wLength > status.data_maxsize) {
      return usbd_stall_pid (ep);
    }
    /* continue DATA OUT stage */
    status.control_state = usbd_ctl_rxdata;
    return;
  case usbd_ctl_rxdata:
    /*receive DATA OUT packet(s) */
    _t = ep_read (ep, status.data_ptr, status.data_count);
    if (status.data_count < _t) {
      /* if received packet is large than expected */
      /* Must be error. Let's drop this request */
      return usbd_stall_pid (ep);
    } else if (status.data_count != _t) {
      /* if all data payload was not received yet */
      status.data_count -= _t;
      //dev->status.data_ptr += _t;
      *dptr += _t;
      return;
    }
    break;
  case usbd_ctl_statusout:
    /* reading STATUS OUT data to buffer */
    ep_read (ep, status.data_ptr, status.data_maxsize);
    status.control_state = usbd_ctl_idle;
    return usbd_process_callback ();
  default:
    /* unexpected RX packet */
    return usbd_stall_pid (ep);
  }
  /* usb request received. let's handle it */
  status.data_ptr = req->data;
  status.data_count = /*req->wLength;*/status.data_maxsize;
  switch (usbd_process_request (req)) {
  case usbd_ack:
    if (req->bmRequestType & USB_REQ_DEVTOHOST) {
      /* return data from function */
      if (status.data_count >= req->wLength) {
        status.data_count = req->wLength;
        status.control_state = usbd_ctl_txdata;
      } else {
        /* DATA IN packet smaller than requested */
        /* ZLP maybe wanted */
        status.control_state = usbd_ctl_ztxdata;
      }
      return usbd_process_eptx (ep | 0x80);

    } else {
      /* confirming by ZLP in STATUS_IN stage */
      ep_write (ep | 0x80, 0, 0);
      status.control_state = usbd_ctl_statusin;
    }
    break;
  case usbd_nak:
    status.control_state = usbd_ctl_statusin;
    break;
  default:
    return usbd_stall_pid (ep);
  }
}

/** \brief General event processing callback
 * \param dev usb device
 * \param evt usb event
 * \param ep active endpoint
 */
void usbd_device::evt_handler (usbd_events evt, uint8_t ep) {
  switch (evt) {
  case usbd_evt_reset:
    usbd_process_reset ();
    break;
  case usbd_evt_eprx:
  case usbd_evt_eptx:
  case usbd_evt_epsetup:
    if (endpoint[ep & 0x07]) endpoint[ep & 0x07]->evt_handler (evt, ep);
    break;
  case usbd_evt_sof:  // sof zkusime pustit na vsechny zname endpointy krome 0
    for (unsigned n=1; n<8; n++) {
      if (endpoint[n]) endpoint[n]->evt_handler(evt, 0);
      else break;
    }
    break;
  default:
    break;
  }
}
