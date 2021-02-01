#ifndef SERIALFLASH_H
#define SERIALFLASH_H

class GpioClass;
class SpiClass;
    /// Enumerace povelů pro SPI FLASH.
    enum FLASH_COMMANDS : uint8_t {
      /* single byte commands */
      FLASH_WRDI = 0x04,    // nepoužito
      FLASH_WREN = 0x06,
      FLASH_RDID = 0x9F,
      FLASHRSTEN = 0x66,    // nepoužito
      FLASH__RST = 0x99,    // nepoužito
      FLASH__RES = 0xAB,    // release from power down, nepoužito
      FLASH__DPD = 0xB9,    // power down, nepoužito
      // multi - byte
      FLASH_RDSR1 = 0x05,
      // dále se mohou povely lišit
      FLASH_RDSR2 = 0x35,   // nepoužito
      FLASH_4READ = 0x03,
      FLASH_4PP   = 0x02,
      FLASH_4SE   = 0x20,
    };
/**
 * @class SerialFlash
 * @brief Sériová SPI NOR flash W25Q32.
 * 
 * Před zápisem musí být oblast vymazaná pomocí EraseSectors().
 * Flash je dost variabilní, umožňuje zapsat i jediný byte, dokonce lze v rámci
 * bytu měnit stav jednotlivých bitů z 1 na 0. To se bude hodit pro nastavování platnosti
 * dat (např. odeslané - neodeslané). Takže zápis do nesmazané oblasti se povede,
 * ale zapsaná data budou logickým součinem s těmi původními.
 * Kód funguje se standardním 24. bitovým adresováním. Jiná paměť se ovšem může chovat jinak.
 * 
 * Pozor - vymazání celé 32MBit flash trvá několik minut !
 */
class SerialFlash {
  public:
    SerialFlash (SpiClass & s, GpioClass & cs) : spi(s), chip_select(cs) {};
    // bool Test   (const char * id);
    /**
     * @brief Zjištění kapacity podle JEDEC standardu.
     * 
     * @return uint8_t n, přičemž 2^n je kapacita paměti v bytech.
     */
    uint8_t GetCapacityByte () const;
    /**
     * @brief Čtení ze sériové flash.
     * 
     * @param begin_adr počáteční adresa
     * @param data ukazatel na data, kam to bude načteno - bufer min len bytů velký
     * @param len délka požadavku v bytech (v zásadě omezeno jen velikostí paměti)
     * @return uint32_t kolik se skutečně načetlo
     */
    uint32_t ReadBlock     (const uint32_t begin_adr,       uint8_t * data, const uint32_t len) const;
    /**
     * @brief Zápis do sériové flash.
     * 
     * @param begin_adr počáteční adresa
     * @param data ukazatel na data
     * @param len jejich délka
     * @return uint32_t kolik se skutečně zapsalo
     */
    uint32_t WriteBlock    (const uint32_t begin_adr, const uint8_t * data, const uint32_t len) const;
    /**
     * @brief Smazání oblasti flash
     * 
     * @param begin_adr počáteční adresa - pokud není zaokrouhlena na calý sektor 0x1000, zaokrouhlí se dolů
     * @param len délka v bytech, mažou se celé sektory 0x1000 dlouhé, takže pokud dáme EraseSectors (0,4097) nebo EraseSectors (1,4096),
     * smažou se 2 první, ale pokud EraseSectors (0,4096), smaže se jen první.
     * @return bool true, pokud je úsoěch
     */
    bool     EraseSectors  (const uint32_t begin_adr, const uint32_t len) const;
    /// Smaže jediný sektor, adresa musí být zaokrouhlena na celý sektor
    bool     EraseSector   (const uint32_t begin_adr) const;
  protected:
    /// Jednoduchý příkaz
    bool     SingleCommand (const FLASH_COMMANDS cmd) const;
    /// Načtení registru STATUS1 nebo STATUS2 pomocí FLASH_RDSRx
    uint8_t  ReadStatus    (const FLASH_COMMANDS cmd) const;
    /// Čtení je rozsekáno na kousky max 128 bytů dlouhé (omezené interní buffery)
    uint32_t ReadChunk     (const uint32_t begin_adr,       uint8_t * data, const uint32_t len) const;
    /// Stejně tak zápis
    uint32_t WriteChunk    (const uint32_t begin_adr, const uint8_t * data, const uint32_t len) const;
    /// Čekání na dokončení operace zápisu / mazání @param time jednotka je cca 20 SPI clock, při 2 MHz 10us
    bool     WaitForReady  (const unsigned time = 3000) const;
  private:
    SpiClass  & spi;            //!< z nadřazené třídy
    GpioClass & chip_select;    //!< z nadřazené třídy
};

#endif // SERIALFLASH_H
