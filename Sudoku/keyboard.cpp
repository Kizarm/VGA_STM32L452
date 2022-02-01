#include <string.h>
#include "STM32L4x2.h"
#include "keyboard.h"

template<class T, size_t N> constexpr size_t array_len (T (&)[N]) { return N; }

enum BITSETS {
  RESET = 0,
  SET   = 1,
};
static Keyboard * KeyboardInstance = nullptr;

extern "C" void EXTI9_5_IRQHandler () {
  EXTI.PR1.B.PR5 = 1u;
  if (KeyboardInstance) KeyboardInstance->irq();
}

static inline void ExtInit () {
  // EXTI 5
  RCC.APB2ENR.B.SYSCFGEN = SET;
  while (RCC.APB2ENR.B.SYSCFGEN == RESET);
  SYSCFG.EXTICR2.modify([](SYSCFG_EXTICR2_s & r) -> auto {
    r.B.EXTI5 = 0u;
    return r.R;
  });  
  EXTI.IMR1. B.MR5 = SET;
  EXTI.RTSR1.B.TR5 = SET;         // rissing edge
  NVIC_EnableIRQ (EXTI9_5_IRQn);
}

Keyboard::Keyboard () : ring(), sclk(GpioPortA, 5, GPIO_Mode_IN),
  miso(GpioPortA, 6, GPIO_Mode_IN) {
  KeyboardInstance = this;
  ShiftCtrl = SHIFT_CONTROL_NORMAL;
  ExtInit();
}

void Keyboard::irq() {
  static int bitcount = 0;
  static unsigned char data = 0x00;
  if (bitcount > 0 && bitcount < 9) {
    data >>= 1;
    if (miso.get()) data |= 0x80;
  }
  if (bitcount++ == 10)  {
    decode(data);
    bitcount = 0;
    data = 0x00;
  }
}
void Keyboard::decode (const uint8_t scan_byte) {
  enum SCAN_STATES {
    SCAN_STATE_CODE = 0, SCAN_STATE_MOD, SCAN_STATE_MOD_RET, SCAN_STATE_RET
  };
  static SCAN_STATES state = SCAN_STATE_CODE;
  constexpr uint16_t modif = 0x0100;
  switch (state) {
    case SCAN_STATE_CODE:
      if        (scan_byte == 0xE0) {
        state = SCAN_STATE_MOD;
      } else if (scan_byte == 0xF0) {
        state = SCAN_STATE_RET;
      } else {
        Scan (static_cast<SDL_SCAN_CODES>(scan_byte), true);
        state = SCAN_STATE_CODE;
      } break;
    case SCAN_STATE_MOD:
      if (scan_byte == 0xF0) {
        state = SCAN_STATE_MOD_RET;
      } else {
        Scan (static_cast<SDL_SCAN_CODES>(modif | scan_byte), true);
        state = SCAN_STATE_CODE;
      } break;
    case SCAN_STATE_MOD_RET:
      Scan (static_cast<SDL_SCAN_CODES>(modif | scan_byte), false);
      state = SCAN_STATE_CODE;
      break;
    case SCAN_STATE_RET:
      Scan (static_cast<SDL_SCAN_CODES>(scan_byte), false);
      state = SCAN_STATE_CODE;
      break;
  }
}
void Keyboard::Scan (const SDL_SCAN_CODES code, const bool pressed) {
  if        (code == SDL_SCANCODE_LCTRL or code  == SDL_SCANCODE_RCTRL) {
    if (pressed) ShiftCtrl = SHIFT_CONTROL_CTRL;
    else         ShiftCtrl = SHIFT_CONTROL_NORMAL;
  } else if (code == SDL_SCANCODE_LSHIFT or code == SDL_SCANCODE_RSHIFT) {
    if (pressed) ShiftCtrl = SHIFT_CONTROL_SHIFT;
    else         ShiftCtrl = SHIFT_CONTROL_NORMAL;
  } else {
    if (!pressed)  return;
    ring.Write (code);
  }
}
