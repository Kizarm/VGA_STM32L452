  .section .text.print
  .globl prtstg,pr6_hi,prtchr,pr6_lo,PrtInv
  
; ****************************************************
; Tisk řetězce, poslední znak má nastaven atribut 80h.
; vstup: HL = adresa začátku řetězce znaků
; ****************************************************
prtstg:	ld a,(hl)		; načíst aktuální znak
	and 7fh		; odmaskovat platné bity
	call prtchr	; znak vytisknout (vrací ACC=0)
	or (hl)		; test MSB tohoto znaku
	inc hl		; posun na další znak řetězce
	jp p,prtstg	; pokud znak neměl 80h, tisk dalšího 
	ret		; jinak konec
; **********************************************
; Předpony pro tisk cifer ve formátu packed BCD.
; **********************************************
pr6_hi:	rrca		; tisk horního nibble
	rrca
	rrca
	rrca
pr6_lo:	and 0fh		; tisk spodního nibble
; *********************************************
; Tisk znaku v rastru 9x8 pixelů.
; vstup: ACC = kód znaku 0..63
;        (prnpos) = adresa tisku do videoram
;         MSB = MSB adresy videoram (defacto Y)
;         LSB = pozice tisku X (0..31)
; *********************************************
prtchr:	push hl		; uschovat HL kvůli adresaci znaku
	ld hl,0		; uschovat stav reg. SP
	add hl,sp
	ld (prtchrSP+1),hl
	ld b,a		; B := A (= kód znaku)
	ld de,tbFont	; báze tabulky fontu
	add a,a		; A := 2x kód znaku
	add a,b		; A := 3x kód znaku
	ld l,a		; HL := 3x kód znaku
	ld h,0
	add hl,hl		; HL := 6x kód znaku
	add hl,hl		; HL := 12x kód znaku
	add hl,de		; HL := kompletní adresa předlohy znaku
	ex de,hl		; DE := kompletní adresa předlohy znaku
	
	ld sp,-(7*64)-1 ; SP := řádkovač
	ld a,(ColAtr+0)	; C := LSB atributu barvy 
	ld c,a
	ld hl,(Prnpos)	; HL := adresa tisku do videoram
	ld a,l
	rra		; ACC := X/2, CY := sudá/lichá pozice
	push af	; uschovat CY (sudá/lichá pozice)
	add a,l		; ACC := 1,5X
	inc l		; posun kurzoru
	ld (Prnpos),hl	; a uložení nové tiskové pozice
	ld l,a		; HL := finální adresa ve videoram
	pop af		; obnovit stav CY (sudá/lichá pozice)
	jp c,prt2nd	; skok pro liché pozice
	
; tisk na sudé tiskové pozice
prt1st:	ld a,(de)		; předloha 0. linky znaku (0/1/2/3)
	and 3fh		; odmaskovat 6 pixelů
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; zapsat do videoram
	inc l		; posunout se o bajt vpravo
	ld a,(hl)		; ponechat 3 bity pravého znaku
	and 38h
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; opět načíst předlohový bajt
	rla		; posunout
	rla		; na pozici
	rla
	and 3		; odmaskovat zbylé 2 pixely
	or b		; přidat bity znaku vpravo
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapsat do pravého bajtu videoram
	inc h		; přesun o 4 mikrořádky níže
	inc de		; další linka předlohy
	
	ld a,(hl)		; ponechat 3 bity pravého znaku
	and 38h
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; nyní v opačném směru zprava doleva
	rla		; tisknu 4. linku znaku (4/5/6/7)
	rla		; po posunu na pozici
	rla
	and 3		; odmaskuju 2 pixely vpravo
	or b		; přidat bity znaku vpravo
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapíšu do pravého bajtu videoram
	dec l		; posun na levý bajt
	ld a,(de)		; opět načtu předlohový bajt
	and 3fh		; ponechám z něj 6 levých pixelů
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; zapíšu do levého bajtu videoram
	inc h		; přesun o 4 mikrořádky níže
	inc de		; další předlohový bajt znaku
	ld a,(de)		; předloha 8. linky znaku (8/9/10/11)
	and 3fh		; odmaskovat 6 pixelů
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; zapsat do videoram
	inc l		; posunout se o bajt vpravo
	ld a,(hl)		; ponechat 3 bity pravého znaku
	and 38h
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; opět načíst předlohový bajt
	rla		; posunout
	rla		; na pozici
	rla
	and 3		; odmaskovat zbylé 2 pixely
	or b		; přidat bity znaku vpravo
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapsat do pravého bajtu videoram
	add hl,sp		; návrat o 8 mikrořádků výše
	inc de		; další linka předlohy
	ld a,(ColAtr+1)	; po každém mikrořádku
	ld (ColAtr+0),a	; prohodím dvojici atributů Colorace
	ld b,a
	ld a,c
	ld (ColAtr+1),a
	ld c,b
	ld a,l		; za předpokladu, že tiskové řádky
	and 0c0h	; začínají na linkách dělitelných osmi,
	jp nz,prt1st	; funguje toto jako NEXT linka
	 jp prtchrCommon	
; tisk na liché tiskové pozice
prt2nd:	ld a,(hl)		; ponechat 3 bity levého znaku
	and 7
	or c		; přidat atribut barvy Colorace
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; předloha 0. linky znaku (0/1/2/3)
	rlca		; posunout na pozici
	rlca
	rlca
	and 38h		; odmaskovat 3 pixely
	or b		; ponechám pixely předchozího znaku!
	ld (hl),a		; zapsat do videoram
	inc l		; posunout se o bajt vpravo
	ld a,(de)		; opět načíst předlohový bajt
	rrca		; posunout
	rrca		; na pozici
	rrca
	and 1fh		; odmaskovat zbylých 5 pixelů
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapsat do pravého bajtu videoram
	inc h		; přesun o 4 mikrořádky níže
	inc de		; další linka předlohy
	
	ld a,(de)		; nyní v opačném směru zprava doleva
	rrca		; tisknu 4. linku znaku (4/5/6/7)
	rrca		; po posunu na pozici
	rrca
	and 1fh		; odmaskuju 5 pixelů vpravo
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapíšu do pravého bajtu videoram
	dec l		; posun na levý bajt
	ld a,(hl)		; ponechat 3 bity levého znaku
	and 7
	or c		; přidat atribut barvy Colorace
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; opět načtu předlohový bajt
	rlca		; posunu pixely na pozici
	rlca
	rlca
	and 38h		; ponechám z něj 3 levé pixely
	or b		; ponechám pixely předchozího znaku!
	ld (hl),a		; zapíšu do levého bajtu videoram
	inc h		; přesun o 4 mikrořádky níže
	inc de		; další předlohový bajt znaku
	
	ld a,(hl)		; ponechat 3 bity levého znaku
	and 7
	or c		; přidat atribut barvy Colorace
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; předloha 8. linky znaku (8/9/10/11)
	rlca		; posunout na pozici
	rlca
	rlca
	and 38h		; odmaskovat 3 pixely
	or b		; ponechám pixely předchozího znaku!
	ld (hl),a		; zapsat do videoram
	inc l		; posunout se o bajt vpravo
	ld a,(de)		; opět načíst předlohový bajt
	rrca		; posunout
	rrca		; na pozici
	rrca
	and 1fh		; odmaskovat zbylých 5 pixelů
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapsat do pravého bajtu videoram
	add hl,sp		; návrat o 8 mikrořádků výše
	inc de		; další linka předlohy
	ld a,(ColAtr+1)	; po každém mikrořádku
	ld (ColAtr+0),a	; prohodím dvojici atributů Colorace
	ld b,a
	ld a,c
	ld (ColAtr+1),a
	ld c,b
	ld a,l		; za předpokladu, že tiskové řádky
	and 0c0h	; začínají na linkách dělitelných osmi,
	jp nz,prt2nd	; funguje toto jako NEXT linka
prtchrCommon:
	ex de,hl		; pro účely uchování adresy tisku
prtchrSP:
	ld sp,0
	pop hl
	ret
; *********************************************
; Tisk inverzního znaku v rastru 9x8 pixelů.
; vstup: ACC = kód znaku 0..63
;        (prnpos) = adresa tisku do videoram
;         MSB = MSB adresy videoram (defacto Y)
;         LSB = pozice tisku X (0..31)
; Procedura invertuje vybrané pozice ve znaku.
; Určeno pouze pro blikající editační kurzor.
; *********************************************
PrtInv:	push hl		; uschovat HL kvůli adresaci znaku
	ld hl,0		; uschovat stav reg. SP
	add hl,sp
	ld (prtchrSP+1),hl
	ld b,a		; B := A (= kód znaku)
	ld de,tbFont	; báze tabulky fontu
	add a,a		; A := 2x kód znaku
	add a,b		; A := 3x kód znaku
	ld l,a		; HL := 3x kód znaku
	ld h,0
	add hl,hl		; HL := 6x kód znaku
	add hl,hl		; HL := 12x kód znaku
	add hl,de		; HL := kompletní adresa předlohy znaku
	ex de,hl		; DE := kompletní adresa předlohy znaku
	
	ld sp,-(7*64)-1 ; SP := řádkovač
	ld a,(ColAtr+0)	; C := LSB atributu barvy 
	ld c,a
	ld hl,(Prnpos)	; HL := adresa tisku do videoram
	ld a,l
	rra		; ACC := X/2, CY := sudá/lichá pozice
	push af	; uschovat CY (sudá/lichá pozice)
	add a,l		; ACC := 1,5X
	inc l		; posun kurzoru
	ld (Prnpos),hl	; a uložení nové tiskové pozice
	ld l,a		; HL := finální adresa ve videoram
	pop af		; obnovit stav CY (sudá/lichá pozice)
	jp c,PrtInv2nd	; skok pro liché pozice
	
; tisk na sudé tiskové pozice
PrtInv1st:
	ld a,(de)		; předloha 0. linky znaku (0/1/2/3)
	cpl
	and 3fh		; odmaskovat 6 pixelů
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; zapsat do videoram
	inc l		; posunout se o bajt vpravo
	ld a,(hl)		; ponechat 3 bity pravého znaku
	and 38h
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; opět načíst předlohový bajt
	cpl
	rla		; posunout
	rla		; na pozici
	rla
	and 3		; odmaskovat zbylé 2 pixely
	or b		; přidat bity znaku vpravo
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapsat do pravého bajtu videoram
	inc h		; přesun o 4 mikrořádky níže
	inc de		; další linka předlohy
	
	ld a,(hl)		; ponechat 3 bity pravého znaku
	and 38h
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; nyní v opačném směru zprava doleva
	cpl
	rla		; tisknu 4. linku znaku (4/5/6/7)
	rla		; po posunu na pozici
	rla
	and 3		; odmaskuju 2 pixely vpravo
	or b		; přidat bity znaku vpravo
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapíšu do pravého bajtu videoram
	dec l		; posun na levý bajt
	ld a,(de)		; opět načtu předlohový bajt
	cpl
	and 3fh		; ponechám z něj 6 levých pixelů
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; zapíšu do levého bajtu videoram
	inc h		; přesun o 4 mikrořádky níže
	inc de		; další předlohový bajt znaku
	ld a,(de)		; předloha 8. linky znaku (8/9/10/11)
	cpl
	and 3fh		; odmaskovat 6 pixelů
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; zapsat do videoram
	inc l		; posunout se o bajt vpravo
	ld a,(hl)		; ponechat 3 bity pravého znaku
	and 38h
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; opět načíst předlohový bajt
	cpl
	rla		; posunout
	rla		; na pozici
	rla
	and 3		; odmaskovat zbylé 2 pixely
	or b		; přidat bity znaku vpravo
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapsat do pravého bajtu videoram
	add hl,sp		; návrat o 8 mikrořádků výše
	inc de		; další linka předlohy
	ld a,(ColAtr+1)	; po každém mikrořádku
	ld (ColAtr+0),a	; prohodím dvojici atributů Colorace
	ld b,a
	ld a,c
	ld (ColAtr+1),a
	ld c,b
	ld a,l		; za předpokladu, že tiskové řádky
	and 0c0h	; začínají na linkách dělitelných osmi,
	jp nz,PrtInv1st	; funguje toto jako NEXT linka
	 jp prtchrCommon	
; tisk na liché tiskové pozice
PrtInv2nd:
	ld a,(hl)		; ponechat 3 bity levého znaku
	and 7
	or c		; přidat atribut barvy Colorace
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; předloha 0. linky znaku (0/1/2/3)
	cpl
	rlca		; posunout na pozici
	rlca
	rlca
	and 38h		; odmaskovat 3 pixely
	or b		; ponechám pixely předchozího znaku!
	ld (hl),a		; zapsat do videoram
	inc l		; posunout se o bajt vpravo
	ld a,(de)		; opět načíst předlohový bajt
	cpl
	rrca		; posunout
	rrca		; na pozici
	rrca
	and 1fh		; odmaskovat zbylých 5 pixelů
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapsat do pravého bajtu videoram
	inc h		; přesun o 4 mikrořádky níže
	inc de		; další linka předlohy
	
	ld a,(de)		; nyní v opačném směru zprava doleva
	cpl
	rrca		; tisknu 4. linku znaku (4/5/6/7)
	rrca		; po posunu na pozici
	rrca
	and 1fh		; odmaskuju 5 pixelů vpravo
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapíšu do pravého bajtu videoram
	dec l		; posun na levý bajt
	ld a,(hl)		; ponechat 3 bity levého znaku
	and 7
	or c		; přidat atribut barvy Colorace
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; opět načtu předlohový bajt
	cpl
	rlca		; posunu pixely na pozici
	rlca
	rlca
	and 38h		; ponechám z něj 3 levé pixely
	or b		; ponechám pixely předchozího znaku!
	ld (hl),a		; zapíšu do levého bajtu videoram
	inc h		; přesun o 4 mikrořádky níže
	inc de		; další předlohový bajt znaku
	
	ld a,(hl)		; ponechat 3 bity levého znaku
	and 7
	or c		; přidat atribut barvy Colorace
	ld b,a		; uschovat mezivýsledek do B
	ld a,(de)		; předloha 8. linky znaku (8/9/10/11)
	cpl
	rlca		; posunout na pozici
	rlca
	rlca
	and 38h		; odmaskovat 3 pixely
	or b		; ponechám pixely předchozího znaku!
	ld (hl),a		; zapsat do videoram
	inc l		; posunout se o bajt vpravo
	ld a,(de)		; opět načíst předlohový bajt
	cpl
	rrca		; posunout
	rrca		; na pozici
	rrca
	and 1fh		; odmaskovat zbylých 5 pixelů
	or c		; přidat atribut barvy Colorace
	ld (hl),a		; a zapsat do pravého bajtu videoram
	add hl,sp		; návrat o 8 mikrořádků výše
	inc de		; další linka předlohy
	ld a,(ColAtr+1)	; po každém mikrořádku
	ld (ColAtr+0),a	; prohodím dvojici atributů Colorace
	ld b,a
	ld a,c
	ld (ColAtr+1),a
	ld c,b
	ld a,l		; za předpokladu, že tiskové řádky
	and 0c0h	; začínají na linkách dělitelných osmi,
	jp nz,PrtInv2nd	; funguje toto jako NEXT linka
	 jp prtchrCommon	
; ******************************************************
; Mapa znaků pro formát 9x12 pixelů se střídavým řazením
; linek v pořadí: 0-4-8-1-5-9-2-6-10-3-7-11
; ******************************************************
tbFont:
;    0    4    8    1    5    9    2    6    10   3    7    11 
; 0
.db 000h,099h,0c3h,07eh,089h,0ffh,0ffh,091h,07eh,0c3h,099h,000h
; 1
.db 000h,0e3h,0c3h,07eh,0e7h,0ffh,0ffh,0e7h,07eh,0e7h,0e7h,000h
; 2
.db 000h,099h,081h,07eh,09fh,0ffh,0ffh,0c3h,07eh,0c3h,0f9h,000h
; 3
.db 000h,099h,0c3h,07eh,0cfh,0ffh,0ffh,09fh,07eh,0c3h,099h,000h
; 4
.db 000h,0f3h,0cfh,07eh,0f9h,0ffh,0ffh,0c9h,07eh,0e7h,081h,000h
; 5
.db 000h,0f9h,0c3h,07eh,0c1h,0ffh,0ffh,09fh,07eh,081h,099h,000h
; 6
.db 000h,0f9h,0c3h,07eh,0c1h,0ffh,0ffh,099h,07eh,0c3h,099h,000h
; 7
.db 000h,09fh,0e7h,07eh,09fh,0ffh,0ffh,0cfh,07eh,081h,0e7h,000h
; 8
.db 000h,099h,0c3h,07eh,0c3h,0ffh,0ffh,099h,07eh,0c3h,099h,000h
; 9
.db 000h,099h,0c3h,07eh,099h,0ffh,0ffh,083h,07eh,0c3h,09fh,000h
; A (0ah)
.db 000h,099h,099h,07eh,099h,0ffh,0ffh,099h,07eh,0c3h,081h,000h
; B (0bh)
.db 000h,099h,0c1h,07eh,0c1h,0ffh,0ffh,099h,07eh,0c1h,099h,000h
; C (0ch)
.db 000h,099h,0c3h,07eh,0f9h,0ffh,0ffh,0f9h,07eh,0c3h,099h,000h
; D (0dh)
.db 000h,099h,0c1h,07eh,099h,0ffh,0ffh,099h,07eh,0c1h,099h,000h
; E (0eh)
.db 000h,0f9h,081h,07eh,0c1h,0ffh,0ffh,0f9h,07eh,081h,0f9h,000h
; F (0fh)
.db 000h,0f9h,0f9h,07eh,0c1h,0ffh,0ffh,0f9h,07eh,081h,0f9h,000h
; G (10h)
.db 000h,099h,0a3h,07eh,0f9h,0ffh,0ffh,081h,07eh,0c3h,099h,000h
; H (11h)
.db 000h,099h,099h,07eh,099h,0ffh,0ffh,081h,07eh,099h,099h,000h
; I (12h)
.db 000h,0e7h,0c3h,07eh,0e7h,0ffh,0ffh,0e7h,07eh,0c3h,0e7h,000h
; J (13h)
.db 000h,09fh,0c3h,07eh,09fh,0ffh,0ffh,09fh,07eh,083h,099h,000h
; K (14h)
.db 000h,0c9h,099h,07eh,0e1h,0ffh,0ffh,0e1h,07eh,099h,0c9h,000h
; L (15h)
.db 000h,0f9h,081h,07eh,0f9h,0ffh,0ffh,0f9h,07eh,0f9h,0f9h,000h
; M (16h)
.db 000h,081h,099h,07eh,0a5h,0ffh,0ffh,0bdh,07eh,099h,099h,000h
; N (17h)
.db 000h,091h,099h,07eh,081h,0ffh,0ffh,089h,07eh,099h,099h,000h
; O (18h)
.db 000h,099h,0c3h,07eh,099h,0ffh,0ffh,099h,07eh,0c3h,099h,000h
; P (19h)
.db 000h,099h,0f9h,07eh,099h,0ffh,0ffh,099h,07eh,0c1h,0c1h,000h
; Q (1Ah)
.db 000h,099h,093h,07eh,099h,0ffh,0ffh,0a9h,07eh,0c3h,0c9h,000h
; R (1Bh)
.db 000h,099h,099h,07eh,099h,0ffh,0ffh,081h,07eh,0c1h,0c9h,000h
; S (1Ch)
.db 000h,0f9h,0c3h,07eh,0c3h,0ffh,0ffh,09fh,07eh,0c3h,099h,000h
; T (1Dh)
.db 000h,0e7h,0e7h,07eh,0e7h,0ffh,0ffh,0e7h,07eh,081h,0e7h,000h
; U (1Eh)
.db 000h,099h,0c3h,07eh,099h,0ffh,0ffh,099h,07eh,099h,099h,000h
; V (1Fh)
.db 000h,099h,0f3h,07eh,099h,0ffh,0ffh,0c9h,07eh,099h,0e1h,000h
; W (20h)
.db 000h,099h,099h,07eh,0bdh,0ffh,0ffh,0a5h,07eh,099h,081h,000h
; X (21h)
.db 000h,091h,099h,07eh,0e3h,0ffh,0ffh,0c7h,07eh,099h,089h,000h
; Y (22h)
.db 000h,099h,0e7h,07eh,099h,0ffh,0ffh,0c3h,07eh,099h,0e7h,000h
; Z (23h)
.db 000h,09fh,081h,07eh,0c7h,0ffh,0ffh,0f3h,07eh,081h,0f9h,000h
; : (24h)
.db 000h,0e7h,0e7h,07eh,0e7h,0ffh,0ffh,0ffh,07eh,0ffh,0e7h,000h
; - (25h)
.db 000h,0ffh,0ffh,07eh,0ffh,0ffh,0ffh,0c3h,07eh,0ffh,0ffh,000h
; SPC tečka (26h)
.db 000h,000h,010h,000h,000h,000h,000h,000h,000h,000h,000h,000h
; , (27h)
.db 000h,0ffh,0e7h,07eh,0ffh,0f3h,0ffh,0ffh,07eh,0ffh,0e7h,000h
; . (28h)
.db 000h,0ffh,0e7h,07eh,0ffh,0ffh,0ffh,0ffh,07eh,0ffh,0e7h,000h
; ! (29h)
.db 000h,0e7h,0e7h,07eh,0e7h,0ffh,0ffh,0e7h,07eh,0e7h,0ffh,000h
; / (2Ah)
.db 000h,09fh,0f9h,07eh,0cfh,0ffh,0ffh,0e7h,07eh,0ffh,0f3h,000h
; SPC čtverec (2Bh)
.db 000h,0ffh,0ffh,07eh,0ffh,0ffh,0ffh,0ffh,07eh,0ffh,0ffh,000h
; nic (2Ch)
.db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
; uvozovky (2Dh)
.db 000h,093h,0ffh,07eh,0b7h,0ffh,0ffh,0ffh,07eh,093h,0ffh,000h
; # (2Eh)
.db 000h,0d7h,0d7h,07eh,083h,0ffh,0ffh,0d7h,07eh,0ffh,083h,000h
; $ (2Fh)
.db 000h,087h,0c3h,07eh,0ebh,0efh,0ffh,0c7h,07eh,0efh,0afh,000h
; % (30h)
.db 000h,0d9h,0cdh,07eh,0e9h,0ffh,0ffh,0f7h,07eh,0ffh,0cbh,000h
; & (31h)
.db 000h,0e9h,093h,07eh,0f3h,0ffh,0ffh,0a5h,07eh,0f3h,0cdh,000h
; apostrof (32h)
.db 000h,0cfh,0ffh,07eh,0dfh,0ffh,0ffh,0ffh,07eh,0cfh,0ffh,000h
; levá kulatá závorka (33h)
.db 000h,0e7h,0cfh,07eh,0e7h,0dfh,0dfh,0e7h,07eh,0cfh,0e7h,000h
; pravá kulatá závorka (34h)
.db 000h,0e7h,0f3h,07eh,0e7h,0fbh,0fbh,0e7h,07eh,0f3h,0e7h,000h
; _ (35h)
.db 000h,0ffh,081h,07eh,0ffh,0ffh,0ffh,0ffh,07eh,0ffh,0ffh,000h
; = (36h)
.db 000h,0ffh,0ffh,07eh,0c3h,0ffh,0ffh,0ffh,07eh,0ffh,0c3h,000h
; } (37h)
.db 000h,0e7h,0e7h,07eh,0cfh,0f3h,0f3h,0cfh,07eh,0e7h,0e7h,000h
; { (38h)
.db 000h,0e7h,0e7h,07eh,0f3h,0cfh,0cfh,0f3h,07eh,0e7h,0e7h,000h
; @ (39h)
.db 000h,099h,083h,07eh,089h,0ffh,0ffh,089h,07eh,0c3h,0f9h,000h
; ` (3Ah)
.db 000h,0f3h,0ffh,07eh,0fbh,0ffh,0ffh,0ffh,07eh,0f3h,0ffh,000h
; \ (3Bh)
.db 000h,0f9h,09fh,07eh,0f3h,0ffh,0ffh,0e7h,07eh,0ffh,0cfh,000h
; ^ (3Ch)
.db 000h,093h,0ffh,07eh,0ffh,0ffh,0efh,0ffh,07eh,0c7h,0ffh,000h
; ; (3Dh)
.db 000h,0e7h,0e7h,07eh,0e7h,0f3h,0ffh,0ffh,07eh,0ffh,0e7h,000h
; ] (3Eh)
.db 000h,0cfh,0c3h,07eh,0cfh,0ffh,0ffh,0cfh,07eh,0c3h,0cfh,000h
; [ (3Fh)
.db 000h,0f3h,0c3h,07eh,0f3h,0ffh,0ffh,0f3h,07eh,0c3h,0f3h,000h
; * (40h)
.db 000h,0efh,0efh,07eh,0abh,0ffh,0ffh,0c7h,07eh,0ffh,0abh,000h
; + (41h)
.db 000h,0e7h,0e7h,07eh,0e7h,0ffh,0ffh,081h,07eh,0ffh,0e7h,000h
; < (42h)
.db 000h,0cfh,0cfh,07eh,0e7h,0ffh,0ffh,0f3h,07eh,0ffh,0e7h,000h
; > (43h)
.db 000h,0f3h,0f3h,07eh,0e7h,0ffh,0ffh,0cfh,07eh,0ffh,0e7h,000h
; ? (44h)
.db 000h,099h,0e7h,07eh,0cfh,0ffh,0ffh,0e7h,07eh,0c3h,0ffh,000h
;    0    4    8    1    5    9    2    6    10   3    7    11 
