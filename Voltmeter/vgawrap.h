#ifndef VGAWRAP_H
#define VGAWRAP_H

#include "vhsync.h"
#include "canvas.h"

class VgaWrap {
  VHSync          sync;
  uint8_t       * pVideoRAM;    // placeholder
  Canvas          canvas;
  volatile bool   disable;
  public:
    VgaWrap();
    
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
