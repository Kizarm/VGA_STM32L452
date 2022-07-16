#include "mendian.h"
#include "msc_class.h"
/*
#include "STM32L4x2.h"
#include "common.h"
#include "core_cm4.h"
*/
#include "led.h"
#include "gpio.h"

#define MSC_EP0_SIZE    0x40
#define MSC_RXD_EP      0x01
#define MSC_TXD_EP      0x81
#define MSC_DATA_SZ     0x40

static const struct usb_device_descriptor device_desc = {
  .bLength            = sizeof (struct usb_device_descriptor),
  .bDescriptorType    = USB_DTYPE_DEVICE,
  .bcdUSB             = VERSION_BCD (2,0,0),
  .bDeviceClass       = 0,                      // at Interface level
  .bDeviceSubClass    = USB_SUBCLASS_NONE,
  .bDeviceProtocol    = USB_PROTO_NONE,
  .bMaxPacketSize0    = MSC_EP0_SIZE,
  .idVendor           = 0x0483,
  .idProduct          = 0x5740,
  .bcdDevice          = VERSION_BCD (1,0,0),
  .iManufacturer      = 1,
  .iProduct           = 2,
  .iSerialNumber      = 3,
  .bNumConfigurations = 1,
};

static const unsigned char UsbConfigDescriptor [] __attribute__((aligned(4))) = {
  0x09,0x02,0x20,0x00,0x01,0x01,0x00,0x80,0x32,
  // Msc     Interface 0
  0x09,0x04,0x00,0x00,0x02,0x08,0x06,0x50,0x04,
  0x07,0x05,0x01,0x02,0x40,0x00,0x00,
  0x07,0x05,0x81,0x02,0x40,0x00,0x00,
};
/** **************************************************/

extern const usb_string_descriptor * const dtable[];

/** **************************************************/

static inline void bytecopy (void * dst, const void * src, uint32_t len) {
  const char * s = (const char *) src;
  char       * d = (char       *) dst;
  for (uint32_t i=0; i<len; i++)  d[i] = s[i];
}

void data_endpoint::evt_handler (usbd_events event, uint8_t ep) {
  ifc->handler(event, ep);
}


/** **************************************************/
MsClass::MsClass(usbd_device & p) : usbd_interface(p), de(p, this)  {
  //addIface (& msif);
  BulkStage      = MSC_BS_CBW;
  SenseData.data = SS_RESET_OCCURRED;
  ReadOnly = false;
}
void MsClass::init() {
  parent->usbd_init  (MSC_EP0_SIZE);
  parent->enable  (true);
  parent->connect (true);
}

void MsClass::handler (usbd_events event, uint8_t ep) {
  switch (event) {
  case usbd_evt_eprx:
    BulkOut ();
    break;
  case usbd_evt_eptx:
    BulkIn();
    break;
  default:
    break;
  }

}
usbd_respond MsClass::if_cfg (uint8_t cfg) {
  switch (cfg) {
  case 0:
    /* deconfiguring device */
    parent->ep_deconfig  (MSC_TXD_EP);
    parent->ep_deconfig  (MSC_RXD_EP);
    parent->usbd_reg_endpoint (MSC_RXD_EP, 0);
    parent->usbd_reg_endpoint (MSC_TXD_EP, 0);
    return usbd_ack;
  case 1:
    /* configuring device */
    parent->ep_config (MSC_RXD_EP, USB_EPTYPE_BULK, MSC_DATA_SZ);
    parent->ep_config (MSC_TXD_EP, USB_EPTYPE_BULK, MSC_DATA_SZ);
    
    parent->usbd_reg_endpoint (MSC_RXD_EP, &de);
    parent->usbd_reg_endpoint (MSC_TXD_EP, &de);
    return usbd_ack;
  default:
    return usbd_fail;
  }
}
usbd_respond MsClass::if_ctl (usbd_ctlreq * p) {
  switch (p->bRequest) {
    case MSC_REQUEST_RESET:
      if ( (p->wValue  == 0) &&                  /* RESET with invalid parameters -> STALL */
           (p->wLength == 0)) {
        if (Reset ()) {
          return usbd_ack;
        }
      }
      break;
    case MSC_REQUEST_GET_MAX_LUN:
      if ( (p->wValue  == 0) &&                  /* GET_MAX_LUN with invalid parameters -> STALL */
           (p->wLength == 1)) {
        if (GetMaxLUN ()) {
          return usbd_ack;
        }
      }
      break;
  }

  return usbd_fail;
}
usbd_respond MsClass::if_dsc (usbd_ctlreq* req, void** address, uint16_t* length) {
  const uint8_t dtype = req->wValue >> 8;
  const uint8_t dnumber = req->wValue & 0xFF;
  const void* desc;
  uint16_t len = 0;
  // asm volatile ("bkpt 0");
  switch (dtype) {
  case USB_DTYPE_DEVICE:
    desc = &device_desc;
    break;
  case USB_DTYPE_CONFIGURATION:
    desc = UsbConfigDescriptor;
    len = sizeof (UsbConfigDescriptor);
    break;
  case USB_DTYPE_STRING:
    if (dnumber < 5) {
      desc = dtable[dnumber];
    } else {
      return usbd_fail;
    }
    break;
  default:
    return usbd_fail;
  }
  if (len == 0) {
    len = ((struct usb_header_descriptor*) desc)->bLength;
  }
  *address = (void*) desc;
  *length = len;
  return usbd_ack;
}

void MsClass::BulkIn (void) {
  switch (BulkStage) {
    case MSC_BS_DATA_IN:
      switch (CBW.CB[0]) {
        case SCSI_READ10:
        case SCSI_READ12:
          MSC_MemoryRead();
          break;
      }
      break;
    case MSC_BS_DATA_IN_LAST:
      MSC_SetCSW();
      break;
    case MSC_BS_DATA_IN_LAST_STALL:
      MSC_SetStallEP (EndpointIn);
      MSC_SetCSW();
      break;
    case MSC_BS_CSW:
      BulkStage = MSC_BS_CBW;
      break;
    default: break;
  }
}
void MsClass::BulkOut (void) {
  BulkLen = parent->ep_read (MSC_RXD_EP, BulkBuf, MSC_DATA_SZ);
  switch (BulkStage) {
    case MSC_BS_CBW:
      MSC_GetCBW();
      break;
    case MSC_BS_DATA_OUT:
      switch (CBW.CB[0]) {
        case SCSI_WRITE10:
        case SCSI_WRITE12:
          MSC_MemoryWrite();
          break;
        case SCSI_VERIFY10:
          MSC_MemoryVerify();
          break;
      }
      break;
    default:
      MSC_SetStallEP(EndpointOut);
      CSW.bStatus = CSW_PHASE_ERROR;
      MSC_SetCSW();
      break;
  }
}
void MsClass::DecResidue (uint32_t n) {
  if (SenseData.data == SS_NO_SENSE)
    CSW.dDataResidue -= n;
}
void MsClass::MSC_RewriteCSW (void) {
  if (CSW.dSignature == MSC_CSW_Signature) {
    parent->ep_write (MSC_TXD_EP, &CSW, sizeof(CSW));
  }
}
void MsClass::SetSenseData (uint32_t t, uint32_t i, uint8_t v) {
  SenseData.data  = t;
  SenseData.info  = i;
  if (v) SenseData.valid = 0x80;
  else   SenseData.valid = 0x00;
}

bool MsClass::GetMaxLUN (void) {
  //dbg();                           /* No LUN associated with this device */
  return true;
}

static GpioClass led (LedPort, LedPin);

void MsClass::MSC_SetCSW (void) {
  uint32_t mtag = CSW.dTag;
  if (mtag & 1) +led;
  else          -led;
  
  CSW.dSignature = MSC_CSW_Signature;
  parent->ep_write (MSC_TXD_EP, &CSW, sizeof(CSW));
  BulkStage = MSC_BS_CSW;
}
void MsClass::MSC_GetCBW (void) {
  uint32_t n;

  for (n = 0; n < BulkLen; n++) {
    *((uint8_t *)&CBW + n) = BulkBuf[n];
  }
  if ((BulkLen == sizeof(CBW)) && (CBW.dSignature == MSC_CBW_Signature)) {
    /* Valid CBW */
    CSW.dTag = CBW.dTag;
    CSW.dDataResidue = CBW.dDataLength;
    if ((CBW.bLUN      != 0) || 
        (CBW.bCBLength <  1) || 
        (CBW.bCBLength > 16)   ) {
      //error("BAD LUN OR LENGHT\n");
      CSW.bStatus = CSW_CMD_FAILED;
      SetSenseData (SS_LOGICAL_UNIT_NOT_SUPPORTED, 0, 0);
      MSC_SetCSW();
    } else {                              // CBW OK
      MSC_CommandParser ((SCSI_Commands) CBW.CB[0]);
    }
  } else {
    /* Invalid CBW */
    MSC_SetStallEP (EndpointIn);
                                           /* set EP to stay stalled */
    MSC_SetStallEP (EndpointOut);
                                           /* set EP to stay stalled */
    BulkStage = MSC_BS_ERROR;
  }
}
void MsClass::MSC_CommandParser (SCSI_Commands p) {
  switch (p) {
    case SCSI_TEST_UNIT_READY:
      MSC_TestUnitReady();
      break;
    case SCSI_REQUEST_SENSE:
      MSC_RequestSense();
      break;
    case SCSI_INQUIRY:
      MSC_Inquiry();
      break;
    case SCSI_MODE_SENSE6:
      MSC_ModeSense6();
      break;
    case SCSI_MODE_SENSE10:
      MSC_ModeSense10();
      break;
    case SCSI_READ_FORMAT_CAPACITIES:
      MSC_ReadFormatCapacity();
      break;
    case SCSI_READ_CAPACITY:
      MSC_ReadCapacity();
      break;
    case SCSI_READ10:
    case SCSI_READ12:
      if (MSC_ReadSetup()) {
        if ((CBW.bmFlags & 0x80) != 0) {
          BulkStage = MSC_BS_DATA_IN;
          MSC_MemoryRead();
        } else {                       /* direction mismatch */
          MSC_SetStallEP(EndpointOut);
          //error("READ DIR ERR\n");
          CSW.bStatus = CSW_PHASE_ERROR;
          MSC_SetCSW();
        }
      }
      break;
    case SCSI_WRITE10:
    case SCSI_WRITE12:
      if (MSC_WriteSetup()) {
        if ((CBW.bmFlags & 0x80) == 0) {
          BulkStage = MSC_BS_DATA_OUT;
        } else {                       /* direction mismatch */
          MSC_SetStallEP(EndpointIn);
          //error("WRITE DIR ERR\n");
          CSW.bStatus = CSW_PHASE_ERROR;
          MSC_SetCSW();
        }
      }
      break;
    case SCSI_VERIFY10:
      if ((CBW.CB[1] & 0x02) == 0) {
        // BYTCHK = 0 -> CRC Check (not implemented)
        CSW.bStatus = CSW_CMD_PASSED;
        MSC_SetCSW();
        break;
      }
      if (MSC_ReadSetup()) {
        if ((CBW.bmFlags & 0x80) == 0) {
          BulkStage = MSC_BS_DATA_OUT;
          MemOK = true;
        } else {
          MSC_SetStallEP(EndpointIn);
          //error("VERIFY DIR ERR\n");
          CSW.bStatus = CSW_PHASE_ERROR;
          MSC_SetCSW();
        }
      }
      break;
    case SCSI_START_STOP_UNIT:
    case SCSI_MEDIA_REMOVAL:
    case SCSI_MODE_SELECT6:
    case SCSI_MODE_SELECT10:
    case SCSI_FORMAT_UNIT:
    default:                        // FAIL - Unsuported cmd
      //error("Unsupported cmd [0x%02X]\n", p);
      CSW.bStatus = CSW_CMD_FAILED;
      SetSenseData (SS_INVALID_FIELD_IN_CDB, 0, 0);
      MSC_SetCSW();
      break;
  }
}

void MsClass::MSC_MemoryRead (void) {
  uint32_t n;
  mmcIOStates st;


  n = MSC_MAX_PACKET;
  
  st = mmc->Read (BulkBuf, n);
  parent->ep_write (MSC_TXD_EP, BulkBuf, n);
  
  if (st == mmcIOPEN) return;

  BulkStage = MSC_BS_DATA_IN_LAST;
  if (SenseData.data == SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE) {
    BulkStage = MSC_BS_DATA_IN_LAST_STALL;
  }

  if (BulkStage != MSC_BS_DATA_IN) {
    // print("res=%d\n", CSW.dDataResidue);
    if (SenseData.data == SS_NO_SENSE)
      CSW.bStatus = CSW_CMD_PASSED;
    else
      CSW.bStatus = CSW_CMD_FAILED;
  }
}
void MsClass::MSC_MemoryVerify (void) {
  uint32_t n;
  mmcIOStates   st;
  static uint8_t  tmp[MSC_MAX_PACKET];
  
  st = mmc->Read(tmp, BulkLen);
  for (n = 0; n < BulkLen; n++) {
    if (tmp[n] != BulkBuf[n]) {
      MemOK = false;
      break;
    }
  }
  if (st == mmcIOPEN) return;
  
  BulkStage = MSC_BS_CSW;
  if (SenseData.data == SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE) {
    MSC_SetStallEP(EndpointOut);
  }
  if (SenseData.data != SS_NO_SENSE) MemOK = 0;
  CSW.bStatus = (MemOK) ? CSW_CMD_PASSED : CSW_CMD_FAILED;
  MSC_SetCSW();
}
void MsClass::MSC_MemoryWrite (void) {
  mmcIOStates st;
  
  st = mmc->Write (BulkBuf, BulkLen);
  if (st == mmcIOPEN) return;
  
  BulkStage = MSC_BS_CSW;
  if (SenseData.data == SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE) {
    MSC_SetStallEP(EndpointOut);
  }

  if (SenseData.data == SS_NO_SENSE)
    CSW.bStatus = CSW_CMD_PASSED;
  else
    CSW.bStatus = CSW_CMD_FAILED;
  MSC_SetCSW();
}
bool MsClass::DataInFormat (void) {
  if (CBW.dDataLength == 0) {
    CSW.bStatus = CSW_PHASE_ERROR;
    MSC_SetCSW();
    return (false);
  }
  if ((CBW.bmFlags & 0x80) == 0) {
    MSC_SetStallEP(EndpointOut);
    CSW.bStatus = CSW_PHASE_ERROR;
    MSC_SetCSW();
    return false;
  }
  return true;
}
void MsClass::DataInTransfer (void) {
  if (BulkLen >= CBW.dDataLength)
    BulkLen = CBW.dDataLength;
  BulkStage = MSC_BS_DATA_IN_LAST;
  
  parent->ep_write (MSC_TXD_EP, BulkBuf, BulkLen);

  CSW.dDataResidue -= BulkLen;
  CSW.bStatus = CSW_CMD_PASSED;
}
void MsClass::MSC_Inquiry (void) {
  // dbg();

  if (!DataInFormat()) return;
  
  static const unsigned char hdr [] = {
    0,          // Direct Access Device
    0x80,       // RMB = 1: Removable Medium
    0,          // Version: No conformance claim to standard
    0x01,
    
    36-4,       // Additional Length
    0x80,       // SCCS = 1: Storage Controller Component
    0,
    0
  };
  uint32_t i = 0,j = 8;
  bytecopy (BulkBuf + i, hdr, j);
  i += j;
  j  = 28;
  bytecopy (BulkBuf + i, "Kizarm. SPI NOR flash on USB", j);
  i += j;
  BulkBuf [4] = i - 4;
  BulkLen     = i;
  
  DataInTransfer();

}
void MsClass::MSC_ModeSense10 (void) {
  if (!DataInFormat()) return;
  static const unsigned char hdr [] = {
    0,0x6,0,0, 0,0,0,0
  };
  bytecopy (BulkBuf, hdr, 8);

  BulkLen = 8;
  DataInTransfer();
}
void MsClass::MSC_ModeSense6 (void) {
  if (!DataInFormat()) return;
  if (!DataInFormat()) return;
  static const unsigned char hdr [] = {
    0x03,0,0 /** 0x80 read-only */ ,0
  };
  bytecopy (BulkBuf, hdr, 4);
  
  if (ReadOnly) BulkBuf [2] = 0x80;

  BulkLen = 4;
  DataInTransfer();
}
void MsClass::MSC_ReadCapacity (void) {
  if (!DataInFormat()) return;
  
  // Last Logical Block
  __be32 BlockCount = mmc->GetCapacity() - 1;
  bytecopy (BulkBuf, & BlockCount, 4);
  
  // Block Length
  __be32 BlockSize = MSC_BlockSize;
  bytecopy (BulkBuf + 4, & BlockSize, 4);

  BulkLen = 8;
  DataInTransfer();
}
void MsClass::MSC_ReadFormatCapacity (void) {
  if (!DataInFormat()) return;
  
  __be32 BlockCount = mmc->GetCapacity();

  BulkBuf[ 0] = 0x00;
  BulkBuf[ 1] = 0x00;
  BulkBuf[ 2] = 0x00;
  BulkBuf[ 3] = 0x08;          /* Capacity List Length */

  /* Block Count */
  bytecopy (BulkBuf + 4, & BlockCount, 4);

  /* Block Length */
  BulkBuf[ 8] = 0x02;          /* Descriptor Code: Formatted Media */
  BulkBuf[ 9] = (MSC_BlockSize >> 16) & 0xFF;
  BulkBuf[10] = (MSC_BlockSize >>  8) & 0xFF;
  BulkBuf[11] = (MSC_BlockSize >>  0) & 0xFF;

  BulkLen = 12;
  DataInTransfer();
}
bool MsClass::MSC_ReadSetup (void) {
  uint32_t m, n=0;
  /* Logical Block Address of First Block */
  m = (CBW.CB[2] << 24) |
      (CBW.CB[3] << 16) |
      (CBW.CB[4] <<  8) |
      (CBW.CB[5] <<  0);

  /* Number of Blocks to transfer */
  switch (CBW.CB[0]) {
    case SCSI_READ10:
    case SCSI_VERIFY10:
      n = (CBW.CB[7] <<  8) |
          (CBW.CB[8] <<  0);
      break;

    case SCSI_READ12:
      n = (CBW.CB[6] << 24) |
          (CBW.CB[7] << 16) |
          (CBW.CB[8] <<  8) |
          (CBW.CB[9] <<  0);
      break;
  }

  if (CBW.dDataLength == 0) {              /* host requests no data */
    //error("HOST REQ NO DATA\n");
    CSW.bStatus = CSW_CMD_FAILED;
    MSC_SetCSW();
    return (false);
  }

  if (CBW.dDataLength != n * MSC_BlockSize) {
    if ((CBW.bmFlags & 0x80) != 0) {       /* stall appropriate EP */ 
      MSC_SetStallEP(EndpointIn);
    } else {
      MSC_SetStallEP(EndpointOut);
    }
    //error("BAD REQ LEN %d\n", n);
    CSW.bStatus = CSW_CMD_FAILED;
    MSC_SetCSW();

    return (false);
  }
  
  mmc->CmdRead (m, n);
  return true;
}
void MsClass::MSC_RequestSense (void) {
  uint32_t n;
  //print("Sense Key [0x%02X] Asc [0x%02X]\n", SK(SenseData.data), ASC(SenseData.data));
  if (!DataInFormat()) return;
  for (n=0; n<18; n++) BulkBuf[n] = 0;                      // memset
  BulkBuf[0] = SenseData.valid | 0x70;                     /* Valid, current error     */
  BulkBuf[2] = SK(SenseData.data);
  BulkBuf[3] = (uint8_t) ((SenseData.info >> 24) & 0xFF);  /* Sense information MSB */
  BulkBuf[4] = (uint8_t) ((SenseData.info >> 16) & 0xFF);  /* Sense information     */
  BulkBuf[5] = (uint8_t) ((SenseData.info >>  8) & 0xFF);  /* Sense information     */
  BulkBuf[6] = (uint8_t)  (SenseData.info        & 0xFF);  /* Sense information LSB */
  BulkBuf[7] = 18 - 8;                                     /* Additional sense length  */
  BulkBuf[12] =  ASC(SenseData.data);
  BulkBuf[13] = ASCQ(SenseData.data);
  
  SetSenseData (SS_NO_SENSE, 0, 0);                     // Clear sense data
  BulkLen = 18;
  DataInTransfer();

}
void MsClass::MSC_TestUnitReady (void) {
  if (CBW.dDataLength != 0) {
    if ((CBW.bmFlags & 0x80) != 0) {
      MSC_SetStallEP(EndpointIn);
    } else {
      MSC_SetStallEP(EndpointOut);
    }
  }
  // Na začátku fail - možná je to blbost, ale jiná zařízení to tak dělají
  if (SenseData.data == SS_RESET_OCCURRED)
    CSW.bStatus = CSW_CMD_FAILED;
  else
    CSW.bStatus = CSW_CMD_PASSED;
  MSC_SetCSW();
}
bool MsClass::MSC_WriteSetup (void) {
  uint32_t m, n=0;
  /* Logical Block Address of First Block */
  m = (CBW.CB[2] << 24) |
      (CBW.CB[3] << 16) |
      (CBW.CB[4] <<  8) |
      (CBW.CB[5] <<  0);

  /* Number of Blocks to transfer */
  switch (CBW.CB[0]) {
    case SCSI_WRITE10:
      n = (CBW.CB[7] <<  8) |
          (CBW.CB[8] <<  0);
      break;

    case SCSI_WRITE12:
      n = (CBW.CB[6] << 24) |
          (CBW.CB[7] << 16) |
          (CBW.CB[8] <<  8) |
          (CBW.CB[9] <<  0);
      break;
  }

  if (CBW.dDataLength == 0) {              /* host requests no data */
    //error("HOST REQ NO DATA\n);
    CSW.bStatus = CSW_CMD_FAILED;
    MSC_SetCSW();
    return (false);
  }

  if (CBW.dDataLength != n * MSC_BlockSize) {
    if ((CBW.bmFlags & 0x80) != 0) {       /* stall appropriate EP */ 
      MSC_SetStallEP(EndpointIn);
    } else {
      MSC_SetStallEP(EndpointOut);
    }
    //error("BAD REQ LEN %d\n", n);
    CSW.bStatus = CSW_CMD_FAILED;
    MSC_SetCSW();

    return (false);
  }
  
  mmc->CmdWrite (m, n);
  return true;
}

bool MsClass::Reset (void) {
  CSW.dSignature = 0;                      // invalid signature

  BulkStage = MSC_BS_CBW;

  return true;
}
void MsClass::MSC_SetStallEP (UsbEndpointDir dir) {
  uint8_t epadr = (dir == EndpointIn) ? MSC_TXD_EP : MSC_RXD_EP;
  parent->ep_setstall (epadr, true);
}
