; wrchar.s
;
; Copyright (C) 2015, Tomáš Pecina <tomas@pecina.cz>
;
; This file is part of cz.pecina.retro, retro 8-bit computer emulators.
;
; This application is free software: you can redistribute it and/or
; modify it under the terms of the GNU General Public License as
; published by the Free Software Foundation, either version 3 of the
; License, or (at your option) any later version.
;
; This application is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.         
;
; You should have received a copy of the GNU General Public License
; along with this program.  If not, see <http://www.gnu.org/licenses/>.


; Modified WRCHAR, with ADRAS (not available in PMD 85-1) and for 10-cell
; glyphs.  In addition, this version is interrupt-compatible as it does not
; use the stack pointer.

	.include "pmd85.inc"
	
; ==============================================================================
; wrchar - write character
; 
;   input:  A - character code
; 	    HL - cursor address
; 	    (color) - color mask
; 
;   uses:   A
; 
	.text
	.globl	wrchar
wrchar:
	push	bc
	push	de
	push	hl
	ex	de,hl
	ld	hl,0
	add	hl,sp
	ld	(tstack),hl
	ex	de,hl
	call	adras
	ex	de,hl
	pop	hl
	push	hl
	ld	bc,-128
	add	hl,bc
	ld	c,10
	ld	a,(color)
	ld	b,a
	ld	sp,-64
1:	dec	de
	ld	a,(de)
	xor	b
	ld	(hl),a
	add	hl,sp
	dec	c
	jp	nz,1b
	ld	(hl),b
	ld	hl,(tstack)
	ld	sp,hl
	pop	hl
	pop	de
	pop	bc
	ret

	.comm	tstack, 2

	.end
