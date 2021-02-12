#ifndef ADCCLASS_H
#define ADCCLASS_H
#include <stdint.h>
#include "fifo.h"

/** @file
 *  @brief A/D převodník.
 * */

/**
 * @class AdcClass
 * @brief A/D převodník.
 * 
 * ADC v STM32L4 je poměrně divný. Dost se toho musí zapnout, aby vůbec něco dělal.
 * */

enum ADC_CHANNELS {
  V2_VSENSE = 0,
  V3_VSENSE,
  VPROC_VSENSE,       // napětí na procesoru

  ADC_MAXCHANNELS,    // interní konstanta - počet kanálů
};

class AdcClass {
  public:
    AdcClass() : ring() {
    };
    /**
     * @brief Inicializace ADC.
     * 
     * Včetně vstupů a OPAMP.
     * 
     */
    void     Init    ();
    // uint16_t Voltage (ADC_CHANNELS ch);
    bool get (uint16_t & data) {
      return ring.Read (data);
    }
  public: // UNUSABLE
    void drq ();                        //!< obsluha přerušení, interní metoda, ale musí mít public atribut
  private:
    Fifo<uint16_t, 4> ring;
    uint16_t buffer [ADC_MAXCHANNELS];  //!< data
};

#endif // ADCCLASS_H
