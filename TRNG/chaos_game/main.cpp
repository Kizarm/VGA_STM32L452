#include "main.h"

/**
 * @brief Test VGA.
 * 
 */
/*
static GpioClass LedYellow (GpioPortA,  9);
static GpioClass LedRed    (GpioPortA,  8);
*/
static ChaosGame game;

int main (void) {
  EnableDebugOnSleep();
  game.Init();
  for (;;) {
    game.Pass();
  }
}
