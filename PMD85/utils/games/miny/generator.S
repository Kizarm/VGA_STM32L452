.include "add_def.S"
CellM	.equ 80h	; kód buňky s minou
CellE	.equ 00h	; kód buňky bez miny
; *******************************************
; Vygeneruje minové pole dle zadané velikosti
; *******************************************
  .section .text.generator
  .globl InitPole
InitPole:
; ************************************************
; Nejprve celé pole vyplní minami, které slouží
; jako částečný mantinel pro pozdější rozmisťování
; ************************************************
InitPoleFill:
	ld bc,+(32*256)+16	; B=32, C=16
	ld hl,Pole		; adresa minového pole
InitPoleFillX:
	push bc			; uschovat čítače rozměru pole
	push hl			; uschovat pozici
				; nahoře ve sloupci
InitPoleFillY:
	ld (hl),CellM		; zaminovat buňku
	inc l			; indexY++
	dec c			; odpočet svislých buněk
	jp nz,InitPoleFillY
	pop hl			; obnovit adresu
				; nahoře ve sloupci
	pop bc			; obnovit čítače rozměru pole
	inc h			; indexX++
	dec b			; odpočet vodorovných buněk
	jp nz,InitPoleFillX
	
; *************************************
; Pak pracovní část pole vyčistí od min
; *************************************
	ld hl,(F_Left)	; C = počet buněk na řádku
	ld a,h
	sub l
	ld c,a
	ld d,l		; D = index MSB buňky v LH rohu
	ld hl,(F_Up)	; B = počet buněk ve sloupci
	push hl
	ld a,h
	sub l
	ld b,a
	ld e,l		; E = index LSB buňky v LH rohu
	ld hl,Pole	; HL = ukazatel na buňku v LH rohu
	add hl,de
	push bc		; uschovat parametry pole
	push hl		; pro sčítání sousedů
InitPoleX:
	push bc		; uschovat rozměry pole
	push hl		; a aktuální adresu pole
InitPoleY:
	ld (hl),CellE	; aktuální buňka nemá minu
	inc hl		; indexY++
	dec b		; odpočet výšky pole
	jp nz,InitPoleY
	pop hl		; obnovit adresu na začátku sloupce
	pop bc		; obnovit rozměry pole
	inc h		; indexX++
	dec c		; odpočet šířky pole
	jp nz,InitPoleX
; ***********************************
; Nyní se koná vlastní rozmístění min
; ***********************************
.if FIX_PATTERN
	call FixPattern	; fixní vzor pro účely ladění
.else
	call RandomPattern
.endif
.if KONTROLUJ_MINY
	; pro jistotu spočítám rozmístěné miny
	pop hl		; adresa buňky v LH rohu
	pop bc		; B = Ysize, C = Xsize
	push bc
	push hl
	ld d,0
SectiPolozeneMinyX:
	push bc		; uschovat počitadla řádků a sloupců
	push hl		; uschovat adresu buňky
SectiPolozeneMinyY:
	ld a,(hl)		; načíst buňku
	and a		; je v ní fyzicky mina?
	jp p,NeniZdeMina
	inc d
NeniZdeMina:
	inc hl		; Y++
	dec b		; odpočet výšky minového pole
	jp nz,SectiPolozeneMinyY
	pop hl		; obnovit adresu na začátku sloupce
	pop bc		; obnovit počitadla řádků/sloupců
	inc h		; X++
	dec c		; odpočet šířky minového pole
	jp nz,SectiPolozeneMinyX
	ld a,(ZbytekMin)
	cp d
	jp nz,$
.endif
; *****************************************
; Následně se do buněk doplní počty sousedů
; abych se s tím při odkrývání nezdržoval
; *****************************************
	pop hl		; adresa buňky v LH rohu
	pop bc		; B = Ysize, C = Xsize
	pop de		; D = Fdown+1, E = Fup
	dec d
	inc e
SectiSousedyX:
	push bc		; uschovat počitadla řádků a sloupců
	push hl		; uschovat adresu buňky
SectiSousedyY:
	ld a,(hl)		; načíst buňku
	and a		; je v ní fyzicky mina?
	call m,SectiSousedyMina ; => přičti +1 u všech sousedů
	inc hl		; Y++
	dec b		; odpočet výšky minového pole
	jp nz,SectiSousedyY
	pop hl		; obnovit adresu na začátku sloupce
	pop bc		; obnovit počitadla řádků/sloupců
	inc h		; X++
	dec c		; odpočet šířky minového pole
	jp nz,SectiSousedyX
	ret
; ************************************************************
; Při sčítání sousedů jsem našel minu, proto přičtu jedničku
; k okolním buňkám. Je to rychlejší než pro každou buňku
; sčítat okolní miny.
; Svislý index hlídám na přetečení krajních hodnot, protože
; se využívá plný rozsah pole 0..15. Vodorovný index
; nehlídám, protože se plný rozsah pole nevyužívá a klidně
; mohu přičítat miny v buňkách mimo aktivní část hracího pole.
; V tomto případě neopustím alokovanou paměť pro pole.
; ************************************************************
SectiSousedyMina:
	ld a,l
	and 0fh
	cp d		; CY=0 pro Y>Ymax
	inc h		; => [+1,0]
	inc (hl)		; na pozici [+1,0] přidej minu
	inc l		; => [+1,+1]
	jp nc,$+4		; v dolním řádku přeskoč pozici [+1,+1]
	inc (hl)		; na pozici [+1,1] přidej minu
	dec h		; => [0,+1]
	jp nc,$+4		; v dolním řádku přeskoč pozici [0,+1]
	inc (hl)		; na pozici [0,1] přidej minu
	dec h		; => [-1,+1]
	jp nc,$+4		; v dolním řádku přeskoč pozici [-1,+1]
	inc (hl)		; na pozici [-1,1] přidej minu
	dec l		; => [-1,0]
	inc (hl)		; na pozici [-1,0] přidej minu
	cp e		; CY=1 pro Y<Ymin
	dec l		; => [-1,-1]
	jp c,$+4		; v horním řádku přeskoč pozici [-1,-1]
	inc (hl)		; na pozici [-1,-1] přidej minu
	inc h		; => [0,-1]
	jp c,$+4		; v horním řádku přeskoč pozici [0,-1]
	inc (hl)		; na pozici [0,-1] přidej minu
	inc h		; => [+1,-1]
	jp c,$+4		; v horním řádku přeskoč pozici [+1,-1]
	inc (hl)		; na pozici [+1,-1] přidej minu
	inc l		; =>návrat na [+0,+0]
	dec h
	ret
; ***********************************************************
; Fixní rozmístění min pro účely ladění - podmíněná kompilace
; ***********************************************************
.if FIX_PATTERN
FixPattern:
	ld hl,Pole+6+(256*9)
	ld (hl),CellM
	inc h
	ld (hl),CellM
	inc h
	ld (hl),CellM
	inc h
	ld (hl),CellM
	inc h
	ld (hl),CellM
	dec h
	dec h
	inc l
	ld (hl),CellM
	dec h
	dec h
	ld (hl),CellM
	inc l
	ld (hl),CellM
	inc h
	ld (hl),CellM
	inc h
	ld (hl),CellM
	inc h
	ld (hl),CellM
	dec h
	inc l
	ld (hl),CellM
	dec h
	dec h
	ld (hl),CellM
	inc l	
	ld (hl),CellM
	inc h
	inc h
	ld (hl),CellM
	inc h
	ld (hl),CellM
	ret
.endif
; **********************************
; Homogenní rozmístění min s variací
; **********************************
RandomPattern:
	ld a,(PoleSize)	; dle velikosti minového pole
	ld hl,tbSeeds	; a tabulky homogenních layoutů min 
	rst 0x18; vybere tu pravou tabulku
	ld c,(hl)		; C = počet min v poli
	inc hl		; přesun na vlastní seznam min
	ld b,CellM	; B = kód položené miny
RandomPatternLoop:
RandomPatternY:
	ld e,(hl)		; LSB PTR do minového pole
	call GetSignedRandom
	add a,e		; k pozici Y přičtu -3..+3
	ld e,a
	and 30h
	cp 30h		; a při opuštění minového pole
	jp nz,RandomPatternY ; zkusím znovu
RandomPatternX:
	inc hl
	ld d,(hl)		; MSB PTR do minového pole
	dec hl
	call GetSignedRandom
	add a,d		; k pozici X přičtu -3..+3
	ld d,a
	and 0e0h
	cp 0e0h	; a při opuštění minového pole
	jp nz,RandomPatternX ; zkusím znovu
	ld a,(de)		; je na cílové adrese v minovém poli
	cp CellM	; už mina?
	jp z,RandomPatternLoop ; zkus novou pozici
	ld a,b		; kód miny
	ld (de),a		; polož do minového pole
	inc hl		; posun v seznamu na další minu
	inc hl
	dec c		; odpočet pokládaných min
	jp nz,RandomPatternLoop
	ret
; *********************
; Vrací (signed int)RND
; *********************
GetSignedRandom:
	call MoreRandom	; zamíchat generátorem podle času v T2
	call GetRandom	; načte obecné náhodné číslo
	and 7		; ponechá jen 3 spodní bity
	rra		; dva nechá, jeden vsune do CY
	ret nc		; CY=0? => vrať 0..+3
	cpl		; CY=1?
	inc a		; => vrať -3..0
	ret
; *****************************************************
; Pro všechny tři velikosti minového pole jsou obsaženy
; zcela homogenní vzory s rozmístěním min. Později se
; dle náhody provedou jemné variace pozice.
; *****************************************************
tbSeeds:
	.dw tbSeed0,tbSeed1,tbSeed2
.ifndef NARROW_PATTERN
tbSeed0:
	.db POCET_MIN_L0	; new set
	.dw Pole+4+(256*7)	; *...*...*
	.dw Pole+4+(256*11)	; .........
	.dw Pole+4+(256*15)	; .........
	.dw Pole+7+(256*9)	; ..*...*..
	.dw Pole+7+(256*13)	; .........
	.dw Pole+9+(256*9)	; ..*...*..
	.dw Pole+9+(256*13)	; .........
	.dw Pole+12+(256*7)	; .........
	.dw Pole+12+(256*11)	; *.......*
	.dw Pole+12+(256*15)
tbSeed1:
	.db POCET_MIN_L1
	.dw Pole+2+(256*6)	; ...............
	.dw Pole+2+(256*8)	; ...............
	.dw Pole+2+(256*10)	; ..*.*.*.*.*.*..
	.dw Pole+2+(256*12)	; ...............
	.dw Pole+2+(256*14)	; ..*.*.*.*.*.*..
	.dw Pole+2+(256*16)	; ...............
	.dw Pole+4+(256*6)	; ...*.*.*.*.*...
	.dw Pole+4+(256*8)	; ...............
	.dw Pole+4+(256*10)	; ...*.*.*.*.*...
	.dw Pole+4+(256*12)	; ...............
	.dw Pole+4+(256*14)	; ..*.*.*.*.*.*..
	.dw Pole+4+(256*16)	; ...............
	.dw Pole+6+(256*7)	; ..*.*.*.*.*.*..
	.dw Pole+6+(256*9)	; ...............
	.dw Pole+6+(256*11)	; ...............
	.dw Pole+6+(256*13)
	.dw Pole+6+(256*15)
	.dw Pole+8+(256*7)
	.dw Pole+8+(256*9)
	.dw Pole+8+(256*11)
	.dw Pole+8+(256*13)
	.dw Pole+8+(256*15)
	.dw Pole+10+(256*6)
	.dw Pole+10+(256*8)
	.dw Pole+10+(256*10)
	.dw Pole+10+(256*12)
	.dw Pole+10+(256*14)
	.dw Pole+10+(256*16)
	.dw Pole+12+(256*6)
	.dw Pole+12+(256*8)
	.dw Pole+12+(256*10)
	.dw Pole+12+(256*12)
	.dw Pole+12+(256*14)
	.dw Pole+12+(256*16)
tbSeed2:
	.db POCET_MIN_L2
	.dw Pole+2+(256*3)	; .....................
	.dw Pole+1+(256*5)	; ....*...*...*...*....
	.dw Pole+2+(256*7)	; ..*...*...*...*...*..
	.dw Pole+1+(256*9)	; ....*...*...*...*....
	.dw Pole+2+(256*11)	; ..*...*...*...*...*..
	.dw Pole+1+(256*13)	; ....*...*...*...*....
	.dw Pole+2+(256*15)	; ..*...*.......*...*..
	.dw Pole+1+(256*17)	; ....*...*...*...*....
	.dw Pole+2+(256*19)	; ..*...*.......*...*..
	.dw Pole+4+(256*3)	; ....*...*...*...*....
	.dw Pole+3+(256*5)	; ..*...*.......*...*..
	.dw Pole+4+(256*7)	; ....*...*...*...*....
	.dw Pole+3+(256*9)	; ..*...*...*...*...*..
	.dw Pole+4+(256*11)	; ....*...*...*...*....
	.dw Pole+3+(256*13)	; ..*...*...*...*...*..
	.dw Pole+4+(256*15)	; .....................
	.dw Pole+3+(256*17)
	.dw Pole+4+(256*19)
	.dw Pole+6+(256*3)
	.dw Pole+5+(256*5)
	.dw Pole+6+(256*7)
	.dw Pole+5+(256*9)
	.dw Pole+5+(256*13)
	.dw Pole+6+(256*15)
	.dw Pole+5+(256*17)
	.dw Pole+6+(256*19)
	.dw Pole+8+(256*3)
	.dw Pole+7+(256*5)
	.dw Pole+8+(256*7)
	.dw Pole+7+(256*9)
	.dw Pole+7+(256*13)
	.dw Pole+8+(256*15)
	.dw Pole+7+(256*17)
	.dw Pole+8+(256*19)
	.dw Pole+10+(256*3)
	.dw Pole+9+(256*5)
	.dw Pole+10+(256*7)
	.dw Pole+9+(256*9)
	.dw Pole+9+(256*13)
	.dw Pole+10+(256*15)
	.dw Pole+9+(256*17)
	.dw Pole+10+(256*19)
	.dw Pole+12+(256*3)
	.dw Pole+11+(256*5)
	.dw Pole+12+(256*7)
	.dw Pole+11+(256*9)
	.dw Pole+12+(256*11)
	.dw Pole+11+(256*13)
	.dw Pole+12+(256*15)
	.dw Pole+11+(256*17)
	.dw Pole+12+(256*19)
	.dw Pole+14+(256*3)
	.dw Pole+13+(256*5)
	.dw Pole+14+(256*7)
	.dw Pole+13+(256*9)
	.dw Pole+14+(256*11)
	.dw Pole+13+(256*13)
	.dw Pole+14+(256*15)
	.dw Pole+13+(256*17)
	.dw Pole+14+(256*19)
.else
tbSeed0:
	.db POCET_MIN_L0	; old set
	.dw Pole+6+(256*8)	; .........
	.dw Pole+5+(256*11)	; ....*....
	.dw Pole+6+(256*14)	; .*.....*.
	.dw Pole+8+(256*8)	; .........
	.dw Pole+8+(256*10)	; .*.*.*.*.
	.dw Pole+8+(256*12)	; .........
	.dw Pole+8+(256*14)	; .*.....*.
	.dw Pole+10+(256*8)	; ....*....
	.dw Pole+11+(256*11)	; .........
	.dw Pole+10+(256*14)
tbSeed1:
	.db POCET_MIN_L1
	.dw Pole+2+(256*6)	; ...............
	.dw Pole+2+(256*8)	; ...............
	.dw Pole+2+(256*10)	; ..*.*.*.*.*.*..
	.dw Pole+2+(256*12)	; ...............
	.dw Pole+2+(256*14)	; ..*.*.*.*.*.*..
	.dw Pole+2+(256*16)	; ...............
	.dw Pole+4+(256*6)	; ...*.*.*.*.*...
	.dw Pole+4+(256*8)	; ...............
	.dw Pole+4+(256*10)	; ...*.*.*.*.*...
	.dw Pole+4+(256*12)	; ...............
	.dw Pole+4+(256*14)	; ..*.*.*.*.*.*..
	.dw Pole+4+(256*16)	; ...............
	.dw Pole+6+(256*7)	; ..*.*.*.*.*.*..
	.dw Pole+6+(256*9)	; ...............
	.dw Pole+6+(256*11)	; ...............
	.dw Pole+6+(256*13)
	.dw Pole+6+(256*15)
	.dw Pole+8+(256*7)
	.dw Pole+8+(256*9)
	.dw Pole+8+(256*11)
	.dw Pole+8+(256*13)
	.dw Pole+8+(256*15)
	.dw Pole+10+(256*6)
	.dw Pole+10+(256*8)
	.dw Pole+10+(256*10)
	.dw Pole+10+(256*12)
	.dw Pole+10+(256*14)
	.dw Pole+10+(256*16)
	.dw Pole+12+(256*6)
	.dw Pole+12+(256*8)
	.dw Pole+12+(256*10)
	.dw Pole+12+(256*12)
	.dw Pole+12+(256*14)
	.dw Pole+12+(256*16)
tbSeed2:
	.db POCET_MIN_L2
	.dw Pole+2+(256*3)	; .....................
	.dw Pole+1+(256*5)	; ....*...*...*...*....
	.dw Pole+2+(256*7)	; ..*...*...*...*...*..
	.dw Pole+1+(256*9)	; ....*...*...*...*....
	.dw Pole+2+(256*11)	; ..*...*...*...*...*..
	.dw Pole+1+(256*13)	; ....*...*...*...*....
	.dw Pole+2+(256*15)	; ..*...*.......*...*..
	.dw Pole+1+(256*17)	; ....*...*...*...*....
	.dw Pole+2+(256*19)	; ..*...*.......*...*..
	.dw Pole+4+(256*3)	; ....*...*...*...*....
	.dw Pole+3+(256*5)	; ..*...*.......*...*..
	.dw Pole+4+(256*7)	; ....*...*...*...*....
	.dw Pole+3+(256*9)	; ..*...*...*...*...*..
	.dw Pole+4+(256*11)	; ....*...*...*...*....
	.dw Pole+3+(256*13)	; ..*...*...*...*...*..
	.dw Pole+4+(256*15)	; .....................
	.dw Pole+3+(256*17)
	.dw Pole+4+(256*19)
	.dw Pole+6+(256*3)
	.dw Pole+5+(256*5)
	.dw Pole+6+(256*7)
	.dw Pole+5+(256*9)
	.dw Pole+5+(256*13)
	.dw Pole+6+(256*15)
	.dw Pole+5+(256*17)
	.dw Pole+6+(256*19)
	.dw Pole+8+(256*3)
	.dw Pole+7+(256*5)
	.dw Pole+8+(256*7)
	.dw Pole+7+(256*9)
	.dw Pole+7+(256*13)
	.dw Pole+8+(256*15)
	.dw Pole+7+(256*17)
	.dw Pole+8+(256*19)
	.dw Pole+10+(256*3)
	.dw Pole+9+(256*5)
	.dw Pole+10+(256*7)
	.dw Pole+9+(256*9)
	.dw Pole+9+(256*13)
	.dw Pole+10+(256*15)
	.dw Pole+9+(256*17)
	.dw Pole+10+(256*19)
	.dw Pole+12+(256*3)
	.dw Pole+11+(256*5)
	.dw Pole+12+(256*7)
	.dw Pole+11+(256*9)
	.dw Pole+12+(256*11)
	.dw Pole+11+(256*13)
	.dw Pole+12+(256*15)
	.dw Pole+11+(256*17)
	.dw Pole+12+(256*19)
	.dw Pole+14+(256*3)
	.dw Pole+13+(256*5)
	.dw Pole+14+(256*7)
	.dw Pole+13+(256*9)
	.dw Pole+14+(256*11)
	.dw Pole+13+(256*13)
	.dw Pole+14+(256*15)
	.dw Pole+13+(256*17)
	.dw Pole+14+(256*19)
.endif
