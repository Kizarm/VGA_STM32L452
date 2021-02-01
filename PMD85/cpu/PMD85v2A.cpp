#include "PMD85v2A.h"

extern "C" const unsigned char ROM_data[];
extern "C" const unsigned long ROM_data_len;

#include <string.h>
PMD85v2A::PMD85v2A() : memory ()
  ,cpu (& memory)
  ,pio (& memory, SYSTEM_PIO_ADR, SYSTEM_PIO_MASK, true)
  ,rom (          ROM_MODULE_ADR, ROM_MODULE_MASK, true)
  ,tim (& cpu,    IIF_TIMER_ADR,  IIF_TIMER_MASK, false)
  ,ift (          IIF_TAPE_ADR,   IIF_TAPE_MASK,   true)
  ,igp (          IIF_GPIO_ADR,   IIF_GPIO_MASK,   true)
  ,p32 (& igp), file()  {
   p32.InsertAllDisks();
}
void PMD85v2A::Init() {
  memory.atach   ("monit2A.rom", 0x8000);
  rom.InsertFile ("loader.rmm");   // ty soubory musí mít nejen správný obsah, pořadí
  rom.InsertFile ("basic2A.rmm");  // ale i délku, nikde se to dál nekontroluje
  cpu.AddDevice  (&rom);
  cpu.AddDevice  (&pio);
  cpu.AddDevice  (&tim);
  cpu.AddDevice  (&ift);
  cpu.AddDevice  (&igp);
}
