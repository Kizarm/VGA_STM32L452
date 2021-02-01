#include "string.h"
#include "vgawrap.h"

VgaWrap::VgaWrap() : sync(), pVideoRAM (sync.getRAM()), canvas(800, 600, pVideoRAM), disable(true) {

}
