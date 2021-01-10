  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .section .rodata.rom
  .globl ROM_data, ROM_data_len
  .globl BAS_data, BAS_data_len
  .align 4
ROM_data:
  .incbin "./cpu/monit2A.rom"
ROM_data_end:
  .align 2
ROM_data_len:
  .word ROM_data_end - ROM_data;
  /*
  .incbin "./com/image.com"
  */
BAS_data:

  .incbin "./cpu/basic2A.rmm"
/*
  .incbin "./cpu/miny.rmm"
*/
BAS_data_end:
  .align 2
BAS_data_len:
  .word BAS_data_end - BAS_data;

.end

