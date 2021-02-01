#include <string.h>
#include "STM32L4x2.h"
#include "gpio.h"
#include "spiclass.h"

enum BITSETS {
  RESET = 0,
  SET   = 1,
};
enum TRANSFER_SIZES {
  XFER_BYTE = 0,
  XFER_HALF,
  XFER_WORD,
};
enum BaudRateControl {
  FPCLK_DIV_2 = 0,
  FPCLK_DIV_4,
  FPCLK_DIV_8,
  FPCLK_DIV_16,
  FPCLK_DIV_32,
  FPCLK_DIV_64,
  FPCLK_DIV_128,
  FPCLK_DIV_256,
};

// RX
static inline void Dma2Ch1Init (const uint8_t * ptr) {
  // Configure the peripheral data register address
  DMA2.CPAR1  = reinterpret_cast<uint32_t> (& (SPI3.DR));
  // Configure the memory address
  DMA2.CMAR1  = reinterpret_cast<uint32_t> (ptr);
  // Configure the number of DMA tranfer to be performs on DMA channel 4
  DMA2.CNDTR1 = SpiBufLen;
  // Configure increment, size, interrupts and circular mode
  DMA2.CCR1.modify([](DMA_CCR1_s & ccr) -> auto {
    ccr.B.MINC  = SET;
    ccr.B.MSIZE = XFER_BYTE;
    ccr.B.PSIZE = XFER_BYTE;
    ccr.B.DIR   = RESET;
    ccr.B.TCIE  = RESET;          // Po dokončení ne přerušit.
    ccr.B.CIRC  = RESET;
    ccr.B.EN    = RESET;
    return ccr.R;
  });
}
// TX
static inline void Dma2Ch2Init (const uint8_t * ptr) {
  // Configure the peripheral data register address
  DMA2.CPAR2  = reinterpret_cast<uint32_t> (& (SPI3.DR));
  // Configure the memory address
  DMA2.CMAR2  = reinterpret_cast<uint32_t> (ptr);
  // Configure the number of DMA tranfer to be performs on DMA channel 5
  DMA2.CNDTR2 = SpiBufLen;
  // Configure increment, size, interrupts and circular mode
  DMA2.CCR2.modify([](DMA_CCR2_s & ccr) -> auto {
    ccr.B.MINC  = SET;
    ccr.B.MSIZE = XFER_BYTE;
    ccr.B.PSIZE = XFER_BYTE;
    ccr.B.DIR   = SET;
    ccr.B.TCIE  = RESET;
    ccr.B.CIRC  = RESET;
    ccr.B.EN    = RESET;
    return ccr.R;
  });
}
/* ********************************************************************************/
void SpiClass::Init () {
  pending  = false;
  RCC.APB1ENR1.B.SPI3EN = SET;
  RCC.AHB1ENR .B.DMA2EN = SET;
  
  GpioClass sck  (GpioPortB, 3, GPIO_Mode_AF);
  GpioClass miso (GpioPortB, 4, GPIO_Mode_AF);
  GpioClass mosi (GpioPortB, 5, GPIO_Mode_AF);
  sck. setPuPd   (GPIO_PuPd_UP);
  sck. setSpeed  (GPIO_Speed_HS);
  miso.setSpeed  (GPIO_Speed_HS);
  mosi.setSpeed  (GPIO_Speed_HS);
  sck. setAF  (6);
  miso.setAF  (6);
  mosi.setAF  (6);

  SPI3.CR1.modify([](SPI_CR1_s & cr1) -> auto {
    cr1.B.CPHA     = SET;
    cr1.B.CPOL     = SET;
    cr1.B.BIDIMODE = RESET;
    cr1.B.RXONLY   = RESET;
    cr1.B.MSTR     = SET;
    cr1.B.BR       = FPCLK_DIV_2;
    cr1.B.LSBFIRST = RESET;         // MSB first
    cr1.B.SSM      = SET;           // RM Figure 388, note 1.
    cr1.B.SSI      = SET;
    return cr1.R;
  });
  
  SPI3.CR2.modify([](SPI_CR2_s & cr2) -> auto {
    /* LDMA se nebudeme zabývat, přístup do DR je 8.bitový (DMA), data rovněž.
     * */
    cr2.B.DS       = 7u;            // 8-bit
    cr2.B.TXDMAEN  = SET;
    cr2.B.RXDMAEN  = SET;
    // Následující asi není důležité ale v řadě F051 to chodilo, tak to necháme, je to podobné.
    cr2.B.SSOE     = SET;           // NSS output enable
    cr2.B.NSSP     = RESET;         // no pulse, continuous op.
    cr2.B.FRXTH    = SET;
    return cr2.R;
  });

  DMA2.CSELR.modify([](DMA_CSELR_s & r) -> auto {
    r.B.C1S = 3u;   // SPI3 Rx
    r.B.C2S = 3u;   // SPI3 Tx
    return r.R;
  });
  Dma2Ch1Init (rxb);
  Dma2Ch2Init (txb);
}
void SpiClass::Fini () {
  GpioClass sck  (GpioPortB, 3, GPIO_Mode_AN);
  GpioClass miso (GpioPortB, 4, GPIO_Mode_AN);
  GpioClass mosi (GpioPortB, 5, GPIO_Mode_AN);
  sck.setPuPd    (GPIO_PuPd_NOPULL);
  
  NVIC_DisableIRQ  (DMA2_CH1_IRQn);
  RCC.APB1ENR1 .B.SPI3EN  = RESET;
  RCC.APB1RSTR1.B.SPI3RST = SET;
  RCC.APB1RSTR1.B.SPI3RST = RESET;
}
uint32_t SpiClass::Transaction (uint8_t * data, const uint32_t len, const GpioClass & chip_select) {
  if (pending) return 0;
  if (len > SpiBufLen) lastTransactionLen = SpiBufLen;
  else                 lastTransactionLen = len;
  memcpy (txb, data, lastTransactionLen);
  -chip_select;
  startTransaction();
  while (pending) {
    waitTransactionEnd();
  }
  +chip_select;
  memcpy (data, rxb, lastTransactionLen);
  return lastTransactionLen;
}
void SpiClass::startTransaction (void) {
  DMA2.CNDTR2 = lastTransactionLen;
  DMA2.CNDTR1 = lastTransactionLen;
  DMA2.CCR2.B.EN = SET;
  DMA2.CCR1.B.EN = SET;
  pending = true;
  SPI3.CR1.B.SPE = SET;        // global enable
}
void SpiClass::waitTransactionEnd() {
  DMA_ISR_s status (DMA2.ISR);
  if (status.B.TCIF1 && status.B.TCIF2) {
    DMA2.CCR1.B.EN = RESET;    // disable DMAs
    DMA2.CCR2.B.EN = RESET;
    DMA2.IFCR.R = status.R;
    SPI3.CR1.B.SPE = RESET;    // global disable
    pending = false;
  }
}
