#ifndef ENDIEN_H
#define ENDIEN_H
#include <stdint.h>
/**
  @file
  @brief Pořadí bytů ve slově.
  
*/
#if __GNUC__ < 4    // Compiler test
#error "Zkontroluj nastaveni"
#endif
// Pro 16.bit musíme struktury pakovat
#define PACKSTRUCT __attribute__((packed))

#if __thumb__
  // Specificky a krátce pro danou architektutu a pokud chceme mít úplnou kontrolu.
  static inline uint32_t swab32 (uint32_t p) {
    register uint32_t t;
    asm volatile ("rev %0, %1":"=r"(t):"0"(p));
    return t;
  }
#else  //__thumb__
  // Obecně
  static inline uint32_t swab32 (uint32_t p) {
    // return __builtin_bswap32 (p); // I takto to jde, ale pro názornost:
    return ((p & 0x000000ff) << 24)
         | ((p & 0x0000ff00) <<  8)
         | ((p & 0x00ff0000) >>  8)
         | ((p & 0xff000000) >> 24);
  }
#endif //__thumb__
// Tohle nebudeme ani specifikovat pro ARM
static inline uint16_t swab16 (uint16_t p) {
  return (p << 8) | (p >> 8);
}
// Nedělá nic a ani nijak neotravuje - pouze pro kompatibilitu
static inline uint32_t nosw32 (uint32_t p) {
  return p;
}
static inline uint16_t nosw16 (uint16_t p) {
  return p;
}
// Specificky podle pořadí bytů - LE je pro ARM i X86 normální.
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  #define cpu_to_be32 swab32
  #define be32_to_cpu swab32
  #define cpu_to_le32 nosw32
  #define le32_to_cpu nosw32
  
  #define cpu_to_be16 swab16
  #define be16_to_cpu swab16
  #define cpu_to_le16 nosw16
  #define le16_to_cpu nosw16
#else
  #define cpu_to_be32 nosw32
  #define be32_to_cpu nosw32
  #define cpu_to_le32 swab32
  #define le32_to_cpu swab32
  
  #define cpu_to_be16 nosw16
  #define be16_to_cpu nosw16
  #define cpu_to_le16 swab16
  #define le16_to_cpu swab16
#endif
/**
  @class ui32be
  @brief C++ 32.bit data v BIG Endien.
  @class ui32le
  @brief C++ 32.bit data v LITTLE Endien.
  @class ui16be
  @brief C++ 16.bit data v BIG Endien.
  @class ui16le
  @brief C++ 16.bit data v LITTLE Endien.
*/
class ui32be {
  public:
    /// Nastavení hodnoty
    /// @par p uint32_t hodnota
    void      set (uint32_t p) {num  = cpu_to_be32 (p);   };
    /// Zjištění hodnoty
    /// @return uint32_t hodnota
    uint32_t  get (void)       {return be32_to_cpu (num); };
  private:
    /// Vlastní data uint32_t - k nim se přímo nedostaneme, jsou privátní
    uint32_t  num;
}PACKSTRUCT;

class ui32le {
  public:
    void      set (uint32_t p) {num  = cpu_to_le32 (p);   };
    uint32_t  get (void)       {return le32_to_cpu (num); };
  private:
    uint32_t  num;
}PACKSTRUCT;
/* *******************************************************/
class ui16be {
  public:
    void      set (uint16_t p) {num  = cpu_to_be16 (p);   };
    uint16_t  get (void)       {return be16_to_cpu (num); };
  private:
    uint16_t  num;
}PACKSTRUCT;

class ui16le {
  public:
    void      set (uint16_t p) {num  = cpu_to_le16 (p);   };
    uint16_t  get (void)       {return le16_to_cpu (num); };
  private:
    uint16_t  num;
}PACKSTRUCT;

#endif // ENDIEN_H
