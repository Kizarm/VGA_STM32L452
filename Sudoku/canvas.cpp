#ifndef __wasm__
#include <cstring>
#endif
#include "canvas.h"

void TextRectangle::show (const char * text, const FPoint & p, Canvas & cv, const unsigned int z) {
  bw = strlen(text);
  xo = (int) mroundf (p.x), yo = (int) mroundf (p.y);
  for (int n=0; n<bw; n++) {
    const char cc = text [n];
    const unsigned gi = (static_cast<unsigned>(cc)) & 0x7F;
    const GLYPH_DESC * gd = glyph [gi];
    show (n << 3, gd, cv, z);
  }
}
void TextRectangle::show (const int order, const GLYPH_DESC * g, Canvas & cv, const unsigned int z) {
  for (int n=0; n<h; n++) {
    const uint8_t row = g->rows [n];
    for (int k=0; k<8; k++) {
      const bool c = ((1 << k) & row) ? true : false;
      for (unsigned yz = 0; yz < z; yz++) {
        for (unsigned xz = 0; xz < z; xz++) {
          const int   x  = xo + (order + k) * z + xz, y = yo + n * z + yz;
          cv.setAt (x, y, c);
        }
      }
    }
  }
}

void Canvas::fill (const bool c) {
  const int max = bwidth * height, fc = c ? 0xFF : 0;
  memset (data, fc, max);
}
inline bool Canvas::bound (const int x, const int y) const {
  if (x < 0)       return false;
  if (y < 0)       return false;
  if (x >= width)  return false;
  if (y >= height) return false;
  return true;
}
void Canvas::setAt (const int x, const int y , const bool c) {
  if (!bound(x, y)) return;
  const int xx = x >> 3;
  const int ix = x  & 7;
  const int bi = xx + y * bwidth;
  if (c) data [bi] |=  (1 << ix);
  else   data [bi] &= ~(1 << ix);
}
void Canvas::line (const real xp, const real yp, const real xe, const real ye, const unsigned w) {
  real dx = xe - xp;
  real dy = yp - ye;
  real dl = dx * dx + dy * dy;
  if (dl == 0.0f) return;
  dl = msqrtf (dl);
  dx = dx / dl;
  dy = dy / dl;
  const Matrix m (dx, dy, -dy, dx, xp, yp);
  
  const unsigned nl = w / 2;
  const unsigned wl = w % 2;
  const real hl = 0.5f * (real) w;
  if (wl) {
    for (real n=-hl; n<dl+hl; n+=1.0f) {
      const FPoint p = m * FPoint (n, 0.0f);
      setAt (p, current);
    }
  }
  for (unsigned k=0; k<nl; k++) {
    const real dw = hl - (real) k;
    const real dz = wl ? 1.0f : 0.5f;
    const real dh = (real) k + dz;
    for (real n=-dw; n<dl+dw; n+=1.0f) {
      const FPoint p = m * FPoint (n, +dh);
      setAt (p, current);
      const FPoint q = m * FPoint (n, -dh);
      setAt (q, current);
    }
  }  
}
void Canvas::line (const FPoint & begin, const FPoint & end, const unsigned w) {
  const FPoint b (matrix * begin);
  const FPoint e (matrix * end  );
  // printf("%d:%d - %d:%d\n", x0, y0, x1, y1);
  line (b.x, b.y, e.x, e.y, w);
}
void Canvas::circ (const FPoint & center, const real radius) {
  if (radius == 0.0f) return;
  real x = radius, y = 0.0f;
  const real dx = 1.0f / radius;
  const real ms = radius * 6.3f;
  real count = 0.0f;
  // kruh se da nakreslit i bez sin a cos, rychle ale trochu nepresne
  for (;;) {
    x += y * dx; y -= x * dx;
    const FPoint e (center.x + x, center.y + y);
    const FPoint t (matrix * e);
    setAt (t, current);
    count += 1.0f;
    if (count > ms) break;
  }
}
void Canvas::setMatrix (const Matrix & m) {
  matrix = m;
}
void Canvas::rects (const unsigned int s, const unsigned int w) {
  const real sql = 66.0f, sul = sql * 9.0f;
  for (unsigned n=0u; n<10u; n+=s) {
    const real st = (real) n * sql;
    FPoint b (0.0f, st), e (sul, st);
    line (b, e, w);
  }
  for (unsigned n=0u; n<10u; n+=s) {
    const real st = (real) n * sql;
    FPoint b (st, 0.0f), e (st, sul);
    line (b, e, w);
  }
}
void Canvas::check() {
  if (manual) return;
  const value_t k = sudoku.find_min();
  pos   (cursor, false);
  setColor (true);
  if (k < 0) {
    gover ();
    return;
  }
  pos   (k);
  cursor = k;
  
  Possible p (cursor);
  help  (p);
  int u = -1;
  if (p.uniq(u)) blink.set (L_GREEN);
  else           blink.set (L_YELLOW);
  if (u < 0) gover ();
}
void Canvas::drawings() {
  stop = false;
  blink.set   (L_GREEN);
  sudoku.fill ();
  blink.set   (L_YELLOW);
    
  fill (false);
  Matrix m (1.0f, 0.0f, 0.0f, -1.0f, 3.0f, height - 3.0f);
  setMatrix(m);
  rects (1u);
  rects (3u, 6u);
  grid  ();
  
  sudoku.remove();
  blink.set   (L_GREEN);
  grid  ();
  check ();
}
void Canvas::set_new() {
  if (manual) {
     value_t * const g = sudoku.getGrid();
     g [cursor] = -1;
     square (cursor);
    return;
  }
  manual = true;
  stop   = false;
  sudoku.clear ();
  fill (false);
  Matrix m (1.0f, 0.0f, 0.0f, -1.0f, 3.0f, height - 3.0f);
  setMatrix(m);
  rects (1u);
  rects (3u, 6u);
  cursor = 0;
  pos (cursor);
}

void Canvas::backup() {
  if (!stop) return;
  stop = false;
  fill (false);
  Matrix m (1.0f, 0.0f, 0.0f, -1.0f, 3.0f, height - 3.0f);
  setMatrix(m);
  rects (1u);
  rects (3u, 6u);
  grid  ();
  
  sudoku.backup ();
  blink.set     (L_GREEN);
  grid  ();
  check ();
}

void Canvas::pos (const int n, const bool c) {
  const unsigned col = n % SUDMAX;
  const unsigned row = n / SUDMAX;
  const real sql = 66.0f, o = 6.0f;
  const real x0 = (real)  col      * sql + o, y0 = (real)  row      * sql + o;
  const real x1 = (real) (col + 1) * sql - o, y1 = (real) (row + 1) * sql - o;
  const unsigned w = 4u;
  setColor (c);
  line (FPoint (x0, y0), FPoint (x0, y1), w);
  line (FPoint (x0, y0), FPoint (x1, y0), w);
  line (FPoint (x1, y0), FPoint (x1, y1), w);
  line (FPoint (x0, y1), FPoint (x1, y1), w);
}

void Canvas::grid() {
  for (unsigned n=0u; n<SUDSQR; n++) {
    square (n);
  }
}
void Canvas::square (const unsigned int n) {
  TextRectangle text (font_AtariST8x16SystemFont.font_data);
  const value_t * g = sudoku.getGrid();
  const real sql = 66.0f;
  const unsigned col = n % SUDMAX;
  const unsigned row = n / SUDMAX;
  const real x = (real) col * sql, y = (real) row * sql;
  FPoint b (x + 20.0f, y + 56.0f);
  char txt [2];
  if (g [n] < 0) txt [0] = ' ';
  else           txt [0] = '0' + g [n];
  txt [1] = '\0';
  text.show (txt, matrix * b, * this, 3u);
}
// Nastavení obtížnosti hry (nikoli generovaného vzoru) 0..3
#define DIFICULT 0
void Canvas::help (Possible & p) {
  sudoku.help(p);
#if DIFICULT > 0
  return;                    // Vypnutí zobrazení help - 1. zobtížnění hry
#endif
  TextRectangle text (font_AtariST8x16SystemFont.font_data);
  char txt [SUDMAX + 1u];
  for (unsigned i=0; i<SUDMAX; i++) txt [i] = ' ';
  int k = 0;
  for (unsigned i=0; i<SUDMAX; i++) {
    const int n = p.nums [i];
    if (n != 0) txt [k++] = '1' + i;
  }
  txt [SUDMAX] = '\0';
  text.show (txt, FPoint (625.0f, 30.0f), * this, 2u);
}
void Canvas::gover() {    // konec
  blink.set (L_RED);
  stop = true;
  TextRectangle text (font_AtariST8x16SystemFont.font_data);
  text.show ("GAME", FPoint (640.0f, 430.0f), * this, 3u);
  text.show ("OVER", FPoint (640.0f, 480.0f), * this, 3u);
}

void Canvas::arrow (const ARROWS a) {
  if (stop) return;
  int col = cursor % SUDMAX;
  int row = cursor / SUDMAX;
  const int max = SUDMAX - 1u;
  switch (a) {
    case ARROW_DOWN:  row -= 1; if (row < 0  ) row = max; break;
    case ARROW_UP:    row += 1; if (row > max) row = 0;   break;
    case ARROW_LEFT:  col -= 1; if (col < 0  ) col = max; break;
    case ARROW_RIGHT: col += 1; if (col > max) col = 0;   break;
    default: return;
  }
  const int npos = row * SUDMAX + col;
  pos (cursor, false);
  pos (npos);
  cursor = npos;
  if (manual) {
    square (cursor);
    return;
  }
  Possible p (cursor);
  help (p);
}
void Canvas::enter() {
  if (manual) manual = false;
#if DIFICULT > 1
  return;              // Vypnutí klávesy enter - 2. zobtížnění hry
#endif
  if (stop) return;
  Possible p (cursor);
  sudoku.help(p);
  int u = 0;
  if (!p.uniq(u)) return;
  value_t * const g = sudoku.getGrid();
  g [cursor] = u;
  square (cursor);
  check  ();
}
void Canvas::number (const int k) {
  if (stop) return;
  value_t * const g = sudoku.getGrid();
  if (g [cursor] > 0) return;
  Possible p  (cursor);
  sudoku.help (p);
  if (p.contains (k)) {
    g [cursor] = k;
    square (cursor);
    check  ();
  } else {
#if DIFICULT > 2
    gover ();          // Skonči po špatném doplnění 3. zobtížnění hry
#endif
  }
}
void Canvas::solve() {
  if (stop)   return;
  if (manual) return;
  if (sudoku.solve()) {
    grid ();
  }
  gover();
}

