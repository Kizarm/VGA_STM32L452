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
.*/

#ifndef _USBD_CORE_H_
#define _USBD_CORE_H_
#if defined(__cplusplus)
extern "C" {
#endif

/** @addtogroup USBD_HW_CORE USB Device HW driver and core API
 * @{ */
#if defined(__DOXYGEN__)
/** @name Compile-time control macros
 * @{ */
#define USBD_SOF_DISABLED   /**<@brief Disables SOF handling.*/
#define USBD_VBUS_DETECT    /**<@brief Enables Vbus detection for L4/F4 */
#define USBD_DP_PORT        /**<@brief DP pullup port for F103/F303 */
#define USBD_DP_PIN         /**<@brief DP pullup pin for F103/F303 */
#define USBD_SOF_OUT        /**<@brief Enables SOF output pin for F4 OTGFS. */
#define USBD_PRIMARY_OTGHS  /**<@brief Sets OTGHS as primary interface for F4*/
#define USBD_USE_EXT_ULPI   /**<@brief Enables external ULPI interface for OTGHS */
/** @} */
#endif

/** @addtogroup USBD_HW USB hardware driver
 *  @brief Contains HW driver API
 * @{ */
/** @anchor USB_EVENTS
 *  @name USB device events
 * @{ */

enum usbd_events : uint8_t {
  usbd_evt_reset  =   0,  /**<@brief Reset.*/
  usbd_evt_sof,           /**<@brief Start of frame.*/
  usbd_evt_susp,          /**<@brief Suspend.*/
  usbd_evt_wkup,          /**<@brief Wakeup.*/
  usbd_evt_eptx,          /**<@brief Data packet transmitted*/
  usbd_evt_eprx,          /**<@brief Data packet received.*/
  usbd_evt_epsetup,       /**<@brief Setup packet received.*/
  usbd_evt_error,         /**<@brief Data error.*/
  usbd_evt_count      
};
/** @} */

/** @anchor USB_LANES_STATUS
 *  @name USB lanes connection states
 * @{ */
enum usbd_lanes_status : uint8_t {
  usbd_lane_unk   =   0,  /**<@brief Unknown or proprietary charger.*/
  usbd_lane_dsc,          /**<@brief Lanes disconnected.*/
  usbd_lane_sdp,          /**<@brief Lanes connected to standard downstream port.*/
  usbd_lane_cdp,          /**<@brief Lanes connected to charging downstream port.*/
  usbd_lane_dcp           /**<@brief Lanes connected to dedicated charging port.*/
};
/** @} */

/** @anchor USBD_HW_CAPS
 *  @name USB HW capabilities and status
 * @{ */
#define USBD_HW_ADDRFST     (1 << 0)    /**<@brief Set address before STATUS_OUT.*/
#define USBD_HW_BC          (1 << 1)    /**<@brief Battery charging detection supported.*/
#define USND_HW_HS          (1 << 2)    /**<@brief High speed supported.*/
#define USBD_HW_ENABLED     (1 << 3)    /**<@brief USB device enabled. */
#define USBD_HW_ENUMSPEED   (2 << 4)    /**<@brief USB device enumeration speed mask.*/
#define USBD_HW_SPEED_NC    (0 << 4)    /**<@brief Not connected */
#define USBD_HW_SPEED_LS    (1 << 4)    /**<@brief Low speed */
#define USBD_HW_SPEED_FS    (2 << 4)    /**<@brief Full speed */
#define USBD_HW_SPEED_HS    (3 << 4)    /**<@brief High speed */

/** @} */
/** @} */

/** @addtogroup USBD_CORE USB device core
 *  @brief Contains core API
 * @{ */
#define USB_EPTYPE_DBLBUF   0x04    /**<@brief Doublebuffered endpoint (bulk endpoint only).*/

/** @name bmRequestType bitmapped field
 * @{ */
#define USB_REQ_DIRECTION   (1 << 7)    /**<@brief Request direction mask.*/
#define USB_REQ_HOSTTODEV   (0 << 7)    /**<@brief Request direction is HOST to DEVICE.*/
#define USB_REQ_DEVTOHOST   (1 << 7)    /**<@brief Request direction is DEVICE to HOST.*/
#define USB_REQ_TYPE        (3 << 5)    /**<@brief Request type mask.*/
#define USB_REQ_STANDARD    (0 << 5)    /**<@brief Standard request.*/
#define USB_REQ_CLASS       (1 << 5)    /**<@brief Class specified request.*/
#define USB_REQ_VENDOR      (2 << 5)    /**<@brief Vendor specified request.*/
#define USB_REQ_RECIPIENT   (3 << 0)    /**<@brief Request recipient mask.*/
#define USB_REQ_DEVICE      (0 << 0)    /**<@brief Request to device.*/
#define USB_REQ_INTERFACE   (1 << 0)    /**<@brief Request to interface.*/
#define USB_REQ_ENDPOINT    (2 << 0)    /**<@brief Request to endpoint.*/
#define USB_REQ_OTHER       (3 << 0)    /**<@brief Other request.*/
/** @} */


/** @brief USB device machine states.*/
enum usbd_machine_state : uint8_t {
  usbd_state_disabled,
  usbd_state_disconnected,
  usbd_state_default,         /**< Default.*/
  usbd_state_addressed,       /**< Addressed.*/
  usbd_state_configured,      /**< Configured.*/
};

/** @brief USB device control endpoint machine state.*/
enum usbd_ctl_state : uint8_t {
  usbd_ctl_idle,              /**<@brief Idle stage. Awaiting for SETUP packet.*/
  usbd_ctl_rxdata,            /**<@brief RX stage. Receiving DATA-OUT payload.*/
  usbd_ctl_txdata,            /**<@brief TX stage. Transmitting DATA-IN payload.*/
  usbd_ctl_ztxdata,           /**<@brief TX stage. Transmitting DATA-IN payload. Zero length
                                 * packet maybe required..*/
  usbd_ctl_lastdata,          /**<@brief TX stage. Last DATA-IN packed passed to buffer. Awaiting
                                 * for the TX completion.*/
  usbd_ctl_statusin,          /**<@brief STATUS-IN stage.*/
  usbd_ctl_statusout,         /**<@brief STATUS-OUT stage.*/
};

/** @brief Asynchronous device control commands.*/
enum usbd_commands {
  usbd_cmd_enable,            /**<@brief Enables device.*/
  usbd_cmd_disable,           /**<@brief Disables device.*/
  usbd_cmd_connect,           /**<@brief Connects device to host.*/
  usbd_cmd_disconnect,        /**<@brief Disconnects device from host.*/
  usbd_cmd_reset,             /**<@brief Resets device.*/
};

/** @brief Reporting status results.*/
typedef enum _usbd_respond {
  usbd_fail,                  /**<@brief Function has an error, STALLPID will be issued.*/
  usbd_ack,                   /**<@brief Function completes request accepted ZLP or data will be send.*/
  usbd_nak,                   /**<@brief Function is busy. NAK handshake.*/
} usbd_respond;

/** @brief Represents generic USB control request.*/
struct usbd_ctlreq {
  uint8_t     bmRequestType;  /**<@brief This bitmapped field identifies the characteristics of
                                 * the specific request.*/
  uint8_t     bRequest;       /**<@brief This field specifies the particular request.*/
  uint16_t    wValue;         /**<@brief It is used to pass a parameter to the device, specific to
                                 * the request.*/
  uint16_t    wIndex;         /**<@brief It is used to pass a parameter to the device, specific to
                                 * the request.*/
  uint16_t    wLength;        /**<@brief This field specifies the length of the data transferred
                                 * during the second phase of the control transfer.*/
  uint8_t     data[];         /**<@brief Data payload.*/
};

/** USB device status data.*/
struct usbd_status {
  void        *data_buf;      /**<@brief Pointer to data buffer used for control requests.*/
  void        *data_ptr;      /**<@brief Pointer to current data for control request.*/
  uint16_t    data_count;     /**<@brief Count remained data for control request.*/
  uint16_t    data_maxsize;   /**<@brief Size of the data buffer for control requests.*/
  uint8_t     ep0size;        /**<@brief Size of the control endpoint.*/
  uint8_t     device_cfg;     /**<@brief Current device configuration number.*/
  usbd_machine_state device_state;   /**<@brief Current @ref usbd_machine_state.*/
  usbd_ctl_state     control_state;  /**<@brief Current @ref usbd_ctl_state.*/
};

class usbd_device;
/** @brief USB control transfer completed callback function.
 *  @param[in] dev pointer to USB device
 *  @param[in] req pointer to usb request structure
 *  @note usbd_device->complete_callback will be set to NULL after this callback completion.
 */
typedef void (*usbd_rqc_callback) (usbd_device *dev, usbd_ctlreq *req);

/** @brief Represents a hardware USB driver call table.*/
class usbd_driver {
  public:
    usbd_driver();
    uint32_t getinfo      (void);
    void     enable       (bool enable);
    uint8_t  connect      (bool connect);
    void     setaddr      (const uint8_t addr);
    bool     ep_config    (uint8_t ep, uint8_t eptype, uint16_t epsize);
    void     ep_deconfig  (uint8_t ep);
    int32_t  ep_read      (uint8_t ep, void *ptr, uint16_t blen);
    int32_t  ep_write     (uint8_t ep, void *ptr, uint16_t blen);
    void     ep_setstall  (uint8_t ep, bool stall);
    bool     ep_isstalled (uint8_t ep);
    void     poll         ();
    uint16_t get_frame    (void);
    virtual void evt_handler (usbd_events event, uint8_t ep) = 0;
};

/** @} */
class usbd_device;

class usbd_endpoint {
  public:
    usbd_endpoint (usbd_device & d) : parent(&d) {};
    virtual void evt_handler (usbd_events event, uint8_t ep) = 0;
    usbd_device * parent;
};

class usbd_interface {
  public:
    usbd_interface (usbd_device & d) : parent(& d) {};
    virtual usbd_respond if_cfg (uint8_t cfg) = 0;
    virtual usbd_respond if_ctl (usbd_ctlreq *req) = 0;
    virtual usbd_respond if_dsc (usbd_ctlreq *req, void **address, uint16_t *dsize) = 0;
    usbd_device  * parent;
  private:
};

/** @addtogroup USBD_CORE
 * @{ */

class usbd_endpoint0 : public usbd_endpoint {
  public:
    usbd_endpoint0   (usbd_device & dev) : usbd_endpoint(dev) {};
    void evt_handler (usbd_events event, uint8_t ep);
};

/** @brief Represents a USB device data.*/
class usbd_device : public usbd_driver {
  usbd_endpoint0 ep0;
  // nejak uchovava status usbd_device
  uint32_t ubuf[0x20];
  public:
    usbd_device() : usbd_driver(), ep0(*this) {};
    void attach (usbd_interface & i) { iface = &i; };
    usbd_interface           *  iface;
    usbd_status                 status;                 /**<\copybrief usbd_status */
    
    usbd_rqc_callback           complete_callback;      /**<\copybrief usbd_rqc_callback zde dulezite - nastavuje adresu */
    
    usbd_endpoint            *  endpoint[8];            /**<@brief array of the endpoint callbacks.*/

    void evt_handler (usbd_events event, uint8_t ep);
    /** @brief Initializes device structure
    * @param dev USB device that will be initialized
    * @param drv Pointer to hardware driver
    * @param ep0size Control endpoint 0 size
    * @param buffer Pointer to control request data buffer (32-bit aligned)
    * @param bsize Size of the data buffer
    */
    void usbd_init (const uint8_t ep0size) {
      status.ep0size = ep0size;
      status.data_ptr = ubuf;
      status.data_buf = ubuf;
      const uint16_t bsize = sizeof (ubuf);
      status.data_maxsize = bsize - __builtin_offsetof (usbd_ctlreq, data);
    }
    /** @brief Register endpoint callback
    * @param dev dev usb device @ref _usbd_device
    * @param ep endpoint index
    * @param callback pointer to user @ref usbd_evt_callback callback for endpoint events
    */
    void usbd_reg_endpoint (uint8_t ep, usbd_endpoint * e) {
      endpoint[ep & 0x07] = e;
    }
    void usbd_process_eptx (uint8_t ep);
    void usbd_process_eprx (uint8_t ep);
  protected:
    void usbd_process_reset ();
    void usbd_process_callback ();
    void usbd_stall_pid (uint8_t ep);
    usbd_respond usbd_configure (uint8_t config);
    usbd_respond usbd_process_devrq   (usbd_ctlreq *req);
    usbd_respond usbd_process_intrq   (usbd_ctlreq *req);
    usbd_respond usbd_process_eptrq   (usbd_ctlreq *req);
    usbd_respond usbd_process_request (usbd_ctlreq *req);
};



/** @} */
/** @} */

#if defined(__cplusplus)
}
#endif
#endif //_USBD_STD_H_
