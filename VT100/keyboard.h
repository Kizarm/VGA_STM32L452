#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "gpio.h"
#include "fifo.h"
#include "ScanCodes.h"

class Console;

enum SHIFT_CONTROL {
  SHIFT_CONTROL_NORMAL = 0, SHIFT_CONTROL_SHIFT, SHIFT_CONTROL_CTRL
};

class Keyboard {
  Console * parent;
  // Fifo<char, 8u> ring;
  GpioClass sclk;
  GpioClass miso;
  SHIFT_CONTROL ShiftCtrl;
  public:
    Keyboard (Console * p);
    void irq ();
    /*
    bool getData (char & data) {
      return ring.Read (data);
    }
    */
    void Scan (const SDL_SCAN_CODES code, const bool pressed);
  protected:
    void decode (const uint8_t data);
};

#endif // KEYBOARD_H
