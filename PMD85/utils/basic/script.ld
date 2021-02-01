OUTPUT_ARCH("z80")
/* Entry Point - musí být definován     */
ENTRY(init)
/* Specifikace paměťových prostorů čipu */
MEMORY {
  /* Začátek zvolen na 0 */
  RAM  (xrw)      : ORIGIN = 0x00000000, LENGTH = 0x08000
}
/* Definice výstupních sekcí */
SECTIONS {
  .reload : {
  init = .;
    *(.text.start)
  } >RAM
}
