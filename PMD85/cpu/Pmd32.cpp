/*  Pmd32.cpp: Class for emulation of disk drive PMD 32
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
#include <string.h>

#include "Pmd32.h"
//---------------------------------------------------------------------------
// pridano pro callback cpu.TCyclesListeners, predpoklada jedinou instanci tt. tridy
static Pmd32 * Pmd32Instance = nullptr;     // nemusi byt soucasti tridy
void Pmd32::Disk32ServiceStatic (int ticks, int dur) {
  if (Pmd32Instance) Pmd32Instance->Disk32Service (ticks, dur);
}
//---------------------------------------------------------------------------
Pmd32::Pmd32 (IifGPIO *pio) {
  Pmd32Instance = this;
  this->pio = pio;
  pio->Attach (this);
  //pio->OnBeforeResetA.connect (this, &Pmd32::BeforeReset);
  //pio->OnAfterResetA.connect (this, &Pmd32::AfterReset);

  for (int ii = 0; ii < NUM_DRIVES; ii++) {
    DRIVES & dr = drives [ii];
    memset (&dr.handle, 0, sizeof (FIL));
    dr.wp       = true;
    dr.atached  = false;
  }
  drvnum    = 0;
  diskIcon  = 0;
  diskTicks = 0;
  diskState = IDLE_STATE;
  tickCounter = CPU_FREQ;
  inHandshake = false;

  memset (memory, 0, sizeof (memory));
  
  f_mount (& fatfs, "", 0);
}
//---------------------------------------------------------------------------
void Pmd32::AfterReset() {
  //pio->OnCpuWriteCWR.connect (this, &Pmd32::OnSetMode2);
  //pio->OnCpuWriteCH.connect  (this, &Pmd32::OnHandshake);

  diskTicks = 0;
  diskState = IDLE_STATE;
  tickCounter = CPU_FREQ;
  inHandshake = false;
  diskIcon = 0;
}
//---------------------------------------------------------------------------
void Pmd32::OnSetMode2 (BYTE CWR) {
  // debug ("OnSetMode2 CWR = %02X\n", CWR);
  if ( (CWR & GA_MODE) == GA_MODE2) {
    pio->ChangeBit (PP_PortC, _STBA, true);
    pio->ChangeBit (PP_PortC, _ACKA, true);
    diskState = WAIT_PRESENT;
    tickCounter = PRESENT_TICKS;
  } else {
    diskState = IDLE_STATE;
    tickCounter = CPU_FREQ;
  }
}
//---------------------------------------------------------------------------
void Pmd32::OnHandshake() {
  BYTE val = 0;
  inHandshake = true;
  const bool cond = pio->ReadBit (PP_PortC, _OBFA);

  if (cond == false) {
    pio->ChangeBit (PP_PortC, _ACKA, false);
    val = pio->ReadByte (PP_PortA);
    pio->ChangeBit (PP_PortC, _ACKA, true);

    // debug ("OnHandshake: %d\n", (int) diskState);
    switch (diskState) {
    case WAIT_PRESENT:
      if (val == PRESENTATION) diskState = WAIT_COMMAND;
      break;

    case WAIT_COMMAND:
      command = val;
      switch (val) {
      case 'B': // BOOT
      case '*': // FAST mode
      case '@': // SLOW mode
        diskState = WAIT_CRC;
        break;

      case 'Q': // read logical sector
      case 'R': // read logical sector
      case 'T': // write logical sector
      case 'W': // write logical sector
      case 'S': // write physical sector
      case 'F': // format track
        diskState = WAIT_SECTOR;
        break;

      case 'I': // drive select + HOME
        diskState = WAIT_DRIVE;
        break;

      case 'U': // write to PMD 32 memory
      case 'C': // read from PMD 32 memory
      case 'J': // execute code in PMD 32 memory
        diskState = WAIT_ADDR_H;
        break;

      case 'G': // get inserted disk image name
      case 'H': // insert disk image
      case 'P': // get disk parameters
        diskState = /*(extraCommands) ? WAIT_DRIVE :*/ WAIT_PRESENT;
        break;

      case 'K': // get actual SD card path
        diskState = /*(extraCommands) ? WAIT_CRC :*/ WAIT_PRESENT;
        break;

      case 'L': // get catalog of actual SD card path
        diskState = /*(extraCommands) ? WAIT_FIND_TYPE :*/ WAIT_PRESENT;
        break;

      case 'M': // change actual SD card path
        diskState = /*(extraCommands) ? WAIT_LEN_NAME :*/ WAIT_PRESENT;
        break;

      case 'N': // create new disk image in actual SD card path
        diskState = /*(extraCommands) ? WAIT_LEN_NAME :*/ WAIT_PRESENT;
        break;

      case PRESENTATION:
        break;

      default:
        diskState = WAIT_PRESENT;
        break;
      }
      CRC = command;
      break;

    case WAIT_SECTOR:
      sector = val;
      drvnum = (BYTE) (sector >> 6);
      if (drvnum > 0 && drvnum < 3) drvnum ^= 3;
      sector &= 0x3F;
      CRC ^= val;
      diskIcon = 1 + (drvnum & (NUM_DRIVES - 1));
      if (command == 'T' || command == 'W' || command == 'S' || command == 'F') diskIcon += NUM_DRIVES;
      diskState = WAIT_TRACK;
      break;

    case WAIT_TRACK:
      track = val;
      CRC ^= val;
      if (command == 'T' || command == 'W' || command == 'S') {
        point = buffer;
        diskState = WAIT_DATA;
        if (command == 'T' || command == 'W')
          byteCounter = SECTOR_SIZE;
        else
          byteCounter = PHYSICAL_SECTOR_SIZE + 1;
      } else
        diskState = WAIT_CRC;
      break;

    case WAIT_DRIVE:
      drvnum = val;
      CRC ^= val;
      if (command == 'H')
        diskState = WAIT_WP;
      else
        diskState = WAIT_CRC;
      break;

    case WAIT_DATA:
      *point++ = val;
      CRC ^= val;
      if (--byteCounter == 0)
        diskState = WAIT_CRC;
      break;

    case WAIT_ADDR_H:
      address = val << 8;
      CRC ^= val;
      diskState = WAIT_ADDR_L;
      break;

    case WAIT_ADDR_L:
      address |= val;
      CRC ^= val;
      if (command == 'J') {
        debug (/*"PMD32", */"%c: %04X", command, address);
        diskState = WAIT_CRC;
      } else
        diskState = WAIT_LEN_H;
      break;

    case WAIT_LEN_H:
      length = val << 8;
      CRC ^= val;
      diskState = WAIT_LEN_L;
      break;

    case WAIT_LEN_L:
      length |= val;
      CRC ^= val;
      if (command == 'C' || command == 'U')
        debug (/*"PMD32", */"%c: %04X,%04X", command, address, length);

      if (command == 'C') diskState = WAIT_CRC;
      else {
        byteCounter = length;
        diskState = WAIT_DATA_MEM;
      }
      break;

    case WAIT_DATA_MEM:
      debug ("address = %d\n", address);
      if (address < INTERNAL_RAM_SIZE)   memory [address] = val;
      address++;
      CRC ^= val;
      if (--byteCounter == 0)
        diskState = WAIT_CRC;
      break;

    case WAIT_FIND_TYPE:
      findType = val;
      CRC ^= val;
      diskState = WAIT_CRC;
      break;

    case WAIT_LEN_NAME:
      CRC ^= val;
      if (val == 0 || val == 0xFF) diskState = WAIT_CRC;
      else                         diskState = WAIT_DATA_NAME;
      point = buffer;
      *point++ = val;
      byteCounter = (int) val;
      break;

    case WAIT_DATA_NAME:
      *point++ = val;
      CRC ^= val;
      if (--byteCounter == 0) {
        *point = 0;
        diskState = WAIT_CRC;
      }
      break;

    case WAIT_WP:
      wp = val;
      CRC ^= val;
      diskState = WAIT_LEN_NAME;
      break;

    case WAIT_CRC:
      if (val == CRC)
        diskState = SEND_ACK;
      else
        diskState = SEND_NAK;
      break;

    }
  }

  inHandshake = false;
}
//---------------------------------------------------------------------------
void Pmd32::Disk32Service (int /*ticks*/, int dur) {
  diskTicks += dur;
  if (diskTicks >= CLOCK_PERIOD) {
    diskTicks -= CLOCK_PERIOD;

    if (inHandshake == false && --tickCounter <= 0) {
      tickCounter = SEND_BYTE_TICKS;
      if (pio->ReadBit (PP_PortC, IBFA) == false) {
        noSend = false;
        Disk32ServiceStateCheck();

        if (noSend == false) {
          pio->WriteByte (PP_PortA, toSend);
          pio->ChangeBit (PP_PortC, _STBA, false);
          pio->ChangeBit (PP_PortC, _STBA, true);
        }
      }

      if (diskState == WAIT_PRESENT || diskState == WAIT_COMMAND) {
        tickCounter = PRESENT_TICKS;
        diskIcon = 0;
      }
    }
  }
}
//---------------------------------------------------------------------------
void Pmd32::Disk32ServiceStateCheck() {
  // debug ("Disk32ServiceStateCheck: %d\n", (int) diskState);
  switch (diskState) {
  case WAIT_PRESENT:
    toSend = PRESENTATION;
    break;

  case SEND_DATA:
    toSend = *point++;
    CRC ^= toSend;
    if (--byteCounter == 0)  diskState = SEND_CRC;
    break;

  case SEND_DATA_MEM:
    debug ("address = %d\n", address);
    if (address < INTERNAL_RAM_SIZE) toSend = memory[address];
    address++;
    CRC ^= toSend;
    if (--byteCounter == 0)
      diskState = SEND_CRC;
    break;

  case SEND_CRC:
    toSend = CRC;
    diskState = WAIT_COMMAND;
    break;

  case SEND_ACK:
    toSend = ACK;
    diskState = SEND_RESULT;
    switch (command) {
    case 'C': // read from PMD 32 memory
      byteCounter = length;
      CRC = ACK;
      diskState = SEND_DATA_MEM;
      break;

    case 'B': // BOOT
    case 'Q': // read logical sector
    case 'R': // read logical sector
    case 'T': // write logical sector
    case 'W': // write logical sector
    case 'S': // write physical sector
    case 'U': // write to PMD 32 memory
    case 'J': // execute code in PMD 32 memory
    case 'G': // get inserted disk image name
    case 'H': // insert disk image
    case 'K': // get actual SD card path
    case 'L': // get catalog of actual SD card path
    case 'M': // change actual SD card path
    case 'N': // create new image in actual SD card path
    case 'P': // get disk parameters
      tickCounter = RDWR_RES_TICKS;
      break;

    case 'F': // format track
      tickCounter = FORMAT_RES_TICKS;
      break;
    }
    break;

  case SEND_RESULT:
    Disk32ServiceSendResultCommand();
    break;

  case SEND_NAK:
    toSend = NAK;
    diskState = WAIT_COMMAND;
    break;

  default:
    noSend = true;
    break;
  }
}
//---------------------------------------------------------------------------
void Pmd32::Disk32ServiceSendResultCommand() {
  // debug ("Disk32ServiceSendResultCommand: %c\n", (char) command);
  switch (command) {
  case 'B': // BOOT
    drvnum = 0;
    track = 0;
    sector = 0;
    diskIcon = 1;
  case 'Q': // read logical sector
  case 'R': // read logical sector
    if (PrepareSector() == true) {
      point = buffer;
      byteCounter = SECTOR_SIZE;
      CRC = 0;
      diskState = SEND_DATA;
      toSend = RESULT_OK;
    } else {
      diskState = WAIT_COMMAND;
      toSend = RESULT_RE;
    }
    break;

  case 'T': // write logical sector
  case 'W': // write logical sector
  case 'S': // write physical sector
  case 'F': // format track
    if (drives[drvnum].wp == true)   toSend = RESULT_WP;
    else if (WriteSector() == true)  toSend = RESULT_OK;
    else                             toSend = RESULT_WE;
    diskState = WAIT_COMMAND;
    break;

  case 'I': // drive select
  case '*': // FAST mode
  case '@': // SLOW mode
  case 'U': // write to PMD 32 memory
  case 'J': // execute code in PMD 32 memory
    toSend = RESULT_OK;
    diskState = WAIT_COMMAND;
    break;
  // Tyhle složité funkce jsem odebral kvůli zjednodušení, pro hraní asi zatím nevadí.
  case 'G': // get inserted disk image name ???
  case 'H': // insert disk image ???
  case 'K': // get actual SD card path ???
  case 'L': // get catalog of actual SD card path ???
  case 'M': // change actual SD card path ???
  case 'N': // create new disk image in actual SD card path ???
    warning ("Disk32ServiceSendResultCommand", "Removed cmd %d\n", command);
    break;

  case 'P': // get disk parameters
    if (drvnum > 3) {
      toSend = RESULT_BD;
      diskState = WAIT_COMMAND;
    } else {
      toSend = RESULT_OK;
      if (!drives[drvnum].atached) {
        *  buffer = 0;
        * (buffer + 1) = 0;
        * (buffer + 2) = 0;
      } else {
        *  buffer = drives[drvnum].tracks;
        * (buffer + 1) = drives[drvnum].sectors;
        * (buffer + 2) = drives[drvnum].sectorSize;
      }
      point = buffer;
      byteCounter = 3;
      CRC = 0;
      diskState = SEND_DATA;
    }
    break;
  }
}
//---------------------------------------------------------------------------
bool Pmd32::PrepareSector() {
  DRIVES & drv = drives [drvnum];
  if (drv.atached && sector < drv.sectors && (drv.tracks == 0 || track < drv.tracks)) {

    DWORD seek = track * drv.sectors * SECTOR_SIZE + sector * SECTOR_SIZE;
    if (f_lseek (&drv.handle, seek/*, SEEK_SET*/) == FR_OK) {
      // debug ("%d READ at track %d, sector %d\n", drvnum, track, sector);
      UINT readen = 0;
      if (f_read (&drv.handle, buffer, SECTOR_SIZE, &readen) == FR_OK) return true;
    }
  }

  return false;
}
//---------------------------------------------------------------------------
bool Pmd32::WriteSector() {
  DRIVES & drv = drives [drvnum];
  DWORD size;

  if (command == 'S') {
    sector &= 0x3C;
    size = PHYSICAL_SECTOR_SIZE;
  } else if (command == 'T' || command == 'W')
    size = SECTOR_SIZE;
  else { // 'F'
    size = drv.sectors * SECTOR_SIZE;
    sector = 0;
    memset (buffer, 0xE5, sizeof (buffer));
  }

  if (drv.atached && sector < drv.sectors
      && (drv.tracks == 0 || track < drv.tracks)) {

    DWORD seek = track * drv.sectors * SECTOR_SIZE + sector * SECTOR_SIZE;
    if (f_lseek (&drv.handle, seek) == FR_OK) {
      // debug ("%d WRITE at track %d, sector %d\n", drvnum, track, sector);
      UINT writen = 0u;
      if (f_write (&drv.handle, buffer, size, &writen) == FR_OK) {
        if (writen == size) return true;
      }
    }
  }

  return false;
}
//---------------------------------------------------------------------------
int Pmd32::InsertDisk (int drive, char * file, bool WP) {
  // RemoveDisk (drive);
  DRIVES & drv = drives [drive];
  drv.tracks     = 80;
  drv.sectors    = 36;
  drv.sectorSize = 2;
  drv.wp         = WP;
  const BYTE mode = FA_READ | (WP ? 0 : FA_WRITE);
  if (f_open (&drv.handle, file, mode) == FR_OK) drv.atached = true;

  if (!drv.atached) return RESULT_NF;
  
  debug ("Drive %d file=\"%s\"%*s, sects=%d, tracks=%d, sectSize=%d, WP=%s\n",
         drive, file, (int) (14 - strlen(file)), "", drives[drive].sectors, drives[drive].tracks,
         drives[drive].sectorSize, WP ? "true" : "false");
  return RESULT_OK;
}
//---------------------------------------------------------------------------
/** V kořenovém adresáři FAT filesystému se musí vytvořit podadresáře A,B,C,D.
 * Pokud je v těchto podadresářích nějaký soubor, použije se jako příslušná
 * jednotka (první nalezený, ostatní jsou ignorovány). Nekontroluje se ani
 * přípona .p32 ani formát souboru, to je na tom, kdo to tam nakopíroval.
 * Kontroluje se přístup - pokud je readonly, nastaví se příznak WP.
 * */
int Pmd32::InsertAllDisks () {
  const int pathlen = 64;
  char path [pathlen];
  FRESULT res;
  for (int n=0; n<NUM_DRIVES; n++) {
    memset (path, 0, pathlen);
    const char d = 'A' + n;
    int i = 0;
    path [i++] = d;
    DIR dir;
    res = f_opendir (&dir, path);
    if (res != FR_OK) continue;
    FILINFO fno;
    for (;;) {
      res = f_readdir (&dir, &fno);
      if (res != FR_OK || fno.fname[0] == 0) break;
      if (!(fno.fattrib & AM_DIR)) {
        // 1. regulerni soubor v adresari A,B,C,D
        path [i++] = '/';
        memcpy (path + i, fno.fname, strlen (fno.fname));
        // debug  ("%d:%s\n", n, path);
        InsertDisk (n, path, fno.fattrib & AM_RDO ? true : false);
        break;
      }
    }
    f_closedir(&dir);
  }
  return RESULT_OK;
}

/*
void Pmd32::RemoveDisk (int drive) {
  if (drives[drive].handle) fclose (drives[drive].handle);
  drives[drive].handle = nullptr;
}
*/
//---------------------------------------------------------------------------
