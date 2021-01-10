#include <stdio.h>
#include "string.h"
#include "endien.h"
#include "intelhex.h"

static uint8_t hexval (const char c) {
  if ('0' <= c && c <= '9')
    return (uint8_t) c - '0';
  else if ('a' <= c && c <= 'f')
    return (uint8_t) c - 'a' + 10;
  else return 0;
}
static unsigned to_hex_str (char * str, const uint8_t * data, const unsigned len) {
  unsigned result = 0;
  const char * hexstr = "0123456789ABCDEF";
  for (unsigned n=0; n<len; n++) {
    const uint8_t c = data [n];
    str [result++] = hexstr [c >>  4];
    str [result++] = hexstr [c & 0xF];
  }
  return result;
}
static uint8_t chk_sum (const uint8_t * data, const unsigned len) {
  uint8_t sum = 0;
  for (unsigned n=0; n<len; n++) sum += data [n];
  return sum;
}

union IhxHeader {
  struct {
    uint8_t  reclen;
    ui16be   load;
    RowTypes rectyp;
  }__attribute__((packed));
  uint8_t bytes [4];
};
union UlbaAddr {
  ui16be  addr;
  uint8_t bytes [2];
};
union EipAddr {
  ui32be  addr;
  uint8_t bytes [4];
};

IntelHex::IntelHex() : address(0u), offset(0u), lenght(0u), total_lenght(0u), ackofs(0u) {
}

RowTypes IntelHex::parseRecord (const char * data, const unsigned int len) {
  //printf ("parseRecord: %d %s\r\n", len, data);
  if (data[0] != (uint8_t) ':')               return badRecord;
  uint8_t tmp [(len >> 1) + 1];
  uint8_t val = 0;
  unsigned  k = 0;
  for (unsigned n=1; n<len; n++) {
    const uint8_t c = data [n];
    if (c == '\r') break;
    if (c == '\n') break;
    val *= 0x10;
    val += hexval (c | 0x20);
    if ((n & 1) == 0) {
      tmp [k++] = val;
      val = 0;
    }
  }
  k -= 1;
  uint8_t chk = 0;
  for (unsigned n=0; n<k; n++) chk += tmp [n];
  chk = 0 - chk;
  // kontrolní součet
  if (chk != tmp[k])                          return badRecord;
  // chybná délka
  if (k < sizeof (IhxHeader))                 return badRecord;
  IhxHeader hdr;
  memcpy (hdr.bytes, tmp, sizeof(IhxHeader));
  // chybná délka
  if (k !=  (hdr.reclen + sizeof(IhxHeader))) return badRecord;
  //printf ("%d: %d=%d, %d, %02X=%02X\n", len, k, hdr.reclen+4, hdr.rectyp, chk, tmp[k]);
  UlbaAddr a1; EipAddr a2;
  RowTypes t = hdr.rectyp;
  lenght = hdr.reclen;
  const uint8_t * start = tmp + sizeof(IhxHeader);
  uint32_t tmpadr;
  // uint16_t old_ofs = offset;
  switch (t) {
    case dataRecord:
      memcpy (chunk, start, lenght);
      offset = hdr.load.get();
      // if (old_ofs != offset) printf ("Posun 0x%04X-0x%04X\n", old_ofs, offset);
      total_lenght = offset + lenght;
      break;
    case elaRecord:
      total_lenght = 0;
      memcpy (a1.bytes, start, lenght);
      address = (uint32_t) a1.addr.get() << 16;
      offset  = hdr.load.get();
      break;
    case slaRecord:
      memcpy (a2.bytes, start, lenght);
      address = a2.addr.get();
      offset  = hdr.load.get();
      break;
    case ackRecord:
    case nakRecord:
      ackofs  = hdr.load.get();
      break;
    case eofRecord:
    case reqRecord:
    case ersRecord:
      offset  = hdr.load.get();
      break;
    // Tyhle 2 rekordy nějak fungují, ale je to divné. Bohužel třeba objcopy
    // je na nízkých adresách z nějakého důvodu používá. Možná je v tom chyba.
    case esaRecord:
      total_lenght = 0;
      memcpy (a1.bytes, start, lenght);
      address = (uint32_t) a1.addr.get() << 4;
      offset  = hdr.load.get();
      break;
    case ssaRecord:
      memcpy (a2.bytes, start, lenght);
      tmpadr  = a2.addr.get();
      address = (tmpadr >> 12);  // CS:IP ? čerti vědí, jak je to myšleno
      offset  = hdr.load.get();
      break;
    default:
      break;
  }
  return t;
}
bool IntelHex::CompareAckOffsset() {
//printf ("ofs: %04X=%04X\n", ackofs, offset);
  if (ackofs == offset) return true;
  return false;
}

void IntelHex::getAddress (uint32_t & adr) {
  adr = address;
}
void IntelHex::getLenght (uint32_t & len) {
  len = total_lenght;
}
void IntelHex::getOffset (uint32_t & ofs) {
  ofs = offset;
}
void IntelHex::WriteData (uint8_t * data) {
  memcpy (data + offset, chunk, lenght);
  offset += lenght;
}
uint8_t * IntelHex::getDataRow (uint32_t & ofs, uint32_t & len) {
  ofs = offset;
  len = lenght;
  return chunk;
}
void IntelHex::AddOffset (uint32_t len) {
  offset += len;
}

uint32_t IntelHex::ElaRecord (char * string, const uint32_t adr) {
  offset = 0;
  uint32_t result = 0;
  string [result++] = ':';
  UlbaAddr  lba;
  IhxHeader hdr;
  hdr.load.set(0);
  hdr.reclen = sizeof (lba);
  hdr.rectyp = elaRecord;
  lba.addr.set (adr >> 16);
  uint8_t chk = 0;
  chk += chk_sum (hdr.bytes, sizeof(IhxHeader));
  chk += chk_sum (lba.bytes, sizeof(UlbaAddr ));
  chk  = 0 - chk;
  result += to_hex_str (string + result, hdr.bytes, sizeof(IhxHeader));
  result += to_hex_str (string + result, lba.bytes, sizeof(UlbaAddr ));
  result += to_hex_str (string + result, & chk, 1);
  //string [result++] = '\r';
  string [result++] = '\n';
  string [result]   = '\0';
  return result;
}
uint32_t IntelHex::SlaRecord (char* string, const uint32_t adr) {
  offset = 0;
  uint32_t result = 0;
  string [result++] = ':';
  EipAddr   lba;
  IhxHeader hdr;
  hdr.load.set(0);
  hdr.reclen = sizeof (lba);
  hdr.rectyp = slaRecord;
  lba.addr.set (adr);
  uint8_t chk = 0;
  chk += chk_sum (hdr.bytes, sizeof(IhxHeader));
  chk += chk_sum (lba.bytes, sizeof(EipAddr  ));
  chk  = 0 - chk;
  result += to_hex_str (string + result, hdr.bytes, sizeof(IhxHeader));
  result += to_hex_str (string + result, lba.bytes, sizeof(EipAddr  ));
  result += to_hex_str (string + result, & chk, 1);
  //string [result++] = '\r';
  string [result++] = '\n';
  string [result]   = '\0';
  return result;
}

uint32_t IntelHex::DataRecord (char * string, const uint8_t * data, const uint32_t len) {
  uint32_t result = 0;
  string [result++] = ':';
  IhxHeader hdr;
  hdr.load.set (offset);
  hdr.reclen = len;
  hdr.rectyp = dataRecord;
  uint8_t chk = 0;
  chk += chk_sum (hdr.bytes, sizeof(IhxHeader));
  chk += chk_sum (data, len);
  chk  = 0 - chk;
  result += to_hex_str (string + result, hdr.bytes, sizeof(IhxHeader));
  if (len) result += to_hex_str (string + result, data, len);
  result += to_hex_str (string + result, & chk, 1);
  //string [result++] = '\r';
  string [result++] = '\n';
  string [result]   = '\0';
  return result;
}

uint32_t IntelHex::EofRecord (char * string) {
  offset = 0;
  const char * eof = ":00000001FF\n";
  const uint32_t result = strlen (eof);
  memcpy (string, eof, result);
  string [result]   = '\0';
  return result;
}
uint32_t IntelHex::BTxRecord (char * string, RowTypes t) {
  uint32_t result = 0;
  string [result++] = ':';
  IhxHeader hdr;
  hdr.load.set (offset);
  hdr.reclen = 0;
  hdr.rectyp = t;
  uint8_t chk = 0;
  chk += chk_sum (hdr.bytes, sizeof(IhxHeader));
  chk  = 0 - chk;
  result += to_hex_str (string + result, hdr.bytes, sizeof(IhxHeader));
  result += to_hex_str (string + result, & chk, 1);
  //string [result++] = '\r';
  string [result++] = '\n';
  string [result]   = '\0';
  //offset += len;
  return result;
}
