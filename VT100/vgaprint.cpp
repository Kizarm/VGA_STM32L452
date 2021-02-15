#include <string.h>
#include "vgaprint.h"
#include "console.h"

template<class T, size_t N> constexpr size_t array_len (T (&)[N]) { return N; }

static GpioClass LedRed   (GpioPortA,  8);
static GpioClass LedYelow (GpioPortA,  9);

VgaPrint::VgaPrint(Console * p, const GLYPH_DESC * const * g, const bool nw) : parent(p), sync(), pVideoRAM(sync.getRAM()), glyph(g),
  c_rows (37u), c_urows(c_rows * font_height), c_cols(100u), m_pos() {
  no_wrap = nw;
  esc_seq = ESCAPE_TEXT;
  esc_cnt = 0u;
  _formatValue = 0;
  _fmtPosX = 0;
  _fmtPosY = 0;
}
uint8_t & VgaPrint::at (const unsigned int x, const unsigned int y) {
  if (x >= c_cols ) return dummy;
  if (y >= c_urows) return dummy;
  const unsigned xy = y * c_cols + x;
  return pVideoRAM [xy];
}
void VgaPrint::draw_glyph (const GLYPH_DESC * gd) {
  for (unsigned n=0; n<font_height; n++) {
    uint8_t & pos = at (m_pos.x, y_index() + n);
    pos = gd->rows [n];
  }
}
bool VgaPrint::position (const char c) { // return true, pokud se ma vykreslit
  switch (esc_seq) {
    case ESCAPE_TEXT:
      if (c == '\x1B') {
        esc_seq = ESCAPE_ESCAPE;
        return false;
      } else break;
    case ESCAPE_ESCAPE:
      if      (c == '[') esc_seq = ESCAPE_FORMAT;
      else if (c == '(') esc_seq = ESCAPE_RESET_FONT;
      else if (c == ')') esc_seq = ESCAPE_RESET_FONT;
      else if (c == 'Z') {
      //parent->Down("\x1B/K",     3);  // identify as VT52
        parent->Down("\x1B[?1;0c", 7);  // identify as VT100
        esc_seq = ESCAPE_TEXT;
      } else {
        +LedRed;  // error
      }
      return false;
    case ESCAPE_FORMAT:
      if (c >= '0' && c <= '9')
        _formatValue = _formatValue * 10 + (c - '0');
      else {
        if (c == ';' ) {
          _fmtPosY = _formatValue;
          _formatValue = 0;
          esc_seq = ESCAPE_FORMAT;
        } else if (c == 'A') {  // up
          if (m_pos.y > 0     ) m_pos.y -= 1u;
          esc_seq = ESCAPE_TEXT;
        } else if (c == 'B') {  // down
          if (m_pos.y < c_rows) m_pos.y += 1u;
          esc_seq = ESCAPE_TEXT;
        } else if (c == 'C') {  // right
          if (m_pos.x < c_cols) m_pos.x += 1u;
          esc_seq = ESCAPE_TEXT;
        } else if (c == 'D') {  // left
          if (m_pos.x > 0)      m_pos.x -= 1u;
          esc_seq = ESCAPE_TEXT;
        } else if (c == 'H') {  // Move cursor to screen location v,h
          _fmtPosX = _formatValue;
          _formatValue = 0;
          esc_seq = ESCAPE_TEXT;
          if (_fmtPosX > 0) _fmtPosX -= 1;
          if (_fmtPosY > 0) _fmtPosY -= 1;
          m_pos.x = _fmtPosX;
          m_pos.y = _fmtPosY;
        } else if (c == 'J') {  // Clear screen from cursor down
          esc_seq = ESCAPE_TEXT;
          clear ();
          _formatValue = 0;
        } else if (c == 'K') {  // Clear line from cursor right
          esc_seq = ESCAPE_TEXT;
          erase_x (m_pos.x);
          _formatValue = 0;
        } else {  // m,q,y...
          esc_seq = ESCAPE_TEXT;
          ~LedYelow;  // unhandled
        }
      }
      return false;
    case ESCAPE_RESET_FONT:
      // c je A,B, nedela nic
      esc_seq = ESCAPE_TEXT;
      return false;
  }
  if (c == '\x08' or c == '\x7F') {
    if (m_pos.x > 0) m_pos.x -= 1u;
    return false;
  }
  if (c == '\n') {
  //m_pos.x  = 0u;
    m_pos.y += 1u;
    return false;
  }
  if (c == '\r') {
    m_pos.x  = 0u;
    return false;
  }
  if (m_pos.x >= c_cols) {
    if (no_wrap) return false;
    m_pos.x  = 0u;
    m_pos.y += 1u;
  }
  return true;
}

void VgaPrint::draw_char (const char c) {
  const bool b = position (c);
  if (m_pos.y >= c_rows) {
    m_pos.y = c_rows - 1;
    uLineOffset += font_height;
    if (uLineOffset >= static_cast<int>(c_urows)) uLineOffset = 0;
    del_row (m_pos.y);
  }
  if (!b) return;
  if (c == '\t') {
    const unsigned np = 8 - m_pos.x % 8;
    m_pos.x += np;
    return;
  }
  if (c < 0x20) return; // netistitelne znaky by uz zde byt nemely
  const unsigned gi = (static_cast<const unsigned> (c)) & 0x7F;
  const GLYPH_DESC * gd = glyph [gi];
  draw_glyph (gd);  
  m_pos.x += 1u;
}
void VgaPrint::puts (const char * str) {
  unsigned n = 0;
  for (;;) {
    const char c = str [n];
    if (c == '\0') break;
    putc (c);
    n += 1;
  }
}
void VgaPrint::erase_x (const unsigned int from) {
  const unsigned b = y_index() * c_cols + from;
  const unsigned l = c_cols - from;
  unsigned i = 0;
  for (unsigned n=0; n<font_height; n++) {
    memset (pVideoRAM + b + i, 0, l);
    i += c_cols;
  }
}
void VgaPrint::del_row (const unsigned int no) {
  const unsigned b = (no * font_height + uLineOffset) % c_urows;
  memset (pVideoRAM + b * c_cols, 0, c_cols * font_height);
}
void VgaPrint::clear() {
  const unsigned len = c_cols * c_urows;
  memset (pVideoRAM, 0, len);
  m_pos.x = 0u, m_pos.y = 0u;
}
