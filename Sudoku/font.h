#ifndef _FONT_H_DEFINED
#define _FONT_H_DEFINED
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
  
struct GLYPH_DESC {
//const uint8_t w;
  const uint8_t rows [16];
}__attribute__((packed));

struct FONT_GEOMETRY {
  const uint8_t x,y;
}__attribute__((packed));
struct FONT {
  const char                      * font_name;
  const struct FONT_GEOMETRY      * font_geometry;
  const struct GLYPH_DESC * const * font_data;
};
extern const struct FONT font_AtariST8x16SystemFont;

#ifdef __cplusplus
};
#endif //__cplusplus
#endif // _FONT_H_DEFINED
