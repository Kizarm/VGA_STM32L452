; ******************************
; Spouštěcí sekvence vlastní hry
; ******************************
  .include "add_def.S"
  .section .text.hra
  .globl Ovladani,NovaHra, Start

Start:
  call SetIO      ; inicializace portů
  call InitProg   ; inicializace programu
SpustMenu:
  call DoMenu   ; úvodní MENU
  call Cls      ; výmaz obrazovky
  call SetMouseWindow ; nastaví dorazy myšího kurzoru
  ld   a,(PoleSize)   ; dle velikosti minového pole
  call ZobrazSestavu  ; vykreslí okolní rámeček
  call MysDPISet      ; nastavit citlivost myši

NovaHra:
	call NastavHru		; nastaví proměnné hry
	ld hl,(AdresaObliceje)	; zobraz std obličej
	ex de,hl			; DE = adresa ve videoram
	ld hl,ImgTrueOblicej	; HL = předloha ikony
	call ShowImage		; vlastní zobrazení ikony
	call InitPole		; generování minového pole
	call ZobrazPole		; vykreslí hrací pole
	out (uartdat),a		; restart časovače 0,5s
	call TiskCasuOutside	; a tisk času bez kolize
				; s myším kurzorem
	call ZobrazPocetZbylychMin
				; tisk do záhlaví
SmyckaHryMysOn:
	rst 0x38; aktivuje kurzor myši
; *************************************
; Hlavní smyčka hry. Hráč jezdí s myší,
; čeká se na klik myši nebo stisk STOP
; *************************************
SmyckaHry:
	call MoreRandom	; průběžně míchám s generátorem náhod 
	ld hl,(VolnychBunek)
	ld a,h
	or l		; po prokliknutí všech volných buněk
	jp z,Vyhra	; následuje výhra
	ld a,1		; test klávesy K1 aka F2
	out (kbdout),a
	in a,(kbdin)
	rra
	jp nc,PressF2	; vyvolá restart hry
	and 20h		; test klávesy STOP
	jp z,SpustMenu	; při stisku skok do hlavního menu
Ovladani:
	call MysDriver	; ježdění s myší/klávesnicí
	push af	; stav tlačítek uschovat (je nutno
	ld a,(MysXCHG)	; použít stav z procedury MysDriver,
	and a		; protože koresponduje s přerušením
	jp z,BezPohybu	; obsluhy myši)
	rst 0x30; vypne kurzor myši
	rst 0x38; a zapne jej na nové pozici
BezPohybu:
	pop af		; obnovit stav tlačítek myši
	jp m,ClickLeft	; stisk L tlačítka myši => obsluha
	jp c,ClickRight	; stisk P tlačítka myši => obsluha
	in a,(uartcwr)	; uplynulo 0,5sec?
	and 4
	call nz,ZmenaCasu	; pokud ano, ošetřit časomíru
	 jp SmyckaHry	; a jezdit ve smyčce..
; ************************************
; Ošetření stisku levého tlačítka myši
; ************************************
ClickLeft:
	call TestNaObliceji	; L klik na obličej?
	jp c,Click2Face		; ANO => restart hry
	ld a,(GameOver)		; příznak GameOver
	and a			; otestuji
	jp z,ClickRelease		; hra skončila => odskok
	call DetekujBunku 	; do HL vybere adresu buňky
	jp c,ClickRelease		; nebyl klik do minového pole
	ld a,(hl)			; kliknul jsem do minového pole
	and 70h			; test odhalenosti buňky
	jp nz,ClickLeftGroup	; vlajky a otazníky
	ld a,(MysSensitivity)	; při ovládání klávesnicí pípne
	and a
	call z,Chirp
	call KlikNaBunku	; animuje kliknutí + test
	jp m,Smrt			; je tam mina => smrt
				; není tam mina =>
	call OdkryjMinovePole	; odhalím část minového pole
	 jp SmyckaHryMysOn	; vracím se k čekání na klik 
; *******************************************
; Kliknutí levým tlačítkem na odhalenou buňku
; *******************************************
ClickLeftGroup:
	and 40h			; je-li atribut odhalení
	jp z,ClickRelease		; neaktivní => konec
	call OtestujOkoli	; otestuje okolí buňky
	ld a,(PocetMin)		; je počet okolních vlajek
	ld c,a
	ld a,(hl)
	and 0fh
	cp c			; roven počtu fyzických min?
	jp nz,ClickRelease	; NE => ignoruj stisk
	ld a,(PocetSousedu)	; je vůbec ještě co v okolí
	and a			; odhalovat?
	jp z,ClickRelease		; NE => ignoruj stisk
	ld a,(MysSensitivity)	; při ovládání klávesnicí pípne
	and a
	call z,Chirp
	rst 0x30; vypne kurzor myši
	ld hl,(AdresaObliceje)	; zobraz obličej "ó"
	ld de,1+(10*64)
	add hl,de
	ex de,hl			; DE = adresa ve videoram
	ld hl,ImgOblicejOOO	; HL = předloha ikony
	call ShowImage		; vlastní zobrazení ikony
	ld a,(PocetSousedu)	; podle počtu neodhalených
	ld c,a			; sousedů
	ld hl,SeznamSousedu	; bere tyto ze seznamu
HromadnyKlik:
	ld e,(hl)			; a na jejich pozici
	inc hl
	ld d,(hl)
	inc hl
	push hl
	ex de,hl
	ld a,0x30		; ikonu "prokliknuté" buňky
	call ZobrazBunku	; zobrazí
	pop hl
	dec c			; další soused ze seznamu
	jp nz,HromadnyKlik
	rst 0x38; pak zapne kurzor myši
	call MouseKeyRelease	; počkat na uvolnění tlačítka
	rst 0x30; vypne kurzor myši
	ld a,(PocetSousedu)	; a pro všechny neodhalené
	ld c,a			; sousedy
	ld hl,SeznamSousedu	; ze seznamu
DalsiSoused:
	ld e,(hl)			; bere jejich pozice
	inc hl
	ld d,(hl)
	inc hl
	ld a,(de)			; a pokud jsem šlápnul na minu,
	and a
	jp m,SmrtDE		; vyvolá smrt,
	push bc
	push hl
	ex de,hl
	call OdkryjMinovePole	; jinak odhalí minové pole
	pop hl			; v okolí tohoto souseda
	pop bc
	dec c			; další soused ze seznamu
	jp nz,DalsiSoused
				; nic mě nezabilo, a tak..
	ld hl,(AdresaObliceje)	; std ikona obličeje
	ld de,1+(10*64)
	add hl,de
	ex de,hl			; DE = adresa ve videoram
	ld hl,ImgOblicejBack
	call ShowImage		; vlastní zobrazení ikony
	 jp SmyckaHryMysOn	; vracím se k čekání na klik 
; ***************************
; Stisk pravého tlačítka myši
; ***************************
ClickRight:
	ld a,(GameOver)		; příznak GameOver
	and a			; otestuji
	jp z,ClickRelease		; hra skončila => odskok
	call DetekujBunku	; do HL vybere adresu buňky
	jp c,ClickRelease		; nebyl click na buňku
	ld a,(hl)			; načtu stav buňky
	and 70h			; jen "odhalená" + status
	ld c,10h		; ikona vlajky
	ld de,-1		; a snížení počtu zbýv. min
	jp z,ZmenBunku		; následuje po prázdné buňce
	ld c,00h		; ikona prázdné buňky
	inc de			; a beze změny počtu zbýv. min
	cp 20h			; následuje po otazníku
	jp z,ZmenBunku
	ld c,20h		; ikona otazníku
	inc de			; a zvýšení počtu zbýv. min
	cp 10h			; následuje po vlajce
	jp nz,ClickRelease	; ostatní stavy buněk nereagují
 
ZmenBunku:
	ld a,(MysSensitivity)	; při ovládání klávesnicí pípne
	and a
	call z,Chirp
	push bc			; uschovat kód požadované ikony
	push hl			; uschovat adresu buňky
	ld hl,(ZbytekMin)		; korekce počtu zbývajících min
	add hl,de
	ld (ZbytekMin),hl
	call ZobrazPocetZbylychMin ; zobrazit počet zbýv. min
	rst 0x30; vypnout kurzor myši
	pop hl			; obnovit adresu buňky
	pop bc			; obnovit kód požadované ikony
	ld a,(hl)			; načíst starý stav buňky
	and 8fh			; vymazat starou ikonu
	or c			; vložit novou ikonu
	ld (hl),a			; zapsat zpět do minového pole
	call ZobrazBunku	; buňku vykreslit
	rst 0x38; zapnout kurzor myši
ClickRelease:
	call MouseKeyRelease	; čekat na uvolnění tlač. myši
	 jp SmyckaHry		; zpět do režimu ježdění s myší
; *************************************************
; Z pozice kurzoru myši určím index v minovém poli,
; otestuji na rozsah souřadnic pro daný level
; a vrátím ukazatel do minového pole
; *************************************************
DetekujBunku:
	ld hl,(MysY)
	inc hl		; korekce záměrného bodu dy = +1
	add hl,hl 
	add hl,hl 
	add hl,hl 
	add hl,hl 
	add hl,hl 
	add hl,hl
	ld a,h
	or 0c0h
	ld h,a
	push hl
	ld hl,(MysX)
	inc hl		; korekce záměrného bodu dx = +1
	ld a,h
	rra
	ld a,l
	rra
	ld l,a		; nejprve L := X/2
	ld h, tbPix2Adr >> 8
	ld e,(hl)		; DE := řádková adresa kurzoru myši
	ld d,0
	pop hl
	add hl,de
	;???;
	ld de, -PlayArea	; koriguji LH rohem pole ve videoram
	add hl,de
	ld a,l		; D = vodorovný index buňky
	rra
	and 1fh
	ld d,a
	add hl,hl		; E = svislý index buňky
	add hl,hl
	ld a,h
	ld e,-1
DetekujBunkuY:
	inc e
	sub 14
	jp nc,DetekujBunkuY
	ld hl,(F_Left)	; test validity vodorovné pozice
	ld a,d
	cp l
	ret c
	cp h
	ccf
	ret c
	ld hl,(F_Up)	; test validity svislé pozice
	ld a,e
	cp l
	ret c
	cp h
	ccf
	ret c
	ld hl,Pole	; přepočet indexů na adresu pole
	add hl,de
	ret
; **************************************************
; Test pozice kurzoru myši, zda je na ikoně obličeje
; výstup: CY=0 => nejsem na obličeji
; **************************************************
TestNaObliceji:
	ld hl,(PoziceObliceje)
	ex de,hl		; DE = levý horní roh ikony obličeje
	ld hl,1110h	; 16 pixelů na šířku, 17 na výšku
	add hl,de		; BC = pravý horní roh ikony +1/+1
	ld b,h
	ld c,l
	ld hl,(MysX)	; test pozice X
	inc hl		; korekce záměrného bodu
	ld a,h
	and a
	ret nz		; MSB<>0
	ld a,l
	cp e
	ccf
	ret nc		; kurzor příliš vlevo
	cp c
	ret nc		; kurzor příliš vpravo
	ld hl,(MysY)	; test pozice Y
	inc hl		; korekce záměrného bodu
	ld a,h
	and a
	ret nz		; MSB<>0
	ld a,l
	cp d
	ccf
	ret nc		; kurzor příliš nahoře
	cp b
	ret		; kurzor příliš dole nebo OK
; *************************************************
; Prokliknutí buňky, čekání na release, čtení stavu
; *************************************************
KlikNaBunku:
	push hl			; uschovat adresu buňky
	rst 0x30; vypne kurzor myši
	ld hl,(AdresaObliceje)	; zobraz obličej "ó"
	ld de,1+(10*64)
	add hl,de
	ex de,hl			; DE = adresa ve videoram
	ld hl,ImgOblicejOOO	; HL = předloha ikony
	call ShowImage		; vlastní zobrazení ikony
	pop hl			; obnovit adresu buňky
	ld a,0x30		; ikona "prokliknuté" buňky
	call ZobrazBunku	; zobrazit ji
	push hl			; uschovat adresu buňky
	rst 0x38; zapnout kurzor myši
	call MouseKeyRelease	; počkat na uvolnění tlačítka
	ld hl,(AdresaObliceje)	; zobraz obličej "ó"
	ld de,1+(10*64)
	add hl,de
	ex de,hl			; DE = adresa ve videoram
	ld hl,ImgOblicejBack
	call ShowImage		; vlastní zobrazení ikony
	rst 0x30; nyní vypnu kurzor myši, neboť
				; - buď končí hra neúspěchem
				; - budu dlouho odhalovat buňky
	pop hl			; obnovit adresu vybrané buňky
	ld a,(hl)			; načíst stav buňky
	and a			; test její hodnoty
	ret
; *********************************************
; Kliknul jsem na ikonu obličeje => restart hry
; *********************************************
Click2Face:
	call StopGame		; zastav hru (vč. času)
	rst 0x30; vypni kurzor myši
	call InvertFace		; inverze obličeje
	rst 0x38; zapni kurzor myši
	call MouseKeyRelease	; čekej na uvolnění L tlačítka
	rst 0x30; vypni kurzor myši
	 jp NovaHra		; restart hry
; ***************************
; Stisk K1/F2 pro restart hry
; ***************************
PressF2:
	rst 0x30; zhasne kurzor myši
	call StopGame		; zastav hru (vč. času)
	call KeyRelease		; počká na uvolnění kláves
	 jp NovaHra		; restart hry
; *********************************************
; Smrt - šlápnul jsem na minu
; prefix pro volání z hromadného odhalení buněk
; *********************************************
SmrtDE:
	ex de,hl
; ***************************
; Smrt - šlápnul jsem na minu
; ***************************
Smrt:	ld (hl),0x4B		; kód smrtící miny
	call StopGame		; zastavím hru vč. času
	ld hl,(AdresaObliceje)	; zobraz obličej "ó"
	ld de,1+(6*64)
	add hl,de
	ex de,hl			; DE = adresa ve videoram
	ld hl,ImgOblicejBad
	call ShowImage		; vlastní zobrazení ikony
	call KontrolaPole	; korekce chyb
	call ZobrazPole		; zobrazení pole
	 jp SmyckaHryMysOn	; zapnout kurzor myši a čekat
				; na restart obličejem
; ****************************************
; Výhra - odhalil jsem všechny volné buňky
; ****************************************
Vyhra:	rst 0x30
	call StopGame		; zastavím hru vč. času
	ld hl,(AdresaObliceje)	; zobraz obličej "ó"
	ld de,1+(6*64)
	add hl,de
	ex de,hl			; DE = adresa ve videoram
	ld hl,ImgOblicejHavaj
	call ShowImage		; vlastní zobrazení ikony
	call KontrolaPole	; korekce chyb
	call ZobrazPole		; zobrazení pole
	call TestNaRekord
	jp c,BylRekord
	ld hl,-1		; odblokovat mechanismus
	ld (VolnychBunek),hl	; pro ukončení hry
	 jp SmyckaHryMysOn	; zapnout kurzor myši a čekat
				; na restart obličejem	
BylRekord:
	call ZapisRekord
	 jp SpustMenu
