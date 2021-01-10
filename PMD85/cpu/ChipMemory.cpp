#include "ChipMemory.h"

ChipMemory::ChipMemory() {
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
    if ((mapAddr >= 0x8000) and (mapAddr < 0x9000) and (ops == OP_WRITE)) return nullptr;
    return memory_data + mapAddr;
  }
  return nullptr;
}
void ChipMemory::atach (const uint8_t * rom, const unsigned int len, const unsigned int offset) {
  uint8_t * dest = memory_data + offset;
  for (unsigned n=0; n<len; n++) dest [n] = rom [n];
}
