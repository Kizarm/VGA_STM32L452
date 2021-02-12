#ifndef RNGCLASS_H
#define RNGCLASS_H
#include "gpio.h"
#include "fifo.h"
#include "baselayer.h"

class RngClass {
  GpioClass             ledg;
  Fifo<uint32_t, 0x100> fifo;
  public:
    RngClass();
    void irq   (const uint32_t data);
    void print (BaseLayer * out);
};

#endif // RNGCLASS_H
