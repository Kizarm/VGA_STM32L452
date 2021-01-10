#include "usart.h"


UsartClass::UsartClass (const char* name) : BaseLayer() {
  int baud = B9600;
  id = name;
  running = false;
  fd = ::open (id, O_RDWR);
  if (fd < 0) return;
  
  struct termios LineFlags;
  int attr = tcgetattr (fd, &LineFlags);
  if (attr) {
    printf ("Nelze zjistit parametry portu %s\n", name);
    ::close  (fd);
    return;
  }
  // nastaveni komunikacnich parametru do struct termios
  LineFlags.c_iflag = IGNPAR;           // ignoruj chyby parity
  LineFlags.c_oflag = 0;                // normalni nastaveni
  LineFlags.c_cflag = CS8 | CREAD | CLOCAL; // 8-bit, povol prijem
  LineFlags.c_lflag = 0;                // Raw input bez echa
  LineFlags.c_cc [VMIN]  = 1;           // minimalni pocet znaku pro cteni
  LineFlags.c_cc [VTIME] = 1;           // read timeout 0.1 s
  
  cfsetospeed (&LineFlags, baud);
  cfsetispeed (&LineFlags, baud);
  tcsetattr   (fd, TCSANOW, &LineFlags);
  fcntl       (fd, F_SETFL, 0);
  
  printf ("Port %s opened\n", id);
  usleep (10000);
  running = true;
  pthread_create (&rc, NULL, UsartClass::UsartHandler,  this);
}

UsartClass::~UsartClass() {
  if (running) {
    running = false;
    pthread_cancel (rc);
    ::close (fd);
    printf ("\nPort %s closed\n", id);
  }
}
uint32_t UsartClass::Up (const char * data, uint32_t len) {
  //data [len] = '\0';
  //printf ("\x1B[1;31m%s.Up   %3d:\x1B[0m\"%s\"\r\n", id, len, data);
  return BaseLayer::Up (data, len);
}

uint32_t UsartClass::Down (const char* data, uint32_t len) {
  if (!running) return 0;
  //data [len] = '\0';
  //printf ("\x1B[1;32m%s.Down %3d:\x1B[0m\"%s\"\r\n", id, len, data);
  return (uint32_t) ::write (fd, data, len);
}

void UsartClass::ReadLoop (void) {
  int n;
  while (running) {
    // Nutno číst po jednom nebo použít timer, jinak to po prvním čtení zdechne.
    n = ::read (fd, rxbuf, 1);
    if (!n) continue;
    Up (rxbuf, n);
  }
}
