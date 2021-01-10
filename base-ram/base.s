  .syntax unified
  .cpu cortex-m3
  .fpu softvfp
  .thumb

  .global g_pfnVectors
  .global Reset_Handler
  .extern _sdata
  .extern _estack

  .section  .text.Reset_Handler
  .type Reset_Handler, %function
Reset_Handler:
  ldr   r0,user_code_begin  @ load sp and pc from user code (vector table)
  ldr   sp,[r0]             @ ldmia not support sp
  ldr   pc,[r0, #4]         @ jump to user

  .align 2
user_code_begin:
  .word _sdata
  .size Reset_Handler, .-Reset_Handler

  .section  .isr_vector,"a",%progbits
  .type g_pfnVectors, %object
g_pfnVectors:
  .word _estack
  .word Reset_Handler
  .size g_pfnVectors, .-g_pfnVectors
