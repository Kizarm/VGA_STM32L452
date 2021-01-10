#ifndef LOADER_H
#define LOADER_H
#include "baselayer.h"
#include "fifo.h"
#include "intelhex.h"
#include "usbd.h"
#include "cdc_class.h"

#ifdef USE_USB

class Loader : public BaseLayer {
  Fifo<char, 64> ring;
  IntelHex       ihx;
  usbd_device    udev;
  cdc_class      cdc_acm;
  uint8_t      * mem_base;
  char           buffer [64];
  unsigned       index;
  uint32_t       m_ofs, m_len;
  public:
    Loader();
    void Init  (uint8_t * base);
    uint32_t Up (const char * data, uint32_t len) override {
      unsigned n;
      for (n=0; n<len; n++) {
        if (!ring.Write(data [n])) break;
      }
      return n;
    }
    void loop ();
  protected:
    void record ();
};

#else

class Loader {
  public:
    Loader() {};
    void Init  (uint8_t *) {};
    void loop () {};
};

#endif // USE_USB

#endif // LOADER_H
