#include "gpio.h"
#include "usart.h"

#define pUSART1 ((USART_Type * const) 0x40013800u) /*!< Universal synchronous asynchronous receiver transmitter */
#define pUSART2 ((USART_Type * const) 0x40004400u) /*!< Universal synchronous asynchronous receiver transmitter */
#define pUSART3 ((USART_Type * const) 0x40004800u) /*!< Universal synchronous asynchronous receiver transmitter */

struct UsartPin {
  GpioPortNum   port;
  uint8_t       no;
  uint8_t       alt;
};
typedef void (*USART_RCC_SET) (bool);

struct UsartConstParam {
  USART_Type  *  usart;
  USART_RCC_SET  clock;
  IRQn_Type      irq;
  UsartPin       txp,   //!< TxD pin
                 rxp;   //!< RxD pin
};
// Protože je to zapojeno divně, uděláme to jako callback.
static void RccSetUsart1 (bool en) {
  if (en) {
    RCC.APB2ENR.B.USART1EN   = 1u;
  } else {
    RCC.APB2ENR.B.USART1EN   = 0u;  // vypni
    RCC.APB2RSTR.B.USART1RST = 1u;  // a resetuj
    RCC.APB2RSTR.B.USART1RST = 0u;
  }
}
static void RccSetUsart2 (bool en) {
  if (en) {
    RCC.APB1ENR1.B.USART2EN   = 1u;
  } else {
    RCC.APB1ENR1.B.USART2EN   = 0u;
    RCC.APB1RSTR1.B.USART2RST = 1u;
    RCC.APB1RSTR1.B.USART2RST = 0u;
  }
}
static void RccSetUsart3 (bool en) {
  if (en) {
    RCC.APB1ENR1.B.USART3EN   = 1u;
  } else {
    RCC.APB1ENR1.B.USART3EN   = 0u;
    RCC.APB1RSTR1.B.USART3RST = 1u;
    RCC.APB1RSTR1.B.USART3RST = 0u;
  }
}

static const UsartConstParam UsartConstMap[MAXUSARTS] = {
  {
    .usart = pUSART1, .clock = RccSetUsart1, .irq = USART1_IRQn,
    .txp = { GpioPortA, 9,  7 },
    .rxp = { GpioPortA, 10, 7 },
  },
  {
    .usart = pUSART2, .clock = RccSetUsart2, .irq = USART2_IRQn,
    .txp = { GpioPortA, 2, 7 },
    .rxp = { GpioPortA, 3, 7 },
  },
  {
    .usart = pUSART3, .clock = RccSetUsart3, .irq = USART3_IRQn,
    .txp = { GpioPortB,10, 7 },
    .rxp = { GpioPortB,11, 7 },   // v zapojení swap
  },
};

/// Instance třídy potřebné pro jednotlivá přerušení.
static UsartClass * UsartIrqTable [MAXUSARTS];

// Obsluha přerušení. Je to obal kvůli mechanizmu vektorů.
// Handler se volá v C, je třeba mu předat jako parametr
// ukazatel na instanci příslušné třídy. Proto je tato metoda
// public, ale je zvnějšku samosebou nepoužitelná.

void UsartClass::irq (void) {
  USART_ISR_s status (port->ISR);           // načti status přerušení  
  char rdata, tdata;

  if (status.B.TXE) {                       // od vysílače
    if (tx.Read (tdata))                        // pokud máme data
      port->TDR = (uint32_t) tdata & 0xFF;      // zapíšeme do výstupu
    else                                        // pokud ne
      port->CR1.B.TXEIE = 0;                    // je nutné zakázat přerušení od vysílače
  }
  if (status.B.RXNE) {                      // od přijímače
    rdata = (port->RDR) & 0xFF;                // načteme data
    Up (&rdata, 1);           // předáme dál stylem vystřel a zapomeň,
  }                           // takže (případné) chyby se musí ošetřit o vrstvu výš.
}
// Voláno z čistého C - startup.c
extern "C" void USART1_IRQHandler (void) {
  UsartClass * inst = UsartIrqTable [UsartNo1];
  if (inst) inst->irq();
}
extern "C" void USART2_IRQHandler (void) {
  UsartClass * inst = UsartIrqTable [UsartNo2];
  if (inst) inst->irq();
}
extern "C" void USART3_IRQHandler (void) {
  UsartClass * inst = UsartIrqTable [UsartNo3];
  if (inst) inst->irq();
}

// Pomocná funkce pro vastavení alternativní funkce pinu.
static inline void setAlt (const UsartPin & p) {
  GpioClass pin (p.port, p.no, GPIO_Mode_AF);
  pin.setAF (p.alt);
}
static inline void setAnalog (const UsartPin & p) {
  GpioClass pin (p.port, p.no, GPIO_Mode_AN);
}

// Class is Bottom
UsartClass::UsartClass (UsartEnum no) : BaseLayer(),
  port (UsartConstMap[no].usart), uno (no) {
}
enum UsartStopBits {
  OneStopBits = 0,
  HalfStopBits,
  TwoStopBits,
  OnePlusHalfBits,
};
/* Pár poznámek k volbě taktování USART.
 * 
 * Pomocí RCC_CCIPR (RM 6.4.27) lze navolit zdroj hodin pro USARTy.
 * Default je PCLK a pokud není zapojena dělička, je to rovno SystemCoreClock.
 * Není celkem důvod na tom něco měnit, v dalším se bude predpokládat,
 * že používáme skutečně SystemCoreClock. Pokud se někde zapne dělička,
 * nebo se zdroj změní, bude nutné to zohlednit.
 * */
void UsartClass::init (const uint32_t baud, const bool swap_pins) {
  if (UsartIrqTable[uno]) return;     // Chyba - jedina instance pro jeden USART
  UsartIrqTable[uno] = this;
  const UsartConstParam * prm  = UsartConstMap + uno;
  // 1. Clock Enable
  prm->clock (true);
  // 2. USART registry 8.bit bez parity, neošetřujeme chyby
  port->CR1.modify([](USART_CR1_s & r) -> auto {
    r.B.RE     = 1u;    // povol příjem
    r.B.TE     = 1u;    // povol vysílání
    r.B.RXNEIE = 1u;    // a přerušení od přijímače, vysílač až bude opravdu vysílat
    r.B.OVER8  = 1u;    // je k diskusi, jestli toto použít.
    return r.R;
  });
  if (swap_pins) {      // USART3 v zapojení bude potřebovat prohodit piny
    port->CR2.B.SWAP = 1u;
  }
//port->CR2.B.STOP = (uint32_t) OneStopBits; // lze změnit, zatím default, většinou stačí
  // disable the receive overrun detection (dělá to jen problémy)
  port->CR3.B.OVRDIS = 1u;
  // 3. GPIO Alternate Config
  setAlt (prm->txp);
  setAlt (prm->rxp);
  // 4. NVIC
  NVIC_EnableIRQ (prm->irq);
  // 5. Nastavení rychlosti a povolení celkově
  SetBaud (baud);
}
void UsartClass::fini () {
  const UsartConstParam * prm  = UsartConstMap + uno;
  port->CR1.B.UE = 0u;          // zákaz
  NVIC_DisableIRQ (prm->irq);   // i přerušení
  prm->clock (false);           // vypni hodiny a zresetuj
  UsartIrqTable[uno] = 0;       // nakonec vymaž instanci z tabulky
  // GPIO fini()
  setAnalog (prm->rxp);
  setAnalog (prm->txp);
}
/* pro pclk = 4 MHz vychází pro baudrate tyto hodnoty:

      OVERSAMPLING 16 (CR1.B.OVER8=0)        OVERSAMPLING 8 (CR1.B.OVER8=1)
______________________________________________________________________________
| žádaná    skutečná  BRR      chyba   | žádaná    skutečná  BRR      chyba   |
|   2400,    2399.52, 0x0683 (-00.02%) |   2400,    2400.24, 0x0D02 (+00.01%) |
|   9600,    9592.33, 0x01A1 (-00.08%) |   9600,    9603.84, 0x0340 (+00.04%) |
|  19200,   19230.77, 0x00D0 (+00.16%) |  19200,   19184.65, 0x01A0 (-00.08%) |
|  38400,   38461.54, 0x0068 (+00.16%) |  38400,   38461.54, 0x00D0 (+00.16%) |
|  57600,   57971.01, 0x0045 (+00.64%) |  57600,   57553.96, 0x0085 (-00.08%) |
| 115200,  114285.71, 0x0023 (-00.79%) | 115200,  115942.03, 0x0042 (+00.64%) |
-------------------------------------------------------------------------------
 i pro pclk = 1 MHz to není tak hrozné
______________________________________________________________________________
|   2400,    2398.08, 0x01A1 (-00.08%) |   2400,    2400.96, 0x0340 (+00.04%) |
|   9600,    9615.38, 0x0068 (+00.16%) |   9600,    9615.38, 0x00D0 (+00.16%) |
|  19200,   19230.77, 0x0034 (+00.16%) |  19200,   19230.77, 0x0064 (+00.16%) |
|  38400,   38461.54, 0x001A (+00.16%) |  38400,   38461.54, 0x0032 (+00.16%) |
|  57600,   58823.53, 0x0011 (+02.12%) |  57600,   57142.86, 0x0021 (-00.79%) |
| 115200,  111111.11, 0x0009 (-03.55%) | 115200,  117647.06, 0x0010 (+02.12%) |
-------------------------------------------------------------------------------
*/
void UsartClass::SetBaud (uint32_t baud) const {
  uint32_t   pclk  = SystemCoreClock;
  const bool over8 = port->CR1.B.OVER8 ? true : false;
  
  port->CR1.B.UE = 0u;        // pro jistotu zakázat

  if (over8) pclk *= 2u;
  // Celočíselné zaokruhlení po dělení, produkuje skutečně nejmenší absolutní hodnotu chyby
  uint32_t  usartdiv  = 2 * pclk;       // Vyjdeme z dvojnásobku
  usartdiv /= baud;                     // vydělíme - dostaneme dvojnásobek
  const uint32_t plus = usartdiv & 1u;  // který když má na konci 1
  usartdiv >>= 1;                       // (tady už je celkem správný podíl)
  usartdiv  += plus;                    // bude potřeba zokrouhlit směrem nahoru
  uint32_t brr;
  if (over8) {
    // Kdo mohl tohle vymyslet, ale je to tak - RM Table 166 sedí.
    brr = (usartdiv & 0xFFFFFFF0U) | ((usartdiv & 0xFU) >> 1);
  } else {
    brr =  usartdiv;
  }
  port->BRR = brr;
  
  port->CR1.B.UE = 1u;        // Nakonec celkově povolit
}

// Nahustí data do fifo, na nic nečeká a odešle na pin
uint32_t UsartClass::Down (const char* data, uint32_t len) {
  uint32_t res;
  for (res=0; res<len; res++) if (!tx.Write (data[res])) break;
  if (!res) return res;
  port->CR1.B.TXEIE = 1u;      // po povolení přerušení okamžitě přeruší
  return res; // Je naspodu - Bottom, takže dál už není třeba nikam předávat
}


