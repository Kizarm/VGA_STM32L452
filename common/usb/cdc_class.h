#ifndef USB_CDC_H
#define USB_CDC_H

#include "usbd.h"
#include "baselayer.h"
#include "fifo.h"

static const uint32_t USB_MAX_NON_ISO_SIZE = 0x40;

class cdc_class;

class loop_endpoint : public usbd_endpoint {
  cdc_class * ifc;
  public:
    loop_endpoint (usbd_device & d, cdc_class * i) : usbd_endpoint(d), ifc(i) {};
    void evt_handler (usbd_events event, uint8_t ep);
};

class intr_endpoint : public usbd_endpoint {
  public:
    intr_endpoint (usbd_device & d) : usbd_endpoint(d){};
    void evt_handler (usbd_events event, uint8_t ep);
};

class UsartClass;

class cdc_class : public usbd_interface, public BaseLayer {
  loop_endpoint le;
  intr_endpoint ie;

  public:
    cdc_class (usbd_device & p) : usbd_interface(p), le(p, this), ie(p) {
      usbtx_rdy   = 1;
      send_enable = 0;
      pusart      = nullptr;
    };
    void init ();
    void handler (usbd_events event, uint8_t ep);
  protected:
    usbd_respond if_cfg (uint8_t cfg);
    usbd_respond if_ctl (usbd_ctlreq *req);
    usbd_respond if_dsc (usbd_ctlreq *req, void **address, uint16_t *dsize);
  public:
    uint32_t Down (const char* buf, uint32_t len);
    /// for optional SetLineCode handling
    void AttachUsart      (UsartClass & usart) {
      pusart = & usart;
    }
    bool SetCtrlLineState (uint16_t state);
    bool SetLineCode      (uint8_t * data);
  protected:
    bool Recv             (uint32_t len);
    void Send             (void);
  private:
    UsartClass      * pusart;    
    uint8_t           rxBuf [USB_MAX_NON_ISO_SIZE];
    uint8_t           txBuf [USB_MAX_NON_ISO_SIZE];
    volatile uint32_t usbtx_rdy;     //!< semafor pro čekání na kompletní výstup dat
    volatile uint32_t send_enable;   //!< je dobre blokovat data dokud neni DTR==1
    Fifo<char, USB_MAX_NON_ISO_SIZE>  tx;
};

#endif // USB_CDC_H
