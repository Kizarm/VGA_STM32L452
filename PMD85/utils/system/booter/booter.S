;------------------------------------------------------------------------------
; BOOTER PMD 32 pre PMD 85-2(A)
; Roman Borik/RM-Team
;      02/2010 - verzia 1
;      04/2013 - verzia 2 - volba BASIC, MONIT, PMD 32
;      05/2013 - verzia 3 - pridana chybajuca inicializacia premennej ESCSEQ
;      04/2015 - verzia 4 - opravena chyba s "odstrankovanim" zasobnika
;      04/2015 - verzia 5 - nastrankovanie RAM presunute do QBOOT
;   24.04.2015 - verzia 6 - opraveny test ROM/RAM
; BOOTER natiahne z ROM modulu ovladac PMD 32 a cast konzolovych rutin pre
; MIKROS V2.2 do nevyuzitej casti VRAM a umoznuje pouzivat 32kB MIKROS V2.2
; na PMD 85-2, respektive 48kB MIKROS V2.2 na PMD 85-2A.
; BOOTER je ulozeny v dvoch 1kB EPROM a musi byt umiestneny v prvych dvoch
; poziciach ROM Modulu. BASIC je treba presunut o 2 pozicie dalej.
; V pripade 32k ROM Modulu je Booter v 2kB EPROM a BASIC sa posunie o 1 poziciu.
; Po Resete sa zobrazi volba ci sa ma spustit povodny kazetovy BASIC, alebo sa
; ma skocic do Monitora alebo sa ma natiahnut ovladac PMD 32 do VRAM.
; Ak je zvolena 3. moznost, z pripojenej PMD 32 sa pokusi precitat BOOT sektor
; z mechaniky A: na adresu 0080h. Pokial sa to podari, skoci sa na adresu 0080h
; a dalsia cinnost pocitaca zavisi od samotneho kodu BOOT sektora.
; Ak sa BOOT sektor nepodari z disku precitat, skoci sa do Monitora a zobrazi
; sa hlasenie "++ Os ready ++".
;------------------------------------------------------------------------------
;		cpu	8080
;		page	0
		.title	"BOOTER PMD 32 pre PMD 85-2(A)"
;------------------------------------------------------------------------------
/* Verze pro nástroje GNU binutils Z80.
   Linkování je poměrně komplikované, protože se výsledný kód kopíruje do
   úseku paměti, který není souvislý. Kód je plně binárně kompatibilní.
*/
; rutiny v ROM
MONIT2		.equ	803Eh	; adresa pre navrat do Monitora
PRTOUT		.equ	8500h	; zobrazenie znaku na aktualnu poziciu kurzora
KLAV		  .equ	84A1h	; test klavesnice s cakanim
ROMIN		  .equ	8C00h	; nacitanie bloku dat z ROM Modulu
JOB		    .equ	8F94h	; obsluha prikazu JOB
; premenne monitora
CURSOR		.equ	0C03Eh	; adresa kurzora
CURCH		  .equ	0C072h	; ukazatel na vstupny text
ESCSEQ		.equ	0C33Ch	; priznak ESC sekvencie
; zaciatocna adresa ovladaca vo VRAM
BeginAdr 	.equ	0C470h
; adresa riadiaceho portu systemovej 8255
;SYS_CW		port	0F7h
Pages .equ 0x52
;------------------------------------------------------------------------------
;		org	0
    .section .text.start
    .globl Start,Booter,Booter_end,BooterLen
;------------------------------------------------------------------------------
Start:
      call ROMIN		; natiahnutie Loadera do RAM od adresy 0080h
			.dw	BtrX
			.dw	BooterLen - 1
			.dw	Booter
			jp  Booter
;------------------------------------------------------------------------------
BtrX:
;   phase 80h
;     .align 6
    .section .text.boot
;------------------------------------------------------------------------------
Booter:		xor a		; vynuluj priznak ESC sekvencie
			ld (ESCSEQ),a
			ld hl,0DD8Bh	; adresa VRAM kam sa zobrazi text
			ld (CURSOR),hl
			ld hl,Text		; adresa textu
			ld b,TextLen	; dlzka textu
Bt1:		ld a,(hl)		; zobraz text
			inc hl
			call PRTOUT
			dec b
			jp nz,Bt1
Bt2:		call KLAV		; test klavesnice
			cp 'M'		; 'M'?
			jp z,MONIT2		; ano, skoc do Monitora
			cp 'P'		; 'P'?
			jp z,Loader		; ano, skoc natiahnut ovladac PMD 32
			cp 'B'		; 'B'?
			jp nz,Bt2		; nie, cakaj dalej
;------------------------------------------------------------------------------
Basic:		ld hl,JobStr	; natiahnutie BASICu do pamati cez prikaz JOB
			ld (CURCH),hl
			 jp JOB
; BASIC je umiestneny za Booterom od adresy 0800.
JobStr:		.db	"080C23F40000"	; 080Ch, 23F4h, 0000h 
Text:     .db  "B-BASIC  M-MONIT  P-PMD 32",13
TextLen   .equ  $-Text
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
; Loader nahraje kod konzolovych rutin a ovladaca PMD 32 do nevyuzitej oblasti
; vedla VideoRAM
Loader:
      ld b,Pages
Loader3:
      push bc
      call ROMIN        ; v DE vraci posledni adresu tgt
LdSrc:		.dw	LdrX      ; from
LdLen:		.dw	000Fh     ; len - 1
LdTrg:		.dw	BeginAdr  ; to
			ld hl,0030h
			add hl,de
			ld (LdTrg),hl
			ld de,0010h
			ld hl,(LdSrc)
			add hl,de
			ld (LdSrc),hl
			pop bc
			dec b
      jp nz,Loader3
      jp BeginAdr
Booter_end:
;------------------------------------------------------------------------------
BooterLen 	.equ	Booter_end - Booter
;		dephase
;------------------------------------------------------------------------------
LdrX .equ _fixed_end  ; z linker skriptu
;  include	"pmd32-bios-driver.a8080"
;------------------------------------------------------------------------------
;TotalLen	.equ	$-Start
;------------------------------------------------------------------------------
  .section .text.fill
  .ds.b 597, 0xFF     ; dospecifikovat rucne podle velikosti binarky

.end
