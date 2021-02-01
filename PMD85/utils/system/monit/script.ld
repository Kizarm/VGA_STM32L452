OUTPUT_ARCH("z80")
/* Entry Point - musí být definován     */
ENTRY(START)
/* Specifikace paměťových prostorů čipu */
MEMORY {
  /* Začátek zvolen na 0 */
  RAM  (xrw)      : ORIGIN = 0x00008000, LENGTH = 0x8000
}
/* Definice výstupních sekcí */
SECTIONS {
  .fixed : {
    KEEP(*(.text.monit));
    _text_end = .;
  } >RAM
}
