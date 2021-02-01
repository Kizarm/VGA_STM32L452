#include "STM32L4x2.h"
#include "gpio.h"
#include "vhsync.h"

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

/* SVGA Signal 800 x 600 @ 56 Hz timing
 * Screen refresh rate  56 Hz
 * Vertical refresh     35.15625 kHz
 * Pixel freq.          36.0 MHz
 * 
 *              Horizontal      Vertical
 * Visible area 800   pixels    600 lines
 * Front porch  24              1
 * Sync pulse   72              2   LOW OR HIGH
 * Back porch   128             22
 * Whole        1024            625
 * 
 * Pro PMD85 se sníží frekvence SPI na 18 MHZ, řádky se pak zdvojí.
 * Takže zobrazení 288x256 přejde na 576x512, což se vejde v pohodě na obrazovku 800x600.
 * */
typedef void (*pVHandler) (void);
// nemuí se nutně použít
#define __attribute__(...)
/* bohužel nejde udělat z reinterpret_cast constexpr, takže to v paměti někde bude (v ARM asi opravdu nejde jinak, zůstane i ukazatel) */
static TIM_Type  & VHTIM __attribute__((section (".fast.VHTIM"))) = * reinterpret_cast<TIM_Type  * const> (0x40000000u);  // TIM2
static DMA_Type  & VHDMA __attribute__((section (".fast.VHDMA"))) = * reinterpret_cast<DMA_Type  * const> (0x40020000u);  // DMA1
static SPI_Type  & VHSPI __attribute__((section (".fast.VHSPI"))) = * reinterpret_cast<SPI_Type  * const> (0x40003800u);  // SPI2
static GPIO_Type & PORTB __attribute__((section (".fast.PORTB"))) = * reinterpret_cast<GPIO_Type * const> (0x48000400u);  // GPIOB

static GpioClass vsync (GpioPortB, 14);
static unsigned uLines = 0u;

static unsigned char * videoRAM = nullptr;
static constexpr unsigned COL_BYTES = 48u;
static constexpr unsigned COL_OFSET = 64u;
static unsigned char dummy [COL_BYTES];

static inline void GenerateVideo (const bool in) {
  // zde je DMA o SPI zakázáno
  if (in) VHDMA.CMAR5 = reinterpret_cast<uint32_t> (videoRAM + COL_OFSET * (uLines >> 1));
  else    VHDMA.CMAR5 = reinterpret_cast<uint32_t> (dummy);
  
  VHDMA.CNDTR5    = COL_BYTES;
  VHSPI.CR1.B.SPE = SET;
  VHDMA.CCR5.B.EN = SET;
  
  uLines += 1u;
}

static void DoNothing  () __attribute__((section (".fast.DoNothing")));
static void EndWhole   () __attribute__((section (".fast.EndWhole")));
static void BeginVSync () __attribute__((section (".fast.BeginVSync")));
static void BeginVSync () __attribute__((section (".fast.BeginVSync")));
static void EndVSync   () __attribute__((section (".fast.EndVSync")));

extern "C" void DMA1_CH5_IRQHandler () __attribute__((section (".fast.DMA1_CH5_IRQHandler")));
extern "C" void TIM2_IRQHandler     () __attribute__((section (".fast.TIM2_IRQHandler")));

static void DoNothing () {
  uLines += 1u;
}
static void EndWhole  () {
  uLines = 0;
}
static void BeginVSync () {
  PORTB.BSRRL = (1u << 14);
  uLines += 1u;
}
static void EndVSync () {
  PORTB.BSRRH = (1u << 14);
  uLines += 1u;
}
static const pVHandler vsync_tab [] __attribute__((section (".fast.vsync_tab"))) = {
  BeginVSync, DoNothing, EndVSync,
  DoNothing,  DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, 
  DoNothing,  DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing,
  DoNothing,  EndWhole
};
/* Pro PMD85 bylo nutno přidat ukončení DMA, které vypne SPI.
 * Tím se uvede MOSI pin do stavu Z a data se nezobrazují.
 * Tak jde použít DMA přímo z videoRAM - 6 bitů ma byte, nejvyšší 2 bity jsou ignorovány,
 * což v černobílém módu v podstatě nevadí a problém to hodně zjednoduší.
 * */
void DMA1_CH5_IRQHandler () {
  DMA_ISR_s status (VHDMA.ISR);
  VHDMA.IFCR.R = status.R;    // clear STATUS
  VHDMA.CCR5.B.EN = RESET;    // disable DMA
  // Tohle není úplně čisté, ale ořeže to okolní artefakty
  VHSPI.DR = 0u;  // tahle nula na konci je podstatná
  uint32_t spi_mask = (1u << 7) | (1u << 11);
  while (VHSPI.SR.R & spi_mask);
  VHSPI.CR1.B.SPE = RESET;    // disable SPI
  
}
void TIM2_IRQHandler () {
  VHTIM.SR.B.UIF = 0u;
  const unsigned pmdUlines = 512u, maxULines = 600u;
  if        (uLines < pmdUlines) {
    GenerateVideo (true);
  } else if (uLines < maxULines) {
    GenerateVideo (false);
  } else {    // prevent too many else if or switch
    const pVHandler f = vsync_tab [uLines - maxULines];
    f ();
  }
}
// TX
static inline void Dma1Ch5Init (const uint8_t * ptr) {
  // Configure the peripheral data register address
  VHDMA.CPAR5  = reinterpret_cast<uint32_t> (& (VHSPI.DR));
  // Configure the memory address
  VHDMA.CMAR5  = reinterpret_cast<uint32_t> (ptr);
  // Configure the number of DMA tranfer to be performs on DMA channel 5
  VHDMA.CNDTR5 = COL_BYTES;
  // Configure increment, size, interrupts and circular mode
  VHDMA.CCR5.modify([](DMA_CCR5_s & ccr) -> auto {
    ccr.B.MINC  = SET;
    ccr.B.MSIZE = XFER_BYTE;
    ccr.B.PSIZE = XFER_BYTE;
    ccr.B.DIR   = SET;
    ccr.B.TCIE  = SET;
    ccr.B.CIRC  = RESET;
    ccr.B.EN    = RESET;
    return ccr.R;
  });
  NVIC_EnableIRQ (DMA1_CH5_IRQn);
}
static inline void TimerInit () {
  GpioClass out (GpioPortA, 0, GPIO_Mode_AF);
  out.setAF (1);
  out.setSpeed(GPIO_Speed_HS);
  out.setPuPd(GPIO_PuPd_DOWN);
  RCC.APB1ENR1.B.TIM2EN = 1u;
  VHTIM.PSC      = 1u;       // 36 MHz
  VHTIM.ARR.R    = 1023u;    // total, 1022 je zrejme spravne
  VHTIM.EGR.B.UG = 1u;
  VHTIM.CCMR1_Output.modify([] (TIM_CCMR1_Output_s & r) -> auto {
    r.B.OC1PE = 1u;
    r.B.OC2PE = 1u;
    r.B.OC1M  = 5u;  // Combined PWM mode 2 (AND)
    r.B.OC2M  = 4u;  // Combined PWM mode 1 (OR)
    r.B.OC1M3 = 1u;
    r.B.OC2M3 = 1u;
    return r.R;
  });
  VHTIM.CCER.modify([](TIM_CCER_s & r) -> auto {
    r.B.CC1P = 0u;   // polarita
    r.B.CC1E = 1u;   // povoleni
    return r.R;    
  });
  constexpr  unsigned  H_OFFSET = 760u;
  VHTIM.CCR1.R = H_OFFSET;
  VHTIM.CCR2.R = H_OFFSET + 74u;
  
  VHTIM.DIER.B.UIE = 1u;
  VHTIM.CR1.B.ARPE = 1u;
  VHTIM.BDTR.B.MOE = 1u;
  NVIC_EnableIRQ (TIM2_IRQn);
  
  VHTIM.CR1.B.CEN  = 1u;
}
static inline void SpiInit () {
  // SPI 2
  RCC.APB1ENR1.B.SPI2EN = SET;
  RCC.AHB1ENR .B.DMA1EN = SET;
  
  GpioClass mosi (GpioPortB, 15, GPIO_Mode_AF);
  mosi.setPuPd   (GPIO_PuPd_DOWN);
  mosi.setSpeed  (GPIO_Speed_HS);
  mosi.setAF  (5);

  VHSPI.CR1.modify([](SPI_CR1_s & cr1) -> auto {
    cr1.B.CPHA     = SET;
    cr1.B.CPOL     = SET;
    cr1.B.BIDIMODE = RESET;
    cr1.B.BIDIOE   = RESET;
    cr1.B.RXONLY   = RESET;
    cr1.B.MSTR     = SET;
    cr1.B.BR       = FPCLK_DIV_4;
    cr1.B.LSBFIRST = SET;           // LSB first
    cr1.B.SSM      = RESET;         // zde hardware management
    cr1.B.SSI      = RESET;
    return cr1.R;
  });
  
  VHSPI.CR2.modify([](SPI_CR2_s & cr2) -> auto {
    cr2.B.SSOE     = SET;
    cr2.B.DS       = 5u;           // 6-bit
    cr2.B.TXDMAEN  = SET;
    cr2.B.RXDMAEN  = RESET;
    return cr2.R;
  });

  VHDMA.CSELR.modify([](DMA_CSELR_s & r) -> auto {
    r.B.C5S = 1u;   // VHSPI Tx
    return r.R;
  });
  Dma1Ch5Init (videoRAM);
  VHSPI.CR1.B.SPE = SET;
}

void VHSync::Init (uint8_t * ptr) {
  videoRAM = ptr + 0xC000u;
  vsync.setSpeed (GPIO_Speed_HS);
  SpiInit   ();
  TimerInit ();
}
