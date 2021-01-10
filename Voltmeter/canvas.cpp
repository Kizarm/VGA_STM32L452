#include <string.h>
#include "canvas.h"

void TextRectangle::show (const char * text, const FPoint & p, Canvas & cv, const unsigned int z) {
  bw = strlen(text);
  xo = (int) mroundf (p.x), yo = (int) mroundf (p.y);
  for (int n=0; n<bw; n++) {
    const char cc = text [n];
    const unsigned gi = (static_cast<const unsigned>(cc)) & 0x7F;
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

void Canvas::drawings() {
  fill (false);
  TextRectangle text (font_AtariST8x16SystemFont.font_data);
  text.show ("mV", matrix * FPoint (+250.0f, -200.0f), * this, 5);
  text.show ("(c) Kizarm 2020", matrix * FPoint (-390.0f, -280.0f), * this);
  text.show ("STM32L452", matrix * FPoint (-390.0f, +280.0f), * this);
  text.show ("@72.0 MHz", matrix * FPoint (-390.0f, +260.0f), * this);
  Matrix m (1.0f, 0.0f, 0.0f, -1.0f, 0.5f * (real) width - 80.0f, 0.5f * (real) (height) - 10.0f);
  setMatrix(m);  
  do {
    const unsigned smax = 200;
    const real step = 2.0f * m_pif / (real) smax;
    const real incr = 32.0f        / (real) smax;
    const real r0 = 120.0f, l1 = 5.0f, l5 = 10.0f, l10 = 15.0f;
    real r = r0;
    FPoint w (-r, 0.0f);
    for (unsigned n=0; n<=5.0f*smax; n++) {
      const real arg = (real) n * step;
      const real ss = msinf (arg);
      const real cs = mcosf (arg);
      const Matrix m (-cs, ss, ss, cs, 0.0f, 0.0f);
      const FPoint b (r, 0.0f);
      const FPoint p (m * b);
      if ((n%100) == 0) {
        const FPoint e (r + l10, 0.0f);
        line (p, m * e, 4u);
      } else if ((n%10) == 0) {
        const FPoint e (r + l10, 0.0f);
        line (p, m * e, 2u);
      } else if ((n%5) == 0) {
        const FPoint e (r + l5,  0.0f);
        line (p, m * e);
      } else {
        const FPoint e (r + l1,  0.0f);
        line (p, m * e);
      }
      line (p, w, 3u);
      w = p;
      r += incr;
    }
  } while (false);
  
  do {
    const unsigned smin = 1u, smax = 20u, step = 1u;
    const real arg0 = 2.0f * m_pif / (real) smax;
    const real  r0  = 290.0f, dr = 0.5f;
    for (unsigned n=smin; n<=smax; n+=step) {
      const real arg = (real) n * arg0;
      const real  r  = r0 +  (real) n * dr;
      const real  px = -r * mcosf (arg);
      const real  py = +r * msinf (arg);
      const int text_len = 16;
      char text_buf [text_len];
      FPoint pt (px - 10.0f, py);
      if (n ==  5) pt.y -=  5.0f;
      if (n == 15) pt.y +=  5.0f;
      if (n == 20) pt.y += 20.0f;
      const int nn = n + 80;
      msnprintf (text_buf, text_len, "%d.%d", nn / 10, nn % 10);
      text.show (text_buf, matrix * pt, * this);
    }
  } while (false);
  do {
    const unsigned smin = 0u, smax = 100u, step = 1u;
    const real arg0 = 2.0f * m_pif / (real) smax;
    const real  r0  = 30.0f;
    FPoint p0 (r0, 0.0f);
    for (unsigned n=smin; n<=smax; n+=step) {
      const real arg = (real) n * arg0;
      const real  px = r0 * mcosf (arg);
      const real  py = r0 * msinf (arg);
      const FPoint p1 (px, py);
      line (p0, p1, 5);
      p0 = p1;
    }
    const FPoint z0 (0.0f, 0.0f);
    circ (z0, 10.0f);
    circ (z0, 11.0f);
    circ (z0, 18.0f);
    circ (z0, 24.0f);
    const real dd = 7.0f;
    const FPoint x0 (-dd, -dd), x1 (+dd, +dd);
    line (x0, x1);
    const FPoint x2 (-dd, +dd), x3 (+dd, -dd);
    line (x2, x3);
  } while (false);
}
void Canvas::pointer (const real n, const bool c) {
  const unsigned smax = 200;
  const real step = 2.0f * m_pif / (real) smax;
  const real incr = 32.0f        / (real) smax;
  const real   r0 = 105.0f, l0 = 10.0f, l1 = 5.0f;
  const real   zz = 0.0f, mm = 1000.0f;
  const real   nn = (n < zz) ? zz : (n < mm) ? n : mm;
  do {
    const real r  = r0 + (real) nn * incr;
    const real ag =      (real) nn * step;
    const real ss = msinf (ag);
    const real cs = mcosf (ag);
    const Matrix m (-cs, ss, ss, cs, 0.0f, 0.0f);
    const FPoint b (r, 0.0f), e (r + l0, 0.0f);
    const FPoint t (r + l1, -l1), u (r  + l1,  +l1);
    const FPoint v (40.0f, 0.0f), w (r0 - l1, 0.0f);
    current = c;
    line (m * b, m * e, 4);
    line (m * v, m * w, 5);
    line (m * e, m * t, 2);
    line (m * e, m * u, 2);
  } while (false);
}

void Canvas::pointer (const real n) {
  const real eps = 0.1f;
  const real delta = mabsf (position - n);
  if (delta < eps) return;
  pointer (position, false);
  pointer (n,        true );
  position = n;
  TextRectangle text (font_AtariST8x16SystemFont.font_data);
  const int text_len = 16;
  char text_buf [text_len];
  msnprintf (text_buf, text_len, "%6d", (int) mroundf (n));
  text.show (text_buf, matrix * FPoint (240.0f, 250.0f), * this, 4);
}

