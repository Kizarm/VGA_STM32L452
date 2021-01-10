#ifndef CHIPMEMORY_H
#define CHIPMEMORY_H

#include "Globals.h"
// operations
enum OPERATIONS {
  OP_READ = 0, OP_WRITE
};

class ChipMemory {
    uint8_t memory_data [0x10000];
  public:
    ChipMemory();
    uint8_t * base () { return memory_data; };
    void atach     (const uint8_t * rom, const unsigned int len, const unsigned int offset = 0u);
    void ResetOn   ();
    void ResetOff  () {};
    
    BYTE ReadByte  (int physAddr);
    WORD ReadWord  (int physAddr);
    void WriteByte (int physAddr, BYTE value);
    void WriteWord (int physAddr, WORD value);
  protected:
    BYTE * FindPointer (int physAddr, OPERATIONS ops);
};

#endif // CHIPMEMORY_H
