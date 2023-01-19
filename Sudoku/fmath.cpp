#include <stdint.h>
#include "fmath.h"

typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

/* Get a 32 bit int from a float.  */
#define FLT_UWORD_IS_ZERO(x) ((x)==0)

#define GET_FLOAT_WORD(i,d)   \
do {                \
  ieee_float_shape_type gf_u; \
  gf_u.value = (d);           \
  (i) = gf_u.word;            \
} while (0)

#define SET_FLOAT_WORD(d,i)   \
do {                \
  ieee_float_shape_type sf_u; \
  sf_u.word = (i);            \
  (d) = sf_u.value;           \
} while (0)

long int mroundf (const float x) {
  int32_t exponent_less_127;
  uint32_t w;
  long int result;
  int32_t sign;

  GET_FLOAT_WORD (w, x);
  exponent_less_127 = ( (w & 0x7f800000) >> 23) - 127;
  sign = (w & 0x80000000) != 0 ? -1 : 1;
  w &= 0x7fffff;
  w |= 0x800000;

  if (exponent_less_127 < (int) ( (8 * sizeof (long int)) - 1)) {
    if (exponent_less_127 < 0)
      return exponent_less_127 < -1 ? 0 : sign;
    else if (exponent_less_127 >= 23)
      result = (long int) w << (exponent_less_127 - 23);
    else {
      w += 0x400000 >> exponent_less_127;
      result = w >> (23 - exponent_less_127);
    }
  } else
    return (long int) x;

  return sign * result;
}
static const float huge = 1.0e30;
float mfloorf (float x) {
  int32_t i0,j0;
  uint32_t i,ix;
  GET_FLOAT_WORD (i0,x);
  ix = (i0&0x7fffffff);
  j0 = (ix>>23)-0x7f;
  if (j0<23) {
    if (j0<0) {                  /* raise inexact if x != 0 */
      if (huge+x> (float) 0.0) { /* return 0*sign(x) if |x|<1 */
        if (i0>=0) {i0=0;}
        else if (!FLT_UWORD_IS_ZERO (ix)) { i0=0xbf800000;}
      }
    } else {
      i = (0x007fffff) >>j0;
      if ( (i0&i) ==0) return x; /* x is integral */
      if (huge+x> (float) 0.0) { /* raise inexact flag */
        if (i0<0) i0 += (0x00800000) >>j0;
        i0 &= (~i);
      }
    }
  } else {
    return x;    /* x is integral */
  }
  SET_FLOAT_WORD (x,i0);
  return x;
}
//static  const float one = 1.0, tiny=1.0e-30;
float mabsf (const float x) {
  return (x < 0.0f) ? -x : +x;
}

float msqrtf (const float x) {
  if (x <= 0.0f) return 0.0f;
  const float e = 1e-4;
  float x0 = x, x1;
  for (unsigned n=0; n<10; n++) {
    x1 = 0.5f * (x0 + x / x0);
    if (mabsf (x1 - x0) < e) break;
    x0 = x1;
  }
  return x1;
}
// even = true -> sin(a), false -> cos(a), z definice, presnejsi (3e-6) ale asi pomalejsi
static float z_fnc (const float a, const bool even) {
  const float err = 1.0e-6f;
  float   result = 0.0f, element = even ? a : 1.0f, temp;
  int32_t divider = even ? 1 : 0;
  const float aa = a * a;
  for (unsigned n=0; n<20; n++) {
    result  += element;
    if (mabsf (element) < err) break;
    divider += 1;
    temp     = (float) divider;
    divider += 1;
    temp    *= (float) divider;
    element *= - (aa / temp);
  }
  return result;
}
static float r_fnc (const float a, const bool even) {
  const float mpi  = m_pif;
  if (a > mpi) {
    // obě funkce mají opačnou hodnotu po polovině periody
    return -r_fnc (a - mpi, even);
  } else {
    const float hpi = 0.5f * m_pif;
    if (a > hpi) {
      // lichá funkce je symetrická kolem čtvrtperiody
      if (even) return +r_fnc (mpi - a, even);
      // sudá funkce je antisymetrická kolem čtvrtperiody
      else      return -r_fnc (mpi - a, even);
    } else {
      // zde už bude argument menší než pi-4
      const float qpi = 0.25f * m_pif;
      if (a > qpi) {    // ukončení rekurze
        // cos(x) = sin(pi/2-x), sin(x) = cos(pi/2-x)
        return z_fnc (hpi - a, !even);
      } else {
        return z_fnc (a,        even);
      }
    }
  }
}

static float w_fnc (const float a, const bool even) {
  // počítat budeme jen pro kladný argument
  const float arg = a < 0.0 ? -a : +a;
  // odstraníme periodičnost
  const float ipd = 0.1591549431f;
  const float phi = arg * ipd;
  float d = phi - mfloorf(phi);
  const float dpi = 2.0f * m_pif;
  d *= dpi;
  const float result = r_fnc (d, even);
  // lichá funkce je antisymetrická kolem počátku
  if (even) return a < 0.0f ? -result : +result;
  // sudá funkce je symetrická kolem počátku
  return result;
}
float msinf (const float a) {
  return w_fnc (a, true);
}
float mcosf (const float a) {
  return w_fnc (a, false);
}
/************************************************************************************/
int msnprintf (char * buf, int length, const char *fmt, ...) {
  va_list    ap;
  signed int rc;

  va_start (ap, fmt);
  rc = mvsnprintf (buf, length, fmt, ap);
  va_end (ap);

  return rc;
}

//------------------------------------------------------------------------------
// Writes a character inside the given string. Returns 1.
// \param pStr  Storage string.
// \param c  Character to write.
//------------------------------------------------------------------------------
static signed int PutChar (char *pStr, char c) {
  *pStr = c;
  return 1;
}

//------------------------------------------------------------------------------
// Writes a string inside the given string.
// Returns the size of the written
// string.
// \param pStr  Storage string.
// \param pSource  Source string.
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
// Writes an unsigned int inside the given string, using the provided fill &
// width parameters.
// Returns the size in characters of the written integer.
// \param pStr  Storage string.
// \param fill  Fill character.
// \param width  Minimum integer width.
// \param value  Integer value.
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

//------------------------------------------------------------------------------
// Writes a signed int inside the given string, using the provided fill & width
// parameters.
// Returns the size of the written integer.
// \param pStr  Storage string.
// \param fill  Fill character.
// \param width  Minimum integer width.
// \param value  Signed integer value.
//------------------------------------------------------------------------------
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
// Writes an hexadecimal value into a string, using the given fill, width &
// capital parameters.
// Returns the number of char written.
// \param pStr  Storage string.
// \param fill  Fill character.
// \param width  Minimum integer width.
// \param maj  Indicates if the letters must be printed in lower- or upper-case.
// \param value  Hexadecimal value.
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

/// Stores the result of a formatted string into another string. Format
/// arguments are given in a va_list instance.
/// Return the number of characters written.
/// \param pStr    Destination string.
/// \param length  Length of Destination string.
/// \param pFormat Format string.
/// \param ap      Argument list.
//------------------------------------------------------------------------------
int mvsnprintf (char *pStr, int length, const char * pFormat, va_list ap) {
  char          fill;
  unsigned char width;
  signed int    num = 0;
  signed int    size = 0;
  // Clear the string
  if (pStr) {
    *pStr = 0;
  }
  // Phase string
  while (*pFormat != 0 && size < length) {
    // Normal character
    if (*pFormat != '%') {
      *pStr++ = *pFormat++;
      size++;
    }
    // Escaped '%'
    else if (* (pFormat+1) == '%') {
      *pStr++ = '%';
      pFormat += 2;
      size++;
    }
    // Token delimiter
    else {
      fill = ' ';
      width = 0;
      pFormat++;
      // Parse filler
      if (*pFormat == '0') {
        fill = '0';
        pFormat++;
      }
      // Parse width
      while ( (*pFormat >= '0') && (*pFormat <= '9')) {
        width = (width*10) + *pFormat-'0';
        pFormat++;
      }
      // Check if there is enough space
      if (size + width > length) {
        width = length - size;
      }

      // Parse type
      switch (*pFormat) {
      case 'd':
      case 'i': num = PutSignedInt   (pStr, fill, width, va_arg (ap, signed int));   break;
      case 'u': num = PutUnsignedInt (pStr, fill, width, va_arg (ap, unsigned int)); break;
      case 'x': num = PutHexa (pStr, fill, width, 0, va_arg (ap, unsigned int));     break;
      case 'X': num = PutHexa (pStr, fill, width, 1, va_arg (ap, unsigned int));     break;
      case 's': num = PutString (pStr, va_arg (ap, char *));       break;
      case 'c': num = PutChar   (pStr, va_arg (ap, unsigned int)); break;
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
