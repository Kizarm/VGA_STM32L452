#ifndef RNGCLASS_H
#define RNGCLASS_H
#include <stdint.h>

class RngClass {
  public:
    RngClass();
    uint32_t Read () const;
};

#endif // RNGCLASS_H
