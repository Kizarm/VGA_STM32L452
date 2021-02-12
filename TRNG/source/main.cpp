#include "system.h"
#include "cdc_class.h"
#include "rngclass.h"


static usbd_device udev;
static cdc_class   cdc_acm (udev);
static RngClass    rng;
static GpioClass   led (GpioPortA, 10);
int main (void) {
  EnableDebugOnSleep();
  udev.attach(cdc_acm);
  cdc_acm.init();
  +led;
  while (1) {
    rng.print (&cdc_acm);
    //asm volatile("wfi");
  }
  return 0;
}

#ifdef __clang__
extern "C" void * __aeabi_memmove (void * dest, const void * src, size_t n) {
  const char * s = (const char *) src;
  char       * d = (char       *) dest;
  for (uint32_t i=0; i<n; i++)  d[i] = s[i];
  return dest;
}
#endif //__clang__
