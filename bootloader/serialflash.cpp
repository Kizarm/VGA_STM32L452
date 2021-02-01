#include <string.h>
#include "serialflash.h"

#define trace(...)

static constexpr unsigned MaxChunkSize  = 128u;
static constexpr unsigned FlashBlockLen = 0x1000u;  // 4KiB = 4096 B
/** Tohle je poměrně divoká struktura hlavičky a dat, použitých pro
 * SPI Transaction(), ale je to zase úsporné.
 * */
union FlashCommandHeader {
  struct {
    FLASH_COMMANDS cmd : 8;
    uint32_t       adr : 24;       // adresa je BIG ENDIEN - vyšší byte vystupuje po SPI dříve (MSB FIRST).
  }__attribute__((packed));
  uint8_t bytes [4];
}__attribute__((packed));
union FlashOperationBuffer {
  struct FlashCommandBuffer {
    FlashCommandHeader hdr;
    uint8_t            buf [MaxChunkSize];
  }__attribute__((packed)) cb;
  uint8_t bytes [sizeof (FlashCommandBuffer)];
};
#if 0
bool SerialFlash::Test (const char * id) {
  uint8_t buf [4] = {FLASH_RDID, 0,0,0}; // Read Identification (RDID 9Fh)
  const uint32_t num = spi.Transaction (buf, 4, chip_select);
  bool result = false;
  do {
    if (num    != 4   ) break;
    if (buf[1] != 0xEF) break;
    if (buf[2] != 0x40) break;
    // buf [3] je 0x16 pro 64 Mb - kapacita 2^22 bytu, je to JEDEC standard
    result = true;
  } while (false);
  trace ("\"%s\": %02X-%02X-%02X %s\r\n", id, buf[1], buf [2], buf [3], result ? "OK" : "FAIL");
  
  return result;  
}
#endif // 0
uint8_t SerialFlash::GetCapacityByte() const {
  uint8_t buf [4] = {FLASH_RDID, 0,0,0}; // Read Identification (RDID 9Fh)
  const uint32_t num = spi.Transaction (buf, 4, chip_select);
  if (num != 4) return 0;
  return buf [3];
}

/* Omezení na stránku je asi zbytečné, ale dá se tomu rozumět všelijak.
 * V každém případě se tím nic nezkazí.
 * */
static const uint32_t FlashPageSize = 0x100;
static inline void bound_to_page (const uint32_t begin, uint32_t & len) {
  uint32_t n =  begin        & ~(FlashPageSize - 1);
  uint32_t m = (begin + len) & ~(FlashPageSize - 1);
  if (m == n) return;   // jsou ve stejné stránce, OK.
  len = m - begin;      // jen do konce stránky
}
uint32_t SerialFlash::ReadBlock     (const uint32_t begin_adr,       uint8_t * data, const uint32_t len) const {
  uint32_t offset = 0u, remain = len;
  while (remain) {
    uint32_t block  = remain;
    if (block > MaxChunkSize) block = MaxChunkSize;
    uint32_t readen = ReadChunk (begin_adr + offset, data + offset, block);
    if (!readen) break;
    offset += readen;
    remain -= readen;
  }
  return offset;
}
uint32_t SerialFlash::WriteBlock    (const uint32_t begin_adr, const uint8_t * data, const uint32_t len) const {
  uint32_t offset = 0u, remain = len;
  while (remain) {
    uint32_t block  = remain;
    if (block > MaxChunkSize) block = MaxChunkSize;
    bound_to_page (begin_adr + offset, block);
    uint32_t writen = WriteChunk (begin_adr + offset, data + offset, block);
    if (!writen) break;
    offset += writen;
    remain -= writen;
  }
  return offset;
}
bool     SerialFlash::EraseSectors  (const uint32_t begin_adr, const uint32_t len) const {
  const uint32_t beg = begin_adr & ~(FlashBlockLen - 1);
  const uint32_t end = begin_adr + len;
  for  (uint32_t n=beg; n<end; n+=FlashBlockLen) {
    if (!EraseSector (n)) return false;
  }
  return true;
}
/* **************************************************************************************/
static inline uint32_t be_set_24 (const uint32_t p) {
  return  ((p & 0x000000ff) << 16)
        | ((p & 0x0000ff00) <<  0)
        | ((p & 0x00ff0000) >> 16);
}
bool     SerialFlash::SingleCommand (const FLASH_COMMANDS cmd) const {
  uint8_t  tmp = cmd;
  uint32_t res = spi.Transaction (&tmp, 1, chip_select);
  if (res != 1u) return false;
  return true;
}
uint8_t  SerialFlash::ReadStatus    (const FLASH_COMMANDS cmd) const {
  uint8_t buf [2] = {cmd, 0};
  spi.Transaction(buf, 2, chip_select);
  return buf[1];
}
uint32_t SerialFlash::ReadChunk     (const uint32_t begin_adr,       uint8_t * data, const uint32_t len) const {
  //trace ("ReadChunk=%06X len=%02X\r\n", begin_adr, len);
  const uint32_t total = len + sizeof (FlashCommandHeader);
  FlashOperationBuffer op;
  op.cb.hdr.cmd = FLASH_4READ;
  op.cb.hdr.adr = be_set_24 (begin_adr);
  memset (op.cb.buf, 0xFF, MaxChunkSize);
  uint32_t result = spi.Transaction (op.bytes, total, chip_select);
  result -= sizeof (FlashCommandHeader);
  // trace_blok(op.bytes, total);
  if (data) memcpy (data, op.cb.buf, result);
  return result;
}
uint32_t SerialFlash::WriteChunk    (const uint32_t begin_adr, const uint8_t * data, const uint32_t len) const {
  //trace ("WriteChunk=%06X len=%02X\r\n", begin_adr, len);
  SingleCommand(FLASH_WREN);    // Zápis se musí povolit před každou operací zápisu / mazání
  const uint32_t total = len + sizeof (FlashCommandHeader);
  FlashOperationBuffer op;
  op.cb.hdr.cmd = FLASH_4PP;
  op.cb.hdr.adr = be_set_24 (begin_adr);
  if (data) memcpy  (op.cb.buf, data, len);
  uint32_t result = spi.Transaction (op.bytes, total, chip_select);
  result -= sizeof (FlashCommandHeader);
  // trace_blok(op.bytes, total);
  if (!WaitForReady()) return 0;
  return result;
}
bool     SerialFlash::WaitForReady (const unsigned time) const {
  uint8_t sr;
  for (unsigned n=0; n<time; n++) {
    sr = ReadStatus(FLASH_RDSR1);
    // trace ("STATUS=%02X\r\n", sr);
    if ((sr & 1) == 0) return true;
  }
  return false;
}
bool     SerialFlash::EraseSector   (const uint32_t begin_adr) const {
  trace ("EraseSector=%06X\r\n", begin_adr);  
  SingleCommand(FLASH_WREN);    // Zápis se musí povolit před každou operací zápisu / mazání
  FlashCommandHeader hdr;
  hdr.cmd = FLASH_4SE;
  hdr.adr = be_set_24 (begin_adr);
  const uint32_t lenght = sizeof (FlashCommandHeader);
  const uint32_t result = spi.Transaction(hdr.bytes, lenght, chip_select);
  if (result != lenght)     return false;
  if (!WaitForReady(30000)) return false;   // max 400 ms, typ 45 ms, dáme 400
  return true;
}
/* **************************************************************************************/
