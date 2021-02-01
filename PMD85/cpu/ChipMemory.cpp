#include "ChipMemory.h"
#include "ff.h"

ChipMemory::ChipMemory() {
  allRAM = false;
}
void ChipMemory::ResetOn() {
}

BYTE ChipMemory::ReadByte (int physAddr) {
  BYTE * ptr = FindPointer (physAddr,OP_READ);
  if (ptr) return * ptr;
  return 0u;
}
WORD ChipMemory::ReadWord (int physAddr) {
  WORD value;
  value = ReadByte(physAddr);
  value |= (WORD) (ReadByte((physAddr + 1) & 0xFFFF) << 8);
  return value;
}
void ChipMemory::WriteByte (int physAddr, BYTE value) {
  BYTE * ptr = FindPointer (physAddr, OP_WRITE);
  if (ptr) * ptr = value;
}
void ChipMemory::WriteWord (int physAddr, WORD value) {
  WriteByte(physAddr, (BYTE) (value & 0xFF));
  WriteByte((physAddr + 1) & 0xFFFF, (BYTE) ((value >> 8) & 0xFF));
}

BYTE * ChipMemory::FindPointer (int physAddr, OPERATIONS ops) {
  if (physAddr >= 0 && physAddr <= 0xFFFF) {
    const int mapAddr = physAddr;
    // tohle hlidani zapisu do oblasti monitoru mozna neni potreba, ale delalo bez nej blbosti, zase vadi u MIKROS
    if ((allRAM == false) and (ops == OP_WRITE) and (mapAddr >= 0x8000) and (mapAddr < 0x9000)) return nullptr;
    return memory_data + mapAddr;
  }
  return nullptr;
}
void ChipMemory::atach (const char * filename, const unsigned int offset) {
  uint8_t * dest = memory_data + offset;
  FIL handle;
  if (f_open (&handle, filename, FA_READ) != FR_OK) return;
  const unsigned to_read = PmdMemorySize - offset;
  unsigned readen = 0u;
  f_read (&handle, dest, to_read, &readen);
  debug ("readen 0x%04X bytes from file \"%s\"\n", readen, filename);
  f_close(&handle);
}
