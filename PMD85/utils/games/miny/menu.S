  .include "add_scr.S"  
  .section .text.menu
  .globl DoMenu
; **********************************
; Vykreslení a obsluha hlavního menu
; **********************************
DoMenu:
	call ModifyMenuText	; modifikace textů
				; LEVEL/COLOR/MOUSE
	ld a,3
	call ZobrazSestavu	; tisk sestavy úvodního menu
DoMenuRelease:
	call KeyRelease		; počkat na uvolnění kláves
DoMenuLoop:
	call MoreRandom		; míchat průběžně generátorem
	ld hl,0808h		; test klávesy L(EVEL)
	rst 0x28
	jp z,ZmenaLevelu
	ld hl,0310h		; test klávesy C(OLOR)
	rst 0x28
	jp z,ZmenaColor
	ld hl,0710h		; test klávesy M(OUSE)
	rst 0x28
	jp z,ZmenaMouse
	ld hl,0d10h		; test klávesy L EOL
	rst 0x28
	ret z
	ld hl,0e10h		; test klávesy P EOL
	rst 0x28
	ret z
	 jp DoMenuLoop
; *****************************************
; Inkrementace proměnné (HL) v rozsahu 0..A
; *****************************************
IncVariable:
	inc (hl)			; inkrementace proměnné
	cp (hl)			; test překročení maxima
	ret nc			; NE => konec
	ld (hl),0			; ANO => čítám znovu od nuly
	ret
; ************
; změna levelu
; ************
ZmenaLevelu:
	call Chirp		; klik
	ld a,2			; 3 stavy (0,1,2)
	ld hl,PoleSize		; proměnné velikosti pole
	call IncVariable	; cyklicky přepínám
	call ZobrazZvolenyLevel	; vypíšu text
	 jp DoMenuRelease	; zpět do smyčky
; *****************
; zobrazovač levelu
; *****************
ZobrazZvolenyLevel:
	ld a,4			; barvu textu "LEVEL"
	call SetCol		; vyberu pro tisk
	ld hl,MenuLev+17
	ld (Prnpos),hl		; nastavím pozici tisku
	ld a,(PoleSize)		; podle vybrané velikosti pole
	ld hl,tbNazvuLevelu	; z tabulky
	rst 0x18; vyberu popisný text
	 jp prtstg		; a ten vytisknu
				; názvy velikostí hracího pole
tbNazvuLevelu:
	.dw NazevLo,NazevMid,NazevHi
NazevLo:
	.db 0,9,_X,0,9,_SPC+80h
NazevMid:
	.db 1,5,_X,1,5,_SPC+80h
NazevHi:
	.db 2,1,_X,1,6,_SPC+80h
; ********************
; změna barevného módu
; ********************
ZmenaColor:
	call Chirp		; klik
	ld a,3			; 4 stavy (0,1,2,3)
	ld hl,ColorMode		; proměnné barevného režimu
	call IncVariable	; cyklicky přepínám
	call ModifyMenuText	; modifikace textů proměnných
	call SetPal		; nastavím novou paletu
	ld a,4			; tisk sestavy úvodního menu
	call ZobrazSestavu	; do pomocné videoram
	call CopyVideoram	; a tu zkopíruje do hlavní
	 jp DoMenuRelease	; zpět do smyčky
				; názvy barevných režimů
NazevMono:
	.db _M,_O,_N,_O
NazevRGBM:
	.db _R,_G,_B,_M
NazevWGRM:
	.db _W,_G,_R,_M
NazevACE:
	.db _A,_C,_E,_SPC
; ********************
; změna nastavení myši
; ********************
ZmenaMouse:
	call Chirp		; klik
	ld a,3			; 4 stavy (0,1,2,3)
	ld hl,MysSensitivity	; proměnné citlivosti myši
	call IncVariable	; cyklicky přepínám
	call ZobrazNastaveniMysi ; vypíšu text
	 jp DoMenuRelease	; zpět do smyčky
; *************************
; zobrazovač nastavení myši
; *************************
ZobrazNastaveniMysi:
	ld a,6			; barvu textu "MOUSE"
	call SetCol		; vyberu pro tisk
	ld hl,MenuMou+17
	ld (Prnpos),hl		; nastavím pozici tisku
	ld a,(MysSensitivity)	; podle stupně citlivosti myši
	ld hl,tbNazvuMysi	; z tabulky
	rst 0x18; vyberu popisný text
	 jp prtstg		; a ten vytisknu
				; názvy nastavení myši
tbNazvuMysi:
	.dw MouseOFF,MouseSLOW,MouseNORM,MouseFAST
MouseOFF:
	.db _O,_F,_F,_SPC,_SPC+80h
MouseSLOW:
	.db _S,_L,_O,_W,_SPC+80h
MouseNORM:
	.db _N,_O,_R,_M,_SPC+80h
MouseFAST:
	.db _F,_A,_S,_T,_SPC+80h
; ***********************************
; Modifikuje text menu dle proměnných
; ***********************************
ModifyMenuText:
	ld a,(PoleSize)		; do sestavy MENU předtiskne
	ld hl,tbNazvuLevelu	; volbu LEVEL
	rst 0x18
	ld de,txtLevelValue
	ld c,5
	rst 0x08
	ld a,(ColorMode)		; do sestavy MENU předtiskne
	add a,a
	add a,a
	ld hl,NazevMono		; volbu COLOR
	rst 0x10
	ld de,txtColorValue
	ld c,4
	rst 0x08
	ld a,(MysSensitivity)	; do sestavy MENU předtiskne
	ld hl,tbNazvuMysi	; volbu MYS
	rst 0x18
	ld de,txtMouseValue
	ld c,4
	rst 0x08
	ret
