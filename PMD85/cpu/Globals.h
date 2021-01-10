#ifndef GLOBALS_H
#define GLOBALS_H
#include <stdint.h>
#ifdef __thumb__
#define debug(...)
#define warning(...)
#else
#include <stdio.h>
#include <stdarg.h>
#define debug printf
static inline void warning (const char * dev, const char * fmt, ...) {
  const unsigned MaxTraceLen = 0x1000;
  char buf [MaxTraceLen];
  va_list    ap;
  signed int rc;
  va_start (ap, fmt);
  rc = vsnprintf (buf, MaxTraceLen, fmt, ap);
  va_end (ap);
  buf [rc] = '\0';
  printf ("Warning \"%s\" : %s\n", dev, buf);
}
#endif

#define MAX_SIGNED_INT (0x7FFFFFFF)
#define MIN_SIGNED_INT (0x80000000)

#define CPU_FREQ            2048000
#define CHNL_SPEAKER        0
#define TAPE_BLOCK_SIZE     65535
#define CHNL_TAPE           1

#define LED_YELLOW          1
#define LED_RED             2
#define LED_BLUE            4

typedef uint8_t  BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;

enum TComputerModel { CM_UNKNOWN = -1, CM_V1 = 0, CM_V2, CM_V2A, CM_V3, CM_MATO, CM_ALFA, CM_ALFA2, CM_C2717, CM_LAST = CM_C2717 };

class PeripheralDevice {
  public:
    const BYTE portAddr;              // port address
    const BYTE portMask;              // port mask
    const bool needReset;             // device need reset
    PeripheralDevice  * next;   // pointer to next list item
    PeripheralDevice (const BYTE _portAddr, const BYTE _portMask, const bool _needReset)
      : portAddr(_portAddr), portMask(_portMask), needReset(_needReset), next (nullptr) {};
    // Pure virtual methods:
    // It should be implemented by interupt controller and called by CPU:
    virtual void WriteToDevice (BYTE /*port*/, BYTE /*value*/, int /*ticks*/) = 0;
    virtual BYTE ReadFromDevice(BYTE /*port*/, int /*ticks*/) = 0;
    virtual void ResetDevice   (int /*ticks*/) { return; };
};
enum TInterruptVector { IV_OPCODE, IV_OPERAND_L, IV_OPERAND_H };

class InterruptController {
  public:
  int    Tag;
  void * cpu;
  // Pure virtual methods:
  // It was implemented by interupt control class and called by processor.
  virtual BYTE getInterruptVector(TInterruptVector intVector) = 0;
};


#endif //  GLOBALS_H
