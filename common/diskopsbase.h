#ifndef DISKOPSBASE_H
#define DISKOPSBASE_H
#include "ff.h"
#include "diskio.h"

class DiskOpsBase {
  public:
    DiskOpsBase() {};
    virtual DSTATUS DiskStatus (BYTE pdrv) = 0;
    virtual DSTATUS DiskInitialize (BYTE pdrv) = 0;
    virtual DRESULT DiskRead  (BYTE pdrv, BYTE       * buff, LBA_t sector, UINT count) = 0;
    virtual DRESULT DiskWrite (BYTE pdrv, const BYTE * buff, LBA_t sector, UINT count) = 0;
    virtual DRESULT DiskIoctl (BYTE pdrv, BYTE cmd, void * buff) = 0;
};
extern DiskOpsBase * DiskOpsBaseInstance;

#endif // DISKOPSBASE_H
