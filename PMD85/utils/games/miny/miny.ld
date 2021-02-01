OUTPUT_ARCH("z80")
/* Entry Point - musí být definován     */
ENTRY(zero_addr)
/* Specifikace paměťových prostorů čipu */
MEMORY {
  /* Začátek zvolen na 0 */
  RAM (xrw)       : ORIGIN = 0x00000000, LENGTH = 0x08000
  ROM (xrw)       : ORIGIN = 0x00000000, LENGTH = 0x10000
}
/* Definice výstupních sekcí */
SECTIONS {
  .fixed : {
  zero_addr = .;
    miny.o(.text.start)
    *(.text.mouse.base)
    *(.text.mouse.bufer)
    *(.text.mouse.aligned)
    *(.text.hra)
    *(.text.sluzby)
    *(.text.menu)
    *(.text.timer)
    *(.text.script)
    *(.text.editor)
    *(.text.palety)
    *(.text.bitmapy)
    *(.text.grafika)
    *(.text.print)
    *(.text.generator)
    *(.text.blockworld)
    *(.text*)
  } >RAM
  .reloc (NOLOAD) : {     /* vyházet nepotřebné   */
    *(.bss)
  } >ROM
}
