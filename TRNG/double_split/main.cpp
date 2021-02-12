#include "main.h"

/**
 * @brief Test VGA.
 * 
 */

extern "C" void SysTick_Handler () {
}
static VHSync    sync;
static RngClass  trng;
static AdcClass  adc;
static GpioClass LedGreen  (GpioPortA, 10);
static GpioClass LedYellow (GpioPortA,  9);
static GpioClass LedRed    (GpioPortA,  8);

static void delay (const unsigned dly) {
  volatile unsigned n = dly;
  while (n--) {
    asm volatile ("wfi");
  }
}

int main (void) {
  EnableDebugOnSleep();
  adc.Init();
  +LedGreen;
  uint8_t * video = sync.getRAM();
  uint32_t  time  = 10000u;
  for (;;) {
    uint16_t adcv;
    if (adc.get (adcv)) {
      time = iexp (4096u - adcv);
    }
    const uint32_t rn = trng.Read ();
    const unsigned x  = (rn & 0xFFF) % 799;   // posledni bit nepouzit
    const unsigned y  = ((rn >> 12) & 0xFFF) % 600;
    const unsigned z  = rn >> 24;
    if (w_table[x] >= z) {
      const unsigned xa = x >> 3;
      const unsigned xb = x  & 7u;
      const unsigned i  =  100u * y + xa;
      uint8_t & d = video [i];
      d |= 1 << xb;
      ~LedYellow;
    }
    ~LedRed;
    delay (time);
  }
}
