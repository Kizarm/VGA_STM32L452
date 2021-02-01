#include <stdio.h>
#include <atomic>
#include <stdint.h>
#include <string>
#include <vector>
#include "loader.h"

using namespace std;

static void file_type (const char * _name) {
  string name (_name);
  const ssize_t fd = name.find_last_of ('.');
  if (fd > 0) {
    string suffix = name.substr (fd + 1, name.length());
    // printf ("suffix = %s\n", suffix.c_str());
    Loader loadder;
    if (suffix == "bas") {
      loadder.SendBasicFile  (_name);
    } else if (suffix == "hex") {
      loadder.SendHexFile    (_name);
    } else if (suffix == "bin") {
      loadder.SendBinaryFile (_name);
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
