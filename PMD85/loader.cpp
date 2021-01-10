#include <string.h>
#include "loader.h"

#ifdef USE_USB

Loader::Loader() : BaseLayer(), ihx(), udev(), cdc_acm(udev) {
  mem_base = nullptr;
  index    = 0u;
}
void Loader::Init (uint8_t * base) {
  mem_base = base;
  udev.attach (cdc_acm);
  cdc_acm.init();
  * this += cdc_acm;
}
void Loader::loop() {
  if (!mem_base)     return;
  char c;
  if (!ring.Read(c)) return;
  buffer [index ++] = c;
  if (c == '\n') record ();
}

void Loader::record() {
  buffer [index] = '\0';
  
  RowTypes t = ihx.parseRecord (buffer, index);
  switch (t) {
    case dataRecord: {
      uint8_t * ptr = ihx.getDataRow (m_ofs, m_len);
      memcpy (mem_base + m_ofs, ptr, m_len);
    } break;
    case eofRecord:
    default: break;
  }
  uint32_t res = ihx.BTxRecord(buffer, ackRecord);
  Down (buffer, res);

  index = 0;
}

#endif // USE_USB