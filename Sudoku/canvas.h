#ifndef CANVAS_H
#define CANVAS_H
#include "fmath.h"
#include <stdint.h>
#include <stdlib.h>
#include "font.h"
#include "sudoku.h"
#include "indicator.h"

enum ARROWS {
  NO_KEY = 0, ARROW_LEFT, ARROW_RIGHT, ARROW_UP, ARROW_DOWN
};

typedef float real;

struct FPoint {
  real x,y;
  FPoint () : x(0.0f), y(0.0f) {};
  FPoint (const real x0, const real y0) : x(x0), y(y0) {};
  FPoint (const FPoint & other) : x(other.x), y(other.y) {};
  FPoint & operator= (const FPoint & other)  { x = other.x; y = other.y; return * this; };
};
class Matrix {
  real m11, m12, m21, m22, ox, oy;
  public:
    Matrix (const real a11 = 1.0f, const real a12 = 0.0f,
            const real a21 = 0.0f, const real a22 = -1.0f,
            const real ax  = 0.0f, const real ay  = 0.0f) :
    m11(a11), m12(a12), m21(a21), m22(a22), ox(ax), oy(ay) {};
    const FPoint operator* (const FPoint & right) const {
      const real x = m11 * right.x + m12 * right.y + ox;
      const real y = m21 * right.x + m22 * right.y + oy;
      const FPoint result (x, y);
      return result;
    }
};
class Canvas;
class TextRectangle {
  const int h;
  const GLYPH_DESC * const * glyph;
  int   bw, xo, yo;
  public:
    TextRectangle (const GLYPH_DESC * const * g) : h(16), glyph(g) {
    };
    void show (const char * text, const FPoint & p, Canvas & cv, const unsigned z = 1u);
  protected:
    void show (const int n,  const GLYPH_DESC * g , Canvas & cv, const unsigned z);
};
class Canvas {
  Indicator blink;
  Sudoku &  sudoku;
  const int width, bwidth, height;
  bool      current, stop, manual;
  Matrix    matrix;
  uint8_t * data;
  real      position;
  int       cursor;
  public:
#ifdef __arm__
    Canvas (Sudoku & s, const int w, const int h, uint8_t * p) : blink(), sudoku (s), width(w), bwidth(w >> 3), height(h),
      current (true), stop (false), manual (false), matrix (1.0f, 0.0f, 0.0f, -1.0f, 0.5f * (real) width, 0.5f * (real) (height)) {
      data = p;
      position = 0.0f;
      cursor   = 0;
    }
#else
    Canvas (Sudoku & s, const int w, const int h, uint8_t * p = nullptr) : blink(), sudoku (s), width(w), bwidth(w >> 3), height(h),
      current (true), stop (false), manual (false), matrix (1.0f, 0.0f, 0.0f, -1.0f, 0.5f * (real) width, 0.5f * (real) (height)) {
      (void) p;
      data = new uint8_t [bwidth * height];
      position = 0.0f;
      cursor   = 0;
    }
    ~Canvas() {
      delete [] data;
    }
#endif
    uint8_t * getData (int & x, int & y) const {
      x = width;
      y = height;
      return data;
    };
    void setMatrix (const Matrix & m);
    void fill      (const bool c);
    void setColor  (const bool c) { current = c; };
    void setAt     (const int x, const int y, const bool c = true);
    void line      (const FPoint & begin, const FPoint & end, const unsigned w = 1);
    
    void circ      (const FPoint & center, const real radius);
    
    void drawings  ();
    void arrow     (const ARROWS a);
    void number    (const int n);
    void enter     ();
    void backup    ();
    void set_new   ();
    void solve     ();
  protected:
    void setAt     (const FPoint p , const bool c = true) {
      setAt ((int) mroundf (p.x), (int) mroundf (p.y), c);
    }
    bool bound     (const int x, const int y) const;
    void line      (const real x0, const real y0, const real x1, const real y1, const unsigned w = 1);
    void rects     (const unsigned s, const unsigned w = 1u);
    void grid      ();
    void pos       (const int n, const bool c = true);
    void help      (Possible & p);
    void square    (const unsigned pos);
    void check     ();
    void gover     ();
};

#endif // CANVAS_H
