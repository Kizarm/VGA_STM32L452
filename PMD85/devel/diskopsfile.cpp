#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "diskopsfile.h"

#define debug printf

DiskOpsBase * DiskOpsBaseInstance = nullptr;

DiskOpsFile::DiskOpsFile() {
  data_ptr = nullptr;
  DiskOpsBaseInstance = this;
}
DiskOpsFile::~DiskOpsFile() {
  delete [] data_ptr;
}

DSTATUS DiskOpsFile::DiskInitialize (BYTE pdrv) {
  (void) pdrv;
  debug ("call %s\n", __FUNCTION__);
  DSTATUS state = STA_NOINIT;
  if (data_ptr) return ~STA_NOINIT;
  const char * filename = "../cpu/image/disk.img";
  struct stat info;
  const int res = stat (filename, & info);
  if (res) return state;

  FILE * in = fopen (filename, "r");
  if (!in) return state;
  data_ptr = new BYTE [info.st_size];
  const int readen = fread (data_ptr, 1, info.st_size, in);
  if (readen != info.st_size) return state;
  fclose (in);
  return 0;
}
DSTATUS DiskOpsFile::DiskStatus (BYTE pdrv) {
  (void) pdrv;
  // debug ("call %s\n", __FUNCTION__);
  if (data_ptr) return 0;
  return STA_NOINIT;
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
  for (unsigned n=0; n<count; n++) {
    const unsigned offset = n * SECT_SIZE;
    MediaRead (buff + offset, sector + n);
  }
  return RES_OK;
}
DRESULT DiskOpsFile::DiskWrite (BYTE pdrv, const BYTE * buff, LBA_t sector, UINT count) {
  (void) pdrv;
  for (unsigned n=0; n<count; n++) {
    const unsigned offset = n * SECT_SIZE;
    MediaWrite (buff + offset, sector + n);
  }
  return RES_OK;
}
//////////////////////////////////////////////////////////////////////////////////////
void DiskOpsFile::MediaRead (uint8_t * buff, const uint32_t sect) {
  debug ("call %s  sector=%3d\n", __FUNCTION__, sect);
  const uint32_t begin = sect * SECT_SIZE;
  memcpy (buff, data_ptr + begin, SECT_SIZE);
}
void DiskOpsFile::MediaWrite (const uint8_t * buff, const uint32_t sect) {
  debug ("call %s sector=%3d\n", __FUNCTION__, sect);
  const uint32_t begin = sect * SECT_SIZE;
  memcpy (data_ptr + begin, buff, SECT_SIZE);
}
