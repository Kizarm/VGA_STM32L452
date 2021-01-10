#ifndef INTELHEX_H
#define INTELHEX_H
#include <stdint.h>

/// Maximální délka rekordu
static const unsigned MaxHexRecord = 64;

enum RowTypes : uint8_t {
  // defined by Intel
  dataRecord = 0, //!< datový paket
  eofRecord,      //!< konec dat
  esaRecord,  //!< X86/16.bit CS/IP počáteční adresa
  ssaRecord,  //!< X86/16.bit CS/IP startovací adresa
  elaRecord,  //!< počáteční  adresa 32-bit (horních 16.bit)
  slaRecord,  //!< startovací adresa 32-bit
  // ... defined by BT protocol
  // všechny budou používat jen offset pro přenos dat.
  ackRecord,  //!< offset - představuje offset předchozích dat
  nakRecord,  //!< stejně jako předchozí
  reqRecord,  //!< Request for data - offset značí odkud vzhledem k počáteční adrese
  ersRecord,  //!< Erase - po blocích, offset je číslo bloku (závisí na typu flash)
  badRecord,  //!< použito pro detekci chyb
};
/// @enum RowTypes
/// Enumerace datových typů Intel-hex formátu

/**
 * @class IntelHex
 * @brief Hepler pro parsování a vytváření paketů Intel HEX formátu.
 * 
 * Prvních 6 typů (#RowTypes) je definováno ve specifikaci např.
 * <a href="https://cs.wikipedia.org/wiki/Intel_HEX">zde</a>. A protože je tam dost volného
 * místa pro rozšíření, jsou zde dodefinovány další typy použité pro komunikaci. Je to tak
 * jednodušší než vymýšlet nějaký vlastní formát pro potvrzování a jiné. Protokol je znakový,
 * poměrně robustní, na druhou stranu má dost velku režii.
 * 
 * Ukázalo sem že úzkým hrdlem komunikace je čekání na potvrzování, takže se režie poněkud zastírá,
 * ale potvrzování být musí pokud to má trochu spolehlivě fungovat.
 * */

class IntelHex {
  public:
    IntelHex();
    /**
     * @brief Základní funkce parseru
     * 
     * @param data vstupní řádek (paket)
     * @param len jeho délka (např. strlen(data))
     * @return RowTypes - to se pak zpracovává dál v nadřazené části např. LinkProtocol
     */
    RowTypes parseRecord (const char * data, const unsigned len);
    /**
     * @brief Nastavení adresy
     * 
     * Buď počáteční nebo starovací.
     * 
     * @param adr odkaz na proměnnou, kam bude adresa nastavena
     */
    void getAddress (uint32_t & adr);
    /**
     * @brief Nastavení délky
     * @param len odkaz na proměnnou, kam bude délka nastavena
     */
    void getLenght  (uint32_t & len);
    /**
     * @brief Nastavení ofsetu
     * @param ofs odkaz na proměnnou, kam bude ofset nastaven
     */
    void getOffset  (uint32_t & ofs);
    /**
     * @brief Zápis dat z příchozího dataRecord
     * 
     * @param data kam se zapíší
     */
    void WriteData  (uint8_t * data);
    /**
     * @brief Posun ofsetu kvůli udržení konzistence
     * 
     * @param len o kolik se má posunout
     */
    void AddOffset  (uint32_t   len);
    
    /**
     * @brief Vytvoření dataRecord
     * 
     * @param string kam se record zapíše
     * @param data pure data rekordu
     * @param len a jejich délka
     * @return uint32_t kolik bylo zapsáno do string
     */
    uint32_t DataRecord (char * string, const uint8_t * data, const uint32_t len);
    /**
     * @brief Vytvoření elaRecord
     * 
     * @param string kam se record zapíše
     * @param adr počáteční adresa
     * @return uint32_t kolik znaků bylo zapsáno do string
     */
    uint32_t ElaRecord  (char * string, const uint32_t adr);
    /**
     * @brief Vytvoření slaRecord
     * 
     * @param string kam se record zapíše
     * @param adr startovací adresa
     * @return uint32_t kolik znaků bylo zapsáno do string
     */
    uint32_t SlaRecord  (char * string, const uint32_t adr);
    /**
     * @brief Vytvoření eofRecord
     * 
     * @param string  kam se record zapíše
     * @return uint32_t kolik znaků bylo zapsáno do string
     */
    uint32_t EofRecord  (char * string);
    
    /**
     * @brief Vytvoření BT rekordů ackRecord, nakRecord, reqRecord, ersRecord
     * 
     * @param string   kam se record zapíše
     * @param t definuj typ rekordu
     * @return uint32_t kolik znaků bylo zapsáno do string
     */
    uint32_t BTxRecord  (char * string, RowTypes t = ackRecord);
    /// pomocná funkce
    bool CompareAckOffsset ();
    /// pomocná funkce    
    uint8_t * getDataRow (uint32_t & ofs, uint32_t & len);
  protected:
  private:
    uint32_t address;
    uint32_t offset;
    uint32_t lenght;
    uint32_t total_lenght;
    uint32_t ackofs;
    uint8_t  chunk [MaxHexRecord];
};

#endif // INTELHEX_H
