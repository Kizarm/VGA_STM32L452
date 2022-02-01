#include "indicator.h"

#ifdef __arm__
Indicator::Indicator() : r(GpioPortA, 8),  y(GpioPortA, 9), g(GpioPortA, 10) {

}
void Indicator::set (const LIGHT p) {
  -r ; -y; -g;
  switch (p) {
    case L_NONE   :     break;
    case L_RED    : +r; break;
    case L_YELLOW : +y; break;
    case L_GREEN  : +g; break;
  }
}

#else
Indicator::Indicator() {}
void Indicator::set (const LIGHT) {}
#endif
