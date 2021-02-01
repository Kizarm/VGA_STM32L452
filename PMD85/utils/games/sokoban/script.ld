OUTPUT_ARCH("z80")
/* Entry Point - musí být definován     */
ENTRY(main)
/* Specifikace paměťových prostorů čipu */
MEMORY {
  RAM (xrw)       : ORIGIN = 0x00000000, LENGTH = 0x7000
}
/* Kam umístíme stack - navrch RAM */
initsp = ORIGIN(RAM) + LENGTH(RAM);
/* Definice výstupních sekcí       */
SECTIONS {
  .fixed : {
    __Ltext = .;
    *(.text*)            /* .text*   sections (code)                              */
    *(text*)             /*  text*   sections (code)                              */
    *(.rodata*)          /* .rodata* sections (constants, strings, etc.)          */
    *(.eh_frame)
    __Htext = .;
  } >RAM
  .reloc : {
    __Ldata = .;
    *(.data*)            /* .data* sections */
    *(data*)             /*  data* sections */
    __Hdata = .;
    __Lbss = .;
    *(.bss*)             /* .bss*  sections */
    *(bss*)              /*  bss*  sections */
    __Hbss = .;
    *(COMMON)
    heap = .;
  } >RAM
levels : {
        levels = .;
        . += def_levels_len;
        levels_end = .;
        }
deflevels __Lbss : {
	deflevels.o(.data)
	} >RAM
}
