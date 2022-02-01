#ifndef VGAWRAP_H
#define VGAWRAP_H

#include "keyboard.h"
#include "vhsync.h"
#include "canvas.h"
#include "sudoku.h"

class VgaWrap {
  Keyboard        kbd;
  VHSync          sync;
  uint8_t       * pVideoRAM;    // placeholder
  Sudoku          sudoku;
  Canvas          canvas;
  public:
    VgaWrap();
    void display () {
      canvas.drawings();
    }
    void pass ();
};

#endif // VGAWRAP_H
