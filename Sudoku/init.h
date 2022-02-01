#ifndef _INIT_H_
#define _INIT_H_
/** @class 
 *  @brief Konstantní pole
 * 
 * */
template<class T, const int N> class StaticArray {
  T dummy;
  T data [N];
  public:
    /** Konstruktor.
     * */
    explicit StaticArray (const T & v) noexcept : dummy() {
      for (int n=0; n<N; n++) data [n] = v;
    }
    T & operator[] (const int index) {
      if (index <  0) return dummy;  // kontrola mezí -
      if (index >= N) return dummy;  // nevyhodí chybu, jen vrátí nesmyslná data
      return data [index];
    }
    /** @class iterator
     *  @brief range-based for () */
    class iterator {
      const T * ptr;
      public:
        iterator(const T * _ptr) : ptr (_ptr) {}
        iterator  operator++ ()                             { ++ptr;   return * this;    }
        bool      operator!= (const iterator & other) const { return   ptr != other.ptr; }
        const T & operator*  ()                       const { return * ptr;              }
    };
    iterator begin () const { return iterator (data    ); }
    iterator end   () const { return iterator (data + N); }
  protected:
};
#endif // _INIT_H_
