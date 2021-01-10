#ifndef FIFO_H
#define FIFO_H
#include "locker.h"

/** @file
 * @brief Fifo čili fronta.
 * 
 * @class Fifo
 * @brief Fifo čili fronta.
 * 
 * Fifo použité v obsluze sériového portu zkusíme napsat jako šablonu. Fakt je, že v tomto případě kód neroste.
 * Zřejmě je překladač docela inteligentní. A jde tak ukládat do fifo různá data, včetně složitých objektů.
 * Fifo je tak jednoduché, že může mít všechny metody v hlavičce, tedy default inline.
 * Je však třeba zajistit atomičnost inkrementace a dekrementace délky dat. Použita je metoda atomic
 * ze standardní knihovny. Ona totiž pravděpodobnost, že se proces v přerušení zrovna trefí do té
 * in(de)krementace je tak malá, že je problém to otestovat na selhání, takže to celkem spolehlivě funguje
 * i bez ošetření té bezpečnosti. Atomic toto udělá bezpečně na CM3/4 pomocí ldrex a strex, tj. nemusí
 * přitom zakazovat globální přerušení.
 * 
*/
template <class T, const int FIFODEPTH = 64> class Fifo {
  public:   // veřejné metody
    /// Parametr konstruktoru by měla být hloubka FIFO, ale pak by musela být dynamická alokace paměti.
    Fifo () : rdi(0), wri(0), len(0)  {};
    /// Zápis do FIFO
    /// @param  c odkaz na jeden prvek co bude zapsán
    /// @return true, pokud není plný
    bool Write (const T & c) {
      if (len < FIFODEPTH) { buf [wri++] = c; saturate (wri); len += 1; return true; }
      else return false;
    };
    /// Čtení z FIFO
    /// @param  c odkaz na jeden prvek, kam to bude načteno
    /// @return true, pokud není prázdný
    bool Read  (T & c) {
      if (len > 0) {     c = buf [rdi++];     saturate (rdi); len -= 1; return true; }
      else return false;
    };
  protected:  // chráněné metody
    /// Saturace indexu - ochrana před zápisem/čtením mimo pole dat
    /// @param index odkaz na saturovaný index
    void saturate (volatile int & index) {
      while (index >= FIFODEPTH) index -= FIFODEPTH; // FIFODEPTH obecně int
    };
  private:    // privátní data
    T            buf[FIFODEPTH];  //!< buffer na data
    volatile int rdi, wri;   //!< pomocné proměnné
    std::atomic<int>  len;   //!< pomocné proměnné
};

#endif // FIFO_H
