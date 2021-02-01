  .include "add_def.S"
  .include "add_scr.S"
  .section .text.editor
  .globl ZadejJmeno

_EOL	.equ 70h	; interní kódy řídicích kláves
_LT	.equ 71h
_RT	.equ 72h
_HOME	.equ 73h
_END	.equ 74h
_CLR	.equ 75h
; *************************************
; Vlastní procedura editace jména hráče
; *************************************
ZadejJmeno:
	ld a,5		; předtisk formuláře ENTER NAME
	call ZobrazSestavu
	call TiskJmena	; předtisk posledního jména
	call KeyRelease	; počkat na uvolnění kláves
	ld de,txtJmeno	; DE = aktuální pozice kurzoru
ZadejJmenoCekejKlavesu:
	call TiskJmena	; přetisk celého jména
	ld a,0ffh	; v následujícím kroku kurzor změní
	ld (CursorFlash),a	; stav na "nesvítí"
ZadejJmenoCekejNaStisk:
	ld a,(CursorFlash)	; časovač blikání kurzoru
	inc a
	and 7fh
	ld (CursorFlash),a
	and 3fh		; při stavech 00h/40h
	call z,Kurzor	; překreslit kurzor
	push de
	call GetKey	; načti klávesu včetně autorepeatu
	pop de
	cp 0ffh	; test na nestisknutou klávesu
	jp z,ZadejJmenoCekejNaStisk ; není stisk => čekej na něj
	cp _EOL
	ret z		; EOL => konec a návrat do MENU
	cp _HOME
	jp z,ZadejJmenoHome	; obsluha klávesy HOME
	cp _END
	jp z,ZadejJmenoEnd	; obsluha klávesy END
	cp _RT
	jp z,ZadejJmenoDoprava	; obsluha klávesy -->
	cp _LT
	jp z,ZadejJmenoDoleva	; obsluha klávesy <--
	cp _CLR
	jp z,ZadejJmenoVymaz	; obsluha klávesy CLR
	call Chirp
	ld (de),a			; tisknutelný znak do buferu
  ; tohle ld nespocita, je nutne to udelat runtime
.if OSS_USE
	push de
	ld   de, txtJmeno
	ld   hl, 0
	ld   a,l
	sub  e
	ld   l,a
	ld   a,h
	sbc  a,d
	ld   h,a
	pop  de
.else
;  ld   hl, -txtJmeno    ; ještě test, zda už není
  ld   hl,0xEF8D
.endif
	;;;;;;;;;;;;;;;;;;;;;
	add hl,de			; kurzor opřený o pravou
	ld a,l			; zarážku
	cp 5
	inc de			; kurzor posunout
	jp c,ZadejJmenoCekejKlavesu ; tisk jména a blik kurzoru
				; pro pozice 0..(N-1)
	dec de			; na poslední pozici návrat
	call TiskJmena		; vytisknout jméno
	xor a			; kurzor bude inverzní
	ld (CursorFlash),a
	 jp ZadejJmenoCekejNaStisk
	;jnc ZadejJmenoCekejNaStisk ; => zcela vpravo bez posunu
	;inx d			; jinak kurzor posunout
	;jmp ZadejJmenoCekejKlavesu ; tisk jména a blik kurzoru
; **************
; Blikač kurzoru
; **************
;xxx = EnterNm + zero_addr - txtJmeno + (zero_addr + 0x040c)
Kurzor:
	ld a,(CursorFlash)		; časovač blikání kurzoru
	cp 40h			; podle stavu MSB
	ld a,(de)			; zobrazuje buď znak na pozici
	push de			; vypočtu fyzickou pozici tisku
  ; tohle ld nespocita, je nutne to udelat runtime
.if OSS_USE
  push de
  ld   de, txtJmeno
  ld   hl, EnterNm + 0x040c
  ld   a,l
  sub  e
  ld   l,a
  ld   a,h
  sbc  a,h
  ld   h,a
  pop  de
.else
; ld   hl,EnterNm+40ch-txtJmeno
  ld   hl, 0xCE99
.endif
  ;;;;;;;;;;;;;;;;;;;;;
	jp c,KurzorInv
KurzorZnak:
	add hl,de
	ld (Prnpos),hl
	call prtchr		; vytisknu normální znak
	pop de
	ret
KurzorInv:
	add hl,de
	ld (Prnpos),hl
	call PrtInv		; vytisknu inverzní znak
	pop de
	ret
; **********************************
; Obslužné procedury řídicích kláves
; **********************************
ZadejJmenoDoprava:
	ld a,e
	cp (txtJmeno+5) & 0xFF
	jp z,ZadejJmenoCekejNaStisk
	inc de
	call Chirp		; klik při stisku
	 jp ZadejJmenoCekejKlavesu
ZadejJmenoDoleva:
	ld a,e
	cp txtJmeno & 0xFF
	jp z,ZadejJmenoCekejNaStisk
	dec de
	call Chirp		; klik při stisku
	 jp ZadejJmenoCekejKlavesu
ZadejJmenoHome:
	ld a,e
	cp txtJmeno & 0xFF
	jp z,ZadejJmenoCekejNaStisk
	ld de,txtJmeno
	call Chirp		; klik při stisku
	 jp ZadejJmenoCekejKlavesu
ZadejJmenoEnd:
	ld b,e
	ld de,txtJmeno
	ld c,5
ZadejJmenoEndLoop:
	ld a,(de)
	cp _SPC
	jp z,ZadejJmenoEndTest
	inc de
	dec c
	jp nz,ZadejJmenoEndLoop
ZadejJmenoEndTest:
	ld a,e
	cp b
	jp z,ZadejJmenoCekejNaStisk
	call Chirp		; klik při stisku
	 jp ZadejJmenoCekejKlavesu
ZadejJmenoVymaz:
	ld a,e
 	cp txtJmeno & 0xFF
	jp nz,ZadejJmenoDoVymaz
	ld hl,txtJmeno
	ld b,6
ZadejJmenoTestCLR:
	ld a,(hl)
	inc hl
	cp _SPC
	jp nz,ZadejJmenoDoVymaz
	dec b
	jp nz,ZadejJmenoTestCLR
	 jp ZadejJmenoCekejNaStisk
ZadejJmenoDoVymaz:
	ld hl,_SPC*257
	ld (txtJmeno+0),hl
	ld (txtJmeno+2),hl
	ld (txtJmeno+4),hl
	ld de,txtJmeno
	call Chirp		; klik při stisku
	 jp ZadejJmenoCekejKlavesu
	
; ********************************************
; Vytiskne jméno rekordmana do editačního pole
; ********************************************
TiskJmena:
	push de
	ld hl,EnterNm+40ch
	ld (Prnpos),hl	; zadej pozici tisku do videoram
	ld hl,txtJmeno	; začátek buferu se jménem hráče
	ld a,(hl)		; načíst znak
	inc hl		; posunout se v buferu na další pozici
	call prtchr	; a načtený znak vytisknout
	ld a,(hl)		; to provést celkem 6x
	inc hl
	call prtchr
	ld a,(hl)
	inc hl
	call prtchr
	ld a,(hl)
	inc hl
	call prtchr
	ld a,(hl)
	inc hl
	call prtchr
	ld a,(hl)
	call prtchr
	pop de
	ret
; **********************************************************
; Ovladač alfanumerické klávesnice včetně funkce autorepeat.
; V ACC vrací ASCII kód klávesy (00h = není stisk)
; **********************************************************
GetKey:	call Inkey	; letmý test klávesnice
	ld a,d
	cp 0ffh
	jp nz,GetKeyPress	; něco bylo stisknuto
	ld hl,RptKad	; není stisk,
	ld a,(hl)
	and a
	ld a,0ffh
	ret z		; klávesa už je mrtvá => neřeším
	dec (hl)
	ret nz 		; běží rozestup ručního opakování
	ld (GetKeyPress+1),a
			; nastavit "klávesa už není stisknuta"
	ret		; a tím povolit novou detekci
GetKeyPress:
	cp 0ffh	; detekován stisk klávesy opakovaně?
	ld hl,RptDly
	jp z,GetKeyRepat	; ANO => pak běž na autorepeat
	ld (GetKeyPress+1),a ; když je změna, zaregistruj ji
	ld (hl),RPT_DLY	; spustit čekání na AUTOREPEAT
	ld hl,RptKad
	ld (hl),RPT_KAD	; kadence AUTOREPEATu
	ret		; ACC = platný znak - úvodní stisk
GetKeyRepat:
	ld a,0ffh	; dokud není čas, znak se negeneruje
	dec (hl)		; odpočet doby po úvodním stisku
	ret nz		; čekám na uplynutí této doby
	inc (hl)		; pak už udržuju čítač na hodnotě 1
	ld hl,RptKad
	dec (hl)		; rychlost autorepeatu
	ret nz		; mezi autorepeat-znaky negeneruji nic
	ld (hl),RPT_KAD	; reload autorepeat kadence
	ld a,(GetKeyPress+1)
			; a vracím opakovaně platný znak
	ret		; (fce autorepeat)
; *********************************************
; Letmý test klávesnice s konstantní délkou
; (ta je nutná kvůli isochronnímu autorepeatu).
; Vrací ASCII kód stisknutého znaku v reg. D
; (00h = není stisk).
; *********************************************
Inkey:
	ld d,0ffh		; neplatný znak (NULL)
	ld hl,tbKbdLayout	; rozložení znaků na klávesnici
InkeyRow:
	ld a,(hl)			; načíst masku řádku
	inc hl			; a posun na poslední znak
	cp 0ffh		; test masky
	ret z			; FFh => konec tabulky
	ld c,a			; C = maska řádku
	ld b,14		; B = kód posledního sloupce
InkeyCol:
	ld a,b			; zvolený sloupec klávesnice
	out (kbdout),a		; aktivovat 
	in a,(kbdin)		; načíst řádkovou odezvu
	or 80h			; odmaskovat nevyužitý bit
	cp c			; test klávesy v řádku a SHIFT
	jp nz,InkeyNotLatch	; není stisk => přeskoč zápis
	ld d,(hl)			; zapiš kód klávesy do D	
InkeyNotLatch:
	inc hl			; test předchozího sloupce
	dec b			; odpočet platných 15 sloupců
	jp p,InkeyCol		; běž na další sloupec
	 jp InkeyRow		; nebo na další řádek
; ******************************************
; Tabulka rozložení znaků na klávesnici
; Lze rozšířit i o kombinace s klávesou STOP
; ******************************************
tbKbdLayout:
	.db 0xFE	; Kx
	.db 0ffh,0ffh,0ffh,0ffh,0ffh,0ffh,0ffh,0ffh
	.db 0ffh,0ffh,0ffh,0ffh,0ffh,0ffh,0ffh
	.db 0xFD	; 12345..
	.db _CLR,0ffh,0ffh,37h,35h,00h,09h,08h
	.db 07h,06h,05h,04h,03h,02h,01h
	.db 0xFB	; QWERT..
	.db _RT,_HOME,_LT,3bh,39h,19h,18h,12h
	.db 1eh,23h,1dh,1bh,0eh,20h,1ah
	.db 0xF7	; ASDFG..
	.db _RT,_END,_LT,3eh,24h,3dh,15h,14h
	.db 13h,11h,10h,0fh,0dh,1ch,0ah
	.db 0xEF	; YXCVB..
	.db _EOL,_EOL,0ffh,0ffh,2ah,28h,27h,16h
	.db 17h,0bh,1fh,0ch,21h,22h,2bh
	.db 0xDE	; SHIFT + Kx
	.db 0ffh,0ffh,0ffh,0ffh,0ffh,0ffh,0ffh,0ffh
	.db 0ffh,0ffh,0ffh,0ffh,0ffh,0ffh,0ffh
	.db 0xDD	; SHIFT + 12345..
	.db _CLR,0ffh,0ffh,38h,36h,25h,34h,33h
	.db 32h,31h,30h,2fh,2eh,2dh,29h
	.db 0xDB	; SHIFT + QWERT..
	.db _RT,_HOME,_LT,3ch,3ah,19h,18h,12h
	.db 1eh,23h,1dh,1bh,0eh,20h,1ah
	.db 0xD7	; SHIFT + ASDFG..
	.db _RT,_END,_LT,3fh,40h,41h,15h,14h
	.db 13h,11h,10h,0fh,0dh,1ch,0ah
	.db 0xCF	; YXCVB..
	.db _EOL,_EOL,0ffh,0ffh,44h,43h,42h,16h
	.db 17h,0bh,1fh,0ch,21h,22h,2bh
	.db 0ffh	; konec tabulky
