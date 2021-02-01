  .section .text.grafika
  .globl CopyVideoram,ShowImage,InvertFace,ShowMaskedImage,ClsTemp,Cls
; *********************************************************
; Zkopíruje záložní obrazovku od 4000h do fyzické obrazovky
; od C000h. Kvůli rychlosti je volena metoda přenosu dat
; za pomoci registru ukazatele zásobníku SP.
; *********************************************************
.macro CopyVideo2
  pop bc
  ld (hl),c
  inc hl
  ld (hl),b
  inc hl
.endm
CopyVideoram:
	ld hl,0		; uschovat hodnotu reg. SP
	add hl,sp
	ld (CopyVideoramSP+1),hl
	ld sp,4000h	; odkud
	ld hl,0c000h	; kam
CopyVideoramLoop:
	CopyVideo2	; zkopírovat 24 dvojic bajtů
	CopyVideo2	; pomocí makra "CopyVideo2"
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	CopyVideo2
	ld hl,16	; přeskočit "zápisník" v záložní
	add hl,sp		; videoram od 4000h
	ld sp,hl
	ld hl,8000h	; a adekvátně přeskočit i "zápisník"
	add hl,sp		; ve fyzické vydeoram
	jp nc,CopyVideoramLoop ; do vyčerpání videoram opakuj..
CopyVideoramSP:
	ld sp,0	; obnovit hodnotu reg. SP
	ret
; ****************************
; Kreslí RAW bitmapový obrázek
; DE = pozice ve videoram
; HL = předloha včetně rozměrů
; ****************************
ShowImage:
	ld c,(hl)		; načíst rozměr X obrázku
	inc hl
	ld b,(hl)		; načíst rozměr Y obrázku
	inc hl
	ex de,hl		; DE = předloha bitmapy
			; HL = adresa kreslení (ve videoram)
ShowImageY:
	push bc		; uschovat rozměry obrázku
	push hl		; uschovat pozici videoram
ShowImageX:
	ld a,(ColAtr)	; načíst aktuální atribut barvy
	ex de,hl
	or (hl)		; přidat data předlohy obrázku
	ex de,hl
	inc de		; další bajt předlohy
	ld (hl),a		; a zapsat do videoram
	inc hl		; další bajt videoram
	dec c		; odpočet šířky obrázku
	jp nz,ShowImageX	; NEXT X
	ld hl,(ColAtr)	; na konci každého mikrořádku
	ld a,h		; prohodím dvojici atributů Colorace
	ld h,l
	ld l,a
	ld (ColAtr),hl
	pop hl		; obnovím adresu videoram (začátek
	ld bc,64	; mikrořádku) a přičtením 64 se dostanu
	add hl,bc		; na začátek dalšího mikrořádku
	pop bc		; obnovím rozměry obrázku
	dec b		; odečtu další mikrořádek obrázku 
	jp nz,ShowImageY	; NEXT Y
	ret
; ***************************************************
; Vykreslení obrázku s implicitní maskou pozadí
; (jedná se o pseudomasku jako alternativu k pixelům)
; BC = adresa předlohy
; HL = cílová adresa kreslení ve videoram (LH roh)
; ***************************************************
ShowMaskedImage:
	ld a,(bc)		; načíst šířku obrázku
	inc bc
	ld e,a
	ld a,(bc)		; načíst výšku obrázku
	inc bc
	ld d,a
ShowMaskedImageSwap:
	ld a,(ColAtr)	; sudý Colorace atribut barvy
	ld (ShowMaskedImageAtr+1),a ; uložit do kreslicí rutiny
	push de
	push hl
ShowMaskedImageLine:
	ld a,(bc)		; načíst bajt předlohy
	inc bc		; další bajt předlohy
	and a		; test atributu masky
	jp m,ShowMaskedImageMask ; => bajt s maskou
ShowMaskedImageAtr:
	or 0		; bajt bez masky doplnit barvou
	ld (hl),a		; a zapsat do videoram
ShowMaskedImageNext:
	inc hl		; další bajt videoram (vpravo)
	dec e		; odpočet šířky obrázku
	jp nz,ShowMaskedImageLine ; NEXT X
	ld hl,(ColAtr)	; prohodit atributy barvy Colorace
	ld a,h		; na konci každého mikrořádku
	ld h,l
	ld l,a
	ld (ColAtr),hl
	pop hl		; obnovit adresu videoram
	ld de,64	; posun na začátek dalšího mikrořádku
	add hl,de
	pop de		; obnovit rozměry obrázku
	dec d		; odpočet výšky obrázku
	jp nz,ShowMaskedImageSwap ; NEXT Y
	ret
ShowMaskedImageMask:
	or 0c0h	; barvy nebudou maskou dotčeny
	and (hl)		; odmaskovat pozadí maskou
	ld (hl),a		; zapsat do videoram
	 jp ShowMaskedImageNext ; další bajt videoram
; **********************
; Inverze ikony obličeje
; **********************
InvertFace:
	ld hl,(AdresaObliceje)
	ld de,64	; posun začátku invertované oblasti
	add hl,de		; vůči jmenovitému LH rohu ikony
	ld de,61	; řádkovač
	ld c,17	; výška invertované oblasti
InvertFaceLoop:
	ld a,(hl)		; invertovat jeden mikrořádek
	xor 38h
	ld (hl),a
	inc hl
	ld a,(hl)
	xor 3fh
	ld (hl),a
	inc hl
	ld a,(hl)
	xor 3fh
	ld (hl),a
	inc hl
	ld a,(hl)
	xor 1
	ld (hl),a
	add hl,de		; přechod na nový mikrořádek
	dec c		; odpočet výšky ikony
	jp nz,InvertFaceLoop ; NEXT Y
	ret
; **************************************************
; Výmaz pomocné obrazovky od 4000h nastavenou barvou
; **************************************************
ClsTemp:
	push hl
	ld hl,0c030h-8000h
	ld (ClsOdkud+1),hl
	 jp ClsCommon
; *****************************************
; Výmaz fyzické obrazovky nastavenou barvou
; *****************************************
Cls:	push hl
	ld hl,0c030h	; vybrat zvolenou videoram
	ld (ClsOdkud+1),hl
ClsCommon:
	xor a		; COLOR(0) určuje barvu pozadí
	call SetCol
	ld de,tbClsPattern
	ld c,4		; 4 dvojice tvoří celý vzor pozadí
ClsSetPattern:
	ld a,(de)		; načtu vzor pozadí (sudý bajt)
	and 3fh		; odfiltruji starý atribut
	or l		; přidám nový sudý atribut barvy
	ld (de),a		; uložím zpět jako nově obarvený vzor
	inc de
	ld a,(de)		; načtu vzor pozadí (lichý bajt)
	and 3fh		; odfiltruji starý atribut
	or h		; přidám nový lichý atribut barvy
	ld (de),a		; uložím zpět jako nově obarvený vzor
	inc de
	dec c		; další dvojice bajtů pozadí
	jp nz,ClsSetPattern
	ld hl,0
	add hl,sp		; uschovat hodnotu ukazatele
	ld (ClsEnd+1),hl	; vrcholku zásobníku
	ld a,(ColorMode)	; vybrat vzor pozadí MONO/COLOR
	and a
	ld de,tbClsPattern ; vzorek pozadí
	jp nz,ClsOdkud
	ld de,tbClsPatNull ; prázdné pozadí
ClsOdkud:
	ld hl,0c030h	; PH roh viditelné části videoram
ClsNext:
	ld a,(de)		; načíst další bajt vzoru pozadí
	inc de
	cp -1		; a až dojdou, ukončit CLS
	jp z,ClsEnd
	ld b,a		; jinak vzor vložit do BC a vyplnit
	ld c,a		; s nimi 32 mikrořádků videoram
	ld a,32	; 32x8=256 pixelů výšky celé obrazovky
ClsLoop:	ld sp,hl
	push bc		; 24x 2 bajty = 48 bajtů mikrořádku
	push bc		; uložím 48 bajtů do fiktivního
	push bc		; zásobníku, který si vždy založím
	push bc		; na konci každého z 256-ti mikrořádků
	push bc		; videoram
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	push bc
	inc h		; další mikrořádek bude o 8 níže
	inc h		; tj. +200h
	dec a		; celkem 32x roztečí po 8 mikrořádcích
	jp nz,ClsLoop	; konec smyčky kreslení jednoho bajtu
			; vzoru pozadí
	ld bc,64-4000h	; přechod na kreslení dalšího bajtu
	add hl,bc		; vzoru pozadí
	 jp ClsNext	; kresli další z 8 bajtů vzoru pozadí
ClsEnd:	ld sp,0	; obnovit ukazatel vrcholku zásobníku
	pop hl
	ret
tbClsPattern:
	.db 1ch		; vzor pozadí pro barevné režimy
	.db 24h
	.db 24h
	.db 23h
	.db 31h
	.db 09h
	.db 09h
	.db 0eh
	.db -1
tbClsPatNull:
	.db 00h		; vzor pozadí pro monochromatický režim
	.db 00h
	.db 00h
	.db 00h
	.db 00h
	.db 00h
	.db 00h
	.db 00h
	.db -1
