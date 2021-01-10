#ifndef VGAWRAP_H
#define VGAWRAP_H

#include "baselayer.h"
#include "fifo.h"
//#include "vgaprint.h"
#include "vhsync.h"
#include "canvas.h"

class VgaWrap : public BaseLayer {
  VHSync          sync;
  uint8_t       * pVideoRAM;    // placeholder
  //VgaPrint        print;
  Canvas          canvas;
  volatile bool   disable;
  public:
    VgaWrap();
    uint32_t    Up   (const char * data, uint32_t len);
    
    void block   () {
      while (disable);
    }
    void display () {
      canvas.drawings();
    }
    void pointer (const float n) {
      canvas.pointer(n);
    }
};

#endif // VGAWRAP_H
