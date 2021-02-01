  .syntax unified
  .cpu cortex-m3
  .fpu softvfp
  .thumb

  .global BootFromRam

  .section  .text.BootFromRam
  .type BootFromRam, %function
BootFromRam:
  eor   r1,r1,r1
  eor   r2,r2,r2
  eor   r3,r3,r3
  eor   r4,r4,r4
  eor   r5,r5,r5
  ldr   r0,user_code_begin  @ load sp and pc from user code (vector table)
  ldr   sp,[r0]             @ ldmia not support sp
  ldr   pc,[r0, #4]         @ jump to user

  .align 2
user_code_begin:
  .word 0x20000000
  .size BootFromRam, .-BootFromRam
