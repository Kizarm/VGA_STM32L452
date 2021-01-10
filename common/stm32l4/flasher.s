  .syntax unified
  .cpu cortex-m3
  .fpu softvfp
  .thumb

  .global g_ldrVectors
  .global Loader_Reset_Handler
  .extern _edata
  .extern _estack
  .extern _vect_tab_begin

  .section .text.start
  .type Loader_Reset_Handler, %function
Loader_Reset_Handler:
  b	LoopCopyDataInit

CopyDataInit:
	ldr	r3, =_siload
	ldr	r3, [r3, r1]
	str	r3, [r0, r1]
	adds	r1, r1, #4
LoopCopyDataInit:
	ldr	r0, =_vect_tab_begin
	ldr	r3, =_edata
	adds	r2, r0, r1
	cmp	r2, r3
	bcc	CopyDataInit

  ldr   r0, flash_tab_begin @ load sp and pc from user code (vector table)
  ldr   sp,[r0]             @ ldmia not support sp
  ldr   pc,[r0, #4]         @ jump to user

  .align 2

flash_tab_begin:
  .word _vect_tab_begin
  .size Loader_Reset_Handler, . - Loader_Reset_Handler

  .section  .loader_vector
  .type g_ldrVectors, %object
g_ldrVectors:
  .word _estack
  .word Loader_Reset_Handler
  .size g_ldrVectors, .-g_ldrVectors

