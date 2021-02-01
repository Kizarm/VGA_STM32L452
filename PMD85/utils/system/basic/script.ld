OUTPUT_ARCH("z80")
/* Entry Point - musí být definován     */
ENTRY(init)
/* Specifikace paměťových prostorů čipu */
MEMORY {
  /* Začátek zvolen na 0 */
  RAM  (xrw)      : ORIGIN = 0x00000000, LENGTH = 0x08000
  RAM1 (xrw)      : ORIGIN = 0x00000000, LENGTH = 0x08000
}
/* Definice výstupních sekcí */
SECTIONS {
  .fixed : {
    KEEP(*(.text.boot));
    _text_end = .;
  } >RAM
  .reload : AT(_text_end) {
  init = .;
    *(.text.start)
  } >RAM1
}
