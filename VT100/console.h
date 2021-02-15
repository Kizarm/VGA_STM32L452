#ifndef CONSOLE_H
#define CONSOLE_H

#include "baselayer.h"
#include "keyboard.h"
#include "vgaprint.h"

class Echo : public BaseLayer {
  public:
    Echo      () : BaseLayer() {};
    // Pro konec, který je napsán jako TOP
    uint32_t  Down (const char * data, uint32_t len) {
      return Up (data, len);
    };
};

/** @class Console
 * Třída je postavena jako TOP
 * */

class Console : public BaseLayer {
  Fifo<char, 0x8000> ring;
  Keyboard           kbd;
  VgaPrint           vga;
  public:
    Console ();
    uint32_t Up   (const char * data, uint32_t len) override;
    void pass ();
};

#endif // CONSOLE_H
