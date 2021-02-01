#ifndef SPICLASS_H
#define SPICLASS_H
#include "gpio.h"

/** @file
 *  @brief SPI2 Hardware Layer
 * 
 * Není to obecný SPI, jen pro konkrétní hardware - SPI2.
 * Zatím jen náčrt řešení.
 * */

/// Maximální délka buferů.
static const unsigned SpiBufLen = 140;

/** @class SpiClass
 *  @brief Zapouzdření SPI2 do třídy.
 * 
 * Zatím jen inicializace hardware a základní přenos dat bez jakéhokoli navázání na další hardware.
 * Chip Select (NSS) bude muset být řešen zvenčí, zde není a ani nebude, protože na tom visí více
 * zařízení. Předpoklad je, že vždy bude stačit 8-bitový přenos u něhož je známa délka.
 * */
class SpiClass {
  public:
    /// Konstruktor
    SpiClass(){};
    void Init ();
    void Fini ();
    /** @brief Základní SPI transakce.
     * 
     * Při příjmu je nutné stejně vysílat stejné množství dat. To je dáno principem SPI a celkem se
     * s tím nedá nic dělat. Zatím je omezení paketu na SpiBufLen, ale není to dogma. Data jsou
     * kopírována do (z) interních buferů, kvůli použitému DMA. DMA značně zjednodušuje transakci
     * a nastavit to není zase taková věda.
     * 
     * @param data Ukazatel na pole bytů, které se odešle a po dokončení se do něj uloží přijatá data.
     * @param len  Počet odesílaných / přijímaných bytů
     * @param chip_select odkaz na pin chip_select
     * @return Počet skutečně odeslaných / přijatých bytů
     * */
    uint32_t Transaction (uint8_t * data, const uint32_t len, const GpioClass & chip_select);
    /*
  public: // UNUSABLE
    void drq   (void);
    */
  protected:
    /// Start přenosu oddělen do této funkce.
    void startTransaction ();
    void waitTransactionEnd ();
  private:
    volatile bool pending;              //!< transakce probíhá
    unsigned      lastTransactionLen;   //!< délka poslední transakce
    uint8_t txb[SpiBufLen];             //!< vysílací buffer
    uint8_t rxb[SpiBufLen];             //!< přijímací buffer
};

#endif // SPICLASS_H
