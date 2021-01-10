/* Entry Point */
ENTRY(Loader_Reset_Handler)

/* Generate a link error if heap and stack don't fit into RAM */
_Min_Heap_Size  = 0; /* required amount of heap  */
_Min_Stack_Size = 0; /* required amount of stack */

/* Specify the memory areas */
MEMORY {
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 512K
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 160K
}

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM) + LENGTH(RAM);

/* Define output sections */
SECTIONS {
  .fixed : {
    _flash_begin = .;
    KEEP(*(.loader_vector))
    *(.text.start)
  } >FLASH
  _siload = .;
  /* The startup code goes first into FLASH */
  /* The program code and other data goes into FLASH */
  .relocate : AT ( _siload )  {
    . = ALIGN(4);
    PROVIDE_HIDDEN (_vect_tab_begin = .);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(4);
    *(.after_vector)
    . = ALIGN(4);
    _etext = .;        /* define a global symbols at end of code */

    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    *(.glue_7)         /* glue arm to thumb code */
    *(.glue_7t)        /* glue thumb to arm code */
    *(.eh_frame)

    *(.init)
    *(.fini)
    /* Pro použití statických konstruktorů v C++, KEEP musí být použit při gc */
    . = ALIGN(4);
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(.ctors))    /* for clang */
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end   = .);
    
    /* Pro použití statických destruktorů v C++, KEEP musí být použit při gc */
    . = ALIGN(4);
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(.dtors))    /* for clang */
    KEEP (*(.fini_array*))  /* for gcc   */
    PROVIDE_HIDDEN (__fini_array_end   = .);
    . = ALIGN(8);
    /* used by the startup to initialize data */
    _sidata = .;
    _sdata = .;        /* create a global symbol at data start */    
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */
    . = ALIGN(8);
    *(.fast.*)         /* funkce běžící rychle v RAM */
    . = ALIGN(8);
    _edata = .;        /* define a global symbol at data end */
    . = ALIGN(4);
  } >RAM

  /* Uninitialized data section */
  .bss : {
    . = ALIGN(4);
    /* This is used by the startup in order to initialize the .bss secion */
    _sbss = .;         /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)
    _ebss = .;
    __bss_end__ = _ebss;
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
  } >RAM
  /* Remove information from the standard libraries */
  /DISCARD/ :
  {
    *(.comment*)
    *(.ARM.*)
  }

  .ARM.attributes 0 : { *(.ARM.attributes) }
}

