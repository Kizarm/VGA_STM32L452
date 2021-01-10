#ifndef BASELAYER_H
#define BASELAYER_H
#include <stdlib.h>
#include <stdint.h>

#ifdef __arm__
  #define debug(...)
#else  // ARCH_CM0
  #ifdef DEBUG
    #define debug printf
  #else  // DEBUG
    #define debug(...)
  #endif // DEBUG
#endif // ARCH_CM0
/** @file
 * @brief Bázová třída pro stack trochu obecnějšího komunikačního protokolu.
 * 
 * @class BaseLayer
 * @brief Od této třídy budeme dále odvozovat ostatní.
 * 
 * Zde je to použito jen pro spolupráci s třídou UsartClass. Jinak je to dost
 * obecná metoda jak vytvořit abstrakní stack. Není to však úplně průhledné a
 * pro programátory v čistém C dost divné. Ale funguje to a je to dobré pokud
 * potřebujeme mít třídy znovupoužitelné a není do nich nutné nijak zasahovat.
 * 
 * Použití virtuálních metod umožňuje polymorfizmus. Pokud v odvozené třídě přetížíme nějakou
 * virtuální metodu, bude se používat ta přetížená, polud ne, použije se ta virtuální.
 * Třída nemá *.cpp, všechny metody jsou jednoduché a tedy inline.
*/
class BaseLayer {
  public:
    /** Konstruktor
    */
    BaseLayer () {
      pUp   = NULL;
      pDown = NULL;
    };
    /** Virtuální metoda, přesouvající data směrem nahoru, pokud s nimi nechceme dělat něco jiného.
    @param data ukazatel na pole dat
    @param len  delka dat v bytech
    @return počet přenesených bytů
    */
    virtual uint32_t    Up   (const char* data, uint32_t len) {
      if (pUp) return pUp->Up (data, len);
      return 0;
    };
    /** Virtuální metoda, přesouvající data směrem dolů, pokud s nimi nechceme dělat něco jiného.
    @param data ukazatel na pole dat
    @param len  delka dat v bytech
    @return počet přenesených bytů
    */
    virtual uint32_t    Down (const char* data, uint32_t len) {
      if (pDown) return pDown->Down (data, len); 
      return len;
    };
    /** @brief Zřetězení stacku.
     * Tohle je vlastně to nejdůležitější. V čistém C by se musely
     * nastavovat ukazatele na callback funkce, tady je to čitší - pro uživatele neviditelné,
     * ale je to to samé.
    @param bl Třída, ležící pod, spodní
    @return Odkaz na tuto třídu (aby se to dalo řetězit)
    */
    virtual BaseLayer&  operator += (BaseLayer& bl) {
      bl.setUp (this);  // ta spodní bude volat při Up tuto třídu
      setDown  (&bl );  // a tato třída bude volat při Down tu spodní
      return *this;
    };
    /** Getter pro pDown
    @return pDown
    */
    BaseLayer* getDown (void) const { return pDown; };
  protected:
    /** Lokální setter pro pUp
    @param p Co budeme do pUp dávat
    */
    void setUp   (BaseLayer* p) { pUp   = p; };
    /** Lokální setter pro pDown
    @param p Co budeme do pDown dávat
    */
    void setDown (BaseLayer* p) { pDown = p; };
  private:
    // Ono to je vlastně oboustranně vázaný spojový seznam.
    BaseLayer*  pUp;        //!< Ukazatel na třídu, která bude dále volat Up
    BaseLayer*  pDown;      //!< Ukazatel na třídu, která bude dále volat Down
};

#endif // BASELAYER_H
