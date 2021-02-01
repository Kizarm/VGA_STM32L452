#include <stdio.h>
#include <atomic>
#include <stdint.h>
#include <string.h>
#include <string>
#include <vector>
#include "common.h"

using namespace std;

static string file_base (const char * _name) {
  string name (_name), result;
  ssize_t n = name.find_last_of ('.');
  if (n > 0) result = name.substr (0, n);
  n = result.find_last_of ('/');
  if (n > 0) result = result.substr(n + 1, result.length());
  printf("result = %s\n", result.c_str());
  return result;
}

static void test (const uint8_t * buf, const int len) {
  printf ("len = 0x%04X (%d) bytes\n", len, len);
  return;
  for (int n=0; n<len; n++) {
    if (n%16 == 0) printf ("\n %04X: ", n);
    printf ("%02X ", buf [n]);
  }
  printf ("\n");
}
static void create_cod_file (const char * name, uint8_t * data, const int len) {
  FILE * out = fopen (name, "w");
  const int res = fwrite (data, 1, len, out);
  if (len != res) {
    printf ("%d != %d\n", len, res);
  }
  fclose (out);
}
static const char * preamble = R"---(NAME %s
CLS
FILE BASIC.COD,0
FILE %s,%04X
MONIT 2
%sJUMP 0
)---";
static void create_inf_file (const string name, const int len) {
  struct Initials {
    uint16_t zero, end;
  };
  unsigned char  buffer [sizeof (Initials)];
  const unsigned offset = 0x2401;
  const unsigned endprg = 0xBE78;               // kam
  const uint16_t prgend = offset + len;
  const Initials params = { 0x0000, prgend };   // co
  const int l = sizeof (params);                // délka (4 byty)
  memcpy (buffer, & params, l);
  const string infname = name + ".inf";
  const string codname = name + ".cod";
  char cod [codname.length() + 1];
  int index = 0;
  for (const char c : codname) {
    cod [index++] = toupper (c);
  }
  cod [index] = '\0';
  index = 0;
  char bas [name.length() + 1];
  for (const char c : name) {
    bas [index++] = toupper (c);
  }
  bas [index] = '\0';
  const int maxbuf = 0x400;
  char buf [maxbuf];
  int  end = 0;
  for (int n=0; n<l; n++) {
    end += snprintf (buf + end, maxbuf - end, "POKE %04X,%02X\n", endprg + n, buffer [n]);
  }
  buf [end] = '\0';
  FILE * out = fopen (infname.c_str(), "w");
  fprintf (out, preamble, bas, cod, offset, buf);
  fclose (out);
}

static void SendBasicFile (const char * name) {
  FILE * in = fopen (name, "r");
  if (!in) return;
  const unsigned maxlen = 0x10000;
  uint8_t * buffer = new uint8_t [maxlen];
  const int res = parseBasicProgram (buffer, in);
  fclose (in);
  test  (buffer, res);
  const string basename = file_base (name);
  const string codename = basename + ".cod";
  create_cod_file (codename.c_str(), buffer, res);
  create_inf_file (basename.c_str(), res);
  delete [] buffer;

}


static void file_type (const char * _name) {
  string name (_name);
  const ssize_t fd = name.find_last_of ('.');
  if (fd > 0) {
    string suffix = name.substr (fd + 1, name.length());
    // printf ("suffix = %s\n", suffix.c_str());
    if (suffix == "bas") {
      SendBasicFile  (_name);
    } else {
      printf ("Unsupported file type .\"%s\"\n", suffix.c_str());
    }
  }
}

int main (int argc, char * argv[]) {
  if (argc < 2) return 1;
  const char * name = argv [1];
  file_type (name);
  return 0;
}
