  .include "add_def.S"
  .include "add_scr.S"
  
  .section .text.sluzby
  .globl GetRandom,SetIO,Chirp,KbdOvladac,MouseKeyReleaseModA,MouseKeyReleaseModB,MouseKeyReleaseModC,SetMouseWindow
  .globl InitProg,NastavHru,MouseKeyRelease,ZobrazPocetZbylychMin,KeyRelease,TestNaRekord,ZapisRekord,Chirp2
  ;.globl
; ******************************************
; Inicializace proměnných po startu programu
; ******************************************
InitProg:
	xor a
.if OSS_USE
  inc a
  inc a
.endif
	ld (PoleSize),a		; výchozí velikost hracího pole
.if OSS_USE
	xor a
.endif
.if INIT_EMU_MOUSE
	inc a
.endif
	ld (MysSensitivity),a	; výchozí nastavení myši
.if INIT_COLORACE
	ld a,3
.else
	ld a,0
.endif
	ld (ColorMode),a		; výchozí barevný režim
	 jp SetPal
; ***************************************************
; Nastavení proměnné hry včetně rozměrů minového pole
; ***************************************************
NastavHru:
	ld a,(PoleSize)
	ld hl,tbNastaveniHry
	rst 0x18
	ld de,F_Left		; 1. sadu proměnných
	ld c,16
	rst 0x08; zkopírovat
	ld de,VolnychBunek	; 2. sadu proměnných
	ld c,16
	rst 0x08; zkopírovat
	xor a		; vynulovat čas a aktivovat hru
	;mvi a,9
	ld (Time+0),a
	ld (Time+1),a
	;xra a
	ld (Time+2),a
	ld a,2		; předdělička 500ms
	ld (Time+3),a
	ld (TimeRun),a	; čas běží
	ld (GameOver),a	; hra běží
	ret
tbNastaveniHry:
	.dw NastaveniHry0,NastaveniHry1,NastaveniHry2
NastaveniHry0:
	.db 7		;  7 = číslo první buňky zleva
	.db 16		; 16 = číslo poslední buňky +1
	.db 4		;  4 = číslo první buňky shora
	.db 13		; 13 = číslo poslední buňky +1
	.dw POCET_MIN_L0
			; počet min ve hře
	.dw 0d013h	; pozice tisku času v záhlaví
	.dw 0d00ah	; pozice tisku zbylých min v záhlaví
	.db 136		; pixelová pozice obličeje X
	.db 62		; pixelová pozice obličeje Y
	.dw 0cf16h	; adresa obličeje ve videoram
	.dw 0cd1ah	; adresa času ve videoram
	.dw 9*9-POCET_MIN_L0
			; počet volných buněk
NastaveniHry1:
	.db 4		;  4 = číslo první buňky zleva
	.db 19		; 19 = číslo poslední buňky +1
	.db 0		;  0 = číslo první buňky shora
	.db 15		; 15 = číslo poslední buňky +1
	.dw POCET_MIN_L1
			; počet min ve hře
	.dw 0c217h	; pozice tisku času v záhlaví
	.dw 0c206h	; pozice tisku zbylých min v záhlaví
	.db 136		; pixelová pozice obličeje X
	.db 6		; pixelová pozice obličeje Y
	.dw 0c116h	; adresa obličeje ve videoram
	.dw 0bf20h	; adresa času ve videoram
	.dw 15*15-POCET_MIN_L1
			; počet volných buněk
NastaveniHry2:
	.db 1		;  1 = číslo první buňky zleva
	.db 22		; 22 = číslo poslední buňky +1
	.db 0		;  0 = číslo první buňky shora
	.db 16		; 16 = číslo poslední buňky +1
	.dw POCET_MIN_L2
			; počet min ve hře
	.dw 0c21bh	; pozice tisku času v záhlaví
	.dw 0c202h	; pozice tisku zbylých min v záhlaví
	.db 136		; pixelová pozice obličeje X
	.db 6		; pixelová pozice obličeje Y
	.dw 0c116h	; adresa obličeje ve videoram
	.dw 0bf26h	; adresa času ve videoram
	.dw 21*16-POCET_MIN_L2
			; počet volných buněk
; *****************************************
; Nastaví pohybové limity myši podle LEVELu
; *****************************************
SetMouseWindow:
	ld a,(PoleSize)		; načte kód LEVELu 0..2
	add a,a
	add a,a
	add a,a
	ld hl,tbMysichDorazu	; z tabulky limitů souřadnic
	rst 0x10
	push hl
	ld de,MysXMin		; do aktuálních limitů myši
	ld c,8			; o délce 8 bajtů
	rst 0x08; nakopíruje data
	pop hl
	ld bc,14
	call AddOfsetToHL
	ld (MysX),hl
	ex de,hl
	inc hl
	inc hl
	inc hl
	ld bc,27
	call AddOfsetToHL
	ld (MysY),hl
	ret
AddOfsetToHL:
	ld e,(hl)
	inc hl
	ld d,(hl)
	ex de,hl
	add hl,bc
	ret
	
tbMysichDorazu:	
	.dw 83,198,59,199	; Xmin,Xmax,Ymin,Ymax pro 9x9
	.dw 47,234,3,227	; Xmin,Xmax,Ymin,Ymax pro 15x15
	.dw 11,270,3,241	; Xmin,Xmax,Ymin,Ymax pro 21x16
; ****************************************************
; Počká na uvolnění všech kláves v aktivovaném sloupci
; ****************************************************
KeyRelease:
	ld bc,1000	; klávesa musí být uvolněna
KeyReleaseWait:
	in a,(kbdin)	; načíst řádkové odezvy klávesnice
	or 80h		; odmaskovat nevyužitý bit
	inc a		; test na všechny řádky nestisknuty
	jp nz,KeyRelease	; něco je stisknuto, čekám na uvolnění
	dec bc		; nic není stisknuto,
	ld a,b		; odpočítávám požadovanou dobu
	or c		; pro detekci defitivního uvolnění
	jp nz,KeyReleaseWait ; všech kláves ve vybraném sloupci
	ret
; ****************************************************
; Počká na uvolnění myších tlačítek, zatímco čas plyne
; ****************************************************
MouseKeyRelease:
	ld bc,200	; tlačítka musí být uvolněna
MouseKeyReleaseWait:
	in a,(kbdin)	; STOPka vládne všem
	add a,a
	ret p
	in a,(uartcwr)	; test plynutí času
	and 4
	call nz,ZmenaCasu
	in a,(mysport)	; načíst stav tlačítek myši
MouseKeyReleaseModA:
	and 0c0h	; odmaskovat nevyužité bity
	jp nz,MouseKeyRelease
	ld a,0dh	; test DEL aka L tlačítko
	out (kbdout),a
	in a,(kbdin)
MouseKeyReleaseModB:
	and 2
	jp z,MouseKeyRelease
	ld a,0eh	; test CLR aka P tlačítko
	out (kbdout),a
	in a,(kbdin)
MouseKeyReleaseModC:
	and 2
	jp z,MouseKeyRelease
			; něco je stisknuto, čekám na uvolnění
	dec bc		; nic není stisknuto,
	ld a,b		; odpočítávám požadovanou dobu
	or c		; pro detekci defitivního uvolnění
	jp nz,MouseKeyReleaseWait
			; všech kláves ve vybraném sloupci
	ret
; ******************************************************
; Zobrazí počet zbylých min do stavového řádku (záhlaví)
; ******************************************************
ZobrazPocetZbylychMin:
	ld a,10
	call SetCol
	ld hl,(PozicePoctuMin)
	ld (Prnpos),hl
	ld hl,(ZbytekMin)
	ld a,h
	and a
	ld a,_SPC
	jp p,ZobrazPocetKladnychMin
	call NegHL
	ld a,_MIN
ZobrazPocetKladnychMin:
	call prtchr	; případné znaménko
	ld de,100
	rst 0x20
	jp c,ZobrazPocetMin99
	ld hl,99
ZobrazPocetMin99:
	ld h,l
	call b7bcd
	push af
	call pr6_hi
	pop af
	 jp pr6_lo
; *****************************************
; omezený převod 8-bitového binárního čísla
; z reg. H na BCD číslo v reg. A (00..99)
; *****************************************
; vstup:  H = binární číslo (00h..63h)
; výstup: A = BCD hodnota (00..99)
; *****************************************
b7bcd:	ld b,7		; převádím 7-bitové číslo
	xor a		; příprava akumulátoru výsledku
	add hl,hl
cykl7:	add hl,hl		; posun H vlevo, CY = H[7]
	adc a,a		; A := 2 x A + CY
	daa		; dekadická korekce
	dec b
	jp nz,cykl7	; NEXT bit
	ret
; *********
; Negace HL
; *********
NegHL:
	ld a,h		; výpočet dvojkového doplňku HL
	cpl		; neboli násobení krát (-1)
	ld h,a
	ld a,l
	cpl
	ld l,a
	inc hl
	ret
; ****************************************
; Nabourání sekvence pseudonáhodných čísel
; ****************************************
  .globl MoreRandom
MoreRandom:
	push hl
	ld hl,Randomize+1
	in a,(ctc2ch)	; podle sekundového čítače T2
	xor (hl)		; XORuj doplňkový faktor náhody
	inc a
	ld (hl),a
	pop hl
	ret
; ***************************************************
; Generátor pseudonáhodných čísel (16-bitový registr)
; zpětnovazební polynom: X[16]+X[15]+X[13]+X[4]+1
; maska výpočtu polynomu: 1101 0000 0000 1000 (D008h)
; ***************************************************
GetRandom:
	push bc		; i když by stačil 8-bitový generátor,
	push hl		; kvůli delších sekvencí použiju ten
RandomNumber:		; 16-bitový
	ld hl,0		; z předchozího čísla
	ld a,h		; z vyššího bajtu
	and 0d0h	; vypočtu hodnotu dílčího
	ld b,a		; polynomu a uložím ji do B
	ld a,l		; rovněž z nižšího bajtu
	and 008h	; vypočtu dílčí polynom
	xor b		; a sloučím z mezivýsledkem z B
	add hl,hl		; předchozí číslo v HL posouvám vlevo
	jp po,rnd16c	; a hodnotu celého generujícího polynomu
	inc hl		; nasunu do registru HL zprava
rnd16c:	ld (RandomNumber+1),hl
			; uložím novou hodnotu čísla
	ld a,l		; používám jen LSB
Randomize:
	add a,0		; doplňkový faktor náhody
	pop hl
	pop bc
	ret
; *************************
; Úvodní inicializace portů
; *************************
SetIO:	ld hl,tbSetIO	; data pro inicializaci portů
SetIOLoop:
	ld a,(hl)		; načíst číslo portu
	inc hl		; posun na další bajt
	ld (SetIOPort+1),a	; číslo portu uložím do instrukce OUT
	inc a		; později vyhodnotím port 0ffh
	ld a,(hl)		; načtu hodnotu pro zápis na port
	inc hl		; posun na další bajt
SetIOPort:
	out (0ffh),a	; vlastní zápis na zvolený port
	jp nz,SetIOLoop	; pokud nebyl port 0ffh, jedu dál
	ret		; (port 0ffh je většinou neobsazen,
			; takže poslední zápis na něj nevadí)
tbSetIO:
	.db kbdcwr,82h	; AllRAM režim
	.db ctccwr,076h	; režim čítače T1 8253
	.db ctc1ch,0abh	; LO(1200Hz)
	.db ctc1ch,006h	; HI(1200Hz)
	.db ctccwr,094h	; režim čítače T2 8253
	.db ctc2ch,000h	; LSB only, MODE#3, BIN
	.db uartcwr,80h	; sekvence reset UARTu 8251
	.db uartcwr,80h	; sekvence reset UARTu 8251
	.db uartcwr,40h	; sekvence reset UARTu 8251
	.db uartcwr,13h	; timeout 480ms
	.db uartcwr,23h	; povolit handshake
	.db uartdat,00h	; prvotní start vysílače
	.db 0ffh	; konec seznamu portů
; *******************************************************
; Porovná dosažený čas s rekordem pro danou velikost pole
; vstup: proměnná Time = dosažený čas
;        proměnná PoleSize = velikost pole
; výstup: DE = ukazatel na rekord
;         CY=1 => nový rekord
; *******************************************************
TestNaRekord:
	ld a,(PoleSize)		; podle velikosti minového pole
	dec a			; vyberu do DE adresu
	ld de,txtBestP1Time	; se záznamem času
	jp m,TestNaRekordSrovnej
	ld de,txtBestP2Time
	jp z,TestNaRekordSrovnej
	ld de,txtBestP3Time
TestNaRekordSrovnej:
	ld h,d			; záloha pro kopírování času
	ld l,e
	ld bc,Time		; vlastní test podkročení času
	ld a,(bc)
	cp (hl)
	ret nz
	inc hl
	inc bc
	ld a,(bc)
	cp (hl)
	ret nz
	inc hl
	inc bc
	ld a,(bc)
	cp (hl)
	ret
; ***********************************
; Zapíše rekord a edituje jméno hráče
; ***********************************
ZapisRekord:
	ld hl,Time		; zkopíruje čas od HL
	ld c,3			; na adresu DE
	rst 0x08; v délce 3 znaky
	call ZadejJmeno		; edituje jméno do buferu
	ld a,(PoleSize)		; vybere adresu jména
	dec a			; podle velikosti minového pole
	ld de,txtBestP1Name
	jp m,ZapisRekordCopy
	ld de,txtBestP2Name
	jp z,ZapisRekordCopy
	ld de,txtBestP3Name
ZapisRekordCopy:
	ld hl,txtJmeno		; a zkopíruje
	ld c,6			; 6 znaků
	rst 0x08; z buferu do vybraného jména
	ret
; ***********************************
; Alternativní ovladač hry klávesnicí
; ***********************************
KbdOvladac:
	xor a			; překreslování kurzoru bude
	ld (MysXCHG),a		; řešeno zde, proto vynuluji
				; signalizaci "změna pozice"
	call KbdOvladacInkey	; čtení klávesnice s funkcí
	inc a			; autorepeat
	ld hl,tbKbdOvladac	; převést na adresu obslužné
	rst 0x18; rutiny
	jp (hl)			; a tuto zavolat
	
tbKbdOvladac:
	.dw KbdOvladacNull	; FFh => žádná klávesa
	.dw KbdOvladacLeft	; 00h => kurzor vlevo
	.dw KbdOvladacRight	; 01h => kurzor vpravo
	.dw KbdOvladacUp	; 02h => kurzor nahoru
	.dw KbdOvladacDown	; 03h => kurzor dolů
KbdOvladacLeft:
	ld hl,(MysXMin)		; DE = Xmin+6
	ld bc,6
	add hl,bc
	ex de,hl
	ld hl,(MysX)		; posun o 12 pix vlevo
	ld bc,-12
	add hl,bc
	rst 0x20; jsem v minovém poli?
	jp c,KbdOvladacNull	; NE => test L+P "tlačítka"
KbdOvladacHorizontal:
	ld (MysX),hl		; ANO => uložit novou pozici
KbdOvladacVertical:
	call Chirp		; ještě zvuk
	rst 0x30; vypnout kurzor myši
	rst 0x38; a zapnout jej na nové pozici
KbdOvladacNull:
	ld hl,0d02h		; test DELETE (=L tlačítko)
	rst 0x28
	ld c,0x40
	jp z,KbdOvladacButton
	ld hl,0e02h		; test CLR (=P tlačítko)
	rst 0x28
	ld c,0x80
	jp z,KbdOvladacButton
	ld c,0
KbdOvladacButton:
	ld a,c			; ven z ovladače dodám stav
	add a,a			; simulovaných tlačítek L+P
	ret
KbdOvladacRight:
	ld hl,(MysXMax)		; DE = Xmax
	ex de,hl
	ld hl,(MysX)		; posun o 12 pixelů vpravo
	ld bc,12
	add hl,bc
	rst 0x20; jsem v minovém poli?
	jp nc,KbdOvladacNull	; NE => test L+P "tlačítka"
	 jp KbdOvladacHorizontal
KbdOvladacUp:
	ld hl,(MysYMin)		; totéž pro kurzor nahoru
	ld bc,20
	add hl,bc
	ex de,hl
	ld hl,(MysY)
	ld bc,-14
	add hl,bc
	rst 0x20
	jp c,KbdOvladacNull
	ld (MysY),hl
	 jp KbdOvladacVertical
KbdOvladacDown:
	ld hl,(MysYMax)		; totéž pro kurzor dolů
	ex de,hl
	ld hl,(MysY)
	ld bc,14
	add hl,bc
	rst 0x20
	jp nc,KbdOvladacNull
	ld (MysY),hl
	 jp KbdOvladacVertical
; **********************************************
; Ovladač klávesnice včetně funkce autorepeat.
; V ACC vrací kód klávesy 0..3 nebo 0FFh (NoKey)
; **********************************************
KbdOvladacInkey:
	call KbdOvladaniScan
			; základní scan klávesnice
	ld a,b
	cp 0ffh	; byl stisk?
	jp nz,KbdOvladacPress
			; něco bylo stisknuto
	ld hl,RptKad	; záplata pro ruční fast repeat
	ld a,(hl)
	and a
	ld a,0ffh
	ret z
	dec (hl)
	ret nz
	ld (KbdOvladacPress+1),a
			; LastKey = NoKey
	ret
KbdOvladacPress:
	cp 0		; trvá stisk klávesy?
	ld hl,RptDly
	jp z,KbdOvladacRepeat
			; pak běž na autorepeat
	ld (KbdOvladacPress+1),a
			; když je změna, LastKey = NewKey
	ld (hl),KBDCTRL_DLY
			; spustit čekání na AUTOREPEAT
	ld hl,RptKad
	ld (hl),KBDCTRL_KAD
			; kadence AUTOREPEATu
			; ACC = platný znak - initial press
	ret
KbdOvladacRepeat:
	ld a,0ffh	; dokud není čas, znak se negeneruje
	dec (hl)		; odpočet doby po initial press
	ret nz		; čekám na uplynutí initial pause
	inc (hl)		; pak už udržuju čítač na hodnotě 1
	ld hl,RptKad
	dec (hl)		; rychlost autorepeatu
	ret nz		; mezi autorepeat-znaky negeneruji nic
	ld (hl),KBDCTRL_KAD
			; reload autorepeat kadence
	ld a,(KbdOvladacPress+1)
			; a vrátím platný znak (fce autorepeat)
	ret
; **********************
; Test klávesnice
; výstup: B: kód klávesy
;         00: vlevo
;         01: vpravo
;         02: nahoru
;         02: dolů
;         FF: nic
; **********************
KbdOvladaniScan:
	ld b,150
KbdOvladaniScanDelay:
	dec b
	jp nz,KbdOvladaniScanDelay
	dec b		; B:=0FFh aka no key
	ld hl,0c04h	; test šipky vlevo
	rst 0x28
	ld c,0
	call z,KbdOvladacNastav
	ld hl,0e04h	; test šipky vpravo
	rst 0x28
	ld c,1
	call z,KbdOvladacNastav
	ld hl,0d04h	; test HOME jako nahoru
	rst 0x28
	ld c,2
	call z,KbdOvladacNastav
	ld hl,0c08h	; test LNLEFT jako nahoru
	rst 0x28
	ld c,2
	call z,KbdOvladacNastav
	ld hl,0d08h	; test END jako dolů
	rst 0x28
	ld c,3
	call z,KbdOvladacNastav
	ld hl,0e08h	; test LNRIGHT jako dolů
	rst 0x28
	ld c,3
	call z,KbdOvladacNastav
	ret
KbdOvladacNastav:
	ld b,c		; zachytím kód stisknuté klávesy
	ret
; *********************
; kliknutí při TIMEOUTu
; *********************
Chirp2:
	push bc
	ld bc,20000
	 jp ChirpCommon
; ***************************
; kliknutí při stisku klávesy
; ***************************
Chirp:
	push bc
	ld bc,256
ChirpCommon:
	push af
	ld a,3
	out (kbdcwr),a
ChirpDelay:
	dec bc
	ld a,b
	or c
	jp nz,ChirpDelay
	ld a,2
	out (kbdcwr),a
	pop af
	pop bc
	ret
