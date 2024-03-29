#include "libwasm.h"
extern void IMPORT(PrintOut) (const char * ptr, const int len);  // external javascript function

size_t strlen (const char *s) {
  size_t l = 0;
  while (*s++) l++;
  return l;
}
char *strncpy (char *dst0, const char *src0, size_t count) {
  char *dscan;
  const char *sscan;

  dscan = dst0;
  sscan = src0;
  while (count > 0) {
      --count;
      if ((*dscan++ = *sscan++) == '\0')
        break;
  }
  while (count-- > 0)
    *dscan++ = '\0';

  return dst0;
}
int strncmp (const char *s1, const char *s2, size_t n) {
  if (n == 0) return 0;
  while (n-- != 0 && *s1 == *s2) {
    if (n == 0 || *s1 == '\0') break;
    s1++;
    s2++;
  }
  return (* (unsigned char *) s1) - (* (unsigned char *) s2);
}
int strcmp (const char *s1, const char *s2) {
  while (*s1 != '\0' && *s1 == *s2) {
    s1++;
    s2++;
  }
  return (* (unsigned char *) s1) - (* (unsigned char *) s2);
}

void *memcpy (void *dest, const void *src, size_t n) {
  const char *s = (const char *) src;
  char *d = (char *) dest;
  int i;
  for (i=0; i<n; i++) d[i] = s[i];
  return dest;
}
void *memset (void *s, int c, size_t n) {
  char *p = (char *) s;
  int i;
  for (i=0; i<n; i++) p[i] = c;
  return s;
}

char *strtok (char *s, const char *delim) {
  static   char *lasts[1];
  register char *spanp;
  register int c, sc;
  char *tok;
  if (s == NULL && (s = *lasts) == NULL)
    return (NULL);
  /*
   * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
   */
cont:
  c = *s++;
  for (spanp = (char *) delim; (sc = *spanp++) != 0;) {
    if (c == sc) {
      if (/*skip_leading_delim*/ 1) {
        goto cont;
      } else {
        *lasts = s;
        s[-1] = 0;
        return (s - 1);
      }
    }
  }
  if (c == 0) {           /* no non-delimiter characters */
    *lasts = NULL;
    return (NULL);
  }
  tok = s - 1;
  /*
   * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
   * Note that delim must have one NUL; we stop if we see that, too.
   */
  for (;;) {
    c = *s++;
    spanp = (char *) delim;
    do {
      if ( (sc = *spanp++) == c) {
        if (c == 0)
          s = NULL;
        else
          s[-1] = 0;
        *lasts = s;
        return (tok);
      }
    } while (sc != 0);
  }
  /* NOTREACHED */
}
/* *************************************************************/
//------------------------------------------------------------------------------
/// Writes a character inside the given string. Returns 1.
/// \param pStr  Storage string.
/// \param c  Character to write.
//------------------------------------------------------------------------------
static signed int PutChar (char *pStr, char c) {
  *pStr = c;
  return 1;
}

//------------------------------------------------------------------------------
/// Writes a string inside the given string.
/// Returns the size of the written
/// string.
/// \param pStr  Storage string.
/// \param pSource  Source string.
//------------------------------------------------------------------------------
static signed int PutString (char *pStr, const char *pSource) {
  signed int num = 0;
  while (*pSource != 0) {
    *pStr++ = *pSource++;
    num++;
  }
  return num;
}

//------------------------------------------------------------------------------
/// Writes an unsigned int inside the given string, using the provided fill &
/// width parameters.
/// Returns the size in characters of the written integer.
/// \param pStr  Storage string.
/// \param fill  Fill character.
/// \param width  Minimum integer width.
/// \param value  Integer value.
//------------------------------------------------------------------------------
static signed int PutUnsignedInt (
  char *pStr,
  char fill,
  signed int width,
  unsigned int value) {
  signed int num = 0;
  // Take current digit into account when calculating width
  width--;
  // Recursively write upper digits
  if ( (value / 10) > 0) {
    num = PutUnsignedInt (pStr, fill, width, value / 10);
    pStr += num;
  }
  // Write filler characters
  else {
    while (width > 0) {
      PutChar (pStr, fill);
      pStr++;
      num++;
      width--;
    }
  }
  // Write lower digit
  num += PutChar (pStr, (value % 10) + '0');
  return num;
}

////------------------------------------------------------------------------------
/// Writes a signed int inside the given string, using the provided fill & width
/// parameters.
/// Returns the size of the written integer.
/// \param pStr  Storage string.
/// \param fill  Fill character.
/// \param width  Minimum integer width.
/// \param value  Signed integer value.
////------------------------------------------------------------------------------
static signed int PutSignedInt (
  char *pStr,
  char fill,
  signed int width,
  signed int value) {
  signed int num = 0;
  unsigned int absolute;
  // Compute absolute value
  if (value < 0) {
    absolute = -value;
  } else {
    absolute = value;
  }
  // Take current digit into account when calculating width
  width--;
  // Recursively write upper digits
  if ( (absolute / 10) > 0) {
    if (value < 0) {
      num = PutSignedInt (pStr, fill, width, - (absolute / 10));
    } else {
      num = PutSignedInt (pStr, fill, width, absolute / 10);
    }
    pStr += num;
  } else {
    // Reserve space for sign
    if (value < 0) {
      width--;
    }
    // Write filler characters
    while (width > 0) {
      PutChar (pStr, fill);
      pStr++;
      num++;
      width--;
    }
    // Write sign
    if (value < 0) {
      num += PutChar (pStr, '-');
      pStr++;
    }
  }
  // Write lower digit
  num += PutChar (pStr, (absolute % 10) + '0');
  return num;
}

//------------------------------------------------------------------------------
/// Writes an hexadecimal value into a string, using the given fill, width &
/// capital parameters.
/// Returns the number of char written.
/// \param pStr  Storage string.
/// \param fill  Fill character.
/// \param width  Minimum integer width.
/// \param maj  Indicates if the letters must be printed in lower- or upper-case.
/// \param value  Hexadecimal value.
//------------------------------------------------------------------------------
static signed int PutHexa (
  char *pStr,
  char fill,
  signed int width,
  unsigned char maj,
  unsigned int value) {
  signed int num = 0;
  // Decrement width
  width--;
  // Recursively output upper digits
  if ( (value >> 4) > 0) {
    num += PutHexa (pStr, fill, width, maj, value >> 4);
    pStr += num;
  }
  // Write filler chars
  else {
    while (width > 0) {
      PutChar (pStr, fill);
      pStr++;
      num++;
      width--;
    }
  }
  // Write current digit
  if ( (value & 0xF) < 10) {
    PutChar (pStr, (value & 0xF) + '0');
  } else if (maj) {
    PutChar (pStr, (value & 0xF) - 10 + 'A');
  } else {
    PutChar (pStr, (value & 0xF) - 10 + 'a');
  }
  num++;
  return num;
}
static signed int PutPointer (char * pStr, void * ptr) {
  int num = PutString(pStr, "0x");
  pStr += num;
  num  += PutHexa(pStr, '0', 8, 0, (unsigned int) ptr);
  return num;
}

signed int vsnprintf (char *pStr, size_t length, const char *pFormat, va_list ap) {
  char          fill;
  unsigned char width;
  signed int    num = 0;
  signed int    size = 0;
  // Clear the string
  if (pStr) { * pStr = 0;  }
  // Phase string
  while (*pFormat != 0 && size < length) {
    // Normal character
    if (*pFormat != '%') {
      *pStr++ = *pFormat++;
      size++;
    } else if (* (pFormat + 1) == '%') { // Escaped '%'
      *pStr++ = '%';
      pFormat += 2;
      size++;
    } else {                 // Token delimiter
      fill = ' ';
      width = 0;
      pFormat++;
      if (*pFormat == '0') { // Parse filler
        fill = '0';
        pFormat++;
      }
      while ((*pFormat >= '0') && (*pFormat <= '9')) { // Parse width
        width = (width * 10) + *pFormat - '0';
        pFormat++;
      }
      // Check if there is enough space
      if (size + width > length) {
        width = length - size;
      }
      // Parse type
type_spec:
      switch (*pFormat) {
        case 'z':           // modifikatory z,l jsou zbytečné - size long a int jsou stejne
        case 'l':
          pFormat++;
          goto type_spec;
        case 'd':
        case 'i':
          num = PutSignedInt (pStr, fill, width, va_arg (ap, signed int));
          break;
        case 'u':
          num = PutUnsignedInt (pStr, fill, width, va_arg (ap, unsigned int));
          break;
        case 'x':
          num = PutHexa (pStr, fill, width, 0, va_arg (ap, unsigned int));
          break;
        case 'X':
          num = PutHexa (pStr, fill, width, 1, va_arg (ap, unsigned int));
          break;
        case 's':
          num = PutString (pStr, va_arg (ap, char *));
          break;
        case 'c':
          num = PutChar (pStr, va_arg (ap, unsigned int));
          break;
        case 'p':
          num = PutPointer (pStr, va_arg (ap, void *));
          break;
        default:
          return 0;
      }
      pFormat++;
      pStr += num;
      size += num;
    }
  }
  // NULL-terminated (final \0 is not counted)
  if (size < length) {
    *pStr = 0;
  } else {
    * (--pStr) = 0;
    size--;
  }
  return size;
}
int puts (const char * ptr) {
  const int len = strlen (ptr);
  char * out = malloc (len);
  strncpy(out, ptr, len);
  PrintOut (out, len);
  free (out);
  return len;
}
#define MAXSTRINGSIZE 0x1000
int printf (const char *fmt, ...) {
  char * p = malloc(MAXSTRINGSIZE);
  va_list ap;
  va_start(ap, fmt);
  int size = vsnprintf(p, MAXSTRINGSIZE, fmt, ap);
  va_end(ap);
  if (size < 0) return 0;
  p [size] = '\0';
  PrintOut(p, size);
  free(p);
  return size;
}
