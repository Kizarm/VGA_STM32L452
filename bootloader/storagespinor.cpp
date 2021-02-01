#include <string.h>
#include "msc_class.h"
#include "storagespinor.h"

static inline void delay (const unsigned dly = 100000) {
  volatile unsigned n = dly;
  while (--n);
}
DiskOpsBase * DiskOpsBaseInstance = nullptr;

StorageSpiNor::StorageSpiNor() : StorageBase(), spi(), cs_fl(GpioPortB, 6, GPIO_Mode_AN),
  initialized (false), fl (spi, cs_fl), mmcblock(MSC_BlockSize)  {
  On();
  mmclen = 0;
  mmcofs = 0;
  const uint8_t cb = fl.GetCapacityByte() & 0x1Fu;
  mmccapacity = ((1u << cb) / mmcblock);
  DiskOpsBaseInstance = this;
}
void StorageSpiNor::On() {
  if (initialized) return;
  +cs_fl;
  cs_fl.setMode (GPIO_Mode_OUT);
  cs_fl.setSpeed(GPIO_Speed_HS);

  delay();      // pockej az se ustali
  spi.Init();
  
  initialized = true;
}

mmcIOStates StorageSpiNor::Write (uint8_t * buf, uint32_t len) {
  if ((mmcblock * mmccapacity) < (mmcofs + len)) {
    parent->SetSenseData (SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE, mmcofs / mmcblock, 1);
    // return mmcIOEND;  // tt. případ reálně nenastává, možná bude nutno veškerý zápis dokončit
                         // jinak se poruší sekvence CBW CSW.
  }
  const unsigned wlen = fl.WriteBlock (mmcofs, buf, len);
  (void) wlen;
  mmcofs   += len;
  mmclen   -= len;
  parent->DecResidue(len);
  if (!mmclen) {
    return mmcIOEND;
  }
  return mmcIOPEN;
}

mmcIOStates StorageSpiNor::Read (uint8_t * buf, uint32_t len) {
  if ((mmcblock * mmccapacity) < (mmcofs + len)) {
    parent->SetSenseData(SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE, mmcofs / mmcblock, 1);
    // return mmcIOEND;  // tt. případ reálně nenastává, možná bude nutno veškeré čtení dokončit
                         // jinak se poruší sekvence CBW CSW.
  }
  // print ("pos=%d, len=%d\n", position, len);
  len = fl.ReadBlock (mmcofs, buf, len);
  mmcofs   += len;
  mmclen   -= len;
  parent->DecResidue(len);
  if (!mmclen) {
    return mmcIOEND;
  }
  return mmcIOPEN;
}

void StorageSpiNor::CmdWrite (uint32_t offset, uint32_t lenght) {
  mmcofs = mmcblock * offset;
  mmclen = mmcblock * lenght;
  fl.EraseSectors (mmcofs, mmclen);
  //if (rc != mmcofs) fprintf(stderr, "Seek error\n");
  //print("ofs=%6d, len=%d\n", offset, lenght);
  parent->SetSenseData (SS_NO_SENSE, 0, 0);  
}

void StorageSpiNor::CmdRead (uint32_t offset, uint32_t lenght) {
  mmcofs = mmcblock * offset;
  mmclen = mmcblock * lenght;
  //if (rc != mmcofs) fprintf(stderr, "Seek error\n");
  //print(" ofs=%6d, len=%d\n", offset, lenght);
  parent->SetSenseData (SS_NO_SENSE, 0, 0);  
}

uint32_t StorageSpiNor::GetCapacity (void) {
  return mmccapacity;
}

/****************************************************************************************************/
DSTATUS StorageSpiNor::DiskInitialize (BYTE pdrv) {
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
DSTATUS StorageSpiNor::DiskStatus (BYTE pdrv) {
  (void) pdrv;
  if (!initialized) return STA_NOINIT;
  return 0;
}
DRESULT StorageSpiNor::DiskIoctl (BYTE pdrv, BYTE cmd, void * buff) {
  (void) pdrv;
  switch (cmd) {
  case GET_SECTOR_SIZE: {
    WORD * p = (WORD*) buff;
    * p = mmcblock;
  } return RES_OK;
  default: break;
  }
  return RES_PARERR;
}
//////////////////////////////////////////////////////////////////////////////////////
DRESULT StorageSpiNor::DiskRead (BYTE pdrv, BYTE * buff, LBA_t sector, UINT count) {
  (void) pdrv;
  for (unsigned n=0; n<count; n++) {
    const unsigned offset = n * mmcblock;
    MediaRead (buff + offset, sector + n);
  }
  return RES_OK;
}
DRESULT StorageSpiNor::DiskWrite (BYTE pdrv, const BYTE * buff, LBA_t sector, UINT count) {
  (void) pdrv;
  for (unsigned n=0; n<count; n++) {
    const unsigned offset = n * mmcblock;
    MediaWrite (buff + offset, sector + n);
  }
  return RES_OK;
}
//////////////////////////////////////////////////////////////////////////////////////
void StorageSpiNor::MediaRead (uint8_t * buff, const uint32_t sect) {
  const uint32_t begin = sect * mmcblock;
  fl.ReadBlock    (begin, buff, mmcblock);

}
void StorageSpiNor::MediaWrite (const uint8_t * buff, const uint32_t sect) {
  const uint32_t begin = sect * mmcblock;
  fl.EraseSectors (begin, mmcblock);
  fl.WriteBlock   (begin, buff, mmcblock);
}
