#include "string.h"
#include "vgawrap.h"

VgaWrap::VgaWrap() : BaseLayer(), sync(), pVideoRAM (sync.getRAM()), canvas(800, 600, pVideoRAM), disable(true) {

}
uint32_t VgaWrap::Up (const char * data, uint32_t len) {
  disable = false;
  return len;
}
