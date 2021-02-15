#ifndef VGAPRINT_H
#define VGAPRINT_H
#include "vhsync.h"
#include "font.h"

static constexpr unsigned font_height = 16u;

struct Position {
  union {
    struct {
      uint16_t x,y;
    };
    uint32_t pos;
  };
  
  Position () {
    pos = 0u;
  }
  Position & operator=(const Position o) {
    pos = o.pos; return * this;
  }
  bool operator!=(const Position o) {
    if (pos != o.pos) return true;
    return false;
  }
};
enum ESCAPE_SEQ {
  ESCAPE_TEXT = 0, ESCAPE_ESCAPE, ESCAPE_FORMAT, ESCAPE_RESET_FONT
};

class Console;

class VgaPrint {
  Console * parent;
  VHSync    sync;
  uint8_t * pVideoRAM;    // placeholder
  const GLYPH_DESC * const * glyph;
  const unsigned c_rows, c_urows, c_cols;
  uint8_t    dummy;
  bool       no_wrap;
  Position   m_pos;
  ESCAPE_SEQ esc_seq;
  unsigned   esc_cnt;
  int        _formatValue, _fmtPosX, _fmtPosY;
  public:
    VgaPrint(Console * p, const GLYPH_DESC * const * g, const bool nw = false);
    void putc  (const char c) {
      draw_cursor (true);
      draw_char   (c);
    }
    void puts   (const char * str);
    void clear  ();
    void cursor () {
      draw_cursor();
    };
  protected:
    uint8_t & at (const unsigned x, const unsigned y);
    unsigned y_index () const {
      return (m_pos.y * font_height + uLineOffset) % c_urows;
    }
    void del_row     (const unsigned no);
    void erase_x     (const unsigned from);
    void draw_glyph  (const GLYPH_DESC * gd);
    void draw_cursor (const bool cl = false) {
      uint8_t  & pos = at (m_pos.x, y_index() + font_height - 1u);
      if (cl) pos = 0u;
      else    pos = ~pos;
    }
    bool position    (const char c);
    void draw_char   (const char c);
    
};

#endif // VGAPRINT_H
