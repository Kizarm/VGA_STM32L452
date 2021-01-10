#ifndef USARTCLASS_H
#define USARTCLASS_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdint.h>
#include <termios.h>
#include "baselayer.h"

#define BUFLEN 1024
// Bottom
class UsartClass : public BaseLayer {
  public:
    UsartClass    (const char * name);
    uint32_t  Up  (const char * data, uint32_t len);
    uint32_t  Down(const char * data, uint32_t len);
   ~UsartClass   ();
  protected:
           void  ReadLoop      (void);
    static void* UsartHandler (void* p) {
      UsartClass* inst = (UsartClass*) p;
      inst->ReadLoop();
      return NULL;
    };
  public:
    bool         running;
  private:
    const char*  id;         //!< Identifikátor třídy pro ladění
    char         rxbuf[BUFLEN];
    int          fd;
    pthread_t    rc;
};
#endif // USARTCLASS_H
