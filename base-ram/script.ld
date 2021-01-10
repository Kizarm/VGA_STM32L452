/* Entry Point */
ENTRY(Reset_Handler)

/* Specify the memory areas */
MEMORY {
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 512K
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 8K
}

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM) + LENGTH(RAM);

/* Define output sections */
SECTIONS {
  .fixed :  {
    . = ALIGN(4);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
  } >FLASH
  .relocate : {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    *(.data*)          /* .data* sections */
    _edata = .;        /* define a global symbol at data end */
  } >RAM
  /DISCARD/ : {
    *(.comment*)
    *(.ARM.*)
  }
  .ARM.attributes 0 : { *(.ARM.attributes) }
}
