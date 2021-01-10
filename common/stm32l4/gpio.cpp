#include "gpio.h"
#define RCC_AHB2ENR_GPIOAEN ((uint32_t)0x00000001u) /*!< Ofs=0 IO port A clock enable */
#define RCC_AHB2ENR_GPIOBEN ((uint32_t)0x00000002u) /*!< Ofs=1 IO port B clock enable */
#define RCC_AHB2ENR_GPIOCEN ((uint32_t)0x00000004u) /*!< Ofs=2 IO port C clock enable */
#define RCC_AHB2ENR_GPIODEN ((uint32_t)0x00000008u) /*!< Ofs=3 IO port D clock enable */
#define RCC_AHB2ENR_GPIOEEN ((uint32_t)0x00000010u) /*!< Ofs=4 IO port E clock enable */
#define RCC_AHB2ENR_GPIOHEN ((uint32_t)0x00000080u) /*!< Ofs=7 IO port H clock enable */

#define pGPIOA ((GPIO_Type * const) 0x48000000u) /*!< General-purpose I/Os */
#define pGPIOB ((GPIO_Type * const) 0x48000400u) /*!< General-purpose I/Os */
#define pGPIOC ((GPIO_Type * const) 0x48000800u) /*!< General-purpose I/Os */
#define pGPIOD ((GPIO_Type * const) 0x48000C00u) /*!< General-purpose I/Os */
#define pGPIOE ((GPIO_Type * const) 0x48001000u) /*!< General-purpose I/Os */
#define pGPIOH ((GPIO_Type * const) 0x48001C00u) /*!< General-purpose I/Os */

// Tabulka 72 bytu ve flash, kód to zkrátí i zrychlí. Aby byla tabulka ve flash, nelze do ní
// umístit odkazy, musí to být ukazatele (jsou konstantní). V C to takhle inicializovat nejde,
// musely by se použít define, C++ (gcc) to spolkne i statické konstanty.
// Ukázalo se, že clang sice statické konstanty spolkne, ale umístí tabulku do .bss (vytvoří
// pro ní statický kostruktor). To je sice nepříjemné, ale horší je, že to nefunguje.
// Pokud zůstaneme u klasických define, funguje to správně, takže to tak necháme.
static const struct GpioAssocPort cPortTab[] = {
  {pGPIOA, RCC_AHB2ENR_GPIOAEN},
  {pGPIOB, RCC_AHB2ENR_GPIOBEN},
  {pGPIOC, RCC_AHB2ENR_GPIOCEN},
  {pGPIOD, RCC_AHB2ENR_GPIODEN},
  {pGPIOE, RCC_AHB2ENR_GPIOEEN},
  {pGPIOH, RCC_AHB2ENR_GPIOHEN},
};

GpioClass::GpioClass (GpioPortNum const port, const uint32_t no, const GPIOMode_TypeDef type) :
  io (cPortTab[port].portAdr), pos(1UL << no), num(no) {
  // Povol hodiny
  RCC.AHB2ENR.R |= cPortTab[port].clkMask;
  // A nastav pin (pořadí dle ST knihovny). Zakomentované funkce jsou defaultní hodnoty, není potřeba.
//setSpeed (GPIO_Speed_LS);
//setOType (GPIO_OType_PP);
  setMode  (type);
//setPuPd  (GPIO_PuPd_NOPULL);
}
GpioGroup::GpioGroup (const GpioPortNum port, const uint8_t * const list, const uint32_t num, const GPIOMode_TypeDef type) :
  io(cPortTab[port].portAdr), pins (list), size (num){
  // Povol hodiny
  RCC.AHB2ENR.R |= cPortTab[port].clkMask;
  // A nastav pin (pořadí dle ST knihovny).
//setSpeed (GPIO_Speed_LS);
//setOType (GPIO_OType_PP);
  setMode  (type);
//setPuPd  (GPIO_PuPd_NOPULL);
}

