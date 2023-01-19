#include "libwasm.h"
#define CHAR_BIT  __CHAR_BIT__
#define INT_MAX   __INT_MAX__
typedef __SIZE_TYPE__ size_t;
static void prng_seed_bytes (const void *key, size_t size);
static unsigned prng_get_uint (void);
/* Nonzero if PRNG has been seeded. */
static int seeded = 0;

void srand (const int t) {
//printf ("seed: %d\n", t);
  prng_seed_bytes (&t, sizeof t);
}
int  rand  () {
  if (!seeded) srand(0xabcd);
  return prng_get_uint() & INT_MAX;
}

/* RC4-based pseudo-random state. */
static unsigned char s[256];
static int s_i, s_j;

/* Swap bytes that A and B point to. */

#define SWAP_BYTE(A, B)                         \
        do {                                    \
                unsigned char swap_temp = *(A); \
                *(A) = *(B);                    \
                *(B) = swap_temp;               \
        } while (0)

/* Retrieves one octet from the array BYTES, which is N_BYTES in
   size, starting at an offset of OCTET_IDX octets.  BYTES is
   treated as a circular array, so that accesses past the first
   N_BYTES bytes wrap around to the beginning. */
static unsigned char get_octet (const void *bytes_, size_t n_bytes, size_t octet_idx) {
  const unsigned char *bytes = bytes_;
  if (CHAR_BIT == 8) 
    return bytes[octet_idx % n_bytes];
  else {
      size_t first_byte = octet_idx * 8 / CHAR_BIT % n_bytes;
      size_t start_bit = octet_idx * 8 % CHAR_BIT;
      unsigned char c = (bytes[first_byte] >> start_bit) & 255;

      size_t bits_filled = CHAR_BIT - start_bit;
      if (CHAR_BIT % 8 != 0 && bits_filled < 8) {
          size_t bits_left = 8 - bits_filled;
          unsigned char bits_left_mask = (1u << bits_left) - 1;
          size_t second_byte = first_byte + 1 < n_bytes ? first_byte + 1 : 0;

          c |= (bytes[second_byte] & bits_left_mask) << bits_filled;
      }
      return c;
  }
}

/* Seeds the pseudo-random number based on the SIZE bytes in
   KEY.  At most the first 2048 bits in KEY are used. */
static void prng_seed_bytes (const void *key, size_t size) {
  int i, j;

  for (i = 0; i < 256; i++) s[i] = i;
  for (i = j = 0; i < 256; i++) {
      j = (j + s[i] + get_octet (key, size, i)) & 255;
      SWAP_BYTE (s + i, s + j);
  }

  s_i = s_j = 0;
  seeded = 1;
}

/* Returns a pseudo-random integer in the range [0, 255]. */
unsigned char prng_get_octet (void) {
  // if (!seeded) prng_seed_time ();

  s_i = (s_i + 1) & 255;
  s_j = (s_j + s[s_i]) & 255;
  SWAP_BYTE (s + s_i, s + s_j);

  return s[(s[s_i] + s[s_j]) & 255];
}
/* Returns a pseudo-random unsigned int in the range [0,
   UINT_MAX]. */
static unsigned prng_get_uint (void) {
  unsigned uint;
  size_t bits;

  uint = prng_get_octet ();
  for (bits = 8; bits < CHAR_BIT * sizeof uint; bits += 8) 
    uint = (uint << 8) | prng_get_octet ();
  return uint;
}
