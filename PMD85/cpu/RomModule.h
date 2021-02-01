/*  RomModule.h: Class for emulation of plugged ROM module
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
#ifndef RomModuleH
#define RomModuleH
//---------------------------------------------------------------------------
#include "Globals.h"
#include "ChipPIO8255.h"
//---------------------------------------------------------------------------
#define ROM_MODULE_MASK       0x8C
#define ROM_MODULE_ADR        0x88

#define ROM_MODULE_REG_MASK   0x8F
#define ROM_MODULE_REG_A      0x88
#define ROM_MODULE_REG_B      0x89
#define ROM_MODULE_REG_C      0x8A
#define ROM_MODULE_REG_CWR    0x8B

static constexpr unsigned ROM_PACK_SIZE_KB    =  16;
static constexpr unsigned ROM_PACK_SIZE       =  (ROM_PACK_SIZE_KB * 1024);
//---------------------------------------------------------------------------
class RomModule: public PeripheralDevice, public ChipPIO8255 {
  public:
    RomModule (const BYTE portAddr, const BYTE portMask, const bool needReset);

    virtual void ResetDevice (int ticks);
    virtual void WriteToDevice (BYTE port, BYTE value, int ticks);
    virtual BYTE ReadFromDevice (BYTE port, int ticks);

    void InsertFile (const char * filename);

    void ReadFromRom();
    void OnCpuReadA () override {
      ReadFromRom();
    };

  private:
    BYTE     RomPack [ROM_PACK_SIZE];
    unsigned lenRom, ofsRom;
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
