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
 * 
 * */
volatile unsigned FramesCount = 0u;

static GpioClass *  pVsync = nullptr;
static unsigned uLines = 0u;

static uint8_t videoRAM [100 * 600] __attribute__((aligned(4)));

static inline void GenerateVideo () {
  DMA1.CCR5.B.EN = RESET;
  DMA1.CMAR5     = reinterpret_cast<uint32_t> (&videoRAM[100 * uLines]);
  DMA1.CNDTR5    = 100;  
  DMA1.CCR5.B.EN = SET;
  
  uLines += 1u;
}
static void DoNothing () {
  uLines += 1u;
}
static void EndWhole  () {
  uLines = 0;
}
static void BeginVSync () {
  +(*pVsync);
  uLines += 1u;
}
static void EndVSync () {
  -(*pVsync);
  FramesCount += 1u;
  uLines += 1u;
}
typedef void (*pVHandler) (void);
static const pVHandler vsync_tab [] = {
  BeginVSync, DoNothing, EndVSync,
  DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, 
  DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing, DoNothing,
  DoNothing, EndWhole
};

extern "C" void TIM2_IRQHandler () {
  TIM2.SR.B.UIF = 0u;
  const unsigned maxULines = 600u;
  if (uLines < maxULines) {
    GenerateVideo ();
  } else {    // prevent too many else if or switch
    const pVHandler f = vsync_tab [uLines - maxULines];
    f ();
  }
}
// TX
static inline void Dma1Ch5Init (const uint8_t * ptr) {
  // Configure the peripheral data register address
  DMA1.CPAR5  = reinterpret_cast<uint32_t> (& (SPI2.DR));
  // Configure the memory address
  DMA1.CMAR5  = reinterpret_cast<uint32_t> (ptr);
  // Configure the number of DMA tranfer to be performs on DMA channel 5
  DMA1.CNDTR5 = 100;
  // Configure increment, size, interrupts and circular mode
  DMA1.CCR5.modify([](DMA_CCR5_s & ccr) -> auto {
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
static inline void TimerInit () {
  GpioClass out (GpioPortA, 0, GPIO_Mode_AF);
  out.setAF (1);
  out.setSpeed(GPIO_Speed_HS);
  RCC.APB1ENR1.B.TIM2EN = 1u;
  TIM2.PSC      = 1u;       // 36 MHz
  TIM2.ARR.R    = 1022u;    // total, 1022 je zrejme spravne
  TIM2.EGR.B.UG = 1u;
  TIM2.CCMR1_Output.modify([] (TIM_CCMR1_Output_s & r) -> auto {
    r.B.OC1PE = 1u;
    r.B.OC2PE = 1u;
    r.B.OC1M  = 5u;  // Combined PWM mode 2 (AND)
    r.B.OC2M  = 4u;  // Combined PWM mode 1 (OR)
    r.B.OC1M3 = 1u;
    r.B.OC2M3 = 1u;
    return r.R;
  });
  TIM2.CCER.modify([](TIM_CCER_s & r) -> auto {
    r.B.CC1P = 0u;   // polarita
    r.B.CC1E = 1u;   // povoleni
    return r.R;    
  });
  TIM2.CCR1.R = 800 + 60;
  TIM2.CCR2.R = 800 + 60 + 74;
  
  TIM2.DIER.B.UIE = 1u;
  TIM2.CR1.B.ARPE = 1u;
  TIM2.BDTR.B.MOE = 1u;
  NVIC_EnableIRQ (TIM2_IRQn);
  
  TIM2.CR1.B.CEN  = 1u;
}
static inline void SpiInit () {
  // SPI 2
  RCC.APB1ENR1.B.SPI2EN = SET;
  RCC.AHB1ENR .B.DMA1EN = SET;
  
  //GpioClass sclk (GpioPortB, 13, GPIO_Mode_AF);
  GpioClass mosi (GpioPortB, 15, GPIO_Mode_AF);
  //sclk.setPuPd   (GPIO_PuPd_UP);
  mosi.setPuPd   (GPIO_PuPd_DOWN);
  //sclk.setSpeed  (GPIO_Speed_HS);
  mosi.setSpeed  (GPIO_Speed_HS);
  //sclk.setAF  (5);
  mosi.setAF  (5);

  SPI2.CR1.modify([](SPI_CR1_s & cr1) -> auto {
    cr1.B.CPHA     = SET;
    cr1.B.CPOL     = SET;
    cr1.B.BIDIMODE = RESET;
    cr1.B.RXONLY   = RESET;
    cr1.B.MSTR     = SET;
    cr1.B.BR       = FPCLK_DIV_2;
    cr1.B.LSBFIRST = SET;           // LSB first
    cr1.B.SSM      = SET;           // RM Figure 388, note 1.
    cr1.B.SSI      = SET;
    return cr1.R;
  });
  
  SPI2.CR2.modify([](SPI_CR2_s & cr2) -> auto {
    cr2.B.DS       = 7u;           // 16-bit
    cr2.B.TXDMAEN  = SET;
    cr2.B.RXDMAEN  = RESET;
    return cr2.R;
  });

  DMA1.CSELR.modify([](DMA_CSELR_s & r) -> auto {
    r.B.C5S = 1u;   // SPI2 Tx
    return r.R;
  });
  Dma1Ch5Init (videoRAM);
  SPI2.CR1.B.SPE = SET;
}

VHSync::VHSync() : vsync (GpioPortB, 14) {
  vsync.setSpeed (GPIO_Speed_HS);
  pVsync    = & vsync;
  pVideoRAM = videoRAM;
  SpiInit   ();
  TimerInit ();
}
/*
void delay (const unsigned time) {
  volatile unsigned n = time;
  while (n--);
}
void VHSync::setVideo() {
  delay (1000000);    // ? pockej na synchronizaci
  const GLYPH_DESC * const * glyph = font_AtariST8x16SystemFont.font_data;
  for (unsigned xy=0; xy<60000; xy++) {
    const unsigned x  = xy % 100;
    const unsigned y  = xy / 100;
    const unsigned uy = y >> 4;
    const unsigned ui = y & 0x0F;
    const uint8_t   c = (x + 0x20) & 0x7F;
    const uint8_t * g = glyph [c]->rows;
    if (uy < 37) {
      if (uy & 7) videoRAM [xy] =  g [ui];
      else        videoRAM [xy] = ~g [ui];
    } else        videoRAM [xy] = 0;
  }
}
*/