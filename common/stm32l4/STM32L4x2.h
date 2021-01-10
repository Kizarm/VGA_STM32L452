#ifndef STM32L4x2_GENERATED_HEADER
#define STM32L4x2_GENERATED_HEADER
#include <stdint.h>

#define __RO volatile const
#define __WO volatile
#define __RW volatile
#define __ROB const
#define __WOB
#define __RWB

/*
name = "STM32L4x2"
version = "1.6"
description = "STM32L4x2"
addressUnitBits = "8"
width = "32"
size = "0x20"
resetValue = "0x0"
resetMask = "0xFFFFFFFF"
cpu:
  name = "CM4"
  revision = "r1p0"
  endian = "little"
  mpuPresent = "false"
  fpuPresent = "false"
  nvicPrioBits = "3"
  vendorSystickConfig = "false"
*/

struct TIM_CR1_s { /*!< control register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CEN              :  1; /*!< Ofs=0, w=1 Counter enable */
      __RWB uint32_t UDIS             :  1; /*!< Ofs=1, w=1 Update disable */
      __RWB uint32_t URS              :  1; /*!< Ofs=2, w=1 Update request source */
      __RWB uint32_t OPM              :  1; /*!< Ofs=3, w=1 One-pulse mode */
      __RWB uint32_t DIR              :  1; /*!< Ofs=4, w=1 Direction */
      __RWB uint32_t CMS              :  2; /*!< Ofs=5, w=2 Center-aligned mode selection */
      __RWB uint32_t ARPE             :  1; /*!< Ofs=7, w=1 Auto-reload preload enable */
      __RWB uint32_t CKD              :  2; /*!< Ofs=8, w=2 Clock division */
            uint32_t unused0          : 22;
    } B;
  } ;
#ifdef __cplusplus
  TIM_CR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CR2_s { /*!< control register 2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t CCDS             :  1; /*!< Ofs=3, w=1 Capture/compare DMA selection */
      __RWB uint32_t MMS              :  3; /*!< Ofs=4, w=3 Master mode selection */
      __RWB uint32_t TI1S             :  1; /*!< Ofs=7, w=1 TI1 selection */
            uint32_t unused1          : 24;
    } B;
  } ;
#ifdef __cplusplus
  TIM_CR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_SMCR_s { /*!< slave mode control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SMS              :  3; /*!< Ofs=0, w=3 Slave mode selection */
            uint32_t unused0          :  1;
      __RWB uint32_t TS               :  3; /*!< Ofs=4, w=3 Trigger selection */
      __RWB uint32_t MSM              :  1; /*!< Ofs=7, w=1 Master/Slave mode */
      __RWB uint32_t ETF              :  4; /*!< Ofs=8, w=4 External trigger filter */
      __RWB uint32_t ETPS             :  2; /*!< Ofs=12, w=2 External trigger prescaler */
      __RWB uint32_t ECE              :  1; /*!< Ofs=14, w=1 External clock enable */
      __RWB uint32_t ETP              :  1; /*!< Ofs=15, w=1 External trigger polarity */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  TIM_SMCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_SMCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_SMCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_DIER_s { /*!< DMA/Interrupt enable register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t UIE              :  1; /*!< Ofs=0, w=1 Update interrupt enable */
      __RWB uint32_t CC1IE            :  1; /*!< Ofs=1, w=1 Capture/Compare 1 interrupt enable */
      __RWB uint32_t CC2IE            :  1; /*!< Ofs=2, w=1 Capture/Compare 2 interrupt enable */
      __RWB uint32_t CC3IE            :  1; /*!< Ofs=3, w=1 Capture/Compare 3 interrupt enable */
      __RWB uint32_t CC4IE            :  1; /*!< Ofs=4, w=1 Capture/Compare 4 interrupt enable */
            uint32_t unused0          :  1;
      __RWB uint32_t TIE              :  1; /*!< Ofs=6, w=1 Trigger interrupt enable */
            uint32_t unused1          :  1;
      __RWB uint32_t UDE              :  1; /*!< Ofs=8, w=1 Update DMA request enable */
      __RWB uint32_t CC1DE            :  1; /*!< Ofs=9, w=1 Capture/Compare 1 DMA request enable */
      __RWB uint32_t CC2DE            :  1; /*!< Ofs=10, w=1 Capture/Compare 2 DMA request enable */
      __RWB uint32_t CC3DE            :  1; /*!< Ofs=11, w=1 Capture/Compare 3 DMA request enable */
      __RWB uint32_t CC4DE            :  1; /*!< Ofs=12, w=1 Capture/Compare 4 DMA request enable */
      __RWB uint32_t COMDE            :  1; /*!< Ofs=13, w=1 COM DMA request enable */
      __RWB uint32_t TDE              :  1; /*!< Ofs=14, w=1 Trigger DMA request enable */
            uint32_t unused2          : 17;
    } B;
  } ;
#ifdef __cplusplus
  TIM_DIER_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_DIER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_DIER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_SR_s { /*!< status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t UIF              :  1; /*!< Ofs=0, w=1 Update interrupt flag */
      __RWB uint32_t CC1IF            :  1; /*!< Ofs=1, w=1 Capture/compare 1 interrupt flag */
      __RWB uint32_t CC2IF            :  1; /*!< Ofs=2, w=1 Capture/Compare 2 interrupt flag */
      __RWB uint32_t CC3IF            :  1; /*!< Ofs=3, w=1 Capture/Compare 3 interrupt flag */
      __RWB uint32_t CC4IF            :  1; /*!< Ofs=4, w=1 Capture/Compare 4 interrupt flag */
            uint32_t unused0          :  1;
      __RWB uint32_t TIF              :  1; /*!< Ofs=6, w=1 Trigger interrupt flag */
            uint32_t unused1          :  2;
      __RWB uint32_t CC1OF            :  1; /*!< Ofs=9, w=1 Capture/Compare 1 overcapture flag */
      __RWB uint32_t CC2OF            :  1; /*!< Ofs=10, w=1 Capture/compare 2 overcapture flag */
      __RWB uint32_t CC3OF            :  1; /*!< Ofs=11, w=1 Capture/Compare 3 overcapture flag */
      __RWB uint32_t CC4OF            :  1; /*!< Ofs=12, w=1 Capture/Compare 4 overcapture flag */
            uint32_t unused2          : 19;
    } B;
  } ;
#ifdef __cplusplus
  TIM_SR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_SR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_SR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_EGR_s { /*!< event generation register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t UG               :  1; /*!< Ofs=0, w=1 Update generation */
      __WOB uint32_t CC1G             :  1; /*!< Ofs=1, w=1 Capture/compare 1 generation */
      __WOB uint32_t CC2G             :  1; /*!< Ofs=2, w=1 Capture/compare 2 generation */
      __WOB uint32_t CC3G             :  1; /*!< Ofs=3, w=1 Capture/compare 3 generation */
      __WOB uint32_t CC4G             :  1; /*!< Ofs=4, w=1 Capture/compare 4 generation */
            uint32_t unused0          :  1;
      __WOB uint32_t TG               :  1; /*!< Ofs=6, w=1 Trigger generation */
            uint32_t unused1          : 25;
    } B;
  } ;
#ifdef __cplusplus
  TIM_EGR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    TIM_EGR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCMR1_Output_s { /*!< capture/compare mode register 1 (output mode) */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CC1S             :  2; /*!< Ofs=0, w=2 Capture/Compare 1 selection */
      __RWB uint32_t OC1FE            :  1; /*!< Ofs=2, w=1 Output compare 1 fast enable */
      __RWB uint32_t OC1PE            :  1; /*!< Ofs=3, w=1 Output compare 1 preload enable */
      __RWB uint32_t OC1M             :  3; /*!< Ofs=4, w=3 Output compare 1 mode */
      __RWB uint32_t OC1CE            :  1; /*!< Ofs=7, w=1 Output compare 1 clear enable */
      __RWB uint32_t CC2S             :  2; /*!< Ofs=8, w=2 Capture/Compare 2 selection */
      __RWB uint32_t OC2FE            :  1; /*!< Ofs=10, w=1 Output compare 2 fast enable */
      __RWB uint32_t OC2PE            :  1; /*!< Ofs=11, w=1 Output compare 2 preload enable */
      __RWB uint32_t OC2M             :  3; /*!< Ofs=12, w=3 Output compare 2 mode */
      __RWB uint32_t OC2CE            :  1; /*!< Ofs=15, w=1 Output compare 2 clear enable */
      __RWB uint32_t OC1M3            :  1;
            uint32_t unused0          :  7;
      __RWB uint32_t OC2M3            :  1;
            uint32_t unused1          :  7;
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCMR1_Output_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCMR1_Output_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCMR1_Output_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCMR1_Input_s { /*!< capture/compare mode register 1 (input mode) */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CC1S             :  2; /*!< Ofs=0, w=2 Capture/Compare 1 selection */
      __RWB uint32_t IC1PSC           :  2; /*!< Ofs=2, w=2 Input capture 1 prescaler */
      __RWB uint32_t IC1F             :  4; /*!< Ofs=4, w=4 Input capture 1 filter */
      __RWB uint32_t CC2S             :  2; /*!< Ofs=8, w=2 Capture/compare 2 selection */
      __RWB uint32_t IC2PSC           :  2; /*!< Ofs=10, w=2 Input capture 2 prescaler */
      __RWB uint32_t IC2F             :  4; /*!< Ofs=12, w=4 Input capture 2 filter */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCMR1_Input_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCMR1_Input_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCMR1_Input_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCMR2_Input_s { /*!< capture/compare mode register 2 (input mode) */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CC3S             :  2; /*!< Ofs=0, w=2 Capture/Compare 3 selection */
      __RWB uint32_t IC3PSC           :  2; /*!< Ofs=2, w=2 Input capture 3 prescaler */
      __RWB uint32_t IC3F             :  4; /*!< Ofs=4, w=4 Input capture 3 filter */
      __RWB uint32_t CC4S             :  2; /*!< Ofs=8, w=2 Capture/Compare 4 selection */
      __RWB uint32_t IC4PSC           :  2; /*!< Ofs=10, w=2 Input capture 4 prescaler */
      __RWB uint32_t IC4F             :  4; /*!< Ofs=12, w=4 Input capture 4 filter */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCMR2_Input_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCMR2_Input_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCMR2_Input_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCMR2_Output_s { /*!< capture/compare mode register 2 (output mode) */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CC3S             :  2; /*!< Ofs=0, w=2 Capture/Compare 3 selection */
      __RWB uint32_t OC3FE            :  1; /*!< Ofs=2, w=1 Output compare 3 fast enable */
      __RWB uint32_t OC3PE            :  1; /*!< Ofs=3, w=1 Output compare 3 preload enable */
      __RWB uint32_t OC3M             :  3; /*!< Ofs=4, w=3 Output compare 3 mode */
      __RWB uint32_t OC3CE            :  1; /*!< Ofs=7, w=1 Output compare 3 clear enable */
      __RWB uint32_t CC4S             :  2; /*!< Ofs=8, w=2 Capture/Compare 4 selection */
      __RWB uint32_t OC4FE            :  1; /*!< Ofs=10, w=1 Output compare 4 fast enable */
      __RWB uint32_t OC4PE            :  1; /*!< Ofs=11, w=1 Output compare 4 preload enable */
      __RWB uint32_t OC4M             :  3; /*!< Ofs=12, w=3 Output compare 4 mode */
      __RWB uint32_t OC4CE            :  1; /*!< Ofs=15, w=1 Output compare 4 clear enable */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCMR2_Output_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCMR2_Output_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCMR2_Output_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCER_s { /*!< capture/compare enable register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CC1E             :  1; /*!< Ofs=0, w=1 Capture/Compare 1 output enable */
      __RWB uint32_t CC1P             :  1; /*!< Ofs=1, w=1 Capture/Compare 1 output Polarity */
            uint32_t unused0          :  1;
      __RWB uint32_t CC1NP            :  1; /*!< Ofs=3, w=1 Capture/Compare 1 output Polarity */
      __RWB uint32_t CC2E             :  1; /*!< Ofs=4, w=1 Capture/Compare 2 output enable */
      __RWB uint32_t CC2P             :  1; /*!< Ofs=5, w=1 Capture/Compare 2 output Polarity */
            uint32_t unused1          :  1;
      __RWB uint32_t CC2NP            :  1; /*!< Ofs=7, w=1 Capture/Compare 2 output Polarity */
      __RWB uint32_t CC3E             :  1; /*!< Ofs=8, w=1 Capture/Compare 3 output enable */
      __RWB uint32_t CC3P             :  1; /*!< Ofs=9, w=1 Capture/Compare 3 output Polarity */
            uint32_t unused2          :  1;
      __RWB uint32_t CC3NP            :  1; /*!< Ofs=11, w=1 Capture/Compare 3 output Polarity */
      __RWB uint32_t CC4E             :  1; /*!< Ofs=12, w=1 Capture/Compare 4 output enable */
      __RWB uint32_t CC4P             :  1; /*!< Ofs=13, w=1 Capture/Compare 3 output Polarity */
            uint32_t unused3          :  1;
      __RWB uint32_t CC4NP            :  1; /*!< Ofs=15, w=1 Capture/Compare 4 output Polarity */
            uint32_t unused4          : 16;
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCER_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CNT_s { /*!< counter */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CNT_L            : 16; /*!< Ofs=0, w=16 Low counter value */
      __RWB uint32_t CNT_H            : 16; /*!< Ofs=16, w=16 High counter value (TIM2 only) */
    } B;
  } ;
#ifdef __cplusplus
  TIM_CNT_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CNT_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CNT_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_ARR_s { /*!< auto-reload register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ARR_L            : 16; /*!< Ofs=0, w=16 Low Auto-reload value */
      __RWB uint32_t ARR_H            : 16; /*!< Ofs=16, w=16 High Auto-reload value (TIM2 only) */
    } B;
  } ;
#ifdef __cplusplus
  TIM_ARR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_ARR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_ARR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCR1_s { /*!< capture/compare register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CCR1_L           : 16; /*!< Ofs=0, w=16 Low Capture/Compare 1 value */
      __RWB uint32_t CCR1_H           : 16; /*!< Ofs=16, w=16 High Capture/Compare 1 value (TIM2 only) */
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCR2_s { /*!< capture/compare register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CCR2_L           : 16; /*!< Ofs=0, w=16 Low Capture/Compare 2 value */
      __RWB uint32_t CCR2_H           : 16; /*!< Ofs=16, w=16 High Capture/Compare 2 value (TIM2 only) */
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCR3_s { /*!< capture/compare register 3 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CCR3_L           : 16; /*!< Ofs=0, w=16 Low Capture/Compare value */
      __RWB uint32_t CCR3_H           : 16; /*!< Ofs=16, w=16 High Capture/Compare value (TIM2 only) */
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCR3_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCR3_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCR3_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCR4_s { /*!< capture/compare register 4 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CCR4_L           : 16; /*!< Ofs=0, w=16 Low Capture/Compare value */
      __RWB uint32_t CCR4_H           : 16; /*!< Ofs=16, w=16 High Capture/Compare value (TIM2 only) */
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCR4_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCR4_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCR4_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_BDTR_s { /*!< break and dead-time register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DTG              :  8; /*!< Ofs=0, w=8 Dead-time generator setup */
      __RWB uint32_t LOCK             :  2; /*!< Ofs=8, w=2 Lock configuration */
      __RWB uint32_t OSSI             :  1; /*!< Ofs=10, w=1 Off-state selection for Idle mode */
      __RWB uint32_t OSSR             :  1; /*!< Ofs=11, w=1 Off-state selection for Run mode */
      __RWB uint32_t BKE              :  1; /*!< Ofs=12, w=1 Break enable */
      __RWB uint32_t BKP              :  1; /*!< Ofs=13, w=1 Break polarity */
      __RWB uint32_t AOE              :  1; /*!< Ofs=14, w=1 Automatic output enable */
      __RWB uint32_t MOE              :  1; /*!< Ofs=15, w=1 Main output enable */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  TIM_BDTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_BDTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_BDTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_DCR_s { /*!< DMA control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DBA              :  5; /*!< Ofs=0, w=5 DMA base address */
            uint32_t unused0          :  3;
      __RWB uint32_t DBL              :  5; /*!< Ofs=8, w=5 DMA burst length */
            uint32_t unused1          : 19;
    } B;
  } ;
#ifdef __cplusplus
  TIM_DCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_DCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_DCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_OR_s { /*!< TIM2 option register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ETR_RMP          :  3; /*!< Ofs=0, w=3 Timer2 ETR remap */
      __RWB uint32_t TI4_RMP          :  2; /*!< Ofs=3, w=2 Internal trigger */
            uint32_t unused0          : 27;
    } B;
  } ;
#ifdef __cplusplus
  TIM_OR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_OR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_OR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_OR1_s { /*!< DMA address for full transfer */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ETR_ADC1_RMP     :  2; /*!< Ofs=0, w=2 External trigger remap on ADC1 analog watchdog */
      __RWB uint32_t ETR_ADC3_RMP     :  2; /*!< Ofs=2, w=2 External trigger remap on ADC3 analog watchdog */
      __RWB uint32_t TI1_RMP          :  1; /*!< Ofs=4, w=1 Input Capture 1 remap */
            uint32_t unused0          : 27;
    } B;
  } ;
#ifdef __cplusplus
  TIM_OR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_OR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_OR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCMR3_Output_s { /*!< capture/compare mode register 2 (output mode) */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  2;
      __RWB uint32_t OC5FE            :  1; /*!< Ofs=2, w=1 Output compare 5 fast enable */
      __RWB uint32_t OC5PE            :  1; /*!< Ofs=3, w=1 Output compare 5 preload enable */
      __RWB uint32_t OC5M             :  3; /*!< Ofs=4, w=3 Output compare 5 mode */
      __RWB uint32_t OC5CE            :  1; /*!< Ofs=7, w=1 Output compare 5 clear enable */
            uint32_t unused1          :  2;
      __RWB uint32_t OC6FE            :  1; /*!< Ofs=10, w=1 Output compare 6 fast enable */
      __RWB uint32_t OC6PE            :  1; /*!< Ofs=11, w=1 Output compare 6 preload enable */
      __RWB uint32_t OC6M             :  3; /*!< Ofs=12, w=3 Output compare 6 mode */
      __RWB uint32_t OC6CE            :  1; /*!< Ofs=15, w=1 Output compare 6 clear enable */
      __RWB uint32_t OC5M_bit3        :  3; /*!< Ofs=16, w=3 Output Compare 5 mode bit 3 */
            uint32_t unused2          :  5;
      __RWB uint32_t OC6M_bit3        :  1; /*!< Ofs=24, w=1 Output Compare 6 mode bit 3 */
            uint32_t unused3          :  7;
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCMR3_Output_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCMR3_Output_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCMR3_Output_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_CCR5_s { /*!< capture/compare register 4 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CCR5             : 16; /*!< Ofs=0, w=16 Capture/Compare value */
            uint32_t unused0          : 13;
      __RWB uint32_t GC5C1            :  1; /*!< Ofs=29, w=1 Group Channel 5 and Channel 1 */
      __RWB uint32_t GC5C2            :  1; /*!< Ofs=30, w=1 Group Channel 5 and Channel 2 */
      __RWB uint32_t GC5C3            :  1; /*!< Ofs=31, w=1 Group Channel 5 and Channel 3 */
    } B;
  } ;
#ifdef __cplusplus
  TIM_CCR5_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TIM_CCR5_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_CCR5_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_OR2_s { /*!< DMA address for full transfer */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BKINE            :  1; /*!< Ofs=0, w=1 BRK BKIN input enable */
      __RWB uint32_t BKCMP1E          :  1; /*!< Ofs=1, w=1 BRK COMP1 enable */
      __RWB uint32_t BKCMP2E          :  1; /*!< Ofs=2, w=1 BRK COMP2 enable */
            uint32_t unused0          :  5;
      __RWB uint32_t BKDFBK0E         :  1; /*!< Ofs=8, w=1 BRK DFSDM_BREAK0 enable */
      __RWB uint32_t BKINP            :  1; /*!< Ofs=9, w=1 BRK BKIN input polarity */
      __RWB uint32_t BKCMP1P          :  1; /*!< Ofs=10, w=1 BRK COMP1 input polarity */
      __RWB uint32_t BKCMP2P          :  1; /*!< Ofs=11, w=1 BRK COMP2 input polarity */
            uint32_t unused1          :  2;
      __RWB uint32_t ETRSEL           :  3; /*!< Ofs=14, w=3 ETR source selection */
            uint32_t unused2          : 15;
    } B;
  } ;
#ifdef __cplusplus
  TIM_OR2_s(): R(0x00000001u) {};
  template<typename F> void modify (F f) volatile {
    TIM_OR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_OR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TIM_OR3_s { /*!< DMA address for full transfer */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BK2INE           :  1; /*!< Ofs=0, w=1 BRK2 BKIN input enable */
      __RWB uint32_t BK2CMP1E         :  1; /*!< Ofs=1, w=1 BRK2 COMP1 enable */
      __RWB uint32_t BK2CMP2E         :  1; /*!< Ofs=2, w=1 BRK2 COMP2 enable */
            uint32_t unused0          :  5;
      __RWB uint32_t BK2DFBK0E        :  1; /*!< Ofs=8, w=1 BRK2 DFSDM_BREAK0 enable */
      __RWB uint32_t BK2INP           :  1; /*!< Ofs=9, w=1 BRK2 BKIN input polarity */
      __RWB uint32_t BK2CMP1P         :  1; /*!< Ofs=10, w=1 BRK2 COMP1 input polarity */
      __RWB uint32_t BK2CMP2P         :  1; /*!< Ofs=11, w=1 BRK2 COMP2 input polarity */
            uint32_t unused1          : 20;
    } B;
  } ;
#ifdef __cplusplus
  TIM_OR3_s(): R(0x00000001u) {};
  template<typename F> void modify (F f) volatile {
    TIM_OR3_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TIM_OR3_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_CR_s { /*!< control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LCDEN            :  1; /*!< Ofs=0, w=1 LCD controller enable */
      __RWB uint32_t VSEL             :  1; /*!< Ofs=1, w=1 Voltage source selection */
      __RWB uint32_t DUTY             :  3; /*!< Ofs=2, w=3 Duty selection */
      __RWB uint32_t BIAS             :  2; /*!< Ofs=5, w=2 Bias selector */
      __RWB uint32_t MUX_SEG          :  1; /*!< Ofs=7, w=1 Mux segment enable */
      __RWB uint32_t BUFEN            :  1; /*!< Ofs=8, w=1 Voltage output buffer enable */
            uint32_t unused0          : 23;
    } B;
  } ;
#ifdef __cplusplus
  LCD_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LCD_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_FCR_s { /*!< frame control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t HD               :  1; /*!< Ofs=0, w=1 High drive enable */
      __RWB uint32_t SOFIE            :  1; /*!< Ofs=1, w=1 Start of frame interrupt enable */
            uint32_t unused0          :  1;
      __RWB uint32_t UDDIE            :  1; /*!< Ofs=3, w=1 Update display done interrupt enable */
      __RWB uint32_t PON              :  3; /*!< Ofs=4, w=3 Pulse ON duration */
      __RWB uint32_t DEAD             :  3; /*!< Ofs=7, w=3 Dead time duration */
      __RWB uint32_t CC               :  3; /*!< Ofs=10, w=3 Contrast control */
      __RWB uint32_t BLINKF           :  3; /*!< Ofs=13, w=3 Blink frequency selection */
      __RWB uint32_t BLINK            :  2; /*!< Ofs=16, w=2 Blink mode selection */
      __RWB uint32_t DIV              :  4; /*!< Ofs=18, w=4 DIV clock divider */
      __RWB uint32_t PS               :  4; /*!< Ofs=22, w=4 PS 16-bit prescaler */
            uint32_t unused1          :  6;
    } B;
  } ;
#ifdef __cplusplus
  LCD_FCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LCD_FCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_FCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_SR_s { /*!< status register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t ENS              :  1; /*!< Ofs=0, w=1 ENS */
      __ROB uint32_t SOF              :  1; /*!< Ofs=1, w=1 Start of frame flag */
      __WOB uint32_t UDR              :  1; /*!< Ofs=2, w=1 Update display request */
      __ROB uint32_t UDD              :  1; /*!< Ofs=3, w=1 Update Display Done */
      __ROB uint32_t RDY              :  1; /*!< Ofs=4, w=1 Ready flag */
      __ROB uint32_t FCRSF            :  1; /*!< Ofs=5, w=1 LCD Frame Control Register Synchronization flag */
            uint32_t unused0          : 26;
    } B;
  } ;
#ifdef __cplusplus
  LCD_SR_s(): R(0x00000020u) {};
  template<typename F> void modify (F f) volatile {
    LCD_SR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_SR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_CLR_s { /*!< clear register */
  union {
      __WOB uint32_t R;
    struct {
            uint32_t unused0          :  1;
      __WOB uint32_t SOFC             :  1; /*!< Ofs=1, w=1 Start of frame flag clear */
            uint32_t unused1          :  1;
      __WOB uint32_t UDDC             :  1; /*!< Ofs=3, w=1 Update display done clear */
            uint32_t unused2          : 28;
    } B;
  } ;
#ifdef __cplusplus
  LCD_CLR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    LCD_CLR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_RAM_COM0_s { /*!< display memory */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t S00              :  1; /*!< Ofs=0, w=1 S00 */
      __RWB uint32_t S01              :  1; /*!< Ofs=1, w=1 S01 */
      __RWB uint32_t S02              :  1; /*!< Ofs=2, w=1 S02 */
      __RWB uint32_t S03              :  1; /*!< Ofs=3, w=1 S03 */
      __RWB uint32_t S04              :  1; /*!< Ofs=4, w=1 S04 */
      __RWB uint32_t S05              :  1; /*!< Ofs=5, w=1 S05 */
      __RWB uint32_t S06              :  1; /*!< Ofs=6, w=1 S06 */
      __RWB uint32_t S07              :  1; /*!< Ofs=7, w=1 S07 */
      __RWB uint32_t S08              :  1; /*!< Ofs=8, w=1 S08 */
      __RWB uint32_t S09              :  1; /*!< Ofs=9, w=1 S09 */
      __RWB uint32_t S10              :  1; /*!< Ofs=10, w=1 S10 */
      __RWB uint32_t S11              :  1; /*!< Ofs=11, w=1 S11 */
      __RWB uint32_t S12              :  1; /*!< Ofs=12, w=1 S12 */
      __RWB uint32_t S13              :  1; /*!< Ofs=13, w=1 S13 */
      __RWB uint32_t S14              :  1; /*!< Ofs=14, w=1 S14 */
      __RWB uint32_t S15              :  1; /*!< Ofs=15, w=1 S15 */
      __RWB uint32_t S16              :  1; /*!< Ofs=16, w=1 S16 */
      __RWB uint32_t S17              :  1; /*!< Ofs=17, w=1 S17 */
      __RWB uint32_t S18              :  1; /*!< Ofs=18, w=1 S18 */
      __RWB uint32_t S19              :  1; /*!< Ofs=19, w=1 S19 */
      __RWB uint32_t S20              :  1; /*!< Ofs=20, w=1 S20 */
      __RWB uint32_t S21              :  1; /*!< Ofs=21, w=1 S21 */
      __RWB uint32_t S22              :  1; /*!< Ofs=22, w=1 S22 */
      __RWB uint32_t S23              :  1; /*!< Ofs=23, w=1 S23 */
      __RWB uint32_t S24              :  1; /*!< Ofs=24, w=1 S24 */
      __RWB uint32_t S25              :  1; /*!< Ofs=25, w=1 S25 */
      __RWB uint32_t S26              :  1; /*!< Ofs=26, w=1 S26 */
      __RWB uint32_t S27              :  1; /*!< Ofs=27, w=1 S27 */
      __RWB uint32_t S28              :  1; /*!< Ofs=28, w=1 S28 */
      __RWB uint32_t S29              :  1; /*!< Ofs=29, w=1 S29 */
      __RWB uint32_t S30              :  1; /*!< Ofs=30, w=1 S30 */
            uint32_t unused0          :  1;
    } B;
  } ;
#ifdef __cplusplus
  LCD_RAM_COM0_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LCD_RAM_COM0_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_RAM_COM0_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_RAM_COM1_s { /*!< display memory */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t S00              :  1; /*!< Ofs=0, w=1 S00 */
      __RWB uint32_t S01              :  1; /*!< Ofs=1, w=1 S01 */
      __RWB uint32_t S02              :  1; /*!< Ofs=2, w=1 S02 */
      __RWB uint32_t S03              :  1; /*!< Ofs=3, w=1 S03 */
      __RWB uint32_t S04              :  1; /*!< Ofs=4, w=1 S04 */
      __RWB uint32_t S05              :  1; /*!< Ofs=5, w=1 S05 */
      __RWB uint32_t S06              :  1; /*!< Ofs=6, w=1 S06 */
      __RWB uint32_t S07              :  1; /*!< Ofs=7, w=1 S07 */
      __RWB uint32_t S08              :  1; /*!< Ofs=8, w=1 S08 */
      __RWB uint32_t S09              :  1; /*!< Ofs=9, w=1 S09 */
      __RWB uint32_t S10              :  1; /*!< Ofs=10, w=1 S10 */
      __RWB uint32_t S11              :  1; /*!< Ofs=11, w=1 S11 */
      __RWB uint32_t S12              :  1; /*!< Ofs=12, w=1 S12 */
      __RWB uint32_t S13              :  1; /*!< Ofs=13, w=1 S13 */
      __RWB uint32_t S14              :  1; /*!< Ofs=14, w=1 S14 */
      __RWB uint32_t S15              :  1; /*!< Ofs=15, w=1 S15 */
      __RWB uint32_t S16              :  1; /*!< Ofs=16, w=1 S16 */
      __RWB uint32_t S17              :  1; /*!< Ofs=17, w=1 S17 */
      __RWB uint32_t S18              :  1; /*!< Ofs=18, w=1 S18 */
      __RWB uint32_t S19              :  1; /*!< Ofs=19, w=1 S19 */
      __RWB uint32_t S20              :  1; /*!< Ofs=20, w=1 S20 */
      __RWB uint32_t S21              :  1; /*!< Ofs=21, w=1 S21 */
      __RWB uint32_t S22              :  1; /*!< Ofs=22, w=1 S22 */
      __RWB uint32_t S23              :  1; /*!< Ofs=23, w=1 S23 */
      __RWB uint32_t S24              :  1; /*!< Ofs=24, w=1 S24 */
      __RWB uint32_t S25              :  1; /*!< Ofs=25, w=1 S25 */
      __RWB uint32_t S26              :  1; /*!< Ofs=26, w=1 S26 */
      __RWB uint32_t S27              :  1; /*!< Ofs=27, w=1 S27 */
      __RWB uint32_t S28              :  1; /*!< Ofs=28, w=1 S28 */
      __RWB uint32_t S29              :  1; /*!< Ofs=29, w=1 S29 */
      __RWB uint32_t S30              :  1; /*!< Ofs=30, w=1 S30 */
      __RWB uint32_t S31              :  1; /*!< Ofs=31, w=1 S31 */
    } B;
  } ;
#ifdef __cplusplus
  LCD_RAM_COM1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LCD_RAM_COM1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_RAM_COM1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_RAM_COM2_s { /*!< display memory */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t S00              :  1; /*!< Ofs=0, w=1 S00 */
      __RWB uint32_t S01              :  1; /*!< Ofs=1, w=1 S01 */
      __RWB uint32_t S02              :  1; /*!< Ofs=2, w=1 S02 */
      __RWB uint32_t S03              :  1; /*!< Ofs=3, w=1 S03 */
      __RWB uint32_t S04              :  1; /*!< Ofs=4, w=1 S04 */
      __RWB uint32_t S05              :  1; /*!< Ofs=5, w=1 S05 */
      __RWB uint32_t S06              :  1; /*!< Ofs=6, w=1 S06 */
      __RWB uint32_t S07              :  1; /*!< Ofs=7, w=1 S07 */
      __RWB uint32_t S08              :  1; /*!< Ofs=8, w=1 S08 */
      __RWB uint32_t S09              :  1; /*!< Ofs=9, w=1 S09 */
      __RWB uint32_t S10              :  1; /*!< Ofs=10, w=1 S10 */
      __RWB uint32_t S11              :  1; /*!< Ofs=11, w=1 S11 */
      __RWB uint32_t S12              :  1; /*!< Ofs=12, w=1 S12 */
      __RWB uint32_t S13              :  1; /*!< Ofs=13, w=1 S13 */
      __RWB uint32_t S14              :  1; /*!< Ofs=14, w=1 S14 */
      __RWB uint32_t S15              :  1; /*!< Ofs=15, w=1 S15 */
      __RWB uint32_t S16              :  1; /*!< Ofs=16, w=1 S16 */
      __RWB uint32_t S17              :  1; /*!< Ofs=17, w=1 S17 */
      __RWB uint32_t S18              :  1; /*!< Ofs=18, w=1 S18 */
      __RWB uint32_t S19              :  1; /*!< Ofs=19, w=1 S19 */
      __RWB uint32_t S20              :  1; /*!< Ofs=20, w=1 S20 */
      __RWB uint32_t S21              :  1; /*!< Ofs=21, w=1 S21 */
      __RWB uint32_t S22              :  1; /*!< Ofs=22, w=1 S22 */
      __RWB uint32_t S23              :  1; /*!< Ofs=23, w=1 S23 */
      __RWB uint32_t S24              :  1; /*!< Ofs=24, w=1 S24 */
      __RWB uint32_t S25              :  1; /*!< Ofs=25, w=1 S25 */
      __RWB uint32_t S26              :  1; /*!< Ofs=26, w=1 S26 */
      __RWB uint32_t S27              :  1; /*!< Ofs=27, w=1 S27 */
      __RWB uint32_t S28              :  1; /*!< Ofs=28, w=1 S28 */
      __RWB uint32_t S29              :  1; /*!< Ofs=29, w=1 S29 */
      __RWB uint32_t S30              :  1; /*!< Ofs=30, w=1 S30 */
      __RWB uint32_t S31              :  1; /*!< Ofs=31, w=1 S31 */
    } B;
  } ;
#ifdef __cplusplus
  LCD_RAM_COM2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LCD_RAM_COM2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_RAM_COM2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_RAM_COM3_s { /*!< display memory */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t S00              :  1; /*!< Ofs=0, w=1 S00 */
      __RWB uint32_t S01              :  1; /*!< Ofs=1, w=1 S01 */
      __RWB uint32_t S02              :  1; /*!< Ofs=2, w=1 S02 */
      __RWB uint32_t S03              :  1; /*!< Ofs=3, w=1 S03 */
      __RWB uint32_t S04              :  1; /*!< Ofs=4, w=1 S04 */
      __RWB uint32_t S05              :  1; /*!< Ofs=5, w=1 S05 */
      __RWB uint32_t S06              :  1; /*!< Ofs=6, w=1 S06 */
      __RWB uint32_t S07              :  1; /*!< Ofs=7, w=1 S07 */
      __RWB uint32_t S08              :  1; /*!< Ofs=8, w=1 S08 */
      __RWB uint32_t S09              :  1; /*!< Ofs=9, w=1 S09 */
      __RWB uint32_t S10              :  1; /*!< Ofs=10, w=1 S10 */
      __RWB uint32_t S11              :  1; /*!< Ofs=11, w=1 S11 */
      __RWB uint32_t S12              :  1; /*!< Ofs=12, w=1 S12 */
      __RWB uint32_t S13              :  1; /*!< Ofs=13, w=1 S13 */
      __RWB uint32_t S14              :  1; /*!< Ofs=14, w=1 S14 */
      __RWB uint32_t S15              :  1; /*!< Ofs=15, w=1 S15 */
      __RWB uint32_t S16              :  1; /*!< Ofs=16, w=1 S16 */
      __RWB uint32_t S17              :  1; /*!< Ofs=17, w=1 S17 */
      __RWB uint32_t S18              :  1; /*!< Ofs=18, w=1 S18 */
      __RWB uint32_t S19              :  1; /*!< Ofs=19, w=1 S19 */
      __RWB uint32_t S20              :  1; /*!< Ofs=20, w=1 S20 */
      __RWB uint32_t S21              :  1; /*!< Ofs=21, w=1 S21 */
      __RWB uint32_t S22              :  1; /*!< Ofs=22, w=1 S22 */
      __RWB uint32_t S23              :  1; /*!< Ofs=23, w=1 S23 */
      __RWB uint32_t S24              :  1; /*!< Ofs=24, w=1 S24 */
      __RWB uint32_t S25              :  1; /*!< Ofs=25, w=1 S25 */
      __RWB uint32_t S26              :  1; /*!< Ofs=26, w=1 S26 */
      __RWB uint32_t S27              :  1; /*!< Ofs=27, w=1 S27 */
      __RWB uint32_t S28              :  1; /*!< Ofs=28, w=1 S28 */
      __RWB uint32_t S29              :  1; /*!< Ofs=29, w=1 S29 */
      __RWB uint32_t S30              :  1; /*!< Ofs=30, w=1 S30 */
      __RWB uint32_t S31              :  1; /*!< Ofs=31, w=1 S31 */
    } B;
  } ;
#ifdef __cplusplus
  LCD_RAM_COM3_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LCD_RAM_COM3_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_RAM_COM3_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_RAM_COM4_s { /*!< display memory */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t S00              :  1; /*!< Ofs=0, w=1 S00 */
      __RWB uint32_t S01              :  1; /*!< Ofs=1, w=1 S01 */
      __RWB uint32_t S02              :  1; /*!< Ofs=2, w=1 S02 */
      __RWB uint32_t S03              :  1; /*!< Ofs=3, w=1 S03 */
      __RWB uint32_t S04              :  1; /*!< Ofs=4, w=1 S04 */
      __RWB uint32_t S05              :  1; /*!< Ofs=5, w=1 S05 */
      __RWB uint32_t S06              :  1; /*!< Ofs=6, w=1 S06 */
      __RWB uint32_t S07              :  1; /*!< Ofs=7, w=1 S07 */
      __RWB uint32_t S08              :  1; /*!< Ofs=8, w=1 S08 */
      __RWB uint32_t S09              :  1; /*!< Ofs=9, w=1 S09 */
      __RWB uint32_t S10              :  1; /*!< Ofs=10, w=1 S10 */
      __RWB uint32_t S11              :  1; /*!< Ofs=11, w=1 S11 */
      __RWB uint32_t S12              :  1; /*!< Ofs=12, w=1 S12 */
      __RWB uint32_t S13              :  1; /*!< Ofs=13, w=1 S13 */
      __RWB uint32_t S14              :  1; /*!< Ofs=14, w=1 S14 */
      __RWB uint32_t S15              :  1; /*!< Ofs=15, w=1 S15 */
      __RWB uint32_t S16              :  1; /*!< Ofs=16, w=1 S16 */
      __RWB uint32_t S17              :  1; /*!< Ofs=17, w=1 S17 */
      __RWB uint32_t S18              :  1; /*!< Ofs=18, w=1 S18 */
      __RWB uint32_t S19              :  1; /*!< Ofs=19, w=1 S19 */
      __RWB uint32_t S20              :  1; /*!< Ofs=20, w=1 S20 */
      __RWB uint32_t S21              :  1; /*!< Ofs=21, w=1 S21 */
      __RWB uint32_t S22              :  1; /*!< Ofs=22, w=1 S22 */
      __RWB uint32_t S23              :  1; /*!< Ofs=23, w=1 S23 */
      __RWB uint32_t S24              :  1; /*!< Ofs=24, w=1 S24 */
      __RWB uint32_t S25              :  1; /*!< Ofs=25, w=1 S25 */
      __RWB uint32_t S26              :  1; /*!< Ofs=26, w=1 S26 */
      __RWB uint32_t S27              :  1; /*!< Ofs=27, w=1 S27 */
      __RWB uint32_t S28              :  1; /*!< Ofs=28, w=1 S28 */
      __RWB uint32_t S29              :  1; /*!< Ofs=29, w=1 S29 */
      __RWB uint32_t S30              :  1; /*!< Ofs=30, w=1 S30 */
      __RWB uint32_t S31              :  1; /*!< Ofs=31, w=1 S31 */
    } B;
  } ;
#ifdef __cplusplus
  LCD_RAM_COM4_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LCD_RAM_COM4_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_RAM_COM4_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_RAM_COM5_s { /*!< display memory */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t S00              :  1; /*!< Ofs=0, w=1 S00 */
      __RWB uint32_t S01              :  1; /*!< Ofs=1, w=1 S01 */
      __RWB uint32_t S02              :  1; /*!< Ofs=2, w=1 S02 */
      __RWB uint32_t S03              :  1; /*!< Ofs=3, w=1 S03 */
      __RWB uint32_t S04              :  1; /*!< Ofs=4, w=1 S04 */
      __RWB uint32_t S05              :  1; /*!< Ofs=5, w=1 S05 */
      __RWB uint32_t S06              :  1; /*!< Ofs=6, w=1 S06 */
      __RWB uint32_t S07              :  1; /*!< Ofs=7, w=1 S07 */
      __RWB uint32_t S08              :  1; /*!< Ofs=8, w=1 S08 */
      __RWB uint32_t S09              :  1; /*!< Ofs=9, w=1 S09 */
      __RWB uint32_t S10              :  1; /*!< Ofs=10, w=1 S10 */
      __RWB uint32_t S11              :  1; /*!< Ofs=11, w=1 S11 */
      __RWB uint32_t S12              :  1; /*!< Ofs=12, w=1 S12 */
      __RWB uint32_t S13              :  1; /*!< Ofs=13, w=1 S13 */
      __RWB uint32_t S14              :  1; /*!< Ofs=14, w=1 S14 */
      __RWB uint32_t S15              :  1; /*!< Ofs=15, w=1 S15 */
      __RWB uint32_t S16              :  1; /*!< Ofs=16, w=1 S16 */
      __RWB uint32_t S17              :  1; /*!< Ofs=17, w=1 S17 */
      __RWB uint32_t S18              :  1; /*!< Ofs=18, w=1 S18 */
      __RWB uint32_t S19              :  1; /*!< Ofs=19, w=1 S19 */
      __RWB uint32_t S20              :  1; /*!< Ofs=20, w=1 S20 */
      __RWB uint32_t S21              :  1; /*!< Ofs=21, w=1 S21 */
      __RWB uint32_t S22              :  1; /*!< Ofs=22, w=1 S22 */
      __RWB uint32_t S23              :  1; /*!< Ofs=23, w=1 S23 */
      __RWB uint32_t S24              :  1; /*!< Ofs=24, w=1 S24 */
      __RWB uint32_t S25              :  1; /*!< Ofs=25, w=1 S25 */
      __RWB uint32_t S26              :  1; /*!< Ofs=26, w=1 S26 */
      __RWB uint32_t S27              :  1; /*!< Ofs=27, w=1 S27 */
      __RWB uint32_t S28              :  1; /*!< Ofs=28, w=1 S28 */
      __RWB uint32_t S29              :  1; /*!< Ofs=29, w=1 S29 */
      __RWB uint32_t S30              :  1; /*!< Ofs=30, w=1 S30 */
      __RWB uint32_t S31              :  1; /*!< Ofs=31, w=1 S31 */
    } B;
  } ;
#ifdef __cplusplus
  LCD_RAM_COM5_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LCD_RAM_COM5_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_RAM_COM5_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_RAM_COM6_s { /*!< display memory */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t S00              :  1; /*!< Ofs=0, w=1 S00 */
      __RWB uint32_t S01              :  1; /*!< Ofs=1, w=1 S01 */
      __RWB uint32_t S02              :  1; /*!< Ofs=2, w=1 S02 */
      __RWB uint32_t S03              :  1; /*!< Ofs=3, w=1 S03 */
      __RWB uint32_t S04              :  1; /*!< Ofs=4, w=1 S04 */
      __RWB uint32_t S05              :  1; /*!< Ofs=5, w=1 S05 */
      __RWB uint32_t S06              :  1; /*!< Ofs=6, w=1 S06 */
      __RWB uint32_t S07              :  1; /*!< Ofs=7, w=1 S07 */
      __RWB uint32_t S08              :  1; /*!< Ofs=8, w=1 S08 */
      __RWB uint32_t S09              :  1; /*!< Ofs=9, w=1 S09 */
      __RWB uint32_t S10              :  1; /*!< Ofs=10, w=1 S10 */
      __RWB uint32_t S11              :  1; /*!< Ofs=11, w=1 S11 */
      __RWB uint32_t S12              :  1; /*!< Ofs=12, w=1 S12 */
      __RWB uint32_t S13              :  1; /*!< Ofs=13, w=1 S13 */
      __RWB uint32_t S14              :  1; /*!< Ofs=14, w=1 S14 */
      __RWB uint32_t S15              :  1; /*!< Ofs=15, w=1 S15 */
      __RWB uint32_t S16              :  1; /*!< Ofs=16, w=1 S16 */
      __RWB uint32_t S17              :  1; /*!< Ofs=17, w=1 S17 */
      __RWB uint32_t S18              :  1; /*!< Ofs=18, w=1 S18 */
      __RWB uint32_t S19              :  1; /*!< Ofs=19, w=1 S19 */
      __RWB uint32_t S20              :  1; /*!< Ofs=20, w=1 S20 */
      __RWB uint32_t S21              :  1; /*!< Ofs=21, w=1 S21 */
      __RWB uint32_t S22              :  1; /*!< Ofs=22, w=1 S22 */
      __RWB uint32_t S23              :  1; /*!< Ofs=23, w=1 S23 */
      __RWB uint32_t S24              :  1; /*!< Ofs=24, w=1 S24 */
      __RWB uint32_t S25              :  1; /*!< Ofs=25, w=1 S25 */
      __RWB uint32_t S26              :  1; /*!< Ofs=26, w=1 S26 */
      __RWB uint32_t S27              :  1; /*!< Ofs=27, w=1 S27 */
      __RWB uint32_t S28              :  1; /*!< Ofs=28, w=1 S28 */
      __RWB uint32_t S29              :  1; /*!< Ofs=29, w=1 S29 */
      __RWB uint32_t S30              :  1; /*!< Ofs=30, w=1 S30 */
      __RWB uint32_t S31              :  1; /*!< Ofs=31, w=1 S31 */
    } B;
  } ;
#ifdef __cplusplus
  LCD_RAM_COM6_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LCD_RAM_COM6_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_RAM_COM6_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LCD_RAM_COM7_s { /*!< display memory */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t S00              :  1; /*!< Ofs=0, w=1 S00 */
      __RWB uint32_t S01              :  1; /*!< Ofs=1, w=1 S01 */
      __RWB uint32_t S02              :  1; /*!< Ofs=2, w=1 S02 */
      __RWB uint32_t S03              :  1; /*!< Ofs=3, w=1 S03 */
      __RWB uint32_t S04              :  1; /*!< Ofs=4, w=1 S04 */
      __RWB uint32_t S05              :  1; /*!< Ofs=5, w=1 S05 */
      __RWB uint32_t S06              :  1; /*!< Ofs=6, w=1 S06 */
      __RWB uint32_t S07              :  1; /*!< Ofs=7, w=1 S07 */
      __RWB uint32_t S08              :  1; /*!< Ofs=8, w=1 S08 */
      __RWB uint32_t S09              :  1; /*!< Ofs=9, w=1 S09 */
      __RWB uint32_t S10              :  1; /*!< Ofs=10, w=1 S10 */
      __RWB uint32_t S11              :  1; /*!< Ofs=11, w=1 S11 */
      __RWB uint32_t S12              :  1; /*!< Ofs=12, w=1 S12 */
      __RWB uint32_t S13              :  1; /*!< Ofs=13, w=1 S13 */
      __RWB uint32_t S14              :  1; /*!< Ofs=14, w=1 S14 */
      __RWB uint32_t S15              :  1; /*!< Ofs=15, w=1 S15 */
      __RWB uint32_t S16              :  1; /*!< Ofs=16, w=1 S16 */
      __RWB uint32_t S17              :  1; /*!< Ofs=17, w=1 S17 */
      __RWB uint32_t S18              :  1; /*!< Ofs=18, w=1 S18 */
      __RWB uint32_t S19              :  1; /*!< Ofs=19, w=1 S19 */
      __RWB uint32_t S20              :  1; /*!< Ofs=20, w=1 S20 */
      __RWB uint32_t S21              :  1; /*!< Ofs=21, w=1 S21 */
      __RWB uint32_t S22              :  1; /*!< Ofs=22, w=1 S22 */
      __RWB uint32_t S23              :  1; /*!< Ofs=23, w=1 S23 */
      __RWB uint32_t S24              :  1; /*!< Ofs=24, w=1 S24 */
      __RWB uint32_t S25              :  1; /*!< Ofs=25, w=1 S25 */
      __RWB uint32_t S26              :  1; /*!< Ofs=26, w=1 S26 */
      __RWB uint32_t S27              :  1; /*!< Ofs=27, w=1 S27 */
      __RWB uint32_t S28              :  1; /*!< Ofs=28, w=1 S28 */
      __RWB uint32_t S29              :  1; /*!< Ofs=29, w=1 S29 */
      __RWB uint32_t S30              :  1; /*!< Ofs=30, w=1 S30 */
      __RWB uint32_t S31              :  1; /*!< Ofs=31, w=1 S31 */
    } B;
  } ;
#ifdef __cplusplus
  LCD_RAM_COM7_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LCD_RAM_COM7_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LCD_RAM_COM7_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_TR_s { /*!< time register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SU               :  4; /*!< Ofs=0, w=4 Second units in BCD format */
      __RWB uint32_t ST               :  3; /*!< Ofs=4, w=3 Second tens in BCD format */
            uint32_t unused0          :  1;
      __RWB uint32_t MNU              :  4; /*!< Ofs=8, w=4 Minute units in BCD format */
      __RWB uint32_t MNT              :  3; /*!< Ofs=12, w=3 Minute tens in BCD format */
            uint32_t unused1          :  1;
      __RWB uint32_t HU               :  4; /*!< Ofs=16, w=4 Hour units in BCD format */
      __RWB uint32_t HT               :  2; /*!< Ofs=20, w=2 Hour tens in BCD format */
      __RWB uint32_t PM               :  1; /*!< Ofs=22, w=1 AM/PM notation */
            uint32_t unused2          :  9;
    } B;
  } ;
#ifdef __cplusplus
  RTC_TR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RTC_TR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_TR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_DR_s { /*!< date register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DU               :  4; /*!< Ofs=0, w=4 Date units in BCD format */
      __RWB uint32_t DT               :  2; /*!< Ofs=4, w=2 Date tens in BCD format */
            uint32_t unused0          :  2;
      __RWB uint32_t MU               :  4; /*!< Ofs=8, w=4 Month units in BCD format */
      __RWB uint32_t MT               :  1; /*!< Ofs=12, w=1 Month tens in BCD format */
      __RWB uint32_t WDU              :  3; /*!< Ofs=13, w=3 Week day units */
      __RWB uint32_t YU               :  4; /*!< Ofs=16, w=4 Year units in BCD format */
      __RWB uint32_t YT               :  4; /*!< Ofs=20, w=4 Year tens in BCD format */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  RTC_DR_s(): R(0x00002101u) {};
  template<typename F> void modify (F f) volatile {
    RTC_DR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_DR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_CR_s { /*!< control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t WCKSEL           :  3; /*!< Ofs=0, w=3 Wakeup clock selection */
      __RWB uint32_t TSEDGE           :  1; /*!< Ofs=3, w=1 Time-stamp event active edge */
      __RWB uint32_t REFCKON          :  1; /*!< Ofs=4, w=1 Reference clock detection enable (50 or 60 Hz) */
      __RWB uint32_t BYPSHAD          :  1; /*!< Ofs=5, w=1 Bypass the shadow registers */
      __RWB uint32_t FMT              :  1; /*!< Ofs=6, w=1 Hour format */
            uint32_t unused0          :  1;
      __RWB uint32_t ALRAE            :  1; /*!< Ofs=8, w=1 Alarm A enable */
      __RWB uint32_t ALRBE            :  1; /*!< Ofs=9, w=1 Alarm B enable */
      __RWB uint32_t WUTE             :  1; /*!< Ofs=10, w=1 Wakeup timer enable */
      __RWB uint32_t TSE              :  1; /*!< Ofs=11, w=1 Time stamp enable */
      __RWB uint32_t ALRAIE           :  1; /*!< Ofs=12, w=1 Alarm A interrupt enable */
      __RWB uint32_t ALRBIE           :  1; /*!< Ofs=13, w=1 Alarm B interrupt enable */
      __RWB uint32_t WUTIE            :  1; /*!< Ofs=14, w=1 Wakeup timer interrupt enable */
      __RWB uint32_t TSIE             :  1; /*!< Ofs=15, w=1 Time-stamp interrupt enable */
      __RWB uint32_t ADD1H            :  1; /*!< Ofs=16, w=1 Add 1 hour (summer time change) */
      __RWB uint32_t SUB1H            :  1; /*!< Ofs=17, w=1 Subtract 1 hour (winter time change) */
      __RWB uint32_t BKP              :  1; /*!< Ofs=18, w=1 Backup */
      __RWB uint32_t COSEL            :  1; /*!< Ofs=19, w=1 Calibration output selection */
      __RWB uint32_t POL              :  1; /*!< Ofs=20, w=1 Output polarity */
      __RWB uint32_t OSEL             :  2; /*!< Ofs=21, w=2 Output selection */
      __RWB uint32_t COE              :  1; /*!< Ofs=23, w=1 Calibration output enable */
      __RWB uint32_t ITSE             :  1; /*!< Ofs=24, w=1 timestamp on internal event enable */
            uint32_t unused1          :  7;
    } B;
  } ;
#ifdef __cplusplus
  RTC_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RTC_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_ISR_s { /*!< initialization and status register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t ALRAWF           :  1; /*!< Ofs=0, w=1 Alarm A write flag */
      __ROB uint32_t ALRBWF           :  1; /*!< Ofs=1, w=1 Alarm B write flag */
      __ROB uint32_t WUTWF            :  1; /*!< Ofs=2, w=1 Wakeup timer write flag */
      __RWB uint32_t SHPF             :  1; /*!< Ofs=3, w=1 Shift operation pending */
      __ROB uint32_t INITS            :  1; /*!< Ofs=4, w=1 Initialization status flag */
      __RWB uint32_t RSF              :  1; /*!< Ofs=5, w=1 Registers synchronization flag */
      __ROB uint32_t INITF            :  1; /*!< Ofs=6, w=1 Initialization flag */
      __RWB uint32_t INIT             :  1; /*!< Ofs=7, w=1 Initialization mode */
      __RWB uint32_t ALRAF            :  1; /*!< Ofs=8, w=1 Alarm A flag */
      __RWB uint32_t ALRBF            :  1; /*!< Ofs=9, w=1 Alarm B flag */
      __RWB uint32_t WUTF             :  1; /*!< Ofs=10, w=1 Wakeup timer flag */
      __RWB uint32_t TSF              :  1; /*!< Ofs=11, w=1 Time-stamp flag */
      __RWB uint32_t TSOVF            :  1; /*!< Ofs=12, w=1 Time-stamp overflow flag */
      __RWB uint32_t TAMP1F           :  1; /*!< Ofs=13, w=1 Tamper detection flag */
      __RWB uint32_t TAMP2F           :  1; /*!< Ofs=14, w=1 RTC_TAMP2 detection flag */
      __RWB uint32_t TAMP3F           :  1; /*!< Ofs=15, w=1 RTC_TAMP3 detection flag */
      __ROB uint32_t RECALPF          :  1; /*!< Ofs=16, w=1 Recalibration pending Flag */
            uint32_t unused0          : 15;
    } B;
  } ;
#ifdef __cplusplus
  RTC_ISR_s(): R(0x00000007u) {};
  template<typename F> void modify (F f) volatile {
    RTC_ISR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_ISR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_PRER_s { /*!< prescaler register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PREDIV_S         : 15; /*!< Ofs=0, w=15 Synchronous prescaler factor */
            uint32_t unused0          :  1;
      __RWB uint32_t PREDIV_A         :  7; /*!< Ofs=16, w=7 Asynchronous prescaler factor */
            uint32_t unused1          :  9;
    } B;
  } ;
#ifdef __cplusplus
  RTC_PRER_s(): R(0x007F00FFu) {};
  template<typename F> void modify (F f) volatile {
    RTC_PRER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_PRER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_ALRMAR_s { /*!< alarm A register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SU               :  4; /*!< Ofs=0, w=4 Second units in BCD format */
      __RWB uint32_t ST               :  3; /*!< Ofs=4, w=3 Second tens in BCD format */
      __RWB uint32_t MSK1             :  1; /*!< Ofs=7, w=1 Alarm A seconds mask */
      __RWB uint32_t MNU              :  4; /*!< Ofs=8, w=4 Minute units in BCD format */
      __RWB uint32_t MNT              :  3; /*!< Ofs=12, w=3 Minute tens in BCD format */
      __RWB uint32_t MSK2             :  1; /*!< Ofs=15, w=1 Alarm A minutes mask */
      __RWB uint32_t HU               :  4; /*!< Ofs=16, w=4 Hour units in BCD format */
      __RWB uint32_t HT               :  2; /*!< Ofs=20, w=2 Hour tens in BCD format */
      __RWB uint32_t PM               :  1; /*!< Ofs=22, w=1 AM/PM notation */
      __RWB uint32_t MSK3             :  1; /*!< Ofs=23, w=1 Alarm A hours mask */
      __RWB uint32_t DU               :  4; /*!< Ofs=24, w=4 Date units or day in BCD format */
      __RWB uint32_t DT               :  2; /*!< Ofs=28, w=2 Date tens in BCD format */
      __RWB uint32_t WDSEL            :  1; /*!< Ofs=30, w=1 Week day selection */
      __RWB uint32_t MSK4             :  1; /*!< Ofs=31, w=1 Alarm A date mask */
    } B;
  } ;
#ifdef __cplusplus
  RTC_ALRMAR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RTC_ALRMAR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_ALRMAR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_ALRMBR_s { /*!< alarm B register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SU               :  4; /*!< Ofs=0, w=4 Second units in BCD format */
      __RWB uint32_t ST               :  3; /*!< Ofs=4, w=3 Second tens in BCD format */
      __RWB uint32_t MSK1             :  1; /*!< Ofs=7, w=1 Alarm B seconds mask */
      __RWB uint32_t MNU              :  4; /*!< Ofs=8, w=4 Minute units in BCD format */
      __RWB uint32_t MNT              :  3; /*!< Ofs=12, w=3 Minute tens in BCD format */
      __RWB uint32_t MSK2             :  1; /*!< Ofs=15, w=1 Alarm B minutes mask */
      __RWB uint32_t HU               :  4; /*!< Ofs=16, w=4 Hour units in BCD format */
      __RWB uint32_t HT               :  2; /*!< Ofs=20, w=2 Hour tens in BCD format */
      __RWB uint32_t PM               :  1; /*!< Ofs=22, w=1 AM/PM notation */
      __RWB uint32_t MSK3             :  1; /*!< Ofs=23, w=1 Alarm B hours mask */
      __RWB uint32_t DU               :  4; /*!< Ofs=24, w=4 Date units or day in BCD format */
      __RWB uint32_t DT               :  2; /*!< Ofs=28, w=2 Date tens in BCD format */
      __RWB uint32_t WDSEL            :  1; /*!< Ofs=30, w=1 Week day selection */
      __RWB uint32_t MSK4             :  1; /*!< Ofs=31, w=1 Alarm B date mask */
    } B;
  } ;
#ifdef __cplusplus
  RTC_ALRMBR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RTC_ALRMBR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_ALRMBR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_SHIFTR_s { /*!< shift control register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t SUBFS            : 15; /*!< Ofs=0, w=15 Subtract a fraction of a second */
            uint32_t unused0          : 16;
      __WOB uint32_t ADD1S            :  1; /*!< Ofs=31, w=1 Add one second */
    } B;
  } ;
#ifdef __cplusplus
  RTC_SHIFTR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    RTC_SHIFTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_TSTR_s { /*!< time stamp time register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t SU               :  4; /*!< Ofs=0, w=4 Second units in BCD format */
      __ROB uint32_t ST               :  3; /*!< Ofs=4, w=3 Second tens in BCD format */
            uint32_t unused0          :  1;
      __ROB uint32_t MNU              :  4; /*!< Ofs=8, w=4 Minute units in BCD format */
      __ROB uint32_t MNT              :  3; /*!< Ofs=12, w=3 Minute tens in BCD format */
            uint32_t unused1          :  1;
      __ROB uint32_t HU               :  4; /*!< Ofs=16, w=4 Hour units in BCD format */
      __ROB uint32_t HT               :  2; /*!< Ofs=20, w=2 Hour tens in BCD format */
      __ROB uint32_t PM               :  1; /*!< Ofs=22, w=1 AM/PM notation */
            uint32_t unused2          :  9;
    } B;
  } ;
#ifdef __cplusplus
  RTC_TSTR_s(__RO RTC_TSTR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct RTC_TSDR_s { /*!< time stamp date register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t DU               :  4; /*!< Ofs=0, w=4 Date units in BCD format */
      __ROB uint32_t DT               :  2; /*!< Ofs=4, w=2 Date tens in BCD format */
            uint32_t unused0          :  2;
      __ROB uint32_t MU               :  4; /*!< Ofs=8, w=4 Month units in BCD format */
      __ROB uint32_t MT               :  1; /*!< Ofs=12, w=1 Month tens in BCD format */
      __ROB uint32_t WDU              :  3; /*!< Ofs=13, w=3 Week day units */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  RTC_TSDR_s(__RO RTC_TSDR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct RTC_CALR_s { /*!< calibration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CALM             :  9; /*!< Ofs=0, w=9 Calibration minus */
            uint32_t unused0          :  4;
      __RWB uint32_t CALW16           :  1; /*!< Ofs=13, w=1 Use a 16-second calibration cycle period */
      __RWB uint32_t CALW8            :  1; /*!< Ofs=14, w=1 Use an 8-second calibration cycle period */
      __RWB uint32_t CALP             :  1; /*!< Ofs=15, w=1 Increase frequency of RTC by 488.5 ppm */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  RTC_CALR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RTC_CALR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_CALR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_TAMPCR_s { /*!< tamper configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TAMP1E           :  1; /*!< Ofs=0, w=1 Tamper 1 detection enable */
      __RWB uint32_t TAMP1TRG         :  1; /*!< Ofs=1, w=1 Active level for tamper 1 */
      __RWB uint32_t TAMPIE           :  1; /*!< Ofs=2, w=1 Tamper interrupt enable */
      __RWB uint32_t TAMP2E           :  1; /*!< Ofs=3, w=1 Tamper 2 detection enable */
      __RWB uint32_t TAMP2TRG         :  1; /*!< Ofs=4, w=1 Active level for tamper 2 */
      __RWB uint32_t TAMP3E           :  1; /*!< Ofs=5, w=1 Tamper 3 detection enable */
      __RWB uint32_t TAMP3TRG         :  1; /*!< Ofs=6, w=1 Active level for tamper 3 */
      __RWB uint32_t TAMPTS           :  1; /*!< Ofs=7, w=1 Activate timestamp on tamper detection event */
      __RWB uint32_t TAMPFREQ         :  3; /*!< Ofs=8, w=3 Tamper sampling frequency */
      __RWB uint32_t TAMPFLT          :  2; /*!< Ofs=11, w=2 Tamper filter count */
      __RWB uint32_t TAMPPRCH         :  2; /*!< Ofs=13, w=2 Tamper precharge duration */
      __RWB uint32_t TAMPPUDIS        :  1; /*!< Ofs=15, w=1 TAMPER pull-up disable */
      __RWB uint32_t TAMP1IE          :  1; /*!< Ofs=16, w=1 Tamper 1 interrupt enable */
      __RWB uint32_t TAMP1NOERASE     :  1; /*!< Ofs=17, w=1 Tamper 1 no erase */
      __RWB uint32_t TAMP1MF          :  1; /*!< Ofs=18, w=1 Tamper 1 mask flag */
      __RWB uint32_t TAMP2IE          :  1; /*!< Ofs=19, w=1 Tamper 2 interrupt enable */
      __RWB uint32_t TAMP2NOERASE     :  1; /*!< Ofs=20, w=1 Tamper 2 no erase */
      __RWB uint32_t TAMP2MF          :  1; /*!< Ofs=21, w=1 Tamper 2 mask flag */
      __RWB uint32_t TAMP3IE          :  1; /*!< Ofs=22, w=1 Tamper 3 interrupt enable */
      __RWB uint32_t TAMP3NOERASE     :  1; /*!< Ofs=23, w=1 Tamper 3 no erase */
      __RWB uint32_t TAMP3MF          :  1; /*!< Ofs=24, w=1 Tamper 3 mask flag */
            uint32_t unused0          :  7;
    } B;
  } ;
#ifdef __cplusplus
  RTC_TAMPCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RTC_TAMPCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_TAMPCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_ALRMASSR_s { /*!< alarm A sub second register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SS               : 15; /*!< Ofs=0, w=15 Sub seconds value */
            uint32_t unused0          :  9;
      __RWB uint32_t MASKSS           :  4; /*!< Ofs=24, w=4 Mask the most-significant bits starting at this bit */
            uint32_t unused1          :  4;
    } B;
  } ;
#ifdef __cplusplus
  RTC_ALRMASSR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RTC_ALRMASSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_ALRMASSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_ALRMBSSR_s { /*!< alarm B sub second register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SS               : 15; /*!< Ofs=0, w=15 Sub seconds value */
            uint32_t unused0          :  9;
      __RWB uint32_t MASKSS           :  4; /*!< Ofs=24, w=4 Mask the most-significant bits starting at this bit */
            uint32_t unused1          :  4;
    } B;
  } ;
#ifdef __cplusplus
  RTC_ALRMBSSR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RTC_ALRMBSSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_ALRMBSSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RTC_OR_s { /*!< option register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t RTC_ALARM_TYPE   :  1; /*!< Ofs=0, w=1 RTC_ALARM on PC13 output type */
      __RWB uint32_t RTC_OUT_RMP      :  1; /*!< Ofs=1, w=1 RTC_OUT remap */
            uint32_t unused0          : 30;
    } B;
  } ;
#ifdef __cplusplus
  RTC_OR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RTC_OR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RTC_OR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct WWDG_CR_s { /*!< Control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t T                :  7; /*!< Ofs=0, w=7 7-bit counter (MSB to LSB) */
      __RWB uint32_t WDGA             :  1; /*!< Ofs=7, w=1 Activation bit */
            uint32_t unused0          : 24;
    } B;
  } ;
#ifdef __cplusplus
  WWDG_CR_s(): R(0x0000007Fu) {};
  template<typename F> void modify (F f) volatile {
    WWDG_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    WWDG_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct WWDG_CFR_s { /*!< Configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t W                :  7; /*!< Ofs=0, w=7 7-bit window value */
      __RWB uint32_t WDGTB            :  2; /*!< Ofs=7, w=2 Timer base */
      __RWB uint32_t EWI              :  1; /*!< Ofs=9, w=1 Early wakeup interrupt */
            uint32_t unused0          : 22;
    } B;
  } ;
#ifdef __cplusplus
  WWDG_CFR_s(): R(0x0000007Fu) {};
  template<typename F> void modify (F f) volatile {
    WWDG_CFR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    WWDG_CFR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct IWDG_SR_s { /*!< Status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t PVU              :  1; /*!< Ofs=0, w=1 Watchdog prescaler value update */
      __ROB uint32_t RVU              :  1; /*!< Ofs=1, w=1 Watchdog counter reload value update */
      __ROB uint32_t WVU              :  1; /*!< Ofs=2, w=1 Watchdog counter window value update */
            uint32_t unused0          : 29;
    } B;
  } ;
#ifdef __cplusplus
  IWDG_SR_s(__RO IWDG_SR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct USART_CR1_s { /*!< Control register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t UE               :  1; /*!< Ofs=0, w=1 USART enable */
      __RWB uint32_t UESM             :  1; /*!< Ofs=1, w=1 USART enable in Stop mode */
      __RWB uint32_t RE               :  1; /*!< Ofs=2, w=1 Receiver enable */
      __RWB uint32_t TE               :  1; /*!< Ofs=3, w=1 Transmitter enable */
      __RWB uint32_t IDLEIE           :  1; /*!< Ofs=4, w=1 IDLE interrupt enable */
      __RWB uint32_t RXNEIE           :  1; /*!< Ofs=5, w=1 RXNE interrupt enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=6, w=1 Transmission complete interrupt enable */
      __RWB uint32_t TXEIE            :  1; /*!< Ofs=7, w=1 interrupt enable */
      __RWB uint32_t PEIE             :  1; /*!< Ofs=8, w=1 PE interrupt enable */
      __RWB uint32_t PS               :  1; /*!< Ofs=9, w=1 Parity selection */
      __RWB uint32_t PCE              :  1; /*!< Ofs=10, w=1 Parity control enable */
      __RWB uint32_t WAKE             :  1; /*!< Ofs=11, w=1 Receiver wakeup method */
      __RWB uint32_t M0               :  1; /*!< Ofs=12, w=1 Word length */
      __RWB uint32_t MME              :  1; /*!< Ofs=13, w=1 Mute mode enable */
      __RWB uint32_t CMIE             :  1; /*!< Ofs=14, w=1 Character match interrupt enable */
      __RWB uint32_t OVER8            :  1; /*!< Ofs=15, w=1 Oversampling mode */
      __RWB uint32_t DEDT0            :  1; /*!< Ofs=16, w=1 DEDT0 */
      __RWB uint32_t DEDT1            :  1; /*!< Ofs=17, w=1 DEDT1 */
      __RWB uint32_t DEDT2            :  1; /*!< Ofs=18, w=1 DEDT2 */
      __RWB uint32_t DEDT3            :  1; /*!< Ofs=19, w=1 DEDT3 */
      __RWB uint32_t DEDT4            :  1; /*!< Ofs=20, w=1 Driver Enable de-assertion time */
      __RWB uint32_t DEAT0            :  1; /*!< Ofs=21, w=1 DEAT0 */
      __RWB uint32_t DEAT1            :  1; /*!< Ofs=22, w=1 DEAT1 */
      __RWB uint32_t DEAT2            :  1; /*!< Ofs=23, w=1 DEAT2 */
      __RWB uint32_t DEAT3            :  1; /*!< Ofs=24, w=1 DEAT3 */
      __RWB uint32_t DEAT4            :  1; /*!< Ofs=25, w=1 Driver Enable assertion time */
      __RWB uint32_t RTOIE            :  1; /*!< Ofs=26, w=1 Receiver timeout interrupt enable */
      __RWB uint32_t EOBIE            :  1; /*!< Ofs=27, w=1 End of Block interrupt enable */
      __RWB uint32_t M1               :  1; /*!< Ofs=28, w=1 Word length */
            uint32_t unused0          :  3;
    } B;
  } ;
#ifdef __cplusplus
  USART_CR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USART_CR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USART_CR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USART_CR2_s { /*!< Control register 2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  4;
      __RWB uint32_t ADDM7            :  1; /*!< Ofs=4, w=1 7-bit Address Detection/4-bit Address Detection */
      __RWB uint32_t LBDL             :  1; /*!< Ofs=5, w=1 LIN break detection length */
      __RWB uint32_t LBDIE            :  1; /*!< Ofs=6, w=1 LIN break detection interrupt enable */
            uint32_t unused1          :  1;
      __RWB uint32_t LBCL             :  1; /*!< Ofs=8, w=1 Last bit clock pulse */
      __RWB uint32_t CPHA             :  1; /*!< Ofs=9, w=1 Clock phase */
      __RWB uint32_t CPOL             :  1; /*!< Ofs=10, w=1 Clock polarity */
      __RWB uint32_t CLKEN            :  1; /*!< Ofs=11, w=1 Clock enable */
      __RWB uint32_t STOP             :  2; /*!< Ofs=12, w=2 STOP bits */
      __RWB uint32_t LINEN            :  1; /*!< Ofs=14, w=1 LIN mode enable */
      __RWB uint32_t SWAP             :  1; /*!< Ofs=15, w=1 Swap TX/RX pins */
      __RWB uint32_t RXINV            :  1; /*!< Ofs=16, w=1 RX pin active level inversion */
      __RWB uint32_t TXINV            :  1; /*!< Ofs=17, w=1 TX pin active level inversion */
      __RWB uint32_t TAINV            :  1; /*!< Ofs=18, w=1 Binary data inversion */
      __RWB uint32_t MSBFIRST         :  1; /*!< Ofs=19, w=1 Most significant bit first */
      __RWB uint32_t ABREN            :  1; /*!< Ofs=20, w=1 Auto baud rate enable */
      __RWB uint32_t ABRMOD0          :  1; /*!< Ofs=21, w=1 ABRMOD0 */
      __RWB uint32_t ABRMOD1          :  1; /*!< Ofs=22, w=1 Auto baud rate mode */
      __RWB uint32_t RTOEN            :  1; /*!< Ofs=23, w=1 Receiver timeout enable */
      __RWB uint32_t ADD0_3           :  4; /*!< Ofs=24, w=4 Address of the USART node */
      __RWB uint32_t ADD4_7           :  4; /*!< Ofs=28, w=4 Address of the USART node */
    } B;
  } ;
#ifdef __cplusplus
  USART_CR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USART_CR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USART_CR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USART_CR3_s { /*!< Control register 3 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EIE              :  1; /*!< Ofs=0, w=1 Error interrupt enable */
      __RWB uint32_t IREN             :  1; /*!< Ofs=1, w=1 Ir mode enable */
      __RWB uint32_t IRLP             :  1; /*!< Ofs=2, w=1 Ir low-power */
      __RWB uint32_t HDSEL            :  1; /*!< Ofs=3, w=1 Half-duplex selection */
      __RWB uint32_t NACK             :  1; /*!< Ofs=4, w=1 Smartcard NACK enable */
      __RWB uint32_t SCEN             :  1; /*!< Ofs=5, w=1 Smartcard mode enable */
      __RWB uint32_t DMAR             :  1; /*!< Ofs=6, w=1 DMA enable receiver */
      __RWB uint32_t DMAT             :  1; /*!< Ofs=7, w=1 DMA enable transmitter */
      __RWB uint32_t RTSE             :  1; /*!< Ofs=8, w=1 RTS enable */
      __RWB uint32_t CTSE             :  1; /*!< Ofs=9, w=1 CTS enable */
      __RWB uint32_t CTSIE            :  1; /*!< Ofs=10, w=1 CTS interrupt enable */
      __RWB uint32_t ONEBIT           :  1; /*!< Ofs=11, w=1 One sample bit method enable */
      __RWB uint32_t OVRDIS           :  1; /*!< Ofs=12, w=1 Overrun Disable */
      __RWB uint32_t DDRE             :  1; /*!< Ofs=13, w=1 DMA Disable on Reception Error */
      __RWB uint32_t DEM              :  1; /*!< Ofs=14, w=1 Driver enable mode */
      __RWB uint32_t DEP              :  1; /*!< Ofs=15, w=1 Driver enable polarity selection */
            uint32_t unused0          :  1;
      __RWB uint32_t SCARCNT          :  3; /*!< Ofs=17, w=3 Smartcard auto-retry count */
      __RWB uint32_t WUS              :  2; /*!< Ofs=20, w=2 Wakeup from Stop mode interrupt flag selection */
      __RWB uint32_t WUFIE            :  1; /*!< Ofs=22, w=1 Wakeup from Stop mode interrupt enable */
      __RWB uint32_t UCESM            :  1; /*!< Ofs=23, w=1 USART Clock Enable in Stop mode */
      __RWB uint32_t TCBGTIE          :  1; /*!< Ofs=24, w=1 Transmission complete before guard time interrupt enable */
            uint32_t unused1          :  7;
    } B;
  } ;
#ifdef __cplusplus
  USART_CR3_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USART_CR3_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USART_CR3_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USART_GTPR_s { /*!< Guard time and prescaler register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PSC              :  8; /*!< Ofs=0, w=8 Prescaler value */
      __RWB uint32_t GT               :  8; /*!< Ofs=8, w=8 Guard time value */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USART_GTPR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USART_GTPR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USART_GTPR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USART_RTOR_s { /*!< Receiver timeout register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t RTO              : 24; /*!< Ofs=0, w=24 Receiver timeout value */
      __RWB uint32_t BLEN             :  8; /*!< Ofs=24, w=8 Block Length */
    } B;
  } ;
#ifdef __cplusplus
  USART_RTOR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USART_RTOR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USART_RTOR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USART_RQR_s { /*!< Request register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t ABRRQ            :  1; /*!< Ofs=0, w=1 Auto baud rate request */
      __WOB uint32_t SBKRQ            :  1; /*!< Ofs=1, w=1 Send break request */
      __WOB uint32_t MMRQ             :  1; /*!< Ofs=2, w=1 Mute mode request */
      __WOB uint32_t RXFRQ            :  1; /*!< Ofs=3, w=1 Receive data flush request */
      __WOB uint32_t TXFRQ            :  1; /*!< Ofs=4, w=1 Transmit data flush request */
            uint32_t unused0          : 27;
    } B;
  } ;
#ifdef __cplusplus
  USART_RQR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    USART_RQR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USART_ISR_s { /*!< Interrupt & status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t PE               :  1; /*!< Ofs=0, w=1 PE */
      __ROB uint32_t FE               :  1; /*!< Ofs=1, w=1 FE */
      __ROB uint32_t NF               :  1; /*!< Ofs=2, w=1 NF */
      __ROB uint32_t ORE              :  1; /*!< Ofs=3, w=1 ORE */
      __ROB uint32_t IDLE             :  1; /*!< Ofs=4, w=1 IDLE */
      __ROB uint32_t RXNE             :  1; /*!< Ofs=5, w=1 RXNE */
      __ROB uint32_t TC               :  1; /*!< Ofs=6, w=1 TC */
      __ROB uint32_t TXE              :  1; /*!< Ofs=7, w=1 TXE */
      __ROB uint32_t LBDF             :  1; /*!< Ofs=8, w=1 LBDF */
      __ROB uint32_t CTSIF            :  1; /*!< Ofs=9, w=1 CTSIF */
      __ROB uint32_t CTS              :  1; /*!< Ofs=10, w=1 CTS */
      __ROB uint32_t RTOF             :  1; /*!< Ofs=11, w=1 RTOF */
      __ROB uint32_t EOBF             :  1; /*!< Ofs=12, w=1 EOBF */
            uint32_t unused0          :  1;
      __ROB uint32_t ABRE             :  1; /*!< Ofs=14, w=1 ABRE */
      __ROB uint32_t ABRF             :  1; /*!< Ofs=15, w=1 ABRF */
      __ROB uint32_t BUSY             :  1; /*!< Ofs=16, w=1 BUSY */
      __ROB uint32_t CMF              :  1; /*!< Ofs=17, w=1 CMF */
      __ROB uint32_t SBKF             :  1; /*!< Ofs=18, w=1 SBKF */
      __ROB uint32_t RWU              :  1; /*!< Ofs=19, w=1 RWU */
      __ROB uint32_t WUF              :  1; /*!< Ofs=20, w=1 WUF */
      __ROB uint32_t TEACK            :  1; /*!< Ofs=21, w=1 TEACK */
      __ROB uint32_t REACK            :  1; /*!< Ofs=22, w=1 REACK */
            uint32_t unused1          :  2;
      __ROB uint32_t TCBGT            :  1; /*!< Ofs=25, w=1 Transmission complete before guard time completion */
            uint32_t unused2          :  6;
    } B;
  } ;
#ifdef __cplusplus
  USART_ISR_s(__RO USART_ISR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct USART_ICR_s { /*!< Interrupt flag clear register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t PECF             :  1; /*!< Ofs=0, w=1 Parity error clear flag */
      __WOB uint32_t FECF             :  1; /*!< Ofs=1, w=1 Framing error clear flag */
      __WOB uint32_t NCF              :  1; /*!< Ofs=2, w=1 Noise detected clear flag */
      __WOB uint32_t ORECF            :  1; /*!< Ofs=3, w=1 Overrun error clear flag */
      __WOB uint32_t IDLECF           :  1; /*!< Ofs=4, w=1 Idle line detected clear flag */
            uint32_t unused0          :  1;
      __WOB uint32_t TCCF             :  1; /*!< Ofs=6, w=1 Transmission complete clear flag */
            uint32_t unused1          :  1;
      __WOB uint32_t LBDCF            :  1; /*!< Ofs=8, w=1 LIN break detection clear flag */
      __WOB uint32_t CTSCF            :  1; /*!< Ofs=9, w=1 CTS clear flag */
            uint32_t unused2          :  1;
      __WOB uint32_t RTOCF            :  1; /*!< Ofs=11, w=1 Receiver timeout clear flag */
      __WOB uint32_t EOBCF            :  1; /*!< Ofs=12, w=1 End of block clear flag */
            uint32_t unused3          :  4;
      __WOB uint32_t CMCF             :  1; /*!< Ofs=17, w=1 Character match clear flag */
            uint32_t unused4          :  2;
      __WOB uint32_t WUCF             :  1; /*!< Ofs=20, w=1 Wakeup from Stop mode clear flag */
            uint32_t unused5          : 11;
    } B;
  } ;
#ifdef __cplusplus
  USART_ICR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    USART_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct I2C_CR1_s { /*!< Control register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PE               :  1; /*!< Ofs=0, w=1 Peripheral enable */
      __RWB uint32_t TXIE             :  1; /*!< Ofs=1, w=1 TX Interrupt enable */
      __RWB uint32_t RXIE             :  1; /*!< Ofs=2, w=1 RX Interrupt enable */
      __RWB uint32_t ADDRIE           :  1; /*!< Ofs=3, w=1 Address match interrupt enable (slave only) */
      __RWB uint32_t NACKIE           :  1; /*!< Ofs=4, w=1 Not acknowledge received interrupt enable */
      __RWB uint32_t STOPIE           :  1; /*!< Ofs=5, w=1 STOP detection Interrupt enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=6, w=1 Transfer Complete interrupt enable */
      __RWB uint32_t ERRIE            :  1; /*!< Ofs=7, w=1 Error interrupts enable */
      __RWB uint32_t DNF              :  4; /*!< Ofs=8, w=4 Digital noise filter */
      __RWB uint32_t ANFOFF           :  1; /*!< Ofs=12, w=1 Analog noise filter OFF */
            uint32_t unused0          :  1;
      __RWB uint32_t TXDMAEN          :  1; /*!< Ofs=14, w=1 DMA transmission requests enable */
      __RWB uint32_t RXDMAEN          :  1; /*!< Ofs=15, w=1 DMA reception requests enable */
      __RWB uint32_t SBC              :  1; /*!< Ofs=16, w=1 Slave byte control */
      __RWB uint32_t NOSTRETCH        :  1; /*!< Ofs=17, w=1 Clock stretching disable */
      __RWB uint32_t WUPEN            :  1; /*!< Ofs=18, w=1 Wakeup from STOP enable */
      __RWB uint32_t GCEN             :  1; /*!< Ofs=19, w=1 General call enable */
      __RWB uint32_t SMBHEN           :  1; /*!< Ofs=20, w=1 SMBus Host address enable */
      __RWB uint32_t SMBDEN           :  1; /*!< Ofs=21, w=1 SMBus Device Default address enable */
      __RWB uint32_t ALERTEN          :  1; /*!< Ofs=22, w=1 SMBUS alert enable */
      __RWB uint32_t PECEN            :  1; /*!< Ofs=23, w=1 PEC enable */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  I2C_CR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    I2C_CR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    I2C_CR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct I2C_CR2_s { /*!< Control register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SADD             : 10; /*!< Ofs=0, w=10 Slave address bit (master mode) */
      __RWB uint32_t RD_WRN           :  1; /*!< Ofs=10, w=1 Transfer direction (master mode) */
      __RWB uint32_t ADD10            :  1; /*!< Ofs=11, w=1 10-bit addressing mode (master mode) */
      __RWB uint32_t HEAD10R          :  1; /*!< Ofs=12, w=1 10-bit address header only read direction (master receiver mode) */
      __RWB uint32_t START            :  1; /*!< Ofs=13, w=1 Start generation */
      __RWB uint32_t STOP             :  1; /*!< Ofs=14, w=1 Stop generation (master mode) */
      __RWB uint32_t NACK             :  1; /*!< Ofs=15, w=1 NACK generation (slave mode) */
      __RWB uint32_t NBYTES           :  8; /*!< Ofs=16, w=8 Number of bytes */
      __RWB uint32_t RELOAD           :  1; /*!< Ofs=24, w=1 NBYTES reload mode */
      __RWB uint32_t AUTOEND          :  1; /*!< Ofs=25, w=1 Automatic end mode (master mode) */
      __RWB uint32_t PECBYTE          :  1; /*!< Ofs=26, w=1 Packet error checking byte */
            uint32_t unused0          :  5;
    } B;
  } ;
#ifdef __cplusplus
  I2C_CR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    I2C_CR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    I2C_CR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct I2C_OAR1_s { /*!< Own address register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OA1              : 10; /*!< Ofs=0, w=10 Interface address */
      __RWB uint32_t OA1MODE          :  1; /*!< Ofs=10, w=1 Own Address 1 10-bit mode */
            uint32_t unused0          :  4;
      __RWB uint32_t OA1EN            :  1; /*!< Ofs=15, w=1 Own Address 1 enable */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  I2C_OAR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    I2C_OAR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    I2C_OAR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct I2C_OAR2_s { /*!< Own address register 2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  1;
      __RWB uint32_t OA2              :  7; /*!< Ofs=1, w=7 Interface address */
      __RWB uint32_t OA2MSK           :  3; /*!< Ofs=8, w=3 Own Address 2 masks */
            uint32_t unused1          :  4;
      __RWB uint32_t OA2EN            :  1; /*!< Ofs=15, w=1 Own Address 2 enable */
            uint32_t unused2          : 16;
    } B;
  } ;
#ifdef __cplusplus
  I2C_OAR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    I2C_OAR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    I2C_OAR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct I2C_TIMINGR_s { /*!< Timing register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SCLL             :  8; /*!< Ofs=0, w=8 SCL low period (master mode) */
      __RWB uint32_t SCLH             :  8; /*!< Ofs=8, w=8 SCL high period (master mode) */
      __RWB uint32_t SDADEL           :  4; /*!< Ofs=16, w=4 Data hold time */
      __RWB uint32_t SCLDEL           :  4; /*!< Ofs=20, w=4 Data setup time */
            uint32_t unused0          :  4;
      __RWB uint32_t PRESC            :  4; /*!< Ofs=28, w=4 Timing prescaler */
    } B;
  } ;
#ifdef __cplusplus
  I2C_TIMINGR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    I2C_TIMINGR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    I2C_TIMINGR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct I2C_TIMEOUTR_s { /*!< Status register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TIMEOUTA         : 12; /*!< Ofs=0, w=12 Bus timeout A */
      __RWB uint32_t TIDLE            :  1; /*!< Ofs=12, w=1 Idle clock timeout detection */
            uint32_t unused0          :  2;
      __RWB uint32_t TIMOUTEN         :  1; /*!< Ofs=15, w=1 Clock timeout enable */
      __RWB uint32_t TIMEOUTB         : 12; /*!< Ofs=16, w=12 Bus timeout B */
            uint32_t unused1          :  3;
      __RWB uint32_t TEXTEN           :  1; /*!< Ofs=31, w=1 Extended clock timeout enable */
    } B;
  } ;
#ifdef __cplusplus
  I2C_TIMEOUTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    I2C_TIMEOUTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    I2C_TIMEOUTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct I2C_ISR_s { /*!< Interrupt and Status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TXE              :  1; /*!< Ofs=0, w=1 Transmit data register empty (transmitters) */
      __RWB uint32_t TXIS             :  1; /*!< Ofs=1, w=1 Transmit interrupt status (transmitters) */
      __ROB uint32_t RXNE             :  1; /*!< Ofs=2, w=1 Receive data register not empty (receivers) */
      __ROB uint32_t ADDR             :  1; /*!< Ofs=3, w=1 Address matched (slave mode) */
      __ROB uint32_t NACKF            :  1; /*!< Ofs=4, w=1 Not acknowledge received flag */
      __ROB uint32_t STOPF            :  1; /*!< Ofs=5, w=1 Stop detection flag */
      __ROB uint32_t TC               :  1; /*!< Ofs=6, w=1 Transfer Complete (master mode) */
      __ROB uint32_t TCR              :  1; /*!< Ofs=7, w=1 Transfer Complete Reload */
      __ROB uint32_t BERR             :  1; /*!< Ofs=8, w=1 Bus error */
      __ROB uint32_t ARLO             :  1; /*!< Ofs=9, w=1 Arbitration lost */
      __ROB uint32_t OVR              :  1; /*!< Ofs=10, w=1 Overrun/Underrun (slave mode) */
      __ROB uint32_t PECERR           :  1; /*!< Ofs=11, w=1 PEC Error in reception */
      __ROB uint32_t TIMEOUT          :  1; /*!< Ofs=12, w=1 Timeout or t_low detection flag */
      __ROB uint32_t ALERT            :  1; /*!< Ofs=13, w=1 SMBus alert */
            uint32_t unused0          :  1;
      __ROB uint32_t BUSY             :  1; /*!< Ofs=15, w=1 Bus busy */
      __ROB uint32_t DIR              :  1; /*!< Ofs=16, w=1 Transfer direction (Slave mode) */
      __ROB uint32_t ADDCODE          :  7; /*!< Ofs=17, w=7 Address match code (Slave mode) */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  I2C_ISR_s(): R(0x00000001u) {};
  template<typename F> void modify (F f) volatile {
    I2C_ISR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    I2C_ISR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct I2C_ICR_s { /*!< Interrupt clear register */
  union {
      __WOB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __WOB uint32_t ADDRCF           :  1; /*!< Ofs=3, w=1 Address Matched flag clear */
      __WOB uint32_t NACKCF           :  1; /*!< Ofs=4, w=1 Not Acknowledge flag clear */
      __WOB uint32_t STOPCF           :  1; /*!< Ofs=5, w=1 Stop detection flag clear */
            uint32_t unused1          :  2;
      __WOB uint32_t BERRCF           :  1; /*!< Ofs=8, w=1 Bus error flag clear */
      __WOB uint32_t ARLOCF           :  1; /*!< Ofs=9, w=1 Arbitration lost flag clear */
      __WOB uint32_t OVRCF            :  1; /*!< Ofs=10, w=1 Overrun/Underrun flag clear */
      __WOB uint32_t PECCF            :  1; /*!< Ofs=11, w=1 PEC Error flag clear */
      __WOB uint32_t TIMOUTCF         :  1; /*!< Ofs=12, w=1 Timeout detection flag clear */
      __WOB uint32_t ALERTCF          :  1; /*!< Ofs=13, w=1 Alert flag clear */
            uint32_t unused2          : 18;
    } B;
  } ;
#ifdef __cplusplus
  I2C_ICR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    I2C_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CRS_CR_s { /*!< control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SYNCOKIE         :  1; /*!< Ofs=0, w=1 SYNC event OK interrupt enable */
      __RWB uint32_t SYNCWARNIE       :  1; /*!< Ofs=1, w=1 SYNC warning interrupt enable */
      __RWB uint32_t ERRIE            :  1; /*!< Ofs=2, w=1 Synchronization or trimming error interrupt enable */
      __RWB uint32_t ESYNCIE          :  1; /*!< Ofs=3, w=1 Expected SYNC interrupt enable */
            uint32_t unused0          :  1;
      __RWB uint32_t CEN              :  1; /*!< Ofs=5, w=1 Frequency error counter enable */
      __RWB uint32_t AUTOTRIMEN       :  1; /*!< Ofs=6, w=1 Automatic trimming enable */
      __RWB uint32_t SWSYNC           :  1; /*!< Ofs=7, w=1 Generate software SYNC event */
      __RWB uint32_t TRIM             :  6; /*!< Ofs=8, w=6 HSI48 oscillator smooth trimming */
            uint32_t unused1          : 18;
    } B;
  } ;
#ifdef __cplusplus
  CRS_CR_s(): R(0x00002000u) {};
  template<typename F> void modify (F f) volatile {
    CRS_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CRS_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CRS_CFGR_s { /*!< configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t RELOAD           : 16; /*!< Ofs=0, w=16 Counter reload value */
      __RWB uint32_t FELIM            :  8; /*!< Ofs=16, w=8 Frequency error limit */
      __RWB uint32_t SYNCDIV          :  3; /*!< Ofs=24, w=3 SYNC divider */
            uint32_t unused0          :  1;
      __RWB uint32_t SYNCSRC          :  2; /*!< Ofs=28, w=2 SYNC signal source selection */
            uint32_t unused1          :  1;
      __RWB uint32_t SYNCPOL          :  1; /*!< Ofs=31, w=1 SYNC polarity selection */
    } B;
  } ;
#ifdef __cplusplus
  CRS_CFGR_s(): R(0x2022BB7Fu) {};
  template<typename F> void modify (F f) volatile {
    CRS_CFGR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CRS_CFGR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CRS_ISR_s { /*!< interrupt and status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t SYNCOKF          :  1; /*!< Ofs=0, w=1 SYNC event OK flag */
      __ROB uint32_t SYNCWARNF        :  1; /*!< Ofs=1, w=1 SYNC warning flag */
      __ROB uint32_t ERRF             :  1; /*!< Ofs=2, w=1 Error flag */
      __ROB uint32_t ESYNCF           :  1; /*!< Ofs=3, w=1 Expected SYNC flag */
            uint32_t unused0          :  4;
      __ROB uint32_t SYNCERR          :  1; /*!< Ofs=8, w=1 SYNC error */
      __ROB uint32_t SYNCMISS         :  1; /*!< Ofs=9, w=1 SYNC missed */
      __ROB uint32_t TRIMOVF          :  1; /*!< Ofs=10, w=1 Trimming overflow or underflow */
            uint32_t unused1          :  4;
      __ROB uint32_t FEDIR            :  1; /*!< Ofs=15, w=1 Frequency error direction */
      __ROB uint32_t FECAP            : 16; /*!< Ofs=16, w=16 Frequency error capture */
    } B;
  } ;
#ifdef __cplusplus
  CRS_ISR_s(__RO CRS_ISR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct CRS_ICR_s { /*!< interrupt flag clear register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SYNCOKC          :  1; /*!< Ofs=0, w=1 SYNC event OK clear flag */
      __RWB uint32_t SYNCWARNC        :  1; /*!< Ofs=1, w=1 SYNC warning clear flag */
      __RWB uint32_t ERRC             :  1; /*!< Ofs=2, w=1 Error clear flag */
      __RWB uint32_t ESYNCC           :  1; /*!< Ofs=3, w=1 Expected SYNC clear flag */
            uint32_t unused0          : 28;
    } B;
  } ;
#ifdef __cplusplus
  CRS_ICR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CRS_ICR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CRS_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_MCR_s { /*!< master control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t INRQ             :  1; /*!< Ofs=0, w=1 INRQ */
      __RWB uint32_t SLEEP            :  1; /*!< Ofs=1, w=1 SLEEP */
      __RWB uint32_t TXFP             :  1; /*!< Ofs=2, w=1 TXFP */
      __RWB uint32_t RFLM             :  1; /*!< Ofs=3, w=1 RFLM */
      __RWB uint32_t NART             :  1; /*!< Ofs=4, w=1 NART */
      __RWB uint32_t AWUM             :  1; /*!< Ofs=5, w=1 AWUM */
      __RWB uint32_t ABOM             :  1; /*!< Ofs=6, w=1 ABOM */
      __RWB uint32_t TTCM             :  1; /*!< Ofs=7, w=1 TTCM */
            uint32_t unused0          :  7;
      __RWB uint32_t RESET            :  1; /*!< Ofs=15, w=1 RESET */
      __RWB uint32_t DBF              :  1; /*!< Ofs=16, w=1 DBF */
            uint32_t unused1          : 15;
    } B;
  } ;
#ifdef __cplusplus
  CAN_MCR_s(): R(0x00010002u) {};
  template<typename F> void modify (F f) volatile {
    CAN_MCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_MCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_MSR_s { /*!< master status register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t INAK             :  1; /*!< Ofs=0, w=1 INAK */
      __ROB uint32_t SLAK             :  1; /*!< Ofs=1, w=1 SLAK */
      __RWB uint32_t ERRI             :  1; /*!< Ofs=2, w=1 ERRI */
      __RWB uint32_t WKUI             :  1; /*!< Ofs=3, w=1 WKUI */
      __RWB uint32_t SLAKI            :  1; /*!< Ofs=4, w=1 SLAKI */
            uint32_t unused0          :  3;
      __ROB uint32_t TXM              :  1; /*!< Ofs=8, w=1 TXM */
      __ROB uint32_t RXM              :  1; /*!< Ofs=9, w=1 RXM */
      __ROB uint32_t SAMP             :  1; /*!< Ofs=10, w=1 SAMP */
      __ROB uint32_t RX               :  1; /*!< Ofs=11, w=1 RX */
            uint32_t unused1          : 20;
    } B;
  } ;
#ifdef __cplusplus
  CAN_MSR_s(): R(0x00000C02u) {};
  template<typename F> void modify (F f) volatile {
    CAN_MSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_MSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TSR_s { /*!< transmit status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t RQCP0            :  1; /*!< Ofs=0, w=1 RQCP0 */
      __RWB uint32_t TXOK0            :  1; /*!< Ofs=1, w=1 TXOK0 */
      __RWB uint32_t ALST0            :  1; /*!< Ofs=2, w=1 ALST0 */
      __RWB uint32_t TERR0            :  1; /*!< Ofs=3, w=1 TERR0 */
            uint32_t unused0          :  3;
      __RWB uint32_t ABRQ0            :  1; /*!< Ofs=7, w=1 ABRQ0 */
      __RWB uint32_t RQCP1            :  1; /*!< Ofs=8, w=1 RQCP1 */
      __RWB uint32_t TXOK1            :  1; /*!< Ofs=9, w=1 TXOK1 */
      __RWB uint32_t ALST1            :  1; /*!< Ofs=10, w=1 ALST1 */
      __RWB uint32_t TERR1            :  1; /*!< Ofs=11, w=1 TERR1 */
            uint32_t unused1          :  3;
      __RWB uint32_t ABRQ1            :  1; /*!< Ofs=15, w=1 ABRQ1 */
      __RWB uint32_t RQCP2            :  1; /*!< Ofs=16, w=1 RQCP2 */
      __RWB uint32_t TXOK2            :  1; /*!< Ofs=17, w=1 TXOK2 */
      __RWB uint32_t ALST2            :  1; /*!< Ofs=18, w=1 ALST2 */
      __RWB uint32_t TERR2            :  1; /*!< Ofs=19, w=1 TERR2 */
            uint32_t unused2          :  3;
      __RWB uint32_t ABRQ2            :  1; /*!< Ofs=23, w=1 ABRQ2 */
      __ROB uint32_t CODE             :  2; /*!< Ofs=24, w=2 CODE */
      __ROB uint32_t TME0             :  1; /*!< Ofs=26, w=1 Lowest priority flag for mailbox 0 */
      __ROB uint32_t TME1             :  1; /*!< Ofs=27, w=1 Lowest priority flag for mailbox 1 */
      __ROB uint32_t TME2             :  1; /*!< Ofs=28, w=1 Lowest priority flag for mailbox 2 */
      __ROB uint32_t LOW0             :  1; /*!< Ofs=29, w=1 Lowest priority flag for mailbox 0 */
      __ROB uint32_t LOW1             :  1; /*!< Ofs=30, w=1 Lowest priority flag for mailbox 1 */
      __ROB uint32_t LOW2             :  1; /*!< Ofs=31, w=1 Lowest priority flag for mailbox 2 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TSR_s(): R(0x1C000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_RF0R_s { /*!< receive FIFO 0 register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t FMP0             :  2; /*!< Ofs=0, w=2 FMP0 */
            uint32_t unused0          :  1;
      __RWB uint32_t FULL0            :  1; /*!< Ofs=3, w=1 FULL0 */
      __RWB uint32_t FOVR0            :  1; /*!< Ofs=4, w=1 FOVR0 */
      __RWB uint32_t RFOM0            :  1; /*!< Ofs=5, w=1 RFOM0 */
            uint32_t unused1          : 26;
    } B;
  } ;
#ifdef __cplusplus
  CAN_RF0R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_RF0R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_RF0R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_RF1R_s { /*!< receive FIFO 1 register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t FMP1             :  2; /*!< Ofs=0, w=2 FMP1 */
            uint32_t unused0          :  1;
      __RWB uint32_t FULL1            :  1; /*!< Ofs=3, w=1 FULL1 */
      __RWB uint32_t FOVR1            :  1; /*!< Ofs=4, w=1 FOVR1 */
      __RWB uint32_t RFOM1            :  1; /*!< Ofs=5, w=1 RFOM1 */
            uint32_t unused1          : 26;
    } B;
  } ;
#ifdef __cplusplus
  CAN_RF1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_RF1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_RF1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_IER_s { /*!< interrupt enable register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TMEIE            :  1; /*!< Ofs=0, w=1 TMEIE */
      __RWB uint32_t FMPIE0           :  1; /*!< Ofs=1, w=1 FMPIE0 */
      __RWB uint32_t FFIE0            :  1; /*!< Ofs=2, w=1 FFIE0 */
      __RWB uint32_t FOVIE0           :  1; /*!< Ofs=3, w=1 FOVIE0 */
      __RWB uint32_t FMPIE1           :  1; /*!< Ofs=4, w=1 FMPIE1 */
      __RWB uint32_t FFIE1            :  1; /*!< Ofs=5, w=1 FFIE1 */
      __RWB uint32_t FOVIE1           :  1; /*!< Ofs=6, w=1 FOVIE1 */
            uint32_t unused0          :  1;
      __RWB uint32_t EWGIE            :  1; /*!< Ofs=8, w=1 EWGIE */
      __RWB uint32_t EPVIE            :  1; /*!< Ofs=9, w=1 EPVIE */
      __RWB uint32_t BOFIE            :  1; /*!< Ofs=10, w=1 BOFIE */
      __RWB uint32_t LECIE            :  1; /*!< Ofs=11, w=1 LECIE */
            uint32_t unused1          :  3;
      __RWB uint32_t ERRIE            :  1; /*!< Ofs=15, w=1 ERRIE */
      __RWB uint32_t WKUIE            :  1; /*!< Ofs=16, w=1 WKUIE */
      __RWB uint32_t SLKIE            :  1; /*!< Ofs=17, w=1 SLKIE */
            uint32_t unused2          : 14;
    } B;
  } ;
#ifdef __cplusplus
  CAN_IER_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_IER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_IER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_ESR_s { /*!< interrupt enable register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t EWGF             :  1; /*!< Ofs=0, w=1 EWGF */
      __ROB uint32_t EPVF             :  1; /*!< Ofs=1, w=1 EPVF */
      __ROB uint32_t BOFF             :  1; /*!< Ofs=2, w=1 BOFF */
            uint32_t unused0          :  1;
      __RWB uint32_t LEC              :  3; /*!< Ofs=4, w=3 LEC */
            uint32_t unused1          :  9;
      __ROB uint32_t TEC              :  8; /*!< Ofs=16, w=8 TEC */
      __ROB uint32_t REC              :  8; /*!< Ofs=24, w=8 REC */
    } B;
  } ;
#ifdef __cplusplus
  CAN_ESR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_ESR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_ESR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_BTR_s { /*!< bit timing register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BRP              : 10; /*!< Ofs=0, w=10 BRP */
            uint32_t unused0          :  6;
      __RWB uint32_t TS1              :  4; /*!< Ofs=16, w=4 TS1 */
      __RWB uint32_t TS2              :  3; /*!< Ofs=20, w=3 TS2 */
            uint32_t unused1          :  1;
      __RWB uint32_t SJW              :  2; /*!< Ofs=24, w=2 SJW */
            uint32_t unused2          :  4;
      __RWB uint32_t LBKM             :  1; /*!< Ofs=30, w=1 LBKM */
      __RWB uint32_t SILM             :  1; /*!< Ofs=31, w=1 SILM */
    } B;
  } ;
#ifdef __cplusplus
  CAN_BTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_BTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_BTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TI0R_s { /*!< TX mailbox identifier register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TXRQ             :  1; /*!< Ofs=0, w=1 TXRQ */
      __RWB uint32_t RTR              :  1; /*!< Ofs=1, w=1 RTR */
      __RWB uint32_t IDE              :  1; /*!< Ofs=2, w=1 IDE */
      __RWB uint32_t EXID             : 18; /*!< Ofs=3, w=18 EXID */
      __RWB uint32_t STID             : 11; /*!< Ofs=21, w=11 STID */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TI0R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TI0R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TI0R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TDT0R_s { /*!< mailbox data length control and time stamp register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DLC              :  4; /*!< Ofs=0, w=4 DLC */
            uint32_t unused0          :  4;
      __RWB uint32_t TGT              :  1; /*!< Ofs=8, w=1 TGT */
            uint32_t unused1          :  7;
      __RWB uint32_t TIME             : 16; /*!< Ofs=16, w=16 TIME */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TDT0R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TDT0R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TDT0R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TDL0R_s { /*!< mailbox data low register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DATA0            :  8; /*!< Ofs=0, w=8 DATA0 */
      __RWB uint32_t DATA1            :  8; /*!< Ofs=8, w=8 DATA1 */
      __RWB uint32_t DATA2            :  8; /*!< Ofs=16, w=8 DATA2 */
      __RWB uint32_t DATA3            :  8; /*!< Ofs=24, w=8 DATA3 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TDL0R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TDL0R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TDL0R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TDH0R_s { /*!< mailbox data high register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DATA4            :  8; /*!< Ofs=0, w=8 DATA4 */
      __RWB uint32_t DATA5            :  8; /*!< Ofs=8, w=8 DATA5 */
      __RWB uint32_t DATA6            :  8; /*!< Ofs=16, w=8 DATA6 */
      __RWB uint32_t DATA7            :  8; /*!< Ofs=24, w=8 DATA7 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TDH0R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TDH0R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TDH0R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TI1R_s { /*!< mailbox identifier register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TXRQ             :  1; /*!< Ofs=0, w=1 TXRQ */
      __RWB uint32_t RTR              :  1; /*!< Ofs=1, w=1 RTR */
      __RWB uint32_t IDE              :  1; /*!< Ofs=2, w=1 IDE */
      __RWB uint32_t EXID             : 18; /*!< Ofs=3, w=18 EXID */
      __RWB uint32_t STID             : 11; /*!< Ofs=21, w=11 STID */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TI1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TI1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TI1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TDT1R_s { /*!< mailbox data length control and time stamp register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DLC              :  4; /*!< Ofs=0, w=4 DLC */
            uint32_t unused0          :  4;
      __RWB uint32_t TGT              :  1; /*!< Ofs=8, w=1 TGT */
            uint32_t unused1          :  7;
      __RWB uint32_t TIME             : 16; /*!< Ofs=16, w=16 TIME */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TDT1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TDT1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TDT1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TDL1R_s { /*!< mailbox data low register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DATA0            :  8; /*!< Ofs=0, w=8 DATA0 */
      __RWB uint32_t DATA1            :  8; /*!< Ofs=8, w=8 DATA1 */
      __RWB uint32_t DATA2            :  8; /*!< Ofs=16, w=8 DATA2 */
      __RWB uint32_t DATA3            :  8; /*!< Ofs=24, w=8 DATA3 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TDL1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TDL1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TDL1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TDH1R_s { /*!< mailbox data high register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DATA4            :  8; /*!< Ofs=0, w=8 DATA4 */
      __RWB uint32_t DATA5            :  8; /*!< Ofs=8, w=8 DATA5 */
      __RWB uint32_t DATA6            :  8; /*!< Ofs=16, w=8 DATA6 */
      __RWB uint32_t DATA7            :  8; /*!< Ofs=24, w=8 DATA7 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TDH1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TDH1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TDH1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TI2R_s { /*!< mailbox identifier register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TXRQ             :  1; /*!< Ofs=0, w=1 TXRQ */
      __RWB uint32_t RTR              :  1; /*!< Ofs=1, w=1 RTR */
      __RWB uint32_t IDE              :  1; /*!< Ofs=2, w=1 IDE */
      __RWB uint32_t EXID             : 18; /*!< Ofs=3, w=18 EXID */
      __RWB uint32_t STID             : 11; /*!< Ofs=21, w=11 STID */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TI2R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TI2R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TI2R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TDT2R_s { /*!< mailbox data length control and time stamp register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DLC              :  4; /*!< Ofs=0, w=4 DLC */
            uint32_t unused0          :  4;
      __RWB uint32_t TGT              :  1; /*!< Ofs=8, w=1 TGT */
            uint32_t unused1          :  7;
      __RWB uint32_t TIME             : 16; /*!< Ofs=16, w=16 TIME */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TDT2R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TDT2R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TDT2R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TDL2R_s { /*!< mailbox data low register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DATA0            :  8; /*!< Ofs=0, w=8 DATA0 */
      __RWB uint32_t DATA1            :  8; /*!< Ofs=8, w=8 DATA1 */
      __RWB uint32_t DATA2            :  8; /*!< Ofs=16, w=8 DATA2 */
      __RWB uint32_t DATA3            :  8; /*!< Ofs=24, w=8 DATA3 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TDL2R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TDL2R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TDL2R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_TDH2R_s { /*!< mailbox data high register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DATA4            :  8; /*!< Ofs=0, w=8 DATA4 */
      __RWB uint32_t DATA5            :  8; /*!< Ofs=8, w=8 DATA5 */
      __RWB uint32_t DATA6            :  8; /*!< Ofs=16, w=8 DATA6 */
      __RWB uint32_t DATA7            :  8; /*!< Ofs=24, w=8 DATA7 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_TDH2R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_TDH2R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_TDH2R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_RI0R_s { /*!< receive FIFO mailbox identifier register */
  union {
      __ROB uint32_t R;
    struct {
            uint32_t unused0          :  1;
      __ROB uint32_t RTR              :  1; /*!< Ofs=1, w=1 RTR */
      __ROB uint32_t IDE              :  1; /*!< Ofs=2, w=1 IDE */
      __ROB uint32_t EXID             : 18; /*!< Ofs=3, w=18 EXID */
      __ROB uint32_t STID             : 11; /*!< Ofs=21, w=11 STID */
    } B;
  } ;
#ifdef __cplusplus
  CAN_RI0R_s(__RO CAN_RI0R_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct CAN_RDT0R_s { /*!< mailbox data high register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t DLC              :  4; /*!< Ofs=0, w=4 DLC */
            uint32_t unused0          :  4;
      __ROB uint32_t FMI              :  8; /*!< Ofs=8, w=8 FMI */
      __ROB uint32_t TIME             : 16; /*!< Ofs=16, w=16 TIME */
    } B;
  } ;
#ifdef __cplusplus
  CAN_RDT0R_s(__RO CAN_RDT0R_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct CAN_RDL0R_s { /*!< mailbox data high register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t DATA0            :  8; /*!< Ofs=0, w=8 DATA0 */
      __ROB uint32_t DATA1            :  8; /*!< Ofs=8, w=8 DATA1 */
      __ROB uint32_t DATA2            :  8; /*!< Ofs=16, w=8 DATA2 */
      __ROB uint32_t DATA3            :  8; /*!< Ofs=24, w=8 DATA3 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_RDL0R_s(__RO CAN_RDL0R_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct CAN_RDH0R_s { /*!< receive FIFO mailbox data high register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t DATA4            :  8; /*!< Ofs=0, w=8 DATA4 */
      __ROB uint32_t DATA5            :  8; /*!< Ofs=8, w=8 DATA5 */
      __ROB uint32_t DATA6            :  8; /*!< Ofs=16, w=8 DATA6 */
      __ROB uint32_t DATA7            :  8; /*!< Ofs=24, w=8 DATA7 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_RDH0R_s(__RO CAN_RDH0R_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct CAN_RI1R_s { /*!< mailbox data high register */
  union {
      __ROB uint32_t R;
    struct {
            uint32_t unused0          :  1;
      __ROB uint32_t RTR              :  1; /*!< Ofs=1, w=1 RTR */
      __ROB uint32_t IDE              :  1; /*!< Ofs=2, w=1 IDE */
      __ROB uint32_t EXID             : 18; /*!< Ofs=3, w=18 EXID */
      __ROB uint32_t STID             : 11; /*!< Ofs=21, w=11 STID */
    } B;
  } ;
#ifdef __cplusplus
  CAN_RI1R_s(__RO CAN_RI1R_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct CAN_RDT1R_s { /*!< mailbox data high register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t DLC              :  4; /*!< Ofs=0, w=4 DLC */
            uint32_t unused0          :  4;
      __ROB uint32_t FMI              :  8; /*!< Ofs=8, w=8 FMI */
      __ROB uint32_t TIME             : 16; /*!< Ofs=16, w=16 TIME */
    } B;
  } ;
#ifdef __cplusplus
  CAN_RDT1R_s(__RO CAN_RDT1R_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct CAN_RDL1R_s { /*!< mailbox data high register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t DATA0            :  8; /*!< Ofs=0, w=8 DATA0 */
      __ROB uint32_t DATA1            :  8; /*!< Ofs=8, w=8 DATA1 */
      __ROB uint32_t DATA2            :  8; /*!< Ofs=16, w=8 DATA2 */
      __ROB uint32_t DATA3            :  8; /*!< Ofs=24, w=8 DATA3 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_RDL1R_s(__RO CAN_RDL1R_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct CAN_RDH1R_s { /*!< mailbox data high register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t DATA4            :  8; /*!< Ofs=0, w=8 DATA4 */
      __ROB uint32_t DATA5            :  8; /*!< Ofs=8, w=8 DATA5 */
      __ROB uint32_t DATA6            :  8; /*!< Ofs=16, w=8 DATA6 */
      __ROB uint32_t DATA7            :  8; /*!< Ofs=24, w=8 DATA7 */
    } B;
  } ;
#ifdef __cplusplus
  CAN_RDH1R_s(__RO CAN_RDH1R_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct CAN_FM1R_s { /*!< filter mode register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FBM0             :  1; /*!< Ofs=0, w=1 Filter mode */
      __RWB uint32_t FBM1             :  1; /*!< Ofs=1, w=1 Filter mode */
      __RWB uint32_t FBM2             :  1; /*!< Ofs=2, w=1 Filter mode */
      __RWB uint32_t FBM3             :  1; /*!< Ofs=3, w=1 Filter mode */
      __RWB uint32_t FBM4             :  1; /*!< Ofs=4, w=1 Filter mode */
      __RWB uint32_t FBM5             :  1; /*!< Ofs=5, w=1 Filter mode */
      __RWB uint32_t FBM6             :  1; /*!< Ofs=6, w=1 Filter mode */
      __RWB uint32_t FBM7             :  1; /*!< Ofs=7, w=1 Filter mode */
      __RWB uint32_t FBM8             :  1; /*!< Ofs=8, w=1 Filter mode */
      __RWB uint32_t FBM9             :  1; /*!< Ofs=9, w=1 Filter mode */
      __RWB uint32_t FBM10            :  1; /*!< Ofs=10, w=1 Filter mode */
      __RWB uint32_t FBM11            :  1; /*!< Ofs=11, w=1 Filter mode */
      __RWB uint32_t FBM12            :  1; /*!< Ofs=12, w=1 Filter mode */
      __RWB uint32_t FBM13            :  1; /*!< Ofs=13, w=1 Filter mode */
            uint32_t unused0          : 18;
    } B;
  } ;
#ifdef __cplusplus
  CAN_FM1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_FM1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_FM1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_FS1R_s { /*!< filter scale register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FSC0             :  1; /*!< Ofs=0, w=1 Filter scale configuration */
      __RWB uint32_t FSC1             :  1; /*!< Ofs=1, w=1 Filter scale configuration */
      __RWB uint32_t FSC2             :  1; /*!< Ofs=2, w=1 Filter scale configuration */
      __RWB uint32_t FSC3             :  1; /*!< Ofs=3, w=1 Filter scale configuration */
      __RWB uint32_t FSC4             :  1; /*!< Ofs=4, w=1 Filter scale configuration */
      __RWB uint32_t FSC5             :  1; /*!< Ofs=5, w=1 Filter scale configuration */
      __RWB uint32_t FSC6             :  1; /*!< Ofs=6, w=1 Filter scale configuration */
      __RWB uint32_t FSC7             :  1; /*!< Ofs=7, w=1 Filter scale configuration */
      __RWB uint32_t FSC8             :  1; /*!< Ofs=8, w=1 Filter scale configuration */
      __RWB uint32_t FSC9             :  1; /*!< Ofs=9, w=1 Filter scale configuration */
      __RWB uint32_t FSC10            :  1; /*!< Ofs=10, w=1 Filter scale configuration */
      __RWB uint32_t FSC11            :  1; /*!< Ofs=11, w=1 Filter scale configuration */
      __RWB uint32_t FSC12            :  1; /*!< Ofs=12, w=1 Filter scale configuration */
      __RWB uint32_t FSC13            :  1; /*!< Ofs=13, w=1 Filter scale configuration */
            uint32_t unused0          : 18;
    } B;
  } ;
#ifdef __cplusplus
  CAN_FS1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_FS1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_FS1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_FFA1R_s { /*!< filter FIFO assignment register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FFA0             :  1; /*!< Ofs=0, w=1 Filter FIFO assignment for filter 0 */
      __RWB uint32_t FFA1             :  1; /*!< Ofs=1, w=1 Filter FIFO assignment for filter 1 */
      __RWB uint32_t FFA2             :  1; /*!< Ofs=2, w=1 Filter FIFO assignment for filter 2 */
      __RWB uint32_t FFA3             :  1; /*!< Ofs=3, w=1 Filter FIFO assignment for filter 3 */
      __RWB uint32_t FFA4             :  1; /*!< Ofs=4, w=1 Filter FIFO assignment for filter 4 */
      __RWB uint32_t FFA5             :  1; /*!< Ofs=5, w=1 Filter FIFO assignment for filter 5 */
      __RWB uint32_t FFA6             :  1; /*!< Ofs=6, w=1 Filter FIFO assignment for filter 6 */
      __RWB uint32_t FFA7             :  1; /*!< Ofs=7, w=1 Filter FIFO assignment for filter 7 */
      __RWB uint32_t FFA8             :  1; /*!< Ofs=8, w=1 Filter FIFO assignment for filter 8 */
      __RWB uint32_t FFA9             :  1; /*!< Ofs=9, w=1 Filter FIFO assignment for filter 9 */
      __RWB uint32_t FFA10            :  1; /*!< Ofs=10, w=1 Filter FIFO assignment for filter 10 */
      __RWB uint32_t FFA11            :  1; /*!< Ofs=11, w=1 Filter FIFO assignment for filter 11 */
      __RWB uint32_t FFA12            :  1; /*!< Ofs=12, w=1 Filter FIFO assignment for filter 12 */
      __RWB uint32_t FFA13            :  1; /*!< Ofs=13, w=1 Filter FIFO assignment for filter 13 */
            uint32_t unused0          : 18;
    } B;
  } ;
#ifdef __cplusplus
  CAN_FFA1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_FFA1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_FFA1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_FA1R_s { /*!< filter activation register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FACT0            :  1; /*!< Ofs=0, w=1 Filter active */
      __RWB uint32_t FACT1            :  1; /*!< Ofs=1, w=1 Filter active */
      __RWB uint32_t FACT2            :  1; /*!< Ofs=2, w=1 Filter active */
      __RWB uint32_t FACT3            :  1; /*!< Ofs=3, w=1 Filter active */
      __RWB uint32_t FACT4            :  1; /*!< Ofs=4, w=1 Filter active */
      __RWB uint32_t FACT5            :  1; /*!< Ofs=5, w=1 Filter active */
      __RWB uint32_t FACT6            :  1; /*!< Ofs=6, w=1 Filter active */
      __RWB uint32_t FACT7            :  1; /*!< Ofs=7, w=1 Filter active */
      __RWB uint32_t FACT8            :  1; /*!< Ofs=8, w=1 Filter active */
      __RWB uint32_t FACT9            :  1; /*!< Ofs=9, w=1 Filter active */
      __RWB uint32_t FACT10           :  1; /*!< Ofs=10, w=1 Filter active */
      __RWB uint32_t FACT11           :  1; /*!< Ofs=11, w=1 Filter active */
      __RWB uint32_t FACT12           :  1; /*!< Ofs=12, w=1 Filter active */
      __RWB uint32_t FACT13           :  1; /*!< Ofs=13, w=1 Filter active */
            uint32_t unused0          : 18;
    } B;
  } ;
#ifdef __cplusplus
  CAN_FA1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_FA1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_FA1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F0R1_s { /*!< Filter bank 0 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F0R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F0R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F0R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F0R2_s { /*!< Filter bank 0 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F0R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F0R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F0R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F1R1_s { /*!< Filter bank 1 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F1R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F1R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F1R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F1R2_s { /*!< Filter bank 1 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F1R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F1R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F1R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F2R1_s { /*!< Filter bank 2 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F2R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F2R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F2R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F2R2_s { /*!< Filter bank 2 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F2R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F2R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F2R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F3R1_s { /*!< Filter bank 3 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F3R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F3R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F3R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F3R2_s { /*!< Filter bank 3 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F3R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F3R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F3R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F4R1_s { /*!< Filter bank 4 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F4R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F4R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F4R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F4R2_s { /*!< Filter bank 4 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F4R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F4R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F4R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F5R1_s { /*!< Filter bank 5 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F5R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F5R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F5R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F5R2_s { /*!< Filter bank 5 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F5R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F5R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F5R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F6R1_s { /*!< Filter bank 6 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F6R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F6R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F6R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F6R2_s { /*!< Filter bank 6 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F6R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F6R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F6R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F7R1_s { /*!< Filter bank 7 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F7R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F7R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F7R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F7R2_s { /*!< Filter bank 7 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F7R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F7R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F7R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F8R1_s { /*!< Filter bank 8 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F8R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F8R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F8R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F8R2_s { /*!< Filter bank 8 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F8R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F8R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F8R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F9R1_s { /*!< Filter bank 9 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F9R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F9R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F9R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F9R2_s { /*!< Filter bank 9 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F9R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F9R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F9R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F10R1_s { /*!< Filter bank 10 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F10R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F10R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F10R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F10R2_s { /*!< Filter bank 10 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F10R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F10R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F10R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F11R1_s { /*!< Filter bank 11 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F11R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F11R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F11R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F11R2_s { /*!< Filter bank 11 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F11R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F11R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F11R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F12R1_s { /*!< Filter bank 4 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F12R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F12R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F12R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F12R2_s { /*!< Filter bank 12 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F12R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F12R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F12R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F13R1_s { /*!< Filter bank 13 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F13R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F13R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F13R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F13R2_s { /*!< Filter bank 13 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F13R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F13R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F13R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F14R1_s { /*!< Filter bank 14 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F14R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F14R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F14R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F14R2_s { /*!< Filter bank 14 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F14R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F14R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F14R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F15R1_s { /*!< Filter bank 15 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F15R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F15R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F15R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F15R2_s { /*!< Filter bank 15 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F15R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F15R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F15R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F16R1_s { /*!< Filter bank 16 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F16R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F16R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F16R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F16R2_s { /*!< Filter bank 16 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F16R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F16R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F16R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F17R1_s { /*!< Filter bank 17 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F17R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F17R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F17R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F17R2_s { /*!< Filter bank 17 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F17R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F17R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F17R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F18R1_s { /*!< Filter bank 18 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F18R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F18R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F18R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F18R2_s { /*!< Filter bank 18 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F18R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F18R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F18R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F19R1_s { /*!< Filter bank 19 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F19R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F19R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F19R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F19R2_s { /*!< Filter bank 19 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F19R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F19R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F19R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F20R1_s { /*!< Filter bank 20 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F20R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F20R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F20R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F20R2_s { /*!< Filter bank 20 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F20R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F20R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F20R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F21R1_s { /*!< Filter bank 21 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F21R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F21R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F21R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F21R2_s { /*!< Filter bank 21 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F21R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F21R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F21R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F22R1_s { /*!< Filter bank 22 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F22R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F22R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F22R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F22R2_s { /*!< Filter bank 22 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F22R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F22R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F22R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F23R1_s { /*!< Filter bank 23 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F23R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F23R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F23R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F23R2_s { /*!< Filter bank 23 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F23R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F23R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F23R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F24R1_s { /*!< Filter bank 24 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F24R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F24R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F24R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F24R2_s { /*!< Filter bank 24 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F24R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F24R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F24R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F25R1_s { /*!< Filter bank 25 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F25R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F25R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F25R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F25R2_s { /*!< Filter bank 25 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F25R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F25R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F25R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F26R1_s { /*!< Filter bank 26 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F26R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F26R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F26R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F26R2_s { /*!< Filter bank 26 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F26R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F26R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F26R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F27R1_s { /*!< Filter bank 27 register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F27R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F27R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F27R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CAN_F27R2_s { /*!< Filter bank 27 register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FB0              :  1; /*!< Ofs=0, w=1 Filter bits */
      __RWB uint32_t FB1              :  1; /*!< Ofs=1, w=1 Filter bits */
      __RWB uint32_t FB2              :  1; /*!< Ofs=2, w=1 Filter bits */
      __RWB uint32_t FB3              :  1; /*!< Ofs=3, w=1 Filter bits */
      __RWB uint32_t FB4              :  1; /*!< Ofs=4, w=1 Filter bits */
      __RWB uint32_t FB5              :  1; /*!< Ofs=5, w=1 Filter bits */
      __RWB uint32_t FB6              :  1; /*!< Ofs=6, w=1 Filter bits */
      __RWB uint32_t FB7              :  1; /*!< Ofs=7, w=1 Filter bits */
      __RWB uint32_t FB8              :  1; /*!< Ofs=8, w=1 Filter bits */
      __RWB uint32_t FB9              :  1; /*!< Ofs=9, w=1 Filter bits */
      __RWB uint32_t FB10             :  1; /*!< Ofs=10, w=1 Filter bits */
      __RWB uint32_t FB11             :  1; /*!< Ofs=11, w=1 Filter bits */
      __RWB uint32_t FB12             :  1; /*!< Ofs=12, w=1 Filter bits */
      __RWB uint32_t FB13             :  1; /*!< Ofs=13, w=1 Filter bits */
      __RWB uint32_t FB14             :  1; /*!< Ofs=14, w=1 Filter bits */
      __RWB uint32_t FB15             :  1; /*!< Ofs=15, w=1 Filter bits */
      __RWB uint32_t FB16             :  1; /*!< Ofs=16, w=1 Filter bits */
      __RWB uint32_t FB17             :  1; /*!< Ofs=17, w=1 Filter bits */
      __RWB uint32_t FB18             :  1; /*!< Ofs=18, w=1 Filter bits */
      __RWB uint32_t FB19             :  1; /*!< Ofs=19, w=1 Filter bits */
      __RWB uint32_t FB20             :  1; /*!< Ofs=20, w=1 Filter bits */
      __RWB uint32_t FB21             :  1; /*!< Ofs=21, w=1 Filter bits */
      __RWB uint32_t FB22             :  1; /*!< Ofs=22, w=1 Filter bits */
      __RWB uint32_t FB23             :  1; /*!< Ofs=23, w=1 Filter bits */
      __RWB uint32_t FB24             :  1; /*!< Ofs=24, w=1 Filter bits */
      __RWB uint32_t FB25             :  1; /*!< Ofs=25, w=1 Filter bits */
      __RWB uint32_t FB26             :  1; /*!< Ofs=26, w=1 Filter bits */
      __RWB uint32_t FB27             :  1; /*!< Ofs=27, w=1 Filter bits */
      __RWB uint32_t FB28             :  1; /*!< Ofs=28, w=1 Filter bits */
      __RWB uint32_t FB29             :  1; /*!< Ofs=29, w=1 Filter bits */
      __RWB uint32_t FB30             :  1; /*!< Ofs=30, w=1 Filter bits */
      __RWB uint32_t FB31             :  1; /*!< Ofs=31, w=1 Filter bits */
    } B;
  } ;
#ifdef __cplusplus
  CAN_F27R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CAN_F27R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CAN_F27R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_EP0R_s { /*!< endpoint 0 register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EA               :  4; /*!< Ofs=0, w=4 Endpoint address */
      __RWB uint32_t STAT_TX          :  2; /*!< Ofs=4, w=2 Status bits, for transmission transfers */
      __RWB uint32_t DTOG_TX          :  1; /*!< Ofs=6, w=1 Data Toggle, for transmission transfers */
      __RWB uint32_t CTR_TX           :  1; /*!< Ofs=7, w=1 Correct Transfer for transmission */
      __RWB uint32_t EP_KIND          :  1; /*!< Ofs=8, w=1 Endpoint kind */
      __RWB uint32_t EP_TYPE          :  2; /*!< Ofs=9, w=2 Endpoint type */
      __RWB uint32_t SETUP            :  1; /*!< Ofs=11, w=1 Setup transaction completed */
      __RWB uint32_t STAT_RX          :  2; /*!< Ofs=12, w=2 Status bits, for reception transfers */
      __RWB uint32_t DTOG_RX          :  1; /*!< Ofs=14, w=1 Data Toggle, for reception transfers */
      __RWB uint32_t CTR_RX           :  1; /*!< Ofs=15, w=1 Correct transfer for reception */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_EP0R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_EP0R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_EP0R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_EP1R_s { /*!< endpoint 1 register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EA               :  4; /*!< Ofs=0, w=4 Endpoint address */
      __RWB uint32_t STAT_TX          :  2; /*!< Ofs=4, w=2 Status bits, for transmission transfers */
      __RWB uint32_t DTOG_TX          :  1; /*!< Ofs=6, w=1 Data Toggle, for transmission transfers */
      __RWB uint32_t CTR_TX           :  1; /*!< Ofs=7, w=1 Correct Transfer for transmission */
      __RWB uint32_t EP_KIND          :  1; /*!< Ofs=8, w=1 Endpoint kind */
      __RWB uint32_t EP_TYPE          :  2; /*!< Ofs=9, w=2 Endpoint type */
      __RWB uint32_t SETUP            :  1; /*!< Ofs=11, w=1 Setup transaction completed */
      __RWB uint32_t STAT_RX          :  2; /*!< Ofs=12, w=2 Status bits, for reception transfers */
      __RWB uint32_t DTOG_RX          :  1; /*!< Ofs=14, w=1 Data Toggle, for reception transfers */
      __RWB uint32_t CTR_RX           :  1; /*!< Ofs=15, w=1 Correct transfer for reception */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_EP1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_EP1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_EP1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_EP2R_s { /*!< endpoint 2 register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EA               :  4; /*!< Ofs=0, w=4 Endpoint address */
      __RWB uint32_t STAT_TX          :  2; /*!< Ofs=4, w=2 Status bits, for transmission transfers */
      __RWB uint32_t DTOG_TX          :  1; /*!< Ofs=6, w=1 Data Toggle, for transmission transfers */
      __RWB uint32_t CTR_TX           :  1; /*!< Ofs=7, w=1 Correct Transfer for transmission */
      __RWB uint32_t EP_KIND          :  1; /*!< Ofs=8, w=1 Endpoint kind */
      __RWB uint32_t EP_TYPE          :  2; /*!< Ofs=9, w=2 Endpoint type */
      __RWB uint32_t SETUP            :  1; /*!< Ofs=11, w=1 Setup transaction completed */
      __RWB uint32_t STAT_RX          :  2; /*!< Ofs=12, w=2 Status bits, for reception transfers */
      __RWB uint32_t DTOG_RX          :  1; /*!< Ofs=14, w=1 Data Toggle, for reception transfers */
      __RWB uint32_t CTR_RX           :  1; /*!< Ofs=15, w=1 Correct transfer for reception */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_EP2R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_EP2R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_EP2R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_EP3R_s { /*!< endpoint 3 register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EA               :  4; /*!< Ofs=0, w=4 Endpoint address */
      __RWB uint32_t STAT_TX          :  2; /*!< Ofs=4, w=2 Status bits, for transmission transfers */
      __RWB uint32_t DTOG_TX          :  1; /*!< Ofs=6, w=1 Data Toggle, for transmission transfers */
      __RWB uint32_t CTR_TX           :  1; /*!< Ofs=7, w=1 Correct Transfer for transmission */
      __RWB uint32_t EP_KIND          :  1; /*!< Ofs=8, w=1 Endpoint kind */
      __RWB uint32_t EP_TYPE          :  2; /*!< Ofs=9, w=2 Endpoint type */
      __RWB uint32_t SETUP            :  1; /*!< Ofs=11, w=1 Setup transaction completed */
      __RWB uint32_t STAT_RX          :  2; /*!< Ofs=12, w=2 Status bits, for reception transfers */
      __RWB uint32_t DTOG_RX          :  1; /*!< Ofs=14, w=1 Data Toggle, for reception transfers */
      __RWB uint32_t CTR_RX           :  1; /*!< Ofs=15, w=1 Correct transfer for reception */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_EP3R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_EP3R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_EP3R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_EP4R_s { /*!< endpoint 4 register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EA               :  4; /*!< Ofs=0, w=4 Endpoint address */
      __RWB uint32_t STAT_TX          :  2; /*!< Ofs=4, w=2 Status bits, for transmission transfers */
      __RWB uint32_t DTOG_TX          :  1; /*!< Ofs=6, w=1 Data Toggle, for transmission transfers */
      __RWB uint32_t CTR_TX           :  1; /*!< Ofs=7, w=1 Correct Transfer for transmission */
      __RWB uint32_t EP_KIND          :  1; /*!< Ofs=8, w=1 Endpoint kind */
      __RWB uint32_t EP_TYPE          :  2; /*!< Ofs=9, w=2 Endpoint type */
      __RWB uint32_t SETUP            :  1; /*!< Ofs=11, w=1 Setup transaction completed */
      __RWB uint32_t STAT_RX          :  2; /*!< Ofs=12, w=2 Status bits, for reception transfers */
      __RWB uint32_t DTOG_RX          :  1; /*!< Ofs=14, w=1 Data Toggle, for reception transfers */
      __RWB uint32_t CTR_RX           :  1; /*!< Ofs=15, w=1 Correct transfer for reception */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_EP4R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_EP4R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_EP4R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_EP5R_s { /*!< endpoint 5 register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EA               :  4; /*!< Ofs=0, w=4 Endpoint address */
      __RWB uint32_t STAT_TX          :  2; /*!< Ofs=4, w=2 Status bits, for transmission transfers */
      __RWB uint32_t DTOG_TX          :  1; /*!< Ofs=6, w=1 Data Toggle, for transmission transfers */
      __RWB uint32_t CTR_TX           :  1; /*!< Ofs=7, w=1 Correct Transfer for transmission */
      __RWB uint32_t EP_KIND          :  1; /*!< Ofs=8, w=1 Endpoint kind */
      __RWB uint32_t EP_TYPE          :  2; /*!< Ofs=9, w=2 Endpoint type */
      __RWB uint32_t SETUP            :  1; /*!< Ofs=11, w=1 Setup transaction completed */
      __RWB uint32_t STAT_RX          :  2; /*!< Ofs=12, w=2 Status bits, for reception transfers */
      __RWB uint32_t DTOG_RX          :  1; /*!< Ofs=14, w=1 Data Toggle, for reception transfers */
      __RWB uint32_t CTR_RX           :  1; /*!< Ofs=15, w=1 Correct transfer for reception */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_EP5R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_EP5R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_EP5R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_EP6R_s { /*!< endpoint 6 register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EA               :  4; /*!< Ofs=0, w=4 Endpoint address */
      __RWB uint32_t STAT_TX          :  2; /*!< Ofs=4, w=2 Status bits, for transmission transfers */
      __RWB uint32_t DTOG_TX          :  1; /*!< Ofs=6, w=1 Data Toggle, for transmission transfers */
      __RWB uint32_t CTR_TX           :  1; /*!< Ofs=7, w=1 Correct Transfer for transmission */
      __RWB uint32_t EP_KIND          :  1; /*!< Ofs=8, w=1 Endpoint kind */
      __RWB uint32_t EP_TYPE          :  2; /*!< Ofs=9, w=2 Endpoint type */
      __RWB uint32_t SETUP            :  1; /*!< Ofs=11, w=1 Setup transaction completed */
      __RWB uint32_t STAT_RX          :  2; /*!< Ofs=12, w=2 Status bits, for reception transfers */
      __RWB uint32_t DTOG_RX          :  1; /*!< Ofs=14, w=1 Data Toggle, for reception transfers */
      __RWB uint32_t CTR_RX           :  1; /*!< Ofs=15, w=1 Correct transfer for reception */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_EP6R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_EP6R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_EP6R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_EP7R_s { /*!< endpoint 7 register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EA               :  4; /*!< Ofs=0, w=4 Endpoint address */
      __RWB uint32_t STAT_TX          :  2; /*!< Ofs=4, w=2 Status bits, for transmission transfers */
      __RWB uint32_t DTOG_TX          :  1; /*!< Ofs=6, w=1 Data Toggle, for transmission transfers */
      __RWB uint32_t CTR_TX           :  1; /*!< Ofs=7, w=1 Correct Transfer for transmission */
      __RWB uint32_t EP_KIND          :  1; /*!< Ofs=8, w=1 Endpoint kind */
      __RWB uint32_t EP_TYPE          :  2; /*!< Ofs=9, w=2 Endpoint type */
      __RWB uint32_t SETUP            :  1; /*!< Ofs=11, w=1 Setup transaction completed */
      __RWB uint32_t STAT_RX          :  2; /*!< Ofs=12, w=2 Status bits, for reception transfers */
      __RWB uint32_t DTOG_RX          :  1; /*!< Ofs=14, w=1 Data Toggle, for reception transfers */
      __RWB uint32_t CTR_RX           :  1; /*!< Ofs=15, w=1 Correct transfer for reception */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_EP7R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_EP7R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_EP7R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_CNTR_s { /*!< control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FRES             :  1; /*!< Ofs=0, w=1 Force USB Reset */
      __RWB uint32_t PDWN             :  1; /*!< Ofs=1, w=1 Power down */
      __RWB uint32_t LPMODE           :  1; /*!< Ofs=2, w=1 Low-power mode */
      __RWB uint32_t FSUSP            :  1; /*!< Ofs=3, w=1 Force suspend */
      __RWB uint32_t RESUME           :  1; /*!< Ofs=4, w=1 Resume request */
      __RWB uint32_t L1RESUME         :  1; /*!< Ofs=5, w=1 LPM L1 Resume request */
            uint32_t unused0          :  1;
      __RWB uint32_t L1REQM           :  1; /*!< Ofs=7, w=1 LPM L1 state request interrupt mask */
      __RWB uint32_t ESOFM            :  1; /*!< Ofs=8, w=1 Expected start of frame interrupt mask */
      __RWB uint32_t SOFM             :  1; /*!< Ofs=9, w=1 Start of frame interrupt mask */
      __RWB uint32_t RESETM           :  1; /*!< Ofs=10, w=1 USB reset interrupt mask */
      __RWB uint32_t SUSPM            :  1; /*!< Ofs=11, w=1 Suspend mode interrupt mask */
      __RWB uint32_t WKUPM            :  1; /*!< Ofs=12, w=1 Wakeup interrupt mask */
      __RWB uint32_t ERRM             :  1; /*!< Ofs=13, w=1 Error interrupt mask */
      __RWB uint32_t PMAOVRM          :  1; /*!< Ofs=14, w=1 Packet memory area over / underrun interrupt mask */
      __RWB uint32_t CTRM             :  1; /*!< Ofs=15, w=1 Correct transfer interrupt mask */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_CNTR_s(): R(0x00000003u) {};
  template<typename F> void modify (F f) volatile {
    USB_CNTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_CNTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_ISTR_s { /*!< interrupt status register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t EP_ID            :  4; /*!< Ofs=0, w=4 Endpoint Identifier */
      __ROB uint32_t DIR              :  1; /*!< Ofs=4, w=1 Direction of transaction */
            uint32_t unused0          :  2;
      __RWB uint32_t L1REQ            :  1; /*!< Ofs=7, w=1 LPM L1 state request */
      __RWB uint32_t ESOF             :  1; /*!< Ofs=8, w=1 Expected start frame */
      __RWB uint32_t SOF              :  1; /*!< Ofs=9, w=1 start of frame */
      __RWB uint32_t RESET            :  1; /*!< Ofs=10, w=1 reset request */
      __RWB uint32_t SUSP             :  1; /*!< Ofs=11, w=1 Suspend mode request */
      __RWB uint32_t WKUP             :  1; /*!< Ofs=12, w=1 Wakeup */
      __RWB uint32_t ERR              :  1; /*!< Ofs=13, w=1 Error */
      __RWB uint32_t PMAOVR           :  1; /*!< Ofs=14, w=1 Packet memory area over / underrun */
      __ROB uint32_t CTR              :  1; /*!< Ofs=15, w=1 Correct transfer */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_ISTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_ISTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_ISTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_FNR_s { /*!< frame number register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t FN               : 11; /*!< Ofs=0, w=11 Frame number */
      __ROB uint32_t LSOF             :  2; /*!< Ofs=11, w=2 Lost SOF */
      __ROB uint32_t LCK              :  1; /*!< Ofs=13, w=1 Locked */
      __ROB uint32_t RXDM             :  1; /*!< Ofs=14, w=1 Receive data - line status */
      __ROB uint32_t RXDP             :  1; /*!< Ofs=15, w=1 Receive data + line status */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_FNR_s(__RO USB_FNR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct USB_DADDR_s { /*!< device address */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ADD              :  7; /*!< Ofs=0, w=7 Device address */
      __RWB uint32_t EF               :  1; /*!< Ofs=7, w=1 Enable function */
            uint32_t unused0          : 24;
    } B;
  } ;
#ifdef __cplusplus
  USB_DADDR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_DADDR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_DADDR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_BTABLE_s { /*!< Buffer table address */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t BTABLE           : 13; /*!< Ofs=3, w=13 Buffer table */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_BTABLE_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_BTABLE_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_BTABLE_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_LPMCSR_s { /*!< LPM control and status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LPMEN            :  1; /*!< Ofs=0, w=1 LPM support enable */
      __RWB uint32_t LPMACK           :  1; /*!< Ofs=1, w=1 LPM Token acknowledge enable */
            uint32_t unused0          :  1;
      __ROB uint32_t REMWAKE          :  1; /*!< Ofs=3, w=1 bRemoteWake value */
      __ROB uint32_t BESL             :  4; /*!< Ofs=4, w=4 BESL value */
            uint32_t unused1          : 24;
    } B;
  } ;
#ifdef __cplusplus
  USB_LPMCSR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_LPMCSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_LPMCSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct USB_BCDR_s { /*!< Battery charging detector */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BCDEN            :  1; /*!< Ofs=0, w=1 Battery charging detector */
      __RWB uint32_t DCDEN            :  1; /*!< Ofs=1, w=1 Data contact detection */
      __RWB uint32_t PDEN             :  1; /*!< Ofs=2, w=1 Primary detection */
      __RWB uint32_t SDEN             :  1; /*!< Ofs=3, w=1 Secondary detection */
      __ROB uint32_t DCDET            :  1; /*!< Ofs=4, w=1 Data contact detection */
      __ROB uint32_t PDET             :  1; /*!< Ofs=5, w=1 Primary detection */
      __ROB uint32_t SDET             :  1; /*!< Ofs=6, w=1 Secondary detection */
      __ROB uint32_t PS2DET           :  1; /*!< Ofs=7, w=1 DM pull-up detection status */
            uint32_t unused0          :  7;
      __RWB uint32_t DPPU             :  1; /*!< Ofs=15, w=1 DP pull-up control */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  USB_BCDR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    USB_BCDR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    USB_BCDR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_CR1_s { /*!< Power control register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LPMS             :  3; /*!< Ofs=0, w=3 Low-power mode selection */
            uint32_t unused0          :  5;
      __RWB uint32_t DBP              :  1; /*!< Ofs=8, w=1 Disable backup domain write protection */
      __RWB uint32_t VOS              :  2; /*!< Ofs=9, w=2 Voltage scaling range selection */
            uint32_t unused1          :  3;
      __RWB uint32_t LPR              :  1; /*!< Ofs=14, w=1 Low-power run */
            uint32_t unused2          : 17;
    } B;
  } ;
#ifdef __cplusplus
  PWR_CR1_s(): R(0x00000200u) {};
  template<typename F> void modify (F f) volatile {
    PWR_CR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_CR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_CR2_s { /*!< Power control register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PVDE             :  1; /*!< Ofs=0, w=1 Power voltage detector enable */
      __RWB uint32_t PLS              :  3; /*!< Ofs=1, w=3 Power voltage detector level selection */
      __RWB uint32_t PVME1            :  1; /*!< Ofs=4, w=1 Peripheral voltage monitoring 1 enable: VDDUSB vs. 1.2V */
      __RWB uint32_t PVME2            :  1; /*!< Ofs=5, w=1 Peripheral voltage monitoring 2 enable: VDDIO2 vs. 0.9V */
      __RWB uint32_t PVME3            :  1; /*!< Ofs=6, w=1 Peripheral voltage monitoring 3 enable: VDDA vs. 1.62V */
      __RWB uint32_t PVME4            :  1; /*!< Ofs=7, w=1 Peripheral voltage monitoring 4 enable: VDDA vs. 2.2V */
            uint32_t unused0          :  1;
      __RWB uint32_t IOSV             :  1; /*!< Ofs=9, w=1 VDDIO2 Independent I/Os supply valid */
      __RWB uint32_t USV              :  1; /*!< Ofs=10, w=1 VDDUSB USB supply valid */
            uint32_t unused1          : 21;
    } B;
  } ;
#ifdef __cplusplus
  PWR_CR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_CR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_CR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_CR3_s { /*!< Power control register 3 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EWUP1            :  1; /*!< Ofs=0, w=1 Enable Wakeup pin WKUP1 */
      __RWB uint32_t EWUP2            :  1; /*!< Ofs=1, w=1 Enable Wakeup pin WKUP2 */
      __RWB uint32_t EWUP3            :  1; /*!< Ofs=2, w=1 Enable Wakeup pin WKUP3 */
      __RWB uint32_t EWUP4            :  1; /*!< Ofs=3, w=1 Enable Wakeup pin WKUP4 */
      __RWB uint32_t EWUP5            :  1; /*!< Ofs=4, w=1 Enable Wakeup pin WKUP5 */
            uint32_t unused0          :  3;
      __RWB uint32_t RRS              :  1; /*!< Ofs=8, w=1 SRAM2 retention in Standby mode */
            uint32_t unused1          :  1;
      __RWB uint32_t APC              :  1; /*!< Ofs=10, w=1 Apply pull-up and pull-down configuration */
            uint32_t unused2          :  4;
      __RWB uint32_t EWF              :  1; /*!< Ofs=15, w=1 Enable internal wakeup line */
            uint32_t unused3          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_CR3_s(): R(0x00008000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_CR3_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_CR3_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_CR4_s { /*!< Power control register 4 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t WP1              :  1; /*!< Ofs=0, w=1 Wakeup pin WKUP1 polarity */
      __RWB uint32_t WP2              :  1; /*!< Ofs=1, w=1 Wakeup pin WKUP2 polarity */
      __RWB uint32_t WP3              :  1; /*!< Ofs=2, w=1 Wakeup pin WKUP3 polarity */
      __RWB uint32_t WP4              :  1; /*!< Ofs=3, w=1 Wakeup pin WKUP4 polarity */
      __RWB uint32_t WP5              :  1; /*!< Ofs=4, w=1 Wakeup pin WKUP5 polarity */
            uint32_t unused0          :  3;
      __RWB uint32_t VBE              :  1; /*!< Ofs=8, w=1 VBAT battery charging enable */
      __RWB uint32_t VBRS             :  1; /*!< Ofs=9, w=1 VBAT battery charging resistor selection */
            uint32_t unused1          : 22;
    } B;
  } ;
#ifdef __cplusplus
  PWR_CR4_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_CR4_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_CR4_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_SR1_s { /*!< Power status register 1 */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t CWUF1            :  1; /*!< Ofs=0, w=1 Wakeup flag 1 */
      __ROB uint32_t CWUF2            :  1; /*!< Ofs=1, w=1 Wakeup flag 2 */
      __ROB uint32_t CWUF3            :  1; /*!< Ofs=2, w=1 Wakeup flag 3 */
      __ROB uint32_t CWUF4            :  1; /*!< Ofs=3, w=1 Wakeup flag 4 */
      __ROB uint32_t CWUF5            :  1; /*!< Ofs=4, w=1 Wakeup flag 5 */
            uint32_t unused0          :  3;
      __ROB uint32_t CSBF             :  1; /*!< Ofs=8, w=1 Standby flag */
            uint32_t unused1          :  6;
      __ROB uint32_t WUFI             :  1; /*!< Ofs=15, w=1 Wakeup flag internal */
            uint32_t unused2          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_SR1_s(__RO PWR_SR1_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct PWR_SR2_s { /*!< Power status register 2 */
  union {
      __ROB uint32_t R;
    struct {
            uint32_t unused0          :  8;
      __ROB uint32_t REGLPS           :  1; /*!< Ofs=8, w=1 Low-power regulator started */
      __ROB uint32_t REGLPF           :  1; /*!< Ofs=9, w=1 Low-power regulator flag */
      __ROB uint32_t VOSF             :  1; /*!< Ofs=10, w=1 Voltage scaling flag */
      __ROB uint32_t PVDO             :  1; /*!< Ofs=11, w=1 Power voltage detector output */
      __ROB uint32_t PVMO1            :  1; /*!< Ofs=12, w=1 Peripheral voltage monitoring output: VDDUSB vs. 1.2 V */
      __ROB uint32_t PVMO2            :  1; /*!< Ofs=13, w=1 Peripheral voltage monitoring output: VDDIO2 vs. 0.9 V */
      __ROB uint32_t PVMO3            :  1; /*!< Ofs=14, w=1 Peripheral voltage monitoring output: VDDA vs. 1.62 V */
      __ROB uint32_t PVMO4            :  1; /*!< Ofs=15, w=1 Peripheral voltage monitoring output: VDDA vs. 2.2 V */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_SR2_s(__RO PWR_SR2_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct PWR_SCR_s { /*!< Power status clear register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t WUF1             :  1; /*!< Ofs=0, w=1 Clear wakeup flag 1 */
      __WOB uint32_t WUF2             :  1; /*!< Ofs=1, w=1 Clear wakeup flag 2 */
      __WOB uint32_t WUF3             :  1; /*!< Ofs=2, w=1 Clear wakeup flag 3 */
      __WOB uint32_t WUF4             :  1; /*!< Ofs=3, w=1 Clear wakeup flag 4 */
      __WOB uint32_t WUF5             :  1; /*!< Ofs=4, w=1 Clear wakeup flag 5 */
            uint32_t unused0          :  3;
      __WOB uint32_t SBF              :  1; /*!< Ofs=8, w=1 Clear standby flag */
            uint32_t unused1          : 23;
    } B;
  } ;
#ifdef __cplusplus
  PWR_SCR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    PWR_SCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PUCRA_s { /*!< Power Port A pull-up control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PU0              :  1; /*!< Ofs=0, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU1              :  1; /*!< Ofs=1, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU2              :  1; /*!< Ofs=2, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU3              :  1; /*!< Ofs=3, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU4              :  1; /*!< Ofs=4, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU5              :  1; /*!< Ofs=5, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU6              :  1; /*!< Ofs=6, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU7              :  1; /*!< Ofs=7, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU8              :  1; /*!< Ofs=8, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU9              :  1; /*!< Ofs=9, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU10             :  1; /*!< Ofs=10, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU11             :  1; /*!< Ofs=11, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU12             :  1; /*!< Ofs=12, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU13             :  1; /*!< Ofs=13, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU14             :  1; /*!< Ofs=14, w=1 Port A pull-up bit y (y=0..15) */
      __RWB uint32_t PU15             :  1; /*!< Ofs=15, w=1 Port A pull-up bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PUCRA_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PUCRA_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PUCRA_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PDCRA_s { /*!< Power Port A pull-down control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PD0              :  1; /*!< Ofs=0, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD1              :  1; /*!< Ofs=1, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD2              :  1; /*!< Ofs=2, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD3              :  1; /*!< Ofs=3, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD4              :  1; /*!< Ofs=4, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD5              :  1; /*!< Ofs=5, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD6              :  1; /*!< Ofs=6, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD7              :  1; /*!< Ofs=7, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD8              :  1; /*!< Ofs=8, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD9              :  1; /*!< Ofs=9, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD10             :  1; /*!< Ofs=10, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD11             :  1; /*!< Ofs=11, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD12             :  1; /*!< Ofs=12, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD13             :  1; /*!< Ofs=13, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD14             :  1; /*!< Ofs=14, w=1 Port A pull-down bit y (y=0..15) */
      __RWB uint32_t PD15             :  1; /*!< Ofs=15, w=1 Port A pull-down bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PDCRA_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PDCRA_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PDCRA_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PUCRB_s { /*!< Power Port B pull-up control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PU0              :  1; /*!< Ofs=0, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU1              :  1; /*!< Ofs=1, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU2              :  1; /*!< Ofs=2, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU3              :  1; /*!< Ofs=3, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU4              :  1; /*!< Ofs=4, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU5              :  1; /*!< Ofs=5, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU6              :  1; /*!< Ofs=6, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU7              :  1; /*!< Ofs=7, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU8              :  1; /*!< Ofs=8, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU9              :  1; /*!< Ofs=9, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU10             :  1; /*!< Ofs=10, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU11             :  1; /*!< Ofs=11, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU12             :  1; /*!< Ofs=12, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU13             :  1; /*!< Ofs=13, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU14             :  1; /*!< Ofs=14, w=1 Port B pull-up bit y (y=0..15) */
      __RWB uint32_t PU15             :  1; /*!< Ofs=15, w=1 Port B pull-up bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PUCRB_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PUCRB_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PUCRB_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PDCRB_s { /*!< Power Port B pull-down control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PD0              :  1; /*!< Ofs=0, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD1              :  1; /*!< Ofs=1, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD2              :  1; /*!< Ofs=2, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD3              :  1; /*!< Ofs=3, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD4              :  1; /*!< Ofs=4, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD5              :  1; /*!< Ofs=5, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD6              :  1; /*!< Ofs=6, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD7              :  1; /*!< Ofs=7, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD8              :  1; /*!< Ofs=8, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD9              :  1; /*!< Ofs=9, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD10             :  1; /*!< Ofs=10, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD11             :  1; /*!< Ofs=11, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD12             :  1; /*!< Ofs=12, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD13             :  1; /*!< Ofs=13, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD14             :  1; /*!< Ofs=14, w=1 Port B pull-down bit y (y=0..15) */
      __RWB uint32_t PD15             :  1; /*!< Ofs=15, w=1 Port B pull-down bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PDCRB_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PDCRB_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PDCRB_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PUCRC_s { /*!< Power Port C pull-up control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PU0              :  1; /*!< Ofs=0, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU1              :  1; /*!< Ofs=1, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU2              :  1; /*!< Ofs=2, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU3              :  1; /*!< Ofs=3, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU4              :  1; /*!< Ofs=4, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU5              :  1; /*!< Ofs=5, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU6              :  1; /*!< Ofs=6, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU7              :  1; /*!< Ofs=7, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU8              :  1; /*!< Ofs=8, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU9              :  1; /*!< Ofs=9, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU10             :  1; /*!< Ofs=10, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU11             :  1; /*!< Ofs=11, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU12             :  1; /*!< Ofs=12, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU13             :  1; /*!< Ofs=13, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU14             :  1; /*!< Ofs=14, w=1 Port C pull-up bit y (y=0..15) */
      __RWB uint32_t PU15             :  1; /*!< Ofs=15, w=1 Port C pull-up bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PUCRC_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PUCRC_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PUCRC_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PDCRC_s { /*!< Power Port C pull-down control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PD0              :  1; /*!< Ofs=0, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD1              :  1; /*!< Ofs=1, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD2              :  1; /*!< Ofs=2, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD3              :  1; /*!< Ofs=3, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD4              :  1; /*!< Ofs=4, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD5              :  1; /*!< Ofs=5, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD6              :  1; /*!< Ofs=6, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD7              :  1; /*!< Ofs=7, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD8              :  1; /*!< Ofs=8, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD9              :  1; /*!< Ofs=9, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD10             :  1; /*!< Ofs=10, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD11             :  1; /*!< Ofs=11, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD12             :  1; /*!< Ofs=12, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD13             :  1; /*!< Ofs=13, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD14             :  1; /*!< Ofs=14, w=1 Port C pull-down bit y (y=0..15) */
      __RWB uint32_t PD15             :  1; /*!< Ofs=15, w=1 Port C pull-down bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PDCRC_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PDCRC_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PDCRC_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PUCRD_s { /*!< Power Port D pull-up control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PU0              :  1; /*!< Ofs=0, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU1              :  1; /*!< Ofs=1, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU2              :  1; /*!< Ofs=2, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU3              :  1; /*!< Ofs=3, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU4              :  1; /*!< Ofs=4, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU5              :  1; /*!< Ofs=5, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU6              :  1; /*!< Ofs=6, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU7              :  1; /*!< Ofs=7, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU8              :  1; /*!< Ofs=8, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU9              :  1; /*!< Ofs=9, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU10             :  1; /*!< Ofs=10, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU11             :  1; /*!< Ofs=11, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU12             :  1; /*!< Ofs=12, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU13             :  1; /*!< Ofs=13, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU14             :  1; /*!< Ofs=14, w=1 Port D pull-up bit y (y=0..15) */
      __RWB uint32_t PU15             :  1; /*!< Ofs=15, w=1 Port D pull-up bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PUCRD_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PUCRD_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PUCRD_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PDCRD_s { /*!< Power Port D pull-down control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PD0              :  1; /*!< Ofs=0, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD1              :  1; /*!< Ofs=1, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD2              :  1; /*!< Ofs=2, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD3              :  1; /*!< Ofs=3, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD4              :  1; /*!< Ofs=4, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD5              :  1; /*!< Ofs=5, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD6              :  1; /*!< Ofs=6, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD7              :  1; /*!< Ofs=7, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD8              :  1; /*!< Ofs=8, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD9              :  1; /*!< Ofs=9, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD10             :  1; /*!< Ofs=10, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD11             :  1; /*!< Ofs=11, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD12             :  1; /*!< Ofs=12, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD13             :  1; /*!< Ofs=13, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD14             :  1; /*!< Ofs=14, w=1 Port D pull-down bit y (y=0..15) */
      __RWB uint32_t PD15             :  1; /*!< Ofs=15, w=1 Port D pull-down bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PDCRD_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PDCRD_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PDCRD_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PUCRE_s { /*!< Power Port E pull-up control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PU0              :  1; /*!< Ofs=0, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU1              :  1; /*!< Ofs=1, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU2              :  1; /*!< Ofs=2, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU3              :  1; /*!< Ofs=3, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU4              :  1; /*!< Ofs=4, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU5              :  1; /*!< Ofs=5, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU6              :  1; /*!< Ofs=6, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU7              :  1; /*!< Ofs=7, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU8              :  1; /*!< Ofs=8, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU9              :  1; /*!< Ofs=9, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU10             :  1; /*!< Ofs=10, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU11             :  1; /*!< Ofs=11, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU12             :  1; /*!< Ofs=12, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU13             :  1; /*!< Ofs=13, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU14             :  1; /*!< Ofs=14, w=1 Port E pull-up bit y (y=0..15) */
      __RWB uint32_t PU15             :  1; /*!< Ofs=15, w=1 Port E pull-up bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PUCRE_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PUCRE_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PUCRE_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PDCRE_s { /*!< Power Port E pull-down control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PD0              :  1; /*!< Ofs=0, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD1              :  1; /*!< Ofs=1, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD2              :  1; /*!< Ofs=2, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD3              :  1; /*!< Ofs=3, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD4              :  1; /*!< Ofs=4, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD5              :  1; /*!< Ofs=5, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD6              :  1; /*!< Ofs=6, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD7              :  1; /*!< Ofs=7, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD8              :  1; /*!< Ofs=8, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD9              :  1; /*!< Ofs=9, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD10             :  1; /*!< Ofs=10, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD11             :  1; /*!< Ofs=11, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD12             :  1; /*!< Ofs=12, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD13             :  1; /*!< Ofs=13, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD14             :  1; /*!< Ofs=14, w=1 Port E pull-down bit y (y=0..15) */
      __RWB uint32_t PD15             :  1; /*!< Ofs=15, w=1 Port E pull-down bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PDCRE_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PDCRE_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PDCRE_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PUCRF_s { /*!< Power Port F pull-up control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PU0              :  1; /*!< Ofs=0, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU1              :  1; /*!< Ofs=1, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU2              :  1; /*!< Ofs=2, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU3              :  1; /*!< Ofs=3, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU4              :  1; /*!< Ofs=4, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU5              :  1; /*!< Ofs=5, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU6              :  1; /*!< Ofs=6, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU7              :  1; /*!< Ofs=7, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU8              :  1; /*!< Ofs=8, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU9              :  1; /*!< Ofs=9, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU10             :  1; /*!< Ofs=10, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU11             :  1; /*!< Ofs=11, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU12             :  1; /*!< Ofs=12, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU13             :  1; /*!< Ofs=13, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU14             :  1; /*!< Ofs=14, w=1 Port F pull-up bit y (y=0..15) */
      __RWB uint32_t PU15             :  1; /*!< Ofs=15, w=1 Port F pull-up bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PUCRF_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PUCRF_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PUCRF_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PDCRF_s { /*!< Power Port F pull-down control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PD0              :  1; /*!< Ofs=0, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD1              :  1; /*!< Ofs=1, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD2              :  1; /*!< Ofs=2, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD3              :  1; /*!< Ofs=3, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD4              :  1; /*!< Ofs=4, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD5              :  1; /*!< Ofs=5, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD6              :  1; /*!< Ofs=6, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD7              :  1; /*!< Ofs=7, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD8              :  1; /*!< Ofs=8, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD9              :  1; /*!< Ofs=9, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD10             :  1; /*!< Ofs=10, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD11             :  1; /*!< Ofs=11, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD12             :  1; /*!< Ofs=12, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD13             :  1; /*!< Ofs=13, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD14             :  1; /*!< Ofs=14, w=1 Port F pull-down bit y (y=0..15) */
      __RWB uint32_t PD15             :  1; /*!< Ofs=15, w=1 Port F pull-down bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PDCRF_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PDCRF_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PDCRF_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PUCRG_s { /*!< Power Port G pull-up control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PU0              :  1; /*!< Ofs=0, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU1              :  1; /*!< Ofs=1, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU2              :  1; /*!< Ofs=2, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU3              :  1; /*!< Ofs=3, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU4              :  1; /*!< Ofs=4, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU5              :  1; /*!< Ofs=5, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU6              :  1; /*!< Ofs=6, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU7              :  1; /*!< Ofs=7, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU8              :  1; /*!< Ofs=8, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU9              :  1; /*!< Ofs=9, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU10             :  1; /*!< Ofs=10, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU11             :  1; /*!< Ofs=11, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU12             :  1; /*!< Ofs=12, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU13             :  1; /*!< Ofs=13, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU14             :  1; /*!< Ofs=14, w=1 Port G pull-up bit y (y=0..15) */
      __RWB uint32_t PU15             :  1; /*!< Ofs=15, w=1 Port G pull-up bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PUCRG_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PUCRG_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PUCRG_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PDCRG_s { /*!< Power Port G pull-down control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PD0              :  1; /*!< Ofs=0, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD1              :  1; /*!< Ofs=1, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD2              :  1; /*!< Ofs=2, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD3              :  1; /*!< Ofs=3, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD4              :  1; /*!< Ofs=4, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD5              :  1; /*!< Ofs=5, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD6              :  1; /*!< Ofs=6, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD7              :  1; /*!< Ofs=7, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD8              :  1; /*!< Ofs=8, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD9              :  1; /*!< Ofs=9, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD10             :  1; /*!< Ofs=10, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD11             :  1; /*!< Ofs=11, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD12             :  1; /*!< Ofs=12, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD13             :  1; /*!< Ofs=13, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD14             :  1; /*!< Ofs=14, w=1 Port G pull-down bit y (y=0..15) */
      __RWB uint32_t PD15             :  1; /*!< Ofs=15, w=1 Port G pull-down bit y (y=0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PDCRG_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PDCRG_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PDCRG_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PUCRH_s { /*!< Power Port H pull-up control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PU0              :  1; /*!< Ofs=0, w=1 Port H pull-up bit y (y=0..1) */
      __RWB uint32_t PU1              :  1; /*!< Ofs=1, w=1 Port H pull-up bit y (y=0..1) */
            uint32_t unused0          : 30;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PUCRH_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PUCRH_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PUCRH_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct PWR_PDCRH_s { /*!< Power Port H pull-down control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PD0              :  1; /*!< Ofs=0, w=1 Port H pull-down bit y (y=0..1) */
      __RWB uint32_t PD1              :  1; /*!< Ofs=1, w=1 Port H pull-down bit y (y=0..1) */
            uint32_t unused0          : 30;
    } B;
  } ;
#ifdef __cplusplus
  PWR_PDCRH_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    PWR_PDCRH_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    PWR_PDCRH_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_CR_s { /*!< control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EN1              :  1; /*!< Ofs=0, w=1 DAC channel1 enable */
            uint32_t unused0          :  1;
      __RWB uint32_t TEN1             :  1; /*!< Ofs=2, w=1 DAC channel1 trigger enable */
      __RWB uint32_t TSEL1            :  3; /*!< Ofs=3, w=3 DAC channel1 trigger selection */
      __RWB uint32_t WAVE1            :  2; /*!< Ofs=6, w=2 DAC channel1 noise/triangle wave generation enable */
      __RWB uint32_t MAMP1            :  4; /*!< Ofs=8, w=4 DAC channel1 mask/amplitude selector */
      __RWB uint32_t DMAEN1           :  1; /*!< Ofs=12, w=1 DAC channel1 DMA enable */
      __RWB uint32_t DMAUDRIE1        :  1; /*!< Ofs=13, w=1 DAC channel1 DMA Underrun Interrupt enable */
      __RWB uint32_t CEN1             :  1; /*!< Ofs=14, w=1 DAC Channel 1 calibration enable */
            uint32_t unused1          :  1;
      __RWB uint32_t EN2              :  1; /*!< Ofs=16, w=1 DAC channel2 enable */
            uint32_t unused2          :  1;
      __RWB uint32_t TEN2             :  1; /*!< Ofs=18, w=1 DAC channel2 trigger enable */
      __RWB uint32_t TSEL2            :  3; /*!< Ofs=19, w=3 DAC channel2 trigger selection */
      __RWB uint32_t WAVE2            :  2; /*!< Ofs=22, w=2 DAC channel2 noise/triangle wave generation enable */
      __RWB uint32_t MAMP2            :  4; /*!< Ofs=24, w=4 DAC channel2 mask/amplitude selector */
      __RWB uint32_t DMAEN2           :  1; /*!< Ofs=28, w=1 DAC channel2 DMA enable */
      __RWB uint32_t DMAUDRIE2        :  1; /*!< Ofs=29, w=1 DAC channel2 DMA underrun interrupt enable */
      __RWB uint32_t CEN2             :  1; /*!< Ofs=30, w=1 DAC Channel 2 calibration enable */
            uint32_t unused3          :  1;
    } B;
  } ;
#ifdef __cplusplus
  DAC_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DAC_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_SWTRIGR_s { /*!< software trigger register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t SWTRIG1          :  1; /*!< Ofs=0, w=1 DAC channel1 software trigger */
      __WOB uint32_t SWTRIG2          :  1; /*!< Ofs=1, w=1 DAC channel2 software trigger */
            uint32_t unused0          : 30;
    } B;
  } ;
#ifdef __cplusplus
  DAC_SWTRIGR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    DAC_SWTRIGR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_DHR12L1_s { /*!< channel1 12-bit left-aligned data holding register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  4;
      __RWB uint32_t DACC1DHR         : 12; /*!< Ofs=4, w=12 DAC channel1 12-bit left-aligned data */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DAC_DHR12L1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DAC_DHR12L1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_DHR12L1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_DHR12L2_s { /*!< channel2 12-bit left aligned data holding register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  4;
      __RWB uint32_t DACC2DHR         : 12; /*!< Ofs=4, w=12 DAC channel2 12-bit left-aligned data */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DAC_DHR12L2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DAC_DHR12L2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_DHR12L2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_DHR12RD_s { /*!< Dual DAC 12-bit right-aligned data holding register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DACC1DHR         : 12; /*!< Ofs=0, w=12 DAC channel1 12-bit right-aligned data */
            uint32_t unused0          :  4;
      __RWB uint32_t DACC2DHR         : 12; /*!< Ofs=16, w=12 DAC channel2 12-bit right-aligned data */
            uint32_t unused1          :  4;
    } B;
  } ;
#ifdef __cplusplus
  DAC_DHR12RD_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DAC_DHR12RD_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_DHR12RD_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_DHR12LD_s { /*!< DUAL DAC 12-bit left aligned data holding register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  4;
      __RWB uint32_t DACC1DHR         : 12; /*!< Ofs=4, w=12 DAC channel1 12-bit left-aligned data */
            uint32_t unused1          :  4;
      __RWB uint32_t DACC2DHR         : 12; /*!< Ofs=20, w=12 DAC channel2 12-bit left-aligned data */
    } B;
  } ;
#ifdef __cplusplus
  DAC_DHR12LD_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DAC_DHR12LD_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_DHR12LD_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_DHR8RD_s { /*!< DUAL DAC 8-bit right aligned data holding register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DACC1DHR         :  8; /*!< Ofs=0, w=8 DAC channel1 8-bit right-aligned data */
      __RWB uint32_t DACC2DHR         :  8; /*!< Ofs=8, w=8 DAC channel2 8-bit right-aligned data */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DAC_DHR8RD_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DAC_DHR8RD_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_DHR8RD_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_SR_s { /*!< status register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          : 13;
      __RWB uint32_t DMAUDR1          :  1; /*!< Ofs=13, w=1 DAC channel1 DMA underrun flag */
      __ROB uint32_t CAL_FLAG1        :  1; /*!< Ofs=14, w=1 DAC Channel 1 calibration offset status */
      __ROB uint32_t BWST1            :  1; /*!< Ofs=15, w=1 DAC Channel 1 busy writing sample time flag */
            uint32_t unused1          : 13;
      __RWB uint32_t DMAUDR2          :  1; /*!< Ofs=29, w=1 DAC channel2 DMA underrun flag */
      __ROB uint32_t CAL_FLAG2        :  1; /*!< Ofs=30, w=1 DAC Channel 2 calibration offset status */
      __ROB uint32_t BWST2            :  1; /*!< Ofs=31, w=1 DAC Channel 2 busy writing sample time flag */
    } B;
  } ;
#ifdef __cplusplus
  DAC_SR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DAC_SR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_SR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_CCR_s { /*!< calibration control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OTRIM1           :  5; /*!< Ofs=0, w=5 DAC Channel 1 offset trimming value */
            uint32_t unused0          : 11;
      __RWB uint32_t OTRIM2           :  5; /*!< Ofs=16, w=5 DAC Channel 2 offset trimming value */
            uint32_t unused1          : 11;
    } B;
  } ;
#ifdef __cplusplus
  DAC_CCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DAC_CCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_CCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_MCR_s { /*!< mode control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t MODE1            :  3; /*!< Ofs=0, w=3 DAC Channel 1 mode */
            uint32_t unused0          : 13;
      __RWB uint32_t MODE2            :  3; /*!< Ofs=16, w=3 DAC Channel 2 mode */
            uint32_t unused1          : 13;
    } B;
  } ;
#ifdef __cplusplus
  DAC_MCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DAC_MCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_MCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_SHHR_s { /*!< Sample and Hold hold time register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t THOLD1           : 10; /*!< Ofs=0, w=10 DAC Channel 1 hold Time */
            uint32_t unused0          :  6;
      __RWB uint32_t THOLD2           : 10; /*!< Ofs=16, w=10 DAC Channel 2 hold time */
            uint32_t unused1          :  6;
    } B;
  } ;
#ifdef __cplusplus
  DAC_SHHR_s(): R(0x00010001u) {};
  template<typename F> void modify (F f) volatile {
    DAC_SHHR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_SHHR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DAC_SHRR_s { /*!< Sample and Hold refresh time register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TREFRESH1        :  8; /*!< Ofs=0, w=8 DAC Channel 1 refresh Time */
            uint32_t unused0          :  8;
      __RWB uint32_t TREFRESH2        :  8; /*!< Ofs=16, w=8 DAC Channel 2 refresh Time */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DAC_SHRR_s(): R(0x00000001u) {};
  template<typename F> void modify (F f) volatile {
    DAC_SHRR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DAC_SHRR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct OPAMP_OPAMP1_CSR_s { /*!< OPAMP1 control/status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OPAEN            :  1; /*!< Ofs=0, w=1 Operational amplifier Enable */
      __RWB uint32_t OPALPM           :  1; /*!< Ofs=1, w=1 Operational amplifier Low Power Mode */
      __RWB uint32_t OPAMODE          :  2; /*!< Ofs=2, w=2 Operational amplifier PGA mode */
      __RWB uint32_t PGA_GAIN         :  2; /*!< Ofs=4, w=2 Operational amplifier Programmable amplifier gain value */
            uint32_t unused0          :  2;
      __RWB uint32_t VM_SEL           :  2; /*!< Ofs=8, w=2 Inverting input selection */
      __RWB uint32_t VP_SEL           :  1; /*!< Ofs=10, w=1 Non inverted input selection */
            uint32_t unused1          :  1;
      __RWB uint32_t CALON            :  1; /*!< Ofs=12, w=1 Calibration mode enabled */
      __RWB uint32_t CALSEL           :  1; /*!< Ofs=13, w=1 Calibration selection */
      __RWB uint32_t USERTRIM         :  1; /*!< Ofs=14, w=1 allows to switch from AOP offset trimmed values to AOP offset */
      __RWB uint32_t CALOUT           :  1; /*!< Ofs=15, w=1 Operational amplifier calibration output */
            uint32_t unused2          : 15;
      __RWB uint32_t OPA_RANGE        :  1; /*!< Ofs=31, w=1 Operational amplifier power supply range for stability */
    } B;
  } ;
#ifdef __cplusplus
  OPAMP_OPAMP1_CSR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    OPAMP_OPAMP1_CSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    OPAMP_OPAMP1_CSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct OPAMP_OPAMP1_OTR_s { /*!< OPAMP1 offset trimming register in normal mode */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TRIMOFFSETN      :  5; /*!< Ofs=0, w=5 Trim for NMOS differential pairs */
            uint32_t unused0          :  3;
      __RWB uint32_t TRIMOFFSETP      :  5; /*!< Ofs=8, w=5 Trim for PMOS differential pairs */
            uint32_t unused1          : 19;
    } B;
  } ;
#ifdef __cplusplus
  OPAMP_OPAMP1_OTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    OPAMP_OPAMP1_OTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    OPAMP_OPAMP1_OTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct OPAMP_OPAMP1_LPOTR_s { /*!< OPAMP1 offset trimming register in low-power mode */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TRIMLPOFFSETN    :  5; /*!< Ofs=0, w=5 Trim for NMOS differential pairs */
            uint32_t unused0          :  3;
      __RWB uint32_t TRIMLPOFFSETP    :  5; /*!< Ofs=8, w=5 Trim for PMOS differential pairs */
            uint32_t unused1          : 19;
    } B;
  } ;
#ifdef __cplusplus
  OPAMP_OPAMP1_LPOTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    OPAMP_OPAMP1_LPOTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    OPAMP_OPAMP1_LPOTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct OPAMP_OPAMP2_CSR_s { /*!< OPAMP2 control/status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OPAEN            :  1; /*!< Ofs=0, w=1 Operational amplifier Enable */
      __RWB uint32_t OPALPM           :  1; /*!< Ofs=1, w=1 Operational amplifier Low Power Mode */
      __RWB uint32_t OPAMODE          :  2; /*!< Ofs=2, w=2 Operational amplifier PGA mode */
      __RWB uint32_t PGA_GAIN         :  2; /*!< Ofs=4, w=2 Operational amplifier Programmable amplifier gain value */
            uint32_t unused0          :  2;
      __RWB uint32_t VM_SEL           :  2; /*!< Ofs=8, w=2 Inverting input selection */
      __RWB uint32_t VP_SEL           :  1; /*!< Ofs=10, w=1 Non inverted input selection */
            uint32_t unused1          :  1;
      __RWB uint32_t CALON            :  1; /*!< Ofs=12, w=1 Calibration mode enabled */
      __RWB uint32_t CALSEL           :  1; /*!< Ofs=13, w=1 Calibration selection */
      __RWB uint32_t USERTRIM         :  1; /*!< Ofs=14, w=1 allows to switch from AOP offset trimmed values to AOP offset */
      __RWB uint32_t CALOUT           :  1; /*!< Ofs=15, w=1 Operational amplifier calibration output */
            uint32_t unused2          : 16;
    } B;
  } ;
#ifdef __cplusplus
  OPAMP_OPAMP2_CSR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    OPAMP_OPAMP2_CSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    OPAMP_OPAMP2_CSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct OPAMP_OPAMP2_OTR_s { /*!< OPAMP2 offset trimming register in normal mode */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TRIMOFFSETN      :  5; /*!< Ofs=0, w=5 Trim for NMOS differential pairs */
            uint32_t unused0          :  3;
      __RWB uint32_t TRIMOFFSETP      :  5; /*!< Ofs=8, w=5 Trim for PMOS differential pairs */
            uint32_t unused1          : 19;
    } B;
  } ;
#ifdef __cplusplus
  OPAMP_OPAMP2_OTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    OPAMP_OPAMP2_OTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    OPAMP_OPAMP2_OTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct OPAMP_OPAMP2_LPOTR_s { /*!< OPAMP2 offset trimming register in low-power mode */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TRIMLPOFFSETN    :  5; /*!< Ofs=0, w=5 Trim for NMOS differential pairs */
            uint32_t unused0          :  3;
      __RWB uint32_t TRIMLPOFFSETP    :  5; /*!< Ofs=8, w=5 Trim for PMOS differential pairs */
            uint32_t unused1          : 19;
    } B;
  } ;
#ifdef __cplusplus
  OPAMP_OPAMP2_LPOTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    OPAMP_OPAMP2_LPOTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    OPAMP_OPAMP2_LPOTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LPTIM_ISR_s { /*!< Interrupt and Status Register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t CMPM             :  1; /*!< Ofs=0, w=1 Compare match */
      __ROB uint32_t ARRM             :  1; /*!< Ofs=1, w=1 Autoreload match */
      __ROB uint32_t EXTTRIG          :  1; /*!< Ofs=2, w=1 External trigger edge event */
      __ROB uint32_t CMPOK            :  1; /*!< Ofs=3, w=1 Compare register update OK */
      __ROB uint32_t ARROK            :  1; /*!< Ofs=4, w=1 Autoreload register update OK */
      __ROB uint32_t UP               :  1; /*!< Ofs=5, w=1 Counter direction change down to up */
      __ROB uint32_t DOWN             :  1; /*!< Ofs=6, w=1 Counter direction change up to down */
            uint32_t unused0          : 25;
    } B;
  } ;
#ifdef __cplusplus
  LPTIM_ISR_s(__RO LPTIM_ISR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct LPTIM_ICR_s { /*!< Interrupt Clear Register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t CMPMCF           :  1; /*!< Ofs=0, w=1 compare match Clear Flag */
      __WOB uint32_t ARRMCF           :  1; /*!< Ofs=1, w=1 Autoreload match Clear Flag */
      __WOB uint32_t EXTTRIGCF        :  1; /*!< Ofs=2, w=1 External trigger valid edge Clear Flag */
      __WOB uint32_t CMPOKCF          :  1; /*!< Ofs=3, w=1 Compare register update OK Clear Flag */
      __WOB uint32_t ARROKCF          :  1; /*!< Ofs=4, w=1 Autoreload register update OK Clear Flag */
      __WOB uint32_t UPCF             :  1; /*!< Ofs=5, w=1 Direction change to UP Clear Flag */
      __WOB uint32_t DOWNCF           :  1; /*!< Ofs=6, w=1 Direction change to down Clear Flag */
            uint32_t unused0          : 25;
    } B;
  } ;
#ifdef __cplusplus
  LPTIM_ICR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    LPTIM_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LPTIM_IER_s { /*!< Interrupt Enable Register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CMPMIE           :  1; /*!< Ofs=0, w=1 Compare match Interrupt Enable */
      __RWB uint32_t ARRMIE           :  1; /*!< Ofs=1, w=1 Autoreload match Interrupt Enable */
      __RWB uint32_t EXTTRIGIE        :  1; /*!< Ofs=2, w=1 External trigger valid edge Interrupt Enable */
      __RWB uint32_t CMPOKIE          :  1; /*!< Ofs=3, w=1 Compare register update OK Interrupt Enable */
      __RWB uint32_t ARROKIE          :  1; /*!< Ofs=4, w=1 Autoreload register update OK Interrupt Enable */
      __RWB uint32_t UPIE             :  1; /*!< Ofs=5, w=1 Direction change to UP Interrupt Enable */
      __RWB uint32_t DOWNIE           :  1; /*!< Ofs=6, w=1 Direction change to down Interrupt Enable */
            uint32_t unused0          : 25;
    } B;
  } ;
#ifdef __cplusplus
  LPTIM_IER_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LPTIM_IER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LPTIM_IER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LPTIM_CFGR_s { /*!< Configuration Register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CKSEL            :  1; /*!< Ofs=0, w=1 Clock selector */
      __RWB uint32_t CKPOL            :  2; /*!< Ofs=1, w=2 Clock Polarity */
      __RWB uint32_t CKFLT            :  2; /*!< Ofs=3, w=2 Configurable digital filter for external clock */
            uint32_t unused0          :  1;
      __RWB uint32_t TRGFLT           :  2; /*!< Ofs=6, w=2 Configurable digital filter for trigger */
            uint32_t unused1          :  1;
      __RWB uint32_t PRESC            :  3; /*!< Ofs=9, w=3 Clock prescaler */
            uint32_t unused2          :  1;
      __RWB uint32_t TRIGSEL          :  3; /*!< Ofs=13, w=3 Trigger selector */
            uint32_t unused3          :  1;
      __RWB uint32_t TRIGEN           :  2; /*!< Ofs=17, w=2 Trigger enable and polarity */
      __RWB uint32_t TIMOUT           :  1; /*!< Ofs=19, w=1 Timeout enable */
      __RWB uint32_t WAVE             :  1; /*!< Ofs=20, w=1 Waveform shape */
      __RWB uint32_t WAVPOL           :  1; /*!< Ofs=21, w=1 Waveform shape polarity */
      __RWB uint32_t PRELOAD          :  1; /*!< Ofs=22, w=1 Registers update mode */
      __RWB uint32_t COUNTMODE        :  1; /*!< Ofs=23, w=1 counter mode enabled */
      __RWB uint32_t ENC              :  1; /*!< Ofs=24, w=1 Encoder mode enable */
            uint32_t unused4          :  7;
    } B;
  } ;
#ifdef __cplusplus
  LPTIM_CFGR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LPTIM_CFGR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LPTIM_CFGR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct LPTIM_CR_s { /*!< Control Register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ENABLE           :  1; /*!< Ofs=0, w=1 LPTIM Enable */
      __RWB uint32_t SNGSTRT          :  1; /*!< Ofs=1, w=1 LPTIM start in single mode */
      __RWB uint32_t CNTSTRT          :  1; /*!< Ofs=2, w=1 Timer start in continuous mode */
            uint32_t unused0          : 29;
    } B;
  } ;
#ifdef __cplusplus
  LPTIM_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    LPTIM_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    LPTIM_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SWPMI_CR_s { /*!< SWPMI Configuration/Control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t RXDMA            :  1; /*!< Ofs=0, w=1 Reception DMA enable */
      __RWB uint32_t TXDMA            :  1; /*!< Ofs=1, w=1 Transmission DMA enable */
      __RWB uint32_t RXMODE           :  1; /*!< Ofs=2, w=1 Reception buffering mode */
      __RWB uint32_t TXMODE           :  1; /*!< Ofs=3, w=1 Transmission buffering mode */
      __RWB uint32_t LPBK             :  1; /*!< Ofs=4, w=1 Loopback mode enable */
      __RWB uint32_t SWPME            :  1; /*!< Ofs=5, w=1 Single wire protocol master interface enable */
            uint32_t unused0          :  4;
      __RWB uint32_t DEACT            :  1; /*!< Ofs=10, w=1 Single wire protocol master interface deactivate */
            uint32_t unused1          : 21;
    } B;
  } ;
#ifdef __cplusplus
  SWPMI_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SWPMI_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SWPMI_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SWPMI_ISR_s { /*!< SWPMI Interrupt and Status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t RXBFF            :  1; /*!< Ofs=0, w=1 Receive buffer full flag */
      __ROB uint32_t TXBEF            :  1; /*!< Ofs=1, w=1 Transmit buffer empty flag */
      __ROB uint32_t RXBERF           :  1; /*!< Ofs=2, w=1 Receive CRC error flag */
      __ROB uint32_t RXOVRF           :  1; /*!< Ofs=3, w=1 Receive overrun error flag */
      __ROB uint32_t TXUNRF           :  1; /*!< Ofs=4, w=1 Transmit underrun error flag */
      __ROB uint32_t RXNE             :  1; /*!< Ofs=5, w=1 Receive data register not empty */
      __ROB uint32_t TXE              :  1; /*!< Ofs=6, w=1 Transmit data register empty */
      __ROB uint32_t TCF              :  1; /*!< Ofs=7, w=1 Transfer complete flag */
      __ROB uint32_t SRF              :  1; /*!< Ofs=8, w=1 Slave resume flag */
      __ROB uint32_t SUSP             :  1; /*!< Ofs=9, w=1 SUSPEND flag */
      __ROB uint32_t DEACTF           :  1; /*!< Ofs=10, w=1 DEACTIVATED flag */
            uint32_t unused0          : 21;
    } B;
  } ;
#ifdef __cplusplus
  SWPMI_ISR_s(__RO SWPMI_ISR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct SWPMI_ICR_s { /*!< SWPMI Interrupt Flag Clear register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t CRXBFF           :  1; /*!< Ofs=0, w=1 Clear receive buffer full flag */
      __WOB uint32_t CTXBEF           :  1; /*!< Ofs=1, w=1 Clear transmit buffer empty flag */
      __WOB uint32_t CRXBERF          :  1; /*!< Ofs=2, w=1 Clear receive CRC error flag */
      __WOB uint32_t CRXOVRF          :  1; /*!< Ofs=3, w=1 Clear receive overrun error flag */
      __WOB uint32_t CTXUNRF          :  1; /*!< Ofs=4, w=1 Clear transmit underrun error flag */
            uint32_t unused0          :  2;
      __WOB uint32_t CTCF             :  1; /*!< Ofs=7, w=1 Clear transfer complete flag */
      __WOB uint32_t CSRF             :  1; /*!< Ofs=8, w=1 Clear slave resume flag */
            uint32_t unused1          : 23;
    } B;
  } ;
#ifdef __cplusplus
  SWPMI_ICR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    SWPMI_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SWPMI_IER_s { /*!< SWPMI Interrupt Enable register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t RXBFIE           :  1; /*!< Ofs=0, w=1 Receive buffer full interrupt enable */
      __RWB uint32_t TXBEIE           :  1; /*!< Ofs=1, w=1 Transmit buffer empty interrupt enable */
      __RWB uint32_t RXBERIE          :  1; /*!< Ofs=2, w=1 Receive CRC error interrupt enable */
      __RWB uint32_t RXOVRIE          :  1; /*!< Ofs=3, w=1 Receive overrun error interrupt enable */
      __RWB uint32_t TXUNRIE          :  1; /*!< Ofs=4, w=1 Transmit underrun error interrupt enable */
      __RWB uint32_t RIE              :  1; /*!< Ofs=5, w=1 Receive interrupt enable */
      __RWB uint32_t TIE              :  1; /*!< Ofs=6, w=1 Transmit interrupt enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=7, w=1 Transmit complete interrupt enable */
      __RWB uint32_t SRIE             :  1; /*!< Ofs=8, w=1 Slave resume interrupt enable */
            uint32_t unused0          : 23;
    } B;
  } ;
#ifdef __cplusplus
  SWPMI_IER_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SWPMI_IER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SWPMI_IER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SYSCFG_MEMRMP_s { /*!< memory remap register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t MEM_MODE         :  3; /*!< Ofs=0, w=3 Memory mapping selection */
      __RWB uint32_t QFS              :  1; /*!< Ofs=3, w=1 QUADSPI memory mapping swap */
            uint32_t unused0          :  4;
      __RWB uint32_t FB_MODE          :  1; /*!< Ofs=8, w=1 Flash Bank mode selection */
            uint32_t unused1          : 23;
    } B;
  } ;
#ifdef __cplusplus
  SYSCFG_MEMRMP_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SYSCFG_MEMRMP_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SYSCFG_MEMRMP_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SYSCFG_CFGR1_s { /*!< configuration register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FWDIS            :  1; /*!< Ofs=0, w=1 Firewall disable */
            uint32_t unused0          :  7;
      __RWB uint32_t BOOSTEN          :  1; /*!< Ofs=8, w=1 I/O analog switch voltage booster enable */
            uint32_t unused1          :  7;
      __RWB uint32_t I2C_PB6_FMP      :  1; /*!< Ofs=16, w=1 Fast-mode Plus (Fm+) driving capability activation on PB6 */
      __RWB uint32_t I2C_PB7_FMP      :  1; /*!< Ofs=17, w=1 Fast-mode Plus (Fm+) driving capability activation on PB7 */
      __RWB uint32_t I2C_PB8_FMP      :  1; /*!< Ofs=18, w=1 Fast-mode Plus (Fm+) driving capability activation on PB8 */
      __RWB uint32_t I2C_PB9_FMP      :  1; /*!< Ofs=19, w=1 Fast-mode Plus (Fm+) driving capability activation on PB9 */
      __RWB uint32_t I2C1_FMP         :  1; /*!< Ofs=20, w=1 I2C1 Fast-mode Plus driving capability activation */
      __RWB uint32_t I2C2_FMP         :  1; /*!< Ofs=21, w=1 I2C2 Fast-mode Plus driving capability activation */
      __RWB uint32_t I2C3_FMP         :  1; /*!< Ofs=22, w=1 I2C3 Fast-mode Plus driving capability activation */
            uint32_t unused2          :  3;
      __RWB uint32_t FPU_IE           :  6; /*!< Ofs=26, w=6 Floating Point Unit interrupts enable bits */
    } B;
  } ;
#ifdef __cplusplus
  SYSCFG_CFGR1_s(): R(0x7C000001u) {};
  template<typename F> void modify (F f) volatile {
    SYSCFG_CFGR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SYSCFG_CFGR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SYSCFG_EXTICR1_s { /*!< external interrupt configuration register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EXTI0            :  3; /*!< Ofs=0, w=3 EXTI 0 configuration bits */
            uint32_t unused0          :  1;
      __RWB uint32_t EXTI1            :  3; /*!< Ofs=4, w=3 EXTI 1 configuration bits */
            uint32_t unused1          :  1;
      __RWB uint32_t EXTI2            :  3; /*!< Ofs=8, w=3 EXTI 2 configuration bits */
            uint32_t unused2          :  1;
      __RWB uint32_t EXTI3            :  3; /*!< Ofs=12, w=3 EXTI 3 configuration bits */
            uint32_t unused3          : 17;
    } B;
  } ;
#ifdef __cplusplus
  SYSCFG_EXTICR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SYSCFG_EXTICR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SYSCFG_EXTICR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SYSCFG_EXTICR2_s { /*!< external interrupt configuration register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EXTI4            :  3; /*!< Ofs=0, w=3 EXTI 4 configuration bits */
            uint32_t unused0          :  1;
      __RWB uint32_t EXTI5            :  3; /*!< Ofs=4, w=3 EXTI 5 configuration bits */
            uint32_t unused1          :  1;
      __RWB uint32_t EXTI6            :  3; /*!< Ofs=8, w=3 EXTI 6 configuration bits */
            uint32_t unused2          :  1;
      __RWB uint32_t EXTI7            :  3; /*!< Ofs=12, w=3 EXTI 7 configuration bits */
            uint32_t unused3          : 17;
    } B;
  } ;
#ifdef __cplusplus
  SYSCFG_EXTICR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SYSCFG_EXTICR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SYSCFG_EXTICR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SYSCFG_EXTICR3_s { /*!< external interrupt configuration register 3 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EXTI8            :  3; /*!< Ofs=0, w=3 EXTI 8 configuration bits */
            uint32_t unused0          :  1;
      __RWB uint32_t EXTI9            :  3; /*!< Ofs=4, w=3 EXTI 9 configuration bits */
            uint32_t unused1          :  1;
      __RWB uint32_t EXTI10           :  3; /*!< Ofs=8, w=3 EXTI 10 configuration bits */
            uint32_t unused2          :  1;
      __RWB uint32_t EXTI11           :  3; /*!< Ofs=12, w=3 EXTI 11 configuration bits */
            uint32_t unused3          : 17;
    } B;
  } ;
#ifdef __cplusplus
  SYSCFG_EXTICR3_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SYSCFG_EXTICR3_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SYSCFG_EXTICR3_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SYSCFG_EXTICR4_s { /*!< external interrupt configuration register 4 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EXTI12           :  3; /*!< Ofs=0, w=3 EXTI12 configuration bits */
            uint32_t unused0          :  1;
      __RWB uint32_t EXTI13           :  3; /*!< Ofs=4, w=3 EXTI13 configuration bits */
            uint32_t unused1          :  1;
      __RWB uint32_t EXTI14           :  3; /*!< Ofs=8, w=3 EXTI14 configuration bits */
            uint32_t unused2          :  1;
      __RWB uint32_t EXTI15           :  3; /*!< Ofs=12, w=3 EXTI15 configuration bits */
            uint32_t unused3          : 17;
    } B;
  } ;
#ifdef __cplusplus
  SYSCFG_EXTICR4_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SYSCFG_EXTICR4_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SYSCFG_EXTICR4_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SYSCFG_SCSR_s { /*!< SCSR */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SRAM2ER          :  1; /*!< Ofs=0, w=1 SRAM2 Erase */
      __ROB uint32_t SRAM2BSY         :  1; /*!< Ofs=1, w=1 SRAM2 busy by erase operation */
            uint32_t unused0          : 30;
    } B;
  } ;
#ifdef __cplusplus
  SYSCFG_SCSR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SYSCFG_SCSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SYSCFG_SCSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SYSCFG_CFGR2_s { /*!< CFGR2 */
  union {
      __RWB uint32_t R;
    struct {
      __WOB uint32_t CLL              :  1; /*!< Ofs=0, w=1 OCKUP (Hardfault) output enable bit */
      __WOB uint32_t SPL              :  1; /*!< Ofs=1, w=1 SRAM2 parity lock bit */
      __WOB uint32_t PVDL             :  1; /*!< Ofs=2, w=1 PVD lock enable bit */
      __WOB uint32_t ECCL             :  1; /*!< Ofs=3, w=1 ECC Lock */
            uint32_t unused0          :  4;
      __RWB uint32_t SPF              :  1; /*!< Ofs=8, w=1 SRAM2 parity error flag */
            uint32_t unused1          : 23;
    } B;
  } ;
#ifdef __cplusplus
  SYSCFG_CFGR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SYSCFG_CFGR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SYSCFG_CFGR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SYSCFG_SWPR_s { /*!< SWPR */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t P0WP             :  1; /*!< Ofs=0, w=1 P0WP */
      __WOB uint32_t P1WP             :  1; /*!< Ofs=1, w=1 P1WP */
      __WOB uint32_t P2WP             :  1; /*!< Ofs=2, w=1 P2WP */
      __WOB uint32_t P3WP             :  1; /*!< Ofs=3, w=1 P3WP */
      __WOB uint32_t P4WP             :  1; /*!< Ofs=4, w=1 P4WP */
      __WOB uint32_t P5WP             :  1; /*!< Ofs=5, w=1 P5WP */
      __WOB uint32_t P6WP             :  1; /*!< Ofs=6, w=1 P6WP */
      __WOB uint32_t P7WP             :  1; /*!< Ofs=7, w=1 P7WP */
      __WOB uint32_t P8WP             :  1; /*!< Ofs=8, w=1 P8WP */
      __WOB uint32_t P9WP             :  1; /*!< Ofs=9, w=1 P9WP */
      __WOB uint32_t P10WP            :  1; /*!< Ofs=10, w=1 P10WP */
      __WOB uint32_t P11WP            :  1; /*!< Ofs=11, w=1 P11WP */
      __WOB uint32_t P12WP            :  1; /*!< Ofs=12, w=1 P12WP */
      __WOB uint32_t P13WP            :  1; /*!< Ofs=13, w=1 P13WP */
      __WOB uint32_t P14WP            :  1; /*!< Ofs=14, w=1 P14WP */
      __WOB uint32_t P15WP            :  1; /*!< Ofs=15, w=1 P15WP */
      __WOB uint32_t P16WP            :  1; /*!< Ofs=16, w=1 P16WP */
      __WOB uint32_t P17WP            :  1; /*!< Ofs=17, w=1 P17WP */
      __WOB uint32_t P18WP            :  1; /*!< Ofs=18, w=1 P18WP */
      __WOB uint32_t P19WP            :  1; /*!< Ofs=19, w=1 P19WP */
      __WOB uint32_t P20WP            :  1; /*!< Ofs=20, w=1 P20WP */
      __WOB uint32_t P21WP            :  1; /*!< Ofs=21, w=1 P21WP */
      __WOB uint32_t P22WP            :  1; /*!< Ofs=22, w=1 P22WP */
      __WOB uint32_t P23WP            :  1; /*!< Ofs=23, w=1 P23WP */
      __WOB uint32_t P24WP            :  1; /*!< Ofs=24, w=1 P24WP */
      __WOB uint32_t P25WP            :  1; /*!< Ofs=25, w=1 P25WP */
      __WOB uint32_t P26WP            :  1; /*!< Ofs=26, w=1 P26WP */
      __WOB uint32_t P27WP            :  1; /*!< Ofs=27, w=1 P27WP */
      __WOB uint32_t P28WP            :  1; /*!< Ofs=28, w=1 P28WP */
      __WOB uint32_t P29WP            :  1; /*!< Ofs=29, w=1 P29WP */
      __WOB uint32_t P30WP            :  1; /*!< Ofs=30, w=1 P30WP */
      __WOB uint32_t P31WP            :  1; /*!< Ofs=31, w=1 SRAM2 page 31 write protection */
    } B;
  } ;
#ifdef __cplusplus
  SYSCFG_SWPR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    SYSCFG_SWPR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct VREF_CSR_s { /*!< VREF control and status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ENVR             :  1; /*!< Ofs=0, w=1 Voltage reference buffer enable */
      __RWB uint32_t HIZ              :  1; /*!< Ofs=1, w=1 High impedance mode */
      __RWB uint32_t VRS              :  1; /*!< Ofs=2, w=1 Voltage reference scale */
      __ROB uint32_t VRR              :  1; /*!< Ofs=3, w=1 Voltage reference buffer ready */
            uint32_t unused0          : 28;
    } B;
  } ;
#ifdef __cplusplus
  VREF_CSR_s(): R(0x00000002u) {};
  template<typename F> void modify (F f) volatile {
    VREF_CSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    VREF_CSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct COMP_COMP1_CSR_s { /*!< Comparator 1 control and status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t COMP1_EN         :  1; /*!< Ofs=0, w=1 Comparator 1 enable bit */
            uint32_t unused0          :  1;
      __RWB uint32_t COMP1_PWRMODE    :  2; /*!< Ofs=2, w=2 Power Mode of the comparator 1 */
      __RWB uint32_t COMP1_INMSEL     :  3; /*!< Ofs=4, w=3 Comparator 1 Input Minus connection configuration bit */
      __RWB uint32_t COMP1_INPSEL     :  2; /*!< Ofs=7, w=2 Comparator1 input plus selection bit */
            uint32_t unused1          :  6;
      __RWB uint32_t COMP1_POLARITY   :  1; /*!< Ofs=15, w=1 Comparator 1 polarity selection bit */
      __RWB uint32_t COMP1_HYST       :  2; /*!< Ofs=16, w=2 Comparator 1 hysteresis selection bits */
      __RWB uint32_t COMP1_BLANKING   :  3; /*!< Ofs=18, w=3 Comparator 1 blanking source selection bits */
            uint32_t unused2          :  1;
      __RWB uint32_t COMP1_BRGEN      :  1; /*!< Ofs=22, w=1 Scaler bridge enable */
      __RWB uint32_t COMP1_SCALEN     :  1; /*!< Ofs=23, w=1 Voltage scaler enable bit */
            uint32_t unused3          :  1;
      __RWB uint32_t COMP1_INMESEL    :  2; /*!< Ofs=25, w=2 comparator 1 input minus extended selection bits */
            uint32_t unused4          :  3;
      __ROB uint32_t COMP1_VALUE      :  1; /*!< Ofs=30, w=1 Comparator 1 output status bit */
      __WOB uint32_t COMP1_LOCK       :  1; /*!< Ofs=31, w=1 COMP1_CSR register lock bit */
    } B;
  } ;
#ifdef __cplusplus
  COMP_COMP1_CSR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    COMP_COMP1_CSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    COMP_COMP1_CSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct COMP_COMP2_CSR_s { /*!< Comparator 2 control and status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t COMP2_EN         :  1; /*!< Ofs=0, w=1 Comparator 2 enable bit */
            uint32_t unused0          :  1;
      __RWB uint32_t COMP2_PWRMODE    :  2; /*!< Ofs=2, w=2 Power Mode of the comparator 2 */
      __RWB uint32_t COMP2_INMSEL     :  3; /*!< Ofs=4, w=3 Comparator 2 Input Minus connection configuration bit */
      __RWB uint32_t COMP2_INPSEL     :  2; /*!< Ofs=7, w=2 Comparator 2 Input Plus connection configuration bit */
      __RWB uint32_t COMP2_WINMODE    :  1; /*!< Ofs=9, w=1 Windows mode selection bit */
            uint32_t unused1          :  5;
      __RWB uint32_t COMP2_POLARITY   :  1; /*!< Ofs=15, w=1 Comparator 2 polarity selection bit */
      __RWB uint32_t COMP2_HYST       :  2; /*!< Ofs=16, w=2 Comparator 2 hysteresis selection bits */
      __RWB uint32_t COMP2_BLANKING   :  3; /*!< Ofs=18, w=3 Comparator 2 blanking source selection bits */
            uint32_t unused2          :  1;
      __RWB uint32_t COMP2_BRGEN      :  1; /*!< Ofs=22, w=1 Scaler bridge enable */
      __RWB uint32_t COMP2_SCALEN     :  1; /*!< Ofs=23, w=1 Voltage scaler enable bit */
            uint32_t unused3          :  1;
      __RWB uint32_t COMP2_INMESEL    :  2; /*!< Ofs=25, w=2 comparator 2 input minus extended selection bits */
            uint32_t unused4          :  3;
      __ROB uint32_t COMP2_VALUE      :  1; /*!< Ofs=30, w=1 Comparator 2 output status bit */
      __WOB uint32_t COMP2_LOCK       :  1; /*!< Ofs=31, w=1 COMP2_CSR register lock bit */
    } B;
  } ;
#ifdef __cplusplus
  COMP_COMP2_CSR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    COMP_COMP2_CSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    COMP_COMP2_CSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_IMR1_s { /*!< Interrupt mask register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t MR0              :  1; /*!< Ofs=0, w=1 Interrupt Mask on line 0 */
      __RWB uint32_t MR1              :  1; /*!< Ofs=1, w=1 Interrupt Mask on line 1 */
      __RWB uint32_t MR2              :  1; /*!< Ofs=2, w=1 Interrupt Mask on line 2 */
      __RWB uint32_t MR3              :  1; /*!< Ofs=3, w=1 Interrupt Mask on line 3 */
      __RWB uint32_t MR4              :  1; /*!< Ofs=4, w=1 Interrupt Mask on line 4 */
      __RWB uint32_t MR5              :  1; /*!< Ofs=5, w=1 Interrupt Mask on line 5 */
      __RWB uint32_t MR6              :  1; /*!< Ofs=6, w=1 Interrupt Mask on line 6 */
      __RWB uint32_t MR7              :  1; /*!< Ofs=7, w=1 Interrupt Mask on line 7 */
      __RWB uint32_t MR8              :  1; /*!< Ofs=8, w=1 Interrupt Mask on line 8 */
      __RWB uint32_t MR9              :  1; /*!< Ofs=9, w=1 Interrupt Mask on line 9 */
      __RWB uint32_t MR10             :  1; /*!< Ofs=10, w=1 Interrupt Mask on line 10 */
      __RWB uint32_t MR11             :  1; /*!< Ofs=11, w=1 Interrupt Mask on line 11 */
      __RWB uint32_t MR12             :  1; /*!< Ofs=12, w=1 Interrupt Mask on line 12 */
      __RWB uint32_t MR13             :  1; /*!< Ofs=13, w=1 Interrupt Mask on line 13 */
      __RWB uint32_t MR14             :  1; /*!< Ofs=14, w=1 Interrupt Mask on line 14 */
      __RWB uint32_t MR15             :  1; /*!< Ofs=15, w=1 Interrupt Mask on line 15 */
      __RWB uint32_t MR16             :  1; /*!< Ofs=16, w=1 Interrupt Mask on line 16 */
      __RWB uint32_t MR17             :  1; /*!< Ofs=17, w=1 Interrupt Mask on line 17 */
      __RWB uint32_t MR18             :  1; /*!< Ofs=18, w=1 Interrupt Mask on line 18 */
      __RWB uint32_t MR19             :  1; /*!< Ofs=19, w=1 Interrupt Mask on line 19 */
      __RWB uint32_t MR20             :  1; /*!< Ofs=20, w=1 Interrupt Mask on line 20 */
      __RWB uint32_t MR21             :  1; /*!< Ofs=21, w=1 Interrupt Mask on line 21 */
      __RWB uint32_t MR22             :  1; /*!< Ofs=22, w=1 Interrupt Mask on line 22 */
      __RWB uint32_t MR23             :  1; /*!< Ofs=23, w=1 Interrupt Mask on line 23 */
      __RWB uint32_t MR24             :  1; /*!< Ofs=24, w=1 Interrupt Mask on line 24 */
      __RWB uint32_t MR25             :  1; /*!< Ofs=25, w=1 Interrupt Mask on line 25 */
      __RWB uint32_t MR26             :  1; /*!< Ofs=26, w=1 Interrupt Mask on line 26 */
      __RWB uint32_t MR27             :  1; /*!< Ofs=27, w=1 Interrupt Mask on line 27 */
      __RWB uint32_t MR28             :  1; /*!< Ofs=28, w=1 Interrupt Mask on line 28 */
      __RWB uint32_t MR29             :  1; /*!< Ofs=29, w=1 Interrupt Mask on line 29 */
      __RWB uint32_t MR30             :  1; /*!< Ofs=30, w=1 Interrupt Mask on line 30 */
      __RWB uint32_t MR31             :  1; /*!< Ofs=31, w=1 Interrupt Mask on line 31 */
    } B;
  } ;
#ifdef __cplusplus
  EXTI_IMR1_s(): R(0xFF820000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_IMR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_IMR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_EMR1_s { /*!< Event mask register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t MR0              :  1; /*!< Ofs=0, w=1 Event Mask on line 0 */
      __RWB uint32_t MR1              :  1; /*!< Ofs=1, w=1 Event Mask on line 1 */
      __RWB uint32_t MR2              :  1; /*!< Ofs=2, w=1 Event Mask on line 2 */
      __RWB uint32_t MR3              :  1; /*!< Ofs=3, w=1 Event Mask on line 3 */
      __RWB uint32_t MR4              :  1; /*!< Ofs=4, w=1 Event Mask on line 4 */
      __RWB uint32_t MR5              :  1; /*!< Ofs=5, w=1 Event Mask on line 5 */
      __RWB uint32_t MR6              :  1; /*!< Ofs=6, w=1 Event Mask on line 6 */
      __RWB uint32_t MR7              :  1; /*!< Ofs=7, w=1 Event Mask on line 7 */
      __RWB uint32_t MR8              :  1; /*!< Ofs=8, w=1 Event Mask on line 8 */
      __RWB uint32_t MR9              :  1; /*!< Ofs=9, w=1 Event Mask on line 9 */
      __RWB uint32_t MR10             :  1; /*!< Ofs=10, w=1 Event Mask on line 10 */
      __RWB uint32_t MR11             :  1; /*!< Ofs=11, w=1 Event Mask on line 11 */
      __RWB uint32_t MR12             :  1; /*!< Ofs=12, w=1 Event Mask on line 12 */
      __RWB uint32_t MR13             :  1; /*!< Ofs=13, w=1 Event Mask on line 13 */
      __RWB uint32_t MR14             :  1; /*!< Ofs=14, w=1 Event Mask on line 14 */
      __RWB uint32_t MR15             :  1; /*!< Ofs=15, w=1 Event Mask on line 15 */
      __RWB uint32_t MR16             :  1; /*!< Ofs=16, w=1 Event Mask on line 16 */
      __RWB uint32_t MR17             :  1; /*!< Ofs=17, w=1 Event Mask on line 17 */
      __RWB uint32_t MR18             :  1; /*!< Ofs=18, w=1 Event Mask on line 18 */
      __RWB uint32_t MR19             :  1; /*!< Ofs=19, w=1 Event Mask on line 19 */
      __RWB uint32_t MR20             :  1; /*!< Ofs=20, w=1 Event Mask on line 20 */
      __RWB uint32_t MR21             :  1; /*!< Ofs=21, w=1 Event Mask on line 21 */
      __RWB uint32_t MR22             :  1; /*!< Ofs=22, w=1 Event Mask on line 22 */
      __RWB uint32_t MR23             :  1; /*!< Ofs=23, w=1 Event Mask on line 23 */
      __RWB uint32_t MR24             :  1; /*!< Ofs=24, w=1 Event Mask on line 24 */
      __RWB uint32_t MR25             :  1; /*!< Ofs=25, w=1 Event Mask on line 25 */
      __RWB uint32_t MR26             :  1; /*!< Ofs=26, w=1 Event Mask on line 26 */
      __RWB uint32_t MR27             :  1; /*!< Ofs=27, w=1 Event Mask on line 27 */
      __RWB uint32_t MR28             :  1; /*!< Ofs=28, w=1 Event Mask on line 28 */
      __RWB uint32_t MR29             :  1; /*!< Ofs=29, w=1 Event Mask on line 29 */
      __RWB uint32_t MR30             :  1; /*!< Ofs=30, w=1 Event Mask on line 30 */
      __RWB uint32_t MR31             :  1; /*!< Ofs=31, w=1 Event Mask on line 31 */
    } B;
  } ;
#ifdef __cplusplus
  EXTI_EMR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_EMR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_EMR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_RTSR1_s { /*!< Rising Trigger selection register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TR0              :  1; /*!< Ofs=0, w=1 Rising trigger event configuration of line 0 */
      __RWB uint32_t TR1              :  1; /*!< Ofs=1, w=1 Rising trigger event configuration of line 1 */
      __RWB uint32_t TR2              :  1; /*!< Ofs=2, w=1 Rising trigger event configuration of line 2 */
      __RWB uint32_t TR3              :  1; /*!< Ofs=3, w=1 Rising trigger event configuration of line 3 */
      __RWB uint32_t TR4              :  1; /*!< Ofs=4, w=1 Rising trigger event configuration of line 4 */
      __RWB uint32_t TR5              :  1; /*!< Ofs=5, w=1 Rising trigger event configuration of line 5 */
      __RWB uint32_t TR6              :  1; /*!< Ofs=6, w=1 Rising trigger event configuration of line 6 */
      __RWB uint32_t TR7              :  1; /*!< Ofs=7, w=1 Rising trigger event configuration of line 7 */
      __RWB uint32_t TR8              :  1; /*!< Ofs=8, w=1 Rising trigger event configuration of line 8 */
      __RWB uint32_t TR9              :  1; /*!< Ofs=9, w=1 Rising trigger event configuration of line 9 */
      __RWB uint32_t TR10             :  1; /*!< Ofs=10, w=1 Rising trigger event configuration of line 10 */
      __RWB uint32_t TR11             :  1; /*!< Ofs=11, w=1 Rising trigger event configuration of line 11 */
      __RWB uint32_t TR12             :  1; /*!< Ofs=12, w=1 Rising trigger event configuration of line 12 */
      __RWB uint32_t TR13             :  1; /*!< Ofs=13, w=1 Rising trigger event configuration of line 13 */
      __RWB uint32_t TR14             :  1; /*!< Ofs=14, w=1 Rising trigger event configuration of line 14 */
      __RWB uint32_t TR15             :  1; /*!< Ofs=15, w=1 Rising trigger event configuration of line 15 */
      __RWB uint32_t TR16             :  1; /*!< Ofs=16, w=1 Rising trigger event configuration of line 16 */
            uint32_t unused0          :  1;
      __RWB uint32_t TR18             :  1; /*!< Ofs=18, w=1 Rising trigger event configuration of line 18 */
      __RWB uint32_t TR19             :  1; /*!< Ofs=19, w=1 Rising trigger event configuration of line 19 */
      __RWB uint32_t TR20             :  1; /*!< Ofs=20, w=1 Rising trigger event configuration of line 20 */
      __RWB uint32_t TR21             :  1; /*!< Ofs=21, w=1 Rising trigger event configuration of line 21 */
      __RWB uint32_t TR22             :  1; /*!< Ofs=22, w=1 Rising trigger event configuration of line 22 */
            uint32_t unused1          :  9;
    } B;
  } ;
#ifdef __cplusplus
  EXTI_RTSR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_RTSR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_RTSR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_FTSR1_s { /*!< Falling Trigger selection register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TR0              :  1; /*!< Ofs=0, w=1 Falling trigger event configuration of line 0 */
      __RWB uint32_t TR1              :  1; /*!< Ofs=1, w=1 Falling trigger event configuration of line 1 */
      __RWB uint32_t TR2              :  1; /*!< Ofs=2, w=1 Falling trigger event configuration of line 2 */
      __RWB uint32_t TR3              :  1; /*!< Ofs=3, w=1 Falling trigger event configuration of line 3 */
      __RWB uint32_t TR4              :  1; /*!< Ofs=4, w=1 Falling trigger event configuration of line 4 */
      __RWB uint32_t TR5              :  1; /*!< Ofs=5, w=1 Falling trigger event configuration of line 5 */
      __RWB uint32_t TR6              :  1; /*!< Ofs=6, w=1 Falling trigger event configuration of line 6 */
      __RWB uint32_t TR7              :  1; /*!< Ofs=7, w=1 Falling trigger event configuration of line 7 */
      __RWB uint32_t TR8              :  1; /*!< Ofs=8, w=1 Falling trigger event configuration of line 8 */
      __RWB uint32_t TR9              :  1; /*!< Ofs=9, w=1 Falling trigger event configuration of line 9 */
      __RWB uint32_t TR10             :  1; /*!< Ofs=10, w=1 Falling trigger event configuration of line 10 */
      __RWB uint32_t TR11             :  1; /*!< Ofs=11, w=1 Falling trigger event configuration of line 11 */
      __RWB uint32_t TR12             :  1; /*!< Ofs=12, w=1 Falling trigger event configuration of line 12 */
      __RWB uint32_t TR13             :  1; /*!< Ofs=13, w=1 Falling trigger event configuration of line 13 */
      __RWB uint32_t TR14             :  1; /*!< Ofs=14, w=1 Falling trigger event configuration of line 14 */
      __RWB uint32_t TR15             :  1; /*!< Ofs=15, w=1 Falling trigger event configuration of line 15 */
      __RWB uint32_t TR16             :  1; /*!< Ofs=16, w=1 Falling trigger event configuration of line 16 */
            uint32_t unused0          :  1;
      __RWB uint32_t TR18             :  1; /*!< Ofs=18, w=1 Falling trigger event configuration of line 18 */
      __RWB uint32_t TR19             :  1; /*!< Ofs=19, w=1 Falling trigger event configuration of line 19 */
      __RWB uint32_t TR20             :  1; /*!< Ofs=20, w=1 Falling trigger event configuration of line 20 */
      __RWB uint32_t TR21             :  1; /*!< Ofs=21, w=1 Falling trigger event configuration of line 21 */
      __RWB uint32_t TR22             :  1; /*!< Ofs=22, w=1 Falling trigger event configuration of line 22 */
            uint32_t unused1          :  9;
    } B;
  } ;
#ifdef __cplusplus
  EXTI_FTSR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_FTSR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_FTSR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_SWIER1_s { /*!< Software interrupt event register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SWIER0           :  1; /*!< Ofs=0, w=1 Software Interrupt on line 0 */
      __RWB uint32_t SWIER1           :  1; /*!< Ofs=1, w=1 Software Interrupt on line 1 */
      __RWB uint32_t SWIER2           :  1; /*!< Ofs=2, w=1 Software Interrupt on line 2 */
      __RWB uint32_t SWIER3           :  1; /*!< Ofs=3, w=1 Software Interrupt on line 3 */
      __RWB uint32_t SWIER4           :  1; /*!< Ofs=4, w=1 Software Interrupt on line 4 */
      __RWB uint32_t SWIER5           :  1; /*!< Ofs=5, w=1 Software Interrupt on line 5 */
      __RWB uint32_t SWIER6           :  1; /*!< Ofs=6, w=1 Software Interrupt on line 6 */
      __RWB uint32_t SWIER7           :  1; /*!< Ofs=7, w=1 Software Interrupt on line 7 */
      __RWB uint32_t SWIER8           :  1; /*!< Ofs=8, w=1 Software Interrupt on line 8 */
      __RWB uint32_t SWIER9           :  1; /*!< Ofs=9, w=1 Software Interrupt on line 9 */
      __RWB uint32_t SWIER10          :  1; /*!< Ofs=10, w=1 Software Interrupt on line 10 */
      __RWB uint32_t SWIER11          :  1; /*!< Ofs=11, w=1 Software Interrupt on line 11 */
      __RWB uint32_t SWIER12          :  1; /*!< Ofs=12, w=1 Software Interrupt on line 12 */
      __RWB uint32_t SWIER13          :  1; /*!< Ofs=13, w=1 Software Interrupt on line 13 */
      __RWB uint32_t SWIER14          :  1; /*!< Ofs=14, w=1 Software Interrupt on line 14 */
      __RWB uint32_t SWIER15          :  1; /*!< Ofs=15, w=1 Software Interrupt on line 15 */
      __RWB uint32_t SWIER16          :  1; /*!< Ofs=16, w=1 Software Interrupt on line 16 */
            uint32_t unused0          :  1;
      __RWB uint32_t SWIER18          :  1; /*!< Ofs=18, w=1 Software Interrupt on line 18 */
      __RWB uint32_t SWIER19          :  1; /*!< Ofs=19, w=1 Software Interrupt on line 19 */
      __RWB uint32_t SWIER20          :  1; /*!< Ofs=20, w=1 Software Interrupt on line 20 */
      __RWB uint32_t SWIER21          :  1; /*!< Ofs=21, w=1 Software Interrupt on line 21 */
      __RWB uint32_t SWIER22          :  1; /*!< Ofs=22, w=1 Software Interrupt on line 22 */
            uint32_t unused1          :  9;
    } B;
  } ;
#ifdef __cplusplus
  EXTI_SWIER1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_SWIER1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_SWIER1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_PR1_s { /*!< Pending register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PR0              :  1; /*!< Ofs=0, w=1 Pending bit 0 */
      __RWB uint32_t PR1              :  1; /*!< Ofs=1, w=1 Pending bit 1 */
      __RWB uint32_t PR2              :  1; /*!< Ofs=2, w=1 Pending bit 2 */
      __RWB uint32_t PR3              :  1; /*!< Ofs=3, w=1 Pending bit 3 */
      __RWB uint32_t PR4              :  1; /*!< Ofs=4, w=1 Pending bit 4 */
      __RWB uint32_t PR5              :  1; /*!< Ofs=5, w=1 Pending bit 5 */
      __RWB uint32_t PR6              :  1; /*!< Ofs=6, w=1 Pending bit 6 */
      __RWB uint32_t PR7              :  1; /*!< Ofs=7, w=1 Pending bit 7 */
      __RWB uint32_t PR8              :  1; /*!< Ofs=8, w=1 Pending bit 8 */
      __RWB uint32_t PR9              :  1; /*!< Ofs=9, w=1 Pending bit 9 */
      __RWB uint32_t PR10             :  1; /*!< Ofs=10, w=1 Pending bit 10 */
      __RWB uint32_t PR11             :  1; /*!< Ofs=11, w=1 Pending bit 11 */
      __RWB uint32_t PR12             :  1; /*!< Ofs=12, w=1 Pending bit 12 */
      __RWB uint32_t PR13             :  1; /*!< Ofs=13, w=1 Pending bit 13 */
      __RWB uint32_t PR14             :  1; /*!< Ofs=14, w=1 Pending bit 14 */
      __RWB uint32_t PR15             :  1; /*!< Ofs=15, w=1 Pending bit 15 */
      __RWB uint32_t PR16             :  1; /*!< Ofs=16, w=1 Pending bit 16 */
            uint32_t unused0          :  1;
      __RWB uint32_t PR18             :  1; /*!< Ofs=18, w=1 Pending bit 18 */
      __RWB uint32_t PR19             :  1; /*!< Ofs=19, w=1 Pending bit 19 */
      __RWB uint32_t PR20             :  1; /*!< Ofs=20, w=1 Pending bit 20 */
      __RWB uint32_t PR21             :  1; /*!< Ofs=21, w=1 Pending bit 21 */
      __RWB uint32_t PR22             :  1; /*!< Ofs=22, w=1 Pending bit 22 */
            uint32_t unused1          :  9;
    } B;
  } ;
#ifdef __cplusplus
  EXTI_PR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_PR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_PR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_IMR2_s { /*!< Interrupt mask register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t MR32             :  1; /*!< Ofs=0, w=1 Interrupt Mask on external/internal line 32 */
      __RWB uint32_t MR33             :  1; /*!< Ofs=1, w=1 Interrupt Mask on external/internal line 33 */
      __RWB uint32_t MR34             :  1; /*!< Ofs=2, w=1 Interrupt Mask on external/internal line 34 */
      __RWB uint32_t MR35             :  1; /*!< Ofs=3, w=1 Interrupt Mask on external/internal line 35 */
      __RWB uint32_t MR36             :  1; /*!< Ofs=4, w=1 Interrupt Mask on external/internal line 36 */
      __RWB uint32_t MR37             :  1; /*!< Ofs=5, w=1 Interrupt Mask on external/internal line 37 */
      __RWB uint32_t MR38             :  1; /*!< Ofs=6, w=1 Interrupt Mask on external/internal line 38 */
      __RWB uint32_t MR39             :  1; /*!< Ofs=7, w=1 Interrupt Mask on external/internal line 39 */
            uint32_t unused0          : 24;
    } B;
  } ;
#ifdef __cplusplus
  EXTI_IMR2_s(): R(0xFFFFFF87u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_IMR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_IMR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_EMR2_s { /*!< Event mask register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t MR32             :  1; /*!< Ofs=0, w=1 Event mask on external/internal line 32 */
      __RWB uint32_t MR33             :  1; /*!< Ofs=1, w=1 Event mask on external/internal line 33 */
      __RWB uint32_t MR34             :  1; /*!< Ofs=2, w=1 Event mask on external/internal line 34 */
      __RWB uint32_t MR35             :  1; /*!< Ofs=3, w=1 Event mask on external/internal line 35 */
      __RWB uint32_t MR36             :  1; /*!< Ofs=4, w=1 Event mask on external/internal line 36 */
      __RWB uint32_t MR37             :  1; /*!< Ofs=5, w=1 Event mask on external/internal line 37 */
      __RWB uint32_t MR38             :  1; /*!< Ofs=6, w=1 Event mask on external/internal line 38 */
      __RWB uint32_t MR39             :  1; /*!< Ofs=7, w=1 Event mask on external/internal line 39 */
            uint32_t unused0          : 24;
    } B;
  } ;
#ifdef __cplusplus
  EXTI_EMR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_EMR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_EMR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_RTSR2_s { /*!< Rising Trigger selection register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t RT35             :  1; /*!< Ofs=3, w=1 Rising trigger event configuration bit of line 35 */
      __RWB uint32_t RT36             :  1; /*!< Ofs=4, w=1 Rising trigger event configuration bit of line 36 */
      __RWB uint32_t RT37             :  1; /*!< Ofs=5, w=1 Rising trigger event configuration bit of line 37 */
      __RWB uint32_t RT38             :  1; /*!< Ofs=6, w=1 Rising trigger event configuration bit of line 38 */
            uint32_t unused1          : 25;
    } B;
  } ;
#ifdef __cplusplus
  EXTI_RTSR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_RTSR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_RTSR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_FTSR2_s { /*!< Falling Trigger selection register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t FT35             :  1; /*!< Ofs=3, w=1 Falling trigger event configuration bit of line 35 */
      __RWB uint32_t FT36             :  1; /*!< Ofs=4, w=1 Falling trigger event configuration bit of line 36 */
      __RWB uint32_t FT37             :  1; /*!< Ofs=5, w=1 Falling trigger event configuration bit of line 37 */
      __RWB uint32_t FT38             :  1; /*!< Ofs=6, w=1 Falling trigger event configuration bit of line 38 */
            uint32_t unused1          : 25;
    } B;
  } ;
#ifdef __cplusplus
  EXTI_FTSR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_FTSR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_FTSR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_SWIER2_s { /*!< Software interrupt event register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t SWI35            :  1; /*!< Ofs=3, w=1 Software interrupt on line 35 */
      __RWB uint32_t SWI36            :  1; /*!< Ofs=4, w=1 Software interrupt on line 36 */
      __RWB uint32_t SWI37            :  1; /*!< Ofs=5, w=1 Software interrupt on line 37 */
      __RWB uint32_t SWI38            :  1; /*!< Ofs=6, w=1 Software interrupt on line 38 */
            uint32_t unused1          : 25;
    } B;
  } ;
#ifdef __cplusplus
  EXTI_SWIER2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_SWIER2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_SWIER2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct EXTI_PR2_s { /*!< Pending register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t PIF35            :  1; /*!< Ofs=3, w=1 Pending interrupt flag on line 35 */
      __RWB uint32_t PIF36            :  1; /*!< Ofs=4, w=1 Pending interrupt flag on line 36 */
      __RWB uint32_t PIF37            :  1; /*!< Ofs=5, w=1 Pending interrupt flag on line 37 */
      __RWB uint32_t PIF38            :  1; /*!< Ofs=6, w=1 Pending interrupt flag on line 38 */
            uint32_t unused1          : 25;
    } B;
  } ;
#ifdef __cplusplus
  EXTI_PR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    EXTI_PR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    EXTI_PR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Firewall_CSSA_s { /*!< Code segment start address */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  8;
      __RWB uint32_t ADD              : 16; /*!< Ofs=8, w=16 code segment start address */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  Firewall_CSSA_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    Firewall_CSSA_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Firewall_CSSA_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Firewall_CSL_s { /*!< Code segment length */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  8;
      __RWB uint32_t LENG             : 14; /*!< Ofs=8, w=14 code segment length */
            uint32_t unused1          : 10;
    } B;
  } ;
#ifdef __cplusplus
  Firewall_CSL_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    Firewall_CSL_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Firewall_CSL_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Firewall_NVDSSA_s { /*!< Non-volatile data segment start address */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  8;
      __RWB uint32_t ADD              : 16; /*!< Ofs=8, w=16 Non-volatile data segment start address */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  Firewall_NVDSSA_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    Firewall_NVDSSA_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Firewall_NVDSSA_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Firewall_NVDSL_s { /*!< Non-volatile data segment length */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  8;
      __RWB uint32_t LENG             : 14; /*!< Ofs=8, w=14 Non-volatile data segment length */
            uint32_t unused1          : 10;
    } B;
  } ;
#ifdef __cplusplus
  Firewall_NVDSL_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    Firewall_NVDSL_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Firewall_NVDSL_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Firewall_VDSSA_s { /*!< Volatile data segment start address */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  6;
      __RWB uint32_t ADD              : 10; /*!< Ofs=6, w=10 Volatile data segment start address */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  Firewall_VDSSA_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    Firewall_VDSSA_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Firewall_VDSSA_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Firewall_VDSL_s { /*!< Volatile data segment length */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  6;
      __RWB uint32_t LENG             : 10; /*!< Ofs=6, w=10 Non-volatile data segment length */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  Firewall_VDSL_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    Firewall_VDSL_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Firewall_VDSL_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Firewall_CR_s { /*!< Configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FPA              :  1; /*!< Ofs=0, w=1 Firewall pre alarm */
      __RWB uint32_t VDS              :  1; /*!< Ofs=1, w=1 Volatile data shared */
      __RWB uint32_t VDE              :  1; /*!< Ofs=2, w=1 Volatile data execution */
            uint32_t unused0          : 29;
    } B;
  } ;
#ifdef __cplusplus
  Firewall_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    Firewall_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Firewall_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SDIO_CLKCR_s { /*!< SDI clock control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CLKDIV           :  8; /*!< Ofs=0, w=8 Clock divide factor */
      __RWB uint32_t CLKEN            :  1; /*!< Ofs=8, w=1 Clock enable bit */
      __RWB uint32_t PWRSAV           :  1; /*!< Ofs=9, w=1 Power saving configuration bit */
      __RWB uint32_t BYPASS           :  1; /*!< Ofs=10, w=1 Clock divider bypass enable bit */
      __RWB uint32_t WIDBUS           :  2; /*!< Ofs=11, w=2 Wide bus mode enable bit */
      __RWB uint32_t NEGEDGE          :  1; /*!< Ofs=13, w=1 SDIO_CK dephasing selection bit */
      __RWB uint32_t HWFC_EN          :  1; /*!< Ofs=14, w=1 HW Flow Control enable */
            uint32_t unused0          : 17;
    } B;
  } ;
#ifdef __cplusplus
  SDIO_CLKCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SDIO_CLKCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SDIO_CLKCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SDIO_CMD_s { /*!< command register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CMDINDEX         :  6; /*!< Ofs=0, w=6 Command index */
      __RWB uint32_t WAITRESP         :  2; /*!< Ofs=6, w=2 Wait for response bits */
      __RWB uint32_t WAITINT          :  1; /*!< Ofs=8, w=1 CPSM waits for interrupt request */
      __RWB uint32_t WAITPEND         :  1; /*!< Ofs=9, w=1 CPSM Waits for ends of data transfer (CmdPend internal signal) */
      __RWB uint32_t CPSMEN           :  1; /*!< Ofs=10, w=1 Command path state machine (CPSM) Enable bit */
      __RWB uint32_t SDIOSuspend      :  1; /*!< Ofs=11, w=1 SD I/O suspend command */
      __RWB uint32_t ENCMDcompl       :  1; /*!< Ofs=12, w=1 Enable CMD completion */
      __RWB uint32_t nIEN             :  1; /*!< Ofs=13, w=1 not Interrupt Enable */
      __RWB uint32_t CE_ATACMD        :  1; /*!< Ofs=14, w=1 CE-ATA command */
            uint32_t unused0          : 17;
    } B;
  } ;
#ifdef __cplusplus
  SDIO_CMD_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SDIO_CMD_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SDIO_CMD_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SDIO_DCTRL_s { /*!< data control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DTEN             :  1; /*!< Ofs=0, w=1 DTEN */
      __RWB uint32_t DTDIR            :  1; /*!< Ofs=1, w=1 Data transfer direction selection */
      __RWB uint32_t DTMODE           :  1; /*!< Ofs=2, w=1 Data transfer mode selection 1: Stream or SDIO multibyte data transfer */
      __RWB uint32_t DMAEN            :  1; /*!< Ofs=3, w=1 DMA enable bit */
      __RWB uint32_t DBLOCKSIZE       :  4; /*!< Ofs=4, w=4 Data block size */
      __RWB uint32_t RWSTART          :  1; /*!< Ofs=8, w=1 Read wait start */
      __RWB uint32_t RWSTOP           :  1; /*!< Ofs=9, w=1 Read wait stop */
      __RWB uint32_t RWMOD            :  1; /*!< Ofs=10, w=1 Read wait mode */
      __RWB uint32_t SDIOEN           :  1; /*!< Ofs=11, w=1 SD I/O enable functions */
            uint32_t unused0          : 20;
    } B;
  } ;
#ifdef __cplusplus
  SDIO_DCTRL_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SDIO_DCTRL_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SDIO_DCTRL_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SDIO_STA_s { /*!< status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t CCRCFAIL         :  1; /*!< Ofs=0, w=1 Command response received (CRC check failed) */
      __ROB uint32_t DCRCFAIL         :  1; /*!< Ofs=1, w=1 Data block sent/received (CRC check failed) */
      __ROB uint32_t CTIMEOUT         :  1; /*!< Ofs=2, w=1 Command response timeout */
      __ROB uint32_t DTIMEOUT         :  1; /*!< Ofs=3, w=1 Data timeout */
      __ROB uint32_t TXUNDERR         :  1; /*!< Ofs=4, w=1 Transmit FIFO underrun error */
      __ROB uint32_t RXOVERR          :  1; /*!< Ofs=5, w=1 Received FIFO overrun error */
      __ROB uint32_t CMDREND          :  1; /*!< Ofs=6, w=1 Command response received (CRC check passed) */
      __ROB uint32_t CMDSENT          :  1; /*!< Ofs=7, w=1 Command sent (no response required) */
      __ROB uint32_t DATAEND          :  1; /*!< Ofs=8, w=1 Data end (data counter, SDIDCOUNT, is zero) */
      __ROB uint32_t STBITERR         :  1; /*!< Ofs=9, w=1 Start bit not detected on all data signals in wide bus mode */
      __ROB uint32_t DBCKEND          :  1; /*!< Ofs=10, w=1 Data block sent/received (CRC check passed) */
      __ROB uint32_t CMDACT           :  1; /*!< Ofs=11, w=1 Command transfer in progress */
      __ROB uint32_t TXACT            :  1; /*!< Ofs=12, w=1 Data transmit in progress */
      __ROB uint32_t RXACT            :  1; /*!< Ofs=13, w=1 Data receive in progress */
      __ROB uint32_t TXFIFOHE         :  1; /*!< Ofs=14, w=1 Transmit FIFO half empty: at least 8 words can be written into the FIFO */
      __ROB uint32_t RXFIFOHF         :  1; /*!< Ofs=15, w=1 Receive FIFO half full: there are at least 8 words in the FIFO */
      __ROB uint32_t TXFIFOF          :  1; /*!< Ofs=16, w=1 Transmit FIFO full */
      __ROB uint32_t RXFIFOF          :  1; /*!< Ofs=17, w=1 Receive FIFO full */
      __ROB uint32_t TXFIFOE          :  1; /*!< Ofs=18, w=1 Transmit FIFO empty */
      __ROB uint32_t RXFIFOE          :  1; /*!< Ofs=19, w=1 Receive FIFO empty */
      __ROB uint32_t TXDAVL           :  1; /*!< Ofs=20, w=1 Data available in transmit FIFO */
      __ROB uint32_t RXDAVL           :  1; /*!< Ofs=21, w=1 Data available in receive FIFO */
      __ROB uint32_t SDIOIT           :  1; /*!< Ofs=22, w=1 SDIO interrupt received */
      __ROB uint32_t CEATAEND         :  1; /*!< Ofs=23, w=1 CE-ATA command completion signal received for CMD61 */
            uint32_t unused0          :  8;
    } B;
  } ;
#ifdef __cplusplus
  SDIO_STA_s(__RO SDIO_STA_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct SDIO_ICR_s { /*!< interrupt clear register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CCRCFAILC        :  1; /*!< Ofs=0, w=1 CCRCFAIL flag clear bit */
      __RWB uint32_t DCRCFAILC        :  1; /*!< Ofs=1, w=1 DCRCFAIL flag clear bit */
      __RWB uint32_t CTIMEOUTC        :  1; /*!< Ofs=2, w=1 CTIMEOUT flag clear bit */
      __RWB uint32_t DTIMEOUTC        :  1; /*!< Ofs=3, w=1 DTIMEOUT flag clear bit */
      __RWB uint32_t TXUNDERRC        :  1; /*!< Ofs=4, w=1 TXUNDERR flag clear bit */
      __RWB uint32_t RXOVERRC         :  1; /*!< Ofs=5, w=1 RXOVERR flag clear bit */
      __RWB uint32_t CMDRENDC         :  1; /*!< Ofs=6, w=1 CMDREND flag clear bit */
      __RWB uint32_t CMDSENTC         :  1; /*!< Ofs=7, w=1 CMDSENT flag clear bit */
      __RWB uint32_t DATAENDC         :  1; /*!< Ofs=8, w=1 DATAEND flag clear bit */
      __RWB uint32_t STBITERRC        :  1; /*!< Ofs=9, w=1 STBITERR flag clear bit */
      __RWB uint32_t DBCKENDC         :  1; /*!< Ofs=10, w=1 DBCKEND flag clear bit */
            uint32_t unused0          : 11;
      __RWB uint32_t SDIOITC          :  1; /*!< Ofs=22, w=1 SDIOIT flag clear bit */
      __RWB uint32_t CEATAENDC        :  1; /*!< Ofs=23, w=1 CEATAEND flag clear bit */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  SDIO_ICR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SDIO_ICR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SDIO_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SDIO_MASK_s { /*!< mask register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CCRCFAILIE       :  1; /*!< Ofs=0, w=1 Command CRC fail interrupt enable */
      __RWB uint32_t DCRCFAILIE       :  1; /*!< Ofs=1, w=1 Data CRC fail interrupt enable */
      __RWB uint32_t CTIMEOUTIE       :  1; /*!< Ofs=2, w=1 Command timeout interrupt enable */
      __RWB uint32_t DTIMEOUTIE       :  1; /*!< Ofs=3, w=1 Data timeout interrupt enable */
      __RWB uint32_t TXUNDERRIE       :  1; /*!< Ofs=4, w=1 Tx FIFO underrun error interrupt enable */
      __RWB uint32_t RXOVERRIE        :  1; /*!< Ofs=5, w=1 Rx FIFO overrun error interrupt enable */
      __RWB uint32_t CMDRENDIE        :  1; /*!< Ofs=6, w=1 Command response received interrupt enable */
      __RWB uint32_t CMDSENTIE        :  1; /*!< Ofs=7, w=1 Command sent interrupt enable */
      __RWB uint32_t DATAENDIE        :  1; /*!< Ofs=8, w=1 Data end interrupt enable */
      __RWB uint32_t STBITERRIE       :  1; /*!< Ofs=9, w=1 Start bit error interrupt enable */
      __RWB uint32_t DBCKENDIE        :  1; /*!< Ofs=10, w=1 Data block end interrupt enable */
      __RWB uint32_t CMDACTIE         :  1; /*!< Ofs=11, w=1 Command acting interrupt enable */
      __RWB uint32_t TXACTIE          :  1; /*!< Ofs=12, w=1 Data transmit acting interrupt enable */
      __RWB uint32_t RXACTIE          :  1; /*!< Ofs=13, w=1 Data receive acting interrupt enable */
      __RWB uint32_t TXFIFOHEIE       :  1; /*!< Ofs=14, w=1 Tx FIFO half empty interrupt enable */
      __RWB uint32_t RXFIFOHFIE       :  1; /*!< Ofs=15, w=1 Rx FIFO half full interrupt enable */
      __RWB uint32_t TXFIFOFIE        :  1; /*!< Ofs=16, w=1 Tx FIFO full interrupt enable */
      __RWB uint32_t RXFIFOFIE        :  1; /*!< Ofs=17, w=1 Rx FIFO full interrupt enable */
      __RWB uint32_t TXFIFOEIE        :  1; /*!< Ofs=18, w=1 Tx FIFO empty interrupt enable */
      __RWB uint32_t RXFIFOEIE        :  1; /*!< Ofs=19, w=1 Rx FIFO empty interrupt enable */
      __RWB uint32_t TXDAVLIE         :  1; /*!< Ofs=20, w=1 Data available in Tx FIFO interrupt enable */
      __RWB uint32_t RXDAVLIE         :  1; /*!< Ofs=21, w=1 Data available in Rx FIFO interrupt enable */
      __RWB uint32_t SDIOITIE         :  1; /*!< Ofs=22, w=1 SDIO mode interrupt received interrupt enable */
      __RWB uint32_t CEATAENDIE       :  1; /*!< Ofs=23, w=1 CE-ATA command completion signal received interrupt enable */
            uint32_t unused0          :  8;
    } B;
  } ;
#ifdef __cplusplus
  SDIO_MASK_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SDIO_MASK_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SDIO_MASK_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SPI_CR1_s { /*!< control register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CPHA             :  1; /*!< Ofs=0, w=1 Clock phase */
      __RWB uint32_t CPOL             :  1; /*!< Ofs=1, w=1 Clock polarity */
      __RWB uint32_t MSTR             :  1; /*!< Ofs=2, w=1 Master selection */
      __RWB uint32_t BR               :  3; /*!< Ofs=3, w=3 Baud rate control */
      __RWB uint32_t SPE              :  1; /*!< Ofs=6, w=1 SPI enable */
      __RWB uint32_t LSBFIRST         :  1; /*!< Ofs=7, w=1 Frame format */
      __RWB uint32_t SSI              :  1; /*!< Ofs=8, w=1 Internal slave select */
      __RWB uint32_t SSM              :  1; /*!< Ofs=9, w=1 Software slave management */
      __RWB uint32_t RXONLY           :  1; /*!< Ofs=10, w=1 Receive only */
      __RWB uint32_t DFF              :  1; /*!< Ofs=11, w=1 Data frame format */
      __RWB uint32_t CRCNEXT          :  1; /*!< Ofs=12, w=1 CRC transfer next */
      __RWB uint32_t CRCEN            :  1; /*!< Ofs=13, w=1 Hardware CRC calculation enable */
      __RWB uint32_t BIDIOE           :  1; /*!< Ofs=14, w=1 Output enable in bidirectional mode */
      __RWB uint32_t BIDIMODE         :  1; /*!< Ofs=15, w=1 Bidirectional data mode enable */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  SPI_CR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SPI_CR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SPI_CR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SPI_CR2_s { /*!< control register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t RXDMAEN          :  1; /*!< Ofs=0, w=1 Rx buffer DMA enable */
      __RWB uint32_t TXDMAEN          :  1; /*!< Ofs=1, w=1 Tx buffer DMA enable */
      __RWB uint32_t SSOE             :  1; /*!< Ofs=2, w=1 SS output enable */
      __RWB uint32_t NSSP             :  1; /*!< Ofs=3, w=1 NSS pulse management */
      __RWB uint32_t FRF              :  1; /*!< Ofs=4, w=1 Frame format */
      __RWB uint32_t ERRIE            :  1; /*!< Ofs=5, w=1 Error interrupt enable */
      __RWB uint32_t RXNEIE           :  1; /*!< Ofs=6, w=1 RX buffer not empty interrupt enable */
      __RWB uint32_t TXEIE            :  1; /*!< Ofs=7, w=1 Tx buffer empty interrupt enable */
      __RWB uint32_t DS               :  4; /*!< Ofs=8, w=4 Data size */
      __RWB uint32_t FRXTH            :  1; /*!< Ofs=12, w=1 FIFO reception threshold */
      __RWB uint32_t LDMA_RX          :  1; /*!< Ofs=13, w=1 Last DMA transfer for reception */
      __RWB uint32_t LDMA_TX          :  1; /*!< Ofs=14, w=1 Last DMA transfer for transmission */
            uint32_t unused0          : 17;
    } B;
  } ;
#ifdef __cplusplus
  SPI_CR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SPI_CR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SPI_CR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SPI_SR_s { /*!< status register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t RXNE             :  1; /*!< Ofs=0, w=1 Receive buffer not empty */
      __ROB uint32_t TXE              :  1; /*!< Ofs=1, w=1 Transmit buffer empty */
            uint32_t unused0          :  2;
      __RWB uint32_t CRCERR           :  1; /*!< Ofs=4, w=1 CRC error flag */
      __ROB uint32_t MODF             :  1; /*!< Ofs=5, w=1 Mode fault */
      __ROB uint32_t OVR              :  1; /*!< Ofs=6, w=1 Overrun flag */
      __ROB uint32_t BSY              :  1; /*!< Ofs=7, w=1 Busy flag */
      __ROB uint32_t TIFRFE           :  1; /*!< Ofs=8, w=1 TI frame format error */
      __ROB uint32_t FRLVL            :  2; /*!< Ofs=9, w=2 FIFO reception level */
      __ROB uint32_t FTLVL            :  2; /*!< Ofs=11, w=2 FIFO transmission level */
            uint32_t unused1          : 19;
    } B;
  } ;
#ifdef __cplusplus
  SPI_SR_s(): R(0x00000002u) {};
  template<typename F> void modify (F f) volatile {
    SPI_SR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SPI_SR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_ACR1_s { /*!< AConfiguration register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t MODE             :  2; /*!< Ofs=0, w=2 Audio block mode */
      __RWB uint32_t PRTCFG           :  2; /*!< Ofs=2, w=2 Protocol configuration */
            uint32_t unused0          :  1;
      __RWB uint32_t DS               :  3; /*!< Ofs=5, w=3 Data size */
      __RWB uint32_t LSBFIRST         :  1; /*!< Ofs=8, w=1 Least significant bit first */
      __RWB uint32_t CKSTR            :  1; /*!< Ofs=9, w=1 Clock strobing edge */
      __RWB uint32_t SYNCEN           :  2; /*!< Ofs=10, w=2 Synchronization enable */
      __RWB uint32_t MONO             :  1; /*!< Ofs=12, w=1 Mono mode */
      __RWB uint32_t OutDri           :  1; /*!< Ofs=13, w=1 Output drive */
            uint32_t unused1          :  2;
      __RWB uint32_t SAIAEN           :  1; /*!< Ofs=16, w=1 Audio block A enable */
      __RWB uint32_t DMAEN            :  1; /*!< Ofs=17, w=1 DMA enable */
            uint32_t unused2          :  1;
      __RWB uint32_t NODIV            :  1; /*!< Ofs=19, w=1 No divider */
      __RWB uint32_t MCJDIV           :  4; /*!< Ofs=20, w=4 Master clock divider */
            uint32_t unused3          :  8;
    } B;
  } ;
#ifdef __cplusplus
  SAI_ACR1_s(): R(0x00000040u) {};
  template<typename F> void modify (F f) volatile {
    SAI_ACR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_ACR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_ACR2_s { /*!< AConfiguration register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FTH              :  3; /*!< Ofs=0, w=3 FIFO threshold */
      __RWB uint32_t FFLUS            :  1; /*!< Ofs=3, w=1 FIFO flush */
      __RWB uint32_t TRIS             :  1; /*!< Ofs=4, w=1 Tristate management on data line */
      __RWB uint32_t MUTE             :  1; /*!< Ofs=5, w=1 Mute */
      __RWB uint32_t MUTEVAL          :  1; /*!< Ofs=6, w=1 Mute value */
      __RWB uint32_t MUTECN           :  6; /*!< Ofs=7, w=6 Mute counter */
      __RWB uint32_t CPL              :  1; /*!< Ofs=13, w=1 Complement bit */
      __RWB uint32_t COMP             :  2; /*!< Ofs=14, w=2 Companding mode */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  SAI_ACR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SAI_ACR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_ACR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_AFRCR_s { /*!< AFRCR */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FRL              :  8; /*!< Ofs=0, w=8 Frame length */
      __RWB uint32_t FSALL            :  7; /*!< Ofs=8, w=7 Frame synchronization active level length */
            uint32_t unused0          :  1;
      __RWB uint32_t FSDEF            :  1; /*!< Ofs=16, w=1 Frame synchronization definition */
      __RWB uint32_t FSPOL            :  1; /*!< Ofs=17, w=1 Frame synchronization polarity */
      __RWB uint32_t FSOFF            :  1; /*!< Ofs=18, w=1 Frame synchronization offset */
            uint32_t unused1          : 13;
    } B;
  } ;
#ifdef __cplusplus
  SAI_AFRCR_s(): R(0x00000007u) {};
  template<typename F> void modify (F f) volatile {
    SAI_AFRCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_AFRCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_ASLOTR_s { /*!< ASlot register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FBOFF            :  5; /*!< Ofs=0, w=5 First bit offset */
            uint32_t unused0          :  1;
      __RWB uint32_t SLOTSZ           :  2; /*!< Ofs=6, w=2 Slot size */
      __RWB uint32_t NBSLOT           :  4; /*!< Ofs=8, w=4 Number of slots in an audio frame */
            uint32_t unused1          :  4;
      __RWB uint32_t SLOTEN           : 16; /*!< Ofs=16, w=16 Slot enable */
    } B;
  } ;
#ifdef __cplusplus
  SAI_ASLOTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SAI_ASLOTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_ASLOTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_AIM_s { /*!< AInterrupt mask register2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OVRUDRIE         :  1; /*!< Ofs=0, w=1 Overrun/underrun interrupt enable */
      __RWB uint32_t MUTEDET          :  1; /*!< Ofs=1, w=1 Mute detection interrupt enable */
      __RWB uint32_t WCKCFG           :  1; /*!< Ofs=2, w=1 Wrong clock configuration interrupt enable */
      __RWB uint32_t FREQIE           :  1; /*!< Ofs=3, w=1 FIFO request interrupt enable */
      __RWB uint32_t CNRDYIE          :  1; /*!< Ofs=4, w=1 Codec not ready interrupt enable */
      __RWB uint32_t AFSDETIE         :  1; /*!< Ofs=5, w=1 Anticipated frame synchronization detection interrupt enable */
      __RWB uint32_t LFSDET           :  1; /*!< Ofs=6, w=1 Late frame synchronization detection interrupt enable */
            uint32_t unused0          : 25;
    } B;
  } ;
#ifdef __cplusplus
  SAI_AIM_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SAI_AIM_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_AIM_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_ASR_s { /*!< AStatus register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OVRUDR           :  1; /*!< Ofs=0, w=1 Overrun / underrun */
      __RWB uint32_t MUTEDET          :  1; /*!< Ofs=1, w=1 Mute detection */
      __RWB uint32_t WCKCFG           :  1; /*!< Ofs=2, w=1 Wrong clock configuration flag. This bit is read only */
      __RWB uint32_t FREQ             :  1; /*!< Ofs=3, w=1 FIFO request */
      __RWB uint32_t CNRDY            :  1; /*!< Ofs=4, w=1 Codec not ready */
      __RWB uint32_t AFSDET           :  1; /*!< Ofs=5, w=1 Anticipated frame synchronization detection */
      __RWB uint32_t LFSDET           :  1; /*!< Ofs=6, w=1 Late frame synchronization detection */
            uint32_t unused0          :  9;
      __RWB uint32_t FLVL             :  3; /*!< Ofs=16, w=3 FIFO level threshold */
            uint32_t unused1          : 13;
    } B;
  } ;
#ifdef __cplusplus
  SAI_ASR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SAI_ASR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_ASR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_ACLRFR_s { /*!< AClear flag register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OVRUDR           :  1; /*!< Ofs=0, w=1 Clear overrun / underrun */
      __RWB uint32_t MUTEDET          :  1; /*!< Ofs=1, w=1 Mute detection flag */
      __RWB uint32_t WCKCFG           :  1; /*!< Ofs=2, w=1 Clear wrong clock configuration flag */
            uint32_t unused0          :  1;
      __RWB uint32_t CNRDY            :  1; /*!< Ofs=4, w=1 Clear codec not ready flag */
      __RWB uint32_t CAFSDET          :  1; /*!< Ofs=5, w=1 Clear anticipated frame synchronization detection flag */
      __RWB uint32_t LFSDET           :  1; /*!< Ofs=6, w=1 Clear late frame synchronization detection flag */
            uint32_t unused1          : 25;
    } B;
  } ;
#ifdef __cplusplus
  SAI_ACLRFR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SAI_ACLRFR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_ACLRFR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_BCR1_s { /*!< BConfiguration register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t MODE             :  2; /*!< Ofs=0, w=2 Audio block mode */
      __RWB uint32_t PRTCFG           :  2; /*!< Ofs=2, w=2 Protocol configuration */
            uint32_t unused0          :  1;
      __RWB uint32_t DS               :  3; /*!< Ofs=5, w=3 Data size */
      __RWB uint32_t LSBFIRST         :  1; /*!< Ofs=8, w=1 Least significant bit first */
      __RWB uint32_t CKSTR            :  1; /*!< Ofs=9, w=1 Clock strobing edge */
      __RWB uint32_t SYNCEN           :  2; /*!< Ofs=10, w=2 Synchronization enable */
      __RWB uint32_t MONO             :  1; /*!< Ofs=12, w=1 Mono mode */
      __RWB uint32_t OutDri           :  1; /*!< Ofs=13, w=1 Output drive */
            uint32_t unused1          :  2;
      __RWB uint32_t SAIBEN           :  1; /*!< Ofs=16, w=1 Audio block B enable */
      __RWB uint32_t DMAEN            :  1; /*!< Ofs=17, w=1 DMA enable */
            uint32_t unused2          :  1;
      __RWB uint32_t NODIV            :  1; /*!< Ofs=19, w=1 No divider */
      __RWB uint32_t MCJDIV           :  4; /*!< Ofs=20, w=4 Master clock divider */
            uint32_t unused3          :  8;
    } B;
  } ;
#ifdef __cplusplus
  SAI_BCR1_s(): R(0x00000040u) {};
  template<typename F> void modify (F f) volatile {
    SAI_BCR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_BCR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_BCR2_s { /*!< BConfiguration register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FTH              :  3; /*!< Ofs=0, w=3 FIFO threshold */
      __RWB uint32_t FFLUS            :  1; /*!< Ofs=3, w=1 FIFO flush */
      __RWB uint32_t TRIS             :  1; /*!< Ofs=4, w=1 Tristate management on data line */
      __RWB uint32_t MUTE             :  1; /*!< Ofs=5, w=1 Mute */
      __RWB uint32_t MUTEVAL          :  1; /*!< Ofs=6, w=1 Mute value */
      __RWB uint32_t MUTECN           :  6; /*!< Ofs=7, w=6 Mute counter */
      __RWB uint32_t CPL              :  1; /*!< Ofs=13, w=1 Complement bit */
      __RWB uint32_t COMP             :  2; /*!< Ofs=14, w=2 Companding mode */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  SAI_BCR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SAI_BCR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_BCR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_BFRCR_s { /*!< BFRCR */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FRL              :  8; /*!< Ofs=0, w=8 Frame length */
      __RWB uint32_t FSALL            :  7; /*!< Ofs=8, w=7 Frame synchronization active level length */
            uint32_t unused0          :  1;
      __RWB uint32_t FSDEF            :  1; /*!< Ofs=16, w=1 Frame synchronization definition */
      __RWB uint32_t FSPOL            :  1; /*!< Ofs=17, w=1 Frame synchronization polarity */
      __RWB uint32_t FSOFF            :  1; /*!< Ofs=18, w=1 Frame synchronization offset */
            uint32_t unused1          : 13;
    } B;
  } ;
#ifdef __cplusplus
  SAI_BFRCR_s(): R(0x00000007u) {};
  template<typename F> void modify (F f) volatile {
    SAI_BFRCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_BFRCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_BSLOTR_s { /*!< BSlot register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t FBOFF            :  5; /*!< Ofs=0, w=5 First bit offset */
            uint32_t unused0          :  1;
      __RWB uint32_t SLOTSZ           :  2; /*!< Ofs=6, w=2 Slot size */
      __RWB uint32_t NBSLOT           :  4; /*!< Ofs=8, w=4 Number of slots in an audio frame */
            uint32_t unused1          :  4;
      __RWB uint32_t SLOTEN           : 16; /*!< Ofs=16, w=16 Slot enable */
    } B;
  } ;
#ifdef __cplusplus
  SAI_BSLOTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SAI_BSLOTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_BSLOTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_BIM_s { /*!< BInterrupt mask register2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OVRUDRIE         :  1; /*!< Ofs=0, w=1 Overrun/underrun interrupt enable */
      __RWB uint32_t MUTEDET          :  1; /*!< Ofs=1, w=1 Mute detection interrupt enable */
      __RWB uint32_t WCKCFG           :  1; /*!< Ofs=2, w=1 Wrong clock configuration interrupt enable */
      __RWB uint32_t FREQIE           :  1; /*!< Ofs=3, w=1 FIFO request interrupt enable */
      __RWB uint32_t CNRDYIE          :  1; /*!< Ofs=4, w=1 Codec not ready interrupt enable */
      __RWB uint32_t AFSDETIE         :  1; /*!< Ofs=5, w=1 Anticipated frame synchronization detection interrupt enable */
      __RWB uint32_t LFSDETIE         :  1; /*!< Ofs=6, w=1 Late frame synchronization detection interrupt enable */
            uint32_t unused0          : 25;
    } B;
  } ;
#ifdef __cplusplus
  SAI_BIM_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    SAI_BIM_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    SAI_BIM_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct SAI_BSR_s { /*!< BStatus register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t OVRUDR           :  1; /*!< Ofs=0, w=1 Overrun / underrun */
      __ROB uint32_t MUTEDET          :  1; /*!< Ofs=1, w=1 Mute detection */
      __ROB uint32_t WCKCFG           :  1; /*!< Ofs=2, w=1 Wrong clock configuration flag */
      __ROB uint32_t FREQ             :  1; /*!< Ofs=3, w=1 FIFO request */
      __ROB uint32_t CNRDY            :  1; /*!< Ofs=4, w=1 Codec not ready */
      __ROB uint32_t AFSDET           :  1; /*!< Ofs=5, w=1 Anticipated frame synchronization detection */
      __ROB uint32_t LFSDET           :  1; /*!< Ofs=6, w=1 Late frame synchronization detection */
            uint32_t unused0          :  9;
      __ROB uint32_t FLVL             :  3; /*!< Ofs=16, w=3 FIFO level threshold */
            uint32_t unused1          : 13;
    } B;
  } ;
#ifdef __cplusplus
  SAI_BSR_s(__RO SAI_BSR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct SAI_BCLRFR_s { /*!< BClear flag register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t OVRUDR           :  1; /*!< Ofs=0, w=1 Clear overrun / underrun */
      __WOB uint32_t MUTEDET          :  1; /*!< Ofs=1, w=1 Mute detection flag */
      __WOB uint32_t WCKCFG           :  1; /*!< Ofs=2, w=1 Clear wrong clock configuration flag */
            uint32_t unused0          :  1;
      __WOB uint32_t CNRDY            :  1; /*!< Ofs=4, w=1 Clear codec not ready flag */
      __WOB uint32_t CAFSDET          :  1; /*!< Ofs=5, w=1 Clear anticipated frame synchronization detection flag */
      __WOB uint32_t LFSDET           :  1; /*!< Ofs=6, w=1 Clear late frame synchronization detection flag */
            uint32_t unused1          : 25;
    } B;
  } ;
#ifdef __cplusplus
  SAI_BCLRFR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    SAI_BCLRFR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG0R1_s { /*!< channel configuration y register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SITP             :  2; /*!< Ofs=0, w=2 SITP */
      __RWB uint32_t SPICKSEL         :  2; /*!< Ofs=2, w=2 SPICKSEL */
            uint32_t unused0          :  1;
      __RWB uint32_t SCDEN            :  1; /*!< Ofs=5, w=1 SCDEN */
      __RWB uint32_t CKABEN           :  1; /*!< Ofs=6, w=1 CKABEN */
      __RWB uint32_t CHEN             :  1; /*!< Ofs=7, w=1 CHEN */
      __RWB uint32_t CHINSEL          :  1; /*!< Ofs=8, w=1 CHINSEL */
            uint32_t unused1          :  3;
      __RWB uint32_t DATMPX           :  2; /*!< Ofs=12, w=2 DATMPX */
      __RWB uint32_t DATPACK          :  2; /*!< Ofs=14, w=2 DATPACK */
      __RWB uint32_t CKOUTDIV         :  8; /*!< Ofs=16, w=8 CKOUTDIV */
            uint32_t unused2          :  6;
      __RWB uint32_t CKOUTSRC         :  1; /*!< Ofs=30, w=1 CKOUTSRC */
      __RWB uint32_t DFSDMEN          :  1; /*!< Ofs=31, w=1 DFSDMEN */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG0R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG0R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG0R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG0R2_s { /*!< channel configuration y register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t DTRBS            :  5; /*!< Ofs=3, w=5 DTRBS */
      __RWB uint32_t OFFSET           : 24; /*!< Ofs=8, w=24 OFFSET */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG0R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG0R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG0R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_AWSCD0R_s { /*!< analog watchdog and short-circuit detector register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SCDT             :  8; /*!< Ofs=0, w=8 SCDT */
            uint32_t unused0          :  4;
      __RWB uint32_t BKSCD            :  4; /*!< Ofs=12, w=4 BKSCD */
      __RWB uint32_t AWFOSR           :  5; /*!< Ofs=16, w=5 AWFOSR */
            uint32_t unused1          :  1;
      __RWB uint32_t AWFORD           :  2; /*!< Ofs=22, w=2 AWFORD */
            uint32_t unused2          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_AWSCD0R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_AWSCD0R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_AWSCD0R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHDATIN0R_s { /*!< channel data input register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t INDAT0           : 16; /*!< Ofs=0, w=16 INDAT0 */
      __RWB uint32_t INDAT1           : 16; /*!< Ofs=16, w=16 INDAT1 */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHDATIN0R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHDATIN0R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHDATIN0R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG1R1_s { /*!< CHCFG1R1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SITP             :  2; /*!< Ofs=0, w=2 SITP */
      __RWB uint32_t SPICKSEL         :  2; /*!< Ofs=2, w=2 SPICKSEL */
            uint32_t unused0          :  1;
      __RWB uint32_t SCDEN            :  1; /*!< Ofs=5, w=1 SCDEN */
      __RWB uint32_t CKABEN           :  1; /*!< Ofs=6, w=1 CKABEN */
      __RWB uint32_t CHEN             :  1; /*!< Ofs=7, w=1 CHEN */
      __RWB uint32_t CHINSEL          :  1; /*!< Ofs=8, w=1 CHINSEL */
            uint32_t unused1          :  3;
      __RWB uint32_t DATMPX           :  2; /*!< Ofs=12, w=2 DATMPX */
      __RWB uint32_t DATPACK          :  2; /*!< Ofs=14, w=2 DATPACK */
            uint32_t unused2          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG1R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG1R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG1R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG1R2_s { /*!< CHCFG1R2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t DTRBS            :  5; /*!< Ofs=3, w=5 DTRBS */
      __RWB uint32_t OFFSET           : 24; /*!< Ofs=8, w=24 OFFSET */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG1R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG1R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG1R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_AWSCD1R_s { /*!< AWSCD1R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SCDT             :  8; /*!< Ofs=0, w=8 SCDT */
            uint32_t unused0          :  4;
      __RWB uint32_t BKSCD            :  4; /*!< Ofs=12, w=4 BKSCD */
      __RWB uint32_t AWFOSR           :  5; /*!< Ofs=16, w=5 AWFOSR */
            uint32_t unused1          :  1;
      __RWB uint32_t AWFORD           :  2; /*!< Ofs=22, w=2 AWFORD */
            uint32_t unused2          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_AWSCD1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_AWSCD1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_AWSCD1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHDATIN1R_s { /*!< CHDATIN1R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t INDAT0           : 16; /*!< Ofs=0, w=16 INDAT0 */
      __RWB uint32_t INDAT1           : 16; /*!< Ofs=16, w=16 INDAT1 */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHDATIN1R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHDATIN1R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHDATIN1R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG2R1_s { /*!< CHCFG2R1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SITP             :  2; /*!< Ofs=0, w=2 SITP */
      __RWB uint32_t SPICKSEL         :  2; /*!< Ofs=2, w=2 SPICKSEL */
            uint32_t unused0          :  1;
      __RWB uint32_t SCDEN            :  1; /*!< Ofs=5, w=1 SCDEN */
      __RWB uint32_t CKABEN           :  1; /*!< Ofs=6, w=1 CKABEN */
      __RWB uint32_t CHEN             :  1; /*!< Ofs=7, w=1 CHEN */
      __RWB uint32_t CHINSEL          :  1; /*!< Ofs=8, w=1 CHINSEL */
            uint32_t unused1          :  3;
      __RWB uint32_t DATMPX           :  2; /*!< Ofs=12, w=2 DATMPX */
      __RWB uint32_t DATPACK          :  2; /*!< Ofs=14, w=2 DATPACK */
            uint32_t unused2          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG2R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG2R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG2R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG2R2_s { /*!< CHCFG2R2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t DTRBS            :  5; /*!< Ofs=3, w=5 DTRBS */
      __RWB uint32_t OFFSET           : 24; /*!< Ofs=8, w=24 OFFSET */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG2R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG2R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG2R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_AWSCD2R_s { /*!< AWSCD2R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SCDT             :  8; /*!< Ofs=0, w=8 SCDT */
            uint32_t unused0          :  4;
      __RWB uint32_t BKSCD            :  4; /*!< Ofs=12, w=4 BKSCD */
      __RWB uint32_t AWFOSR           :  5; /*!< Ofs=16, w=5 AWFOSR */
            uint32_t unused1          :  1;
      __RWB uint32_t AWFORD           :  2; /*!< Ofs=22, w=2 AWFORD */
            uint32_t unused2          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_AWSCD2R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_AWSCD2R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_AWSCD2R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHDATIN2R_s { /*!< CHDATIN2R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t INDAT0           : 16; /*!< Ofs=0, w=16 INDAT0 */
      __RWB uint32_t INDAT1           : 16; /*!< Ofs=16, w=16 INDAT1 */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHDATIN2R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHDATIN2R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHDATIN2R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG3R1_s { /*!< CHCFG3R1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SITP             :  2; /*!< Ofs=0, w=2 SITP */
      __RWB uint32_t SPICKSEL         :  2; /*!< Ofs=2, w=2 SPICKSEL */
            uint32_t unused0          :  1;
      __RWB uint32_t SCDEN            :  1; /*!< Ofs=5, w=1 SCDEN */
      __RWB uint32_t CKABEN           :  1; /*!< Ofs=6, w=1 CKABEN */
      __RWB uint32_t CHEN             :  1; /*!< Ofs=7, w=1 CHEN */
      __RWB uint32_t CHINSEL          :  1; /*!< Ofs=8, w=1 CHINSEL */
            uint32_t unused1          :  3;
      __RWB uint32_t DATMPX           :  2; /*!< Ofs=12, w=2 DATMPX */
      __RWB uint32_t DATPACK          :  2; /*!< Ofs=14, w=2 DATPACK */
            uint32_t unused2          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG3R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG3R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG3R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG3R2_s { /*!< CHCFG3R2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t DTRBS            :  5; /*!< Ofs=3, w=5 DTRBS */
      __RWB uint32_t OFFSET           : 24; /*!< Ofs=8, w=24 OFFSET */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG3R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG3R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG3R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_AWSCD3R_s { /*!< AWSCD3R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SCDT             :  8; /*!< Ofs=0, w=8 SCDT */
            uint32_t unused0          :  4;
      __RWB uint32_t BKSCD            :  4; /*!< Ofs=12, w=4 BKSCD */
      __RWB uint32_t AWFOSR           :  5; /*!< Ofs=16, w=5 AWFOSR */
            uint32_t unused1          :  1;
      __RWB uint32_t AWFORD           :  2; /*!< Ofs=22, w=2 AWFORD */
            uint32_t unused2          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_AWSCD3R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_AWSCD3R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_AWSCD3R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHDATIN3R_s { /*!< CHDATIN3R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t INDAT0           : 16; /*!< Ofs=0, w=16 INDAT0 */
      __RWB uint32_t INDAT1           : 16; /*!< Ofs=16, w=16 INDAT1 */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHDATIN3R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHDATIN3R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHDATIN3R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG4R1_s { /*!< CHCFG4R1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SITP             :  2; /*!< Ofs=0, w=2 SITP */
      __RWB uint32_t SPICKSEL         :  2; /*!< Ofs=2, w=2 SPICKSEL */
            uint32_t unused0          :  1;
      __RWB uint32_t SCDEN            :  1; /*!< Ofs=5, w=1 SCDEN */
      __RWB uint32_t CKABEN           :  1; /*!< Ofs=6, w=1 CKABEN */
      __RWB uint32_t CHEN             :  1; /*!< Ofs=7, w=1 CHEN */
      __RWB uint32_t CHINSEL          :  1; /*!< Ofs=8, w=1 CHINSEL */
            uint32_t unused1          :  3;
      __RWB uint32_t DATMPX           :  2; /*!< Ofs=12, w=2 DATMPX */
      __RWB uint32_t DATPACK          :  2; /*!< Ofs=14, w=2 DATPACK */
            uint32_t unused2          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG4R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG4R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG4R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG4R2_s { /*!< CHCFG4R2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t DTRBS            :  5; /*!< Ofs=3, w=5 DTRBS */
      __RWB uint32_t OFFSET           : 24; /*!< Ofs=8, w=24 OFFSET */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG4R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG4R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG4R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_AWSCD4R_s { /*!< AWSCD4R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SCDT             :  8; /*!< Ofs=0, w=8 SCDT */
            uint32_t unused0          :  4;
      __RWB uint32_t BKSCD            :  4; /*!< Ofs=12, w=4 BKSCD */
      __RWB uint32_t AWFOSR           :  5; /*!< Ofs=16, w=5 AWFOSR */
            uint32_t unused1          :  1;
      __RWB uint32_t AWFORD           :  2; /*!< Ofs=22, w=2 AWFORD */
            uint32_t unused2          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_AWSCD4R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_AWSCD4R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_AWSCD4R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHDATIN4R_s { /*!< CHDATIN4R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t INDAT0           : 16; /*!< Ofs=0, w=16 INDAT0 */
      __RWB uint32_t INDAT1           : 16; /*!< Ofs=16, w=16 INDAT1 */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHDATIN4R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHDATIN4R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHDATIN4R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG5R1_s { /*!< CHCFG5R1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SITP             :  2; /*!< Ofs=0, w=2 SITP */
      __RWB uint32_t SPICKSEL         :  2; /*!< Ofs=2, w=2 SPICKSEL */
            uint32_t unused0          :  1;
      __RWB uint32_t SCDEN            :  1; /*!< Ofs=5, w=1 SCDEN */
      __RWB uint32_t CKABEN           :  1; /*!< Ofs=6, w=1 CKABEN */
      __RWB uint32_t CHEN             :  1; /*!< Ofs=7, w=1 CHEN */
      __RWB uint32_t CHINSEL          :  1; /*!< Ofs=8, w=1 CHINSEL */
            uint32_t unused1          :  3;
      __RWB uint32_t DATMPX           :  2; /*!< Ofs=12, w=2 DATMPX */
      __RWB uint32_t DATPACK          :  2; /*!< Ofs=14, w=2 DATPACK */
            uint32_t unused2          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG5R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG5R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG5R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG5R2_s { /*!< CHCFG5R2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t DTRBS            :  5; /*!< Ofs=3, w=5 DTRBS */
      __RWB uint32_t OFFSET           : 24; /*!< Ofs=8, w=24 OFFSET */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG5R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG5R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG5R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_AWSCD5R_s { /*!< AWSCD5R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SCDT             :  8; /*!< Ofs=0, w=8 SCDT */
            uint32_t unused0          :  4;
      __RWB uint32_t BKSCD            :  4; /*!< Ofs=12, w=4 BKSCD */
      __RWB uint32_t AWFOSR           :  5; /*!< Ofs=16, w=5 AWFOSR */
            uint32_t unused1          :  1;
      __RWB uint32_t AWFORD           :  2; /*!< Ofs=22, w=2 AWFORD */
            uint32_t unused2          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_AWSCD5R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_AWSCD5R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_AWSCD5R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHDATIN5R_s { /*!< CHDATIN5R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t INDAT0           : 16; /*!< Ofs=0, w=16 INDAT0 */
      __RWB uint32_t INDAT1           : 16; /*!< Ofs=16, w=16 INDAT1 */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHDATIN5R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHDATIN5R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHDATIN5R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG6R1_s { /*!< CHCFG6R1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SITP             :  2; /*!< Ofs=0, w=2 SITP */
      __RWB uint32_t SPICKSEL         :  2; /*!< Ofs=2, w=2 SPICKSEL */
            uint32_t unused0          :  1;
      __RWB uint32_t SCDEN            :  1; /*!< Ofs=5, w=1 SCDEN */
      __RWB uint32_t CKABEN           :  1; /*!< Ofs=6, w=1 CKABEN */
      __RWB uint32_t CHEN             :  1; /*!< Ofs=7, w=1 CHEN */
      __RWB uint32_t CHINSEL          :  1; /*!< Ofs=8, w=1 CHINSEL */
            uint32_t unused1          :  3;
      __RWB uint32_t DATMPX           :  2; /*!< Ofs=12, w=2 DATMPX */
      __RWB uint32_t DATPACK          :  2; /*!< Ofs=14, w=2 DATPACK */
            uint32_t unused2          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG6R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG6R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG6R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG6R2_s { /*!< CHCFG6R2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t DTRBS            :  5; /*!< Ofs=3, w=5 DTRBS */
      __RWB uint32_t OFFSET           : 24; /*!< Ofs=8, w=24 OFFSET */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG6R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG6R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG6R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_AWSCD6R_s { /*!< AWSCD6R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SCDT             :  8; /*!< Ofs=0, w=8 SCDT */
            uint32_t unused0          :  4;
      __RWB uint32_t BKSCD            :  4; /*!< Ofs=12, w=4 BKSCD */
      __RWB uint32_t AWFOSR           :  5; /*!< Ofs=16, w=5 AWFOSR */
            uint32_t unused1          :  1;
      __RWB uint32_t AWFORD           :  2; /*!< Ofs=22, w=2 AWFORD */
            uint32_t unused2          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_AWSCD6R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_AWSCD6R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_AWSCD6R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHDATIN6R_s { /*!< CHDATIN6R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t INDAT0           : 16; /*!< Ofs=0, w=16 INDAT0 */
      __RWB uint32_t INDAT1           : 16; /*!< Ofs=16, w=16 INDAT1 */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHDATIN6R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHDATIN6R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHDATIN6R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG7R1_s { /*!< CHCFG7R1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SITP             :  2; /*!< Ofs=0, w=2 SITP */
      __RWB uint32_t SPICKSEL         :  2; /*!< Ofs=2, w=2 SPICKSEL */
            uint32_t unused0          :  1;
      __RWB uint32_t SCDEN            :  1; /*!< Ofs=5, w=1 SCDEN */
      __RWB uint32_t CKABEN           :  1; /*!< Ofs=6, w=1 CKABEN */
      __RWB uint32_t CHEN             :  1; /*!< Ofs=7, w=1 CHEN */
      __RWB uint32_t CHINSEL          :  1; /*!< Ofs=8, w=1 CHINSEL */
            uint32_t unused1          :  3;
      __RWB uint32_t DATMPX           :  2; /*!< Ofs=12, w=2 DATMPX */
      __RWB uint32_t DATPACK          :  2; /*!< Ofs=14, w=2 DATPACK */
            uint32_t unused2          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG7R1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG7R1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG7R1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHCFG7R2_s { /*!< CHCFG7R2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t DTRBS            :  5; /*!< Ofs=3, w=5 DTRBS */
      __RWB uint32_t OFFSET           : 24; /*!< Ofs=8, w=24 OFFSET */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHCFG7R2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHCFG7R2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHCFG7R2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_AWSCD7R_s { /*!< AWSCD7R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SCDT             :  8; /*!< Ofs=0, w=8 SCDT */
            uint32_t unused0          :  4;
      __RWB uint32_t BKSCD            :  4; /*!< Ofs=12, w=4 BKSCD */
      __RWB uint32_t AWFOSR           :  5; /*!< Ofs=16, w=5 AWFOSR */
            uint32_t unused1          :  1;
      __RWB uint32_t AWFORD           :  2; /*!< Ofs=22, w=2 AWFORD */
            uint32_t unused2          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_AWSCD7R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_AWSCD7R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_AWSCD7R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_CHDATIN7R_s { /*!< CHDATIN7R */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t INDAT0           : 16; /*!< Ofs=0, w=16 INDAT0 */
      __RWB uint32_t INDAT1           : 16; /*!< Ofs=16, w=16 INDAT1 */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_CHDATIN7R_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_CHDATIN7R_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_CHDATIN7R_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_CR1_s { /*!< control register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DFEN             :  1; /*!< Ofs=0, w=1 DFSDM enable */
      __RWB uint32_t JSWSTART         :  1; /*!< Ofs=1, w=1 Start a conversion of the injected group of channels */
            uint32_t unused0          :  1;
      __RWB uint32_t JSYNC            :  1; /*!< Ofs=3, w=1 Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger */
      __RWB uint32_t JSCAN            :  1; /*!< Ofs=4, w=1 Scanning conversion mode for injected conversions */
      __RWB uint32_t JDMAEN           :  1; /*!< Ofs=5, w=1 DMA channel enabled to read data for the injected channel group */
            uint32_t unused1          :  2;
      __RWB uint32_t JEXTSEL          :  3; /*!< Ofs=8, w=3 Trigger signal selection for launching injected conversions */
            uint32_t unused2          :  2;
      __RWB uint32_t JEXTEN           :  2; /*!< Ofs=13, w=2 Trigger enable and trigger edge selection for injected conversions */
            uint32_t unused3          :  2;
      __RWB uint32_t RSWSTART         :  1; /*!< Ofs=17, w=1 Software start of a conversion on the regular channel */
      __RWB uint32_t RCONT            :  1; /*!< Ofs=18, w=1 Continuous mode selection for regular conversions */
      __RWB uint32_t RSYNC            :  1; /*!< Ofs=19, w=1 Launch regular conversion synchronously with DFSDM0 */
            uint32_t unused4          :  1;
      __RWB uint32_t RDMAEN           :  1; /*!< Ofs=21, w=1 DMA channel enabled to read data for the regular conversion */
            uint32_t unused5          :  2;
      __RWB uint32_t RCH              :  3; /*!< Ofs=24, w=3 Regular channel selection */
            uint32_t unused6          :  2;
      __RWB uint32_t FAST             :  1; /*!< Ofs=29, w=1 Fast conversion mode selection for regular conversions */
      __RWB uint32_t AWFSEL           :  1; /*!< Ofs=30, w=1 Analog watchdog fast mode select */
            uint32_t unused7          :  1;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_CR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM0_CR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM0_CR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_CR2_s { /*!< control register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t JEOCIE           :  1; /*!< Ofs=0, w=1 Injected end of conversion interrupt enable */
      __RWB uint32_t REOCIE           :  1; /*!< Ofs=1, w=1 Regular end of conversion interrupt enable */
      __RWB uint32_t JOVRIE           :  1; /*!< Ofs=2, w=1 Injected data overrun interrupt enable */
      __RWB uint32_t ROVRIE           :  1; /*!< Ofs=3, w=1 Regular data overrun interrupt enable */
      __RWB uint32_t AWDIE            :  1; /*!< Ofs=4, w=1 Analog watchdog interrupt enable */
      __RWB uint32_t SCDIE            :  1; /*!< Ofs=5, w=1 Short-circuit detector interrupt enable */
      __RWB uint32_t CKABIE           :  1; /*!< Ofs=6, w=1 Clock absence interrupt enable */
            uint32_t unused0          :  1;
      __RWB uint32_t EXCH             :  8; /*!< Ofs=8, w=8 Extremes detector channel selection */
      __RWB uint32_t AWDCH            :  8; /*!< Ofs=16, w=8 Analog watchdog channel selection */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_CR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM0_CR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM0_CR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_ISR_s { /*!< interrupt and status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t JEOCF            :  1; /*!< Ofs=0, w=1 End of injected conversion flag */
      __ROB uint32_t REOCF            :  1; /*!< Ofs=1, w=1 End of regular conversion flag */
      __ROB uint32_t JOVRF            :  1; /*!< Ofs=2, w=1 Injected conversion overrun flag */
      __ROB uint32_t ROVRF            :  1; /*!< Ofs=3, w=1 Regular conversion overrun flag */
      __ROB uint32_t AWDF             :  1; /*!< Ofs=4, w=1 Analog watchdog */
            uint32_t unused0          :  8;
      __ROB uint32_t JCIP             :  1; /*!< Ofs=13, w=1 Injected conversion in progress status */
      __ROB uint32_t RCIP             :  1; /*!< Ofs=14, w=1 Regular conversion in progress status */
            uint32_t unused1          :  1;
      __ROB uint32_t CKABF            :  8; /*!< Ofs=16, w=8 Clock absence flag */
      __ROB uint32_t SCDF             :  8; /*!< Ofs=24, w=8 short-circuit detector flag */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_ISR_s(__RO DFSDM_DFSDM0_ISR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_ICR_s { /*!< interrupt flag clear register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  2;
      __RWB uint32_t CLRJOVRF         :  1; /*!< Ofs=2, w=1 Clear the injected conversion overrun flag */
      __RWB uint32_t CLRROVRF         :  1; /*!< Ofs=3, w=1 Clear the regular conversion overrun flag */
            uint32_t unused1          : 12;
      __RWB uint32_t CLRCKABF         :  8; /*!< Ofs=16, w=8 Clear the clock absence flag */
      __RWB uint32_t CLRSCDF          :  8; /*!< Ofs=24, w=8 Clear the short-circuit detector flag */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_ICR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM0_ICR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM0_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_FCR_s { /*!< filter control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t IOSR             :  8; /*!< Ofs=0, w=8 Integrator oversampling ratio (averaging length) */
            uint32_t unused0          :  8;
      __RWB uint32_t FOSR             : 10; /*!< Ofs=16, w=10 Sinc filter oversampling ratio (decimation rate) */
            uint32_t unused1          :  3;
      __RWB uint32_t FORD             :  3; /*!< Ofs=29, w=3 Sinc filter order */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_FCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM0_FCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM0_FCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_JDATAR_s { /*!< data register for injected group */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t JDATACH          :  3; /*!< Ofs=0, w=3 Injected channel most recently converted */
            uint32_t unused0          :  5;
      __ROB uint32_t JDATA            : 24; /*!< Ofs=8, w=24 Injected group conversion data */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_JDATAR_s(__RO DFSDM_DFSDM0_JDATAR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_RDATAR_s { /*!< data register for the regular channel */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t RDATACH          :  3; /*!< Ofs=0, w=3 Regular channel most recently converted */
            uint32_t unused0          :  1;
      __ROB uint32_t RPEND            :  1; /*!< Ofs=4, w=1 Regular channel pending data */
            uint32_t unused1          :  3;
      __ROB uint32_t RDATA            : 24; /*!< Ofs=8, w=24 Regular channel conversion data */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_RDATAR_s(__RO DFSDM_DFSDM0_RDATAR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_AWHTR_s { /*!< analog watchdog high threshold register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BKAWH            :  4; /*!< Ofs=0, w=4 Break signal assignment to analog watchdog high threshold event */
            uint32_t unused0          :  4;
      __RWB uint32_t AWHT             : 24; /*!< Ofs=8, w=24 Analog watchdog high threshold */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_AWHTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM0_AWHTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM0_AWHTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_AWLTR_s { /*!< analog watchdog low threshold register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BKAWL            :  4; /*!< Ofs=0, w=4 Break signal assignment to analog watchdog low threshold event */
            uint32_t unused0          :  4;
      __RWB uint32_t AWLT             : 24; /*!< Ofs=8, w=24 Analog watchdog low threshold */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_AWLTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM0_AWLTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM0_AWLTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_AWSR_s { /*!< analog watchdog status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t AWLTF            :  8; /*!< Ofs=0, w=8 Analog watchdog low threshold flag */
      __ROB uint32_t AWHTF            :  8; /*!< Ofs=8, w=8 Analog watchdog high threshold flag */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_AWSR_s(__RO DFSDM_DFSDM0_AWSR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_AWCFR_s { /*!< analog watchdog clear flag register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CLRAWLTF         :  8; /*!< Ofs=0, w=8 Clear the analog watchdog low threshold flag */
      __RWB uint32_t CLRAWHTF         :  8; /*!< Ofs=8, w=8 Clear the analog watchdog high threshold flag */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_AWCFR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM0_AWCFR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM0_AWCFR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_EXMAX_s { /*!< Extremes detector maximum register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t EXMAXCH          :  3; /*!< Ofs=0, w=3 Extremes detector maximum data channel */
            uint32_t unused0          :  5;
      __ROB uint32_t EXMAX            : 24; /*!< Ofs=8, w=24 Extremes detector maximum value */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_EXMAX_s(__RO DFSDM_DFSDM0_EXMAX_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_EXMIN_s { /*!< Extremes detector minimum register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t EXMINCH          :  3; /*!< Ofs=0, w=3 Extremes detector minimum data channel */
            uint32_t unused0          :  5;
      __ROB uint32_t EXMIN            : 24; /*!< Ofs=8, w=24 EXMIN */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_EXMIN_s(__RO DFSDM_DFSDM0_EXMIN_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM0_CNVTIMR_s { /*!< conversion timer register */
  union {
      __ROB uint32_t R;
    struct {
            uint32_t unused0          :  4;
      __ROB uint32_t CNVCNT           : 28; /*!< Ofs=4, w=28 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM0_CNVTIMR_s(__RO DFSDM_DFSDM0_CNVTIMR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_CR1_s { /*!< control register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DFEN             :  1; /*!< Ofs=0, w=1 DFSDM enable */
      __RWB uint32_t JSWSTART         :  1; /*!< Ofs=1, w=1 Start a conversion of the injected group of channels */
            uint32_t unused0          :  1;
      __RWB uint32_t JSYNC            :  1; /*!< Ofs=3, w=1 Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger */
      __RWB uint32_t JSCAN            :  1; /*!< Ofs=4, w=1 Scanning conversion mode for injected conversions */
      __RWB uint32_t JDMAEN           :  1; /*!< Ofs=5, w=1 DMA channel enabled to read data for the injected channel group */
            uint32_t unused1          :  2;
      __RWB uint32_t JEXTSEL          :  3; /*!< Ofs=8, w=3 Trigger signal selection for launching injected conversions */
            uint32_t unused2          :  2;
      __RWB uint32_t JEXTEN           :  2; /*!< Ofs=13, w=2 Trigger enable and trigger edge selection for injected conversions */
            uint32_t unused3          :  2;
      __RWB uint32_t RSWSTART         :  1; /*!< Ofs=17, w=1 Software start of a conversion on the regular channel */
      __RWB uint32_t RCONT            :  1; /*!< Ofs=18, w=1 Continuous mode selection for regular conversions */
      __RWB uint32_t RSYNC            :  1; /*!< Ofs=19, w=1 Launch regular conversion synchronously with DFSDM0 */
            uint32_t unused4          :  1;
      __RWB uint32_t RDMAEN           :  1; /*!< Ofs=21, w=1 DMA channel enabled to read data for the regular conversion */
            uint32_t unused5          :  2;
      __RWB uint32_t RCH              :  3; /*!< Ofs=24, w=3 Regular channel selection */
            uint32_t unused6          :  2;
      __RWB uint32_t FAST             :  1; /*!< Ofs=29, w=1 Fast conversion mode selection for regular conversions */
      __RWB uint32_t AWFSEL           :  1; /*!< Ofs=30, w=1 Analog watchdog fast mode select */
            uint32_t unused7          :  1;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_CR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM1_CR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM1_CR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_CR2_s { /*!< control register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t JEOCIE           :  1; /*!< Ofs=0, w=1 Injected end of conversion interrupt enable */
      __RWB uint32_t REOCIE           :  1; /*!< Ofs=1, w=1 Regular end of conversion interrupt enable */
      __RWB uint32_t JOVRIE           :  1; /*!< Ofs=2, w=1 Injected data overrun interrupt enable */
      __RWB uint32_t ROVRIE           :  1; /*!< Ofs=3, w=1 Regular data overrun interrupt enable */
      __RWB uint32_t AWDIE            :  1; /*!< Ofs=4, w=1 Analog watchdog interrupt enable */
      __RWB uint32_t SCDIE            :  1; /*!< Ofs=5, w=1 Short-circuit detector interrupt enable */
      __RWB uint32_t CKABIE           :  1; /*!< Ofs=6, w=1 Clock absence interrupt enable */
            uint32_t unused0          :  1;
      __RWB uint32_t EXCH             :  8; /*!< Ofs=8, w=8 Extremes detector channel selection */
      __RWB uint32_t AWDCH            :  8; /*!< Ofs=16, w=8 Analog watchdog channel selection */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_CR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM1_CR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM1_CR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_ISR_s { /*!< interrupt and status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t JEOCF            :  1; /*!< Ofs=0, w=1 End of injected conversion flag */
      __ROB uint32_t REOCF            :  1; /*!< Ofs=1, w=1 End of regular conversion flag */
      __ROB uint32_t JOVRF            :  1; /*!< Ofs=2, w=1 Injected conversion overrun flag */
      __ROB uint32_t ROVRF            :  1; /*!< Ofs=3, w=1 Regular conversion overrun flag */
      __ROB uint32_t AWDF             :  1; /*!< Ofs=4, w=1 Analog watchdog */
            uint32_t unused0          :  8;
      __ROB uint32_t JCIP             :  1; /*!< Ofs=13, w=1 Injected conversion in progress status */
      __ROB uint32_t RCIP             :  1; /*!< Ofs=14, w=1 Regular conversion in progress status */
            uint32_t unused1          :  1;
      __ROB uint32_t CKABF            :  8; /*!< Ofs=16, w=8 Clock absence flag */
      __ROB uint32_t SCDF             :  8; /*!< Ofs=24, w=8 short-circuit detector flag */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_ISR_s(__RO DFSDM_DFSDM1_ISR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_ICR_s { /*!< interrupt flag clear register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  2;
      __RWB uint32_t CLRJOVRF         :  1; /*!< Ofs=2, w=1 Clear the injected conversion overrun flag */
      __RWB uint32_t CLRROVRF         :  1; /*!< Ofs=3, w=1 Clear the regular conversion overrun flag */
            uint32_t unused1          : 12;
      __RWB uint32_t CLRCKABF         :  8; /*!< Ofs=16, w=8 Clear the clock absence flag */
      __RWB uint32_t CLRSCDF          :  8; /*!< Ofs=24, w=8 Clear the short-circuit detector flag */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_ICR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM1_ICR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM1_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_FCR_s { /*!< filter control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t IOSR             :  8; /*!< Ofs=0, w=8 Integrator oversampling ratio (averaging length) */
            uint32_t unused0          :  8;
      __RWB uint32_t FOSR             : 10; /*!< Ofs=16, w=10 Sinc filter oversampling ratio (decimation rate) */
            uint32_t unused1          :  3;
      __RWB uint32_t FORD             :  3; /*!< Ofs=29, w=3 Sinc filter order */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_FCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM1_FCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM1_FCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_JDATAR_s { /*!< data register for injected group */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t JDATACH          :  3; /*!< Ofs=0, w=3 Injected channel most recently converted */
            uint32_t unused0          :  5;
      __ROB uint32_t JDATA            : 24; /*!< Ofs=8, w=24 Injected group conversion data */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_JDATAR_s(__RO DFSDM_DFSDM1_JDATAR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_RDATAR_s { /*!< data register for the regular channel */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t RDATACH          :  3; /*!< Ofs=0, w=3 Regular channel most recently converted */
            uint32_t unused0          :  1;
      __ROB uint32_t RPEND            :  1; /*!< Ofs=4, w=1 Regular channel pending data */
            uint32_t unused1          :  3;
      __ROB uint32_t RDATA            : 24; /*!< Ofs=8, w=24 Regular channel conversion data */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_RDATAR_s(__RO DFSDM_DFSDM1_RDATAR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_AWHTR_s { /*!< analog watchdog high threshold register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BKAWH            :  4; /*!< Ofs=0, w=4 Break signal assignment to analog watchdog high threshold event */
            uint32_t unused0          :  4;
      __RWB uint32_t AWHT             : 24; /*!< Ofs=8, w=24 Analog watchdog high threshold */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_AWHTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM1_AWHTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM1_AWHTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_AWLTR_s { /*!< analog watchdog low threshold register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BKAWL            :  4; /*!< Ofs=0, w=4 Break signal assignment to analog watchdog low threshold event */
            uint32_t unused0          :  4;
      __RWB uint32_t AWLT             : 24; /*!< Ofs=8, w=24 Analog watchdog low threshold */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_AWLTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM1_AWLTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM1_AWLTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_AWSR_s { /*!< analog watchdog status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t AWLTF            :  8; /*!< Ofs=0, w=8 Analog watchdog low threshold flag */
      __ROB uint32_t AWHTF            :  8; /*!< Ofs=8, w=8 Analog watchdog high threshold flag */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_AWSR_s(__RO DFSDM_DFSDM1_AWSR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_AWCFR_s { /*!< analog watchdog clear flag register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CLRAWLTF         :  8; /*!< Ofs=0, w=8 Clear the analog watchdog low threshold flag */
      __RWB uint32_t CLRAWHTF         :  8; /*!< Ofs=8, w=8 Clear the analog watchdog high threshold flag */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_AWCFR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM1_AWCFR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM1_AWCFR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_EXMAX_s { /*!< Extremes detector maximum register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t EXMAXCH          :  3; /*!< Ofs=0, w=3 Extremes detector maximum data channel */
            uint32_t unused0          :  5;
      __ROB uint32_t EXMAX            : 24; /*!< Ofs=8, w=24 Extremes detector maximum value */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_EXMAX_s(__RO DFSDM_DFSDM1_EXMAX_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_EXMIN_s { /*!< Extremes detector minimum register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t EXMINCH          :  3; /*!< Ofs=0, w=3 Extremes detector minimum data channel */
            uint32_t unused0          :  5;
      __ROB uint32_t EXMIN            : 24; /*!< Ofs=8, w=24 EXMIN */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_EXMIN_s(__RO DFSDM_DFSDM1_EXMIN_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM1_CNVTIMR_s { /*!< conversion timer register */
  union {
      __ROB uint32_t R;
    struct {
            uint32_t unused0          :  4;
      __ROB uint32_t CNVCNT           : 28; /*!< Ofs=4, w=28 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM1_CNVTIMR_s(__RO DFSDM_DFSDM1_CNVTIMR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_CR1_s { /*!< control register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DFEN             :  1; /*!< Ofs=0, w=1 DFSDM enable */
      __RWB uint32_t JSWSTART         :  1; /*!< Ofs=1, w=1 Start a conversion of the injected group of channels */
            uint32_t unused0          :  1;
      __RWB uint32_t JSYNC            :  1; /*!< Ofs=3, w=1 Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger */
      __RWB uint32_t JSCAN            :  1; /*!< Ofs=4, w=1 Scanning conversion mode for injected conversions */
      __RWB uint32_t JDMAEN           :  1; /*!< Ofs=5, w=1 DMA channel enabled to read data for the injected channel group */
            uint32_t unused1          :  2;
      __RWB uint32_t JEXTSEL          :  3; /*!< Ofs=8, w=3 Trigger signal selection for launching injected conversions */
            uint32_t unused2          :  2;
      __RWB uint32_t JEXTEN           :  2; /*!< Ofs=13, w=2 Trigger enable and trigger edge selection for injected conversions */
            uint32_t unused3          :  2;
      __RWB uint32_t RSWSTART         :  1; /*!< Ofs=17, w=1 Software start of a conversion on the regular channel */
      __RWB uint32_t RCONT            :  1; /*!< Ofs=18, w=1 Continuous mode selection for regular conversions */
      __RWB uint32_t RSYNC            :  1; /*!< Ofs=19, w=1 Launch regular conversion synchronously with DFSDM0 */
            uint32_t unused4          :  1;
      __RWB uint32_t RDMAEN           :  1; /*!< Ofs=21, w=1 DMA channel enabled to read data for the regular conversion */
            uint32_t unused5          :  2;
      __RWB uint32_t RCH              :  3; /*!< Ofs=24, w=3 Regular channel selection */
            uint32_t unused6          :  2;
      __RWB uint32_t FAST             :  1; /*!< Ofs=29, w=1 Fast conversion mode selection for regular conversions */
      __RWB uint32_t AWFSEL           :  1; /*!< Ofs=30, w=1 Analog watchdog fast mode select */
            uint32_t unused7          :  1;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_CR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM2_CR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM2_CR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_CR2_s { /*!< control register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t JEOCIE           :  1; /*!< Ofs=0, w=1 Injected end of conversion interrupt enable */
      __RWB uint32_t REOCIE           :  1; /*!< Ofs=1, w=1 Regular end of conversion interrupt enable */
      __RWB uint32_t JOVRIE           :  1; /*!< Ofs=2, w=1 Injected data overrun interrupt enable */
      __RWB uint32_t ROVRIE           :  1; /*!< Ofs=3, w=1 Regular data overrun interrupt enable */
      __RWB uint32_t AWDIE            :  1; /*!< Ofs=4, w=1 Analog watchdog interrupt enable */
      __RWB uint32_t SCDIE            :  1; /*!< Ofs=5, w=1 Short-circuit detector interrupt enable */
      __RWB uint32_t CKABIE           :  1; /*!< Ofs=6, w=1 Clock absence interrupt enable */
            uint32_t unused0          :  1;
      __RWB uint32_t EXCH             :  8; /*!< Ofs=8, w=8 Extremes detector channel selection */
      __RWB uint32_t AWDCH            :  8; /*!< Ofs=16, w=8 Analog watchdog channel selection */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_CR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM2_CR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM2_CR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_ISR_s { /*!< interrupt and status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t JEOCF            :  1; /*!< Ofs=0, w=1 End of injected conversion flag */
      __ROB uint32_t REOCF            :  1; /*!< Ofs=1, w=1 End of regular conversion flag */
      __ROB uint32_t JOVRF            :  1; /*!< Ofs=2, w=1 Injected conversion overrun flag */
      __ROB uint32_t ROVRF            :  1; /*!< Ofs=3, w=1 Regular conversion overrun flag */
      __ROB uint32_t AWDF             :  1; /*!< Ofs=4, w=1 Analog watchdog */
            uint32_t unused0          :  8;
      __ROB uint32_t JCIP             :  1; /*!< Ofs=13, w=1 Injected conversion in progress status */
      __ROB uint32_t RCIP             :  1; /*!< Ofs=14, w=1 Regular conversion in progress status */
            uint32_t unused1          :  1;
      __ROB uint32_t CKABF            :  8; /*!< Ofs=16, w=8 Clock absence flag */
      __ROB uint32_t SCDF             :  8; /*!< Ofs=24, w=8 short-circuit detector flag */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_ISR_s(__RO DFSDM_DFSDM2_ISR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_ICR_s { /*!< interrupt flag clear register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  2;
      __RWB uint32_t CLRJOVRF         :  1; /*!< Ofs=2, w=1 Clear the injected conversion overrun flag */
      __RWB uint32_t CLRROVRF         :  1; /*!< Ofs=3, w=1 Clear the regular conversion overrun flag */
            uint32_t unused1          : 12;
      __RWB uint32_t CLRCKABF         :  8; /*!< Ofs=16, w=8 Clear the clock absence flag */
      __RWB uint32_t CLRSCDF          :  8; /*!< Ofs=24, w=8 Clear the short-circuit detector flag */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_ICR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM2_ICR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM2_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_FCR_s { /*!< filter control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t IOSR             :  8; /*!< Ofs=0, w=8 Integrator oversampling ratio (averaging length) */
            uint32_t unused0          :  8;
      __RWB uint32_t FOSR             : 10; /*!< Ofs=16, w=10 Sinc filter oversampling ratio (decimation rate) */
            uint32_t unused1          :  3;
      __RWB uint32_t FORD             :  3; /*!< Ofs=29, w=3 Sinc filter order */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_FCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM2_FCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM2_FCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_JDATAR_s { /*!< data register for injected group */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t JDATACH          :  3; /*!< Ofs=0, w=3 Injected channel most recently converted */
            uint32_t unused0          :  5;
      __ROB uint32_t JDATA            : 24; /*!< Ofs=8, w=24 Injected group conversion data */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_JDATAR_s(__RO DFSDM_DFSDM2_JDATAR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_RDATAR_s { /*!< data register for the regular channel */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t RDATACH          :  3; /*!< Ofs=0, w=3 Regular channel most recently converted */
            uint32_t unused0          :  1;
      __ROB uint32_t RPEND            :  1; /*!< Ofs=4, w=1 Regular channel pending data */
            uint32_t unused1          :  3;
      __ROB uint32_t RDATA            : 24; /*!< Ofs=8, w=24 Regular channel conversion data */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_RDATAR_s(__RO DFSDM_DFSDM2_RDATAR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_AWHTR_s { /*!< analog watchdog high threshold register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BKAWH            :  4; /*!< Ofs=0, w=4 Break signal assignment to analog watchdog high threshold event */
            uint32_t unused0          :  4;
      __RWB uint32_t AWHT             : 24; /*!< Ofs=8, w=24 Analog watchdog high threshold */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_AWHTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM2_AWHTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM2_AWHTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_AWLTR_s { /*!< analog watchdog low threshold register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BKAWL            :  4; /*!< Ofs=0, w=4 Break signal assignment to analog watchdog low threshold event */
            uint32_t unused0          :  4;
      __RWB uint32_t AWLT             : 24; /*!< Ofs=8, w=24 Analog watchdog low threshold */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_AWLTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM2_AWLTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM2_AWLTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_AWSR_s { /*!< analog watchdog status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t AWLTF            :  8; /*!< Ofs=0, w=8 Analog watchdog low threshold flag */
      __ROB uint32_t AWHTF            :  8; /*!< Ofs=8, w=8 Analog watchdog high threshold flag */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_AWSR_s(__RO DFSDM_DFSDM2_AWSR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_AWCFR_s { /*!< analog watchdog clear flag register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CLRAWLTF         :  8; /*!< Ofs=0, w=8 Clear the analog watchdog low threshold flag */
      __RWB uint32_t CLRAWHTF         :  8; /*!< Ofs=8, w=8 Clear the analog watchdog high threshold flag */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_AWCFR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM2_AWCFR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM2_AWCFR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_EXMAX_s { /*!< Extremes detector maximum register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t EXMAXCH          :  3; /*!< Ofs=0, w=3 Extremes detector maximum data channel */
            uint32_t unused0          :  5;
      __ROB uint32_t EXMAX            : 24; /*!< Ofs=8, w=24 Extremes detector maximum value */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_EXMAX_s(__RO DFSDM_DFSDM2_EXMAX_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_EXMIN_s { /*!< Extremes detector minimum register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t EXMINCH          :  3; /*!< Ofs=0, w=3 Extremes detector minimum data channel */
            uint32_t unused0          :  5;
      __ROB uint32_t EXMIN            : 24; /*!< Ofs=8, w=24 EXMIN */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_EXMIN_s(__RO DFSDM_DFSDM2_EXMIN_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM2_CNVTIMR_s { /*!< conversion timer register */
  union {
      __ROB uint32_t R;
    struct {
            uint32_t unused0          :  4;
      __ROB uint32_t CNVCNT           : 28; /*!< Ofs=4, w=28 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM2_CNVTIMR_s(__RO DFSDM_DFSDM2_CNVTIMR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_CR1_s { /*!< control register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DFEN             :  1; /*!< Ofs=0, w=1 DFSDM enable */
      __RWB uint32_t JSWSTART         :  1; /*!< Ofs=1, w=1 Start a conversion of the injected group of channels */
            uint32_t unused0          :  1;
      __RWB uint32_t JSYNC            :  1; /*!< Ofs=3, w=1 Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger */
      __RWB uint32_t JSCAN            :  1; /*!< Ofs=4, w=1 Scanning conversion mode for injected conversions */
      __RWB uint32_t JDMAEN           :  1; /*!< Ofs=5, w=1 DMA channel enabled to read data for the injected channel group */
            uint32_t unused1          :  2;
      __RWB uint32_t JEXTSEL          :  3; /*!< Ofs=8, w=3 Trigger signal selection for launching injected conversions */
            uint32_t unused2          :  2;
      __RWB uint32_t JEXTEN           :  2; /*!< Ofs=13, w=2 Trigger enable and trigger edge selection for injected conversions */
            uint32_t unused3          :  2;
      __RWB uint32_t RSWSTART         :  1; /*!< Ofs=17, w=1 Software start of a conversion on the regular channel */
      __RWB uint32_t RCONT            :  1; /*!< Ofs=18, w=1 Continuous mode selection for regular conversions */
      __RWB uint32_t RSYNC            :  1; /*!< Ofs=19, w=1 Launch regular conversion synchronously with DFSDM0 */
            uint32_t unused4          :  1;
      __RWB uint32_t RDMAEN           :  1; /*!< Ofs=21, w=1 DMA channel enabled to read data for the regular conversion */
            uint32_t unused5          :  2;
      __RWB uint32_t RCH              :  3; /*!< Ofs=24, w=3 Regular channel selection */
            uint32_t unused6          :  2;
      __RWB uint32_t FAST             :  1; /*!< Ofs=29, w=1 Fast conversion mode selection for regular conversions */
      __RWB uint32_t AWFSEL           :  1; /*!< Ofs=30, w=1 Analog watchdog fast mode select */
            uint32_t unused7          :  1;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_CR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM3_CR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM3_CR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_CR2_s { /*!< control register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t JEOCIE           :  1; /*!< Ofs=0, w=1 Injected end of conversion interrupt enable */
      __RWB uint32_t REOCIE           :  1; /*!< Ofs=1, w=1 Regular end of conversion interrupt enable */
      __RWB uint32_t JOVRIE           :  1; /*!< Ofs=2, w=1 Injected data overrun interrupt enable */
      __RWB uint32_t ROVRIE           :  1; /*!< Ofs=3, w=1 Regular data overrun interrupt enable */
      __RWB uint32_t AWDIE            :  1; /*!< Ofs=4, w=1 Analog watchdog interrupt enable */
      __RWB uint32_t SCDIE            :  1; /*!< Ofs=5, w=1 Short-circuit detector interrupt enable */
      __RWB uint32_t CKABIE           :  1; /*!< Ofs=6, w=1 Clock absence interrupt enable */
            uint32_t unused0          :  1;
      __RWB uint32_t EXCH             :  8; /*!< Ofs=8, w=8 Extremes detector channel selection */
      __RWB uint32_t AWDCH            :  8; /*!< Ofs=16, w=8 Analog watchdog channel selection */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_CR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM3_CR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM3_CR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_ISR_s { /*!< interrupt and status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t JEOCF            :  1; /*!< Ofs=0, w=1 End of injected conversion flag */
      __ROB uint32_t REOCF            :  1; /*!< Ofs=1, w=1 End of regular conversion flag */
      __ROB uint32_t JOVRF            :  1; /*!< Ofs=2, w=1 Injected conversion overrun flag */
      __ROB uint32_t ROVRF            :  1; /*!< Ofs=3, w=1 Regular conversion overrun flag */
      __ROB uint32_t AWDF             :  1; /*!< Ofs=4, w=1 Analog watchdog */
            uint32_t unused0          :  8;
      __ROB uint32_t JCIP             :  1; /*!< Ofs=13, w=1 Injected conversion in progress status */
      __ROB uint32_t RCIP             :  1; /*!< Ofs=14, w=1 Regular conversion in progress status */
            uint32_t unused1          :  1;
      __ROB uint32_t CKABF            :  8; /*!< Ofs=16, w=8 Clock absence flag */
      __ROB uint32_t SCDF             :  8; /*!< Ofs=24, w=8 short-circuit detector flag */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_ISR_s(__RO DFSDM_DFSDM3_ISR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_ICR_s { /*!< interrupt flag clear register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  2;
      __RWB uint32_t CLRJOVRF         :  1; /*!< Ofs=2, w=1 Clear the injected conversion overrun flag */
      __RWB uint32_t CLRROVRF         :  1; /*!< Ofs=3, w=1 Clear the regular conversion overrun flag */
            uint32_t unused1          : 12;
      __RWB uint32_t CLRCKABF         :  8; /*!< Ofs=16, w=8 Clear the clock absence flag */
      __RWB uint32_t CLRSCDF          :  8; /*!< Ofs=24, w=8 Clear the short-circuit detector flag */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_ICR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM3_ICR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM3_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_FCR_s { /*!< filter control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t IOSR             :  8; /*!< Ofs=0, w=8 Integrator oversampling ratio (averaging length) */
            uint32_t unused0          :  8;
      __RWB uint32_t FOSR             : 10; /*!< Ofs=16, w=10 Sinc filter oversampling ratio (decimation rate) */
            uint32_t unused1          :  3;
      __RWB uint32_t FORD             :  3; /*!< Ofs=29, w=3 Sinc filter order */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_FCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM3_FCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM3_FCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_JDATAR_s { /*!< data register for injected group */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t JDATACH          :  3; /*!< Ofs=0, w=3 Injected channel most recently converted */
            uint32_t unused0          :  5;
      __ROB uint32_t JDATA            : 24; /*!< Ofs=8, w=24 Injected group conversion data */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_JDATAR_s(__RO DFSDM_DFSDM3_JDATAR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_RDATAR_s { /*!< data register for the regular channel */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t RDATACH          :  3; /*!< Ofs=0, w=3 Regular channel most recently converted */
            uint32_t unused0          :  1;
      __ROB uint32_t RPEND            :  1; /*!< Ofs=4, w=1 Regular channel pending data */
            uint32_t unused1          :  3;
      __ROB uint32_t RDATA            : 24; /*!< Ofs=8, w=24 Regular channel conversion data */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_RDATAR_s(__RO DFSDM_DFSDM3_RDATAR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_AWHTR_s { /*!< analog watchdog high threshold register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BKAWH            :  4; /*!< Ofs=0, w=4 Break signal assignment to analog watchdog high threshold event */
            uint32_t unused0          :  4;
      __RWB uint32_t AWHT             : 24; /*!< Ofs=8, w=24 Analog watchdog high threshold */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_AWHTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM3_AWHTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM3_AWHTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_AWLTR_s { /*!< analog watchdog low threshold register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t BKAWL            :  4; /*!< Ofs=0, w=4 Break signal assignment to analog watchdog low threshold event */
            uint32_t unused0          :  4;
      __RWB uint32_t AWLT             : 24; /*!< Ofs=8, w=24 Analog watchdog low threshold */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_AWLTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM3_AWLTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM3_AWLTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_AWSR_s { /*!< analog watchdog status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t AWLTF            :  8; /*!< Ofs=0, w=8 Analog watchdog low threshold flag */
      __ROB uint32_t AWHTF            :  8; /*!< Ofs=8, w=8 Analog watchdog high threshold flag */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_AWSR_s(__RO DFSDM_DFSDM3_AWSR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_AWCFR_s { /*!< analog watchdog clear flag register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CLRAWLTF         :  8; /*!< Ofs=0, w=8 Clear the analog watchdog low threshold flag */
      __RWB uint32_t CLRAWHTF         :  8; /*!< Ofs=8, w=8 Clear the analog watchdog high threshold flag */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_AWCFR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DFSDM_DFSDM3_AWCFR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DFSDM_DFSDM3_AWCFR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_EXMAX_s { /*!< Extremes detector maximum register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t EXMAXCH          :  3; /*!< Ofs=0, w=3 Extremes detector maximum data channel */
            uint32_t unused0          :  5;
      __ROB uint32_t EXMAX            : 24; /*!< Ofs=8, w=24 Extremes detector maximum value */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_EXMAX_s(__RO DFSDM_DFSDM3_EXMAX_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_EXMIN_s { /*!< Extremes detector minimum register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t EXMINCH          :  3; /*!< Ofs=0, w=3 Extremes detector minimum data channel */
            uint32_t unused0          :  5;
      __ROB uint32_t EXMIN            : 24; /*!< Ofs=8, w=24 EXMIN */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_EXMIN_s(__RO DFSDM_DFSDM3_EXMIN_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DFSDM_DFSDM3_CNVTIMR_s { /*!< conversion timer register */
  union {
      __ROB uint32_t R;
    struct {
            uint32_t unused0          :  4;
      __ROB uint32_t CNVCNT           : 28; /*!< Ofs=4, w=28 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN */
    } B;
  } ;
#ifdef __cplusplus
  DFSDM_DFSDM3_CNVTIMR_s(__RO DFSDM_DFSDM3_CNVTIMR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DMA_ISR_s { /*!< interrupt status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t GIF1             :  1; /*!< Ofs=0, w=1 Channel x global interrupt flag (x = 1 ..7) */
      __ROB uint32_t TCIF1            :  1; /*!< Ofs=1, w=1 Channel x transfer complete flag (x = 1 ..7) */
      __ROB uint32_t HTIF1            :  1; /*!< Ofs=2, w=1 Channel x half transfer flag (x = 1 ..7) */
      __ROB uint32_t TEIF1            :  1; /*!< Ofs=3, w=1 Channel x transfer error flag (x = 1 ..7) */
      __ROB uint32_t GIF2             :  1; /*!< Ofs=4, w=1 Channel x global interrupt flag (x = 1 ..7) */
      __ROB uint32_t TCIF2            :  1; /*!< Ofs=5, w=1 Channel x transfer complete flag (x = 1 ..7) */
      __ROB uint32_t HTIF2            :  1; /*!< Ofs=6, w=1 Channel x half transfer flag (x = 1 ..7) */
      __ROB uint32_t TEIF2            :  1; /*!< Ofs=7, w=1 Channel x transfer error flag (x = 1 ..7) */
      __ROB uint32_t GIF3             :  1; /*!< Ofs=8, w=1 Channel x global interrupt flag (x = 1 ..7) */
      __ROB uint32_t TCIF3            :  1; /*!< Ofs=9, w=1 Channel x transfer complete flag (x = 1 ..7) */
      __ROB uint32_t HTIF3            :  1; /*!< Ofs=10, w=1 Channel x half transfer flag (x = 1 ..7) */
      __ROB uint32_t TEIF3            :  1; /*!< Ofs=11, w=1 Channel x transfer error flag (x = 1 ..7) */
      __ROB uint32_t GIF4             :  1; /*!< Ofs=12, w=1 Channel x global interrupt flag (x = 1 ..7) */
      __ROB uint32_t TCIF4            :  1; /*!< Ofs=13, w=1 Channel x transfer complete flag (x = 1 ..7) */
      __ROB uint32_t HTIF4            :  1; /*!< Ofs=14, w=1 Channel x half transfer flag (x = 1 ..7) */
      __ROB uint32_t TEIF4            :  1; /*!< Ofs=15, w=1 Channel x transfer error flag (x = 1 ..7) */
      __ROB uint32_t GIF5             :  1; /*!< Ofs=16, w=1 Channel x global interrupt flag (x = 1 ..7) */
      __ROB uint32_t TCIF5            :  1; /*!< Ofs=17, w=1 Channel x transfer complete flag (x = 1 ..7) */
      __ROB uint32_t HTIF5            :  1; /*!< Ofs=18, w=1 Channel x half transfer flag (x = 1 ..7) */
      __ROB uint32_t TEIF5            :  1; /*!< Ofs=19, w=1 Channel x transfer error flag (x = 1 ..7) */
      __ROB uint32_t GIF6             :  1; /*!< Ofs=20, w=1 Channel x global interrupt flag (x = 1 ..7) */
      __ROB uint32_t TCIF6            :  1; /*!< Ofs=21, w=1 Channel x transfer complete flag (x = 1 ..7) */
      __ROB uint32_t HTIF6            :  1; /*!< Ofs=22, w=1 Channel x half transfer flag (x = 1 ..7) */
      __ROB uint32_t TEIF6            :  1; /*!< Ofs=23, w=1 Channel x transfer error flag (x = 1 ..7) */
      __ROB uint32_t GIF7             :  1; /*!< Ofs=24, w=1 Channel x global interrupt flag (x = 1 ..7) */
      __ROB uint32_t TCIF7            :  1; /*!< Ofs=25, w=1 Channel x transfer complete flag (x = 1 ..7) */
      __ROB uint32_t HTIF7            :  1; /*!< Ofs=26, w=1 Channel x half transfer flag (x = 1 ..7) */
      __ROB uint32_t TEIF7            :  1; /*!< Ofs=27, w=1 Channel x transfer error flag (x = 1 ..7) */
            uint32_t unused0          :  4;
    } B;
  } ;
#ifdef __cplusplus
  DMA_ISR_s(__RO DMA_ISR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct DMA_IFCR_s { /*!< interrupt flag clear register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t CGIF1            :  1; /*!< Ofs=0, w=1 Channel x global interrupt clear (x = 1 ..7) */
      __WOB uint32_t CTCIF1           :  1; /*!< Ofs=1, w=1 Channel x transfer complete clear (x = 1 ..7) */
      __WOB uint32_t CHTIF1           :  1; /*!< Ofs=2, w=1 Channel x half transfer clear (x = 1 ..7) */
      __WOB uint32_t CTEIF1           :  1; /*!< Ofs=3, w=1 Channel x transfer error clear (x = 1 ..7) */
      __WOB uint32_t CGIF2            :  1; /*!< Ofs=4, w=1 Channel x global interrupt clear (x = 1 ..7) */
      __WOB uint32_t CTCIF2           :  1; /*!< Ofs=5, w=1 Channel x transfer complete clear (x = 1 ..7) */
      __WOB uint32_t CHTIF2           :  1; /*!< Ofs=6, w=1 Channel x half transfer clear (x = 1 ..7) */
      __WOB uint32_t CTEIF2           :  1; /*!< Ofs=7, w=1 Channel x transfer error clear (x = 1 ..7) */
      __WOB uint32_t CGIF3            :  1; /*!< Ofs=8, w=1 Channel x global interrupt clear (x = 1 ..7) */
      __WOB uint32_t CTCIF3           :  1; /*!< Ofs=9, w=1 Channel x transfer complete clear (x = 1 ..7) */
      __WOB uint32_t CHTIF3           :  1; /*!< Ofs=10, w=1 Channel x half transfer clear (x = 1 ..7) */
      __WOB uint32_t CTEIF3           :  1; /*!< Ofs=11, w=1 Channel x transfer error clear (x = 1 ..7) */
      __WOB uint32_t CGIF4            :  1; /*!< Ofs=12, w=1 Channel x global interrupt clear (x = 1 ..7) */
      __WOB uint32_t CTCIF4           :  1; /*!< Ofs=13, w=1 Channel x transfer complete clear (x = 1 ..7) */
      __WOB uint32_t CHTIF4           :  1; /*!< Ofs=14, w=1 Channel x half transfer clear (x = 1 ..7) */
      __WOB uint32_t CTEIF4           :  1; /*!< Ofs=15, w=1 Channel x transfer error clear (x = 1 ..7) */
      __WOB uint32_t CGIF5            :  1; /*!< Ofs=16, w=1 Channel x global interrupt clear (x = 1 ..7) */
      __WOB uint32_t CTCIF5           :  1; /*!< Ofs=17, w=1 Channel x transfer complete clear (x = 1 ..7) */
      __WOB uint32_t CHTIF5           :  1; /*!< Ofs=18, w=1 Channel x half transfer clear (x = 1 ..7) */
      __WOB uint32_t CTEIF5           :  1; /*!< Ofs=19, w=1 Channel x transfer error clear (x = 1 ..7) */
      __WOB uint32_t CGIF6            :  1; /*!< Ofs=20, w=1 Channel x global interrupt clear (x = 1 ..7) */
      __WOB uint32_t CTCIF6           :  1; /*!< Ofs=21, w=1 Channel x transfer complete clear (x = 1 ..7) */
      __WOB uint32_t CHTIF6           :  1; /*!< Ofs=22, w=1 Channel x half transfer clear (x = 1 ..7) */
      __WOB uint32_t CTEIF6           :  1; /*!< Ofs=23, w=1 Channel x transfer error clear (x = 1 ..7) */
      __WOB uint32_t CGIF7            :  1; /*!< Ofs=24, w=1 Channel x global interrupt clear (x = 1 ..7) */
      __WOB uint32_t CTCIF7           :  1; /*!< Ofs=25, w=1 Channel x transfer complete clear (x = 1 ..7) */
      __WOB uint32_t CHTIF7           :  1; /*!< Ofs=26, w=1 Channel x half transfer clear (x = 1 ..7) */
      __WOB uint32_t CTEIF7           :  1; /*!< Ofs=27, w=1 Channel x transfer error clear (x = 1 ..7) */
            uint32_t unused0          :  4;
    } B;
  } ;
#ifdef __cplusplus
  DMA_IFCR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    DMA_IFCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DMA_CCR1_s { /*!< channel x configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EN               :  1; /*!< Ofs=0, w=1 Channel enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=1, w=1 Transfer complete interrupt enable */
      __RWB uint32_t HTIE             :  1; /*!< Ofs=2, w=1 Half transfer interrupt enable */
      __RWB uint32_t TEIE             :  1; /*!< Ofs=3, w=1 Transfer error interrupt enable */
      __RWB uint32_t DIR              :  1; /*!< Ofs=4, w=1 Data transfer direction */
      __RWB uint32_t CIRC             :  1; /*!< Ofs=5, w=1 Circular mode */
      __RWB uint32_t PINC             :  1; /*!< Ofs=6, w=1 Peripheral increment mode */
      __RWB uint32_t MINC             :  1; /*!< Ofs=7, w=1 Memory increment mode */
      __RWB uint32_t PSIZE            :  2; /*!< Ofs=8, w=2 Peripheral size */
      __RWB uint32_t MSIZE            :  2; /*!< Ofs=10, w=2 Memory size */
      __RWB uint32_t PL               :  2; /*!< Ofs=12, w=2 Channel priority level */
      __RWB uint32_t MEM2MEM          :  1; /*!< Ofs=14, w=1 Memory to memory mode */
            uint32_t unused0          : 17;
    } B;
  } ;
#ifdef __cplusplus
  DMA_CCR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DMA_CCR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DMA_CCR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DMA_CCR2_s { /*!< channel x configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EN               :  1; /*!< Ofs=0, w=1 Channel enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=1, w=1 Transfer complete interrupt enable */
      __RWB uint32_t HTIE             :  1; /*!< Ofs=2, w=1 Half transfer interrupt enable */
      __RWB uint32_t TEIE             :  1; /*!< Ofs=3, w=1 Transfer error interrupt enable */
      __RWB uint32_t DIR              :  1; /*!< Ofs=4, w=1 Data transfer direction */
      __RWB uint32_t CIRC             :  1; /*!< Ofs=5, w=1 Circular mode */
      __RWB uint32_t PINC             :  1; /*!< Ofs=6, w=1 Peripheral increment mode */
      __RWB uint32_t MINC             :  1; /*!< Ofs=7, w=1 Memory increment mode */
      __RWB uint32_t PSIZE            :  2; /*!< Ofs=8, w=2 Peripheral size */
      __RWB uint32_t MSIZE            :  2; /*!< Ofs=10, w=2 Memory size */
      __RWB uint32_t PL               :  2; /*!< Ofs=12, w=2 Channel priority level */
      __RWB uint32_t MEM2MEM          :  1; /*!< Ofs=14, w=1 Memory to memory mode */
            uint32_t unused0          : 17;
    } B;
  } ;
#ifdef __cplusplus
  DMA_CCR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DMA_CCR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DMA_CCR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DMA_CCR3_s { /*!< channel x configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EN               :  1; /*!< Ofs=0, w=1 Channel enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=1, w=1 Transfer complete interrupt enable */
      __RWB uint32_t HTIE             :  1; /*!< Ofs=2, w=1 Half transfer interrupt enable */
      __RWB uint32_t TEIE             :  1; /*!< Ofs=3, w=1 Transfer error interrupt enable */
      __RWB uint32_t DIR              :  1; /*!< Ofs=4, w=1 Data transfer direction */
      __RWB uint32_t CIRC             :  1; /*!< Ofs=5, w=1 Circular mode */
      __RWB uint32_t PINC             :  1; /*!< Ofs=6, w=1 Peripheral increment mode */
      __RWB uint32_t MINC             :  1; /*!< Ofs=7, w=1 Memory increment mode */
      __RWB uint32_t PSIZE            :  2; /*!< Ofs=8, w=2 Peripheral size */
      __RWB uint32_t MSIZE            :  2; /*!< Ofs=10, w=2 Memory size */
      __RWB uint32_t PL               :  2; /*!< Ofs=12, w=2 Channel priority level */
      __RWB uint32_t MEM2MEM          :  1; /*!< Ofs=14, w=1 Memory to memory mode */
            uint32_t unused0          : 17;
    } B;
  } ;
#ifdef __cplusplus
  DMA_CCR3_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DMA_CCR3_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DMA_CCR3_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DMA_CCR4_s { /*!< channel x configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EN               :  1; /*!< Ofs=0, w=1 Channel enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=1, w=1 Transfer complete interrupt enable */
      __RWB uint32_t HTIE             :  1; /*!< Ofs=2, w=1 Half transfer interrupt enable */
      __RWB uint32_t TEIE             :  1; /*!< Ofs=3, w=1 Transfer error interrupt enable */
      __RWB uint32_t DIR              :  1; /*!< Ofs=4, w=1 Data transfer direction */
      __RWB uint32_t CIRC             :  1; /*!< Ofs=5, w=1 Circular mode */
      __RWB uint32_t PINC             :  1; /*!< Ofs=6, w=1 Peripheral increment mode */
      __RWB uint32_t MINC             :  1; /*!< Ofs=7, w=1 Memory increment mode */
      __RWB uint32_t PSIZE            :  2; /*!< Ofs=8, w=2 Peripheral size */
      __RWB uint32_t MSIZE            :  2; /*!< Ofs=10, w=2 Memory size */
      __RWB uint32_t PL               :  2; /*!< Ofs=12, w=2 Channel priority level */
      __RWB uint32_t MEM2MEM          :  1; /*!< Ofs=14, w=1 Memory to memory mode */
            uint32_t unused0          : 17;
    } B;
  } ;
#ifdef __cplusplus
  DMA_CCR4_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DMA_CCR4_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DMA_CCR4_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DMA_CCR5_s { /*!< channel x configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EN               :  1; /*!< Ofs=0, w=1 Channel enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=1, w=1 Transfer complete interrupt enable */
      __RWB uint32_t HTIE             :  1; /*!< Ofs=2, w=1 Half transfer interrupt enable */
      __RWB uint32_t TEIE             :  1; /*!< Ofs=3, w=1 Transfer error interrupt enable */
      __RWB uint32_t DIR              :  1; /*!< Ofs=4, w=1 Data transfer direction */
      __RWB uint32_t CIRC             :  1; /*!< Ofs=5, w=1 Circular mode */
      __RWB uint32_t PINC             :  1; /*!< Ofs=6, w=1 Peripheral increment mode */
      __RWB uint32_t MINC             :  1; /*!< Ofs=7, w=1 Memory increment mode */
      __RWB uint32_t PSIZE            :  2; /*!< Ofs=8, w=2 Peripheral size */
      __RWB uint32_t MSIZE            :  2; /*!< Ofs=10, w=2 Memory size */
      __RWB uint32_t PL               :  2; /*!< Ofs=12, w=2 Channel priority level */
      __RWB uint32_t MEM2MEM          :  1; /*!< Ofs=14, w=1 Memory to memory mode */
            uint32_t unused0          : 17;
    } B;
  } ;
#ifdef __cplusplus
  DMA_CCR5_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DMA_CCR5_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DMA_CCR5_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DMA_CCR6_s { /*!< channel x configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EN               :  1; /*!< Ofs=0, w=1 Channel enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=1, w=1 Transfer complete interrupt enable */
      __RWB uint32_t HTIE             :  1; /*!< Ofs=2, w=1 Half transfer interrupt enable */
      __RWB uint32_t TEIE             :  1; /*!< Ofs=3, w=1 Transfer error interrupt enable */
      __RWB uint32_t DIR              :  1; /*!< Ofs=4, w=1 Data transfer direction */
      __RWB uint32_t CIRC             :  1; /*!< Ofs=5, w=1 Circular mode */
      __RWB uint32_t PINC             :  1; /*!< Ofs=6, w=1 Peripheral increment mode */
      __RWB uint32_t MINC             :  1; /*!< Ofs=7, w=1 Memory increment mode */
      __RWB uint32_t PSIZE            :  2; /*!< Ofs=8, w=2 Peripheral size */
      __RWB uint32_t MSIZE            :  2; /*!< Ofs=10, w=2 Memory size */
      __RWB uint32_t PL               :  2; /*!< Ofs=12, w=2 Channel priority level */
      __RWB uint32_t MEM2MEM          :  1; /*!< Ofs=14, w=1 Memory to memory mode */
            uint32_t unused0          : 17;
    } B;
  } ;
#ifdef __cplusplus
  DMA_CCR6_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DMA_CCR6_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DMA_CCR6_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DMA_CCR7_s { /*!< channel x configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EN               :  1; /*!< Ofs=0, w=1 Channel enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=1, w=1 Transfer complete interrupt enable */
      __RWB uint32_t HTIE             :  1; /*!< Ofs=2, w=1 Half transfer interrupt enable */
      __RWB uint32_t TEIE             :  1; /*!< Ofs=3, w=1 Transfer error interrupt enable */
      __RWB uint32_t DIR              :  1; /*!< Ofs=4, w=1 Data transfer direction */
      __RWB uint32_t CIRC             :  1; /*!< Ofs=5, w=1 Circular mode */
      __RWB uint32_t PINC             :  1; /*!< Ofs=6, w=1 Peripheral increment mode */
      __RWB uint32_t MINC             :  1; /*!< Ofs=7, w=1 Memory increment mode */
      __RWB uint32_t PSIZE            :  2; /*!< Ofs=8, w=2 Peripheral size */
      __RWB uint32_t MSIZE            :  2; /*!< Ofs=10, w=2 Memory size */
      __RWB uint32_t PL               :  2; /*!< Ofs=12, w=2 Channel priority level */
      __RWB uint32_t MEM2MEM          :  1; /*!< Ofs=14, w=1 Memory to memory mode */
            uint32_t unused0          : 17;
    } B;
  } ;
#ifdef __cplusplus
  DMA_CCR7_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DMA_CCR7_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DMA_CCR7_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct DMA_CSELR_s { /*!< channel selection register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t C1S              :  4; /*!< Ofs=0, w=4 DMA channel 1 selection */
      __RWB uint32_t C2S              :  4; /*!< Ofs=4, w=4 DMA channel 2 selection */
      __RWB uint32_t C3S              :  4; /*!< Ofs=8, w=4 DMA channel 3 selection */
      __RWB uint32_t C4S              :  4; /*!< Ofs=12, w=4 DMA channel 4 selection */
      __RWB uint32_t C5S              :  4; /*!< Ofs=16, w=4 DMA channel 5 selection */
      __RWB uint32_t C6S              :  4; /*!< Ofs=20, w=4 DMA channel 6 selection */
      __RWB uint32_t C7S              :  4; /*!< Ofs=24, w=4 DMA channel 7 selection */
            uint32_t unused0          :  4;
    } B;
  } ;
#ifdef __cplusplus
  DMA_CSELR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    DMA_CSELR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    DMA_CSELR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_CR_s { /*!< Clock control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t MSION            :  1; /*!< Ofs=0, w=1 MSI clock enable */
      __ROB uint32_t MSIRDY           :  1; /*!< Ofs=1, w=1 MSI clock ready flag */
      __RWB uint32_t MSIPLLEN         :  1; /*!< Ofs=2, w=1 MSI clock PLL enable */
      __WOB uint32_t MSIRGSEL         :  1; /*!< Ofs=3, w=1 MSI clock range selection */
      __RWB uint32_t MSIRANGE         :  4; /*!< Ofs=4, w=4 MSI clock ranges */
      __RWB uint32_t HSION            :  1; /*!< Ofs=8, w=1 HSI clock enable */
      __RWB uint32_t HSIKERON         :  1; /*!< Ofs=9, w=1 HSI always enable for peripheral kernels */
      __ROB uint32_t HSIRDY           :  1; /*!< Ofs=10, w=1 HSI clock ready flag */
      __RWB uint32_t HSIASFS          :  1; /*!< Ofs=11, w=1 HSI automatic start from Stop */
            uint32_t unused0          :  4;
      __RWB uint32_t HSEON            :  1; /*!< Ofs=16, w=1 HSE clock enable */
      __ROB uint32_t HSERDY           :  1; /*!< Ofs=17, w=1 HSE clock ready flag */
      __RWB uint32_t HSEBYP           :  1; /*!< Ofs=18, w=1 HSE crystal oscillator bypass */
      __WOB uint32_t CSSON            :  1; /*!< Ofs=19, w=1 Clock security system enable */
            uint32_t unused1          :  4;
      __RWB uint32_t PLLON            :  1; /*!< Ofs=24, w=1 Main PLL enable */
      __ROB uint32_t PLLRDY           :  1; /*!< Ofs=25, w=1 Main PLL clock ready flag */
      __RWB uint32_t PLLSAI1ON        :  1; /*!< Ofs=26, w=1 SAI1 PLL enable */
      __ROB uint32_t PLLSAI1RDY       :  1; /*!< Ofs=27, w=1 SAI1 PLL clock ready flag */
            uint32_t unused2          :  4;
    } B;
  } ;
#ifdef __cplusplus
  RCC_CR_s(): R(0x00000063u) {};
  template<typename F> void modify (F f) volatile {
    RCC_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_ICSCR_s { /*!< Internal clock sources calibration register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t MSICAL           :  8; /*!< Ofs=0, w=8 MSI clock calibration */
      __RWB uint32_t MSITRIM          :  8; /*!< Ofs=8, w=8 MSI clock trimming */
      __ROB uint32_t HSICAL           :  8; /*!< Ofs=16, w=8 HSI clock calibration */
      __RWB uint32_t HSITRIM          :  5; /*!< Ofs=24, w=5 HSI clock trimming */
            uint32_t unused0          :  3;
    } B;
  } ;
#ifdef __cplusplus
  RCC_ICSCR_s(): R(0x10000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_ICSCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_ICSCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_CFGR_s { /*!< Clock configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SW               :  2; /*!< Ofs=0, w=2 System clock switch */
      __ROB uint32_t SWS              :  2; /*!< Ofs=2, w=2 System clock switch status */
      __RWB uint32_t HPRE             :  4; /*!< Ofs=4, w=4 AHB prescaler */
      __RWB uint32_t PPRE1            :  3; /*!< Ofs=8, w=3 PB low-speed prescaler (APB1) */
      __RWB uint32_t PPRE2            :  3; /*!< Ofs=11, w=3 APB high-speed prescaler (APB2) */
            uint32_t unused0          :  1;
      __RWB uint32_t STOPWUCK         :  1; /*!< Ofs=15, w=1 Wakeup from Stop and CSS backup clock selection */
            uint32_t unused1          :  8;
      __RWB uint32_t MCOSEL           :  3; /*!< Ofs=24, w=3 Microcontroller clock output */
            uint32_t unused2          :  1;
      __ROB uint32_t MCOPRE           :  3; /*!< Ofs=28, w=3 Microcontroller clock output prescaler */
            uint32_t unused3          :  1;
    } B;
  } ;
#ifdef __cplusplus
  RCC_CFGR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_CFGR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_CFGR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_PLLCFGR_s { /*!< PLL configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PLLSRC           :  2; /*!< Ofs=0, w=2 Main PLL, PLLSAI1 and PLLSAI2 entry clock source */
            uint32_t unused0          :  2;
      __RWB uint32_t PLLM             :  3; /*!< Ofs=4, w=3 Division factor for the main PLL and audio PLL (PLLSAI1 and PLLSAI2) input clock */
            uint32_t unused1          :  1;
      __RWB uint32_t PLLN             :  7; /*!< Ofs=8, w=7 Main PLL multiplication factor for VCO */
            uint32_t unused2          :  1;
      __RWB uint32_t PLLPEN           :  1; /*!< Ofs=16, w=1 Main PLL PLLSAI3CLK output enable */
      __RWB uint32_t PLLP             :  1; /*!< Ofs=17, w=1 Main PLL division factor for PLLSAI3CLK (SAI1 and SAI2 clock) */
            uint32_t unused3          :  2;
      __RWB uint32_t PLLQEN           :  1; /*!< Ofs=20, w=1 Main PLL PLLUSB1CLK output enable */
      __RWB uint32_t PLLQ             :  2; /*!< Ofs=21, w=2 Main PLL division factor for PLLUSB1CLK(48 MHz clock) */
            uint32_t unused4          :  1;
      __RWB uint32_t PLLREN           :  1; /*!< Ofs=24, w=1 Main PLL PLLCLK output enable */
      __RWB uint32_t PLLR             :  2; /*!< Ofs=25, w=2 Main PLL division factor for PLLCLK (system clock) */
      __RWB uint32_t PLLPDIV          :  5; /*!< Ofs=27, w=5 Main PLL division factor for PLLSAI2CLK */
    } B;
  } ;
#ifdef __cplusplus
  RCC_PLLCFGR_s(): R(0x00001000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_PLLCFGR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_PLLCFGR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_PLLSAI1CFGR_s { /*!< PLLSAI1 configuration register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  8;
      __RWB uint32_t PLLSAI1N         :  7; /*!< Ofs=8, w=7 SAI1PLL multiplication factor for VCO */
            uint32_t unused1          :  1;
      __RWB uint32_t PLLSAI1PEN       :  1; /*!< Ofs=16, w=1 SAI1PLL PLLSAI1CLK output enable */
      __RWB uint32_t PLLSAI1P         :  1; /*!< Ofs=17, w=1 SAI1PLL division factor for PLLSAI1CLK (SAI1 or SAI2 clock) */
            uint32_t unused2          :  2;
      __RWB uint32_t PLLSAI1QEN       :  1; /*!< Ofs=20, w=1 SAI1PLL PLLUSB2CLK output enable */
      __RWB uint32_t PLLSAI1Q         :  2; /*!< Ofs=21, w=2 SAI1PLL division factor for PLLUSB2CLK (48 MHz clock) */
            uint32_t unused3          :  1;
      __RWB uint32_t PLLSAI1REN       :  1; /*!< Ofs=24, w=1 PLLSAI1 PLLADC1CLK output enable */
      __RWB uint32_t PLLSAI1R         :  2; /*!< Ofs=25, w=2 PLLSAI1 division factor for PLLADC1CLK (ADC clock) */
      __RWB uint32_t PLLSAI1PDIV      :  5; /*!< Ofs=27, w=5 PLLSAI1 division factor for PLLSAI1CLK */
    } B;
  } ;
#ifdef __cplusplus
  RCC_PLLSAI1CFGR_s(): R(0x00001000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_PLLSAI1CFGR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_PLLSAI1CFGR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_CIER_s { /*!< Clock interrupt enable register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LSIRDYIE         :  1; /*!< Ofs=0, w=1 LSI ready interrupt enable */
      __RWB uint32_t LSERDYIE         :  1; /*!< Ofs=1, w=1 LSE ready interrupt enable */
      __RWB uint32_t MSIRDYIE         :  1; /*!< Ofs=2, w=1 MSI ready interrupt enable */
      __RWB uint32_t HSIRDYIE         :  1; /*!< Ofs=3, w=1 HSI ready interrupt enable */
      __RWB uint32_t HSERDYIE         :  1; /*!< Ofs=4, w=1 HSE ready interrupt enable */
      __RWB uint32_t PLLRDYIE         :  1; /*!< Ofs=5, w=1 PLL ready interrupt enable */
      __RWB uint32_t PLLSAI1RDYIE     :  1; /*!< Ofs=6, w=1 PLLSAI1 ready interrupt enable */
            uint32_t unused0          :  2;
      __RWB uint32_t LSECSSIE         :  1; /*!< Ofs=9, w=1 LSE clock security system interrupt enable */
      __RWB uint32_t HSI48RDYIE       :  1; /*!< Ofs=10, w=1 HSI48 ready interrupt enable */
            uint32_t unused1          : 21;
    } B;
  } ;
#ifdef __cplusplus
  RCC_CIER_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_CIER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_CIER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_CIFR_s { /*!< Clock interrupt flag register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t LSIRDYF          :  1; /*!< Ofs=0, w=1 LSI ready interrupt flag */
      __ROB uint32_t LSERDYF          :  1; /*!< Ofs=1, w=1 LSE ready interrupt flag */
      __ROB uint32_t MSIRDYF          :  1; /*!< Ofs=2, w=1 MSI ready interrupt flag */
      __ROB uint32_t HSIRDYF          :  1; /*!< Ofs=3, w=1 HSI ready interrupt flag */
      __ROB uint32_t HSERDYF          :  1; /*!< Ofs=4, w=1 HSE ready interrupt flag */
      __ROB uint32_t PLLRDYF          :  1; /*!< Ofs=5, w=1 PLL ready interrupt flag */
      __ROB uint32_t PLLSAI1RDYF      :  1; /*!< Ofs=6, w=1 PLLSAI1 ready interrupt flag */
            uint32_t unused0          :  1;
      __ROB uint32_t CSSF             :  1; /*!< Ofs=8, w=1 Clock security system interrupt flag */
      __ROB uint32_t LSECSSF          :  1; /*!< Ofs=9, w=1 LSE Clock security system interrupt flag */
      __ROB uint32_t HSI48RDYF        :  1; /*!< Ofs=10, w=1 HSI48 ready interrupt flag */
            uint32_t unused1          : 21;
    } B;
  } ;
#ifdef __cplusplus
  RCC_CIFR_s(__RO RCC_CIFR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct RCC_CICR_s { /*!< Clock interrupt clear register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t LSIRDYC          :  1; /*!< Ofs=0, w=1 LSI ready interrupt clear */
      __WOB uint32_t LSERDYC          :  1; /*!< Ofs=1, w=1 LSE ready interrupt clear */
      __WOB uint32_t MSIRDYC          :  1; /*!< Ofs=2, w=1 MSI ready interrupt clear */
      __WOB uint32_t HSIRDYC          :  1; /*!< Ofs=3, w=1 HSI ready interrupt clear */
      __WOB uint32_t HSERDYC          :  1; /*!< Ofs=4, w=1 HSE ready interrupt clear */
      __WOB uint32_t PLLRDYC          :  1; /*!< Ofs=5, w=1 PLL ready interrupt clear */
      __WOB uint32_t PLLSAI1RDYC      :  1; /*!< Ofs=6, w=1 PLLSAI1 ready interrupt clear */
            uint32_t unused0          :  1;
      __WOB uint32_t CSSC             :  1; /*!< Ofs=8, w=1 Clock security system interrupt clear */
      __WOB uint32_t LSECSSC          :  1; /*!< Ofs=9, w=1 LSE Clock security system interrupt clear */
      __WOB uint32_t HSI48RDYC        :  1; /*!< Ofs=10, w=1 HSI48 oscillator ready interrupt clear */
            uint32_t unused1          : 21;
    } B;
  } ;
#ifdef __cplusplus
  RCC_CICR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    RCC_CICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_AHB1RSTR_s { /*!< AHB1 peripheral reset register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DMA1RST          :  1; /*!< Ofs=0, w=1 DMA1 reset */
      __RWB uint32_t DMA2RST          :  1; /*!< Ofs=1, w=1 DMA2 reset */
            uint32_t unused0          :  6;
      __RWB uint32_t FLASHRST         :  1; /*!< Ofs=8, w=1 Flash memory interface reset */
            uint32_t unused1          :  2;
      __RWB uint32_t CRCRST           :  1; /*!< Ofs=11, w=1 CRC reset */
            uint32_t unused2          :  4;
      __RWB uint32_t TSCRST           :  1; /*!< Ofs=16, w=1 Touch Sensing Controller reset */
            uint32_t unused3          : 15;
    } B;
  } ;
#ifdef __cplusplus
  RCC_AHB1RSTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_AHB1RSTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_AHB1RSTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_AHB2RSTR_s { /*!< AHB2 peripheral reset register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t GPIOARST         :  1; /*!< Ofs=0, w=1 IO port A reset */
      __RWB uint32_t GPIOBRST         :  1; /*!< Ofs=1, w=1 IO port B reset */
      __RWB uint32_t GPIOCRST         :  1; /*!< Ofs=2, w=1 IO port C reset */
      __RWB uint32_t GPIODRST         :  1; /*!< Ofs=3, w=1 IO port D reset */
      __RWB uint32_t GPIOERST         :  1; /*!< Ofs=4, w=1 IO port E reset */
            uint32_t unused0          :  2;
      __RWB uint32_t GPIOHRST         :  1; /*!< Ofs=7, w=1 IO port H reset */
            uint32_t unused1          :  5;
      __RWB uint32_t ADCRST           :  1; /*!< Ofs=13, w=1 ADC reset */
            uint32_t unused2          :  2;
      __RWB uint32_t AESRST           :  1; /*!< Ofs=16, w=1 AES hardware accelerator reset */
            uint32_t unused3          :  1;
      __RWB uint32_t RNGRST           :  1; /*!< Ofs=18, w=1 Random number generator reset */
            uint32_t unused4          : 13;
    } B;
  } ;
#ifdef __cplusplus
  RCC_AHB2RSTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_AHB2RSTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_AHB2RSTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_AHB3RSTR_s { /*!< AHB3 peripheral reset register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  8;
      __RWB uint32_t QSPIRST          :  1; /*!< Ofs=8, w=1 Quad SPI memory interface reset */
            uint32_t unused1          : 23;
    } B;
  } ;
#ifdef __cplusplus
  RCC_AHB3RSTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_AHB3RSTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_AHB3RSTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_APB1RSTR1_s { /*!< APB1 peripheral reset register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TIM2RST          :  1; /*!< Ofs=0, w=1 TIM2 timer reset */
            uint32_t unused0          :  3;
      __RWB uint32_t TIM6RST          :  1; /*!< Ofs=4, w=1 TIM6 timer reset */
      __RWB uint32_t TIM7RST          :  1; /*!< Ofs=5, w=1 TIM7 timer reset */
            uint32_t unused1          :  3;
      __RWB uint32_t LCDRST           :  1; /*!< Ofs=9, w=1 LCD interface reset */
            uint32_t unused2          :  4;
      __RWB uint32_t SPI2RST          :  1; /*!< Ofs=14, w=1 SPI2 reset */
      __RWB uint32_t SPI3RST          :  1; /*!< Ofs=15, w=1 SPI3 reset */
            uint32_t unused3          :  1;
      __RWB uint32_t USART2RST        :  1; /*!< Ofs=17, w=1 USART2 reset */
      __RWB uint32_t USART3RST        :  1; /*!< Ofs=18, w=1 USART3 reset */
      __RWB uint32_t USART4RST        :  1; /*!< Ofs=19, w=1 USART4 reset. */
            uint32_t unused4          :  1;
      __RWB uint32_t I2C1RST          :  1; /*!< Ofs=21, w=1 I2C1 reset */
      __RWB uint32_t I2C2RST          :  1; /*!< Ofs=22, w=1 I2C2 reset */
      __RWB uint32_t I2C3RST          :  1; /*!< Ofs=23, w=1 I2C3 reset */
      __RWB uint32_t CRSRST           :  1; /*!< Ofs=24, w=1 CRS reset */
      __RWB uint32_t CAN1RST          :  1; /*!< Ofs=25, w=1 CAN1 reset */
      __RWB uint32_t USBFSRST         :  1; /*!< Ofs=26, w=1 USB FS reset */
            uint32_t unused5          :  1;
      __RWB uint32_t PWRRST           :  1; /*!< Ofs=28, w=1 Power interface reset */
      __RWB uint32_t DAC1RST          :  1; /*!< Ofs=29, w=1 DAC1 interface reset */
      __RWB uint32_t OPAMPRST         :  1; /*!< Ofs=30, w=1 OPAMP interface reset */
      __RWB uint32_t LPTIM1RST        :  1; /*!< Ofs=31, w=1 Low Power Timer 1 reset */
    } B;
  } ;
#ifdef __cplusplus
  RCC_APB1RSTR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_APB1RSTR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_APB1RSTR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_APB1RSTR2_s { /*!< APB1 peripheral reset register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LPUART1RST       :  1; /*!< Ofs=0, w=1 Low-power UART 1 reset */
      __RWB uint32_t I2C4RST          :  1; /*!< Ofs=1, w=1 I2C4 reset */
      __RWB uint32_t SWPMI1RST        :  1; /*!< Ofs=2, w=1 Single wire protocol reset */
            uint32_t unused0          :  2;
      __RWB uint32_t LPTIM2RST        :  1; /*!< Ofs=5, w=1 Low-power timer 2 reset */
            uint32_t unused1          : 26;
    } B;
  } ;
#ifdef __cplusplus
  RCC_APB1RSTR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_APB1RSTR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_APB1RSTR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_APB2RSTR_s { /*!< APB2 peripheral reset register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SYSCFGRST        :  1; /*!< Ofs=0, w=1 System configuration (SYSCFG) reset */
            uint32_t unused0          :  9;
      __RWB uint32_t SDMMCRST         :  1; /*!< Ofs=10, w=1 SDMMC reset */
      __RWB uint32_t TIM1RST          :  1; /*!< Ofs=11, w=1 TIM1 timer reset */
      __RWB uint32_t SPI1RST          :  1; /*!< Ofs=12, w=1 SPI1 reset */
            uint32_t unused1          :  1;
      __RWB uint32_t USART1RST        :  1; /*!< Ofs=14, w=1 USART1 reset */
            uint32_t unused2          :  1;
      __RWB uint32_t TIM15RST         :  1; /*!< Ofs=16, w=1 TIM15 timer reset */
      __RWB uint32_t TIM16RST         :  1; /*!< Ofs=17, w=1 TIM16 timer reset */
            uint32_t unused3          :  3;
      __RWB uint32_t SAI1RST          :  1; /*!< Ofs=21, w=1 Serial audio interface 1 (SAI1) reset */
            uint32_t unused4          :  2;
      __RWB uint32_t DFSDMRST         :  1; /*!< Ofs=24, w=1 DFSDM filter reset */
            uint32_t unused5          :  7;
    } B;
  } ;
#ifdef __cplusplus
  RCC_APB2RSTR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_APB2RSTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_APB2RSTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_AHB1ENR_s { /*!< AHB1 peripheral clock enable register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DMA1EN           :  1; /*!< Ofs=0, w=1 DMA1 clock enable */
      __RWB uint32_t DMA2EN           :  1; /*!< Ofs=1, w=1 DMA2 clock enable */
            uint32_t unused0          :  6;
      __RWB uint32_t FLASHEN          :  1; /*!< Ofs=8, w=1 Flash memory interface clock enable */
            uint32_t unused1          :  3;
      __RWB uint32_t CRCEN            :  1; /*!< Ofs=12, w=1 CRC clock enable */
            uint32_t unused2          :  3;
      __RWB uint32_t TSCEN            :  1; /*!< Ofs=16, w=1 Touch Sensing Controller clock enable */
            uint32_t unused3          : 15;
    } B;
  } ;
#ifdef __cplusplus
  RCC_AHB1ENR_s(): R(0x00000100u) {};
  template<typename F> void modify (F f) volatile {
    RCC_AHB1ENR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_AHB1ENR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_AHB2ENR_s { /*!< AHB2 peripheral clock enable register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t GPIOAEN          :  1; /*!< Ofs=0, w=1 IO port A clock enable */
      __RWB uint32_t GPIOBEN          :  1; /*!< Ofs=1, w=1 IO port B clock enable */
      __RWB uint32_t GPIOCEN          :  1; /*!< Ofs=2, w=1 IO port C clock enable */
      __RWB uint32_t GPIODEN          :  1; /*!< Ofs=3, w=1 IO port D clock enable */
      __RWB uint32_t GPIOEEN          :  1; /*!< Ofs=4, w=1 IO port E clock enable */
            uint32_t unused0          :  2;
      __RWB uint32_t GPIOHEN          :  1; /*!< Ofs=7, w=1 IO port H clock enable */
            uint32_t unused1          :  5;
      __RWB uint32_t ADCEN            :  1; /*!< Ofs=13, w=1 ADC clock enable */
            uint32_t unused2          :  2;
      __RWB uint32_t AESEN            :  1; /*!< Ofs=16, w=1 AES accelerator clock enable */
            uint32_t unused3          :  1;
      __RWB uint32_t RNGEN            :  1; /*!< Ofs=18, w=1 Random Number Generator clock enable */
            uint32_t unused4          : 13;
    } B;
  } ;
#ifdef __cplusplus
  RCC_AHB2ENR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_AHB2ENR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_AHB2ENR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_AHB3ENR_s { /*!< AHB3 peripheral clock enable register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  8;
      __RWB uint32_t QSPIEN           :  1; /*!< Ofs=8, w=1 QSPIEN */
            uint32_t unused1          : 23;
    } B;
  } ;
#ifdef __cplusplus
  RCC_AHB3ENR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_AHB3ENR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_AHB3ENR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_APB1ENR1_s { /*!< APB1ENR1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TIM2EN           :  1; /*!< Ofs=0, w=1 TIM2 timer clock enable */
      __RWB uint32_t TIM3EN           :  1; /*!< Ofs=1, w=1 TIM3 timer clock enable */
            uint32_t unused0          :  2;
      __RWB uint32_t TIM6EN           :  1; /*!< Ofs=4, w=1 TIM6 timer clock enable */
      __RWB uint32_t TIM7EN           :  1; /*!< Ofs=5, w=1 TIM7 timer clock enable */
            uint32_t unused1          :  3;
      __RWB uint32_t LCDEN            :  1; /*!< Ofs=9, w=1 LCD clock enable */
      __RWB uint32_t RTCAPBEN         :  1; /*!< Ofs=10, w=1 RTC APB clock enable */
      __RWB uint32_t WWDGEN           :  1; /*!< Ofs=11, w=1 Window watchdog clock enable */
            uint32_t unused2          :  2;
      __RWB uint32_t SPI2EN           :  1; /*!< Ofs=14, w=1 SPI2 clock enable */
      __RWB uint32_t SPI3EN           :  1; /*!< Ofs=15, w=1 SPI3 clock enable */
            uint32_t unused3          :  1;
      __RWB uint32_t USART2EN         :  1; /*!< Ofs=17, w=1 USART2 clock enable */
      __RWB uint32_t USART3EN         :  1; /*!< Ofs=18, w=1 USART3 clock enable */
      __RWB uint32_t UART4EN          :  1; /*!< Ofs=19, w=1 UART4 clock enable */
            uint32_t unused4          :  1;
      __RWB uint32_t I2C1EN           :  1; /*!< Ofs=21, w=1 I2C1 clock enable */
      __RWB uint32_t I2C2EN           :  1; /*!< Ofs=22, w=1 I2C2 clock enable */
      __RWB uint32_t I2C3EN           :  1; /*!< Ofs=23, w=1 I2C3 clock enable */
      __RWB uint32_t CRSEN            :  1; /*!< Ofs=24, w=1 CRS clock enable */
      __RWB uint32_t CAN1EN           :  1; /*!< Ofs=25, w=1 CAN1 clock enable */
      __RWB uint32_t USBF             :  1; /*!< Ofs=26, w=1 USB FS clock enable */
            uint32_t unused5          :  1;
      __RWB uint32_t PWREN            :  1; /*!< Ofs=28, w=1 Power interface clock enable */
      __RWB uint32_t DAC1EN           :  1; /*!< Ofs=29, w=1 DAC1 interface clock enable */
      __RWB uint32_t OPAMPEN          :  1; /*!< Ofs=30, w=1 OPAMP interface clock enable */
      __RWB uint32_t LPTIM1EN         :  1; /*!< Ofs=31, w=1 Low power timer 1 clock enable */
    } B;
  } ;
#ifdef __cplusplus
  RCC_APB1ENR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_APB1ENR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_APB1ENR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_APB1ENR2_s { /*!< APB1 peripheral clock enable register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LPUART1EN        :  1; /*!< Ofs=0, w=1 Low power UART 1 clock enable */
      __RWB uint32_t I2C4EN           :  1; /*!< Ofs=1, w=1 I2C4 clock enable */
      __RWB uint32_t SWPMI1EN         :  1; /*!< Ofs=2, w=1 Single wire protocol clock enable */
            uint32_t unused0          :  2;
      __RWB uint32_t LPTIM2EN         :  1; /*!< Ofs=5, w=1 LPTIM2EN */
            uint32_t unused1          : 18;
      __RWB uint32_t DFSDMEN          :  1; /*!< Ofs=24, w=1 DFSDMEN enable */
            uint32_t unused2          :  7;
    } B;
  } ;
#ifdef __cplusplus
  RCC_APB1ENR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_APB1ENR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_APB1ENR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_APB2ENR_s { /*!< APB2ENR */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SYSCFGEN         :  1; /*!< Ofs=0, w=1 SYSCFG clock enable */
            uint32_t unused0          :  6;
      __RWB uint32_t FIREWALLEN       :  1; /*!< Ofs=7, w=1 Firewall clock enable */
            uint32_t unused1          :  2;
      __RWB uint32_t SDMMCEN          :  1; /*!< Ofs=10, w=1 SDMMC clock enable */
      __RWB uint32_t TIM1EN           :  1; /*!< Ofs=11, w=1 TIM1 timer clock enable */
      __RWB uint32_t SPI1EN           :  1; /*!< Ofs=12, w=1 SPI1 clock enable */
            uint32_t unused2          :  1;
      __RWB uint32_t USART1EN         :  1; /*!< Ofs=14, w=1 USART1clock enable */
            uint32_t unused3          :  1;
      __RWB uint32_t TIM15EN          :  1; /*!< Ofs=16, w=1 TIM15 timer clock enable */
      __RWB uint32_t TIM16EN          :  1; /*!< Ofs=17, w=1 TIM16 timer clock enable */
            uint32_t unused4          :  3;
      __RWB uint32_t SAI1EN           :  1; /*!< Ofs=21, w=1 SAI1 clock enable */
            uint32_t unused5          : 10;
    } B;
  } ;
#ifdef __cplusplus
  RCC_APB2ENR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_APB2ENR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_APB2ENR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_AHB1SMENR_s { /*!< AHB1 peripheral clocks enable in Sleep and Stop modes register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DMA1SMEN         :  1; /*!< Ofs=0, w=1 DMA1 clocks enable during Sleep and Stop modes */
      __RWB uint32_t DMA2SMEN         :  1; /*!< Ofs=1, w=1 DMA2 clocks enable during Sleep and Stop modes */
            uint32_t unused0          :  6;
      __RWB uint32_t FLASHSMEN        :  1; /*!< Ofs=8, w=1 Flash memory interface clocks enable during Sleep and Stop modes */
      __RWB uint32_t SRAM1SMEN        :  1; /*!< Ofs=9, w=1 SRAM1 interface clocks enable during Sleep and Stop modes */
            uint32_t unused1          :  2;
      __RWB uint32_t CRCSMEN          :  1; /*!< Ofs=12, w=1 CRCSMEN */
            uint32_t unused2          :  3;
      __RWB uint32_t TSCSMEN          :  1; /*!< Ofs=16, w=1 Touch Sensing Controller clocks enable during Sleep and Stop modes */
            uint32_t unused3          : 15;
    } B;
  } ;
#ifdef __cplusplus
  RCC_AHB1SMENR_s(): R(0x00011303u) {};
  template<typename F> void modify (F f) volatile {
    RCC_AHB1SMENR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_AHB1SMENR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_AHB2SMENR_s { /*!< AHB2 peripheral clocks enable in Sleep and Stop modes register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t GPIOASMEN        :  1; /*!< Ofs=0, w=1 IO port A clocks enable during Sleep and Stop modes */
      __RWB uint32_t GPIOBSMEN        :  1; /*!< Ofs=1, w=1 IO port B clocks enable during Sleep and Stop modes */
      __RWB uint32_t GPIOCSMEN        :  1; /*!< Ofs=2, w=1 IO port C clocks enable during Sleep and Stop modes */
      __RWB uint32_t GPIODSMEN        :  1; /*!< Ofs=3, w=1 IO port D clocks enable during Sleep and Stop modes */
      __RWB uint32_t GPIOESMEN        :  1; /*!< Ofs=4, w=1 IO port E clocks enable during Sleep and Stop modes */
            uint32_t unused0          :  2;
      __RWB uint32_t GPIOHSMEN        :  1; /*!< Ofs=7, w=1 IO port H clocks enable during Sleep and Stop modes */
            uint32_t unused1          :  1;
      __RWB uint32_t SRAM2SMEN        :  1; /*!< Ofs=9, w=1 SRAM2 interface clocks enable during Sleep and Stop modes */
            uint32_t unused2          :  3;
      __RWB uint32_t ADCFSSMEN        :  1; /*!< Ofs=13, w=1 ADC clocks enable during Sleep and Stop modes */
            uint32_t unused3          :  2;
      __RWB uint32_t AESSMEN          :  1; /*!< Ofs=16, w=1 AES accelerator clocks enable during Sleep and Stop modes */
            uint32_t unused4          :  1;
      __RWB uint32_t RNGSMEN          :  1; /*!< Ofs=18, w=1 Random Number Generator clocks enable during Sleep and Stop modes */
            uint32_t unused5          : 13;
    } B;
  } ;
#ifdef __cplusplus
  RCC_AHB2SMENR_s(): R(0x000532FFu) {};
  template<typename F> void modify (F f) volatile {
    RCC_AHB2SMENR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_AHB2SMENR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_AHB3SMENR_s { /*!< AHB3 peripheral clocks enable in Sleep and Stop modes register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  8;
      __RWB uint32_t QSPISMEN         :  1; /*!< Ofs=8, w=1 QSPISMEN */
            uint32_t unused1          : 23;
    } B;
  } ;
#ifdef __cplusplus
  RCC_AHB3SMENR_s(): R(0x00000101u) {};
  template<typename F> void modify (F f) volatile {
    RCC_AHB3SMENR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_AHB3SMENR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_APB1SMENR1_s { /*!< APB1SMENR1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TIM2SMEN         :  1; /*!< Ofs=0, w=1 TIM2 timer clocks enable during Sleep and Stop modes */
            uint32_t unused0          :  3;
      __RWB uint32_t TIM6SMEN         :  1; /*!< Ofs=4, w=1 TIM6 timer clocks enable during Sleep and Stop modes */
      __RWB uint32_t TIM7SMEN         :  1; /*!< Ofs=5, w=1 TIM7 timer clocks enable during Sleep and Stop modes */
            uint32_t unused1          :  3;
      __RWB uint32_t LCDSMEN          :  1; /*!< Ofs=9, w=1 LCD clocks enable during Sleep and Stop modes */
      __RWB uint32_t RTCAPBSMEN       :  1; /*!< Ofs=10, w=1 RTC APB clock enable during Sleep and Stop modes */
      __RWB uint32_t WWDGSMEN         :  1; /*!< Ofs=11, w=1 Window watchdog clocks enable during Sleep and Stop modes */
            uint32_t unused2          :  2;
      __RWB uint32_t SPI2SMEN         :  1; /*!< Ofs=14, w=1 SPI2 clocks enable during Sleep and Stop modes */
      __RWB uint32_t SP3SMEN          :  1; /*!< Ofs=15, w=1 SPI3 clocks enable during Sleep and Stop modes */
            uint32_t unused3          :  1;
      __RWB uint32_t USART1SMEN       :  1; /*!< Ofs=17, w=1 USART1 clocks enable during Sleep and Stop modes */
      __RWB uint32_t USART2SMEN       :  1; /*!< Ofs=18, w=1 USART2 clocks enable during Sleep and Stop modes */
            uint32_t unused4          :  2;
      __RWB uint32_t I2C1SMEN         :  1; /*!< Ofs=21, w=1 I2C1 clocks enable during Sleep and Stop modes */
      __RWB uint32_t I2C2SMEN         :  1; /*!< Ofs=22, w=1 I2C2 clocks enable during Sleep and Stop modes */
      __RWB uint32_t I2C3SMEN         :  1; /*!< Ofs=23, w=1 I2C3 clocks enable during Sleep and Stop modes */
      __RWB uint32_t CRSSMEN          :  1; /*!< Ofs=24, w=1 CRS clock enable during Sleep and Stop modes */
      __RWB uint32_t CAN1SMEN         :  1; /*!< Ofs=25, w=1 CAN1 clocks enable during Sleep and Stop modes */
      __RWB uint32_t USBFSSMEN        :  1; /*!< Ofs=26, w=1 USB FS clock enable during Sleep and Stop modes */
            uint32_t unused5          :  1;
      __RWB uint32_t PWRSMEN          :  1; /*!< Ofs=28, w=1 Power interface clocks enable during Sleep and Stop modes */
      __RWB uint32_t DAC1SMEN         :  1; /*!< Ofs=29, w=1 DAC1 interface clocks enable during Sleep and Stop modes */
      __RWB uint32_t OPAMPSMEN        :  1; /*!< Ofs=30, w=1 OPAMP interface clocks enable during Sleep and Stop modes */
      __RWB uint32_t LPTIM1SMEN       :  1; /*!< Ofs=31, w=1 Low power timer 1 clocks enable during Sleep and Stop modes */
    } B;
  } ;
#ifdef __cplusplus
  RCC_APB1SMENR1_s(): R(0xF2FECA3Fu) {};
  template<typename F> void modify (F f) volatile {
    RCC_APB1SMENR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_APB1SMENR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_APB1SMENR2_s { /*!< APB1 peripheral clocks enable in Sleep and Stop modes register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LPUART1SMEN      :  1; /*!< Ofs=0, w=1 Low power UART 1 clocks enable during Sleep and Stop modes */
            uint32_t unused0          :  1;
      __RWB uint32_t SWPMI1SMEN       :  1; /*!< Ofs=2, w=1 Single wire protocol clocks enable during Sleep and Stop modes */
            uint32_t unused1          :  2;
      __RWB uint32_t LPTIM2SMEN       :  1; /*!< Ofs=5, w=1 LPTIM2SMEN */
            uint32_t unused2          : 26;
    } B;
  } ;
#ifdef __cplusplus
  RCC_APB1SMENR2_s(): R(0x00000025u) {};
  template<typename F> void modify (F f) volatile {
    RCC_APB1SMENR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_APB1SMENR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_APB2SMENR_s { /*!< APB2SMENR */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SYSCFGSMEN       :  1; /*!< Ofs=0, w=1 SYSCFG clocks enable during Sleep and Stop modes */
            uint32_t unused0          :  9;
      __RWB uint32_t SDMMCSMEN        :  1; /*!< Ofs=10, w=1 SDMMC clocks enable during Sleep and Stop modes */
      __RWB uint32_t TIM1SMEN         :  1; /*!< Ofs=11, w=1 TIM1 timer clocks enable during Sleep and Stop modes */
      __RWB uint32_t SPI1SMEN         :  1; /*!< Ofs=12, w=1 SPI1 clocks enable during Sleep and Stop modes */
            uint32_t unused1          :  1;
      __RWB uint32_t USART1SMEN       :  1; /*!< Ofs=14, w=1 USART1clocks enable during Sleep and Stop modes */
            uint32_t unused2          :  1;
      __RWB uint32_t TIM15SMEN        :  1; /*!< Ofs=16, w=1 TIM15 timer clocks enable during Sleep and Stop modes */
      __RWB uint32_t TIM16SMEN        :  1; /*!< Ofs=17, w=1 TIM16 timer clocks enable during Sleep and Stop modes */
            uint32_t unused3          :  3;
      __RWB uint32_t SAI1SMEN         :  1; /*!< Ofs=21, w=1 SAI1 clocks enable during Sleep and Stop modes */
            uint32_t unused4          : 10;
    } B;
  } ;
#ifdef __cplusplus
  RCC_APB2SMENR_s(): R(0x01677C01u) {};
  template<typename F> void modify (F f) volatile {
    RCC_APB2SMENR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_APB2SMENR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_CCIPR_s { /*!< CCIPR */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t USART1SEL        :  2; /*!< Ofs=0, w=2 USART1 clock source selection */
      __RWB uint32_t USART2SEL        :  2; /*!< Ofs=2, w=2 USART2 clock source selection */
      __RWB uint32_t USART3SEL        :  2; /*!< Ofs=4, w=2 USART3 clock source selection */
      __RWB uint32_t USART4SEL        :  2; /*!< Ofs=6, w=2 USART4 clock source selection */
            uint32_t unused0          :  2;
      __RWB uint32_t LPUART1SEL       :  2; /*!< Ofs=10, w=2 LPUART1 clock source selection */
      __RWB uint32_t I2C1SEL          :  2; /*!< Ofs=12, w=2 I2C1 clock source selection */
      __RWB uint32_t I2C2SEL          :  2; /*!< Ofs=14, w=2 I2C2 clock source selection */
      __RWB uint32_t I2C3SEL          :  2; /*!< Ofs=16, w=2 I2C3 clock source selection */
      __RWB uint32_t LPTIM1SEL        :  2; /*!< Ofs=18, w=2 Low power timer 1 clock source selection */
      __RWB uint32_t LPTIM2SEL        :  2; /*!< Ofs=20, w=2 Low power timer 2 clock source selection */
      __RWB uint32_t SAI1SEL          :  2; /*!< Ofs=22, w=2 SAI1 clock source selection */
            uint32_t unused1          :  2;
      __RWB uint32_t CLK48SEL         :  2; /*!< Ofs=26, w=2 48 MHz clock source selection */
      __RWB uint32_t ADCSEL           :  2; /*!< Ofs=28, w=2 ADCs clock source selection */
      __RWB uint32_t SWPMI1SEL        :  1; /*!< Ofs=30, w=1 SWPMI1 clock source selection */
            uint32_t unused2          :  1;
    } B;
  } ;
#ifdef __cplusplus
  RCC_CCIPR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_CCIPR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_CCIPR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_BDCR_s { /*!< BDCR */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LSEON            :  1; /*!< Ofs=0, w=1 LSE oscillator enable */
      __ROB uint32_t LSERDY           :  1; /*!< Ofs=1, w=1 LSE oscillator ready */
      __RWB uint32_t LSEBYP           :  1; /*!< Ofs=2, w=1 LSE oscillator bypass */
      __RWB uint32_t LSEDRV           :  2; /*!< Ofs=3, w=2 SE oscillator drive capability */
      __RWB uint32_t LSECSSON         :  1; /*!< Ofs=5, w=1 LSECSSON */
      __ROB uint32_t LSECSSD          :  1; /*!< Ofs=6, w=1 LSECSSD */
            uint32_t unused0          :  1;
      __RWB uint32_t RTCSEL           :  2; /*!< Ofs=8, w=2 RTC clock source selection */
            uint32_t unused1          :  5;
      __RWB uint32_t RTCEN            :  1; /*!< Ofs=15, w=1 RTC clock enable */
      __RWB uint32_t BDRST            :  1; /*!< Ofs=16, w=1 Backup domain software reset */
            uint32_t unused2          :  7;
      __RWB uint32_t LSCOEN           :  1; /*!< Ofs=24, w=1 Low speed clock output enable */
      __RWB uint32_t LSCOSEL          :  1; /*!< Ofs=25, w=1 Low speed clock output selection */
            uint32_t unused3          :  6;
    } B;
  } ;
#ifdef __cplusplus
  RCC_BDCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RCC_BDCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_BDCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_CSR_s { /*!< CSR */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LSION            :  1; /*!< Ofs=0, w=1 LSI oscillator enable */
      __ROB uint32_t LSIRDY           :  1; /*!< Ofs=1, w=1 LSI oscillator ready */
            uint32_t unused0          :  6;
      __RWB uint32_t MSISRANGE        :  4; /*!< Ofs=8, w=4 SI range after Standby mode */
            uint32_t unused1          : 11;
      __RWB uint32_t RMVF             :  1; /*!< Ofs=23, w=1 Remove reset flag */
      __ROB uint32_t FIREWALLRSTF     :  1; /*!< Ofs=24, w=1 Firewall reset flag */
      __ROB uint32_t OBLRSTF          :  1; /*!< Ofs=25, w=1 Option byte loader reset flag */
      __ROB uint32_t PINRSTF          :  1; /*!< Ofs=26, w=1 Pin reset flag */
      __ROB uint32_t BORRSTF          :  1; /*!< Ofs=27, w=1 BOR flag */
      __ROB uint32_t SFTRSTF          :  1; /*!< Ofs=28, w=1 Software reset flag */
      __ROB uint32_t IWDGRSTF         :  1; /*!< Ofs=29, w=1 Independent window watchdog reset flag */
      __ROB uint32_t WWDGRSTF         :  1; /*!< Ofs=30, w=1 Window watchdog reset flag */
      __ROB uint32_t LPWRSTF          :  1; /*!< Ofs=31, w=1 Low-power reset flag */
    } B;
  } ;
#ifdef __cplusplus
  RCC_CSR_s(): R(0x0C000600u) {};
  template<typename F> void modify (F f) volatile {
    RCC_CSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_CSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RCC_CRRCR_s { /*!< Clock recovery RC register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t HSI48ON          :  1; /*!< Ofs=0, w=1 HSI48 clock enable */
      __ROB uint32_t HSI48RDY         :  1; /*!< Ofs=1, w=1 HSI48 clock ready flag */
            uint32_t unused0          :  5;
      __ROB uint32_t HSI48CAL         :  9; /*!< Ofs=7, w=9 HSI48 clock calibration */
            uint32_t unused1          : 16;
    } B;
  } ;
#ifdef __cplusplus
  RCC_CRRCR_s(): R(0x0C000600u) {};
  template<typename F> void modify (F f) volatile {
    RCC_CRRCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RCC_CRRCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Flash_ACR_s { /*!< Access control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LATENCY          :  3; /*!< Ofs=0, w=3 Latency */
            uint32_t unused0          :  5;
      __RWB uint32_t PRFTEN           :  1; /*!< Ofs=8, w=1 Prefetch enable */
      __RWB uint32_t ICEN             :  1; /*!< Ofs=9, w=1 Instruction cache enable */
      __RWB uint32_t DCEN             :  1; /*!< Ofs=10, w=1 Data cache enable */
      __RWB uint32_t ICRST            :  1; /*!< Ofs=11, w=1 Instruction cache reset */
      __RWB uint32_t DCRST            :  1; /*!< Ofs=12, w=1 Data cache reset */
      __RWB uint32_t RUN_PD           :  1; /*!< Ofs=13, w=1 Flash Power-down mode during Low-power run mode */
      __RWB uint32_t SLEEP_PD         :  1; /*!< Ofs=14, w=1 Flash Power-down mode during Low-power sleep mode */
            uint32_t unused1          : 17;
    } B;
  } ;
#ifdef __cplusplus
  Flash_ACR_s(): R(0x00000600u) {};
  template<typename F> void modify (F f) volatile {
    Flash_ACR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Flash_ACR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Flash_SR_s { /*!< Status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EOP              :  1; /*!< Ofs=0, w=1 End of operation */
      __RWB uint32_t OPERR            :  1; /*!< Ofs=1, w=1 Operation error */
            uint32_t unused0          :  1;
      __RWB uint32_t PROGERR          :  1; /*!< Ofs=3, w=1 Programming error */
      __RWB uint32_t WRPERR           :  1; /*!< Ofs=4, w=1 Write protected error */
      __RWB uint32_t PGAERR           :  1; /*!< Ofs=5, w=1 Programming alignment error */
      __RWB uint32_t SIZERR           :  1; /*!< Ofs=6, w=1 Size error */
      __RWB uint32_t PGSERR           :  1; /*!< Ofs=7, w=1 Programming sequence error */
      __RWB uint32_t MISERR           :  1; /*!< Ofs=8, w=1 Fast programming data miss error */
      __RWB uint32_t FASTERR          :  1; /*!< Ofs=9, w=1 Fast programming error */
            uint32_t unused1          :  4;
      __RWB uint32_t RDERR            :  1; /*!< Ofs=14, w=1 PCROP read error */
      __RWB uint32_t OPTVERR          :  1; /*!< Ofs=15, w=1 Option validity error */
      __ROB uint32_t BSY              :  1; /*!< Ofs=16, w=1 Busy */
            uint32_t unused2          : 15;
    } B;
  } ;
#ifdef __cplusplus
  Flash_SR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    Flash_SR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Flash_SR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Flash_CR_s { /*!< Flash control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PG               :  1; /*!< Ofs=0, w=1 Programming */
      __RWB uint32_t PER              :  1; /*!< Ofs=1, w=1 Page erase */
      __RWB uint32_t MER1             :  1; /*!< Ofs=2, w=1 Bank 1 Mass erase */
      __RWB uint32_t PNB              :  8; /*!< Ofs=3, w=8 Page number */
      __RWB uint32_t BKER             :  1; /*!< Ofs=11, w=1 Bank erase */
            uint32_t unused0          :  3;
      __RWB uint32_t MER2             :  1; /*!< Ofs=15, w=1 Bank 2 Mass erase */
      __RWB uint32_t START            :  1; /*!< Ofs=16, w=1 Start */
      __RWB uint32_t OPTSTRT          :  1; /*!< Ofs=17, w=1 Options modification start */
      __RWB uint32_t FSTPG            :  1; /*!< Ofs=18, w=1 Fast programming */
            uint32_t unused1          :  5;
      __RWB uint32_t EOPIE            :  1; /*!< Ofs=24, w=1 End of operation interrupt enable */
      __RWB uint32_t ERRIE            :  1; /*!< Ofs=25, w=1 Error interrupt enable */
      __RWB uint32_t RDERRIE          :  1; /*!< Ofs=26, w=1 PCROP read error interrupt enable */
      __RWB uint32_t OBL_LAUNCH       :  1; /*!< Ofs=27, w=1 Force the option byte loading */
            uint32_t unused2          :  2;
      __RWB uint32_t OPTLOCK          :  1; /*!< Ofs=30, w=1 Options Lock */
      __RWB uint32_t LOCK             :  1; /*!< Ofs=31, w=1 FLASH_CR Lock */
    } B;
  } ;
#ifdef __cplusplus
  Flash_CR_s(): R(0xC0000000u) {};
  template<typename F> void modify (F f) volatile {
    Flash_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Flash_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Flash_ECCR_s { /*!< Flash ECC register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t ADDR_ECC         : 19; /*!< Ofs=0, w=19 ECC fail address */
      __ROB uint32_t BK_ECC           :  1; /*!< Ofs=19, w=1 ECC fail bank */
      __ROB uint32_t SYSF_ECC         :  1; /*!< Ofs=20, w=1 System Flash ECC fail */
            uint32_t unused0          :  3;
      __RWB uint32_t ECCIE            :  1; /*!< Ofs=24, w=1 ECC correction interrupt enable */
            uint32_t unused1          :  5;
      __RWB uint32_t ECCC             :  1; /*!< Ofs=30, w=1 ECC correction */
      __RWB uint32_t ECCD             :  1; /*!< Ofs=31, w=1 ECC detection */
    } B;
  } ;
#ifdef __cplusplus
  Flash_ECCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    Flash_ECCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Flash_ECCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Flash_OPTR_s { /*!< Flash option register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t RDP              :  8; /*!< Ofs=0, w=8 Read protection level */
      __RWB uint32_t BOR_LEV          :  3; /*!< Ofs=8, w=3 BOR reset Level */
            uint32_t unused0          :  1;
      __RWB uint32_t nRST_STOP        :  1; /*!< Ofs=12, w=1 nRST_STOP */
      __RWB uint32_t nRST_STDBY       :  1; /*!< Ofs=13, w=1 nRST_STDBY */
            uint32_t unused1          :  2;
      __RWB uint32_t IDWG_SW          :  1; /*!< Ofs=16, w=1 Independent watchdog selection */
      __RWB uint32_t IWDG_STOP        :  1; /*!< Ofs=17, w=1 Independent watchdog counter freeze in Stop mode */
      __RWB uint32_t IWDG_STDBY       :  1; /*!< Ofs=18, w=1 Independent watchdog counter freeze in Standby mode */
      __RWB uint32_t WWDG_SW          :  1; /*!< Ofs=19, w=1 Window watchdog selection */
      __RWB uint32_t BFB2             :  1; /*!< Ofs=20, w=1 Dual-bank boot */
      __RWB uint32_t DUALBANK         :  1; /*!< Ofs=21, w=1 Dual-Bank on 512 KB or 256 KB Flash memory devices */
            uint32_t unused2          :  1;
      __RWB uint32_t nBOOT1           :  1; /*!< Ofs=23, w=1 Boot configuration */
      __RWB uint32_t SRAM2_PE         :  1; /*!< Ofs=24, w=1 SRAM2 parity check enable */
      __RWB uint32_t SRAM2_RST        :  1; /*!< Ofs=25, w=1 SRAM2 Erase when system reset */
            uint32_t unused3          :  6;
    } B;
  } ;
#ifdef __cplusplus
  Flash_OPTR_s(): R(0xF0000000u) {};
  template<typename F> void modify (F f) volatile {
    Flash_OPTR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Flash_OPTR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Flash_PCROP1ER_s { /*!< Flash Bank 1 PCROP End address register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PCROP1_END       : 16; /*!< Ofs=0, w=16 Bank 1 PCROP area end offset */
            uint32_t unused0          : 15;
      __RWB uint32_t PCROP_RDP        :  1; /*!< Ofs=31, w=1 PCROP area preserved when RDP level decreased */
    } B;
  } ;
#ifdef __cplusplus
  Flash_PCROP1ER_s(): R(0x0FFF0000u) {};
  template<typename F> void modify (F f) volatile {
    Flash_PCROP1ER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Flash_PCROP1ER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Flash_WRP1AR_s { /*!< Flash Bank 1 WRP area A address register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t WRP1A_STRT       :  8; /*!< Ofs=0, w=8 Bank 1 WRP first area tart offset */
            uint32_t unused0          :  8;
      __RWB uint32_t WRP1A_END        :  8; /*!< Ofs=16, w=8 Bank 1 WRP first area A end offset */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  Flash_WRP1AR_s(): R(0xFF00FF00u) {};
  template<typename F> void modify (F f) volatile {
    Flash_WRP1AR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Flash_WRP1AR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Flash_WRP1BR_s { /*!< Flash Bank 1 WRP area B address register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t WRP1B_END        :  8; /*!< Ofs=0, w=8 Bank 1 WRP second area B start offset */
            uint32_t unused0          :  8;
      __RWB uint32_t WRP1B_STRT       :  8; /*!< Ofs=16, w=8 Bank 1 WRP second area B end offset */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  Flash_WRP1BR_s(): R(0xFF00FF00u) {};
  template<typename F> void modify (F f) volatile {
    Flash_WRP1BR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Flash_WRP1BR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Flash_WRP2AR_s { /*!< Flash Bank 2 WRP area A address register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t WRP2A_STRT       :  8; /*!< Ofs=0, w=8 Bank 2 WRP first area A start offset */
            uint32_t unused0          :  8;
      __RWB uint32_t WRP2A_END        :  8; /*!< Ofs=16, w=8 Bank 2 WRP first area A end offset */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  Flash_WRP2AR_s(): R(0xFF00FF00u) {};
  template<typename F> void modify (F f) volatile {
    Flash_WRP2AR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Flash_WRP2AR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct Flash_WRP2BR_s { /*!< Flash Bank 2 WRP area B address register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t WRP2B_STRT       :  8; /*!< Ofs=0, w=8 Bank 2 WRP second area B start offset */
            uint32_t unused0          :  8;
      __RWB uint32_t WRP2B_END        :  8; /*!< Ofs=16, w=8 Bank 2 WRP second area B end offset */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  Flash_WRP2BR_s(): R(0xFF00FF00u) {};
  template<typename F> void modify (F f) volatile {
    Flash_WRP2BR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    Flash_WRP2BR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct CRC_CR_s { /*!< Control register */
  union {
      __RWB uint32_t R;
    struct {
      __WOB uint32_t RESET            :  1; /*!< Ofs=0, w=1 RESET bit */
            uint32_t unused0          :  2;
      __RWB uint32_t POLYSIZE         :  2; /*!< Ofs=3, w=2 Polynomial size */
      __RWB uint32_t REV_IN           :  2; /*!< Ofs=5, w=2 Reverse input data */
      __RWB uint32_t REV_OUT          :  1; /*!< Ofs=7, w=1 Reverse output data */
            uint32_t unused1          : 24;
    } B;
  } ;
#ifdef __cplusplus
  CRC_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    CRC_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    CRC_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TSC_CR_s { /*!< control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t TSCE             :  1; /*!< Ofs=0, w=1 Touch sensing controller enable */
      __RWB uint32_t START            :  1; /*!< Ofs=1, w=1 Start a new acquisition */
      __RWB uint32_t AM               :  1; /*!< Ofs=2, w=1 Acquisition mode */
      __RWB uint32_t SYNCPOL          :  1; /*!< Ofs=3, w=1 Synchronization pin polarity */
      __RWB uint32_t IODEF            :  1; /*!< Ofs=4, w=1 I/O Default mode */
      __RWB uint32_t MCV              :  3; /*!< Ofs=5, w=3 Max count value */
            uint32_t unused0          :  4;
      __RWB uint32_t PGPSC            :  3; /*!< Ofs=12, w=3 pulse generator prescaler */
      __RWB uint32_t SSPSC            :  1; /*!< Ofs=15, w=1 Spread spectrum prescaler */
      __RWB uint32_t SSE              :  1; /*!< Ofs=16, w=1 Spread spectrum enable */
      __RWB uint32_t SSD              :  7; /*!< Ofs=17, w=7 Spread spectrum deviation */
      __RWB uint32_t CTPL             :  4; /*!< Ofs=24, w=4 Charge transfer pulse low */
      __RWB uint32_t CTPH             :  4; /*!< Ofs=28, w=4 Charge transfer pulse high */
    } B;
  } ;
#ifdef __cplusplus
  TSC_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TSC_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TSC_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TSC_IER_s { /*!< interrupt enable register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EOAIE            :  1; /*!< Ofs=0, w=1 End of acquisition interrupt enable */
      __RWB uint32_t MCEIE            :  1; /*!< Ofs=1, w=1 Max count error interrupt enable */
            uint32_t unused0          : 30;
    } B;
  } ;
#ifdef __cplusplus
  TSC_IER_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TSC_IER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TSC_IER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TSC_ICR_s { /*!< interrupt clear register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EOAIC            :  1; /*!< Ofs=0, w=1 End of acquisition interrupt clear */
      __RWB uint32_t MCEIC            :  1; /*!< Ofs=1, w=1 Max count error interrupt clear */
            uint32_t unused0          : 30;
    } B;
  } ;
#ifdef __cplusplus
  TSC_ICR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TSC_ICR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TSC_ICR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TSC_ISR_s { /*!< interrupt status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EOAF             :  1; /*!< Ofs=0, w=1 End of acquisition flag */
      __RWB uint32_t MCEF             :  1; /*!< Ofs=1, w=1 Max count error flag */
            uint32_t unused0          : 30;
    } B;
  } ;
#ifdef __cplusplus
  TSC_ISR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TSC_ISR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TSC_ISR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TSC_IOHCR_s { /*!< I/O hysteresis control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t G1_IO1           :  1; /*!< Ofs=0, w=1 G1_IO1 */
      __RWB uint32_t G1_IO2           :  1; /*!< Ofs=1, w=1 G1_IO2 */
      __RWB uint32_t G1_IO3           :  1; /*!< Ofs=2, w=1 G1_IO3 */
      __RWB uint32_t G1_IO4           :  1; /*!< Ofs=3, w=1 G1_IO4 */
      __RWB uint32_t G2_IO1           :  1; /*!< Ofs=4, w=1 G2_IO1 */
      __RWB uint32_t G2_IO2           :  1; /*!< Ofs=5, w=1 G2_IO2 */
      __RWB uint32_t G2_IO3           :  1; /*!< Ofs=6, w=1 G2_IO3 */
      __RWB uint32_t G2_IO4           :  1; /*!< Ofs=7, w=1 G2_IO4 */
      __RWB uint32_t G3_IO1           :  1; /*!< Ofs=8, w=1 G3_IO1 */
      __RWB uint32_t G3_IO2           :  1; /*!< Ofs=9, w=1 G3_IO2 */
      __RWB uint32_t G3_IO3           :  1; /*!< Ofs=10, w=1 G3_IO3 */
      __RWB uint32_t G3_IO4           :  1; /*!< Ofs=11, w=1 G3_IO4 */
      __RWB uint32_t G4_IO1           :  1; /*!< Ofs=12, w=1 G4_IO1 */
      __RWB uint32_t G4_IO2           :  1; /*!< Ofs=13, w=1 G4_IO2 */
      __RWB uint32_t G4_IO3           :  1; /*!< Ofs=14, w=1 G4_IO3 */
      __RWB uint32_t G4_IO4           :  1; /*!< Ofs=15, w=1 G4_IO4 */
      __RWB uint32_t G5_IO1           :  1; /*!< Ofs=16, w=1 G5_IO1 */
      __RWB uint32_t G5_IO2           :  1; /*!< Ofs=17, w=1 G5_IO2 */
      __RWB uint32_t G5_IO3           :  1; /*!< Ofs=18, w=1 G5_IO3 */
      __RWB uint32_t G5_IO4           :  1; /*!< Ofs=19, w=1 G5_IO4 */
      __RWB uint32_t G6_IO1           :  1; /*!< Ofs=20, w=1 G6_IO1 */
      __RWB uint32_t G6_IO2           :  1; /*!< Ofs=21, w=1 G6_IO2 */
      __RWB uint32_t G6_IO3           :  1; /*!< Ofs=22, w=1 G6_IO3 */
      __RWB uint32_t G6_IO4           :  1; /*!< Ofs=23, w=1 G6_IO4 */
      __RWB uint32_t G7_IO1           :  1; /*!< Ofs=24, w=1 G7_IO1 */
      __RWB uint32_t G7_IO2           :  1; /*!< Ofs=25, w=1 G7_IO2 */
      __RWB uint32_t G7_IO3           :  1; /*!< Ofs=26, w=1 G7_IO3 */
      __RWB uint32_t G7_IO4           :  1; /*!< Ofs=27, w=1 G7_IO4 */
      __RWB uint32_t G8_IO1           :  1; /*!< Ofs=28, w=1 G8_IO1 */
      __RWB uint32_t G8_IO2           :  1; /*!< Ofs=29, w=1 G8_IO2 */
      __RWB uint32_t G8_IO3           :  1; /*!< Ofs=30, w=1 G8_IO3 */
      __RWB uint32_t G8_IO4           :  1; /*!< Ofs=31, w=1 G8_IO4 */
    } B;
  } ;
#ifdef __cplusplus
  TSC_IOHCR_s(): R(0xFFFFFFFFu) {};
  template<typename F> void modify (F f) volatile {
    TSC_IOHCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TSC_IOHCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TSC_IOASCR_s { /*!< I/O analog switch control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t G1_IO1           :  1; /*!< Ofs=0, w=1 G1_IO1 */
      __RWB uint32_t G1_IO2           :  1; /*!< Ofs=1, w=1 G1_IO2 */
      __RWB uint32_t G1_IO3           :  1; /*!< Ofs=2, w=1 G1_IO3 */
      __RWB uint32_t G1_IO4           :  1; /*!< Ofs=3, w=1 G1_IO4 */
      __RWB uint32_t G2_IO1           :  1; /*!< Ofs=4, w=1 G2_IO1 */
      __RWB uint32_t G2_IO2           :  1; /*!< Ofs=5, w=1 G2_IO2 */
      __RWB uint32_t G2_IO3           :  1; /*!< Ofs=6, w=1 G2_IO3 */
      __RWB uint32_t G2_IO4           :  1; /*!< Ofs=7, w=1 G2_IO4 */
      __RWB uint32_t G3_IO1           :  1; /*!< Ofs=8, w=1 G3_IO1 */
      __RWB uint32_t G3_IO2           :  1; /*!< Ofs=9, w=1 G3_IO2 */
      __RWB uint32_t G3_IO3           :  1; /*!< Ofs=10, w=1 G3_IO3 */
      __RWB uint32_t G3_IO4           :  1; /*!< Ofs=11, w=1 G3_IO4 */
      __RWB uint32_t G4_IO1           :  1; /*!< Ofs=12, w=1 G4_IO1 */
      __RWB uint32_t G4_IO2           :  1; /*!< Ofs=13, w=1 G4_IO2 */
      __RWB uint32_t G4_IO3           :  1; /*!< Ofs=14, w=1 G4_IO3 */
      __RWB uint32_t G4_IO4           :  1; /*!< Ofs=15, w=1 G4_IO4 */
      __RWB uint32_t G5_IO1           :  1; /*!< Ofs=16, w=1 G5_IO1 */
      __RWB uint32_t G5_IO2           :  1; /*!< Ofs=17, w=1 G5_IO2 */
      __RWB uint32_t G5_IO3           :  1; /*!< Ofs=18, w=1 G5_IO3 */
      __RWB uint32_t G5_IO4           :  1; /*!< Ofs=19, w=1 G5_IO4 */
      __RWB uint32_t G6_IO1           :  1; /*!< Ofs=20, w=1 G6_IO1 */
      __RWB uint32_t G6_IO2           :  1; /*!< Ofs=21, w=1 G6_IO2 */
      __RWB uint32_t G6_IO3           :  1; /*!< Ofs=22, w=1 G6_IO3 */
      __RWB uint32_t G6_IO4           :  1; /*!< Ofs=23, w=1 G6_IO4 */
      __RWB uint32_t G7_IO1           :  1; /*!< Ofs=24, w=1 G7_IO1 */
      __RWB uint32_t G7_IO2           :  1; /*!< Ofs=25, w=1 G7_IO2 */
      __RWB uint32_t G7_IO3           :  1; /*!< Ofs=26, w=1 G7_IO3 */
      __RWB uint32_t G7_IO4           :  1; /*!< Ofs=27, w=1 G7_IO4 */
      __RWB uint32_t G8_IO1           :  1; /*!< Ofs=28, w=1 G8_IO1 */
      __RWB uint32_t G8_IO2           :  1; /*!< Ofs=29, w=1 G8_IO2 */
      __RWB uint32_t G8_IO3           :  1; /*!< Ofs=30, w=1 G8_IO3 */
      __RWB uint32_t G8_IO4           :  1; /*!< Ofs=31, w=1 G8_IO4 */
    } B;
  } ;
#ifdef __cplusplus
  TSC_IOASCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TSC_IOASCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TSC_IOASCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TSC_IOSCR_s { /*!< I/O sampling control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t G1_IO1           :  1; /*!< Ofs=0, w=1 G1_IO1 */
      __RWB uint32_t G1_IO2           :  1; /*!< Ofs=1, w=1 G1_IO2 */
      __RWB uint32_t G1_IO3           :  1; /*!< Ofs=2, w=1 G1_IO3 */
      __RWB uint32_t G1_IO4           :  1; /*!< Ofs=3, w=1 G1_IO4 */
      __RWB uint32_t G2_IO1           :  1; /*!< Ofs=4, w=1 G2_IO1 */
      __RWB uint32_t G2_IO2           :  1; /*!< Ofs=5, w=1 G2_IO2 */
      __RWB uint32_t G2_IO3           :  1; /*!< Ofs=6, w=1 G2_IO3 */
      __RWB uint32_t G2_IO4           :  1; /*!< Ofs=7, w=1 G2_IO4 */
      __RWB uint32_t G3_IO1           :  1; /*!< Ofs=8, w=1 G3_IO1 */
      __RWB uint32_t G3_IO2           :  1; /*!< Ofs=9, w=1 G3_IO2 */
      __RWB uint32_t G3_IO3           :  1; /*!< Ofs=10, w=1 G3_IO3 */
      __RWB uint32_t G3_IO4           :  1; /*!< Ofs=11, w=1 G3_IO4 */
      __RWB uint32_t G4_IO1           :  1; /*!< Ofs=12, w=1 G4_IO1 */
      __RWB uint32_t G4_IO2           :  1; /*!< Ofs=13, w=1 G4_IO2 */
      __RWB uint32_t G4_IO3           :  1; /*!< Ofs=14, w=1 G4_IO3 */
      __RWB uint32_t G4_IO4           :  1; /*!< Ofs=15, w=1 G4_IO4 */
      __RWB uint32_t G5_IO1           :  1; /*!< Ofs=16, w=1 G5_IO1 */
      __RWB uint32_t G5_IO2           :  1; /*!< Ofs=17, w=1 G5_IO2 */
      __RWB uint32_t G5_IO3           :  1; /*!< Ofs=18, w=1 G5_IO3 */
      __RWB uint32_t G5_IO4           :  1; /*!< Ofs=19, w=1 G5_IO4 */
      __RWB uint32_t G6_IO1           :  1; /*!< Ofs=20, w=1 G6_IO1 */
      __RWB uint32_t G6_IO2           :  1; /*!< Ofs=21, w=1 G6_IO2 */
      __RWB uint32_t G6_IO3           :  1; /*!< Ofs=22, w=1 G6_IO3 */
      __RWB uint32_t G6_IO4           :  1; /*!< Ofs=23, w=1 G6_IO4 */
      __RWB uint32_t G7_IO1           :  1; /*!< Ofs=24, w=1 G7_IO1 */
      __RWB uint32_t G7_IO2           :  1; /*!< Ofs=25, w=1 G7_IO2 */
      __RWB uint32_t G7_IO3           :  1; /*!< Ofs=26, w=1 G7_IO3 */
      __RWB uint32_t G7_IO4           :  1; /*!< Ofs=27, w=1 G7_IO4 */
      __RWB uint32_t G8_IO1           :  1; /*!< Ofs=28, w=1 G8_IO1 */
      __RWB uint32_t G8_IO2           :  1; /*!< Ofs=29, w=1 G8_IO2 */
      __RWB uint32_t G8_IO3           :  1; /*!< Ofs=30, w=1 G8_IO3 */
      __RWB uint32_t G8_IO4           :  1; /*!< Ofs=31, w=1 G8_IO4 */
    } B;
  } ;
#ifdef __cplusplus
  TSC_IOSCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TSC_IOSCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TSC_IOSCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TSC_IOCCR_s { /*!< I/O channel control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t G1_IO1           :  1; /*!< Ofs=0, w=1 G1_IO1 */
      __RWB uint32_t G1_IO2           :  1; /*!< Ofs=1, w=1 G1_IO2 */
      __RWB uint32_t G1_IO3           :  1; /*!< Ofs=2, w=1 G1_IO3 */
      __RWB uint32_t G1_IO4           :  1; /*!< Ofs=3, w=1 G1_IO4 */
      __RWB uint32_t G2_IO1           :  1; /*!< Ofs=4, w=1 G2_IO1 */
      __RWB uint32_t G2_IO2           :  1; /*!< Ofs=5, w=1 G2_IO2 */
      __RWB uint32_t G2_IO3           :  1; /*!< Ofs=6, w=1 G2_IO3 */
      __RWB uint32_t G2_IO4           :  1; /*!< Ofs=7, w=1 G2_IO4 */
      __RWB uint32_t G3_IO1           :  1; /*!< Ofs=8, w=1 G3_IO1 */
      __RWB uint32_t G3_IO2           :  1; /*!< Ofs=9, w=1 G3_IO2 */
      __RWB uint32_t G3_IO3           :  1; /*!< Ofs=10, w=1 G3_IO3 */
      __RWB uint32_t G3_IO4           :  1; /*!< Ofs=11, w=1 G3_IO4 */
      __RWB uint32_t G4_IO1           :  1; /*!< Ofs=12, w=1 G4_IO1 */
      __RWB uint32_t G4_IO2           :  1; /*!< Ofs=13, w=1 G4_IO2 */
      __RWB uint32_t G4_IO3           :  1; /*!< Ofs=14, w=1 G4_IO3 */
      __RWB uint32_t G4_IO4           :  1; /*!< Ofs=15, w=1 G4_IO4 */
      __RWB uint32_t G5_IO1           :  1; /*!< Ofs=16, w=1 G5_IO1 */
      __RWB uint32_t G5_IO2           :  1; /*!< Ofs=17, w=1 G5_IO2 */
      __RWB uint32_t G5_IO3           :  1; /*!< Ofs=18, w=1 G5_IO3 */
      __RWB uint32_t G5_IO4           :  1; /*!< Ofs=19, w=1 G5_IO4 */
      __RWB uint32_t G6_IO1           :  1; /*!< Ofs=20, w=1 G6_IO1 */
      __RWB uint32_t G6_IO2           :  1; /*!< Ofs=21, w=1 G6_IO2 */
      __RWB uint32_t G6_IO3           :  1; /*!< Ofs=22, w=1 G6_IO3 */
      __RWB uint32_t G6_IO4           :  1; /*!< Ofs=23, w=1 G6_IO4 */
      __RWB uint32_t G7_IO1           :  1; /*!< Ofs=24, w=1 G7_IO1 */
      __RWB uint32_t G7_IO2           :  1; /*!< Ofs=25, w=1 G7_IO2 */
      __RWB uint32_t G7_IO3           :  1; /*!< Ofs=26, w=1 G7_IO3 */
      __RWB uint32_t G7_IO4           :  1; /*!< Ofs=27, w=1 G7_IO4 */
      __RWB uint32_t G8_IO1           :  1; /*!< Ofs=28, w=1 G8_IO1 */
      __RWB uint32_t G8_IO2           :  1; /*!< Ofs=29, w=1 G8_IO2 */
      __RWB uint32_t G8_IO3           :  1; /*!< Ofs=30, w=1 G8_IO3 */
      __RWB uint32_t G8_IO4           :  1; /*!< Ofs=31, w=1 G8_IO4 */
    } B;
  } ;
#ifdef __cplusplus
  TSC_IOCCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TSC_IOCCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TSC_IOCCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct TSC_IOGCSR_s { /*!< I/O group control status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t G1E              :  1; /*!< Ofs=0, w=1 Analog I/O group x enable */
      __RWB uint32_t G2E              :  1; /*!< Ofs=1, w=1 Analog I/O group x enable */
      __RWB uint32_t G3E              :  1; /*!< Ofs=2, w=1 Analog I/O group x enable */
      __RWB uint32_t G4E              :  1; /*!< Ofs=3, w=1 Analog I/O group x enable */
      __RWB uint32_t G5E              :  1; /*!< Ofs=4, w=1 Analog I/O group x enable */
      __RWB uint32_t G6E              :  1; /*!< Ofs=5, w=1 Analog I/O group x enable */
      __RWB uint32_t G7E              :  1; /*!< Ofs=6, w=1 Analog I/O group x enable */
      __RWB uint32_t G8E              :  1; /*!< Ofs=7, w=1 Analog I/O group x enable */
            uint32_t unused0          :  8;
      __ROB uint32_t G1S              :  1; /*!< Ofs=16, w=1 Analog I/O group x status */
      __ROB uint32_t G2S              :  1; /*!< Ofs=17, w=1 Analog I/O group x status */
      __ROB uint32_t G3S              :  1; /*!< Ofs=18, w=1 Analog I/O group x status */
      __ROB uint32_t G4S              :  1; /*!< Ofs=19, w=1 Analog I/O group x status */
      __ROB uint32_t G5S              :  1; /*!< Ofs=20, w=1 Analog I/O group x status */
      __ROB uint32_t G6S              :  1; /*!< Ofs=21, w=1 Analog I/O group x status */
      __ROB uint32_t G7S              :  1; /*!< Ofs=22, w=1 Analog I/O group x status */
      __ROB uint32_t G8S              :  1; /*!< Ofs=23, w=1 Analog I/O group x status */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  TSC_IOGCSR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    TSC_IOGCSR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    TSC_IOGCSR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
#if 0
struct GPIO_MODER_s { /*!< GPIO port mode register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t MODER0           :  2; /*!< Ofs=0, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER1           :  2; /*!< Ofs=2, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER2           :  2; /*!< Ofs=4, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER3           :  2; /*!< Ofs=6, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER4           :  2; /*!< Ofs=8, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER5           :  2; /*!< Ofs=10, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER6           :  2; /*!< Ofs=12, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER7           :  2; /*!< Ofs=14, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER8           :  2; /*!< Ofs=16, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER9           :  2; /*!< Ofs=18, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER10          :  2; /*!< Ofs=20, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER11          :  2; /*!< Ofs=22, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER12          :  2; /*!< Ofs=24, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER13          :  2; /*!< Ofs=26, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER14          :  2; /*!< Ofs=28, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t MODER15          :  2; /*!< Ofs=30, w=2 Port x configuration bits (y = 0..15) */
    } B;
  } ;
#ifdef __cplusplus
  GPIO_MODER_s(): R(0xA8000000u) {};
  template<typename F> void modify (F f) volatile {
    GPIO_MODER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    GPIO_MODER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct GPIO_OTYPER_s { /*!< GPIO port output type register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OT0              :  1; /*!< Ofs=0, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT1              :  1; /*!< Ofs=1, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT2              :  1; /*!< Ofs=2, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT3              :  1; /*!< Ofs=3, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT4              :  1; /*!< Ofs=4, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT5              :  1; /*!< Ofs=5, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT6              :  1; /*!< Ofs=6, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT7              :  1; /*!< Ofs=7, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT8              :  1; /*!< Ofs=8, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT9              :  1; /*!< Ofs=9, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT10             :  1; /*!< Ofs=10, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT11             :  1; /*!< Ofs=11, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT12             :  1; /*!< Ofs=12, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT13             :  1; /*!< Ofs=13, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT14             :  1; /*!< Ofs=14, w=1 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OT15             :  1; /*!< Ofs=15, w=1 Port x configuration bits (y = 0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  GPIO_OTYPER_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    GPIO_OTYPER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    GPIO_OTYPER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct GPIO_OSPEEDR_s { /*!< GPIO port output speed register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OSPEEDR0         :  2; /*!< Ofs=0, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR1         :  2; /*!< Ofs=2, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR2         :  2; /*!< Ofs=4, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR3         :  2; /*!< Ofs=6, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR4         :  2; /*!< Ofs=8, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR5         :  2; /*!< Ofs=10, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR6         :  2; /*!< Ofs=12, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR7         :  2; /*!< Ofs=14, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR8         :  2; /*!< Ofs=16, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR9         :  2; /*!< Ofs=18, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR10        :  2; /*!< Ofs=20, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR11        :  2; /*!< Ofs=22, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR12        :  2; /*!< Ofs=24, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR13        :  2; /*!< Ofs=26, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR14        :  2; /*!< Ofs=28, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t OSPEEDR15        :  2; /*!< Ofs=30, w=2 Port x configuration bits (y = 0..15) */
    } B;
  } ;
#ifdef __cplusplus
  GPIO_OSPEEDR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    GPIO_OSPEEDR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    GPIO_OSPEEDR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct GPIO_PUPDR_s { /*!< GPIO port pull-up/pull-down register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t PUPDR0           :  2; /*!< Ofs=0, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR1           :  2; /*!< Ofs=2, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR2           :  2; /*!< Ofs=4, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR3           :  2; /*!< Ofs=6, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR4           :  2; /*!< Ofs=8, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR5           :  2; /*!< Ofs=10, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR6           :  2; /*!< Ofs=12, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR7           :  2; /*!< Ofs=14, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR8           :  2; /*!< Ofs=16, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR9           :  2; /*!< Ofs=18, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR10          :  2; /*!< Ofs=20, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR11          :  2; /*!< Ofs=22, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR12          :  2; /*!< Ofs=24, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR13          :  2; /*!< Ofs=26, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR14          :  2; /*!< Ofs=28, w=2 Port x configuration bits (y = 0..15) */
      __RWB uint32_t PUPDR15          :  2; /*!< Ofs=30, w=2 Port x configuration bits (y = 0..15) */
    } B;
  } ;
#ifdef __cplusplus
  GPIO_PUPDR_s(): R(0x64000000u) {};
  template<typename F> void modify (F f) volatile {
    GPIO_PUPDR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    GPIO_PUPDR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct GPIO_IDR_s { /*!< GPIO port input data register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t IDR0             :  1; /*!< Ofs=0, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR1             :  1; /*!< Ofs=1, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR2             :  1; /*!< Ofs=2, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR3             :  1; /*!< Ofs=3, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR4             :  1; /*!< Ofs=4, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR5             :  1; /*!< Ofs=5, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR6             :  1; /*!< Ofs=6, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR7             :  1; /*!< Ofs=7, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR8             :  1; /*!< Ofs=8, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR9             :  1; /*!< Ofs=9, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR10            :  1; /*!< Ofs=10, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR11            :  1; /*!< Ofs=11, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR12            :  1; /*!< Ofs=12, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR13            :  1; /*!< Ofs=13, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR14            :  1; /*!< Ofs=14, w=1 Port input data (y = 0..15) */
      __ROB uint32_t IDR15            :  1; /*!< Ofs=15, w=1 Port input data (y = 0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  GPIO_IDR_s(__RO GPIO_IDR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct GPIO_ODR_s { /*!< GPIO port output data register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ODR0             :  1; /*!< Ofs=0, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR1             :  1; /*!< Ofs=1, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR2             :  1; /*!< Ofs=2, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR3             :  1; /*!< Ofs=3, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR4             :  1; /*!< Ofs=4, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR5             :  1; /*!< Ofs=5, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR6             :  1; /*!< Ofs=6, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR7             :  1; /*!< Ofs=7, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR8             :  1; /*!< Ofs=8, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR9             :  1; /*!< Ofs=9, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR10            :  1; /*!< Ofs=10, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR11            :  1; /*!< Ofs=11, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR12            :  1; /*!< Ofs=12, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR13            :  1; /*!< Ofs=13, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR14            :  1; /*!< Ofs=14, w=1 Port output data (y = 0..15) */
      __RWB uint32_t ODR15            :  1; /*!< Ofs=15, w=1 Port output data (y = 0..15) */
            uint32_t unused0          : 16;
    } B;
  } ;
#ifdef __cplusplus
  GPIO_ODR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    GPIO_ODR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    GPIO_ODR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct GPIO_BSRR_s { /*!< GPIO port bit set/reset register */
  union {
      __WOB uint32_t R;
    struct {
      __WOB uint32_t BS0              :  1; /*!< Ofs=0, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS1              :  1; /*!< Ofs=1, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS2              :  1; /*!< Ofs=2, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS3              :  1; /*!< Ofs=3, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS4              :  1; /*!< Ofs=4, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS5              :  1; /*!< Ofs=5, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS6              :  1; /*!< Ofs=6, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS7              :  1; /*!< Ofs=7, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS8              :  1; /*!< Ofs=8, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS9              :  1; /*!< Ofs=9, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS10             :  1; /*!< Ofs=10, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS11             :  1; /*!< Ofs=11, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS12             :  1; /*!< Ofs=12, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS13             :  1; /*!< Ofs=13, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS14             :  1; /*!< Ofs=14, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BS15             :  1; /*!< Ofs=15, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BR0              :  1; /*!< Ofs=16, w=1 Port x set bit y (y= 0..15) */
      __WOB uint32_t BR1              :  1; /*!< Ofs=17, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR2              :  1; /*!< Ofs=18, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR3              :  1; /*!< Ofs=19, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR4              :  1; /*!< Ofs=20, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR5              :  1; /*!< Ofs=21, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR6              :  1; /*!< Ofs=22, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR7              :  1; /*!< Ofs=23, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR8              :  1; /*!< Ofs=24, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR9              :  1; /*!< Ofs=25, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR10             :  1; /*!< Ofs=26, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR11             :  1; /*!< Ofs=27, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR12             :  1; /*!< Ofs=28, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR13             :  1; /*!< Ofs=29, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR14             :  1; /*!< Ofs=30, w=1 Port x reset bit y (y = 0..15) */
      __WOB uint32_t BR15             :  1; /*!< Ofs=31, w=1 Port x reset bit y (y = 0..15) */
    } B;
  } ;
#ifdef __cplusplus
  GPIO_BSRR_s(): R(0x00000000u) {};
  template<typename F> void setbits (F f) volatile {
    GPIO_BSRR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct GPIO_LCKR_s { /*!< GPIO port configuration lock register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LCK0             :  1; /*!< Ofs=0, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK1             :  1; /*!< Ofs=1, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK2             :  1; /*!< Ofs=2, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK3             :  1; /*!< Ofs=3, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK4             :  1; /*!< Ofs=4, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK5             :  1; /*!< Ofs=5, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK6             :  1; /*!< Ofs=6, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK7             :  1; /*!< Ofs=7, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK8             :  1; /*!< Ofs=8, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK9             :  1; /*!< Ofs=9, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK10            :  1; /*!< Ofs=10, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK11            :  1; /*!< Ofs=11, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK12            :  1; /*!< Ofs=12, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK13            :  1; /*!< Ofs=13, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK14            :  1; /*!< Ofs=14, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCK15            :  1; /*!< Ofs=15, w=1 Port x lock bit y (y= 0..15) */
      __RWB uint32_t LCKK             :  1; /*!< Ofs=16, w=1 Port x lock bit y (y= 0..15) */
            uint32_t unused0          : 15;
    } B;
  } ;
#ifdef __cplusplus
  GPIO_LCKR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    GPIO_LCKR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    GPIO_LCKR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct GPIO_AFRL_s { /*!< GPIO alternate function low register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t AFRL0            :  4; /*!< Ofs=0, w=4 Alternate function selection for port x bit y (y = 0..7) */
      __RWB uint32_t AFRL1            :  4; /*!< Ofs=4, w=4 Alternate function selection for port x bit y (y = 0..7) */
      __RWB uint32_t AFRL2            :  4; /*!< Ofs=8, w=4 Alternate function selection for port x bit y (y = 0..7) */
      __RWB uint32_t AFRL3            :  4; /*!< Ofs=12, w=4 Alternate function selection for port x bit y (y = 0..7) */
      __RWB uint32_t AFRL4            :  4; /*!< Ofs=16, w=4 Alternate function selection for port x bit y (y = 0..7) */
      __RWB uint32_t AFRL5            :  4; /*!< Ofs=20, w=4 Alternate function selection for port x bit y (y = 0..7) */
      __RWB uint32_t AFRL6            :  4; /*!< Ofs=24, w=4 Alternate function selection for port x bit y (y = 0..7) */
      __RWB uint32_t AFRL7            :  4; /*!< Ofs=28, w=4 Alternate function selection for port x bit y (y = 0..7) */
    } B;
  } ;
#ifdef __cplusplus
  GPIO_AFRL_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    GPIO_AFRL_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    GPIO_AFRL_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct GPIO_AFRH_s { /*!< GPIO alternate function high register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t AFRH8            :  4; /*!< Ofs=0, w=4 Alternate function selection for port x bit y (y = 8..15) */
      __RWB uint32_t AFRH9            :  4; /*!< Ofs=4, w=4 Alternate function selection for port x bit y (y = 8..15) */
      __RWB uint32_t AFRH10           :  4; /*!< Ofs=8, w=4 Alternate function selection for port x bit y (y = 8..15) */
      __RWB uint32_t AFRH11           :  4; /*!< Ofs=12, w=4 Alternate function selection for port x bit y (y = 8..15) */
      __RWB uint32_t AFRH12           :  4; /*!< Ofs=16, w=4 Alternate function selection for port x bit y (y = 8..15) */
      __RWB uint32_t AFRH13           :  4; /*!< Ofs=20, w=4 Alternate function selection for port x bit y (y = 8..15) */
      __RWB uint32_t AFRH14           :  4; /*!< Ofs=24, w=4 Alternate function selection for port x bit y (y = 8..15) */
      __RWB uint32_t AFRH15           :  4; /*!< Ofs=28, w=4 Alternate function selection for port x bit y (y = 8..15) */
    } B;
  } ;
#ifdef __cplusplus
  GPIO_AFRH_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    GPIO_AFRH_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    GPIO_AFRH_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
#endif // 0
struct ADC_ISR_s { /*!< interrupt and status register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ADRDY            :  1; /*!< Ofs=0, w=1 ADRDY */
      __RWB uint32_t EOSMP            :  1; /*!< Ofs=1, w=1 EOSMP */
      __RWB uint32_t EOC              :  1; /*!< Ofs=2, w=1 EOC */
      __RWB uint32_t EOS              :  1; /*!< Ofs=3, w=1 EOS */
      __RWB uint32_t OVR              :  1; /*!< Ofs=4, w=1 OVR */
      __RWB uint32_t JEOC             :  1; /*!< Ofs=5, w=1 JEOC */
      __RWB uint32_t JEOS             :  1; /*!< Ofs=6, w=1 JEOS */
      __RWB uint32_t AWD1             :  1; /*!< Ofs=7, w=1 AWD1 */
      __RWB uint32_t AWD2             :  1; /*!< Ofs=8, w=1 AWD2 */
      __RWB uint32_t AWD3             :  1; /*!< Ofs=9, w=1 AWD3 */
      __RWB uint32_t JQOVF            :  1; /*!< Ofs=10, w=1 JQOVF */
            uint32_t unused0          : 21;
    } B;
  } ;
#ifdef __cplusplus
  ADC_ISR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_ISR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_ISR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_IER_s { /*!< interrupt enable register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ADRDYIE          :  1; /*!< Ofs=0, w=1 ADRDYIE */
      __RWB uint32_t EOSMPIE          :  1; /*!< Ofs=1, w=1 EOSMPIE */
      __RWB uint32_t EOCIE            :  1; /*!< Ofs=2, w=1 EOCIE */
      __RWB uint32_t EOSIE            :  1; /*!< Ofs=3, w=1 EOSIE */
      __RWB uint32_t OVRIE            :  1; /*!< Ofs=4, w=1 OVRIE */
      __RWB uint32_t JEOCIE           :  1; /*!< Ofs=5, w=1 JEOCIE */
      __RWB uint32_t JEOSIE           :  1; /*!< Ofs=6, w=1 JEOSIE */
      __RWB uint32_t AWD1IE           :  1; /*!< Ofs=7, w=1 AWD1IE */
      __RWB uint32_t AWD2IE           :  1; /*!< Ofs=8, w=1 AWD2IE */
      __RWB uint32_t AWD3IE           :  1; /*!< Ofs=9, w=1 AWD3IE */
      __RWB uint32_t JQOVFIE          :  1; /*!< Ofs=10, w=1 JQOVFIE */
            uint32_t unused0          : 21;
    } B;
  } ;
#ifdef __cplusplus
  ADC_IER_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_IER_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_IER_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_CR_s { /*!< control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ADEN             :  1; /*!< Ofs=0, w=1 ADEN */
      __RWB uint32_t ADDIS            :  1; /*!< Ofs=1, w=1 ADDIS */
      __RWB uint32_t ADSTART          :  1; /*!< Ofs=2, w=1 ADSTART */
      __RWB uint32_t JADSTART         :  1; /*!< Ofs=3, w=1 JADSTART */
      __RWB uint32_t ADSTP            :  1; /*!< Ofs=4, w=1 ADSTP */
      __RWB uint32_t JADSTP           :  1; /*!< Ofs=5, w=1 JADSTP */
            uint32_t unused0          : 22;
      __RWB uint32_t ADVREGEN         :  1; /*!< Ofs=28, w=1 ADVREGEN */
      __RWB uint32_t DEEPPWD          :  1; /*!< Ofs=29, w=1 DEEPPWD */
      __RWB uint32_t ADCALDIF         :  1; /*!< Ofs=30, w=1 ADCALDIF */
      __RWB uint32_t ADCAL            :  1; /*!< Ofs=31, w=1 ADCAL */
    } B;
  } ;
#ifdef __cplusplus
  ADC_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_CFGR_s { /*!< configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t DMAEN            :  1; /*!< Ofs=0, w=1 DMAEN */
      __RWB uint32_t DMACFG           :  1; /*!< Ofs=1, w=1 DMACFG */
            uint32_t unused0          :  1;
      __RWB uint32_t RES              :  2; /*!< Ofs=3, w=2 RES */
      __RWB uint32_t ALIGN            :  1; /*!< Ofs=5, w=1 ALIGN */
      __RWB uint32_t EXTSEL           :  4; /*!< Ofs=6, w=4 EXTSEL */
      __RWB uint32_t EXTEN            :  2; /*!< Ofs=10, w=2 EXTEN */
      __RWB uint32_t OVRMOD           :  1; /*!< Ofs=12, w=1 OVRMOD */
      __RWB uint32_t CONT             :  1; /*!< Ofs=13, w=1 CONT */
      __RWB uint32_t AUTDLY           :  1; /*!< Ofs=14, w=1 AUTDLY */
      __RWB uint32_t AUTOFF           :  1; /*!< Ofs=15, w=1 AUTOFF */
      __RWB uint32_t DISCEN           :  1; /*!< Ofs=16, w=1 DISCEN */
      __RWB uint32_t DISCNUM          :  3; /*!< Ofs=17, w=3 DISCNUM */
      __RWB uint32_t JDISCEN          :  1; /*!< Ofs=20, w=1 JDISCEN */
      __RWB uint32_t JQM              :  1; /*!< Ofs=21, w=1 JQM */
      __RWB uint32_t AWD1SGL          :  1; /*!< Ofs=22, w=1 AWD1SGL */
      __RWB uint32_t AWD1EN           :  1; /*!< Ofs=23, w=1 AWD1EN */
      __RWB uint32_t JAWD1EN          :  1; /*!< Ofs=24, w=1 JAWD1EN */
      __RWB uint32_t JAUTO            :  1; /*!< Ofs=25, w=1 JAUTO */
      __RWB uint32_t AWDCH1CH         :  5; /*!< Ofs=26, w=5 AWDCH1CH */
            uint32_t unused1          :  1;
    } B;
  } ;
#ifdef __cplusplus
  ADC_CFGR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_CFGR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_CFGR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_CFGR2_s { /*!< configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t ROVSE            :  1; /*!< Ofs=0, w=1 DMAEN */
      __RWB uint32_t JOVSE            :  1; /*!< Ofs=1, w=1 DMACFG */
      __RWB uint32_t OVSR             :  3; /*!< Ofs=2, w=3 RES */
      __RWB uint32_t OVSS             :  4; /*!< Ofs=5, w=4 ALIGN */
      __RWB uint32_t TOVS             :  1; /*!< Ofs=9, w=1 EXTSEL */
      __RWB uint32_t ROVSM            :  1; /*!< Ofs=10, w=1 EXTEN */
            uint32_t unused0          : 21;
    } B;
  } ;
#ifdef __cplusplus
  ADC_CFGR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_CFGR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_CFGR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_SMPR1_s { /*!< sample time register 1 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  3;
      __RWB uint32_t SMP1             :  3; /*!< Ofs=3, w=3 SMP1 */
      __RWB uint32_t SMP2             :  3; /*!< Ofs=6, w=3 SMP2 */
      __RWB uint32_t SMP3             :  3; /*!< Ofs=9, w=3 SMP3 */
      __RWB uint32_t SMP4             :  3; /*!< Ofs=12, w=3 SMP4 */
      __RWB uint32_t SMP5             :  3; /*!< Ofs=15, w=3 SMP5 */
      __RWB uint32_t SMP6             :  3; /*!< Ofs=18, w=3 SMP6 */
      __RWB uint32_t SMP7             :  3; /*!< Ofs=21, w=3 SMP7 */
      __RWB uint32_t SMP8             :  3; /*!< Ofs=24, w=3 SMP8 */
      __RWB uint32_t SMP9             :  3; /*!< Ofs=27, w=3 SMP9 */
            uint32_t unused1          :  2;
    } B;
  } ;
#ifdef __cplusplus
  ADC_SMPR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_SMPR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_SMPR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_SMPR2_s { /*!< sample time register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SMP10            :  3; /*!< Ofs=0, w=3 SMP10 */
      __RWB uint32_t SMP11            :  3; /*!< Ofs=3, w=3 SMP11 */
      __RWB uint32_t SMP12            :  3; /*!< Ofs=6, w=3 SMP12 */
      __RWB uint32_t SMP13            :  3; /*!< Ofs=9, w=3 SMP13 */
      __RWB uint32_t SMP14            :  3; /*!< Ofs=12, w=3 SMP14 */
      __RWB uint32_t SMP15            :  3; /*!< Ofs=15, w=3 SMP15 */
      __RWB uint32_t SMP16            :  3; /*!< Ofs=18, w=3 SMP16 */
      __RWB uint32_t SMP17            :  3; /*!< Ofs=21, w=3 SMP17 */
      __RWB uint32_t SMP18            :  3; /*!< Ofs=24, w=3 SMP18 */
            uint32_t unused0          :  5;
    } B;
  } ;
#ifdef __cplusplus
  ADC_SMPR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_SMPR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_SMPR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_TR1_s { /*!< watchdog threshold register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LT1              : 12; /*!< Ofs=0, w=12 LT1 */
            uint32_t unused0          :  4;
      __RWB uint32_t HT1              : 12; /*!< Ofs=16, w=12 HT1 */
            uint32_t unused1          :  4;
    } B;
  } ;
#ifdef __cplusplus
  ADC_TR1_s(): R(0x0FFF0000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_TR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_TR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_TR2_s { /*!< watchdog threshold register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LT2              :  8; /*!< Ofs=0, w=8 LT2 */
            uint32_t unused0          :  8;
      __RWB uint32_t HT2              :  8; /*!< Ofs=16, w=8 HT2 */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  ADC_TR2_s(): R(0x0FFF0000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_TR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_TR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_TR3_s { /*!< watchdog threshold register 3 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t LT3              :  8; /*!< Ofs=0, w=8 LT3 */
            uint32_t unused0          :  8;
      __RWB uint32_t HT3              :  8; /*!< Ofs=16, w=8 HT3 */
            uint32_t unused1          :  8;
    } B;
  } ;
#ifdef __cplusplus
  ADC_TR3_s(): R(0x0FFF0000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_TR3_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_TR3_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_SQR1_s { /*!< regular sequence register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t L3               :  4; /*!< Ofs=0, w=4 L3 */
            uint32_t unused0          :  2;
      __RWB uint32_t SQ1              :  5; /*!< Ofs=6, w=5 SQ1 */
            uint32_t unused1          :  1;
      __RWB uint32_t SQ2              :  5; /*!< Ofs=12, w=5 SQ2 */
            uint32_t unused2          :  1;
      __RWB uint32_t SQ3              :  5; /*!< Ofs=18, w=5 SQ3 */
            uint32_t unused3          :  1;
      __RWB uint32_t SQ4              :  5; /*!< Ofs=24, w=5 SQ4 */
            uint32_t unused4          :  3;
    } B;
  } ;
#ifdef __cplusplus
  ADC_SQR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_SQR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_SQR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_SQR2_s { /*!< regular sequence register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SQ5              :  5; /*!< Ofs=0, w=5 SQ5 */
            uint32_t unused0          :  1;
      __RWB uint32_t SQ6              :  5; /*!< Ofs=6, w=5 SQ6 */
            uint32_t unused1          :  1;
      __RWB uint32_t SQ7              :  5; /*!< Ofs=12, w=5 SQ7 */
            uint32_t unused2          :  1;
      __RWB uint32_t SQ8              :  5; /*!< Ofs=18, w=5 SQ8 */
            uint32_t unused3          :  1;
      __RWB uint32_t SQ9              :  5; /*!< Ofs=24, w=5 SQ9 */
            uint32_t unused4          :  3;
    } B;
  } ;
#ifdef __cplusplus
  ADC_SQR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_SQR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_SQR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_SQR3_s { /*!< regular sequence register 3 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SQ10             :  5; /*!< Ofs=0, w=5 SQ10 */
            uint32_t unused0          :  1;
      __RWB uint32_t SQ11             :  5; /*!< Ofs=6, w=5 SQ11 */
            uint32_t unused1          :  1;
      __RWB uint32_t SQ12             :  5; /*!< Ofs=12, w=5 SQ12 */
            uint32_t unused2          :  1;
      __RWB uint32_t SQ13             :  5; /*!< Ofs=18, w=5 SQ13 */
            uint32_t unused3          :  1;
      __RWB uint32_t SQ14             :  5; /*!< Ofs=24, w=5 SQ14 */
            uint32_t unused4          :  3;
    } B;
  } ;
#ifdef __cplusplus
  ADC_SQR3_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_SQR3_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_SQR3_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_SQR4_s { /*!< regular sequence register 4 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t SQ15             :  5; /*!< Ofs=0, w=5 SQ15 */
            uint32_t unused0          :  1;
      __RWB uint32_t SQ16             :  5; /*!< Ofs=6, w=5 SQ16 */
            uint32_t unused1          : 21;
    } B;
  } ;
#ifdef __cplusplus
  ADC_SQR4_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_SQR4_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_SQR4_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_JSQR_s { /*!< injected sequence register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t JL               :  2; /*!< Ofs=0, w=2 JL */
      __RWB uint32_t JEXTSEL          :  4; /*!< Ofs=2, w=4 JEXTSEL */
      __RWB uint32_t JEXTEN           :  2; /*!< Ofs=6, w=2 JEXTEN */
      __RWB uint32_t JSQ1             :  5; /*!< Ofs=8, w=5 JSQ1 */
            uint32_t unused0          :  1;
      __RWB uint32_t JSQ2             :  5; /*!< Ofs=14, w=5 JSQ2 */
            uint32_t unused1          :  1;
      __RWB uint32_t JSQ3             :  5; /*!< Ofs=20, w=5 JSQ3 */
            uint32_t unused2          :  1;
      __RWB uint32_t JSQ4             :  5; /*!< Ofs=26, w=5 JSQ4 */
            uint32_t unused3          :  1;
    } B;
  } ;
#ifdef __cplusplus
  ADC_JSQR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_JSQR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_JSQR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_OFR1_s { /*!< offset register 1 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OFFSET1          : 12; /*!< Ofs=0, w=12 OFFSET1 */
            uint32_t unused0          : 14;
      __RWB uint32_t OFFSET1_CH       :  5; /*!< Ofs=26, w=5 OFFSET1_CH */
      __RWB uint32_t OFFSET1_EN       :  1; /*!< Ofs=31, w=1 OFFSET1_EN */
    } B;
  } ;
#ifdef __cplusplus
  ADC_OFR1_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_OFR1_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_OFR1_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_OFR2_s { /*!< offset register 2 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OFFSET2          : 12; /*!< Ofs=0, w=12 OFFSET2 */
            uint32_t unused0          : 14;
      __RWB uint32_t OFFSET2_CH       :  5; /*!< Ofs=26, w=5 OFFSET2_CH */
      __RWB uint32_t OFFSET2_EN       :  1; /*!< Ofs=31, w=1 OFFSET2_EN */
    } B;
  } ;
#ifdef __cplusplus
  ADC_OFR2_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_OFR2_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_OFR2_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_OFR3_s { /*!< offset register 3 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OFFSET3          : 12; /*!< Ofs=0, w=12 OFFSET3 */
            uint32_t unused0          : 14;
      __RWB uint32_t OFFSET3_CH       :  5; /*!< Ofs=26, w=5 OFFSET3_CH */
      __RWB uint32_t OFFSET3_EN       :  1; /*!< Ofs=31, w=1 OFFSET3_EN */
    } B;
  } ;
#ifdef __cplusplus
  ADC_OFR3_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_OFR3_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_OFR3_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_OFR4_s { /*!< offset register 4 */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t OFFSET4          : 12; /*!< Ofs=0, w=12 OFFSET4 */
            uint32_t unused0          : 14;
      __RWB uint32_t OFFSET4_CH       :  5; /*!< Ofs=26, w=5 OFFSET4_CH */
      __RWB uint32_t OFFSET4_EN       :  1; /*!< Ofs=31, w=1 OFFSET4_EN */
    } B;
  } ;
#ifdef __cplusplus
  ADC_OFR4_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_OFR4_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_OFR4_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_AWD2CR_s { /*!< Analog Watchdog 2 Configuration Register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  1;
      __RWB uint32_t AWD2CH           : 18; /*!< Ofs=1, w=18 AWD2CH */
            uint32_t unused1          : 13;
    } B;
  } ;
#ifdef __cplusplus
  ADC_AWD2CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_AWD2CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_AWD2CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_AWD3CR_s { /*!< Analog Watchdog 3 Configuration Register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  1;
      __RWB uint32_t AWD3CH           : 18; /*!< Ofs=1, w=18 AWD3CH */
            uint32_t unused1          : 13;
    } B;
  } ;
#ifdef __cplusplus
  ADC_AWD3CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_AWD3CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_AWD3CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_DIFSEL_s { /*!< Differential Mode Selection Register 2 */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  1;
      __RWB uint32_t DIFSEL_1_15      : 15; /*!< Ofs=1, w=15 Differential mode for channels 15 to 1 */
      __ROB uint32_t DIFSEL_16_18     :  3; /*!< Ofs=16, w=3 Differential mode for channels 18 to 16 */
            uint32_t unused1          : 13;
    } B;
  } ;
#ifdef __cplusplus
  ADC_DIFSEL_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_DIFSEL_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_DIFSEL_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct ADC_CALFACT_s { /*!< Calibration Factors */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CALFACT_S        :  7; /*!< Ofs=0, w=7 CALFACT_S */
            uint32_t unused0          :  9;
      __RWB uint32_t CALFACT_D        :  7; /*!< Ofs=16, w=7 CALFACT_D */
            uint32_t unused1          :  9;
    } B;
  } ;
#ifdef __cplusplus
  ADC_CALFACT_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    ADC_CALFACT_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    ADC_CALFACT_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct AES_CR_s { /*!< control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EN               :  1; /*!< Ofs=0, w=1 AES enable */
      __RWB uint32_t DATATYPE         :  2; /*!< Ofs=1, w=2 Data type selection (for data in and data out to/from the cryptographic block) */
      __RWB uint32_t MODE             :  2; /*!< Ofs=3, w=2 AES operating mode */
      __RWB uint32_t CHMOD            :  2; /*!< Ofs=5, w=2 AES chaining mode */
      __RWB uint32_t CCFC             :  1; /*!< Ofs=7, w=1 Computation Complete Flag Clear */
      __RWB uint32_t ERRC             :  1; /*!< Ofs=8, w=1 Error clear */
      __RWB uint32_t CCFIE            :  1; /*!< Ofs=9, w=1 CCF flag interrupt enable */
      __RWB uint32_t ERRIE            :  1; /*!< Ofs=10, w=1 Error interrupt enable */
      __RWB uint32_t DMAINEN          :  1; /*!< Ofs=11, w=1 Enable DMA management of data input phase */
      __RWB uint32_t DMAOUTEN         :  1; /*!< Ofs=12, w=1 Enable DMA management of data output phase */
            uint32_t unused0          : 19;
    } B;
  } ;
#ifdef __cplusplus
  AES_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    AES_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    AES_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct AES_SR_s { /*!< status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t CCF              :  1; /*!< Ofs=0, w=1 Computation complete flag */
      __ROB uint32_t RDERR            :  1; /*!< Ofs=1, w=1 Read error flag */
      __ROB uint32_t WRERR            :  1; /*!< Ofs=2, w=1 Write error flag */
            uint32_t unused0          : 29;
    } B;
  } ;
#ifdef __cplusplus
  AES_SR_s(__RO AES_SR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct RNG_CR_s { /*!< control register */
  union {
      __RWB uint32_t R;
    struct {
            uint32_t unused0          :  2;
      __RWB uint32_t RNGEN            :  1; /*!< Ofs=2, w=1 Random number generator enable */
      __RWB uint32_t IE               :  1; /*!< Ofs=3, w=1 Interrupt enable */
            uint32_t unused1          : 28;
    } B;
  } ;
#ifdef __cplusplus
  RNG_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RNG_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RNG_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct RNG_SR_s { /*!< status register */
  union {
      __RWB uint32_t R;
    struct {
      __ROB uint32_t DRDY             :  1; /*!< Ofs=0, w=1 Data ready */
      __ROB uint32_t CECS             :  1; /*!< Ofs=1, w=1 Clock error current status */
      __ROB uint32_t SECS             :  1; /*!< Ofs=2, w=1 Seed error current status */
            uint32_t unused0          :  2;
      __RWB uint32_t CEIS             :  1; /*!< Ofs=5, w=1 Clock error interrupt status */
      __RWB uint32_t SEIS             :  1; /*!< Ofs=6, w=1 Seed error interrupt status */
            uint32_t unused1          : 25;
    } B;
  } ;
#ifdef __cplusplus
  RNG_SR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    RNG_SR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    RNG_SR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct QUADSPI_CR_s { /*!< control register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t EN               :  1; /*!< Ofs=0, w=1 Enable */
      __RWB uint32_t ABORT            :  1; /*!< Ofs=1, w=1 Abort request */
      __RWB uint32_t DMAEN            :  1; /*!< Ofs=2, w=1 DMA enable */
      __RWB uint32_t TCEN             :  1; /*!< Ofs=3, w=1 Timeout counter enable */
      __RWB uint32_t SSHIFT           :  1; /*!< Ofs=4, w=1 Sample shift */
            uint32_t unused0          :  1;
      __RWB uint32_t DFM              :  1; /*!< Ofs=6, w=1 Dual-flash mode */
      __RWB uint32_t FSEL             :  1; /*!< Ofs=7, w=1 FLASH memory selection */
      __RWB uint32_t FTHRES           :  5; /*!< Ofs=8, w=5 IFO threshold level */
            uint32_t unused1          :  3;
      __RWB uint32_t TEIE             :  1; /*!< Ofs=16, w=1 Transfer error interrupt enable */
      __RWB uint32_t TCIE             :  1; /*!< Ofs=17, w=1 Transfer complete interrupt enable */
      __RWB uint32_t FTIE             :  1; /*!< Ofs=18, w=1 FIFO threshold interrupt enable */
      __RWB uint32_t SMIE             :  1; /*!< Ofs=19, w=1 Status match interrupt enable */
      __RWB uint32_t TOIE             :  1; /*!< Ofs=20, w=1 TimeOut interrupt enable */
            uint32_t unused2          :  1;
      __RWB uint32_t APMS             :  1; /*!< Ofs=22, w=1 Automatic poll mode stop */
      __RWB uint32_t PMM              :  1; /*!< Ofs=23, w=1 Polling match mode */
      __RWB uint32_t PRESCALER        :  8; /*!< Ofs=24, w=8 Clock prescaler */
    } B;
  } ;
#ifdef __cplusplus
  QUADSPI_CR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    QUADSPI_CR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    QUADSPI_CR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct QUADSPI_DCR_s { /*!< device configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CKMODE           :  1; /*!< Ofs=0, w=1 Mode 0 / mode 3 */
            uint32_t unused0          :  7;
      __RWB uint32_t CSHT             :  3; /*!< Ofs=8, w=3 Chip select high time */
            uint32_t unused1          :  5;
      __RWB uint32_t FSIZE            :  5; /*!< Ofs=16, w=5 FLASH memory size */
            uint32_t unused2          : 11;
    } B;
  } ;
#ifdef __cplusplus
  QUADSPI_DCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    QUADSPI_DCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    QUADSPI_DCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct QUADSPI_SR_s { /*!< status register */
  union {
      __ROB uint32_t R;
    struct {
      __ROB uint32_t TEF              :  1; /*!< Ofs=0, w=1 Transfer error flag */
      __ROB uint32_t TCF              :  1; /*!< Ofs=1, w=1 Transfer complete flag */
      __ROB uint32_t FTF              :  1; /*!< Ofs=2, w=1 FIFO threshold flag */
      __ROB uint32_t SMF              :  1; /*!< Ofs=3, w=1 Status match flag */
      __ROB uint32_t TOF              :  1; /*!< Ofs=4, w=1 Timeout flag */
      __ROB uint32_t BUSY             :  1; /*!< Ofs=5, w=1 Busy */
            uint32_t unused0          :  2;
      __ROB uint32_t FLEVEL           :  7; /*!< Ofs=8, w=7 FIFO level */
            uint32_t unused1          : 17;
    } B;
  } ;
#ifdef __cplusplus
  QUADSPI_SR_s(__RO QUADSPI_SR_s & o) : R(o.R) {};
#endif // __cplusplus
} ;
struct QUADSPI_FCR_s { /*!< flag clear register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t CTEF             :  1; /*!< Ofs=0, w=1 Clear transfer error flag */
      __RWB uint32_t CTCF             :  1; /*!< Ofs=1, w=1 Clear transfer complete flag */
            uint32_t unused0          :  1;
      __RWB uint32_t CSMF             :  1; /*!< Ofs=3, w=1 Clear status match flag */
      __RWB uint32_t CTOF             :  1; /*!< Ofs=4, w=1 Clear timeout flag */
            uint32_t unused1          : 27;
    } B;
  } ;
#ifdef __cplusplus
  QUADSPI_FCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    QUADSPI_FCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    QUADSPI_FCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;
struct QUADSPI_CCR_s { /*!< communication configuration register */
  union {
      __RWB uint32_t R;
    struct {
      __RWB uint32_t INSTRUCTION      :  8; /*!< Ofs=0, w=8 Instruction */
      __RWB uint32_t IMODE            :  2; /*!< Ofs=8, w=2 Instruction mode */
      __RWB uint32_t ADMODE           :  2; /*!< Ofs=10, w=2 Address mode */
      __RWB uint32_t ADSIZE           :  2; /*!< Ofs=12, w=2 Address size */
      __RWB uint32_t ABMODE           :  2; /*!< Ofs=14, w=2 Alternate bytes mode */
      __RWB uint32_t ABSIZE           :  2; /*!< Ofs=16, w=2 Alternate bytes size */
      __RWB uint32_t DCYC             :  5; /*!< Ofs=18, w=5 Number of dummy cycles */
            uint32_t unused0          :  1;
      __RWB uint32_t DMODE            :  2; /*!< Ofs=24, w=2 Data mode */
      __RWB uint32_t FMODE            :  2; /*!< Ofs=26, w=2 Functional mode */
      __RWB uint32_t SIOO             :  1; /*!< Ofs=28, w=1 Send instruction only once mode */
            uint32_t unused1          :  1;
      __RWB uint32_t DHHC             :  1; /*!< Ofs=30, w=1 DDR hold half cycle */
      __RWB uint32_t DDRM             :  1; /*!< Ofs=31, w=1 Double data rate mode */
    } B;
  } ;
#ifdef __cplusplus
  QUADSPI_CCR_s(): R(0x00000000u) {};
  template<typename F> void modify (F f) volatile {
    QUADSPI_CCR_s t; t.R = R;
    R = f (t);
  }
  template<typename F> void setbits (F f) volatile {
    QUADSPI_CCR_s t;
    R = f (t);
  }
#endif // __cplusplus
} ;

typedef struct TIM_s { /*!< peripheral group TIM */
  __RW struct TIM_CR1_s         CR1;             /*!< Ofs=  0, W=4 control register 1 */
  __RW struct TIM_CR2_s         CR2;             /*!< Ofs=  4, W=4 control register 2 */
  __RW struct TIM_SMCR_s        SMCR;            /*!< Ofs=  8, W=4 slave mode control register */
  __RW struct TIM_DIER_s        DIER;            /*!< Ofs= 12, W=4 DMA/Interrupt enable register */
  __RW struct TIM_SR_s          SR;              /*!< Ofs= 16, W=4 status register */
  __WO struct TIM_EGR_s         EGR;             /*!< Ofs= 20, W=4 event generation register */
  union {
    __RW struct TIM_CCMR1_Output_s CCMR1_Output;    /*!< Ofs= 24, W=4 capture/compare mode register 1 (output mode) */
    __RW struct TIM_CCMR1_Input_s CCMR1_Input;     /*!< Ofs= 24, W=4 capture/compare mode register 1 (input mode) */
  } ;
  union {
    __RW struct TIM_CCMR2_Input_s CCMR2_Input;     /*!< Ofs= 28, W=4 capture/compare mode register 2 (input mode) */
    __RW struct TIM_CCMR2_Output_s CCMR2_Output;    /*!< Ofs= 28, W=4 capture/compare mode register 2 (output mode) */
  } ;
  __RW struct TIM_CCER_s        CCER;            /*!< Ofs= 32, W=4 capture/compare enable register */
  __RW struct TIM_CNT_s         CNT;             /*!< Ofs= 36, W=4 counter */
  __RW uint32_t PSC;             /*!< Ofs= 40, W=4 prescaler */
  __RW struct TIM_ARR_s         ARR;             /*!< Ofs= 44, W=4 auto-reload register */
  __RW uint32_t RCR;             /*!< Ofs= 48, W=4 repetition counter register */
  __RW struct TIM_CCR1_s        CCR1;            /*!< Ofs= 52, W=4 capture/compare register 1 */
  __RW struct TIM_CCR2_s        CCR2;            /*!< Ofs= 56, W=4 capture/compare register 2 */
  __RW struct TIM_CCR3_s        CCR3;            /*!< Ofs= 60, W=4 capture/compare register 3 */
  __RW struct TIM_CCR4_s        CCR4;            /*!< Ofs= 64, W=4 capture/compare register 4 */
  __RW struct TIM_BDTR_s        BDTR;            /*!< Ofs= 68, W=4 break and dead-time register */
  __RW struct TIM_DCR_s         DCR;             /*!< Ofs= 72, W=4 DMA control register */
  __RW uint32_t DMAR;            /*!< Ofs= 76, W=4 DMA address for full transfer */
  union {
    __RW struct TIM_OR_s          OR;              /*!< Ofs= 80, W=4 TIM2 option register */
    __RW struct TIM_OR1_s         OR1;             /*!< Ofs= 80, W=4 DMA address for full transfer */
  } ;
  __RW struct TIM_CCMR3_Output_s CCMR3_Output;    /*!< Ofs= 84, W=4 capture/compare mode register 2 (output mode) */
  __RW struct TIM_CCR5_s        CCR5;            /*!< Ofs= 88, W=4 capture/compare register 4 */
  __RW uint32_t CCR6;            /*!< Ofs= 92, W=4 capture/compare register 4 */
  __RW struct TIM_OR2_s         OR2;             /*!< Ofs= 96, W=4 DMA address for full transfer */
  __RW struct TIM_OR3_s         OR3;             /*!< Ofs=100, W=4 DMA address for full transfer */
}  TIM_Type; /* W=104=0x68 */
typedef struct LCD_s { /*!< peripheral group LCD */
  __RW struct LCD_CR_s          CR;              /*!< Ofs=  0, W=4 control register */
  __RW struct LCD_FCR_s         FCR;             /*!< Ofs=  4, W=4 frame control register */
  __RW struct LCD_SR_s          SR;              /*!< Ofs=  8, W=4 status register */
  __WO struct LCD_CLR_s         CLR;             /*!< Ofs= 12, W=4 clear register */
       uint32_t UNUSED0;
  __RW struct LCD_RAM_COM0_s    RAM_COM0;        /*!< Ofs= 20, W=4 display memory */
       uint32_t UNUSED1;
  __RW struct LCD_RAM_COM1_s    RAM_COM1;        /*!< Ofs= 28, W=4 display memory */
       uint32_t UNUSED2;
  __RW struct LCD_RAM_COM2_s    RAM_COM2;        /*!< Ofs= 36, W=4 display memory */
       uint32_t UNUSED3;
  __RW struct LCD_RAM_COM3_s    RAM_COM3;        /*!< Ofs= 44, W=4 display memory */
       uint32_t UNUSED4;
  __RW struct LCD_RAM_COM4_s    RAM_COM4;        /*!< Ofs= 52, W=4 display memory */
       uint32_t UNUSED5;
  __RW struct LCD_RAM_COM5_s    RAM_COM5;        /*!< Ofs= 60, W=4 display memory */
       uint32_t UNUSED6;
  __RW struct LCD_RAM_COM6_s    RAM_COM6;        /*!< Ofs= 68, W=4 display memory */
       uint32_t UNUSED7;
  __RW struct LCD_RAM_COM7_s    RAM_COM7;        /*!< Ofs= 76, W=4 display memory */
}  LCD_Type; /* W=80=0x50 */
typedef struct RTC_s { /*!< peripheral group RTC */
  __RW struct RTC_TR_s          TR;              /*!< Ofs=  0, W=4 time register */
  __RW struct RTC_DR_s          DR;              /*!< Ofs=  4, W=4 date register */
  __RW struct RTC_CR_s          CR;              /*!< Ofs=  8, W=4 control register */
  __RW struct RTC_ISR_s         ISR;             /*!< Ofs= 12, W=4 initialization and status register */
  __RW struct RTC_PRER_s        PRER;            /*!< Ofs= 16, W=4 prescaler register */
  __RW uint32_t WUTR;            /*!< Ofs= 20, W=4 wakeup timer register */
       uint32_t UNUSED0;
  __RW struct RTC_ALRMAR_s      ALRMAR;          /*!< Ofs= 28, W=4 alarm A register */
  __RW struct RTC_ALRMBR_s      ALRMBR;          /*!< Ofs= 32, W=4 alarm B register */
  __WO uint32_t WPR;             /*!< Ofs= 36, W=4 write protection register */
  __RO uint32_t SSR;             /*!< Ofs= 40, W=4 sub second register */
  __WO struct RTC_SHIFTR_s      SHIFTR;          /*!< Ofs= 44, W=4 shift control register */
  __RO struct RTC_TSTR_s        TSTR;            /*!< Ofs= 48, W=4 time stamp time register */
  __RO struct RTC_TSDR_s        TSDR;            /*!< Ofs= 52, W=4 time stamp date register */
  __RO uint32_t TSSSR;           /*!< Ofs= 56, W=4 timestamp sub second register */
  __RW struct RTC_CALR_s        CALR;            /*!< Ofs= 60, W=4 calibration register */
  __RW struct RTC_TAMPCR_s      TAMPCR;          /*!< Ofs= 64, W=4 tamper configuration register */
  __RW struct RTC_ALRMASSR_s    ALRMASSR;        /*!< Ofs= 68, W=4 alarm A sub second register */
  __RW struct RTC_ALRMBSSR_s    ALRMBSSR;        /*!< Ofs= 72, W=4 alarm B sub second register */
  __RW struct RTC_OR_s          OR;              /*!< Ofs= 76, W=4 option register */
  __RW uint32_t BKP0R;           /*!< Ofs= 80, W=4 backup register */
  __RW uint32_t BKP1R;           /*!< Ofs= 84, W=4 backup register */
  __RW uint32_t BKP2R;           /*!< Ofs= 88, W=4 backup register */
  __RW uint32_t BKP3R;           /*!< Ofs= 92, W=4 backup register */
  __RW uint32_t BKP4R;           /*!< Ofs= 96, W=4 backup register */
  __RW uint32_t BKP5R;           /*!< Ofs=100, W=4 backup register */
  __RW uint32_t BKP6R;           /*!< Ofs=104, W=4 backup register */
  __RW uint32_t BKP7R;           /*!< Ofs=108, W=4 backup register */
  __RW uint32_t BKP8R;           /*!< Ofs=112, W=4 backup register */
  __RW uint32_t BKP9R;           /*!< Ofs=116, W=4 backup register */
  __RW uint32_t BKP10R;          /*!< Ofs=120, W=4 backup register */
  __RW uint32_t BKP11R;          /*!< Ofs=124, W=4 backup register */
  __RW uint32_t BKP12R;          /*!< Ofs=128, W=4 backup register */
  __RW uint32_t BKP13R;          /*!< Ofs=132, W=4 backup register */
  __RW uint32_t BKP14R;          /*!< Ofs=136, W=4 backup register */
  __RW uint32_t BKP15R;          /*!< Ofs=140, W=4 backup register */
  __RW uint32_t BKP16R;          /*!< Ofs=144, W=4 backup register */
  __RW uint32_t BKP17R;          /*!< Ofs=148, W=4 backup register */
  __RW uint32_t BKP18R;          /*!< Ofs=152, W=4 backup register */
  __RW uint32_t BKP19R;          /*!< Ofs=156, W=4 backup register */
  __RW uint32_t BKP20R;          /*!< Ofs=160, W=4 backup register */
  __RW uint32_t BKP21R;          /*!< Ofs=164, W=4 backup register */
  __RW uint32_t BKP22R;          /*!< Ofs=168, W=4 backup register */
  __RW uint32_t BKP23R;          /*!< Ofs=172, W=4 backup register */
  __RW uint32_t BKP24R;          /*!< Ofs=176, W=4 backup register */
  __RW uint32_t BKP25R;          /*!< Ofs=180, W=4 backup register */
  __RW uint32_t BKP26R;          /*!< Ofs=184, W=4 backup register */
  __RW uint32_t BKP27R;          /*!< Ofs=188, W=4 backup register */
  __RW uint32_t BKP28R;          /*!< Ofs=192, W=4 backup register */
  __RW uint32_t BKP29R;          /*!< Ofs=196, W=4 backup register */
  __RW uint32_t BKP30R;          /*!< Ofs=200, W=4 backup register */
  __RW uint32_t BKP31R;          /*!< Ofs=204, W=4 backup register */
}  RTC_Type; /* W=208=0xD0 */
typedef struct WWDG_s { /*!< peripheral group WWDG */
  __RW struct WWDG_CR_s         CR;              /*!< Ofs=  0, W=4 Control register */
  __RW struct WWDG_CFR_s        CFR;             /*!< Ofs=  4, W=4 Configuration register */
  __RW uint32_t SR;              /*!< Ofs=  8, W=4 Status register */
}  WWDG_Type; /* W=12=0xC */
typedef struct IWDG_s { /*!< peripheral group IWDG */
  __WO uint32_t KR;              /*!< Ofs=  0, W=4 Key register */
  __RW uint32_t PR;              /*!< Ofs=  4, W=4 Prescaler register */
  __RW uint32_t RLR;             /*!< Ofs=  8, W=4 Reload register */
  __RO struct IWDG_SR_s         SR;              /*!< Ofs= 12, W=4 Status register */
  __RW uint32_t WINR;            /*!< Ofs= 16, W=4 Window register */
}  IWDG_Type; /* W=20=0x14 */
typedef struct USART_s { /*!< peripheral group USART */
  __RW struct USART_CR1_s       CR1;             /*!< Ofs=  0, W=4 Control register 1 */
  __RW struct USART_CR2_s       CR2;             /*!< Ofs=  4, W=4 Control register 2 */
  __RW struct USART_CR3_s       CR3;             /*!< Ofs=  8, W=4 Control register 3 */
  __RW uint32_t BRR;             /*!< Ofs= 12, W=4 Baud rate register */
  __RW struct USART_GTPR_s      GTPR;            /*!< Ofs= 16, W=4 Guard time and prescaler register */
  __RW struct USART_RTOR_s      RTOR;            /*!< Ofs= 20, W=4 Receiver timeout register */
  __WO struct USART_RQR_s       RQR;             /*!< Ofs= 24, W=4 Request register */
  __RO struct USART_ISR_s       ISR;             /*!< Ofs= 28, W=4 Interrupt & status register */
  __WO struct USART_ICR_s       ICR;             /*!< Ofs= 32, W=4 Interrupt flag clear register */
  __RO uint32_t RDR;             /*!< Ofs= 36, W=4 Receive data register */
  __RW uint32_t TDR;             /*!< Ofs= 40, W=4 Transmit data register */
}  USART_Type; /* W=44=0x2C */
typedef struct I2C_s { /*!< peripheral group I2C */
  __RW struct I2C_CR1_s         CR1;             /*!< Ofs=  0, W=4 Control register 1 */
  __RW struct I2C_CR2_s         CR2;             /*!< Ofs=  4, W=4 Control register 2 */
  __RW struct I2C_OAR1_s        OAR1;            /*!< Ofs=  8, W=4 Own address register 1 */
  __RW struct I2C_OAR2_s        OAR2;            /*!< Ofs= 12, W=4 Own address register 2 */
  __RW struct I2C_TIMINGR_s     TIMINGR;         /*!< Ofs= 16, W=4 Timing register */
  __RW struct I2C_TIMEOUTR_s    TIMEOUTR;        /*!< Ofs= 20, W=4 Status register 1 */
  __RW struct I2C_ISR_s         ISR;             /*!< Ofs= 24, W=4 Interrupt and Status register */
  __WO struct I2C_ICR_s         ICR;             /*!< Ofs= 28, W=4 Interrupt clear register */
  __RO uint32_t PECR;            /*!< Ofs= 32, W=4 PEC register */
  __RO uint32_t RXDR;            /*!< Ofs= 36, W=4 Receive data register */
  __RW uint32_t TXDR;            /*!< Ofs= 40, W=4 Transmit data register */
}  I2C_Type; /* W=44=0x2C */
typedef struct CRS_s { /*!< peripheral group CRS */
  __RW struct CRS_CR_s          CR;              /*!< Ofs=  0, W=4 control register */
  __RW struct CRS_CFGR_s        CFGR;            /*!< Ofs=  4, W=4 configuration register */
  __RO struct CRS_ISR_s         ISR;             /*!< Ofs=  8, W=4 interrupt and status register */
  __RW struct CRS_ICR_s         ICR;             /*!< Ofs= 12, W=4 interrupt flag clear register */
}  CRS_Type; /* W=16=0x10 */
typedef struct CAN_s { /*!< peripheral group CAN */
  __RW struct CAN_MCR_s         MCR;             /*!< Ofs=  0, W=4 master control register */
  __RW struct CAN_MSR_s         MSR;             /*!< Ofs=  4, W=4 master status register */
  __RW struct CAN_TSR_s         TSR;             /*!< Ofs=  8, W=4 transmit status register */
  __RW struct CAN_RF0R_s        RF0R;            /*!< Ofs= 12, W=4 receive FIFO 0 register */
  __RW struct CAN_RF1R_s        RF1R;            /*!< Ofs= 16, W=4 receive FIFO 1 register */
  __RW struct CAN_IER_s         IER;             /*!< Ofs= 20, W=4 interrupt enable register */
  __RW struct CAN_ESR_s         ESR;             /*!< Ofs= 24, W=4 interrupt enable register */
  __RW struct CAN_BTR_s         BTR;             /*!< Ofs= 28, W=4 bit timing register */
       uint32_t UNUSED0[88];
  __RW struct CAN_TI0R_s        TI0R;            /*!< Ofs=384, W=4 TX mailbox identifier register */
  __RW struct CAN_TDT0R_s       TDT0R;           /*!< Ofs=388, W=4 mailbox data length control and time stamp register */
  __RW struct CAN_TDL0R_s       TDL0R;           /*!< Ofs=392, W=4 mailbox data low register */
  __RW struct CAN_TDH0R_s       TDH0R;           /*!< Ofs=396, W=4 mailbox data high register */
  __RW struct CAN_TI1R_s        TI1R;            /*!< Ofs=400, W=4 mailbox identifier register */
  __RW struct CAN_TDT1R_s       TDT1R;           /*!< Ofs=404, W=4 mailbox data length control and time stamp register */
  __RW struct CAN_TDL1R_s       TDL1R;           /*!< Ofs=408, W=4 mailbox data low register */
  __RW struct CAN_TDH1R_s       TDH1R;           /*!< Ofs=412, W=4 mailbox data high register */
  __RW struct CAN_TI2R_s        TI2R;            /*!< Ofs=416, W=4 mailbox identifier register */
  __RW struct CAN_TDT2R_s       TDT2R;           /*!< Ofs=420, W=4 mailbox data length control and time stamp register */
  __RW struct CAN_TDL2R_s       TDL2R;           /*!< Ofs=424, W=4 mailbox data low register */
  __RW struct CAN_TDH2R_s       TDH2R;           /*!< Ofs=428, W=4 mailbox data high register */
  __RO struct CAN_RI0R_s        RI0R;            /*!< Ofs=432, W=4 receive FIFO mailbox identifier register */
  __RO struct CAN_RDT0R_s       RDT0R;           /*!< Ofs=436, W=4 mailbox data high register */
  __RO struct CAN_RDL0R_s       RDL0R;           /*!< Ofs=440, W=4 mailbox data high register */
  __RO struct CAN_RDH0R_s       RDH0R;           /*!< Ofs=444, W=4 receive FIFO mailbox data high register */
  __RO struct CAN_RI1R_s        RI1R;            /*!< Ofs=448, W=4 mailbox data high register */
  __RO struct CAN_RDT1R_s       RDT1R;           /*!< Ofs=452, W=4 mailbox data high register */
  __RO struct CAN_RDL1R_s       RDL1R;           /*!< Ofs=456, W=4 mailbox data high register */
  __RO struct CAN_RDH1R_s       RDH1R;           /*!< Ofs=460, W=4 mailbox data high register */
       uint32_t UNUSED1[12];
  __RW uint32_t FMR;             /*!< Ofs=512, W=4 filter master register */
  __RW struct CAN_FM1R_s        FM1R;            /*!< Ofs=516, W=4 filter mode register */
       uint32_t UNUSED2;
  __RW struct CAN_FS1R_s        FS1R;            /*!< Ofs=524, W=4 filter scale register */
       uint32_t UNUSED3;
  __RW struct CAN_FFA1R_s       FFA1R;           /*!< Ofs=532, W=4 filter FIFO assignment register */
       uint32_t UNUSED4;
  __RW struct CAN_FA1R_s        FA1R;            /*!< Ofs=540, W=4 filter activation register */
       uint32_t UNUSED5[8];
  __RW struct CAN_F0R1_s        F0R1;            /*!< Ofs=576, W=4 Filter bank 0 register 1 */
  __RW struct CAN_F0R2_s        F0R2;            /*!< Ofs=580, W=4 Filter bank 0 register 2 */
  __RW struct CAN_F1R1_s        F1R1;            /*!< Ofs=584, W=4 Filter bank 1 register 1 */
  __RW struct CAN_F1R2_s        F1R2;            /*!< Ofs=588, W=4 Filter bank 1 register 2 */
  __RW struct CAN_F2R1_s        F2R1;            /*!< Ofs=592, W=4 Filter bank 2 register 1 */
  __RW struct CAN_F2R2_s        F2R2;            /*!< Ofs=596, W=4 Filter bank 2 register 2 */
  __RW struct CAN_F3R1_s        F3R1;            /*!< Ofs=600, W=4 Filter bank 3 register 1 */
  __RW struct CAN_F3R2_s        F3R2;            /*!< Ofs=604, W=4 Filter bank 3 register 2 */
  __RW struct CAN_F4R1_s        F4R1;            /*!< Ofs=608, W=4 Filter bank 4 register 1 */
  __RW struct CAN_F4R2_s        F4R2;            /*!< Ofs=612, W=4 Filter bank 4 register 2 */
  __RW struct CAN_F5R1_s        F5R1;            /*!< Ofs=616, W=4 Filter bank 5 register 1 */
  __RW struct CAN_F5R2_s        F5R2;            /*!< Ofs=620, W=4 Filter bank 5 register 2 */
  __RW struct CAN_F6R1_s        F6R1;            /*!< Ofs=624, W=4 Filter bank 6 register 1 */
  __RW struct CAN_F6R2_s        F6R2;            /*!< Ofs=628, W=4 Filter bank 6 register 2 */
  __RW struct CAN_F7R1_s        F7R1;            /*!< Ofs=632, W=4 Filter bank 7 register 1 */
  __RW struct CAN_F7R2_s        F7R2;            /*!< Ofs=636, W=4 Filter bank 7 register 2 */
  __RW struct CAN_F8R1_s        F8R1;            /*!< Ofs=640, W=4 Filter bank 8 register 1 */
  __RW struct CAN_F8R2_s        F8R2;            /*!< Ofs=644, W=4 Filter bank 8 register 2 */
  __RW struct CAN_F9R1_s        F9R1;            /*!< Ofs=648, W=4 Filter bank 9 register 1 */
  __RW struct CAN_F9R2_s        F9R2;            /*!< Ofs=652, W=4 Filter bank 9 register 2 */
  __RW struct CAN_F10R1_s       F10R1;           /*!< Ofs=656, W=4 Filter bank 10 register 1 */
  __RW struct CAN_F10R2_s       F10R2;           /*!< Ofs=660, W=4 Filter bank 10 register 2 */
  __RW struct CAN_F11R1_s       F11R1;           /*!< Ofs=664, W=4 Filter bank 11 register 1 */
  __RW struct CAN_F11R2_s       F11R2;           /*!< Ofs=668, W=4 Filter bank 11 register 2 */
  __RW struct CAN_F12R1_s       F12R1;           /*!< Ofs=672, W=4 Filter bank 4 register 1 */
  __RW struct CAN_F12R2_s       F12R2;           /*!< Ofs=676, W=4 Filter bank 12 register 2 */
  __RW struct CAN_F13R1_s       F13R1;           /*!< Ofs=680, W=4 Filter bank 13 register 1 */
  __RW struct CAN_F13R2_s       F13R2;           /*!< Ofs=684, W=4 Filter bank 13 register 2 */
  __RW struct CAN_F14R1_s       F14R1;           /*!< Ofs=688, W=4 Filter bank 14 register 1 */
  __RW struct CAN_F14R2_s       F14R2;           /*!< Ofs=692, W=4 Filter bank 14 register 2 */
  __RW struct CAN_F15R1_s       F15R1;           /*!< Ofs=696, W=4 Filter bank 15 register 1 */
  __RW struct CAN_F15R2_s       F15R2;           /*!< Ofs=700, W=4 Filter bank 15 register 2 */
  __RW struct CAN_F16R1_s       F16R1;           /*!< Ofs=704, W=4 Filter bank 16 register 1 */
  __RW struct CAN_F16R2_s       F16R2;           /*!< Ofs=708, W=4 Filter bank 16 register 2 */
  __RW struct CAN_F17R1_s       F17R1;           /*!< Ofs=712, W=4 Filter bank 17 register 1 */
  __RW struct CAN_F17R2_s       F17R2;           /*!< Ofs=716, W=4 Filter bank 17 register 2 */
  __RW struct CAN_F18R1_s       F18R1;           /*!< Ofs=720, W=4 Filter bank 18 register 1 */
  __RW struct CAN_F18R2_s       F18R2;           /*!< Ofs=724, W=4 Filter bank 18 register 2 */
  __RW struct CAN_F19R1_s       F19R1;           /*!< Ofs=728, W=4 Filter bank 19 register 1 */
  __RW struct CAN_F19R2_s       F19R2;           /*!< Ofs=732, W=4 Filter bank 19 register 2 */
  __RW struct CAN_F20R1_s       F20R1;           /*!< Ofs=736, W=4 Filter bank 20 register 1 */
  __RW struct CAN_F20R2_s       F20R2;           /*!< Ofs=740, W=4 Filter bank 20 register 2 */
  __RW struct CAN_F21R1_s       F21R1;           /*!< Ofs=744, W=4 Filter bank 21 register 1 */
  __RW struct CAN_F21R2_s       F21R2;           /*!< Ofs=748, W=4 Filter bank 21 register 2 */
  __RW struct CAN_F22R1_s       F22R1;           /*!< Ofs=752, W=4 Filter bank 22 register 1 */
  __RW struct CAN_F22R2_s       F22R2;           /*!< Ofs=756, W=4 Filter bank 22 register 2 */
  __RW struct CAN_F23R1_s       F23R1;           /*!< Ofs=760, W=4 Filter bank 23 register 1 */
  __RW struct CAN_F23R2_s       F23R2;           /*!< Ofs=764, W=4 Filter bank 23 register 2 */
  __RW struct CAN_F24R1_s       F24R1;           /*!< Ofs=768, W=4 Filter bank 24 register 1 */
  __RW struct CAN_F24R2_s       F24R2;           /*!< Ofs=772, W=4 Filter bank 24 register 2 */
  __RW struct CAN_F25R1_s       F25R1;           /*!< Ofs=776, W=4 Filter bank 25 register 1 */
  __RW struct CAN_F25R2_s       F25R2;           /*!< Ofs=780, W=4 Filter bank 25 register 2 */
  __RW struct CAN_F26R1_s       F26R1;           /*!< Ofs=784, W=4 Filter bank 26 register 1 */
  __RW struct CAN_F26R2_s       F26R2;           /*!< Ofs=788, W=4 Filter bank 26 register 2 */
  __RW struct CAN_F27R1_s       F27R1;           /*!< Ofs=792, W=4 Filter bank 27 register 1 */
  __RW struct CAN_F27R2_s       F27R2;           /*!< Ofs=796, W=4 Filter bank 27 register 2 */
}  CAN_Type; /* W=800=0x320 */
typedef struct USB_s { /*!< peripheral group USB */
  __RW struct USB_EP0R_s        EP0R;            /*!< Ofs=  0, W=4 endpoint 0 register */
  __RW struct USB_EP1R_s        EP1R;            /*!< Ofs=  4, W=4 endpoint 1 register */
  __RW struct USB_EP2R_s        EP2R;            /*!< Ofs=  8, W=4 endpoint 2 register */
  __RW struct USB_EP3R_s        EP3R;            /*!< Ofs= 12, W=4 endpoint 3 register */
  __RW struct USB_EP4R_s        EP4R;            /*!< Ofs= 16, W=4 endpoint 4 register */
  __RW struct USB_EP5R_s        EP5R;            /*!< Ofs= 20, W=4 endpoint 5 register */
  __RW struct USB_EP6R_s        EP6R;            /*!< Ofs= 24, W=4 endpoint 6 register */
  __RW struct USB_EP7R_s        EP7R;            /*!< Ofs= 28, W=4 endpoint 7 register */
       uint32_t UNUSED0[8];
  __RW struct USB_CNTR_s        CNTR;            /*!< Ofs= 64, W=4 control register */
  __RW struct USB_ISTR_s        ISTR;            /*!< Ofs= 68, W=4 interrupt status register */
  __RO struct USB_FNR_s         FNR;             /*!< Ofs= 72, W=4 frame number register */
  __RW struct USB_DADDR_s       DADDR;           /*!< Ofs= 76, W=4 device address */
  __RW struct USB_BTABLE_s      BTABLE;          /*!< Ofs= 80, W=4 Buffer table address */
  __RW struct USB_LPMCSR_s      LPMCSR;          /*!< Ofs= 84, W=4 LPM control and status register */
  __RW struct USB_BCDR_s        BCDR;            /*!< Ofs= 88, W=4 Battery charging detector */
}  USB_Type; /* W=92=0x5C */
typedef struct PWR_s { /*!< peripheral group PWR */
  __RW struct PWR_CR1_s         CR1;             /*!< Ofs=  0, W=4 Power control register 1 */
  __RW struct PWR_CR2_s         CR2;             /*!< Ofs=  4, W=4 Power control register 2 */
  __RW struct PWR_CR3_s         CR3;             /*!< Ofs=  8, W=4 Power control register 3 */
  __RW struct PWR_CR4_s         CR4;             /*!< Ofs= 12, W=4 Power control register 4 */
  __RO struct PWR_SR1_s         SR1;             /*!< Ofs= 16, W=4 Power status register 1 */
  __RO struct PWR_SR2_s         SR2;             /*!< Ofs= 20, W=4 Power status register 2 */
  __WO struct PWR_SCR_s         SCR;             /*!< Ofs= 24, W=4 Power status clear register */
       uint32_t UNUSED0;
  __RW struct PWR_PUCRA_s       PUCRA;           /*!< Ofs= 32, W=4 Power Port A pull-up control register */
  __RW struct PWR_PDCRA_s       PDCRA;           /*!< Ofs= 36, W=4 Power Port A pull-down control register */
  __RW struct PWR_PUCRB_s       PUCRB;           /*!< Ofs= 40, W=4 Power Port B pull-up control register */
  __RW struct PWR_PDCRB_s       PDCRB;           /*!< Ofs= 44, W=4 Power Port B pull-down control register */
  __RW struct PWR_PUCRC_s       PUCRC;           /*!< Ofs= 48, W=4 Power Port C pull-up control register */
  __RW struct PWR_PDCRC_s       PDCRC;           /*!< Ofs= 52, W=4 Power Port C pull-down control register */
  __RW struct PWR_PUCRD_s       PUCRD;           /*!< Ofs= 56, W=4 Power Port D pull-up control register */
  __RW struct PWR_PDCRD_s       PDCRD;           /*!< Ofs= 60, W=4 Power Port D pull-down control register */
  __RW struct PWR_PUCRE_s       PUCRE;           /*!< Ofs= 64, W=4 Power Port E pull-up control register */
  __RW struct PWR_PDCRE_s       PDCRE;           /*!< Ofs= 68, W=4 Power Port E pull-down control register */
  __RW struct PWR_PUCRF_s       PUCRF;           /*!< Ofs= 72, W=4 Power Port F pull-up control register */
  __RW struct PWR_PDCRF_s       PDCRF;           /*!< Ofs= 76, W=4 Power Port F pull-down control register */
  __RW struct PWR_PUCRG_s       PUCRG;           /*!< Ofs= 80, W=4 Power Port G pull-up control register */
  __RW struct PWR_PDCRG_s       PDCRG;           /*!< Ofs= 84, W=4 Power Port G pull-down control register */
  __RW struct PWR_PUCRH_s       PUCRH;           /*!< Ofs= 88, W=4 Power Port H pull-up control register */
  __RW struct PWR_PDCRH_s       PDCRH;           /*!< Ofs= 92, W=4 Power Port H pull-down control register */
}  PWR_Type; /* W=96=0x60 */
typedef struct DAC_s { /*!< peripheral group DAC */
  __RW struct DAC_CR_s          CR;              /*!< Ofs=  0, W=4 control register */
  __WO struct DAC_SWTRIGR_s     SWTRIGR;         /*!< Ofs=  4, W=4 software trigger register */
  __RW uint32_t DHR12R1;         /*!< Ofs=  8, W=4 channel1 12-bit right-aligned data holding register */
  __RW struct DAC_DHR12L1_s     DHR12L1;         /*!< Ofs= 12, W=4 channel1 12-bit left-aligned data holding register */
  __RW uint32_t DHR8R1;          /*!< Ofs= 16, W=4 channel1 8-bit right-aligned data holding register */
  __RW uint32_t DHR12R2;         /*!< Ofs= 20, W=4 channel2 12-bit right aligned data holding register */
  __RW struct DAC_DHR12L2_s     DHR12L2;         /*!< Ofs= 24, W=4 channel2 12-bit left aligned data holding register */
  __RW uint32_t DHR8R2;          /*!< Ofs= 28, W=4 channel2 8-bit right-aligned data holding register */
  __RW struct DAC_DHR12RD_s     DHR12RD;         /*!< Ofs= 32, W=4 Dual DAC 12-bit right-aligned data holding register */
  __RW struct DAC_DHR12LD_s     DHR12LD;         /*!< Ofs= 36, W=4 DUAL DAC 12-bit left aligned data holding register */
  __RW struct DAC_DHR8RD_s      DHR8RD;          /*!< Ofs= 40, W=4 DUAL DAC 8-bit right aligned data holding register */
  __RO uint32_t DOR1;            /*!< Ofs= 44, W=4 channel1 data output register */
  __RO uint32_t DOR2;            /*!< Ofs= 48, W=4 channel2 data output register */
  __RW struct DAC_SR_s          SR;              /*!< Ofs= 52, W=4 status register */
  __RW struct DAC_CCR_s         CCR;             /*!< Ofs= 56, W=4 calibration control register */
  __RW struct DAC_MCR_s         MCR;             /*!< Ofs= 60, W=4 mode control register */
  __RW uint32_t SHSR1;           /*!< Ofs= 64, W=4 Sample and Hold sample time register 1 */
  __RW uint32_t SHSR2;           /*!< Ofs= 68, W=4 Sample and Hold sample time register 2 */
  __RW struct DAC_SHHR_s        SHHR;            /*!< Ofs= 72, W=4 Sample and Hold hold time register */
  __RW struct DAC_SHRR_s        SHRR;            /*!< Ofs= 76, W=4 Sample and Hold refresh time register */
}  DAC_Type; /* W=80=0x50 */
typedef struct OPAMP_s { /*!< peripheral group OPAMP */
  __RW struct OPAMP_OPAMP1_CSR_s OPAMP1_CSR;      /*!< Ofs=  0, W=4 OPAMP1 control/status register */
  __RW struct OPAMP_OPAMP1_OTR_s OPAMP1_OTR;      /*!< Ofs=  4, W=4 OPAMP1 offset trimming register in normal mode */
  __RW struct OPAMP_OPAMP1_LPOTR_s OPAMP1_LPOTR;    /*!< Ofs=  8, W=4 OPAMP1 offset trimming register in low-power mode */
       uint32_t UNUSED0;
  __RW struct OPAMP_OPAMP2_CSR_s OPAMP2_CSR;      /*!< Ofs= 16, W=4 OPAMP2 control/status register */
  __RW struct OPAMP_OPAMP2_OTR_s OPAMP2_OTR;      /*!< Ofs= 20, W=4 OPAMP2 offset trimming register in normal mode */
  __RW struct OPAMP_OPAMP2_LPOTR_s OPAMP2_LPOTR;    /*!< Ofs= 24, W=4 OPAMP2 offset trimming register in low-power mode */
}  OPAMP_Type; /* W=28=0x1C */
typedef struct LPTIM_s { /*!< peripheral group LPTIM */
  __RO struct LPTIM_ISR_s       ISR;             /*!< Ofs=  0, W=4 Interrupt and Status Register */
  __WO struct LPTIM_ICR_s       ICR;             /*!< Ofs=  4, W=4 Interrupt Clear Register */
  __RW struct LPTIM_IER_s       IER;             /*!< Ofs=  8, W=4 Interrupt Enable Register */
  __RW struct LPTIM_CFGR_s      CFGR;            /*!< Ofs= 12, W=4 Configuration Register */
  __RW struct LPTIM_CR_s        CR;              /*!< Ofs= 16, W=4 Control Register */
  __RW uint32_t CMP;             /*!< Ofs= 20, W=4 Compare Register */
  __RW uint32_t ARR;             /*!< Ofs= 24, W=4 Autoreload Register */
  __RO uint32_t CNT;             /*!< Ofs= 28, W=4 Counter Register */
}  LPTIM_Type; /* W=32=0x20 */
typedef struct SWPMI_s { /*!< peripheral group SWPMI */
  __RW struct SWPMI_CR_s        CR;              /*!< Ofs=  0, W=4 SWPMI Configuration/Control register */
  __RW uint32_t BRR;             /*!< Ofs=  4, W=4 SWPMI Bitrate register */
       uint32_t UNUSED0;
  __RO struct SWPMI_ISR_s       ISR;             /*!< Ofs= 12, W=4 SWPMI Interrupt and Status register */
  __WO struct SWPMI_ICR_s       ICR;             /*!< Ofs= 16, W=4 SWPMI Interrupt Flag Clear register */
  __RW struct SWPMI_IER_s       IER;             /*!< Ofs= 20, W=4 SWPMI Interrupt Enable register */
  __RO uint32_t RFL;             /*!< Ofs= 24, W=4 SWPMI Receive Frame Length register */
  __WO uint32_t TDR;             /*!< Ofs= 28, W=4 SWPMI Transmit data register */
  __RO uint32_t RDR;             /*!< Ofs= 32, W=4 SWPMI Receive data register */
}  SWPMI_Type; /* W=36=0x24 */
typedef struct SYSCFG_s { /*!< peripheral group SYSCFG */
  __RW struct SYSCFG_MEMRMP_s   MEMRMP;          /*!< Ofs=  0, W=4 memory remap register */
  __RW struct SYSCFG_CFGR1_s    CFGR1;           /*!< Ofs=  4, W=4 configuration register 1 */
  __RW struct SYSCFG_EXTICR1_s  EXTICR1;         /*!< Ofs=  8, W=4 external interrupt configuration register 1 */
  __RW struct SYSCFG_EXTICR2_s  EXTICR2;         /*!< Ofs= 12, W=4 external interrupt configuration register 2 */
  __RW struct SYSCFG_EXTICR3_s  EXTICR3;         /*!< Ofs= 16, W=4 external interrupt configuration register 3 */
  __RW struct SYSCFG_EXTICR4_s  EXTICR4;         /*!< Ofs= 20, W=4 external interrupt configuration register 4 */
  __RW struct SYSCFG_SCSR_s     SCSR;            /*!< Ofs= 24, W=4 SCSR */
  __RW struct SYSCFG_CFGR2_s    CFGR2;           /*!< Ofs= 28, W=4 CFGR2 */
  __WO struct SYSCFG_SWPR_s     SWPR;            /*!< Ofs= 32, W=4 SWPR */
  __WO uint32_t SKR;             /*!< Ofs= 36, W=4 SKR */
}  SYSCFG_Type; /* W=40=0x28 */
typedef struct VREF_s { /*!< peripheral group VREF */
  __RW struct VREF_CSR_s        CSR;             /*!< Ofs=  0, W=4 VREF control and status register */
  __RW uint32_t CCR;             /*!< Ofs=  4, W=4 calibration control register */
}  VREF_Type; /* W=8=0x8 */
typedef struct COMP_s { /*!< peripheral group COMP */
  __RW struct COMP_COMP1_CSR_s  COMP1_CSR;       /*!< Ofs=  0, W=4 Comparator 1 control and status register */
  __RW struct COMP_COMP2_CSR_s  COMP2_CSR;       /*!< Ofs=  4, W=4 Comparator 2 control and status register */
}  COMP_Type; /* W=8=0x8 */
typedef struct EXTI_s { /*!< peripheral group EXTI */
  __RW struct EXTI_IMR1_s       IMR1;            /*!< Ofs=  0, W=4 Interrupt mask register */
  __RW struct EXTI_EMR1_s       EMR1;            /*!< Ofs=  4, W=4 Event mask register */
  __RW struct EXTI_RTSR1_s      RTSR1;           /*!< Ofs=  8, W=4 Rising Trigger selection register */
  __RW struct EXTI_FTSR1_s      FTSR1;           /*!< Ofs= 12, W=4 Falling Trigger selection register */
  __RW struct EXTI_SWIER1_s     SWIER1;          /*!< Ofs= 16, W=4 Software interrupt event register */
  __RW struct EXTI_PR1_s        PR1;             /*!< Ofs= 20, W=4 Pending register */
       uint32_t UNUSED0[2];
  __RW struct EXTI_IMR2_s       IMR2;            /*!< Ofs= 32, W=4 Interrupt mask register */
  __RW struct EXTI_EMR2_s       EMR2;            /*!< Ofs= 36, W=4 Event mask register */
  __RW struct EXTI_RTSR2_s      RTSR2;           /*!< Ofs= 40, W=4 Rising Trigger selection register */
  __RW struct EXTI_FTSR2_s      FTSR2;           /*!< Ofs= 44, W=4 Falling Trigger selection register */
  __RW struct EXTI_SWIER2_s     SWIER2;          /*!< Ofs= 48, W=4 Software interrupt event register */
  __RW struct EXTI_PR2_s        PR2;             /*!< Ofs= 52, W=4 Pending register */
}  EXTI_Type; /* W=56=0x38 */
typedef struct Firewall_s { /*!< peripheral group Firewall */
  __RW struct Firewall_CSSA_s   CSSA;            /*!< Ofs=  0, W=4 Code segment start address */
  __RW struct Firewall_CSL_s    CSL;             /*!< Ofs=  4, W=4 Code segment length */
  __RW struct Firewall_NVDSSA_s NVDSSA;          /*!< Ofs=  8, W=4 Non-volatile data segment start address */
  __RW struct Firewall_NVDSL_s  NVDSL;           /*!< Ofs= 12, W=4 Non-volatile data segment length */
  __RW struct Firewall_VDSSA_s  VDSSA;           /*!< Ofs= 16, W=4 Volatile data segment start address */
  __RW struct Firewall_VDSL_s   VDSL;            /*!< Ofs= 20, W=4 Volatile data segment length */
       uint32_t UNUSED0[2];
  __RW struct Firewall_CR_s     CR;              /*!< Ofs= 32, W=4 Configuration register */
}  Firewall_Type; /* W=36=0x24 */
typedef struct SDIO_s { /*!< peripheral group SDIO */
  __RW uint32_t POWER;           /*!< Ofs=  0, W=4 power control register */
  __RW struct SDIO_CLKCR_s      CLKCR;           /*!< Ofs=  4, W=4 SDI clock control register */
  __RW uint32_t ARG;             /*!< Ofs=  8, W=4 argument register */
  __RW struct SDIO_CMD_s        CMD;             /*!< Ofs= 12, W=4 command register */
  __RO uint32_t RESPCMD;         /*!< Ofs= 16, W=4 command response register */
  __RO uint32_t RESP1;           /*!< Ofs= 20, W=4 response 1..4 register */
  __RO uint32_t RESP2;           /*!< Ofs= 24, W=4 response 1..4 register */
  __RO uint32_t RESP3;           /*!< Ofs= 28, W=4 response 1..4 register */
  __RO uint32_t RESP4;           /*!< Ofs= 32, W=4 response 1..4 register */
  __RW uint32_t DTIMER;          /*!< Ofs= 36, W=4 data timer register */
  __RW uint32_t DLEN;            /*!< Ofs= 40, W=4 data length register */
  __RW struct SDIO_DCTRL_s      DCTRL;           /*!< Ofs= 44, W=4 data control register */
  __RO uint32_t DCOUNT;          /*!< Ofs= 48, W=4 data counter register */
  __RO struct SDIO_STA_s        STA;             /*!< Ofs= 52, W=4 status register */
  __RW struct SDIO_ICR_s        ICR;             /*!< Ofs= 56, W=4 interrupt clear register */
  __RW struct SDIO_MASK_s       MASK;            /*!< Ofs= 60, W=4 mask register */
       uint32_t UNUSED0[2];
  __RO uint32_t FIFOCNT;         /*!< Ofs= 72, W=4 FIFO counter register */
       uint32_t UNUSED1[13];
  __RW uint32_t FIFO;            /*!< Ofs=128, W=4 data FIFO register */
}  SDIO_Type; /* W=132=0x84 */
typedef struct SPI_s { /*!< peripheral group SPI */
  __RW struct SPI_CR1_s         CR1;             /*!< Ofs=  0, W=4 control register 1 */
  __RW struct SPI_CR2_s         CR2;             /*!< Ofs=  4, W=4 control register 2 */
  __RW struct SPI_SR_s          SR;              /*!< Ofs=  8, W=4 status register */
  __RW uint32_t DR;              /*!< Ofs= 12, W=4 data register */
  __RW uint32_t CRCPR;           /*!< Ofs= 16, W=4 CRC polynomial register */
  __RO uint32_t RXCRCR;          /*!< Ofs= 20, W=4 RX CRC register */
  __RO uint32_t TXCRCR;          /*!< Ofs= 24, W=4 TX CRC register */
}  SPI_Type; /* W=28=0x1C */
typedef struct SAI_s { /*!< peripheral group SAI */
       uint32_t UNUSED0;
  __RW struct SAI_ACR1_s        ACR1;            /*!< Ofs=  4, W=4 AConfiguration register 1 */
  __RW struct SAI_ACR2_s        ACR2;            /*!< Ofs=  8, W=4 AConfiguration register 2 */
  __RW struct SAI_AFRCR_s       AFRCR;           /*!< Ofs= 12, W=4 AFRCR */
  __RW struct SAI_ASLOTR_s      ASLOTR;          /*!< Ofs= 16, W=4 ASlot register */
  __RW struct SAI_AIM_s         AIM;             /*!< Ofs= 20, W=4 AInterrupt mask register2 */
  __RW struct SAI_ASR_s         ASR;             /*!< Ofs= 24, W=4 AStatus register */
  __RW struct SAI_ACLRFR_s      ACLRFR;          /*!< Ofs= 28, W=4 AClear flag register */
  __RW uint32_t ADR;             /*!< Ofs= 32, W=4 AData register */
  __RW struct SAI_BCR1_s        BCR1;            /*!< Ofs= 36, W=4 BConfiguration register 1 */
  __RW struct SAI_BCR2_s        BCR2;            /*!< Ofs= 40, W=4 BConfiguration register 2 */
  __RW struct SAI_BFRCR_s       BFRCR;           /*!< Ofs= 44, W=4 BFRCR */
  __RW struct SAI_BSLOTR_s      BSLOTR;          /*!< Ofs= 48, W=4 BSlot register */
  __RW struct SAI_BIM_s         BIM;             /*!< Ofs= 52, W=4 BInterrupt mask register2 */
  __RO struct SAI_BSR_s         BSR;             /*!< Ofs= 56, W=4 BStatus register */
  __WO struct SAI_BCLRFR_s      BCLRFR;          /*!< Ofs= 60, W=4 BClear flag register */
  __RW uint32_t BDR;             /*!< Ofs= 64, W=4 BData register */
}  SAI_Type; /* W=68=0x44 */
typedef struct DFSDM_s { /*!< peripheral group DFSDM */
  __RW struct DFSDM_CHCFG0R1_s  CHCFG0R1;        /*!< Ofs=  0, W=4 channel configuration y register */
  __RW struct DFSDM_CHCFG0R2_s  CHCFG0R2;        /*!< Ofs=  4, W=4 channel configuration y register */
  __RW struct DFSDM_AWSCD0R_s   AWSCD0R;         /*!< Ofs=  8, W=4 analog watchdog and short-circuit detector register */
  __RW uint32_t CHWDAT0R;        /*!< Ofs= 12, W=4 channel watchdog filter data register */
  __RW struct DFSDM_CHDATIN0R_s CHDATIN0R;       /*!< Ofs= 16, W=4 channel data input register */
       uint32_t UNUSED0[3];
  __RW struct DFSDM_CHCFG1R1_s  CHCFG1R1;        /*!< Ofs= 32, W=4 CHCFG1R1 */
  __RW struct DFSDM_CHCFG1R2_s  CHCFG1R2;        /*!< Ofs= 36, W=4 CHCFG1R2 */
  __RW struct DFSDM_AWSCD1R_s   AWSCD1R;         /*!< Ofs= 40, W=4 AWSCD1R */
  __RW uint32_t CHWDAT1R;        /*!< Ofs= 44, W=4 CHWDAT1R */
  __RW struct DFSDM_CHDATIN1R_s CHDATIN1R;       /*!< Ofs= 48, W=4 CHDATIN1R */
       uint32_t UNUSED1[3];
  __RW struct DFSDM_CHCFG2R1_s  CHCFG2R1;        /*!< Ofs= 64, W=4 CHCFG2R1 */
  __RW struct DFSDM_CHCFG2R2_s  CHCFG2R2;        /*!< Ofs= 68, W=4 CHCFG2R2 */
  __RW struct DFSDM_AWSCD2R_s   AWSCD2R;         /*!< Ofs= 72, W=4 AWSCD2R */
  __RW uint32_t CHWDAT2R;        /*!< Ofs= 76, W=4 CHWDAT2R */
  __RW struct DFSDM_CHDATIN2R_s CHDATIN2R;       /*!< Ofs= 80, W=4 CHDATIN2R */
       uint32_t UNUSED2[3];
  __RW struct DFSDM_CHCFG3R1_s  CHCFG3R1;        /*!< Ofs= 96, W=4 CHCFG3R1 */
  __RW struct DFSDM_CHCFG3R2_s  CHCFG3R2;        /*!< Ofs=100, W=4 CHCFG3R2 */
  __RW struct DFSDM_AWSCD3R_s   AWSCD3R;         /*!< Ofs=104, W=4 AWSCD3R */
  __RW uint32_t CHWDAT3R;        /*!< Ofs=108, W=4 CHWDAT3R */
  __RW struct DFSDM_CHDATIN3R_s CHDATIN3R;       /*!< Ofs=112, W=4 CHDATIN3R */
       uint32_t UNUSED3[3];
  __RW struct DFSDM_CHCFG4R1_s  CHCFG4R1;        /*!< Ofs=128, W=4 CHCFG4R1 */
  __RW struct DFSDM_CHCFG4R2_s  CHCFG4R2;        /*!< Ofs=132, W=4 CHCFG4R2 */
  __RW struct DFSDM_AWSCD4R_s   AWSCD4R;         /*!< Ofs=136, W=4 AWSCD4R */
  __RW uint32_t CHWDAT4R;        /*!< Ofs=140, W=4 CHWDAT4R */
  __RW struct DFSDM_CHDATIN4R_s CHDATIN4R;       /*!< Ofs=144, W=4 CHDATIN4R */
       uint32_t UNUSED4[3];
  __RW struct DFSDM_CHCFG5R1_s  CHCFG5R1;        /*!< Ofs=160, W=4 CHCFG5R1 */
  __RW struct DFSDM_CHCFG5R2_s  CHCFG5R2;        /*!< Ofs=164, W=4 CHCFG5R2 */
  __RW struct DFSDM_AWSCD5R_s   AWSCD5R;         /*!< Ofs=168, W=4 AWSCD5R */
  __RW uint32_t CHWDAT5R;        /*!< Ofs=172, W=4 CHWDAT5R */
  __RW struct DFSDM_CHDATIN5R_s CHDATIN5R;       /*!< Ofs=176, W=4 CHDATIN5R */
       uint32_t UNUSED5[3];
  __RW struct DFSDM_CHCFG6R1_s  CHCFG6R1;        /*!< Ofs=192, W=4 CHCFG6R1 */
  __RW struct DFSDM_CHCFG6R2_s  CHCFG6R2;        /*!< Ofs=196, W=4 CHCFG6R2 */
  __RW struct DFSDM_AWSCD6R_s   AWSCD6R;         /*!< Ofs=200, W=4 AWSCD6R */
  __RW uint32_t CHWDAT6R;        /*!< Ofs=204, W=4 CHWDAT6R */
  __RW struct DFSDM_CHDATIN6R_s CHDATIN6R;       /*!< Ofs=208, W=4 CHDATIN6R */
       uint32_t UNUSED6[3];
  __RW struct DFSDM_CHCFG7R1_s  CHCFG7R1;        /*!< Ofs=224, W=4 CHCFG7R1 */
  __RW struct DFSDM_CHCFG7R2_s  CHCFG7R2;        /*!< Ofs=228, W=4 CHCFG7R2 */
  __RW struct DFSDM_AWSCD7R_s   AWSCD7R;         /*!< Ofs=232, W=4 AWSCD7R */
  __RW uint32_t CHWDAT7R;        /*!< Ofs=236, W=4 CHWDAT7R */
  __RW struct DFSDM_CHDATIN7R_s CHDATIN7R;       /*!< Ofs=240, W=4 CHDATIN7R */
       uint32_t UNUSED7[3];
  __RW struct DFSDM_DFSDM0_CR1_s DFSDM0_CR1;      /*!< Ofs=256, W=4 control register 1 */
  __RW struct DFSDM_DFSDM0_CR2_s DFSDM0_CR2;      /*!< Ofs=260, W=4 control register 2 */
  __RO struct DFSDM_DFSDM0_ISR_s DFSDM0_ISR;      /*!< Ofs=264, W=4 interrupt and status register */
  __RW struct DFSDM_DFSDM0_ICR_s DFSDM0_ICR;      /*!< Ofs=268, W=4 interrupt flag clear register */
  __RW uint32_t DFSDM0_JCHGR;    /*!< Ofs=272, W=4 injected channel group selection register */
  __RW struct DFSDM_DFSDM0_FCR_s DFSDM0_FCR;      /*!< Ofs=276, W=4 filter control register */
  __RO struct DFSDM_DFSDM0_JDATAR_s DFSDM0_JDATAR;   /*!< Ofs=280, W=4 data register for injected group */
  __RO struct DFSDM_DFSDM0_RDATAR_s DFSDM0_RDATAR;   /*!< Ofs=284, W=4 data register for the regular channel */
  __RW struct DFSDM_DFSDM0_AWHTR_s DFSDM0_AWHTR;    /*!< Ofs=288, W=4 analog watchdog high threshold register */
  __RW struct DFSDM_DFSDM0_AWLTR_s DFSDM0_AWLTR;    /*!< Ofs=292, W=4 analog watchdog low threshold register */
  __RO struct DFSDM_DFSDM0_AWSR_s DFSDM0_AWSR;     /*!< Ofs=296, W=4 analog watchdog status register */
  __RW struct DFSDM_DFSDM0_AWCFR_s DFSDM0_AWCFR;    /*!< Ofs=300, W=4 analog watchdog clear flag register */
  __RO struct DFSDM_DFSDM0_EXMAX_s DFSDM0_EXMAX;    /*!< Ofs=304, W=4 Extremes detector maximum register */
  __RO struct DFSDM_DFSDM0_EXMIN_s DFSDM0_EXMIN;    /*!< Ofs=308, W=4 Extremes detector minimum register */
  __RO struct DFSDM_DFSDM0_CNVTIMR_s DFSDM0_CNVTIMR;  /*!< Ofs=312, W=4 conversion timer register */
       uint32_t UNUSED8[49];
  __RW struct DFSDM_DFSDM1_CR1_s DFSDM1_CR1;      /*!< Ofs=512, W=4 control register 1 */
  __RW struct DFSDM_DFSDM1_CR2_s DFSDM1_CR2;      /*!< Ofs=516, W=4 control register 2 */
  __RO struct DFSDM_DFSDM1_ISR_s DFSDM1_ISR;      /*!< Ofs=520, W=4 interrupt and status register */
  __RW struct DFSDM_DFSDM1_ICR_s DFSDM1_ICR;      /*!< Ofs=524, W=4 interrupt flag clear register */
  __RW uint32_t DFSDM1_JCHGR;    /*!< Ofs=528, W=4 injected channel group selection register */
  __RW struct DFSDM_DFSDM1_FCR_s DFSDM1_FCR;      /*!< Ofs=532, W=4 filter control register */
  __RO struct DFSDM_DFSDM1_JDATAR_s DFSDM1_JDATAR;   /*!< Ofs=536, W=4 data register for injected group */
  __RO struct DFSDM_DFSDM1_RDATAR_s DFSDM1_RDATAR;   /*!< Ofs=540, W=4 data register for the regular channel */
  __RW struct DFSDM_DFSDM1_AWHTR_s DFSDM1_AWHTR;    /*!< Ofs=544, W=4 analog watchdog high threshold register */
  __RW struct DFSDM_DFSDM1_AWLTR_s DFSDM1_AWLTR;    /*!< Ofs=548, W=4 analog watchdog low threshold register */
  __RO struct DFSDM_DFSDM1_AWSR_s DFSDM1_AWSR;     /*!< Ofs=552, W=4 analog watchdog status register */
  __RW struct DFSDM_DFSDM1_AWCFR_s DFSDM1_AWCFR;    /*!< Ofs=556, W=4 analog watchdog clear flag register */
  __RO struct DFSDM_DFSDM1_EXMAX_s DFSDM1_EXMAX;    /*!< Ofs=560, W=4 Extremes detector maximum register */
  __RO struct DFSDM_DFSDM1_EXMIN_s DFSDM1_EXMIN;    /*!< Ofs=564, W=4 Extremes detector minimum register */
  __RO struct DFSDM_DFSDM1_CNVTIMR_s DFSDM1_CNVTIMR;  /*!< Ofs=568, W=4 conversion timer register */
       uint32_t UNUSED9[49];
  __RW struct DFSDM_DFSDM2_CR1_s DFSDM2_CR1;      /*!< Ofs=768, W=4 control register 1 */
  __RW struct DFSDM_DFSDM2_CR2_s DFSDM2_CR2;      /*!< Ofs=772, W=4 control register 2 */
  __RO struct DFSDM_DFSDM2_ISR_s DFSDM2_ISR;      /*!< Ofs=776, W=4 interrupt and status register */
  __RW struct DFSDM_DFSDM2_ICR_s DFSDM2_ICR;      /*!< Ofs=780, W=4 interrupt flag clear register */
  __RW uint32_t DFSDM2_JCHGR;    /*!< Ofs=784, W=4 injected channel group selection register */
  __RW struct DFSDM_DFSDM2_FCR_s DFSDM2_FCR;      /*!< Ofs=788, W=4 filter control register */
  __RO struct DFSDM_DFSDM2_JDATAR_s DFSDM2_JDATAR;   /*!< Ofs=792, W=4 data register for injected group */
  __RO struct DFSDM_DFSDM2_RDATAR_s DFSDM2_RDATAR;   /*!< Ofs=796, W=4 data register for the regular channel */
  __RW struct DFSDM_DFSDM2_AWHTR_s DFSDM2_AWHTR;    /*!< Ofs=800, W=4 analog watchdog high threshold register */
  __RW struct DFSDM_DFSDM2_AWLTR_s DFSDM2_AWLTR;    /*!< Ofs=804, W=4 analog watchdog low threshold register */
  __RO struct DFSDM_DFSDM2_AWSR_s DFSDM2_AWSR;     /*!< Ofs=808, W=4 analog watchdog status register */
  __RW struct DFSDM_DFSDM2_AWCFR_s DFSDM2_AWCFR;    /*!< Ofs=812, W=4 analog watchdog clear flag register */
  __RO struct DFSDM_DFSDM2_EXMAX_s DFSDM2_EXMAX;    /*!< Ofs=816, W=4 Extremes detector maximum register */
  __RO struct DFSDM_DFSDM2_EXMIN_s DFSDM2_EXMIN;    /*!< Ofs=820, W=4 Extremes detector minimum register */
  __RO struct DFSDM_DFSDM2_CNVTIMR_s DFSDM2_CNVTIMR;  /*!< Ofs=824, W=4 conversion timer register */
       uint32_t UNUSED10[49];
  __RW struct DFSDM_DFSDM3_CR1_s DFSDM3_CR1;      /*!< Ofs=1024, W=4 control register 1 */
  __RW struct DFSDM_DFSDM3_CR2_s DFSDM3_CR2;      /*!< Ofs=1028, W=4 control register 2 */
  __RO struct DFSDM_DFSDM3_ISR_s DFSDM3_ISR;      /*!< Ofs=1032, W=4 interrupt and status register */
  __RW struct DFSDM_DFSDM3_ICR_s DFSDM3_ICR;      /*!< Ofs=1036, W=4 interrupt flag clear register */
  __RW uint32_t DFSDM3_JCHGR;    /*!< Ofs=1040, W=4 injected channel group selection register */
  __RW struct DFSDM_DFSDM3_FCR_s DFSDM3_FCR;      /*!< Ofs=1044, W=4 filter control register */
  __RO struct DFSDM_DFSDM3_JDATAR_s DFSDM3_JDATAR;   /*!< Ofs=1048, W=4 data register for injected group */
  __RO struct DFSDM_DFSDM3_RDATAR_s DFSDM3_RDATAR;   /*!< Ofs=1052, W=4 data register for the regular channel */
  __RW struct DFSDM_DFSDM3_AWHTR_s DFSDM3_AWHTR;    /*!< Ofs=1056, W=4 analog watchdog high threshold register */
  __RW struct DFSDM_DFSDM3_AWLTR_s DFSDM3_AWLTR;    /*!< Ofs=1060, W=4 analog watchdog low threshold register */
  __RO struct DFSDM_DFSDM3_AWSR_s DFSDM3_AWSR;     /*!< Ofs=1064, W=4 analog watchdog status register */
  __RW struct DFSDM_DFSDM3_AWCFR_s DFSDM3_AWCFR;    /*!< Ofs=1068, W=4 analog watchdog clear flag register */
  __RO struct DFSDM_DFSDM3_EXMAX_s DFSDM3_EXMAX;    /*!< Ofs=1072, W=4 Extremes detector maximum register */
  __RO struct DFSDM_DFSDM3_EXMIN_s DFSDM3_EXMIN;    /*!< Ofs=1076, W=4 Extremes detector minimum register */
  __RO struct DFSDM_DFSDM3_CNVTIMR_s DFSDM3_CNVTIMR;  /*!< Ofs=1080, W=4 conversion timer register */
}  DFSDM_Type; /* W=1084=0x43C */
typedef struct DMA_s { /*!< peripheral group DMA */
  __RO struct DMA_ISR_s         ISR;             /*!< Ofs=  0, W=4 interrupt status register */
  __WO struct DMA_IFCR_s        IFCR;            /*!< Ofs=  4, W=4 interrupt flag clear register */
  __RW struct DMA_CCR1_s        CCR1;            /*!< Ofs=  8, W=4 channel x configuration register */
  __RW uint32_t CNDTR1;          /*!< Ofs= 12, W=4 channel x number of data register */
  __RW uint32_t CPAR1;           /*!< Ofs= 16, W=4 channel x peripheral address register */
  __RW uint32_t CMAR1;           /*!< Ofs= 20, W=4 channel x memory address register */
       uint32_t UNUSED0;
  __RW struct DMA_CCR2_s        CCR2;            /*!< Ofs= 28, W=4 channel x configuration register */
  __RW uint32_t CNDTR2;          /*!< Ofs= 32, W=4 channel x number of data register */
  __RW uint32_t CPAR2;           /*!< Ofs= 36, W=4 channel x peripheral address register */
  __RW uint32_t CMAR2;           /*!< Ofs= 40, W=4 channel x memory address register */
       uint32_t UNUSED1;
  __RW struct DMA_CCR3_s        CCR3;            /*!< Ofs= 48, W=4 channel x configuration register */
  __RW uint32_t CNDTR3;          /*!< Ofs= 52, W=4 channel x number of data register */
  __RW uint32_t CPAR3;           /*!< Ofs= 56, W=4 channel x peripheral address register */
  __RW uint32_t CMAR3;           /*!< Ofs= 60, W=4 channel x memory address register */
       uint32_t UNUSED2;
  __RW struct DMA_CCR4_s        CCR4;            /*!< Ofs= 68, W=4 channel x configuration register */
  __RW uint32_t CNDTR4;          /*!< Ofs= 72, W=4 channel x number of data register */
  __RW uint32_t CPAR4;           /*!< Ofs= 76, W=4 channel x peripheral address register */
  __RW uint32_t CMAR4;           /*!< Ofs= 80, W=4 channel x memory address register */
       uint32_t UNUSED3;
  __RW struct DMA_CCR5_s        CCR5;            /*!< Ofs= 88, W=4 channel x configuration register */
  __RW uint32_t CNDTR5;          /*!< Ofs= 92, W=4 channel x number of data register */
  __RW uint32_t CPAR5;           /*!< Ofs= 96, W=4 channel x peripheral address register */
  __RW uint32_t CMAR5;           /*!< Ofs=100, W=4 channel x memory address register */
       uint32_t UNUSED4;
  __RW struct DMA_CCR6_s        CCR6;            /*!< Ofs=108, W=4 channel x configuration register */
  __RW uint32_t CNDTR6;          /*!< Ofs=112, W=4 channel x number of data register */
  __RW uint32_t CPAR6;           /*!< Ofs=116, W=4 channel x peripheral address register */
  __RW uint32_t CMAR6;           /*!< Ofs=120, W=4 channel x memory address register */
       uint32_t UNUSED5;
  __RW struct DMA_CCR7_s        CCR7;            /*!< Ofs=128, W=4 channel x configuration register */
  __RW uint32_t CNDTR7;          /*!< Ofs=132, W=4 channel x number of data register */
  __RW uint32_t CPAR7;           /*!< Ofs=136, W=4 channel x peripheral address register */
  __RW uint32_t CMAR7;           /*!< Ofs=140, W=4 channel x memory address register */
       uint32_t UNUSED6[6];
  __RW struct DMA_CSELR_s       CSELR;           /*!< Ofs=168, W=4 channel selection register */
}  DMA_Type; /* W=172=0xAC */
typedef struct RCC_s { /*!< peripheral group RCC */
  __RW struct RCC_CR_s          CR;              /*!< Ofs=  0, W=4 Clock control register */
  __RW struct RCC_ICSCR_s       ICSCR;           /*!< Ofs=  4, W=4 Internal clock sources calibration register */
  __RW struct RCC_CFGR_s        CFGR;            /*!< Ofs=  8, W=4 Clock configuration register */
  __RW struct RCC_PLLCFGR_s     PLLCFGR;         /*!< Ofs= 12, W=4 PLL configuration register */
  __RW struct RCC_PLLSAI1CFGR_s PLLSAI1CFGR;     /*!< Ofs= 16, W=4 PLLSAI1 configuration register */
       uint32_t UNUSED0;
  __RW struct RCC_CIER_s        CIER;            /*!< Ofs= 24, W=4 Clock interrupt enable register */
  __RO struct RCC_CIFR_s        CIFR;            /*!< Ofs= 28, W=4 Clock interrupt flag register */
  __WO struct RCC_CICR_s        CICR;            /*!< Ofs= 32, W=4 Clock interrupt clear register */
       uint32_t UNUSED1;
  __RW struct RCC_AHB1RSTR_s    AHB1RSTR;        /*!< Ofs= 40, W=4 AHB1 peripheral reset register */
  __RW struct RCC_AHB2RSTR_s    AHB2RSTR;        /*!< Ofs= 44, W=4 AHB2 peripheral reset register */
  __RW struct RCC_AHB3RSTR_s    AHB3RSTR;        /*!< Ofs= 48, W=4 AHB3 peripheral reset register */
       uint32_t UNUSED2;
  __RW struct RCC_APB1RSTR1_s   APB1RSTR1;       /*!< Ofs= 56, W=4 APB1 peripheral reset register 1 */
  __RW struct RCC_APB1RSTR2_s   APB1RSTR2;       /*!< Ofs= 60, W=4 APB1 peripheral reset register 2 */
  __RW struct RCC_APB2RSTR_s    APB2RSTR;        /*!< Ofs= 64, W=4 APB2 peripheral reset register */
       uint32_t UNUSED3;
  __RW struct RCC_AHB1ENR_s     AHB1ENR;         /*!< Ofs= 72, W=4 AHB1 peripheral clock enable register */
  __RW struct RCC_AHB2ENR_s     AHB2ENR;         /*!< Ofs= 76, W=4 AHB2 peripheral clock enable register */
  __RW struct RCC_AHB3ENR_s     AHB3ENR;         /*!< Ofs= 80, W=4 AHB3 peripheral clock enable register */
       uint32_t UNUSED4;
  __RW struct RCC_APB1ENR1_s    APB1ENR1;        /*!< Ofs= 88, W=4 APB1ENR1 */
  __RW struct RCC_APB1ENR2_s    APB1ENR2;        /*!< Ofs= 92, W=4 APB1 peripheral clock enable register 2 */
  __RW struct RCC_APB2ENR_s     APB2ENR;         /*!< Ofs= 96, W=4 APB2ENR */
       uint32_t UNUSED5;
  __RW struct RCC_AHB1SMENR_s   AHB1SMENR;       /*!< Ofs=104, W=4 AHB1 peripheral clocks enable in Sleep and Stop modes register */
  __RW struct RCC_AHB2SMENR_s   AHB2SMENR;       /*!< Ofs=108, W=4 AHB2 peripheral clocks enable in Sleep and Stop modes register */
  __RW struct RCC_AHB3SMENR_s   AHB3SMENR;       /*!< Ofs=112, W=4 AHB3 peripheral clocks enable in Sleep and Stop modes register */
       uint32_t UNUSED6;
  __RW struct RCC_APB1SMENR1_s  APB1SMENR1;      /*!< Ofs=120, W=4 APB1SMENR1 */
  __RW struct RCC_APB1SMENR2_s  APB1SMENR2;      /*!< Ofs=124, W=4 APB1 peripheral clocks enable in Sleep and Stop modes register 2 */
  __RW struct RCC_APB2SMENR_s   APB2SMENR;       /*!< Ofs=128, W=4 APB2SMENR */
       uint32_t UNUSED7;
  __RW struct RCC_CCIPR_s       CCIPR;           /*!< Ofs=136, W=4 CCIPR */
       uint32_t UNUSED8;
  __RW struct RCC_BDCR_s        BDCR;            /*!< Ofs=144, W=4 BDCR */
  __RW struct RCC_CSR_s         CSR;             /*!< Ofs=148, W=4 CSR */
  __RW struct RCC_CRRCR_s       CRRCR;           /*!< Ofs=152, W=4 Clock recovery RC register */
}  RCC_Type; /* W=156=0x9C */
typedef struct Flash_s { /*!< peripheral group Flash */
  __RW struct Flash_ACR_s       ACR;             /*!< Ofs=  0, W=4 Access control register */
  __WO uint32_t PDKEYR;          /*!< Ofs=  4, W=4 Power down key register */
  __WO uint32_t KEYR;            /*!< Ofs=  8, W=4 Flash key register */
  __WO uint32_t OPTKEYR;         /*!< Ofs= 12, W=4 Option byte key register */
  __RW struct Flash_SR_s        SR;              /*!< Ofs= 16, W=4 Status register */
  __RW struct Flash_CR_s        CR;              /*!< Ofs= 20, W=4 Flash control register */
  __RW struct Flash_ECCR_s      ECCR;            /*!< Ofs= 24, W=4 Flash ECC register */
       uint32_t UNUSED0;
  __RW struct Flash_OPTR_s      OPTR;            /*!< Ofs= 32, W=4 Flash option register */
  __RW uint32_t PCROP1SR;        /*!< Ofs= 36, W=4 Flash Bank 1 PCROP Start address register */
  __RW struct Flash_PCROP1ER_s  PCROP1ER;        /*!< Ofs= 40, W=4 Flash Bank 1 PCROP End address register */
  __RW struct Flash_WRP1AR_s    WRP1AR;          /*!< Ofs= 44, W=4 Flash Bank 1 WRP area A address register */
  __RW struct Flash_WRP1BR_s    WRP1BR;          /*!< Ofs= 48, W=4 Flash Bank 1 WRP area B address register */
       uint32_t UNUSED1[4];
  __RW uint32_t PCROP2SR;        /*!< Ofs= 68, W=4 Flash Bank 2 PCROP Start address register */
  __RW uint32_t PCROP2ER;        /*!< Ofs= 72, W=4 Flash Bank 2 PCROP End address register */
  __RW struct Flash_WRP2AR_s    WRP2AR;          /*!< Ofs= 76, W=4 Flash Bank 2 WRP area A address register */
  __RW struct Flash_WRP2BR_s    WRP2BR;          /*!< Ofs= 80, W=4 Flash Bank 2 WRP area B address register */
}  Flash_Type; /* W=84=0x54 */
typedef struct CRC_s { /*!< peripheral group CRC */
  __RW uint32_t DR;              /*!< Ofs=  0, W=4 Data register */
  __RW uint32_t IDR;             /*!< Ofs=  4, W=4 Independent data register */
  __RW struct CRC_CR_s          CR;              /*!< Ofs=  8, W=4 Control register */
       uint32_t UNUSED0;
  __RW uint32_t INIT;            /*!< Ofs= 16, W=4 Initial CRC value */
  __RW uint32_t POL;             /*!< Ofs= 20, W=4 polynomial */
}  CRC_Type; /* W=24=0x18 */
typedef struct TSC_s { /*!< peripheral group TSC */
  __RW struct TSC_CR_s          CR;              /*!< Ofs=  0, W=4 control register */
  __RW struct TSC_IER_s         IER;             /*!< Ofs=  4, W=4 interrupt enable register */
  __RW struct TSC_ICR_s         ICR;             /*!< Ofs=  8, W=4 interrupt clear register */
  __RW struct TSC_ISR_s         ISR;             /*!< Ofs= 12, W=4 interrupt status register */
  __RW struct TSC_IOHCR_s       IOHCR;           /*!< Ofs= 16, W=4 I/O hysteresis control register */
       uint32_t UNUSED0;
  __RW struct TSC_IOASCR_s      IOASCR;          /*!< Ofs= 24, W=4 I/O analog switch control register */
       uint32_t UNUSED1;
  __RW struct TSC_IOSCR_s       IOSCR;           /*!< Ofs= 32, W=4 I/O sampling control register */
       uint32_t UNUSED2;
  __RW struct TSC_IOCCR_s       IOCCR;           /*!< Ofs= 40, W=4 I/O channel control register */
       uint32_t UNUSED3;
  __RW struct TSC_IOGCSR_s      IOGCSR;          /*!< Ofs= 48, W=4 I/O group control status register */
  __RO uint32_t IOG1CR;          /*!< Ofs= 52, W=4 I/O group x counter register */
  __RO uint32_t IOG2CR;          /*!< Ofs= 56, W=4 I/O group x counter register */
  __RO uint32_t IOG3CR;          /*!< Ofs= 60, W=4 I/O group x counter register */
  __RO uint32_t IOG4CR;          /*!< Ofs= 64, W=4 I/O group x counter register */
  __RO uint32_t IOG5CR;          /*!< Ofs= 68, W=4 I/O group x counter register */
  __RO uint32_t IOG6CR;          /*!< Ofs= 72, W=4 I/O group x counter register */
  __RO uint32_t IOG7CR;          /*!< Ofs= 76, W=4 I/O group x counter register */
  __RO uint32_t IOG8CR;          /*!< Ofs= 80, W=4 I/O group x counter register */
}  TSC_Type; /* W=84=0x54 */
typedef struct GPIO_s { /*!< peripheral group GPIO */
  __RW uint32_t      MODER;      /*!< Ofs=  0, W=4 GPIO port mode register */
  __RW uint32_t     OTYPER;      /*!< Ofs=  4, W=4 GPIO port output type register */
  __RW uint32_t    OSPEEDR;      /*!< Ofs=  8, W=4 GPIO port output speed register */
  __RW uint32_t      PUPDR;      /*!< Ofs= 12, W=4 GPIO port pull-up/pull-down register */
  __RO uint32_t        IDR;      /*!< Ofs= 16, W=4 GPIO port input data register */
  __RW uint32_t        ODR;      /*!< Ofs= 20, W=4 GPIO port output data register */
  union {
  __WO uint32_t       BSRR;      /*!< Ofs= 24, W=4 GPIO port bit set/reset register */
    struct {
    __WO uint16_t     BSRRL;     /*!< Ofs= 24, W=4 GPIO port bit set/reset register */
    __WO uint16_t     BSRRH;     /*!< Ofs= 24, W=4 GPIO port bit set/reset register */
    };
  };
  __RW uint32_t       LCKR;      /*!< Ofs= 28, W=4 GPIO port configuration lock register */
  __RW uint32_t       AFR[2];    /*!< Ofs= 32, W=8 GPIO alternate function low register */
}  GPIO_Type; /* W=40=0x28 */
typedef struct ADC_s { /*!< peripheral group ADC */
  __RW struct ADC_ISR_s         ISR;             /*!< Ofs=  0, W=4 interrupt and status register */
  __RW struct ADC_IER_s         IER;             /*!< Ofs=  4, W=4 interrupt enable register */
  __RW struct ADC_CR_s          CR;              /*!< Ofs=  8, W=4 control register */
  __RW struct ADC_CFGR_s        CFGR;            /*!< Ofs= 12, W=4 configuration register */
  __RW struct ADC_CFGR2_s       CFGR2;           /*!< Ofs= 16, W=4 configuration register */
  __RW struct ADC_SMPR1_s       SMPR1;           /*!< Ofs= 20, W=4 sample time register 1 */
  __RW struct ADC_SMPR2_s       SMPR2;           /*!< Ofs= 24, W=4 sample time register 2 */
       uint32_t UNUSED0;
  __RW struct ADC_TR1_s         TR1;             /*!< Ofs= 32, W=4 watchdog threshold register 1 */
  __RW struct ADC_TR2_s         TR2;             /*!< Ofs= 36, W=4 watchdog threshold register */
  __RW struct ADC_TR3_s         TR3;             /*!< Ofs= 40, W=4 watchdog threshold register 3 */
       uint32_t UNUSED1;
  __RW struct ADC_SQR1_s        SQR1;            /*!< Ofs= 48, W=4 regular sequence register 1 */
  __RW struct ADC_SQR2_s        SQR2;            /*!< Ofs= 52, W=4 regular sequence register 2 */
  __RW struct ADC_SQR3_s        SQR3;            /*!< Ofs= 56, W=4 regular sequence register 3 */
  __RW struct ADC_SQR4_s        SQR4;            /*!< Ofs= 60, W=4 regular sequence register 4 */
  __RO uint32_t DR;              /*!< Ofs= 64, W=4 regular Data Register */
       uint32_t UNUSED2[2];
  __RW struct ADC_JSQR_s        JSQR;            /*!< Ofs= 76, W=4 injected sequence register */
       uint32_t UNUSED3[4];
  __RW struct ADC_OFR1_s        OFR1;            /*!< Ofs= 96, W=4 offset register 1 */
  __RW struct ADC_OFR2_s        OFR2;            /*!< Ofs=100, W=4 offset register 2 */
  __RW struct ADC_OFR3_s        OFR3;            /*!< Ofs=104, W=4 offset register 3 */
  __RW struct ADC_OFR4_s        OFR4;            /*!< Ofs=108, W=4 offset register 4 */
       uint32_t UNUSED4[4];
  __RO uint32_t JDR1;            /*!< Ofs=128, W=4 injected data register 1 */
  __RO uint32_t JDR2;            /*!< Ofs=132, W=4 injected data register 2 */
  __RO uint32_t JDR3;            /*!< Ofs=136, W=4 injected data register 3 */
  __RO uint32_t JDR4;            /*!< Ofs=140, W=4 injected data register 4 */
       uint32_t UNUSED5[4];
  __RW struct ADC_AWD2CR_s      AWD2CR;          /*!< Ofs=160, W=4 Analog Watchdog 2 Configuration Register */
  __RW struct ADC_AWD3CR_s      AWD3CR;          /*!< Ofs=164, W=4 Analog Watchdog 3 Configuration Register */
       uint32_t UNUSED6[2];
  __RW struct ADC_DIFSEL_s      DIFSEL;          /*!< Ofs=176, W=4 Differential Mode Selection Register 2 */
  __RW struct ADC_CALFACT_s     CALFACT;         /*!< Ofs=180, W=4 Calibration Factors */
}  ADC_Type; /* W=184=0xB8 */
typedef struct AES_s { /*!< peripheral group AES */
  __RW struct AES_CR_s          CR;              /*!< Ofs=  0, W=4 control register */
  __RO struct AES_SR_s          SR;              /*!< Ofs=  4, W=4 status register */
  __RW uint32_t DINR;            /*!< Ofs=  8, W=4 data input register */
  __RO uint32_t DOUTR;           /*!< Ofs= 12, W=4 data output register */
  __RW uint32_t KEYR0;           /*!< Ofs= 16, W=4 key register 0 */
  __RW uint32_t KEYR1;           /*!< Ofs= 20, W=4 key register 1 */
  __RW uint32_t KEYR2;           /*!< Ofs= 24, W=4 key register 2 */
  __RW uint32_t KEYR3;           /*!< Ofs= 28, W=4 key register 3 */
  __RW uint32_t IVR0;            /*!< Ofs= 32, W=4 initialization vector register 0 */
  __RW uint32_t IVR1;            /*!< Ofs= 36, W=4 initialization vector register 1 */
  __RW uint32_t IVR2;            /*!< Ofs= 40, W=4 initialization vector register 2 */
  __RW uint32_t IVR3;            /*!< Ofs= 44, W=4 initialization vector register 3 */
}  AES_Type; /* W=48=0x30 */
typedef struct RNG_s { /*!< peripheral group RNG */
  __RW struct RNG_CR_s          CR;              /*!< Ofs=  0, W=4 control register */
  __RW struct RNG_SR_s          SR;              /*!< Ofs=  4, W=4 status register */
  __RO uint32_t DR;              /*!< Ofs=  8, W=4 data register */
}  RNG_Type; /* W=12=0xC */
typedef struct QUADSPI_s { /*!< peripheral group QUADSPI */
  __RW struct QUADSPI_CR_s      CR;              /*!< Ofs=  0, W=4 control register */
  __RW struct QUADSPI_DCR_s     DCR;             /*!< Ofs=  4, W=4 device configuration register */
  __RO struct QUADSPI_SR_s      SR;              /*!< Ofs=  8, W=4 status register */
  __RW struct QUADSPI_FCR_s     FCR;             /*!< Ofs= 12, W=4 flag clear register */
  __RW uint32_t DLR;             /*!< Ofs= 16, W=4 data length register */
  __RW struct QUADSPI_CCR_s     CCR;             /*!< Ofs= 20, W=4 communication configuration register */
  __RW uint32_t AR;              /*!< Ofs= 24, W=4 address register */
  __RW uint32_t ABR;             /*!< Ofs= 28, W=4 ABR */
  __RW uint32_t DR;              /*!< Ofs= 32, W=4 data register */
  __RW uint32_t PSMKR;           /*!< Ofs= 36, W=4 polling status mask register */
  __RW uint32_t PSMAR;           /*!< Ofs= 40, W=4 polling status match register */
  __RW uint32_t PIR;             /*!< Ofs= 44, W=4 polling interval register */
  __RW uint32_t LPTR;            /*!< Ofs= 48, W=4 low-power timeout register */
}  QUADSPI_Type; /* W=52=0x34 */

#ifdef __cplusplus
static TIM_Type               & TIM2                   = * reinterpret_cast<TIM_Type               * const> (0x40000000u); /*!< General-purpose-timers */
static TIM_Type               & TIM3                   = * reinterpret_cast<TIM_Type               * const> (0x40000400u); /*!< General-purpose-timers */
static TIM_Type               & TIM6                   = * reinterpret_cast<TIM_Type               * const> (0x40001000u); /*!< Basic-timers */
static TIM_Type               & TIM7                   = * reinterpret_cast<TIM_Type               * const> (0x40001400u); /*!< Basic-timers */
static LCD_Type               & LCD                    = * reinterpret_cast<LCD_Type               * const> (0x40002400u); /*!< Liquid crystal display controller */
static RTC_Type               & RTC                    = * reinterpret_cast<RTC_Type               * const> (0x40002800u); /*!< Real-time clock */
static WWDG_Type              & WWDG                   = * reinterpret_cast<WWDG_Type              * const> (0x40002C00u); /*!< System window watchdog */
static IWDG_Type              & IWDG                   = * reinterpret_cast<IWDG_Type              * const> (0x40003000u); /*!< Independent watchdog */
static SPI_Type               & SPI2                   = * reinterpret_cast<SPI_Type               * const> (0x40003800u); /*!< Serial peripheral interface/Inter-IC sound */
static SPI_Type               & SPI3                   = * reinterpret_cast<SPI_Type               * const> (0x40003C00u); /*!< Serial peripheral interface/Inter-IC sound */
static USART_Type             & USART2                 = * reinterpret_cast<USART_Type             * const> (0x40004400u); /*!< Universal synchronous asynchronous receiver transmitter */
static USART_Type             & USART3                 = * reinterpret_cast<USART_Type             * const> (0x40004800u); /*!< Universal synchronous asynchronous receiver transmitter */
static USART_Type             & UART4                  = * reinterpret_cast<USART_Type             * const> (0x40004C00u); /*!< Universal synchronous asynchronous receiver transmitter */
static I2C_Type               & I2C1                   = * reinterpret_cast<I2C_Type               * const> (0x40005400u); /*!< Inter-integrated circuit */
static I2C_Type               & I2C2                   = * reinterpret_cast<I2C_Type               * const> (0x40005800u); /*!< Inter-integrated circuit */
static I2C_Type               & I2C3                   = * reinterpret_cast<I2C_Type               * const> (0x40005C00u); /*!< Inter-integrated circuit */
static CRS_Type               & CRS                    = * reinterpret_cast<CRS_Type               * const> (0x40006000u); /*!< Clock recovery system */
static CAN_Type               & CAN1                   = * reinterpret_cast<CAN_Type               * const> (0x40006400u); /*!< Controller area network */
static USB_Type               & USB_FS                 = * reinterpret_cast<USB_Type               * const> (0x40006800u); /*!< Universal serial bus full-speed device interface */
static USB_Type               & USB_SRAM               = * reinterpret_cast<USB_Type               * const> (0x40006C00u); /*!< Universal serial bus full-speed device interface */
static PWR_Type               & PWR                    = * reinterpret_cast<PWR_Type               * const> (0x40007000u); /*!< Power control */
static DAC_Type               & DAC1                   = * reinterpret_cast<DAC_Type               * const> (0x40007400u); /*!< Digital-to-analog converter */
static OPAMP_Type             & OPAMP                  = * reinterpret_cast<OPAMP_Type             * const> (0x40007800u); /*!< Operational amplifiers */
static LPTIM_Type             & LPTIM1                 = * reinterpret_cast<LPTIM_Type             * const> (0x40007C00u); /*!< Low power timer */
static USART_Type             & LPUART1                = * reinterpret_cast<USART_Type             * const> (0x40008000u); /*!< Universal synchronous asynchronous receiver transmitter */
static I2C_Type               & I2C4                   = * reinterpret_cast<I2C_Type               * const> (0x40008400u); /*!< Inter-integrated circuit */
static SWPMI_Type             & SWPMI1                 = * reinterpret_cast<SWPMI_Type             * const> (0x40008800u); /*!< Single Wire Protocol Master Interface */
static LPTIM_Type             & LPTIM2                 = * reinterpret_cast<LPTIM_Type             * const> (0x40009400u); /*!< Low power timer */
static SYSCFG_Type            & SYSCFG                 = * reinterpret_cast<SYSCFG_Type            * const> (0x40010000u); /*!< System configuration controller */
static VREF_Type              & VREFBUF                = * reinterpret_cast<VREF_Type              * const> (0x40010030u); /*!< Voltage reference buffer */
static COMP_Type              & COMP                   = * reinterpret_cast<COMP_Type              * const> (0x40010200u); /*!< Comparator */
static EXTI_Type              & EXTI                   = * reinterpret_cast<EXTI_Type              * const> (0x40010400u); /*!< External interrupt/event controller */
static Firewall_Type          & FIREWALL               = * reinterpret_cast<Firewall_Type          * const> (0x40011C00u); /*!< Firewall */
static SDIO_Type              & SDMMC                  = * reinterpret_cast<SDIO_Type              * const> (0x40012800u); /*!< Secure digital input/output interface */
static TIM_Type               & TIM1                   = * reinterpret_cast<TIM_Type               * const> (0x40012C00u); /*!< Advanced-timers */
static SPI_Type               & SPI1                   = * reinterpret_cast<SPI_Type               * const> (0x40013000u); /*!< Serial peripheral interface/Inter-IC sound */
static USART_Type             & USART1                 = * reinterpret_cast<USART_Type             * const> (0x40013800u); /*!< Universal synchronous asynchronous receiver transmitter */
static TIM_Type               & TIM15                  = * reinterpret_cast<TIM_Type               * const> (0x40014000u); /*!< General purpose timers */
static TIM_Type               & TIM16                  = * reinterpret_cast<TIM_Type               * const> (0x40014400u); /*!< General purpose timers */
static SAI_Type               & SAI1                   = * reinterpret_cast<SAI_Type               * const> (0x40015400u); /*!< Serial audio interface */
static DFSDM_Type             & DFSDM                  = * reinterpret_cast<DFSDM_Type             * const> (0x40016000u); /*!< Digital filter for sigma delta modulators */
static DMA_Type               & DMA1                   = * reinterpret_cast<DMA_Type               * const> (0x40020000u); /*!< Direct memory access controller */
static DMA_Type               & DMA2                   = * reinterpret_cast<DMA_Type               * const> (0x40020400u); /*!< Direct memory access controller */
static RCC_Type               & RCC                    = * reinterpret_cast<RCC_Type               * const> (0x40021000u); /*!< Reset and clock control */
static Flash_Type             & FLASH                  = * reinterpret_cast<Flash_Type             * const> (0x40022000u); /*!< Flash */
static CRC_Type               & CRC                    = * reinterpret_cast<CRC_Type               * const> (0x40023000u); /*!< Cyclic redundancy check calculation unit */
static TSC_Type               & TSC                    = * reinterpret_cast<TSC_Type               * const> (0x40024000u); /*!< Touch sensing controller */
static GPIO_Type              & GPIOA                  = * reinterpret_cast<GPIO_Type              * const> (0x48000000u); /*!< General-purpose I/Os */
static GPIO_Type              & GPIOB                  = * reinterpret_cast<GPIO_Type              * const> (0x48000400u); /*!< General-purpose I/Os */
static GPIO_Type              & GPIOC                  = * reinterpret_cast<GPIO_Type              * const> (0x48000800u); /*!< General-purpose I/Os */
static GPIO_Type              & GPIOD                  = * reinterpret_cast<GPIO_Type              * const> (0x48000C00u); /*!< General-purpose I/Os */
static GPIO_Type              & GPIOE                  = * reinterpret_cast<GPIO_Type              * const> (0x48001000u); /*!< General-purpose I/Os */
static GPIO_Type              & GPIOH                  = * reinterpret_cast<GPIO_Type              * const> (0x48001C00u); /*!< General-purpose I/Os */
static ADC_Type               & ADC                    = * reinterpret_cast<ADC_Type               * const> (0x50040000u); /*!< Analog-to-Digital Converter */
static AES_Type               & AES                    = * reinterpret_cast<AES_Type               * const> (0x50060000u); /*!< Advanced encryption standard hardware accelerator */
static RNG_Type               & RNG                    = * reinterpret_cast<RNG_Type               * const> (0x50060800u); /*!< Random number generator */
static QUADSPI_Type           & QUADSPI                = * reinterpret_cast<QUADSPI_Type           * const> (0xA0001000u); /*!< QuadSPI interface */
#else // __cplusplus
static TIM_Type               * const TIM2                   = (TIM_Type               * const) 0x40000000u; /*!< General-purpose-timers */
static TIM_Type               * const TIM3                   = (TIM_Type               * const) 0x40000400u; /*!< General-purpose-timers */
static TIM_Type               * const TIM6                   = (TIM_Type               * const) 0x40001000u; /*!< Basic-timers */
static TIM_Type               * const TIM7                   = (TIM_Type               * const) 0x40001400u; /*!< Basic-timers */
static LCD_Type               * const LCD                    = (LCD_Type               * const) 0x40002400u; /*!< Liquid crystal display controller */
static RTC_Type               * const RTC                    = (RTC_Type               * const) 0x40002800u; /*!< Real-time clock */
static WWDG_Type              * const WWDG                   = (WWDG_Type              * const) 0x40002C00u; /*!< System window watchdog */
static IWDG_Type              * const IWDG                   = (IWDG_Type              * const) 0x40003000u; /*!< Independent watchdog */
static SPI_Type               * const SPI2                   = (SPI_Type               * const) 0x40003800u; /*!< Serial peripheral interface/Inter-IC sound */
static SPI_Type               * const SPI3                   = (SPI_Type               * const) 0x40003C00u; /*!< Serial peripheral interface/Inter-IC sound */
static USART_Type             * const USART2                 = (USART_Type             * const) 0x40004400u; /*!< Universal synchronous asynchronous receiver transmitter */
static USART_Type             * const USART3                 = (USART_Type             * const) 0x40004800u; /*!< Universal synchronous asynchronous receiver transmitter */
static USART_Type             * const UART4                  = (USART_Type             * const) 0x40004C00u; /*!< Universal synchronous asynchronous receiver transmitter */
static I2C_Type               * const I2C1                   = (I2C_Type               * const) 0x40005400u; /*!< Inter-integrated circuit */
static I2C_Type               * const I2C2                   = (I2C_Type               * const) 0x40005800u; /*!< Inter-integrated circuit */
static I2C_Type               * const I2C3                   = (I2C_Type               * const) 0x40005C00u; /*!< Inter-integrated circuit */
static CRS_Type               * const CRS                    = (CRS_Type               * const) 0x40006000u; /*!< Clock recovery system */
static CAN_Type               * const CAN1                   = (CAN_Type               * const) 0x40006400u; /*!< Controller area network */
static USB_Type               * const USB_FS                 = (USB_Type               * const) 0x40006800u; /*!< Universal serial bus full-speed device interface */
static USB_Type               * const USB_SRAM               = (USB_Type               * const) 0x40006C00u; /*!< Universal serial bus full-speed device interface */
static PWR_Type               * const PWR                    = (PWR_Type               * const) 0x40007000u; /*!< Power control */
static DAC_Type               * const DAC1                   = (DAC_Type               * const) 0x40007400u; /*!< Digital-to-analog converter */
static OPAMP_Type             * const OPAMP                  = (OPAMP_Type             * const) 0x40007800u; /*!< Operational amplifiers */
static LPTIM_Type             * const LPTIM1                 = (LPTIM_Type             * const) 0x40007C00u; /*!< Low power timer */
static USART_Type             * const LPUART1                = (USART_Type             * const) 0x40008000u; /*!< Universal synchronous asynchronous receiver transmitter */
static I2C_Type               * const I2C4                   = (I2C_Type               * const) 0x40008400u; /*!< Inter-integrated circuit */
static SWPMI_Type             * const SWPMI1                 = (SWPMI_Type             * const) 0x40008800u; /*!< Single Wire Protocol Master Interface */
static LPTIM_Type             * const LPTIM2                 = (LPTIM_Type             * const) 0x40009400u; /*!< Low power timer */
static SYSCFG_Type            * const SYSCFG                 = (SYSCFG_Type            * const) 0x40010000u; /*!< System configuration controller */
static VREF_Type              * const VREFBUF                = (VREF_Type              * const) 0x40010030u; /*!< Voltage reference buffer */
static COMP_Type              * const COMP                   = (COMP_Type              * const) 0x40010200u; /*!< Comparator */
static EXTI_Type              * const EXTI                   = (EXTI_Type              * const) 0x40010400u; /*!< External interrupt/event controller */
static Firewall_Type          * const FIREWALL               = (Firewall_Type          * const) 0x40011C00u; /*!< Firewall */
static SDIO_Type              * const SDMMC                  = (SDIO_Type              * const) 0x40012800u; /*!< Secure digital input/output interface */
static TIM_Type               * const TIM1                   = (TIM_Type               * const) 0x40012C00u; /*!< Advanced-timers */
static SPI_Type               * const SPI1                   = (SPI_Type               * const) 0x40013000u; /*!< Serial peripheral interface/Inter-IC sound */
static USART_Type             * const USART1                 = (USART_Type             * const) 0x40013800u; /*!< Universal synchronous asynchronous receiver transmitter */
static TIM_Type               * const TIM15                  = (TIM_Type               * const) 0x40014000u; /*!< General purpose timers */
static TIM_Type               * const TIM16                  = (TIM_Type               * const) 0x40014400u; /*!< General purpose timers */
static SAI_Type               * const SAI1                   = (SAI_Type               * const) 0x40015400u; /*!< Serial audio interface */
static DFSDM_Type             * const DFSDM                  = (DFSDM_Type             * const) 0x40016000u; /*!< Digital filter for sigma delta modulators */
static DMA_Type               * const DMA1                   = (DMA_Type               * const) 0x40020000u; /*!< Direct memory access controller */
static DMA_Type               * const DMA2                   = (DMA_Type               * const) 0x40020400u; /*!< Direct memory access controller */
static RCC_Type               * const RCC                    = (RCC_Type               * const) 0x40021000u; /*!< Reset and clock control */
static Flash_Type             * const FLASH                  = (Flash_Type             * const) 0x40022000u; /*!< Flash */
static CRC_Type               * const CRC                    = (CRC_Type               * const) 0x40023000u; /*!< Cyclic redundancy check calculation unit */
static TSC_Type               * const TSC                    = (TSC_Type               * const) 0x40024000u; /*!< Touch sensing controller */
static GPIO_Type              * const GPIOA                  = (GPIO_Type              * const) 0x48000000u; /*!< General-purpose I/Os */
static GPIO_Type              * const GPIOB                  = (GPIO_Type              * const) 0x48000400u; /*!< General-purpose I/Os */
static GPIO_Type              * const GPIOC                  = (GPIO_Type              * const) 0x48000800u; /*!< General-purpose I/Os */
static GPIO_Type              * const GPIOD                  = (GPIO_Type              * const) 0x48000C00u; /*!< General-purpose I/Os */
static GPIO_Type              * const GPIOE                  = (GPIO_Type              * const) 0x48001000u; /*!< General-purpose I/Os */
static GPIO_Type              * const GPIOH                  = (GPIO_Type              * const) 0x48001C00u; /*!< General-purpose I/Os */
static ADC_Type               * const ADC                    = (ADC_Type               * const) 0x50040000u; /*!< Analog-to-Digital Converter */
static AES_Type               * const AES                    = (AES_Type               * const) 0x50060000u; /*!< Advanced encryption standard hardware accelerator */
static RNG_Type               * const RNG                    = (RNG_Type               * const) 0x50060800u; /*!< Random number generator */
static QUADSPI_Type           * const QUADSPI                = (QUADSPI_Type           * const) 0xA0001000u; /*!< QuadSPI interface */
#endif // __cplusplus

typedef enum IRQn {
#include "cm4sysirq.h"
  WWDG_IRQn                = 0, /*!< Window Watchdog interrupt */
  PVD_PVM_IRQn             = 1, /*!< PVD through EXTI line detection */
  RTC_TAMP_STAMP_IRQn      = 2, /*!< Tamper and TimeStamp interrupts */
  RTC_WKUP_IRQn            = 3, /*!< RTC Tamper or TimeStamp /CSS on LSE through EXTI line 19 interrupts */
  FLASH_IRQn               = 4, /*!< Flash global interrupt */
  RCC_IRQn                 = 5, /*!< RCC global interrupt */
  EXTI0_IRQn               = 6, /*!< EXTI Line 0 interrupt */
  EXTI1_IRQn               = 7, /*!< EXTI Line 1 interrupt */
  EXTI2_IRQn               = 8, /*!< EXTI Line 2 interrupt */
  EXTI3_IRQn               = 9, /*!< EXTI Line 3 interrupt */
  EXTI4_IRQn               = 10, /*!< EXTI Line4 interrupt */
  DMA1_CH1_IRQn            = 11, /*!< DMA1 Channel1 global interrupt */
  DMA1_CH2_IRQn            = 12, /*!< DMA1 Channel2 global interrupt */
  DMA1_CH3_IRQn            = 13, /*!< DMA1 Channel3 interrupt */
  DMA1_CH4_IRQn            = 14, /*!< DMA1 Channel4 interrupt */
  DMA1_CH5_IRQn            = 15, /*!< DMA1 Channel5 interrupt */
  DMA1_CH6_IRQn            = 16, /*!< DMA1 Channel6 interrupt */
  DMA1_CH7_IRQn            = 17, /*!< DMA1 Channel 7 interrupt */
  ADC1_IRQn                = 18, /*!< ADC1 and ADC2 global interrupt */
  CAN1_TX_IRQn             = 19, /*!< CAN1 TX interrupts */
  CAN1_RX0_IRQn            = 20, /*!< CAN1 RX0 interrupts */
  CAN1_RX1_IRQn            = 21, /*!< CAN1 RX1 interrupts */
  CAN1_SCE_IRQn            = 22, /*!< CAN1 SCE interrupt */
  EXTI9_5_IRQn             = 23, /*!< EXTI Line5 to Line9 interrupts */
  TIM1_BRK_TIM15_IRQn      = 24, /*!< Timer 15 global interrupt */
  TIM1_UP_TIM16_IRQn       = 25, /*!< Timer 16 global interrupt */
  TIM1_TRG_COM_IRQn        = 26, /*!< TIM1 trigger and commutation interrupt */
  TIM1_CC_IRQn             = 27, /*!< TIM1 Capture Compare interrupt */
  TIM2_IRQn                = 28, /*!< TIM2 global interrupt */
  TIM3_IRQn                = 29, /*!< TIM3 global interrupt */
  I2C1_EV_IRQn             = 31, /*!< I2C1 event interrupt */
  I2C1_ER_IRQn             = 32, /*!< I2C1 error interrupt */
  I2C2_EV_IRQn             = 33, /*!< I2C2 event interrupt */
  I2C2_ER_IRQn             = 34, /*!< I2C2 error interrupt */
  SPI1_IRQn                = 35, /*!< SPI1 global interrupt */
  SPI2_IRQn                = 36, /*!< SPI2 global interrupt */
  USART1_IRQn              = 37, /*!< USART1 global interrupt */
  USART2_IRQn              = 38, /*!< USART2 global interrupt */
  USART3_IRQn              = 39, /*!< USART3 global interrupt */
  EXTI15_10_IRQn           = 40, /*!< EXTI Lines 10 to 15 interrupts */
  RTC_ALARM_IRQn           = 41, /*!< RTC alarms through EXTI line 18 interrupts */
  DFSDM1_FLT3_IRQn         = 42, /*!< DFSDM1_FLT3 global interrupt */
  SDMMC1_IRQn              = 49, /*!< SDMMC global Interrupt */
  SPI3_IRQn                = 51, /*!< SPI3 global Interrupt */
  UART4_IRQn               = 52, /*!< UART4 global Interrupt */
  TIM6_DACUNDER_IRQn       = 54, /*!< TIM6 global and DAC1 and 2 underrun error interrupts */
  TIM7_IRQn                = 55, /*!< TIM7 global interrupt */
  DMA2_CH1_IRQn            = 56, /*!< DMA2 Channel 1 global Interrupt */
  DMA2_CH2_IRQn            = 57, /*!< DMA2 Channel 2 global Interrupt */
  DMA2_CH3_IRQn            = 58, /*!< DMA2 Channel 3 global Interrupt */
  DMA2_CH4_IRQn            = 59, /*!< DMA2 Channel 4 global Interrupt */
  DMA2_CH5_IRQn            = 60, /*!< DMA2 Channel 5 global Interrupt */
  DFSDM1_IRQn              = 61, /*!< DFSDM1_FLT0 global interrupt */
  DFSDM2_IRQn              = 62, /*!< DFSDM1_FLT1 global interrupt */
  DFSDM1_FLT2_IRQn         = 63, /*!< DFSDM1_FLT2 global interrupt */
  COMP_IRQn                = 64, /*!< COMP1 and COMP2 interrupts */
  LPTIM1_IRQn              = 65, /*!< LP TIM1 interrupt */
  LPTIM2_IRQn              = 66, /*!< LP TIM2 interrupt */
  USB_FS_IRQn              = 67, /*!< USB event interrupt through EXTI */
  DMA2_CH6_IRQn            = 68, /*!< DMA2 Channel 6 global Interrupt */
  DMA2_CH7_IRQn            = 69, /*!< DMA2 Channel 7 global Interrupt */
  LPUART1_IRQn             = 70, /*!< LPUART1 global interrupt */
  QUADSPI_IRQn             = 71, /*!< Quad SPI global interrupt */
  I2C3_EV_IRQn             = 72, /*!< I2C3 event interrupt */
  I2C3_ER_IRQn             = 73, /*!< I2C3 error interrupt */
  SAI1_IRQn                = 74, /*!< SAI1 global interrupt */
  SWPMI1_IRQn              = 76, /*!< SWPMI1 global interrupt */
  TSC_IRQn                 = 77, /*!< TSC global interrupt */
  LCD_IRQn                 = 78, /*!< LCD global interrupt */
  AES_IRQn                 = 79, /*!< AES global interrupt */
  RNG_IRQn                 = 80, /*!< RNG global interrupt */
  FPU_IRQn                 = 81, /*!< Floating point unit interrupt */
  CRS_IRQn                 = 82, /*!< CRS interrupt */
  I2C4_EV_IRQn             = 83, /*!< I2C4 event interrupt, wakeup through EXTI */
  I2C4_ER_IRQn             = 84, /*!< I2C4 error interrupt */
} IRQn_Type;

#if 0  // koliduje s CMSIS a chybi potrebna systemova preruseni
//! Pouzijte COPY / PASTE do prislusnych souboru
typedef enum IRQn {
  WWDG_IRQn                = 0, /*!< Window Watchdog interrupt */
  PVD_PVM_IRQn             = 1, /*!< PVD through EXTI line detection */
  RTC_TAMP_STAMP_IRQn      = 2, /*!< Tamper and TimeStamp interrupts */
  RTC_WKUP_IRQn            = 3, /*!< RTC Tamper or TimeStamp /CSS on LSE through EXTI line 19 interrupts */
  FLASH_IRQn               = 4, /*!< Flash global interrupt */
  RCC_IRQn                 = 5, /*!< RCC global interrupt */
  EXTI0_IRQn               = 6, /*!< EXTI Line 0 interrupt */
  EXTI1_IRQn               = 7, /*!< EXTI Line 1 interrupt */
  EXTI2_IRQn               = 8, /*!< EXTI Line 2 interrupt */
  EXTI3_IRQn               = 9, /*!< EXTI Line 3 interrupt */
  EXTI4_IRQn               = 10, /*!< EXTI Line4 interrupt */
  DMA1_CH1_IRQn            = 11, /*!< DMA1 Channel1 global interrupt */
  DMA1_CH2_IRQn            = 12, /*!< DMA1 Channel2 global interrupt */
  DMA1_CH3_IRQn            = 13, /*!< DMA1 Channel3 interrupt */
  DMA1_CH4_IRQn            = 14, /*!< DMA1 Channel4 interrupt */
  DMA1_CH5_IRQn            = 15, /*!< DMA1 Channel5 interrupt */
  DMA1_CH6_IRQn            = 16, /*!< DMA1 Channel6 interrupt */
  DMA1_CH7_IRQn            = 17, /*!< DMA1 Channel 7 interrupt */
  ADC1_IRQn                = 18, /*!< ADC1 and ADC2 global interrupt */
  CAN1_TX_IRQn             = 19, /*!< CAN1 TX interrupts */
  CAN1_RX0_IRQn            = 20, /*!< CAN1 RX0 interrupts */
  CAN1_RX1_IRQn            = 21, /*!< CAN1 RX1 interrupts */
  CAN1_SCE_IRQn            = 22, /*!< CAN1 SCE interrupt */
  EXTI9_5_IRQn             = 23, /*!< EXTI Line5 to Line9 interrupts */
  TIM1_BRK_TIM15_IRQn      = 24, /*!< Timer 15 global interrupt */
  TIM1_UP_TIM16_IRQn       = 25, /*!< Timer 16 global interrupt */
  TIM1_TRG_COM_IRQn        = 26, /*!< TIM1 trigger and commutation interrupt */
  TIM1_CC_IRQn             = 27, /*!< TIM1 Capture Compare interrupt */
  TIM2_IRQn                = 28, /*!< TIM2 global interrupt */
  TIM3_IRQn                = 29, /*!< TIM3 global interrupt */
  I2C1_EV_IRQn             = 31, /*!< I2C1 event interrupt */
  I2C1_ER_IRQn             = 32, /*!< I2C1 error interrupt */
  I2C2_EV_IRQn             = 33, /*!< I2C2 event interrupt */
  I2C2_ER_IRQn             = 34, /*!< I2C2 error interrupt */
  SPI1_IRQn                = 35, /*!< SPI1 global interrupt */
  SPI2_IRQn                = 36, /*!< SPI2 global interrupt */
  USART1_IRQn              = 37, /*!< USART1 global interrupt */
  USART2_IRQn              = 38, /*!< USART2 global interrupt */
  USART3_IRQn              = 39, /*!< USART3 global interrupt */
  EXTI15_10_IRQn           = 40, /*!< EXTI Lines 10 to 15 interrupts */
  RTC_ALARM_IRQn           = 41, /*!< RTC alarms through EXTI line 18 interrupts */
  DFSDM1_FLT3_IRQn         = 42, /*!< DFSDM1_FLT3 global interrupt */
  SDMMC1_IRQn              = 49, /*!< SDMMC global Interrupt */
  SPI3_IRQn                = 51, /*!< SPI3 global Interrupt */
  UART4_IRQn               = 52, /*!< UART4 global Interrupt */
  TIM6_DACUNDER_IRQn       = 54, /*!< TIM6 global and DAC1 and 2 underrun error interrupts */
  TIM7_IRQn                = 55, /*!< TIM7 global interrupt */
  DMA2_CH1_IRQn            = 56, /*!< DMA2 Channel 1 global Interrupt */
  DMA2_CH2_IRQn            = 57, /*!< DMA2 Channel 2 global Interrupt */
  DMA2_CH3_IRQn            = 58, /*!< DMA2 Channel 3 global Interrupt */
  DMA2_CH4_IRQn            = 59, /*!< DMA2 Channel 4 global Interrupt */
  DMA2_CH5_IRQn            = 60, /*!< DMA2 Channel 5 global Interrupt */
  DFSDM1_IRQn              = 61, /*!< DFSDM1_FLT0 global interrupt */
  DFSDM2_IRQn              = 62, /*!< DFSDM1_FLT1 global interrupt */
  DFSDM1_FLT2_IRQn         = 63, /*!< DFSDM1_FLT2 global interrupt */
  COMP_IRQn                = 64, /*!< COMP1 and COMP2 interrupts */
  LPTIM1_IRQn              = 65, /*!< LP TIM1 interrupt */
  LPTIM2_IRQn              = 66, /*!< LP TIM2 interrupt */
  USB_FS_IRQn              = 67, /*!< USB event interrupt through EXTI */
  DMA2_CH6_IRQn            = 68, /*!< DMA2 Channel 6 global Interrupt */
  DMA2_CH7_IRQn            = 69, /*!< DMA2 Channel 7 global Interrupt */
  LPUART1_IRQn             = 70, /*!< LPUART1 global interrupt */
  QUADSPI_IRQn             = 71, /*!< Quad SPI global interrupt */
  I2C3_EV_IRQn             = 72, /*!< I2C3 event interrupt */
  I2C3_ER_IRQn             = 73, /*!< I2C3 error interrupt */
  SAI1_IRQn                = 74, /*!< SAI1 global interrupt */
  SWPMI1_IRQn              = 76, /*!< SWPMI1 global interrupt */
  TSC_IRQn                 = 77, /*!< TSC global interrupt */
  LCD_IRQn                 = 78, /*!< LCD global interrupt */
  AES_IRQn                 = 79, /*!< AES global interrupt */
  RNG_IRQn                 = 80, /*!< RNG global interrupt */
  FPU_IRQn                 = 81, /*!< Floating point unit interrupt */
  CRS_IRQn                 = 82, /*!< CRS interrupt */
  I2C4_EV_IRQn             = 83, /*!< I2C4 event interrupt, wakeup through EXTI */
  I2C4_ER_IRQn             = 84, /*!< I2C4 error interrupt */
} IRQn_Type;
//! Vector table declarations (device part)
  void WWDG_IRQHandler     (void) ALIAS(Default_Handler);
  void PVD_PVM_IRQHandler  (void) ALIAS(Default_Handler);
  void RTC_TAMP_STAMP_IRQHandler (void) ALIAS(Default_Handler);
  void RTC_WKUP_IRQHandler (void) ALIAS(Default_Handler);
  void FLASH_IRQHandler    (void) ALIAS(Default_Handler);
  void RCC_IRQHandler      (void) ALIAS(Default_Handler);
  void EXTI0_IRQHandler    (void) ALIAS(Default_Handler);
  void EXTI1_IRQHandler    (void) ALIAS(Default_Handler);
  void EXTI2_IRQHandler    (void) ALIAS(Default_Handler);
  void EXTI3_IRQHandler    (void) ALIAS(Default_Handler);
  void EXTI4_IRQHandler    (void) ALIAS(Default_Handler);
  void DMA1_CH1_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH2_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH3_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH4_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH5_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH6_IRQHandler (void) ALIAS(Default_Handler);
  void DMA1_CH7_IRQHandler (void) ALIAS(Default_Handler);
  void ADC1_IRQHandler     (void) ALIAS(Default_Handler);
  void CAN1_TX_IRQHandler  (void) ALIAS(Default_Handler);
  void CAN1_RX0_IRQHandler (void) ALIAS(Default_Handler);
  void CAN1_RX1_IRQHandler (void) ALIAS(Default_Handler);
  void CAN1_SCE_IRQHandler (void) ALIAS(Default_Handler);
  void EXTI9_5_IRQHandler  (void) ALIAS(Default_Handler);
  void TIM1_BRK_TIM15_IRQHandler (void) ALIAS(Default_Handler);
  void TIM1_UP_TIM16_IRQHandler (void) ALIAS(Default_Handler);
  void TIM1_TRG_COM_IRQHandler (void) ALIAS(Default_Handler);
  void TIM1_CC_IRQHandler  (void) ALIAS(Default_Handler);
  void TIM2_IRQHandler     (void) ALIAS(Default_Handler);
  void TIM3_IRQHandler     (void) ALIAS(Default_Handler);
  void I2C1_EV_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C1_ER_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C2_EV_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C2_ER_IRQHandler  (void) ALIAS(Default_Handler);
  void SPI1_IRQHandler     (void) ALIAS(Default_Handler);
  void SPI2_IRQHandler     (void) ALIAS(Default_Handler);
  void USART1_IRQHandler   (void) ALIAS(Default_Handler);
  void USART2_IRQHandler   (void) ALIAS(Default_Handler);
  void USART3_IRQHandler   (void) ALIAS(Default_Handler);
  void EXTI15_10_IRQHandler (void) ALIAS(Default_Handler);
  void RTC_ALARM_IRQHandler (void) ALIAS(Default_Handler);
  void DFSDM1_FLT3_IRQHandler (void) ALIAS(Default_Handler);
  void SDMMC1_IRQHandler   (void) ALIAS(Default_Handler);
  void SPI3_IRQHandler     (void) ALIAS(Default_Handler);
  void UART4_IRQHandler    (void) ALIAS(Default_Handler);
  void TIM6_DACUNDER_IRQHandler (void) ALIAS(Default_Handler);
  void TIM7_IRQHandler     (void) ALIAS(Default_Handler);
  void DMA2_CH1_IRQHandler (void) ALIAS(Default_Handler);
  void DMA2_CH2_IRQHandler (void) ALIAS(Default_Handler);
  void DMA2_CH3_IRQHandler (void) ALIAS(Default_Handler);
  void DMA2_CH4_IRQHandler (void) ALIAS(Default_Handler);
  void DMA2_CH5_IRQHandler (void) ALIAS(Default_Handler);
  void DFSDM1_IRQHandler   (void) ALIAS(Default_Handler);
  void DFSDM2_IRQHandler   (void) ALIAS(Default_Handler);
  void DFSDM1_FLT2_IRQHandler (void) ALIAS(Default_Handler);
  void COMP_IRQHandler     (void) ALIAS(Default_Handler);
  void LPTIM1_IRQHandler   (void) ALIAS(Default_Handler);
  void LPTIM2_IRQHandler   (void) ALIAS(Default_Handler);
  void USB_FS_IRQHandler   (void) ALIAS(Default_Handler);
  void DMA2_CH6_IRQHandler (void) ALIAS(Default_Handler);
  void DMA2_CH7_IRQHandler (void) ALIAS(Default_Handler);
  void LPUART1_IRQHandler  (void) ALIAS(Default_Handler);
  void QUADSPI_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C3_EV_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C3_ER_IRQHandler  (void) ALIAS(Default_Handler);
  void SAI1_IRQHandler     (void) ALIAS(Default_Handler);
  void SWPMI1_IRQHandler   (void) ALIAS(Default_Handler);
  void TSC_IRQHandler      (void) ALIAS(Default_Handler);
  void LCD_IRQHandler      (void) ALIAS(Default_Handler);
  void AES_IRQHandler      (void) ALIAS(Default_Handler);
  void RNG_IRQHandler      (void) ALIAS(Default_Handler);
  void FPU_IRQHandler      (void) ALIAS(Default_Handler);
  void CRS_IRQHandler      (void) ALIAS(Default_Handler);
  void I2C4_EV_IRQHandler  (void) ALIAS(Default_Handler);
  void I2C4_ER_IRQHandler  (void) ALIAS(Default_Handler);
//! Vector table definitions (device part)
  WWDG_IRQHandler,
  PVD_PVM_IRQHandler,
  RTC_TAMP_STAMP_IRQHandler,
  RTC_WKUP_IRQHandler,
  FLASH_IRQHandler,
  RCC_IRQHandler,
  EXTI0_IRQHandler,
  EXTI1_IRQHandler,
  EXTI2_IRQHandler,
  EXTI3_IRQHandler,
  EXTI4_IRQHandler,
  DMA1_CH1_IRQHandler,
  DMA1_CH2_IRQHandler,
  DMA1_CH3_IRQHandler,
  DMA1_CH4_IRQHandler,
  DMA1_CH5_IRQHandler,
  DMA1_CH6_IRQHandler,
  DMA1_CH7_IRQHandler,
  ADC1_IRQHandler,
  CAN1_TX_IRQHandler,
  CAN1_RX0_IRQHandler,
  CAN1_RX1_IRQHandler,
  CAN1_SCE_IRQHandler,
  EXTI9_5_IRQHandler,
  TIM1_BRK_TIM15_IRQHandler,
  TIM1_UP_TIM16_IRQHandler,
  TIM1_TRG_COM_IRQHandler,
  TIM1_CC_IRQHandler,
  TIM2_IRQHandler,
  TIM3_IRQHandler,
  0,
  I2C1_EV_IRQHandler,
  I2C1_ER_IRQHandler,
  I2C2_EV_IRQHandler,
  I2C2_ER_IRQHandler,
  SPI1_IRQHandler,
  SPI2_IRQHandler,
  USART1_IRQHandler,
  USART2_IRQHandler,
  USART3_IRQHandler,
  EXTI15_10_IRQHandler,
  RTC_ALARM_IRQHandler,
  DFSDM1_FLT3_IRQHandler,
  0,
  0,
  0,
  0,
  0,
  0,
  SDMMC1_IRQHandler,
  0,
  SPI3_IRQHandler,
  UART4_IRQHandler,
  0,
  TIM6_DACUNDER_IRQHandler,
  TIM7_IRQHandler,
  DMA2_CH1_IRQHandler,
  DMA2_CH2_IRQHandler,
  DMA2_CH3_IRQHandler,
  DMA2_CH4_IRQHandler,
  DMA2_CH5_IRQHandler,
  DFSDM1_IRQHandler,
  DFSDM2_IRQHandler,
  DFSDM1_FLT2_IRQHandler,
  COMP_IRQHandler,
  LPTIM1_IRQHandler,
  LPTIM2_IRQHandler,
  USB_FS_IRQHandler,
  DMA2_CH6_IRQHandler,
  DMA2_CH7_IRQHandler,
  LPUART1_IRQHandler,
  QUADSPI_IRQHandler,
  I2C3_EV_IRQHandler,
  I2C3_ER_IRQHandler,
  SAI1_IRQHandler,
  0,
  SWPMI1_IRQHandler,
  TSC_IRQHandler,
  LCD_IRQHandler,
  AES_IRQHandler,
  RNG_IRQHandler,
  FPU_IRQHandler,
  CRS_IRQHandler,
  I2C4_EV_IRQHandler,
  I2C4_ER_IRQHandler,

#endif // 0
#endif // STM32L4x2_GENERATED_HEADER

