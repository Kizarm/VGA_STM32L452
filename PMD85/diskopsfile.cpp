#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "diskopsfile.h"

#define debug(...)

DiskOpsBase * DiskOpsBaseInstance = nullptr;

static inline void delay (const unsigned dly = 100000) {
  volatile unsigned n = dly;
  while (--n);
}

DiskOpsFile::DiskOpsFile() : DiskOpsBase(), spi(), cs_fl(GpioPortB, 6, GPIO_Mode_AN),
  initialized (false), fl (spi, cs_fl), ledYellow (GpioPortA, 9, GPIO_Mode_OUT), ledRed (GpioPortA, 8, GPIO_Mode_OUT) {
  data_ptr = nullptr;
  DiskOpsBaseInstance = this;
}

DSTATUS DiskOpsFile::DiskInitialize (BYTE pdrv) {
  (void) pdrv;
  if (initialized) return 0;
  +cs_fl;
  cs_fl.setMode (GPIO_Mode_OUT);
  cs_fl.setSpeed(GPIO_Speed_HS);

  delay();      // pockej az se ustali
  spi.Init();
  
  initialized = true;
  return 0;
}
DSTATUS DiskOpsFile::DiskStatus (BYTE pdrv) {
  (void) pdrv;
  if (!initialized) return STA_NOINIT;
  // debug ("call %s\n", __FUNCTION__);
  return 0;
}
DRESULT DiskOpsFile::DiskIoctl (BYTE pdrv, BYTE cmd, void * buff) {
  (void) pdrv;
  debug ("call %s ctrl=%d\n", __FUNCTION__, cmd);
  switch (cmd) {
  case GET_SECTOR_SIZE: {
    WORD * p = (WORD*) buff;
    * p = SECT_SIZE;
  } return RES_OK;
  default: break;
  }
  return RES_PARERR;
}
//////////////////////////////////////////////////////////////////////////////////////
DRESULT DiskOpsFile::DiskRead (BYTE pdrv, BYTE * buff, LBA_t sector, UINT count) {
  (void) pdrv;
  +ledYellow;
  for (unsigned n=0; n<count; n++) {
    const unsigned offset = n * SECT_SIZE;
    MediaRead (buff + offset, sector + n);
  }
  -ledYellow;
  return RES_OK;
}
DRESULT DiskOpsFile::DiskWrite (BYTE pdrv, const BYTE * buff, LBA_t sector, UINT count) {
  (void) pdrv;
  +ledRed;
  for (unsigned n=0; n<count; n++) {
    const unsigned offset = n * SECT_SIZE;
    MediaWrite (buff + offset, sector + n);
  }
  -ledRed;
  return RES_OK;
}
//////////////////////////////////////////////////////////////////////////////////////
void DiskOpsFile::MediaRead (uint8_t * buff, const uint32_t sect) {
  debug ("call %s  sector=%3d\n", __FUNCTION__, sect);
  const uint32_t begin = sect * SECT_SIZE;
  // memcpy (buff, data_ptr + begin, SECT_SIZE);
  fl.ReadBlock    (begin, buff, SECT_SIZE);

}
void DiskOpsFile::MediaWrite (const uint8_t * buff, const uint32_t sect) {
  debug ("call %s sector=%3d\n", __FUNCTION__, sect);
  const uint32_t begin = sect * SECT_SIZE;
  // memcpy (data_ptr + begin, buff, SECT_SIZE);
  fl.EraseSectors (begin, SECT_SIZE);
  fl.WriteBlock   (begin, buff, SECT_SIZE);
}
