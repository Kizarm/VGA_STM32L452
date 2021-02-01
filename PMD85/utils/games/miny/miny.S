/*  VLEVO = kurzorová šipka vlevo
    VPRAVO = kurzorová šipka vpravo
    NAHORU = HOME / LINE LEFT
    DOLŮ = END / LINE RIGHT
    L-tlačítko = DELETE
    P-tlačítko = CLR
    restart hry = K1
    návrat do menu = STOP
    
    Tato verze je upravena z původního zdroje https://www.pmd85.cz/wp-content/uploads/minysrc.zip
    pro GNU binutils https://www.gnu.org/software/binutils/ (z80-none-elf-as ...), Vše  už je
    v samostatných modulech, pokud se v add_def.S vypnou první 2 volby, zůstane kód bitově stejný
    jako originál, žádné vážné úpravy v tom nejsou.
*/
.include "add_def.S"
  .section .text.start
  .globl zero_addr, GetCol
zero_addr:
  .p2align 3
	di		; skok na začátek hry
	ld sp,8000h	
	 jp Start
LDIR:
	ret z
; .org 8    ; RST 1
	.p2align 3
			; *****
	ld a,(hl)		; LDIR - kopírování bloku
	ld (de),a		; (HL) >> (DE) o délce C
	inc hl
	inc de
	dec c
	 jp LDIR
; .org 10h  ; RST 2
  .p2align 3
			; *****
	add a,l		; HL := HL + A
	ld l,a
	ret nc
	inc h
	ret
; ************************************************************
; Dle hodnoty v ACC načte Colorace atribut z nastavené palety.
; Parametr instrukce "lxi h,.." je měněn dle vybrané palety.
; Podpora funkce SetPal.
; ************************************************************
GetCol:
  ld hl,PalAce	; HL := atribut barvy z tabulky dle A
; .org 18h  ; RST 3
  .p2align 3
			; *****
	add a,a		; HL = (HL + 2xA)
	rst 0x10
	ld a,(hl)
	inc hl
	ld h,(hl)
	ld l,a
	ret
; .org 20h  ; RST 4
  .p2align 3
			; *****
	ld a,l		; Porovná HL s obsahem DE
	sub e		; Příznaky jako u rodiny instrukcí CMP
	ld a,h		; Z=1 když HL=DE (Z=0 když HL<>DE)
	sbc a,d		; CY=1 když HL<DE (CY=0 když HL>=DE)
	ret
; .org 28h  ; RST 5
  .p2align 3
			; *****
	ld a,h		; Test klávesy ve sloupci H
	out (kbdout),a	; s maskou L
	in a,(kbdin)	; Z=1 když je klávesa stisknuta
	and l
	ret
; .org 30h  ; RST 6
  .p2align 3
			; *****
	 jp MysDea	; zkratka na proceduru
; .org 38h  ; RST 7
  .p2align 3
			; *****
	 jp MysAct	; zkratka na proceduru
.end

