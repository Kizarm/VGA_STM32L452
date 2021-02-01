/*  RomModule.cpp: Class for emulation of plugged ROM module
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
#include <string.h>
#include "RomModule.h"
#include "ff.h"
//---------------------------------------------------------------------------
RomModule::RomModule (const BYTE portAddr, const BYTE portMask, const bool needReset)
  : PeripheralDevice (portAddr, portMask, needReset), ChipPIO8255 (false) {
  lenRom  = 0u;
  ofsRom  = 0u;
  // OnCpuReadA.connect (this, &RomModule::ReadFromRom);
}
//---------------------------------------------------------------------------
// metody zdedene z triedy PeripheralDevice
//---------------------------------------------------------------------------
/**
 * Metoda je volana procesorom pri jeho resete.
 */
void RomModule::ResetDevice (int) {
  ChipReset (false);
}
//---------------------------------------------------------------------------
/**
 * Metoda je volana procesorom pri zapise na porty PIO RomModulu.
 */
void RomModule::WriteToDevice (BYTE port, BYTE value, int) {
  switch (port & ROM_MODULE_REG_MASK) {
  case ROM_MODULE_REG_A:
    CpuWrite (PP_PortA, value);
    break;

  case ROM_MODULE_REG_B:
    CpuWrite (PP_PortB, value);
    break;

  case ROM_MODULE_REG_C:
    CpuWrite (PP_PortC, value);
    break;

  case ROM_MODULE_REG_CWR:
    CpuWrite (PP_CWR, value);
    break;
  }
}
//---------------------------------------------------------------------------
/**
 * Metoda je volana procesorom pri citani z portov PIO RomModulu.
 */
BYTE RomModule::ReadFromDevice (BYTE port, int) {
  BYTE retval;

  switch (port & ROM_MODULE_REG_MASK) {
  case ROM_MODULE_REG_A:
    retval = CpuRead (PP_PortA);
    break;

  case ROM_MODULE_REG_B:
    retval = CpuRead (PP_PortB);
    break;

  case ROM_MODULE_REG_C:
    retval = CpuRead (PP_PortC);
    break;

  case ROM_MODULE_REG_CWR:
    retval = CpuRead (PP_CWR);
    break;

  default:
    retval = 0xFF;
    break;
  }

  return retval;
}
//---------------------------------------------------------------------------
void RomModule::InsertFile (const char * filename) {
  FIL handle;
  if (f_open (&handle, filename, FA_READ) != FR_OK) return;
  const unsigned to_read = ROM_PACK_SIZE - lenRom;
  unsigned readen = 0u;
  f_read (&handle, RomPack + lenRom, to_read, &readen);
  debug ("readen 0x%04X bytes from file \"%s\"\n", readen, filename);
  lenRom += readen;
  f_close(&handle);
}
//---------------------------------------------------------------------------
void RomModule::ReadFromRom() {
  WORD addr;

  addr  =         PeripheralReadByte (PP_PortB);
  addr |= (WORD) (PeripheralReadByte (PP_PortC) << 8);
  addr -= ofsRom;
  
  const BYTE db = RomPack [addr];
  // debug ("Read from %04X %02X\n", addr, db);

  if (addr >= lenRom) PeripheralWriteByte (PP_PortA, 0xFF);
  else                PeripheralWriteByte (PP_PortA, db);
}
//---------------------------------------------------------------------------
