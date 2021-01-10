#include "PMD85v2A.h"

extern "C" const unsigned char ROM_data[];
extern "C" const unsigned long ROM_data_len;
extern "C" const unsigned char BAS_data[];
extern "C" const unsigned long BAS_data_len;

extern "C" const unsigned char IMG_data[];
extern "C" const unsigned long IMG_data_len;

PMD85v2A::PMD85v2A() : memory (),
  cpu (& memory),
  pio (& memory, SYSTEM_PIO_ADR, SYSTEM_PIO_MASK, true),
  rom (          ROM_MODULE_ADR, ROM_MODULE_MASK, true),
  tim (& cpu,    IIF_TIMER_ADR,  IIF_TIMER_MASK, false),
  ift (          IIF_TAPE_ADR,   IIF_TAPE_MASK,   true)
/*igp (          IIF_GPIO_ADR,   IIF_GPIO_MASK,   true)*/ {

}
void PMD85v2A::Init() {
  memory.atach   (ROM_data, ROM_data_len, 0x8000);
//memory.atach   (IMG_data, IMG_data_len, 0x0000);  
  rom.InsertRom  (0, BAS_data_len / 1024, BAS_data);
  cpu.AddDevice  (&rom);
  cpu.AddDevice  (&pio);
  cpu.AddDevice  (&tim);
  cpu.AddDevice  (&ift);
//cpu.AddDevice  (&igp);
}
