/*  SystemPIO.h: Class for emulation of system PIO
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
#ifndef SystemPIOH
#define SystemPIOH
//---------------------------------------------------------------------------
#include "Globals.h"
#include "ChipPIO8255.h"
#include "ChipMemory.h"
#include "ScanCodes.h"
//---------------------------------------------------------------------------
#define BEEP_FREQ_SEPARATED

#define SYSTEM_PIO_MASK   0x8C
#define SYSTEM_PIO_ADR    0x84

#define SYSTEM_REG_MASK   0x8F
#define SYSTEM_REG_A      0x84
#define SYSTEM_REG_B      0x85
#define SYSTEM_REG_C      0x86
#define SYSTEM_REG_CWR    0x87

#ifdef BEEP_FREQ_SEPARATED
#define HALF_PERIOD_1KH   ((CPU_FREQ / 1000) / 2) // 1 kHz  (R9 from horizontal synchronization)
#define HALF_PERIOD_4KH   ((CPU_FREQ / 4000) / 2) // 4 kHz  (R7 from horizontal synchronization)
#else
#define R_CNT_PERIOD      (CPU_FREQ / 1024000)    // STB 1,024 MHz
#define R_MAX_COUNT       (20480 * R_CNT_PERIOD)
#define R9_MASK           (1 << (9 + 1))
#define R7_MASK           (1 << (7 + 1))
#endif
//---------------------------------------------------------------------------
// keyboard map structure
typedef struct {
  SDL_SCAN_CODES vkey;
  BYTE           column;
  BYTE           rowmask;
} KEYMAP;
//---------------------------------------------------------------------------
class SystemPIO : public PeripheralDevice, public ChipPIO8255 {
  public:
    SystemPIO (ChipMemory * mem, const BYTE portAddr, const BYTE portMask, const bool needReset);

    void ResetDevice    (int ticks)                        override;
    void WriteToDevice  (BYTE port, BYTE value, int ticks) override;
    BYTE ReadFromDevice (BYTE port, int ticks)             override;
    /* budeme volat externe, klavesnice sdili pamet - KeyColumns[], to je vse */
    void KeyBoardAsync (const SDL_SCAN_CODES code, const bool pressed);
    // void ScanKeyboard (BYTE * keybuf);
    void WritePaging();
    /* nahrada signal - slot ??? */
    void OnCpuReadB () override {
      ReadKeyboardB();
    }
    void OnCpuWriteCH () override {
      WritePaging();
    }
#ifndef __arm__
    BYTE ledState;
#endif // __arm__
  private:
    int  range (const SDL_SCAN_CODES x) const;
    void ReadKeyboardB();
    ChipMemory * memory;
    static const KEYMAP KeyMap[];
    BYTE ShiftStopCtrl;
    BYTE KeyColumns[16];
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
