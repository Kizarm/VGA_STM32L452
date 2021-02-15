#include "main.h"
/**
 * @brief Test VGA.
 * 
 */
static usbd_device udev;
static cdc_class   cdc_acm (udev);
static Console     console;
//static Echo      echo;
static GpioClass   LedGreen (GpioPortA, 10);

static void delay_frames (const unsigned no) {
  FramesCount = 0u;
  while (FramesCount < no) {
    asm volatile ("wfi");
  }
}
int main (void) {
  EnableDebugOnSleep();
  udev.attach (cdc_acm);
  cdc_acm.init();
  console += cdc_acm;
//console += echo;
  +LedGreen;
  delay_frames (10);
  for (;;) {
    console.pass();
  }
}
