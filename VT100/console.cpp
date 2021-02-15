#include "console.h"
#include "vhsync.h"
#include "font.h"

Console::Console() : BaseLayer(), ring(), kbd(this), vga(this, font_AtariST8x16SystemFont.font_data) {

}

void Console::pass() {
  asm volatile ("wfi");
  
  char data;
  if (ring.Read(data)) {
    FramesCount = 0;
    vga.putc (data);
  }
  
  if (FramesCount > 26) {
    FramesCount = 0;
    vga.cursor();
  }
}

uint32_t Console::Up (const char * data, uint32_t len) {
  unsigned res = 0;
  for (res=0; res<len; res++) {
    if (!ring.Write (data [res])) break;
  //vga.putc (data [res]);
  }
  return res;
}

