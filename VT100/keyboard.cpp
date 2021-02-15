#include <string.h>
#include "STM32L4x2.h"
#include "keyboard.h"
#include "console.h"

template<class T, size_t N> constexpr size_t array_len (T (&)[N]) { return N; }

struct KEYMAP {
  SDL_SCAN_CODES code;
  const char * normal, * shifted, * ctrl;
};
// keycodes VT52
static const KEYMAP KeyMap[] = {
  { SDL_SCANCODE_F9,            "",  "",        "" },     // K8   (F9)             0x0001
  { SDL_SCANCODE_F5,            "",  "",        "" },     // K4   (F5)             0x0003
  { SDL_SCANCODE_F3,            "",  "",        "" },     // K2   (F3)             0x0004
  { SDL_SCANCODE_F1,            "",  "",        "" },     // K0   (F1)             0x0005
  { SDL_SCANCODE_F2,            "",  "",        "" },     // K1   (F2)             0x0006
  { SDL_SCANCODE_F12,        "run $shutup\r","","" },     // K11  (F12)            0x0007
  { SDL_SCANCODE_F10,           "",  "",        "" },     // K9   (F10)            0x0009
  { SDL_SCANCODE_F8,            "",  "",        "" },     // K7   (F8)             0x000A
  { SDL_SCANCODE_F6,            "",  "",        "" },     // K5   (F6)             0x000B
  { SDL_SCANCODE_F4,            "",  "",        "" },     // K3   (F4)             0x000C
  { SDL_SCANCODE_TAB,           "\t",  "\t",    "" },     // C-D       (Tab)       0x000D
  { SDL_SCANCODE_GRAVE,         "`",  "~",      "" },     // WRK  (`)              0x000E
  { SDL_SCANCODE_Q,             "q",  "Q",  "\x11" },     // Q                     0x0015
  { SDL_SCANCODE_1,             "1",  "!",      "" },     // 1                     0x0016
  { SDL_SCANCODE_Z,             "z",  "Z",  "\x1A" },     // Y                     0x001A
  { SDL_SCANCODE_S,             "s",  "S",  "\x13" },     // S                     0x001B
  { SDL_SCANCODE_A,             "a",  "A",  "\x01" },     // A                     0x001C
  { SDL_SCANCODE_W,             "w",  "W",  "\x17" },     // W                     0x001D
  { SDL_SCANCODE_2,             "2",  "@",      "" },     // 2                     0x001E
  { SDL_SCANCODE_C,             "c",  "C",  "\x03" },     // C                     0x0021
  { SDL_SCANCODE_X,             "x",  "X",  "\x18" },     // X                     0x0022
  { SDL_SCANCODE_D,             "d",  "D",  "\x04" },     // D                     0x0023
  { SDL_SCANCODE_E,             "e",  "E",  "\x05" },     // E                     0x0024
  { SDL_SCANCODE_4,             "4",  "$",      "" },     // 4                     0x0025
  { SDL_SCANCODE_3,             "3",  "#",      "" },     // 3                     0x0026
  { SDL_SCANCODE_SPACE,         " ",  " ",      "" },     // SPACE                 0x0029
  { SDL_SCANCODE_V,             "v",  "V",  "\x16" },     // V                     0x002A
  { SDL_SCANCODE_F,             "f",  "F",  "\x06" },     // F                     0x002B
  { SDL_SCANCODE_T,             "t",  "T",  "\x14" },     // T                     0x002C
  { SDL_SCANCODE_R,             "r",  "R",  "\x12" },     // R                     0x002D
  { SDL_SCANCODE_5,             "5",  "%",      "" },     // 5                     0x002E
  { SDL_SCANCODE_N,             "n",  "N",  "\x0D" },     // N                     0x0031
  { SDL_SCANCODE_B,             "b",  "B",  "\x02" },     // B                     0x0032
  { SDL_SCANCODE_H,             "h",  "H",  "\x08" },     // H                     0x0033
  { SDL_SCANCODE_G,             "g",  "G",  "\x07" },     // G                     0x0034
  { SDL_SCANCODE_Y,             "y",  "Y",  "\x19" },     // Z                     0x0035
  { SDL_SCANCODE_6,             "6",  "^",      "" },     // 6                     0x0036
  { SDL_SCANCODE_M,             "m",  "M",  "\x0D" },     // M                     0x003A
  { SDL_SCANCODE_J,             "j",  "J",  "\x0A" },     // J                     0x003B
  { SDL_SCANCODE_U,             "u",  "U",  "\x15" },     // U                     0x003C
  { SDL_SCANCODE_7,             "7",  "&",      "" },     // 7                     0x003D
  { SDL_SCANCODE_8,             "8",  "*",      "" },     // 8                     0x003E
  { SDL_SCANCODE_COMMA,         ",",  "<",      "" },     // ,    (,)              0x0041
  { SDL_SCANCODE_K,             "k",  "K",  "\x0B" },     // K                     0x0042
  { SDL_SCANCODE_I,             "i",  "I",  "\x09" },     // I                     0x0043
  { SDL_SCANCODE_O,             "o",  "O",  "\x0F" },     // O                     0x0044
  { SDL_SCANCODE_0,             "0",  ")",      "" },     // 0                     0x0045
  { SDL_SCANCODE_9,             "9",  "(",      "" },     // 9                     0x0046
  { SDL_SCANCODE_PERIOD,        ".",  ">",      "" },     // .    (.)              0x0049
  { SDL_SCANCODE_SLASH,         "/",  "?",      "" },     // /    (/)              0x004A
  { SDL_SCANCODE_L,             "l",  "L",  "\x0C" },     // L                     0x004B
  { SDL_SCANCODE_SEMICOLON,     ";",  ":",      "" },     // ;    (')              0x004C
  { SDL_SCANCODE_P,             "p",  "P",  "\x10" },     // P                     0x004D
  { SDL_SCANCODE_MINUS,         "-",  "_",      "" },     // _    (-)              0x004E
  { SDL_SCANCODE_APOSTROPHE,    "\'",  "\"",    "" },     // :    (;)              0x0052
  { SDL_SCANCODE_LEFTBRACKET,   "[",  "{",      "" },     // @    ([)              0x0054
  { SDL_SCANCODE_EQUALS,        "=",  "+",      "" },     // [ ]  (=)              0x0055
  { SDL_SCANCODE_RETURN,        "\x0D", "\x0D", "" },     // right EOL (Enter)     0x005A
  { SDL_SCANCODE_RIGHTBRACKET,  "]",  "}",      "" },     // \    (])              0x005B
  { SDL_SCANCODE_BACKSLASH,     "\\",  "|",     "" },     // { }  (\)              0x005D
  { SDL_SCANCODE_BACKSPACE,    "\x7F","\x08","\x1B""D" }, //                       0x0066
  { SDL_SCANCODE_KP_1,          "1",  "1",  "\x1B""?q" }, // Num 1                 0x0069
  { SDL_SCANCODE_KP_4,          "4",  "4",  "\x1B""?t" }, // Num 4                 0x006B
  { SDL_SCANCODE_KP_7,          "7",  "7",  "\x1B""?w" }, // Num 7                 0x006C
  { SDL_SCANCODE_KP_0,          "0",  "0",  "\x1B""?p" }, // Num 0                 0x0070
  { SDL_SCANCODE_KP_PERIOD,     ".",  ".",  "\x1B""?n" }, // Num .                 0x0071
  { SDL_SCANCODE_KP_2,          "2",  "2",  "\x1B""?r" }, // Num 2                 0x0072
  { SDL_SCANCODE_KP_5,          "5",  "5",  "\x1B""?u" }, // Num 5                 0x0073
  { SDL_SCANCODE_KP_6,          "6",  "6",  "\x1B""?v" }, // Num 6                 0x0074
  { SDL_SCANCODE_KP_8,          "8",  "8",  "\x1B""?x" }, // Num 8                 0x0075
  { SDL_SCANCODE_ESCAPE,        "\x1B","\x1B",      "" }, //                       0x0076
  { SDL_SCANCODE_F11, "12:00 01-jan-99\r","" ,      "" }, // K10  (F11)            0x0078
  { SDL_SCANCODE_KP_PLUS,       "+",  "+",          "" }, // Num +                 0x0079
  { SDL_SCANCODE_KP_3,          "3",  "3",  "\x1B""?s" }, // Num 3                 0x007A
  { SDL_SCANCODE_KP_MINUS,      "-",  "-",          "" }, // Num -                 0x007B
  { SDL_SCANCODE_KP_MULTIPLY,   "*",  "*",          "" }, // Num *                 0x007C
  { SDL_SCANCODE_KP_9,          "9",  "9",  "\x1B""?y" }, // Num 9                 0x007D
  { SDL_SCANCODE_F7,            "",  "",            "" }, // K6   (F7)             0x0083
  { SDL_SCANCODE_KP_DIVIDE,     "/",  "/",          "" }, // Num /                 0x014A
  { SDL_SCANCODE_KP_ENTER, "\x0A",  "\x0A", "\x1B""?M" }, // left EOL  (Enter)     0x015A
  { SDL_SCANCODE_END,           "\x05",  "",        "" }, // END    (End)          0x0169
  { SDL_SCANCODE_LEFT,          "\x1B""[D",  "",    "" }, // <--    (Left)         0x016B
  { SDL_SCANCODE_HOME,          "\x01","\x1B""H",   "" }, // HOME   (Home)         0x016C
  { SDL_SCANCODE_INSERT,                      "","","" }, // INS    (Insert)       0x0170
  { SDL_SCANCODE_DELETE,        "\x7F",     "",     "" }, // DEL    (Delete)       0x0171
  { SDL_SCANCODE_DOWN,          "\x1B""[B",  "",    "" }, // -->]   (Down)         0x0172
  { SDL_SCANCODE_RIGHT,         "\x1B""[C",  "",    "" }, // -->    (Right)        0x0174
  { SDL_SCANCODE_UP,            "\x1B""[A",  "",    "" }, // [<--   (Up)           0x0175
  { SDL_SCANCODE_PAGEDOWN,      "",  "",            "" }, // CLR    (Page Down)    0x017A
  { SDL_SCANCODE_PAGEUP,                      "","","" }, // RCL    (Page Up)      0x017D
  { SDL_SCANCODE_EXIT,          "",  "",            "" }, // UNUSED                0xF000
};

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

Keyboard::Keyboard (Console * p) : parent(p), /*ring(),*/ sclk(GpioPortA, 5, GPIO_Mode_IN),
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
// metoda bisekce bude asi efektivnejsi, pole je setridene podle code
static const int range (const SDL_SCAN_CODES x) {
  int l = 0, r = array_len (KeyMap) - 1;

  while (l <= r) {
    const int s = (l + r) >> 1;
    const SDL_SCAN_CODES x0 = KeyMap [s].code;
    if      (x0 < x) l = s + 1;
    else if (x0 > x) r = s - 1;
    else return s;
  }
  return -1;
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
    const int  index    = range (code);
    if (index < 0) return;
    const KEYMAP & line = KeyMap [index];
    const char * pd = line.normal;
    switch (ShiftCtrl) {
      case SHIFT_CONTROL_NORMAL: pd = line.normal;  break;
      case SHIFT_CONTROL_SHIFT:  pd = line.shifted; break;
      case SHIFT_CONTROL_CTRL:   pd = line.ctrl;    break;
    }
    if (!pd)       return;
    const int len = strlen (pd);
    if (!len)      return;
    for (int n=0; n<len; n++) {
      parent->Down  (pd + n, 1);
    }
  }
}
