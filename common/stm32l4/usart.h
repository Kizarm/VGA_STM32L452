#ifndef USART1CLASS_H
#define USART1CLASS_H

#include "STM32L4x2.h"
#include "baselayer.h"
#include "fifo.h"
/** @file
  * @brief Inicializace a obsluha USART.

  * @class UsartClass
  * @brief Ve stacku dole - Bottom, pod tím jsou už jen dráty.
  *
  * Ukazuje použití jak dědičnosti - dědí vlastnosti třídy BaseLayer, tak polymorfizmu,
  * protože BaseLayer používá virtuální veřejné metody pro začlenění do stacku.
  * Kromě toho je sem zapouzdřena (kompozice) i třída Fifo, což je šablona.
  * Takže deklarace na několika řádcích obsahuje snad všechny vymoženosti,
  * které C++ nabízí a přitom bude generovat smysluplný a celkem použitelný kód.

  * Není to psáno obecně jako třeba periferní knihovny od ST, ale to je úmysl,
  * kód by měl být co nejmenší a přesto opakovatelně použitelný. Prakticky je potřeba
  * opravdu nastavit jen přenosovou rychlost, málokdy je potřeba měnit formát 8N1
  * nebo zapínat hardware flow control. A USART na tomto procesoru je tak složitý,
  * že prakticky všechny jeho speciální módy činnosti knihovna ST stejně neumí postihnout.
  */
/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
/// Enumerace USARTů, jen první 3.
enum UsartEnum {
  UsartNo1 = 0,
  UsartNo2,
  UsartNo3,
  MAXUSARTS
};

class UsartClass : public BaseLayer {
  public: // Mandatory
    /// Konstruktor @param no Číslo (enum) USARTu.
    UsartClass (const UsartEnum no);
    /** @brief Začátek činnosti se zvolenými parametry.
     *  @param baud  Baudrate
     *  @param swap_pins Pokud je potřeba, zamění se piny Rx a Tx
     * */
    void init (const uint32_t baud, const bool swap_pins = false);
    /** @brief Ukončení činnosti, celková deinicializace.
     *
     * V podstatě nahrazuje destruktor, ale použití bude asi hlavně pro Low Power módy.
     * */
    void fini ();
    /// Přetížení - data (přes FIFO) přímo na drát
    /// @param data ukazatel na data
    /// @param len  délka dat v bytech
    /// @return počet skutečně přenesených bytů (může se od len dost lišit)
    uint32_t    Down (const char* data, uint32_t len);
    /// Nastavení baudové rychlosti.
    /// @param baud požadovaná rychlost
    void        SetBaud (uint32_t baud) const;
  public: // Optional
  public: // Unusable
    /// Obsluha přerušení.
    void        irq (void);      //!< Obecná metoda
  private:
    USART_Type * const  port; //!< Adresa registrů
    uint32_t     const  uno;  //!< číslo usartu (fakticky UsartEnum no)
    Fifo<char,  64>     tx;   //!< Zajišťuje, že metoda Down neblokuje program
};

#endif // USART1CLASS_H
