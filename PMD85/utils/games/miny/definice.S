  .include "add_def.S"
  .section .bss
  
  .globl ColorMode,ColAtr,PoleSize,Prnpos,MysSensitivity,Time,TimeRun,GameOver,CursorFlash
  .globl PocetMin,PocetSousedu,RptDly,RptKad,SeznamSousedu
  .globl F_Left,F_Right,F_Up,F_Down,ZbytekMin,PoziceCasu,PozicePoctuMin,PoziceObliceje,AdresaObliceje,AdresaCasu
  .globl VolnychBunek

		.org 0c430h	; proměnné hry
ColorMode:	.ds 1	; číslo barevného režimu
ColAtr:		.ds 2	; registr atributu barvy
PoleSize:	.ds 1	; velikost minového pole
Prnpos:		.ds 2	; pozice tisku interním fontem
MysSensitivity:	.ds 1	; citlivost myši
Time:		.ds 4	; aktuální čas
TimeRun:		.ds 1	; povolení běhu času
GameOver:	.ds 1	; 0 = GameOver:, ANY = hra
CursorFlash:	.ds 1	; zpomalovač blikání kurzoru
		.org 0c470h
PocetMin:	.ds 1	; počet vlajek kolem analyzované buňky
PocetSousedu:	.ds 1	; počet neodhalených sousedů kolem..
RptDly:		.ds 1	; časovač spuštění AUTOREPEATu
RptKad:		.ds 1	; časovač kadence AUTOREPEATu
		.org 0c4b0h
SeznamSousedu:	.ds 16	; seznam neodhalených sousedů kolem
			; buňky při její analýze
			; ********************************* 
			; v následujícím bloku nepřehazovat
			; pořadí proměnných!!!
			; ********************************* 
	.org 0c4f0h	; proměnné, které se hromadně kopírují
			; podle velikosti minového pole
F_Left:		.ds 1	; číslo první platné buňky zleva
F_Right:		.ds 1	; číslo buňky napravo od poslední
F_Up:		.ds 1	; číslo první platné buňky shora
F_Down:		.ds 1	; číslo buňky pod poslední platnou
ZbytekMin:	.ds 2	; počet min v minovém poli dané velik.
PoziceCasu:	.ds 2	; adresa tisku času v záhlaví
			; (interní kódování PRINTu)
PozicePoctuMin:	.ds 2	; adresa tisku zbylých min v záhlaví
			; (interní kódování PRINTu)
PoziceObliceje:	.ds 2	; pixelová pozice LH rohu
AdresaObliceje:	.ds 2	; adresa obličeje ve videoram
AdresaCasu:	.ds 2	; adresa tisku času v záhlaví
			; (fyzická adresa ve videoram)
	.org 0c530h	; pokračování proměnných levelu
VolnychBunek:	.ds 2	; počet volných buněk v minovém poli
			; ******************************* 
			; v předchozím bloku nepřehazovat
			; pořadí proměnných!!!
			; ******************************* 
