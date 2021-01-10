#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "gpio.h"
#include "fifo.h"
#include "ScanCodes.h"

class Keyboard {
  Fifo<uint8_t, 16> ring;
  GpioClass         sclk;
  GpioClass         miso;
  public:
    Keyboard ();
    void irq ();
    /* ! in main.cpp */
    void Scan (const SDL_SCAN_CODES code, const bool pressed);
    void loop () {
      uint8_t data;
      if (ring.Read(data)) decode (data);
    }
  protected:
    void decode (const uint8_t data);
};

#endif // KEYBOARD_H
