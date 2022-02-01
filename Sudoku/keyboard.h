#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "gpio.h"
#include "fifo.h"
#include "ScanCodes.h"

enum SHIFT_CONTROL {
  SHIFT_CONTROL_NORMAL = 0, SHIFT_CONTROL_SHIFT, SHIFT_CONTROL_CTRL
};

class Keyboard {
  Fifo<SDL_SCAN_CODES, 8u> ring;
  GpioClass sclk;
  GpioClass miso;
  SHIFT_CONTROL ShiftCtrl;
  public:
    Keyboard ();
    void irq ();
    
    bool getData (SDL_SCAN_CODES & data) {
      return ring.Read (data);
    }
    
    void Scan (const SDL_SCAN_CODES code, const bool pressed);
  protected:
    void decode (const uint8_t data);
};

#endif // KEYBOARD_H
