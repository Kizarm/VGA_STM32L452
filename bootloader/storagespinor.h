#ifndef STORAGESPINOR_H
#define STORAGESPINOR_H

#include "storagebase.h"
#include "diskopsbase.h"
#include "spiclass.h"
#include "serialflash.h"

class StorageSpiNor : public StorageBase, DiskOpsBase {
  public:
    StorageSpiNor();
    void On   ();
    
    mmcIOStates Write (uint8_t * buf, uint32_t len)      override;
    mmcIOStates Read  (uint8_t * buf, uint32_t len)      override;
    void CmdWrite     (uint32_t offset, uint32_t lenght) override;
    void CmdRead      (uint32_t offset, uint32_t lenght) override;
    uint32_t GetCapacity (void)                          override;
    
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
    
    const uint32_t mmcblock;            //!< délka bloku
    uint32_t       mmccapacity;         //!< kapacita disku = délka souboru
    uint32_t       mmcofs;              //!< offset
    uint32_t       mmclen;              //!< délka
};

#endif // STORAGESPINOR_H
