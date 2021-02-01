#include "main.h"

/**
 * @brief VGA na STM32L452, emulace PMD85v2A.
 * 
 */
extern "C" void SysTick_Handler () {
  // zatím nepoužito
}

static VHSync   vhsync;
static Keyboard keyboard;
static PMD85v2A pmd;

void Keyboard::Scan (const SDL_SCAN_CODES code, const bool pressed) {
  pmd.Keyboard (code, pressed);
}

int main (void) {
  EnableDebugOnSleep();
  vhsync.Init (pmd.Base());
  pmd.Init  ();
  pmd.Reset ();

  for (;;) {
    // asm volatile ("wfi"); // brždění není potřeba, ve smyčce je docela dost kódu
    pmd     .Step ();
    keyboard.loop ();
  }
}
#ifndef USE_USB 
extern "C" {
  // not needed
  void __cxa_pure_virtual () {
  }
};
#endif