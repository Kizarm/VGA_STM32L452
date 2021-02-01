/*  Pmd32.h: Class for emulation of disk drive PMD 32
  Copyright (c) 2008-2010 Roman Borik <pmd85emu@gmail.com>
  Copyright (c) 2011 Martin Borik <mborik@users.sourceforge.net>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
#ifndef Pmd32H
#define Pmd32H
//---------------------------------------------------------------------------
#include "ChipMemory.h"
#include "IifGPIO.h"
#include "ff.h"
/** Přidána knihovna pro spolupráci s FAT filesystémem z dílny CHaN.
 * Tak je to připraveno pro spolupráci s flash a USB, jen zbývá dodělat
 * drivery flash po SPI v souboru diskio.c (ARM). Vypadá to zamotaně,
 * ale mohlo by to fungovat.
 * */
//---------------------------------------------------------------------------
#define OPER_FREQ               20000
#define CLOCK_PERIOD            (CPU_FREQ / OPER_FREQ)
#define PRESENT_TICKS           100     // 5 ms
#define SEND_BYTE_TICKS         2       // 100 us
#define FORMAT_RES_TICKS        8000    // 400 ms
#define RDWR_RES_TICKS          20      // 1 ms

#define PRESENTATION            0xAA
#define ACK                     0x33
#define NAK                     0x99

enum DISK_RESULT {
  RESULT_OK             =  0,       // OK
  RESULT_WP             =  1,       // write-protected disk
  RESULT_FE             =  2,       // format error
  RESULT_RE             =  3,       // read error
  RESULT_WE             =  4,       // write error
  RESULT_BD             =  5,       // bad disk number
  RESULT_NF             =  6,       // file/dir not found
  RESULT_TL             =  7,       // file/dir name too long
  RESULT_CE             =  8,       // disk image creation error
  RESULT_CM             =  9,       // configuration file missed
  RESULT_CR             =  10,      // configuration file read error
  RESULT_CC             =  11,      // configuration file corrupted
  RESULT_UI             =  12,      // unknown disk image file
};
enum DISK_STATE {
  IDLE_STATE            =  0,
  WAIT_PRESENT          =  1,
  WAIT_COMMAND          =  2,
  WAIT_CRC              =  3,
  WAIT_SECTOR           =  4,
  WAIT_TRACK            =  5,
  WAIT_DRIVE            =  6,
  WAIT_DATA             =  7,
  SEND_DATA             =  8,
  SEND_CRC              =  9,
  SEND_ACK              =  10,
  SEND_RESULT           =  11,
  SEND_NAK              =  12,
  WAIT_ADDR_H           =  13,
  WAIT_ADDR_L           =  14,
  WAIT_LEN_H            =  15,
  WAIT_LEN_L            =  16,
  WAIT_DATA_MEM         =  17,
  SEND_DATA_MEM         =  18,
  WAIT_FIND_TYPE        =  19,
  WAIT_LEN_NAME         =  20,
  WAIT_DATA_NAME        =  21,
  WAIT_WP               =  22,
};

#define SECTOR_SIZE             128
#define PHYSICAL_SECTOR_SIZE    (4 * SECTOR_SIZE)
#define INTERNAL_RAM_SIZE       (1 * SECTOR_SIZE)

#define MAX_SECTORS_PER_TRACKS  64
#define MAX_TRACKS              256

enum DRIVE_NUMBER {
  DRIVE_A = 0,
  DRIVE_B,
  DRIVE_C,
  DRIVE_D,
  NUM_DRIVES
};

//---------------------------------------------------------------------------
class Pmd32 {
  public:
    Pmd32 (IifGPIO * pio);
    /*
#ifndef __thumb__
    virtual ~Pmd32 () {
      f_exit();
    }
#endif // __thumb__
    */

    void BeforeReset() {};
    void AfterReset();
    void OnSetMode2 (BYTE CWR);
    void OnHandshake();

    void Disk32Service (int ticks, int dur);
    int  InsertDisk (int drive, char * file, bool WP);
    // void RemoveDisk (int drive); // nebudeme s tim hybat za chodu
    inline void SetWpDisk (int drv, bool wp) { drives[drv].wp = wp; }
    static void Disk32ServiceStatic (int ticks, int dur);
    int  InsertAllDisks ();

    int diskIcon;

  private:
    struct DRIVES {
      FIL    handle;
      bool   atached;
      bool   wp;
      BYTE   tracks;     // total tracks count
      BYTE   sectors;    // logical sectors per track
      BYTE   sectorSize; // physical sector size (0=128B, 1=256B, 2=512B, 3=1KB)
    };

    IifGPIO * pio;
    DRIVES    drives[NUM_DRIVES];

    BYTE   drvnum;
    BYTE   track;
    BYTE   sector;
    int    address;
    int    length;
    BYTE   findType;
    BYTE   wp;

    BYTE   memory [INTERNAL_RAM_SIZE];                        // zkusme zkratit
    BYTE   buffer [/*MAX_SECTORS_PER_TRACKS **/ SECTOR_SIZE]; // cte i zapisuje se po sektoru
    BYTE * point;
    DWORD  dwRW;

    BYTE   command;
    BYTE   CRC;
    int    byteCounter;
    bool   result;
    bool   inHandshake;

    BYTE   toSend;
    bool   noSend;

    int    diskState;
    int    diskTicks;
    int    tickCounter;

    void  Disk32ServiceStateCheck();
    void  Disk32ServiceSendResultCommand();

    bool  PrepareSector();
    bool  WriteSector();
    
    FATFS fatfs;
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
