/* inclusion guard */
#ifndef __FMATH_H__
#define __FMATH_H__
#ifdef __cplusplus
#include <stdarg.h>

extern "C" {
#endif // __cplusplus
  static const float m_pif = 3.14159265359f;

  long int mroundf (const float x);
  float    msqrtf  (const float x);
  float    mabsf   (const float x);
  float    msinf   (const float x);
  float    mcosf   (const float x);
  float    mfloorf (float x);

  int  msnprintf   (char * buf,  int length, const char * fmt, ...);
  int mvsnprintf   (char * pStr, int length, const char * pFormat, va_list ap);

#ifdef __cplusplus
};
#endif // __cplusplus
#endif /* __FMATH_H__ */
