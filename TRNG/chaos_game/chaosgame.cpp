#include "chaosgame.h"

static const Fractal<4u> Barnsley = {
  {
    [] (const FPoint & p) -> const FPoint {
      const Matrix m (0.0f, 0.0f, 0.0f, 0.16f);
      return m * p;
    },
    [] (const FPoint & p) -> const FPoint {
      const Matrix m (0.85f, 0.04f, -0.04f, 0.85f);
      const FPoint q (0.0f, 1.6f);
      return m * p + q;
    },
    [] (const FPoint & p) -> const FPoint {
      const Matrix m (0.20f, -0.26f, 0.23f, 0.22f);
      const FPoint q (0.0f, 1.6f);
      return m * p + q;
    },
    [] (const FPoint & p) -> const FPoint {
      const Matrix m (-0.15f, 0.28f, 0.26f, 0.24f);
      const FPoint q (0.0f, 0.44f);
      return m * p + q;
    }
  },
  {
    0.01f, 0.85f, 0.07f, 0.07f
  }
};
static const Fractal<3u> Sierpinski = {
  {
    [] (const FPoint & p) -> const FPoint {
      const FPoint v (0.0f, 10.0f);
      return (p + v) * 0.5f;
    },
    [] (const FPoint & p) -> const FPoint {
      const FPoint v (-5.77f, 0.0f);
      return (p + v) * 0.5f;
    },
    [] (const FPoint & p) -> const FPoint {
      const FPoint v (+5.77f, 0.0f);
      return (p + v) * 0.5f;
    }
  },
  {
    0.3333f, 0.3333f, 0.3334f
  }
};
static const real normalize (const uint32_t p) {
  constexpr uint32_t m = 0xFFFFFFFFu;
  const real r = (real) p / (real) m;
  return r;
}
static void delay (const unsigned dly) {
  volatile unsigned n = dly;
  while (n--) {
    asm volatile ("wfi");
  }
}

static const float exp_table [] = {
  1.002251f, 1.004507f, 1.009035f, 1.018152f, 1.036633f, 1.074608f, 1.154782f, 1.333521f, 1.778279f, 3.162278f, 10.000000f, 100.000000f, 
};
static const unsigned iexp (const unsigned x) {
  float y = 1.0f;
  for (unsigned n=0; n<12; n++) {
    if ((1u << n) & x) {
      y *= exp_table [n];
    }
  }
  return (unsigned) y;
}

ChaosGame::ChaosGame() : LedGreen(GpioPortA, 10), sync(), trng(), adc(),
  // vyuzijeme vlastnosti Cortex-M4 - Bit banding, zjednodusi adresaci
  pVideoBit (reinterpret_cast<uint32_t * const>(0x22000000u + 32u * (reinterpret_cast<uint32_t>(sync.getRAM()) - 0x20000000u))),
  next (), time(10000u) {
}
void ChaosGame::Init() {
  adc.Init();
  const real np = normalize (trng.Read());
  if (np < 0.5f) pict = SIERPINSKI;
  else           pict = BARNSLEY;
}
void ChaosGame::Pass() {
  +LedGreen;
  const real np = normalize (trng.Read());
  FPoint pt;
  switch (pict) {
    case SIERPINSKI: pt = Sierpinski.transformation(next, np); break;
    case BARNSLEY  : pt = Barnsley  .transformation(next, np); break;
  }
  const real     z = 60.0f;
  const unsigned x = (unsigned) (z * pt.x + 400.5f);
  const unsigned y = (unsigned) (600.5f - z * pt.y);
  at (x, y) = 1u;
  
  next = pt;
  
  uint16_t adcv;
  if (adc.get (adcv)) {
    time = iexp (4096u - adcv);
  }
  
  -LedGreen;
  delay (time);
}
