#ifndef INDICATOR_H
#define INDICATOR_H
#if defined __arm__
#include "gpio.h"
#elif defined __wasm__
#include "libwasm.h"
#else
#include <stdio.h>
#endif
enum LIGHT {
  L_NONE = 0, L_RED, L_GREEN, L_YELLOW
};

class Indicator {
#ifdef __arm__
  GpioClass r,y,g;  
#endif
  public:
    Indicator();
    void set (const LIGHT p);
};

#endif // INDICATOR_H
