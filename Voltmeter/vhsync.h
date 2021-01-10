#ifndef HSYNC_H
#define HSYNC_H
#include "gpio.h"

class VHSync {
  GpioClass vsync;
  uint8_t * pVideoRAM;    // placeholder
  public:
    VHSync();
    uint8_t * getRAM () {
      return pVideoRAM;
    }
    // void setVideo ();
};

#endif // HSYNC_H
