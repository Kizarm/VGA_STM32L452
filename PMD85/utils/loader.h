#ifndef LOADER_H
#define LOADER_H

#include <atomic>
#include "intelhex.h"
#include "baselayer.h"
#include "usart.h"
#include "common.h"

class Loader : public BaseLayer {
  UsartClass        usart;
  IntelHex          ihx;
  const unsigned    up_max;
  char            * up_buf;
  unsigned          up_idx;
  std::atomic<bool> reply;
  protected:
    void Send (const uint8_t  * data, const unsigned int len, const unsigned int offset = 0u);
    void SendWait (const char * data, const unsigned int len) {
      // return;
      Down (data, len);
      wait_ack ();
    }
    void SendEof  ();
    void wait_ack ();
  public:
    Loader();
    virtual ~Loader();
    uint32_t Up (const char * data, uint32_t len) override;
    /** Pro Basic je nutné ještě "zkorektnit" konec programu.
     *  Zde je to řešeno zápisem na "správné" místo v paměti.
     * */
    void SendBasicFile  (const char * name);
    /** Zatím jen od adresy 0.
     * */
    void SendBinaryFile (const char * name);
    void SendHexFile    (const char * name);
};

#endif // LOADER_H
