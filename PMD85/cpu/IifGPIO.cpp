/*  IifGPIO.cpp: Class for emulation of base GPIO interface
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
#include "IifGPIO.h"
// #include "CommonUtils.h"
//---------------------------------------------------------------------------
IifGPIO::IifGPIO (const BYTE portAddr, const BYTE portMask, const bool needReset) 
  : PeripheralDevice (portAddr, portMask, needReset), ChipPIO8255 (true) {
  /*
  OnBeforeResetA.disconnect_all();
  OnBeforeResetB.disconnect_all();
  OnAfterResetA.disconnect_all();
  OnAfterResetB.disconnect_all();
  */
  pPmd32 = nullptr;
}
//---------------------------------------------------------------------------
// metody zdedene z triedy PeripheralDevice
//---------------------------------------------------------------------------
/**
 * Metoda je volana procesorom pri jeho resete.
 */
void IifGPIO::ResetDevice (int ticks) {
  currentTicks = ticks;
  
  OnBeforeResetA();
  OnBeforeResetB();
  
  ChipReset (false);
  
  OnAfterResetA();
  OnAfterResetB();
  
}
//---------------------------------------------------------------------------
/**
 * Metoda je volana procesorom pri zapise na porty GPIO.
 */
void IifGPIO::WriteToDevice (BYTE port, BYTE value, int ticks) {
  currentTicks = ticks;

  switch (port & IIF_GPIO_REG_MASK) {
  case IIF_GPIO_REG_A:
    CpuWrite (PP_PortA, value);
    break;

  case IIF_GPIO_REG_B:
    CpuWrite (PP_PortB, value);
    break;

  case IIF_GPIO_REG_C:
    CpuWrite (PP_PortC, value);
    break;

  case IIF_GPIO_REG_CWR:
    CpuWrite (PP_CWR, value);
    break;
  }
  // debug ("WriteToDevice %02X -> %02X\n", port, value);
}
//---------------------------------------------------------------------------
/**
 * Metoda je volana procesorom pri citani z portov GPIO.
 */
BYTE IifGPIO::ReadFromDevice (BYTE port, int ticks) {
  BYTE retval;

  currentTicks = ticks;

  switch (port & IIF_GPIO_REG_MASK) {
  case IIF_GPIO_REG_A:
    retval = CpuRead (PP_PortA);
    break;

  case IIF_GPIO_REG_B:
    retval = CpuRead (PP_PortB);
    break;

  case IIF_GPIO_REG_C:
    retval = CpuRead (PP_PortC);
    break;

  case IIF_GPIO_REG_CWR:
    retval = CpuRead (PP_CWR);
    break;

  default:
    retval = 0xFF;
    break;
  }
  // debug ("ReadFromDevice %02X -> %02X\n", port, retval);

  return retval;
}
//---------------------------------------------------------------------------
void IifGPIO::WriteByte (TPIOPort dest, BYTE val) {
  PeripheralWriteByte (dest, val);
}
//---------------------------------------------------------------------------
BYTE IifGPIO::ReadByte (TPIOPort src) {
  return PeripheralReadByte (src);
}
//---------------------------------------------------------------------------
void IifGPIO::ChangeBit (TPIOPort dest, TPIOPortBit bit, bool state) {
  PeripheralChangeBit (dest, bit, state);
}
//---------------------------------------------------------------------------
bool IifGPIO::ReadBit (TPIOPort src, TPIOPortBit bit) {
  return PeripheralReadBit (src, bit);
}
//---------------------------------------------------------------------------
#include "Pmd32.h"
void IifGPIO::OnCpuWriteCH() {
  if (pPmd32) pPmd32->OnHandshake();
}
void IifGPIO::OnCpuWriteCWR (BYTE b) {
  if (pPmd32) pPmd32->OnSetMode2 (b);
}
///////////////////////////////////////////
void IifGPIO::OnAfterResetA() {
  if (pPmd32) pPmd32->AfterReset();
}
void IifGPIO::OnAfterResetB() {

}
void IifGPIO::OnBeforeResetA() {
  if (pPmd32) pPmd32->BeforeReset();
}
void IifGPIO::OnBeforeResetB() {

}
