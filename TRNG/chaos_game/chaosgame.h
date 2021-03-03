#ifndef CHAOSGAME_H
#define CHAOSGAME_H

#include <string.h>
#include "gpio.h"
#include "vhsync.h"
#include "rngclass.h"
#include "adcclass.h"

static constexpr unsigned x_max = 800;
static constexpr unsigned y_max = 600;

typedef float real;

struct FPoint {
  real x,y;
  FPoint () : x(0.0f), y(0.0f) {};
  FPoint (const real x0, const real y0) : x(x0), y(y0) {};
  FPoint (const FPoint & other) : x(other.x), y(other.y) {};
  FPoint & operator= (const FPoint & other)  { x = other.x; y = other.y; return * this; };
  FPoint   operator+ (const FPoint & other) const {
    FPoint result (* this);
    result.x += other.x;
    result.y += other.y;
    return result;
  }
  FPoint   operator* (const real r) const {
    FPoint result (* this);
    result.x *= r;
    result.y *= r;
    return result;
  }
};
class Matrix {
  real m11, m12, m21, m22;
  public:
    Matrix (const real a11 = 1.0f, const real a12 =  0.0f,
            const real a21 = 0.0f, const real a22 = -1.0f) :
            m11(a11), m12(a12), m21(a21), m22(a22) {};
    const FPoint operator* (const FPoint & right) const {
      const real x = m11 * right.x + m12 * right.y;
      const real y = m21 * right.x + m22 * right.y;
      const FPoint result (x, y);
      return result;
    }
};
typedef const FPoint (*handle) (const FPoint &);
/** @class Fractal
 * K vykreslení fraktálu se používá postupné aplikace několika
 * afinních transformací bodu s náhodným výběrem té právě použité.
 * Součet pravděpodobností všech používaných transformací je
 * roven 1. Vybrány byly transformace pro Barnsleyho kapradí
 * a Sierpińského trojúhelník.
 * */
template <const unsigned tab_len> struct Fractal {
  const handle func_table [tab_len];
  const real   prob_table [tab_len];
  FPoint transformation (const FPoint & pt, const real np) const {
    const unsigned i = fn_index (np);
    return func_table [i] (pt);
  }
  protected:
    unsigned fn_index (const real p) const {
      unsigned r;
      real suma = 0.0f;
      for (r=0u; r<tab_len; r++) {
        suma += prob_table [r];
        if (suma >= p) break;
      }
      if (r >= tab_len) r = tab_len - 1u;
      return r;
    }
};
enum PICTURE {
  SIERPINSKI, BARNSLEY
};

class ChaosGame {
  GpioClass LedGreen;
  VHSync    sync;
  RngClass  trng;
  AdcClass  adc;
  
  uint32_t * const pVideoBit;
  uint32_t         dummy;
  FPoint           next;
  unsigned         time;
  PICTURE          pict;
  public:
    ChaosGame();
    void Init ();
    void Pass ();
  protected:
    uint32_t & at (const unsigned x, const unsigned y) {
      if (y >= y_max - 0u) return dummy;
      if (x >= x_max - 1u) return dummy;
      return pVideoBit [y * x_max + x];
    }
};

#endif // CHAOSGAME_H
