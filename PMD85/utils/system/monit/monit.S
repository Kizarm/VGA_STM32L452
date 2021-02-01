;	Tento výpis vznikl zpětným překladem paměti ROM,
;analýzou tohoto programu a doplněním komentáři na základě
;této analýzy.

;Autoři:
;	ing. Vít Libovický
;	     Jiří Olmer
/*
  Tato verze je upravena pro úspěšný překlad pomocí GNU binutils.
  Vzniklé binárky jsou plně kompatibilní s původními výpisy.
*/
;;;; Lze volit verzi 0x2A nebo 0x2 (2A nebo 2) ;;;;
MONVER .equ 0x2A
;========================================================
;		Kódy řídících kláves
;========================================================

CR	.equ	0DH	;omezovač textů

KSCLR	.equ	1	;SHIFT CLR
KEND	.equ	3	;END
KSCD	.equ	6	;SHIFT C-D
KSWRK	.equ	7	;SHIFT WRK
KLEFT	.equ	8	;<-
KSRRIGH	.equ	9	;SHIFT ->|
KSLLEFT	.equ	0AH	;SHIFT |<-
KWRK	.equ	0BH	;WRK
KHOME	.equ	0CH	;home
KEOL	.equ	0DH	;EOL
KSRCL	.equ	0EH	;SHIFT RCL
KPTL	.equ	0FH	;PTL
KSEND	.equ	10H	;SHIFT END
KSRIGHT	.equ	11H	;SHIFT ->
KSDEL	.equ	12H	;SHIFT DEL
KSLEFT	.equ	13H	;SHIFT <-
KRCL	.equ	17H	;SCL
KRIGHT	.equ	18H	;->
KRRIGHT	.equ	19H	;->|
KLLEFT	.equ	1AH	;|<-
KCLR	.equ	1BH	;CLR
KINS	.equ	1CH	;INS
KDEL	.equ	1DH	;DEL
KCD	.equ	1EH	;C-D
KSHOME	.equ	1FH	;SHIFT home



;========================================================
;		Pracovní oblasti v paměti RAM
;========================================================

BUF	.equ	0C030H	;začátek bufferu dial. řádku

DIAL	.equ	0C032H	;adr. zač. výpisu dial. řádku na displeji
DLZRAD	.equ	0C034H	;konec bufferu dial. řádku
DCUR	.equ	0C036H	;pozice kurzoru v bufferu
RPOS	.equ	0C038H	;první vypisovaný znak z bufferu na displej
COLOR	.equ	0C03AH	;kód barvy
BEEPPOS	.equ	0C03BH	;pozice v bufferu pro pípnutí
TAS00	.equ	0C03CH	;bývalé TASCII
CURSOR	.equ	0C03EH	;adresa kurzoru na displeji

SPVAL	.equ	0C070H	;adresa vrcholu zásobníku
CURCH	.equ	0C072H	;adresa nastavení při analýze bufferu
MESS	.equ	0C074H	;adresa začátku textu pro výpis
RETCLL	.equ	0C076H	;návratová adresa pro ENTER
ODLOZ	.equ	0C078H	;adresa pro uložení textu po EOL v ENTER
RETSP	.equ	0C07AH	;adresa zásobníku pro návrat z ENTER
SPEED	.equ	0C07CH	;konst. rychlosti pro seriové I/O v módu terminál
ITABDIR	.equ	0C07EH	;začátek tabulky příkazů monitoru

TASCII	.equ	0C0B0H	;tabulka adres tabulek tvarů znaků

RAM	.equ	0C0F0H	;návratový vektor po MGSV, MGLD a MGEND
IIROLL	.equ	0C0F4H	;adresy pro posun displeje
RSIRRAD	.equ	0C0F5H	;
POROLL	.equ	0C0F6H	;
CURROLL	.equ	0C0F8H	;
VYSKA	.equ	0C0FAH	;
ENLNW	.equ	0C0FBH	;
RADSIR	.equ	0C0FCH	;
DLZR	.equ	0C0FEH	;
DLZP	.equ	0C0FFH	;

BEEDT	.equ	0C130H	;adresa tabulky pro BEEP
KDIR	.equ	0C132H	;adresa tab. adres podprogramů pro kódy 00..1FH
ASCII	.equ	0C134H	;znak načtení z klávesnice
SWRK	.equ	0C135H	;příznak WRK
MGCHAR	.equ	0C136H	;typ souboru
SPTL	.equ	0C137H	;příznak PTL
MONX	.equ	0C138H	;návratová adresa pro JUMP
CDBUF	.equ	0C13AH	;adresa C-D buffer (text hlášení)
LSTR	.equ	0C13CH	;
STACK	.equ	0C13EH	;

X1	.equ	0C170H	;souřadnice X počátečního bodu
Y1	.equ	0C172H	;souřadnice Y počátečního bodu
LCHAR	.equ	0C173H	;
X2	.equ	0C173H	;souřadnice X koncového bodu
Y2	.equ	0C174H	;souřadnice Y koncového bodu
DCUROLD	.equ	0C175H	;
DELKA	.equ	0C177H	;
OLDKEY	.equ	0C178H	;
BCUR	.equ	0C17AH	;adresa kurzoru
KEYEND	.equ	0C17CH	;adresa klíčů
KEYTOP	.equ	0C17EH	;rádoby hranice paměti pro klíče

FINDNR	.equ	0C1B0H	;požadované číslo souboru
FINDTP	.equ	0C1B1H	;požadovaný typ souboru
HEAD	.equ	0C1B2H	;tabulka hlavičky souboru
NUMFIL	.equ	0C1B2H	;číslo souboru
TYPFIL	.equ	0C1B3H	;typ souboru
ADRFIL	.equ	0C1B4H	;adresa začátku dat souboru
LENFIL	.equ	0C1B6H	;délka souboru-1
NAMFIL	.equ	0C1B8H	;8 znaků názvu souboru, doplněno mezerami

OCHR	.equ	0C1F1H	;'*' => načten chránění soubor
POC	.equ	0C1F2H	;
VYSTUP	.equ	0C1F4H	;
PLOTCOL	.equ	0C1F8H	;
MODIFY	.equ	0C1FAH	;
FREQ	.equ	0C1FEH	;konstanta rychlosti pro magnetofon



;========================================================
;	ASEG
;	ORG     8000H
  .section .text.monit
  .globl START

START:	LD	SP,START	;Vstupní bod po RESET
	JP	MON		;nastavit PC na správnou adresu

MON:	LD	A,8AH		;PA, PC03 výstup, PB, PC47 vstup
	OUT	(0F7H),A	;nastavení systémové 8255
	CALL	OCHRAN		;pokus o utajení programů BASIC
;DE = INITAB

MONLL:	LD	HL,BUF		;začátek oblasti syst. proměnných
	LD	C,30H		;offset datových oblastí
	LD	A,08H		;počet oblastí
L8014:	PUSH	AF
	LD	B,10H 		;délka oblastí
L8017:	LD	A,(DE) 		;přenesení 16 bajtů z ROM do RAM
	LD	(HL),A
	INC	HL
	INC	DE
	DEC	B
	JP	NZ,L8017
	ADD	HL,BC		;adresovat další oblast
   	POP	AF
	DEC	A		;celé 8x
	JP	NZ,L8014

	LD	HL,(KEYEND)	;adresa tabulky klíčů
	DEC	HL
	LD	(HL),A		;ukončení tabulky klíčů 0

	CALL	PIO		;nastavit PIO v ROM-PACKu, smazat obrazovku
	CALL	ROMIN		;načtení prvních 13 bajtů z ROM-PACKu
  .dw	0,13,HEAD

	LD	A,(HEAD)	;1. bajt z ROM-PACKu
	CP	0CDH		;je to instrukce CALL?
	JP	Z,HEAD		;AN0 => spustit načtených 13 bajtů


MON1:	LD 	HL,L8424	;připravit text 'Os ready'
	LD 	(MESS),HL
	LD	A,'?'		;typ souboru: binární
	LD	(MGCHAR),A	;uložit typ
SYST3:	CALL 	CLR	 	;smazat editační řádek
PRBWTXT:
	CALL	PRBTXT	 	;pípnout, vypsat připravený text
	CALL	I82531	 	;inicializace 8253 a 8251
; 8253 nastaví mimo slyšitelné pásmo (64000 Hz)

	CALL 	INKLAV		;načtení klávesy
	CP	CR
	CALL	NZ,DOKEY	;vypsat znak do editačního řádku

SYST:	CALL	WRBUFF		;vypsat editační řádek
	LD	HL,(SPVAL)	;nastavit vrchol zásobníku
	LD      SP,HL
	CALL	L8BF1		;vstup řádky
	LD	HL,L8D87	;připravit text "No command"
	LD	(MESS),HL
	LD	HL,SYST		;připravit návratovou adresu
	PUSH	HL
	LD	HL,(ITABDIR)	;adresa tabulky příkazů
	EX	DE,HL		; do DE
L8072:	LD	HL,(ODLOZ)	;text vstupní řádky
L8075:	INC	DE
	LD	A,(DE)		;konec příkazu v tabulce?
	AND	A
	JP	Z,SYST1		;ANO => spustit příslušný podprogram
	CP	(HL)		;porovnat znak příkazu
	INC	HL
	JP	Z,L8075		;shodný znak => porovnat další
	INC	A		;test na konec tabulky příkazů
	JP	Z,SYST3		;konec => vypsat chybové hlášení

L8084:	LD	A,(DE)		;vyhledat konec slova v tabulce
	AND	A
	INC	DE
	JP	NZ,L8084
	INC	DE		;na začátek dalšího slova
	JP	L8072		;další porovnávání

;========================================================
;		Posun obrazu směrem vzhůru
;========================================================
; Tento podprogram nelze použít při povoleném přerušení!

ROLL:	LD	HL,0000H	;uložit SP
	ADD	HL,SP
	LD	(STACK),HL
	LD	HL,(RADSIR)	;rozteč textových řádků (9 linek)
	LD	BC,0C000H	;adresa začátku displeje
	ADD	HL,BC
	LD	SP,HL		;adresa pro čtení do SP!!!
	LD	HL,0C000H-1	;adresa pro zápis
	LD	A,(IIROLL)	;počet přenášených linek
L80A3:	LD	B,48/6		;počet cyklů

L80A5:	POP	DE		;načtení dvou bajtů z displeje
	INC	HL
	LD	(HL),E		;uložení bajtů do displeje
	INC	HL
	LD	(HL),D
	POP	DE		;další dva bajty
	INC	HL
	LD	(HL),E
	INC	HL
	LD	(HL),D
	POP	DE		;třetí dvojice bajtů
	INC	HL
	LD	(HL),E
	INC	HL
	LD	(HL),D
	DEC	B		;celkem přenést 48 bajtů
	JP	NZ,L80A5

	EX	DE,HL
	LD	HL,0010H	;SP adresovat na další zdrojový řádek
	ADD	HL,SP
	LD	SP,HL		;adresu do SP
	LD	HL,0010H	;HL adresovat na další cílový řádek
	ADD	HL,DE
	DEC	A		;snížit čítač linek
	JP	NZ,L80A3	;cykl

	LD	HL,(STACK)	;obnovit původní hodnotu SP
	LD	SP,HL
	LD	HL,(POROLL)	;adresa posledního textového řádku
	EX	DE,HL
	LD	A,(RSIRRAD)	;počet mazaných linek (9)
	LD	B,A
	LD	HL,(CURROLL)	;adresa pro psaní další řádky
	JP	L85B3		;smazat poslední textový řádek

;========================================================
BEPUK:	IN	A,(0F6H)	;invertovat bit zvuku a diody LED
	XOR	02H
	OUT	(0F6H),A
	RET

;========================================================
;	Vstupní šestnáctková konverze 4 bity
;========================================================
;CALL:	(HL) = ASCII kód převáděného znaku
;RET:	CY => není to šestnáctková číslice
;	NC => je to šestnáctková číslice,
;		A = 0..15

HEX1:	LD	A,(HL)
HEX:	CP	'0'		;je to číslice?
	RET	C		;NE
	CP	'9'+1		;je to číslice 0..9?
	JP	C,L80F1		;ANO
	SUB	7
	CP	'9'+1		;je to písmeno A..F?
	RET	C		;NE
	CP	'F'+1-7
	CCF
	RET	C		;NE
L80F1:	AND   00001111B
	RET

BEEPDT: .db	2,16		;tabulka dat pro BEEP
  .db	-1		;konec tabulky

;========================================================
; 	Vstupní šestnáctková konverze 8 bitů
;========================================================
;CALL:	HL = adresa textu: dvě šestnáctkové číslice
;RET:	CY => syntaktická chyba (špatný znak)
;	NC => oba znaky jsou správné
;		A = 0..255
;		HL = za druhý znak
;ruší:	HL, AF, B

PAIRIN:	CALL	HEX1		;načti 1. znak
	RET	C		;chybný
	RLCA			;do vyšších bitů
	RLCA
	RLCA
	RLCA
	LD	B,A		;uschovat
	INC	HL		;na další znak
	CALL	HEX1		;načíst 2. znak
	RET	C 		;chybný
	INC	HL		;HL za druhý znak
	OR	B		;připojit vyšší bity
	RET

L8108:  .db	 -1		;pro zachování adres

;========================================================
;	Vstupní šestnáctková konverze 16 bitů
;========================================================
;CALL:	HL = text: 4 šestnáctkové číslice
;RET:	CY => syntaktická chyba
;	NC => správné číslice,
;		DE = načtené číslo 0..65535
;		HL = za čtvrtý znak
;ruší: HL, DE, AF, B

ADRIN:	CALL	PAIRIN		;načtení vyššího bajtu
	RET	C		;chyba
	LD	D,A		;do D

	CALL	PAIRIN		;načtení nižšího bajtu
	LD	E,A		;do E
	RET

;========================================================
;	CLR - vymezerování editačního bufferu
;========================================================

CLR:	CALL	HOME		;nastavit kurzor na první znak

;========================================================
; SHIFT CLR - vymezerování editačního bufferu od kurzoru
;========================================================

SHCLR:	CALL	CURPOS		;do HL adresu aktuálního znaku
	LD	A,(DLZRAD)	;konec editačního bufferu
	INC	A		;+1
L811D:	LD	(HL),' '	;zapsat mezeru
	INC	L		;na další znak
	CP	L		;až do konce řádky
	JP	NZ,L811D
	RET

;========================================================
;	Výstupní šestnáctková konverze 8 bitů s tiskem
;========================================================
;CALL:	A = číslo 0..255
;	adresa kurzoru
;ruší:	AF, B

PREV01:	LD	B,A		;číslo do B
	RRCA			;bity 4..7 do bitů 0..3
	RRCA
	RRCA
	RRCA
	CALL	PRE00		;převést na ASCII znak
	CALL	PRTOUT		;vypsat na displej
	LD	A,B		;původní číslo
	CALL	PRE00		;převést na ASCII znak
	JP	PRTOUT		;vypsat druhý znak na displej

PREV21:	LD	(DCUR),A	;pozice kurzoru v editačním bufferu
	LD	A,E		;vypisovaná hodnota do A

;========================================================
;	Výstupní šestnáctková konverze 8 bitů
;========================================================
;CALL:	A  = číslo 0..255
;	HL = adresa bufferu (na dva znaky)
;RET:	HL = na druhý znak
;ruší:	HL, AF, B

PREV02:	LD	B,A		;schovat číslo pro další použití
	RRCA			;bity 4..7 do bitů 0..3
	RRCA
	RRCA
	RRCA
	CALL	PRE00	 	;převést na ASCII znak
	LD	(HL),A		;uložit první znak
	INC	HL
	LD	A,B		;číslo
	CALL	PRE00		;převést na ASCII
	LD	(HL),A		;uložit druhý znak
	RET

;========================================================
; Vstupní šestnáctková konverze 16 bitů s tiskem chyby
;========================================================
;CALL:	CURCH = adresa textu
;RET:	NC => číslo syntakticky správně,
;	HL = CURCH = na text za čtvrtou číslicí
; Při chybě v zápisu čísla vypíše "Error in address"
; a skočí do hlavní smyčky monitoru.

RADR:	LD	HL,(CURCH)	;ukazatel na text
	CALL	ADRIN		;načíst šestnáctkové č. do DE
	LD	(CURCH),HL	;vrátit ukazatel textu
	RET	NC		;bez chyby => návrat
	LD	HL,L83EE	;text "Error in address"
	LD	(MESS),HL	;připravit adresu textu
	JP	PRBWTXT		;do hlavní smyčky s tiskem a pípnutím

;========================================================
; Výpočet adresy aktuálního znaku v editačním bufferu
;========================================================
;RET:	HL = adresa aktuálního znaku v editačním bufferu

CURPOS:	LD	HL,(RPOS)	;adresa 1. znaku v bufferu
L8161:	EX	DE,HL
	LD	HL,(DCUR)	;pozice kurzoru na obrazovce
	ADD	HL,DE		;adresa aktuálního znaku do HL
	RET

;========================================================
; SHIFT END - zapnutí/vypnutí pípnutí při stisku klávesy
;========================================================
MODBEP:	IN	A,(0F6H)	;stav systémové brány C
	XOR	04H		;invertovat bit 2
	OUT	(0F6H),A	;změnit stav brány C
	RET

;========================================================
;	SHIFT C-D - zapnutí módu terminál
;========================================================
;Ukončit mód terminál lze stiskem SHIFT RCL a RESET!

TERM:	CALL	L8B45+1	;inicializace 8251 a 8253
; 8251: /16, 8 bitů, bez parity, 2 STOP bity, TxEN, RxEN
; 8253: nastaví se na rychlost podle proměnné SPEED (4800 Bd)

	CALL	ERASE		;smazání obrazovky
	CALL	L8B33+1		;vyšle CTRL-Q do sériové linky
	LD	B,CR
	CALL	L8B36		;vyšle CTRL-M do linky

;--------------------------------------------------------
;		Hlavní smyčka módu terminál
;--------------------------------------------------------
L817C:	CALL 	XCHCUR		;vykreslit kurzor
L817F:	IN	A,(1FH)		;status 8251
	AND	02H		;test RxRDY
	JP	Z,L81B4 	;nebyl přijat znak

	LD	BC,L817C	;připravit návratovou adresu
	PUSH	BC
	CALL	XCHCUR		;smazat kurzor
	IN	A,(1EH)		;načíst přijatý znak
	CALL	RAM		;RET - volný vektor
	CP	CR		;přijato CR?
	JP	NZ,L81A2	;NE

	LD	B,'S'-'@'
	CALL	L8B36		;vyslat CTRL-S
	CALL	L84FD+1		;tisk CR
	JP	L8B33+1		;vyslat CTRL-Q; RET

L81A2:	CP	05H		;je to CTRL-E (JUMP) ?
	JP	Z,BRANCH	;ANO
	CP	04H		;je to CTRL-D (INPUT) ?
	JP	Z,INMEM		;ANO
	CP	02H		;je to CTRL-B (OUTPUT) ?
	JP	Z,OUTMEM	;ANO
	JP	PRTOUT		;ostatní znaky vypsat na displej; RET

;========================================================
;	Vyslání znaku z klávesy do sériové linky
;========================================================
L81B4:	IN	A,(1FH)		;status 8251
	AND	01H		;volný vysílač?
	JP	Z,L81D5		;NE => do hlavní smyčky
	CALL	INKEY		;test klávesnice
	JP	Z,L81D5		;žádný znak => do hlavní smyčky
	CP	1DH		;je to DEL?
	JP	NZ,L81C8	;NE => nechat
	LD	A,7FH		;místo DEL (1DH) vyslat DELETE (7FH)
L81C8:	CP	0EH		;je to SHIFT RCL?
	JP	NZ,L81D3	;NE

	CALL	XCHCUR		;vykreslit kurzor
	JP	MON1		;návrat do monitoru

L81D3:	OUT	(1EH),A		;vyslat znak z klávesnice do linky
L81D5:	JP	L817F		;do hlavní smyčky

TEXTHEAD:
	LD	DE,NAMFIL	;buffer pro název souboru
TEXTTH:	LD	B,08H		;délka názvu souboru

;========================================================
;	Přenos textu s doplněním mezer do počtu
;========================================================
;CALL:	HL = text končící CR
;	DE = buffer pro text
;	B  = maximální počet znaků

TEXTSP:	LD	A,(HL)		;načíst znak
	CP	CR		;je konec textu?
	JP	NZ,L81E6	;NE
	LD	A,' ' 		;ANO => doplnit mezerami
	DEC	HL
L81E6:	LD	(DE),A		;uložit znak
	INC	DE
	INC	HL
	DEC	B		;cykl podle počtu znaků
	JP	NZ,TEXTSP
	RET

;========================================================
;		Vypnout pištění
;========================================================
BECLR:	IN	A,(0F6H)	;stav systémové brány C
	AND	11111100B	;smazat bity 0 a 1
	OUT	(0F6H),A	;zapsat nový stav brány
	RET

;========================================================
;	Příkaz JUMP - spuštění programu
;========================================================

JUMP:	LD	HL,(MONX)	;návratová adresa
	EX	(SP),HL		; na zásobník
	CALL	RADR		;načíst adresu pro skok
	PUSH	DE		;adresu na zásobník
	LD	HL,L829C	;text "Executive"
	CALL	L8E4B		;vypsat text
	EI			;povolit přerušení!!!???
	RET			;skočit na danou adresu

;========================================================
; Příkaz DUMP - výpis paměti v šestnáctkové formě a ve znacích
;========================================================

DUMP:	CALL	RADR		;načíst adresu
	EX	DE,HL		; do HL

L8209:	PUSH	HL		;uložit adresu
	LD	A,H		;vyšší bajt adresy
	CALL	PREV01		;vypsat
	LD	A,L		;nižší bajt adresy
	CALL	PREV01		;vypsat
	CALL	SPACE		;vypsat mezeru
	LD	C,8		;8 bajtů na řádek
L8217:	CALL	SPACE		;vypsat mezeru
	LD	A,(HL)		;načíst bajt z dané adresy
	CALL	PREV01		;vypsat bajt šestnáctkově
	INC	HL		;na další bajt
	DEC	C		;snížit čítač
	JP	NZ,L8217	;8x

	LD	C,05H
L8225:	CALL	SPACE		;vypsat 5 mezer
	DEC	C
	JP	NZ,L8225

	LD	C,8
	POP	HL		;adresa osmice bajtů

L822F:	LD	A,(HL)		;načíst bajt
	PUSH	HL
	CALL	PRT02		;vypsat jako znak
	POP	HL
	INC	HL		;na další adresu
	DEC	C		;snížit čítač
	JP	NZ,L822F	;8x

L823A:	IN	A,(0F5H)	;načíst stav klávesnice
	AND	20H		;stisknut SHIFT?
	JP	Z,L823A		;ANO => čekat

	CALL	L84FD+1		;vypsat CR
	CALL	STOP		;test klávesy STOP
	JP	NZ,L8209	;NE => psát další řádek

	CALL	CLR		;vymazat editační buffer
	JP	SYST		;návrat do hlavní smyčky monitoru

;========================================================
;		Tabulka inicializačních dat
;========================================================
INITAB:
       ;PHASE	0C030H
  .dw	7F00H
  .dw	0FFC0H
  .dw	7F4FH
  .dw	0
  .dw	7F00H
  .db	0
  .db	69
  .dw	PRTOUT
  .dw	0
	;DEPHASE

	;PHASE	0C070H
  .dw	START-1
  .dw	0,0,0

  .dw	7F82H
  .dw	0
  .dw	27
  .dw	TABDIR
	;DEPHASE

	;PHASE	0C0B0H
NEZOBRAZOVAT	.equ	0FF00H	;tyto kódy se nezobrazují
  .dw	NEZOBRAZOVAT
  .dw	DIAKR+8
  .dw	PISM+8
  .dw	MPISM+8
  .dw	NEZOBRAZOVAT
  .dw	NEZOBRAZOVAT
  .dw	NEZOBRAZOVAT
  .dw	NEZOBRAZOVAT
	;DEPHASE

	;PHASE	0C0F0H
	NOP
	JP	DECP1
  .db	0EAH
  .db	9
  .dw	0FAB0H
  .dw	0FD00H
  .db	0FBH
  .db	30H
  .dw	240H
  .db	30H
  .db	20H
	;DEPHASE

	;PHASE	0C130H
  .dw	BEEPDT
  .dw	TKDIR-2
  .db	0,0,0,0
  .dw	MON1
  .dw	7F52H
	;DEPHASE
L829C:  .db	"++ Executive ++",CR

	;PHASE	0C170H+11
  .dw	7F00H
  .dw	7D00H
	;DEPHASE

L82B0:  .db	"++ Error in data ++",CR

	;PHASE	0C1F0H+4
	LD	A,(HL)
	CP	3FH
	CP	00H
	NOP
	XOR	B
	NOP
	LD	(HL),A
	RET

  .dw	6ABH
	;DEPHASE


;========================================================
;		Tabulka kódů kláves
;========================================================
; 1. bajt je číslo řádku
; 2. až 16. bajt jsou kódy příslušných tlačítek (zleva)

KEYMAP:
  .db	0x3B; 00111011B
  .ascii	"QWERTZUIOP@\\"
  .db	KLEFT,KHOME,KRIGHT

  .db	0x37 ;00110111B
  .ascii	"ASDFGHJKL;:]"
  .db	KLLEFT,KEND,KRRIGHT

  .db	0x2F ;00101111B
  .ascii	" YXCVBNM,./"
  .db	0,0,KEOL,KEOL

  .db	0x3D ;00111101B
  .ascii	"1234567890_}"
  .db	KINS,KDEL,KCLR

  .db	0x1D ;00011101B
  .ascii	"!"
  .db 0x22
  .ascii  "#$%&'()-={"  ; ???
  .db	KPTL,KSDEL,KSCLR

  .db	0x1B ;00011011B
  .ascii	"qwertzuiop`^"
  .db	KSLEFT,KSHOME,KSRIGHT

  .db	0x17 ;00010111B
  .ascii	"asdfghjkl+*["
  .db	KSLLEFT,KSEND,KSRRIGH

  .db	0x0F ;00001111B
  .ascii	" yxcvbnm<>?"
  .db	0,0,KEOL,KEOL

  .db	0x1E ;00011110B
  .db	94H,95H,96H,97H,98H,99H,9AH,9BH
  .db	9CH,9DH,9EH,9FH
  .db	KSWRK,KSCD,KSRCL

  .db	0x3E ;00111110B
  .db	88H,89H,8AH,8BH,8CH,8DH,8EH,8FH
  .db	90H,91H,92H,93H
  .db	KWRK,KCD,KRCL

  .db	0		;příznak konce tabulky

;========================================================
;	Tabulka podprogramů editačních kláves
;========================================================
TKDIR:
.macro INLCMD KOD, ADRESA
  .db  \KOD   ;kód klávesy
  .dw  \ADRESA
.endm

	INLCMD	KPTL,PTL
	INLCMD	KSRCL,MON1
	INLCMD	KSCD,TERM
	INLCMD	KSDEL,0
	INLCMD	KWRK,WRK
	INLCMD	KCD,CD
	INLCMD	KRCL,RCL
	INLCMD	KINS,INS
	INLCMD	KDEL,DEL
	INLCMD	KCLR,CLR
	INLCMD	KLEFT,LEFT
	INLCMD	KHOME,HOME
	INLCMD	KRIGHT,RIGHT
	INLCMD	KLLEFT,LLEFT
	INLCMD	KEND,END
	INLCMD	KRRIGHT,RRIGHT
	INLCMD	KEOL,EOL
	INLCMD	KSCLR,SHCLR
	INLCMD	KSHOME,ERASE
	INLCMD	KSLLEFT,MODNEG
	INLCMD	KSRRIGH,MODCOL
	INLCMD	KSWRK,MODCHR
	INLCMD	KSEND,MODBEP

TABDIR: .db	0		;příznak konce tabulky

;========================================================
;		Tabulka příkazů monitoru
;========================================================
.macro MONCMD NAZEV,ADRESA
  .db  "&NAZEV",0  ;text příkazu ukončený 0
  .dw  \ADRESA
.endm
	MONCMD	SUB,SUB
	MONCMD	MEM,MEM
	MONCMD	JUMP,JUMP
	MONCMD	DUMP,DUMP
	MONCMD	MGSV,MGSV
	MONCMD	MGLD,MGLD
	MONCMD	MGEND,MGEND
	MONCMD	JOB,JOB
  .db	-1		;příznak konce tabulky

;========================================================
;		Texty hlášení
;========================================================
L83EE:  .db	"++ Error in addres ++",CR
L8404:  .db	"++ Mg stop! ++",CR
L8413:  .db	"++ File error ++",CR
L8424:  .db	"++ Os ready ++",CR
L8433:  .db	"++ Memory overflow ++",CR

; Tvaru znaku "čtvereček"
; Tiskne se místo všech netištitelných kódů
  .db	0,0,0,0,1CH,14H,1CH,0	;čtvereček
UNDEF:

;========================================================
;		Pokračovaní podprogramu SUB
;========================================================
;CALL: DE = následující adresa

SUB03:	PUSH	DE
	CALL	CLR		;smazat editační buffer
L8455:	POP	DE
SUBTXT:	LD	HL,(BUF)	;začátek editačního textu
	LD	(HL),'S'	;připravit text "SUB adresa"
	INC	HL
L845C:	LD	(HL),'U'
	INC	HL
	LD	(HL),'B'
L8461: 	INC	HL
	LD	(HL),' '
	INC	HL
	LD	A,D		;vyšší bajt adresy z DE
	CALL	PREV02		;vypsat
	INC	HL
	LD	A,09H		;umístit kurzor za adresu
	JP	PREV21

;========================================================
;	SHIFT WRK - zvýšení kódu znaku pod kurzorem o 1
;========================================================

MODCHR:	CALL	CURPOS		;adresa znaku pod kurzorem do HL
L8472:	PUSH	HL
	LD	A,(HL)		;vybrat kód znaku
L8474:	INC	A		;zvýšit o 1
	PUSH	AF
L8476:	CALL	ADRAS		;vytvořit adresu do generátoru znaků
	POP	BC
	LD	A,B
	JP	Z,L8474		;netištitelný znak přeskočit
L847E:	POP	HL		;adresa do textového bufferu
	LD	(HL),A		;zapsat nový kód
	RET

;========================================================
;	Vykreslení/smazání kurzoru
;========================================================

XCHCUR:	LD	HL,(CURSOR)	;adresa pro tisk znaku
XCCUR:	LD	BC,-40H		;-linka
	ADD	HL,BC		;na předchozí linku
	LD	A,(HL)		;vybrat bajt z displeje
	XOR	00111110B	;invertovat některé bity
	LD	(HL),A		;zapsat zpět
	RET

;========================================================
;	Načtení bajtu z magnetofonu
;========================================================

BYTE1:	PUSH	BC
	PUSH	DE
	PUSH	HL
	JP	L8B80		;do podprogramu čtení bajtu z magnetofonu

;========================================================
;	WRK - zápis do funkčních kláves
;========================================================

WRK:	LD	A,-1		;nahodit příznak zápisu
	LD	(SWRK),A
	RET

;========================================================
;	PTL - zapnutí/vypnutí výpisu editační řádky po EOL
;========================================================

PTL:	LD	HL,SPTL		;adresa příznaku
	LD	A,(HL)		;vybrat stav příznaku
L849D:	CPL			;invertovat
	LD	(HL),A		;zapsat nový stav příznaku
	RET

L84A0:	NOP			;pro dodržení adres

;========================================================
;	Načtení znaku z klávesnice s čekáním na stisk
;========================================================
;RET:	A = kód stisknuté klávesy

KLAV:
INKLAV:	PUSH	BC		;uložit registry
	PUSH	DE
	PUSH	HL
L84A4:	IN	A,(1EH)		;vyprázdnit přijímač 8251
	CALL	INKEY		;vstup znaku z klávesnice bez čekání
 	JP	Z,L84A4		;žádná klávesa => čekat v cyklu
 L84AC:	JP	ADRRET		;obnovit registry a návrat

;========================================================
;  Výpis znaku při editaci řádky
;========================================================

CHAR:	CALL	CURPOS		;adresace do editačního bufferu
	LD	(HL),A		;zapsat znak
	LD	A,(BEEPPOS)	;pozice pro pípnutí
	CP	L		;kurzor na této pozici?
	CALL	Z,BEEP		;ANO => pípnout

;========================================================
;			->
;========================================================
RIGHT:	LD	HL,DCUR		;pozice v editačním bufferu
	INC	(HL)		;zvýšit o 1
	LD	A,(DLZR)	;konec displeje
	CP	(HL)		;překročen?
	RET	NZ		;NE => návrat
	DEC	(HL)		;na původní hodnotu

;========================================================
;		|<-
;========================================================

LLEFT:	LD	HL,RPOS		;pozice prvního vypisovaného znaku
	LD	A,(DLZP)	;konec displeje
	CP	(HL)		;jsme na konci?
	RET	Z		;ANO => ignorovat
	INC	(HL)		;zvýšit počáteční pozici
	RET

;========================================================
;	Vytvoření adresy do generátoru znaků
;========================================================
;CALL:	A = znak
;RET:	HL = adresa bajtu za 8 bajty tvaru znaku
;ruší:	HL, DE, BC, AF

ADRAS:	LD	B,A		;uložit znak
	AND	00011111B	;znak MOD 32
	LD	C,A
	LD	A,B
	SUB	C		;znak/32 * 32
	RRCA
	RRCA
	RRCA
	RRCA			;znak/32 * 2
	LD	L,A		; do HL
	LD	H,0
	LD	B,H
	LD	A,C		;znak MOD 32
	ADD	A,A		;*2
	ADD	A,A		;*4
	ADD	A,A		;*8
	LD	C,A
	LD	DE,TASCII	;adresa tabulky adres
	ADD	HL,DE		;indexovat do tabulky
	LD	D,(HL)		;vybrat adresu
	INC	HL
	LD	H,(HL)		; do HL
	LD	L,D
	ADD	HL,BC		;přičíst offset (znak)
	LD	A,H		;adresa je FF..H?
	INC	A
	RET	NZ		;NE => platný tvar

; Znak je netištitelný, vrátí se adresa čtverečku
	LD	HL,SUB03	;adresa čtverečku
	RET

L84F1:	NOP
	NOP

BREAD:	LD	HL,(BCUR)
	LD	A,(HL)
	AND	3FH
	RET

L84FA:	NOP

;========================================================
;		Vypsat mezeru
;========================================================

SPACE:	LD	A,' '

L84FD:  .db	11H		;LD DE,nn

;========================================================
;		Vypsat CR
;========================================================

	LD	A,CR

;========================================================
;		Vypsat znak
;========================================================
;CALL:	A = znak
;ruší:	AF

PRTOUT:	PUSH	BC		;uložit registry
	PUSH	DE
	PUSH	HL
	LD	HL,ADRRET	;připravit návratovou adresu
	PUSH	HL
	CP	CR		;je to CR?
	JP	NZ,L8523	;NE

	LD	HL,(CURSOR)	;adresa kurzoru
	LD	A,(VYSKA)	;kam až se smí psát
	CP	H
	JP	C,ROLL		;již není místo => odrolovat

	LD	A,L		;adresa začátku řádky na displeji
	AND	11000000B
	LD	L,A
	EX	DE,HL		; do DE
	LD	HL,(RADSIR)	;offset adres mezi řádky
	ADD	HL,DE		;adresa další řádky
	LD	(CURSOR),HL	;nová adresa kurzoru
	RET

L8523:	CP	1CH		;je to CLS?
	JP	Z,ERASE		;ANO => smazat displej
	CP	0AH		;je to LF?
	RET	Z		;ANO => ignorovat!

	AND	A		;je to NULL?
	RET	Z		;ANO => ignorovat

	LD	HL,CURSOR	;adresa kurzoru
	DEC	(HL)		;snížit adresu
	CP	08H		;je to BACKSPACE?
	RET	Z		;ANO => návrat

; BACKSPACE na začátku řádky umístí kurzor do "neviditelné"
; části displej, kde má monitor proměnné.
; Efekt při vypsaní znaku do této časti paměti je nedefinovatelný
; a skončí nejspíše krachem!!!

	INC	(HL)		;obnovit původní stav
	LD	C,A		;znak uložit do Z
	LD	A,(HL)		;pozice X na displeji
	AND	00111111B
	LD	B,A		; do B
	LD	A,(ENLNW)	;maximum znaků na displej
	CP	B		;překročeno?
	CALL	Z,L84FD+1	;ANO => CR

	LD	A,C		;znak
PRT02:	LD	HL,CURSOR	;adresa kurzoru
	INC	(HL)		;zvýšit o 1
	LD	HL,(CURSOR)	;vybrat adresu
	DEC	HL		;na původní pozici

;========================================================
;		Výpis znaku
;========================================================
; Ani tento potřebný podprogram nelze použít s povoleným přerušením!!!
; ©koda, že autoři programu o přerušení u mikroprocesoru 8080 nevědí.

;CALL:	HL = adresa kurzoru (2 linky pod znakem)
;	A = znak

WRCHAR:	PUSH	BC		;uložit registry
	PUSH	DE

	PUSH	HL		;adresa do displeje
	CALL	ADRAS		;adresa tvaru znaku do HL
	EX	DE,HL		; do DE

	LD	HL,0000H	;uložit SP pro případné další použití
	ADD	HL,SP
	LD	(STACK),HL

	LD	A,(COLOR)	;atribut (barva)
	POP	HL		;adresa do displeje
	PUSH	HL
	LD	SP,-40H		;-linka
;SP je původně určen pro zcela jiný účel!
	LD	BC,-80H		;o dvě linky nahoru
	ADD	HL,BC
	LD	B,A		;atribut
	LD	C,08H		;tvar znaku má 8 bajtů
L8567:	DEC	DE		;snížit ukazatel na tvar
	LD	A,(DE)		;vybrat tvar
	XOR	B		;+ atribut
	LD	(HL),A		;zapsat bajt tvaru
	ADD	HL,SP		;-40H: na předchozí linku displeje
	DEC	C		;snížit čítač
	JP	NZ,L8567	;8x

	LD	(HL),B		;vymazat linku nad znakem

	LD	HL,(STACK)	;obnovit zásobník
	LD	SP,HL
ADRRET:	POP	HL		;obnovit registry
	POP	DE
ADRR1T:	POP	BC
	RET

;========================================================
;		Spuštění příkazu monitoru
;========================================================

SYST1:	CALL	SSKIP		;přeskočit mezery v textu (HL)
	LD	(CURCH),HL	;uložit do ukazatele textu
	INC	DE		;v tabulce na adresu
	EX	DE,HL
	JP	L8C66		;vybrat adresu a spustit podprogram

L8584:	JP	WRCHAR		;Tisk znaku (původní adresa)

;========================================================
;		Příkaz MEM - výpis úseku paměti
;========================================================

MEM:	CALL	RADR		;načíst adresu do DE
	CALL	SUBTXT		;příprava textu "SUB adresa"

	LD	B,16		;vypisuje se 16 bajtů paměti
L858F:	PUSH	BC
	INC	HL
	LD	(HL),' '	;připravit mezeru
	INC	HL
	LD	A,(DE)		;vybrat bajt z paměti
	CALL	PREV02		;připravit bajt šestnáctkově
	INC	DE		;na další bajt
	POP	BC
	DEC	B		;snížit čítač
	JP	NZ,L858F	;16x
	RET			;po návratu se vypíše připravený text

;========================================================
; SHIFT |< - Zapnutí/vypnutí inverzního tisku + výmaz displeje
;========================================================
;ruší:	HL, DE, BC, AF

MODNEG:	LD	A,(COLOR)	;atribut
	XOR	3FH		;invertovat
	LD	(COLOR),A	;zapsat nový atribut

;========================================================
;		SHIFT HOME - Smazání displeje
;========================================================
; Ani tento potřebný podprogram nelze použít s povoleným přerušením!!!!

;ruší:	HL, DE, BC, AF

ERASE:	LD	BC,0C280H	;adresa prvního znaku na displeji
	LD	DE,0C030H	;adresa konce první linky+1
	LD	HL,(RADSIR)	;offset mezi řádky
	ADD	HL,BC
	LD	B,00H		;256 linek

;========================================================
;		Výmaz části displeje
;========================================================
;CALL:	HL = adresa kurzoru
;	DE = adresa konce nejvyšší mazané linky+1
;	B = počet mazaných linek

L85B3:	LD	(CURSOR),HL	;nastavit adresu pro kurzor
	LD	A,(COLOR)	;atribut

	LD	HL,0000H	;uložit SP
	ADD	HL,SP
	EX	DE,HL		;do DE
	LD	SP,HL		;adresa konce linky do SP
; K čemu všemu lze SP použít!
	LD	C,A		;atribut do B i C
	LD	A,B		;počet mazaných linek do A
	LD	B,C

L85C2:	
  ;REPT	24		;!!! šetříme pamětí !!! ???
	PUSH	BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
  PUSH  BC
	;ENDM
	LD	SP,0040H	;SP na další linku
	ADD	HL,SP
	LD	SP,HL

	DEC	A		;snížit čítač
	JP	NZ,L85C2	;cykl

	EX	DE,HL		;obnovit SP
	LD	SP,HL
	RET			;konečně návrat!

;========================================================
;		Test rozsvícení bodu
;========================================================
;CALL:	X1, Y1 = souřadnice bodu
;RET:	Z,  A=0 => bod nesvítí
;	NZ, A=l => bod svítí
;ruší:	HL, DE, BC, AF

RPOINT:	LD	HL,(Y1-1)	;Y1 do H
	LD	A,(X1)		;X1 do L
	LD	L,A
	CALL	POSPOINT	;adresovat displej
	LD	A,(HL)		;vybrat bajt z displeje
	AND	B		;AND maska
	RET	Z		;nesvítí
	LD	A,01H		;svítí
	RET

;========================================================
;		Načtení bajtu ze sériové linky
;========================================================
;RET:	A = načtený bajt

INB:	IN	A,(1FH)		;načíst status
	AND	02H		;načten bajt?
	JP	Z,INB		;NE => čekat
	IN	A,(1EH)		;načíst data do A
	RET

;========================================================
;	Tabulka tvarů znaků s kódy 20H..3FH
;========================================================
DIAKR:
; 20H " "
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......

; 21H "!"
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	00H	;......
  .db	00H	;......
  .db	08H	;...#..
  .db	00H	;......

; 22H """
  .db	14H	;..#.#.
  .db	14H	;..#.#.
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......

; 23H "#"
  .db	14H	;..#.#.
  .db	14H	;..#.#.
  .db	3EH	;.#####
  .db	14H	;..#.#.
  .db	3EH	;.#####
  .db	14H	;..#.#.
  .db	14H	;..#.#.
  .db	00H	;......

; 24H "$"
  .db	08H	;...#..
  .db	3CH	;..####
  .db	0AH	;.#.#..
  .db	1CH	;..###.
  .db	28H	;...#.#
  .db	1EH	;.####.
  .db	08H	;...#..
  .db	00H	;......

; 25H "%"
  .db	06H	;.##...
  .db	26H	;.##..#
  .db	10H	;....#.
  .db	08H	;...#..
  .db	04H	;..#...
  .db	32H	;.#..##
  .db	30H	;....##
  .db	00H	;......

; 26H "&"
  .db	08H	;...#..
  .db	14H	;..#.#.
  .db	14H	;..#.#.
  .db	0CH	;..##..
  .db	2AH	;.#.#.#
  .db	12H	;.#..#.
  .db	2CH	;..##.#
  .db	00H	;......

; 27H "'"
  .db	08H	;...#..
  .db	08H	;...#..
  .db	04H	;..#...
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......

; 28H "("
  .db	08H	;...#..
  .db	04H	;..#...
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	04H	;..#...
  .db	08H	;...#..
  .db	00H	;......

; 29H ")"
  .db	08H	;...#..
  .db	10H	;....#.
  .db	20H	;.....#
  .db	20H	;.....#
  .db	20H	;.....#
  .db	10H	;....#.
  .db	08H	;...#..
  .db	00H	;......

; 2AH "*"
  .db	00H	;......
  .db	08H	;...#..
  .db	2AH	;.#.#.#
  .db	1CH	;..###.
  .db	2AH	;.#.#.#
  .db	08H	;...#..
  .db	00H	;......
  .db	00H	;......

; 2BH "+"
  .db	00H	;......
  .db	08H	;...#..
  .db	08H	;...#..
  .db	3EH	;.#####
  .db	08H	;...#..
  .db	08H	;...#..
  .db	00H	;......
  .db	00H	;......

; 2CH ","
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	08H	;...#..
  .db	08H	;...#..
  .db	04H	;..#...
  .db	00H	;......

; 21H "-"
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	3CH	;..####
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......

; 2EH "."
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	08H	;...#..
  .db	00H	;......

; 2FH "/"
  .db	00H	;......
  .db	20H	;.....#
  .db	10H	;....#.
  .db	08H	;...#..
  .db	04H	;..#...
  .db	02H	;.#....
  .db	00H	;......
  .db	00H	;......

; 30H "0"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	32H	;.#..##
  .db	2AH	;.#.#.#
  .db	26H	;.##..#
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	00H	;......

; 31H "1"
  .db	08H	;...#..
  .db	0CH	;..##..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	1CH	;..###.
  .db	00H	;......

; 32H "2"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	20H	;.....#
  .db	18H	;...##.
  .db	04H	;..#...
  .db	02H	;.#....
  .db	3EH	;.#####
  .db	00H	;......

; 33H "3"
  .db	3EH	;.#####
  .db	20H	;.....#
  .db	10H	;....#.
  .db	38H	;...###
  .db	20H	;.....#
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	00H	;......

; 34H "4"
  .db	10H	;....#.
  .db	18H	;...##.
  .db	14H	;..#.#.
  .db	12H	;.#..#.
  .db	3EH	;.#####
  .db	10H	;....#.
  .db	10H	;....#.
  .db	00H	;......

; 35H "5"
  .db	3EH	;.#####
  .db	02H	;.#....
  .db	1EH	;.####.
  .db	20H	;.....#
  .db	20H	;.....#
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	00H	;......

; 34H "6"
  .db	38H	;...###
  .db	04H	;..#...
  .db	02H	;.#....
  .db	1EH	;.####.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	00H	;......

; 37H "7"
  .db	3EH	;.#####
  .db	20H	;.....#
  .db	10H	;....#.
  .db	08H	;...#..
  .db	04H	;..#...
  .db	04H	;..#...
  .db	04H	;..#...
  .db	00H	;......

; 38H "8"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	00H	;......

; 39H "9"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	3CH	;..####
  .db	20H	;.....#
  .db	10H	;....#.
  .db	0EH	;.###..
  .db	00H	;......

; 3AH ":"
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	08H	;...#..
  .db	00H	;......
  .db	08H	;...#..
  .db	00H	;......
  .db	00H	;......

; 3BH ";"
  .db	00H	;......
  .db	00H	;......
  .db	08H	;...#..
  .db	00H	;......
  .db	08H	;...#..
  .db	08H	;...#..
  .db	04H	;..#...
  .db	00H	;......

; 3CH "<"
  .db	10H	;....#.
  .db	08H	;...#..
  .db	04H	;..#...
  .db	02H	;.#....
  .db	04H	;..#...
  .db	08H	;...#..
  .db	10H	;....#.
  .db	00H	;......

; 3DH "="
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	3EH	;.#####
  .db	00H	;......
  .db	3EH	;.#####
  .db	00H	;......
  .db	00H	;......

; 3EH ">"
  .db	04H	;..#...
  .db	08H	;...#..
  .db	10H	;....#.
  .db	20H	;.....#
  .db	10H	;....#.
  .db	08H	;...#..
  .db	04H	;..#...
  .db	00H	;......

; 3FH "?"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	20H	;.....#
  .db	10H	;....#.
  .db	08H	;...#..
  .db	00H	;......
  .db	08H	;...#..
  .db	00H	;......

;========================================================
;	Tabulka tvarů  znaků s  kódy 40H..5FH
;========================================================
PISM:
; 40H "@"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	32H	;.#..##
  .db	2AH	;.#.#.#
  .db	3AH	;.#.###
  .db	02H	;.#....
  .db	1CH	;..###.
  .db	00H	;......

; 41H "A"
  .db	08H	;...#..
  .db	14H	;..#.#.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	3EH	;.#####
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	00H	;......

; 42H "B"
  .db	1EH	;.####.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	1EH	;.####.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	1EH	;.####.
  .db	00H	;......

; 43H "C"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	00H	;......

; 44H "D"
  .db	1EH	;.####.
  .db	24H	;..#..#
  .db	24H	;..#..#
  .db	24H	;..#..#
  .db	24H	;..#..#
  .db	24H	;..#..#
  .db	1EH	;.####.
  .db	00H	;......

; 45H "E"
  .db	3EH	;.#####
  .db	02H	;.#....
  .db	02H	;.#....
  .db	1EH	;.####.
  .db	02H	;.#....
  .db	02H	;.#....
  .db	3EH	;.#####
  .db	00H	;......

; 46H "F"
  .db	3EH	;.#####
  .db	02H	;.#....
  .db	02H	;.#....
  .db	1EH	;.####.
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	00H	;......

; 47H "G'
  .db	1CH	;..###.
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	32H	;.#..##
  .db	22H	;.#...#
  .db	3CH	;..####
  .db	00H	;......

; 48H "H"
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	3EH	;.#####
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	00H	;......

; 49H "I"
  .db	1CH	;..###.
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	1CH	;..###.
  .db	00H	;......

; 4AH "J"
  .db	20H	;.....#
  .db	20H	;.....#
  .db	20H	;.....#
  .db	20H	;.....#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	00H	;......

; 4BH "K"
  .db	22H	;.#...#
  .db	12H	;.#..#.
  .db	0AH	;.#.#..
  .db	06H	;.#....
  .db	0AH	;.#.#..
  .db	12H	;.#..#.
  .db	22H	;.#...#
  .db	00H	;......

; 4CH "L"
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	3EH	;.#####
  .db	00H	;......

; 4DH "M"
  .db	22H	;.#...#
  .db	36H	;.##.##
  .db	2AH	;.#.#.#
  .db	2AH	;.#.#.#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	00H	;......

; 4EH "N"
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	26H	;.##..#
  .db	2AH	;.#.#.#
  .db	32H	;.#..##
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	00H	;......

; 4FH "O"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	00H	;......

; 50H "P"
  .db	1EH	;.####.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	1EH	;.####.
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	00H	;......

; 51H "Q"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	2AH	;.#.#.#
  .db	12H	;.#..#.
  .db	2CH	;..##.#
  .db	00H	;......

; 52H "R"
  .db	1EH	;.####.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	1EH	;.####.
  .db	0AH	;.#.#..
  .db	12H	;.#..#.
  .db	22H	;.#...#
  .db	00H	;......

; 53H "S"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	02H	;.#....
  .db	1CH	;..###.
  .db	20H	;.....#
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	00H	;......

; 54H "T"
  .db	3EH	;.#####
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	00H	;......

; 55H "U"
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	1CH	;..###.
  .db	00H	;......

; 56H "V"
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	14H	;..#.#.
  .db	14H	;..#.#.
  .db	08H	;...#..
  .db	08H	;...#..
  .db	00H	;......

; 57H "W"
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	2AH	;.#.#.#
  .db	2AH	;.#.#.#
  .db	2AH	;.#.#.#
  .db	14H	;..#.#.
  .db	00H	;......

; 5BH "X"
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	14H	;..#.#.
  .db	08H	;...#..
  .db	14H	;..#.#.
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	00H	;......

; 59H "Y"
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	14H	;..#.#.
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	00H	;......

; 5AH "Z"
  .db	3EH	;.#####
  .db	20H	;.....#
  .db	10H	;....#.
  .db	08H	;...#..
  .db	04H	;..#...
  .db	02H	;.#....
  .db	3EH	;.#####
  .db	00H	;......

; 5BH "["
  .db	0EH	;.###..
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	0EH	;.###..
  .db	00H	;......

; 5CH "\"
  .db	00H	;......
  .db	02H	;.#....
  .db	04H	;..#...
  .db	08H	;...#..
  .db	10H	;....#.
  .db	20H	;.....#
  .db	00H	;......
  .db	00H	;......

; 5DH "]"
  .db	38H	;...###
  .db	20H	;.....#
  .db	20H	;.....#
  .db	20H	;.....#
  .db	20H	;.....#
  .db	20H	;.....#
  .db	38H	;...###
  .db	00H	;......

; 5EH "^"
  .db	1CH	;..###.
  .db	22H	;.#...#
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......

; 5FH "_"
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	3EH	;.#####
  .db	00H	;......

;========================================================
;	Provedení změny v editační řádce
;========================================================
;CALL:	ASCII = kód znaku nebo povelu
;RET:	změněný editační buffer, je vypsán na displej
;ruší:	AF

EDIT:
KEYOUT:	PUSH	BC		;uložit registry
	PUSH	DE
	PUSH	HL
	LD	HL,ADRRET	;připravit návratovou adresu
L8806:	PUSH	HL
	CALL	DOKEY		;provést opravy v editační řádce
L880A:	JP	WRBUFF		;vypsat nový stav na displej

;========================================================
;	INS - vsunutí mezery na místo kurzoru
;========================================================

INS:	CALL	CURPOS		;adresa kurzoru do HL
	LD	C,L		;pozice X do C
	CALL	ENDLN		;adresa konce BUFOUT do HL
	LD	D,H		;do DE
	LD	E,L
	INC	DE	 	;+1
	LD	A,C
	CP	E
	RET	NC		;mezera se již nevejde

L881A:	LD	A,(HL)		;odsunout text do konce řádky
	LD	(DE),A
	LD	A,C		;aktuální pozice?
	CP	L
	DEC	HL
	DEC	DE
	JP	NZ,L881A	;NE => odsouvat dál
	INC	HL
	LD	(HL),' '	;zapsat mezeru
	RET

;========================================================
;		Vyvolaní funkčních kláves
;========================================================
KEY:	LD	A,(ASCII)	;stisknutá klávesa
	LD	C,A		; do C
	LD	A,(SWRK)	;byl WRK?
	OR	A
	JP	NZ,SETWRK	;ANO => zapsat!

  .db	32H		;LD (nn),A

;========================================================
;	RCL - vyvolaní poslední odeslané řádky
;========================================================

RCL:	LD	C,87H		;kód klíče RCL
	LD	HL,(KEYEND)	;adresa začátku klíčů
L8838:	DEC	HL		;-1
	LD	A,(HL)		;konec tabulky?
	OR	A
	RET	Z		;ANO => nenalezeno => ignorovat
	CP	C		;je to hledaný klíč?
	JP	NZ,L8838	;NE => hledat dál

; Kód klíče byl nalezen

L8840:	DEC	HL
	LD	A,(HL)		;vybrat znak klíče
	OR	A		;konec klíče?
	RET	Z		;ANO => návrat
	LD	(ASCII),A	;uložit znak
	JP	P,L884D		;ASCII znak
	CP	0A0H		;je to kód klíče?
	RET	C		;ANO => konec

L884D:	PUSH	HL		;uschovat adresu do tabulky klíčů
	CALL	DOKEY		;provést opravu v editačním bufferu
	POP	HL		;obnovit ukazatel
	JP	L8840		;cykl

;========================================================
;	Výpis textu editační řádky na displej
;========================================================

WRBUFF:	LD	HL,(RPOS)	;první vypisovaný znak
ZOBRBUF:
WRLINE:	EX	DE,HL
	LD	HL,(DIAL)	;adresa do displeje pro výpis
	LD	A,(DLZR)	;počet zobrazovaných znaků
	LD	B,A		; do B

L8860:	LD	A,(DE)		;vezmi znak
	CALL	WRCHAR		;vypiš znak
	INC	HL		;na další
	INC	DE
	DEC	B		;snížit čítač
	JP	NZ,L8860	;cykl
	RET

;========================================================
;	Zápis 16 shodných bajtů na magnetofon
;========================================================
;CALL:	A = bajt
;ruší:	HL

LEADER:	LD	L,16
L886D:	LD	H,A		;uschovat bajt
	CALL	USARTOUT	;vyslat bajt
	LD	A,H
	DEC	L		;16x
	JP	NZ,L886D
	RET

;========================================================
;	Načtení dvou bajtů ze sériové linky
;========================================================
;RET:	HL = načtené dva bajty (adresa)

INHL:	CALL	INB		;načíst první bajt
	LD	L,A		; do L
	CALL	INB		;načíst druhý bajt
	LD	H,A		; do H
	RET

;========================================================
;	HOME - Nastavení kurzoru na první znak
;========================================================

HOME:	XOR	A		;0
	LD	(RPOS),A	;první vypisovaný z bufferu na displej
	LD	(DCUR),A	;pozice kurzoru v editačním bufferu
	RET

;========================================================
;	Výstupní šestnáctková konverze 4 bity
;========================================================
;CALL:	A = bity 0..3: číslo
;RET:	A = šestnáctková číslice

PRE00:	AND	00001111B
	CP	10
	SBC	A,2FH
	DAA
	RET

;========================================================
;	Čekání na změnu stavu vstupu z magnetofonu
;========================================================
; Čtení z magnetofonu probíhá na bitu 7 statusu 8251
; Čas timeout se vypočte: C*28µsec*16µsec

SCAN2:	LD	C,37		;timeout konstanta
	IN	A,(1FH)		;načíst status 8251
	LD	H,A		; do H

SCAN:	DEC	C		;snížit čítač timeout
	RET	Z		;timeout! => návrat s chybou

	IN	A,(0F5H)	;test klávesy STOP
	AND	40H
	RET	Z		;ANO => návrat

	IN	A,(1FH)		;načíst status 8251
	XOR	H		;změna?
	JP	P,SCAN		;NE => cykl
	RET			;ANO => návrat

;========================================================
;		Pípání podle tabulky
;========================================================

BEEP:	LD	HL,(BEEDT)	;adresa tabulky

BELL:	CALL	BECLR		;vypnout zvuk
	LD	B,A		;stav brány
	LD	A,(HL)		;bajt z tabulky
	CP	-1		;konec tabulky?
	RET	Z		;ANO => návrat
	OR	B		;+stav
	OUT	(0F6H),A	;zapsat nový stav
	INC	HL		;na další bajt tabulky
	LD	D,(HL)		;jak dlouho
	CALL	WAITS		;čekat
	INC	HL
	JP	BELL		;cykl

L88BA:  .db	1,2,4,8,10H,20H

;========================================================
;	Tabulka tvarů  malých písmen 60H..7FH
;========================================================
MPISM:
; 60H "`"
  .db	04H	;..#...
  .db	08H	;...#..
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......

; 61H "a"
  .db	00H	;......
  .db	00H	;......
  .db	0CH	;..##..
  .db	10H	;....#.
  .db	1CH	;..###.
  .db	12H	;.#..#.
  .db	1CH	;..###.
  .db	00H	;......

; 62H "b"
  .db	02H	;.#....
  .db	02H	;.#....
  .db	0EH	;.###..
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	0EH	;.###..
  .db	00H	;......

; 63H "c"
  .db	00H	;......
  .db	00H	;......
  .db	0CH	;..##..
  .db	12H	;.#..#.
  .db	02H	;.#....
  .db	12H	;.#..#.
  .db	0CH	;..##..
  .db	00H	;......

; 64H "d"
  .db	10H	;....#.
  .db	10H	;....#.
  .db	1CH	;..###.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	1CH	;..###.
  .db	00H	;......

; 65H "e"
  .db	00H	;......
  .db	00H	;......
  .db	0CH	;..##..
  .db	12H	;.#..#.
  .db	1EH	;.####.
  .db	02H	;.#....
  .db	0CH	;..##..
  .db	00H	;......

; 66H "f"
  .db	08H	;...#..
  .db	14H	;..#.#.
  .db	04H	;..#...
  .db	0EH	;.###..
  .db	04H	;..#...
  .db	04H	;..#...
  .db	04H	;..#...
  .db	00H	;......

; 67H "g"
  .db	00H	;......
  .db	00H	;......
  .db	0CH	;..##..
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	1CH	;..###.
  .db	10H	;....#.
  .db	0EH	;.###..

; 68H "h"
  .db	02H	;.#....
  .db	02H	;.#....
  .db	0EH	;.###..
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	00H	;......

; 69H "i"
  .db	08H	;...#..
  .db	00H	;......
  .db	0CH	;..##..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	1CH	;..###.
  .db	00H	;......

; 6AH "j"
  .db	10H	;....#.
  .db	00H	;......
  .db	18H	;...##.
  .db	10H	;....#.
  .db	10H	;....#.
  .db	10H	;....#.
  .db	12H	;.#..#.
  .db	0CH	;..##..

; 6BH "k"
  .db	02H	;.#....
  .db	02H	;.#....
  .db	12H	;.#..#.
  .db	0AH	;.#.#..
  .db	06H	;.##...
  .db	0AH	;.#.#..
  .db	12H	;.#..#.
  .db	00H	;......

; 6CH "l"
  .db	0CH	;..##..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	1CH	;..###.
  .db	00H	;......

; 6DH "m"
  .db	00H	;......
  .db	00H	;......
  .db	16H	;.##.#.
  .db	2AH	;.#.#.#
  .db	2AH	;.#.#.#
  .db	2AH	;.#.#.#
  .db	2AH	;.#.#.#
  .db	00H	;......

; 6EH "n"
  .db	00H	;......
  .db	00H	;......
  .db	0EH	;.###..
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	00H	;......

; 6FH "o"
  .db	00H	;......
  .db	00H	;......
  .db	0CH	;..##..
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	0CH	;..##..
  .db	00H	;......

; 70H "p"
  .db	00H	;......
  .db	00H	;......
  .db	0EH	;.###..
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	0EH	;.###..
  .db	02H	;.#....
  .db	02H	;.#....

; 71H "q"
  .db	00H	;......
  .db	00H	;......
  .db	1CH	;..###.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	1CH	;..###.
  .db	10H	;....#.
  .db	10H	;....#.

; 72H "r"
  .db	00H	;......
  .db	00H	;......
  .db	1AH	;.#.##.
  .db	06H	;.##...
  .db	02H	;.#....
  .db	02H	;.#....
  .db	02H	;.#....
  .db	00H	;......

; 73H "s"
  .db	00H	;......
  .db	00H	;......
  .db	1CH	;..###.
  .db	02H	;.#....
  .db	0CH	;..##..
  .db	10H	;....#.
  .db	0EH	;.###..
  .db	00H	;......

; 74H "t"
  .db	04H	;..#...
  .db	04H	;..#...
  .db	0EH	;.###..
  .db	04H	;..#...
  .db	04H	;..#...
  .db	14H	;..#.#.
  .db	08H	;...#..
  .db	00H	;......

; 75H "u"
  .db	00H	;......
  .db	00H	;......
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	0CH	;..##..
  .db	00H	;......

; 76H "v"
  .db	00H	;......
  .db	00H	;......
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	0CH	;..##..
  .db	04H	;..#...
  .db	00H	;......

; 77H "w"
  .db	00H	;......
  .db	00H	;......
  .db	22H	;.#...#
  .db	22H	;.#...#
  .db	2AH	;.#.#.#
  .db	2AH	;.#.#.#
  .db	14H	;..#.#.
  .db	00H	;......

; 78H "x"
  .db	00H	;......
  .db	00H	;......
  .db	22H	;.#...#
  .db	14H	;..#.#.
  .db	08H	;...#..
  .db	14H	;..#.#.
  .db	22H	;.#...#
  .db	00H	;......

; 79H "y"
  .db	00H	;......
  .db	00H	;......
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	12H	;.#..#.
  .db	1CH	;..###.
  .db	10H	;....#.
  .db	0CH	;..##..

; 7AH "z"
  .db	00H	;......
  .db	00H	;......
  .db	1EH	;.####.
  .db	08H	;...#..
  .db	04H	;..#...
  .db	02H	;.#....
  .db	1EH	;.####.
  .db	00H	;......

; 7BH "{"
  .db	10H	;....#.
  .db	08H	;...#..
  .db	08H	;...#..
  .db	04H	;..#...
  .db	08H	;...#..
  .db	08H	;...#..
  .db	10H	;....#.
  .db	00H	;......

; 7CH "|"
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	00H	;......
  .db	08H	;...#..
  .db	08H	;...#..
  .db	08H	;...#..
  .db	00H	;......

; 7DH "}"
  .db	04H	;..#...
  .db	08H	;...#..
  .db	08H	;...#..
  .db	10H	;....#.
  .db	08H	;...#..
  .db	08H	;...#..
  .db	04H	;..#...
  .db	00H	;......

; 7EH "~"
  .db	00H	;......
  .db	00H	;......
  .db	04H	;..#...
  .db	2AH	;.#.#.#
  .db	10H	;....#.
  .db	00H	;......
  .db	00H	;......
  .db	00H	;......

; 7FH "?"
  .db	3EH	;.#####
  .db	3EH	;.#####
  .db	3EH	;.#####
  .db	3EH	;.#####
  .db	3EH	;.#####
  .db	3EH	;.#####
  .db	3EH	;.#####
  .db	00H	;......


;========================================================
;		Test klávesnice bez čekání
;========================================================
;RET:	Z => nic není stisknuto nebo byl přijat znak do 8251
;	NZ, A = ASCII = kód stisknuté klávesy
;ruší:	HL, DE, BC, AF


INKEY:	LD	HL,(OLDKEY)	;H = čítač, L = minulý stav brány B
	DEC	H		;snížit čítač
	JP	M,L8A2E		;nečekat

L89C7:	IN	A,(0F5H)	;načíst stav
	AND	7FH		;vymaskovat nedefinovaný bit
	CP	L		;změna stavu?
	JP	NZ,L8A20	;ANO => dekódovat novou klávesu
	IN	A,(1FH)		;status 8251
	AND	02H		;přijat bajt?
	JP	Z,L89DB		;NE => čekat
L89D6:	LD	(OLDKEY),HL	;uložit
	XOR	A		;nic není stisknuto
	RET			;návrat

L89DB:	DEC	B		;256x cykl
	JP	NZ,L89C7
	DEC	H		;H* 256 cyklů
	JP	NZ,L89C7

; Stisknutá klávesa je stále ještě držena => zopakovat

	LD	H,7		;rychlost opakování znaků
	IN	A,(0F4H)	;číslo sloupce klávesnice
	AND	00001111B	;0..15
	LD	E,A		; do E

L89EA:	LD	(OLDKEY),HL	;nová časová konstanta
	LD	A,L		;stav sloupce klávesnice
	AND	00111111B
	LD	D,A		; do D

; Budeme hledat kód stisknuté klávesy

	LD	BC,0010H	;offset řádků v tabulce
	LD	HL,KEYMAP-10H 	;tabulka klávesnice
L89F7:	ADD	HL,BC
	LD	A,(HL)
	AND	A		;konec tabulky?
	JP	Z,INKEY		;ANO => nenalezeno => znovu
	CP	D		;hledaný kód?
	JP	NZ,L89F7	;NE => hledat dál
	LD	D,00H
	ADD	HL,DE		;přičíst řádek
	INC	HL
	CALL	BEPUK		;zapnout zvuk a LED
L8A08:	INC	D		;čekat a pípat
	JP	NZ,L8A08

	CALL	BEPUK		;vypnout pazvuk a zhasnout LED
	LD	A,(HL)		;vybrat kód klávesy
	CP	' '+1		;grafický znak?
	JP	C,L8A1C		;NE => nechat být

	IN	A,(0F5H)	;STOP?
	CPL
	RLCA
	AND	80H
	OR	(HL)		;při podržení STOP přičte 80H
L8A1C:	LD	(ASCII),A	;uložit kód klávesy
	RET

L8A20:	LD	E,00H		;256x
L8A22:	IN	A,(0F5H)	;status klávesnice
	AND	7FH
	CP	L		;původní stav?
	JP	Z,L89DB		;ANO => opakovat znak
	DEC	E		;256x
	JP	NZ,L8A22

L8A2E:	LD	E,15		;číslo sloupce 14..0
L8A30:	DEC	E
	LD	H,00H
	JP	M,L89D6		;konec klávesnice
	IN	A,(1FH)		;test stavu 8251
	AND	02H		;přijat znak?
	JP	NZ,L89D6	;ANO => návrat
	IN	A,(0F4H)	;načíst stav brány
	AND	11110000B	;ponechat bity 4..7
	OR	E		;+ sloupec
	OUT	(0F4H),A	;zvolit sloupec
	IN	A,(0F5H)	;načíst stav sloupce klávesnice
	AND	7FH		;vymaskovat nedefinovaný bit
	LD	L,A		;uložit do L
	CPL
	AND	1FH		;nějaká klávesa?
	JP	Z,L8A30		;NE => testovat další sloupec

; Stisknuta klávesa

	LD	H,80		;čas odezvy opakování
	JP	L89EA		;vydekódovat kód klávesy

;========================================================
;		Načtení čísla souboru
;========================================================

DECPAR:	LD	HL,L82B0	;text "Error in data"
	LD	(MESS),HL
	LD	HL,(CURCH)	;adresa textu příkazu
	CALL	PAIRIN		;načíst A šestnáctkové
	RET	C		;chyba

	INC	HL		;přeskočit znak za číslem
	LD	(CURCH),HL
	CP	9AH
	CCF			;>9AH
	RET	C		;chyba

; Převod šestnáctkového čísla na dekadické

	LD	C,A
	RRCA
	RRCA
	RRCA
	RRCA			;bity 4..7 do 0..3
	AND	00001111B
	ADD	A,A		;*10
	LD	B,A
	ADD	A,A
	ADD	A,A
	ADD	A,B
	LD	B,A
	LD	A,C
	AND	00001111B
	ADD	A,B		;a je to hotovo!!!

	PUSH	HL
	LD	HL,0C300H	;JP DECP1
	LD	(RAM),HL
	LD	HL,DECP1	;RET
	LD	(RAM+2),HL
	POP	HL
DECP1:	RET

;========================================================
;		Pípnutí a tisk hlášení
;========================================================
;CALL:	MESS = adresa textu hlášení

PRTTEXT:
	CALL	BEEP		;pípnout
	JP	L8E48		;vypsat text hlášení

;========================================================
;	Příkaz   SUB - uložení několika bajtů do paměti
;========================================================

SUB:	LD	HL,L82B0	;text "Error in data"
	LD	(MESS),HL
	CALL	RADR		;načíst adresu do DE
L8A98:	CALL	SSKIP		;přeskočit mezery
	CP	CR		;konec textu?
	JP	Z,SUB03		;vypsat následující adresu
	CP	0x27		;text v apostrofech?
	JP	Z,L8AB0		;ANO
	CALL	PAIRIN		;načíst šestnáctkový bajt
	JP	C,PRBWTXT	;chyba => vypsat a ukončení funkce
	LD	(DE),A		;zapsat bajt
	INC	DE
	JP	L8A98		;cykl

L8AB0:	INC	HL
L8AB1:	LD	A,(HL)		;načíst znak
	CP	CR		;konec textu?
	INC	HL
	JP	Z,SUB03		;ANO => vypsat další adresu
	CP	0x27		;konec textu?
	JP	Z,L8A98		;ANO => další čtení
	LD	(DE),A		;zapsat znak
	INC	DE
	JP	L8AB1		;cykl

;========================================================
;	Zápis textu řádky do funkčních kláves
;========================================================
;CALL:	C = kód klíče

SETWRK:	CALL	BEEP		;zabzučet
	CALL	CURPOS		;adresa kurzoru v editačním bufferu
L8AC8:	LD	B,L		;uložit pozici X
	LD	HL,L8433	;text "Memory overflow"
	LD	(MESS),HL
	LD	HL,(KEYEND)	;vrchol tabulky klíčů
L8AD2:	DEC	HL
	LD	A,(HL)
	OR	A		;konec tabulky klíčů?
	JP	Z,L8AF6		;ANO
	CP	C		;hledaný klíč?
	JP	NZ,L8AD2	;NE => hledat dál

; Zvolený klíč byl v tabulce klíčů nalezen => smaže se

	LD	D,H		;adresu nalezeného klíče do DE
	LD	E,L

; Přeskočit text nalezeného klíče

L8ADE:	DEC	HL
	LD	A,(HL)		;bajt z tabulky
	OR	A		;konec tabulky?
	JP	Z,L8AF7		;ANO
	JP	P,L8ADE		;znak => přeskočit
	CP	0A0H
	JP	NC,L8ADE	;znak => přeskočit

L8AEC:	LD	A,(HL)		;přenést zbytek tabulky vzhůru
	LD	(DE),A
	DEC	HL
	DEC	DE
	OR	A		;konec tabulky?
	JP	NZ,L8AEC	;NE => přenášet dál
	INC	DE
	EX	DE,HL
L8AF6:	EX	DE,HL

; v DE je adresa aktuálního konce tabulky klíčů

;  Následuje test překročení povolené spodní hranice tabulky,
; ale nebere se v úvahu délka vkládaného klíče!
;  Tabulka klíčů může hranici KEYTOP překročit o délku
; editační řádky (tj. o 80 znaků).

L8AF7:	LD	HL,(KEYTOP)	;Spodní hranice tabulky
	LD	A,E		;porovnání DE-HL
	SUB	L
	LD	A,D
	SBC	A,H
	JP	C,ERROR		;DE < HL => "Memory overflow"

	LD	HL,(KEYEND)	;začátek tabulky
	EX	DE,HL
	DEC	B		;prázdný klíč?
	JP	M,L8B14		;ANO => POUZE se smazal
	INC	B		;NE
	LD	(HL),C		;zapsat do tabulky kód klíče
	DEC	HL
L8B0C:	LD	A,(DE)		;přenést text klíče
	LD	(HL),A
	DEC	HL
	INC	DE
	DEC	B		;snížit čítač
	JP	NZ,L8B0C	;cykl

L8B14:	LD	(HL),0		;konec tabulky je označen 0

WRKCLR:	LD	HL,SWRK		;smazat příznak WRK
	LD	(HL),0
	RET

;========================================================
;	Vyslání bloku 128 bajtů do seriové linky
;========================================================
; Vyvolá se přijetím kódu CTRL-B v módu terminál.

OUTMEM:	CALL	INHL		;přijmout adresu dat
	LD	D,10H		;počkat
	CALL	WAITS
; D=0

	LD	DE,128		;počet bajtů
L8B27:	LD	B,(HL)		;načíst bajt z paměti
	CALL	L8B36		;vyslat bajt
	INC	HL
	ADD	A,D		;přičíst kontrolní součet
	LD	D,A
	DEC	E		;128x
	JP	NZ,L8B27

	LD	B,D		;vyslat kontrolní součet

L8B33:  .db	3AH		;LD A,(nn)
	LD	B,'Q'-'@'
L8B36:	IN	A,(1FH)		;test stavu 8251
	AND	01H		;volný vysílač
	JP	Z,L8B36		;NE -> čekat
	LD	A,B
	OUT	(1EH),A		;vyslat bajt
	RET

;========================================================
;		Inicializace 8251 a 8253
;========================================================

I82531:	LD	HL,0020H
;8253: 60000 Hz (ticho do magnetofonu)
;8251: nepodstatné

L8B44:	XOR	A
;8253: frekvence podle HL
;8251: /1, 8 bitů, bez parity, 2 STOP, TxEN, /DTR, /RTS

L8B45:  .db	1		;LD BC,nn

	SCF
;8253: frekvence seriové linky (SPEED)
;8251: /16, 8 bitů, bez parity, 2 STOP, TxEN, RxEN, /RTS
	LD	HL,(SPEED)
			  	;LD   A,H
				;RET  NZ

	LD	A,00H		;příprava 8251 před SOFT RESET
	OUT	(1FH),A
	LD	A,40H		;SOFT RESET 8251
	OUT	(1FH),A
	LD	A,0EDH		;8251: magnetofon
	LD	C,23H
	JP	NC,L8B5C
	INC	A		;8251: seriová linka"
	INC	C
	INC	C
L8B5C:	OUT	(1FH),A
	LD	A,C
	OUT	(1FH),A

	LD	A,76H		;8253: mód 3, symetr. dělička
	OUT	(5FH),A
	LD	A,L		;HL = dělící poměr
	OUT	(5DH),A
	LD	A,H
	OUT	(5DH),A
	RET

;========================================================
;		Načtení bajtu z magnetofonu
;========================================================
;RET:	CY => timeout, STOP
;	NC => A = načtení bajt
;ruší:	AF

BYTE:	PUSH	BC		;uschovat registry
	PUSH	DE
	PUSH	HL

	LD	HL,(LCHAR)	;H = fáze, L =  délka pulzu

; Načtení START bitu
L8B72:	LD	C,26H
	CALL	SCAN		;čekej na změnu
	SCF
	JP	Z,L8B98		;chyba: timeout, STOP
	LD	A,C
	CP	L		;příliš krátký puls
	JP	P,L8B72

L8B80:	LD	DE,007FH	;D = stav, E = čítač 8x
L8B83:	CALL	SCAN2		;čekej na změnu
	LD	A,C
	CP	L		;1/0?
	JP	C,L8B8E+1
	CALL	SCAN2
L8B8E:  .db	26H		;LD H,n
	INC	D
	LD	A,D		;bit 0 v D nese informaci
	RRCA			;informační bit do CY
	LD	A,E		;do E
	RRA
	LD	E,A
	JP	C,L8B83		;8x bit => bajt

L8B98:	POP	HL		;obnovit registry
	POP	DE
	POP	BC
	RET

;========================================================
; Příkaz MGLD - načtení binárního souboru z magnetofonu
;========================================================

MGLD:	LD	A,(MGCHAR)
  .db	2EH		;LD L,n

;========================================================
; Příkaz MGEND - kontrola binárního souboru z magnetofonu
;========================================================
; Provede pouze kontrolu kontrolního součtu.

MGEND:	XOR	A
	LD	(FINDTP),A	;příznak čtení/kontrola
	CALL	DECPAR		;načti číslo souboru do A
	JP	C,PRBWTXT	;chyba "Error in data"
	LD	(FINDNR),A	;uložit číslo hledaného souboru
	CALL	SHEAD		;načtení celého souboru
	JP	C,SYST3		;chyba
	JP	NZ,SYST3	;chyba

; Soubor byl v pořádku načten nebo zkontrolován

	CALL	CLR		;smazat editační řádek
	JP	BEEP		;pípnout, návrat do hlavní smyčky

;========================================================
;	Povel JUMP v módu terminál
;========================================================
; Načte ze seriové linky adresu podprogramu, na který skočí

BRANCH:	CALL	INHL		;načíst adreso do HL
	PUSH	HL		;uložit
	CALL	ERASE		;smazat celou obrazovku
	POP	DE		;adresa podprogramu
	POP	HL		;xxx
	LD	HL,TERM		;adresa hlavní smyčky kódu terminál
	PUSH	HL
	EX	DE,HL
	JP	(HL)		;skok na podprogram

;========================================================
;		Čekací smyčka
;========================================================
;CALL:	A,D = čas: A*43.5usec + D*10 msec.
;ruší:	AF, D

WAITS:	EX	(SP),HL
	EX	(SP),HL
	EX	(SP),HL
	EX	(SP),HL
	DEC	A		;cykl A*
	JP	NZ,WAITS
	DEC	D		;cykl D*
	JP	NZ,WAITS
	RET

;========================================================
;	Pokus o ochranu souboru proti přečtení
;========================================================
; Po RESETu se testuje, zda na adrese OCHR = C1F1H
; není znak "*". Pokud zde tento znak je, smaže se celá paměť.
; Tato funkce se využívá pouze v BASICu pro ochranu
; kvalitních, špičkových, jedinečných, neopakovatelných
; programátorských výplodů.

OCHRAN:	LD	HL,0000H	;čím mazat paměť
L8BDB:	PUSH	HL
	LD	A,(OCHR)
	CP	'*'
	JP	Z,L8BDB		;smazat celou paměť

	LD	SP,START	;obnovit SP
	LD	DE,INITAB
	JP	MONLL		;pokračování inicializace

L8BED:	NOP			;pro zachování adres

;========================================================
;		Vstup řádky s editací
;========================================================

ENTER:	NOP
	NOP
	NOP
L8BF1:	CALL	WRBUFF		;vypsat editační řádek
	POP	HL		;vybrat návratovou adresu
	LD	(RETCLL),HL	;uložit ji
	LD	HL,0000H	;načíst SP
	ADD	HL,SP
	JP	ENTER1		;pokračování jinde

L8BFF:	NOP			;pro zachování adres

;========================================================
;		Načtení bloku dat z ROM-PACKu
;========================================================
;CALL:	parametry jsou v programu za voláním CALL TRANSFER
; .dw	adresa začátku v ROM-PACKu
; .dw	počet čtených bajtu -1
; .dw	adresa začátku v RAM pro načtení

; Počet bajtů je nyní definován jinak než tomu bylo u PMD-85-1!

TRANSFER:
ROMIN:	LD	A,90H		;inicializace 8255 v ROM-PACKu
	OUT	(0FBH),A	;a zapnutí +12V do ROM
	EX	(SP),HL		;adresa parametrů do HL
	LD	A,(HL)		;nižší bajt adresy
	OUT	(0F9H),A	;nastavit
	INC	HL
	LD	A,(HL)		;vyšší bajt adresy
	OUT	(0FAH),A	;nastavit
	INC	HL
	LD	C,(HL)		;načíst počet bajtů dat do BC
	INC	HL
	LD	B,(HL)
	INC	B		;délka + 100H
	INC	HL
	LD	E,(HL)		;adresa RAM pro načtení do DE
	INC	HL
	LD	D,(HL)
	INC	HL		;na instrukci za tabulku parametrů
L8C16:	IN	A,(0F8H)	;načíst bajt dat
	LD	(DE),A		; a uložit do RAM
	INC	DE		;další adresa do RAM
	DEC	BC		;snížit čítač bajtů
	IN	A,(0F9H)	;zvýšit adresu v ROM-PACku
	INC	A
	OUT	(0F9H),A
	JP	NZ,L8C28	;nižší bajt nebyl překročen
	IN	A,(0FAH)	;zvýšit i vyšší bajt adresy
	INC	A
	OUT	(0FAH),A
L8C28:	LD	A,B		;test B na 0
	OR	A
	JP	NZ,L8C16	;B není nula => číst dál

; Normální programátor by test realizoval takto:
;    LD  A,B
;    OR  C
; takže by počet bajtů v parametrech přesně odpovídal,
; a ještě by se ušetřil bajt kódu.
; Proč to dělat jednoduše, když to jde i složitě.

	LD	A,0FFH		;vypnutí +12V do ROM
	OUT	(0FAH),A
	EX	(SP),HL		;návratovou adresu na zásobník
	RET			;návrat do programu za tabulku parametrů

;========================================================
;	Posun kurzoru v editační řádce doleva
;========================================================
LEFT:	LD	HL,DCUR		;pozice kurzoru v bufferu
	DEC	(HL)		;snížit
	RET	P		;>=0 => návrat
	INC	(HL)		;na 0

;========================================================
;	Posun zobrazované části řádku doprava
;========================================================
RRIGHT:	LD	HL,RPOS		;první vypsaný znak
	DEC	(HL)		;snížit
	RET	P		;>=0 => návrat
	INC	(HL)		;na 0
	RET

MONIT:	JP	MON1		;původní vstup do monitoru

;========================================================
;	Provedení změny v editační řádce
;========================================================
;CALL:	ASCII = řídící nebo grafický znak
;RET:	změněný text v editačním bufferu

DOKEY:	LD	A,(ASCII)	;znak
	LD	B,A
	CP	0A0H		;80H..9FH jsou kódy funkčních kláves
	JP	NC,CHAR
	CP	80H
	JP	NC,KEY		;stisknuta funkční klávesa
	CP	20H		;řídící kód?
	CALL	WRKCLR		;smazat příznak klávesy WRK
	JP	NC,CHAR		;NE => grafický znak

; B = řídící znak 00..1FH

	LD	HL,(KDIR)	;adresa tabulky adres podprogramů -2
L8C5C:	INC	HL		;HL+2
	INC	HL
	LD	A,(HL)		;kód
	AND	A		;je to 0?
	RET	Z		;ANO => konec tabulky => ignorovat kód
	INC	HL
	CP	B		;je to hledaný kód?
	JP	NZ,L8C5C	;NE => hledat dál
L8C66:	LD	B,(HL)		;kód byl nalezen, vybrat adresu
	INC	HL
	LD	H,(HL)
	LD	L,B
	JP	(HL)		;skok na podprogram

; Na tomto podprogramu předvedl autor, jak lze zvolením chybného
; algoritmu podprogram zesložitit. Použitím jednoduché tabulky
; 32 adres podprogramů by se ušetřilo 16 bajtů.


;========================================================
;		Cyklická změna atributu
;========================================================
MODCOL:	LD	A,(COLOR)	;atribut
	ADD	A,40H		;4 módy: 00,40,80,C0
	LD	(COLOR),A	;modifikovaný atribut
	RET

;========================================================
;		Test klávesy STOP
;========================================================
;RET:	Z,  A=3   => STOP je stisknuto
;	NZ, A=40H => STOP není stisknuto

STOP:	IN	A,(0F5H)	;status klávesnice
	AND	40H		;STOP je v bitu 6
	RET	NZ		;STOP není stisknuto
	LD	A,03H		;volajaký kód
	RET			;STOP je stisknuto

L8C7C:	NOP			;pro zachování adres

;========================================================
;	Vykreslení bodu v daném grafickém módu
;========================================================
;CALL:	X1 = souřadnice X
;	Y1 = souřadnice Y

POINT:	PUSH	BC		;uschovat adresy
	PUSH	DE
	PUSH	HL
	LD	HL,ADRRET	;návrat: POP HL,DE,BC; RET
	PUSH	HL

L8C84:	LD	HL,(Y1-1)	;souřadnice Y do H
	LD	A,(X1)		;souřadnice X do L
	LD	L,A
	PUSH	HL		;uschovat souřadnice
	CALL	POSPOINT	;vypočítat adresu do displeje
	CALL	VYSTUP		;vykreslit bod
	POP	DE		;souřadnice X,Y
	RET			;=> POP HL,DE,BC; RET

;========================================================
;	Výpočet adresy bodu v displeji
;========================================================
;CALL:	L - souřadnice X (0..255)
;	H = souřadnice Y (0..255)
;RET:	HL = adresa bajtu v displeji
;	B = bitová maska (1,2,4,8,10H,20H)
;ruší:	HL,DE,BC,AF

POSPOINT:
	PUSH	HL
	LD	A,(COLOR)	;atribut výstupu
	AND	0C0H
	LD	(PLOTCOL),A	;modifikovat program
	LD	H,00H
	LD	C,L		;souřadnice X
	LD	B,H		;0 do H
	INC	HL		;X+1
	LD	D,H
	LD	E,L
	ADD	HL,HL		;*2
	ADD	HL,HL		;*4
	ADD	HL,DE		;*5
	ADD	HL,HL		;*10
	ADD	HL,HL		;*20
	ADD	HL,DE		;*21
	ADD	HL,HL		;*42
	ADD	HL,HL		;*84
	ADD	HL,DE		;*85 <=> /3
	LD	A,0FEH
	AND	H
	RRCA			;/2
	LD	E,A
	LD	A,E		;?????
	ADD	A,A		;*2
	ADD	A,E		;*3
	ADD	A,A		;*6
	SUB	C		;-(X MOD 6)
	CPL			;NEG
	INC	A
	LD	C,A		;X MOD 6 do C
	LD	D,0C0H		;vyšší bajt adresy displeje
	INC	E
	INC	E
	LD	HL,L88BA	;tabulka bitových masek
	ADD	HL,BC		;indexovat do tabulky
	LD	B,(HL)		;vybrat masku do B
	POP	HL		;souřadnice X,Y
	LD	L,H		;Y do L
	LD	H,00H
	ADD	HL,HL		;Y*2
	ADD	HL,HL		;*4
	ADD	HL,HL		;*8
	ADD	HL,HL		;*16
	ADD	HL,HL		;*32
	ADD	HL,HL		;*64
	ADD	HL,DE		;+ SCREEN + X DIV 6
	RET

L8CCF:	NOP			;pro zachování adres

;========================================================
;		Lineární interpolátor
;========================================================
;CALL:	X1,Y1 = souřadnice počátečního bodu
;	X2,Y2 = souřadnice koncového bodu

; Tento podprogram je napsán nezvykle kvalitně a je velmi rychlý.

INPOL:
PLOT:	CALL	L8C84		;vykreslit počáteční bod
; DE = souřadnice počátečního bodu
	LD	HL,(X2)		;souřadnice koncového bodu
	LD	A,L		; zapsat do X1,Y1
	LD	(X1),A
	LD	A,H
	LD	(Y1),A

; úsečka se kreslí vždy zprava doleva

	LD	A,L
	SUB	E		;X2-X1
	JP	NC,L8CE6	;X2 >= X1
	LD	A,E
	SUB	L
	EX	DE,HL		;prohodit body
L8CE6:	LD	B,A		;rozdíl DX

; Podle směru  nahoru / dolů připravit offset + / - 40H

	LD	A,H
	SUB	D
	LD	DE,-40H		;zdola nahoru
	JP	NC,L8CF4
	LD	DE,0040H	;shora dolu
	CPL			;NEG DY
	INC	A
L8CF4:	LD	C,A		;;rozdíl DY

	EX	DE,HL
	LD	(STACK),HL	;uložit řádkový offset
	EX	DE,HL
	LD	D,B		;DX
	LD	E,A		;DY
	INC	E		;DY+1
	PUSH	DE
	PUSH	BC
	CALL	POSPOINT	;adresa do displeje do HL
	LD	D,B		;bitová maska počátečního bodu
	POP	BC
	LD	E,B		;DX
	LD	B,D		;bitová maska
	LD	A,E		;DX-DY
	CP	C
	JP	NC,L8D15

; DY > DX

	OR	A		;NC
	RRA			;DX/2
	SUB	C		;DX/2-DY
	LD	E,A		;?????
	DEC	E		;DX/2-DY-1
	LD	A,E		;?????
	POP	DE
	JP	L8D42

;DX >= DY

L8D15:	LD	A,C
	RRA			;DY/2
	SUB	E		;DY/2-DX
	CPL			;NEG
	LD	E,A
	INC	E		;DX-DY/2
	LD	B,00H
L8D1D:	LD	A,B
	ADD	A,D
	LD	B,A
L8D20:	LD	A,D
	RRCA
	LD	D,A
	JP	NC,L8D2E
	CALL	VYSTUP		;nakreslit bod
	DEC	HL
	LD	D,20H
	LD	B,00H
L8D2E:	SCF
	LD	A,E
	SBC	A,C
	LD	E,A
	JP	NC,L8D1D

L8D35:	CALL	VYSTUP		;vykreslit bod
	LD	B,D
	LD	A,E
	EX	DE,HL
	LD	HL,(STACK)	;řádkový offset +/- 40H
	ADD	HL,DE		;modifikovat adresu do displeje
	POP	DE		;D=DX, E=DY+1
	DEC	E		;snížit čítač bodů
	RET	Z		;konec interpolace

L8D42:	PUSH	DE
	SCF
	ADC	A,D
	LD	E,A
	LD	D,B
	JP	NC,L8D35
	JP	L8D20

;========================================================
;		Výmaz znaku pod kurzorem
;========================================================

DEL:	CALL	ENDLN		;adresa posledního znaku do HL
	LD	C,L		;uschovat
	CALL	CURPOS		;adresa znaku pod kurzorem do HL
	LD	D,H
	LD	E,L
	INC	DE		;na následující znak
	LD	A,C
	CP	E		;poslední znak?
	JP	C,L8D65		;ANO
L8D5C:	LD	A,(DE)		;přenést znak
	LD	(HL),A

; Test konce textu je zbytečně složitý šlo by to lépe

	LD	A,C		;poslední znak?
	CP	E
	INC	HL
	INC	DE
	JP	NZ,L8D5C	;NE => přenášet dál
L8D65:	LD	(HL),' '	;vymazat poslední znak
	RET

L8D68:	JP	$		;????? nekonečná smyčka ?????

L8D6B:	NOP			;pro zachování adres

;========================================================
;	Zápis bloku dat na magnetofon
;========================================================
;CALL:	HL = adresa začátku bloku dat
;	DE = počet bajtů-1
;ruší:	HL,DE,BC,AF

TAPEOUT:
	INC	DE		;o bajt víc
	LD	B,00H		;nulovat kontrolní součet

L8D6F:	LD	A,(HL)		;bajt dat
	CALL	USARTOUT	;zapsat na magnetofon
	LD	A,(HL)		;bajt dat
	ADD	A,B		;modifikovat kontrolní součet v B
	LD	B,A
	INC	HL		;na další bajt dat
	DEC	DE		;snížit čítač bajtů
	LD	A,D		;DE=0?
	OR	E
	JP	NZ,L8D6F	;NE => cykl
	LD	A,B		;kontrolní součet

;========================================================
;		Zápis bajtu do 8251
;========================================================
;CALL:	A = bajt
;ruší:	AF

; V okamžiku volání musí být 8251 volná!
; Napřed se zapíše bajt dat, potom se teprve testuje status.
; Je zvykem to dělat obráceně.

USARTOUT:
	OUT	(1EH),A		;napřed zapsat bajt dat
L8D80:	IN	A,(1FH)        	; a pak testovat status 8251
	RRCA			;TxRDY?
	JP	NC,L8D80	;NE => čekat
	RET

L8D87:  .db	"++ No command ++",CR

;========================================================
;	Ukončení editace v textovém bufferu
;========================================================

EOL:	CALL	ENDLN		;adresa konce textu do HL
	PUSH	HL
	LD	B,L
	LD	HL,(BUF)	;začátek editačního bufferu
	EX	DE,HL		; do DE
	LD	HL,(ODLOZ)	;začátek výstupního bufferu
	LD	A,(SPTL)	;příznak PTL do C
	LD	C,A
L8DA8:	LD	A,(DE)		;přenést znak
	LD	(HL),A
	INC	HL
	INC	DE
	INC	C		;test příznaku PTL
	CALL	NZ,PRTOUT	;PTL zapnut => tisk znaku
	DEC	C
	DEC	B		;snížit čítač znaků řádky
	JP	P,L8DA8		;cykl
	LD	(HL),CR		;text je ukončen CR
	INC	C		;test příznaku PTL
	CALL	NZ,L84FD+1	;vypsat CR
	POP	HL		;adresa konce textu
	LD	C,87H		;pomocný klíč: RCL
	INC	HL
L8DBF:	JP	L8AC8		;uložit do tabulky klíčů

;========================================================
;		Načtení bloku dat z magnetofonu
;========================================================
;CALL:	HL = počáteční adresa pro načtení
;	DE = počet bajtů -1
;RET:	blok dat v paměti
;	Z => načteno v pořádku,
;	NZ => chyba při čtení nebo STOP
;ruší:	DE,BC,AF

LOAD:	LD	C,0FFH		;příznak LOAD
L8DC4:	PUSH	HL
	LD	B,00H		;vynulovat kontrolní součet
L8DC7:	CALL	BYTE		;načíst bajt
	JP	C,ADRR1T	;chyba při čtení
	INC	C		;LOAD/VERIFY?
	DEC	C
	JP	Z,L8DD3		;VERIFY
	LD	(HL),A		;LOAD => zapsat bajt
L8DD3:	INC	HL
	ADD	A,B		;modifikovat kontrolní součet v B
	LD	B,A
	LD	A,D		;test DE na 0
	OR	E
	DEC	DE
L8DD9:	JP	NZ,L8DC7	;cykl
	CALL	BYTE		;načíst kontrolní součet
	XOR	B		;porovnat
	POP	HL		;počáteční adresa
	RET

;========================================================
;		Vyhledaní a načtení souboru
;========================================================
;RET:	HEAD = hlavička souboru
;	C,NZ => chyba

SHEAD:	LD	HL,L8413	;text "File error"
	LD	(MESS),HL
	CALL	HEADIN		;načíst synchronizaci a hlavičku
	RET	C		;chyba => návrat

	LD	DE,HEAD		;načtená hlavička
	LD	A,(DE)		;číslo souboru
L8DF0:	CALL	BINDEC		;konverze
	LD	HL,(BUF)	;ukazatel do textového bufferu
	CALL	PREV02		;výstupní konverze
	LD	A,00H
	LD	(DCUR),A
	INC	HL
	LD	(HL),'/'	;za číslo souboru dá '/'
	INC	HL
	INC	DE
	LD	A,(DE)		;typ souboru
	LD	(HL),A		;vypisuje se
	INC	HL
	LD	(HL),' '
	INC	HL
	LD	DE,NAMFIL	;adresa názvu
	EX	DE,HL
	CALL	TEXTTH		;přenést text názvu
	CALL	WRBUFF		;vypsat připravený řádek

	LD	HL,(HEAD)	;L=číslo, H=typ
	LD	A,(FINDNR)	;číslo hledaného souboru
	AND	A		;0 => číst vše
	JP	Z,L8E21
	CP	L		;porovnání čísla
	JP	NZ,L8E3A	;jiný => hledat dál
L8E21:	LD	A,(FINDTP)	;typ hledaného souboru
	AND	A		;0 => číst vše
	LD	C,A
	JP	Z,L8E2D
	CP	H		;porovnání typu
	JP	NZ,L8E3A

L8E2D:	LD	HL,(LENFIL)	;počet bajtů-1
	EX	DE,HL	; do DE
	LD	HL,(ADRFIL)	;zaváděcí adresa
	CALL	RAM		;=> RET
	JP	L8DC4		;načíst soubor do paměti

;-------Nalezen jiný soubor -------

L8E3A:	CALL	EOL		;na začátek řádky
	CALL	BEEP		;pípnout
	JP	SHEAD		;hledat dál

;========================================================
;		Výpis chybového hlášení
;========================================================
;CALL:	MESS - adresa textu

PRBTXT:	PUSH	HL
ERROR:	CALL	BEEP		;pípnout
	POP	HL

L8E48:	LD	HL,(MESS)	;adresa textu
L8E4B:	EX	DE,HL
	LD	HL,(CDBUF)	;adresa textového bufferu.
	LD	B,48
	EX	DE,HL
	CALL	TEXTSP		;připravit text do bufferu
	PUSH	HL

;========================================================
;	Funkce C-D - vypiš posledního chybového hlášení
;========================================================
CD:	POP	HL
	LD	HL,(CDBUF)	;začátek textu v bufferu
	JP	WRLINE		;vypsat text

;========================================================
;	Vyhledání konce textu v editačním bufferu
;========================================================
;CALL:	DLZRAD = konec textu editačního řádku
;RET:	HL = adresa posledního platného znaku řádky
;ruší:	HL,AF

; Od konce řádky přeskakuje mezery.
; Na konec textu řádky nelze tedy mezery zapsat.

ENDLN:	LD	HL,(DLZRAD)	;adresa konce editačního bufferu
L8E60:	LD	A,' '
	CP	(HL)		;mezera?
	JP	NZ,L8E6A	;NE
	DEC	L		;na předchozí znak
	JP	NZ,L8E60	;cykl
L8E6A:	LD	A,H		;uložit H
	LD	H,00H
	LD	(LSTR),HL	;počet znaků
	LD	H,A		;obnovit H
	RET

L8E72: NOP			;pro zachování adres

;========================================================
;	Konverze kódu BCD na binární
;========================================================
;CALL:	A = BCD kód
;RET:	A = binární kód
;ruší:	HL,B,AF

BINDCD:
BINDEC:	LD	H,A
	LD	B,08H
	XOR	A
L8E77:	ADD	HL,HL
	ADC	A,A
	DAA
	DEC	B
	JP	NZ,L8E77
	RET

;========================================================
;	Zápis bloku paměti do souboru na magnetofon
;========================================================

MGSV:	CALL	DECPAR	;načíst číslo souboru
	JP	C,PRBWTXT	;chyba
	LD	HL,SYST3	;návratová adresa
	PUSH	HL
	LD	L,A		;číslo souboru
	LD	A,(MGCHAR)	;typ souboru
	LD	H,A
	LD	(HEAD),HL
	CALL	RADR		;načíst počáteční adresu
	EX	DE,HL		;do HL
	LD	(ADRFIL),HL
	PUSH	HL
	LD	HL,CURCH	;přeskočit jeden znak
	INC	(HL)
	CALL	RADR		;načíst koncovou adresu
	POP	HL		;počáteční adresa

SAVE:	LD	A,E		;konec-začátek => počet bajtů
	SUB	L
	LD	L,A
	LD	A,D
	SBC	A,H
	LD	H,A		;počet bajtů do HL
	JP	C,PRBWTXT	;chyba (konec menší než začátek)
	LD	(LENFIL),HL	;délka bloku
	LD	HL,(CURCH)	;přeskočit jeden znak
	INC	HL
	CALL	TEXTHEAD	;načíst název souboru
	CALL	PRGOUT		;zapsat celý soubor
	LD	HL,L8404	;text "Mg STOP"
	LD	(MESS),HL
	RET

;========================================================
;	Načtení synchronizace a hlavičky souboru
;========================================================
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; verze 2A se lisi v techto bytech od 0x8EBF do 0x8F25
.if MONVER != 0x2A

HEADIN:	CALL	BECLR		;vypnout zvuk
	LD	D,13H		;inicializační délka pulzů
	LD	B,A
L8EC4:	IN	A,(0F5H)	;klávesnice
	CPL
	RLCA
	RLCA
	RET	C		;stisknuto STOP
	CALL	SCAN2		;čekat na hranu na vstupu
	LD	A,C		;délka pulzu
	CP	D
	JP	M,HEADIN	;příliš dlouhý puls nebo timeout
	DEC	B		;256x
	JP	NZ,L8EC4	;načíst 256 správných pulzů
	SUB	04H		;délka krátkého pulzu
	LD	D,A
L8ED9:	LD	L,C
	CALL	BEPUK		;invertovat zvukový bit
	CALL	SCAN2		;čekat na změnu na vstupu
	IN	A,(0F5H)	;klávesnice
	CPL
	RLCA
	RLCA
	RET	C		;stisknuto STOP
	LD	A,C
	CP	D
	JP	P,L8ED9		;stále krátké pulzy

;-------Přišel první START bit -------

	SUB	04H
	ADD	A,L
	RRA
	LD	L,A		;vypočtena rozhodovací délka pulzů
	LD	(LCHAR),HL	;uložit střed a fázi
	CALL	BYTE1		;načíst 1.bajt
	CALL	BECLR		;vypnout zvuk
	
L8EF9:
  JP	C,HEADIN	;chyba => znovu
	CALL	BYTE		;načíst bajt
	AND	A		;0?
	JP	NZ,L8EF9	;NE => ignorovat
L8F03:	CALL	BYTE		;načíst bajt
	JP	C,HEADIN	;Chyba => znovu
	CP	55H		;poslední sync je 16X55H
	JP	NZ,L8F03	;NE
	LD	D,0FH		;ještě 15x
L8F10:	CALL	BYTE		;načíst 15x 55H
	CP	55H
	JP	NZ,HEADIN	;NE => znovu
	DEC	D
	JP	NZ,L8F10

;------Načtena synchronizace ------

	LD	HL,HEAD		;adresa pro hlavičku
	LD	DE,000DH	;délka hlavičky-1
	CALL	LOAD		;načíst hlavičku
	JP	NZ,HEADIN	;chyba => znovu
.else
;-----------------MONITOR V2A--------------------
HEADIN:
  ld d,0x17
  ld b,0x00
L8EC2:
  in a,(0xf5)
  cpl
  rlca
  rlca
  ret c
  call  SCAN2
  ld a,c
  cp d
  jp m, HEADIN
  dec b
  jp nz,L8EC2
  sub   0x05
  ld d,a
L8ED7:
  ld l,c
  call  BEPUK
  call  SCAN2
  in a,(0xf5)
  cpl
  rlca
  rlca
  ret c
  ld a,c
  cp d
  jp p, L8ED7
  sub   0x03
  add a,l
  rra
  ld l,a
  ld   (LCHAR),hl
  call  BECLR
  call  BYTE1
L8EF7:
  inc a
  jp nz,L8F01
  call  BYTE
  jp    L8EF7
L8F01:
  call  BYTE
  jp c, HEADIN
  and a
  jp z, L8F01
  ld d, 0x0f
L8F0D:
  call  BYTE
  cp    0x55
  jp nz,HEADIN
  dec d
  jp nz,L8F0D
  ld hl,HEAD
  ld de,0x000d
  call  LOAD
  jp c, HEADIN
  jp nz,HEADIN
.endif
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	RET			;úspěšně načteno

;========================================================
;	Funkce  END - nastavení kurzoru na poslední znak
;========================================================

END:	CALL	ENDLN		;adresa posledního znaku
	LD	A,(DLZRAD)	;na posledním znaku?
	CP	L
	JP	Z,L8F34		;ANO
	INC	L		;za poslední znak
L8F34:	LD	A,(DLZR)	;počet zobrazovaných znaků v řádce
	DEC	A
	CP	L		;překročen počet?
	LD	A,L
	LD	HL,RPOS
	JP	NC,L8F48+1	;NE
	LD	C,A
	LD	A,(DLZP)
	LD	B,A
	LD	(HL),A
	LD	A,C
	SUB	B
L8F48:  .db	21H		;LD HL,nn
	LD	(HL),0		;na první znak
	LD	(DCUR),A	;pozice kurzoru
	RET

;========================================================
;	Inicializace 8255 na interfejsové desce
;========================================================
; Nastaví 8255 realizující paralelní porty.

; PA: mód 1, výstup
; PB: mód 1, výstup
; PCA: vstup
; PCB: vstup
; povolen INTR, pro výstup PA, PCA
; povolen INTR, pro vstup i výstup PB, PCB

PIO:	LD	A,0ADH
	OUT	(4FH),A
	LD	A,0DH
	OUT	(4FH),A
	LD	A,05H
	OUT	(4FH),A
	JP	ERASE	;smazat obrazovku

L8F5E:	NOP		;seno
	NOP

;========================================================
;		Zápis bloku dat do souboru
;========================================================
;CALL:	HEAD = hlavička souboru

PRGOUT:	LD	HL,(FREQ)	;rychlost (1200 Bd)
	CALL	L8B44		;nastavit 8251 a 8253
	LD	D,00H
	CALL	WAITS		;čekat => úvodní písk
	LD	A,0FFH		;zapsat 16 x FFH
	CALL	LEADER
	XOR	A		;zapsat 16 x 00H
	CALL	LEADER
	LD	A,55H		;zapsat 16 x 55H
	CALL	LEADER

	LD	HL,HEAD		;adresa hlavičky
	LD	DE,000DH	;délka hlavičky-1
	CALL	TAPEOUT		;zapsat hlavičku

	LD	D,30H		;čekat => pauza před daty
	CALL	WAITS
	CALL	RAM		;=> RET
	LD	HL,(LENFIL)	;počet bajtů dat
	EX	DE,HL
	LD	HL,(ADRFIL)	;začátek bloku dat
	JP	TAPEOUT		;vyslat blok dat

;========================================================
;	Příkaz JOB - načtení bloku dat z ROM-PACKu
;========================================================

JOB:	LD	A,90H		;inicializace 8255 v ROM-PACKu
	OUT	(0FBH),A
	CALL	RADR		;načíst adresu dat v ROM
	LD	A,E
	OUT	(0F9H),A	;nižší bajt adresy
	LD	A,D
	OUT	(0FAH),A	;vyšší bajt adresy
	CALL	RADR
	LD	B,D		;délka+100H do BC
	INC	B
	LD	C,E
	PUSH	BC
	CALL	RADR		;načíst adresu pro uložení
	LD	H,D
	LD	L,E
	POP	BC
	CALL	L8C16		;načíst data z ROM-PACKu

;========================================================
;	Přeskočit mezery v textu
;========================================================
;CALL:	HL = adresa textu
;RET:	HL = adresa textu za mezerami

SSKIP:	DEC	HL
L8FB2:	INC	HL
	LD	A,(HL)
	CP	' '		;mezera?
	JP	Z,L8FB2		;ANO => přeskočit
	RET

;========================================================
;	Editace v řádce - pokračovaní
;========================================================

ENTER1:	LD	(RETSP),HL	;uložit SP
	LD	HL,(SPVAL)	;nastavit nový SP
	LD	SP,HL

L8FC1:	LD	HL,(DIAL)
	CALL	L8161
	LD	(DCUROLD),HL	;adresa kurzoru
	CALL	XCCUR		;vykreslit kurzor
	CALL	INKLAV		;vzít znak z klávesnice
	LD	HL,(DCUROLD)
	CALL	XCCUR		;smazat kurzor
	CALL	KEYOUT		;modifikace editační řádky
	LD	A,(ASCII)	;znak z klávesnice
	CP	CR	;EOL?
	JP	NZ,L8FC1	;NE => cykl

;------ Bylo stisknuto EOL ------

	CALL	CLR		;smazat editační řádek
	CALL	WRBUFF		;vypsat smazaný editační řádek
	LD	HL,(RETSP)	;obnovit původní SP
	LD	SP,HL
	LD	HL,(RETCLL)	;návratová adresa
	JP	(HL)		;návrat

L8FEF:	NOP			;pro zachování adres

L8FF0:	RET			;zde byla inicializace grafiky PMD-85-1

;========================================================
;	Načtení bloku dat ze sériové linky do paměti
;========================================================
;CALL:	ze seriové linky: L,H adresa + 128 bajtů dat

INMEM:	CALL	INHL		;načíst adresu
	LD	B,128		;bude se číst 128 bajtů
L8FF6: 	CALL	INB		;načti bajt
	LD	(HL),A		;uložit do paměti
	INC	HL
	DEC	B
	JP	NZ,L8FF6	;cykl 128x
	RET			;návrat

	;END	START
.end
