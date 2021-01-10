/*  IifTimer.cpp: Class for emulation of timer interface
    Copyright (c) 2006-2010 Roman Borik <pmd85emu@gmail.com>

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
#include "IifTimer.h"
//#include "CommonUtils.h"
//---------------------------------------------------------------------------
IifTimer::IifTimer (ChipCpu8080 *_cpu, const BYTE portAddr, const BYTE portMask, const bool needReset)
  : PeripheralDevice (portAddr, portMask, needReset), ChipPIT8253() {

  cntRtc = 0;
  stateRtc = true;
  cpu = _cpu;

  PeripheralSetGate (CT_0, true);
  PeripheralSetClock (CT_0, false);
  PeripheralSetGate (CT_1, true);
  PeripheralSetClock (CT_1, false);
  PeripheralSetGate (CT_2, true);
  PeripheralSetClock (CT_2, stateRtc);

  // zatim to stejne nic nedela
  //  Counters[0].OnOutChange.connect (this, &IifTimer::Timer0OutChange);
}
//---------------------------------------------------------------------------
void IifTimer::WriteToDevice (BYTE port, BYTE value, int) {
//  debug("IfTimer", "ticks=%d, port=%u, value=%u", ticks, port, value);

  switch (port & IIF_TIMER_REG_MASK) {
  case IIF_TIMER_REG_T0:
    CpuWrite (CT_0, value);
    break;

  case IIF_TIMER_REG_T1:
    CpuWrite (CT_1, value);
    break;

  case IIF_TIMER_REG_T2:
    CpuWrite (CT_2, value);
    break;

  case IIF_TIMER_REG_CWR:
    CpuWrite (CT_CWR, value);
    break;
  }
}
//---------------------------------------------------------------------------
BYTE IifTimer::ReadFromDevice (BYTE port, int) {
  BYTE retval;

  switch (port & IIF_TIMER_REG_MASK) {
  case IIF_TIMER_REG_T0:
    retval = CpuRead (CT_0);
    break;

  case IIF_TIMER_REG_T1:
    retval = CpuRead (CT_1);
    break;

  case IIF_TIMER_REG_T2:
    retval = CpuRead (CT_2);
    break;

  case IIF_TIMER_REG_CWR:
    retval = CpuRead (CT_CWR);
    break;

  default:
    retval = 0xFF;
    break;
  }

//  debug("IfTimer", "ticks=%d, port=%u, retval=%u", ticks, port, retval);

  return retval;
}
//---------------------------------------------------------------------------
void IifTimer::ITimerService (int ticks, int dur) {
    // Timer T2 - RTC
    cntRtc += dur;
    while (cntRtc >= HALF_SEC_RTC) {
      cntRtc -= HALF_SEC_RTC;
      stateRtc = !stateRtc;
      PeripheralSetClock (CT_2, stateRtc);
    }

    // Timer T1 - clock for USART
    for (int ii = 0; ii < dur; ii++) {
      PeripheralSetClock (CT_1, true);
      PeripheralSetClock (CT_1, false);
    }

    currentTicks = ticks;

}
//---------------------------------------------------------------------------
void IifTimer::Timer0OutChange (TPITCounter, bool) {
}
//---------------------------------------------------------------------------
void IifTimer::CT2Clock (TPITCounter, bool outState) {
  PeripheralSetClock (CT_2, outState);
}
//---------------------------------------------------------------------------
