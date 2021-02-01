; ****************************************************
; ovladač Myš602 pro PMD-85 (3rd generation)
; ****************************************************
; vstupní port: 8Ch
; formát bitů portu: PL--XXYY
; 6. 7. 2020 - výrazné úpravy => 3rd generation
;              13500-14500 čtení/sec
; ****************************************************
; ******************************************************
; Rutina pro rozpoznání pohybu myši typu 602.
; Detekce pohybu myši bez překreslování jejího kurzoru.
; ******************************************************
; Po návratu je stav L tlačítka myši přítomen
; v nejvyšším bitu reg. A (a je nastaven příznak S)
; a stav pravého tlačítka je v příznaku CY.
; Proto: JC adr => skok při P tlačítku
;        JM adr => skok při L tlačítku
; ******************************************************
; xxy .equ zero_addr - ((zero_addr + MysTab) >> 8) ; neni potreba
  .include "add_def.S"
  .section .text.mouse.base
  .global MysDriver,tbPix2Ofs,LoadXCoor,LoadYCoor,MysDea,MysX,MysY
  .global MysXMin,MysXMax,MysYMin,MysYMax,MysAdr,MysAOld,MysXCHG,MysBit
  .global tbPix2Adr,MysAct,MysActBufer,MysDPISet
  .align 0
MysDriver:
	xor a
	ld b,a		; BC = přírůstek souřadnice X
	ld c,a
	ld d,a		; DE = přírůstek souřadnice Y
	ld e,a
	dec a		; odpočet doby chodu
	ld (MysRpt),a	; (ideální je velké číslo, max. 255)
			; doba chodu nesmí být větší než 255,
			; protože pak neplatí některé
			; předpoklady u matematických úprav
MysLoop:
	in a,(mysport)	; načíst signály myši
	and 0fh		; ponechat jen clonky
MysOld:	add a,0		; plus starý stav clonek
	ld l,a		; index v tabulce přechodů
	add a,a		; starý stav se vysune z ACC
	add a,a		; a nový stav clonek se
	add a,a		; uloží do vyšší poloviny bajtu
	add a,a		; a následně do paměti jako
	ld (MysOld+1),a	; starý stav clonek
	ld h,0x01
	ld l,(hl)		; načíst LO-adr ovladače směru
	dec h		; k němu HI-adr ovladače směru
			; ve stránce 00xxh
	jp (hl)		; a skok na tento ovladač
MysQuit:			; byla změna souřadnic během cyklu?
	ld a,c		; test dX
	or e		; a dY
	ld (MysXCHG),a	; ACC=0 <=> myš bez pohybu
	ex de,hl
	call MysSenstvt	; korekce citlivosti myši v ose Y
	ex de,hl
	ld hl,(MysY)	; Y:=Y+dY (plus test pozice Y)
	add hl,de
	call TestYCoor	; test nastavených dorazů v ose Y
	ld (MysY),hl	; uložit novou hodnotu souřadnice Y
	ld h,b
	ld l,c
	call MysSenstvt	; korekce citlivosti myši v ose X
	ex de,hl
	ld hl,(MysX)	; X:=X+dX (plus test pozice X)
	add hl,de
	call TestXCoor	; test nastavených dorazů v ose X
	ld (MysX),hl	; uložit novou hodnotu souřadnice Y
	in a,(mysport)	; načíst signály myši
	add a,a		; CY=pravé tlačítko, P=levé tlačítko
	ret
; *****************************************************
; Verze převodníku citlivosti a dynamického zrychlování
; pro jednotlivá nastavení citlivosti myši
; *****************************************************
MysDPIHom:
	ld a,l		; verze převodníku pro myš 40DPI
	and a
	ret z
	dec a	
	ret z		; 0,1 => x1
	add hl,hl
	dec a
	ret z		; 2 => x2
	add hl,hl
	add hl,hl
	dec a
	ret z		; 3 => x8
	add hl,hl
	add hl,hl
	dec a
	ret		; >3 => x32
MysDPIStd:
	ld a,l		; verze převodníku pro myš 130DPI
	cp 2		; ověřeno, ergonomické
	ret c		; 0,1 => x1
	add hl,hl
	cp 4
	ret c		; 2,3 => x2
	add hl,hl
	cp 6
	ret c		; 4,5 => x4
	add hl,hl
	cp 8
	ret c		; 6,7 => x8
	add hl,hl
	ret		; >7 => x16
MysDPIEmu:
	ld a,l		; verze převodníku pro myš emulátoru
	cp 12		; ověřeno, ergonomické
	ret nc
	cp 2
	ret c
	rra
	ld l,a
	ret
; ************************************************
; Obslužné vektory pro směry pohybu myši
; musí ležet ve 256 bajtové stránce před
; tabulkou přechodových stavů clonek myši "mystab"
; tabulka "mystab" obsahuje jen LO-adr vektorů!!!
; ************************************************
mys_sv:	dec de		; Y--
mys_vv:	inc bc		; X++
mysnul:	ld hl,MysRpt
	dec (hl)
	jp nz,MysLoop
	 jp MysQuit
mys_jz:	inc de		; Y++
mys_zz:	dec bc		; X--
	ld hl,MysRpt
	dec (hl)
	jp nz,MysLoop
	 jp MysQuit
mys_sz:	dec bc		; X--
mys_ss:	dec de		; Y--
	ld hl,MysRpt
	dec (hl)
	jp nz,MysLoop
	 jp MysQuit
mys_jv:	inc bc		; X++
mys_jj:	inc de		; Y++
	ld hl,MysRpt
	dec (hl)
	jp nz,MysLoop
	 jp MysQuit
; **********************************************
; Tabulka nižších bajtů adres obslužných vektorů
; (vyšší bajt adresy obslužného vektoru je vždy!
; o jedničku menší než vyšší bajt bázové adresy
; tabulky "mystab").
; Tyto equations nepřesouvat před rutiny!!!
; **********************************************

m60	.equ mysnul	; nulová funkce
m61	.equ mys_ss	; sever
m62	.equ mys_sv	; severovýchod
m63	.equ mys_vv	; východ
m64	.equ mys_jv	; jihovýchod
m65	.equ mys_jj	; jih
m66	.equ mys_jz	; jihozápad
m67	.equ mys_zz	; západ
m68	.equ mys_sz	; severozápad

; ***********************************************************
; Bufer pro zálohu pozadí kurzoru myši. Musí končit na adrese
; dělitelné 256-ti, aby při inkrementaci LSB generoval Z=1.
; *********************************************************** 
  .section .text.mouse.bufer
  .globl MysBufer
  .align 4
  .ds    8
MysBufer: ; dost vachrlate, nutno zkontrolovat mapu - xxE8h
	.ds  24		; vlastní bufer pozadí kurzoru myši
bufer_section_end:
; ***********************************************
; Tabulka přechodových stavů clonek myši 602.
; Obsahuje LO-adr obslužných vektorů detekovaných
; směrů. Tabulka musí začínat na adrese xx00h!
; ***********************************************
	; nižší nibble adresy je nový stav clonek
	; vyšší nibble adresy je starý stav clonek
	; 01/02 v rámci nibble je svislý směr
	; 04/08 v rámci nibble je vodorovný směr
  .section .text.mouse.aligned
  .align 8
				; tabulka pro detekci pohybu
MysTab:
	.db m60 & 0xFF,m65 & 0xFF,m61 & 0xFF,m60 & 0xFF,m63 & 0xFF,m64 & 0xFF,m62 & 0xFF,m63 & 0xFF ; 00
	.db m67 & 0xFF,m66 & 0xFF,m68 & 0xFF,m67 & 0xFF,m60 & 0xFF,m65 & 0xFF,m61 & 0xFF,m60 & 0xFF
	.db m61 & 0xFF,m60 & 0xFF,m60 & 0xFF,m65 & 0xFF,m62 & 0xFF,m63 & 0xFF,m63 & 0xFF,m64 & 0xFF ; 10
	.db m68 & 0xFF,m67 & 0xFF,m67 & 0xFF,m66 & 0xFF,m61 & 0xFF,m60 & 0xFF,m60 & 0xFF,m65 & 0xFF
	.db m65 & 0xFF,m60 & 0xFF,m60 & 0xFF,m61 & 0xFF,m64 & 0xFF,m63 & 0xFF,m63 & 0xFF,m62 & 0xFF ; 20
	.db m66 & 0xFF,m67 & 0xFF,m67 & 0xFF,m68 & 0xFF,m65 & 0xFF,m60 & 0xFF,m60 & 0xFF,m61 & 0xFF
	.db m60 & 0xFF,m61 & 0xFF,m65 & 0xFF,m60 & 0xFF,m63 & 0xFF,m62 & 0xFF,m64 & 0xFF,m63 & 0xFF ; 30
	.db m67 & 0xFF,m68 & 0xFF,m66 & 0xFF,m67 & 0xFF,m60 & 0xFF,m61 & 0xFF,m65 & 0xFF,m60 & 0xFF
	.db m67 & 0xFF,m66 & 0xFF,m68 & 0xFF,m67 & 0xFF,m60 & 0xFF,m65 & 0xFF,m61 & 0xFF,m60 & 0xFF ; 40
	.db m60 & 0xFF,m65 & 0xFF,m61 & 0xFF,m60 & 0xFF,m63 & 0xFF,m64 & 0xFF,m62 & 0xFF,m63 & 0xFF
	.db m68 & 0xFF,m67 & 0xFF,m67 & 0xFF,m66 & 0xFF,m61 & 0xFF,m60 & 0xFF,m60 & 0xFF,m65 & 0xFF ; 50
	.db m61 & 0xFF,m60 & 0xFF,m60 & 0xFF,m65 & 0xFF,m62 & 0xFF,m63 & 0xFF,m63 & 0xFF,m64 & 0xFF
	.db m66 & 0xFF,m67 & 0xFF,m67 & 0xFF,m68 & 0xFF,m65 & 0xFF,m60 & 0xFF,m60 & 0xFF,m61 & 0xFF ; 60
	.db m65 & 0xFF,m60 & 0xFF,m60 & 0xFF,m61 & 0xFF,m64 & 0xFF,m63 & 0xFF,m63 & 0xFF,m62 & 0xFF
	.db m67 & 0xFF,m68 & 0xFF,m66 & 0xFF,m67 & 0xFF,m60 & 0xFF,m61 & 0xFF,m65 & 0xFF,m60 & 0xFF ; 70
	.db m60 & 0xFF,m61 & 0xFF,m65 & 0xFF,m60 & 0xFF,m63 & 0xFF,m62 & 0xFF,m64 & 0xFF,m63 & 0xFF
	.db m63 & 0xFF,m64 & 0xFF,m62 & 0xFF,m63 & 0xFF,m60 & 0xFF,m65 & 0xFF,m61 & 0xFF,m60 & 0xFF ; 80
	.db m60 & 0xFF,m65 & 0xFF,m61 & 0xFF,m60 & 0xFF,m67 & 0xFF,m66 & 0xFF,m68 & 0xFF,m67 & 0xFF
	.db m62 & 0xFF,m63 & 0xFF,m63 & 0xFF,m64 & 0xFF,m61 & 0xFF,m60 & 0xFF,m60 & 0xFF,m65 & 0xFF ; 90
	.db m61 & 0xFF,m60 & 0xFF,m60 & 0xFF,m65 & 0xFF,m68 & 0xFF,m67 & 0xFF,m67 & 0xFF,m66 & 0xFF
	.db m64 & 0xFF,m63 & 0xFF,m63 & 0xFF,m62 & 0xFF,m65 & 0xFF,m60 & 0xFF,m60 & 0xFF,m61 & 0xFF ; A0
	.db m65 & 0xFF,m60 & 0xFF,m60 & 0xFF,m61 & 0xFF,m66 & 0xFF,m67 & 0xFF,m67 & 0xFF,m68 & 0xFF
	.db m63 & 0xFF,m62 & 0xFF,m64 & 0xFF,m63 & 0xFF,m60 & 0xFF,m61 & 0xFF,m65 & 0xFF,m60 & 0xFF ; B0
	.db m60 & 0xFF,m61 & 0xFF,m65 & 0xFF,m60 & 0xFF,m67 & 0xFF,m68 & 0xFF,m66 & 0xFF,m67 & 0xFF
	.db m60 & 0xFF,m65 & 0xFF,m61 & 0xFF,m60 & 0xFF,m67 & 0xFF,m66 & 0xFF,m68 & 0xFF,m67 & 0xFF ; C0
	.db m63 & 0xFF,m64 & 0xFF,m62 & 0xFF,m63 & 0xFF,m60 & 0xFF,m65 & 0xFF,m61 & 0xFF,m60 & 0xFF
	.db m61 & 0xFF,m60 & 0xFF,m60 & 0xFF,m65 & 0xFF,m68 & 0xFF,m67 & 0xFF,m67 & 0xFF,m66 & 0xFF ; D0
	.db m62 & 0xFF,m63 & 0xFF,m63 & 0xFF,m64 & 0xFF,m61 & 0xFF,m60 & 0xFF,m60 & 0xFF,m65 & 0xFF
	.db m65 & 0xFF,m60 & 0xFF,m60 & 0xFF,m61 & 0xFF,m66 & 0xFF,m67 & 0xFF,m67 & 0xFF,m68 & 0xFF ; E0
	.db m64 & 0xFF,m63 & 0xFF,m63 & 0xFF,m62 & 0xFF,m65 & 0xFF,m60 & 0xFF,m60 & 0xFF,m61 & 0xFF
	.db m60 & 0xFF,m61 & 0xFF,m65 & 0xFF,m60 & 0xFF,m67 & 0xFF,m68 & 0xFF,m66 & 0xFF,m67 & 0xFF ; F0
	.db m63 & 0xFF,m62 & 0xFF,m64 & 0xFF,m63 & 0xFF,m60 & 0xFF,m61 & 0xFF,m65 & 0xFF,m60 & 0xFF
; ************************************************************
; Tabulka pixelových ofsetů v ose X pro výběr kurzoru
; dle pixelové pozice 0..5
; Tabulka vrací hodnotu MOD3 (dvěma se předdělí instrukcí RAR)
; Rozsah tabulky (vstupních hodnot) je 0..(287/2)
; ************************************************************
  .align 8
tbPix2Ofs:
	.db 0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2
	.db 0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2
	.db 0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2
	.db 0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2
	.db 0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2
	.db 0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2
; ******************************************
; Kontrola rozsahu souřadnice X kurzoru myši
;  vstup: HL = souřadnice X
; výstup: HL = souřadnice X omezená dorazy
; ******************************************
LoadXCoor:
	ld hl,(MysX)	; souřadnici X
TestXCoor:
	ex de,hl
	ld hl,(MysXMin)	; a L doraz
	rst 0x20; porovnám
	ret nc		; X < L doraz, vracím L doraz
	
	ld hl,(MysXMax)	; načtu P doraz
	rst 0x20; porovnám
	ex de,hl
	ret nc		; X < P doraz, souřadnice X je OK
	ld a,h		; když je X > P doraz, může být
	and a		; ještě souřadnice X záporná..
	ex de,hl
	ret p		; není => vracím tedy P doraz
	ld hl,(MysXMin)	; je => vracím L doraz
	ret
; ******************************************
; Kontrola rozsahu souřadnice Y kurzoru myši
;  vstup: HL = souřadnice Y
; výstup: HL = souřadnice Y omezená dorazy
; ******************************************
LoadYCoor:
	ld hl,(MysY)	; souřadnici Y
TestYCoor:
	ex de,hl
	ld hl,(MysYMin)	; a H doraz
	rst 0x20; porovnám
	ret nc		; Y je nad H dorazem, vracím H doraz
	ld hl,(MysYMax)	; načtu D doraz
	rst 0x20; porovnám
	ex de,hl
	ret nc		; Y nad D dorazem, souřadnice Y je OK
	ld a,h		; když je Y pod D dorazem, může být
	and a		; ještě souřadnice Y záporná..
	ex de,hl
	ret p		; není => vracím tedy D doraz
	ld hl,(MysYMin)	; je => vracím H doraz
	ret
; *******************************************
; Deaktivace myši
; Obnoví pozadí pod kurzorem myši z buferu.
; Bufer sám je adresován lineárně, ovšem
; obsah je zpřeházen pro adresaci vram 0-4R-8
; *******************************************
MysDea:	ld bc,-(7*64)-1	; BC = řádkovač
	ld de,MysBufer	; DE = bufer pozadí
	ld hl,(MysAOld)
RefreshLoop:
	ld a,(de)		; 0
	ld (hl),a
	inc l
	inc e
	ld a,(de)
	ld (hl),a
	inc h
	inc e
	ld a,(de)		; 4R
	ld (hl),a
	dec l
	inc e
	ld a,(de)
	ld (hl),a
	ld (de),a
	inc h
	inc e
	ld a,(de)		; 8
	ld (hl),a
	inc l
	inc e
	ld a,(de)
	ld (hl),a
	add hl,bc
	inc e
	jp nz,RefreshLoop	; konec buferu?
	ret
; ********
; proměnné
; ********
MysX:	.dw 0		; souřadnice X kurzoru myši
MysY:	.dw 0		; souřadnice Y kurzoru myši
MysXMin:	.dw 0		; L doraz kurzoru myši (min 0!!!)
MysXMax:	.dw 281		; P doraz kurzoru myši (max 281!!!)
MysYMin:	.dw 0		; H doraz kurzoru myši (min 0!!!)
MysYMax:	.dw 244		; D doraz kurzoru myši (max 244)
MysAdr:	.dw 0		; adresa kurzoru myši ve videoram
MysAOld:	.dw 0		; stará adresa kurzoru myši ve videoram
MysXCHG:	.db 0		; příznak změny pozice kurzoru
MysRpt:	.db 0		; počitadlo opakování ve smyčce
MysBit:	.dw MysCrv	; ukazatel na vybraný kurzor dle MysX
; ***********************************************************
; Tabulka adres v ose X pro posun kurzoru dle pixelové pozice
; Tabulka vrací hodnotu /3 (dvěma se předdělí instrukcí RAR)
; Rozsah tabulky (vstupních hodnot) je 0..(287/2)
; ***********************************************************
  .align 8
tbPix2Adr:
	.db 00,00,00,01,01,01,02,02,02,03,03,03,04,04,04
	.db 05,05,05,06,06,06,07,07,07,08,08,08,09,09,09
	.db 10,10,10,11,11,11,12,12,12,13,13,13,14,14,14
	.db 15,15,15,16,16,16,17,17,17,18,18,18,19,19,19
	.db 20,20,20,21,21,21,22,22,22,23,23,23,24,24,24
	.db 25,25,25,26,26,26,27,27,27,28,28,28,29,29,29
	.db 30,30,30,31,31,31,32,32,32,33,33,33,34,34,34
	.db 35,35,35,36,36,36,37,37,37,38,38,38,39,39,39
	.db 40,40,40,41,41,41,42,42,42,43,43,43,44,44,44
	.db 45,45,45,46,46,46,47,47,47
	
; *********************
; aktivace myši
; - test validní adresy
; - uschování pozadí
; - vykreslení kurzoru
; *********************
MysAct:
; *******************************************
; uschová pozadí pod kurzorem myši do buferu
; bufer sám je adresován lineárně, ovšem
; obsah je zpřeházen pro adresaci vram 0-4R-8
; *******************************************
	call Pixel2Adr	; HL = adresa kurzoru myši
			; včetně testu validity
MysActBufer:
	ld bc,-(7*64)-1	; BC = řádkovač
	ld de,MysBufer	; DE = bufer pozadí
MysSaveLoop:
	ld a,(hl)		; [0,0]
	ld (de),a
	inc l
	inc e
	ld a,(hl)		; [1,0]
	ld (de),a
	inc h
	inc e
	ld a,(hl)		; [1,4]
	ld (de),a
	dec l
	inc e
	ld a,(hl)		; [0,4]
	ld (de),a
	inc h
	inc e
	ld a,(hl)		; [0,8]
	ld (de),a
	inc l
	inc e
	ld a,(hl)		; [1,8]
	ld (de),a
	add hl,bc
	inc e
	jp nz,MysSaveLoop	; konec buferu?
; ******************************
; nakreslí kurzor myši na pozadí
; ******************************
ShowMys:
	ld hl,0         ; uschovat hodnotu SP
	add hl,sp
	ld (ShowMysSP+1),hl
	ld hl,(MysBit)	; H:L = 02:uu, kde uu je bitová
			;       pozice kurzoru myši 0..5
	ld l,(hl)         ; H:L = 02:vv, což je úplná adresa
			;       s animační fází kurzoru myši
	ld sp,hl            ; SP = předloha kurzoru myši podle
			;      horizontální pozice v bajtu
	ld hl,(MysAdr)     ; HL = adresa kurzoru
	ld (MysAOld),hl
	ld de,MysBufer    ; DE = bufer pozadí kurzoru
ShowMysLoop:
	pop bc           ; 0
	ld a,(de)
	inc e
	and b
	or c
	ld (hl),a
	inc l
	pop bc
	ld a,(de)
	inc e
	and b
	or c
	ld (hl),a
	inc h
	pop bc           ; 4R
	ld a,(de)
	inc e
	and b
	or c
	ld (hl),a
	dec l
	pop bc
	ld a,(de)
	inc e
	and b
	or c
	ld (hl),a
	inc h
	pop bc           ; 8
	ld a,(de)
	inc e
	and b
	or c
	ld (hl),a
	inc l
	pop bc
	ld a,(de)
	and b
	or c
	ld (hl),a
	ld bc,-(7*64)-1 ; řádkovač
	add hl,bc
	inc e
	jp nz,ShowMysLoop
ShowMysSP:
	ld sp,0        ; obnova hodnoty reg. SP
	ret
; ******************************************************
; 6 animačních fází myšího kurzoru.
; Tabulka ofsetů až po návěští myscr5 musí ležet v jedné
; 256-bajtové stránce!
; ******************************************************
  .align 8
MysCrv:
  .db myscr0 & 0xFF  ; ofset fáze 0
  .db myscr1 & 0xFF  ; ofset fáze 1
  .db myscr2 & 0xFF  ; ofset fáze 2
  .db myscr3 & 0xFF  ; ofset fáze 3
  .db myscr4 & 0xFF  ; ofset fáze 4
  .db myscr5 & 0xFF  ; ofset fáze 5
myscr0: .dw 0f800h,0ff00h ; 0 - fáze 0
	.dw 0fe00h,0c01eh ; 4R
	.dw 0c010h,0fe00h ; 8
	.dw 0f002h,0ff00h ; 1
	.dw 0fe00h,0c03eh ; 5R
	.dw 0c720h,0fe00h ; 9
	.dw 0e006h,0ff00h ; 2
	.dw 0fe00h,0c00eh ; 6R
	.dw 0cf20h,0fe00h ; 10
	.dw 0c00eh,0ff00h ; 3
	.dw 0ff00h,0c012h ; 7R
	.dw 0cf00h,0fe00h ; 11
myscr1:	.dw 0f100h,0ff00h ; 0 - fáze 1
	.dw 0fc00h,0c13ch ; 4R
	.dw 0c120h,0fc00h ; 8
	.dw 0e104h,0ff00h ; 1
	.dw 0fc01h,0c13ch ; 5R
	.dw 0cf00h,0fc01h ; 9
	.dw 0c10ch,0ff00h ; 2
	.dw 0fc00h,0c11ch ; 6R
	.dw 0df00h,0fc01h ; 10
	.dw 0c11ch,0fe00h ; 3
	.dw 0fe00h,0c124h ; 7R
	.dw 0df00h,0fc00h ; 11
myscr2:	.dw 0e300h,0ff00h ; 0 - fáze 2
	.dw 0f801h,0c338h ; 4R
	.dw 0c300h,0f801h ; 8
	.dw 0c308h,0ff00h ; 1
	.dw 0f803h,0c338h ; 5R
	.dw 0df00h,0f802h ; 9
	.dw 0c318h,0fe00h ; 2
	.dw 0f800h,0c338h ; 6R
	.dw 0ff00h,0f802h ; 10
	.dw 0c338h,0fc00h ; 3
	.dw 0fc01h,0c308h ; 7R
	.dw 0ff00h,0f800h ; 11
myscr3: .dw 0c700h,0ff00h ; 0 - fáze 3
	.dw 0f003h,0c730h ; 4R
	.dw 0c700h,0f002h ; 8
	.dw 0c710h,0fe00h ; 1
	.dw 0f007h,0c730h ; 5R
	.dw 0ff00h,0f004h ; 9
	.dw 0c730h,0fc00h ; 2
	.dw 0f001h,0c730h ; 6R
	.dw 0ff00h,0f104h ; 10
	.dw 0c730h,0f801h ; 3
	.dw 0f802h,0c710h ; 7R
	.dw 0ff00h,0f100h ; 11
myscr4: .dw 0cf00h,0fe00h ; 0 - fáze 4
	.dw 0e007h,0cf20h ; 4R
	.dw 0cf00h,0e004h ; 8
	.dw 0cf20h,0fc00h ; 1
	.dw 0e00fh,0cf20h ; 5R
	.dw 0ff00h,0e108h ; 9
	.dw 0cf20h,0f801h ; 2
	.dw 0e003h,0cf20h ; 6R
	.dw 0ff00h,0e308h ; 10
	.dw 0cf20h,0f003h ; 3
	.dw 0f004h,0cf20h ; 7R
	.dw 0ff00h,0e300h ; 11
myscr5:	.dw 0df00h,0fc00h ; 0 - fáze 5
	.dw 0c00fh,0df00h ; 4R
	.dw 0df00h,0c008h ; 8
	.dw 0df00h,0f801h ; 1
	.dw 0c01fh,0df00h ; 5R
	.dw 0ff00h,0c310h ; 9
	.dw 0df00h,0f003h ; 2
	.dw 0c007h,0df00h ; 6R
	.dw 0ff00h,0c710h ; 10
	.dw 0df00h,0e007h ; 3
	.dw 0e009h,0df00h ; 7R
	.dw 0ff00h,0c700h ; 11
; *********************************************************
; Z pixelových souřadnic, které ořeže na platný rozsah,
; vypočte adresu kurzoru ve videoram
; vstup: proměnné MysX, MysY
; výstup: HL = adresa kurzoru ve videoram
; 
; *********************************************************
Pixel2Adr:
	call LoadYCoor	; HL := 11yyyyyy yy000000
	ld (MysY),hl
	add hl,hl 
	add hl,hl 
	add hl,hl 
	add hl,hl 
	add hl,hl 
	add hl,hl
	ld a,h
	add a,0c0h
	ld h,a
	push hl
	call LoadXCoor	; HL := HL + pozice bajtu na řádku
	ld (MysX),hl	; tedy HL := 11yyyyyy  yyxxxxxx
	ld a,h
	rra
	ld a,l
	rra
	ld l,a		; nejprve L := X/2 (CY=zbytek)
	ld h,tbPix2Ofs >> 8
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
; ****************************************************
; Nastavení citlivosti myši
; vstup: A=0: bez myši
;        A=1: malá citlivost    (verze emulátor)
;	 A=2: střední citlivost (std HW mouse 130DPI )
;        A=3: vysoká citlivost  (homemade 40DPI)
; ****************************************************
MysDPISet:
	ld a,(MysSensitivity)	; podle nastavení myši
	cp 4			; (pouze platného)
	ret nc
	ld hl,tbMysDPISet	; z tabulky citlivostí	
	rst 0x18; vybere tu požadovanou
	ld (MysSenstvtPos+1),hl	; a uloží ji
	ld a,(MysSensitivity)	; podle nastavení myši
	and a			; vybere
	ld hl,KbdOvladac	; buď ovladač klávesnice
	ld de,000E6h		; a modifikátory procedury
	jp z,MysDPISetup		; pro uvolnění tlačítek
	ld hl,MysDriver		; nebo ovladač myši
	ld de,0C0F6h		; a modifikátory...

MysDPISetup:
	ld (Ovladani+1),hl		; uloží ovladač myš/klávesnice
	ld a,d			; a modifikátory...
	ld (MouseKeyReleaseModA+1),a
	ld a,e
	ld (MouseKeyReleaseModB),a
	ld (MouseKeyReleaseModC),a
	ret
tbMysDPISet:
	.dw MysDPIEmu,MysDPIEmu,MysDPIStd,MysDPIHom
; ***********************
; korekce citlivosti myši
; ***********************
MysSenstvt:
	ld a,h		; test znaménka čísla v HL
	and a		; CY nuluje, P trvale nese znaménko!
	push af	; uschovat příznak P (polarita)
	jp p,MysSenstvtPos
	cpl		; pro záporná čísla převod na kladná
	ld h,a		; x (-1) pomocí dvojkového doplňku
	ld a,l
	cpl
	ld l,a
	inc hl
MysSenstvtPos:
	call 0		; úprava citlivosti myši
MysSenstvtNorm:
	pop af		; obnovit příznak P (polarita)
	ret p		; pro původně kladná čísla konec,
	ld a,h
	cpl		; pro původně záporná čísla 
	ld h,a		; převod na záporná x (-1)
	ld a,l		; pomocí dvojkového doplňku
	cpl
	ld l,a
	inc hl
	ret
