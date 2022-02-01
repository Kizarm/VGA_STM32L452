#include "string.h"
#include "vgawrap.h"

VgaWrap::VgaWrap() : kbd(), sync(), pVideoRAM (sync.getRAM()), sudoku(), canvas(sudoku, 800, 600, pVideoRAM) {

}

void VgaWrap::pass() {
  SDL_SCAN_CODES code;
  if (kbd.getData(code)) {
    ARROWS arr = NO_KEY;
    int    res = 0;
    switch (code) {
      case SDL_SCANCODE_BACKSPACE:
        canvas.backup   ();
        return;
      case SDL_SCANCODE_ESCAPE :
        canvas.drawings ();
        return;
      case SDL_SCANCODE_KP_ENTER :
      case SDL_SCANCODE_RETURN   :
        canvas.enter ();
        return;
      case SDL_SCANCODE_INSERT :
        sudoku.save ();
        return;
      case SDL_SCANCODE_UP     : arr = ARROW_UP;    break;
      case SDL_SCANCODE_DOWN   : arr = ARROW_DOWN;  break;
      case SDL_SCANCODE_LEFT   : arr = ARROW_LEFT;  break;
      case SDL_SCANCODE_RIGHT  : arr = ARROW_RIGHT; break;
      
      case SDL_SCANCODE_1      :
      case SDL_SCANCODE_KP_1   : res = 1; break;
      case SDL_SCANCODE_2      :
      case SDL_SCANCODE_KP_2   : res = 2; break;
      case SDL_SCANCODE_3      :
      case SDL_SCANCODE_KP_3   : res = 3; break;
      case SDL_SCANCODE_4      :
      case SDL_SCANCODE_KP_4   : res = 4; break;
      case SDL_SCANCODE_5      :
      case SDL_SCANCODE_KP_5   : res = 5; break;
      case SDL_SCANCODE_6      :
      case SDL_SCANCODE_KP_6   : res = 6; break;
      case SDL_SCANCODE_7      :
      case SDL_SCANCODE_KP_7   : res = 7; break;
      case SDL_SCANCODE_8      :
      case SDL_SCANCODE_KP_8   : res = 8; break;
      case SDL_SCANCODE_9      :
      case SDL_SCANCODE_KP_9   : res = 9; break;
      default: return;
    }
    if (arr != NO_KEY) {
      canvas.arrow  (arr);
      return;
    }
    if (res) {
      canvas.number (res);
      return;
    }
  } else {
    asm volatile ("wfi");
  }
}
