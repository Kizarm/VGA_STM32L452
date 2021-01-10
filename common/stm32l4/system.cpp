#include "common.h"
#include "STM32L4x2.h"
#include "core_cm4.h"
#include "system.h"
/** @file
  * @brief Základní nastavení systému.
  * 
 * */

#if !defined  (HSE_VALUE)
#define HSE_VALUE    8000000U  /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (MSI_VALUE)
#define MSI_VALUE    4000000U  /*!< Value of the Internal oscillator in Hz */
#endif /* MSI_VALUE */

#if !defined  (HSI_VALUE)
#define HSI_VALUE    16000000U /*!< Value of the Internal oscillator in Hz */
#endif /* HSI_VALUE */

/// Použito v locker.h
//volatile int gblMutex = 0;
/// Systémové hodiny
uint32_t SystemCoreClock = 4000000U;

  const uint8_t  AHBPrescTable[16] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U};
//const uint8_t  APBPrescTable[8] =  {0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};
  const uint32_t MSIRangeTable[12] = {100000U,   200000U,   400000U,   800000U,  1000000U,  2000000U,
                                    4000000U, 8000000U, 16000000U, 24000000U, 32000000U, 48000000U
                                   };

// In Linker script
extern uint32_t  _vect_tab_begin;

/**
  * @brief  Configures the System clock source, PLL Multiplier and Divider factors,
  *         AHB/APBx prescalers and Flash settings
  * 
  * NOTE:   This function should be called only once the RCC clock configuration
  *         is reset to the default reset state (done in SystemInit() function).
  */
static inline void HSE72MhzClock (void) {
  RCC.APB1ENR1.B.PWREN = 1u;
  // Set power Range 1
  PWR.CR1.modify([](PWR_CR1_s & r)->auto {
    r.B.VOS = 1u;
    return r.R;
  });
  while (PWR.SR2.B.VOSF);
  PWR.CR2.B.USV = 1;            // !!! bylo  nutno pridat
  /* Adjust Flash latency */
  FLASH.ACR.modify([](Flash_ACR_s & r)->auto {
    r.B.DCEN    = 1u;
    r.B.ICEN    = 1u;
    r.B.PRFTEN  = 1u;
    r.B.LATENCY = 4u;
    return r.R;
  });
  RCC.CR.modify([=](RCC_CR_s & r)->auto {
    r.B.MSIRANGE = 11u; // MSI 48 MHz (USB)
    r.B.MSIRGSEL = 1u;
    r.B.MSION    = 1u;
    r.B.HSEON    = 1u;
    return r.R;
  });
  while (RCC.CR.B.HSERDY     == 0u);
  while (RCC.CR.B.MSIRDY     == 0u);
  RCC.PLLCFGR.modify([](RCC_PLLCFGR_s & r)->auto {
    r.B.PLLSRC = 3u;  // HSE 8 MHz
    r.B.PLLM   = 0u;  // : 1  => 8 MHz
    r.B.PLLN   = 36u; // 36 x => 288 MHz
    
    r.B.PLLR   = 1u;  // : 4 => 72MHz (SYSTEM)
    r.B.PLLQ   = 2u;  // : 6 => 48MHz (UNUSED)
    return r.R;
  });
  RCC.CR.B.PLLON = 1u;
  while (RCC.CR.B.PLLRDY == 0u);
  RCC.PLLCFGR.modify([](RCC_PLLCFGR_s & r)->auto {
    r.B.PLLREN = 1u;  // PLLCLK output enable
    r.B.PLLQEN = 0u;  // PLL PLL48M1CLK output disable
    return r.R;
  }); 
  RCC.CFGR.modify([](RCC_CFGR_s & r)->auto {
    r.B.SW = 3u;      // PLL 72MHz selected as system clock
    return r.R;
  });
  RCC.CCIPR.modify([](RCC_CCIPR_s & r)->auto {
    r.B.CLK48SEL = 3u; // MSI clock selected as 48 MHz clock
    return r.R;
  });
#ifdef USE_USB
  /* enable GPIOA clock */
  RCC.AHB2ENR.B.GPIOAEN = 1;
  /* set GP11 and GP12 as USB data pins AF10 */
  GPIOA.AFR[1]  |=   (0x0A << 12) | (0x0A << 16);
  GPIOA.MODER   &= ~((0x03 << 22) | (0x03 << 24));
  GPIOA.MODER   |=   (0x02 << 22) | (0x02 << 24);
  GPIOA.OSPEEDR |=   (0x03 << 22) | (0x03 << 24);
#endif // USE_USB
}
static inline void HSI72MhzClock (void) {
  RCC.APB1ENR1.B.PWREN = 1u;
  // Set power Range 1
  PWR.CR1.modify([](PWR_CR1_s & r)->auto {
    r.B.VOS = 1u;
    return r.R;
  });
  while (PWR.SR2.B.VOSF);
  PWR.CR2.B.USV = 1;            // !!! bylo  nutno pridat
  /* Adjust Flash latency */
  FLASH.ACR.modify([](Flash_ACR_s & r)->auto {
    r.B.DCEN    = 1u;
    r.B.ICEN    = 1u;
    r.B.PRFTEN  = 1u;
    r.B.LATENCY = 4u;
    return r.R;
  });
  RCC.CR.modify([=](RCC_CR_s & r)->auto {
    r.B.MSIRANGE = 6u;
    r.B.MSIRGSEL = 1u;
    r.B.MSION    = 1u;
    return r.R;
  });
  while (RCC.CR.B.MSIRDY     == 0u);
  RCC.PLLCFGR.modify([](RCC_PLLCFGR_s & r)->auto {
    r.B.PLLSRC = 1u;  // HSE 8 MHz
    r.B.PLLM   = 0u;  // : 1  => 4 MHz
    r.B.PLLN   = 72u; // 72 x => 288 MHz
    
    r.B.PLLR   = 1u;  // : 4 => 72MHz (SYSTEM)
    r.B.PLLQ   = 2u;  // : 6 => 48MHz (USB)
    return r.R;
  });
  RCC.CR.B.PLLON = 1u;
  while (RCC.CR.B.PLLRDY == 0u);
  RCC.PLLCFGR.modify([](RCC_PLLCFGR_s & r)->auto {
    r.B.PLLREN = 1u;  // PLLCLK output enable
    r.B.PLLQEN = 1u;  // PLL PLL48M1CLK output enable
    return r.R;
  }); 
  RCC.CFGR.modify([](RCC_CFGR_s & r)->auto {
    r.B.SW = 3u;      // PLL selected as system clock
    return r.R;
  });
  RCC.CCIPR.modify([](RCC_CCIPR_s & r)->auto {
    r.B.CLK48SEL = 2u; // PLL Q clock (PLL48M1CLK) selected as 48 MHz clock
    return r.R;
  });
#ifdef USE_USB
  /* enable GPIOA clock */
  RCC.AHB2ENR.B.GPIOAEN = 1;
  /* set GP11 and GP12 as USB data pins AF10 */
  GPIOA.AFR[1]  |=   (0x0A << 12) | (0x0A << 16);
  GPIOA.MODER   &= ~((0x03 << 22) | (0x03 << 24));
  GPIOA.MODER   |=   (0x02 << 22) | (0x02 << 24);
  GPIOA.OSPEEDR |=   (0x03 << 22) | (0x03 << 24);
#endif // USE_USB
}
void SystemInit (void) {
  /* FPU settings
   * Zapíná FPU, pokud je přítomen (ano) a při překladu je použit parametr -mfpu=fpv4-sp-d16
   */
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
  SCB->CPACR |= ( (3UL << 10*2) | (3UL << 11*2)); /* set CP10 and CP11 Full Access */
#else
//#warning "FPU not allowed"
#endif

  /* Reset the RCC clock configuration to the default reset state ------------*/
  /* Set MSION bit */
  RCC.CR.B.MSION = 1u;

  /* Reset CFGR register */
  RCC.CFGR.R = 0x00000000U;

  /* Reset HSEON, CSSON , HSION, and PLLON bits */
  RCC.CR.R &= 0xEAF6FFFFU;

  /* Reset PLLCFGR register */
  RCC.PLLCFGR.R = 0x00001000U;

  /* Reset HSEBYP bit */
  RCC.CR.R &= 0xFFFBFFFFU;

  /* Disable all interrupts */
  RCC.CIER.R = 0x00000000U;


  /* Configure the Vector Table location add offset address ------------------*/
  SCB->VTOR = (uint32_t) &_vect_tab_begin; /* Vector Table Relocation in SRAM/FLASH */

  /* Configure the System clock source, PLL Multiplier and Divider factors,
     AHB/APBx prescalers and Flash settings ----------------------------------*/
  /* tady je ještě nastavení flash cache, priority grouping NVIC (asi zbytečné) */
  HSE72MhzClock();
}
void UserSystemInit () {
  SCB->VTOR = (uint32_t) &_vect_tab_begin;
}
/* Převzato z HAL, zde bude důležité zřejmě jen msirange, v low power je lépe všechny HS oscilátory vypnout.
 * */
void SystemCoreClockUpdate (void) {
  uint32_t tmp = 0U, msirange = 0U, pllvco = 0U, pllr = 2U, pllsource = 0U, pllm = 2U;

  /* Get MSI Range frequency--------------------------------------------------*/
  if (RCC.CR.B.MSIRGSEL == 0) {
    /* MSISRANGE from RCC_CSR applies */
    msirange = RCC.CSR.B.MSISRANGE;
  } else {
    /* MSIRANGE from RCC_CR applies */
    msirange = RCC.CR.B.MSIRANGE;
  }
  /* MSI frequency range in HZ */
  msirange = MSIRangeTable[msirange];

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (RCC.CFGR.B.SWS) {
    case 0x00:  /* MSI used as system clock source */
      SystemCoreClock = msirange;
      break;

    case 0x01:  /* HSI used as system clock source */
      SystemCoreClock = HSI_VALUE;
      break;

    case 0x02:  /* HSE used as system clock source */
      SystemCoreClock = HSE_VALUE;
      break;

    case 0x03:  /* PLL used as system clock  source */
      /* PLL_VCO = (HSE_VALUE or HSI_VALUE or MSI_VALUE/ PLLM) * PLLN
        SYSCLK = PLL_VCO / PLLR
        */
      pllsource = RCC.PLLCFGR.B.PLLSRC;
      pllm = RCC.PLLCFGR.B.PLLM + 1U ;

      switch (pllsource) {
        case 0x02:  /* HSI used as PLL clock source */
          pllvco = (HSI_VALUE / pllm);
          break;

        case 0x03:  /* HSE used as PLL clock source */
          pllvco = (HSE_VALUE / pllm);
          break;

        default:    /* MSI used as PLL clock source */
          pllvco = (msirange / pllm);
          break;
      }
      pllvco = pllvco * RCC.PLLCFGR.B.PLLN;
      pllr = (RCC.PLLCFGR.B.PLLR + 1U) * 2U;
      SystemCoreClock = pllvco/pllr;
      break;

    default:    // zbytecne
      SystemCoreClock = msirange;
      break;
  }
  /* Compute HCLK clock frequency --------------------------------------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[RCC.CFGR.B.HPRE];
  /* HCLK clock frequency */
  SystemCoreClock >>= tmp;
}

