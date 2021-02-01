  .include "add_def.S"
  .include "add_scr.S"
  .section .text.script
  .globl txtJmeno,txtBestP1Time,txtBestP2Time,txtBestP3Time
  .globl txtBestP1Name,txtBestP2Name,txtBestP3Name
  .globl ZobrazSestavu,txtLevelValue,txtColorValue,txtMouseValue
; *******************************************
; Zobrazí sestavu grafických objektů (script)
; vstup: A = číslo sestavy
; *******************************************
ZobrazSestavu:
	ld hl,tbZobrSest
	rst 0x18; vybrat sestavu dle hodnoty v A
ZobrazSestavuLoop:
	ld de,ZobrazSestavuLoop
	push de		; uložit návratovou adresu
	ld e,(hl)		; načíst adresu ovladače
	inc hl
	ld d,(hl)
	inc hl
	ex de,hl		; pozici v seznamu uschovat do DE
	jp (hl)		; volat ovladač grafického objektu
; *******************************************************
; Tabulka sestav grafických objektů
; První tři sestavy odpovídají rámečkům dle velikosti hry
; *******************************************************
tbZobrSest:
	.dw tbZobrMala		; #0 rámeček malé hry
	.dw tbZobrStredni	; #1 rámeček střední hry
	.dw tbZobrVelka		; #2 rámeček velké hry
	.dw tbVstupniMenu	; #3 úvodní menu
	.dw tbRefreshMenu	; #4 překreslení barev v menu
	.dw tbZadejJmeno	; #5 editace jména rekordmana
; *************************************
; Jednotlivé sestavy grafických objektů
; *************************************
; vykreslí hrací pole 9x9
tbZobrMala:
	.dw NastavBarvu
	.db 10
	.dw AplikujVodorovnouMasku,PlayArea+(35*64)+13
	.db 20,1
	.dw ZobrazObraz,ImgHeader0,PlayArea+(36*64)+13
	.dw RamSvisly,0f0fh,PlayArea+(56*64)+32
	.db 65
	.dw AplikujSvislouMasku,PlayArea+(38*64)+33
	.db 0feh,151
	.dw RamVodorovny,PlayArea+(13*14*64)+14
	.db 18
	.dw AplikujVodorovnouMasku,PlayArea+(((13*14)+4)*64)+13
	.db 20,1
	.dw AplikujVodorovnouMasku,PlayArea+(((13*14)+5)*64)+14
	.db 19,2
	.dw RamSvisly,1e1eh,PlayArea+(56*64)+13
	.db 63
	.dw RamSvisly,3e3eh,PlayArea+(91*2*64)+13
	.db 2
	.dw ScriptKonec
; vykreslí hrací pole 15x15
tbZobrStredni:
	.dw NastavBarvu
	.db 10
	.dw AplikujVodorovnouMasku,PlayArea-(21*64)+7
	.db 32,1
	.dw ZobrazObraz,ImgHeader1,PlayArea-(20*64)+7
	.dw RamSvisly,0f0fh,PlayArea+(0*64)+38
	.db 107
	.dw AplikujSvislouMasku,PlayArea-(17*64)+39
	.db 0feh,234
	.dw RamVodorovny,PlayArea+8+(15*14*64)
	.db 30
	.dw AplikujVodorovnouMasku,PlayArea+(((15*14)+4)*64)+7
	.db 32,1
	.dw AplikujVodorovnouMasku,PlayArea+(((15*14)+5)*64)+8
	.db 31,2
	.dw RamSvisly,1e1eh,PlayArea+(0*64)+7
	.db 105
	.dw RamSvisly,3e3eh,PlayArea+(105*2*64)+7
	.db 2
	.dw ScriptKonec
; vykreslí hrací pole 21x16
tbZobrVelka:
	.dw NastavBarvu
	.db 10
	.dw AplikujVodorovnouMasku,PlayArea+1-(21*64)
	.db 44,1
	.dw ZobrazObraz,ImgHeader2,PlayArea+1-(20*64)
	.dw RamSvisly,0f0fh,PlayArea+44
	.db 114
	.dw AplikujSvislouMasku,PlayArea+45-(18*64)
	.db 0feh,248
	.dw RamVodorovny,PlayArea+2+(16*14*64)
	.db 42
	.dw AplikujVodorovnouMasku,PlayArea+1+(((16*14)+4)*64)
	.db 44,1
	.dw AplikujVodorovnouMasku,PlayArea+2+(((16*14)+5)*64)
	.db 43,2
	.dw RamSvisly,1e1eh,PlayArea+1
	.db 112
	.dw RamSvisly,3e3eh,PlayArea+1+(112*2*64)
	.db 2
	.dw ScriptKonec
; vykreslí titulní obrazovku (prvotní vykreslení)
tbVstupniMenu:
	.dw ScriptClsVideoram
	.dw NastavBarvu
	.db 1
	.dw ZobrazMaskovanyObraz,ImgLogo,0c401h
	.dw NastavBarvu
	.db 9
	.dw ZobrazMaskovanyObraz,ImgVylozky,0cd01h
	.dw NastavBarvu
	.db 2
	.dw TiskniText,MenuBst+MenuBsX+4,txtBestPlayers
	.dw AplikujSvislouMasku,MenuBst+(MenuBsX*3/2-1)+6
	.db 0dfh,12
	.dw NastavBarvu
	.db 3
	.dw TiskniText,MenuP1+MenuBsX,txtBestP1
	.dw AplikujSvislouMasku,MenuP1+(MenuBsX*3/2-1)
	.db 0dfh,12
	.dw TiskniText,MenuP2+MenuBsX,txtBestP2
	.dw AplikujSvislouMasku,MenuP2+(MenuBsX*3/2-1)
	.db 0dfh,12
	.dw TiskniText,MenuP3+MenuBsX,txtBestP3
	.dw AplikujSvislouMasku,MenuP3+(MenuBsX*3/2-1)
	.db 0dfh,12
	.dw NastavBarvu
	.db 4
	.dw TiskniText,MenuLev+8,txtLevel
	.dw AplikujSvislouMasku,MenuLev+11
	.db 0dfh,12
	.dw NastavBarvu
	.db 5
	.dw TiskniText,MenuCol+8,txtColor
	.dw AplikujSvislouMasku,MenuCol+11
	.db 0dfh,12
	.dw NastavBarvu
	.db 6
	.dw TiskniText,MenuMou+8,txtMouse
	.dw AplikujSvislouMasku,MenuMou+11
	.db 0dfh,12
	.dw NastavBarvu
	.db 7
	.dw TiskniText,MenuEOL+4,txtPressEol
	.dw AplikujSvislouMasku,MenuEOL+5
	.db 0dfh,12
	.dw NastavBarvu
	.db 8
	.dw TiskniText,MenuCpy+8,txtCopyright
	.dw AplikujSvislouMasku,MenuCpy+11
	.db 0dfh,12
	.dw ScriptKonec
; vykreslí titulní obrazovku (překreslení při změně palety)
; kreslí do pomocné videoram, následně nutno překopírovat!
tbRefreshMenu:
	.dw ScriptClsTemp
	.dw NastavBarvu
	.db 1
	.dw ZobrazMaskovanyObraz,ImgLogo,0c401h-8000h
	.dw NastavBarvu
	.db 9
	.dw ZobrazMaskovanyObraz,ImgVylozky,0cd01h-8000h
	.dw NastavBarvu
	.db 2
	.dw TiskniText,MenuBst+MenuBsX+4-8000h,txtBestPlayers
	.dw AplikujSvislouMasku,MenuBst+(MenuBsX*3/2-1)+6-8000h
	.db 0dfh,12
	.dw NastavBarvu
	.db 3
	.dw TiskniText,MenuP1+MenuBsX-8000h,txtBestP1
	.dw AplikujSvislouMasku,MenuP1+(MenuBsX*3/2-1)-8000h
	.db 0dfh,12
	.dw TiskniText,MenuP2+MenuBsX-8000h,txtBestP2
	.dw AplikujSvislouMasku,MenuP2+(MenuBsX*3/2-1)-8000h
	.db 0dfh,12
	.dw TiskniText,MenuP3+MenuBsX-8000h,txtBestP3
	.dw AplikujSvislouMasku,MenuP3+(MenuBsX*3/2-1)-8000h
	.db 0dfh,12
	.dw NastavBarvu
	.db 4
	.dw TiskniText,MenuLev+8-8000h,txtLevel
	.dw AplikujSvislouMasku,MenuLev+11-8000h
	.db 0dfh,12
	.dw NastavBarvu
	.db 5
	.dw TiskniText,MenuCol+8-8000h,txtColor
	.dw AplikujSvislouMasku,MenuCol+11-8000h
	.db 0dfh,12
	.dw NastavBarvu
	.db 6
	.dw TiskniText,MenuMou+8-8000h,txtMouse
	.dw AplikujSvislouMasku,MenuMou+11-8000h
	.db 0dfh,12
	.dw NastavBarvu
	.db 7
	.dw TiskniText,MenuEOL+4-8000h,txtPressEol
	.dw AplikujSvislouMasku,MenuEOL+5-8000h
	.db 0dfh,12
	.dw NastavBarvu
	.db 8
	.dw TiskniText,MenuCpy+8-8000h,txtCopyright
	.dw AplikujSvislouMasku,MenuCpy+11-8000h
	.db 0dfh,12
	.dw ScriptKonec
; předtisk editace jména rekordmana
tbZadejJmeno:
	.dw NastavBarvu
	.db 11
	.dw RamSvisly,3e3eh,EnterNm+0dh-100h
	.db 18
	.dw RamSvisly,1f1fh,EnterNm+0eh
	.db 6
	.dw RamVodorovny,EnterNm+0eh-100h
	.db 19
	.dw RamVodorovny,EnterNm+0eh+300h
	.db 19
	.dw RamVodorovny,EnterNm+0eh+700h
	.db 19
	.dw RamSvisly,3f3fh,EnterNm+21h-100h
	.db 18
	.dw RamSvisly,1f1fh,EnterNm+22h-100h
	.db 18
	.dw RamSvisly,3f3fh,EnterNm+0eh+400h
	.db 6
	.dw RamSvisly,3f3fh,EnterNm+0fh+400h
	.db 6
	.dw RamSvisly,3f3fh,EnterNm+10h+400h
	.db 6
	.dw RamSvisly,1f1fh,EnterNm+11h+400h
	.db 6
	.dw RamVodorovny,EnterNm+1bh+400h
	.db 6
	.dw RamVodorovny,EnterNm+1bh+500h
	.db 6
	.dw RamVodorovny,EnterNm+1bh+600h
	.db 6
	.dw NastavBarvu
	.db 12
	.dw TiskniText,EnterNm+0ah,txtZadejJmeno
	.dw AplikujVodorovnouMasku,EnterNm+0dh-140h
	.db 22,1
	.dw AplikujSvislouMasku,EnterNm+23h
	.db 0fch,35
	.dw AplikujVodorovnouMasku,EnterNm+80dh
	.db 22,1
	.dw AplikujVodorovnouMasku,EnterNm+84eh
	.db 21,2
	.dw NastavBarvu
	.db 13
	.dw ScriptKonec
; ***********************
; texty titulní obrazovky
; ***********************
txtBestPlayers:
	.db _B,_E,_S,_T,__,_P,_L,_A,_Y,_E,_R,_S+80h
txtBestP1:
	.db 0,9,_X,0,9,__
txtBestP1Name:
	.db _P,_M,_D,_MIN,8,5,__
txtBestP1Time:
	.db 9,9,9,__,_S,_E,_C+80h
txtBestP2:
	.db 1,5,_X,1,5,__
txtBestP2Name:
	.db _P,_M,_D,_MIN,8,5,__
txtBestP2Time:
	.db 9,9,9,__,_S,_E,_C+80h
txtBestP3:
	.db 2,1,_X,1,6,__
txtBestP3Name:
	.db _P,_M,_D,_MIN,8,5,__
txtBestP3Time:
	.db 9,9,9,__,_S,_E,_C+80h
txtLevel:
	.db _L,_DBL,__,_L,_E,_V,_E,_L,__
txtLevelValue:
	.db _SPC,_SPC,_SPC,_SPC,_SPC,_SPC,_SPC+80h
txtColor:
	.db _C,_DBL,__,_C,_O,_L,_O,_R,__
txtColorValue:
	.db _SPC,_SPC,_SPC,_SPC,_SPC,_SPC,_SPC+80h
txtMouse:
	.db _M,_DBL,__,_M,_O,_U,_S,_E,__
txtMouseValue:
	.db _SPC,_SPC,_SPC,_SPC,_SPC,_SPC,_SPC+80h
txtPressEol:
	.db _P,_R,_E,_S,_S,__,_E,_O,_L,__,_T,_O,__,_S,_T,_A
	.db _R,_T,__,_G,_A,_M,_E,_SCR+80h
txtCopyright:
.if OSS_USE
	.db 2,0,2,0,_SPC,_K,_I,_Z,_A,_R,_M
	.db _SPC,_O,_S,_S,_DOT+80h
.else
  .db 2,0,2,0,_SPC,_SPC,_L,_I,_B,_O,_R
  .db _SPC,_L,_DOT,_A,_DOT+80h
.endif
txtZadejJmeno:
	.db __,_E,_N,_T,_E,_R,__,_N,_A,_M,_E,__+80h

txtJmeno:
	.db _SPC,_SPC,_SPC,_SPC,_SPC,_SPC

; ****************************
; Implementace příkazů scriptu
; ****************************
; nastaví barvu pro další kreslení do ColAtr
NastavBarvu:
	ex de,hl
	ld a,(hl)
	inc hl
	push hl
	call SetCol
	pop hl
	ret
; svislá část rámečků minového pole
RamSvisly:
	ex de,hl
	ld c,(hl)
	inc hl
	ld b,(hl)
	inc hl
	ex de,hl
	ld hl,(ColAtr)
	add hl,bc
	ld b,h
	ld c,l
	ex de,hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	ld a,(hl)
	inc hl
	push hl
	ex de,hl
	ld de,64
RamSvislyLoop:
	ld (hl),c
	add hl,de
	ld (hl),b
	add hl,de
	dec a
	jp nz,RamSvislyLoop
ScriptKonec:
	pop hl
	ret
; vodorovná část rámečků minového pole
RamVodorovny:
	ex de,hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	ld a,(hl)
	inc hl
	push hl
	ld hl,(ColAtr)
	ld bc,3f3fh
	add hl,bc
	ld b,h
	ld c,l
	ex de,hl
	ld de,64
	call RamVodorovny1
	pop hl
	ret
RamVodorovny1:
	call RamVodorovny2
RamVodorovny2:
	call RamVodorovny4
RamVodorovny4:
	push af	; celkem 4 mikrořádky
	push hl
RamVodorovneX:
	ld (hl),c		; E = 0x3F + atribut
	inc hl		; posun doprava
	dec a		; odpočet šířky rámečku
	jp nz,RamVodorovneX
	pop hl
	add hl,de		; adresa dalšího mikrořádku
	ld a,c		; prohodit atribut Colorace
	ld c,b
	ld b,a
	pop af		; obnovit šířku rámečku
	ret
; zobrazí obrázek nastavenou barvou
ZobrazObraz:
	ex de,hl
	ld c,(hl)
	inc hl
	ld b,(hl)
	inc hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	push hl
	ld h,b
	ld l,c
	call ShowImage
	pop hl
	ret
; zobrazí obrázek s integrovanou maskou
ZobrazMaskovanyObraz:
	ex de,hl
	ld c,(hl)
	inc hl
	ld b,(hl)
	inc hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	push hl
	ex de,hl
	call ShowMaskedImage
	pop hl
	ret
; odfiltruje svislou sekvenci pixelů pomocí bajtové masky
AplikujSvislouMasku:
	ex de,hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	ld c,(hl)
	inc hl
	ld b,(hl)
	inc hl
	push hl
	ex de,hl
	ld de,64
AplikujSvislouMaskuLoop:
	ld a,(hl)
	and c
	ld (hl),a
	add hl,de
	dec b
	jp nz,AplikujSvislouMaskuLoop
	pop hl
	ret
; odfiltruje vodorovnou sekvenci pixelů (N mikrořádků)
AplikujVodorovnouMasku:
	ex de,hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	ld c,(hl)
	inc hl
	ld b,(hl)
	inc hl
	push hl
	ex de,hl
	ld de,64
AplikujVodorovnouMaskuY:
	push bc
	push hl
AplikujVodorovnouMaskuX:
	ld a,(hl)
	and 0c0h
	ld (hl),a
	inc hl
	dec c
	jp nz,AplikujVodorovnouMaskuX
	pop hl
	add hl,de
	pop bc
	dec b
	jp nz,AplikujVodorovnouMaskuY
	pop hl
	ret
; tisk textu na zadané adrese
TiskniText:
	ex de,hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	ex de,hl
	ld (Prnpos),hl
	ex de,hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	push hl
	ex de,hl
	call prtstg
	pop hl
	ret
; Vymaže fyzickou videoram
ScriptClsVideoram:
	ex de,hl
	 jp Cls
; Vymaže pomocnou videoram
ScriptClsTemp:
	ex de,hl
	 jp ClsTemp
