#include "STM32L4x2.h"
#include "rngclass.h"

static RngClass * RngClassInstance = nullptr;

RngClass::RngClass() : ledg (GpioPortA, 8), fifo() {
  RngClassInstance    = this;
  RCC.AHB2ENR.B.RNGEN = 1u;
  NVIC_EnableIRQ (RNG_IRQn);
  RNG.CR.modify([](RNG_CR_s & r) -> auto {
    r.B.RNGEN = 1u;
    r.B.IE    = 1u;
    return r.R;
  });
}
void RngClass::irq (const uint32_t data) {
  if (!fifo.Write(data)) {
    RNG.CR.B.RNGEN = 0u;
    -ledg;
  }
}
static const char HexTable [] = ("0123456789ABCDEF");
void RngClass::print (BaseLayer * out) {
  uint32_t data;
  const unsigned buflen = 64;
  char buffer [buflen];
  unsigned index = 0u;
  for (;;) {
    if (!fifo.Read(data)) {
      RNG.CR.B.RNGEN = 1u;
      +ledg;
      continue;
    }
    buffer [index++] = (data >> 24) & 0xFF;
    buffer [index++] = (data >> 16) & 0xFF;
    buffer [index++] = (data >>  8) & 0xFF;
    buffer [index++] = (data >>  0) & 0xFF;
    
    if (index >= buflen) break;
  }
  unsigned offset = 0u;
  for (;;) {
    const unsigned k = out->Down (buffer + offset, index);
    offset += k;
    index  -= k;
    if (index == 0u) break;
  }
}

extern "C" void RNG_IRQHandler () {
  uint32_t number = 0u;
  if (RNG.SR.B.DRDY) {
    number = RNG.DR;
  }
  const uint32_t status = RNG.SR.R;
  if (status) {
    return; // chyba
  }
  if (RngClassInstance) RngClassInstance->irq (number);
}
