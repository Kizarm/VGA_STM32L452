#ifndef DISKOPSFILE_H
#define DISKOPSFILE_H
#include "diskopsbase.h"
#include "gpio.h"
#include "spiclass.h"
#include "serialflash.h"

static constexpr int SECT_SIZE = 4096;

class DiskOpsFile : public DiskOpsBase {
  BYTE * data_ptr;
  public:
    DiskOpsFile();
    DSTATUS DiskStatus     (BYTE pdrv)                                         override;
    DSTATUS DiskInitialize (BYTE pdrv)                                         override;
    DRESULT DiskRead  (BYTE pdrv, BYTE       * buff, LBA_t sector, UINT count) override;
    DRESULT DiskWrite (BYTE pdrv, const BYTE * buff, LBA_t sector, UINT count) override;
    DRESULT DiskIoctl (BYTE pdrv, BYTE cmd, void * buff)                       override;
  protected:
    void MediaRead  (      uint8_t * buff, const uint32_t sect);
    void MediaWrite (const uint8_t * buff, const uint32_t sect);
  private:
    SpiClass   spi;
    GpioClass  cs_fl;
    bool initialized;
    SerialFlash   fl;
    GpioClass  ledYellow;
    GpioClass  ledRed;
};

#endif // DISKOPSFILE_H
