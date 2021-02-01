; ************************************************
; Zapouzdření pro volání z odkrývače minového pole
; ************************************************
  .include "add_def.S"
  .section .text.timer
  .globl SafeZmenaCasu,ZmenaCasu,TiskCasuOutside,StopGame
 
SafeZmenaCasu:
	push bc
	push de
	push hl
	call ZmenaCasu
	pop hl
	pop de
	pop bc
	ret
; *************************
; Test změny času během hry
; *************************
ZmenaCasu:
	ld a,(TimeRun)
	and a
	call nz,TimeFlow		; fyzický odpočet času
	ret nc			; NENÍ ciferná změna => konec
				; JE ciferná změna => tisk
; ***************************************************
; Vytiskne čas
; Pokud kurzor myši zasahuje do prostoru časomíry,
; provede soutisk v buferu a pak kopíruje do videoram
; Předpokládá rozsvícený ukazatel myši
; ***************************************************
TiskCasu:
	ld a,10
	call SetCol
	ld hl,(PoziceCasu)		; výškový test kolize
	add hl,hl
	add hl,hl
	ld a,h
	add a,12
	ld hl,MysY
	cp (hl)
	jp c,TiskCasuOutside
	sub 24
	jp c,TiskCasuTestX
	cp (hl)
	jp nc,TiskCasuOutside
	
TiskCasuTestX:
	ld hl,(MysX)		; šířkový test kolize
	ex de,hl
	ld a,(PoziceCasu)
	and 3fh
	ld l,a
	ld h,0
	add hl,hl
	add hl,hl
	add hl,hl
	add a,3*9
	rst 0x10
	rst 0x20
	jp c,TiskCasuOutside
	ld bc,-(3*9)-12
	add hl,bc
	rst 0x20
	jp nc,TiskCasuOutside
TiskCasuInside:			; kurzor v kolizi s časomírou
	push bc			; záloha videoram do buferu
	ld hl,(AdresaCasu)
	ex de,hl
	ld hl,-8000h
	add hl,de
	ex de,hl
	push de
	push hl
	call CopyVideoBlock
	ld hl,(MysAOld)		; přesměrování myši do buferu
	push hl
	ld de,-8000h
	add hl,de
	ld (MysAOld),hl
	ld hl,(MysAdr)
	push hl
	ld de,-8000h
	add hl,de
	ld (MysAdr),hl
	rst 0x30; tisk času do buferu
	ld hl,(PoziceCasu)
	ld de,-8000h
	add hl,de
	ld (Prnpos),hl
	ld a,(Time+0)
	call prtchr
	ld a,(Time+1)
	call prtchr
	ld a,(Time+2)
	call prtchr
	call Pixel2AdrBuf
	call MysActBufer
	pop hl			; myš zpět do videoram
	ld (MysAdr),hl
	pop hl
	ld (MysAOld),hl
	pop de			; přenos z buferu do videoram
	pop hl
	call CopyVideoBlock
	pop bc
	ret
TiskCasuOutside:
	push bc			; bezpečný tisk časomíry
	ld hl,(PoziceCasu)
	ld (Prnpos),hl
	ld a,(Time+0)
	call prtchr
	ld a,(Time+1)
	call prtchr
	ld a,(Time+2)
	call prtchr
	pop bc
	ret
; ********
; Tok času
; ********
TimeFlow:
	out (uartdat),a		; restart časovače (UARTu)
	ld hl,Time+3		; předdělička 2x 0,5sec
	dec (hl)
	scf
	ccf
	ret nz
	ld (hl),2
	dec hl			; při času 999 se
	ld a,(hl)
	dec hl
	add a,(hl)
	dec hl
	add a,(hl)
	cp 3*9
	call nc,Chirp2		; pípne
	jp nc,StopTime		; a zastaví časomíra
	inc hl			; sekundy
	inc hl
	inc (hl)
	ld a,(hl)
	cp 10
	ret c			; CY=1 <=> změna času
	ld (hl),0
	dec hl			; desítky sekund
	inc (hl)
	ld a,(hl)
	cp 10
	ret c			; CY=1 <=> změna času
	ld (hl),0
	dec hl			; stovky sekund
	inc (hl)
	scf			; CY=1 <=> změna času
	ret
; *****************
; Zastaví celou hru
; *****************
StopGame:
	xor a			; příznak GameOver
	ld (GameOver),a
; ********************
; Zastaví odpočet času
; ********************
StopTime:
	xor a			; pouze vynulovat
	ld (TimeRun),a		; příznak plynutí času
	ret
; **********************************************
; Kopíruje blok mezi fyzickou videoram a buferem
; (HL) >> (DE)
; **********************************************
CopyVideoBlock:
	ld bc,0924h		; 9 slice x 36 mikrořádků
CopyVideoBlockY:
	push bc
	push de
	push hl
CopyVideoBlockX:
	ld a,(hl)
	ld (de),a
	inc hl
	inc de
	dec b
	jp nz,CopyVideoBlockX
	pop hl
	pop de
	ld c,64
	add hl,bc
	ex de,hl
	add hl,bc
	ex de,hl
	pop bc
	dec c
	jp nz,CopyVideoBlockY
	ret
; *********************************************************
; Z pixelových souřadnic, které ořeže na platný rozsah,
; vypočte adresu kurzoru v buferu
; vstup: proměnné MysX, MysY
; výstup: HL = adresa kurzoru
; *********************************************************
Pixel2AdrBuf:
	call LoadYCoor
	ld (MysY),hl
	add hl,hl 
	add hl,hl 
	add hl,hl 
	add hl,hl 
	add hl,hl 
	add hl,hl
	ld a,h
	add a,40h
	ld h,a
	push hl
	call LoadXCoor	; HL := HL + pozice bajtu na řádku
	ld (MysX),hl
	ld a,h
	rra
	ld a,l
	rra
	ld l,a		; nejprve L := X/2 (CY=zbytek)
	ld h, tbPix2Ofs >> 8
	ld a,(hl)		; A := pixelový ofset 0..5
	rla
	ld (MysBit),a
	inc h
	ld e,(hl)
	ld d,0
	pop hl
	add hl,de
	ld (MysAdr),hl
	ret
