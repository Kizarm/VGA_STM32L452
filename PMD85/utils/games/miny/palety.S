  .section .text.palety
  .globl SetPal,SetCol,PalAce
; **************************
; Nastaví barevné schéma hry
; **************************
SetPal:
	ld a,(ColorMode)	; dle kódu barevného režimu
	ld hl,tbPals	; z nabídky palet
	rst 0x18; vybere adresu požadované palety
	ld (GetCol+1),hl	; a uloží ji jako aktuální
	ld a,(ColorMode)	; dle kódu barevného režimu
	ld hl,tbTextur	; z nabídky textur buněk
	rst 0x18; vybere adresu požadované sady
	ld (ZobrazBunkuStd+1),hl
			; a uloží ji jako aktuální
	ret
			; tabulka adres palet barev
tbPals:   .dw Pal_BW,PalRGB,PalWGR,PalAce
			; tabulka sad textur buněk
tbTextur: .dw tbBunekBW,tbBunekRGB,tbBunekWGR,tbBunekACE 
; *****************************************
; Vybere barvu z barvového registru dle ACC
; a uloží ji do (ColAtr) a do HL.
; *****************************************
SetCol:	call GetCol	; načte atribut barvy dle ACC do HL
	ld (ColAtr),hl	; a uloží i do atributu barvy
	ret
; ********************************************************
; Barvové palety
; Barva #00 - pozadí musí mít oba barvové atributy stejné
; a tak lze vybírat pouze ze 4 základních barev mimo barvy
; systému ColorAce (dostupné: GRN, RED, BLU, PUR)
; ********************************************************
; ********************************************************
;.module Monochrom
_White		.equ 00000h
_Gray		.equ 04040h
_FlashWhite	.equ 08080h
_FlashGray	.equ 0c0c0h
Pal_BW:	.dw _Gray	; #00 pozadí
	.dw _White	; #01 nápis minesweeper
	.dw _Gray	; #02 BEST PLAYERS
	.dw _Gray	; #03 jména nejlepších hráčů
	.dw _White	; #04 :L:EVEL
	.dw _White	; #05 :C:OLOR
	.dw _White	; #06 :M:OUSE
	.dw _White	; #07 PRESS EOL..
	.dw _Gray	; #08 2020 LIBOR L.A.
	.dw _White	; #09 výložky
	.dw _White	; #10 rámeček hracího pole
	.dw _Gray	; #11 rámeček editoru jména
	.dw _White	; #12 nadpis Enter name
	.dw _White	; #13 text editoru jména
; ********************************************************
;.module RGBM4
_Green		.equ 00000h
_Red		.equ 04040h
_Blue		.equ 08080h
_Magenta	.equ 0c0c0h
PalRGB:	.dw _Blue	; #00 pozadí
	.dw _Green	; #01 nápis minesweeper
	.dw _Red	; #02 BEST PLAYERS
	.dw _Red	; #03 jména nejlepších hráčů
	.dw _Magenta	; #04 :L:EVEL
	.dw _Magenta	; #05 :C:OLOR
	.dw _Magenta	; #06 :M:OUSE
	.dw _Magenta	; #07 PRESS EOL..
	.dw _Red	; #08 2020 LIBOR L.A.
	.dw _Green	; #09 výložky
	.dw _Magenta	; #10 rámeček hracího pole
	.dw _Red	; #11 rámeček editoru jména
	.dw _Magenta	; #12 nadpis Enter name
	.dw _Green	; #13 text editoru jména
; ********************************************************
;.module WGRM4
WGRM4_White		.equ 00000h
WGRM4_Green		.equ 04040h
WGRM4_Red		.equ 08080h
_Maroon		.equ 0c0c0h
PalWGR:	.dw _Maroon	; #00 pozadí
	.dw WGRM4_White	; #01 nápis minesweeper
	.dw WGRM4_Red	; #02 BEST PLAYERS
	.dw WGRM4_Red	; #03 jména nejlepších hráčů
	.dw WGRM4_Green	; #04 :L:EVEL
	.dw WGRM4_Green	; #05 :C:OLOR
	.dw WGRM4_Green	; #06 :M:OUSE
	.dw WGRM4_Green	; #07 PRESS EOL..
	.dw WGRM4_Red	; #08 2020 LIBOR L.A.
	.dw WGRM4_White	; #09 výložky
	.dw WGRM4_White	; #10 rámeček hracího pole
	.dw WGRM4_Red	; #11 rámeček editoru jména
	.dw WGRM4_Green	; #12 nadpis Enter name
	.dw WGRM4_White	; #13 text editoru jména
; ********************************************************
;.module COLORACE
COLORACE_Green		.equ 00000h
COLORACE_Red		.equ 04040h
COLORACE_Blue		.equ 08080h
COLORACE_Magenta	.equ 0c0c0h
COLORACE_Yellow		.equ 00040h
_Cyan		.equ 00080h
COLORACE_White		.equ 000c0h
PalAce:	.dw _Blue	; #00 pozadí
	.dw COLORACE_White	; #01 nápis minesweeper
	.dw COLORACE_Magenta	; #02 BEST PLAYERS
	.dw COLORACE_Magenta	; #03 jména nejlepších hráčů
	.dw COLORACE_Yellow	; #04 :L:EVEL
	.dw COLORACE_Yellow	; #05 :C:OLOR
	.dw COLORACE_Yellow	; #06 :M:OUSE
	.dw COLORACE_Green	; #07 PRESS EOL..
	.dw COLORACE_Red	; #08 2020 LIBOR L.A.
	.dw _Cyan	; #09 výložky
	.dw _Cyan	; #10 rámeček hracího pole
	.dw COLORACE_Magenta	; #11 rámeček editoru jména
	.dw COLORACE_Yellow	; #12 nadpis Enter name
	.dw COLORACE_Green	; #13 text editoru jména
