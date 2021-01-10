#ifndef __SYSTEM_STM32L4XX_H
#define __SYSTEM_STM32L4XX_H
#include <stdint.h>

/** @file
 *  @brief Základní nastavení CPU.
 * 
 * Doplněné o DBGMCU pro debug ve sleep módu. 
 * */

#ifdef __cplusplus
extern "C" {
#endif 
/** System Clock Frequency (Core Clock) */
extern uint32_t SystemCoreClock;
/** Inicializace jádra a hodin periferií */
extern void SystemInit            (void);
/** Spočte frekvenci jádra v závislosti na nastavení */
extern void SystemCoreClockUpdate (void);

/** Inicializace jen tabulky vektorů, hodiny a flash inicializovány bootloaderem */
extern void UserSystemInit        (void);
/// Control registr DEBUG MCU
typedef union {
  struct {
    uint32_t DBG_SLEEP   : 1;   //!< Debug Sleep mode
    uint32_t DBG_STOP    : 1;   //!< Debug Stop mode
    uint32_t DBG_STANDBY : 1;   //!< Debug Standby mode
    uint32_t UNUSED1     : 2;
    uint32_t TRACE_IOEN  : 1;   //!< Trace pin assignment control
    uint32_t TRACE_MODE  : 2;   //!< TRACE pin assignment for Asynchronous/Synchronous Mode, TRACEDATA size
    uint32_t UNUSED2     : 24;
  }        B;                 //!< jednotlivé bity
  uint32_t R;                 //!< Celková hodnota
} DBGMCU_CR;
/// Blok řízení DEBUG MCU
typedef struct {
  volatile uint32_t  IDCODE;    //!< ID procesoru
  volatile DBGMCU_CR CR;        //!< Řízení debug při low power modech.
  volatile uint32_t  APB1_FZ1;  //!< chování periferií při debug
  volatile uint32_t  APB1_FZ2;  //!< chování periferií při debug
  volatile uint32_t  APB2_FZ;   //!< chování periferií při debug
} DBGMCU_L4;
/// Adresa DBGMCU bloku
static DBGMCU_L4 * const  MDBGMCU = (DBGMCU_L4 *) 0xE0042000;
/// Pokud použijeme v programu wfi/wfe, je nutné povolit debug i v tt. módu.
static inline void EnableDebugOnSleep (void) {
  MDBGMCU->CR.B.DBG_SLEEP   = 1;
}

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_STM32L4XX_H */
