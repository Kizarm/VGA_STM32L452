/*  SystemPIO.cpp: Class for emulation of system PIO
  Copyright (c) 2006 Roman Borik <pmd85emu@gmail.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
#include "SystemPIO.h"
//---------------------------------------------------------------------------
SystemPIO::SystemPIO (ChipMemory * mem, const BYTE portAddr, const BYTE portMask, const bool needReset)
 : PeripheralDevice(portAddr, portMask, needReset), ChipPIO8255 (false) {
  this->memory = mem;
  /*
    OnCpuReadB.connect(this, &SystemPIO::ReadKeyboardB);
  */
  ledState = 0;
  ShiftStopCtrl = 0;
  for (int ii = 0; ii < (int) sizeof (KeyColumns); ii++)  KeyColumns[ii] = 0;
}
//---------------------------------------------------------------------------
// methods inherited from PeripheralDevice class
//---------------------------------------------------------------------------
/**
 * Method is executed after CPU reset.
 */
void SystemPIO::ResetDevice (int) {
  ChipReset (false);
}
//---------------------------------------------------------------------------
/**
 * Method is called by CPU during write to ports of system PIO.
 */
void SystemPIO::WriteToDevice (BYTE port, BYTE value, int) {

  memory->ResetOff();

  switch (port & SYSTEM_REG_MASK) {
  case SYSTEM_REG_A:
    CpuWrite (PP_PortA, value);
    break;

  case SYSTEM_REG_B:
    CpuWrite (PP_PortB, value);
    break;

  case SYSTEM_REG_C:
    CpuWrite (PP_PortC, value);
    break;

  case SYSTEM_REG_CWR:
    CpuWrite (PP_CWR, value);
    break;
  }
}
//---------------------------------------------------------------------------
/**
 * Method is called by CPU during read from ports of system PIO.
 */
BYTE SystemPIO::ReadFromDevice (BYTE port, int /*ticks*/) {
  BYTE retval;

  switch (port & SYSTEM_REG_MASK) {
  case SYSTEM_REG_A:
    retval = CpuRead (PP_PortA);
    break;

  case SYSTEM_REG_B:
    retval = CpuRead (PP_PortB);
    break;

  case SYSTEM_REG_C:
    retval = CpuRead (PP_PortC);
    break;

  case SYSTEM_REG_CWR:
    retval = CpuRead (PP_CWR);
    break;

  default:
    retval = 0xFF;
    break;
  }

  return retval;
}
//---------------------------------------------------------------------------
#ifdef  __thumb__
#define KEYBOARD_ENGLISH
typedef uint32_t size_t;
// KEYBOARD MAPS
// vkey, column, rowmask // comment: PMD key (PC key)
const KEYMAP SystemPIO::KeyMap[] = {
  { SDL_SCANCODE_F9,            8,  1 },     // K8   (F9)             0x0001
  { SDL_SCANCODE_F5,            4,  1 },     // K4   (F5)             0x0003
  { SDL_SCANCODE_F3,            2,  1 },     // K2   (F3)             0x0004
  { SDL_SCANCODE_F1,            0,  1 },     // K0   (F1)             0x0005
  { SDL_SCANCODE_F2,            1,  1 },     // K1   (F2)             0x0006
  { SDL_SCANCODE_F12,          11,  1 },     // K11  (F12)            0x0007
  { SDL_SCANCODE_F10,           9,  1 },     // K9   (F10)            0x0009
  { SDL_SCANCODE_F8,            7,  1 },     // K7   (F8)             0x000A
  { SDL_SCANCODE_F6,            5,  1 },     // K5   (F6)             0x000B
  { SDL_SCANCODE_F4,            3,  1 },     // K3   (F4)             0x000C
  { SDL_SCANCODE_TAB,          13,  1 },     // C-D       (Tab)       0x000D
  { SDL_SCANCODE_GRAVE,        12,  1 },     // WRK  (`)              0x000E
  { SDL_SCANCODE_Q,             0,  4 },     // Q                     0x0015
  { SDL_SCANCODE_1,             0,  2 },     // 1                     0x0016
#ifdef KEYBOARD_ENGLISH
  { SDL_SCANCODE_Z,             5,  4 },     // Z                     0x001A
#else  
  { SDL_SCANCODE_Z,             1, 16 },     // Y                     0x001A
#endif // KEYBOARD_ENGLISH
  { SDL_SCANCODE_S,             1,  8 },     // S                     0x001B
  { SDL_SCANCODE_A,             0,  8 },     // A                     0x001C
  { SDL_SCANCODE_W,             1,  4 },     // W                     0x001D
  { SDL_SCANCODE_2,             1,  2 },     // 2                     0x001E
  { SDL_SCANCODE_C,             3, 16 },     // C                     0x0021
  { SDL_SCANCODE_X,             2, 16 },     // X                     0x0022
  { SDL_SCANCODE_D,             2,  8 },     // D                     0x0023
  { SDL_SCANCODE_E,             2,  4 },     // E                     0x0024
  { SDL_SCANCODE_4,             3,  2 },     // 4                     0x0025
  { SDL_SCANCODE_3,             2,  2 },     // 3                     0x0026
  { SDL_SCANCODE_SPACE,         0, 16 },     // SPACE                 0x0029
  { SDL_SCANCODE_V,             4, 16 },     // V                     0x002A
  { SDL_SCANCODE_F,             3,  8 },     // F                     0x002B
  { SDL_SCANCODE_T,             4,  4 },     // T                     0x002C
  { SDL_SCANCODE_R,             3,  4 },     // R                     0x002D
  { SDL_SCANCODE_5,             4,  2 },     // 5                     0x002E
  { SDL_SCANCODE_N,             6, 16 },     // N                     0x0031
  { SDL_SCANCODE_B,             5, 16 },     // B                     0x0032
  { SDL_SCANCODE_H,             5,  8 },     // H                     0x0033
  { SDL_SCANCODE_G,             4,  8 },     // G                     0x0034
#ifdef KEYBOARD_ENGLISH
  { SDL_SCANCODE_Y,             1, 16 },     // Y                     0x0035
#else
  { SDL_SCANCODE_Y,             5,  4 },     // Z                     0x0035
#endif // KEYBOARD_ENGLISH
  { SDL_SCANCODE_6,             5,  2 },     // 6                     0x0036
  { SDL_SCANCODE_M,             7, 16 },     // M                     0x003A
  { SDL_SCANCODE_J,             6,  8 },     // J                     0x003B
  { SDL_SCANCODE_U,             6,  4 },     // U                     0x003C
  { SDL_SCANCODE_7,             6,  2 },     // 7                     0x003D
  { SDL_SCANCODE_8,             7,  2 },     // 8                     0x003E
  { SDL_SCANCODE_COMMA,         8, 16 },     // ,    (,)              0x0041
  { SDL_SCANCODE_K,             7,  8 },     // K                     0x0042
  { SDL_SCANCODE_I,             7,  4 },     // I                     0x0043
  { SDL_SCANCODE_O,             8,  4 },     // O                     0x0044
  { SDL_SCANCODE_0,             9,  2 },     // 0                     0x0045
  { SDL_SCANCODE_9,             8,  2 },     // 9                     0x0046
  { SDL_SCANCODE_PERIOD,        9, 16 },     // .    (.)              0x0049
  { SDL_SCANCODE_SLASH,        10, 16 },     // /    (/)              0x004A
  { SDL_SCANCODE_L,             8,  8 },     // L                     0x004B
  { SDL_SCANCODE_SEMICOLON,     9,  8 },     // ;    (')              0x004C
  { SDL_SCANCODE_P,             9,  4 },     // P                     0x004D
  { SDL_SCANCODE_MINUS,        10,  2 },     // _    (-)              0x004E
  { SDL_SCANCODE_APOSTROPHE,   10,  8 },     // :    (;)              0x0052
  { SDL_SCANCODE_LEFTBRACKET,  10,  4 },     // @    ([)              0x0054
  { SDL_SCANCODE_EQUALS,       11,  8 },     // [ ]  (=)              0x0055
  { SDL_SCANCODE_RETURN,       14, 16 },     // right EOL (Enter)     0x005A
  { SDL_SCANCODE_RIGHTBRACKET, 11,  4 },     // \    (])              0x005B
  { SDL_SCANCODE_BACKSLASH,    11,  2 },     // { }  (\)              0x005D
  { SDL_SCANCODE_KP_1,          0,  2 },     // Num 1                 0x0069
  { SDL_SCANCODE_KP_4,          3,  2 },     // Num 4                 0x006B
  { SDL_SCANCODE_KP_7,          6,  2 },     // Num 7                 0x006C
  { SDL_SCANCODE_KP_0,          9,  2 },     // Num 0                 0x0070
  { SDL_SCANCODE_KP_PERIOD,     9, 16 },     // Num .                 0x0071
  { SDL_SCANCODE_KP_2,          1,  2 },     // Num 2                 0x0072
  { SDL_SCANCODE_KP_5,          4,  2 },     // Num 5                 0x0073
  { SDL_SCANCODE_KP_6,          5,  2 },     // Num 6                 0x0074
  { SDL_SCANCODE_KP_8,          7,  2 },     // Num 8                 0x0075
  { SDL_SCANCODE_F11,          10,  1 },     // K10  (F11)            0x0078
  { SDL_SCANCODE_KP_PLUS,       9, 40 },     // Num +                 0x0079
  { SDL_SCANCODE_KP_3,          2,  2 },     // Num 3                 0x007A
  { SDL_SCANCODE_KP_MINUS,      9, 34 },     // Num -                 0x007B
  { SDL_SCANCODE_KP_MULTIPLY,  10, 40 },     // Num *                 0x007C
  { SDL_SCANCODE_KP_9,          8,  2 },     // Num 9                 0x007D
  { SDL_SCANCODE_F7,            6,  1 },     // K6   (F7)             0x0083
  { SDL_SCANCODE_KP_DIVIDE,    10, 16 },     // Num /                 0x014A
  { SDL_SCANCODE_KP_ENTER,     13, 16 },     // left EOL  (Enter)     0x015A
  { SDL_SCANCODE_END,          13,  8 },     // END    (End)          0x0169
  { SDL_SCANCODE_LEFT,         12,  4 },     // <--    (Left)         0x016B
  { SDL_SCANCODE_HOME,         13,  4 },     // HOME   (Home)         0x016C
  { SDL_SCANCODE_INSERT,       12,  2 },     // INS    (Insert)       0x0170
  { SDL_SCANCODE_DELETE,       13,  2 },     // DEL    (Delete)       0x0171
  { SDL_SCANCODE_DOWN,         14,  8 },     // -->]   (Down)         0x0172
  { SDL_SCANCODE_RIGHT,        14,  4 },     // -->    (Right)        0x0174
  { SDL_SCANCODE_UP,           12,  8 },     // [<--   (Up)           0x0175
  { SDL_SCANCODE_PAGEDOWN,     14,  2 },     // CLR    (Page Down)    0x017A
  { SDL_SCANCODE_PAGEUP,       14,  1 },     // RCL    (Page Up)      0x017D
  { SDL_SCANCODE_EXIT,          0,  0 },     // UNUSED                0xF000
};
#else
// KEYBOARD MAPS
// vkey, column, rowmask // comment: PMD key (PC key)
const KEYMAP SystemPIO::KeyMap[] = {
//{ SDL_SCANCODE_CAPSLOCK,     12, 16 },  // CapsLock for PMD 85-3 we can't handle
  { SDL_SCANCODE_SPACE,         0, 16 },     // SPACE                 0x00000020
  { SDL_SCANCODE_APOSTROPHE,   10,  8 },     // :    (;)              0x00000027
  { SDL_SCANCODE_COMMA,         8, 16 },     // ,    (,)              0x0000002C
  { SDL_SCANCODE_MINUS,        10,  2 },     // _    (-)              0x0000002D
  { SDL_SCANCODE_PERIOD,        9, 16 },     // .    (.)              0x0000002E
  { SDL_SCANCODE_SLASH,        10, 16 },     // /    (/)              0x0000002F
  { SDL_SCANCODE_0,             9,  2 },     // 0                     0x00000030
  { SDL_SCANCODE_1,             0,  2 },     // 1                     0x00000031
  { SDL_SCANCODE_2,             1,  2 },     // 2                     0x00000032
  { SDL_SCANCODE_3,             2,  2 },     // 3                     0x00000033
  { SDL_SCANCODE_4,             3,  2 },     // 4                     0x00000034
  { SDL_SCANCODE_5,             4,  2 },     // 5                     0x00000035
  { SDL_SCANCODE_6,             5,  2 },     // 6                     0x00000036
  { SDL_SCANCODE_7,             6,  2 },     // 7                     0x00000037
  { SDL_SCANCODE_8,             7,  2 },     // 8                     0x00000038
  { SDL_SCANCODE_9,             8,  2 },     // 9                     0x00000039
  { SDL_SCANCODE_SEMICOLON,     9,  8 },     // ;    (')              0x0000003B
  { SDL_SCANCODE_EQUALS,       11,  8 },     // [ ]  (=)              0x0000003D
  { SDL_SCANCODE_A,             0,  8 },     // A                     0x00000041
  { SDL_SCANCODE_B,             5, 16 },     // B                     0x00000042
  { SDL_SCANCODE_C,             3, 16 },     // C                     0x00000043
  { SDL_SCANCODE_D,             2,  8 },     // D                     0x00000044
  { SDL_SCANCODE_E,             2,  4 },     // E                     0x00000045
  { SDL_SCANCODE_F,             3,  8 },     // F                     0x00000046
  { SDL_SCANCODE_G,             4,  8 },     // G                     0x00000047
  { SDL_SCANCODE_H,             5,  8 },     // H                     0x00000048
  { SDL_SCANCODE_I,             7,  4 },     // I                     0x00000049
  { SDL_SCANCODE_J,             6,  8 },     // J                     0x0000004A
  { SDL_SCANCODE_K,             7,  8 },     // K                     0x0000004B
  { SDL_SCANCODE_L,             8,  8 },     // L                     0x0000004C
  { SDL_SCANCODE_M,             7, 16 },     // M                     0x0000004D
  { SDL_SCANCODE_N,             6, 16 },     // N                     0x0000004E
  { SDL_SCANCODE_O,             8,  4 },     // O                     0x0000004F
  { SDL_SCANCODE_P,             9,  4 },     // P                     0x00000050
  { SDL_SCANCODE_Q,             0,  4 },     // Q                     0x00000051
  { SDL_SCANCODE_R,             3,  4 },     // R                     0x00000052
  { SDL_SCANCODE_S,             1,  8 },     // S                     0x00000053
  { SDL_SCANCODE_T,             4,  4 },     // T                     0x00000054
  { SDL_SCANCODE_U,             6,  4 },     // U                     0x00000055
  { SDL_SCANCODE_V,             4, 16 },     // V                     0x00000056
  { SDL_SCANCODE_W,             1,  4 },     // W                     0x00000057
  { SDL_SCANCODE_X,             2, 16 },     // X                     0x00000058
  { SDL_SCANCODE_Y,             5,  4 },     // Z                     0x00000059
  { SDL_SCANCODE_Z,             1, 16 },     // Y                     0x0000005A
  { SDL_SCANCODE_LEFTBRACKET,  10,  4 },     // @    ([)              0x0000005B
  { SDL_SCANCODE_BACKSLASH,    11,  2 },     // { }  (\)              0x0000005C
  { SDL_SCANCODE_RIGHTBRACKET, 11,  4 },     // \    (])              0x0000005D
  { SDL_SCANCODE_GRAVE,        12,  1 },     // WRK  (`)              0x00000060
  { SDL_SCANCODE_TAB,          13,  1 },     // C-D       (Tab)       0x01000001
  { SDL_SCANCODE_KP_ENTER,     13, 16 },     // left EOL  (Enter)     0x01000004
  { SDL_SCANCODE_RETURN,       14, 16 },     // right EOL (Enter)     0x01000005
  { SDL_SCANCODE_INSERT,       12,  2 },     // INS    (Insert)       0x01000006
  { SDL_SCANCODE_DELETE,       13,  2 },     // DEL    (Delete)       0x01000007
  { SDL_SCANCODE_HOME,         13,  4 },     // HOME   (Home)         0x01000010
  { SDL_SCANCODE_END,          13,  8 },     // END    (End)          0x01000011
  { SDL_SCANCODE_LEFT,         12,  4 },     // <--    (Left)         0x01000012
  { SDL_SCANCODE_UP,           12,  8 },     // [<--   (Up)           0x01000013
  { SDL_SCANCODE_RIGHT,        14,  4 },     // -->    (Right)        0x01000014
  { SDL_SCANCODE_DOWN,         14,  8 },     // -->]   (Down)         0x01000015
  { SDL_SCANCODE_PAGEUP,       14,  1 },     // RCL    (Page Up)      0x01000016
  { SDL_SCANCODE_PAGEDOWN,     14,  2 },     // CLR    (Page Down)    0x01000017
  { SDL_SCANCODE_F1,            0,  1 },     // K0   (F1)             0x01000030
  { SDL_SCANCODE_F2,            1,  1 },     // K1   (F2)             0x01000031
  { SDL_SCANCODE_F3,            2,  1 },     // K2   (F3)             0x01000032
  { SDL_SCANCODE_F4,            3,  1 },     // K3   (F4)             0x01000033
  { SDL_SCANCODE_F5,            4,  1 },     // K4   (F5)             0x01000034
  { SDL_SCANCODE_F6,            5,  1 },     // K5   (F6)             0x01000035
  { SDL_SCANCODE_F7,            6,  1 },     // K6   (F7)             0x01000036
  { SDL_SCANCODE_F8,            7,  1 },     // K7   (F8)             0x01000037
  { SDL_SCANCODE_F9,            8,  1 },     // K8   (F9)             0x01000038
  { SDL_SCANCODE_F10,           9,  1 },     // K9   (F10)            0x01000039
  { SDL_SCANCODE_F11,          10,  1 },     // K10  (F11)            0x0100003A
  { SDL_SCANCODE_F12,          11,  1 },     // K11  (F12)            0x0100003B
  { SDL_SCANCODE_END_TAB,       0,  0 },     // UNUSED                0x02000000
};
#endif //  __thumb__
//---------------------------------------------------------------------------
#if 0
/**
 * This method identifies a map of keyboard matrix based on keys pressed.
 * It is called repeatedly by Refresh timer.
 * The keymap is being searched based on computer model.
 */
void SystemPIO::ScanKeyboard (BYTE * KeyBuffer) {
  // static BYTE keyExchZY, keyExchYZ;

  if (KeyBuffer == nullptr) return;
/*
  // pressing of ALT/META resets whole matrix because it's used for hotkeys
  if (KeyBuffer[SDL_SCANCODE_APPLICATION] || KeyBuffer[SDL_SCANCODE_LALT] || KeyBuffer[SDL_SCANCODE_RALT]
      || KeyBuffer[SDL_SCANCODE_LGUI] || KeyBuffer[SDL_SCANCODE_RGUI]) {
    for (int ii = 0; ii < (int) sizeof (KeyColumns); ii++)
      KeyColumns[ii] = 0;
    ShiftStopCtrl = 0;
    return;
  }
*/

  int bi = 0;
  // ********** PMD 85 **********
  while (KeyMap[bi].vkey) {
    if (KeyBuffer[KeyMap[bi].vkey]) KeyColumns[KeyMap[bi].column] |=  KeyMap[bi].rowmask;
    else                            KeyColumns[KeyMap[bi].column] &= ~KeyMap[bi].rowmask;
    bi++;
  }
  // BackSpace
  if (KeyBuffer[SDL_SCANCODE_BACKSPACE] && !KeyBuffer[SDL_SCANCODE_LEFT]) KeyColumns[12] |= 4;
  // SHIFT
  if (KeyBuffer[SDL_SCANCODE_LSHIFT] || KeyBuffer[SDL_SCANCODE_RSHIFT])   ShiftStopCtrl |=  0x20;
  else                                                                    ShiftStopCtrl &= ~0x20;
  // STOP
  if (KeyBuffer[SDL_SCANCODE_ESCAPE] || KeyBuffer[SDL_SCANCODE_LCTRL] || KeyBuffer[SDL_SCANCODE_RCTRL])   ShiftStopCtrl |=  0x40;
  else                                                                                                    ShiftStopCtrl &= ~0x40;
}
#endif // 0
// tahle neprůhledná konstrukce je modernější obdoba makra jako je sizeof array / sizeof member
template<class T, size_t N> constexpr size_t array_len (T (&)[N]) { return N; }
// metoda bisekce bude asi efektivnejsi, pole je setridene podle vkey
int SystemPIO::range (const SDL_SCAN_CODES x) const {
  int l = 0, r = array_len (KeyMap) - 1;

  while (l <= r) {
    const int s = (l + r) >> 1;
    const SDL_SCAN_CODES x0 = KeyMap [s].vkey;
    if      (x0 < x) l = s + 1;
    else if (x0 > x) r = s - 1;
    else return s;
  }
  return -1;
}

void SystemPIO::KeyBoardAsync (const SDL_SCAN_CODES code, const bool pressed) {
  if (code == SDL_SCANCODE_BACKSPACE) {
    if (pressed) KeyColumns[12] |=  0x04;
    else         KeyColumns[12] &= ~0x04;
  } else if (code == SDL_SCANCODE_ESCAPE) {
    if (pressed) ShiftStopCtrl |=  0x40;
    else         ShiftStopCtrl &= ~0x40;
  } else if (code == SDL_SCANCODE_LSHIFT or code == SDL_SCANCODE_RSHIFT) {
    if (pressed) ShiftStopCtrl |=  0x20;
    else         ShiftStopCtrl &= ~0x20;
  } else {
    const int  index   = range (code);
    const bool intable = (index < 0) ? false : true;
    if (intable) {
      // debug ("In Table %08X, %s, index = %d\n", (int) code, pressed ? "pressed" : "release", index);
      const unsigned ci = KeyMap [index].column;
      const uint8_t  bi = KeyMap [index].rowmask;
      if (pressed) KeyColumns [ci] |=  bi;
      else         KeyColumns [ci] &= ~bi;
    } else {
      debug ("Unsupported code 0x%08X\n", code);
    }  
  }
}

//---------------------------------------------------------------------------
/**
 * Method is used as notification function during reading of Port B.
 * Method setup status of Port B which represents currently addressed column
 * of key matrix.
 */
void SystemPIO::ReadKeyboardB() {
  BYTE val;

  val = (BYTE) ( (~KeyColumns[PeripheralReadByte (PP_PortA) & 0x0F] & 0x1F) | (~ShiftStopCtrl & 0x60));

  PeripheralWriteByte (PP_PortB, val);
}
//---------------------------------------------------------------------------
