#include <string.h>
#include <stdint.h>
#include "system.h"
#include "msc_class.h"
#include "storagespinor.h"
#include "ff.h"

static volatile  unsigned g_ticks     = 0u;
static constexpr unsigned usb_timeout = 1000u;
volatile unsigned g_usb_address_ready = 0u;

static GpioClass LedGreen (GpioPortA, 10);
static GpioClass LedRed   (GpioPortA,  8);

static GpioClass NoFile   (GpioPortA, 1, GPIO_Mode_IN);
static GpioClass NoUSB    (GpioPortA, 3, GPIO_Mode_IN);
static GpioClass NoWrite  (GpioPortA, 2, GPIO_Mode_IN);

extern "C" void BootFromRam ();
extern "C" void SysTick_Handler () {
  g_ticks += 1;
}
static bool WaitUsbReady () {
  if (!NoUSB.get() or !NoFile.get()) return false;
  g_ticks = 0u;
  for (;;) {
    if (g_usb_address_ready)         return true;
    if (g_ticks > usb_timeout)       return false;
    asm volatile("wfi");
  }
}
static void StopPeripherals () {
  RCC.APB1RSTR1.B.SPI3RST  = 1u;
  RCC.AHB1RSTR. B.DMA2RST  = 1u;
  NVIC_DisableIRQ (USB_FS_IRQn);
  RCC.APB1RSTR1.B.USBFSRST = 1u;
  RCC.AHB2RSTR. B.GPIOARST = 1u;
  RCC.AHB2RSTR. B.GPIOBRST = 1u;
  
  RCC.APB1RSTR1.B.SPI3RST  = 0u;
  RCC.AHB1RSTR. B.DMA2RST  = 0u;
  RCC.APB1RSTR1.B.USBFSRST = 0u;
  RCC.AHB2RSTR. B.GPIOARST = 0u;
  RCC.AHB2RSTR. B.GPIOBRST = 0u;
  
  RCC.APB1ENR1.B.SPI3EN  = 0u;
  RCC.AHB1ENR .B.DMA2EN  = 0u;
  RCC.APB1ENR1.B.USBF    = 0u;
  RCC.AHB2ENR. B.GPIOAEN = 0u;
  RCC.AHB2ENR. B.GPIOBEN = 0u;
}
static constexpr unsigned RAM_BEGIN = 0x20000000;
static bool MainBootProcess () {
  bool result = false;
  // na začátku RAM musí být nějaká "rozumná" hodnota SP
  const uint32_t * stack = reinterpret_cast<const uint32_t*>(RAM_BEGIN);
  const uint32_t   value = * stack;
  if ((value <= RAM_BEGIN) or (value > (RAM_BEGIN + 0x28000))) return result;
  StopPeripherals();
  BootFromRam    ();
  return true; // no return;
}
static bool BootFromFile (const char * name, const uint32_t len) {
  bool result = false;
  FIL handle;
  if (f_open(&handle, name, FA_READ) != FR_OK)                return result;
  uint8_t * data = reinterpret_cast<uint8_t*>(RAM_BEGIN);
  unsigned readen = 0;
  if (f_read (&handle, data, len, & readen) != FR_OK)         return result;
  f_close (&handle);
  result = MainBootProcess();
  return result;  // ok no return
}
static  FATFS fatfs;
static bool StartBootProcess () {
  if (!NoFile.get()) {
    return MainBootProcess();  // ok no return
  }
  +LedGreen;
  const int pathlen = 64;
  char path [pathlen];
  FRESULT res;
  bool    result = false;
  
  f_mount (& fatfs, "", 0);
  
  DIR dir;
  const char * root = "FIRMWARE";
  const int rl = strlen (root);
  memcpy (path, root, rl);
  int i = rl;
  path [i] = '\0';
  res = f_opendir (&dir, path);
  if (res != FR_OK) return MainBootProcess();  // při chybě externí flash může skočit do programu, který je nahrán do RAM pomocí SVD
  FILINFO fno;
  for (;;) {
    res = f_readdir (&dir, &fno);
    if (res != FR_OK || fno.fname[0] == 0) break;
    if (!(fno.fattrib & AM_DIR)) {
      // 1. regulerni soubor v adresari FIRMWARE
      path [i++] = '/';
      const int ll = strlen (fno.fname);
      memcpy (path + i, fno.fname, ll);
      i += ll;
      path [i] = '\0';
      result = BootFromFile (path, fno.fsize);
      break;
    }
  }
  f_closedir(&dir);
  return result;
}
static void wait_ms (const unsigned ms = 5u) {
  g_ticks = 0u;
  while (g_ticks < ms);
}

static usbd_device   udev;
static MsClass       umsc (udev);
static StorageSpiNor disc;

int main (void) {
  EnableDebugOnSleep();
  NoFile .setPuPd (GPIO_PuPd_UP);
  NoUSB  .setPuPd (GPIO_PuPd_UP);
  NoWrite.setPuPd (GPIO_PuPd_UP);
  SysTick_Config (SystemCoreClock / 1000);
  wait_ms ();
  udev.attach(umsc);
  umsc.attach(disc, ! NoWrite.get());
  umsc.init();
  if (!WaitUsbReady()) {
    // disable SysTick + interrupt
    SysTick->CTRL &= ~ (SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk);
    if (!StartBootProcess()) {
      -LedGreen;
      +LedRed;
    }
  }
  while (1) {
    asm volatile("wfi");
  }
  return 0;
}
