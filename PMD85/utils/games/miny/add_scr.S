_A  .equ 0ah  ; kódování interního fontu
_B  .equ 0bh
_C  .equ 0ch
_D  .equ 0dh
_E  .equ 0eh
_F  .equ 0fh
_G  .equ 10h
_H  .equ 11h
_I  .equ 12h
_J  .equ 13h
_K  .equ 14h
_L  .equ 15h
_M  .equ 16h
_N  .equ 17h
_O  .equ 18h
_P  .equ 19h
_Q  .equ 1ah
_R  .equ 1bh
_S  .equ 1ch
_T  .equ 1dh
_U  .equ 1eh
_V  .equ 1fh
_W  .equ 20h
_X  .equ 21h
_Y  .equ 22h
_Z  .equ 23h
_DBL  .equ 24h  ; dvojtečka
_MIN  .equ 25h  ; mínus (pomlčka)
__  .equ 26h  ; vynechané místo (s tečkou)
_COMA .equ 27h  ; čárka
_DOT  .equ 28h  ; tečka
_SCR  .equ 29h  ; vykřičník
_LOM  .equ 2Ah  ; lomítko
_SPC  .equ 2Bh  ; mezera (plný čtverec)
FontHeight  .equ 64*12  ; výška fontu
FontSpaceL  .equ 64*4 ; základní mezera mezi řádky
FontSpaceH  .equ 64*12  ; vysoká mezera mezi řádky
MenuPos .equ 0d300h   ; pozice textů v MENU
MenuBst .equ MenuPos    ; (v pomocné videoram je adresa
MenuBsX .equ 6      ; o 8000h menší)
MenuP1  .equ MenuBst+FontHeight+FontSpaceL
MenuP2  .equ MenuP1+FontHeight+FontSpaceL
MenuP3  .equ MenuP2+FontHeight+FontSpaceL
MenuLev .equ MenuP3+FontHeight+FontSpaceH
MenuCol .equ MenuLev+FontHeight+FontSpaceL
MenuMou .equ MenuCol+FontHeight+FontSpaceL
MenuEOL .equ MenuMou+FontHeight+FontSpaceH
MenuCpy .equ MenuEOL+FontHeight+FontSpaceH
;EnterNm  .equ 0dc00h
EnterNm .equ 0db00h ; LSB != 00h

