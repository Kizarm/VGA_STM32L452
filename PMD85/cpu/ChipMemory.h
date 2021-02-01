#ifndef CHIPMEMORY_H
#define CHIPMEMORY_H

#include "Globals.h"
// operations
enum OPERATIONS {
  OP_READ = 0, OP_WRITE
};
static constexpr unsigned PmdMemorySize = 0x10000;

class ChipMemory {
    uint8_t memory_data [PmdMemorySize];
    bool allRAM;
  public:
    ChipMemory();
    uint8_t * base () { return memory_data; };
    void atach     (const char * filename, const unsigned int offset = 0u);
    void ResetOn   ();
    void ResetOff  () {};
    
    BYTE ReadByte  (int physAddr);
    WORD ReadWord  (int physAddr);
    void WriteByte (int physAddr, BYTE value);
    void WriteWord (int physAddr, WORD value);
    
    bool IsAllRAM  ()            { return allRAM;   }
    void SetAllRAM (bool allram) { allRAM = allram; }
  protected:
    BYTE * FindPointer (int physAddr, OPERATIONS ops);
};

#endif // CHIPMEMORY_H
