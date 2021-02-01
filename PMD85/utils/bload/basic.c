//---------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "common.h"
//---------------------------------------------------------------------------
#define BUF_SIZE      128
#define KWORD_CNT     111
#define QUOTE         1
#define REM           2
#define DATA          4
#define MAX_LINE_LEN  77

//---------------------------------------------------------------------------
char *keywords[KWORD_CNT] = {
  "END","FOR","NEXT","DATA","INPUT","DIM","READ","LET",
  "GOTO","RUN","IF","RESTORE","GOSUB","RETURN","REM","STOP","BIT","ON",
  "NULL","WAIT","DEF","POKE","PRINT","ERR","LIST","CLEAR","LLIST","RAD",
  "NEW","TAB(","TO","FNC","SPC(","THEN","NOT","STEP","+","-","*","/","^",
  "AND","OR",">","=","<","SGN","INT","ABS","USR","FRE","INP","POS","SQR",
  "RND","LOG","EXP","COS","SIN","TAN","ATN","PEEK","LEN","STR$","VAL",
  "ASC","CHR$","LEFT$","RIGHT$","MID$","SCALE","PLOT","MOVE","BEEP",
  "AXES","GCLEAR","PAUSE","DISP","?","BMOVE","BPLOT","LOAD","SAVE",
  "DLOAD","DSAVE","LABEL","FILL","AUTO","OUTPUT","STATUS","ENTER",
  "CONTROL","CHECK","CONT","OUT","INKEY","CODE","ROM","APOKE","PEN",
  "INK(","APEEK","ADR","AT","HEX$","DEG","","","","WINDOW","REN"
};
//---------------------------------------------------------------------------
static char findToken (char **src);
//---------------------------------------------------------------------------
int parseBasicProgram (BYTE *out, FILE *in) {
  BYTE *o = out;
  char buf[BUF_SIZE], *p, buf2[BUF_SIZE], *q, ch;
  int idx, adr, num, lnum, flg;

  printf ("Importing BASIC program...\n");

  adr = 0x2401; // pociatocna adresa RAM, kde zacina program v BASICu
  lnum = 0;
  while (TRUE) {
    p = fgets (buf, BUF_SIZE - 1, in);
    if (p == NULL)
      break;

    idx = strlen (buf);
    while (idx > 0 && (buf[idx - 1] == '\n' || buf[idx - 1] == '\r'))
      buf[--idx] = 0;
    if (!idx)
      continue;

    num = 0;
    while (isdigit (*p))
      num = num * 10 + (*p++ - '0');
    while (isspace (*p))
      p++;

    printf ("\rLine: %d", num);
    if (idx > MAX_LINE_LEN)
      printf ("\tLine is long. Possible problem!\n");
    if (num < lnum)
      printf ("\tWrong order of line. Last line %d\n", lnum);
    if ( (MAX_LINE_LEN - (p - buf)) < 3)
      printf ("\tLine is short. Possible problem!\n");

    q = buf2;
    flg = 0;
    while (*p) {
      ch = 0;
      if (! (flg & (QUOTE | REM | DATA)))
        ch = findToken (&p);
      if (!ch)
        ch = *p++;
      *q++ = ch;

      if (ch == '"' && ! (flg & QUOTE))
        flg |= QUOTE;
      else if (ch == '"' && (flg & QUOTE))
        flg &= ~QUOTE;
      else if (ch == -114 && ! (flg & REM)) // 0x8E - REM
        flg |= REM;
      else if (ch == -125 && ! (flg & DATA)) // 0x83 - DATA
        flg |= DATA;
      else if (ch == ':' && (flg & (DATA | QUOTE)) == DATA)
        flg &= ~DATA;
    }
    *q = 0;

    idx = strlen (buf2);
    adr = adr + 4 + idx + 1;

    * ( (WORD *) o) = (WORD) adr;
    o += 2;
    * ( (WORD *) o) = (WORD) num;
    o += 2;
    memcpy (o, buf2, idx);
    o += idx;
    *o++ = 0;

    lnum = num;
  }

  *o++ = 0;
  *o++ = 0;

  printf ("\rDone.                      \n");

  return o - out;
}
//---------------------------------------------------------------------------
static char findToken (char **src) {
  char *p, *q;
  int i;

  for (i = 0; i < KWORD_CNT; i++) {
    p = *src;
    q = keywords[i];
    while (*p && *p == *q) {
      p++;
      q++;
      if (!*q) {
        *src = p;
        return (char) (i + 0x80);
      }
    }
  }

  return 0;
}
//---------------------------------------------------------------------------

