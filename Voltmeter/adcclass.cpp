#include "STM32L4x2.h"
#include "adcclass.h"
#include "gpio.h"

/* *********************************************************************************************/
// Není v generované hlavičce !!!
struct COM_ADC_CCR {
  union {
    __RWB uint32_t R;
    struct {
      uint32_t       UNUSED1 : 16;
      __RWB uint32_t CKMODE  : 2;
      __RWB uint32_t PRESC   : 4;
      __RWB uint32_t VREFEN  : 1;
      __RWB uint32_t CH17SEL : 1;
      __RWB uint32_t CH18SEL : 1;
      uint32_t       UNUSED2 : 7;
    } B;
  };
  void modify  (uint32_t (*f) (COM_ADC_CCR & r)) volatile {
    COM_ADC_CCR t; t.R = R;
    R = f (t);
  }
};
struct ADC_COMMON_S {
  __RW uint32_t    CSR;
  uint32_t unused;
  __RW COM_ADC_CCR CCR;
};
enum BITSETS {
  RESET = 0,
  SET   = 1,
};
enum TRANSFER_SIZES {
  XFER_BYTE = 0,
  XFER_HALF,
  XFER_WORD,
};
/* *********************************************************************************************/
static ADC_COMMON_S & ADCCOM  = * reinterpret_cast<ADC_COMMON_S * const> (0x50040300u);
static AdcClass * AdcClassInstance = 0;

static inline void Dma1Ch1Init (const uint16_t * ptr) {
  DMA1.CSELR.B.C1S = 0;       // DMA channel select
  // Configure the peripheral data register address
  DMA1.CPAR1  = reinterpret_cast<uint32_t> (& (ADC.DR));
  // Configure the memory address
  DMA1.CMAR1  = reinterpret_cast<uint32_t> (ptr);
  // Configure increment, size, interrupts and circular mode
  DMA1.CCR1.modify([](DMA_CCR1_s & ccr) -> auto {
    ccr.B.MINC  = SET;
    ccr.B.MSIZE = XFER_HALF;
    ccr.B.PSIZE = XFER_HALF;
    ccr.B.DIR   = RESET;        // cte z periferie
    ccr.B.TCIE  = SET;          // Po dokončení přerušit.
    ccr.B.CIRC  = RESET;
    return ccr.R;
  });
}
static inline void Timer6Init () {
  RCC.APB1ENR1.B.TIM6EN = SET;
  TIM6.PSC        = 71u;      // 1 MHz
  TIM6.ARR.R      = 9999u;    // total, 10ms
  TIM6.CR1.B.ARPE = SET;
  TIM6.EGR.B.UG   = SET;
  TIM6.CR2.B.MMS  = 2u;       // TRGO event
}
static inline void EnableAdc () {
  RCC.AHB2ENR.B.ADCEN  = SET;
  RCC.AHB1ENR.B.DMA1EN = SET;
  ADCCOM.CCR.modify([](COM_ADC_CCR & r) -> auto {
    r.B.CKMODE = 2u;          // HCLK / 2 (není jisté, že HCLK je v pořádku)
    r.B.PRESC  = 11u;         // vydelit 256
    r.B.VREFEN = SET;         // povolit interní referenci (pro výpočet napětí)
    return r.R;
  });
  // exit from deep power down
  ADC.CR.modify([] (ADC_CR_s & r) -> auto {
    r.B.DEEPPWD  = RESET;
    r.B.ADVREGEN = SET;
    return r.R;
  });
  // wait ADCVREG_STUP 20us
  volatile uint32_t dly = 2000;
  while (--dly);
}
static inline void AdcCalibrate () {
  // Ensure that ADEN = 0
  if (ADC.CR.B.ADEN != RESET) {
    ADC.CR.B.ADEN = RESET;   // Clear ADEN
  }
  // Launch the calibration by setting ADCAL
  ADC.CR.B.ADCAL = SET;
  // Wait until ADCAL=0
  while (ADC.CR.B.ADCAL != RESET);
}
static inline void AdcInit () {
  // Nastavíme vstupní piny - zatím jen přímo
  GpioClass in1 (GpioPortA, 2, GPIO_Mode_AN);  // CH 10
  GpioClass in2 (GpioPortA, 3, GPIO_Mode_AN);  // CH 9
  // Kanály pro konverzi
  ADC.SQR1.modify([](ADC_SQR1_s & r) -> auto {
    r.B.SQ1 = 7u;           // CH7, PA2
    r.B.SQ2 = 8u;           // CH8, PA3
    r.B.SQ3 = 0u;           // CH0 - interní reference
    // ...
    r.B.L3 = ADC_MAXCHANNELS;
    return r.R;
  });
  // doby vzorkování
  ADC.SMPR1.modify([](ADC_SMPR1_s & r) -> auto {
    r.B.SMP1 = 6u;
    r.B.SMP2 = 6u;
    r.B.SMP3 = 6u;
    return r.R;
  });
  ADC.CFGR.modify ([](ADC_CFGR_s & r) -> auto {
    r.B.DMAEN  = SET; // spolupráce s DMA
    r.B.EXTEN  = 1u;
    r.B.EXTSEL = 13u;
    return r.R;
  });
}
/* *********************************************************************************************/
void AdcClass::Init () {
  AdcClassInstance = this;
  Timer6Init  ();
  EnableAdc   ();
  AdcCalibrate();
  AdcInit     ();
  NVIC_EnableIRQ  (DMA1_CH1_IRQn);
  Dma1Ch1Init (buffer);
  
  DMA1.CNDTR1     = ADC_MAXCHANNELS;
  DMA1.CCR1.B.EN  = SET;
  
  ADC.CR.B.ADEN    = SET;
  ADC.ISR.B.ADRDY  = SET;
  while (ADC.ISR.B.ADRDY == 0);
  TIM6.CR1.B.CEN   = SET;
  ADC.CR.B.ADSTART = SET;
}
/*
// přepočet hodnoty na napětí v mV
uint16_t AdcClass::Voltage(ADC_CHANNELS ch) {
  const uint32_t divider = buffer [VPROC_VSENSE]; // hodnota napětí interní reference
  if (divider == 0) return 0xFFFF;  // předejdeme dělení 0
  const uint16_t VREFINT = * reinterpret_cast<uint16_t* const>(0x1FFF75AAU);
  uint32_t result;
  if (ch == VPROC_VSENSE) {
    result = ((uint32_t) VREFINT * (uint32_t) 0x0FFF)      << 8;
  } else {
    result = ((uint32_t) VREFINT * (uint32_t) buffer [ch]) << 8;
  }
  result  /= divider;
  result  *= 3000;
  result >>= 20;                    // 12 + 8, podle RM by se správně mělo dělit 4095, ale zase tak přesné to není.
  if (ch == VBAT_VSENSE) {          // dělící poměr 2/3 R11, R12
    result  *= 3;                   // * 1.5
    result >>= 1;
  }
  return (uint16_t) result;
}
*/
/* *********************************************************************************************/

void AdcClass::drq() {
  DMA1.CCR1.B.EN = RESET;    // disable DMA
  DMA_ISR_s  status(DMA1.ISR);
  DMA1.IFCR.R = status.R;
  ring.Write (buffer [V2_VSENSE]);
  DMA1.CNDTR1      = ADC_MAXCHANNELS;
  DMA1.CCR1.B.EN   = SET;
  ADC.CR.B.ADSTART = SET;
}
extern "C" void DMA1_CH1_IRQHandler (void) {
  //asm volatile ("bkpt 0");
  if (AdcClassInstance) AdcClassInstance->drq();
}
