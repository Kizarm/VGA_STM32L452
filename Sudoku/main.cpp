#include "main.h"

/**
 * @brief Test VGA.
 * 
 */
static VgaWrap display;

int main (void) {
  EnableDebugOnSleep();
  
  display.display();
  for (;;) {
    display.pass();
  }
}
