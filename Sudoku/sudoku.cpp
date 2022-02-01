#include "sudoku.h"
#ifdef __arm__
#include "rngclass.h"
static RngClass Generator;
static inline unsigned rand () {
  return Generator.Read();
}

#else
#include <stdlib.h>
#include <time.h>
#endif

static constexpr value_t UNASSIGNED = -1;

Set::Set() noexcept : order(0u) {
  for (unsigned n=0u; n<SUDMAX; n++) indexes [n] = UNASSIGNED;
}
bool Set::contains (const value_t * grid, const value_t value) const {
  for (index_t n : indexes) {
    if (grid [n] == value) return true;
  }
  return false;
}
void Set::add_idx (const index_t value) {
  indexes [order++] = value;
}
/*********************************************************************/
static void shuffle (StaticArray<index_t, SUDMAX> & data, const bool rnd) {
  if (!rnd) return;
  for (unsigned n=0u; n<SUDMAX; n++) {
    const unsigned m = rand() % SUDMAX;
    if (n == m) continue;
    const index_t t = data [n];
    data [n] = data [m];
    data [m] = t;
  }
}
static bool findUnassigned (const value_t * const data, unsigned & n) {
  for (n=0u; n<SUDSQR; n++) {
    if (data [n] == UNASSIGNED) return true;   // return unassiged index n
  }
  return false;
}
/*********************************************************************/
Sudoku::Sudoku (const bool rnd) noexcept : randomize(rnd), numberList (0) {
#ifndef __arm__  
  const time_t t = time (nullptr);
  srand (t);
#endif
  clear ();
  for (unsigned n=0u; n<SUDMAX; n++) numberList [n] = n + (SUDHLF < 4u ? 1 : 0);
  for (unsigned n=0u; n<SUDSQR; n++) {   // fill quards r,c,s
    const unsigned col = n % SUDMAX;
    const unsigned row = n / SUDMAX;
    const unsigned sqr = SUDHLF * (row / SUDHLF) + (col / SUDHLF);
    c[col].add_idx (n);
    r[row].add_idx (n);
    s[sqr].add_idx (n);
  }
}
bool Sudoku::solve (value_t * const data, const bool rnd) {
  unsigned n = 0u;
  if (!findUnassigned (data, n)) return true;   // END
  shuffle (numberList, rnd);
  for (index_t num : numberList) {
    if (not_used (data, n, num)) {
      data [n] = num;
      if (solve (data, rnd))     return true;
      data [n] = UNASSIGNED;
    }
  }
  return false;
}
void Sudoku::uniq (value_t * const data, int & sol) {
  unsigned n = 0u;
  if (!findUnassigned (data, n)) {
    sol += 1;
    return;   // END
  }
  for (index_t num : numberList) {
    if (sol > 1) break;
    if (not_used (data, n, num)) {
      data [n] = num;
      uniq (data, sol);
    }
    data [n] = UNASSIGNED;
  }
}

bool Sudoku::not_used (const value_t * const data, const unsigned int n, const index_t value) const {
  const unsigned col = n % SUDMAX;
  const unsigned row = n / SUDMAX;
  const unsigned sqr = SUDHLF * (row / SUDHLF) + (col / SUDHLF);
  if (c[col].contains (data, value)) return false;
  if (r[row].contains (data, value)) return false;
  if (s[sqr].contains (data, value)) return false;
  return true;
}
void Sudoku::remove() {
  for (unsigned n=0u; n<SUDMAX; n++) numberList [n] = n + (SUDHLF < 4u ? 1 : 0);
  value_t copy [SUDSQR];
  for (unsigned n=0u; n<SUDSQR; n++) copy [n] = grid [n];
  int attempts = 5, removed = 0, solutions;
  while (attempts) {
    index_t index = rand() % SUDSQR;
    while (copy [index] == UNASSIGNED) index = rand() % SUDSQR;
    value_t backup = copy [index];
    copy [index]   = UNASSIGNED;
    
    value_t work [SUDSQR];
    for (unsigned n=0u; n<SUDSQR; n++) work [n] = copy [n];
    solutions = 0;
    uniq (work, solutions);
    if (solutions != 1) {
      copy [index] = backup;
      attempts -= 1;
    } else removed += 1;
  }
  for (unsigned n=0u; n<SUDSQR; n++) grid [n] = copy [n];
  for (unsigned n=0u; n<SUDSQR; n++) back [n] = copy [n];
}
value_t Sudoku::find_min() {
  value_t result = UNASSIGNED;
  int min = SUDMAX + 1;
  for (unsigned n=0u; n<SUDSQR; n++) {
    if (grid [n] != UNASSIGNED) continue;
    
    int cnt = 0;
    for (index_t num : numberList) {
      if (not_used (grid, n, num)) {
        cnt += 1;
      }
    }
    if (cnt < min) {
      result = n;
      min = cnt;
    }
  }
  return result;
}
void Sudoku::help (Possible & p) const {
  const int n = p.npos;
  if (grid [n] != UNASSIGNED) return;
  int k = 0;
  for (index_t num : numberList) {
    if (not_used (grid, n, num)) {
      p.nums [k] = 1;
    }
    k += 1;
  }
}

void Sudoku::backup() {
  for (unsigned n=0u; n<SUDSQR; n++) grid [n] = back [n];
}

void Sudoku::clear() {
  for (unsigned n=0u; n<SUDSQR; n++) grid [n] = UNASSIGNED;
  for (unsigned n=0u; n<SUDSQR; n++) back [n] = UNASSIGNED;
}
