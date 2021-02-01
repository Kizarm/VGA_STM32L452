; labels.s
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


; Labels.

	.include "sokoban.inc"
	
; ==============================================================================
; Label "SOKOBAN 1.0"
;
	.data
	.globl	label_sokoban
label_sokoban:
	.byte	12, 16
	.byte	0x3e, 0x21, 0x1f, 0x0c, 0x0c, 0x3e, 0x31, 0x1f, 0x20, 0x01
	.byte	0x03, 0x03, 0x00, 0x03, 0x38, 0x01
	.byte	0x3f, 0x33, 0x3f, 0x0c, 0x0e, 0x3f, 0x33, 0x3f, 0x30, 0x03
	.byte	0x07, 0x03, 0x20, 0x03, 0x3c, 0x03
	.byte	0x03, 0x33, 0x30, 0x0c, 0x07, 0x03, 0x33, 0x30, 0x38, 0x07
	.byte	0x07, 0x03, 0x30, 0x03, 0x0e, 0x07
	.byte	0x03, 0x30, 0x30, 0x2c, 0x03, 0x03, 0x33, 0x30, 0x1c, 0x0e
	.byte	0x0f, 0x03, 0x00, 0x03, 0x06, 0x06
	.byte	0x03, 0x30, 0x30, 0x3c, 0x01, 0x03, 0x33, 0x30, 0x0c, 0x0c
	.byte	0x0f, 0x03, 0x00, 0x03, 0x06, 0x06
	.byte	0x3f, 0x31, 0x30, 0x3c, 0x00, 0x03, 0x33, 0x1f, 0x0c, 0x0c
	.byte	0x1b, 0x03, 0x00, 0x03, 0x06, 0x06
	.byte	0x3e, 0x33, 0x30, 0x3c, 0x00, 0x03, 0x33, 0x1f, 0x3c, 0x0f
	.byte	0x1b, 0x03, 0x00, 0x03, 0x06, 0x06
	.byte	0x00, 0x33, 0x30, 0x3c, 0x01, 0x03, 0x33, 0x30, 0x3c, 0x0f
	.byte	0x33, 0x03, 0x00, 0x03, 0x06, 0x06
	.byte	0x00, 0x33, 0x30, 0x2c, 0x03, 0x03, 0x33, 0x30, 0x0c, 0x0c
	.byte	0x33, 0x03, 0x00, 0x03, 0x06, 0x06
	.byte	0x03, 0x33, 0x30, 0x0c, 0x07, 0x03, 0x33, 0x30, 0x0c, 0x0c
	.byte	0x23, 0x03, 0x00, 0x03, 0x0e, 0x07
	.byte	0x3f, 0x33, 0x3f, 0x0c, 0x0e, 0x3f, 0x33, 0x3f, 0x0c, 0x0c
	.byte	0x23, 0x03, 0x00, 0x33, 0x3c, 0x03
	.byte	0x3e, 0x21, 0x1f, 0x0c, 0x0c, 0x3e, 0x31, 0x1f, 0x0c, 0x0c
	.byte	0x03, 0x03, 0x00, 0x33, 0x38, 0x01
	
	.end
