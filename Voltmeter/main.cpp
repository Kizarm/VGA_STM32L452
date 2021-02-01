#include "main.h"

/**
 * @brief Test VGA.
 * 
 */
typedef float real;
class Filtr {
  public:
    Filtr() {
      for (int i=0; i<6; i++) x[i] = 0.0f;
      for (int i=0; i<5; i++) y[i] = 0.0f;
    };
    real run (real x0) {
      real y0 = 0.0f;
      x[0] = x0 * 4.638681e-04f;
      y0  +=                 x[5];
      y0  +=    +1.062834f * x[4];
      y0  +=    -1.811499f * x[3];
      y0  +=    -1.811499f * x[2];
      y0  +=    +1.062834f * x[1];
      y0  +=                 x[0];
      x[5] = x[4];
      x[4] = x[3];
      x[3] = x[2];
      x[2] = x[1];
      x[1] = x[0];
      y0  +=    +0.881893f * y[2];
      y0  +=    -2.756483f * y[1];
      y0  +=    +2.874357f * y[0];
      y[4] = y[3];
      y[3] = y[2];
      y[2] = y[1];
      y[1] = y[0];
      y[0] = y0;
      return y0;
    };
  private:
    real  x [6], y [5];
};
static Filtr fir;

extern "C" void SysTick_Handler () {
}
static VgaWrap     display;
static AdcClass    adc;

int main (void) {
  EnableDebugOnSleep();
  adc.Init();
  
  display.display();
  
  uint32_t cnt = 0u;
  float sum = 0.0f;
  for (;;) {
    uint16_t td;
    if (adc.get(td)) {
      sum += fir.run ((float) td);
      if (cnt >= 10) {
        cnt = 0u;
        const float n = (sum * 0.02469f);
        display.pointer (n);
        sum = 0.0f;
      }
      cnt += 1;
    } else {
      asm volatile ("wfi");
    }
    
  }
}
