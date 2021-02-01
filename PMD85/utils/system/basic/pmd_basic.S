; kalibrace 60 znaků
; 2345678901234567890123456789012345678901234567890123456789
; *******************************
; ***                         ***
; ***   PMD-85 BASIC G/V2.A   ***
; ***                         ***
; *******************************
; 1) Tato verze velmi často modifikuje svůj kód, proto se
;    nehodí k implemetaci do ROM.
; 2) Značení funkcí BIOSu a proměnných ve standardním
;    zápisníku ve videoram respektuje symbolická jména
;    zavedená Libovickým & Olmerem v jejich komentovaném
;    výpisu Monitoru PMD-85-2 (s výjimkou procedury "byte"
;    na adrese 8b6ch, která s ohledem na klíčová slova
;    překladače byla přejmenována na "ldbyte").
; 3) Po prvním spuštění BASICu se přesměruje bufer pro ulo-
;    žení textu z dialogového řádku po stisku EOL z adresy
;    7F82h na adresu BE07h, kde zůstane i po přechodu
;    do Monitoru. Některé procedury ovšem využívají
;    i původní adresu buferu o hodnotě 7F82h.
; 4) U příkazu ROM je (zřejmě chybně) nastavena délka přeno-
;    su bloku o 256 bajtů delší než je ve skutečnosti,
;    protože u verze 1 se to takto dělalo. BIOS verze 2/2A
;    si sám tuto hodnotu zvětší o těch potřebných 256 bajtů,
;    takže je to uděláno 2x a namísto 1kB se z ROMPACKu
;    přenáší 1,25kB dat.
; 5) Tato verze vykazuje silnou podobnost s verzí Nascom
;    BASIC 4.7 s délkou 8k.
; 6) Grafické příkazy využívají proměnné @0..@7, @X a @Y.
;    Bližší informace v sekci grafických příkazů.
; 7) Při načítání řetězcových polí příkazem DLOAD se chybně
;    testuje překročení dostupné paměti. Je použita konstan-
;    ta 5Fh, která u verze 2.0 určovala podkročení adresy
;    6000h, vymezené pro řetězcová pole, Pro verzi 2A by
;    tato konstanta měla mít hodnotu 90h (adresa procedury
;    1F74h)
; 8) Chybný průběh funkce RND se záporným argumentem.
;    (Přepíše koeficienty mocninné řady pro výpočet
;     funkce EXP.)
; *********************************************
; konstanty a proměnné v dolních 32k paměti RAM
; mimo vlastní kód BASIC interpreteru
; *********************************************
romarea	 .equ 7000h	; oblast programů pro příkaz ROM
usrexec	 .equ 7f00h	; oblast uživatelských programů
edibuff  .equ 7f82h	; ukazatel na text, vytvořený
			; v řádkovém editoru BIOSu
			; (podprogramem ENTER)
; ************************
; vazba na procedury BIOSu
; ************************
hex	 .equ 80e0h	; konverze ASCII > 4 bity
pairin	 .equ 80f7h	; konverze 2xASCII > bajt
clr	 .equ 8113h	; inicializace editačního buferu
prevo2	 .equ 813bh	; převod čísla na hexadecimální
inklav	 .equ 84a1h	; vstup ASCII znaku z klávesnice
adras	 .equ 84ceh	; výpočet adresy znaku dle čísla
prtout	 .equ 8500h	; tisk znaku na obrazovku
inb	 .equ 85f6h	; načtení bajtu ze sériové linky
edit	 .equ 8800h	; výkonná rutina kláves
wrbuf	 .equ 8855h	; vypíše obsah editačního řádku
beep	 .equ 88a3h	; generování tónu
mgfhead  .equ 8a7ah	; MGF modifikační procedura
i82531   .equ 8b41h	; nastavení 8251 a 8253
ldbyte	 .equ 8b6ch	; načtení bajtu z MGF
enter2   .equ 8bf4h	; nestandardní volání ENTER
transfer .equ 8c00h	; program pro přenos z ROMPACKu
point	 .equ 8c7dh	; vykreslení pixelu
pospoint .equ 8c94h	; výpočet adresy a bitové masky
inpol	 .equ 8cd0h	; interpolátor BIOSu
usartout .equ 8d7eh	; výstup znaku po sériové lince
shead	 .equ 8de2h	; vyhledání a načtení souboru
prbtxt   .equ 8e43h	; zobrazí edit. bufer v dial. řádku
save	 .equ 8ea1h	; načte a uloží jméno souboru na MGF
save2	 .equ 8eadh	; výkonná část BIOSovské funkce SAVE
; **************************************
; proměnné v rozšířené paměti 64kB verze
; **************************************
colpos	.equ 0be01h	;  1b aktuální sloupec na obrazovce
ctrlflg	.equ 0be03h	;  1b pozůstatek z jiné verze
crntln	.equ 0be04h	;  2b číslo aktuálního řádku
c_odloz .equ 0be07h	; 80b textový bufer pro editaci
			;     (přepisuje následující
			;      proměnné, což ovšem v daném
			;      režimu asi nevadí)
dimreq	.equ 0be52h	;  1b NONZERO => požadavek na vytvo-
			;     ření (neexistující) proměnné
vartype	.equ 0be53h	;  1b 00h=číslo/01h=řetězec
quote	.equ 0be54h	;  1b příznak uvozovkového režimu
Xbe55	.equ 0be55h	;  2b spolu s be57 jedna proměnná
laststg	.equ 0be57h	;  2b ukazatel na hlavičku řetězcové 
			;     proměnné v bloku proměnných
			;     !!!
tmpstrg	.equ 0be59h	;  4b pomocná řetězcová proměnná
failln	.equ 0be5dh	;  2b číslo chybového řádku
onerrln	.equ 0be61h	;  2b číslo řádku ON ERR GOTO
tmpvar	.equ 0be65h	;  4b pomocná řetězcová proměnná
strlast	.equ 0be69h	;  2b ukazatel na volné místo pod
			;     posledním textem řetězců
fncadr	.equ 0be6bh	;  2b adresa nadřazeného operátoru
			;     v zápisu zdrojového kódu
dataln	.equ 0be6dh	;  2b číslo aktuálního řádku DATA
indxen	.equ 0be6fh	;  1b 01h..80h => nelze použít inde-
			;                 xovanou proměnnou
ovrbuf	.equ 0be70h	;  1b příznak porušení dialog. řádku
inptype	.equ 0be71h	;  1b 00h=INPUT/NONZERO=READ
crntadr	.equ 0be72h	;  2b ukazatel do zdrojového kódu
			;     programu v BASICu
eofxpr	.equ 0be74h	;  2b ukazatel na konec výrazu
stopln	.equ 0be76h	;  2b číslo přerušeného řádku
			;     (tlačítkem STOP, nebo příkazy)
stopadr .equ 0be78h	;  2b adresa místa přerušení
			;     (tlačítkem STOP, nebo příkazy)
			;     0000h => nelze zadat CONT
varbase	.equ 0be7ah	;  2b začátek oblasti proměnných
arrbase	.equ 0be7ch	;  2b začátek oblasti polí
arrend	.equ 0be7eh	;  2b konec oblasti polí
dataadr	.equ 0be80h	;  2b adresa aktuální položky DATA
fpaccum	.equ 0be82h	;  5b FP akumulátor (4b) + rozšíření
fpprtbf .equ 0be87h	; 12b textový bufer FP čísla
			;  1b nevyužito nebo rezerva na NULL
nulstrg	.equ 0be94h	; bufer pro nulový řetězec?
; *******************************************************
; proměnné ve standardním zápisníku "napravo" od videoram
; *******************************************************
buf	.equ 0c030h	; 2b začátek editačního buferu
color	.equ 0c03ah	; 1b atribut barvy
cursor	.equ 0c03eh	; 2b adresa pro tisk znaků
curch	.equ 0c072h	; 2b ukaz. do edit. buferu při čtení
mess	.equ 0c074h	; 2b adresa systémového hlášení
odloz	.equ 0c078h	; 2b adresa textu po editaci řádku
ram	.equ 0c0f0h	; 4b návratový vektor u MGF operací
kdir	.equ 0c132h	; 2b tabulka vektorů řídicích kláves
ascii	.equ 0c134h	; 1b znak načtení z klávesnice
lstr	.equ 0c13ch	; 2b délka textu v zadaném řádku
x1	.equ 0c170h	; 2b X-souřadnice počátečního bodu
y1	.equ 0c172h	; 1b Y-souřadnice počátečního bodu
x2	.equ 0c173h	; 1b X-souřadnice koncového bodu
y2	.equ 0c174h	; 1b Y-souřadnice koncového bodu
bcur	.equ 0c17ah	; 2b ukaz. pro BMOVE/BPLOT
findnr	.equ 0c1b0h	; 1b číslo požadovaného MGF souboru
findtp	.equ 0c1b1h	; 1b typ požadovaného MGF souboru
numfil	.equ 0c1b2h	; 1b číslo souboru u MGF operací
typfil	.equ 0c1b3h	; 1b typ souboru u MGF operací
adrfil	.equ 0c1b4h	; 2b začátek souboru u MGF operací
lenfil	.equ 0c1b6h	; 2b délka MGF souboru, zmenšená o 1
namfil	.equ 0c1b8h	; 8b jméno MGF souboru
ochr	.equ 0c1f1h	; 1b příznak chráněného souboru 2Ah
vystup	.equ 0c1f4h	; 10b rutina pixelových operací
arrlen	.equ 0c330h	; 2b délka pole proměnných
imsptr	.equ 0c334h	; 2b ukazatel do imsbuf
imsbuf	.equ 0c33ah	; 6b bufer hlavičky protokolu IMS-2
Xc370	.equ 0c370h	; 
arradr	.equ 0c374h	; 2b adresa začátku pole proměnných
Xc377	.equ 0c377h	; 
autonr	.equ 0c37ch	; 2b počáteční hodnota řádku AUTO
autosp	.equ 0c37eh	; 1b hodnota kroku u příkazu AUTO
autofl	.equ 0c37fh	; 1b 0 = aktivní režim AUTO
; ******************************
; Zde začíná PMD-85 BASIC G/V2.A
; ******************************
BINLEN .equ basic_end - init
RMM    .equ 1
  .globl BINLEN
;	.org 0
  .section .text.start
  .globl init,oneradr,basic_end
; *******************************
; RST0 - inicializace interpretru
; *******************************
			; (0000h)
init:	ld hl,edibuff	; Výstup znaků půjde
	ld a,0fh	; do editačního buferu.
	 jp init2
; *******************************************************
; RST 1 - test znaku na adrese (HL) na hodnotu za RST 1
;       - není-li shoda, přejde na chybu 09h - Syntax err
; *******************************************************
			; (0008h)
X0008:	ld a,(hl)		; Načíst znak, který je v pořadí
	ex (sp),hl		; a porovnat se znakem, který
	cp (hl)		; následuje za volací instrukcí
			; RST 1
	inc hl		; posun na další znak
	ex (sp),hl		
	jp nz,err_09	; v případě neshody vyvolat
			; chybu 09h - Syntax err
; ****************************************
; RST 2 - test na cifru 0-9 na adrese (HL)
;       - přeskakuje mezery
;       - je-li platná cifra, nastaví CY=1
; ****************************************
			; (0010h)
X0010:	inc hl		; nejprve posun na další znak
	ld a,(hl)		; a jeho test
	cp 3ah		; na horní rozsah cifer
	ret nc		; je-li větší => konec
	 jp X04d6	; další testy
; ****************************************************
; RST 3 - porovná HL vůči DE
;       - příznaky Z a CY nastavuje jako instrukce CMP
; ****************************************************
			; (0018h)
X0018:	ld a,h		; Nejprve porovnat vyšší bajty
	sub d		; (tedy H versus D)
	ret nz
	ld a,l		; a v případě shody i nižší bajty
	sub e		; (tedy L versus E)
	ret
; *******************************
; vektor na porovnání dvou hodnot
; *******************************
X001e:	.dw 0a36h
; ************************************************
; RST 4 - zkratka pro načtení 8-bitového argumentu
; ************************************************
			; (0020h)
X0020:	 jp X1627	; jen odskok na vlastní rutinu
; **************************
; universální textový výstup
; **************************
			; (0023h)
cout:	 jp prtout	; modifikací adresy se volí ovladače
			; pro výstup znaku
; ********
; proměnné
; ********
X0026:	.db 0		; kód chyby pro ON ERR GOTO
X0027:	.db 1		; parametr příkazu NULL +1
; **********************************************
; RST 5 - dle hodnoty v reg. E zobrazí kód chyby
; **********************************************
			; (0028h)
X0028:	pop af		; zrušit návratovou adresu
	 jp 0108h	; a skok na vlastní chybové hlášení
; ********
; proměnné
; ********
X002c:	.dw edibuff	; ukazatel (kurzor) pro "tisk" 
			; do buferu
			; (002eh)
maxcol:	.db 30h		; počet znaků na řádek při tisku
			; (příkaz LLIST si tuto proměnnou
			; modifikuje na 80 ale pak vrací
			; původní hodnotu) tuto proměnnou
			; lze modifikovat pouze příkazem
			; POKE, není na to příkaz
X002fh:	.db 00h		; nevyužitý bajt
; **********************************************
; RST6 - Test stavu FP akumulátoru
; v reg. A vrací hodnou -1/0/+1 dle konvence SGN
; **********************************************
			; (0030h)
X0030:	ld a,(fpaccum+3)	; Test exponentu FP akumulátoru
	and a		; a při nenulové hodnotě provést
	jp nz,X10d0	; další testy
	ret		; jinak nastavit A = CY = Z = 0
; ***********************
; RST7 - obluha přerušení
; ***********************
X0038:	nop		; pokud bude pod BASICem používáno
	nop		; přerušení, hrozí porušení dat
	ret		; v zásobníku, neboť procedury BIOSu
			; používají registr SP jako pracovní
; *********************************
; konstanty, určující meze v paměti
; *********************************
strlim:	.dw 9000h	; (003bh) "konec" textů řetězců
spbase:	.dw 6fffh	; (003dh) hodnota registru SP
pgbase:	.dw 2401h	; (003fh) začátek programu
stbase:	.dw 9f00h	; (0041h) "začátek" textů řetězců
; ***************************
; pomocná procedura pro BPLOT
; ***************************
			; (0043h)
X0043:	ld a,(de)		; jen načtení předlohy,
	xor (hl)		; sloučení s pozadím funkcí XOR
	ld (hl),a		; a zápis do videoram
	ret
; *******************************
; pokračování inicializace BASICu
; *******************************
			; (0047h)
init2:	di
	ld (X002c),hl	; init tiskového buferu (7f82h)
	ld (mess),hl	; a jeho deklarace pro BIOS
	ld hl,Xc370	; vyplnit 15 bajtů od adresy C370h
X0051:	ld (hl),0		; vhodnými údaji
	dec a
	inc hl
	jp nz,X0051
	ld (hl),0ffh
	ld a,10h
	ld (Xc377),a
	ld hl,(spbase)	; inicializace SP pro BASIC
	ld sp,hl
	ld hl,t_init	; tisk textu BASIC-G /V2.A
X0066:	ld a,(hl)
	inc hl
	push af
	call cout
	pop af
	and a
	jp nz,X0066
	xor a		; test na výskyt BASICovského programu
	ld hl,(pgbase)	; pokud je na adrese 2402h hodnota 24h
	dec hl		; (tedy odkaz na další řádek) pak je
	ld (hl),a		; platný program v paměti a nic se neděje
	ei
	inc hl		; ale co když bude první BASICovský řádek
	inc hl		; uměle zadán s délkou větší než 256 bajtů?
	ld a,(hl)		; no, přirozenou cestou to nikdy nenastane
	cp h
	call nz,X01f4	; v opačném případě se provede příkaz NEW
	call X01ff	; ale v každém případě se při restartu
			; BASICu provede ekvivalent příkazu CLEAR
	.db 3eh		; mvi a,0c1h
X0083:	pop bc
; ********************************************************
; zde se program vrací po stisku klávesy STOP, po vykonání
; příkazů STOP nebo END nebo pokud dojdou řádky programu
; ********************************************************
			; (0084h)
X0084:	call X071e	; podmíněný CR+LF
X0087:	ld hl,X0324	; do editačního buferu dialogového řádku
	ld (cout+1),hl	; přesměrovat tisk
	ld hl,t_ok	; string „OK“
	call tx2edi	; vytisknout do editačního buferu
	 jp X013f	; a skok do dialogové smyčky BASICu
; ***********************************************
; tabulka aritmetických operátorů, jejich priorit
; a skokových vektorů obslužných rutin
; ***********************************************
			; (0096h)
X0096:	.db 079h	; priorita operátoru +
	.dw X1252	; a jeho obslužný vektor
	.db 079h	; priorita operátoru -
	.dw X0e97	; a jeho obslužný vektor
	.db 07ch	; priorita operátoru *
	.dw X0fc1	; a jeho obslužný vektor
	.db 07ch	; priorita operátoru /
	.dw X101f	; a jeho obslužný vektor
	.db 07fh	; priorita operátoru ^
	.dw X1359	; a jeho obslužný vektor
	.db 050h	; priorita operátoru AND
	.dw f_and	; a jeho obslužný vektor
	.db 046h	; priorita operátoru OR
	.dw f_or	; a jeho obslužný vektor
; ********************
; systémové hlášení OK
; ********************
			; (00abh)
t_ok:	.db "OK",0dh,0
; *******************************************
; test obsahu zásobníku zda obsahuje položku
; cyklu FOR/NEXT a pokud ano, test na shodu
; pracovní proměnné (dodané v DE)
; Z=1 znamená pozitivní nález
; *******************************************
			; (00afh)
X00af:	ld hl,4		; ofset v rámci datové položky
	add hl,sp
X00b3:	ld a,(hl)		; kód položky
	inc hl
	cp 81h		; je to struktura FOR?
	ret nz		; není => konec testu
	ld c,(hl)
	inc hl
	ld b,(hl)		; BC = adresa pracovní proměnné
	inc hl
	push hl
	ld l,c
	ld h,b
	ld a,d
	or e
	ex de,hl
	jp z,X00c7	; pokud se pracovní proměnná
	ex de,hl		; shoduje s tou dodanou v DE,
	rst 0x18; pak konec, jinak
X00c7:	ld bc,13	; se zavrtat 13(+3) bajtů hlouběji
	pop hl		; do zásobníku na potenciálně
	ret z		; další (nadřazený) cyklus
	add hl,bc		; FOR/NEXT (předčasné ukončení
	 jp X00b3	; vnořeného cyklu).
; **************
; alokace paměti
; **************
			; (00d0h)
X00d0:	call X00e8	; nejprve test dostatečné paměti
; *******************************************************
; Vytvoří místo v paměti na požadované adrese odsunutím
; horní části směrem k vyšším adresám. Kopírování provádí
; v opačném pořadí adres.
; *******************************************************
			; (00d3h)
X00d3:	push bc		; prohodí obsahy BC a HL
	ex (sp),hl
	pop bc
X00d6:	rst 0x18; dokud nedosáhne HL hodnoty DE,
	ld a,(hl)		; kopírování bloku z adresy dané HL
	ld (bc),a		; na adresu danou BC
	ret z
	dec bc		; od vyšších adres dolů
	dec hl
	 jp X00d6
; *****************************************
; Test na dostatek paměti pro novou datovou
; položku v množství (2 x C) bajtů.
; *****************************************
			; (00dfh)
X00df:	push hl		; k poslední využité adrese
	ld hl,(arrend)	; (využito pro indexované
	ld b,0		; proměnné) se připočte hodnota 2xC
	add hl,bc		; a tento požadavek na nový
	add hl,bc		; horní limit využité RAM se otestuje
	.db 3eh
; *****************************************
; Test na volnou paměť v množství HL bajtů.
; *****************************************
			; (00e8h)
X00e8:	push hl		; vypočte se, kolik místa zbude
	ld a,0d4h	; mezi novým horním limitem využité
	sub l		; RAM a spodní položkou zásobníku
	ld l,a		; (včetně rezervy 44 bajtů pro jeho
	ld a,0ffh	; kolísání)
	sbc a,h
	ld h,a
	add hl,sp
	pop hl
	ret c
X00f4:	ld e,7		; pokud místo nezbyde, vyvolá se
	rst 0x28; chyba 07h - Pg too big
; ***************************************************
; vyvolání chyby při nesmyslné položce v příkazu DATA
; ***************************************************
X00f7:	ld hl,(dataln)	; řádek s aktuální položkou DATA
	ld (crntln),hl	; se podstrčí jako aktuální
			; a vyvolá se chyba 09 - Syntax err
; ****************************
; Chybové hlášení „Syntax err“
; ****************************
err_09:	ld e,09h	; (00fdh)
	.db 01h		; lxi b,..
; ****************************
; Chybové hlášení „Dv by zero“
; ****************************
err_0c:	ld e,0ch	; (0100h)
	.db 01h		; lxi b,..
; ****************************
; Chybové hlášení „No for stm“
; ****************************
err_05:	ld e,05h	; (0103h)
	.db 01h		; lxi b,..
; ****************************
; Chybové hlášení „Arr.alloc.“
; ****************************
err_02:	ld e,02h	; (0106h)
; ****************************
; Tisk (chybového) hlášení
; Vstup: číslo hlášení v reg.E
; ****************************
			; (0108h)
X0108:	call X0220	; vynulovat STACK
	ld (ctrlflg),a	; v této verzi nevyužitá proměnná
	ld a,e
	ld (X0026),a	; uložit kód chyby
	ld hl,(crntln)	; a číslo chybového řádku
	ld (failln),hl
	ld a,h		; v dialogovém režimu ignorovat
	and l		; konstrukci ON ERR GOTO
	inc a
	jp z,X0136
	ld hl,(oneradr)	; je definována uživatelská obsluha
	ld a,h		; chyb ?
	or l
	jp z,X0136	; ne => přeskočit ON ERR GOTO
; *********************************************************
; uživatelské ošetření chyby ON ERR GOTO
; *********************************************************
; jako číslo řádku se dosadí číslo řádku, na kterém je
; samotná konstrukce ON ERR GOTO a jako adresa pro čtení
; zdrojového textu BASICu se nastaví adresa klíčového slova
; GOTO v zápisu ON ERR GOTO
; *********************************************************
	ld (crntadr),hl	; nastavit řádek s ošetřením chyby
	ex de,hl
	ld hl,0		; deaktivovat funkci ON ERROR GOTO
	ld (oneradr),hl
	ld hl,(onerrln)	; načíst ještě číslo řádku a od něj
	 jp X04a8	; pokračovat v běhu programu
; *********************************
; Standardní ošetření chyby výpisem
; *********************************
			; (0136h)
X0136:	call X071e	; podmíněný CR + LF (dokončení řádku)
	call X169c	; tisk chyby do dialogového řádku
	call X071e	; podmíněný CR + LF
; ***********************************************
; Zobrazit systémové hlášení do dialogového řádku
; ***********************************************
			; (013fh)
X013f:	call X1e33	; nastavit výstup textu na obrazovku
			; a nadefinovat editační bufer
	call clr	; vymazat dialogový řádek
	call prbtxt	; editační bufer zobrazí v dialogového řádku
	.db 26h		; mvi h,0e1h
; **************************************************************
; zde se vstupuje z příkazu LLIST, když vyberu řádek pro editaci
; a do editačního buferu dialogového řádku nakopíruji jeho obsah
; **************************************************************
			; (0149h)
X0149:	pop hl
X014a:	ld hl,0ffffh	; jsem v dialogovém režimu
	ld (crntln),hl
	call X1ec0	; pokud je aktivní AUTO, předtisknout č. řádku
	call i82531	; nadefinovat režimy 8251/8253
	call X0307	; volat BIOS/ENTER (editace dialogového řádku)
			; HL = začátek textového buferu po editaci
	ld (ovrbuf),a	; (=0) po provedení instrukce RETURN, která
			; vrátí aktivitu do dialogového režimu se bude
			; pokračovat v následujících zadaných instrukcích
	rst 0x10; test na úvodní cifru na vloženém řádku
	push af
	call getnum	; do reg. DE extrahovat číslo BASIC řádku
	push de
	call X023d	; provést tokenizaci klíčových slov
	ld b,a
	pop de
	pop af
	jp nc,X20eb 	; přímé provedení řádku bez čísla
			; (deaktivovat režim AUTO)
; *****************************
; Uložení BASIC řádku do paměti
; *****************************
			; (016bh)
	push de		; Řádek začíná číslem, proto
	push bc		; bude uložen do paměti.
	rst 0x10
	and a		; přeskočit mezery a test znaku
	push af
	call fndlin	; existuje už tento řádek?
	jp c,X017c	; ano => běž dál
			; nyní víme, že řádek s tímto číslem ještě
			; neexistuje
	pop af		; teď obnovíme informaci, která říká, zda bylo
	push af	; zadáno pouze číslo řádku (neexistujícího)
	jp z,err_0b	; ano? => chyba 0bh - Numb.nonex
	and a
X017c:	push bc		; při zadávání nového, zatím neexistujícího
	jp nc,X0191	; řádku skočíme na jeho vložení, při mazání
			; existujícího řádku pokračujeme
; *********************************************
; vymazat vybraný BASICovský řádek (paměť
; s programem posunout směrem k nižším adresám)
; *********************************************
 
	ex de,hl
	ld hl,(varbase)	; v HL držím konec programu
X0184:	ld a,(de)		; vlastní přesun bajtů
	ld (bc),a		; směrem k nižším adresám
	inc bc
	inc de
	rst 0x18; dosáhl jsem konce programu?
	jp nz,X0184	; ne => další bajt
	ld h,b		; v BC mám nyní nový konec programu,
	ld l,c		; tak jej uložím do patřičné proměnné
	ld (varbase),hl	; (ta určuje i začátek proměnných)
; ***********************
; zde se vloží nový řádek
; ***********************
X0191:	pop de		; DE = adresa, kam budu vkládat řádek
	pop af		; PSW ještě pořád nese informaci o tom,
			; zda jsem zadal pouze číslo řádku
	jp z,X01b8	; a pokud ano, pak už jen přepočet ukazatelů
	ld hl,(varbase)
	ex (sp),hl
	pop bc		; alokace potřebné paměti od adresy
	add hl,bc		; DE v délce BC (bylo vypočteno dříve)
	push hl		; blok dat se kopíruje v opačném pořadí,
	call X00d0	; aby se nepřepisoval sám sebou
	pop hl
	ld (varbase),hl	; po vytvoření místa v paměti pro nový řádek
	ex de,hl
	ld (hl),h		; do struktury nového řádku se zapíše něco,
			; co sepozději stejně přepíše. zřejmě chyba
	pop de		; vyzvednout číslo řádku
	inc hl
	inc hl
	ld (hl),e		; a uložit je do 3. a 4. bajtu
	inc hl
	ld (hl),d
	inc hl
	ld de,c_odloz	; zde se obsah nového řádku z editačního
X01b0:	ld a,(de)		; buferu (po tokenizaci) nakopíruje
	ld (hl),a		; do vytvořeného prostoru v bloku programu
	inc hl
	inc de
	and a
	jp nz,X01b0
; *****************************************************
; inicializace ukazatelů proměnných
; *****************************************************
; protože jsme zvětšili/zmenšili kód programu a hned
; za programem jsou naskládány proměnné, je dobré kvůli
; integritě dat prohlásit všechny proměnné a ukazatele
; za neexistující
; *****************************************************
			; (01b8h)
X01b8:	call X01ff	; CLEAR + přepočet ukazatelů
	inc hl
	ex de,hl
; **********************************************************
; provede se zřetězení všech! řádků programu (včetně nového)
; **********************************************************
			; (01bdh)
X01bd:	ld h,d		; základní zřetězovací smyčka
	ld l,e
	ld a,(hl)		; načíst první dva bajty řádku
	inc hl		; (potenc. ukazatel na další řádek)
	or (hl)
	jp z,X014a	; byl poslední řádek => konec
	inc hl
	inc hl		; přeskočit zbytek hlavičky řádku
	inc hl		; ve zdrojovém zápisu BASICu
	xor a
X01c9:	cp (hl)		; najedeme za poslední (tj. nulový)
	inc hl		; bajt programového řádku
	jp nz,X01c9
	ex de,hl		; a tuto adresu uložíme do hlavičky
	ld (hl),e		; předchozího řádku
	inc hl
	ld (hl),d
	 jp X01bd
; *************************************
; hledání řádku podle jeho čísla
; vstup:  DE = číslo řádku
; výstup: CY = 0 (řádek nenalezen)
;         CY = 1 (adresa řádku je v BC) 
; *************************************
			; (01d5h)
fndlin:	ld hl,(pgbase)	; začneme od začátku (programu)
fndlfr:	ld b,h
	ld c,l
	ld a,(hl)		; pokud je v záhlaví řádku odkaz na
	inc hl		; nulovou adresu (první dva bajty)
	or (hl)
	dec hl
	ret z		; pak konec programu => nenalezeno
	inc hl
	inc hl
	ld a,(hl)		; načíst číslo prohledávaného řádku
	inc hl
	ld h,(hl)
	ld l,a
	rst 0x18; shoduje se?
	ld h,b
	ld l,c
	ld a,(hl)
	inc hl
	ld h,(hl)
	ld l,a
	ccf
	ret z		; ano => konec a CY = 1
	ccf
	ret nc		; ne, navíc čísla řádků už jsou větší
	 jp fndlfr	; ne, pak test dalšího řádku
; **********
; příkaz NEW
; **********
			; (01f3h)
c_new:	ret nz		; nesmí následovat žádný parametr
X01f4:	ld hl,(pgbase)
	xor a
	ld (hl),a		; na začátek programu uložit vektor
	inc hl		; 0000h, indikující neplatný program
	ld (hl),a
	inc hl
	ld (varbase),hl	; a ukazatel na oblast proměnných
			; nadeklarovat hned za neexistující
			; program
; ************************************************
; varianta příkazu CLEAR, volaná při editaci řádků
; a s tím spojeným vymazáním všech proměnných
; ************************************************
X01ff:	ld hl,(pgbase)
	dec hl
	xor a
; ************
; příkaz CLEAR
; ************
			; (0204h)
c_clea:	ret nz		; nesmí následovat žádný parametr
X0205:	ld (crntadr),hl
	ld hl,(stbase)	; vymazat texty řetězcových
	ld (strlast),hl	; proměnných
	call datrst	; RESTORE na začátek programu
	ld hl,(varbase)
	ld (arrbase),hl	; vymazat proměnné
	ld (arrend),hl	; a pole
	ld hl,0
	ld (oneradr),hl	; deaktivovat funkci ON ERR GOTO
; *******************************************
; vynulování interních proměnných a zásobníku
; se zachováním programu a proměnných BASICu
; *******************************************
			; (0220h)
X0220:	pop bc		; uschovat návratovou adresu do BC
	ld hl,(spbase)	; inicializovat ukazatel zásobníku
	ld sp,hl
	ld hl,tmpstrg	; ???
	ld (laststg),hl	; ???
	xor a
	ld l,a
	ld h,a
	ld (stopadr),hl	; znemožnit pokrač. příkazem CONT
	ld (indxen),a
	ld (v_dgrd),a	; obloukové míry v radiánech
	push hl
	push bc		; vrátit do zásobníku návratovou
	ld hl,(crntadr)	; adresu a obnovit ukazatel do zdro-
	ret		; jového kódu BASIC programu
; *****************************************
; převod sekvence ASCII znaků na kód BASICu
; (tuto proceduru využivá i funkce VAL)
; *****************************************
			; (023dh)
X023d:	xor a		; na začátek vypnu uvozovkový režim a mohu
	ld (quote),a	; tím pádem nahrazovat příkazy jejich kódem
	ld c,5
	ld de,c_odloz	; převedený text uložím do buferu 
X0246:	ld a,(hl)
	cp 20h		; test na mezeru
	jp z,X02d1
	ld b,a
	cp 22h		; test na uvozovky
	jp z,X02f1
	and a		; test na nulový bajt
	jp z,X02f8
	cp 27h		; test na apostrof
	jp nz,X026b
X025b:	ld a,b		; narazil jsem na apostrof, proto budu
	ld (de),a		; doslova převádět znak po znaku, dokud
	inc c		; se bude jednat o znaky hexadecimální
	inc de		; abecedy
	inc hl
	ld a,(hl)
	ld b,a
	call hex	; test na hexadecimální znak
	jp nc,X025b	; pokud to je, pokračuj ve smyčce,
	 jp X0246	; pokud není, běž na hlavní převaděč
; *********************************************************
; zpracování ostatních zn. mimo SPACE, uvozovek a apostrofu
; *********************************************************
X026b:	ld a,(quote)	; test uvozovkového (doslovného) režimu
	and a
	ld a,(hl)		; pokud je, jdu ven z této sekce a převádím
	jp nz,X02d1	; přesně znak po znaku bez TOKENS
			; v opačném případě dělám náhrady
	cp 3fh		; znaku ? (otazník)
	ld a,0ceh	; znakem _ (podtržítko)
	jp z,X02d1	; a v tom případě jdu ven z této sekce
	ld a,(hl)		; ještě otestuju znak, je-li to desítková
	cp 30h		; cifra, dvojtečka nebo středník
	jp c,X0285	; => v tom případě taky převádím
	cp 3ch		; znak po znaku bez TOKENS
	jp c,X02d1
X0285:	push de
	ld de,tb_tok-1	; rozpoznání klíčového slova
	push bc
	ld bc,X02cd	; adresa pro návrat (STACK)
	push bc
	ld b,7fh	; připravit počitadlo TOKEN CODE
	ld a,(hl)
	and a
	jp p,X0298
	and 7fh
	ld (hl),a
X0298:	ld c,(hl)		; do acc (=reg.c) se uloží bajt z (hl)
	ex de,hl
X029a:	inc hl
	or (hl)
	jp p,X029a	; najít první znak dalšího příkazu
	inc b		; a zvednout počitadlo TOKEN CODE
	ld a,(hl)
	and 7fh
	ret z		; test na konec tabulky příkazů
	cp c		; porovnat se znakem rozpoznávaného slova
	jp nz,X029a	; při první neshodě zkusit další příkaz
	ex de,hl
	push hl
X02aa: 	inc de
	ld a,(de)		; test dalších znaků nalezeného příkazu
	and a
	jp m,X02c9	; až do příchodu nového příkazu
	ld c,a
	ld a,b
	cp 88h		; pokud zrovna porovnáváme shodu na
	jp nz,X02b9	; příkaz GOTO, pak při porovnávání
	rst 0x10; přeskakujeme mezery v BASIC zápisu
	dec hl		; možné jsou proto varianty:
X02b9:	inc hl		; GOTO
	ld a,(hl)		; GO TO
	and a		; G O T O
	jp p,X02c1	; G   OT O
	and 7fh
X02c1:	cp c
	jp z,X02aa	; shoda dalšího znaku rozpoznávaného příkazu
	pop hl
	 jp X0298	; jinak test na další příkaz
X02c9:	ld c,b		; v reg. c vrátí TOKEN CODE
	pop af
	ex de,hl
	ret
X02cd:	ex de,hl		; pokud jsem identifikoval klíčové slovo
	ld a,c		; BASICu, uložím je následující procedurou
	pop bc		; do výstupního buferu
	pop de
			; (02d1h)
X02d1:	inc hl		; doslovný převod znaku
	ld (de),a		; inkriminovaný znak uložit
	inc de		; další adresa na výstupu
	inc c		; počitadlo převedených symbolů
	sub 3ah
	jp z,X02df	; dvojtečka? pak vypnout uvozovkový mód
	cp 49h
	jp nz,X02e2	; příkaz DATA? pak zapnout uvozovkový režim
X02df:	ld (quote),a
X02e2:	sub 54h		; příkaz REM? pak nezapínat uvozovkový režim
	jp nz,X0246	; ale přesto kopírovat doslova až do příchodu
	ld b,a		; nulového bajtu, který uložím do registru B
X02e8:	ld a,(hl)		; doslovná kopírovací smyčka, čekající
	and a		; na příchod ukončovacího znaku, který
	jp z,X02f8	; je držen v registru B (buď to budou
	cp b		; uvozovky nebo nulový bajt konce řádku)
	jp z,X02d1
X02f1:	inc hl
	ld (de),a
	inc c
	inc de
	 jp X02e8
X02f8:	ld hl,c_odloz-1	; zakončení převodu - připraví
	ld (de),a		; ukazatel před bufer a na konec
	inc de		; buferu přidá tři nuly
	ld (de),a
	inc de
	ld (de),a
	ret
; *****************************************************
; pípnout, vymazat editační bufer a editovat dialogový
; řádek voláním nestandardního vstupu podprogramu ENTER
; *****************************************************
			; (0301h)
X0301:	call c_beep
	call clr
; *******************************************************
; editace dialogového řádku bez jeho předchozího vymazání
; *******************************************************
			; (0307h)
X0307:	ld hl,c_odloz	; od této adresy se nakopíruje text,
	ld (hl),0		; zadaný v dialogovém řádku při editaci
	ld (odloz),hl
	call enter2	; volat podprogram ENTER (editace řádku)
	ld hl,(lstr)
	ex de,hl
	ld hl,c_odloz	; sečtením adres začátku textového buferu
	add hl,de		; a počtu znaků v něm
	inc hl		; a ještě posunutím za poslední znak
	xor a		; dostaneme adresu, na kterou umístíme
	ld (hl),a		; editační zarážku 00
	ld (colpos),a	; vynulovat počitadlo tisk. sloupce
	ld hl,c_odloz-1	; a inicializovat HL na začátek textového
	ret		; buferu
; *******************************************************************
; "driver" tisku standardní tiskovou procedurou do editačního buferu,
; což se následně projeví jako předtisk dat v dialogovém řádku
; *******************************************************************
			; (0324h)
X0324:	push hl
	ld hl,(X002c)	; načíst aktuální ukazatel (kurzor)
	ld (hl),a		; uložit znak do buferu
	inc hl		; posunout kurzor
	ld (X002c),hl	; a jeho hodnotu uložit
	pop hl
	ret
; ************
; příkaz LLIST
; ************
			; (032fh)
c_llst:	call rdlnnr	; načíst parametr (číslo řádku)
	ret nz		; konec s chybou, pokud nenásleduje dvojtečka
	pop bc		; zrušit návratovou adresu (ukončit program)
	call fndlin	; nalézt požadovaný řádek
	push bc
X0338:	pop hl		; v HL mám počáteční adresu aktuálního řádku
	ld c,(hl)
	inc hl
	ld b,(hl)		; do BC načtu délku řádku,
	inc hl
	ld a,b
	or c		; je-li nulová, jsem na konci programu
	jp z,X0087	; a tak se vrátím do dialogové smyčky
	push bc
	push hl
	ld hl,maxcol	; uschovat původní hodnotu proměnné maxcol
	ld a,(hl)
	ld (X0366+1),a
	ld (hl),79	; a nastavit hodnotu 79 (to jako 80 sloupců)
	ld hl,(buf)	; adresu buferu dialogového řádku použijeme
	ld (X002c),hl	; jako adresu tiskového buferu pro
	ld hl,X0324	; tiskový driver universálního výstupu
	ld (cout+1),hl	; do paměťového buferu
	pop hl
	ld e,(hl)		; nyní načteme BASICovské číslo řádku
	inc hl
	ld d,(hl)
	inc hl
	push hl
	ex de,hl
	call X126b	; a vytiskneme je zatím do buferu
	call X0383	; a stejně tak i zbylý obsah řádku
X0366:	ld a,0		; zde se nezapisuje nula, jak by se mohlo
	ld (maxcol),a	; zdát ale původní hodnota proměnné maxcol
	call X1e33	; universální výstup přesměrovat zpět
			; do pracovní oblasti obrazovky
	call wrbuf	; do dialogového řádku zobrazíme náhled
			; vybraného řádku
	call inklav	; a přečteme, jakou klávesou uživatel reagoval
	cp 0dh
	jp nz,X0149	; pokud je to EOL, jdeme editovat
	call clr	; jinak ten bufer vyčistíme
	xor a
	ld (colpos),a	; ještě inicializace počitadla znaků
	 jp X0338	; a jdeme zobrazit další řádek
; **************************************************************
; vytiskne zakódovaný obsah BASICovského řádku do čisté sekvence
; ASCII znaků (rozvine zástupné jednobajtové kódy příkazů)
; **************************************************************
			; (0383h)
X0383:	pop hl		; defacto do HL uložíme předposlední položku
	ex (sp),hl		; ze zásobníku, která je adresou v programu
			; na pátem bajtu vybraného řádku, tedy
			; za délkou řádku a jeho číslem
	ld bc,32	; C = ASCII kód mezery (úvodní mezera za číslem
			;     tisknutého řádku)
X0388:	ld d,0		; D = 00/22h - atribut uvozovkového režimu
X038a:	ld a,c
	and a
	call nz,X03dd	; jakýkoliv nenulový znak vytisknout
	ld a,(hl)
	and a
	inc hl
	ret z		; konec řádku
	ld c,a
	cp 22h		; test na uvozovky
	jp nz,X039b
	sub d		; pokud přijdou uvozovky, překlopí se hodnota
	ld d,a		; registru D na tu druhou z hodnot 00/22h
X039b:	ld a,d
	and a		; při uvozovkovém (doslovném) režimu se nic
	jp nz,X038a	; nedekóduje a tiskne se každý bajt natvrdo
	ld a,b		; ošetření znaků za příkazy DATA a REM
	and a		; v případě těchto příkazů se vše co je za
	jp z,X03ad	; nimi interpretuje jako jednoduché ASCII
	sub c		; znaky (u příkazu DATA až do následujícího
	jp nz,X03aa	; znaku dvojtečka, u příkazu REM
	ld b,a		; až do následujícího znaku LF - ASCII kód 0Fh)
X03aa:	 jp X03da	; jde na další znak (vypíná uvozovkový mód)
; ****************************************************************
; dle kódu v registru C vytiskne ASCII znak nebo zakódovaný příkaz
; (u příkazů DATA a REM aktivuje jejich atributy)
; ****************************************************************
X03ad:	ld a,c		; je-li načtený bajt v rozsahu 00..7Fh,
	and a		; pak se jedná o prostý ASCII znak
	jp p,X03da	; a ten bude vytištěn
	sub 7fh		; kódy nad 7Fh vyhledáme v tabulce TOKENS
	ld c,a
	ld de,tb_tok
	cp 4		; v případě kódu příkazu DATA
	jp nz,X03bf
	ld b,3ah	; nastavíme atribut 3Ah (ASCII kód dvojtečky)
X03bf:	cp 0fh		; v případě kódu příkazu REM
	jp nz,X03c5
	ld b,a		; atribut 0Fh (ASCII kód LF, součást CR+LF)
X03c5:	ld a,(de)		; dojet v tabulce TOKENS na začátek dalšího
	inc de		; klíčového slova
	and a
	jp p,X03c5
	dec c		; čekání na to správné klíčové slovo
	jp nz,X03c5
	and 7fh		; odmaskovat MSB prvního znaku příkazu
X03d1:	call X03dd	; vytisknout tento znak
	ld a,(de)		; načíst další znak nalezeného příkazu
	inc de		; ukazatel posunout za něj,
	and a		; a dokud není začátek dalšího příkazu (což
	jp p,X03d1	; je konec toho aktuálního), tisknout..
X03da:	 jp X0388	; jde na další znak (vypíná uvozovkový mód)
; *************************************************
; universální výstup znaku do čehokoliv s ošetřením
; maximálního počtu znaků na řádek při tisku
; *************************************************
X03dd:	push bc		; (03ddh)
	push af
	cp 20h		; jedná se o řídicí znak ASCII?
	jp c,X03f7	; pokud ano, běž přímo na tiskový driver
	ld a,(maxcol)	; je-li omezovač počtu sloupců nulový
	and a		; pak nic neřešit a přímo tisknout
	jp z,X03f7
	ld b,a		; ale jinak porovnat s aktuálním číslem
	ld a,(colpos)	; tiskového sloupce a pokud tisk
	cp b		; překročil maximální sloupec,
	call nc,X0723	; zařádkovat (CR+LF+NULL bajtů)
	inc a
	ld (colpos),a	; formálně upravit ukazatel tiskového sloupce
X03f7:	pop af		; a zde již přechod na samotný tisk
	push af
	ld c,a
	call cout	; volání univerzálního tiskového driveru
	pop af
	pop bc
	ret
; ***********
; příkaz LIST
; ***********
			; (0400h)
c_list:	call X23b3	; záplata pro kanálový výstup
X0403:	call rdlnnr	; načíst číslo řádku
	ret nz		; za příkazem kromě čísla nesmí být nic
	pop bc		; po příkazu LIST se (případný) program ukončí
	call fndlin	; číslo řádku převést na adresu řádku v paměti
	push bc
X040c:	pop hl		; v HL mám počáteční adresu aktuálního řádku
	ld c,(hl)
	inc hl
	ld b,(hl)		; do BC načtu délku řádku,
	inc hl
	xor a
	ld (X0740+1),a
	ld a,b
	or c		; je-li nulová, jsem na konci programu
	jp z,X0084	; a tak se vrátím do dialogové smyčky
	call X04eb	; test SHIFT/STOP
	call X0723	; vyšle kombinaci CR+LF+NULL bajtů
	push bc
	ld e,(hl)		; nyní načteme BASICovské číslo řádku
	inc hl
	ld d,(hl)
	inc hl
	push hl
	ex de,hl
	call X126b	; které vytiskneme
	ld a,(colpos)	; zde počet mezer na úvod zalomeného řádku,
	inc a		; aby se nám čísla řádků neztrácela v textu
	ld (X0740+1),a	; (čísla řádků jsou předsazená o svou délku+1)
	call X0383	; vytisknout kódovaný zbytek BASIC řádku
	 jp X040c	; další řádek..
; ***************************************************
; datová struktura v zásobníku pro jeden cyklus FOR
; má tento tvar (adresa směrem dolů klesá)
; ***************************************************
; 2 bajty - adresa zdrojového kódu, kde začíná smyčka
;           (za posledním znakem celého zápisu FOR..)
; 2 bajty - číslo řádku, kde začíná smyčka
;           (za posledním znakem celého zápisu FOR..)
; 4 bajty - FP číslo, určující koncovou hodnotu cyklu
; 4 bajty - FP číslo, určující velikost kroku
;           (včetně znaménka!)
; 1 bajt  - ještě jednou znaménko kroku -1/0/+1
; 2 bajty - adresa proměnné cyklu (ukazuje na 3. bajt
;           ze šesti, tedy na vlastní hodnotu)
; 1 bajt  - signatura 81h označující cyklus FOR
; ***************************************************
; **********
; příkaz FOR
; **********
			; (0437h)
c_for:	ld a,64h	; jako proměnnou cyklu nelze
	ld (indxen),a	; použít indexovanou proměnnou
	call c_let	; volání příkazu LET (načte pracovní
	ex (sp),hl		; proměnnou a výchozí hodnotu cyklu)
	call X00af	; pokud proměnná cyklu není ještě
	pop de		; v žádném cyklu použita, snížím
	jp nz,X0449	; stack a tam bude založena nová
	add hl,bc		; struktura FOR, jinak přepíšu!
	ld sp,hl		; nalezenou strukturu FOR, která
			; tuto proměnnou již použila a tím
			; při následném NEXT vyvolám chybu
			; křížení smyček 05h - No for stm
X0449:	ex de,hl
	ld c,8		; test na volných 8*2 bajty paměti
	call X00df
	push hl		; výpočet adresy za zápisem FOR..
	call c_data	; tuto adresu začátku smyčky
	ex (sp),hl		; uložit do zásobníku
	push hl
	ld hl,(crntln)	; uložit do zásobníku číslo
	ex (sp),hl		; aktuálního řádku
	call X08cb
	rst 0x08; vynutit si klíčové slovo
	.db 9eh		; "TO" před koncovou hodnotou cyklu
	call numpar	; načíst koncovou hodnotu cyklu
	push hl		; do FP akumulátoru
	call X1113	; a následně do B:C:D:E
	pop hl
	push bc		; uložit do zásobníku tuto koncovou
	push de		; hodnotu (FP konstanta)
	ld bc,8100h	; default hodnota STEP (+1)
	ld d,c		; pokud není výslovně uvedena
	ld e,d		; (FP číslo 00h 00h 00h 81h)
	ld a,(hl)
	cp 0a3h	; následuje příkaz STEP?
	ld a,1		; ještě dodefinovat znaménko kroku
	jp nz,X047f
	rst 0x10; STEP uveden => přeskočit mezery a
	call numpar	; načíst hodnotu kroku
	push hl		; do FP akumulátoru
	call X1113	; a následně do B:C:D:E
	rst 0x30; do ACC dosadit znaménko kroku
	pop hl
X047f:	push bc		; koncová hodnota ve formátu FP
	push de		; velikost kroku ve formátu FP 
	push af	; znaménko kroku -1/0+1
	inc sp		; (uloží se jen ACC, ne příznaky)
	push hl
	ld hl,(crntadr)	; adresa proměnné cyklu
	ex (sp),hl
X0488:	ld b,81h	; a jeden bajt signatury FOR (81h)
	push bc
	inc sp		; (uloží se jen reg. B, ale ne C)
; *********************************
; vykonání další instrukce v pořadí
; *********************************
			; 048ch – ExecNext
X048c:	call X04eb	; otestovat klávesy SHIFT a STOP
	ld (crntadr),hl
	ld a,(hl)
	cp ':'		; pokud najdu oddělovací znak
	jp z,X04ac	; dvojtečka, přeskočím jej
	and a		; každý jiný znak kromě nuly
	jp nz,err_09	; vyvolá chybu 09h - Syntax err.
	inc hl		; našel jsem konec řádku, načtu tedy
	ld a,(hl)		; první dva bajty následujícího
	inc hl		; řádku
	or (hl)
	jp z,X04fd	; jsou-li nulové, pak konec programu
	inc hl		; jinak načtu číslo nového řádku
	ld e,(hl)
	inc hl
	ld d,(hl)
	ex de,hl
X04a8:	ld (crntln),hl	; a uložím je jako číslo aktuálního
	ex de,hl		; řádku programu
; *************************
; Interpretace kódu příkazu
; *************************
			; (04ach)
X04ac:	rst 0x10
	ld de,X048c	; přímé vykonání příkazu
	push de
X04b1:	ret z
X04b2:	sub 80h		; vstup v ACC
	jp c,c_let	; znaky pod 80h => interpretovat jako LET
	cp 1dh		; kódy příkazů (ne funkcí a pomocných slov)
	jp c,X04c3
	sub 46h		; pro kódy funkcí a pomocných slov se volá
	jp m,err_09	; chybové hlášení 9h – Syntax err
	add a,1dh		; u 2. části příkazů (od c6h) se přemapuje
X04c3:	rlca		; ukazatel do tabulky adres výkonných rutin
	ld c,a		; v reg. páru BC se sestaví ofset do této
	ld b,0		; tabulky adres výkonných rutin
	ex de,hl
	ld hl,tb_cmd	; tabulka klíčových slov
	add hl,bc
	ld c,(hl)
	inc hl
	ld b,(hl)
	push bc		; uložit adresu, kam se nakonec půjde
	ex de,hl
X04d1:	inc hl
	ld a,(hl)
	cp 3ah		; ukazatel výběru BASIC kódu nastavit 
	ret nc		; na event. parametr za příkazem
; ****************************
; dokončení RST2 - testu znaku
; ****************************
X04d6:	cp 20h		; přeskakování mezer
	jp z,X04d1
	cp 30h		; test na dolní rozsah cifer
	ccf		; je-li znakem cifra, vrací CY=1
	inc a
	dec a
	ret
; *********************************
; RESTORE na začátek BASIC programu
; *********************************
			; (04e1h)
datrst:	ex de,hl
	ld hl,(pgbase)	; adresa začátku BASIC programu
	dec hl
X04e6:	ld (dataadr),hl	; je použita jako výchozí adresa
	ex de,hl		; řádku s DATA pro příkaz READ
	ret
; ***********************
; SHIFT/STOP LISTING TEST
; ***********************
			; (04ebh)
X04eb:	in a,(0f5h)		; test klávesy SHIFT
	and 20h
	jp z,X04eb	; čekání při SHIFT
X04f2:	in a,(0f5h)
	and 40h
	ret nz		; test klávesy STOP
; ***********
; příkaz STOP
; ***********
			; (04f7h)
c_stop:	.db 0f6h	; ori 0c0h - kvůli zjednodušení se
			; u příkazu STOP nehlídá následující
			; znak, tak jako u příkazu END
; **********
; příkaz END
; **********
			; (04f8h)
c_end:	ret nz		; chyba při jiném znaku než ':'
	ld (crntadr),hl	; uložit ukazatel na aktuální znak programu
	pop bc		; likvidace návratové adresy
; **********************************
; ukončení programu, dojdou-li řádky
; **********************************
			; (04fdh)
X04fd:	ld hl,(crntln)	; otestovat číslo řádku, pokud je platné
	push af	; (tj. není FFFFh) pak jsme v programu a ne
	ld a,l		; v dialogovém režimu a tudíž si uložíme
	and h
	inc a
	jp z,X0510
	ld (stopln),hl	; řádek, na kterém jsme přerušili program
	ld hl,(crntadr)
	ld (stopadr),hl	; a ukazatel na následující znak v programu
X0510:	call X071e
	pop af
	ld e,16h	; chyba 16h - „Stop“ se vyvolá
	call nz,X169c	; jen u příkazu STOP a stisku klávesy STOP
	 jp X0084
; ***********
; příkaz CONT
; ***********
			; (051ch)
c_cont:	ld hl,(stopadr)	; pokud není kde pokračovat,
	ld a,h
	or l		; (ukazatel stopadr má hodnotu 0000h)
	ld e,0dh
	jp z,X0108	; vyvolá se chyba 0dh - „Can’t cont“
	ex de,hl
	ld hl,(stopln)	; jinak se obnoví číslo řádku
	ld (crntln),hl
	ex de,hl		; a do HL adresa aktuálního znaku
	ret		; (ta se později uloží do crntadr)
; ***********
; příkaz NULL
; ***********
			; (052fh)
c_null:	rst 0x20; Načíst parametr v rozsahu
	ret nz		; 0..255
	inc a
	cp 50h		; a pokud je větší než 78, hlásit
	jp nc,X0569	; chybu 03h - Fnc.param.
	ld (X0027),a	; jinak parametr uložit
	ret
; ****************************************************************
; je-li znak na adrese (HL) písmeno A..Z nebo a..z, pak vrací CY=0
; ****************************************************************
			; (053bh)
isabcd:	ld a,(hl)		; testuje bajt
	cp 40h		; zda je větší než kód písmene @
	ret c
	ld a,(hl)
	cp 5bh		; a zároveň menší než kód písmene Z
	ccf
	ret nc
	ld a,(hl)
	cp 61h		; a další test na skupinu kódů
	ret c
	cp 7bh		; písmen a..z
	ccf
	ret
; *********************************************************
; přeskočí mezery a vyhodnotí číselný výraz s rozsahem
; 0..32767 (v opačném případě hlásí chybu 03h - Fnc.param.)
; *********************************************************
			; (054ch)
X054c:	rst 0x10; přeskočit mezery
; ******************************************************
; vyhodnotí číselný výraz a pokud je záporný nebo >32767
; pak zahlásí chybu Fnc.param.
; ******************************************************
			; (054dh)
getpin:	call numpar	; vyhodnotit číselný výraz
; **************************************
; test čísla ve FP akumulátoru na rozsah
; 0..+32767
; **************************************
			; (0550h)
tstpin:	rst 0x30; test FP čísla na znaménko
	jp m,X0569	; záporné číslo => chyba Fnc.param.
; **************************************
; test čísla ve FP akumulátoru na rozsah
; -32768..+32767
; **************************************
			; (0554h)
tstint:	ld a,(fpaccum+3)	; je-li absolutní hodnota čísla
	cp 90h		; ve FP akumulátoru <32768, pak
	jp c,X116d	; převést na Integer 16 bit
	ld bc,9080h	; a ještě povolit průchod
	ld de,0000h	; okrajové hodnoty -32768
	push hl
	call X1142	; zde je vlastní porovnání..
	pop hl
	ld d,c
	ret z
X0569:	ld e,3		; chyba 03h - Fnc.param.
	rst 0x28
; ***********************
; zkompletuje číslo řádku
; ***********************
			; (056ch)
rdlnnr:	dec hl		; test znaku na cifru
	rst 0x10
	jp z,getnum	; po dvojtečce načíst číslo
	jp c,getnum	; při cifře také načíst číslo
	push bc
	call getpin	; jinak vyčíslit výraz
	pop bc		; s povoleným rozsahem
	dec hl		; 0..32767
	rst 0x10
	ret
; *******************************************
; Ze stringu extrahuje BASICovské číslo řádku
; výstup: reg. DE
; *******************************************
			; (057ch)
getnum:	dec hl
	ld de,0
X0580:	rst 0x10
	ret nc		; konec při jiném znaku než je cifra
	push hl
	push af
	ld hl,0ccch	; 3276
	rst 0x18
	jp c,err_09	; test na Syntax Err při >3276x
	ld h,d
	ld l,e
	add hl,de
	add hl,hl
	add hl,de
	add hl,hl		; HL = 10 * DE
	ld a,h
	and 80h
	jp nz,err_09	; Syntax Err při čísle řádku >32767
	pop af
	sub 30h		; obnovit načtený ciferný znak
	ld e,a		; a převést na cifru
	ld d,0
	add hl,de		; HL = 10 * DE + cifra
	ex de,hl		; a výsledek uložit do reg. DE
	pop hl
	 jp X0580
; **********
; příkaz RUN
; **********
			; (05a3h)
c_run:	jp z,X01ff	; 
	call X0205
	ld bc,X048c
	 jp X05bf
; ************
; příkaz GOSUB
; ************
			; (05afh)
c_gosb:	ld c,3		; Alokace 3 x 2 bajty v zásobníku (i když se
	call X00df	; využije jen 5 bajtů)
	pop bc		; dočasně vyzvednout návratovou adresu
	push hl		; uložit ukazatel na aktuální znak v programu
	push hl
	ld hl,(crntln)
	ex (sp),hl		; dokončit uložení aktuálního čísla řádku
	ld a,8ch	; uložit kód „GOSUB“
	push af
	inc sp		; zde se ušetří onen šestý bajt
X05bf:	push bc		; a zpět uložit návratovou adresu
			; pak už se to chová jako GOTO
; ***********
; příkaz GOTO
; ***********
			; (05c0h)
c_goto:	call rdlnnr	; do DE připravit požadované číslo řádku
	call c_rem	; defacto „dojet“ na konec BASIC řádku
	push hl
	ld hl,(crntln)	; aktuální číslo BASIC řádku
	rst 0x18; porovnat s požadovaným
	pop hl
	inc hl
	call c,fndlfr	; a buď od daného místa
	call nc,fndlin	; nebo od začátku programu
	ld h,b		; vyhledat požadovaný BASIC řádek
	ld l,c
	dec hl
	ret c		; řádek nalezen => ukončení příkazu
; **********************************
; chybové hlášení "Řádek neexistuje"
; **********************************
err_0b:	ld e,0bh	; chyba „Numb.nonex“ (05d7h)
	rst 0x28
; *************
; příkaz RETURN
; *************
			; (05dah)
c_retr:	ret nz		; příkaz musí být bez parametrů
	ld d,0ffh
	call X00af	; test zásobníku
	ld sp,hl		; a odebrání 4 nevýznamných bajtů
	cp 8ch		; test na kód GOSUB
	ld e,0ah
	jp nz,X0108	; chyba 0ah - „Return err“
	pop hl		; vyzvednout číslo řádku
	ld (crntln),hl	; a uložit jako aktuální
	inc hl
	ld a,h		; je-li číslo řádku platné, pak byl
	or l		; podprogram volán v programovém režimu
	jp nz,X05f9	; a proto regulérní návrat do programu
	ld a,(ovrbuf)	; podprogram byl volán v dialogovém
	and a		; režimu (číslo řádku je FFFFh)
	jp nz,X0083	; pokud došlo během chodu programu
			; k porušení editačního buferu (například
			; příkazem INPUT), pak nevykonávat další
			; příkazy v editačním režimu za voláním
			; GOSUB XXX
			; bohužel kód v tomto odstavci nefunguje,
			; protože BE70h je stále nulové!
X05f9:	ld hl,X048c	; návratová adresa do interpretační
	ex (sp),hl		; rutiny + ignorovat zbytek řádku
; ***********
; příkaz DATA
; ***********
			; (05fdh)
c_data:	.db 01h		; lxi b,X0e3a	
	.db 3ah		; zde se jen nadefinuje jedna z platných
			; zarážek, určujících konec sekvence, které
			; si nyní program nevšímá (až při READ)
			; zde defacto jen dvojtečka - ASCII kód 3Ah,
			; celá sekvence pak vypadá takto:
			; lxi b,0e3ah/nop a pokrač. na adrese 0601h,
			; kde se definuje hodnota pouze registru B
; **********
; COMAND REM
; **********
			; (05ffh)
c_rem:	ld c,0		; B = C = 0 (u REM je ignorován text
	ld b,0		; až do konce řádku - nehlídá se dvojtečka)
X0603:	ld a,c		; v registru B se drží zarážka (dvojtečka),
	ld c,b		; která se v případě potřeby vypne a schová
	ld b,a		; do registru C
X0606:	ld a,(hl)		; procházení znaků za REM/DATA/...
	and a
	ret z		; test na konec řádku
	cp b
	ret z		; test na zarážku (např. dvojtečka)
	inc hl
	cp 22h		; test na uvozovky (vypínají a opět
	jp z,X0603	; zapínají test zarážky)
	 jp X0606	; ostatní znaky přeskočit
; **********
; příkaz LET
; **********
			; (0614h)
c_let:	call varadr	; do DE načíst adresu proměnné
			; (pokud neexistuje => vytvořit)
	rst 0x08; vynucení
	.db 0ach	; token kódu '='
X0619:	push de
	ld a,(vartype)	; načíst požadovaný datový typ
	push af
	call X08d6	; vyčíslit výraz
	pop af
	ex (sp),hl
	ld (crntadr),hl
	rra		; do CY umístit typ (0 = číslo)
	call X08cd	; provést typovou kontrolu
	jp z,X065f	; skok při číselné proměnné
X062d:	push hl
	ld hl,(fpaccum)	; v FP akumulátoru přeskočíme údaj
	push hl		; o délce řetězcové proměnné a další
	inc hl		; (prázdný) bajt a z dalších dvou
	inc hl		; bajtů načteme ukazatel na text
	ld e,(hl)
	inc hl
	ld d,(hl)		; do DE ukazatel na text proměnné
	ld hl,(pgbase)
	rst 0x18; pokud ještě cílová proměnná
	jp nc,X064e	; nebyla použita (má neplatný uka-
			; zatel na text), pak založit
			; prázdnou proměnnou
	ld hl,(spbase)	; pokud už někdy použita byla,
	rst 0x18; otestuji, zda je to textová
	pop de		; konstanta ve zdrojovém kódu
	jp nc,X0656	; (adresa textu je "nad" zdrojovým
			; kódem BASIC programu ale "pod"
			; zásobníkem)
			; odkaz na textovou konstantu
			; jen přiřadím do proměnné
	ld hl,(varbase)	; stejně tak i v případě, že se
	rst 0x18; jedná o řetězec, který leží
	jp nc,X0656	; v přechodné oblasti "pod"
			; adresou začátku proměnných
X064d:	.db 3eh		; mvi a,0d1h - přeskočí "pop d"
X064e:	pop de		; obnovím adresu cílové proměnné
	call X153f	; BC = adresa zdrojového řetězce
			; HL = adresa BE59 ???
	ex de,hl
	call X0cd2	; vytvoří pracovní kopii proměnné
X0656:	call X153f	; BC = BE59 ???
			; HL = BE55 ???
	pop hl
	call X1122	; přenos 4byte z (DE) na (HL)
	pop hl
	ret
X065f:	push hl		; obsah FP akumulátoru uloží
	call X111f	; do proměnné na levé straně
	pop de		; přiřazovacího příkazu
	pop hl		; obnovit ukazatel do zdrojového
	ret		; kódu a konec příkazu
; *********
; příkaz ON
; *********
			; (0666h)
c_on:	cp 97h		; test na klíčové slovo ERR
	jp nz,X067f
	ex de,hl		; konstrukce ON ERR 
	ld hl,(crntln)	; analýza čísla řádku
	ld (onerrln),hl
	ld a,h
	and l
	inc a
	jp z,X0cb0	; chyba „Only in pg“
	ex de,hl		; jsem-li v programu, uložím adresu
	ld (oneradr),hl	; za konstrukcí ON ERR na adresu 23feh
	 jp c_rem	; a zbytek řádku ignoruji
X067f:	call numpar	; konstrukce ON var GOTO/GOSUB
	call tstint
	ld a,d
	and a
	jp z,X068d	; max. hodnota proměnné je 255
	ld de,0
X068d:	ld a,(hl)
	ld b,a
	cp 8ch		; test na klíčové slovo GOSUB
	jp z,X0697
	rst 0x08; jinak vynucený test na slovo GOTO
	.db 88h
	dec hl
X0697:	ld c,e		; v reg. e je pořadí skokové adresy
X0698:	dec c		; v seznamu za ON var GOTO/GOSUB
	ld a,b		; do acc se připraví kód GOTO/GOSUB pro ..
	jp z,X04b2	; případ úspěšného provedení skoku
	inc hl
	call rdlnnr	; přeskočit proměnnou
	cp 2ch		; pak musí být čárka
	ret nz		; jinak konec (chybí argumenty)
	 jp X0698	; přesun na další adresu v seznamu
; *********
; příkaz IF
; *********
			; (06a7h)
c_if:	call X08d6	; vyčíslení výrazu
	ld a,(hl)
	cp 88h		; test na kód GOTO
	jp z,X06b2
	rst 0x08; pokud není GOTO,
	.db 0a1h	; pak vynutit THEN
X06b2:	dec hl
	call X08cb	; vynutit si číselnou proměnnou
	rst 0x30; zde je odpověď na otázku, jak se kóduje
	jp z,c_rem	; v BASICu TRUE a FALSE:
			; TRUE  = nenulový výsledek (v FP akumulátoru)
			; FALSE = nulový výsledek
	rst 0x10; přeskočit mezery a testovat další znak
	jp c,c_goto	; pokud je, vyčíslit číslo řádku a GO
	 jp X04b1	; jinak bez jakékoliv akce pokračovat
			; v interpretaci kódu
; ************
; příkaz PRINT
; ************
			; (06c1h)
c_prnt:	call X1e33	; textový výstup nastavit na obrazovku
	cp 23h		; je-li prvním znakem za příkazem PRINT znak
	jp z,X2071	; kanálového výstupu (#), pak se přímo skočí
			; na příkaz OUTPUT, což je v dané situaci
			; ekvivalent (sdílí i stejný formát výstupních
			; dat, která lze posílat na I/O zařízení)
X06c9:	dec hl
	rst 0x10; přeskočit mezery a test PRINT bez parametrů
X06cb:	jp z,X0723	; => odřádkovat
X06ce:	ret z		; po poslední položce konec příkazu
	cp 9dh		; test na token klíčového slova TAB(
	jp z,X0763
	cp 0a0h	; test na SPC(
	jp z,X0763
	cp 0e7h	; test na AT
	jp z,X0788
	cp 0e4h	; test na INK(
	jp z,X07c0
	push hl
	cp ','		; test na oddělovač čárka
	jp z,X074f
	cp 3bh		; test na oddělovač středník
	jp z,X0783
	pop bc
	call X08d6	; když nic z toho nepřišlo, očekává se výraz
	push hl
	ld a,(vartype)	; je vyhodnocený výraz číselný nebo řetězcový?
	and a
	jp nz,X0715	; => řetězcový výraz
			; => číselný výraz
	call X1276	; FP číslo "vytiskne" do buferu
	call X0cf6	; 
	ld hl,(fpaccum)	; a délku tohoto řetězce
	ld a,(colpos)	; spolu s aktuálním sloupcovým ukazatelem
	add a,(hl)		; sečte - pokud je ovšem sloupec
	cp 48		; větší než 47,
	call nc,X0723	; odřádkuje se CR+LF+NULL bajtů
	call X0d37
	ld a,' '	; to je ta prokletá mezera, kterou BASIC bez
	call X03dd	; našeho vědomí vkládá za každé číslo
	xor a
			; (0715h)
X0715:	call nz,X0d37	; vytisknout řetězcový výraz, uvedený
	pop hl		; v příkazu PRINT,
	dec hl
	rst 0x10; přeskočit mezery
	 jp X06cb	; a test další položky příkazu PRINT
; ***************
; podmíněný CR+LF
; ***************
			; (071eh)
X071e:	ld a,(colpos)	; odřádkování CR+LF se provede jen tehdy,
	and a		; pokud to má význam (sloupcový ukazatel
	ret z		; není na začátku řádku)
; *********************************************************
; odřádkování, vyšle se sekvence znaků CR + LF + NULL bajtů
; *********************************************************
			; (0723h)
X0723:	ld a,0dh
	call X03dd	; poslat CR na universální výstup
	ld a,0ah
	call X03dd	; poslat LF na universální výstup
; *****************************************************
; dle počtu NULL bajtů vyšle tyto na universální výstup
; *****************************************************
			; (072dh)
X072d:	ld a,(X0027)	; načíst počet NULL bajtů+1
X0730:	dec a
	ld (colpos),a	; zde se fakticky nic neukládá, neboť na konci
	jp z,X0740	; procedury je vždy colpos nulové!
	push af
	xor a		; nulový bajt
	call X03dd	; vyslat na universální výstup
	pop af
	 jp X0730	; a opakovat do splnění limitu
; *************************************************************
; defacto jen zakončení předchozí procedury s nastavením CY = 0
; *************************************************************
			; (0740h)
X0740:	ld a,0		; vhodná hodnota pro další běh
; **********************************************************
; podle hodnoty v registru A vytiskne požadovaný počet mezer
; (je využíváno příkazem LIST)
; **********************************************************
			; (0742h)
X0742:	and a
	ret z		; toto asi komentář nepotřebuje..
	dec a
	push af
	ld a,' '
	call X03dd	; snad jen, že zde je universální
	pop af		; výstup znaku
	 jp X0742
; ***************
; oddělovač čárka
; ***************
			; (074fh)
X074f:	ld a,(colpos)
	cp 2ah		; pokud je aktuální hodnota tiskového sloupce
	call nc,X0723	; větší než 42, zařádkovat CR+LF+NULL bajtů
	jp nc,X0783	; a už nic jiného nedělat
X075a:	sub 14		; v daném řádku tak dlouho odečítám tiskovou
	jp nc,X075a	; rozteč 14, až se dostanu "před" začátek
	cpl		; řádku a výsledek po otočení znaménka mi dá
	 jp X0778	; počet mezer, které musím vytisknout..
; *********************
; klíčová slova TAB/SPC
; *********************
			; (0763h)
X0763:	push af
	rst 0x10; přeskočit mezery
	rst 0x20; načíst parametr příkazu
	rst 0x08; vynutit pravou závorku
	.db ')'
	dec hl
	pop af
	sub 0a0h	; nyní rozlišit TAB( a SPC(
	push hl
	jp z,X0773	; TAB se počítá od začátku řádku
	ld a,(colpos)	; SPC se "odpíchne" od aktuálního sloupce
X0773:	cpl
	add a,e		; nyní připočteme parametr funkce TAB/SPC
	jp nc,X0783	; a pokud se u TAB nelze "vrátit" doleva
			; ignorujeme takový TAB(N)
; ****************************************************
; dle hodnoty v reg. A vytiskne požadovaný počet mezer
; ****************************************************
X0778:	inc a
	ld b,a		; výsledný počet požadovaných
	ld a,' '	; mezer
X077c:	call X03dd	; pustíme do universálního výstupu
	dec b
	jp nz,X077c
; ***************************************************************
; bezprostřední přechod na další položku PRINT bez vkládání mezer
; ***************************************************************
			; (0783h)
X0783:	pop hl		; obnovit ukazatel na další znaky
	rst 0x10; přeskočit případné mezery
	 jp X06ce	; a zpět do smyčky příkazu PRINT
; ****************
; klíčové slovo AT
; ****************
			; (0788h)
X0788:	rst 0x10
	rst 0x20; načíst číslo Y tiskového řádku (nahoře=0)
	cp 1ah		; a pokud je větší než 25, upravit
	jp c,X0791
	ld a,19h	; je právě na hodnotu 25
X0791:	push hl
	inc a
	ld b,a		; nyní se vypočte dílčí část fyzické adresy
	add a,a		; ve videoram, která odpovídá zvolenému řádku
	add a,a		; dle vzorce
	add a,a		;  adresa = C000h + 64 x (9Y+11)
	add a,b
	inc a		; tedy jeden textový řádek má 9 mikrořádků
	inc a		; a protože znaky se kreslí "odspodu",
	ld b,a		; je tam i ta aditivní konstanta pro první
	rrca		; (respektive nultý) řádek
	rrca		; konstanta C000h je začátek videoram
	and 3fh
	or 0c0h
	ld h,a
	ld a,b
	rrca
	rrca
	and 0c0h
	ld l,a
	ex (sp),hl
	rst 0x08; vynutit oddělovací čárku
	.db ','
	rst 0x20; načíst číslo tiskového sloupce
	dec hl
	cp 48		; a pokud je větší než 47, upravit
	jp c,X07b4
	ld a,47	; je právě na hodnotu 47
X07b4:	ld (colpos),a	; (a uložit i do ukazatele tisk. sloupce)
	ex (sp),hl		; obnovit předvypočtenou fyzickou adresu
	add a,l		; a přičíst příspěvek řádku
	ld l,a		; a sestavenou adresu ve videoram pro ukazatel
	ld (cursor),hl	; tisku uložit do proměnné BIOSu
	 jp X0783	; a běž na další položku v příkazu PRINT
; *****************
; klíčové slovo INK
; *****************
			; (07c0h)
X07c0:	rst 0x10; přeskočit mezery
	call X2161	; zavolat rutinu PEN/INK pro nastavení masky
	rst 0x08; vynutit pravou závorku
	.db ')'
	 jp X06ce	; a zpracovat další položku v příkazu PRINT
; ************************************************
; zpracování chyby při vstupu dat INPUT/ENTER/READ
; ************************************************
			; (07c9h)
X07c9:	ld a,(inptype)	; pokud byl vstup dat realizován
	and a		; příkazem READ
	jp nz,X00f7	; vyvolat chybu 09h - "Syntax err"
	ld e,13h	; pro INPUT chyba 13h - "Input err"
	rst 0x28
; ******************
; příkaz INPUT/ENTER
; ******************
			; (07d3h)
c_inpt:	cp 23h		; test na znak # (kanálový vstup)
	jp z,X2123	; a případný odskok
	push hl
	ld hl,X0301	; nadefinovat obslužný vektor pro
	ld (X080b+1),hl	; vstup dat z klávesnice (INPUT)
	call prgtst	; test na programový režim
	pop hl
X07e3:	push hl		; uschovat ukazatel na zdrojový text
	pop bc
	push bc		; BC = HL
	 jp X07ee	; a skok na společnou rutinu
; ***********
; příkaz READ
; ***********
			; (07e9h)
c_read:	push hl
	ld hl,(dataadr)
X07ed:	.db 0f6h	; + xra a => ori 0afh
X07ee:	xor a
; ******************************
; společná část INPUT/ENTER/READ
; ******************************
X07ef:	ld (inptype),a
	ex (sp),hl
X07f3:	ld bc,2ccfh	; skryté instrukce CF 2C
	call varadr	; DE = adresa proměnné
	ex (sp),hl
	push de
	ld a,(hl)		; test na čárku
	cp ','
	jp z,X0812
	ld a,(inptype)	; zde se procedura dělí na dvě
	and a		; specifické části READ / INPUT
	jp nz,X085d	; skok při READ
	ld hl,7f01h
X080b:	call 0		; INPUT/ENTER vektor
	pop de
	pop bc
	push bc
	push de
X0812:	ld a,(vartype)	; rozlišení číselné a řetězcové
	and a		; proměnné
	jp z,X0832
	rst 0x10; načtení řetězcové proměnné
	ld d,a		; pokud řetězec začíná uvozovkami,
	ld b,a		; pak může končit opět jen uvozovkami
	cp 22h		; nebo koncem řádku
	jp z,X0826
	ld d,':'	; jinak může "končit" dvojtečkou (konec
	ld b,','	; seznamu DATA) nebo čárkou (oddělovač
	dec hl		; hodnot) nebo koncem řádku
X0826:	call X0cfa	; ..vlastní "vyčíslení" řetězce..
	ex de,hl		; vsunout návratovou adresu na proceduru,
	ld hl,X083b	; která na rozdíl od LET ještě otestuje
	ex (sp),hl		; čárku za hodnotou a event. provede
	push de		; nové přiřazení..
	 jp X062d	; skok do výkonné části příkazu LET
			; načtení číselné proměnné
X0832:	rst 0x10; ze zdrojového textu sestavit
	call X11cc	; FP konstantu do FP akumulátoru
	ex (sp),hl		; HL = adresa proměnné, a tam
	call X111f	; uložit sestavenou FP konstantu
	pop hl		; obnovit ukazatel na zdroj. text
X083b:	dec hl		; přeskočit mezery v zápisu BASICu
	rst 0x10; a pokud není konec řádku nebo
	jp z,X0845	; dvojtečka, pak testovat..
	cp ','		; oddělovač položek?
	jp nz,X07c9	; pokud není, hlásit chybu
X0845:	ex (sp),hl		; ze zápisu dat se přepnout
	dec hl		; za příkaz READ/INPUT
	rst 0x10; pokud nekončí seznam proměnných,
	jp nz,X07f3+1	; návrat ke čtení dalšího prvku
	pop de
	ld a,(inptype)	; pokud už nejsou další proměnné
	and a		; následující za příkazem READ,
	ex de,hl		; aktualizovat ukazatel pro READ
	jp nz,X04e6	; na aktuální prvek DATA
	push de		; pokud nechce číst příkaz INPUT
	or (hl)		; další hodnoty a ony tam jsou, pak
	ld e,14h	; chyba 14h - Field lost
	jp nz,X0108
	pop hl		; obnovit ukazatel do zdrojového
	ret		; textu programu v BASICu a konec
; *******************************
; specifická část pro příkaz READ
; *******************************
			; (085dh)
X085d:	call c_data
	and a
	jp nz,X0876
	inc hl		; po detekci konce řádku otestuji
	ld a,(hl)		; přítomnost dalšího řádku
	inc hl
	or (hl)		; pokud již další neexistuje, pak
	ld e,6		; vyvolat chybu 06h - Data exhau
	jp z,X0108
	inc hl		; v opačném případě uložím číslo
	ld e,(hl)		; nového řádku jako číslo
	inc hl
	ld d,(hl)
	ex de,hl
	ld (dataln),hl	; řádku s aktuální položkou DATA
	ex de,hl
X0876:	rst 0x10; je další znak kódem příkazu DATA?
	cp 83h		; pokud ne,
	jp nz,X085d	; čti další proměnnou (nebo znak)
	 jp X0812	
; ***********
; příkaz NEXT
; ***********
			; (087fh)
c_next:	ld de,0		; následuje-li text, zkusit jej
X0882:	call nz,varadr	; interpretovat jako proměnnou cyklu
	ld (crntadr),hl	; jinak si NEXT vybere poslední FOR
	call X00af	; zkusit v zásobníku najít strukturu
	jp nz,err_05	; FOR s adresou proměnné cyklu v DE
			; (pokud není nebo nesedí proměnná
			; cyklu, vyvolá se chyba křížení
			; smyček FOR    05h - No for stm)
	ld sp,hl
	push de
	ld a,(hl)
	inc hl
	push af
	push de
	call X1105	; FP číslo zkopírovat z adresy (HL)
	ex (sp),hl		; do FP akumulátoru (proměnná cyklu)
	push hl
	call X0e8d	; přičte krok cyklu k FP akumulátoru
	pop hl
	call X111f	; obsah FP akumulátoru vrátí do paměti
	pop hl
	call X1116	; do B:C:D:E načte cílovou hodnotu cyklu
	push hl
	call X1142	; a porovná s obsahem FP akumulátoru
	pop hl
	pop bc
	sub b
	call X1116	
	jp z,X08ba	; dosaženo cílové hodnoty proměnné cyklu
	ex de,hl		; nebylo dosaženo cílové hodnoty,
	ld (crntln),hl	; další průchod cyklem..
	ld l,c
	ld h,b
	 jp X0488
X08ba:	ld sp,hl		; parametry v příkazu NEXT je možné
	ld hl,(crntadr)	; sdružovat oddělením čárkou, např.
	ld a,(hl)		; NEXT C,B,A
	cp ','
	jp nz,X048c
	rst 0x10; pokračovat na NEXT další proměnné
	call X0882	; s uschováním adresy zdrojového
			; textu (program nepokračuje
			; procedurou numpar!)
; ************************************************************
; výpočet hodnoty číselného výrazu a uložení do FP akumulátoru
; ************************************************************
			; (08c8h)
numpar:	call X08d6 	; vyhodnotit výraz
; ************************
; typová kontrola na číslo
; ************************
X08cb:	.db 0f6h	; ori 37h
			; následující typovou kontrolu volám
			; s vynulovaným CY, tedy požaduji
			; číselnou proměnnou
; **************************
; typová kontrola na řetězec
; **************************
			; (08cch)
t_strg:	scf		; budu testovat na řetězcový typ
X08cd:	call X1684	; vlastní test
	ret pe		; pokud je shoda, návrat
X08d1:	ld e,11h
	rst 0x28; jinak chyba 11h - Type conv.
; **************************************************************
; Vyčíslení hodnoty výrazu a uložení do FP akumulátoru
; s vynucením levé závorky (u funkcí nebo povinného závorkování)
; **************************************************************
X08d4:	rst 0x08; vynutit levou závorku
	.db '('
; *************************************************
; vyhodnocení obecného výrazu (bez zadané priority)
; *************************************************
X08d6:	dec hl
	ld d,0		; na začátku žádná priorita
; **************************************************
; vyhodnocení obecného výrazu (s prioritou v reg. D)
; **************************************************
X08d9:	push de
	ld c,1		; Bude pro novou FP proměnnou
	call X00df	; dost místa v paměti?
	call X094b	; vyčíslení dílčího výrazu před
			; operátorem
	ld (eofxpr),hl	; uložit adresu za výrazem
X08e5:	ld hl,(eofxpr)	; načíst adresu za výrazem
X08e8:	pop bc		; obnovit kód priority do reg. B
	ld a,b
	cp 78h		; u číselných operátorů
			; (tedy ne u logických)
	call nc,X08cb	; provést typovou kontrolu na číslo
	ld a,(hl)		; načíst znak
	ld d,0		; a otestovat výskyt relačních
X08f2:	sub 0abh	; operátorů
	jp c,X090c
	cp 3
	jp nc,X090c
	cp 1		; zde se řeší relační operátory
	rla		; A = 001|010|100 pro >|=|<
	xor d		; přičemž bitové váhy jednotlivých
	cp d		; relačních operátorů lze sčítat
	ld d,a
			; při opakování operátoru
	jp c,err_09	; chybové hlášení 9h - Syntax err
	ld (fncadr),hl
	rst 0x10; přeskočit mezery a otestovat
	 jp X08f2	; další relační znak (kombinaci)
X090c:	ld a,d		; pokračujeme po event. identifikaci
	and a		; kombinace relačních operátorů
	jp nz,X0a24	; (s interními čísly 0..7 v reg. D)
	ld a,(hl)		; načíst znak
	ld (fncadr),hl	; uložit adresu operátoru
	sub 0a4h	; pro unární funkce
	ret c		; NOT, FNC a BIT konec
	cp 7		; a rovněž pro ostatní unární funkce
	ret nc
			; mohou následovat pouze operátory
			; +,-,*,/,^,AND,OR
	ld e,a		; tato sekvence řeší spojování
	ld a,(vartype)	; řetězcových proměnných (typ musí
	dec a		; být řetězec a musí se jednat
	or e		; o operaci sčítání - interní kód 0)
	ld a,e
	jp z,X0e1c
	rlca		; zde se řeší operátory
	add a,e		; +,-,*,/,^,AND,OR nad čísly
	ld e,a
	ld hl,X0096	; z tabulky obslužných rutin
	add hl,de		; operátorů načíst
	ld a,b		; prioritu posledního operátoru
	ld d,(hl)		; a prioritu nového operátoru
	cp d		; porovnat
	ret nc		; jestliže má "starší" operátor
			; větší prioritu, pak ten nový
			; nevyhodnocovat
			; v opačném případě (nový operátor
			; má prioritu vyšší):
	inc hl
	call X08cb	; typová kontrola na číslo
X0934:	push bc		; uschovat "starou" prioritu
	ld bc,X08e5	; připravit návrat do vyhodnocovače
	push bc		; výrazu
	ld b,e		; uschovat kód operátoru
	ld c,d		; a kód priority
	call pushfp	; aktuální hodnotu výrazu uložit
			; do zásobníku
	ld e,b		; obnovit kód operátoru
	ld d,c		; a kód priority
	ld c,(hl)		; v tabulce adres/priorit operátorů
	inc hl		; načíst adresu obslužné rutiny
	ld b,(hl)		; pro daný operátor
	inc hl
	push bc		; a připravit jej do zásobníku
	ld hl,(fncadr)	; obnovit začátek výrazu "nalevo"
			; od operátoru
	 jp X08d9	; a znovu se pokusit vyhodnotit
; ********************************
; Vyčíslení hodnoty dílčího výrazu
; ********************************
X094b:	xor a
	ld (vartype),a	; default číselná proměnná
	rst 0x10; přeskočit mezery a načíst znak
	jp z,err_09	; hlášení „Syntax err“ je-li konec řádku
	jp c,X11cc	; cifra => do FP akumulátoru načti číslo
	call isabcd	; test na písmeno
	jp nc,X09b9	; vyčísli proměnnou
	cp 0a4h	; je-li tím znakem unární + pak je ignoruj
	jp z,X094b
	cp '.'		; při nalezení desetinné tečky se postupuje
	jp z,X11cc	; tak, že se načte číslo (bez úvodní nuly)
	cp 0a5h	; při načtení unárního mínus vyčíslit výraz
	jp z,X09a8	; a otočit mu znaménko
	cp 22h		; uvozovky
	jp z,X0cf7
			; následují funkce, jimž se předává ukazatel
			; na následující znak v BASICovském zápisu
			; a tyto funkce si buď zjistí ukazatel
			; na pracovní proměnnou nebo mají svůj vlastní
			; postup, jak s argumentem naložit
	cp 0a2h	; funkce NOT
	jp z,X0a82			
	cp 9fh		; funkce FNC
	jp z,X0c6d
	cp 0d9h	; funkce STATUS
	jp z,X220a
	cp 0dfh	; funkce INKEY
	jp z,X1ee8
	cp 90h		; funkce BIT
	jp z,X1f05
	cp 0e5h	; funkce APEEK
	jp z,X163d
	cp 0e6h	; funkce ADR
	jp z,X2317
	cp 27h		; apostrof
	jp z,X1652
	cp 0e8h	; funkce HEX$
	jp z,f_hex
	sub 0aeh	; ostatní funkce, volané na rozdíl od těch
	jp nc,X09ca	; výše uvedených, s hodnotou jejich argumentu
			; (09a2h)
X09a2:	call X08d4	; takže vyčíslit hodnotu
	rst 0x08; a vynutit pravou ukončující závorku
	.db ')'		; (hodnota se při volání funkce předává
	ret		;  v FP akumulátoru)
; *******************
; funkce unární mínus
; *******************
			; (09a8h)
X09a8:	ld d,7dh	; s jeho relativní prioritou
	call X08d9	; vyčíslit následující výraz
	ld hl,(eofxpr)	; uložit adresu následujícího
	push hl		; operátoru
	call X10f0	; negace načtené hodnoty (vlastní
			; funkce unárního mínus)
X09b4:	call X08cb	; typová kontrola na číslo
	pop hl		; obnovit ukazatel na další operátor
	ret		; a konec
; **************************************************
; vyčíslovaný výraz začíná písmenem (názvu proměnné)
; **************************************************
			; (09b9h)
X09b9:	call varadr	; do DE načíst adresu proměnné
X09bc:	push hl
	ex de,hl		; pro operace s řetězci uložit do
	ld (fpaccum),hl	; FP akumulátoru odkaz na vlastní
			; text proměnné
	ld a,(vartype)	; pro operace s čísly uložit do
	and a		; FP akumulátoru hodnotu FP čísla,
	call z,X1105	; uloženého od adresy HL
	pop hl		; obnovit ukazatel do zdrojového
	ret		; textu programu v BASICu
; *****************************************
; volání funkcí s kódy AEh..C5h (SGN..MID$)
; *****************************************
			; (09cah)
X09ca:	ld b,0		; podle hodnoty reg. A vypočtu
	rlca		; pozici v tabulce skokových adres
	ld c,a		; BC = 2 x A
	push bc		; pozici v tabulce funkcí uschovat
	rst 0x10; pro všechny funkce kromě
	ld a,c		; LEFT$, RIGHT$ a MID$
	cp 29h
	jp c,X09eb	; jdu na samostatnou rutinu
; ******************************************************
; rozcestník funkcí, vracejících řetězec libovolné délky
; ******************************************************
	call X08d4	; načti parametr s vynucením levé
			; kulaté závorky
	rst 0x08; pak si vynutit
	.db ','		; oddělovací čárku
	call t_strg	; typová kontrola parametru
			; na typ řetězec
	ex de,hl		; ukazatel na argument (řetězec)
	ld hl,(fpaccum)	; uschovat do zásobníku "pod"
	ex (sp),hl		; pozici v tabulce skokových adres
	push hl		; (viz výše)
	ex de,hl
	rst 0x20; načíst 8-bitový parametr
	ex de,hl		; do HL ulož pozici v tabulce
	ex (sp),hl		; a do zásobníku adresu proměnné
	 jp X09f3
; *******************************************************
; rozcestník funkcí, vracejících FP číslo nebo jeden znak
; *******************************************************
			; (09ebh)
X09eb:	call X09a2	; načíst argument v závorce
	ex (sp),hl
	ld de,X09b4	; připravit typovou kontrolu
	push de		; na závěr (vyžadovat typ číslo)
; *******************************
; společná část pro volání funkcí
; *******************************
			; (09f3h)
X09f3:	ld bc,tb_fnc	; k začátku tabulky adres obslužných
	add hl,bc		; programů funkcí přičti pozici v HL
	ld c,(hl)
	inc hl
	ld h,(hl)		; a tam vyzvedni onu adresu,
	ld l,c
	jp (hl)		; na kterou se provede skok
; *********
; funkce OR
; *********
			; (09fch)
f_or:	.db 0f6h	; ori 0afh
; **********
; funkce AND
; **********
			; (09fdh)
f_and:	xor a
	push af	; uschovat typ AND/OR
	call X08cb	; načíst druhý! parametr
	call tstint	; kontrola hodnoty na rozsah
	pop af		; -32768..32767
	ex de,hl
	pop bc
	ex (sp),hl
	ex de,hl
	call fpbcde	; první parametr obnovit
	push af	; ze zásobníku,
	call tstint	; otestovat jej na rozsah
	pop af		; -32768..32767
	pop bc
	ld a,c
	ld hl,ac2fp	; připravit se na převod
	jp nz,X0a1f	; zde fyzické rozlišení AND/OR
	and e		; výpočet BC and DE => A:C
	ld c,a
	ld a,b
	and d
	jp (hl)		; převod A:C > FP akumulátor
X0a1f:	or e		; výpočet BC or DE => A:C
	ld c,a
	ld a,b
	or d
	jp (hl)		; převod A:C > FP akumulátor
; ***************************
; obsluha relačních operátorů
; ***************************
X0a24:	ld hl,X001e	; podstrčit fiktivní "tabulku"
			; s adresou obslužné rutiny
			; pro relační operátory
	ld a,(vartype)	; do reg. E umístit rozlišovací kód
	rra		; relačního operátoru a typu
	ld a,d
	rla		; bit 0 obsahuje typ, bity 3, 2 a 1
	ld e,a		; obsahují kód relačního operátoru
	ld d,64h	; prioritu relačního operátoru
	ld a,b		; (toho aktuálně nalezeného)
	cp d		; porovnat s poslední prioritou
	ret nc		; pokud nová priorita je menší
			; než ta předchozí, konec
	 jp X0934	; jinak vyčíslit dílčí výraz
			; za relačním operátorem
; *************************************
; obslužná rutina pro relační operátory
; (volací vektor je na adrese 001Eh)
; *************************************
			; (0a36h)
X0a36h:	ld a,c		; do CY připravit hodnotu datového
	and a		; typu
	rra
	pop bc		; vyzvednout poslední výsledek
	pop de		; ze zásobníku do B:C:D:E
	push af	; podle příznaku CY (0 = číslo)
	call X08cd	; typová kontrola číslo/řetězec
	ld hl,X0a78	; po vlastním porovnání se bude
	push hl		; volat zakončovací procedura
	jp z,X1142	; porovnat FP a B:C:D:E
; *****************
; porovnání řetězců
; *****************
			; (0a46h)
	xor a		; typ číslo
	ld (vartype),a	; bude výsledným typem operace
	push de		; 
	call X1523	; do HL načte adresu proměnné
			; napravo od relačního operátoru
	ld a,(hl)		; načíst délku pravého řetězce
	inc hl
	inc hl
	ld c,(hl)		; načíst adresu textu pravého
	inc hl		; řetězce
	ld b,(hl)
	pop de
	push bc		; uschovat adresu pravého řetězce
	push af	; uschovat délku pravého řetězce
	call X1527	; do HL načte adresu proměnné
			; nalevo od relačního operátoru
	call X1116	; od adresy HL načte
			; BC = adresu textu levého řetězce
			;  E = délku levého řetězce
	pop af		;  D = délka textu pravého řetězce
	ld d,a
	pop hl		; HL = adresa textu pravého řetězce
X0a60:	ld a,e		; při souběžném vyčerpání všech
	or d		; (shodných) znaků obou řetězců
	ret z		; se vrátí hodnota 0 jako "shoda"
	ld a,d		; pokud dojdou dříve znaky pravého
	sub 1		; řetězce, nastavím A = -1
	ret c		; (levý řetězec > pravý řetězec)
	xor a		; pokud dojdou dříve znaky levého
	cp e		; řetězce, nastavím A = +1
	inc a		; (levý řetězec < pravý řetězec)
	ret nc
			; při shodě jdu na další znak
	dec d		; počitadlo znaků pravého řetězce
	dec e		; počitadlo znaků levého řetězce
	ld a,(bc)		; aktuální znak levého řetězce
	cp (hl)		; porovnat s aktuálním znakem
	inc hl		; pravého řetězce a posunout se
	inc bc		; na další znaky
	jp z,X0a60	; při shodě testovat další znaky
	ccf		; při neshodě znaků vrátit hodnoty
	 jp X10d6	; CY = 0 => levý < pravý
			; CY = 1 => levý > pravý
; *********************
; dokončovací procedura
; *********************
			; (0a78h)
X0a78:	inc a		; typický bílý trpaslík, který
	adc a,a		; výsledek </=/> ve formě hodnot
	pop bc		; -1/0/+1 podle zadané podmínky
	and b		; (ta se obnoví v registru B)
	add a,0ffh	; převede na výslednou hodnotu
	sbc a,a		;  0 => NEPRAVDA
	 jp a2fp	; -1 => PRAVDA
; **************************************
; funkce NOT (vypočte jedničkový doplněk
; šestnáctibitového čísla se znaménkem)
; **************************************
			; (0a82h)
X0a82:	ld d,5ah	; relativní priorita operátoru NOT
	call X08d9	; vyčíslení argumentu
	call X08cb	; typová kontrola na typ číslo
	call tstint	; test na rozsah -32768..32767
	ld a,e
	cpl
	ld c,a
	ld a,d
	cpl		; určit jedničkový doplněk
	call ac2fp	; převést zpět na FP číslo
	pop bc		; změnit návratovou adresu do funkce
	 jp X08e5	; vyčíslení argumentu a formálně
			; ukončit výraz
; **************************************
; zvýšení dimenze proměnné v příkazu DIM
; **************************************
			; (0a99h)
X0a99:	dec hl		; 
	rst 0x10; je aktuální znak
	ret z		; znakem konce řádku? => pak návrat
	rst 0x08; vynutit oddělovací čárku
	.db ','
; **********************************************************
; příkaz DIM
; **********************************************************
; Tímto příkazem lze definovat i jednoduché proměnné (tedy
; ne pole) a v tom případě se netestuje jejich redefinice.
; Při redefinici jednoduché proměnné se nemění její hodnota.
; Naopak při pokusu o redefinici pole se vyvolá chybové
; hlášení Arr.alloc.
; **********************************************************
			; (0a9eh)
c_dim:	ld bc,X0a99	; připravit se na zvýšení dimenze
	push bc		; pole
	.db 0f6h	; ori 0afh s přeskočením "xra a"
			; uložení nenulové hodnoty do pro-
			; měnné "dimreq" vyvolá požadavek
			; na vytvoření proměnné (zde pole)
			; za příkazem DIM
; ****************************************************
; test názvu proměnné a vyčíslení ukazatele na ni
; (v případě, že proměnná neexistuje, tak se vytvoří)
; vstup:  HL - ukazatel do zdrojového kódu BASICu, kde
;              je očekáváno jméno proměnné
; výstup: DE - adresa proměnné
; ****************************************************
			; (0aa3h)
varadr:	xor a		; předpokládáme existenci proměnné
X0aa4:	ld (dimreq),a	; (nebudeme ji vytvářet)
	ld b,(hl)		; do B načíst 1. znak jména proměnné
X0aa8:	call isabcd	; a test na písmeno
	jp c,err_09	; pokud není, pak chyba Syntax err
	xor a		; předběžně nastavit neplatný 2.znak
	ld c,a		; jména proměnné
	ld (vartype),a	; a typ číslo
	rst 0x10; test dalšího znaku ze zdrojového
			; kódu BASICu
	jp c,X0abd	; skok při jednopísmenné proměnné
	call isabcd	; jinak důkladný test 2. písmene
			; názvu proměnné na znaky a cifry
	jp c,X0ac8	; skok při jednopísmenné proměnné
X0abd:	ld c,a		; v BC je nyní jméno proměnné
X0abe:	rst 0x10; (rozlišují se jen první dva znaky)
	jp c,X0abe
	call isabcd	; následovat může libovolný počet
	jp nc,X0abe	; písmen a cifer
X0ac8:	sub '$'		; test na znak $, určující řetězec
	jp nz,X0ad5
	inc a		; pokud je uveden, nastaví se typ
	ld (vartype),a	; řetězec
	rrca		; a MSB druhého bajtu se jménem
	add a,c		; proměnné se nastaví na 1
	ld c,a
	rst 0x10; posun na další znak ve zdrojovém
			; kódu BASICu
X0ad5:	ld a,(indxen)	; u konstrukcí, kde chci zakázat
	dec a		; použití indexované proměnné,
	jp p,X0ae2	; přeskočím test na levou závorku
			; (tím vyvolám Syntax err při jejím
			;  použití)
	ld a,(hl)		; jinak ten test na levou závorku
	sub '('		; provedu
	jp z,X0b43	; a v případě indexu skok..
X0ae2:	xor a		; závorka se nekonala, zruším zákaz
	ld (indxen),a	; indexovaných proměnných
	push hl
	ld hl,(arrbase)	; DE = konec proměnných
	ex de,hl		; HL = začátek proměnných
	ld hl,(varbase)	; (jednoduché proměnné bez polí)
; **********************************************
; smyčka pro vyhledání proměnné podle jména v BC
; **********************************************
			; (0AEEh)
X0aee:	rst 0x18; prošel jsem všechny proměnné
			; bez nalezení té pravé?
	jp z,X0b05	; pak ji musíme vytvořit
	ld a,c		; test druhého znaku jména proměnné
	sub (hl)
	inc hl
	jp nz,X0afa	; při neshodě běž na další proměnnou
	ld a,b		; test prvního znaku jména proměnné
	sub (hl)
X0afa:	inc hl
	jp z,X0b35	; při shodě běž na zakončení
	inc hl
	inc hl		; jinak přeskočit následující
	inc hl		; 4 bajty, které nesou vlastní
	inc hl		; hodnotu proměnné (nebo odkaz)
	 jp X0aee	; a test další proměnné
; *************************************
; vytvoření nové proměnné s názvem v BC
; *************************************
X0b05:	pop hl		; obnovit ukazatel zdrojového kódu
	ex (sp),hl
	push de		; pokud je dotaz na adresu proměnné
	ld de,X09bc	; volán z vyčíslení výrazu, pak se
	rst 0x18; proměnná nevytváří a do FP akumu-
	pop de		; látoru se uloží nula (odkaz na
	jp z,X0b38	; nulový řetězec v případě vyčíslení
	ex (sp),hl		; řetězcového výrazu)
	push hl
	push bc
	ld bc,6
	ld hl,(arrend)	
	push hl
	add hl,bc
	pop bc
	push hl		; pokus o alokaci 6 byte pro novou
	call X00d0	; proměnnou s posunem bloku polí
	pop hl
	ld (arrend),hl	; konec všech proměnných (i polí)
	ld h,b
	ld l,c
	ld (arrbase),hl	; konec jednoduchých proměnných
X0b29:	dec hl		; a nyní od konce zapíšu do nově
	ld (hl),0		; vzniklé proměnné šest nul
	rst 0x18; (DE ukazuje na adresu proměnné)
	jp nz,X0b29
	pop de		; obnovím jméno proměnné z BC
	ld (hl),e		; a uložím je na pozici prvních
	inc hl		; dvou bajtů proměnné
	ld (hl),d
	inc hl
; ***********************************************
; společné zakončení výše uvedené rodiny procedur
; ***********************************************
X0b35:	ex de,hl		; do DE uložit adresu proměnné+2
	pop hl		; a obnovit obsah HL
	ret
X0b38:	ld (fpaccum+3),a	; ve specifických případech se
	ld hl,nulstrg	; proměnná nevytvoří a nahradí
	ld (fpaccum),hl	; se nulovým výrazem (viz výše)
	pop hl
	ret
; **************************************************
; vyčíslení ukazatele na pole
; postupně načítá argumenty, oddělené čárkou a zvedá
; dimenzi pole (hodnoty indexů ukládá do zásobníku)
; **************************************************
			; (0B43h)
X0b43:	push hl		; beze změny hodnoty HL se uloží
	ld hl,(dimreq)	; do zásobníku obsah adresy dimreq
	ex (sp),hl		; (nenulová hodnota znamená požada-
			; vek na vytvoření nové proměnné)
	ld d,a		; vynuluje se počitadlo rozměrů pole
X0b49:	push de		; uschovat počitadlo rozměrů
	push bc		; uschovat jméno proměnné
	call X054c	; přečíst hodnotu indexu v rozsahu
			; 0..31767 
	pop bc		; obnovit jméno proměnné
	pop af		; a aktuální počet rozměrů
	ex de,hl		; pod poslední položku zásobníku se
	ex (sp),hl		; uloží načtená 2B hodnota, určující
	push hl		; počet položek v aktuálním rozměru
	ex de,hl		; pole
	inc a		; zvednout dimenzi pole o jednu
	ld d,a		; a uložit do registru D
	ld a,(hl)		; Je dalším znakem ve zdrojovém kódu
	cp ','		; čárka (oddělující další index)?
	jp z,X0b49	; pokud ano, "přidáme" rozměr
	rst 0x08; vynutit pravou závorku
	.db ')'
	ld (eofxpr),hl	; uložit ukazatel do zdrojového kódu
	pop hl		; a obnovit hodnotu dimreq, která se
	ld (dimreq),hl	; díky rekurzivnímu volnání mohla
			; změnit
	ld e,0		; pozůstatek MS BASICu (nefunkční)
	push de		; uschovat počet načtených dimenzí
	ld hl,(arrbase)
	.db 3eh		; přeskočení následující instrukce
			; DAD D (falešný kód MVI A,19h)
X0b6c:	add hl,de		; přeskočím na další pole
	ex de,hl
	ld hl,(arrend)	; do DE načíst adresu konce polí
	ex de,hl		; a porovnat s aktuální adresou
	rst 0x18; prohledal jsem všechna pole?
	jp z,X0b98	; pokud ano, (a nic jsem nenašel)
			; pak vytvoř nové pole
	ld a,(hl)		; druhý znak jména aktuálního pole
	cp c		; porovnám s druhým znakem jména
	inc hl		; hledaného pole
	jp nz,X0b7e	; při neshodě ještě načtu adresu
			; dalšího pole a test dalšího pole
	ld a,(hl)		; první znak jména aktuálního pole
	cp b		; porovnám s prvním znakem jména
X0b7e:	inc hl		; hledaného pole
	ld e,(hl)
	inc hl		; do DE načtu posun adresy dalšího
	ld d,(hl)		; pole oproti tomu aktuálnímu
	inc hl
	jp nz,X0b6c	; zpožděný test shody jmén hledaného
			; a aktuálního pole, při neshodě jdu
			; na test dalšího pole
	ld (arradr),hl	; aktuální adresa v HL ukazuje "za"
			; hlavičku nalezeného pole
	ld a,(dimreq)	; pokud jsem nalezené pole chtěl
	and a		; znovu vytvořit (dimreq <> 0)
	jp nz,err_02	; vyvolat chybu 02h - Arr.alloc.
	pop af		; obnovit počet načtených dimenzí
	sub (hl)		; a porovnat s počtem dimenzí pole
	jp z,X0bf4	; při shodě běž vyhledat požadovaný
			; prvek pole
X0b95:	ld e,1		; chyba 01h - Subscr.rng
	rst 0x28; (rozdílná dimenze pole)
; *********************
; vytvoření nového pole
; *********************
X0b98:	ld de,4		; pro nové pole se budou později
			; alokovat 4x 2 bajty
	pop af		; do A obnoví počet dimenzí
			; do FLAGS načte samé nuly
			; ..mvi e,0 výše..
	jp z,X0569	; chyba 03h - Fnc.param.
			; (do FLAGS obnoví samé nuly, skok
			;  se  nikdy neprovede - pozůstatek
			;  MS BASICu)
	ld (hl),c		; do prvních dvou bajtů hlavičky
	inc hl		; nově vytvářeného pole uložit jméno
	ld (hl),b		; pole (ještě se pro něj nealokovalo
	inc hl		; místo ale předpokládá se, že bude)
	ld c,a		; počet dimenzí pole do C
	call X00df	; vlastní alokace paměti pro pole
	inc hl		; teď přeskočit dva bajty, kde
	inc hl		; později (až to budu vědět) uložím
			; velikost tohoto pole
	ld (fncadr),hl	; uložit si ukazatel
	ld (hl),c		; zapsat počet dimenzí do hlavičky
	inc hl		; pole a přejít na další bajt
	ld a,(dimreq)	; pokud jsem pole nedefinoval
	rla		; (bylo implicitně vytvořeno
	ld a,c		; operací s ním)
X0bb3:	ld bc,0bh	; pak zvolit výchozí počet prvků 11
	jp nc,X0bbb	; (počítá se od 0 => indexy 0..10)
			; při explicitní definici pole
	pop bc		; vybrat ze zásobníku poslední index
	inc bc		; zvýšit rozsah indexu o prvek nula
X0bbb:	ld (hl),c		; do hlavičky pole zapsat hodnotu
	inc hl		; maximálního rozsahu posledního
	ld (hl),b		; indexu
	inc hl
	push af	; v DE vstupuje velikost (v bajtech)
	push hl		; o řád nižší struktury pole
	call hl_bxd	; vynásobit počtem prvků (v BC)
	ex de,hl		; aktuálního indexu
	pop hl		; a opět uložit do DE
	pop af		; (v DE se kumuluje velikost paměti,
			; kterou bude celé pole zabírat)
	dec a		; jdeme na další (vyšší) index
	jp nz,X0bb3	; pokud tedy ještě existuje
	push af	; CY = požadavek na vytvoření pole
	ld b,d		; zálohovat velikost datové oblasti
	ld c,e		; pole
	ex de,hl
	add hl,de		; HL = koncová adresa celého pole
	jp c,X0b95	; test na přetečení adresy >FFFFh
	call X00e8	; test volné paměti
	ld (arrend),hl	; uložit nový konec polí (posunuto
			; o délku nového pole)
X0bd9:	dec hl		; celou datovou oblast nově vytvo-
	ld (hl),0		; řeného pole vyplnit nulami
	rst 0x18
	jp nz,X0bd9
	inc bc		; zvětšit velikost pole o jeden bajt
			; (bajt s údajem o počtu dimenzí)
	ld d,a
	ld hl,(fncadr)
	ld e,(hl)		; DE = počet dimenzí pole
	ex de,hl		; DE = celková velikost pole
	add hl,hl		; (2 bajty na jednu dimenzi +
	add hl,bc		;  velikost datové oblasti)
	ex de,hl
	dec hl		; ukazatel vrátit na začátek
	dec hl		; datové struktury založeného pole
	ld (hl),e
	inc hl		; a zapsat do dvou vynechaných bajtů
	ld (hl),d		; celkovou velikost pole
	inc hl
	pop af		; pokud jsem pole chtěl jen založit,
	jp c,X0c16	; tak končím
			; jinak v HL předám ukazatel na
			; počet dimenzí vytvořeného pole
; *****************************
; vyhledá požadovaný prvek pole
; *****************************
X0bf4:	ld b,a		; BC = 0000h (začínám sčítat prvky)
	ld c,a
	ld a,(hl)		; A = počet dimenzí pole
	inc hl
	.db 16h		; "falešná" instrukce mvi d,0e1h
			; pro odstínění POP H
X0bf9:	pop hl		; počínaje druhým indexem obnovím
			; ukazatel do struktury pole
			; HL "skáče" po začátcích dimenzí
	ld e,(hl)		; do DE načtu maximální povolený
	inc hl		; index pro danou dimenzi
	ld d,(hl)
	inc hl
	ex (sp),hl		; uložím ukazatel na začátek další
			; dimenze pole/do HL načtu další
			; zadaný index
	push af	; počitadlo dimenzí pole
	rst 0x18; překročil jsem povolený index?
	jp nc,X0b95	; pak chyba 01h - Subscr.rng
	push hl		; k HL přičtu počet prvků v nižší
	call hl_bxd	; dimenzi (ta vstupuje v BC)
	pop de
	add hl,de
	pop af		; jdu na další index
	dec a
	ld b,h		; počet prvků všech dimenzí včetně
	ld c,l		; té poslední uložím do BC
	jp nz,X0bf9	; mám v zásobníku další index?
	add hl,hl		; každý prvek pole zabírá 4 bajty,
	add hl,hl		; proto počet prvků x 4
	pop bc
	add hl,bc		; přičtu začátek datové oblasti
	ex de,hl		; a v DE vrátím ukazatel na vybraný
			; prvek pole
X0c16:	ld hl,(eofxpr)	; obnovit ukazatel na zdrojový text
	ret		; programu v BASICu
; **********
; funkce FRE
; **********
			; (0c1ah)
f_fre:	ld hl,(arrend)	; funkce rozlišuje prostor
	ex de,hl		; pro číselné a řetězcové proměnné
	ld hl,0
	add hl,sp		; uvedením libovolné formální pro-
	ld a,(vartype)	; měnné daného typu jako parametru
	and a		; se určí velikost dostupné paměti
	jp z,sub_de	; => pro číselné proměnné a program
			; (prostor od konce posledního pole
			;  až po zásobník)
	call X1523	; => pro řetězcové proměnné ???
X0c2c:	call X0d75
	ld hl,(strlim)
	ex de,hl
	ld hl,(strlast)
; **************************************
; do FP akumulátoru uloží rozdíl HL - DE
; **************************************
			; (0c36h)
sub_de:	ld a,l		; vypočte rozdíl
	sub e
	ld c,a		; A:C = HL - DE
	ld a,h
	sbc a,d
; *************************************************
; převod 16-bitového čísla se znaménkem z A:C na FP
; *************************************************
			; (0c3bh)
ac2fp:	ld b,c
; *************************************************
; převod 16-bitového čísla se znaménkem z A:B na FP
; *************************************************
			; (0c3ch)
ab2fp:	ld d,b
	ld e,0
	ld hl,vartype	; přepnout na číselné proměnné
	ld (hl),e
	ld b,90h	; exponent 2^16 pro 16-bit integer
	 jp badefp
; **********
; funkce POS
; **********
			; (0c48h)
f_pos:	ld a,(colpos)	; pouze načtu proměnnou ukazatele
			; tiskového sloupce, která je
			; zřízena jen za tímto účelem
; ***********************************
; převod hodnoty z reg. A na FP číslo
; ***********************************
			; (0c4bh)
X0c4b:	ld b,a		; výsledek v akumulátoru postupně
	xor a		; převedu na FP číslo
	 jp ab2fp
; **********
; příkaz DEF
; **********
			; (0c50h)
c_def:	call X0cb3	; vynutit klíčové slovo FNC a
			; zaregistrovat funkci jako novou
			; proměnnou
	call prgtst	; test na programový režim
	ld bc,c_data	; po definici uživatelské funkce
	push bc		; se samotný definiční výraz bude
			; ignorovat jako například seznam
			; položek za příkazem DATA
	push de		; v DE je adresa prvního bajtu
			; ze čtyř, určujících obsah nově
			; vytvořené proměnné
			; (rozuměj Uživatelské funkce)
	rst 0x08; vynutit si
	.db '('		; levou závorku
	call varadr	; vynutit si argument funkce
	call X08cb	; číselného typu (jeho adresa v DE)
	rst 0x08; vynutit si
	.db ')'		; pravou závorku
	rst 0x08; vynutit si
	.db 0ach	; kód znaku '='
	ld b,h		; ukazatel na zápis definiční funkce
	ld c,l		; uložit do BC
	ex (sp),hl		; do HL obnovit adresu na obsah
			; proměnné (=funkce)
	 jp X0ca1	; nadefinovat fiktivní "proměnnou",
			; zastupující funkci a ignorovat
			; samotný zápis funkce
; **********
; funkce FNC
; **********
			; (0c6dh)
X0c6d:	call X0cb3	; formálně vynutit klíčové slovo FNC
	push de		; a do DE uložit adresu na fiktivní
			; proměnnou, kde je
			; uložen odkaz na definiční funkci
	call X09a2	; vyčíslit argument
			; uživatelské funkce,který
	call X08cb	; musí být číselného typu
	ex (sp),hl		; uschovat ukazatel na zdrojový kód
			; programu BASICu a do HL načíst
			; adresu fiktivní proměnné
	ld e,(hl)
	inc hl		; do DE načtu adresu definiční
	ld d,(hl)		; funkce v zápise programu BASICu
	inc hl
	ld a,(hl)		; do HL uložím adresu proměnné,
	inc hl		; která slouží jako argument funkce
	ld h,(hl)
	ld l,a
	ld c,(hl)		; do zásobníku uložím původní
	inc hl		; hodnotu proměnné argumentu
	ld b,(hl)		; a tuto proměnnou použiju
	inc hl		; pro výčíslení hodnoty uživatelské
	push bc		; funkce (poté obnovím tuto původní
	ld c,(hl)		; hodnotu)
	inc hl
	ld b,(hl)
	push bc
	dec hl		; do HL opět nastavím adresu
	dec hl		; proměnné argumentu
	dec hl
	push hl
			; DE = adresa zápisu definice fce
	rst 0x18; tento kód nedává smysl, DE ukazuje
	push de		; vždy do zápisu programu a HL někde
	jp z,X0569	; na proměnnou (tento kousek není
			; obsažen v originálním MS BASICu
			; a autor PMD verze chtěl asi hlídat
			; rekurzi, protože při té opravdu
			; systém chybně zaplní celou paměť)
			; v originále je pouze PUSH D
	call X111f	; obsah FP akumulátoru uloží
			; postupně od adresy HL
	pop hl		; obnovit ukazatel na definci funkce
	call numpar	; výpočet výrazu do FP akumulátoru
	dec hl
	rst 0x10; test na cifru na adrese HL
	jp nz,err_09	; chyba 09h - Syntax err
	pop hl		; obnovit adresu proměnné argumentu
	pop de		; a její obsah
	pop bc		; vrátit na původní hodnotu
; ************************************************
; nadefinovat fiktivní proměnnou, jejíž konstrukce 
; poslouží k definici uživatelské funkce
; ************************************************
			; (0ca1h)
X0ca1:	ld (hl),c		; první dva bajty za jménem funkce
	inc hl		; obsahují odkaz do programu BASICu,
	ld (hl),b		; kde začíná definice funkce
			; za znakem rovnítko
	 jp X0cf0	; do dalších dvou bajtů uložit
			; adresu proměnné, která slouží jako
			; argument funkce
; ************************
; test na programový režim
; ************************
			; (0ca7h)
prgtst:	push hl		; pokud je číslo aktuálního
	ld hl,(crntln)	; prováděného řádku rovno 65535
	inc hl		; (FFFFh), což znamená, že program
	ld a,h		; "nejede" (je v dialogovém režimu)
	or l
	pop hl
	ret nz		; pak se vyvolá chyba 04..
; **********************************
; chybové hlášení 04h - "Only in pg"
; **********************************
			; (0cb0h)
X0cb0:	ld e,4		; vyvolání chyby 04h - Only in pg
	rst 0x28; přes standardní mechanismus
; **************************************************
; zaregistrování jména funkce a kontrola jejího typu
; **************************************************
			; (0cb3h)
X0cb3:	rst 0x08; po příkazu DEF může následovat
	.db 9fh		; jedině klíčové slovo FNC
	ld a,80h	; zakázat použití indexu v názvu
	ld (indxen),a	; definované funkce (sami budeme
			; používat závorky pro argument)
	or (hl)		; u jména funkce vnutím druhému
	ld b,a		; znaku nejvyšší bit = 1
	call X0aa8	; funkce se zaregistruje jako nová
			; proměnná a formálně se vyčíslí
	 jp X08cb	; a výsledek musí být typ číslo..
; ********
; fce STR$
; ********
			; (0cc2h)
f_str:	call X08cb	; typová kontrola argumentu na číslo
	call X1276	; tisk FP čísla z FP akumulátoru do
			; vyhrazeného 12-znakového buferu
			; (do HL nastaví adresu zač. buferu)
; ********************************************
; string od adresy HL přiřadím cílové proměnné
; ********************************************
X0cc8:	call X0cf6	; výpočet délky řetězce a dosazení
			; odkazu na něj do pomocné proměnné
			; laststg
	call X1523	; ???
	ld bc,X157a	; ???
	push bc
; ********************************************************
; Vytvoří prac.kopii řetězcové proměnné včetně kopie textu
; ********************************************************
; podle hlavičky proměnné na adrese HL nadefinuje hlavičku
; pomocné proměnné na adrese BE65 (tmpvar) a text proměnné
; nakopíruje do nově alokovaného prostoru
; ********************************************************
X0cd2:	ld a,(hl)		; načíst 0. bajt hlavičky řetězcové
	inc hl		; proměnné, udávající její délku
	inc hl
	push hl
	call txaloc	; alokace volné paměti pro text
	pop hl
	ld c,(hl)		; načíst ukazatel na obsah
	inc hl		; řetězcové proměnné
	ld b,(hl)
	call X0cea	; inicializace hlavičky pracovní
	push hl		; proměnné
	ld l,a		; a nyní samotné kopírování obsahu
	call strcpy	; řetězce do pomocné proměnné
	pop de
	ret
; ********************************************
; vytvoření prázdné řetězcové proměnné délky A
; ********************************************
			; (0ce7h)
X0ce7:	call txaloc	; alokovat paměť pro text proměnné
; ************************************************
; inicializace hlavičky pomocné řetězcové proměnné
; A = délka řetězce, DE = adresa obsahu (řetězce)
; ************************************************
X0cea:	ld hl,tmpvar	; adresa hlavičky pomocné proměnné
	push hl
	ld (hl),a		; zapsat délku vlastního řetězce
	inc hl
X0cf0:	inc hl
	ld (hl),e		; zapsat odkaz na vlastní řetězec
	inc hl
	ld (hl),d
	pop hl
	ret		; ???
; **************************************
; vyčíslení řetězce s predekrementací HL
; **************************************
X0cf6:	dec hl
; **********************************************
; adresu a délku řetězce uloženého od adresy HL
; dosadí do hlavičky pomocné proměnné a následně
; tuto hlavičku nakopíruju na adresu, uloženou
; v proměnné laststg
; **********************************************
			; (0cf7h)
X0cf7:	ld b,22h	; řetězec může končit uvozkovkami
	ld d,b		; nebo alternativním znakem
X0cfa:	push hl
	ld c,0ffh	; inicializovat počitadlo délky
X0cfd:	inc hl		; řetězce
	ld a,(hl)		; načíst znak řetězce,
	inc c		; inkrementovat počitadlo jeho délky
	and a
	jp z,X0d0c	; pokud nenastane konec řádku,
	cp d
	jp z,X0d0c	; nepřijde znak dvojtečka (příkazy
	cp b		; INPUT/DATA/REM)
	jp nz,X0cfd	; nebo uvozovky, pokračovat
			; ve sčítání délky řetězce
X0d0c:	cp 22h		; pokud byl string ukončen
	call z,X04d1	;  uvozovkami, přeskočit je
	ex (sp),hl
	inc hl
	ex de,hl		; DE = adresa 1. znaku řetězce
	ld a,c		;  A = vypočtené délka
	call X0cea	; inicializace hlavičky pomocné
			; proměnné (odkaz na text je nasmě-
			; rován na zdrojový text)
X0d18:	ld de,tmpvar
	ld hl,(laststg)	; ukazatel na předchozí proměnnou
	ld (fpaccum),hl	; uložit do FP akumulátoru
	ld a,1		; nastavit typ "řetězcová proměnná"
	ld (vartype),a
	call X1122	; zkompletovanou hlavičku řetězcové
			; proměnné uložím do cílové proměnné
			; jejíž adresa je v laststg
	rst 0x18; došlo k rekurzivnímu přepisu?
	ld (laststg),hl	; hodnotu zvednutou o 4 uložím zpět
	pop hl
	ld a,(hl)		; načtu znak za výrazem
	ret nz
	ld e,10h	; chyba 10h - Str.algrth
	rst 0x28
; ************************************
; tisk textu z adresy HL do editačního
; buferu s preinkrementací registru HL
; ************************************
			; (0d33h)
X0d33:	inc hl
; **********************************************
; tisk textu z adresy HL do editačního buferu
; tento text bude předtištěn v dialogovém řádku
; po přechodu do stavu, kdy BASIC čeká na příkaz
; **********************************************
tx2edi:	call X0cf6	; (0d34h)
X0d37:	call X1523
	call X1116	; (HL) > B:C:D:E
	inc e
X0d3e:	dec e		; E = počet znaků k tisku
	ret z
	ld a,(bc)		; BC = ukazatel na text k tisku
	call X03dd
	cp 0dh		; přišel znak CR?
	call z,X072d
	inc bc		; další znak
	 jp X0d3e
; ******************************
; alokace paměti pro řetězec,
; jehož délka je dodána v reg. A
; přidělenou adresu vrací v DE
; ******************************
			; (0d4dh)
txaloc:	and a		; test délky řetězce
	.db 0eh		; mvi c,0f1h - odmaskování POP PSW
X0d4f:	pop af
	push af
	ld hl,(strlim)	; Test, zda výraz (strlast-A)
	ex de,hl		; podkročí strlim (mez pro ukládání
	ld hl,(strlast)	; textů řetezcových proměnných).
	cpl
	ld c,a
	ld b,0ffh
	add hl,bc
	inc hl
	rst 0x18; Pokud se tam nový řetězec nevejde,
	jp c,X0d69	; běž dále..
	ld (strlast),hl	; Pokud se tam nový řetězec vejde,
	inc hl		; zablokuj pro něj místo a vrať
	ex de,hl		; ukazatel na toto volné místo
	pop af		; v reg. DE.
	ret
; **********************************
; uvolnění oblasti pro texty řetězců
; **********************************
X0d69:	pop af		; obnovit požadovanou délku řetězce
			; (1. průchod) nebo příznak Z
			; (při ostatních průchodech)
	ld e,0fh	; a vyvolat chybu 0fh - No str.spc
	jp z,X0108	; při jeho nulové délce (1. průchod)
			; nebo při nulové uvolněné paměti
			; (ostatní průchody)
	cp a		; nahodit příznak Z=1
	push af
	ld bc,X0d4f	; připravit se na nový pokus
	push bc		; o alokaci paměti
X0d75:	ld hl,(stbase)	; 9F00h
X0d78:	ld (strlast),hl
	ld hl,0		; do zásobníku uložit textovou
	push hl		; proměnnou, obsahující mimo jiné
	ld hl,(strlim)	; 
	push hl		; ukazatel na text proměnné
	ld hl,tmpstrg	; HL = BE59h
X0d86:	ex de,hl
	ld hl,(laststg)	; DE = poslední řetězec
	ex de,hl
	rst 0x18; ???
	ld bc,X0d86
	jp nz,X0dd2
	ld hl,(varbase)
X0d95:	ex de,hl		; nyní budu procházet jednoduché
	ld hl,(arrbase)	; proměnné s ukazatelem v HL
	ex de,hl		; až po začátek polí (ARRBASE)
	rst 0x18; prohledal jsem všechny proměnné?
	jp z,X0da9	; ano => skok dál
	ld a,(hl)		; jinak načíst první znak jména
	inc hl		; proměnné
	inc hl		; a do příznaku S nastavit typ
	and a		; proměnné (S = 1 => řetězcová)
	call X0dd5
	 jp X0d95	; jdu na další proměnnou
; ***********
; volání 0da9
X0da8:	pop bc		; ???
X0da9:	ex de,hl
	ld hl,(arrend)
	ex de,hl
	rst 0x18
	jp z,X0df7
	call X1116
	ld a,e
	push hl
	add hl,bc
	and a
	jp p,X0da8
	ld (fncadr),hl
	pop hl
	ld c,(hl)
	ld b,0
	add hl,bc
	add hl,bc
	inc hl
X0dc6:	ex de,hl
	ld hl,(fncadr)
	ex de,hl
	rst 0x18
	jp z,X0da9
	ld bc,X0dc6
X0dd2:	push bc
	or 80h
; *****************************************************
; u řetězcové proměnné nenulové délky, která již byla
; přemístěna do uklizené oblasti změní v zásobníku
; poslední dvě položky na adresu následující proměnné
; a ukazatel na související text této proměnné
; *****************************************************
			; (0dd5h)
X0dd5:	ld a,(hl)		; A = délka textu řetězcové proměnné
	inc hl
	inc hl
	ld e,(hl)		; DE = adresa textu
	inc hl
	ld d,(hl)
	inc hl
	ret p		; je-li to číselná proměnná, vrať se
	and a		; je-li délka řetězce
	ret z		; nulová, pak taky návrat
	ld b,h		; do BC uschovat adresu proměnné
	ld c,l
	ld hl,(strlast)
	rst 0x18; leží text řetězce výše než ukazuje
	ld h,b		; hodnota HL (STRLAST)?
	ld l,c
	ret c		; pak konec, taky nic neřešíme
	pop hl		; leží text řetězce v oblasti
	ex (sp),hl		; programu (řetězcová konstanta)?
	rst 0x18
	ex (sp),hl
	push hl
	ld h,b
	ld l,c
	ret nc		; pak s proměnnou nic nedělej, konec
	pop bc		; ??? jinak uschovat návratovou adresu
	pop af
	pop af		; jinak v zásobníku změň poslední
	push hl		; dvě položky na adresu další
	push de		; proměnné a její ukazatel na text
	push bc		; obnovit návratovou adresu
	ret		; a konec
; **********************
; opět stringy
			; (0df7h)
X0df7:	pop de		; ???
	pop hl
	ld a,l
	or h
	ret z
	dec hl		; BC = 
	ld b,(hl)
	dec hl
	ld c,(hl)
	push hl
	dec hl
	dec hl
	ld l,(hl)
	ld h,0
	add hl,bc
	ld d,b
	ld e,c
	dec hl
	ld b,h
	ld c,l
	ld hl,(strlast)
	call X00d3	; kopíruje (DE..BC) => (HL)
	pop hl
	ld (hl),c
	inc hl
	ld (hl),b
	ld l,c
	ld h,b
	dec hl
	 jp X0d78
; ************************************
; operace + nad řetězcovými proměnnými
; ************************************
			; (0e1ch)
X0e1c:	push bc
	push hl
	ld hl,(fpaccum)	; uschovat odkaz na první řetězec
	ex (sp),hl		; do zásobníku
	call X094b	; načíst odkaz na druhý řetězec
	ex (sp),hl		; uschovat druhý/obnovit první
	call t_strg	; typová kontrola na řetězec
	ld a,(hl)		; délka prvního řetězce
	push hl
	ld hl,(fpaccum)
	push hl
	add a,(hl)		; plus délka druhého řetězce
	ld e,0eh	; dají při délce větší než 255 znaků
	jp c,X0108	; chybu 0Eh - Strng long
	call X0ce7	; založit 4B hlavičku proměnné
			; na adrese BE65 s platnou délkou
			; a odkazem na prázdné alokované
			; místo pro nový řetězec
	pop de		; obnovit odkaz na druhou proměnnou
	call X1527	; a z něj ukazatel na vlastní text
	ex (sp),hl		; uložit ukazatel na 2. text
			; do zásobníku
	call X1526	; obnovený odkaz na 1. proměnnou
	push hl		; přetvořím na ukazatel na 1. text
			; a rovněž uložím do zásobníku
	ld hl,(tmpvar+2)	; z pomocné proměnné načtu adresu
	ex de,hl		; alokovaného místa pro výsledek
	call X150d	; a zkopíruji tam první řetězec
	call X150d	; a druhý řetězec
	ld hl,X08e8	; budu se vracet do obecné vyhodno-
	ex (sp),hl		; covací smyčky, ovšem až po
	push hl
	 jp X0d18	; zkopírování pomocné proměnné
			; do bloku proměnných
; ***********
; příkaz POKE
; ***********
			; (0e53h)
c_poke:	call numpar	; do FP aukulátoru vyčíslit adresu
	call tstint	; a povolit jen rozsah -32768..32767
	push de
	rst 0x08; vynutit oddělovací čárku
	.db ','
X0e5c:	rst 0x20; načte SHORT INTEGER
	pop de
	ld (de),a		; uložit načtený bajt
	dec hl
	rst 0x10
	cp ','		; následuje čárka?
	ret nz
	inc de		; pokud ano, inkrementace adresy pro zápis
	push de
	rst 0x10; přeskočit oddělovací čárku
	 jp X0e5c	; a zapsat do paměti další bajt..
; ************
; příkaz APOKE
; ************
			; (0e6ah)
c_apok:	call numpar	; do FP aukulátoru vyčíslit adresu
	call tstint	; a povolit jen rozsah -32768..32767
	push de		; adresu zápisu schovat do zásobníku
	rst 0x08; vynutit oddělovací čárku
	.db ','
	.db 3eh		; mvi a,0d7h
X0e74:	rst 0x10; přeskočit mezery
	call numpar	; načíst do FP číslo
	call tstint	; a povolit jen rozsah -32768..32767
	ex (sp),hl
	ld (hl),e		; obnovit ze zásobníku adresu pro
	inc hl		; zápis a sekvenčně zapsat načtený
	ld (hl),d		; 16-bitový parametr (little endian)
	inc hl
	ex (sp),hl		; adresu pro zápis znovu uložit
	dec hl
	rst 0x10; následuje po parametru čárka?
	cp ','
	jp z,X0e74	; pokud ano, zpracovat další parametr
	pop de		; víceméně zrušit adresu pro zápis
	ret		; a konec
; *************************************
; připočte hodnotu 0,5 k FP akumulátoru
; *************************************
			; (0e8ah)
X0e8a:	ld hl,X1808	; konstanta 0,5
; ********************************************
; připočte konstantu z paměti k FP akumulátoru
; ********************************************
			; (0e8dh)
X0e8d:	call X1116	; načíst B:C:D:E z adresy HL
	 jp X0e9c
; ***********************************************
; do FP akumulátoru vypočte rozdíl FP čísla
; uloženého na adrese HL a čísla v FP akumulátoru
; ***********************************************
			; (0e93h)
X0e93:	call X1116	; načíst B:C:D:E z adresy HL
	.db 21h		; lxi h,..
; ********************************
; obslužná procedura operátoru "-"
; ********************************
			; (0e97h)
X0e97:	pop bc		; ze zásobníku obnovit
	pop de		; FP číslo do B:C:D:E
; ****************************************
; FP akumulátor := B:C:D:E - FP akumulátor
; ****************************************
			; (0e99h)
X0e99:	call X10f0	; otočení znaménka u čísla
			; v FP akumulátoru
; ****************************************
; FP akumulátor := B:C:D:E + FP akumulátor
; ****************************************
			; (0e9ch)
X0e9c:	ld a,b		; pokud je nulové FP číslo
	and a		; v B:C:D:E, pak se obsah
	ret z		; FP akumulátoru nemění
	ld a,(fpaccum+3)	; pokud je nulové číslo v FP
	and a		; akumulátoru, pak zkopírovat
	jp z,fpbcde	; B:C:D:E do FP akumulátoru
	sub b		; výpočet rozdílu exponentů
	jp nc,X0eb6	; obou FP čísel
	cpl
	inc a		; (pokud je rozdíl záporný,
	ex de,hl		; prohodí se obě čísla, aby
	call pushfp	; tento rozdíl byl kladný,
	ex de,hl		; tj. aby exponent čísla
	call fpbcde	; v FP akumulátoru byl větší)
	pop bc
	pop de
X0eb6:	cp 25		; pokud je číslo B:C:D:E menší
	ret nc		; o 25 a více dvojkových řádů,
			; pak se na součtu neprojeví
			; (rozlišení mantisy je totiž
			; ca 24 bitů = dvojkových řádů)
	push af	; převést mantisy obou čísel
	call X112d	; do interního kódu MS BASIC
	ld h,a		; a do H uschovat kód 80h při shodě
	pop af		; znamének (jinak 00h)
	call manrgt	; mantisu FP čísla v C:D:E:B
	or h		; posunout doprava o tolik bitů,
	ld hl,fpaccum	; kolik činí rozdíl exponentů
			; (právě jsem obě čísla zarovnal
			; na stejný exponent)
	jp p,X0edc	; při opačných znaménkách sčítaných
			; čísel jdu na výpočet rozdílu
	call X0f41	; jsou-li znaménka sčítaných čísel
			; stejná, sečtu mantisy do C:D:E:B
	jp nc,X0f22	; a pokud nedošlo k přetečení,
			; převedu výsledek do FP akumulátoru
			; pokud je mantisa moc velká, budu
	inc hl		; ji posouvat o jeden bit doprava,
	inc (hl)		; musím tedy inkrementovat exponent
			; abych zachoval hodnotu čísla
			; pokud při tom exponent přeteče
	jp z,X0f3e	; zahlásím chybu 08h - Overflow
	ld l,1		; posunu tedy mantisu doprava, abych
	call X0f77	; měl kam dát ten "přetečený" bit
	 jp X0f22	; výsledek převedu do FP akumulátoru
; ****************************************
; sčítání mantis čísel s opačným znaménkem
; ****************************************
			; (0edch)
X0edc:	xor a		; začít rozšiřujícím bajtem, který
	sub b		; nemá poziční ekvivalent
	ld b,a		; v FP akumulátoru
	ld a,(hl)
	sbc a,e		; a následně odečíst
	ld e,a
	inc hl
	ld a,(hl)
	sbc a,d		; všechny
	ld d,a
	inc hl
	ld a,(hl)
	sbc a,c		; tři ostatní bajty mantisy
	ld c,a
			; přechod na závěrečnou normalizaci
			; FP čísla 
; ******************************************************
; normalizace 32-bitového čísla v C:D:E:B, jeho oříznutí
; na 24 bitů C:D:E a uložení do FP akumulátoru
; ******************************************************
			; (0eeah)
fpnorm:	call c,maninv	; v případě záporného čísla
			; vynásobit mantisu x (-1)
X0eed:	ld l,b
	ld h,e
	xor a		; počitadlo posunů vlevo (kvůli
			; korekci exponentu je záporné)
X0ef0:	ld b,a
	ld a,c		; budu rotovat sekvenci C:D:H:L
	and a		; doleva tak dlouho, dokud
	jp nz,X0f0f	; na nejvyšší bit mantisy
	ld c,d		; nevyjede jedničkový bit
	ld d,h		; 
	ld h,l		; zde je zkratka po osmi bitech,
	ld l,a		; pokud je C v C:D:H:L nulové
	ld a,b
	sub 8		; 
	cp 0e0h	; pokud jsem vysunul (-)32 bitů
	jp nz,X0ef0	; a nejvyšší byte mantisy je stále
			; nulový, pak je i výsledek nulový
; **********************************
; do FP akumulátoru dosadí hodnotu 0
; **********************************
			; (0f02h)
fpzero:	xor a		; Nula představuje speciální stav
X0f03:	ld (fpaccum+3),a	; FP čísla, kdy stačí vynulovat
	ret		; exponent.
; *************************************************
; vysouvání mantisy v C:D:H:L doleva po jednom bitu
; *************************************************
			; (0f07h)
X0f07:	dec b		; dokud je nejvyšší bit mantisy
	add hl,hl		; nulový, odečtu v reg. B jednu
	ld a,d		; shiftovací pozici a provedu
	rla		; posun kaskády C:D:H:L doleva
	ld d,a		; o jeden bit
	ld a,c
	adc a,a
	ld c,a
X0f0f:	jp p,X0f07	; nejvyšší bit mantisy je nulový?
	ld a,b		; už ne, už tam je jednička
	ld e,h
	ld b,l		; B = rozšiřující bajt mantisy
	and a
	jp z,X0f22
	ld hl,fpaccum+3	; exponent FP čísla zmenším o tolik
	add a,(hl)		; řádů, o kolik pozic jsem posunul
	ld (hl),a		; mantisu vlevo (v ACC přišel počet
			; posunů se záporným znaménkem)
	jp nc,fpzero	; je-li výsledný exponent příliš
			; malý, vrátit hodnotu nula
	ret z		; konec, je-li výsledek nulový
			; (exponent FP akumulátoru už je 0)
X0f22:	ld a,b		; pokud je v rozšiřujícím byte
X0f23:	ld hl,fpaccum+3	; mantisy číslo >127, zokrouhlím
	and a		; mantisu tak, že
	call m,X0f34	; přičtu +1 k její 3-bajtové části
	ld b,(hl)		; exponent výsledku do reg. B
	inc hl
	ld a,(hl)		; z rozšiřujícího byte mantisy
	and 80h		; extrahuji znaménkový bit
	xor c		; a vložím jej na pozici MSB
	ld c,a		; reg. C - nejvyššího bajtu mantisy
	 jp fpbcde	; FP číslo z B:C:D:E dá do FP akum.
; *******************************************************
; zaokrouhlení mantisy v C:D:E přičtením jedničky
; (při přetečení se inkrementuje exponent FP akumulátoru)
; *******************************************************
			; (0f34h)
X0f34:	inc e		; základní inkrementace mantisy
	ret nz
	inc d
	ret nz
	inc c
	ret nz		; a pokud nepřetekla, tak konec
	ld c,80h	; mantisa přetekla, tak provedeme
	inc (hl)		; inkrementaci exponentu a pokud
X0f3d:	ret nz		; zůstal v pracovním rozsahu, konec
X0f3e:	ld e,8		; ovšem při jeho přetečení
	rst 0x28; vyvolat chybu 08h - Overflow
; ****************************
; sčítání mantis dvou FP čísel
; ****************************
			; (0f41h)
X0f41:	ld a,(hl)		; ukázka sčítání čísel větší
	add a,e		; délky než 16 bitů :)
	ld e,a
	inc hl
	ld a,(hl)
	adc a,d
	ld d,a
	inc hl
	ld a,(hl)
	adc a,c
	ld c,a
	ret
; **************************************
; negace rozšířené mantisy C:D:E:B
; (B je zde ve funkci rozšíření mantisy)
; **************************************
			; (0f4dh)
maninv:	ld hl,fpaccum+4	; negace hodnoty rozšiřujícího bajtu
	ld a,(hl)		; mantisy v FP akumulátoru
	cpl
	ld (hl),a
	xor a		; výpočet inverze
	ld l,a
	sub b		; C:D:E:B := 0 - C:D:E:B
	ld b,a
	ld a,l
	sbc a,e
	ld e,a
	ld a,l
	sbc a,d
	ld d,a
	ld a,l
	sbc a,c
	ld c,a
	ret
; *****************************************
; posun mantisy v C:D:E:B doprava o A pozic
; *****************************************
			; (0f61h)
manrgt:	ld b,0		; vynulovat rozšíření mantisy
X0f63:	sub 8		; lze posunout najednou o 8 pozic?
	jp c,X0f70	; pokud ne, jdi na jemný posun
	ld b,e		; jinak posuň mantisu o osm bitů
	ld e,d		; doprava s přetečením do rozšiřu-
	ld d,c		; jícího byte v registru B
	ld c,0
	 jp X0f63	; a posouvej dál..
X0f70:	add a,9		; stornovat pokus o posun o 8 bitů
	ld l,a		; požadovaný počet posunů do L
X0f73:	xor a		; a v této smyčce otrocky posouvat
	dec l		; mantisu, uloženou v sekvenci
	ret z		; registrů C:D:E:B, vždy o jeden bit
	ld a,c		; vpravo
X0f77:	rra
	ld c,a
	ld a,d
	rra
	ld d,a
	ld a,e
	rra
	ld e,a
	ld a,b
	rra
	ld b,a
	 jp X0f73
; ******************************************
; funkce LOG - výpočet přirozeného logaritmu
; ******************************************
; Interně je FP číslo kódováno jako m x 2^n, kde m je manti-
; sa a n je dvojkový exponent. A protože logaritmus součinu
; je roven součtu logaritmů, platí:
; LN(m x 2^n) = LN(m) + LN(2^n)
; převodem na dvojkový logaritmus dostaneme vztah:
; LN(m x 2^n) = 0,693147 x [ LOG2(m) + LOG2(2^n)]
;             = 0,693147 x [ LOG2(m) + n]
; kvůli rychlosti konvergence aproximační řady použijeme
; transformaci: m <=> m/(sqrt(2)/2)
; tím nahradíme výpočet LOG2(m) výpočtem
; LOG2((m-sqrt(2)/2)/(m+sqrt(2)/2))-0,5 což je
; použitá sekvence LOG2(1-(sqrt(2)/(m+sqrt(2)/2)))-0,5
			; (0f85h)
f_log:	rst 0x30; znaménko čísla v FP akumulátoru
	jp pe,X0569	; pokud parametr není kladný,
			; vyvolá chybu 03h - Fnc.param.
	ld hl,fpaccum+3
	ld a,(hl)
	ld bc,8035h	; konstantu 0,5*sqrt(2) = 0.707...
	ld de,04f3h	; uložíme do B:C:D:E
	sub b		; odečtu posun nuly exponentu (80h)
	push af	; a čistý dvojkový exponent uschovám
	ld (hl),b		; exponent má nyní hodnotu 1
			; a mantisa neovlivněná exponentem
			; vstupuje do dalších výpočtů
	push de		; FP := FP + sqrt(2)/2
	push bc		; (k mantise přičtu sqrt(2)/2)
	call X0e9c
	pop bc
	pop de
	inc b		; B:C:D:E := sqrt(2) (tj. 1.414...)
	call X1021	; FP := sqrt(2) / FP
	ld hl,X17f7
	call X0e93	; FP := 1 - FP
	ld hl,X17fb	; aproximace LOG2(x) mocninnou řadou
	call oaprox	; s lichými koeficienty
	ld bc,8080h	; FP := FP - 0,5
	ld de,0000h
	call X0e9c
	pop af		; obnovit čistý exponent původního
	call X124c	; čísla a přičíst k FP
; ****************************************************
; vynásobení výsledku v FP akumulátoru číslem 0,693147
; (přechod z dvojkového na přirozený logaritmus)
; ****************************************************
X0fba:	ld bc,8031h	; a vynásobením x 0,693147 převedeme
	ld de,7218h	; z dvojkového na přirozený logaritmus
	.db 21h		; lxi h,..
; ****************************************
; obslužná procedura operátoru krát
; do FP akumulátoru uloží součin sebe sama
; a FP čísla, uloženého v zásobníku
; ****************************************
			; (0fc1h)
X0fc1:	pop bc		; do B:C:D:E načíst FP číslo
	pop de		; ze zásobníku
; *********************************************
; FACCU := FACCU x B:C:D:E
; reg. B slouží jako prodloužení mantisy vpravo
; a kumuluje vysouvané nejnižší složky součinu
; *********************************************
			; (0fc3h)
X0fc3:	rst 0x30; je-li ve FP akumulátoru nula,
	ret z		; tak je to i výsledek :)
	ld l,0		; exponenty se v případě násobení
	call X1091	; FP čísel pouze sečtou
	ld a,c		; mantisu C:D:E uložím jako přímé
	ld (X0ff9+1),a	; parametry instrukcí v těle
	ex de,hl		; vlastní násobící smyčky
	ld (X0ff4+1),hl
	ld bc,0		; vynulovat pracovní mantisu
	ld d,b		; včetně jejího prodloužení v reg. B
	ld e,b
	ld hl,X0eed	; po ukončení násobení bude
	push hl		; následovat normalizace čísla
	ld hl,X0fe3	; smyčka násobení 8-bitovým číslem
	push hl		; se po přímém vykonání vyvolá
	push hl		; ještě 2x (push h + push h)
			; tj. násobení 24-bitovou mantisou
			; z FP akumulátoru
	ld hl,fpaccum	; začínáme od LSB FP akumulátoru
X0fe3:	ld a,(hl)		; načtu aktuální bajt FP akumulátoru
	inc hl
	and a		; a pokud je nulový, provedu
	jp z,X100e	; pouze posun vlevo (urychlení)
	push hl		; uschovat ukazatel na aktuální bajt
			; FP akumulátoru
	ex de,hl		; HL = LSB a NSB pracovní mantisy
		
	ld e,8		; postupné "násobení" všemi bity
X0fed:	rra		; vynásobím C:D:E:B aktuálním bitem
			; FP akumulátoru
	ld d,a		; uschovat akt. bajt FP akumulátoru
	ld a,c		; A = MSB pracovní mantisy
	jp nc,X0ffb	; při násobení nulou jen rotace
	push de		; při násobení jedničkou i součet
X0ff4:	ld de,0		; k sekvenci A:H:L (prac. mantisa)
	add hl,de		; přičte 24-bitovou hodnotu, kterou
	pop de		; jsme do "LXI D,xxxx" a "ACI 80h"
X0ff9:	adc a,80h		; uložili na začátku procedury
X0ffb:	rra		; rotace pracovní mantisy o jeden
	ld c,a		; bit vpravo, výsledek se uloží
	ld a,h		; do sekvence C:H:L:B
	rra
	ld h,a
	ld a,l
	rra
	ld l,a
	ld a,b
	rra
	ld b,a
	dec e		; odpočet bitů aktuálního bajtu
	ld a,d		; obnovit aktuální bajt FP akumul.
	jp nz,X0fed	; je další bit?
	ex de,hl		; pokud ne, LSB a NSB pracovní
			; mantisy obnovím do DE
X100c:	pop hl		; obnovím adresu na aktuální bajt
			; FP akumulátoru
	ret		; a ve skutečnosti jdu na další bajt
X100e:	ld b,e		; v případě dílčího násobení nulovým
	ld e,d		; bajtem se jen posune pracovní
	ld d,c		; mantisa C:D:E:B vpravo o osm bitů
	ld c,a
	ret		; a ve skutečnosti jdu na další bajt
; *************************************
; obsah FP akumulátoru vydělí číslem 10
; *************************************
			; (1013h)
X1013:	call pushfp	; FP akumulátor uloží do zásobníku
	ld bc,8420h
	ld de,0000h	; konstantu 10 
	call fpbcde	; uloží do FP akumulátoru
; **********************************
; FP číslo v zásobníku vydělí číslem
; z FP akumulátoru
; **********************************
			; (101fh)
X101f:	pop bc		; do B:C:D:E načíst FP číslo
	pop de		; ze zásobníku
; ****************************************
; obslužná procedura operátoru "děleno"
; FP akumulátor := B:C:D:E / FP akumulátor
; ****************************************
			; (1021h)
X1021:	rst 0x30; při dělení nulou vyvolat
	jp z,err_0c	; chybu 0ch - Dv by zero
	ld l,0ffh	; exponent FP čísla v FP akumulátoru
	call X1091	; nastaví na rozdíl exponentů
	inc (hl)		; dělence a dělitele a tím určí
	inc (hl)		; exponent výsledného podílu
	dec hl
	ld a,(hl)		; mantisu dělitele uložit jako
	ld (X104f+1),a	; přímé operandy instrukcí
	dec hl		; v sekvenci odečítání dělitele
	ld a,(hl)
	ld (X104b+1),a
	dec hl
	ld a,(hl)
	ld (X1047+1),a
	ld b,c		; B:H:L := mantisa dělence
	ex de,hl		; C:D:E := 0
	xor a
	ld c,a
	ld d,a
	ld e,a
	ld (X1052+1),a
X1044:	push hl		; uschovat hodnotu průběžného
	push bc		; zbytku v B:H:L
	ld a,l
X1047:	sub 0		; od průběžného zbytku v B:H:L
	ld l,a		; odečtu mantisu dělitele
	ld a,h
X104b:	sbc a,0
	ld h,a
	ld a,b
X104f:	sbc a,80h
	ld b,a
X1052:	ld a,0		; prodloužení průběžného zbytku
	sbc a,0		; před B:H:L (znaménko)
	ccf
	jp nc,X1061	; byl-li zbytek < dělitel, pak skok
	ld (X1052+1),a	; jinak akceptovat odečet a nechat
	pop af		; jej v B:H:L
	pop af
	scf
	.db 0d2h
X1061:	pop bc		; obnovit původní hodnotu průběžného
	pop hl		; zbytku před odečtem
	ld a,c		; ???
	inc a
	dec a
	rra
	jp m,X0f23	; korekce a FP := B:C:D:E
	rla
	ld a,e		; C:D:E posunout vlevo s nasunutím
	rla		; výsledku odečtu zprava
	ld e,a
	ld a,d
	rla
	ld d,a
	ld a,c
	rla
	ld c,a
	add hl,hl		; posun prodloužené sekvence
	ld a,b		; (1052h):B:H:L vlevo jako
	rla		; pokračování sekvence C:D:E
	ld b,a
	ld a,(X1052+1)
	rla
	ld (X1052+1),a
	ld a,c		; ???
	or d
	or e
	jp nz,X1044
	push hl
	ld hl,fpaccum+3	; ???
	dec (hl)
	pop hl
	jp nz,X1044
	 jp X0f3e	; chyba 08h - Overflow
; *********************************************
; provede součet/rozdíl exponentů dvou FP čísel
; reg. L = součet(=0) nebo rozdíl (=0FFh)
; reg. B = exponent prvního FP čísla
; (FP akumulátor+3) = exponent druhého FP čísla
; výsledný exponent uloží do (FP akumulátor+3)
; *********************************************
			; (1091h)
X1091:	ld a,b		; je-li exponent prvního FP čísla
	and a		; nulový, pak je v FP akumulátoru
	jp z,X10b3	; (jeho exponentu) hotový výsledek
	ld a,l		; přepínač součet/rozdíl
	ld hl,fpaccum+3	; sečte exponenty obou FP čísel
	xor (hl)		; očištěné od posunu nulové hodnoty
	add a,b		; a testuje extrémy (nula/nekonečno) 
	ld b,a
	rra
	xor b
	ld a,b
	jp p,X10b2	; skok při některém z extrémů
	add a,80h		; k výsledku operace nad exponenty
	ld (hl),a		; přičíst posun nuly (80h) a uložit
			; do exponentu FP akumulátoru
	jp z,X100c	; nulová hodnoty FP čísla
	call X112d	; do mantis načíst úvodní jedničky
	ld (hl),a		; znaménko do rozšiřujícího
			; byte FP akumulátoru
	dec hl		; posun na exponent FP akumulátoru
	ret
; ****************************************************
; generování mezních hodnot
; při podtečení zvolí nulu, při přetečení vyvolá chybu
; ****************************************************
X10af:	rst 0x30; určí znaménko exponentu (-1/0/+1)
	cpl		; které však otočí
	pop hl
X10b2:	and a		; a podle toho..
X10b3:	pop hl
	jp p,fpzero	; při podtečení pod rozlišovací
			; schopnost FP interpretace vrátí
			; nulovou hodnotu (lim 1/e^n >> 0)
	 jp X0f3e	; v opačném případě
			; vyvolá chybu 08h - Overflow
; *******************************************
; vynásobí hodnotu v FP akumulátoru číslem 10
; *******************************************
			; (10bah)
fp_x10:	call X1113	; FP >> B:C:D:E
	ld a,b		; je-li v FP akumulátoru nula,
	and a
	ret z		; je to i výsledek
	add a,2		; dvojkový exponent zvětšený o dva
			; znamená vynásobit číslo čtyřmi
	jp c,X0f3e	; testovat a hlásit přetečení
	ld b,a		; uložit zpět exponent
	call X0e9c	; k FP akumulátoru přičíst FP číslo,
			; uložené v kaskádě B:C:D:E
			; máme vynásobeno 5x
	ld hl,fpaccum+3	; vynásobíme FP akumulátor dvěma
	inc (hl)		; (zvedneme dvojkový exponent o 1)
	 jp X0f3d	; a provedeme test na přetečení
; ******************************************
; pokračování RST 6 - test znaménka FP čísla
; ******************************************
			; (10d0h)
X10d0:	ld a,(fpaccum+2)	; MSB mantisy drží znaménko (pokud se
			; ovšem nejedná o čistou nulu, pak je
			; nulový exponent)
	.db 0feh	; cpi ..
X10d4:	cpl
	rla		; CY = znaménko čísla
X10d6:	sbc a,a		; A=00h pro kladná, A=FFh pro záporná
	 jp X167c
; **********
; funkce SGN
; **********
			; (10dah)
f_sgn:	rst 0x30; načte hodnotu -1/0/+1 dle hodnoty FP
; *****************************************************
; převede 8-bitové číslo se znaménkem z ACC na FP číslo
; *****************************************************
			; (10dbh)
a2fp:	ld b,88h	; exponent 2^8 pro FP číslo
	ld de,0		; oba MSB jsou nulové, ACC nese hodnotu
; ***********************************************
; číslo B:A:D:E převede na normalizované FP číslo
; ***********************************************
			; (10e0h)
badefp:	ld hl,fpaccum+3
	ld (hl),b		; uložit exponent
	ld c,a		; B:A:D:E >> B:C:D:E:00 >> (exp):C:D:E:B
	ld b,0		; vynulovat prodloužení
	inc hl
	ld (hl),80h	; do prodloužení FP akumulátoru uložit
			; hodnotu 0,5 pro zaokrouhlení
			; při normalizaci
	rla		; do CY uložit znaménko
	 jp fpnorm
; **********
; funkce ABS
; **********
			; (10eeh)
f_abs:	rst 0x30; test znaménka
	ret p		; a pokud je kladné, konec
; ***********************************************
; Otočení znaménka u FP čísla v akumulátoru FACCU
; ***********************************************
			; (10f0h)
X10f0:	ld hl,fpaccum+2	; u čísla uloženého v FP akumulátoru
	ld a,(hl)
	xor 80h		; neguje znaménkový bit
	ld (hl),a
	ret
; ***********************************
; Uložení FP akumulátoru do zásobníku
; ***********************************
			; (10f8h)
pushfp:	ex de,hl
	ld hl,(fpaccum)	; "pod" návratovou adresu
	ex (sp),hl		; v zásobníku vsune 2x 2bajty
	push hl		; FP akumulátoru
	ld hl,(fpaccum+2)
	ex (sp),hl
	push hl
	ex de,hl
	ret
; ****************************************************
; FP číslo, uložené od adresy, dané obsahem reg. HL
; uloží do FP akumulátoru (s mezizápisem přes B:C:D:E)
; ****************************************************
			; (1105h)
X1105:	call X1116	; (HL) > B:C:D:E
; ****************************************
; FP číslo B:C:D:E uloží do FP akumulátoru
; ****************************************
			; (1108h)
fpbcde:	ex de,hl
	ld (fpaccum),hl
	ld h,b
	ld l,c
	ld (fpaccum+2),hl
	ex de,hl
	ret
; *****************************************************
; číslo z FP akumulátoru nakopíruje do registrů B:C:D:E
; *****************************************************
			; (1113h)
X1113:	ld hl,fpaccum
; **************************************************
; od adresy uložené v reg. HL načte FP číslo B:C:D:E
; **************************************************
			; (1116h)
X1116:	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	ld c,(hl)
	inc hl
	ld b,(hl)
X111d:	inc hl
	ret
; **************************************
; obsah FP akumulátoru uloží do paměti
; od adresy, dané obsahem reg. HL
; **************************************
			; (111fh)
X111f:	ld de,fpaccum
; ***************************************
; přenos 4 bajtů z adresy DE na adresu HL
; ***************************************
X1122:	ld b,4
; ***************************************
; přenos B bajtů z adresy DE na adresu HL
; ***************************************
X1124:	ld a,(de)
	ld (hl),a
	inc de
	inc hl
	dec b
	jp nz,X1124
	ret
; ************************************************
; převod mantis dvou FP čísel z formátu dvojkového
; doplňkového kódu na meziformát MS BASICu
; ************************************************
			; (112dh)
X112d:	ld hl,fpaccum+2	; nastavit úvodní jedničku na pozici
	ld a,(hl)		; MSB mantisy v FP akumulátoru
	rlca
	scf
	rra
	ld (hl),a
	ccf		; a negovaný původní znaménkový bit
	rra		; uložit do rozšiřujícího bajtu
	inc hl		; FP akumulátoru na pozici MSB
	inc hl
	ld (hl),a
	ld a,c		; nastavit úvodní jedničku na pozici
	rlca		; MSB mantisy v C:D:E
	scf
	rra
	ld c,a
	rra		; v ACC vrátí 80h při shodě
	xor (hl)		; znamének, jinak 00h
	ret
; ***********************************************
; Porovnání FP čísel v FP akumulátoru a v B:C:D:E
; ***********************************************
			; (1142h)
X1142:	ld a,b		; Pokud je B:C:D:E nulové, provést
	and a		; analýzu FP akumulátoru 
	jp z,X0030	; (vyjde to na stejno)
	ld hl,X10d4	; adresa závěrečné procedury, která
	push hl		; vrací stavy -1/0/+1
	rst 0x30; při nulovém FP akumulátoru
	ld a,c		; test znaménka čísla v B:C:D:E
	ret z		; (via X10d4)
	ld hl,fpaccum+2	; při nerovnosti znamének čísel
	xor (hl)		; porovnat jen znaménka
	ld a,c
	ret m		; (via X10d4)
	call X115a	; jinak poctivě porovnat obě čísla
			; (při shodě se sem už nevracíme)
	rra		; při neshodě sestavit pseudobyte
	xor c		; obsahující relaci a znaménko
	ret		; a jít na X10d4
; *******************************************************
; porovná FP číslo v B:C:D:E s FP číslem v FP akumulátoru
; *******************************************************
			; (115ah)
X115a:	inc hl		; bajt po bajtu porovná
	ld a,b		; sekvenci B:C:D:E
	cp (hl)		; se čtveřicí hodnot v paměti
	ret nz
	dec hl		; porovnává se od nejvíce významného
	ld a,c		; směrem k nejméně významnému
	cp (hl)
	ret nz		; při neshodě procedura končí
	dec hl		; a příznaky Z, CY (ale i další)
	ld a,d		; reflektují relaci mezi položkami
	cp (hl)
	ret nz		; při shodě se jde testovat další
	dec hl		; méně významný člen sekvence
	ld a,e
	sub (hl)
	ret nz
	pop hl		; při shodě zrušit návratovou adresu
	pop hl		; a skok na proceduru X10d4
	ret
; *****************************************************
; do B:C:D:E uloží celočíselnou část FP čísla z B:C:D:E
; *****************************************************
			; (116dh)
X116d:	ld b,a		; nastavit nulovou hodnotu výsledku
	ld c,a
	ld d,a
	ld e,a
	and a		; pro případ
	ret z		; nulového vstupního argumentu
	push hl
	call X1113	; načíst argument z FP do B:C:D:E
	call X112d	; C:D:E naplnit absolutní hodnotou
			; mantisy čísla a převést na interní
			; kódování
	xor (hl)		; původní znaménko argumentu
	ld h,a		; uložit do registru H
	call m,X1191	; u záporných čísel návrat z dvojko-
			; vého doplňku na jedničkový doplněk
	ld a,98h	; posunout mantisu doprava o tolik
	sub b		; pozic, abych zbyla jen celá část
	call manrgt	; (odehrává se v C:D:E)
	ld a,h		; zde se dělá rozdíl mezi INT(+N)
	rla		; a INT(-N), tzn. pro záporné číslo
	call c,X0f34	; je absolutní hodnota výsledku
			; menší o 1 oproti kladnému číslu
	ld b,0		; nulový exponent (posun mantisy)
	call c,maninv	; negace mantisy pro záporná čísla
	pop hl
	ret
; *************************
; dekrement kaskády B:C:D:E
; *************************
X1191:	dec de		; nejprve dekrement D:E a při
	ld a,d
	and e
	inc a		; podtečení na 0FFFFh se
	ret nz
	dec bc		; dekrementuje i B:C
	ret
; **********
; funkce INT
; **********
			; (1198h)
f_int:	ld hl,fpaccum+3	; načíst dvojkový exponent
	ld a,(hl)		; pokud je posun mantisy vpravo
	cp 98h		; >24bitů (98h-80h=18h=24), pak
	ld a,(fpaccum)	; číslo v FP akumulátoru žádnou
	ret nc		; desetinnou část nemá => konec
	ld a,(hl)		; načíst původní exponent pro případ
			; nulové hodnoty
	call X116d	; výpočet celé části v B:C:D:E
	ld (hl),98h	; celá mantisa bude před des. tečkou
			; (zatím je v FP akumulátoru původní
			; číslo)
	ld a,e		; některé funkce vyžadují hodnotu
	push af	; LSB mantisy, tak ji schováme
	ld a,c		; načíst znaménko mantisy
	rla		; do příznakového bitu CY
	call fpnorm	; a provést její normalizaci
	pop af		; do ACC obnovit LSB mantisy
	ret
; ********************
; výpočet HL = BC x DE
; ********************
			;(11b1h)
hl_bxd:	ld hl,0		; vynulovat průběžný akumulátor
	ld a,b		; test triviálního případu BC = 0
	or c		; nulová hodnota registru BC
	ret z		; vyvolá konec s nulovou hodnotou HL
	ld a,16	; 16 kroků násobení (délka DE)
X11b9:	add hl,hl		; posun akumulátoru vlevo
	jp c,X0b95	; a v případě přetečení 
			; chyba 01h - Subscr.rng
	ex de,hl		; posun DE vlevo s vysunutím MSB
	add hl,hl		; do příznakového bitu CY
	ex de,hl
	jp nc,X11c7	; při nulovém bitu CY nedělat nic
	add hl,bc		; ale při jedničkovém provedu
	jp c,X0b95	; HL = HL + BC a testuju přetečení
X11c7:	dec a		; pronásobit BC dalším bitem z DE
	jp nz,X11b9	; a to celkem 16x
	ret
; ******************************************************
; při vyhodnocování výrazu byla nalezena cifra, proto se
; BASIC pokusí převést sekvenci cifer na FP číslo
; ******************************************************
X11cc:	cp '-'		; bude tam unární mínus?
	push af	; příznak Z uschovat pro pozdější test
	jp z,X11d8
	cp '+'		; nebo tam je unární plus?
	jp z,X11d8	; to jen přeskočíme
	dec hl		; připravit na čtení dalšího znaku
X11d8:	call fpzero	; vynulovat FP akumulátor
	ld b,a		; B = počet desetinných cifer
	ld d,a		; D = příznak znaménka exponentu
	ld e,a		; E = hodnota desítkového exponentu
	cpl		; C = rozlišení celočíselné
	ld c,a		;     a desetinné části čísla
X11e0:	rst 0x10; test dalšího znaku mantisy
	jp c,X1235	; je-li to cifra, přidej ji k číslu
	cp '.'		; test na desetinnou tečku
	jp z,X1210
	cp 'E'		; test na exponenciální zápis
	jp nz,X1214	; pokud není, přeskočit jeho načtení
	rst 0x10; načíst první znak exponentu
	push hl		; a pro případ, že by to bylo
	ld hl,X1204	; znaménko, připravit se na zadání
	ex (sp),hl		; vlastní hodnoty exponentu
	dec d		; příznak záporného exponentu
	cp 0a5h	; otestovat token operátoru '-'
	ret z
	cp '-'		; otestovat unární mínus exponentu
	ret z
	inc d		; shodit příznak zápor. exponentu
	cp '+'		; a otestovat formální unární plus
	ret z		; exponentu
	cp 0a4h	; a ještě token operátoru '+'
	ret z
	pop af		; nepřišlo žádné znaménko, začínáme
	dec hl		; číslem (zrušíme odskok - pop psw)
			; načtení a vyčíslení exponentu
X1204:	rst 0x10; dokud je platná cifra,
	jp c,X1257	; načítej do E hodnotu exponentu
	inc d		; pokud byl nastaven příznak
	jp nz,X1214	; záporného exponentu, pak	
	xor a		; se znaménko exponentu v registru E
	sub e		; otočí
	ld e,a
	inc c		; přeskočení následujícího testu
X1210:	inc c		; po zadání celočíselné části volá
	jp z,X11e0	; ještě jednou pro desetinnou část
X1214:	push hl		; ukazatel do zdojového textu BASICu
			; uschovat do zásobníku
	ld a,e		; exponent - počet desetinných míst
	sub b		; uložit do registru A
X1217:	call p,fpscal	; podle potřeby je číslo v FP
	jp p,X1223	; akumulátoru posouváno buď vlevo
	push af	; nebo vpravo, tak aby se dosáhlo
	call X1013	; výsledku ve tvaru:
	pop af
	inc a		; 0.NNNNNN x 10^E
X1223:	jp nz,X1217
	pop de		; (0,5 <= mantisa < 1)
	pop af		; obnovit výsledek testu na unární
	call z,X10f0	; mínus (pokud bylo, provedeme
			; negaci čísla v FP akumulátoru)
	ex de,hl		; do HL obnovit ukazatel na zdrojový
	ret		; text programu v BASICu
; ****************************************************
; vynásobí FP akumulátor deseti včetně podpory iterace
; ****************************************************
			; (122dh)
fpscal:	ret z		; poslední iterace? => konec
fpx10i:	push af
	call fp_x10	; vlastní násobení FP := FP x 10
	pop af
	dec a		; další iterace
	ret
; *******************************************
; přidání cifry v registru A k FP akumulátoru
; *******************************************
			; (1235h)
X1235:	push de		; uschovat příznak negat. exponentu
	ld d,a		; uschovat hodnotu cifry
	ld a,b		; pokud C indikuje desetinnou část
	adc a,c		; čísla, přičítat k B počet
	ld b,a		; načtených desetinných míst
	push bc		; uschovat pracovní registry
	push hl
	push de
	call fp_x10	; a FP akumulátor vynásobit deseti
	pop af		; obnovit načítanou cifru
	sub 30h		; převést ji na absolutní hodnotu
	call X124c	; a přičíst k FP akumulátoru
	pop hl
	pop bc		; obnovit pracovní registry
	pop de
	 jp X11e0	; a zpět do smyčky čtení znaků
; **************************************************
; přičte cifru v registru A k hodnotě FP akumulátoru
; **************************************************
			; (124ch)
X124c:	call pushfp	; FP akumulátor do zásobníku
	call a2fp	; A do FP akumulátoru
; ****************************************
; obslužná procedura operátoru +
; do FP akumulátoru uloží součet sebe sama
; a FP čísla, uloženého v zásobníku
; ****************************************
X1252:
	pop bc		; do B:C:D:E zformuje FP číslo
	pop de		; uložené v zásobníku
	 jp X0e9c	; a volá samotný součet
; ****************************************************
; načte cifru ze zdrojového textu BASICu a nasune ji
; do registru E zprava (používá se pro načtení hodnoty
; exponentu s max. hodnotou 38)
; ****************************************************
			; (1257h)
X1257:	ld a,e		; obsah registru E
	rlca		; vynásob dvěma..
	rlca		; čtyřmi..
	add a,e		; pěti..
	rlca		; vlastně deseti
	add a,(hl)		; a přičti cifru z adresy dané HL
	sub '0'
	ld e,a
	 jp X1204	; vrať se do hlavní procedury
; ***************************
; tiskne string "at line xxx"
; ***************************
			; (1263h)
X1263:	push hl		; uschovat číslo řádku
	ld hl,X16ff	; text "at line "
	call tx2edi	; vytisknout na obrazovku
	pop hl		; obnovit číslo řádku
; ************************************************
; 16-bitovou hodnotu v HL převede na FP a vytiskne
; ************************************************
			; (126bh)
X126b:	ex de,hl		; HL převedeme na nenormalizované
	xor a		; číslo B(exponent):A:H:L
	ld b,98h	; pak už stačí jen (98h-80h=18h=24)
	call badefp	; 24 shiftů doleva, abychom z čísla
	ld hl,X0d33	; 0.A:H:L udělali číslo A:H:L.0
	push hl		; po tisku do 12-znakového buferu
			; se provede další "tisk", tentokrát
			; do předtiskového buferu
; ****************************************
; vytiskne FP číslo do 12-znakového buferu
; ****************************************
X1276:	ld hl,fpprtbf	; adresa tiskového buferu
	push hl
	rst 0x30; test na znaménko, není-li záporné,
	ld (hl),' '	; vynechat mezeru
	jp p,X1282
	ld (hl),'-'	; jinak tam vložit unární mínus
X1282:	inc hl		; pokud je číslo nulové, uložit
	ld (hl),'0'	; jen cifru "0"
	jp z,X1337	; a zakončit
	push hl
	call m,X10f0	; záporná čísla převést na kladná
	xor a		; vynulovat počet řádových posunů
	push af	; a uschovat do zásobníku
	call X133d	; pokud je číslo větší než 999999,
			; skočit na část, kde se posouvá
			; vpravo (dělí se deseti)
X1291:	ld bc,9143h	; dokud je číslo menší než 100000,
	ld de,4ff8h	; posouvat vlevo (násobí se deseti)
	call X1142	;
	jp po,X12ae
	pop af
	call fpx10i
	push af
	 jp X1291
X12a5:	call X1013	; FP := FP/10
	pop af		; počitadlo snížených řádů
	inc a		; zvětšit o jedna
	push af
	call X133d	; opakuj dokud je FP číslo > 999999
			; nyní máme prvních šest cifer
			; mantisy jako integer a upravenou
			; (nenormovanou) hodnotu exponentu
X12ae:	call X0e8a	; šestimístnou mantisu
	inc a		; ve FP akumulátoru
	call X116d	; zaokrouhlit
	call fpbcde	; (+0,5 > INT > COPY to FP)
	ld bc,0306h	; B : standardně 1 cifra před čárkou
			; C : standardně 6 cifer přesnost
	pop af		; počitadlo snížených řádů
	add a,c		; 
	inc a		; čísla menší než 0,01 jsou tištěna
	jp m,X12ca	; v exponenciálním tvaru
	cp 8		; a čísla větší než 999999 jsou také
	jp nc,X12ca	; tištěna v exponenciálním tvaru
	inc a
	ld b,a		; nulový exponent (N x 10^0 = N)
	ld a,2		; tedy zápis bez exponentu
X12ca:	dec a		; A = 2 + exponent
	dec a		; B = 2 + počet cifer před čárkou
	pop hl
	push af
	ld de,tb10ex	; tab. desítkové báze
	dec b
	jp nz,X12db
	ld (hl),'.'	; pro rozšíření rozsahu čísel, kdy
	inc hl		; není použit exponenciální tvar,
	ld (hl),30h	; je pro B=2 použito ještě zápisu
	inc hl		; 0.0xxxxxx (rozlišení 6 cifer)
X12db:	dec b		; vyčerpal jsem cifry celé části
	ld (hl),'.'	; čísla a nastal čas pro vložení
	call z,X111d	; desetinné čárky?
	push bc		; uschovat počitadlo cifer
	push hl		; a ukazatel do tiskového buferu
	push de		; uschovat tab. desítkové báze
	call X1113	; (B):C:D:E := FP
	pop hl		; HL = tab. desítkové báze
	ld b,'0'-1	; inicializace cifry
X12ea:	inc b		; od celočíselné hodnoty mantisy
	ld a,e		; v C:D:E odečítá zvolený desítkový
	sub (hl)		; řád a v registru B formuje
	ld e,a		; ASCII interpretaci cifry, určující
	inc hl		; počet daných desítkových řádů
	ld a,d		; v hodnotě mantisy
	sbc a,(hl)
	ld d,a
	inc hl
	ld a,c
	sbc a,(hl)
	ld c,a
	dec hl
	dec hl		; a to se opakuje, dokud mantisa
	jp nc,X12ea	; není menší než nula
	call X0f41	; pak stornovat poslední odečet
	inc hl
	call fpbcde	; do FP uložit C:D:E
	ex de,hl		
	pop hl		; obnovit ukazatel do tiskového
	ld (hl),b		; buferu a zapsat cifru aktuálně
	inc hl		; zjištěného řádu, pak posun
	pop bc		; obnovit počitadlo platných číslic
	dec c		; a pokud je co tisknout,
	jp nz,X12db	; tak tisk další cifry
	dec b		; jsou poslední cifry desetinné?
	jp z,X131b	; pokud ne, přeskočit test..
X130f:	dec hl		; odmazání nevýznamných nul
	ld a,(hl)		; desetinného čísla zprava
	cp '0'
	jp z,X130f
	cp '.'		; je-li posledním znakem desetinná
	call nz,X111d	; tečka, umazat i tuto
X131b:	pop af		; pokud je exponent nulový,
	jp z,X133a	; zakončit "tiskem" nulového bajtu
	ld (hl),'E'	; jinak pokračujeme tiskem znaku 'E'
	inc hl		; jako prefixem exponentu
	ld (hl),'+'
	jp p,X132b	; podle polarity exponentu zvolíme
	ld (hl),'-'	; a zapíšeme jeho znaménko
	cpl		; pro převod hodnoty exponentu
	inc a		; na ASCII změníme jeho znaménko
X132b:	ld b,'0'-1	; do B uložit přímo ASCII znak,
X132d:	inc b		; reprezentující počet desítek
	sub 0ah		; hodnoty exponentu
	jp nc,X132d
	add a,3ah		; korekce zbytku na výpočet jednotek
	inc hl		; exponentu do registru A
	ld (hl),b		; zapsat cifru desítek exponentu
X1337:	inc hl		; (včetně nevýznamné nuly)
	ld (hl),a		; zapsat cifru jednotek exponentu
	inc hl
X133a:	ld (hl),c		; a zakončit nulovým bajtem
	pop hl
	ret
X133d:	ld bc,9474h	; pomocná rutina, která se podílí
	ld de,23f7h	; na opakovaném dělení čísla
	call X1142	; v FP akumulátoru deseti, dokud je
	pop hl		; větší než 999999
	jp po,X12a5
	jp (hl)
; ********************************************************
; uloží do zásobníku adresu procedury pro otočení znaménka
; ********************************************************
			; (134bh)
X134b:	ld hl,X10f0	; volací adresu procedury pro negaci
	ex (sp),hl		; zamění s navrátovou adresou,
	jp (hl)		; na kterou se vrátí řízení programu
; *************************************
; funkce SQR (druhá odmocnina)
; *************************************
; její výpočet je realizován dle vztahu
; SQR(X) = x ^ 0.5
; *************************************
			; (1350h)
f_sqr:	call pushfp	; argument schovat do zásobníku
	ld hl,X1808	; do FP akumulátoru načíst hodnotu
	call X1105	; konstanty mocnitele 0.5
; ***********************************************
; funkce ^ (obecná mocnina)
; ***********************************************
; vypočte obecnou mocninu
; základ mocniny (mocněnec) je uložen v zásobníku
; exponent (mocnitel) je uložen v FP akumulátoru
; ***********************************************
; výpočet je realizován pomocí funkcí LOG a EXP
; dle vztahu: x^n = e^(n x ln(x))
; ***********************************************
; pozn. k odlišení exponentu z definice mocniny
;       od exponentu z interpretace FP čísla je
;       v textu použito výrazů mocněnec/mocnitel
; ***********************************************
X1359:	pop bc		; mocněnec načíst ze zásobníku
	pop de		; do sekvence registrů B:C:D:E
	rst 0x30; test mocnitele (x^0 je vždy 1)
	ld a,b		; (zatím nezavázně načíst znaménko
			;  mocněnce)
	jp z,f_exp	; při nulovém mocniteli převést
			; výpočet na EXP(0), což je 1
	jp p,X1367	; pro kladné hodnoty mocnitele
			; přeskočit test dělení nulou
			; (x^-n) = 1/(x^n)
	and a		; a pokud bych chtěl dělit tou nulou
			; (mocněnec = 0)
	jp p,err_0c	; pak chyba 0c - Dv by zero
			; chyba! zde měla být instrukce
			; jz err_0c
			; jinak totiž kromě dělení nulou se
			; jako chyba vyhodnotí i všichni
			; mocněnci s hodnotou <0,5
X1367:	and a		; test mocněnce na případnou nulu
	jp z,X0f03	; 0^n je vždy nula
	push de		; mocněnec uschovat do zásobníku
	push bc
	ld a,c		; test znaménka mocněnce
	or 7fh
	call X1113	; mocnitel z FP akum. do B:C:D:E
	jp p,X1384	; kladný mocněnec => výpočet přímo
			; pro záporné hodnoty mocněnce je
			; nutno ohlídat znaménko
	push de		; následující sekvence vypočte
	push bc		; rozdíl mezi mocnitelem a jeho
	call f_int	; celočíselnou hodnotou
	pop bc
	pop de		; a nastaví příznaky
	push af
	call X1142	; Z = 1 pro záporný mocněnec (kladné
	pop hl		;       jsme totiž vyloučili)
	ld a,h		; CY = 1 pro kombinaci lichý mocni-
	rra		;        tel/záporný mocněnec
X1384:	pop hl		; mocněnec do FP akumulátoru
	ld (fpaccum+2),hl
	pop hl
	ld (fpaccum),hl
	call c,X134b	; pro liché hodnoty mocnitele
			; záporného mocněnce bude na závěr
			; výpočtu otočeno znaménko
	call z,X10f0	; záporný mocněnec vždy převést
			; na kladný
	push de		; a nyní už počítáme podle předpisu
	push bc
	call f_log	; ..logaritmus mocněnce..
	pop bc
	pop de
	call X0fc3	; ..vynásobíme mocnitelem..
			; a použijeme jako exponent 
			; funkce e^x
; *********************************************************
; funkce EXP - exponenciální funkce nad přirozeným základem
; *********************************************************
			; (139ch)
f_exp:	call pushfp	; argument uložený v FP akumulátoru
	ld bc,8138h	; a konstantu 1/ln(2)
	ld de,0aa3bh	; (přirozený logaritmus)
	call X0fc3	; vzájemně vynásobit
			; =přechod z přirozeného na dvojkový
			; základ logaritmu
	ld a,(fpaccum+3)	; pokud je exponent větší než 127,
	cp 88h		; (2^7) pak ihned vyvolat přetečení
	jp nc,X10af	; pokud je argument menší než -127,
			; (2^-7), je výsledek pod mezí
			; rozlišení, tedy nula
	call f_int	; nyní přesněji otestovat argument
	add a,80h		; na max. +87 (větší generuje chybu
	add a,2		; přetečení) a min. -88 (menší
	jp c,X10af	; generuje podtečení, tedy nulu)
			; ..testuje se LSB mantisy..
	push af	; uschovat LSB mantisy FP čísla
	ld hl,X17f7	; FP konstanta 1.0
	call X0e8d	; bude připčtena k FP akumulátoru
	call X0fba	; vynásobení konstantou 0,693147
	pop af		; pro přechod z dvojkového na přiro-
			; zený logaritmus
	pop bc		; obnovit původní argument funkce
	pop de
	push af
	call X0e99	; a od něj odečíst poslední výsledek 
	call X10f0	; změnit znaménko
	ld hl,X181e	; aproximace polynomem
	call approx	; se sadou 8 koeficientů
	ld de,0		; obnovit závěrečnou konstantu
	pop bc
	ld c,d
	 jp X0fc3	; pro finální vynásobení
; *********
;funkce RND
; *********
			; (13dch)
f_rnd:	rst 0x30; test znaménka argumentu
	ld hl,X183f	; při záporném argumentu skok
	jp m,X143b	; na samostatnou rutinu
			; pro nulový argument
	ld hl,X1860	; poslední hodnotu funkce RND
	call X1105	; načíst do FP akumulátoru
	ld hl,X183f	; 
	ret z		; a předat ven jako hodnotu funkce
			; pro kladný argument
	add a,(hl)		; připravit další ze sady osmi!
	and 7		; multiplikativních konstant
	ld (hl),a
	inc hl
	ld b,0		; dle pořadí konstanty
	add a,a		; určit její adresu
	add a,a
	ld c,a
	add hl,bc
	call X1116	; načíst multiplikativní konstantu
	call X0fc3	; a vynásobit obsah FP akumulátoru
	ld a,(X23f3)	; připravit další ze sady tří
	inc a		; aditivních konstant
	and 3		; (proměnná na adrese 23F3h nabývá
	ld b,0		; pouze hodnot 1, 2 nebo 3)
	cp 1
	adc a,b
	ld (X23f3),a
	ld hl,X1860	; dle pořadí konstanty
	add a,a		; načíst její adresu
	add a,a
	ld c,a
	add hl,bc
	call X0e8d	; a tuto konstantu přičíst
; ***********************************************
; společná část RND pro kladný a záporný argument
; ***********************************************
X1416:	call X1113	; obsah FP akumulátoru uloží
			; do sekvence B:C:D:E
	ld a,e		; nyní se provedou bitové
	ld e,c		; manipulace, které je
	xor 4fh		; těžké (a zbytečné)
	ld c,a		; popisovat matematicky
	ld (hl),80h	; opět nějaké hardcore
	dec hl		; bitové manipulace nad
	ld b,(hl)		; vlastním FP akumulátorem
	ld (hl),80h	; (někdy méně znamená více)
	ld hl,X2177	; další prvek, vnášející
	inc (hl)		; nahodilost
	ld a,(hl)
	sub 0abh
	jp nz,X1432
	ld (hl),a
	inc c
	dec d
	inc e
X1432:	call X0eed	; provést normalizaci
			; čísla v B:C:D:E
			; (zde konečně dochází k
			; expanzi rozsahu 0.5 < n < 1
			; na rozsah 0 < n < 1)
	ld hl,X1860	; uložit nově vypočtené
	 jp X111f	; pseudonáhodné číslo
; **************************
; RND se záporným parametrem
; **************************
X143b:	ld (hl),a		; chyba! RND se záporným
	dec hl		; argumentem přepíše
	ld (hl),a		; poslední koeficient
	dec hl		; aproximačního polynomu
	ld (hl),a		; pro výpočet funkce EXP
	 jp X1416	; a tak pak hlásí přetečení!
; **********
; příkaz DEG
; **********
			; (1443h)
c_deg:	.db 0f6h	; ori 0afh - maskování XRA A
			; a uložení nenulové hodnoty
; **********
; příkaz RAD
; **********
			; (1444h)
c_rad:	xor a		; jen uložit atribut zvolené
	ld (v_dgrd),a	; obloukové míry
	ret
; **********
; funkce COS
; **********
			; (1449h)
f_cos:	ld hl,X1870	; konstantu 1.5708 (RAD)
	ld a,(v_dgrd)
	and a
	jp z,X1456	; nebo
	ld hl,X22fe	; konstantu 90° (DEG)
X1456:	call X0e8d	; přidat k argumentu funkce jako
			; fázový posun COS vůči SIN
; **********************************************************
; funkce SIN(x)
; **********************************************************
; k výpočtu se použije součet mocninné řady:
; SIN(x) = x-(x^3)/3!+(x^5)/5!-(x^7)/7!+(x^9)/9!
; upravené pro jednodušší aplikaci do tvaru:
; SIN(x) = x(1+x^2(-1/3!+x^2(1/5!+x^2(-1/7!+x^2(1/9!)))))
; argument je kvůli normalizaci dělen číslem 2PI, proto jed-
; notlivé koeficienty řady obsahují kumulativní mocniny 2PI
; **********************************************************
			; (1459h)
f_sin:	call pushfp	; uložit argument do zásobníku
	ld bc,8349h
	ld de,0fdbh	; podle zvolené obloukové míry se
	ld a,(v_dgrd)
	and a		; buď konstantou 360°    (DEG)
	jp z,X146f	;           nebo 6,28319 (RAD)
	ld bc,8934h
	ld de,0000h
X146f:	call fpbcde
	pop bc
	pop de		; obnovený argument funkce
	call X1021	; vydělí (360° resp. 2PI => 1.0)
	call pushfp	; odečteme celočíselné násobky 2PI
	call f_int	; čímž dosáhneme předpokládané
	pop bc		; periodicity 2PI
	pop de
	call X0e99
	ld hl,X1874	; pro -0,25 < argument < 0,25
	call X0e93	; (0..45°) je aproximace dostatečně
	rst 0x30; přesná
	scf
	jp p,X1492	; a tak jdeme hned na součet řady
	call X0e8a	; převod argumentu z rozsahu
	rst 0x30; 0,25 až 0,5 zrcadlově na rozsah
	and a		; 0 až 0,25
X1492:	push af	; kompenzace posunu 0,25 z testu
	call p,X10f0	; nicméně základní interval
	ld hl,X1874	; aproximace pro hodnoty
	call X0e8d	; -0,25 < argument < 0,25 zůstává..
	pop af
	call nc,X10f0
	ld hl,X1878	; se sadou koeficientů aproximační
			; řady jít na aproximaci funkce SIN
; **********************************************
; součet mocninné řady pouze lichých koeficientů
; **********************************************
			; (14a3h)
oaprox:	call pushfp	; každý člen řady vypočítat vydělený
	ld de,X0fc1	; vstupní hodnotou X a tímto X pak
	push de		; vynásobit výsledek (vytknutí X)
	push hl		; dále lze výpočet zjednodušit
	call X1113	; "zkvadratizováním" X - pak je
	call X0fc3	; řada počítána defacto jen pro
	pop hl		; každý druhý člen (zde pro liché)
; **********************************************
; obecný součet mocninné řady
; (všimněte si pořadí operací krát a plus, řada
; je sčítána ve tvaru s postupným vytýkáním X,
; což ovšem nic nemění na hodnotách koeficientů)
; **********************************************
			; (14b2h)
approx:	call pushfp	; argument uložit do zásobníku
	ld a,(hl)		; od adresy HL načíst postupně
	inc hl		; počet koeficientů a následně
			; samotné koeficienty
	call X1105	; do FP načíst první koeficient
	.db 06h		; mvi b,0f1h - maskování POP PSW
			; při výpočtu prvního člene řady
X14bb:	pop af		; obnovit počet zbývajících členů
	pop bc		; obnovit argument pro výpočet
	pop de		; do B:C:D:E
	dec a		; je celá řada sečtena?
	ret z		; pokud ano, pak konec
	push de		; jinak uložit argument pro výpočet
	push bc		; dalšího člene řady zpět
	push af	; a uložit počet zbývajících členů
	push hl		; průběžný výsledek vynásobit
	call X0fc3	; argumentem X (nebo taky X^2, že?)
	pop hl
	call X1116	; načíst další koeficient řady
	push hl
	call X0e9c	; a přičíst k průběžnému výsledku
	pop hl
	 jp X14bb	; běž na další člen řady
; **********
; funkce TAN
; **********
			; (14d3h)
f_tan:	call pushfp	; argument uložit pro výpočet COS
	call f_sin	; nyní vypočíst hodnotu SIN
	pop bc
	pop hl
	call pushfp	; výsledek funkce SIN uschovat
	ex de,hl
	call fpbcde	; FP nyní nese opět vstupní argument,
	call f_cos	; ze kterého vypočteme hodnotu COS
	 jp X101f	; a dle definice
			; TAN(x)=SIN(x)/COS(x) vydělíme..
; **********
; funkce ATN
; **********
			; (14e8h)
f_atn:	rst 0x30; funkce je lichá, takže pro záporné
			; argumenty připraví otočení
	call m,X134b	; znaménka výsledku a provede
	call m,X10f0	; otočení znaménka argumentu
	ld a,(fpaccum+3)	; pro čísla menší než 1
	cp 81h
	jp c,X1503	; provede výpočet přímo
	ld bc,8100h	; v ostatních případech vypočte
	ld d,c		; převrácenou hodnotu argumentu
	ld e,c
	call X1021
	ld hl,X0e93	; a připraví korekci výsledku ve
	push hl		; tvaru  (PI/2) - výsledek
X1503:	ld hl,X188d	; aproximaci mocninnou řadou
	call oaprox	; s lichými koeficienty
	ld hl,X1870	; adresa aditivní konstanty PI/2 pro
	ret		; případnou korekci výsledku při
			; argumentu >1
; ***********************************************
; kopírování řetězce podle jeho hlavičky, uložené
; v zásobníku pod návratovou adresou
; DE - cílová adresa pro uložení řetězce
; ***********************************************
			; (150dh)
X150d:	pop hl
	ex (sp),hl		; zpod návratové adresy
	ld a,(hl)		; vytáhnout adresu řetězcové
	inc hl		; proměnné (její hlavičky)
	inc hl		; a načíst:
	ld c,(hl)		;
	inc hl		; do reg. L - délku
	ld b,(hl)		; do reg. BC - adresu textu
	ld l,a		; (DE se dodá zvenku)
; ***********************************
; kopírování řetězce
; (délka L, z adresy BC na adresu DE)
; ***********************************
			; (1516h)
strcpy:	inc l
X1517:	dec l		; test zbývající délky přenosu
	ret z		; a konec při posledním znaku
	ld a,(bc)
	ld (de),a		; samotný přenos znaku
	inc bc
	inc de		; posun adres
	 jp X1517	; další znak
; *************************************************
; do HL uloží adresu 4b hlavičky řetězcové proměnné ???
; *************************************************
X1520:	call t_strg	; typová kontrola na řetězec
X1523:	ld hl,(fpaccum)	; do DE uloží adresu
X1526:	ex de,hl		; řetězcové proměnné
; ***************************************
; v DE vstupuje adresa řetězcové proměnné
; ***************************************
X1527:	call X153f	; BC <= adresa tmpstrg
	ex de,hl		; DE <= adresa zdrojové proměnné
	ret nz		; není to poslední proměnná
			; HL = původní hodnota DE
	push de		; 
	ld d,b
	ld e,c
	dec de
	ld c,(hl)
	ld hl,(strlast)
	rst 0x18
	jp nz,X153d
	ld b,a		; HL = HL + délka textu aktuálního
	add hl,bc		; řetězce
	ld (strlast),hl
X153d:	pop hl
	ret
; *****************************************************
; pomocná vyhledávací procedura pro řetězcové proměnné
; do BC načte odkaz na text aktuální řetězcové proměnné
; a posune se na předchozí proměnnou
; *****************************************************
X153f:	ld hl,(laststg)	; ???
	dec hl
	ld b,(hl)
	dec hl
	ld c,(hl)
	dec hl
	dec hl
	rst 0x18
	ret nz
	ld (laststg),hl
	ret
; **********
; funkce LEN
; **********
			; (154eh)
f_len:	ld bc,X0c4b	; funkci převodu reg. A na FP číslo
	push bc		; uložím do zásobníku
; ***************************************
; do HL nastaví adresu řetězcové proměnné
; a do A jeho délku
; ***************************************
			; (1552h)
getlen:	call X1520	; do HL uloží adresu proměnné
			; z 0. a 1. bajtu FP akumulátoru
	xor a
	ld d,a
	ld (vartype),a	; výsledkem funkce je typ číslo
	ld a,(hl)		; načíst délku řetězce
	and a		; a test s ovlivněním příznaků CPU
	ret		; návrat nebo přepočet A >> FP
; **********
; funkce ASC
; **********
f_asc:	ld bc,X0c4b	; funkci převodu hodnoty z reg. A
	push bc		; na FP číslo uložím do zásobníku
	call getlen	; do HL načtu adresu zadané proměnné
	jp z,X0569	; chyba 03h - Fnc.param.
			; (nulová délka řetězce)
	inc hl
	inc hl		; třetí a čtvrtý bajt řetězcové
	ld e,(hl)		; proměnné nese adresu uložení
	inc hl		; vlastního textu
	ld d,(hl)
	ld a,(de)		; první bajt textu (jeho hodnotu)
	ret		; uložím do reg. A a převedu na FP
; ***********
; funkce CHR$
; ***********
			; (156eh)
f_chr:	ld a,1		; pro délku 1 bajt
	call X0ce7	; vytvořit řetězcovou proměnnou
	call tst255	; test argumentu na rozsah 0..255
	ld hl,(tmpvar+2)	; načíst adresu vytvořené řetězcové proměnné
	ld (hl),e		; a zapsat ten znak, přetypovaný
			; z typu int256 na typ char
X157a:	pop bc
	 jp X0d18	; zkopírovat 4bajtovou hlavičku
			; proměnné z tmpvar do laststg
			; a ukazatel do FP akumulátoru
; ************
; funkce LEFT$
; ************
			; (157eh)
f_left:	call X1600	; do reg. B načíst číselný parametr
			; a vynutit si pravou závorku
	xor a		; výběr začne "prvním" znakem
			; v reg. A je první znak výběru
X1582:	ex (sp),hl		; HL = ukazatel na zdrojový řetězec
			; (jeho hlavičku)
			; BASIC programu schovám do STACKu)
	ld c,a		; C = první znak výběru
X1584:	push hl		; (vstup od MID$)
	ld a,(hl)		; načíst délku řetězce
	cp b		; porovnat s požadovanou délkou
	jp c,X158c	; překračuje-li délka výběru délku
			; zdrojového řetězce, přenést celý
			; zdrojový řetězec
	ld a,b		; jinak přenést požadovanou délku
X158b:	.db 11h		; (..lxi d,000eh) a nenulovat reg. C
X158c:	ld c,0		; při nedostatku znaků u RIGHT začít
			; paušálně od "prvního" znaku
	push bc		; C = první znak výběru z řetězce
	call txaloc	; alokace paměti délky A
			; (v DE se vrátí adresa)
	pop bc		; obnovit meze výběru
	pop hl		; obnovit adresu hlavičky proměnné
	push hl		; z hlavičky proměnné přečtu do
	inc hl		; HL adresu začátku řetězce
	inc hl
	ld b,(hl)		; sice se nám zde ztratí informace
	inc hl		; o délce výběru (reg. B) ale tu
	ld h,(hl)		; délku zjistíme z délky alokované
	ld l,b		; paměti pro cílový řetězec (reg. A)
	ld b,0		; v reg. C nám zůstala pozice
	add hl,bc		; prvního znaku výběru ze zdrojového
	ld b,h		; řetězce a tak adresu začátku
	ld c,l		; vypočteme do HL=BC
	call X0cea	; dle délky a adresy vybraného
			; textu nastavit hlavičku pomocné
			; proměnné na adrese tmpvar
	ld l,a		; vybraný text se zkopíruje do nově
	call strcpy	; alokovaného místa
	pop de		; do DE obnovit adresu hlavičky
			; zdrojové proměnné
	call X1527	; ???
	 jp X0d18	; zkopírovat 4bajtovou hlavičku
			; proměnné z tmpvar do laststg
			; a ukazatel do FP akumulátoru
; *************
; funkce RIGHT$
; *************
			; (15aeh)
f_rajt:	call X1600	; do reg. B načíst číselný parametr
			; a vynutit si pravou závorku
	pop de		; obnovit do DE ukazatel
	push de		; na zdrojový řetězec
	ld a,(de)		; a načíst jeho délku
	sub b		; odečíst požadovaný počet znaků
	 jp X1582	; zprava a dále už je to stejné
			; pro LEFT$ / MID$ / RIGHT$
; ***********
; funkce MID$
; ***********
f_mid:	ex de,hl		; (15b8h)
	ld a,(hl)
	call X1603	; načíst adresu proměnné a první
	push bc		; dva parametry
	ld e,255	; default třetí parametr
	cp ')'		; je 3. parametr uveden explicitně?
	jp z,X15c8	; => NE
	rst 0x08; pokud ano, pak vynutit
	.db ','		; oddělovací čárku a načíst
	rst 0x20; třetí parametr
X15c8:	rst 0x08; teď už musí přijít pravá závorka
	.db ')'
	pop af		; v reg. A je první znak výběru
	ex (sp),hl
	ld bc,X1584	; připravit se na přechod ke kopí-
	push bc		; rování výběru
	dec a		; pozici 1. znaku odpovídá adresa 0
	cp (hl)		; test dostatečné délky zdrojového
			; řetězce
	ld b,0		; pokud není dost znaků,
	ret nc		; kopíruju vše od prvního znaku
			; je-li dost znaků,
	ld c,a		; pak C = první znak
	ld a,(hl)		; je od něj doprava dost znaků?
	sub c
	cp e		; pokud chybí v řetězci znaky, vzít
	ld b,a		; od prvního znaku výběru doprava
	ret c		; všechny další znaky
	ld b,e		; jinak použít tolik znaků, kolik
	ret		; předepisuje 3. parametr
; **********
; funkce VAL
; **********
			; (15ddh)
f_val:	call getlen	; načíst délku řetězce argumentu
	jp z,fpzero	; je-li nulová, pak je výsledek nula
	ld e,a		; E = délka řetězce
	inc hl		; v HL vstupuje odkaz na proměnnou
	inc hl
	ld a,(hl)
	inc hl
	ld h,(hl)		; z té proměnné načteme adresu
	ld l,a		; vlastního textu do HL
	push hl		; a tu uschováme do zásobníku
	add hl,de		; posunout se na konec řetězce
	ld b,(hl)		; načíst znakovou zarážku (uvozovky)
	ld (hl),d		; místo ní vložit nulu
	ex (sp),hl		; uschovat adresu změněné zarážky
			; a obnovit adresu začátku řetězce
	push bc		; uschovat původní zarážku
	call X023d	; řetězec do buferu c_odloz
	inc hl		; ukazatel na začátek buferu c_odloz
	call numpar	; do FP akumulátoru vyhodnotit
			; hodnotu číselného výrazu
	ld a,(hl)		; řetězec musí jít vyhodnotit celý
	and a		; (musí následovat koncová nula)
	jp nz,err_09	; jinak chyba 09h - Syntax err.
	pop bc		; obnovit zarážku
	pop hl		; a adresu její změny
	ld (hl),b		; vrátit původní zarážku zpět
	ret		; a konec
; *************************
; podpora LEFT$/RIGHT$/MID$
; *************************
			; (1600h)
X1600:	ex de,hl
	rst 0x08; vynutit ukončující závorku
	.db ')'
X1603:	pop bc
	pop de		; DE = hodnota prvního parametru po stringu
	push bc
	ld b,e
	inc b
	dec b
	ret nz		; při nulové pozici výběru vyvolat
	 jp X0569	; chybu 03h - Fnc.param.
; **********
; funkce INP
; **********
			; (160dh)
f_inp:	call tst255	; parametr, který si funkce sebou
	ld (X1613+1),a	; nese ve FP akumulátoru otestovat
X1613:	in a,(0)		; na 8-bitový rozsah a použít jako
	 jp X0c4b	; adresu portu. Načtený bajt z portu
			; převést na FP číslo.
; **********
; příkaz OUT
; **********
			; (1618h)
c_out:	call X161e	; Načíst adresu portu a hodnotu
X161b:	out (0),a		; a tuto hodnotu poslat na port.
	ret		; Nothing else matters..
; ****************************************
; příkaz OUT/WAIT - načte adresu periferie
; ****************************************
			; (161eh)
X161e:	rst 0x20; načte SHORT INTEGER
	ld (X198d+1),a	; uloží adresu portu pro WAIT
	ld (X161b+1),a	; uloží adresu portu pro OUT
	rst 0x08; vynutit
	.db ','		; oddělovací čárku
; **********************
; GET SHORT INT (0..255)
; **********************
			; (1627h)
X1627:	call numpar	; vyčíslení FP výrazu..
; ********************************************
; test hodnoty FP akumulátoru na rozsah 0..255
; ********************************************
			; (162ah)
tst255:	call tstpin	; povolit jen kladná čísla
	ld a,d		; a povolit pouze rozsah
	and a		; 0..255, jinak se zobrazí
	jp nz,X0569	; chybové hlášení 03 Fnc.param.
	dec hl
	rst 0x10
	ld a,e		; v ACC se vrací načtená hodnota
	ret
; ***********
; funkce PEEK
; ***********
			; (1636h)
f_peek:	call tstint	; test argumentu (adresy) na rozsah
	ld a,(de)		; z této adresy přečtu bajt,
	 jp X0c4b	; který převedu na FP číslo
; ************
; funkce APEEK
; ************
			; (163dh)
X163d:	push bc
	rst 0x10; přeskočit mezery, načíst argument
	call X09a2	; (adresu) povinně v závorkách
	call tstint	; otestovat rozsah -32768..32767
	ld a,(de)		; načíst nižší byte
	ld c,a
	inc de		; o adresu výše
	ld a,(de)		; načíst vyšší bajt
	pop de
X164a:	push hl		; a než provedu závěrečnou typovou
	ld hl,X09b4	; kontrolu výsledku,
	push hl
	 jp ac2fp	; převedu hodnotu v A:C na FP číslo
; ***************************************************
; načtení hexadecimálního čísla s prefixem (apostrof)
; ***************************************************
			; (1652h)
X1652:	ex de,hl		; BIOS využívá ke čtení řádku DE
	ld b,1		; bude minimálně jeden platný znak
	ld hl,0		; vynulovat akumulátor výsledku
X1658:	inc de		; další znak v analyzovaném řádku
	ld a,(de)		; načíst a otestovat, zda je
	call hex	; platným hexadecimálním znakem
	jp c,X1671	; pokud není, rozhodne se dále
	ld c,a		; platný znak (převedený na hodnotu
	ld b,0		; 0..15) uložit do BC
	ld a,h
	and 0f0h	; pokud už je hodnota akumulátoru
	jp nz,X0f3e	; příliš vysoká, 
			; vyvolat chybu 08h - Overflow
	add hl,hl
	add hl,hl		; jinak posunout akumulátor o čtyři
	add hl,hl		; bity (jedna cifra) vlevo a přičíst
	add hl,hl		; k němu nově načtený znak v BC
	add hl,bc
	 jp X1658	; a načíst další znak z řádku
; *******************************************************
; při načítání hexadecimálního čísla přišel neplatný znak
; *******************************************************
			; (1671h)
X1671:	ld a,b		; pokud počet načtených platných
	and a		; znaků je nulový, vyvolat
	jp nz,err_09	; chybu 09h - Syntax err
	ex de,hl		; jinak obnovit ukazatel znaků
	dec hl		; v řádku, platný pro BASIC
	rst 0x10; a přeskočit mezery
	 jp X231f	; výsledek v DE převést na FP číslo
; ******************************
; Dokončení testu FP akumulátoru
; ******************************
			; (167ch)
X167c:	call X1688	; vypočtu (pouze) příznak parity a
	ret nz		; při záporném FP akumulátoru konec
	inc a		; upravit výsledek SGN() na +1
	 jp X1688	; a nastavit (pouze) příznak parity
			;
			; celá tato kaskáda funkcí od RST6
			; sem nastavuje kromě příznakových
			; bitů také hodnotu reg. A takto:
			; A =   0  =>  nulová hodnota FP
			; A =  +1  =>  kladná hodnota FP
			; A =  -1  =>  záporná hodnota FP
; **********************
; typová kontrola výrazu
; **********************
			; (1684h)
X1684:	ld a,(vartype)	; tato procedura nastaví příznak
	adc a,a		; parity na hodnotu 1 (skok při JPE)
X1688:	push hl		; pokud je typ vyhodnoceného výrazu
	push af	; shodný s typem, který specifikuji
	pop hl		; v dodané hodnotě příznakového bitu
	and a		; CY: 0 => požaduji číselný výraz
	ld a,l		;     1 => požaduji řetězcový výraz
	jp pe,X1695
	and 0fbh
	 jp X1697
X1695:	or 4		; celá tahle sekvence dělá to samé
X1697:	ld l,a		; co instrukce "ANA A" jen s tím
	push hl		; rozdílem, že ovlivňuje pouze
	pop af		; příznak parity P
	pop hl
	ret
; *******************************************
; Tisk chybového hlášení do dialogového řádku
; *******************************************
			; (169ch)
X169c:	ld d,0		; vstup v reg. E
	dec de
	ex de,hl
	ld b,h
	ld c,l
	add hl,hl
	add hl,hl
	add hl,bc
	add hl,hl		; hl = 10 x reg.E
	ld de,X1711	; začátek tabulky chybových hlášení
	add hl,de
	ld de,X16f3
	ex de,hl
	ld c,0ah	; délka všech hlášení je 10 znaků
X16b0:	ld a,(de)		; chybové hlášení nakopírovat
	ld (hl),a		; do stringu od adresy 16ech
	inc hl
	inc de
	dec c
	jp nz,X16b0
	ld hl,X0324	; tisknout se bude nejprve do buferu
	ld (cout+1),hl
	ld hl,X16ec
	call tx2edi
	ld hl,(crntln)	; pokud je v režimu PROGRAM
	ld a,h
	and l
	inc a
	call nz,X1263	; přidat "at line xxx"
	ld hl,X1708
	 jp tx2edi	; jinak zakončit chybové hlášení
; **********
; funkce USR
; **********
			; (16d3h)
f_usr:	call tstint	; načíst parametr příkazu, což je
	push hl		; adresa programu ve strojovém kódu
	push de
	push bc
	ex de,hl
	ld (X16dd+1),hl	; tuto adresu uložit do následující
X16dd:	call 0ffffh	; instrukce CALL
	pop bc
	pop de
	pop hl
	 jp X0c4b	; výsledek v A převést na FP číslo
; ************************************************
; příkaz _ (alternativa DISP s čekáním na klávesu)
; ************************************************
			; (16e6h)
c___:	call c_disp	; zavolat samotný kód příkazu DISP
	 jp inklav	; a počkat na stisk nějaké klávesy
; *****************************************
; jednotlivé části chybových hlášení BASICu
; *****************************************
X16ec:	.db " + + + "
X16f3:	.db 0,0,0,0,0,0,0,0,0,0
X16fd:	.db " ",0
X16ff:	.db "at line ",0h
X1708:	.db " + + +",0dh,0ah,0h
X1711:	.db "Subscr.rng"	; 01h
X171b:	.db "Arr.alloc."	; 02h
X1725:	.db "Fnc.param."	; 03h
X172f:	.db "Only in pg"	; 04h
X1739:	.db "No for stm"	; 05h
X1743:	.db "Data exhau"	; 06h
X174d:	.db "Pg too big"	; 07h
X1757:	.db "Overflow ",0	; 08h
X1761:	.db "Syntax err"	; 09h
X176b:	.db "Return err"	; 0ah
X1775:	.db "Numb.nonex"	; 0bh
X177f:	.db "Dv by zero"	; 0ch
X1789:	.db "Can't cont"	; 0dh
X1793:	.db "Strng long"	; 0eh
X179d:	.db "No str.spc"	; 0fh
X17a7:	.db "Str.algrth"	; 10h
X17b1:	.db "Type conv."	; 11h
X17bb:	.db "File small"	; 12h
X17c5:	.db "Input err "	; 13h
X17cf:	.db "Field lost"	; 14h
X17d9:	.db "File bound"	; 15h
X17e3:	.db "Stop ",0,0,0,0,0	; 16h
X17ed:	.db "File error"	; 17h
; ************
; FP konstanta
; ************
				; (17f7h)
X17f7:	.db 000h,000h,000h,081h	; +1.0
; ****************************************************
; aproximační data funkce N x LOG2(X)
; (dvojkový logaritmus včetně transformační konstanty)
; ****************************************************
			; (17fbh)
X17fb:	.db 003h	; 3 koeficienty řady
	.db 0aah,056h,019h,080h	; 1/5 x 2.88539 = 0.598979
	.db 0f1h,022h,076h,080h	; 1/3 x 2.88539 = 0.961471
	.db 045h,0aah,038h,082h	; 1/1 x 2.88539 = 2.88539
; ************
; FP konstanta
; ************
				; (1808h)
X1808:	.db 000h,000h,000h,080h	; +0.5
; *******************
; FP mocniny čísla 10
; *******************
				; (180ch)
tb10ex:	.db 0a0h,086h,001h	; 100.000
	.db 010h,027h,000h	;  10.000
	.db 0e8h,003h,000h	;   1.000
	.db 064h,000h,000h	;     100
	.db 00ah,000h,000h	;      10
	.db 001h,000h,000h	;       1
; ***************************
; aproximační data funkce EXP
; ***************************
			; (181eh)
X181e:	.db 08h		; 8 koeficientů mocninné řady
			; (ty první se dosti liší ale
			; postupně se přesnost zvyšuje)
	.db 040h,02eh,094h,074h	; -1/7!
	.db 070h,04fh,02eh,077h	; +1/6!
	.db 06eh,002h,088h,07ah	; -1/5!
	.db 0e6h,0a0h,02ah,07ch	; +1/4!
	.db 050h,0aah,0aah,07eh	; -1/3!
	.db 0ffh,0ffh,07fh,07fh	; +1/2!
	.db 000h,000h,080h,081h	; -1/1!
	.db 000h,000h,000h,081h	; +1/0!
; ********************************************
; ukazatel pro výběr multiplikativní konstanty
; ********************************************
			; (183fh)
X183f:	.db 000h	; výběrový ukazatel 0..7 na jednu
			; z následujících konstant
; ********************************************************
; multiplikativní konstanty pro výpočet hodnoty funkce RND
; ********************************************************
			; (1840h)
X1840:	.db 035h,04ah,0cah,099h
X1844:	.db 039h,01ch,076h,098h
X1848:	.db 022h,095h,0b3h,098h
X184c:	.db 00ah,0ddh,047h,098h
X1850:	.db 053h,0d1h,099h,099h
X1854:	.db 00ah,01ah,09fh,098h
X1858:	.db 065h,0bch,0cdh,098h
X185c:	.db 0d6h,077h,03eh,098h
; ******************************
; poslední vypočtená hodnota RND
; ******************************
			; (1860h)
X1860:	.db 052h,0c7h,04fh,080h	
; *************************************************
; aditivní konstanty pro výpočet hodnoty funkce RND
; *************************************************
X1864:	.db 068h,0b1h,046h,068h
X1868:	.db 099h,0e9h,092h,069h
X186c:	.db 010h,0d1h,075h,068h
; ************************************
; převodní FP konstanta stupně/radiány
; ************************************
				; (1870h)
X1870:	.db 0dbh,00fh,049h,081h	; +1.5708
; ************************************
; konstanta pro výpočet funkcí SIN/COS
; ************************************
				; (1874h)
X1874:	.db 000h,000h,000h,07fh	; +0.25
; ****************************************************
; koeficienty mocninné (Taylorovy) řady pro aproximaci
; funkcí SIN/COS (přes Hornerovo schéma)
; ****************************************************
			; (1878h)
X1878:	.db 05h			; počet koeficientů
	.db 0bah,0d7h,01eh,086h	; +1/9! x (2PI)^9 = +39.7107
	.db 064h,026h,099h,087h	; -1/7! x (2PI)^7 = -76.575
	.db 058h,034h,023h,087h	; +1/5! x (2PI)^5 = +81.6022
	.db 0e0h,05dh,0a5h,086h	; -1/3! x (2PI)^3 = -41.3417
	.db 0dah,00fh,049h,083h	; +1/1! x (2PI)^1 = +6.28319
; *****************************************************
; koeficienty mocninné řady pro aproximaci funkce ATN
; (koeficienty se postupně odchylují od Taylorovy řady)
; *****************************************************
			; (188dh)
X188d:	.db 9			; počet koeficientů
	.db 04ah,0d7h,03bh,078h	; +0.00286623 <> +1/17
	.db 002h,06eh,084h,07bh	; -0.0161657  <> -1/15
	.db 0feh,0c1h,02fh,07ch	; +0.0429096  <> +1/13
	.db 074h,031h,09ah,07dh	; -0.752896   <> -1/11
	.db 084h,03dh,05ah,07dh	; +1.06563    ~  +1/9
	.db 0c8h,07fh,091h,07eh	; -0.142089   ~  -1/7
	.db 0e4h,0bbh,04ch,07eh	; +0.199936   ~  +1/5
	.db 06ch,0aah,0aah,07fh	; -0.333331   ~  -1/3
	.db 000h,000h,000h,081h	; +1.00000    =  +1/1
; ********************************
; titulní nadpis při startu BASICu
; ********************************
			; (18b2h)
t_init: .db 1ch,"BASIC-G /V2.A",0dh,0
; ****************************************
; vektory pro interpretaci unárních funkcí
; ****************************************
			; (18c2h)
tb_fnc:	.dw f_sgn	; SGN
	.dw f_int	; INT
	.dw f_abs	; ABS
	.dw f_usr	; USR
	.dw f_fre	; FRE
	.dw f_inp	; INP
	.dw f_pos	; POS
	.dw f_sqr	; SQR
	.dw f_rnd	; RND
	.dw f_log	; LOG
	.dw f_exp	; EXP
	.dw f_cos	; COS
	.dw f_sin	; SIN
	.dw f_tan	; TAN
	.dw f_atn	; ATN
	.dw f_peek	; PEEK
	.dw f_len	; LEN
	.dw f_str	; STR$
	.dw f_val	; VAL
	.dw f_asc	; ASC
	.dw f_chr	; CHR$
	.dw f_left	; LEFT$
	.dw f_rajt	; RIGHT$
	.dw f_mid	; MID$
; ********************************
; Vektory pro interpretaci příkazů
; ********************************
			; (18f2h)
tb_cmd:	.dw c_end	; 80h END
	.dw c_for	; 81h FOR
	.dw c_next	; 82h NEXT
	.dw c_data	; 83h DATA
	.dw c_inpt	; 84h INPUT
	.dw c_dim	; 85h DIM
	.dw c_read	; 86h READ
	.dw c_let	; 87h LET
	.dw c_goto	; 88h GOTO
	.dw c_run	; 89h RUN
	.dw c_if	; 8ah IF
	.dw c_rstr	; 8bh RESTORE
	.dw c_gosb	; 8ch GOSUB
	.dw c_retr	; 8dh RETURN
	.dw c_rem	; 8eh REM
	.dw c_stop	; 8fh STOP
	.dw err_09	; 90h BIT    (vektor na Syntax err)
	.dw c_on	; 91h ON
	.dw c_null	; 92h NULL
	.dw c_wait	; 93h WAIT
	.dw c_def	; 94h DEF
	.dw c_poke	; 95h POKE
	.dw c_prnt	; 96h PRINT
	.dw err_09	; 97h ERR    (vektor na Syntax err)
	.dw c_list	; 98h LIST
	.dw c_clea	; 99h CLEAR
	.dw c_llst	; 9ah LLIST
	.dw c_rad	; 9bh RAD
	.dw c_new	; 9ch NEW
	.dw c_scal	; c6h SCALE
	.dw c_plot	; c7h PLOT
	.dw c_move	; c8h MOVE
	.dw c_beep	; c9h BEEP
	.dw c_axes	; cah AXES
	.dw c_gclr	; cbh GCLEAR
	.dw c_paus	; cch PAUSE
	.dw c_disp	; cdh DISP
	.dw c___	; ceh _
	.dw c_bmov	; cfh BMOVE
	.dw c_bplo	; d0h BPLOT
	.dw c_load	; d1h LOAD
	.dw c_save	; d2h SAVE
	.dw c_dloa	; d3h DLOAD
	.dw c_dsav	; d4h DSAVE
	.dw c_labl	; d5h LABEL
	.dw c_fill	; d6h FILL
	.dw c_auto	; d7h AUTO
	.dw c_otpt	; d8h OUTPUT
	.dw err_09	; d9h STATUS (vektor na Syntax err)
	.dw c_entr	; dah ENTER
	.dw c_ctrl	; dbh CONTROL
	.dw c_chck	; dch CHECK
	.dw c_cont	; ddh CONT
	.dw c_out	; deh OUT
	.dw err_09	; dfh INKEY  (vektor na Syntax err)
	.dw c_code	; e0h CODE
	.dw c_rom	; e1h ROM
	.dw c_apok	; e2h APOKE
	.dw c_pen	; e3h PEN
	.dw err_09	; e4h INK    (vektor na Syntax err)
	.dw err_09	; e5h APEEK  (vektor na Syntax err)
	.dw err_09	; e6h ADR    (vektor na Syntax err)
	.dw err_09	; e7h AT     (vektor na Syntax err)
	.dw err_09	; e8h HEX$   (vektor na Syntax err)
	.dw c_deg	; e9h DEG
	.db 0ffh,0ffh,0ffh,0ffh,0ffh
	.db 0ffh,0ffh,0ffh,0ffh,0ffh
; ********************************
; příkaz WAIT port,[maska,]hodnota
; ********************************
			; (197eh)
c_wait:	call X161e	; načíst číslo portu a komparační
	push af	; hodnotu
	ld e,0		; default maskovací parametr
	dec hl
	rst 0x10
	jp z,X198c	; dva nebo tři parametry?
	rst 0x08; když tři,
	.db ','		; tak vynutit znak čárka
	rst 0x20; a přečíst maskovací  parametr
X198c:	pop bc
X198d:	in a,(0)		; načíst data z portu
	xor e		; maskovací parametr
	and b		; komparační hodnota
	jp z,X198d	; čekání na shodu
	ret
; *************************************************
; Tabulka klíčových slov a jejich překladových kódů
; *************************************************
				; (1995h)
tb_tok:	.db 'E'+80h,"ND"	; 80h END
	.db 'F'+80h,"OR"	; 81h FOR
	.db 'N'+80h,"EXT"	; 82h NEXT
	.db 'D'+80h,"ATA"	; 83h DATA
	.db 'I'+80h,"NPUT"	; 84h INPUT
	.db 'D'+80h,"IM"	; 85h DIM
	.db 'R'+80h,"EAD"	; 86h READ
	.db 'L'+80h,"ET"	; 87h LET
	.db 'G'+80h,"OTO"	; 88h GOTO
	.db 'R'+80h,"UN"	; 89h RUN
	.db 'I'+80h,"F"		; 8ah IF
	.db 'R'+80h,"ESTORE"	; 8bh RESTORE
	.db 'G'+80h,"OSUB"	; 8ch GOSUB
	.db 'R'+80h,"ETURN"	; 8dh RETURN
	.db 'R'+80h,"EM"	; 8eh REM
	.db 'S'+80h,"TOP"	; 8fh STOP
	.db 'B'+80h,"IT"	; 90h BIT
	.db 'O'+80h,"N"		; 91h ON
	.db 'N'+80h,"ULL"	; 92h NULL
	.db 'W'+80h,"AIT"	; 93h WAIT
	.db 'D'+80h,"EF"	; 94h DEF
	.db 'P'+80h,"OKE"	; 95h POKE
	.db 'P'+80h,"RINT"	; 96h PRINT
	.db 'E'+80h,"RR"	; 97h ERR
	.db 'L'+80h,"IST"	; 98h LIST
	.db 'C'+80h,"LEAR"	; 99h CLEAR
	.db 'L'+80h,"LIST"	; 9ah LLIST
	.db 'R'+80h,"AD"	; 9bh RAD
	.db 'N'+80h,"EW"	; 9ch NEW
	.db 'T'+80h,"AB("	; 9dh TAB(
	.db 'T'+80h,"O"		; 9eh TO
	.db 'F'+80h,"NC"	; 9fh FNC
	.db 'S'+80h,"PC("	; a0h SPC(
	.db 'T'+80h,"HEN"	; a1h THEN
	.db 'N'+80h,"OT"	; a2h NOT
	.db 'S'+80h,"TEP"	; a3h STEP
	.db '+'+80h		; a4h +
	.db '-'+80h		; a5h -
	.db '*'+80h		; a6h *
	.db '/'+80h		; a7h /
	.db '^'+80h		; a8h ^
	.db 'A'+80h,"ND"	; a9h AND
	.db 'O'+80h,"R"		; aah OR
	.db '>'+80h		; abh >
	.db '='+80h		; ach =
	.db '<'+80h		; adh <
	.db 'S'+80h,"GN"	; aeh SGN
	.db 'I'+80h,"NT"	; afh INT
	.db 'A'+80h,"BS"	; b0h ABS
	.db 'U'+80h,"SR"	; b1h USR
	.db 'F'+80h,"RE"	; b2h FRE
	.db 'I'+80h,"NP"	; b3h INP
	.db 'P'+80h,"OS"	; b4h POS
	.db 'S'+80h,"QR"	; b5h SQR
	.db 'R'+80h,"ND"	; b6h RND
	.db 'L'+80h,"OG"	; b7h LOG
	.db 'E'+80h,"XP"	; b8h EXP
	.db 'C'+80h,"OS"	; b9h COS
	.db 'S'+80h,"IN"	; bah SIN
	.db 'T'+80h,"AN"	; bbh TAN
	.db 'A'+80h,"TN"	; bch ATN
	.db 'P'+80h,"EEK"	; bdh PEEK
	.db 'L'+80h,"EN"	; beh LEN
	.db 'S'+80h,"TR$"	; bfh STR$
	.db 'V'+80h,"AL"	; c0h VAL
	.db 'A'+80h,"SC"	; c1h ASC
	.db 'C'+80h,"HR$"	; c2h CHR$
	.db 'L'+80h,"EFT$"	; c3h LEFT$
	.db 'R'+80h,"IGHT$"	; c4h RIGHT$
	.db 'M'+80h,"ID$"	; c5h MID$
	.db 'S'+80h,"CALE"	; c6h SCALE
	.db 'P'+80h,"LOT"	; c7h PLOT
	.db 'M'+80h,"OVE"	; c8h MOVE
	.db 'B'+80h,"EEP"	; c9h BEEP
	.db 'A'+80h,"XES"	; cah AXES
	.db 'G'+80h,"CLEAR"	; cbh GCLEAR
	.db 'P'+80h,"AUSE"	; cch PAUSE
	.db 'D'+80h,"ISP"	; cdh DISP
	.db '_'+80h		; ceh _
	.db 'B'+80h,"MOVE"	; cfh BMOVE
	.db 'B'+80h,"PLOT"	; d0h BPLOT
	.db 'L'+80h,"OAD"	; d1h LOAD
	.db 'S'+80h,"AVE"	; d2h SAVE
	.db 'D'+80h,"LOAD"	; d3h DLOAD
	.db 'D'+80h,"SAVE"	; d4h DSAVE
	.db 'L'+80h,"ABEL"	; d5h LABEL
	.db 'F'+80h,"ILL"	; d6h FILL
	.db 'A'+80h,"UTO"	; d7h AUTO
	.db 'O'+80h,"UTPUT"	; d8h OUTPUT
	.db 'S'+80h,"TATUS"	; d9h STATUS
	.db 'E'+80h,"NTER"	; dah ENTER
	.db 'C'+80h,"ONTROL"	; dbh CONTROL
	.db 'C'+80h,"HECK"	; dch CHECK
	.db 'C'+80h,"ONT"	; ddh CONT
	.db 'O'+80h,"UT"	; deh OUT
	.db 'I'+80h,"NKEY"	; dfh INKEY
	.db 'C'+80h,"ODE"	; e0h CODE
	.db 'R'+80h,"OM"	; e1h ROM
	.db 'A'+80h,"POKE"	; e2h APOKE
	.db 'P'+80h,"EN"	; e3h PEN
	.db 'I'+80h,"NK("	; e4h INK(
	.db 'A'+80h,"PEEK"	; e5h APEEK
	.db 'A'+80h,"DR"	; e6h ADR
	.db 'A'+80h,"T"		; e7h AT
	.db 'H'+80h,"EX$"	; e8h HEX$
	.db 'D'+80h,"EG"	; e9h DEG
	.db 080h		; zarážka posledního slova
	.ds.b 17,0FFh		; rezerva
; ***********
; funkce HEX$
; ***********
			; (1b27h)
f_hex:	push bc
	rst 0x10
	call X09a2	; vyčíslit číselný argument
	call tstint	; a jeho test na rozsah
			; -32768..32767
	ex (sp),hl
	ld hl,X09b4	; na závěr bude typová kontrola
	push hl		; (na číselný typ)
	ld hl,fpprtbf	; předtím ovšem převod na string
	push hl
	ld a,d
	call prevo2	; převedeme vyšší bajt hodnoty
	inc hl
	call prevo2-1	; pak nižší bajt
	inc hl
	ld (hl),0		; a koncová zarážka stringu
	pop hl
	 jp X0cc8	; vzniklý string přiřadím cílové
			; proměnné (až pak následuje zmíněná
			; typová kontrola argumentu)
; **********************************************************
; zde se simuluje zdrojový kód BASICu, když se přepočítávají
; interní grafické proměnné (bože, možná to je cesta ale..)
; **********************************************************
			; (1b47h)
; následující zápis je komprimovaný kód: @6=255/(@4-@2) EOL
;                                        @7=242/(@3-@5) EOL
;                                        @0=-@2*@6      EOL
;                                        @1=-@5*@7      EOL
;                                   (@X=)@0+@6*@X       EOL
;                                   (@Y=)@1+@7*@Y       EOL
X1b47:	.db "@6",0ach,"255",0a7h,"(@4",0a5h,"@2)",0
X1b56:	.db "@7",0ach,"242",0a7h,"(@3",0a5h,"@5)",0
X1b65:	.db "@0",0ach,0a5h,"@2",0a6h,"@6",0
X1b6f:	.db "@1",0ach,0a5h,"@5",0a6h,"@7",0
X1b79:	.db "@0",0a4h,"@6",0a6h
X1b7f:	.db "@X",0			; (velké X)
X1b82:	.db "@1",0a4h,"@7",0a6h
X1b88:	.db "@Y",0			; (velké Y)
; **********************************************************
; názvy fiktivních proměnných grafického subsystému @2..@5
; (u verze 1 se používaly zakázané proměnné X0..X2 a Y0..Y3)
; **********************************************************
			; (1b8bh)
X1b8b:	.db "@2",0	; tento zápis napodobuje zdrojový
	.db "@4",0	; text BASICu kvůli zjednodušení
	.db "@3",0	; přiřazení hodnot
	.db "@5",0
; ************
; příkaz SCALE
; ************
			; (1b97h)
c_scal:	ld de,X1b8b	; seznam proměnných, které budu
	ld c,3		; načítat budou 3 v cyklu a pak
X1b9c:	push de		; ještě jedna
	push bc
	push hl
	ex de,hl
	call varadr	; vždy přečíst ze seznamu název
	pop hl		; proměnné, pak načíst hodnotu
	call X0619	; ze seznamu parametrů příkazu SCALE
	rst 0x08; a tuto hodnotu přiřadit proměnné
	.db ','		; ..vynutit oddělovací čárku
	pop bc
	pop de
	inc de
	inc de
	inc de
	dec c
	jp nz,X1b9c
	push hl
	ex de,hl
	call varadr	; a dost nechutně to udělat
	pop hl		; pro čtvrtou proměnnou
	call X0619	; a čtvrtý parametr
	push hl
	ld hl,X1b47	; fiktivní BASIC kód do procedury
	call c_let	; vyhodnocení hodnoty proměnné @6
	ld hl,X1b56	; fiktivní BASIC kód do procedury
	call c_let	; vyhodnocení hodnoty proměnné @7
	ld hl,X1b65	; fiktivní BASIC kód do procedury
	call c_let	; vyhodnocení hodnoty proměnné @0
	ld hl,X1b6f	; fiktivní BASIC kód do procedury
	call c_let	; vyhodnocení hodnoty proměnné @1
	pop hl
	ret
; **********************************************************
; pomocná procedura grafických příkazů - přepočet jedné
; souřadnice dle zvoleného měřítka SCALE pomocí simulovaných
; výrazů (adresy výrazů se dodají v registrech BC a DE)
; **********************************************************
			; (1bd6h)
X1bd6:	push bc		;
	push hl		; 
	ex de,hl		; na adrese DE si přečte jméno
	call varadr	; interní proměnné za příkazem
	pop hl		; vyčíslí hodnotu výrazu a přiřadí
	call X0619	; uvedené interní proměnné, poté
	ex (sp),hl		; provede přepočítávací výraz ve
	call numpar	; fiktivním kódu BASICu od adresy BC
	call tstint	; ořeže na rozsah -32768 .. 32767
	ld a,d		;
	or a		;
	call nz,X1c1a	; a ošetří přetečení >255
	pop hl		;
	ld a,e		;
	ret		;
; *********************************************************
; pomocná procedura grafických příkazů - obě souřadnice X/Y
; *********************************************************
			; (1befh)
X1bef:	ld bc,X1b79	; načtení X-ové souřadnice do inter-
	ld de,X1b7f	; ní proměnné @X a poté simulace
	call X1bd6	; rovnice: @X = @0+@6*@X
	ld (x2),a		; uložit vypočtenou souřadnici X
	rst 0x08; vynutit oddělovací čárku
	.db ','
	ld bc,X1b82	; načtení Y-ové souřadnice do inter-
	ld de,X1b88	; ní proměnné @Y a poté simulace
	call X1bd6	; rovnice: @Y = @1+@7*@Y
	cp 0f3h	; navíc u Y-ové souřadnice omezit
	call nc,X1c1a	; rozsah na 0..242
	ld (y2),a		; uložit vypočtenou souřadnici Y
X1c0e:	ld a,0		; pokud jsem při kreslení úseček
	and a		; vyjel mimo obrazovku, pak se dvě
	ret z		; úsečky (tam+zpět) nebudou kreslit
	sub 1		; zde odpočítávám to "tam" a "zpět"
	ld (X1c0e+1),a	; ale při doběhu úsečky "zpět" už
	 jp X1c58	; musím nastavit koncové souřadnice
			; jako výchozí pro nový PLOT
X1c1a:	ld a,2		; došlo k překročení povoleného roz-
	ld (X1c0e+1),a	; sahu v grafické oblasti pro danou
	ld e,0		; souřadnici => 2 následující úsečky
	ret		; se nebudou kreslit - jedna tam a
			; druhá zpět (pokud pokračuji PLOTem
			; za hranicemi viditelné části obra-
			; zovky, trvale se nastavuje odpočet
			; na zhasnutí následujících dvou
			; úseček)
; ***********
; příkaz PLOT
; ***********
			; (1c22h)
c_plot:	call X1bef	; načíst souřadnice prvního bodu
	dec hl		; (ty jsou povinné)
	rst 0x10; pokud následuje dvojtečka, nebo
	jp z,X1c36	; končí řádek, jdi kreslit
	cp 59		; pokud následuje středník
	jp z,X1c36	; tak jdi taky kreslit
			; (lomená čára se řeší až tam)
	rst 0x08; v opačném případě očekáváme třetí
	.db ','		; parametr a tak vynutíme čárku,
	rst 0x20; načteme ten třetí parametr,
	or a		; který, je-li nenulový, způsobí
	jp nz,X1c3c	; vykreslování jen koncových bodů
			; dílčích úseček
X1c36:	call X1c90	; jinak se vykreslí celá úsečka
	 jp X1c44	; test na případné pokračování
			; lomené úsečky z posledního bodu
X1c3c:	push hl		; v případě uvedení třetího nenul-
	call X1c58	; ového parametru příkazu PLOT se
	call z,point	; vykreslí jen koncový bod úsečky
	pop hl
X1c44:	dec hl		; úspěšně jsme zadali souřadnice
	rst 0x10; (event. třetí parametr) a tak,
	ret z		; následuje-li dvojtečka nebo konec
	rst 0x08; řádku, je konec příkazu
	.db ';'		; jinak vynutit středník a
	 jp c_plot	; následují další souřadnice
; ***********
; příkaz MOVE
; ***********
			; (1c4ch)
c_move:	xor a		; u příkazu MOVE se implicitně
	ld (X1c0e+1),a	; nastaví atribut "jsem v okně"
	call X1bef	; a načtou se souřadnice X a Y
			; (netrefení se do okna způsobí
			; nekreslení dalších dvou úseček)
	dec hl
	rst 0x10; cokoliv jiného než dvojtečka nebo
	jp nz,err_09	; konec řádku vyvolá chybu
; *******************************************************
; překlopení nových (načtených) souřadnic X,Y do starých,
; tedy výchozích pro další kreslení
; *******************************************************
X1c58:	ld a,(X1c0e+1)	; mohu kreslit? (=jsem v grafickém
	and a		; okně?)
	ret nz		; pokud ne, nic nedělám
	ld a,(x2)		; pokud tam jsem, nebo jsem se tam
	ld (x1),a		; vrátil, pak nové, respektive nově
	ld b,a		; načtené souřadnice X2,Y2 přesunu
	ld a,(y2)		; do těch výchozích X1,Y1, které
	ld (y1),a		; poslouží jako výchozí bod
	ret		; pro další kreslení
; ***********
; příkaz AXES
; ***********
			; (1c6bh)
c_axes:	call c_move	; voláním MOVE zadám průsečík os
	ld a,(X1c0e+1)	; otestuji opuštění grafického okna
	and a
	ret nz
	push bc		; a pokud jsem v okně, kreslím
	xor a
	ld (x1),a		; z (0,y)
	cpl
	ld (x2),a		; do (255,y)
	call X1c90	; nejprve vodorovnou osu
	pop bc
	ld a,b
	ld (x1),a		; a potom
	ld (x2),a
	xor a		; z (x,0)
	ld (y1),a
	ld a,0f2h	; do (x,242)
	ld (y2),a		; i svislou osu
; *********************
; obecné vykreslení osy
; *********************
X1c90:	ld a,(X1c0e+1)	; test na přítomnost v platném
	and a		; rozmezí souřadnic grafického okna
	ret nz
	push hl		; a pokud jsem v okně, směle kreslím
	call inpol
	pop hl
	ret
; ***********
; příkaz BEEP
; ***********
			; (1c9bh)
c_beep:	push hl		; schovat ukazatel na aktuální
	call beep	; znak v zápisu programu
	pop hl		; a volat rutinu BIOSu pro
	ret		; generování pípnutí
; **********
; příkaz PEN
; **********
			; (1ca1h)
c_pen:	call X2161	; vyřešit bity 0, 1 a 2 vstupního
	ld a,c		; parametru příkazu (společné s INK)
	cp 3fh
	jp nz,X1cb5	; následuje nepřehledná síť, která
	ld a,b		; v konečném důsledku modifikuje grafickou
	and 18h		; rutinu "vystup" na adrese C1F4h, která
	cp 8		; je volána grafickými příkazy BASICu
	jp z,X1cb5
	xor 10h		; pro jednotlivé hodnoty parametru PEN
	ld b,a		; jsou uvedeny výsledné varianty této
X1cb5:	ld a,b		; modifikované procedury
	ld de,0fefeh
	ld bc,0b000h	; Hodnoty příkazu PEN:
	and 18h		;
	jp nz,X1cc7	; spodní dva bity nastavující barvu
	ld de,0e6f6h	; """""""""""""""""""""""""""""""""
	 jp X1cd3	; +0 .. nastaví atribut barvy na 00
X1cc7:	cp 8		; +1 .. nastaví atribut barvy na 01
	jp nz,X1cd1	; +2 .. nastaví atribut barvy na 10
	ld b,0a8h	; +3 .. nastaví atribut barvy na 11
	 jp X1cd3	;
X1cd1:	ld c,2fh	; další tři bity, nastavující režim
			; """""""""""""""""""""""""""""""""
X1cd3:	push hl		; kreslí      maže        invertuje  
	ld hl,vystup+1	;
	ld (hl),d		; 0, 20      4, 16, 24    8, 12, 28
	inc hl		;
	inc hl		;    |           |           |
	ld (hl),e		;    V           V           V
	inc hl		;
	inc hl		; mov a,m     mov a,m     mov a,m
	ld (hl),c		; ani 3fh     cpi 3fh     cpi 3fh
	inc hl		; ori 00h     cpi 00h     cpi 00h
	ld (hl),b		; nop         cma         nop
	inc hl		; ora b       ora b       xra b
	ld (hl),c		; nop         cma         nop
	pop hl		; mov m,a     mov m,a     mov m,a
	ret		; ret         ret         ret
; ************
; příkaz BMOVE
; ************
			; (1ce4h)
c_bmov:	rst 0x20
	ld (bcur),a	; načíst a uschovat short integer
	cp 30h		; při souřadnici x>47 vypsání
	jp nc,X0b95	; chybového hlášení „Subscr.rng“
	rst 0x08; test povinného znaku
	.db ','		; čárka
	rst 0x20; načíst short integer
	cp 0f3h	; při souřadnici y>242 vypsání
	jp nc,X0b95	; chybového hlášení „Subscr.rng“
	push hl
	ld h,0
	ld d,0c0h
	ld l,a
	add hl,hl
	add hl,hl
	add hl,hl
	add hl,hl
	add hl,hl
	add hl,hl
	ld a,(bcur)
	ld e,a
	add hl,de		; HL = 0C000h + 64.y + x
	ld (bcur),hl	; adresu uložit do proměnné BIOSu
	pop hl
	ret
; ************
; příkaz BPLOT
; ************
c_bplo:	call varadr	; načíst STRING (ukazatel)
	rst 0x08; test na povinný znak
	.db ','		; čárka
	push de
	rst 0x20; načíst SHORT INT
	pop de
	ld c,a		; C = parametr rozkladu obrázku
	ld (autonr),a
	ld a,(de)
	ld b,a		; B = počet znaků řetězce
	and a
	ret z
	push hl
	inc de
	inc de
	ld a,(de)
	ld l,a
	inc de
	ld a,(de)
	ld d,a		; DE = ukazatel na znaky řetězce
	ld e,l
	ld hl,(bcur)	; HL = cílová adresa ve videoram
X1d27:	call X0043	; vlastní zápis jednoho bajtu
	ld a,c
	cp 1
	call nz,X1d49	; při větší šířce pak volat
	push de		; universálnější algoritmus kreslení
	ld de,64	; přechod na další mikrořádek
	add hl,de		; při vykreslování obrázku
	pop de
	ld a,h
	cp 0fdh	; test na přetečení obrazovky
	jp z,X1d47
	inc de		; další znak řetězce
	ld (bcur),hl
	dec b		; byl poslední?
	jp nz,X1d27	; pokud ne, kresli další znak
	.db 011h	; lxi d,
X1d45:	.db 0e1h	; pop h
	.db 0e1h	; pop h
X1d47:	pop hl		; .db 0e1h
	ret		; .db 0c9h
X1d49:	push hl		; vykreslení jednoho rozkladového
	dec c		; mikrořádku s šířkou C bajtů
X1d4b:	inc hl
	ld a,l
	and 30h		; a pokud by měl obrázek zasáhnout
	cp 30h		; do zápisníku, tak ty kolizní
	jp z,X1d69	; znaky nekreslit, pouze je přeskočit
	ld (bcur),hl
	dec b
	jp z,X1d45
	inc de
	call X0043
	dec c
	jp nz,X1d4b
X1d63:	ld a,(autonr)
	ld c,a
	pop hl
	ret
X1d69:	dec b		; přeskočení kolizních znaků
	jp z,X1d45	; při možném poškození obsahu
	inc de		; zápisníku napravo od videoram
	dec c
	jp nz,X1d69
	 jp X1d63
; ***********************************************************
; vykreslí v osách X a Y zvětšenou bitovou interpretaci bajtu
; (FILL volá tuto proceduru přímo pro svůj třetí parametr,
; LABEL opakovaně pro každou linku znaku)
; ***********************************************************
			; (1d75h)
magbyt:	push af
	ld hl,(x1+1)
	ld a,(x1)
	ld l,a
	pop af
	push hl		; C170 nese informaci o souřadnici X (0..255)
	push af	; C172 nese informaci o souřadnici Y (0..255)
	push hl
	call pospoint	; z toho vypčtu do HL adresu ve videoram
	pop de		;               do B  bitovou masku
	ld c,e
	ex de,hl
	ld hl,(autosp)	; v C mám pixelovou pozici X
	ex de,hl		; v E mám vodorovné zvětšení
	pop af		; v D mám svislé zvětšení
X1d8c:	or a		; bajt, jehož bitovou interpretaci kreslím
	jp z,X1dca	; (nulový bajt neřeším, hned jej přeskočím)
	rra		; test aktuálního bitu
	push de
	push af
X1d93:	pop af
	push af
	jp nc,X1db0	; a přeskočení jeho kreslení, pokud je nulový
	push bc		; nejprve se nakreslí jeden svislý proužek
	push de		; zdola nahoru, pak se půjde na další proužek
	push hl		; napravo odněj
	ld c,d
	ld de,-64
X1d9f:	call vystup	; modifikovatelná grafická rutina v RAM
	add hl,de		; která zohledňuje nastavení příkazem PEN
	ld a,h		; (pracuje s bitovou maskou na vybrané adrese)
	cp 0c0h
	jp c,X1dad	; vyjel jsem mimo videoram => konec kreslení
	dec c		; další pixel svislého proužku
	jp nz,X1d9f
X1dad:	pop hl
	pop de
	pop bc
X1db0:	ld a,b		; nyní vypočtu masku pro svislý proužek napravo
	add a,a		; posunu pixel v bitové masce
	cp 40h		; a pokud už jsem v oblasti atributů
	jp c,X1dba
	ld a,1		; nastavím v masce aktivní bit na opačném konci
	inc hl		; a posunu adresu videoram
X1dba:	ld b,a
	inc c		; posun pixelové pozice X o jednu doprava
	jp z,X1dc8	; pokud jsem mimo grafickou zónu, konec
	dec e		; budu kreslit další svislý proužek aktuálního
	jp nz,X1d93	; testovaného bitu (celkem E proužků)?
	pop af
	pop de
	 jp X1d8c	; běž na test dalšího z osmi bitů bajtu
X1dc8:	pop af		; zakončení:
	pop de		; do DE obnovím zvětšení v obou osách
X1dca:	pop hl		; do HL obnovím pixelové souřadnice X,Y
	ld a,h		; vleze do videoram na výšku další zvětšený
	sub d		; pixel?
	jp nc,X1dd1
	xor a		; pokud ne, vynuluji a
X1dd1:	ld (y1),a		; uložím nový stav souřadnice Y
	ld a,e
	add a,a		; a pro účely příkazu LABEL
	add a,e		; posunu pixelovou souřadnici X
	add a,a		; o 6 pixelů doprava (zatím bez jejího
	add a,l		; uložení, to si LABEL udělá sám)
	ret nc
	ld a,0ffh
	ret
; ********************************************
; tiskový ovladač LABEL pro universální výstup
; ********************************************
			; (1dddh)
X1ddd:	cp 0dh		; ASCII znak CR
	ret z		; ukončí tisk
	cp 0ah		; znak LF
	ret z		; rovněž
	push de
	push hl
	call adras	; podle znaku určí adresu fontu
	ld e,7		; bude se kreslit jeho 7 mikrořádků
	ld a,(autofl)	; vertikální zvětšení
	ld b,a
	ld a,(y1)		; a aktuální pozici Y
	push af
	add a,b		; sečtu (dostanu novou souřadnici Y)
	dec hl		; připravím první platný bajt znaku
	jp c,X1e07	; při překročení maximální hodnoty
	cp 0f3h	; souřadnice Y (=242) přeskočím
	jp nc,X1e01	; její uložení, jinak
	ld (y1),a		; uložím novou Y adresu
	inc e		; nesmyslný kód, který v zásadě
	inc hl		; nic neřeší
X1e01:	 jp X1e07	; běž kreslit
X1e04:	 jp X2296	; ukazatel do bloku MGF operací
X1e07:	dec hl		; další bajt předlohy znaku
	push hl
	push de
	ld a,(hl)		; další bajt z generátoru znaků
	rrca		; rotace znaku o jeden pixel vlevo
	call magbyt	; vykreslím zvětšeninu v ose X
	pop de
	pop hl
	dec e		; byla poslední linka znaku?
	jp nz,X1e07	; ne => kreslí další linku
	ld (x1),a		; uložit nové souřadnice, které se vykreslením
	pop af		; nápisu posunuly za tento nápis
	ld (y1),a
	pop hl
	pop de
	ret
; ************
; příkaz LABEL
; ************
			; (1e1fh)
c_labl:	ld a,(hl)		; je místo zvětšovacích parametrů znak
	cp 0a6h	; krát (hvězdička)?
	call nz,X1e45	; pokud ne, načíst zvětšovací parametry
	inc hl		; (jinak zůstávají v platnosti ty poslední)
	rst 0x08; vynutit oddělovací středník
	.db ';'
	ld de,X1ddd	; LABELovský tiskový ovladač
X1e2b:	ex de,hl		; pro universální výstup
	ld (cout+1),hl
	ex de,hl
	call X06c9	; odskok defacto na PRINT bez testu
			; kanálového výstupu (LABEL, stejně jako
			; např. i DISP sídlí stejný formát řazení
			; tiskových parametrů jako PRINT a to včetně
			; oddělovačů typ čárka, středník atd.)
; **********************************************
; nastaví standardní textový výstup na obrazovku
; a editační bufer do standardní lokality 7F82h
; **********************************************
			; (1e33h)
X1e33:	push hl
	ld hl,prtout	; na standardní tiskovou rutinu BIOSu
	ld (cout+1),hl	; navedu skokový vektor universálního výstupu
	ld hl,edibuff	; a nastavím standardní editační a odkládací
	ld (X002c),hl	; bufery (7F82h)
	ld (mess),hl
	pop hl
	ret
; ****************************************
; načtení zvětšovacích parametrů pro LABEL
; ****************************************
			; (1e45h)
X1e45:	rst 0x20; první parametr (horizontální zvětšení)
	ld (autosp),a	; (funkci AUTO to teď určitě vadit nebude)
	rst 0x08; vynutit oddělovací čárku
	.db ','
	rst 0x20; druhý parametr (vertikální zvětšení)
	ld (autofl),a
	dec hl
	ret		; a návrat do příkazu LABEL
; ***********
; příkaz FILL
; ***********
			; (1e51h)
c_fill:	call X1e45	; povinně načíst zvětšovací parametry
	inc hl
	rst 0x08; vynutit znak středník
	.db ';'
	rst 0x20; načíst bajt, jehož bitovou interpretaci
	push hl
	call magbyt	; budeme touto procedurou zvětšovat
	pop hl
	ret
; ***********
; příkaz DISP
; ***********
c_disp:	ld a,0		; vynulovat
	ld (colpos),a	; formální počitadlo znaků na řádku
	ld de,X0324	; universální výstup přesměrovat do buferu
			; dialogového řádku
	call X1e2b	; provést tisk PRINTem do tohoto buferu
	push hl		; zobrazit textový bufer do dialogového
	call prbtxt+5	; řádku ale bez pípnutí
	pop hl
	ret		; a konec..
; ***********
; příkaz AUTO
; ***********
			; (1e6fh)
c_auto:	push hl
	ld hl,10	; standardní rozteč řádků
	ld (autosp),hl	; bez uvedeného parametru
	pop hl
	ld a,(hl)
	or a
	jp z,X1e96	; AUTO úplně bez parametrů
	call numpar
	call tstint
	push hl
	ex de,hl
	ld (autonr),hl
	pop hl
	ld a,(hl)		; pokud je jen jeden parametr
	or a		; pak číslovat od zadaného
	jp z,X0149	; čísla s krokem 10..
	rst 0x08
	.db ','		; jinak vynutit čárku a načíst
	rst 0x20; ještě i krok číslování..
	ld (autosp),a
X1e93:	 jp X0149
X1e96:	ld hl,(pgbase)	; je v paměti nějaký program?
	ld e,(hl)
	inc hl
	ld d,(hl)
	ld a,d
	or e
	jp z,X1eb2	; není => číslování 10,20,30..
X1ea1:	ex de,hl
	push de
	ld e,(hl)
	inc hl
	ld d,(hl)
	ld a,d
	or e
	pop bc
	jp nz,X1ea1
	push bc
	pop hl
	inc hl
	ld e,(hl)		; jinak načíst číslo posledního
	inc hl		; řádku
	ld d,(hl)
X1eb2:	ex de,hl
	ld (autonr),hl
	ld de,10	; a zvýšit jej o 10..
	add hl,de
	ld (autonr),hl
	 jp X1e93
; *******************
; obsluha režimu AUTO
; *******************
			; (1ec0h)
X1ec0:	ld a,(autofl)	; je aktivní režim AUTO?
	or a
	ret nz		; NE => pak konec
	ld hl,X1ee2	; ANO => tisk přesměrovat
	ld (cout+1),hl	; do buferu dialogového řádku
	ld hl,(autonr)
	push hl
	call X126b	; vytisknout číslo řádku,
	ld a,20h	; mezeru
	call X1ee2
	ld hl,(autosp)	; aktualizovat nové číslo řádku
	pop de
	add hl,de
	ld (autonr),hl
	 jp X1e33	; a tisk přesměrovat na obrazovku
X1ee2:	ld (ascii),a	; vlastní ovladač tisku do buferu
	 jp edit	; dialogového řádku
; ************
; funkce INKEY
; ************
			; (1ee8h)
X1ee8:	push bc
	rst 0x10
	ld c,0ch	; začít s klávesou K11
X1eec:	dec c
	ld a,c
	out (0f4h),a
	in a,(0f5h)
	and 1
	ld a,c
	jp z,X1efd	; stisknuto
	or a
	jp nz,X1eec	; postupovat až ke klávese K0
	cpl		; žádná klávesa = kód 255
X1efd:	ex (sp),hl
	ld de,X09b4	; typová kontrola na typ "číslo" po převodu
	push de		; hodnoty z reg. A na FP
	 jp X0c4b	; a samotný hodnoty v reg. A na FP číslo
; **********
; funkce BIT
; **********
			; (1f05h)
X1f05:	push bc		; formalita, na konci typové kontroly se
			; holt vybírá hodnota ze STACKu
	rst 0x10; přeskočit mezery a
	rst 0x20; načíst první parametr
	push af
	rst 0x08; vynutit oddělovací čárku
	.db ','
	rst 0x20; načíst druhý parametr,
	and 7		; který ořežeme na rozsah 0..7
	ld c,a
	jp z,X1f19
	pop af		; obnovit první parametr
X1f13:	rra		; rotovat jej doprava tolikrát,
	dec c		; kolikrát určuje druhý parametr
	jp nz,X1f13
	.db 0eh		; mvi c,0f1h
X1f19:	pop af
	and 1		; a zeptám se na hodnotu bitu 1, ve kterém
	 jp X1efd	; se nyní nalézá testovaný bit
; ***********
; příkaz CODE
; ***********
c_code:	call varadr	; (1f1fh)
	push hl		; v DE vrátí adresu $-proměnné
	ex de,hl
	ld a,(hl)		; délka stringu musí být sudá
	rrca		; jinak se zahlásí
	jp c,X08d1	; Chyba 11h - "Type conv."
	ld c,a		; C = počet dvojic znaků ASCII
	inc hl
	inc hl
	ld e,(hl)
	inc hl
	ld h,(hl)
	ld l,e		; HL = ukazatel na text
	ld de,usrexec	; transfer uživatel. programu
X1f33:	ld a,(hl)		; zbytečná instrukce, protože
	call pairin	; zde se do ACC načte číslo,
	jp c,X08d1	; uvedené v hexadecimální ascii
	ld (de),a		; interpretaci od (HL)
	inc de		; pak už jen tento bajt uložit
	dec c		; a zpracovat další ASCII znak
	jp nz,X1f33
	call usrexec	; volat uživatelský program
	pop hl		; obnovit ukazatel na zdrojový text
	dec hl
	rst 0x10
	ret z		; je-li další znak dvojtečka, pak konec
	rst 0x08; jinak trvat na nutnosti vložit
	.db ','		; povinný znak čárka
	 jp c_code	; a zpracovat další string
; ************
; příkaz PAUSE
; ************
			; (1f4ch)
c_paus:	ld a,0		; implicitní hodnota
	call nz,X1627	; event. načíst SHORT INTEGER
	ld d,a
X1f52:	ld bc,3400h	; konstanta 1msec
X1f55:	dec c
	jp nz,X1f55
	dec b
	jp nz,X1f55
	dec d
	ret z
	out (0f4h),a	; test STOP/SPACE pro přerušení
	in a,(0f5h)		; časování PAUSE
	cpl
	and 50h
	jp z,X1f52
	ret
; *******************************************************
; Tato procedura se vykoná ihned po natažení hlavičky
; datového bloku v případě, že chci natahovat řetězcové
; pole - porovnají se délky požadovaného pole a pole
; na MGF pásce (bez testu vlastních textů proměnných).
; Čtení dat a přiřazování hodnot jednotlivým položkám
; pole se děje v uživatelské smyčce mimo procedury BIOSu.
; *******************************************************
			; (1f6ah)
X1f6a:	ld hl,(adrfil)	; to, co je u ostatních datových
	dec hl		; bloků na MGF pásce považováno za
	call X23a7	; adresu, to je u řetězcových polí
			; použito jako délka hlavičky pole
			; => nejprve tedy porovnám délky
			; hlaviček obou polí (natahovaného
			; z MGF a toho formálního v paměti)
	
	call X23d4	; BC = počet dimenzí pole
			; DE = adresa za posledním prvkem
			; HL = ukazatel na 1. prvek pole
			; nyní budu načítat čtveřice bajtů,
			; což jsou jednotlivé položky
			; řetězcového pole
; *****************************************************
; cyklus načítání jednotlivých položek řetězcového pole
; *****************************************************
X1f74:	call ldbyte	; 1. bajt čtveřice určuje délku
	ld c,a		; textu, přiřazeného této položce
	ld (hl),a		; pole - tu načtu do reg. C
	add a,b
	ld b,a
	inc hl
	inc hl
	push hl		; adresa aktuálního prvku pole
	push bc		; CRC a délka textu položky
	ld b,0ffh	; v oblasti pro texty řetězcových
	ld hl,(strlast)	; proměnných snížím ukazatel
	ld a,c		; na poslední použitou položku
	cpl		; o délku nového textu
	ld c,a
	add hl,bc		; v BC je dvojkový doplněk délky,
	inc hl		; proto místo odečítání přičítám BC
	ld a,h		; pokud je dat příliš mnoho
	cp 5fh		; (klesnou pod adresu 6000h)
	jp c,X00f4	; pak chyba 07h - Pg too big
			; není to chyba? neměl by u verze
			; 2A být namísto 5Fh limit 8Fh či
			; spíše ještě přesněji 90h?
	ld (strlast),hl
	pop bc		; obnovit CRC a délku položky
	inc hl		; v HL je nyní adresa textu
	push hl		; aktuálního prvku pole a pokud
	inc c		; délka tohoto prvku
	dec c		; je nenulová, dojde k načtení
	ld a,b		; vlastního textu znak po znaku
	jp z,X1fa6
X1f9b:	call ldbyte	; načítám jednotlivé znaky textu
	ld (hl),a		; a v oblasti od 9000h je ukládám
	add a,b		; na adresu, která byla pro načíta-
	ld b,a		; nou položku pole alokována
	inc hl		; CRC je v reg. B
	dec c		; a délka textu je v reg. C
	jp nz,X1f9b	
X1fa6:	pop bc		; CRC mi ještě zůstalo v reg. A
	pop hl		; obnovit adresu 4B hlavičky aktuál-
			; ního prvku pole
	ld (hl),c		; do samotné proměnné (4 bajty)
	inc hl		; uložím odkaz na nově založený text
	ld (hl),b		; (proměnné jsou již v dolní
	inc hl		; polovině RAM za zdrojovým kódem
	ld b,a		; gramu v BASICu)
	rst 0x18
	jp nz,X1f74	; a registr DE mi nese koncovou
			; adresu pole pro testování konce
	pop af		; zrušit "návratovou" adresu pro
			; faktické natažení bloku dat za
			; hlavičkou (právě jsme to udělali
			; sami bez BIOSovské procedury,
			; která se na tento formát nehodí)
	call ldbyte	; načíst standardní CRC bajt
	cp b		; porovnat s průběžně vytvářeným
	ret		; CRC a ukončit příkaz
; ********************************************
; odeslání hlavičky zprávy dle protokolu IMS-2
; ********************************************
			; (1fb7h)
X1fb7:	ld hl,imsbuf	; Popis protokolu přesahuje rámec
	call X2005	; tohoto dokumentu, více v Uživa-
X1fbd:	in a,(7dh)		; telské příručce IV - OUTPUT/ENTER
	and 0ch
	ret z		; Z délky dostupného buferu
	cp 8		; (6 bajtů od adresy C33Ah)
	jp nz,X1fbd	; lze usuzovat na oslovení max.
	ld a,(hl)		; tří příjemců dat v síti IMS-2
	or a
	jp z,X2005
	out (7ch),a
	call X200c
	ld a,62h
	out (7eh),a
X1fd5:	in a,(7dh)
	and 8
	jp nz,X1fd5
	ld a,60h
	out (7eh),a
	inc hl
	 jp X1fbd
; ********************************************************
; driver IMS-2 8255 pro konzolový výstup (příkazem OUTPUT)
; ********************************************************
			; (1fe4h)
X1fe4:	ld c,a		; počkat na stav NRFD a NDAC
X1fe5:	in a,(7dh)
	and 0ch
	ret z
	cp 8
	jp nz,X1fe5
	ld a,c		; vyslat nová data
	out (7ch),a
	call X200c	; a po ustálení dat na sběrnici
	ld a,42h	; aktivovat DAV
	out (7eh),a
X1ff9:	in a,(7dh)
	and 8
	jp nz,X1ff9	; počkat na potvrzení příjmu dat
	ld a,40h	; deaktivovat DAV
	out (7eh),a
	ret
X2005:	ld a,60h	; nastavit handshake signály
	out (7eh),a
	call X200c	; a počkat trochu déle (2x)
X200c:	xor a
X200d:	dec a
	ret z
	 jp X200d
; *************************************************
; inicializace driveru IMS-2 8255 pro příkaz OUTPUT
; *************************************************
			; (2012h)
odrv7c:	ld hl,X1fe4	; přesměrovat konzolový výstup
	ld (cout+1),hl	; na driver IMS-2 8255 na adrese 7ch
	ld hl,imsbuf	; do buferu hlavičky zprávy
	ld (hl),3fh	; zapsat adresní část
	inc hl
	ld (hl),55h
	ld (imsptr),hl	; a uložit ukazatel na konec
	pop hl		; hlavičky v buferu
X2024:	inc hl
	rst 0x20; načíst druhou cifru kanálové
	push hl		; specifikace
	ld hl,(imsptr)	; a do buferu hlavičky zprávy
	inc hl
	or 20h		; zakomponovat adresu příjemce
	ld (hl),a		; dat v systému IMS-2
	ld (imsptr),hl	; (bližší popis viz Uživatelská
	inc hl		; příručka IV - OUTPUT/ENTER)
	ld (hl),0
	pop hl		; pokud následuje za druhou cifrou
	ld a,(hl)		; (určuje adresáta) čárka, pak
	cp ','		; předpokládám a načtu další cifru
	jp z,X2024	; pro specifikaci dalšího adresáta
	rst 0x08
	.db ';'		; na konci vynutit odděl. středník
	call X204a	; inicializace 8255
	push hl
	call X1fb7	; poslat hlavičku zprávy
	pop hl
	dec hl
	rst 0x10
X2047:	 jp X06cb	; a odskok na přesměrovaný PRINT
X204a:	ld a,82h	; nastavit směr portů a režim
	out (7fh),a		; IMS-2 8255 na adrese 7Ch
	ld a,40h	; pro funkční emulaci HW protokolu
	out (7eh),a		; IMS-2
	ret
; **************
; příkaz CONTROL
; **************
			; (2053h)
c_ctrl:	rst 0x20; Velmi diskutabilní příkaz,
	rla		; který lze nahradit jednoduchým
	rla		; příkazem OUT. 
	rla
	rla		; 1. parametr určuje horní čtveřici
	or 0ch		;    bitů čísla portu (AAAA)
	push af	; 2. parametr určuje nejnižší dva
	inc hl		;    bity čísla portu (BB)
	rst 0x20; 
	and 3		; výsledné č. portu je: AAAA11BB
	ld c,a		; např. CONTROL 7,1,5 zapíše do IO
	pop af		; s bázovou adresou 7X na jeho port 01
	or c		; hodnotu 5 (ekvivalent OUT 7dh,5)
	ld (c_ctrp+1),a
c_ctrn:	inc hl		; Počínaje třetím parametrem
	rst 0x20; zapisovat jejich hodnoty
c_ctrp:	out (0),a		; na vypočtený port
	ld a,(hl)		; dokud jsou tyto parametry
	cp ','		; (oddělené čárkou) přítomny.
	jp z,c_ctrn
	ret		; V důsledku maskovací konstanty
			; ori 0ch nemůže zapisovat do 8255
			; obsluhující klávesnici a ROM modul.
; **********************************************
; příkaz OUTPUT (plný ekvivalent příkazu PRINT#)
; **********************************************
; Příkaz OUTPUT má před středníkem specifikaci kanálu
; (záměrně nepoužívám výraz "číslo"), která obsahuje jak
; vlastní adresu I/O obvodu, tak způsob zápisu na vybraný
; port. Například u USART (adresa 1Ch) je možný jediný zápis
; tj. zápis do buferu vysílače a proto v případě příkazu
; OUTPUT 1;[seznam] je za jedničkou, označující I/O adresu
; hned středník. Ale u PIO 8255 je variant zápisu více
; a tyto jsou rozlišeny druhou cifrou specifikace kanálu.
; Kanálová specifikace u PIO 8255 na adrese 4Ch nemusí být
; v této verzi BASICu zadána třímístným číslem, stačí
; 2 cifry. Ta první, která nemusí ani cifrou být
; (z ASCII kódu prvního znaku se instrukcí ANI 7 odmaskují
; 3 nejnižší bity) určuje adresu I/O portu a ta druhá
; cifra s rozsahem opět 0..7 označuje číslo obslužného
; driveru. Funguje tedy například OUTPUT D3;"WAIT FOR INTR"
; (Příklad posílá jednotlivé znaky řetězce za středníkem
; na port PA obvodu GPIO 8255 na adrese 4Ch a před zápisem
; každého bajtu na port PA testuje připravenost na PC3, což
; je dáno charakterem obslužného driveru č.3. Písmeno D je
; pak ekvivalent cifry 4 a určuje adresu GPIO.)
			; (2070h)
c_otpt:	dec hl
X2071:	rst 0x10; načíst znak, určující číslo
	ld bc,c_otdr	; I/O obvodu
	push hl
	ld hl,X06cb	; pokračování příkazem PRINT
X2079:	ld (X2047+1),hl
X207c:	and 7		; max. 8 různých I/O obvodů
	rla
	ld h,0		; do HL zformuje adresu obslužné
	ld l,a		; rutiny pro zvolený I/O obvod
	add hl,bc
	ld c,(hl)
	inc hl
	ld h,(hl)
	ld l,c
	jp (hl)		; a skok na vybranou rutinu
; ******************************************************
; tabulka obslužných rutin příkazu OUTPUT pro I/O obvody
; ******************************************************
			; (2088h)
c_otdr:	.dw err_09	; neobsazeno
	.dw odrv1c	; USART 8251 (adresa 1Ch)
	.dw err_09	; neobsazeno
	.dw err_09	; neobsazeno
	.dw odrv4c	; GPIO 8255 (adresa 4ch)
	.dw err_09	; CTC 8253 (ovšem bez ovladače)
	.dw err_09	; neobsazeno
	.dw odrv7c	; IMS-2 8255 (adresa 7ch)
; ***********************************************
; adresové ofsety driverů pro výstup dat příkazem
; OUTPUT při zápisu na GPIO 8255 na adrese 4ch
; ***********************************************
			; (2098h)
X2098:	.db 0a0h	; => 20a0h: přímý zápis na port PA
	.db 0a3h	; => 20a3h: přímý zápis na port PB
	.db 0a6h	; => 20a6h: přímý zápis na port PC
	.db 0b6h	; => 20b6h: zápis na port PA
			; s čekáním na READY na pinu PC3
	.db 0a9h	; => 20a9h: zápis na port PB
			; s čekáním na READY na pinu PC0
	.db 0b5h	; => 20b5h: zápis negovaných dat
			; na port PA s čekáním na READY
			; na pinu PC3
	.db 0e5h	; => 20e5h: uživatelský driver
	.db 0e8h	; => 20e8h: uživatelský driver
; ********************************************************
; drivery GPIO 8255 pro konzolový výstup (příkazem OUTPUT)
; ********************************************************
X20a0:	out (4ch),a		; driver 0
	ret		; přímý zápis na port PA
X20a3:	out (4dh),a		; driver 1
	ret		; přímý zápis na port PB
X20a6:	out (4eh),a		; driver 2
	ret		; přímý zápis na port PC
X20a9:	ld c,a		; driver 4
X20aa:	in a,(4eh)		; zápis na port PB s čekáním
	and 1		; na stav READY na pinu PC0
	jp z,X20aa
	ld a,c
	out (4dh),a
	ret
X20b5:	cpl		; driver 5
			; zápis negovaných dat na port PA
			; s čekáním na stav READY na PC3
X20b6:	ld c,a		; driver 3
X20b7:	in a,(4eh)		; zápis na port PA s čekáním
	and 8		; na stav READY na pinu PC3
	jp z,X20b7
	ld a,c
	out (4ch),a
	ret
; ******************************************************
; rutina DSAVE pro uložení řetězcových polí na MGF pásku
; ******************************************************
			; (20C2h)
X20c2:	call X23d4	; do BC uloží dimenzi pole
			; do DE koncovou adresu pole
			; do HL adresu prvního prvku pole
X20c5:	ld c,(hl)		; délku textu aktuálního prvku pole
	call X23ea	; vyšle na MGF
	inc hl
	ld a,(hl)
	inc hl
	push hl
	ld h,(hl)		; do HL připraví ukazatel na vlastní
	ld l,a		; text aktuálního prvku
	inc c
X20d0:	dec c		; a celý tento text, postupně znak
	jp z,X20da	; po znaku pošle na MGF
	call X23ea
	 jp X20d0
X20da:	pop hl		; po dokončení textu aktuál. prvku
	inc hl		; se posune na další prvek pole,
	rst 0x18; otestuje případný konec pole
	jp nz,X20c5	; a pokud není, jde na další prvek
	pop hl		; je-li konec, zruší nepotřebný
	ld a,b		; vektor (8F8Ah) na BIOSovský SAVE
	 jp usartout	; a vyšle (svůj) CRC kód z reg. B
; ********************************************************
; drivery GPIO 8255 pro konzolový výstup (příkazem OUTPUT)
; ********************************************************
X20e5:	 jp err_09	; driver 6 - uživatelský
X20e8:	 jp err_09	; driver 7 - uživatelský
; ********************************
; deaktivace režimu AUTO-matického
; číslování vkládaných řádků
; ********************************
X20eb:	ld a,0ffh	; (20ebh)
	ld (autofl),a	; samotná deaktivace AUTO
	 jp X04ac	; a skok na vykonání příkazu
; ******************************************************
; driver IMS-2 8255 pro konzolový vstup (příkazem ENTER)
; ******************************************************
			; (20f3h)
X20f3:	ld a,92h	; směr portu PA přepnout na čtení
	out (7fh),a
	ld a,4dh	; nastavit handshake signály
	out (7eh),a
X20fb:	ld a,49h
	out (7eh),a
X20ff:	in a,(7dh)		; počkat na potvrzení platných dat
	and 2
	jp z,X20ff
	in a,(7ch)		; přečíst vstupní data
	ld (hl),a		; a uložit je do buferu
	ld a,45h	; 
	out (7eh),a		; potvrdit příjem dat
X210d:	in a,(7dh)		; počkat na výchozí stav
	and 2		; handshake signálů
	jp nz,X210d
	ld a,4dh	; výchozí stav komunikačních
	out (7eh),a		; handshake signálů
	ld a,(hl)		; přijatý bajt otestovat
	inc hl
	cp 0ah		; na koncovou zarážku LF a pokud
	jp nz,X20fb	; nepřišla, příjem dalšího bajtu
	 jp X21e2	; jinak zakončit bufer kódem 00h
			; a jít na INPUT
; *********************************************
; příkaz ENTER (plný ekvivalent příkazu INPUT#)
; *********************************************
; doporučuji přečíst si poznámky k příkazu OUTPUT
			; (2122h)
c_entr:	dec hl		; dle prvni cifry kanálové specifi-
X2123:	rst 0x10; kace se vybere obslužná rutina
	ld bc,c_endr	; pro jednotlivé I/O obvody
	push hl
	 jp X207c
; ************************************************
; inicializace driveru IMS-2 8255 pro příkaz ENTER
; ************************************************
			; (212bh)
idrv7c:	ld hl,X20f3	; driver IMS-2 8255 vnutit
	ld (X080b+1),hl	; do procedury INPUT
	pop hl
	inc hl
	rst 0x20; druhou cifru kanálové specifikace
	or 40h		; převést na formát IMS-2 a použít
	push af	; ji jako adresu TALKER
	rst 0x08; vynutit
	.db ';'		; oddělovač středník
	pop af		; (na rozdíl od příkazu OUTPUT, kde
	push hl		; adresátů LISTENER může být více,
			; TALKER může být jen jeden)
	ld hl,353fh	; definice hlavičky protokolu IMS-2
	ld (imsbuf),hl	; do výstupního buferu
	ld l,a
	ld h,0
	ld (imsbuf+2),hl	; (včetně čísla TALKERa)
	call X204a	; inicializace obvodu IMS-2 8255
	call X1fb7	; vyslat iniciační zprávu do sítě
	pop hl
X214e:	 jp X07e3	; a jít na INPUT
; *****************************************************
; tabulka obslužných rutin příkazu ENTER pro I/O obvody
; *****************************************************
			; (2151h)
c_endr:	.dw err_09	; neobsazeno
	.dw idrv1c	; USART 8251 (adresa 1Ch)
	.dw err_09	; neobsazeno
	.dw err_09	; neobsazeno
	.dw idrv4c	; GPIO 8255 (adresa 4ch)
	.dw err_09	; CTC 8253 (ovšem bez ovladače)
	.dw err_09	; neobsazeno
	.dw idrv7c	; IMS-2 8255 (adresa 7ch)
; *********************************************************
; rutina pro načtení a nastavení barvového atributu INK/PEN
; *********************************************************
			; (2161h)
X2161:	rst 0x20; načíst konstantu v rozsahu 0..255
	ld b,a
	and 4		; parametr za klíčovým slovem INK
	jp z,X216a	; má smysluplný rozsah 0..7, hodnoty
	ld a,3fh	; větší se upraví aplikací modulo 8
X216a:	ld c,a		; (PEN má rozsah větší)
	ld a,b
	and 7		; 2 LSB parametru se nakopírují do
	rrca		; dvou atributových (barvových) bitů
	rrca		; tiskové masky, třetí bit parametru
	and 0c0h	; (váha 4) určuje případnou inverzi
	or c
	ld (color),a	; 0 = atribut 0 (00h) / černé pozadí
	ret		; 1 = atribut 1 (40h) / černé pozadí
			; 2 = atribut 2 (80h) / černé pozadí
			; 3 = atribut 3 (C0h) / černé pozadí
			; 4 = atribut 0 (00h) / inverze
			; 5 = atribut 1 (40h) / inverze
			; 6 = atribut 2 (80h) / inverze
			; 7 = atribut 3 (C0h) / inverze
; *******************************
; proměnná pro výpočet funkce RND
; *******************************
X2177:	.db 0		; pořadí multiplikativního parametru
; ************************************************
; inicializace driveru GPIO 8255 pro příkaz OUTPUT
; ************************************************
			; (2178h) 
odrv4c:	pop hl
	inc hl
	rst 0x20; načíst druhou cifru kanálové
	and 7		; specifikace
	push hl
	ld hl,X2098
	ld b,0
	ld c,a
	add hl,bc		; podle této cifry s hodnotou 0..7
	ld l,(hl)		; zvolit odpovídající driver
	ld h,20h
	ld (cout+1),hl	; pro konzolový výstup
	pop hl
	rst 0x08; ještě si vynutit
	.db ';'		; oddělovací středník
	 jp X2047	; a jít na příkaz PRINT
; ***********************************************
; inicializace driveru GPIO 8255 pro příkaz ENTER
; ***********************************************
			; (2191h)
idrv4c:	pop hl
	inc hl
	rst 0x20; načíst druhou cifru kanálové
	and 7		; specifikace
	push hl
	ld hl,X21aa
	ld b,0
	ld c,a
	add hl,bc		; podle této cifry s hodnotou 0..7
	ld l,(hl)		; zvolit odpovídající driver
	ld h,21h
	ld (X080b+1),hl	; pro konzolový vstup
	pop hl
	rst 0x08; ještě si vynutit
	.db ';'		; oddělovací středník
	 jp X214e	; a jít na příkaz INPUT
; **********************************************
; adresové ofsety driverů pro vstup dat příkazem
; ENTER při čtení z GPIO 8255 na adrese 4ch
; **********************************************
			; (21aah)
X21aa:	.db 0b2h	; => 21b2h: přímé čtení z portu PA
	.db 0b5h	; => 21b5h: přímé čtení z portu PB
	.db 0b8h	; => 21b8h: přímé čtení z portu PC
	.db 0bfh	; => 21bfh: čtení z portu PA
			; s čekáním na STROBE na pinu PC5
	.db 0d2h	; => 21d2h: čtení z portu PB
			; s čekáním na STROBE na pinu PC1
	.db 0bfh	; => 21bfh: driver 5 <=> driver 3
	.db 0f7h	; => 21f7h: uživatelský driver
	.db 0fah	; => 21fah: uživatelský driver
; ******************************************************
; drivery GPIO 8255 pro konzolový vstup (příkazem ENTER)
; ******************************************************
X21b2:	in a,(4ch)		; driver 0
			; přímé čtení z portu PA
	.db 01h		; lxi b,X4ddb
X21b5:	in a,(4dh)		; driver 1
			; přímé čtení z portu PB
	.db 01h		; lxi b,X4edb
X21b8:	in a,(4eh)		; driver 2	
			; přímé čtení z portu PC
	ld (hl),a		; načtený bajt uložit
	inc hl		; a protože se bez strobování
	 jp X21e4	; mohlo jednat jen o jediný bajt,
			; zakončit bufer kódem 00h
X21bf:	in a,(4eh)		; driver 3
	and 20h		; počkat na strobovací signál
	jp z,X21bf	; na pinu PC5, přečíst hodnotu
	in a,(4ch)		; z portu PA
	ld (hl),a		; zapsat ji do buferu
	inc hl		; posunout ukazatel pro další bajt
	cp 0ah		; a pokud nepřišel koncový znak LF
	jp nz,X21bf	; pokračovat ve čtení celé zprávy
	 jp X21e2	; zakončit bufer a nastavit
			; ukazatel na jeho začátek
X21d2:	in a,(4eh)		; driver 4
	and 2		; počkat na strobovací signál
	jp z,X21d2	; na pinu PC1, přečíst hodnotu
	in a,(4dh)		; z portu PB
	ld (hl),a		; zapsat ji do buferu
	inc hl		; posunout ukazatel pro další bajt
	cp 0ah		; a pokud nepřišel koncový znak LF
	jp nz,X21d2	; pokračovat ve čtení celé zprávy
X21e2:	dec hl		; "odstranit" přijaté znaky CR+LF
	dec hl		; a místo nich zapsat interní
X21e4:	ld (hl),0		; ukončovací znak 00h
	ld hl,usrexec	; ukazatel do editačního buferu
	ret		; nastavit na jeho začátek
; ************************************************
; inicializace driveru USART 8251 pro příkaz ENTER
; ************************************************
			; (21eah)
idrv1c:	ld hl,X21fd	; adresu driveru pro příjem dat
	ld (X080b+1),hl	; z USARTu vnutit proceduře
	pop hl		; INPUT
	inc hl
	rst 0x08; vynutit
	.db ';'		; oddělovač středník
	 jp X214e	; a jít na INPUT
; ******************************************************
; drivery GPIO 8255 pro konzolový vstup (příkazem ENTER)
; ******************************************************
X21f7:	 jp err_09	; driver 6 - uživatelský
X21fa:	 jp err_09	; driver 7 - uživatelský
; ******************************************************
; driver USART 8251 pro konzolový vstup (příkazem ENTER)
; ******************************************************
X21fd:	call inb	; počkat na bajt z USARTu
	ld (hl),a		; zapsat jej do paměti
	inc hl
	cp 0ah		; a dokud to není koncový znak LF
	jp nz,X21fd	; číst celý seznam
	 jp X21e2	; pak zakončit bufer kódem 00h a
			; nastavit ukazatel na jeho začátek
; *************
; funkce STATUS
; *************
			; (220ah)
X220a:	push bc
	rst 0x10
	rst 0x20; načíst 1. parametr (kanál)
	rla
	rla		; pounout do horních 4 bitů, čímž
	rla		; se v registru A ustaví bázová
	rla		; adresa pro vybraný obvod/kanál
	or 0ch		; odmaskovat klávesnici a ROMPACK
	push af
	rst 0x08; vynutit
	.db ','		; oddělovací čárku mezi parametry
	rst 0x20; načíst druhý parametr
	and 3		; (jeden ze čtyř registrů vybraného
	ld c,a		; obvodu/kanálu)
	pop af
	or c		; a přidat k bázové adrese
	ld (X1613+1),a	; uložit jako parametr instrukce IN
	ex (sp),hl
	ld de,X09b4	; po vyčíslení se bude provádět
	push de		; typová kontrola
	 jp X1613	; a teď už načíst hodnotu z vybra-
			; ného portu a převést na FP číslo
; ***********
; příkaz SAVE
; ***********
			; (2227h)
c_save:	call X22b4	; inicializace ovladače a načtení
	ld (numfil),a	; čísla souboru
	ld a,'>'
	ld (typfil),a	; typ BASIC
	rst 0x10; nyní přeskočit mezery a ukazatel
	dec hl		; na text uložit do proměnné
	ld (curch),hl	; BIOSu pro čtení editačního buferu
X2237:	inc hl
	ld a,(hl)		; přeskočit veškerý další platný
	and a		; text..
	jp nz,X2237
	ld (hl),0dh	; a na konci řádku nasimulovat znak
	push hl		; CR namísto BASICovského kódu 00h
	ld hl,(varbase)
	ex de,hl		; ..s hodnotami začátku (HL)
	ld hl,(pgbase)	; a konce (DE) programu v BASICu
	ld (adrfil),hl	; zavolat rutinu BIOSu pro SAVE
	call save	; která si i načte jméno souboru..
X224d:	pop hl		; nyní obnovit ukazatel na místo
	ld (hl),0		; v editačním buferu, kde jsme
	ret		; provedli změnu a znak CR změníme
			; zpět na 00h.
; ***********
; příkaz LOAD
; ***********
			; (2251h)
c_load:	ld b,'>'
	cp 0e0h	; test na sekvenci LOAD CODE
	jp nz,X225b
	rst 0x10; přeskočit kód příkazu "CODE"
	ld b,'?'	; a typ MGF záznamu zvolit BIN
X225b:	ld a,b
	.db 1eh		; mvi e,0afh
; ************
; příkaz CHECK
; ************
			; (225dh)
c_chck:	xor a		; typ nahrávky  > (BASIC)
	push af	;               ? (CODE)
	ld (findtp),a	;              00 (CHECK)
	call X22b4	; načíst číslo souboru s jeho testem
	ld (findnr),a	; a uložit je
	push hl
	call X2395	; načíst soubor
	ld a,(typfil)	; a pokud typ načteného souboru
	cp '?'		; není BINární, pokračovat níže
	jp nz,X2277
	pop hl
	pop af
	ret		; jinak konec
			; soubor tedy není BINární, takže
			; to budou data nebo BASIC program
X2277:	call X2295	; nastavit ukazatele podle délky
	pop hl		; načteného programu
	pop af
	and a		; byl-li to jen CHECK,
	ret z		; pak konec
	ld a,(namfil)	; ale jinak (jedná se o LOAD) se
	cp '*'		; otestuje první znak jména a pokud
	ret nz		; to není hvězdička, skončili jsme
			; pokud to ale hvězdička je, jedná
			; se o chráněný soubor => pak nasta-
	ld (ochr),a	; vit příznak mazání RAM po RESETu
	ld a,0c9h
	ld (X04f2),a	; odstavit test klávesy STOP
	ld hl,837bh	; tabulku vektorů obslužných proce-
	ld (kdir),hl	; dur řídicích kláves zkrátit
	 jp X01ff	; o funkce PTL, SHIFT+RCL, SHIFT+CD
			; a ihned spustit (simulace RUN)
; **********************************************
; nalezení konce programu po jeho natažení z MGF
; **********************************************
			; (2295h)
X2295:	push hl
X2296:	xor a
	ld hl,(pgbase)	; počínaje začátkem programu
X229a:	cp (hl)		; najít tři nulové bajty za sebou,
	inc hl		; indikující konec programu
	jp nz,X229a
	cp (hl)
	inc hl
	jp nz,X229a
	cp (hl)
	inc hl
	jp nz,X229a	; nalezenou adresu uložíme jako
	ld (varbase),hl	; konec programu/začátek proměnných
	ld hl,0		; pro případ autostartu chráněného
	ld (stopadr),hl	; souboru nastavíme neplatnou
	pop hl		; adresu funkce STOP
	ret
; ******************************************************
; nastaví modifikační vektor, volaný po načtení/uložení
; hlavičky MGF záznamu a přečte a otestuje číslo souboru
; ******************************************************
			; (22b4h)
X22b4:	push hl
	ld hl,edibuff
	ld (odloz),hl
	pop hl
	call mgfhead	; modifikační vektor MGF/terminál
	rst 0x20; načtení čísla souboru
	cp 100		; a test na 00..99
	ld e,15h	; pokud je číslo větší, vyvolá se
	jp nc,X0108	; chyba ++ File bound ++
	ret
; ****************************************************
; příprava pro DLOAD a DSAVE
; načte číslo souboru, definuje modifikační vektor,
; nastaví typ souboru 44h a načte proměnnou, se kterou
; se bude pracovat
; ****************************************************
			; (22c8h)
X22c8:	call X22b4	; definice MGF vektoru a čísla
	push hl
	ld l,a
	ld h,44h
	ld (findnr),hl	; požadovaný typ/číslo souboru
	ld (numfil),hl	; načtený typ/číslo souboru
	xor a
	ld (arradr+1),a	; proměnná nebyla zadána
	pop hl
	rst 0x08; vynutit si znak středník
	.db ';'
	call varadr	; zjistit parametry pole
	dec hl
	rst 0x08
	.db ')'		; vynutit si závěrečnou závorku
	ld (curch),hl	; uložit ukazatel v editačním buferu
	ld hl,(arradr)	; otestovat třetí a čtvrtý bajt
	xor a		; proměnné, kde je uložen ukazatel
	cp h		; na samotný obsah pole
	jp z,err_02	; neplatný => chyba 02 - Arr.alloc.
	dec hl		; z hlavičky indexované proměnné
	ld d,(hl)		; (pole) načíst jeho délku a tuto
	dec hl
	ld e,(hl)
	ex de,hl
	dec hl
	ld (lenfil),hl	; uložit jako délku souboru
	ld (arrlen),hl	; a délku pole
	dec de
	dec de
	ld a,(de)		; test na první znak názvu pole
	or a		; (následná instrukce JP rozliší
	ret		; číselné/řetězcové proměnné)
; *******************************************
; fázovací FP konstanta COS >> SIN pro DEGREE
; *******************************************
X22fe:	.db 000h,000h,034h,087h	; 90.0
; **************
; příkaz RESTORE
; **************
			; (2302h)
c_rstr:	jp z,datrst	; bez parametru nastavit ukazatel
			; pro čtení DATA příkazem READ úplně
			; na začátek programu
	call rdlnnr	; jinak načíst číslo řádku,
	push hl
	call fndlin	; řádek se pokusit nalézt a pokud
	jp nc,err_0b	; neexistuje, chyba 0Bh - Numb.nonex
	ld h,b
	ld l,c
	dec hl
	ld (dataadr),hl	; adresu nalezeného řádku uložit
	pop hl
	ret
; **********
; funkce ADR
; **********
; Funkce ADR vrací ukazatel na třetí bajt šestibytové
; proměnné. U číselných proměnných tam začíná vlastní
; hodnota čísla, u řetězcových tam je délka, nulový bajt
; a adresa, kde se nalézá vlastní obsah řetězce.
			; (2317h)
X2317:	rst 0x10; defacto přeskočit mezery
	rst 0x08; vynutit si
	.db '('		; levou závorku
	call varadr	; do DE uložit adresu proměnné
	rst 0x08; a vynutit si
	.db ')'		; pravou závorku
X231f:	ld c,e
	ld a,d
	 jp X164a	; adresu převést na FP číslo
; **********
; příkaz ROM
; **********
c_rom:	rst 0x20; načíst short int (8 bitů)
	and 7		; parametr N ořezat na rozsah 0..7
	push hl
	rlca		; a z toho vyrobit počáteční adresu
	rlca		; pro přenos dat z ROMPACKu do RAM
	add a,24h		; s hodnotou 2400h + (N x 400h)
	ld (c_roml+1),a
	call transfer	; přenos dat z ROMPACKu do RAM
c_roml:	.dw 0000h	; výchozí adresa v ROMPACKu
	.dw 0500h	; délka přenášeného bloku (501h!)
	.dw romarea	; cílová adresa v RAM (běžně 7000h)
	pop hl
	 jp romarea	; a načtený kód ihned spustit..
; *************
; příkaz GCLEAR
; *************
c_gclr:	xor a		; vynulovat číslo tiskového sloupce
	ld (colpos),a	; pro příkaz POS
	ld a,1ch	; samotné vymazání obrazovky tiskem
	 jp prtout	; znaku s ASCII kódem 28 (1Ch)
			; FS (FILE SEPARATOR)
; ************
; příkaz DSAVE
; ************
			; (2345h)
c_dsav:	call X22c8	; načíst číslo souboru, nadefinovat
			; typ záznamu 'D' jako DATA, zjistit
			; adresu požadovaného pole
	ld hl,(arradr)	; adresu, kde začíná požadované pole
	ld (adrfil),hl	; uložit jako začátek MGF záznamu
	jp p,X2373	; skok při číselných proměnných
			; (u nich je pozice v paměti jasná)
			; uložení řetězcového pole:
	ld hl,0ffffh	; inicializovat délku bloku s texty
	ld (lenfil),hl	; jednotlivých prvků pole
	call X23d4	; BC = dimenze pole (B je nulové)
			; DE = adresa konce pole
			; HL = adresa 1. prvku pole
X235a:	ld c,(hl)		; z aktuálního prvku pole zjistit
	push hl		; délku textu
	ld hl,(lenfil)	; a přičíst k proměnné "lenfil",
	add hl,bc		; která tentokrát neurčuje délku
	inc hl		; celého souboru ale jen délku
	ld (lenfil),hl	; "textové" části bez samotné
	pop hl		; datové struktury
	inc hl
	inc hl
	inc hl
	inc hl		; posun na další prvek pole
	rst 0x18; otestovat konec pole
	jp nz,X235a	; a sečíst délky všech prvků pole
	ld hl,X20c2	; po natažení hlavičky (společná
	ld (ram+2),hl	; část s číselnými poli) se spustí
			; specifická rutina pro řetězcová
			; pole
; ****************************************************
; rutina DSAVE pro uložení číselných polí na MGF pásku
; (společná část i pro řetězcová pole)
; ****************************************************
X2373:	ld hl,(curch)	; ukončovací kód řádku v editačním
	dec hl		; buferu (00h) zaměnit za kód
X2377:	inc hl		; CR (0Dh)
	ld a,(hl)
	and a
	jp nz,X2377
	ld (hl),0dh
	push hl		; zapamatovat si adresu záměny
	call save2	; načíst název souboru a uložit blok
			; paměti na MGF
	 jp X224d	; na konci editačního buferu obnovit
			; kód konce řádku (00h) namísto
			; dočasně zapsaného kódu CR (0Dh)
; ************
; příkaz DLOAD
; ************
			; (2386h)
c_dloa:	call X22c8	; načíst číslo souboru, nadefinovat
			; typ záznamu 'D' jako DATA, zjistit
			; adresu požadované proměnné (pole)
	ld hl,X23a4	; adresa obslužné rutiny pro číselné
	jp p,X2392
	ld hl,X1f6a	; a pro řetězcové proměnné
X2392:	ld (ram+2),hl
X2395:	call shead	; natáhnout blok dat
			; a vykonat obslužnou rutinu
	ld e,17h	; „File error“
	jp nz,X0108	; při chybě CRC
	jp c,X0108	; nebo chybě časování
	ld hl,(curch)	; obnovit ukazatel na program
	ret		; a konec příkazu
; ***************************************************
; Tato procedura se vykoná ihned po natažení hlavičky
; datového bloku v případě, že chci natahovat číselné
; pole - porovnají se délky požadovaného pole a pole
; na MGF pásce a pokud je vše OK, procedura končí
; a datový blok se prostě natáhne. Jinak hlásí chybu.
; ***************************************************
			; (23A4h)
X23a4:	ld hl,(lenfil)	; délku pole na MGF pásce
X23a7:	ex de,hl
	ld hl,(arrlen)	; a délku pole v paměti
	rst 0x18; porovnat
	ld hl,(arradr)	; připravit si ukazatel na pole a
	ret z		; pokud se velikosti shodují, jde
			; se nahrávat samotná data
	ld e,12h	; jinak chyba 12h - File small
	rst 0x28
; ***********************************************
; záplata příkazu LIST, testující kanálový výstup
; ***********************************************
			; (23b3h)
X23b3:	call X1e33	; universální výstup přesměrovat
	dec hl		; do pracovní části obrazovky
	rst 0x10; přeskočit mezery za příkazem LIST
	cp '#'		; test na kanálový výstup
	ret nz		; při nekanálovém LISTu návrat zpět
	pop af		; jinak zrušit návratovou adresu
	rst 0x10; přeskočit případné mezery
	ld bc,c_otdr	; připravit tabulku driverů OUTPUT
	push hl
	ld hl,X0403	; načíst návratovou adresu do LISTu
	 jp X2079 	; a inicializovat vybraný driver
; *************************************************
; inicializace driveru USART 8251 pro příkaz OUTPUT
; *************************************************
			; (23c7h)
odrv1c:	ld hl,usartout	; přesměrování konzolového výstupu
	ld (cout+1),hl	; na USART (využije se driver BIOSu)
	pop hl
	inc hl
	rst 0x08; vynutit oddělovací
	.db ';'		; středník
	 jp X2047	; a jít přímo na příkaz PRINT
; ********************************************************
; příprava pro DLOAD/DSAVE a řetězcová pole
; ********************************************************
; v BC vrací dimenzi pole 1 = A$(x), 2 = A$(x,y), ...
; v DE vrací koncovou adresu pole
; v HL vrací adresu za hlavičkou řetězcového pole, ukazuje
;      tedy na první (čtyřbajtový) prvek pole
; ********************************************************
X23d4:	ld hl,(arrlen)	; délka hlavičky řetězcového pole
	inc hl		; se uloží tam, kde zpravidla bývá
	ld (adrfil),hl	; začátek datového bloku
	ex de,hl
	ld hl,(arradr)	; adresa začátku pole
	push hl
	add hl,de
	ex de,hl
	pop hl
	ld c,(hl)
	ld b,0
	inc hl
	add hl,bc
	add hl,bc
	ret
; *******************************************************
; vyšle znak z paměti na adrese HL na USART a aktualizuje
; kontrolní součet - pomocná procedura pro DSAVE
; *******************************************************
			; (23eah)
X23ea:	ld a,(hl)		; znak z (HL) poslat na USART
	call usartout
	ld a,(hl)		; aktualizovat kontrolní součet
	add a,b		; v registru B
	ld b,a
	inc hl
	ret
; *******************************
; proměnná pro výpočet funkce RND
; *******************************
X23f3:	.db 00h		; pořadí aditivní konstanty
; *********************************************
; následující obsah se už z ROMPACKu nekopíruje
; *********************************************
; ***********************
; nevyužitý zbytek paměti
; ***********************
basic_end:
X23f4:
; zkraceni na delku potrebnou pro rmm
.if RMM
v_dgrd  .equ X23f4 + 9
oneradr .equ X23f4 + 10
; puvodne
.else
  .db 0e5h,00h,00h,00h,00h,00h,00h,00h,00h
; ********
; proměnné
; ********
		; (23fdh)
v_dgrd:	 .db 0	; RAD(00h)/DEG(nenulový obsah)
oneradr: .dw 0	; ON ERROR GOTO (ukazatel na GOTO)
.endif
	.end
