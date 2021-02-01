OSS_USE         .equ 1
INIT_COLORACE   .equ 0
;;;;;;;;;;;;;;;;;;;;;;
FIX_PATTERN	    .equ 0
KONTROLUJ_MINY	.equ 0
INIT_EMU_MOUSE	.equ 0

uartdat .equ 1eh  ; datový registr UARTu 8251
uartcwr .equ 1fh  ; řídicí registr UARTu 8251
ctc1ch  .equ 5dh  ; kanál #1 časovače 8253
ctc2ch  .equ 5eh  ; kanál #2 časovače 8253
ctccwr  .equ 5fh  ; řídicí registr časovače 8253
mysport .equ 08ch ; adresa portu myši602
kbdout  .equ 0f4h ; PIO 8255 - volba sloupce kbd
kbdin .equ 0f5h ; PIO 8255 - řádkové odezva kbd
kbdled  .equ 0f6h ; PIO 8255 - LED, BEEP & BANK
kbdcwr  .equ 0f7h ; PIO 8255 - řídicí registr
PlayArea  .equ 0c601h ; pozice buňky [0,0]
        ; minového pole ve videoram
.if FIX_PATTERN
POCET_MIN_L0  .equ 16 ; počet min v levelu 9x9
POCET_MIN_L1  .equ 16 ; počet min v levelu 15x15
POCET_MIN_L2  .equ 16 ; počet min v levelu 21x16
.else
POCET_MIN_L0  .equ 10 ; počet min v levelu 9x9
POCET_MIN_L1  .equ 34 ; počet min v levelu 15x15
POCET_MIN_L2  .equ 60 ; počet min v levelu 21x16
.endif
        ; autorepeat editoru jména
RPT_DLY   .equ 100  ; doba pro spuštění autorepeatu
RPT_KAD   .equ 15   ; doba mezi znaky autorepeatu
        ; autorepeat ovladače hry
Pole  .equ  0e030h  ; hrací pole 24 x 16 buněk
      ; adresace pole: 111xxxxx 0011yyyy
        
KBDCTRL_DLY .equ 200  ; doba pro spuštění autorepeatu
KBDCTRL_KAD .equ 40   ; doba mezi znaky autorepeatu
