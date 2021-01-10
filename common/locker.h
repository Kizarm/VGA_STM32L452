#ifndef ARMLOCKER_H
#define ARMLOCKER_H
/** @file
 *  @brief  Architecture specific C/C++ atomic operation
 * 
 * Zákaz a povolení přerušení, specificky pro ARM Cortex-M0.
 * Pro Cortex-M3/4 lze použít pro počítadlo ve frontě ldrex / strex, což by
 * mohlo být efektivnější.
 * 
 * Jen pro třídu Fifo, velmi zjednodušené.
 */


#if __ARM_ARCH_6M__
namespace std {
  template<typename T>class atomic {
    volatile T t;
    public:
      atomic (const T o) : t(o) {};
      operator T() const {return t;};
      atomic<T> & operator+= (const T n) {
        asm volatile ("cpsid i");
        t += n;
        asm volatile ("cpsie i");
        return * this;
      };
      atomic<T> & operator-= (const T n) {
        asm volatile ("cpsid i");
        t -= n;
        asm volatile ("cpsie i");
        return * this;
      };
  };
};
#elif defined __clang__ && __ARM_ARCH_7EM__
namespace std {
  // pouze pro int
  template<typename T> class atomic {
    T t;
    public:
      atomic (const T o) : t(o) {}
      
      T load_exclusive (T * const ptr) const {
        T res;
        __asm volatile (
          "ldrex %0, [%1]"
          :"=r" (res): "r"(ptr)
        );
        return res;
      }
      unsigned store_exclusive (const T v, T * const ptr) {
        unsigned res;
        __asm volatile (
          "strex %0, %2, [%1]"
          :"=&r" (res): "r"(ptr), "r"(v)
        );
        return res;
      }
      T * const load_ptr () {
        return &t;
      }
      atomic & operator+= (int n) {
        T * const tmp = load_ptr();
        __asm volatile ("dmb sy");
        for (;;) {
          T e = load_exclusive (tmp);
          e += n;
          if (!store_exclusive(e, tmp)) break;
        }
        __asm volatile ("dmb sy");
        return * this;
      }
      atomic & operator-= (int n) {
        T * const tmp = load_ptr();
        __asm volatile ("dmb sy");
        for (;;) {
          T e = load_exclusive (tmp);
          e -= n;
          if (!store_exclusive(e, tmp)) break;
        }
        __asm volatile ("dmb sy");
        return * this;
      }
      operator T () const {
        T ret;
        __asm volatile (
          "dmb sy\n\t"
          "ldr %0, [%1]\n\t"
          "dmb sy\n"
          :"=r"(ret) : "r"(&t)
        );
        return ret;
      }
  };
};
#else // Normální architektury mají std::atomic v knihovně
  #include <atomic>
#endif


#endif // ARMLOCKER_H
