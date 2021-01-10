#include <stdint.h>
#include "system.h"

#if defined (__cplusplus)
extern "C" {
#endif

/// V linker skriptu
  extern void (*__init_array_start) ();
  extern void (*__init_array_end) ();
/// Inicializace statických konstruktorů - použít explicitně po celkové inicializaci systému
  static inline void static_init() {
    void (**p) ();
    // Tohle je sice konstrukce značně nepřehledná (nalezená na webu), leč funguje.
    for (p = &__init_array_start; p < &__init_array_end; p++) (*p) ();
  }


#define WEAK     __attribute__ ((weak))
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

  extern unsigned int _estack;
  /* start address for the initialization values of the .data section.
  defined in linker script */
  extern unsigned int _sidata;
  /* start address for the .data section. defined in linker script */
  extern unsigned int _sdata;
  /* end address for the .data section. defined in linker script */
  extern unsigned int _edata;
  /* start address for the .bss section. defined in linker script */
  extern unsigned int _sbss;
  /* end address for the .bss section. defined in linker script */
  extern unsigned int _ebss;

  WEAK void Reset_Handler (void);
  WEAK void DefaultHandler (void);


  void  NMI_Handler             (void) ALIAS (Default_Handler);
  void  HardFault_Handler       (void) ALIAS (Default_Handler);
  void  MemManage_Handler       (void) ALIAS (Default_Handler);
  void  BusFault_Handler        (void) ALIAS (Default_Handler);
  void  UsageFault_Handler      (void) ALIAS (Default_Handler);
  void  SVC_Handler             (void) ALIAS (Default_Handler);
  void  DebugMon_Handler        (void) ALIAS (Default_Handler);
  void  PendSV_Handler          (void) ALIAS (Default_Handler);
  void  SysTick_Handler         (void) ALIAS (Default_Handler);

  void WWDG_IRQHandler     (void) ALIAS(Default_Handler);
  void PVD_PVM_IRQHandler  (void) ALIAS(Default_Handler);
  void RTC_TAMP_STAMP_IRQHandler (void) ALIAS(Default_Handler);
  void RTC_WKUP_IRQHandler (void) ALIAS(Default_Handler);
  void FLASH_IRQHandler    (void) ALIAS(Default_Handler);
  void RCC_IRQHandler      (void) ALIAS(Default_Handler);
  void EXTI0_IRQHandler    (void) ALIAS(Default_Handler);
  void EXTI1_IRQHandler    (void) ALIAS(Default_Handler);
  void EXTI2_IRQHandler    (void) ALIAS(Default_Handler);
  void EXTI3_IRQHandler    (void) ALIAS(Default_Handler);
  void EXTI4_IRQHandler    (void) ALIAS(Default_Handler);
  void DMA1_CH1_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH2_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH3_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH4_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH5_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH6_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH7_IRQHandler (void) ALIAS(Default_Handler);
  void ADC1_IRQHandler     (void) ALIAS(Default_Handler);
  void CAN1_TX_IRQHandler  (void) ALIAS(Default_Handler);
  void CAN1_RX0_IRQHandler (void) ALIAS(Default_Handler);
  void CAN1_RX1_IRQHandler (void) ALIAS(Default_Handler);
  void CAN1_SCE_IRQHandler (void) ALIAS(Default_Handler);
  void EXTI9_5_IRQHandler  (void) ALIAS(Default_Handler);
  void TIM1_BRK_TIM15_IRQHandler (void) ALIAS(Default_Handler);
  void TIM1_UP_TIM16_IRQHandler (void) ALIAS(Default_Handler);
  void TIM1_TRG_COM_IRQHandler (void) ALIAS(Default_Handler);
  void TIM1_CC_IRQHandler  (void) ALIAS(Default_Handler);
  void TIM2_IRQHandler     (void) ALIAS(Default_Handler);
  void TIM3_IRQHandler     (void) ALIAS(Default_Handler);
  void I2C1_EV_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C1_ER_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C2_EV_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C2_ER_IRQHandler  (void) ALIAS(Default_Handler);
  void SPI1_IRQHandler     (void) ALIAS(Default_Handler);
  void SPI2_IRQHandler     (void) ALIAS(Default_Handler);
  void USART1_IRQHandler   (void) ALIAS(Default_Handler);
  void USART2_IRQHandler   (void) ALIAS(Default_Handler);
  void USART3_IRQHandler   (void) ALIAS(Default_Handler);
  void EXTI15_10_IRQHandler (void) ALIAS(Default_Handler);
  void RTC_ALARM_IRQHandler (void) ALIAS(Default_Handler);
  void DFSDM1_FLT3_IRQHandler (void) ALIAS(Default_Handler);
  void SDMMC1_IRQHandler   (void) ALIAS(Default_Handler);
  void SPI3_IRQHandler     (void) ALIAS(Default_Handler);
  void UART4_IRQHandler    (void) ALIAS(Default_Handler);
  void TIM6_DACUNDER_IRQHandler (void) ALIAS(Default_Handler);
  void TIM7_IRQHandler     (void) ALIAS(Default_Handler);
  void DMA2_CH1_IRQHandler (void) ALIAS(Default_Handler);
  void DMA2_CH2_IRQHandler (void) ALIAS(Default_Handler);
  void DMA2_CH3_IRQHandler (void) ALIAS(Default_Handler);
  void DMA2_CH4_IRQHandler (void) ALIAS(Default_Handler);
  void DMA2_CH5_IRQHandler (void) ALIAS(Default_Handler);
  void DFSDM1_IRQHandler   (void) ALIAS(Default_Handler);
  void DFSDM2_IRQHandler   (void) ALIAS(Default_Handler);
  void DFSDM1_FLT2_IRQHandler (void) ALIAS(Default_Handler);
  void COMP_IRQHandler     (void) ALIAS(Default_Handler);
  void LPTIM1_IRQHandler   (void) ALIAS(Default_Handler);
  void LPTIM2_IRQHandler   (void) ALIAS(Default_Handler);
  void USB_FS_IRQHandler   (void) ALIAS(Default_Handler);
  void DMA2_CH6_IRQHandler (void) ALIAS(Default_Handler);
  void DMA2_CH7_IRQHandler (void) ALIAS(Default_Handler);
  void LPUART1_IRQHandler  (void) ALIAS(Default_Handler);
  void QUADSPI_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C3_EV_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C3_ER_IRQHandler  (void) ALIAS(Default_Handler);
  void SAI1_IRQHandler     (void) ALIAS(Default_Handler);
  void SWPMI1_IRQHandler   (void) ALIAS(Default_Handler);
  void TSC_IRQHandler      (void) ALIAS(Default_Handler);
  void LCD_IRQHandler      (void) ALIAS(Default_Handler);
  void AES_IRQHandler      (void) ALIAS(Default_Handler);
  void RNG_IRQHandler      (void) ALIAS(Default_Handler);
  void FPU_IRQHandler      (void) ALIAS(Default_Handler);
  void CRS_IRQHandler      (void) ALIAS(Default_Handler);
  void I2C4_EV_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C4_ER_IRQHandler  (void) ALIAS(Default_Handler);

  extern int main (void);
  extern void SystemInit (void);

#if defined (__cplusplus)
} // extern "C"
#endif

__attribute__ ( (section (".isr_vector")))
void (* const Vectors[]) (void) = {
  (void ( *) (void)) &_estack,
  Reset_Handler,                    // The reset handler
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0,
  0,
  0,
  0,
  SVC_Handler,
  DebugMon_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler,

  /* External Interrupts */
  WWDG_IRQHandler,
  PVD_PVM_IRQHandler,
  RTC_TAMP_STAMP_IRQHandler,
  RTC_WKUP_IRQHandler,
  FLASH_IRQHandler,
  RCC_IRQHandler,
  EXTI0_IRQHandler,
  EXTI1_IRQHandler,
  EXTI2_IRQHandler,
  EXTI3_IRQHandler,
  EXTI4_IRQHandler,
  DMA1_CH1_IRQHandler,
  DMA1_CH2_IRQHandler,
  DMA1_CH3_IRQHandler,
  DMA1_CH4_IRQHandler,
  DMA1_CH5_IRQHandler,
  DMA1_CH6_IRQHandler,
  DMA1_CH7_IRQHandler,
  ADC1_IRQHandler,
  CAN1_TX_IRQHandler,
  CAN1_RX0_IRQHandler,
  CAN1_RX1_IRQHandler,
  CAN1_SCE_IRQHandler,
  EXTI9_5_IRQHandler,
  TIM1_BRK_TIM15_IRQHandler,
  TIM1_UP_TIM16_IRQHandler,
  TIM1_TRG_COM_IRQHandler,
  TIM1_CC_IRQHandler,
  TIM2_IRQHandler,
  TIM3_IRQHandler,
  0,
  I2C1_EV_IRQHandler,
  I2C1_ER_IRQHandler,
  I2C2_EV_IRQHandler,
  I2C2_ER_IRQHandler,
  SPI1_IRQHandler,
  SPI2_IRQHandler,
  USART1_IRQHandler,
  USART2_IRQHandler,
  USART3_IRQHandler,
  EXTI15_10_IRQHandler,
  RTC_ALARM_IRQHandler,
  DFSDM1_FLT3_IRQHandler,
  0,
  0,
  0,
  0,
  0,
  0,
  SDMMC1_IRQHandler,
  0,
  SPI3_IRQHandler,
  UART4_IRQHandler,
  0,
  TIM6_DACUNDER_IRQHandler,
  TIM7_IRQHandler,
  DMA2_CH1_IRQHandler,
  DMA2_CH2_IRQHandler,
  DMA2_CH3_IRQHandler,
  DMA2_CH4_IRQHandler,
  DMA2_CH5_IRQHandler,
  DFSDM1_IRQHandler,
  DFSDM2_IRQHandler,
  DFSDM1_FLT2_IRQHandler,
  COMP_IRQHandler,
  LPTIM1_IRQHandler,
  LPTIM2_IRQHandler,
  USB_FS_IRQHandler,
  DMA2_CH6_IRQHandler,
  DMA2_CH7_IRQHandler,
  LPUART1_IRQHandler,
  QUADSPI_IRQHandler,
  I2C3_EV_IRQHandler,
  I2C3_ER_IRQHandler,
  SAI1_IRQHandler,
  0,
  SWPMI1_IRQHandler,
  TSC_IRQHandler,
  LCD_IRQHandler,
  AES_IRQHandler,
  RNG_IRQHandler,
  FPU_IRQHandler,
  CRS_IRQHandler,
  I2C4_EV_IRQHandler,
  I2C4_ER_IRQHandler,

};
static inline void fillStack (void) {
  register unsigned int *dst, *end;
  dst = &_ebss;
  end = &_estack - 1u;
  while (dst < end) *dst++ = 0xDEADBEEFU;
}
void Reset_Handler (void) {

  fillStack();
  register unsigned int *dst, *end;

  /* Zero fill the bss section */
  dst = &_sbss;
  end = &_ebss;
  while (dst < end)  *dst++ = 0U;

  /* Copy data section from flash to RAM */
  register unsigned int *src;
  src = &_sidata;
  dst = &_sdata;
  end = &_edata;
  if (src != dst) {
    while (dst < end) *dst++ = *src++;
  }
  
  SystemInit();
  SystemCoreClockUpdate();          // Potřebné pro USART
  static_init();                    // Zde zavolám globální konstruktory

  main();

  for (;;);
}


void Default_Handler (void) {
  for (;;);
  //asm volatile ("bkpt 0");
}
