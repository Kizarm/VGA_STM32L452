#include <string.h>
#include <vector>
#include <string>
#include "loader.h"

using namespace std;

Loader::Loader() : BaseLayer(), usart("/dev/serial/by-id/usb-Kizarm_Labs._USB_Serial_convertor_0001-if00"),
  ihx(), up_max(0x1000) {
  up_idx  = 0u, reply = false;
  up_buf  = new char [up_max];
  * this += usart;
}
Loader::~Loader() {
  delete [] up_buf;
}

uint32_t Loader::Up (const char * data, uint32_t len) {
  for (unsigned n=0; n<len; n++) {
    const char c = data [n];
    up_buf [up_idx++] = c;
    if (c == '\n') {
      up_buf [--up_idx] = '\0';
      RowTypes t = ihx.parseRecord (up_buf, up_idx);
      if (t == ackRecord) {
        bool b = ihx.CompareAckOffsset();
        printf("reply %d = %s, %s\r", (int) t, up_buf, b ? "true" : "false");
        fflush(stdout);
      }
      reply  = true;
      up_idx = 0;
    }
  }
  return len;
}

void Loader::Send (const uint8_t * data, const unsigned int _len, const unsigned int _offset) {
  const unsigned chunk_size = 16u;
  char hexbuf [2 * chunk_size + 16u];
  unsigned remain = _len;
  unsigned offset = 0u;
  ihx.getOffset (offset);
  offset = _offset - offset;
  ihx.AddOffset (offset);
  for (;;) {
    unsigned len = remain;
    if (len > chunk_size) len = chunk_size;
    uint32_t res = ihx.DataRecord (hexbuf, data + offset, len);
    // printf ("%s", hexbuf);
    SendWait (hexbuf, res);
    ihx.AddOffset (len);
    remain -= len;
    offset += len;
    if (!remain) break;
  }
}
void Loader::SendEof () {
  const unsigned chunk_size = 16u;
  char hexbuf [2 * chunk_size + 16u];
  unsigned offset;

  ihx.getOffset (offset);
  uint32_t end = ihx.EofRecord (hexbuf);
  SendWait (hexbuf, end);
  printf ("\nEND at %5d (0x%04X)\n", offset, offset);
}

void Loader::wait_ack() {
  while (!reply) {
    usleep (10);
  }
  reply = false;
}

void Loader::SendBinaryFile (const char * name) {
  FILE * in = fopen (name, "r");
  if (!in) return;
  const unsigned maxlen = 0x10000;
  uint8_t * buffer = new uint8_t [maxlen];
  unsigned res = fread (buffer, 1, maxlen, in);
  fclose  (in);
  Send    (buffer, res);
  SendEof ();
  delete [] buffer;
}
// debug funkce
static void test (const uint8_t * buf, const int len) {
  printf ("len = 0x%04X (%d) bytes\n", len, len);
  return;
  for (int n=0; n<len; n++) {
    if (n%16 == 0) printf ("\n %04X: ", n);
    printf ("%02X ", buf [n]);
  }
  printf ("\n");
}
void Loader::SendBasicFile (const char * name) {
  struct Initials {
    uint16_t zero, end;
  };
  FILE * in = fopen (name, "r");
  if (!in) return;
  const unsigned maxlen = 0x10000;
  uint8_t * buffer = new uint8_t [maxlen];
  const unsigned offset = 0x2401;
  const int res = parseBasicProgram (buffer + offset, in);
  fclose (in);
  test  (buffer + offset, res);
  Send  (buffer, res,  offset);
  char tmp [64];
  ihx.EofRecord (tmp); // dummy EOF
  // automatický zápis konce programu do zápisníku BASIC, který je normálně dělán interním programem.
  const unsigned endprg = 0xBE78;               // kam
  const uint16_t prgend = offset + res;
  const Initials params = { 0x0000, prgend };   // co
  const int len = sizeof (params);              // délka (4 byty)
  memcpy (buffer + endprg, & params, len);
  Send   (buffer, len, endprg);
  SendEof();
  delete [] buffer;

}
struct Chunk {
  unsigned ofs, len;
  Chunk (const unsigned _ofs) {
    ofs = _ofs, len = 0;
  }
};
void Loader::SendHexFile (const char * name) {
  printf ("file : %s\n", name);
  FILE * in = fopen (name, "r");
  if (!in) return;
  
  vector<string> result;
  for (;;) {
    size_t n = 0;
    char * lineptr = nullptr;
    const ssize_t res = getline (&lineptr, &n, in);
    if (res < 0) break;
    if (lineptr) {
      result.push_back(string (lineptr));
      free (lineptr);
    }
  }
  fclose (in);

  const unsigned maxlen = 0x10000;
  unsigned       offset = -1u;
  uint8_t * buffer = new uint8_t [maxlen];
  memset (buffer, 0xFF, maxlen);
  uint32_t ofs = 0u, len = 0u;
  vector<Chunk> chunks;
  unsigned      chunki = 0u;
  unsigned   chunksize = 0u;
  for (const string & line : result) {
    RowTypes t = ihx.parseRecord (line.c_str(), line.length());
    if (t == dataRecord) {
      const uint8_t * data = ihx.getDataRow (ofs, len);
      memcpy (buffer + ofs, data, len);
      chunksize += len;
      if (offset != ofs) {
        Chunk chunk (ofs);
        chunks.push_back (chunk);
        if (chunki > 0) chunks [chunki - 1].len = chunksize;
        offset    = ofs;
        chunki   += 1u;
        chunksize = 0u;
      }
      offset += len;
    } else if (t == eofRecord) {
      printf ("File \"%s\" end at 0x%04X\n", name, ofs + len);
      const size_t n = chunks.size() - 1;
      chunks [n].len = ofs + len - chunks [n].ofs;
    } else {
      fprintf (stderr, "Neocekavany rekord %d\n", (int) t);
    }
  }
  for (Chunk & chunk : chunks) {
    printf ("chunk: ofs = 0x%04X, len = 0x%04X\n", chunk.ofs, chunk.len);
    char tmp [64];
    ihx.EofRecord (tmp); // dummy EOF
    Send   (buffer, chunk.len, chunk.ofs);
  }
  SendEof ();
  delete [] buffer;
}

