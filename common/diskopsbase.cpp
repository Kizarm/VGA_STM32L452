#include "diskopsbase.h"

DSTATUS disk_status (
  BYTE pdrv   /* Physical drive nmuber to identify the drive */
) {
  if (DiskOpsBaseInstance) return DiskOpsBaseInstance->DiskStatus(pdrv);
  return STA_NOINIT;
}
/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
  BYTE pdrv       /* Physical drive nmuber to identify the drive */
) {
  if (DiskOpsBaseInstance) return DiskOpsBaseInstance->DiskInitialize(pdrv);
  return STA_NOINIT;
}
/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
  BYTE pdrv,    /* Physical drive nmuber to identify the drive */
  BYTE *buff,   /* Data buffer to store read data */
  LBA_t sector, /* Start sector in LBA */
  UINT count    /* Number of sectors to read */
) {
  if (DiskOpsBaseInstance) return DiskOpsBaseInstance->DiskRead (pdrv, buff, sector, count);
  return RES_NOTRDY;
}
/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
  BYTE pdrv,        /* Physical drive nmuber to identify the drive */
  const BYTE *buff, /* Data to be written */
  LBA_t sector,     /* Start sector in LBA */
  UINT count        /* Number of sectors to write */
) {
  if (DiskOpsBaseInstance) return DiskOpsBaseInstance->DiskWrite(pdrv, buff, sector, count);
  return RES_NOTRDY;
}

#endif

/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
  BYTE pdrv,    /* Physical drive nmuber (0..) */
  BYTE cmd,     /* Control code */
  void *buff    /* Buffer to send/receive control data */
) {
  if (DiskOpsBaseInstance) return DiskOpsBaseInstance->DiskIoctl(pdrv, cmd, buff);
  return RES_PARERR;
}
