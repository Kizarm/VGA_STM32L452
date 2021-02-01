#include <stdio.h>
#include <atomic>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

static constexpr unsigned image_len = 0x100000 * 4; // 4 MiB

static void file_create (const char * _name) {
  const unsigned block = 0x1000;
  uint8_t buffer [block];
  for (unsigned n=0; n<block; n++) buffer [n] = 0xFF;
  FILE * out = fopen (_name, "w");
  unsigned len = image_len;
  for (;;) {
    unsigned res = fwrite (buffer, 1, block, out);
    if (res != block) break;
    len -= res;
    if (len == 0)     break;
  }
  fclose (out);
}
int main (int argc, char * argv[]) {
  /* test
  volatile uint8_t prom1=0, prom2=0, prom3=0;
  volatile uint8_t pole[] = {0, 0, 0};
  volatile uint8_t * const ptr = pole, * volatile p1 = & prom1, * p2;
//ptr = & prom2; chyba
  p1 = & prom2; // OK
  p2 = & prom3; // OK
  (void) ptr, (void) p1, (void) p2;
  */
  
  if (argc < 2) return 1;
  const char * name = argv [1];
  file_create (name);
  return 0;
}
