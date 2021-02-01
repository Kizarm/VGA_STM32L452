  .equ BSTART,  0x0   ; zacatek binarky, vyzkouseno pouze 0
  .equ TRANSFER,0x8C00
  .section .text.boot
  .globl boot
  .extern BINLEN
boot:
  call TRANSFER
  .dw  boot_end
  .dw  BINLEN
  .dw  BSTART
  jp   BSTART
boot_end:
.end

