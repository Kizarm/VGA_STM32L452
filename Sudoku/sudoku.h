#ifndef SUDOKU_H
#define SUDOKU_H
#ifdef __arm__
#define printf(...)
#else
#include <stdio.h>
#include <string>
#endif
#include "init.h"

static constexpr unsigned SUDHLF = 3u;    // 3 = normal, 4 = hexa, 5+ nefunguje
static_assert ((SUDHLF >= 2u) and (SUDHLF <= 4u), "SIZE ERROR");
static constexpr unsigned SUDMAX = SUDHLF * SUDHLF;
static constexpr unsigned SUDSQR = SUDMAX * SUDMAX;
typedef signed char index_t;             // pro normalni Sudoku muze byt i char
typedef signed char value_t;

struct Possible {
  index_t nums [SUDMAX];
  value_t npos;
  Possible (const int n = 0) {
    npos = n;
    clear();
  }
  void clear () {
    for (unsigned n=0; n<SUDMAX; n++) nums [n] = 0;
  }
  bool uniq (int & k) {
    unsigned m = 0;
    for (unsigned n=0; n<SUDMAX; n++) {
      if (nums [n]) {
        m += 1; k = n + 1;
      }
    }
    if (m == 1) return true;
    return false;
  }
  bool contains (const int k) {
    const int max = SUDMAX;
    for (int n=0; n<max; n++) {
      if ((nums [n]) and ((n + 1) == k)) return true;
    }
    return false;
  }
};

struct Set {
  unsigned order;
  index_t  indexes  [SUDMAX];
  explicit Set  () noexcept;
  bool contains (const value_t * grid, const value_t value) const;
  void add_idx  (const index_t value);
};

class Sudoku {
  bool                          randomize;
  StaticArray<index_t, SUDMAX>  numberList;
  value_t                       grid [SUDSQR];
  value_t                       back [SUDSQR];
  Set r [SUDMAX], c [SUDMAX], s [SUDMAX];
  public:
    explicit   Sudoku   (const bool rnd = true) noexcept;
    value_t  * getGrid  () { return grid; }
    void       fill     () { clear (); solve (grid, randomize); }
    void       remove   ();
    value_t    find_min ();
    void       help     (Possible & p) const;
    void       backup   ();
    void       save     () {
      for (unsigned n=0; n<SUDSQR; n++) back [n] = grid [n];
    }
    void       clear    ();
    bool       solve    () { return solve (grid, false); }
  protected:
    void       uniq     (value_t * const data, int & sol);
    bool       solve    (value_t * const data, const bool rnd = false);
    bool       not_used (const value_t * const data, const unsigned n, const index_t value) const;
};

#endif // SUDOKU_H
