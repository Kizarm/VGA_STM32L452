/*  ChipCpu8080.cpp: Class for emulation of i8080 microprocessor
  Copyright (c) 2006-2015 Roman Borik <pmd85emu@gmail.com>

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
//-----------------------------------------------------------------------------
#include "ChipCpu8080.h"
//-----------------------------------------------------------------------------
// instructions T-cycles:
// conditional Cc functions calls and Rc returns is solved separately,
//   this tick values are only if condition isn't met,
//   if some condition is met, we will add TR5R3R3W3W3 or TR5R3R3 ticks
const char ChipCpu8080::duration[256] = {
//          x0       x1           x2           x3           x4           x5       x6       x7
//          x8       x9           xA           xB           xC           xD       xE       xF
  /* 0x */   TR4, TR4R3R3,       TR4W3,         TR5,         TR5,         TR5,   TR4R3,     TR4,
  TR4, TR4N3N3,       TR4R3,         TR5,         TR5,         TR5,   TR4R3,     TR4,
  /* 1x */   TR4, TR4R3R3,       TR4W3,         TR5,         TR5,         TR5,   TR4R3,     TR4,
  TR4, TR4N3N3,       TR4R3,         TR5,         TR5,         TR5,   TR4R3,     TR4,
  /* 2x */   TR4, TR4R3R3, TR4R3R3W3W3,         TR5,         TR5,         TR5,   TR4R3,     TR4,
  TR4, TR4N3N3, TR4R3R3R3R3,         TR5,         TR5,         TR5,   TR4R3,     TR4,
  /* 3x */   TR4, TR4R3R3,   TR4R3R3W3,         TR5,     TR4R3W3,     TR4R3W3, TR4R3W3,     TR4,
  TR4, TR4N3N3,   TR4R3R3R3,         TR5,         TR5,         TR5,   TR4R3,     TR4,
  /* 4x */   TR5,     TR5,         TR5,         TR5,         TR5,         TR5,   TR4R3,     TR5,
  TR5,     TR5,         TR5,         TR5,         TR5,         TR5,   TR4R3,     TR5,
  /* 5x */   TR5,     TR5,         TR5,         TR5,         TR5,         TR5,   TR4R3,     TR5,
  TR5,     TR5,         TR5,         TR5,         TR5,         TR5,   TR4R3,     TR5,
  /* 6x */   TR5,     TR5,         TR5,         TR5,         TR5,         TR5,   TR4R3,     TR5,
  TR5,     TR5,         TR5,         TR5,         TR5,         TR5,   TR4R3,     TR5,
  /* 7x */ TR4W3,   TR4W3,       TR4W3,       TR4W3,       TR4W3,       TR4W3,   TR4N1,   TR4W3,
  TR5,     TR5,         TR5,         TR5,         TR5,         TR5,   TR4R3,     TR5,
  /* 8x */   TR4,     TR4,         TR4,         TR4,         TR4,         TR4,   TR4R3,     TR4,
  TR4,     TR4,         TR4,         TR4,         TR4,         TR4,   TR4R3,     TR4,
  /* 9x */   TR4,     TR4,         TR4,         TR4,         TR4,         TR4,   TR4R3,     TR4,
  TR4,     TR4,         TR4,         TR4,         TR4,         TR4,   TR4R3,     TR4,
  /* Ax */   TR4,     TR4,         TR4,         TR4,         TR4,         TR4,   TR4R3,     TR4,
  TR4,     TR4,         TR4,         TR4,         TR4,         TR4,   TR4R3,     TR4,
  /* Bx */   TR4,     TR4,         TR4,         TR4,         TR4,         TR4,   TR4R3,     TR4,
  TR4,     TR4,         TR4,         TR4,         TR4,         TR4,   TR4R3,     TR4,
  /* Cx */   TR5, TR4R3R3,     TR4R3R3,     TR4R3R3,     TR5R3R3,     TR5W3W3,   TR4R3, TR5W3W3,
  TR5, TR4R3R3,     TR4R3R3,     TR4R3R3,     TR5R3R3, TR5R3R3W3W3,   TR4R3, TR5W3W3,
  /* Dx */   TR5, TR4R3R3,     TR4R3R3,     TR4R3W3,     TR5R3R3,     TR5W3W3,   TR4R3, TR5W3W3,
  TR5, TR4R3R3,     TR4R3R3,     TR4R3R3,     TR5R3R3, TR5R3R3W3W3,   TR4R3, TR5W3W3,
  /* Ex */   TR5, TR4R3R3,     TR4R3R3, TR4R3R3W3W5,     TR5R3R3,     TR5W3W3,   TR4R3, TR5W3W3,
  TR5,     TR5,     TR4R3R3,         TR4,     TR5R3R3, TR5R3R3W3W3,   TR4R3, TR5W3W3,
  /* Fx */   TR5, TR4R3R3,     TR4R3R3,         TR4,     TR5R3R3,     TR5W3W3,   TR4R3, TR5W3W3,
  TR5,     TR5,     TR4R3R3,         TR4,     TR5R3R3, TR5R3R3W3W3,   TR4R3, TR5W3W3
};
//-----------------------------------------------------------------------------
// length of instructions in bytes
const char ChipCpu8080::length[256] = {
//       x0  x1  x2  x3  x4  x5  x6  x7  x8  x9  xA  xB  xC  xD  xE  xF
  /* 0x */  1,  3,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  1,  1,  2,  1,
  /* 1x */  1,  3,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  1,  1,  2,  1,
  /* 2x */  1,  3,  3,  1,  1,  1,  2,  1,  1,  1,  3,  1,  1,  1,  2,  1,
  /* 3x */  1,  3,  3,  1,  1,  1,  2,  1,  1,  1,  3,  1,  1,  1,  2,  1,
  /* 4x */  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
  /* 5x */  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
  /* 6x */  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
  /* 7x */  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
  /* 8x */  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
  /* 9x */  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
  /* Ax */  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
  /* Bx */  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
  /* Cx */  1,  1,  3,  3,  3,  1,  2,  1,  1,  1,  3,  3,  3,  3,  2,  1,
  /* Dx */  1,  1,  3,  2,  3,  1,  2,  1,  1,  1,  3,  2,  3,  3,  2,  1,
  /* Ex */  1,  1,  3,  1,  3,  1,  2,  1,  1,  1,  3,  1,  3,  3,  2,  1,
  /* Fx */  1,  1,  3,  1,  3,  1,  2,  1,  1,  1,  3,  1,  3,  3,  2,  1
};
//-----------------------------------------------------------------------------
// Table of AC (Auxiliary Carry) results after ADD and SUB instructions.
// AC flag can be detected from bit3 of both arguments and result.
// This table is in r21 form, where 'r' is bit3 of result, '2' is bit3
// of second argument and '1' is bit3 of first argument (A register).
// Table is different for ADD and SUB operations.
//
BYTE ChipCpu8080::auxcarryAddTable[8] = { 0, FLAG_AC, FLAG_AC, FLAG_AC, 0, 0, 0, FLAG_AC };
BYTE ChipCpu8080::auxcarrySubTable[8] = { FLAG_AC, FLAG_AC, 0, FLAG_AC, 0, FLAG_AC, 0, 0 };
BYTE ChipCpu8080::sz53p1Table[0x100] = { (BYTE) -1 };
WORD ChipCpu8080::daaTable[0x400] = { (WORD) -1 };
//-----------------------------------------------------------------------------
ChipCpu8080::ChipCpu8080 (ChipMemory * mem) {
  memory = mem;
  af.w = bc.w = de.w = hl.w = sp.w = pc.w = 0;

  //ports = nullptr;
  //lastPort = nullptr;
  device  = nullptr;
  intCtrl = nullptr;

  slowCpu = false;
  countTCycles = 0;
  totalTCycles = 0;
  lastInstrTCycles = 0;
  fetchCounter = 0;

  PrepareFlagsTables();
  Reset();
}
//-----------------------------------------------------------------------------
/*
ChipCpu8080::~ChipCpu8080() {
  PORT_HANDLER * port, * nextp;

  port = ports;
  while (port) {
    nextp = port->next;
    port->Destroy ();
    port = nextp;
  }
  ports    = nullptr;
  lastPort = nullptr;

  //TCyclesListeners.disconnect_all();
}
*/
//-----------------------------------------------------------------------------
void ChipCpu8080::PrepareFlagsTables() {
  int i, j, k;
  WORD a;
  BYTE f;

  // S, P flags; bit5 and bit3 are always zero; bit1 is always set
  for (i = 0; i < 0x100; i++) {
    j = i;
    // parity counting
    f = 0;
    for (k = 0; k < 8; k++) {
      f ^= (BYTE) (j & 1);
      j >>= 1;
    }

    sz53p1Table[i] = (BYTE) ( (i & FLAG_S) | (f ? 0 : FLAG_PE) | FLAG_1);
  }
  // Z flag
  sz53p1Table[0] |= FLAG_Z; // Z is set to zero

  // DAA table
  for (i = 0; i < 0x400; i++) {
    a = (WORD) (i & 0xFF);
    f = 0;
    if ( (i & 0x200) || (a & 0x0F) > 0x09) { // AC
      if ( (a & 0x0F) > 9)
        f |= FLAG_AC;
      a += (WORD) 0x06;
    }
    if ( (i & 0x100) || a > 0x9F) { // CY
      a += (WORD) 0x60;
      f |= FLAG_CY;
    }
    f |= sz53p1Table[ (BYTE) a];

    daaTable[i] = (WORD) ( ( ( (BYTE) a) << 8) | f);
  }
}
//-----------------------------------------------------------------------------
void ChipCpu8080::Reset() {
  resetPending = false;
  iff = false;
  ei1 = false;
  ei2 = false;
  halt = false;
  inta = false;
  PC = 0x8000;

  InitCountIntCycles();
  memory->ResetOn();

  PeripheralDevice * ph = device;
  while (ph) {
    if (ph->needReset)
      ph->ResetDevice (0);
    ph = ph->next;
  }
}
//-----------------------------------------------------------------------------
/**
 * SetChipState method is used while opening a Snapshot for preset some of
 * internal registers of processor.
 * Buffer data must be in order: Interupt state, AF, BC, DE, HL, PC, SP
 */
void ChipCpu8080::SetChipState (BYTE * buffer) {
  if (buffer != nullptr) {
    iff = (*buffer & 1);
    ei1 = (*buffer & 2);
    ei2 = (*buffer & 4);
    halt = (*buffer & 8);
    inta = (*buffer & 16);
    AF = * (WORD *) (buffer + 1);
    BC = * (WORD *) (buffer + 3);
    DE = * (WORD *) (buffer + 5);
    HL = * (WORD *) (buffer + 7);
    PC = * (WORD *) (buffer + 9);
    SP = * (WORD *) (buffer + 11);
  }
}
//-----------------------------------------------------------------------------
/**
 * GetChipState method is used while saving a Snapshot to store some of
 * internal registers of processor. Method returns length of data in bytes.
 * Buffer data will be in order: Interupt state, AF, BC, DE, HL, PC, SP
 */
int ChipCpu8080::GetChipState (BYTE * buffer) {
  if (buffer != nullptr) {
    *buffer = (BYTE) ( ( (iff) ? 1 : 0)
                       | ( (ei1) ? 2 : 0)
                       | ( (ei2) ? 4 : 0)
                       | ( (halt) ? 8 : 0)
                       | ( (inta) ? 16 : 0));
    * (WORD *) (buffer + 1) = AF;
    * (WORD *) (buffer + 3) = BC;
    * (WORD *) (buffer + 5) = DE;
    * (WORD *) (buffer + 7) = HL;
    * (WORD *) (buffer + 9) = PC;
    * (WORD *) (buffer + 11) = SP;
  }

  return 13;
}
//-----------------------------------------------------------------------------
bool ChipCpu8080::DoInterrupt() {
  if (iff == false)
    return false; // interupt not accepted

  iff = false;
  ei1 = false;
  ei2 = false;
  inta = true; // in next call of DoInstruction will be processed interupt
  return true; // interupt accepted
}
//-----------------------------------------------------------------------------
int ChipCpu8080::DoInstruction() {
  BYTE opcode;        // instruction opcode
  BYTE bytetemp = 0;  // 1-byte operand, temporal byte
  WORD wordtemp = 0;  // 2-byte operand, temporal word
  DWORD dwordtemp;    // 4-byte temporal dword
  int lookup;
  bool jump = false;

  if (resetPending) {
    Reset();
    return 0;
  }

  if (inta) { // interrupt processing
    if (halt) { // handling of HLT instruction
      halt = false;
      PC++;
    }

    if (intCtrl == nullptr) // if interrupt controller not defined,
      opcode = 0xFF; // then only RST 7 instruction has been handled,
    else { // else interrupt controller must provide instruction to handle.
      opcode = intCtrl->getInterruptVector (IV_OPCODE);
      if (length[opcode] > 1)
        bytetemp = intCtrl->getInterruptVector (IV_OPERAND_L);
      if (length[opcode] > 2)
        wordtemp = (WORD) (bytetemp | (intCtrl->getInterruptVector (IV_OPERAND_H) << 8));
    }

    intSP = SP;
    intCyclesCur = totalTCycles;

    inta = false;
  } else { // fetch of the instruction from memory
    opcode = memory->ReadByte (PC++);
    // debug ("PC = %04X, opcode = %02X\n", PC - 1, opcode);
    if (length[opcode] == 2)
      bytetemp = memory->ReadByte (PC++);
    else if (length[opcode] == 3) {
      wordtemp = memory->ReadWord (PC);
      PC += (WORD) 2;
    }

    fetchCounter++;
  }

  TCyclesListeners(countTCycles, lastInstrTCycles);

  switch (opcode) {
  case 0x00: // NOP
  case 0x08: // NOP - undocumented
  case 0x10: // NOP - undocumented
  case 0x18: // NOP - undocumented
  case 0x20: // NOP - undocumented
  case 0x28: // NOP - undocumented
  case 0x30: // NOP - undocumented
  case 0x38: // NOP - undocumented
    break;

  case 0x01: // LXI B,word
    BC = wordtemp;
    break;

  case 0x02: // STAX B
    memory->WriteByte (BC, A);
    break;

  case 0x03: // INX B
    BC++;
    break;

  case 0x04: // INR B
    INR (B);
    break;

  case 0x05: // DCR B
    DCR (B);
    break;

  case 0x06: // MVI B,byte
    B = bytetemp;
    break;

  case 0x07: // RLC
    A = (BYTE) ( (A << 1) | (A >> 7));
    F = (BYTE) ( (F & (FLAG_S | FLAG_Z | FLAG_AC | FLAG_PE)) | FLAG_1 | (A & FLAG_CY));
    break;

  case 0x09: // DAD B
    DAD (BC);
    break;

  case 0x0a: // LDAX B
    A = memory->ReadByte (BC);
    break;

  case 0x0b: // DCX B
    BC--;
    break;

  case 0x0c: // INR C
    INR (C);
    break;

  case 0x0d: // DCR C
    DCR (C);
    break;

  case 0x0e: // MVI C,byte
    C = bytetemp;
    break;

  case 0x0f: // RRC
    F = (BYTE) ( (F & (FLAG_S | FLAG_Z | FLAG_AC | FLAG_PE)) | FLAG_1 | (A & FLAG_CY));
    A = (BYTE) ( (A >> 1) | (A << 7));
    break;

  case 0x11: // LXI D,word
    DE = wordtemp;
    break;

  case 0x12: // SDAX D
    memory->WriteByte (DE, A);
    break;

  case 0x13: // INX D
    DE++;
    break;

  case 0x14: // INR D
    INR (D);
    break;

  case 0x15: // DCR D
    DCR (D);
    break;

  case 0x16: // MVI D,byte
    D = bytetemp;
    break;

  case 0x17: // RAL
    bytetemp = A;
    A = (BYTE) ( (A << 1) | (F & FLAG_CY));
    F = (BYTE) ( (F & (FLAG_S | FLAG_Z | FLAG_AC | FLAG_PE)) | FLAG_1 | (bytetemp >> 7));
    break;

  case 0x19: // DAD D
    DAD (DE);
    break;

  case 0x1a: // LDAX D
    A = memory->ReadByte (DE);
    break;

  case 0x1b: // DCX D
    DE--;
    break;

  case 0x1c: // INR E
    INR (E);
    break;

  case 0x1d: // DCR E
    DCR (E);
    break;

  case 0x1e: // MVI E,byte
    E = bytetemp;
    break;

  case 0x1f: // RAR
    bytetemp = A;
    A = (BYTE) ( (A >> 1) | (F << 7));
    F = (BYTE) ( (F & (FLAG_S | FLAG_Z | FLAG_AC | FLAG_PE)) | FLAG_1 | (bytetemp & FLAG_CY));
    break;

  case 0x21: // LXI H,word
    HL = wordtemp;
    break;

  case 0x22: // SHLD adr
    memory->WriteWord (wordtemp, HL);
    break;

  case 0x23: // INX H
    HL++;
    break;

  case 0x24: // INR H
    INR (H);
    break;

  case 0x25: // DCR H
    DCR (H);
    break;

  case 0x26: // MVI H,byte
    H = bytetemp;
    break;

  case 0x27: // DAA
    wordtemp = A;
    if (F & FLAG_CY)
      wordtemp |= 0x100;
    if (F & FLAG_AC)
      wordtemp |= 0x200;
    AF = daaTable[wordtemp];
    break;

  case 0x29: // DAD H
    DAD (HL);
    break;

  case 0x2a: // LHLD adr
    HL = memory->ReadWord (wordtemp);
    break;

  case 0x2b: // DCX H
    HL--;
    break;

  case 0x2c: // INR L
    INR (L);
    break;

  case 0x2d: // DCR L
    DCR (L);
    break;

  case 0x2e: // MVI L,byte
    L = bytetemp;
    break;

  case 0x2f: // CMA
    A ^= 0xff;
    break;

  case 0x31: // LXI SP,word
    SP = wordtemp;
    break;

  case 0x32: // STA adr
    memory->WriteByte (wordtemp, A);
    break;

  case 0x33: // INX SP
    SP++;
    break;

  case 0x34: // INR M
    bytetemp = memory->ReadByte (HL);
    INR (bytetemp);
    memory->WriteByte (HL, bytetemp);
    break;

  case 0x35: // DCR M
    bytetemp = memory->ReadByte (HL);
    DCR (bytetemp);
    memory->WriteByte (HL, bytetemp);
    break;

  case 0x36: // MVI M,byte
    memory->WriteByte (HL, bytetemp);
    break;

  case 0x37: // STC
    F = (BYTE) ( (F & (FLAG_S | FLAG_Z | FLAG_AC | FLAG_PE)) | FLAG_1 | FLAG_CY);
    break;

  case 0x39: // DAD SP
    DAD (SP);
    break;

  case 0x3a: // LDA adr
    A = memory->ReadByte (wordtemp);
    break;

  case 0x3b: // DCX SP
    SP--;
    break;

  case 0x3c: // INR A
    INR (A);
    break;

  case 0x3d: // DCR A
    DCR (A);
    break;

  case 0x3e: // MVI A,byte
    A = bytetemp;
    break;

  case 0x3f: // CMC
    F = (BYTE) ( (F & (FLAG_S | FLAG_Z | FLAG_AC | FLAG_PE)) | FLAG_1 | ( (F & FLAG_CY) ? 0 : FLAG_CY));
    break;

  case 0x40: // MOV B,B
    break;

  case 0x41: // MOV B,C
    B = C;
    break;

  case 0x42: // MOV B,D
    B = D;
    break;

  case 0x43: // MOV B,E
    B = E;
    break;

  case 0x44: // MOV B,H
    B = H;
    break;

  case 0x45: // MOV B,L
    B = L;
    break;

  case 0x46: // MOV B,M
    B = memory->ReadByte (HL);
    break;

  case 0x47: // MOV B,A
    B = A;
    break;

  case 0x48: // MOV C,B
    C = B;
    break;

  case 0x49: // MOV C,C
    break;

  case 0x4a: // MOV C,D
    C = D;
    break;

  case 0x4b: // MOV C,E
    C = E;
    break;

  case 0x4c: // MOV C,H
    C = H;
    break;

  case 0x4d: // MOV C,L
    C = L;
    break;

  case 0x4e: // MOV C,M
    C = memory->ReadByte (HL);
    break;

  case 0x4f: // MOV C,A
    C = A;
    break;

  case 0x50: // MOV D,B
    D = B;
    break;

  case 0x51: // MOV D,C
    D = C;
    break;

  case 0x52: // MOV D,D
    break;

  case 0x53: // MOV D,E
    D = E;
    break;

  case 0x54: // MOV D,H
    D = H;
    break;

  case 0x55: // MOV D,L
    D = L;
    break;

  case 0x56: // MOV D,M
    D = memory->ReadByte (HL);
    break;

  case 0x57: // MOV D,A
    D = A;
    break;

  case 0x58: // MOV E,B
    E = B;
    break;

  case 0x59: // MOV E,C
    E = C;
    break;

  case 0x5a: // MOV E,D
    E = D;
    break;

  case 0x5b: // MOV E,E
    break;

  case 0x5c: // MOV E,H
    E = H;
    break;

  case 0x5d: // MOV E,L
    E = L;
    break;

  case 0x5e: // MOV E,M
    E = memory->ReadByte (HL);
    break;

  case 0x5f: // MOV E,A
    E = A;
    break;

  case 0x60: // MOV H,B
    H = B;
    break;

  case 0x61: // MOV H,C
    H = C;
    break;

  case 0x62: // MOV H,D
    H = D;
    break;

  case 0x63: // MOV H,E
    H = E;
    break;

  case 0x64: // MOV H,H
    break;

  case 0x65: // MOV H,L
    H = L;
    break;

  case 0x66: // MOV H,M
    H = memory->ReadByte (HL);
    break;

  case 0x67: // MOV H,A
    H = A;
    break;

  case 0x68: // MOV L,B
    L = B;
    break;

  case 0x69: // MOV L,C
    L = C;
    break;

  case 0x6a: // MOV L,D
    L = D;
    break;

  case 0x6b: // MOV L,E
    L = E;
    break;

  case 0x6c: // MOV L,H
    L = H;
    break;

  case 0x6d: // MOV L,L
    break;

  case 0x6e: // MOV L,M
    L = memory->ReadByte (HL);
    break;

  case 0x6f: // MOV L,A
    L = A;
    break;

  case 0x70: // MOV M,B
    memory->WriteByte (HL, B);
    break;

  case 0x71: // MOV M,C
    memory->WriteByte (HL, C);
    break;

  case 0x72: // MOV M,D
    memory->WriteByte (HL, D);
    break;

  case 0x73: // MOV M,E
    memory->WriteByte (HL, E);
    break;

  case 0x74: // MOV M,H
    memory->WriteByte (HL, H);
    break;

  case 0x75: // MOV M,L
    memory->WriteByte (HL, L);
    break;

  case 0x76: // HLT
    PC--;
    if (!halt) {
      halt = true;
      lastInstrTCycles = GetDuration (opcode, false);
    } else
      lastInstrTCycles = 1;
    break;

  case 0x77: // MOV M,A
    memory->WriteByte (HL, A);
    break;

  case 0x78: // MOV A,B
    A = B;
    break;

  case 0x79: // MOV A,C
    A = C;
    break;

  case 0x7a: // MOV A,D
    A = D;
    break;

  case 0x7b: // MOV A,E
    A = E;
    break;

  case 0x7c: // MOV A,H
    A = H;
    break;

  case 0x7d: // MOV A,L
    A = L;
    break;

  case 0x7e: // MOV A,M
    A = memory->ReadByte (HL);
    break;

  case 0x7f: // MOV A,A
    break;

  case 0x80: // ADD B
    ADD (B);
    break;

  case 0x81: // ADD C
    ADD (C);
    break;

  case 0x82: // ADD D
    ADD (D);
    break;

  case 0x83: // ADD E
    ADD (E);
    break;

  case 0x84: // ADD H
    ADD (H);
    break;

  case 0x85: // ADD L
    ADD (L);
    break;

  case 0x86: // ADD M
    bytetemp = memory->ReadByte (HL);
    ADD (bytetemp);
    break;

  case 0x87: // ADD A
    ADD (A);
    break;

  case 0x88: // ADC B
    ADC (B);
    break;

  case 0x89: // ADC C
    ADC (C);
    break;

  case 0x8a: // ADC D
    ADC (D);
    break;

  case 0x8b: // ADC E
    ADC (E);
    break;

  case 0x8c: // ADC H
    ADC (H);
    break;

  case 0x8d: // ADC L
    ADC (L);
    break;

  case 0x8e: // ADC M
    bytetemp = memory->ReadByte (HL);
    ADC (bytetemp);
    break;

  case 0x8f: // ADC A
    ADC (A);
    break;

  case 0x90: // SUB B
    SUB (B);
    break;

  case 0x91: // SUB C
    SUB (C);
    break;

  case 0x92: // SUB D
    SUB (D);
    break;

  case 0x93: // SUB E
    SUB (E);
    break;

  case 0x94: // SUB H
    SUB (H);
    break;

  case 0x95: // SUB L
    SUB (L);
    break;

  case 0x96: // SUB M
    bytetemp = memory->ReadByte (HL);
    SUB (bytetemp);
    break;

  case 0x97: // SUB A
    SUB (A);
    break;

  case 0x98: // SBB B
    SBB (B);
    break;

  case 0x99: // SBB C
    SBB (C);
    break;

  case 0x9a: // SBB D
    SBB (D);
    break;

  case 0x9b: // SBB E
    SBB (E);
    break;

  case 0x9c: // SBB H
    SBB (H);
    break;

  case 0x9d: // SBB L
    SBB (L);
    break;

  case 0x9e: // SBB M
    bytetemp = memory->ReadByte (HL);
    SBB (bytetemp);
    break;

  case 0x9f: // SBB A
    SBB (A);
    break;

  case 0xa0: // ANA B
    ANA (B);
    break;

  case 0xa1: // ANA C
    ANA (C);
    break;

  case 0xa2: // ANA D
    ANA (D);
    break;

  case 0xa3: // ANA E
    ANA (E);
    break;

  case 0xa4: // ANA H
    ANA (H);
    break;

  case 0xa5: // ANA L
    ANA (L);
    break;

  case 0xa6: // ANA M
    bytetemp = memory->ReadByte (HL);
    ANA (bytetemp);
    break;

  case 0xa7: // ANA A
    ANA (A);
    break;

  case 0xa8: // XRA B
    XRA (B);
    break;

  case 0xa9: // XRA C
    XRA (C);
    break;

  case 0xaa: // XRA D
    XRA (D);
    break;

  case 0xab: // XRA E
    XRA (E);
    break;

  case 0xac: // XRA H
    XRA (H);
    break;

  case 0xad: // XRA L
    XRA (L);
    break;

  case 0xae: // XRA M
    bytetemp = memory->ReadByte (HL);
    XRA (bytetemp);
    break;

  case 0xaf: // XRA A
    XRA (A);
    break;

  case 0xb0: // ORA B
    ORA (B);
    break;

  case 0xb1: // ORA C
    ORA (C);
    break;

  case 0xb2: // ORA D
    ORA (D);
    break;

  case 0xb3: // ORA E
    ORA (E);
    break;

  case 0xb4: // ORA H
    ORA (H);
    break;

  case 0xb5: // ORA L
    ORA (L);
    break;

  case 0xb6: // ORA M
    bytetemp = memory->ReadByte (HL);
    ORA (bytetemp);
    break;

  case 0xb7: // ORA A
    ORA (A);
    break;

  case 0xb8: // CMP B
    CMP (B);
    break;

  case 0xb9: // CMP C
    CMP (C);
    break;

  case 0xba: // CMP D
    CMP (D);
    break;

  case 0xbb: // CMP E
    CMP (E);
    break;

  case 0xbc: // CMP H
    CMP (H);
    break;

  case 0xbd: // CMP L
    CMP (L);
    break;

  case 0xbe: // CMP M
    bytetemp = memory->ReadByte (HL);
    CMP (bytetemp);
    break;

  case 0xbf: // CMP A
    CMP (A);
    break;

  case 0xc0: // RNZ
    if (! (F & FLAG_Z)) {
      RET();
      jump = true;
      CountIntCycles();
    }
    break;

  case 0xc1: // POP B
    POP (BC);
    break;

  case 0xc2: // JNZ adr
    if (! (F & FLAG_Z))
      JMP();
    break;

  case 0xc3: // JMP adr
  case 0xcb: // JMP adr - undocumented
    JMP();
    break;

  case 0xc4: // CNZ adr
    if (! (F & FLAG_Z)) {
      CALL();
      jump = true;
    }
    break;

  case 0xc5: // PUSH B
    PUSH (BC);
    break;

  case 0xc6: // ADI byte
    ADD (bytetemp);
    break;

  case 0xc7: // RST 0
    RST (0x00);
    break;

  case 0xc8: // RZ
    if (F & FLAG_Z) {
      RET();
      jump = true;
      CountIntCycles();
    }
    break;

  case 0xc9: // RET
  case 0xd9: // RET - undocumented
    RET();
    CountIntCycles();
    break;

  case 0xca: // JZ adr
    if (F & FLAG_Z)
      JMP();
    break;

  case 0xcc: // CZ adr
    if (F & FLAG_Z) {
      CALL();
      jump = true;
    }
    break;

  case 0xcd: // CALL adr
  case 0xdd: // CALL adr - undocumented
  case 0xed: // CALL adr - undocumented
  case 0xfd: // CALL adr - undocumented
    CALL();
    break;

  case 0xce: // ACI byte
    ADC (bytetemp);
    break;

  case 0xcf: // RST 1
    RST (0x08);
    break;

  case 0xd0: // RNC
    if (! (F & FLAG_CY)) {
      RET();
      jump = true;
      CountIntCycles();
    }
    break;

  case 0xd1: // POP D
    POP (DE);
    break;

  case 0xd2: // JNC adr
    if (! (F & FLAG_CY))
      JMP();
    break;

  case 0xd3: { // OUT port
    PeripheralDevice * dev = FindDevice (bytetemp);
    if (dev) dev->WriteToDevice (bytetemp, A, countTCycles);
    // debug ("OUT (%04X) %02X -> @%02X\n", PC - 2, A, bytetemp);
  }
  break;

  case 0xd4: // CNC adr
    if (! (F & FLAG_CY)) {
      CALL();
      jump = true;
    }
    break;

  case 0xd5: // PUSH D
    PUSH (DE);
    break;

  case 0xd6: // SUI byte
    SUB (bytetemp);
    break;

  case 0xd7: // RST 2
    RST (0x10);
    break;

  case 0xd8: // RC
    if (F & FLAG_CY) {
      RET();
      jump = true;
      CountIntCycles();
    }
    break;

  case 0xda: // JC adr
    if (F & FLAG_CY)
      JMP();
    break;

  case 0xdb: { // IN port
    PeripheralDevice * dev = FindDevice (bytetemp);
    if (dev)  A = dev->ReadFromDevice (bytetemp, countTCycles);
    else      A = 0xFF;
    // debug ("IN  (%04X) %02X <- @%02X\n", PC - 2, A, bytetemp);
  }
  break;

  case 0xdc: // CC adr
    if (F & FLAG_CY) {
      CALL();
      jump = true;
    }
    break;

  case 0xde: // SBI byte
    SBB (bytetemp);
    break;

  case 0xdf: // RST 3
    RST (0x18);
    break;

  case 0xe0: // RPO
    if (! (F & FLAG_PE)) {
      RET();
      jump = true;
      CountIntCycles();
    }
    break;

  case 0xe1: // POP H
    POP (HL);
    break;

  case 0xe2: // JPO adr
    if (! (F & FLAG_PE))
      JMP();
    break;

  case 0xe3: // XTHL
    wordtemp = memory->ReadWord (SP);
    memory->WriteWord (SP, HL);
    HL = wordtemp;
    break;

  case 0xe4: // CPO adr
    if (! (F & FLAG_PE)) {
      CALL();
      jump = true;
    }
    break;

  case 0xe5: // PUSH H
    PUSH (HL);
    break;

  case 0xe6: // ANI byte
    ANA (bytetemp);
    break;

  case 0xe7: // RST 4
    RST (0x20);
    break;

  case 0xe8: // RPE
    if (F & FLAG_PE) {
      RET();
      jump = true;
      CountIntCycles();
    }
    break;

  case 0xe9: // PCHL
    PC = HL;
    CountIntCycles();
    break;

  case 0xea: // JPE adr
    if (F & FLAG_PE)
      JMP();
    break;

  case 0xeb: // XCHG
    wordtemp = DE;
    DE = HL;
    HL = wordtemp;
    break;

  case 0xec: // CPE adr
    if (F & FLAG_PE) {
      CALL();
      jump = true;
    }
    break;

  case 0xee: // XRI byte
    XRA (bytetemp);
    break;

  case 0xef: // RST 5
    RST (0x28);
    break;

  case 0xf0: // RP
    if (! (F & FLAG_S)) {
      RET();
      jump = true;
      CountIntCycles();
    }
    break;

  case 0xf1: // POP PSW
    POP (AF);
    F = (BYTE) ( (F & (FLAG_S | FLAG_Z | FLAG_AC | FLAG_PE | FLAG_CY)) | FLAG_1);
    break;

  case 0xf2: // JP adr
    if (! (F & FLAG_S))
      JMP();
    break;

  case 0xf3: // DI
    iff = false;
    ei1 = false;
    ei2 = false;
    break;

  case 0xf4: // CP adr
    if (! (F & FLAG_S)) {
      CALL();
      jump = true;
    }
    break;

  case 0xf5: // PUSH PSW
    F = (BYTE) ( (F & (FLAG_S | FLAG_Z | FLAG_AC | FLAG_PE | FLAG_CY)) | FLAG_1);
    PUSH (AF);
    break;

  case 0xf6: // ORI byte
    ORA (bytetemp);
    break;

  case 0xf7: // RST 6
    RST (0x30);
    break;

  case 0xf8: // RM
    if (F & FLAG_S) {
      RET();
      jump = true;
      CountIntCycles();
    }
    break;

  case 0xf9: // SPHL
    SP = HL;
    break;

  case 0xfa: // JM adr
    if (F & FLAG_S)
      JMP();
    break;

  case 0xfb: // EI
    ei1 = true;
    ei2 = false;
    break;

  case 0xfc: // CM adr
    if (F & FLAG_S) {
      CALL();
      jump = true;
    }
    break;

  case 0xfe: // CPI byte
    CMP (bytetemp);
    break;

  case 0xff: // RST 7
    RST (0x38);
    break;
  }

  if (ei2) {
    ei2 = false;
    iff = true;
  }

  if (ei1) {
    ei1 = false;
    ei2 = true;
  }

  if (!halt) lastInstrTCycles = GetDuration (opcode, jump);

  countTCycles += lastInstrTCycles;
  totalTCycles += lastInstrTCycles;
  if (totalTCycles < 0) // overflow happen!
    totalTCycles += MAX_SIGNED_INT;

  return lastInstrTCycles;
}
//-----------------------------------------------------------------------------
int ChipCpu8080::GetDuration (BYTE opcode, bool jmp) {
  if (!jmp)
    return duration[opcode];
  if ( (opcode & 0xC7) == 0xC0) // Rx
    return TR5R3R3;
//  if ((opcode & 0xC7) == 0xC4) // Cx
  return TR5R3R3W3W3;
}
//---------------------------------------------------------------------------
void ChipCpu8080::AddDevice (PeripheralDevice * dev) {
  if (!device) {
    device = dev;
    return;
  }
  PeripheralDevice * pd = device;
  while (true) {
    if (!pd->next) {
      pd->next = dev;
      break;
    }
    pd = pd->next;
  }
}
//-----------------------------------------------------------------------------
PeripheralDevice * ChipCpu8080::FindDevice (BYTE port) {
  PeripheralDevice * ph = device;

  while (ph) {
    if ((port & ph->portMask) == ph->portAddr) return ph;
    ph = ph->next;
  }

  return nullptr;
}
//-----------------------------------------------------------------------------
void ChipCpu8080::SetInterruptController (InterruptController * intCtrl) {
  this->intCtrl = intCtrl;
  if (intCtrl != nullptr) intCtrl->cpu = this;
}
//-----------------------------------------------------------------------------
void ChipCpu8080::InitCountIntCycles() {
  intSP = -1;
  intCyclesCur = 0;
  intCyclesMin = MAX_SIGNED_INT;
  intCyclesMax = MIN_SIGNED_INT;
  intCyclesAvg = 0;
}
//---------------------------------------------------------------------------
void ChipCpu8080::CountIntCycles() {
  if (intSP != -1 && intSP == SP) {
    intCyclesCur = totalTCycles - intCyclesCur;
    if (intCyclesCur < 0)
      intCyclesCur += MAX_SIGNED_INT;
    if (intCyclesMin > intCyclesCur)
      intCyclesMin = intCyclesCur;
    if (intCyclesMax < intCyclesCur)
      intCyclesMax = intCyclesCur;
    intCyclesAvg = (intCyclesMin + intCyclesMax) / 2;
    intSP = -1;
  }
}
//---------------------------------------------------------------------------
#include "Pmd32.h"
#include "IifTimer.h"
void ChipCpu8080::TCyclesListeners (int ticks, int dur) {
#ifndef __arm__
    IifTimer::ITimerServiceStatic (ticks, dur);   // TODO : ku podivu tohle dost brzdí emulaci, bohužel některé hry (Sudoku...) to potřebují
#endif // __arm__
    Pmd32::Disk32ServiceStatic    (ticks, dur);
}
