; ************************************************
; Datová struktura pole:
; 111XXXXX 0011YYYY	XXXXX: sloupec 0..23
;			 YYYY: řádek 0..15
; formát buněk:
; MOSSPPPP	   M: 0/1 = fyzicky přítomná mina
;                  O: 0/1 = již odhalená buňka
;		  SS: 0-3 = vizuální stav buňky
;                           (00: nestisknuto
;                            01: vlajka
;                            10: otazník
;                            11: stisknuto)
;               PPPP: 0-8 = počet min v okolí buňky nebo
;                           po konci hry typ miny
;                           (9: mina
;                           10: škrtnutá mina
;                           11: smrtící mina)
;
; předdefinované obtížnosti:
; 0: pole 9x9   - 10min
; 1: pole 15x15 - 34min
; 2: pole 21x16 - 60min
;
; pozn. Nastavené hrací pole se může vyskytovat
;       kdekoliv ve vyčleněné datové struktuře
;       a nemusí být zarovnáno k okrajům.
; ************************************************
; *********************************************
; Zobrazí minového pole dle nastavené velikosti
; *********************************************
.include "add_def.S"
  .section .text.blockworld
  .globl ZobrazPole,OdkryjMinovePole,OtestujOkoli,KontrolaPole,ZobrazBunku,ZobrazBunkuStd
ZobrazPole:
	ld hl,(F_Left)	; C = počet buněk na řádku
	ld a,h
	sub l
	ld c,a
	ld d,l		; D = index MSB buňky v LH rohu
	ld hl,(F_Up)	; B = počet buněk ve sloupci
	ld a,h
	sub l
	ld b,a
	ld e,l		; E = index LSB buňky v LH rohu
	ld hl,Pole	; HL = ukazatel na buňku
	add hl,de		;      v LH rohu použité části pole
ZobrazPoleX:
	push bc		; FOR X:= Xmin to Xmax
	push hl
ZobrazPoleY:
	ld a,(hl)		; FOR Y:= Ymin to Ymax
	call ZobrazBunku ; zobrazí bitmapu buňky
	inc l		; index pole Y++
	dec b		; odpočet výšky pole
	jp nz,ZobrazPoleY	; NEXT Y
	pop hl		; obnovit ukazatel pole
	pop bc		; obnovit rozměry pole 
	inc h		; index pole X++
	dec c		; odpočet šířky pole
	jp nz,ZobrazPoleX	; NEXT X
	ret
; *****************************************************
; Na konci hry vykreslí skutečnou podobu minového pole.
; Zvýrazní nesouhlas mezi vlajkami a minami.
; *****************************************************
KontrolaPole:
	ld hl,(F_Left)	; C = počet buněk na řádku
	ld a,h
	sub l
	ld c,a
	ld d,l		; D = index MSB buňky v LH rohu
	ld hl,(F_Up)	; B = počet buněk ve sloupci
	ld a,h
	sub l
	ld b,a
	ld e,l		; E = index LSB buňky v LH rohu
	ld hl,Pole	; HL = ukazatel na buňku
	add hl,de		;      v LH rohu použité části pole
KontrolaPoleX:
	push bc		; FOR X:= Xmin to Xmax
	push hl
KontrolaPoleY:
	ld a,(hl)		; FOR Y:= Ymin to Ymax
	add a,a		; je v buňce skutečná mina?
	jp c,KontrolaPoleMina ; => kontrola vlajky
	ld a,(hl)		; test označení vlajkou
	and 70h		; ponechat označení buňky
	cp 10h		; je to vlajka?
	jp z,KontrolaPoleVlajka ; => kontrola skutečné miny
	add a,a		; test na odhalené buňky
	jp m,KontrolaPoleZustava ; již odhalené buňky neřeším
	ld a,(hl)		; jinak je odhalím
	or 40h		; (nastavením atributu)
KontrolaPoleKorekce:
	ld (hl),a		; zápis stavu buňky po případné korekci
KontrolaPoleZustava:
	inc l		; index pole Y++
	dec b		; odpočet výšky pole
	jp nz,KontrolaPoleY ; NEXT Y
	pop hl		; obnovit ukazatel pole
	pop bc		; obnovit rozměry pole 
	inc h		; index pole X++
	dec c		; odpočet šířky pole
	jp nz,KontrolaPoleX ; NEXT X
	ret
KontrolaPoleMina:
	ld a,(hl)			; je v buňce (..s minou)
	and 30h
	cp 10h			; vlajka?
	jp z,KontrolaPoleZustava	; ANO => pak jdi na další pole
	ld a,0x49		; NE => vyznač korekci
	 jp KontrolaPoleKorekce
KontrolaPoleVlajka:
	ld a,0x4A		; mina pod vlajkou není (to je
				; vyloučeno předchozím testem)
	 jp KontrolaPoleKorekce	; proto udělám korekci
				; a vložím škrtnutou minu
; **********************************************************
; Zobrazí buňku
; vstup: ACC = kód buňky
;         HL = adresa buňky v datové struktuře minového pole
; **********************************************************
ZobrazBunku:
	push bc		; uschovat registry do zásobníku
	push de
	push hl
	ex de,hl
	ld hl,0		; uschovat SP
	add hl,sp
	ld (ZobrazBunkuSP+1),hl
	add a,a		; test na odkrytou buňku
	jp m,ZobrazBunkuOdkrytou
			; ODKRYTÁ => přímo zobraz potisk
	rra		; NEODKRYTÁ => přepočítej číslo
	rra		;              obrázku na buňce
	rra		;              a pak překresli buňku
	rra
	and 6
	add a,24
ZobrazBunkuOdkrytou:
	and 1eh		; maska pro adresu s potiskem buňky
ZobrazBunkuStd:
	ld hl,0		; adresa sady textur buněk
	ld c,a
	ld b,0
	add hl,bc		; připočíst pořadí obrázku s potiskem
	ld a,(hl)		; načíst LSB adresy obrázku 
	inc hl
	ld h,(hl)		; načíst MSB adresy obrázku
	ld l,a		; zkompletovat adresu obrázku
	ld sp,hl		; SP = adresa potisku pro buňku
	ex de,hl		; HL = adresa v minovém poli
	ld a,h		; načíst číslo sloupce
	and 1fh		; ponechat jen funkční rozsah
	add a,a		; x2 (buňky jsou široké 2 bajty)
	ld e,a
	ld d,0		; DE = část adresy videoram od X
	ld a,l		; načíst číslo řádku
	and 0fh		; ponechat jen funkční rozsah
	add a,a		; x2 (přímý index do tabulky int16)
	ld c,a
	ld b,0		; BC = ofset v tabulce násobků 14-ti
	ld hl,tbVysekRadku ; buňky mají nekulatou výšku 14pix
	add hl,bc		; proto se násobení x14 řeší tabulkou
	ld a,(hl)		; načíst výškovou adresu buňky
	inc hl		; ve videoram
	ld h,(hl)
	ld l,a
	add hl,de		; přičíst šířkový příspěvek adresy
			; HL = komplet adresa buňky ve videoram
	ld de,63	; DE = řádkovač
	ld a,2		; počet opakování (7x2=14 mikrořádků)
ZobrazBunkuLoop:
	pop bc		; zkopírovat mikrořádek 0 nebo 7
	ld (hl),c
	inc hl
	ld (hl),b
	add hl,de
	pop bc		; zkopírovat mikrořádek 1 nebo 8
	ld (hl),c
	inc hl
	ld (hl),b
	add hl,de
	pop bc		; zkopírovat mikrořádek 2 nebo 9
	ld (hl),c
	inc hl
	ld (hl),b
	add hl,de
	pop bc		; zkopírovat mikrořádek 3 nebo 10
	ld (hl),c
	inc hl
	ld (hl),b
	add hl,de
	pop bc		; zkopírovat mikrořádek 4 nebo 11
	ld (hl),c
	inc hl
	ld (hl),b
	add hl,de
	pop bc		; zkopírovat mikrořádek 5 nebo 12
	ld (hl),c
	inc hl
	ld (hl),b
	add hl,de
	pop bc		; zkopírovat mikrořádek 6 nebo 13
	ld (hl),c
	inc hl
	ld (hl),b
	add hl,de
	dec a		; postupně dvě sedmice mikrořádků
	jp nz,ZobrazBunkuLoop
	
ZobrazBunkuSP:
	ld sp,0	; obnovit zásobník
	pop hl		; a registry procesoru
	pop de
	pop bc	
	ret
			; tabulka násobků 14pixelů na výšku
tbVysekRadku:
	.dw PlayArea+(0*14*64)
	.dw PlayArea+(1*14*64)
	.dw PlayArea+(2*14*64)
	.dw PlayArea+(3*14*64)
	.dw PlayArea+(4*14*64)
	.dw PlayArea+(5*14*64)
	.dw PlayArea+(6*14*64)
	.dw PlayArea+(7*14*64)
	.dw PlayArea+(8*14*64)
	.dw PlayArea+(9*14*64)
	.dw PlayArea+(10*14*64)
	.dw PlayArea+(11*14*64)
	.dw PlayArea+(12*14*64)
	.dw PlayArea+(13*14*64)
	.dw PlayArea+(14*14*64)
	.dw PlayArea+(15*14*64)
; ***********************************************
; Narazil jsem na ještě neodhalenou buňku
; a tak začnu podle pravidel odkrývat minové pole
; ***********************************************
OdkryjMinovePole:
	ld bc,0		; zarážku 0000h (konec seznamu)
	push bc		; uložím do zásobníku 
	ex de,hl		; B,C = rozsah buněk na řádku
	ld hl,(F_Left)	; D,E = rozsah buněk ve sloupci 
	ld b,h
	ld c,l
	ld hl,(F_Up)
	ex de,hl
	inc c		; korekce limitů pole pro testy sousedů
	dec b		; posunu dovnitř minového pole
	inc e		; (krajní buňky nemají vnější sousedy)
	dec d
			; začátek smyčky odkrývání
OdkryjPole:
	in a,(uartcwr)	; hlídám plynutí času
	and 4
	call nz,SafeZmenaCasu
	ld a,(hl)		; přečti stav buňky
	and a		; a otestuj
	jp nz,OdkryjPoleZobrazBunku
			; jsem na neodhalené neoznačené buňce
	ld a,h		; při testu L okolí kontrola
	and 1fh		; pozice buňky
	cp c		; zda nejsem v poli úplně vlevo
	jp c,OdkryjPoleL	; pokud ano, netestuji vlevo
	dec h		; jinak se posunu doleva
	push hl		; zapamatuji si adresu buňky [-1,0]
	inc h		; a vrátím se na původní pozici
OdkryjPoleL:
	cp b		; nejsem v poli úplně vpravo?
	jp nc,OdkryjPoleR	; pokud ano, netestuji vpravo
	inc h		; jinak se posunu doprava
	push hl		; zapamatuji si adresu buňky [+1,0]
	dec h		; a vrátím se na původní pozici
OdkryjPoleR:
	ld a,l		; nyní výškový test
	and 0fh		; z adresy vypreparuji index Y
	cp e		; porovnám s minimální hodnotou (horní)
	jp c,OdkryjPoleU	; na horním okraji bez horních sousedů 
	dec l		; u ostatních buněk se posunu nahoru
	push hl		; uschovám pozici buňky [0,-1]
	ld a,h		; nyní ještě test diagonální buňky LH
	and 1fh		; ponechím jen index X
	cp c		; porovnám s minimální hodnotou (levou)
	jp c,OdkryjPoleUL	; na levém okraji bez sousedů vlevo
	dec h		; jinak se ovšem posunu doleva
	push hl		; zapamatuji si adresu buňky [-1,-1]
	inc h		; a vrátím se na původní pozici
OdkryjPoleUL:
	cp b		; porovnám s max hodnotou (pravou+1)
	jp nc,OdkryjPoleUR ; na pravém okraji bez sousedů vpravo
	inc h		; jinak se ovšem posunu doprva
	push hl		; zapamatuji si adresu buňky [+1,-1]
	dec h		; a vrátím se na původní pozici
OdkryjPoleUR:
	inc l		; vrátím se na původní pozici [0,0]
OdkryjPoleU:
	ld a,l		; totéž v bleděmodrém pro test dolů..
	and 0fh
	cp d
	jp nc,OdkryjPoleD
	inc l
	push hl
	ld a,h
	and 1fh
	cp c
	jp c,OdkryjPoleDL
	dec h
	push hl
	inc h
OdkryjPoleDL:
	cp b
	jp nc,OdkryjPoleDR
	inc h
	push hl
	dec h
OdkryjPoleDR:
	dec l
OdkryjPoleD:
OdkryjPoleZobrazBunku:		; HL ukazuje na aktuální buňku
	ld a,(hl)			; přečtu její hodnotu
	and 70h			; a pokud je už odhalená,
	jp nz,OdkryjPoleDalsi	; zahodím ji a jdu na další..
	ld a,(hl)			; neodhalené buňce
	or 40h			; změním status na "odhalená"
	ld (hl),a			; stav buňky uložím
	call ZobrazBunku	; buňku překreslím na obrazovce
	ld hl,(VolnychBunek)	; snížím počet ještě
	dec hl			; neodhalených buněk
	ld (VolnychBunek),hl
OdkryjPoleDalsi:
	pop hl			; vyndám ze zásobníku adresu
	ld a,h			; další buňky, otestuji
	or l			; na nulovou hodnotu
	jp nz,OdkryjPole		; je-li nenulová, tedy platná,
				; odkryji ji a pokračuji z ní
	ret			; nalezená zarážka 0000h => end
; *******************************************************
; Analýza okolí vybrané buňky
; sečte okolní vlajky a vygeneruje seznam prázdných buněk
; *******************************************************
OtestujOkoli:
	xor a			; vynulovat
	ld (PocetMin),a		; počet fyzických min kolem
	ld (PocetSousedu),a	; a počet neodhalených sousedů
	push hl			; výpočet dorazů
	ld hl,(F_Left)		; HORIZ = (E+1)..(D)
	ex de,hl
	ld hl,(F_Up)		; VERT = (C+1)..(B)
	ld b,h			; (indexy jsou správně!!!)
	ld c,l
	pop hl
	inc e
	dec d
	inc c
	dec b
				; test trojice nad buňkou
	ld a,l			; z adresy buňky
	and 0fh			; vypreparuji index Y
	cp c			; test na horní okraj pole
	jp c,NescitejHorni	; nahoře nemám sousedy.. 
	dec l			; jinak se ovšem posunu nahoru
	call SectiRadek		; analyzuji tam buňky (3x) 
	inc l			; a vrátím se na původní pozici
NescitejHorni:
	call SectiRadek		; analýza buněk (3x) v úrovni 0
				; test trojice pod buňkou
	ld a,l			; z adresy buňky
	and 0fh			; vypreparuji index Y
	cp b			; test na spodní okraj pole
	jp nc,NescitejDolni	; dole namám sousedy..
	inc l			; jinak se ovšem posunu dolů
	call SectiRadek		; analyzuji tam buňky (3x) 
	dec l			; a vrátím se na původní pozici
NescitejDolni:
	ret	
				; analýza tří buněk na řádku
SectiRadek:			; nejprve analýza levé buňky
	ld a,h			; z adresy buňky
	and 1fh			; vypreparuji index X
	cp e			; test na levý okraj pole
	jp c,NescitejLevy		; vlevo nemám sousedy..
	dec h			; jinak se ovšem posunu doleva
	call AnalyzujBunku	; analyzuji tam buňku (jedinou)
	inc h			; a vrátím se na původní pozici
NescitejLevy:
	call AnalyzujBunku	; analýza střední buňky trojice
	ld a,h			; a nyní analýza pravé buňky
	and 1fh			; vypreparuji index X
	cp d			; test na pravý okraj pole
	ret nc			; vpravo nemám sousedy => konec
	inc h			; jinak se posunu doprava
	call AnalyzujBunku	; analyzuji tam buňku (jedinou)
	dec h			; a vrátím se na původní pozici
	ret
AnalyzujBunku:
	ld a,(hl)			; načtu hodnotu buňky
	and 70h			; nechám jen atribut "odhalená"
				; a případný stav vlajka/?
	call z,NeodkrytaBunka	; buňka je neodhalená => zapiš
	ld a,(hl)			; ještě test na počet vlajek
	and 70h			; nechám jen atribut "odhalená"
				; a případný stav vlajka/?
	cp 10h			; test na stav "vlajka"
	ret nz			; není vlajka => konec
	ld a,(PocetMin)		; s každou vlajkou v okolí
	inc a			; analyzované buňky zvednu
	ld (PocetMin),a		; počet předpokládaných min
	ret
NeodkrytaBunka:
	push de			; uschovat registry
	push hl
	ld a,(PocetSousedu)	; do seznamu neodhalených
	add a,a			; sousedů
	ld hl,SeznamSousedu
	rst 0x10
	pop de
	ld (hl),e			; přidám adresu analyzované
	inc hl			; buňky
	ld (hl),d
	ex de,hl
	pop de
	ld a,(PocetSousedu)	; a zvednu počet neodhalených
	inc a			; buněk v sousedství
	ld (PocetSousedu),a
	ret
