#include "STM32L4x2.h"
#include "rngclass.h"

RngClass::RngClass() {
  RCC.AHB2ENR.B.RNGEN = 1u;
  RNG.CR.modify([](RNG_CR_s & r) -> auto {
    r.B.RNGEN = 1u;
    return r.R;
  });
}
uint32_t RngClass::Read () const {
  while (!RNG.SR.B.DRDY) {
    asm volatile ("wfi");
  }
  return RNG.DR;
}

