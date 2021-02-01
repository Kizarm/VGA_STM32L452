  .section .text.bitmapy
  .globl tbBunekBW,ImgTrueOblicej,ImgOblicejOOO,ImgOblicejBack,ImgOblicejHavaj
  .globl ImgOblicejBad,ImgHeader0,ImgHeader1,ImgHeader2,ImgLogo,ImgVylozky,tbBunekRGB,tbBunekWGR,tbBunekACE
; ********************************************************
; čísla buněčných bitmap
; ********************************************************
; 00h = odhalená prázdná buňka bez sousedních min
; 01h = odhalená prázdná buňka s jednou sousední minou
; 02h = odhalená prázdná buňka se dvěmi sousedními minami
; 03h = odhalená prázdná buňka se třemi sousedními minami
; 04h = odhalená prázdná buňka se čtyřmi sousedními minami
; 05h = odhalená prázdná buňka s pěti sousedními minami
; 06h = odhalená prázdná buňka se šesti sousedními minami
; 07h = odhalená prázdná buňka se sedmi sousedními minami
; 08h = odhalená prázdná buňka s osmi sousedními minami
; 09h = mina
; 0Ah = škrtnutá mina
; 0Bh = smrtící mina
; 0Ch = nestisknutá buňka
; 0Dh = vlajka
; 0Eh = otazník
; 0Fh = stisknutá buňka
; ********************************************************
; *******************************************
; Sada textur buněk pro monochromatický režim
; *******************************************
tbBunekBW:
	.dw ImgRGB0		; #0 prázdná bez okolních min
	.dw ImgRGB1		; #1 jedna sousední mina
	.dw ImgRGB2		; #2 dvě sousední miny
	.dw ImgRGB3		; #3 tři sousední miny
	.dw ImgRGB4		; #4 čtyři sousední miny
	.dw ImgRGB5		; #5 pět sousedních min
	.dw ImgRGB6		; #6 šest sousedních min
	.dw ImgRGB7		; #7 sedm sousedních min
	.dw ImgRGB8		; #8 osm sousedních min
	.dw ImgBWMina		; #9 mina
	.dw ImgBWSkrt		; #10 škrtnutá mina
	.dw ImgBWDead		; #11 smrtící mina
	.dw ImgBWInit		; #12 neprokliknutá buňka
	.dw ImgBWVlajka		; #13 vlajka
	.dw ImgBWOtaznik	; #14 otazník
	.dw ImgBWClick		; #15 prokliknutá buňka
ImgBWMina:
	.db 000h,000h ; 0
	.db 000h,000h ; 1
	.db 020h,000h ; 2
	.db 024h,004h ; 3
	.db 038h,003h ; 4
	.db 038h,003h ; 5
	.db 03eh,00fh ; 6
	.db 038h,003h ; 7
	.db 038h,003h ; 8
	.db 024h,004h ; 9
	.db 020h,000h ; 10
	.db 000h,000h ; 11
	.db 000h,000h ; 12
	.db 000h,000h ; 13
ImgBWSkrt:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 05dh,057h ; 2
	.db 05bh,05bh ; 3
	.db 04fh,05eh ; 4
	.db 057h,05dh ; 5
	.db 061h,050h ; 6
	.db 057h,05dh ; 7
	.db 04fh,05eh ; 8
	.db 05bh,05bh ; 9
	.db 05dh,057h ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgBWDead:
	.db 080h,080h ; 0
	.db 080h,080h ; 1
	.db 0a0h,080h ; 2
	.db 0a4h,084h ; 3
	.db 0b8h,083h ; 4
	.db 0b8h,083h ; 5
	.db 0beh,08fh ; 6
	.db 0b8h,083h ; 7
	.db 0b8h,083h ; 8
	.db 0a4h,084h ; 9
	.db 0a0h,080h ; 10
	.db 080h,080h ; 11
	.db 080h,080h ; 12
	.db 080h,080h ; 13
ImgBWInit:
	.db 02ah,00ah ; 0
	.db 015h,015h ; 1
	.db 02ah,00ah ; 2
	.db 015h,015h ; 3
	.db 02ah,00ah ; 4
	.db 015h,015h ; 5
	.db 02ah,00ah ; 6
	.db 015h,015h ; 7
	.db 02ah,00ah ; 8
	.db 015h,015h ; 9
	.db 02ah,00ah ; 10
	.db 015h,015h ; 11
	.db 02ah,00ah ; 12
	.db 000h,000h ; 13
ImgBWVlajka:
	.db 000h,000h ; 0
	.db 000h,000h ; 1
	.db 008h,000h ; 2
	.db 038h,000h ; 3
	.db 038h,001h ; 4
	.db 038h,003h ; 5
	.db 038h,001h ; 6
	.db 018h,000h ; 7
	.db 008h,000h ; 8
	.db 008h,000h ; 9
	.db 008h,000h ; 10
	.db 000h,000h ; 11
	.db 000h,000h ; 12
	.db 000h,000h ; 13
ImgBWOtaznik:
	.db 000h,000h ; 0
	.db 000h,000h ; 1
	.db 000h,000h ; 2
	.db 030h,001h ; 3
	.db 018h,003h ; 4
	.db 000h,003h ; 5
	.db 020h,001h ; 6
	.db 030h,000h ; 7
	.db 000h,000h ; 8
	.db 030h,000h ; 9
	.db 000h,000h ; 10
	.db 000h,000h ; 11
	.db 000h,000h ; 12
	.db 000h,000h ; 13
ImgBWClick:
	.db 000h,000h ; 0
	.db 014h,005h ; 1
	.db 02ah,00ah ; 2
	.db 014h,005h ; 3
	.db 02ah,00ah ; 4
	.db 014h,005h ; 5
	.db 02ah,00ah ; 6
	.db 014h,005h ; 7
	.db 02ah,00ah ; 8
	.db 014h,005h ; 9
	.db 02ah,00ah ; 10
	.db 014h,005h ; 11
	.db 000h,000h ; 12
	.db 000h,000h ; 13
; ********************************
; Sada textur buněk pro režim RGBM
; ********************************
tbBunekRGB:
	.dw ImgRGB0		; #0 prázdná bez okolních min
	.dw ImgRGB1		; #1 jedna sousední mina
	.dw ImgRGB2		; #2 dvě sousední miny
	.dw ImgRGB3		; #3 tři sousední miny
	.dw ImgRGB4		; #4 čtyři sousední miny
	.dw ImgRGB5		; #5 pět sousedních min
	.dw ImgRGB6		; #6 šest sousedních min
	.dw ImgRGB7		; #7 sedm sousedních min
	.dw ImgRGB8		; #8 osm sousedních min
	.dw ImgRGBMina		; #9 mina
	.dw ImgBWSkrt		; #10 škrtnutá mina
	.dw ImgRGBDead		; #11 smrtící mina
	.dw ImgRGBInit		; #12 neprokliknutá buňka
	.dw ImgRGBVlajka	; #13 vlajka
	.dw ImgRGBOtaznik	; #14 otazník
	.dw ImgRGBClick		; #15 prokliknutá buňka
ImgRGB0:
	.db 03fh,01fh ; 0
	.db 03fh,01fh ; 1
	.db 03fh,01fh ; 2
	.db 03fh,01fh ; 3
	.db 03fh,01fh ; 4
	.db 03fh,01fh ; 5
	.db 03fh,01fh ; 6
	.db 03fh,01fh ; 7
	.db 03fh,01fh ; 8
	.db 03fh,01fh ; 9
	.db 03fh,01fh ; 10
	.db 03fh,01fh ; 11
	.db 03fh,01fh ; 12
	.db 000h,000h ; 13
ImgRGB1:
	.db 03fh,01fh ; 0
	.db 03fh,01fh ; 1
	.db 03fh,01fh ; 2
	.db 01fh,01eh ; 3
	.db 00fh,01eh ; 4
	.db 01fh,01eh ; 5
	.db 01fh,01eh ; 6
	.db 01fh,01eh ; 7
	.db 01fh,01eh ; 8
	.db 00fh,01ch ; 9
	.db 03fh,01fh ; 10
	.db 03fh,01fh ; 11
	.db 03fh,01fh ; 12
	.db 000h,000h ; 13
ImgRGB2:
	.db 03fh,01fh ; 0
	.db 03fh,01fh ; 1
	.db 03fh,01fh ; 2
	.db 00fh,01ch ; 3
	.db 027h,019h ; 4
	.db 03fh,019h ; 5
	.db 03fh,01ch ; 6
	.db 00fh,01eh ; 7
	.db 027h,01fh ; 8
	.db 007h,018h ; 9
	.db 03fh,01fh ; 10
	.db 03fh,01fh ; 11
	.db 03fh,01fh ; 12
	.db 000h,000h ; 13
ImgRGB3:
	.db 03fh,01fh ; 0
	.db 03fh,01fh ; 1
	.db 03fh,01fh ; 2
	.db 00fh,01ch ; 3
	.db 027h,019h ; 4
	.db 03fh,019h ; 5
	.db 03fh,01ch ; 6
	.db 03fh,019h ; 7
	.db 027h,019h ; 8
	.db 00fh,01ch ; 9
	.db 03fh,01fh ; 10
	.db 03fh,01fh ; 11
	.db 03fh,01fh ; 12
	.db 000h,000h ; 13
ImgRGB4:
	.db 03fh,01fh ; 0
	.db 03fh,01fh ; 1
	.db 03fh,01fh ; 2
	.db 03fh,01ch ; 3
	.db 01fh,01eh ; 4
	.db 00fh,01fh ; 5
	.db 027h,01fh ; 6
	.db 027h,01ch ; 7
	.db 007h,018h ; 8
	.db 03fh,01ch ; 9
	.db 03fh,01fh ; 10
	.db 03fh,01fh ; 11
	.db 03fh,01fh ; 12
	.db 000h,000h ; 13
ImgRGB5:
	.db 03fh,01fh ; 0
	.db 03fh,01fh ; 1
	.db 03fh,01fh ; 2
	.db 007h,018h ; 3
	.db 027h,01fh ; 4
	.db 007h,01ch ; 5
	.db 03fh,019h ; 6
	.db 03fh,019h ; 7
	.db 027h,019h ; 8
	.db 00fh,01ch ; 9
	.db 03fh,01fh ; 10
	.db 03fh,01fh ; 11
	.db 03fh,01fh ; 12
	.db 000h,000h ; 13
ImgRGB6:
	.db 03fh,01fh ; 0
	.db 03fh,01fh ; 1
	.db 03fh,01fh ; 2
	.db 00fh,01ch ; 3
	.db 027h,019h ; 4
	.db 027h,01fh ; 5
	.db 007h,01ch ; 6
	.db 027h,019h ; 7
	.db 027h,019h ; 8
	.db 00fh,01ch ; 9
	.db 03fh,01fh ; 10
	.db 03fh,01fh ; 11
	.db 03fh,01fh ; 12
	.db 000h,000h ; 13
ImgRGB7:
	.db 03fh,01fh ; 0
	.db 03fh,01fh ; 1
	.db 03fh,01fh ; 2
	.db 007h,018h ; 3
	.db 03fh,019h ; 4
	.db 03fh,019h ; 5
	.db 03fh,01ch ; 6
	.db 01fh,01eh ; 7
	.db 01fh,01eh ; 8
	.db 01fh,01eh ; 9
	.db 03fh,01fh ; 10
	.db 03fh,01fh ; 11
	.db 03fh,01fh ; 12
	.db 000h,000h ; 13
ImgRGB8:
	.db 03fh,01fh ; 0
	.db 03fh,01fh ; 1
	.db 03fh,01fh ; 2
	.db 00fh,01ch ; 3
	.db 027h,019h ; 4
	.db 027h,019h ; 5
	.db 00fh,01ch ; 6
	.db 027h,019h ; 7
	.db 027h,019h ; 8
	.db 00fh,01ch ; 9
	.db 03fh,01fh ; 10
	.db 03fh,01fh ; 11
	.db 03fh,01fh ; 12
	.db 000h,000h ; 13
ImgRGBMina:
	.db 0c0h,0c0h ; 0
	.db 0c0h,0c0h ; 1
	.db 0e0h,0c0h ; 2
	.db 0e4h,0c4h ; 3
	.db 0f8h,0c3h ; 4
	.db 0f8h,0c3h ; 5
	.db 0feh,0cfh ; 6
	.db 0f8h,0c3h ; 7
	.db 0f8h,0c3h ; 8
	.db 0e4h,0c4h ; 9
	.db 0e0h,0c0h ; 10
	.db 0c0h,0c0h ; 11
	.db 0c0h,0c0h ; 12
	.db 0c0h,0c0h ; 13
ImgRGBDead:
	.db 040h,040h ; 0
	.db 040h,040h ; 1
	.db 060h,040h ; 2
	.db 064h,044h ; 3
	.db 078h,043h ; 4
	.db 078h,043h ; 5
	.db 07eh,04fh ; 6
	.db 078h,043h ; 7
	.db 078h,043h ; 8
	.db 064h,044h ; 9
	.db 060h,040h ; 10
	.db 040h,040h ; 11
	.db 040h,040h ; 12
	.db 040h,040h ; 13
ImgRGBInit:
	.db 0ffh,0cfh ; 0
	.db 0ffh,0d7h ; 1
	.db 0ffh,0cfh ; 2
	.db 0ffh,0d7h ; 3
	.db 0ffh,0cfh ; 4
	.db 0ffh,0d7h ; 5
	.db 0ffh,0cfh ; 6
	.db 0ffh,0d7h ; 7
	.db 0ffh,0cfh ; 8
	.db 0ffh,0d7h ; 9
	.db 0ffh,0cfh ; 10
	.db 0d5h,0d5h ; 11
	.db 0eah,0cah ; 12
	.db 0c0h,0c0h ; 13
ImgRGBVlajka:
	.db 0c0h,0c0h ; 0
	.db 0c0h,0c0h ; 1
	.db 0c8h,0c0h ; 2
	.db 0f8h,0c0h ; 3
	.db 0f8h,0c1h ; 4
	.db 0f8h,0c3h ; 5
	.db 0f8h,0c1h ; 6
	.db 0d8h,0c0h ; 7
	.db 0c8h,0c0h ; 8
	.db 0c8h,0c0h ; 9
	.db 0c8h,0c0h ; 10
	.db 0c0h,0c0h ; 11
	.db 0c0h,0c0h ; 12
	.db 0c0h,0c0h ; 13
ImgRGBOtaznik:
	.db 0c0h,0c0h ; 0
	.db 0c0h,0c0h ; 1
	.db 0c0h,0c0h ; 2
	.db 0f0h,0c1h ; 3
	.db 0d8h,0c3h ; 4
	.db 0c0h,0c3h ; 5
	.db 0e0h,0c1h ; 6
	.db 0f0h,0c0h ; 7
	.db 0c0h,0c0h ; 8
	.db 0f0h,0c0h ; 9
	.db 0c0h,0c0h ; 10
	.db 0c0h,0c0h ; 11
	.db 0c0h,0c0h ; 12
	.db 0c0h,0c0h ; 13
ImgRGBClick:
	.db 0eah,0cah ; 0
	.db 0d5h,0d5h ; 1
	.db 0feh,0dfh ; 2
	.db 0fdh,0dfh ; 3
	.db 0feh,0dfh ; 4
	.db 0fdh,0dfh ; 5
	.db 0feh,0dfh ; 6
	.db 0fdh,0dfh ; 7
	.db 0feh,0dfh ; 8
	.db 0fdh,0dfh ; 9
	.db 0feh,0dfh ; 10
	.db 0fdh,0dfh ; 11
	.db 0feh,0dfh ; 12
	.db 0c0h,0c0h ; 13
; ********************************
; Sada textur buněk pro režim WGRM
; ********************************
tbBunekWGR:
	.dw ImgWGRM0		; #0 prázdná bez okolních min
	.dw ImgWGRM1		; #1 jedna sousední mina
	.dw ImgWGRM2		; #2 dvě sousední miny
	.dw ImgWGRM3		; #3 tři sousední miny
	.dw ImgWGRM4		; #4 čtyři sousední miny
	.dw ImgWGRM5		; #5 pět sousedních min
	.dw ImgWGRM6		; #6 šest sousedních min
	.dw ImgWGRM7		; #7 sedm sousedních min
	.dw ImgWGRM8		; #8 osm sousedních min
	.dw ImgBWMina		; #9 mina
	.dw ImgWGRSkrt		; #10 škrtnutá mina
	.dw ImgBWDead		; #11 smrtící mina
	.dw ImgBWInit		; #12 neprokliknutá buňka
	.dw ImgBWVlajka		; #13 vlajka
	.dw ImgBWOtaznik	; #14 otazník
	.dw ImgBWClick		; #15 prokliknutá buňka
ImgWGRM0:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 07fh,05fh ; 2
	.db 07fh,05fh ; 3
	.db 07fh,05fh ; 4
	.db 07fh,05fh ; 5
	.db 07fh,05fh ; 6
	.db 07fh,05fh ; 7
	.db 07fh,05fh ; 8
	.db 07fh,05fh ; 9
	.db 07fh,05fh ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgWGRM1:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 07fh,05fh ; 2
	.db 05fh,05eh ; 3
	.db 04fh,05eh ; 4
	.db 05fh,05eh ; 5
	.db 05fh,05eh ; 6
	.db 05fh,05eh ; 7
	.db 05fh,05eh ; 8
	.db 04fh,05ch ; 9
	.db 07fh,05fh ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgWGRM2:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 07fh,05fh ; 2
	.db 04fh,05ch ; 3
	.db 067h,059h ; 4
	.db 07fh,059h ; 5
	.db 07fh,05ch ; 6
	.db 04fh,05eh ; 7
	.db 067h,05fh ; 8
	.db 047h,058h ; 9
	.db 07fh,05fh ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgWGRM3:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 07fh,05fh ; 2
	.db 04fh,05ch ; 3
	.db 067h,059h ; 4
	.db 07fh,059h ; 5
	.db 07fh,05ch ; 6
	.db 07fh,059h ; 7
	.db 067h,059h ; 8
	.db 04fh,05ch ; 9
	.db 07fh,05fh ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgWGRM4:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 07fh,05fh ; 2
	.db 07fh,05ch ; 3
	.db 05fh,05eh ; 4
	.db 04fh,05fh ; 5
	.db 067h,05fh ; 6
	.db 067h,05ch ; 7
	.db 047h,058h ; 8
	.db 07fh,05ch ; 9
	.db 07fh,05fh ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgWGRM5:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 07fh,05fh ; 2
	.db 047h,058h ; 3
	.db 067h,05fh ; 4
	.db 047h,05ch ; 5
	.db 07fh,059h ; 6
	.db 07fh,059h ; 7
	.db 067h,059h ; 8
	.db 04fh,05ch ; 9
	.db 07fh,05fh ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgWGRM6:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 07fh,05fh ; 2
	.db 04fh,05ch ; 3
	.db 067h,059h ; 4
	.db 067h,05fh ; 5
	.db 047h,05ch ; 6
	.db 067h,059h ; 7
	.db 067h,059h ; 8
	.db 04fh,05ch ; 9
	.db 07fh,05fh ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgWGRM7:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 07fh,05fh ; 2
	.db 047h,058h ; 3
	.db 07fh,059h ; 4
	.db 07fh,059h ; 5
	.db 07fh,05ch ; 6
	.db 05fh,05eh ; 7
	.db 05fh,05eh ; 8
	.db 05fh,05eh ; 9
	.db 07fh,05fh ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgWGRM8:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 07fh,05fh ; 2
	.db 04fh,05ch ; 3
	.db 067h,059h ; 4
	.db 067h,059h ; 5
	.db 04fh,05ch ; 6
	.db 067h,059h ; 7
	.db 067h,059h ; 8
	.db 04fh,05ch ; 9
	.db 07fh,05fh ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgWGRSkrt:
	.db 0bfh,09fh ; 0
	.db 0bfh,09fh ; 1
	.db 09dh,097h ; 2
	.db 09bh,09bh ; 3
	.db 08fh,09eh ; 4
	.db 097h,09dh ; 5
	.db 0a1h,090h ; 6
	.db 097h,09dh ; 7
	.db 08fh,09eh ; 8
	.db 09bh,09bh ; 9
	.db 09dh,097h ; 10
	.db 0bfh,09fh ; 11
	.db 0bfh,09fh ; 12
	.db 080h,080h ; 13
; ************************************
; Sada textur buněk pro režim Colorace
; ************************************
tbBunekACE:
	.dw ImgACE0		; #0 prázdná bez okolních min
	.dw ImgACE1		; #1 jedna sousední mina
	.dw ImgACE2		; #2 dvě sousední miny
	.dw ImgACE3		; #3 tři sousední miny
	.dw ImgACE4		; #4 čtyři sousední miny
	.dw ImgACE5		; #5 pět sousedních min
	.dw ImgACE6		; #6 šest sousedních min
	.dw ImgACE7		; #7 sedm sousedních min
	.dw ImgACE8		; #8 osm sousedních min
	.dw ImgACEMina		; #9 mina
	.dw ImgACESkrt		; #10 škrtnutá mina
	.dw ImgACEDead		; #11 smrtící mina
	.dw ImgACEInit		; #12 neprokliknutá buňka
	.dw ImgACEVlajka	; #13 vlajka
	.dw ImgACEOtaznik	; #14 otazník
	.dw ImgACEClick		; #15 prokliknutá buňka
ImgACE0:
	.db 000h,000h ; 0
	.db 0c0h,0c0h ; 1
	.db 000h,000h ; 2
	.db 0c0h,0c0h ; 3
	.db 000h,000h ; 4
	.db 0c0h,0c0h ; 5
	.db 020h,001h ; 6
	.db 0e0h,0c1h ; 7
	.db 000h,000h ; 8
	.db 0c0h,0c0h ; 9
	.db 000h,000h ; 10
	.db 0c0h,0c0h ; 11
	.db 000h,00h ; 12
	.db 0c0h,0c0h ; 13
ImgACE1:
	.db 000h,000h ; 0
	.db 080h,080h ; 1
	.db 000h,000h ; 2
	.db 0a0h,081h ; 3
	.db 030h,001h ; 4
	.db 0a0h,081h ; 5
	.db 020h,001h ; 6
	.db 0a0h,081h ; 7
	.db 020h,001h ; 8
	.db 0b0h,083h ; 9
	.db 000h,000h ; 10
	.db 080h,080h ; 11
	.db 000h,000h ; 12
	.db 080h,080h ; 13
ImgACE2:
	.db 000h,000h ; 0
	.db 000h,000h ; 1
	.db 000h,000h ; 2
	.db 030h,003h ; 3
	.db 018h,006h ; 4
	.db 000h,006h ; 5
	.db 000h,003h ; 6
	.db 030h,001h ; 7
	.db 018h,000h ; 8
	.db 038h,007h ; 9
	.db 000h,000h ; 10
	.db 000h,000h ; 11
	.db 000h,000h ; 12
	.db 000h,000h ; 13
ImgACE3:
	.db 000h,000h ; 0
	.db 040h,040h ; 1
	.db 000h,000h ; 2
	.db 070h,043h ; 3
	.db 018h,006h ; 4
	.db 040h,046h ; 5
	.db 000h,003h ; 6
	.db 040h,046h ; 7
	.db 018h,006h ; 8
	.db 070h,043h ; 9
	.db 000h,000h ; 10
	.db 040h,040h ; 11
	.db 000h,000h ; 12
	.db 040h,040h ; 13
ImgACE4:
	.db 0c0h,0c0h ; 0
	.db 0c0h,0c0h ; 1
	.db 0c0h,0c0h ; 2
	.db 0c0h,0c3h ; 3
	.db 0e0h,0c1h ; 4
	.db 0f0h,0c0h ; 5
	.db 0d8h,0c0h ; 6
	.db 0d8h,0c3h ; 7
	.db 0f8h,0c7h ; 8
	.db 0c0h,0c3h ; 9
	.db 0c0h,0c0h ; 10
	.db 0c0h,0c0h ; 11
	.db 0c0h,0c0h ; 12
	.db 0c0h,0c0h ; 13
ImgACE5:
	.db 080h,080h ; 0
	.db 080h,080h ; 1
	.db 080h,080h ; 2
	.db 0b8h,087h ; 3
	.db 098h,080h ; 4
	.db 0b8h,083h ; 5
	.db 080h,086h ; 6
	.db 080h,086h ; 7
	.db 098h,086h ; 8
	.db 0b0h,083h ; 9
	.db 080h,080h ; 10
	.db 080h,080h ; 11
	.db 080h,080h ; 12
	.db 080h,080h ; 13
ImgACE6:
	.db 040h,040h ; 0
	.db 040h,040h ; 1
	.db 040h,040h ; 2
	.db 070h,043h ; 3
	.db 058h,046h ; 4
	.db 058h,040h ; 5
	.db 078h,043h ; 6
	.db 058h,046h ; 7
	.db 058h,046h ; 8
	.db 070h,043h ; 9
	.db 040h,040h ; 10
	.db 040h,040h ; 11
	.db 040h,040h ; 12
	.db 040h,040h ; 13
ImgACE7:
	.db 000h,000h ; 0
	.db 0c0h,0c0h ; 1
	.db 000h,000h ; 2
	.db 0f8h,0c7h ; 3
	.db 000h,006h ; 4
	.db 0c0h,0c6h ; 5
	.db 000h,003h ; 6
	.db 0e0h,0c1h ; 7
	.db 020h,001h ; 8
	.db 0e0h,0c1h ; 9
	.db 000h,000h ; 10
	.db 0c0h,0c0h ; 11
	.db 000h,000h ; 12
	.db 0c0h,0c0h ; 13
ImgACE8:
	.db 000h,000h ; 0
	.db 0c0h,0c0h ; 1
	.db 000h,000h ; 2
	.db 0f0h,0c3h ; 3
	.db 018h,006h ; 4
	.db 0d8h,0c6h ; 5
	.db 030h,003h ; 6
	.db 0d8h,0c6h ; 7
	.db 018h,006h ; 8
	.db 0f0h,0c3h ; 9
	.db 000h,000h ; 10
	.db 0c0h,0c0h ; 11
	.db 000h,000h ; 12
	.db 0c0h,0c0h ; 13
ImgACEMina:
	.db 03fh,01fh ; 0
	.db 0ffh,0dfh ; 1
	.db 01fh,01fh ; 2
	.db 0dbh,0dbh ; 3
	.db 007h,01ch ; 4
	.db 0c7h,0dch ; 5
	.db 001h,010h ; 6
	.db 0c7h,0dch ; 7
	.db 007h,01ch ; 8
	.db 0dbh,0dbh ; 9
	.db 01fh,01fh ; 10
	.db 0ffh,0dfh ; 11
	.db 03fh,01fh ; 12
	.db 0c0h,0c0h ; 13
ImgACESkrt:
	.db 040h,040h ; 0
	.db 040h,040h ; 1
	.db 062h,048h ; 2
	.db 064h,044h ; 3
	.db 070h,041h ; 4
	.db 068h,042h ; 5
	.db 05eh,04fh ; 6
	.db 068h,042h ; 7
	.db 070h,041h ; 8
	.db 064h,044h ; 9
	.db 062h,048h ; 10
	.db 040h,040h ; 11
	.db 040h,040h ; 12
	.db 040h,040h ; 13
ImgACEDead:
	.db 07fh,05fh ; 0
	.db 07fh,05fh ; 1
	.db 05fh,05fh ; 2
	.db 05bh,05bh ; 3
	.db 047h,05ch ; 4
	.db 047h,05ch ; 5
	.db 041h,050h ; 6
	.db 047h,05ch ; 7
	.db 047h,05ch ; 8
	.db 05bh,05bh ; 9
	.db 05fh,05fh ; 10
	.db 07fh,05fh ; 11
	.db 07fh,05fh ; 12
	.db 040h,040h ; 13
ImgACEInit:
	.db 03fh,00fh ; 0
	.db 0ffh,0d7h ; 1
	.db 03fh,00fh ; 2
	.db 0ffh,0d7h ; 3
	.db 03fh,00fh ; 4
	.db 0ffh,0d7h ; 5
	.db 03fh,00fh ; 6
	.db 0ffh,0d7h ; 7
	.db 03fh,00fh ; 8
	.db 0ffh,0d7h ; 9
	.db 03fh,00fh ; 10
	.db 0d5h,0d5h ; 11
	.db 02ah,00ah ; 12
	.db 0c0h,0c0h ; 13
ImgACEVlajka:
	.db 03fh,01fh ; 0
	.db 0ffh,0dfh ; 1
	.db 037h,01fh ; 2
	.db 0c7h,0dfh ; 3
	.db 007h,01eh ; 4
	.db 0c7h,0dch ; 5
	.db 007h,01eh ; 6
	.db 0e7h,0dfh ; 7
	.db 037h,01fh ; 8
	.db 0f7h,0dfh ; 9
	.db 037h,01fh ; 10
	.db 0ffh,0dfh ; 11
	.db 03fh,01fh ; 12
	.db 0c0h,0c0h ; 13
ImgACEOtaznik:
	.db 03fh,01fh ; 0
	.db 0ffh,0dfh ; 1
	.db 03fh,01fh ; 2
	.db 0cfh,0deh ; 3
	.db 027h,01ch ; 4
	.db 0ffh,0dch ; 5
	.db 01fh,01eh ; 6
	.db 0cfh,0dfh ; 7
	.db 03fh,01fh ; 8
	.db 0cfh,0dfh ; 9
	.db 03fh,01fh ; 10
	.db 0ffh,0dfh ; 11
	.db 03fh,01fh ; 12
	.db 0c0h,0c0h ; 13
ImgACEClick:
	.db 02ah,00ah ; 0
	.db 0d5h,0d5h ; 1
	.db 03eh,01fh ; 2
	.db 0fdh,0dfh ; 3
	.db 03eh,01fh ; 4
	.db 0fdh,0dfh ; 5
	.db 03eh,01fh ; 6
	.db 0fdh,0dfh ; 7
	.db 03eh,01fh ; 8
	.db 0fdh,0dfh ; 9
	.db 03eh,01fh ; 10
	.db 0fdh,0dfh ; 11
	.db 03eh,01fh ; 12
	.db 0c0h,0c0h ; 13
; ************************
; Titulní logo MINESWEEPER
; ************************
ImgLogo:
	.db 47,34
	.db 000h,0beh,0bfh,0bfh,000h,0b8h,000h,0beh
	.db 000h,0beh,0bfh,000h,0beh,000h,000h,000h
	.db 0beh,000h,000h,000h,0beh,000h,0beh,0bfh
	.db 0bfh,000h,0beh,000h,000h,000h,0beh,000h
	.db 000h,000h,0beh,000h,000h,000h,0beh,000h
	.db 000h,000h,0beh,000h,000h,000h,0beh ; 0
	.db 03eh,0beh,0bfh,0bfh,03eh,0b8h,03eh,0beh
	.db 03eh,0beh,0bfh,03eh,0beh,03eh,03eh,03eh
	.db 0beh,03eh,03eh,03eh,0beh,03eh,0beh,0bfh
	.db 0bfh,03eh,0beh,03eh,03eh,03eh,0beh,03eh
	.db 03eh,03eh,0beh,03eh,03eh,03eh,0beh,03eh
	.db 03eh,03eh,0beh,03eh,03eh,03eh,0beh ; 1
	.db 03eh,0beh,0bfh,0bfh,03eh,0b8h,03eh,0beh
	.db 03eh,0beh,0bfh,03eh,0beh,03eh,03eh,03eh
	.db 0beh,03eh,03eh,03eh,0beh,03eh,0beh,0bfh
	.db 0bfh,03eh,0beh,03eh,03eh,03eh,0beh,03eh
	.db 03eh,03eh,0beh,03eh,03eh,03eh,0beh,03eh
	.db 03eh,03eh,0beh,03eh,03eh,03eh,0beh ; 2
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,03eh,03eh
	.db 0b8h,03eh,03eh,03eh,0b8h,03eh,0b8h,0bfh
	.db 0bfh,03eh,0b8h,03eh,03eh,03eh,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,03eh,03eh,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,03eh,03eh,0b8h ; 3
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,03eh,03eh
	.db 0b8h,03eh,03eh,03eh,0b8h,03eh,0b8h,0bfh
	.db 0bfh,03eh,0b8h,03eh,03eh,03eh,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,03eh,03eh,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,03eh,03eh,0b8h ; 4
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,03eh,03eh
	.db 0b8h,03eh,03eh,03eh,0b8h,03eh,0b8h,0bfh
	.db 0bfh,03eh,0b8h,03eh,03eh,03eh,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,03eh,03eh,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,03eh,03eh,0b8h ; 5
	.db 000h,000h,0beh,000h,000h,0b8h,000h,0b8h
	.db 000h,000h,0beh,000h,0b8h,000h,000h,000h
	.db 0b8h,000h,000h,000h,0b8h,000h,0b8h,000h
	.db 0beh,000h,0b8h,000h,000h,000h,0b8h,000h
	.db 000h,000h,0b8h,000h,000h,000h,0b8h,000h
	.db 000h,000h,0b8h,000h,000h,000h,0b8h ; 6
	.db 03eh,03eh,0beh,03eh,03eh,0b8h,03eh,0b8h
	.db 03eh,03eh,0beh,03eh,0b8h,03eh,000h,000h
	.db 0b8h,03eh,000h,000h,0b8h,03eh,0b8h,03eh
	.db 0beh,03eh,0b8h,03eh,000h,000h,0b8h,03eh
	.db 000h,000h,0b8h,03eh,000h,03eh,0b8h,03eh
	.db 000h,000h,0b8h,03eh,000h,03eh,0b8h ; 7
	.db 03eh,03eh,0beh,03eh,03eh,0b8h,03eh,0b8h
	.db 03eh,03eh,0beh,03eh,0b8h,03eh,080h,080h
	.db 0b8h,03eh,080h,080h,0b8h,03eh,0b8h,03eh
	.db 0beh,03eh,0b8h,03eh,080h,080h,0b8h,03eh
	.db 080h,080h,0b8h,03eh,080h,03eh,0b8h,03eh
	.db 080h,080h,0b8h,03eh,080h,03eh,0b8h ; 8
	.db 03eh,03eh,0b8h,03eh,03eh,0b8h,03eh,0b8h
	.db 03eh,03eh,0b8h,03eh,0b8h,03eh,0b8h,0bfh
	.db 0bfh,03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,0b8h,0bfh,0bfh,03eh
	.db 0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h ; 9
	.db 03eh,03eh,0b8h,03eh,03eh,0b8h,03eh,0b8h
	.db 03eh,03eh,0b8h,03eh,0b8h,03eh,0b8h,0bfh
	.db 0bfh,03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,0b8h,0bfh,0bfh,03eh
	.db 0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h ; 10
	.db 03eh,03eh,0b8h,03eh,03eh,0b8h,03eh,0b8h
	.db 03eh,03eh,0b8h,03eh,0b8h,03eh,0b8h,0bfh
	.db 0bfh,03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,0b8h,0bfh,0bfh,03eh
	.db 0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h ; 11
	.db 000h,000h,000h,080h,000h,0b8h,000h,0b8h
	.db 000h,000h,000h,000h,0b8h,000h,000h,0beh
	.db 0bfh,000h,000h,000h,0beh,000h,0b8h,000h
	.db 0b8h,000h,0b8h,000h,000h,0beh,0bfh,000h
	.db 000h,0beh,0bfh,000h,0b8h,000h,0b8h,000h
	.db 000h,0beh,0bfh,000h,0b8h,000h,0b8h ; 12
	.db 03eh,000h,03eh,086h,03eh,0b8h,03eh,0b8h
	.db 03eh,000h,03eh,03eh,0b8h,03eh,03eh,0beh
	.db 0bfh,03eh,03eh,03eh,0beh,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,03eh,0beh,0bfh,03eh
	.db 03eh,0beh,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 03eh,0beh,0bfh,03eh,0b8h,03eh,0b8h ; 13
	.db 03eh,080h,03eh,086h,03eh,0b8h,03eh,0b8h
	.db 03eh,080h,03eh,03eh,0b8h,03eh,03eh,0beh
	.db 0bfh,03eh,03eh,03eh,0beh,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,03eh,0beh,0bfh,03eh
	.db 03eh,0beh,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 03eh,0beh,0bfh,03eh,0b8h,03eh,0b8h ; 14
	.db 03eh,0b8h,03eh,0b8h,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,03eh,03eh,0b8h,03eh,03eh,0b8h
	.db 0bfh,03eh,03eh,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,03eh,0b8h,0bfh,03eh
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,0b8h ; 15
	.db 03eh,0b8h,03eh,0b8h,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,03eh,03eh,0b8h,03eh,03eh,0b8h
	.db 0bfh,03eh,03eh,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,03eh,0b8h,0bfh,03eh
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,0b8h ; 16
	.db 03eh,0b8h,03eh,0b8h,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,03eh,03eh,0b8h,03eh,03eh,0b8h
	.db 0bfh,03eh,03eh,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,03eh,0b8h,0bfh,03eh
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,0b8h ; 17
	.db 000h,0b8h,080h,0b8h,000h,0b8h,000h,0b8h
	.db 000h,0b8h,080h,000h,0b8h,000h,000h,0b8h
	.db 0bfh,080h,000h,000h,0b8h,000h,0b8h,000h
	.db 0b8h,000h,0b8h,000h,000h,0b8h,0bfh,000h
	.db 000h,0b8h,0bfh,000h,000h,000h,0b8h,000h
	.db 000h,0b8h,0bfh,000h,000h,080h,0b8h ; 18
	.db 03eh,0b8h,087h,0b8h,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,087h,03eh,0b8h,03eh,000h,0b8h
	.db 0bfh,087h,000h,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,000h,0b8h,0bfh,03eh
	.db 000h,0b8h,0bfh,03eh,03eh,03eh,0b8h,03eh
	.db 000h,0b8h,0bfh,03eh,03eh,086h,0b8h ; 19
	.db 03eh,0b8h,087h,0b8h,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,087h,03eh,0b8h,03eh,080h,0b8h
	.db 0bfh,087h,080h,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,080h,0b8h,0bfh,03eh
	.db 080h,0b8h,0bfh,03eh,03eh,03eh,0b8h,03eh
	.db 080h,0b8h,0bfh,03eh,03eh,086h,0b8h ; 20
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,0b8h,0bfh
	.db 0bfh,0bfh,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,0b8h,0bfh,0bfh,03eh
	.db 0b8h,0bfh,0bfh,03eh,03eh,03eh,0b8h,03eh
	.db 0b8h,0bfh,0bfh,03eh,03eh,0b8h,0bfh ; 21
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,0b8h,0bfh
	.db 0bfh,0bfh,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,0b8h,0bfh,0bfh,03eh
	.db 0b8h,0bfh,0bfh,03eh,03eh,03eh,0b8h,03eh
	.db 0b8h,0bfh,0bfh,03eh,03eh,0b8h,0bfh ; 22
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,0b8h,0bfh
	.db 0bfh,0bfh,0bfh,03eh,0b8h,03eh,0b8h,03eh
	.db 0b8h,03eh,0b8h,03eh,0b8h,0bfh,0bfh,03eh
	.db 0b8h,0bfh,0bfh,03eh,03eh,03eh,0b8h,03eh
	.db 0b8h,0bfh,0bfh,03eh,03eh,0b8h,0bfh ; 23
	.db 000h,0b8h,0bfh,0bfh,000h,0b8h,000h,0b8h
	.db 000h,0b8h,0bfh,000h,0b8h,000h,000h,000h
	.db 0b8h,000h,000h,000h,0b8h,080h,000h,080h
	.db 000h,080h,0b8h,000h,000h,000h,0beh,000h
	.db 000h,000h,0beh,000h,000h,000h,0b8h,000h
	.db 000h,000h,0b8h,000h,000h,000h,0beh ; 24
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,03eh,03eh
	.db 0b8h,03eh,03eh,03eh,0b8h,087h,03eh,086h
	.db 03eh,086h,0b8h,03eh,03eh,03eh,0beh,03eh
	.db 03eh,03eh,0beh,03eh,000h,000h,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,000h,03eh,0beh ; 25
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,03eh,03eh
	.db 0b8h,03eh,03eh,03eh,0b8h,087h,03eh,086h
	.db 03eh,086h,0b8h,03eh,03eh,03eh,0beh,03eh
	.db 03eh,03eh,0beh,03eh,080h,080h,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,080h,03eh,0beh ; 26
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,03eh,03eh
	.db 0b8h,03eh,03eh,03eh,0b8h,0bfh,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,03eh,03eh,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,0b8h,0bfh,0bfh,03eh
	.db 03eh,03eh,0b8h,03eh,0b8h,03eh,0b8h ; 27
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,03eh,03eh
	.db 0b8h,03eh,03eh,03eh,0b8h,0bfh,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,03eh,03eh,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,0b8h,0bfh,0bfh,03eh
	.db 03eh,03eh,0b8h,03eh,0b8h,03eh,0b8h ; 28
	.db 03eh,0b8h,0bfh,0bfh,03eh,0b8h,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,0b8h,03eh,03eh,03eh
	.db 0b8h,03eh,03eh,03eh,0b8h,0bfh,03eh,0b8h
	.db 03eh,0b8h,0bfh,03eh,03eh,03eh,0b8h,03eh
	.db 03eh,03eh,0b8h,03eh,0b8h,0bfh,0bfh,03eh
	.db 03eh,03eh,0b8h,03eh,0b8h,03eh,0b8h ; 29
	.db 080h,0b8h,0bfh,0bfh,080h,0b8h,080h,0b8h
	.db 080h,0b8h,0bfh,080h,0b8h,080h,000h,000h
	.db 0b8h,080h,000h,000h,0b8h,0bfh,080h,0b8h
	.db 080h,0b8h,0bfh,080h,000h,000h,0b8h,080h
	.db 000h,000h,0b8h,080h,0b8h,0bfh,0bfh,080h
	.db 000h,000h,0b8h,080h,0b8h,080h,0b8h ; 30
	.db 087h,0b8h,0bfh,0bfh,087h,0b8h,087h,0b8h
	.db 087h,0b8h,0bfh,087h,0b8h,087h,000h,000h
	.db 0b8h,087h,000h,000h,0b8h,0bfh,087h,0b8h
	.db 087h,0b8h,0bfh,087h,000h,000h,0b8h,087h
	.db 000h,000h,0b8h,087h,0b8h,0bfh,0bfh,087h
	.db 000h,000h,0b8h,087h,0b8h,087h,0b8h ; 31
	.db 087h,0b8h,0bfh,0bfh,087h,0b8h,087h,0b8h
	.db 087h,0b8h,0bfh,087h,0b8h,087h,080h,080h
	.db 0b8h,087h,080h,080h,0b8h,0bfh,087h,0b8h
	.db 087h,0b8h,0bfh,087h,080h,080h,0b8h,087h
	.db 080h,080h,0b8h,087h,0b8h,0bfh,0bfh,087h
	.db 080h,080h,0b8h,087h,0b8h,087h,0b8h ; 32
	.db 0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh
	.db 0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh
	.db 0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh
	.db 0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh
	.db 0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh
	.db 0bfh,0bfh,0bfh,0bfh,0bfh,0bfh,0bfh ; 33
; ************************
; Záhlaví hracího pole 9x9
; ************************
ImgHeader0:
	.db 20,20
	 ; 0
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	 ; 1
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,017h,035h
	.db 02ah,03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	 ; 2
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	 ; 3
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,037h,007h
	.db 03eh,03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	 ; 4
	.db 01eh,000h,000h,000h,000h,000h,000h,03eh,03fh,039h
	.db 039h,03fh,003h,000h,000h,000h,000h,000h,000h,00fh
	 ; 5
	.db 01eh,000h,000h,000h,000h,000h,000h,03eh,037h,03eh
	.db 037h,03eh,003h,01fh,000h,000h,000h,000h,000h,00fh
	 ; 6
	.db 01eh,000h,000h,000h,000h,000h,002h,03eh,03fh,03eh
	.db 037h,03fh,023h,020h,000h,000h,000h,000h,000h,00fh
	 ; 7
	.db 01eh,000h,000h,000h,000h,010h,012h,03eh,017h,033h
	.db 02ch,03eh,013h,004h,001h,000h,000h,000h,000h,00fh
	 ; 8
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,01fh,033h
	.db 02ch,03fh,013h,004h,001h,000h,000h,000h,000h,00fh
	 ; 9
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,017h,03fh
	.db 02fh,03eh,013h,004h,001h,000h,000h,000h,000h,00fh
	 ; 10
	.db 01eh,000h,000h,000h,000h,038h,03fh,03eh,01fh,03fh
	.db 02fh,03fh,013h,01ch,001h,000h,000h,000h,000h,00fh
	; 11
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,017h,03bh
	.db 02dh,03eh,013h,000h,001h,000h,000h,000h,000h,00fh 
	 ; 12
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,03fh,006h
	.db 036h,03fh,013h,000h,001h,000h,000h,000h,000h,00fh
	; 13
	.db 01eh,000h,000h,000h,000h,010h,012h,03eh,037h,03eh
	.db 037h,03eh,023h,020h,000h,000h,000h,000h,000h,00fh 
	 ; 14
	.db 01eh,000h,000h,000h,000h,000h,002h,03eh,03fh,039h
	.db 039h,03fh,003h,01fh,000h,000h,000h,000h,000h,00fh
	; 15
	.db 01eh,000h,000h,000h,000h,000h,000h,03eh,037h,007h
	.db 03eh,03eh,003h,000h,000h,000h,000h,000h,000h,00fh 
	 ; 16
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	; 17
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,017h,035h
	.db 02ah,03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh 
	 ; 18
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	; 19
	.db 01eh,000h,000h,000h,000h,000h,000h,000h,000h,000h
	.db 000h,000h,000h,000h,000h,000h,000h,000h,000h,00fh 
; **************************
; Záhlaví hracího pole 15x15
; **************************
ImgHeader1:
	.db 32,20
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 0
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 1
	.db 03fh,03fh,03fh,03fh,03fh,017h,035h,02ah,03eh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 2
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 3
	.db 03fh,03fh,03fh,03fh,03fh,037h,007h,03eh,03eh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,00fh
	.db 01eh,000h,000h,000h,000h,000h,000h,03eh,03fh ; 4
	.db 03fh,03fh,03fh,03fh,03fh,03fh,039h,039h,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,003h,000h,000h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,000h,000h,03eh,03fh ; 5
	.db 03fh,03fh,03fh,03fh,03fh,037h,03eh,037h,03eh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,003h,01fh,000h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,000h,002h,03eh,03fh ; 6
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03eh,037h,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,023h,020h,000h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,010h,012h,03eh,03fh ; 7
	.db 03fh,03fh,03fh,03fh,03fh,017h,033h,02ch,03eh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,013h,004h,001h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,03fh ; 8
	.db 03fh,03fh,03fh,03fh,03fh,01fh,033h,02ch,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,013h,004h,001h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,03fh ; 9
	.db 03fh,03fh,03fh,03fh,03fh,017h,03fh,02fh,03eh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,013h,004h,001h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,038h,03fh,03eh,03fh ; 10
	.db 03fh,03fh,03fh,03fh,03fh,01fh,03fh,02fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,013h,01ch,001h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,03fh ; 11
	.db 03fh,03fh,03fh,03fh,03fh,017h,03bh,02dh,03eh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,013h,000h,001h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,03fh ; 12
	.db 03fh,03fh,03fh,03fh,03fh,03fh,006h,036h,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,013h,000h,001h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,010h,012h,03eh,03fh ; 13
	.db 03fh,03fh,03fh,03fh,03fh,037h,03eh,037h,03eh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,023h,020h,000h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,000h,002h,03eh,03fh ; 14
	.db 03fh,03fh,03fh,03fh,03fh,03fh,039h,039h,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,003h,01fh,000h
	.db 000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,000h,000h,03eh,03fh ; 15
	.db 03fh,03fh,03fh,03fh,03fh,037h,007h,03eh,03eh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,003h,000h,000h
	.db 000h,000h,000h,000h,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 16
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 17
	.db 03fh,03fh,03fh,03fh,03fh,017h,035h,02ah,03eh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 18
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,00fh
	.db 01eh,000h,000h,000h,000h,000h,000h,000h,000h ; 19
	.db 000h,000h,000h,000h,000h,000h,000h,000h,000h
	.db 000h,000h,000h,000h,000h,000h,000h,000h,000h
	.db 000h,000h,000h,000h,00fh
; **************************
; Záhlaví hracího pole 21x16
; **************************
ImgHeader2:
	.db 44,20
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 0
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 1
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,017h,035h,02ah,03eh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 2
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 3
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,037h,007h,03eh,03eh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	.db 01eh,000h,000h,000h,000h,000h,000h,03eh,03fh ; 4
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,039h,039h,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 003h,000h,000h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,000h,000h,03eh,03fh ; 5
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,037h,03eh,037h,03eh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 003h,01fh,000h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,000h,002h,03eh,03fh ; 6
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03eh,037h,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 023h,020h,000h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,010h,012h,03eh,03fh ; 7
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,017h,033h,02ch,03eh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 013h,004h,001h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,03fh ; 8
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,01fh,033h,02ch,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 013h,004h,001h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,03fh ; 9
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,017h,03fh,02fh,03eh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 013h,004h,001h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,038h,03fh,03eh,03fh ; 10
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,01fh,03fh,02fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 013h,01ch,001h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,03fh ; 11
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,017h,03bh,02dh,03eh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 013h,000h,001h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,020h,00fh,03eh,03fh ; 12
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,006h,036h,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 013h,000h,001h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,010h,012h,03eh,03fh ; 13
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,037h,03eh,037h,03eh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 023h,020h,000h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,000h,002h,03eh,03fh ; 14
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,039h,039h,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 003h,01fh,000h,000h,000h,000h,000h,00fh
	.db 01eh,000h,000h,000h,000h,000h,000h,03eh,03fh ; 15
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,037h,007h,03eh,03eh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 003h,000h,000h,000h,000h,000h,000h,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 16
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 17
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,017h,035h,02ah,03eh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	.db 03eh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh ; 18
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh,03fh
	.db 03fh,03fh,03fh,03fh,03fh,03fh,03fh,00fh
	.db 01eh,000h,000h,000h,000h,000h,000h,000h,000h ; 19
	.db 000h,000h,000h,000h,000h,000h,000h,000h,000h
	.db 000h,000h,000h,000h,000h,000h,000h,000h,000h
	.db 000h,000h,000h,000h,000h,000h,000h,000h,000h
	.db 000h,000h,000h,000h,000h,000h,000h,00fh
; *************************
; Standardní ikona obličeje
; *************************
ImgTrueOblicej:
	.db 4,18
	.db 03fh,03fh,03fh,03fh ; 0
	.db 017h,035h,02ah,03eh ; 1
	.db 03fh,03fh,03fh,03fh ; 2
	.db 037h,007h,03eh,03eh ; 3
	.db 03fh,039h,039h,03fh ; 4
	.db 037h,03eh,037h,03eh ; 5
	.db 03fh,03eh,037h,03fh ; 6
	.db 017h,033h,02ch,03eh ; 7
	.db 01fh,033h,02ch,03fh ; 8
	.db 017h,03fh,02fh,03eh ; 9
	.db 01fh,03fh,02fh,03fh ; 10
	.db 017h,03bh,02dh,03eh ; 11
	.db 03fh,006h,036h,03fh ; 12
	.db 037h,03eh,037h,03eh ; 13
	.db 03fh,039h,039h,03fh ; 14
	.db 037h,007h,03eh,03eh ; 15
	.db 03fh,03fh,03fh,03fh ; 16
	.db 017h,035h,02ah,03eh ; 17
; ************************************
; Změnová část bitmapy pro obličej "ó"
; ************************************
ImgOblicejOOO:
	.db 2,4
	.db 00fh,02fh ; 0
	.db 037h,02eh ; 1
	.db 036h,036h ; 2
	.db 00eh,037h ; 3
; *************************************************
; Změnová část bitmapy pro std obličej ze stavu "ó"
; *************************************************
ImgOblicejBack:
	.db 2,4
	.db 03fh,02fh ; 0
	.db 03bh,02dh ; 1
	.db 006h,036h ; 2
	.db 03eh,037h ; 3
; ****************************************
; Změnová část bitmapy pro obličej "havaj"
; ****************************************
ImgOblicejHavaj:
	.db 2,4
	.db 03eh,037h ; 0
	.db 001h,028h ; 1
	.db 030h,020h ; 2
	.db 031h,028h ; 3
; **************************************
; Změnová část bitmapy pro obličej "bad"
; **************************************
ImgOblicejBad:
	.db 2,8
	.db 03eh,037h ; 0
	.db 033h,02ch ; 1
	.db 039h,029h ; 2
	.db 03fh,02fh ; 3
	.db 03fh,02fh ; 4
	.db 007h,02eh ; 5
	.db 03ah,035h ; 6
	.db 03eh,037h ; 7
; **********************
; Sada výložek pod logem
; **********************
ImgVylozky:
	.db 21,11
	.db 000h,000h,000h,000h,000h,000h,0bfh,000h ; 0
	.db 000h,000h,000h,000h,000h,0bfh,000h,000h
	.db 000h,000h,000h,000h,0bfh
	.db 03eh,03bh,02fh,03fh,03bh,00fh,0bfh,03eh ; 1
	.db 03fh,03fh,03fh,03fh,00fh,0bfh,03eh,03fh
	.db 03fh,03fh,03fh,00fh,0bfh
	.db 02eh,01bh,02ch,008h,01ah,00ch,0bfh,022h ; 2
	.db 028h,023h,008h,022h,008h,0bfh,03ah,022h
	.db 00ah,022h,009h,009h,0bfh
	.db 026h,03bh,02dh,02bh,03ah,00dh,0beh,03ah ; 3
	.db 02ah,02bh,02ah,03ah,00eh,0beh,012h,02ah
	.db 02ah,03bh,00dh,00bh,0beh
	.db 02eh,01bh,02ch,028h,01ah,00ch,0beh,03ah ; 4
	.db 02ah,02bh,028h,03ah,008h,0beh,02ah,02ah
	.db 00ah,022h,009h,009h,0beh
	.db 02eh,01bh,02fh,00eh,03ah,00dh,0beh,03ah ; 5
	.db 02ah,02bh,00ch,03ah,00eh,0beh,03ah,02ah
	.db 03ah,03ah,009h,00dh,0beh
	.db 006h,01bh,02ch,028h,01ah,00ch,0beh,022h ; 6
	.db 008h,022h,02ah,022h,008h,0beh,03ah,022h
	.db 008h,022h,009h,009h,0beh
	.db 03eh,03bh,02fh,03fh,03bh,00fh,0beh,03eh ; 7
	.db 03fh,03fh,03fh,03fh,00fh,0beh,03eh,03fh
	.db 03fh,03fh,03fh,00fh,0beh
	.db 080h,000h,000h,000h,000h,000h,0beh,080h ; 8
	.db 000h,000h,000h,000h,000h,0beh,080h,000h
	.db 000h,000h,000h,000h,0beh
	.db 0bfh,000h,000h,000h,000h,000h,0beh,0bfh ; 9
	.db 000h,000h,000h,000h,000h,0beh,0bfh,000h
	.db 000h,000h,000h,000h,0beh
	.db 0bfh,0c0h,0c0h,0c0h,0c0h,0c0h,0beh,0bfh ; 10
	.db 0c0h,0c0h,0c0h,0c0h,0c0h,0beh,0bfh,0c0h
	.db 0c0h,0c0h,0c0h,0c0h,0beh
