#ifndef PMD85V2A_H
#define PMD85V2A_H

#include "Globals.h"
#include "diskopsfile.h"
#include "IifGPIO.h"
#include "Pmd32.h"
#include "ChipCpu8080.h"
#include "ChipMemory.h"
#include "SystemPIO.h"
#include "RomModule.h"
#include "IifTimer.h"
#include "IifTape.h"

class PMD85v2A {
  ChipMemory  memory;
  ChipCpu8080 cpu;
  SystemPIO   pio;
  RomModule   rom;
  IifTimer    tim;
  IifTape     ift;
  IifGPIO     igp;
  Pmd32       p32;
  DiskOpsFile file;
  public:
    PMD85v2A();
    void Init ();
    void Step () {
      cpu.DoInstruction();
    }
    void Reset () {
      cpu.DoReset();
    }
    uint8_t * Base () {
      return memory.base();
    }
    void Keyboard (SDL_SCAN_CODES code, bool pressed) {
      pio.KeyBoardAsync (code, pressed);
    }
};

#endif // PMD85V2A_H
