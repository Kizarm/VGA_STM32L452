;------------------------------------------------------------------------------
; Ovladac PMD 32 pre PMD 85-2(A)
; Roman Borik/RM-Team
;   19.04.2015 - verzia 4 - opravena chyba s "odstrankovanim" zasobnika
;   19.04.2015 - verzia 5 - do QBOOT pridane nastrankovanie RAM
;   24.04.2015 - verzia 6 - opraveny test ROM/RAM
; Ovladac je umiestneny v nvyuzitej oblasti pamati vedla VRAM.
;------------------------------------------------------------------------------
;		cpu	8080
;		page	0
		.title	"Ovladac PMD 32 + CP/M BIOS pre PMD 85-2(A)"
;------------------------------------------------------------------------------
; rutiny v ROM
MONIT2		.equ	803Eh	; adresa pre navrat do Monitora
ROLL		  .equ	80A0h	; rolovanie obrazovky
ERALIN		.equ	80CAh	; zmazanie posledneho riadku
XCCUR		  .equ	8484h	; zobrazenie/zmazanie kurzora
PRTOUT		.equ	8500h	; zobrazenie znaku na aktualnu poziciu kurzora
INKEY		  .equ	89C0h	; test klavesnice bez cakania
; premenne monitora
COLOR		  .equ	0C03Ah	; kod farby
CURSOR		.equ	0C03Eh	; adresa kurzora
IIROLL		.equ	0C0F4h	; pocet prenasanych mikroriadkov pri rolovani
RADSIR		.equ	0C0FCh	; sirka riadku - offset medzi dvoma riadkami
ASCII		  .equ	0C134h	; kod stlacenej klavesy
STACK		  .equ	0C13Eh	; odpamatanie SP
IIROLL2		.equ	0C33Ah	; povodna hodnota poctu prenasanych mikroriadkov pri rolovani
ESCSEQ		.equ	0C33Ch	; priznak ESC sekvencie
ESCROW		.equ	0C33Dh	; cislo riadku pre ESC sekvenciu
; zaciatocna adresa ovladaca vo VRAM
BeginAdr 	.equ	0C470h
; definicia adries portov 8255 pre PMD 32
PIO_A		  .equ	4Ch		; bazova adresa 8255
PIO_B		  .equ	PIO_A+1
PIO_C		  .equ	PIO_A+2
PIO_CW		.equ	PIO_A+3
; adresa riadiaceho portu systemovej 8255
SYS_CW		.equ	0F7h
;------------------------------------------------------------------------------
; Adresy vstupnych bodov:
;	QBOOT		  0C470h
;	SELDSK		0C473h
;	CONIN		  0C476h
;	CONOUT		0C479h
;	CONST		  0C47Ch
;	QREAD		  0C4B0h
;	QWRITE		0C4B3h
;	SETSEC		0C4B6h
;	SETTRK		0C4B9h
;	SETDMA		0C4BCh
;	LIST		  0C4F0h
;	LISTST		0C4F3h
;	QLOAD		  0C4F6h
;	ReadByte	0C4F9h
;	SendCommand	    0C4FCh
;	SendByte	      0C530h
;	SndCrcRdAckErr	0C533h
;	ReadAckErr	    0C536h
;	WaitErrT15	    0C539h
;	WaitErrT	      0C53Ch
;	SndCrcRdAck	    0C570h
;	ReadCheckCrc	  0C573h
; adresy premennych 
;	Drive		        0C47Fh
;	Sector		      0C4BFh
;	Track		        0C4FFh
;	Dma		          0C5BEh
;------------------------------------------------------------------------------
  .globl QBOOT,SELDSK,CONIN,CONOUT,CONST,QREAD,QWRITE,SETSEC,SETTRK,SETDMA,LIST,LISTST
  .globl QLOAD,ReadByte,SendCommand,SendByte,SndCrcRdAckErr,ReadAckErr,WaitErrT15,WaitErrT,SndCrcRdAck,ReadCheckCrc
  .globl Drive,Sector,Track,Dma
  .section .text.00S
  .globl label_00
  ;.align 4
label_00:
		 jp QBOOT		; 0C470h
		 jp SELDSK
		 jp CONIN
		 jp CONOUT
		 jp CONST
Drive:		db	0		; 0C47Fh
  .section .text.01S
  .globl label_01
  ;.align 4
label_01:
		 jp QREAD		; 0C4B0h
		 jp QWRITE
		 jp SETSEC
		 jp SETTRK
		 jp SETDMA
Sector:		db	0		; 0C4BFh
  .section .text.02S
  .globl label_02
  ;.align 4
label_02:
		 jp LIST		; 0C4F0h
		 jp LISTST
		 jp QLOAD
		 jp ReadByte
		 jp SendCommand
Track:		db	0		; 0C4FFh
  .section .text.03S
  .globl label_03
  ;.align 4
label_03:
		 jp SendByte	; 0C530h
		 jp SndCrcRdAckErr
		 jp ReadAckErr
		 jp WaitErrT15
		 jp WaitErrT
		.ds 1,0xFF
  .section .text.04S
  .globl label_04
  ;.align 4
label_04:
		 jp SndCrcRdAck	; 0C570h
		 jp ReadCheckCrc
;-------
EnaByteOut:	ld a,08h		; 0->C4 zakazanie INTRA pre vstup A
		out (PIO_CW),a
		ld a,0Dh		; 1->C6 povolenie INTRA pre vystup A
		out (PIO_CW),a
		ret
		.ds 1,0xFF
  .section .text.05S
  .globl label_05
  ;.align 4
label_05:
;-------
; Precita byte z PMD 32 a zaroven modifikuje CRC.
; I: B=priebežné CRC
; O: CY=1 - chyba
;    CY=0 - A=C=precitany byte, B=modifikovane CRC
; M: AF, BC
;-------
ReadByte:	push de		; DE na zasobnik
		call IsIntra		; je platny byte na vstupe?
		pop de		; obnov DE
		ret c			; nie, vrat sa s chybou
		in a,(PIO_A)		; precitaj byte
		ld c,a		; odloz si ho do C
		xor b		; modifikuj CRC
		ld b,a		; a uloz ho naspat do B
		ld a,c		; vrat nacitany byte do A
		ret
		.ds 1,0xFF
;-------
Dma:		dw	0		; 0C5BEh
  .section .text.06S
  .globl label_06
  ;.align 4
label_06:
SwitchRom:	pop de		; navratova adresa do DE
		ld hl,0		; adresa zasobnika do HL
		add hl,sp
SwitchRomSP:	ld sp,0		; nova adresa zasobnika
		push hl		; stara adresa zasobnika na SP-2
		push de		; navratova adresa na novy zasobnik
SwitchRomX:	ld a,9		; nastrankuj ROM 
		out (SYS_CW),a
		ret
		.ds 1,0xFF
  .section .text.07S
  .globl label_07
  ;.align 4
label_07:
;-------
SwitchRam:	pop de		; navratova adresa do DE
SwitchRamSP:	ld hl,(0)		; povodny zasobnik-2 do HL
		ld sp,hl			; nastav povodnu adresu zasobnika
		ld a,8		; nastrankuj RAM 
		out (SYS_CW),a
		ex de,hl			; nepriamo sa vrat
		jp (hl)
;---------
LISTST:		in a,(PIO_C)
		rra
		sbc a,a
		ret
  .section .text.08S
  .globl label_08
  ;.align 4
label_08:
;-------
EnaByteIn:	ld a,09h		; 1->C4 povolenie INTRA pre vstup A
		out (PIO_CW),a
		ld a,0Ch		; 0->C6 zakazanie INTRA pre vystup A
		out (PIO_CW),a
		ret
;-------
; Kratke zdrzanie
; I: -
; O: kratke zdrzanie asi 90 us
; M: AF
;-------
WaitQ:		ld a,20
WaitQ1:		dec a
		jp nz,WaitQ1
		ret
  .section .text.09S
  .globl label_09
  ;.align 4
label_09:
;-------
; Zisti, ci je nastavene INTRA. Na INTRA sa caka zvoleny cas.
; INTRA=1, ak je platny byte na vstupe, alebo bol precitany byte z vystupu.
; I: Pri volani od IsIntraD DE=timeout
; O: CY=1 - timeout
;    CY=0 - OK
; M: CY, DE
;-------
IsIntra:	ld de,205		; timeout asi 5ms
IsIntraD:	push af		; uloz AF
IsIntra2:	in a,(PIO_C)		; zisti stav INTRA
		and 8
		jp nz,IsIntra3	; ak je INTRA=1, skoc dopredu
		dec de
		ld a,d
		 jp IsIntraJ1
  .section .text.0AS
  .globl label_0A
  ;.align 4
label_0A:
IsIntraJ1:	or e
		jp nz,IsIntra2	; a ak nie je nulove, vrat sa do slucky
		pop af		; doslo k timeoutu, obnov AF
		scf			; nastav CY ako priznak chyby
		ret
IsIntra3:	pop af
		or a		; vynuluj CY
		ret
;---------
SETDMA:		ld h,b
		ld l,c
		ld (Dma),hl
		ret
  .section .text.0BS
  .globl label_0B
  ;.align 4
label_0B:
;-------
; Posle povel do PMD 32. Pred poslanim povelu sa najprv preveri, ci na zbernici
; nahodou nie je prezentacny byte.
; I: A=povel
; O: CY=1 - chyba
;    CY=0 - OK, B=A=modifikovane CRC
; M: AF, B
;-------
SendCommand:	ld b,a		; uloz posielany byte do B
		push bc		; BC, DE na zasobnik
		push de
		call IsPresent	; zisti, ci je na zbernici prezentacny byte 0AAh
					; ak ano, odosli naspat prezentacny byte
		pop de
		pop bc		; obnov DE, BC
		ret c			; vrat sa, ak doslo ku chybe
		ld a,b		; vrat posielany byte do A
		ld b,0		; vynuluj CRC
; pokracuj dalej
		 jp SendCommandJ1
		.ds 1,0xFF
  .section .text.0CS
  .globl label_0C
  ;.align 4
label_0C:
;-------
; Posle byte do PMD 32 a modifikuje priebezne CRC.
; I: A=posielany byte, B=priebezne CRC
; O: CY=1 - chyba
;    CY=0 - OK, B=A=modifikovane CRC
; M: AF, B
;-------
SendCommandJ1:
SendByte:	push de		; DE na zasobnik
		call IsIntra		; zisti, ci je volny vystup
		pop de		; obnov DE
		ret c			; vrat sa, ak doslo ku timeoutu
		out (PIO_A),a		; posli byte na vystup
		xor b		; modofikuj CRC
		ld b,a		; a uloz ho naspat do B
		ret
;---------
SETTRK:		ld a,c
		ld (Track),a
		ret
  .section .text.0DS
  .globl label_0D
  ;.align 4
label_0D:
;-------
; Zisti, ci na zbernici nie je nahodou prezentacny byte 0AAh, ktory poslala
; disketova jednotka po navrate do "idle" stavu, kedy cakala na povel.
; I: -
; O: CY=1 - chyba
;    CY=0 - OK
; M: AF, DE
;-------
IsPresent:	call EnaByteIn	; povol prerusenie pre vstup
		call WaitQ		; male zdrzanie asi 90 us
		in a,(PIO_C)
		and 8		; je platny byte na vstupe?
		jp z,EnaByteOut	; ak nie, vrat sa cez povolenie prerusenia pre vystup
		 jp IsPresentJ1
  .section .text.0ES
  .globl label_0E
  ;.align 4
label_0E:

IsPresentJ1:
IsPresent5:	call EnaByteIn	; povol prerusenie pre vstup
IsPresent4:	in a,(PIO_A)		; precitaj byte zo vstupu
		cp 0AAh		; ak je to prezentacny byte 0AAh
		jp z,IsPresent2	; skoc poslat prezentacny byte 0AAh na vystup
		ld de,5000		; timeout asi 125 ms
		 jp IsPresentJ2
  .section .text.0FS
  .globl label_0F
  ;.align 4
label_0F:

IsPresentJ2:	call IsIntraD	; cakaj na byte
		ret c			; timeout, vrat sa
		 jp IsPresent4	; ano, skoc precitat byte zo vstupu
IsPresent2:	call WaitQ		; male zdrzanie asi 90 us
		call EnaByteOut	; povol prerusenie pre vystup
		 jp IsPresentJ3
  .section .text.10S
  .globl label_10
  ;.align 4
label_10:

IsPresentJ3:	ld a,0AAh		; posli na vystup prezentacny byte 0AAh
		out (PIO_A),a
		ld de,5000		; timeout asi 125 ms
		call IsIntraD	; cakaj na byte
		jp c,IsPresent5	; ak nebol prezentacny byte prijaty, skoc otestovat vstup
		ret			; bol prijaty prezentacny byte, vrat sa s vynulovanym CY
		.ds 2,0xFF
  .section .text.11S
  .globl label_11
  ;.align 4
label_11:

;-------
; Posle povel "B" a precita BOOT. Vzdy je to z jednotky A:
ReadBoot:	ld a,'B'		; povel "B" - precitaj BOOT
		call SendCommand	; odosli na vystup
		 jp ReadSectorB
;-------
; Zisti, ci je pripojena PMD 32 a ci odpoveda prezentacnym bytom.
; I: -
; O: CY=1 - chyba, timeout, PMD 32 neodpoveda prezentacnym bytom
; M: AF, DE, B
;-------
CheckDevice:	ld a,0C4h		; inicializuj GPIO 8255
		out (PIO_CW),a		; SK A: MOD 2, A-in/out,  SK B: MOD 1, B-out
		 jp CheckDeviceJ1
		.ds 1,0xFF
  .section .text.12S
  .globl label_12
  ;.align 4
label_12:

CheckDeviceJ1:	ld a,5
		out (PIO_CW),a
		call EnaByteIn	; povol prerusenie pre vstup
		ld de,10000		; timeout asi 250 ms
		call IsIntraD	; cakaj na byte
		 jp CheckDeviceJ2
  .section .text.13S
  .globl label_13
  ;.align 4
label_13:

CheckDeviceJ2:	ret c			; timeout, vrat sa
		in a,(PIO_A)		; precitaj prijaty byte
		cp 0AAh		; je to prezentacny byte 0AAh ?
		scf			; nastav CY ako priznak chyby
		ret nz			; nie je to prezentacny byte 0AAh, vrat sa s CY
		call EnaByteOut	; povol prerusenie pre vystup
		ld a,0AAh		; posli ako odpoved prezentacny byte 0AAh
		 jp SendByte
		.ds 1,0xFF
  .section .text.14S
  .globl label_14
  ;.align 4
label_14:

;-------
; Posle CRC na vystup a pocka na ACK a vysledok povelu.
; I: B=aktualne CRC
; O: CY=1 - chyba
;    CY=0 - OK, A=vysledok povelu
; M: AF, BC, DE
;-------
SndCrcRdAckErr:	ld a,b		; posielane CRC do A
		call SendByte	; posli na vystup
		ret c			; vrat sa, ak doslo ku chybe
ReadAckErr:	call EnaByteIn	; povol prerusenie na vstupe
		call ReadByte	; precitaj byte zo vstupu
		ret c			; vrat sa, ak doslo ku chybe
		 jp ReadAckErrJ1
		.ds 1,0xFF
  .section .text.15S
  .globl label_15
  ;.align 4
label_15:

ReadAckErrJ1:	cp 33h		; bolo prijate byte ACK?
		scf			; nastav chybovy priznak
		ret nz			; vrat sa s chybou, ak to nebolo ACK
WaitErrT15:	ld de,3000		; timeout asi 15,5 sec
WaitErrT:	push de		; DE na zasobnik
		call IsIntra		; je platny byte na vstupe?
		pop de		; obnov DE
		 jp WaitErrTJ1
		.ds 1,0xFF
  .section .text.16S
  .globl label_16
  ;.align 4
label_16:

WaitErrTJ1:	jp nc,ReadByte	; ak ano, skoc ho precitat
		dec de		; zniz pocitadlo timeoutu
		ld a,d		; a testuj ho na nulu
		or e
		jp nz,WaitErrT	; ak nie je nulovy, skoc do slucky
		scf			; nastav priznak chyby
		ret
		.ds 5,0xFF
  .section .text.17S
  .globl label_17
  ;.align 4
label_17:

;-------
; Odosle CRC a caka na potvrdenie. Otestuje chybovy kod na nulu.
; I: B=posielane CRC
; O: CY=1 - chyba
;    CY=0 - OK
; M: AF, BC, DE
;-------
SndCrcRdAck:	call SndCrcRdAckErr	; posli CRC a cakaj ACK a vysledok povelu
		ret c			; vrat sa, ak doslo ku chybe
		 jp ReadCheckCrc2	; ak bol druhy byte skutocne 0, je to OK
;-------
; Precita byte zo vstupu, pre.dstavujuci CRC
; I: -
; O: CY=1 - chyba CRC alebo timeout
;    CY=0 - CRC OK
; M: AF, BC
;-------
ReadCheckCrc:	call ReadByte	; precitaj CRC zo vstupu
		ret c			; vrat sa, ak doslo ku chybe
		ld a,b		; skontroluj CRC
ReadCheckCrc2:	or a
		ret z			; OK
		scf			; nastav priznak chyby
		ret
  .section .text.18S
  .globl label_18
  ;.align 4
label_18:

;-------
; Posle do PMD 32 cislo sektoru vratane cisla disku a cislo stopy.
; vstup: cislo sektoru, disku a stopy na adresach Drive, Sector, Track
; vystup: CY = 1 - chyba
;         CY = 0 - OK, B = A = modifikovane CRC
; meni: AF, BC
;-------
SendSectorTrack:
		ld a,(Sector)
		call SendByte
		ret c
		ld a,(Track)
		 jp SendByte
		.ds 3,0xFF
  .section .text.19S
  .globl label_19
  ;.align 4
label_19:

;-------
; Povel "Q" - precitanie sektora z disku.
ReadSector:	ld a,'Q'		; povel "Q" - precitaj sektor
		call SendCommand	; odosli na vystup
		ret c			; vrat sa, ak doslo ku chybe
		call SendSectorTrack	; posli stopu a sektor
ReadSectorB:	ret c			; vrat sa, ak doslo ku chybe
		call SndCrcRdAck	; posli CRC a pockaj na potvrdenie
		 jp ReadSectorJ1
  .section .text.1AS
  .globl label_1A
  ;.align 4
label_1A:

ReadSectorJ1:	ret c			; vrat sa, ak doslo ku chybe
		ld b,0		; vynuluj CRC
		ld d,128		; nastav pocitadlo
		ld hl,(Dma)		; do HL adresa pamati
ReadSector2:	call ReadByte	; precitaj byte
		ret c			; vrat sa, ak doslo ku chybe
		ld (hl),a		; uloz byte do pamati
		 jp ReadSectorJ2
  .section .text.1BS
  .globl label_1B
  ;.align 4
label_1B:

ReadSectorJ2:	inc hl		; posun ukazatel
		dec d		; zniz pocitadlo prijimanych bytov
		jp nz,ReadSector2	; ak neboli prijate vsetky, vrat sa do slucky
		 jp ReadCheckCrc	; skoc precitat CRC
;---------
QREAD:		call ReadSector
		ld a,0
		adc a,0
		ret
  .section .text.1CS
  .globl label_1C
  ;.align 4
label_1C:

;-------
; Povel "T" - zapise sektor na disk.
WriteSector:	ld a,'T'		; povel "T" - zapis sektor
		call SendCommand	; odosli na vystup
		ret c			; vrat sa, ak doslo ku chybe
		call SendSectorTrack	; posli stopu a sektor
		ret c			; vrat sa, ak doslo ku chybe
		ld d,128		; nastav pocitadlo
		 jp WriteSectorJ1
		.ds 1,0xFF
  .section .text.1DS
  .globl label_1D
  ;.align 4
label_1D:

WriteSectorJ1:	ld hl,(Dma)		; do HL adresa pamati
WriteSector2:	ld a,(hl)		; byte z pamati
		call SendByte	; odosli
		ret c			; vrat sa, ak doslo ku chybe
		inc hl		; posun ukazatel
		dec d		; zniz pocitadlo bytov
		jp nz,WriteSector2	; opakuj pre vsetkych 128 bytov
		 jp SndCrcRdAck	; odosli CRC a cakaj na potvrdenie
  .section .text.1ES
  .globl label_1E
  ;.align 4
label_1E:

;-------
HeadHome:	ld a,'I'		; povel "I" - hlava mechaniky na 0. stopu
		call SendCommand	; odosli na vystup
		ret c			; vrat sa, ak doslo ku chybe
		ld a,(Drive)		; posli Drive
		call SendByte
		ret c			; vrat sa, ak doslo ku chybe
		 jp SndCrcRdAck	; odosli CRC a cakaj na potvrdenie
  .section .text.1FS
  .globl label_1F
  ;.align 4
label_1F:

;-------
QBOOT:		ld a,82h		; inicializuj sytemovu 8255 a odpoj ROM
		out (SYS_CW),a
		ld hl,8000h		; zisti, ci je od 8000h ROM
		ld a,(hl)		; invertuj byte na adrese v HL
		cpl
		ld (hl),a
		cp (hl)		; porovnaj, ci skutocne doslo ku zmene - ROM vs. RAM
		cpl			; vrat povodnu hodnotu do pamati
		ld (hl),a
		 jp QBOOTJ1
  .section .text.20S
  .globl label_20
  ;.align 4
label_20:

QBOOTJ1:	jp nz,QBOOT0		; pre PMD 85-2 bude zasobnik pod ROM
		ld h,0C0h		; pre PMD 85-2A bude zasobnik pod VRAM
QBOOT0:		ld (SwitchRomSP+1),hl	; uloz adresu zasobnika
		dec hl
		dec hl
		ld (SwitchRamSP+1),hl
		 jp QBOOTJ2
  .section .text.21S
  .globl label_21
  ;.align 4
label_21:

QBOOTJ2:	ld hl,0080h		; DMA adresa pre nacitanie BOOT sektora
		ld (Dma),hl
		ld b,4		; 4 pokusy
QBOOT2:		push bc
		call CheckDevice	; over, ci je PMD 32 pripojena
		 jp QBOOTJ3
		.ds 1,0xFF
  .section .text.22S
  .globl label_22
  ;.align 4
label_22:

QBOOTJ3:	jp c,QBOOT3
		call ReadBoot	; precitaj BOOT
QBOOT3:		pop bc
		jp nc,0080h		; ak bolo citanie v poriadku, spust BOOT kod
		dec b
		 jp QBOOTJ4
		.ds 2,0xFF
  .section .text.23S
  .globl label_23
  ;.align 4
label_23:

QBOOTJ4:	jp nz,QBOOT2
JumpMon:	ld a,0ADh		; ak sa nepodarilo precitat BOOT
		out (PIO_CW),a		; reinicializuj PIO
		ld a,0Dh
		out (PIO_CW),a
		ld a,05h
		 jp QBOOTJ5
  .section .text.24S
  .globl label_24
  ;.align 4
label_24:

QBOOTJ5:	out (PIO_CW),a
		call SwitchRomX	; pripoj ROM
		 jp MONIT2		; a vrat sa do Monitora
;---------
QWRITE:		call WriteSector
		ld a,0
		adc a,0
		ret
  .section .text.25S
  .globl label_25
  ;.align 4
label_25:

;---------
QLOAD:		ex de,hl
		ld hl,(Dma)
		push hl
		ex de,hl
		ld (Dma),hl
		xor a
		ld (Track),a
		 jp QLOADJ1
  .section .text.26S
  .globl label_26
  ;.align 4
label_26:

QLOADJ1:	inc a
Qload1:		ld (Sector),a
		ld b,4
Qload3:		push bc
		call ReadSector
		pop bc
		 jp QLOADJ2
		.ds 2,0xFF
  .section .text.27S
  .globl label_27
  ;.align 4
label_27:

QLOADJ2:	jp nc,Qload2
		dec b
		jp nz,Qload3
		pop hl
		 jp JumpMon
;---------
LIST:		in a,(PIO_C)
		 jp LISTJ1
  .section .text.28S
  .globl label_28
  ;.align 4
label_28:

Qload2:		ld hl,(Dma)
		ld de,80h
		add hl,de
		ld (Dma),hl
		ld a,(Sector)
		 jp QLOADJ3
  .section .text.29S
  .globl label_29
  ;.align 4
label_29:

QLOADJ3:	inc a
		cp 1Ah
		jp nz,Qload4
		xor a
		ld hl,Track
		inc (hl)
Qload4:		dec c
		 jp QLOADJ4
		.ds 1,0xFF
  .section .text.2AS
  .globl label_2A
  ;.align 4
label_2A:

QLOADJ4:	jp nz,Qload1
		pop hl
		ld (Dma),hl
		ret
;---------
LISTJ1:		rra
		jp nc,LIST
		ld a,c
		out (PIO_B),a
		ret
  .section .text.2BS
  .globl label_2B
  ;.align 4
label_2B:

;---------
SELDSK:		call HeadHome
		ld a,0
		ld (Track),a
		adc a,0
		ret
		.ds 5,0xFF
  .section .text.2CS
  .globl label_2C
  ;.align 4
label_2C:

;---------
SETSEC:		ld a,(Sector)
		and 0C0h
		dec c
		or c
		ld (Sector),a
		inc c
		ret
		.ds 4,0xFF
  .section .text.2DS
  .globl label_2D
  ;.align 4
label_2D:

;---------
TestKbd:	call SwitchRom
		call INKEY
		cp 87h
		jp c,TestKbd2
		cp 0A0h
		 jp TestKbdJ1
  .section .text.2ES
  .globl label_2E
  ;.align 4
label_2E:

TestKbdJ1:	jp nc,TestKbd2
		sub 87h
TestKbd2:	cp 1Dh
		jp nz,TestKbd3
		ld a,7Fh
TestKbd3:	ld b,a
		 jp TestKbdJ2
  .section .text.2FS
  .globl label_2F
  ;.align 4
label_2F:

TestKbdJ2:	call SwitchRam
		ld a,b
		and a
		ret
;---------
CONIN:		ld a,(ASCII)
		and a
		jp nz,ConIn2
		 jp TestKbdJ3
  .section .text.30S
  .globl label_30
  ;.align 4
label_30:

TestKbdJ3:
ConIn3:		call TestKbd
		jp z,ConIn3
ConIn2:		ld b,a
		xor a
		ld (ASCII),a
		ld a,b
		ret
		.ds 3,0xFF
  .section .text.31S
  .globl label_31
  ;.align 4
label_31:

;---------
CONST:		ld a,(ASCII)
		and a
		jp nz,ConSt2
		call TestKbd
		ret z
ConSt2:		ld a,0FFh
		ret
		.ds 2,0xFF
  .section .text.32S
  .globl label_32
  ;.align 4
label_32:

;---------
CONOUT:		call SwitchRom
		call TestCursorAdr
		push bc
		call nc,XCCUR
		pop bc
		ld a,c
		 jp CONOUTJ1
		.ds 1,0xFF
  .section .text.33S
  .globl label_33
  ;.align 4
label_33:

CONOUTJ1:	call ConOut0
		call TestCursorAdr
		call nc,XCCUR
		call SwitchRam	; musi byt CALL!!!
		ret
		.ds 3,0xFF
  .section .text.34S
  .globl label_34
  ;.align 4
label_34:

;---------
TestCursorAdr:	ld hl,(CURSOR)
		ld a,h
		cp 0C0h
		ret c
		ld a,l
		and 3Fh
		cp 30h
		ccf
		ret
		.ds 2,0xFF
  .section .text.35S
  .globl label_35
  ;.align 4
label_35:

;---------
ConOut0:	ld a,(ESCSEQ)
		and a
		jp nz,ConOutAT
		ld a,c
		cp 20h
		jp nc,PRTOUT
		 jp ConOut0J1
  .section .text.36S
  .globl label_36
  ;.align 4
label_36:

ConOut0J1:	ld hl,(CURSOR)
		cp 1Eh		; HOME - kurzor do ľavého horného rohu obrazovky
		jp nz,ConOutCtrl01
ConOutCtrl02:	ld de,0C040h
		 jp ConOut0J2
		.ds 2,0xFF
  .section .text.37S
  .globl label_37
  ;.align 4
label_37:

ConOut0J2:	ld hl,(RADSIR)
		add hl,de
ConOutCtrl03:	ld (CURSOR),hl
		ret
ConOutCtrl01:	cp 1Fh		; CLS - zmazanie obrazovky a kurzor do laveho horneho rohu
		jp nz,ConOutCtrl04
		 jp ConOut0J3
  .section .text.38S
  .globl label_38
  ;.align 4
label_38:

ConOut0J3:	ld a,1Ch
		call PRTOUT
		 jp ConOutCtrl02
ConOutCtrl04:	cp 0Ah		; DOWN - kurzor dole (LF)
		jp nz,ConOutCtrl05
		 jp ConOut0J4
  .section .text.39S
  .globl label_39
  ;.align 4
label_39:

ConOut0J4:	ld a,l
		and 3Fh
		push af
		ld a,0Dh
		call PRTOUT
		ld hl,CURSOR
		pop af
		 jp ConOut0J5
  .section .text.3AS
  .globl label_3A
  ;.align 4
label_3A:

ConOut0J5:	add a,(hl)
		ld (hl),a
		ret
ConOutCtrl05:	cp 09h		; HTAB - posun kurzora o 8 pozicii doprava
		jp nz,ConOutCtrl06
		ld a,08h
		add a,l
		and 3Fh
		 jp ConOut0J6
  .section .text.3BS
  .globl label_3B
  ;.align 4
label_3B:

ConOut0J6:
ConOutCtrl07:	cp 30h
		ld e,a
		jp c,ConOutCtrl08
		ld e,2Fh
ConOutCtrl08:	ld a,l
		and 0C0h
		add a,e
		ld l,a
		 jp ConOutCtrl03
  .section .text.3CS
  .globl label_3C
  ;.align 4
label_3C:

ConOutCtrl06:	cp 0Eh		; RIGHT - posun kurzora doprava
		jp nz,ConOutCtrl09
		ld a,l
		and 3Fh
		inc a
		 jp ConOutCtrl07
		.ds 4,0xFF
  .section .text.3DS
  .globl label_3D
  ;.align 4
label_3D:

ConOutCtrl09:	cp 08h		; LEFT - posun kurzora dolava
		jp nz,ConOutCtrl10
		ld a,l
		and 3Fh
		ret z
		dec a
		 jp ConOutCtrl07
		.ds 3,0xFF
  .section .text.3ES
  .globl label_3E
  ;.align 4
label_3E:

ConOutCtrl10:	cp 0Fh		; UP - kurzor hore
		jp nz,ConOutCtrl11
		push hl
		ex de,hl
		ld hl,(RADSIR)
		ld a,e
		sub l
		ld l,a
		 jp ConOut0J7
  .section .text.3FS
  .globl label_3F
  ;.align 4
label_3F:

ConOut0J7:	ld a,d
		sbc a,h
		ld h,a
		cp 0C1h
		pop de
		ret c
		 jp ConOutCtrl03
ConOutCtrl11:	cp 1Ch		; CLRL - zrusenie aktualneho riadku
		 jp ConOut0J8
		.ds 1,0xFF
  .section .text.40S
  .globl label_40
  ;.align 4
label_40:

ConOut0J8:	jp nz,ConOutCtrl12
		push hl
		ld de,ConOutCtrl13
		push de
		ld a,0C0h
		and l
		ld l,a
		ex de,hl
		 jp ConOut0J9
  .section .text.41S
  .globl label_41
  ;.align 4
label_41:

ConOut0J9:	ld hl,0
		add hl,sp
		ld (STACK),hl
		ld hl,(RADSIR)
		ld a,e
		sub l
		ld l,a
		 jp ConOut0J10
  .section .text.42S
  .globl label_42
  ;.align 4
label_42:

ConOut0J10:	ld a,d
		sbc a,h
		ld h,a
		push hl
		add hl,hl
		add hl,hl
		ld a,(IIROLL)
		ld (IIROLL2),a
		sub h
		 jp ConOut0J11
  .section .text.43S
  .globl label_43
  ;.align 4
label_43:

ConOut0J11:	inc a
		ld (IIROLL),a
		pop hl
		cp 08h
		jp c,ConOutCtrl14
		ld bc,0FFC0h
		 jp ConOut0J12
  .section .text.44S
  .globl label_44
  ;.align 4
label_44:

ConOut0J12:	ex de,hl
		add hl,bc
		ld sp,hl
		ex de,hl
		add hl,bc
		dec hl
		 jp ROLL
ConOutCtrl14:	pop de
		call ERALIN
		 jp ConOut0J13
  .section .text.45S
  .globl label_45
  ;.align 4
label_45:

ConOut0J13:
ConOutCtrl13:	ld a,(IIROLL2)
		ld (IIROLL),a
		pop hl
		ld (CURSOR),hl
		ret
ConOutCtrl12:	ld a,l
		 jp ConOut0J14
		.ds 1,0xFF
  .section .text.46S
  .globl label_46
  ;.align 4
label_46:

ConOut0J14:	and 0C0h
		ld l,a
		ld a,c
		cp 0Dh		; CR - kurzor na začiatok riadku
		jp z,ConOutCtrl03
		cp 1Ah		; NORM - normálne zobrazovanie (neinverzne)
		 jp ConOut0J15
		.ds 2,0xFF
  .section .text.47S
  .globl label_47
  ;.align 4
label_47:

ConOut0J15:	jp nz,ConOutCtrl15
		ld a,(COLOR)
		and 0C0h
		ld (COLOR),a
		ret
		.ds 4,0xFF
  .section .text.48S
  .globl label_48
  ;.align 4
label_48:

ConOutCtrl15:	cp 1Dh		; INV - inverzné zobrazovanie
		jp nz,ConOutCtrl16
		ld a,(COLOR)
		xor 3Fh
		ld (COLOR),a
		ret
		.ds 2,0xFF
  .section .text.49S
  .globl label_49
  ;.align 4
label_49:

ConOutCtrl16:	cp 01h		; ATTR0 - zobrazovanie farbou 0
		jp nz,ConOutCtrl17
		ld a,(COLOR)
		and 3Fh
		ld (COLOR),a
		ret
		.ds 2,0xFF
  .section .text.4AS
  .globl label_4A
  ;.align 4
label_4A:

ConOutCtrl17:	cp 02h		; ATTR1 - zobrazovanie farbou 1
		jp nz,ConOutCtrl18
		ld a,(COLOR)
		and 3Fh
		or 40h
		ld (COLOR),a
		ret
  .section .text.4BS
  .globl label_4B
  ;.align 4
label_4B:

ConOutCtrl18:	cp 03h		; ATTR2 - zobrazovanie farbou 2
		jp nz,ConOutCtrl19
		ld a,(COLOR)
		and 3Fh
		or 80h
		ld (COLOR),a
		ret
  .section .text.4CS
  .globl label_4C
  ;.align 4
label_4C:

ConOutCtrl19:	cp 04h		; ATTR3 - zobrazovanie farbou 3
		jp nz,ConOutCtrl20
		ld a,(COLOR)
		or 0C0h
		ld (COLOR),a
		ret
		.ds 2,0xFF
  .section .text.4DS
  .globl label_4D
  ;.align 4
label_4D:

ConOutCtrl20:	cp 1Bh		; ESC - nastavenie pozície kurzora, za tým - riadok + 32, stĺpec + 32
		jp nz,PRTOUT
		ld a,1		; ocakava sa Riadok
		ld (ESCSEQ),a
		ret
		.ds 5,0xFF
  .section .text.4ES
  .globl label_4E
  ;.align 4
label_4E:

ConOutAT:	dec a
		jp nz,ConOutAT1
		ld a,2		; ocakava sa Stlpec
		ld (ESCSEQ),a
		ld a,0E1h
		add a,c
		ld (ESCROW),a
		ret
  .section .text.4FS
  .globl label_4F
  ;.align 4
label_4F:

ConOutAT1:	ld hl,(RADSIR)
		ld a,(ESCROW)
		ex de,hl
		ld hl,0C040h
ConOutAT2:	add hl,de
		dec a
		 jp ConOut0J16
		.ds 1,0xFF
  .section .text.50S
  .globl label_50
  ;.align 4
label_50:

ConOut0J16:	jp nz,ConOutAT2
		ld a,c
		sub 20h
		cp 30h
		jp c,ConOutAT3
		ld a,2Fh
		 jp ConOut0J17
  .section .text.51S
  .globl label_51
  ;.align 4
label_51:

ConOut0J17:
ConOutAT3:	add a,l
		ld l,a
		xor a
		ld (ESCSEQ),a
		 jp ConOutCtrl03
		.ds 7,0xFF
.end
