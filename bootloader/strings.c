#include "stdint.h"
#include "wchar.h"
#include "usb_std.h"

static const uint8_t str_0[] =  {0x04,0x03,0x09,0x04};

#define WSTR1 (L"Kizarm labs.")
#define WSTR2 (L"SPI NOR disc on STM32L452")
#define WSTR3 (L"00001")
#define WSTR4 (L"Data Interface")

struct w_string_desc {
  uint8_t       len, typ;
  const wchar_t str [];
}__attribute__((packed));

static const struct w_string_desc t1 = { sizeof WSTR1, USB_DTYPE_STRING, {WSTR1}};
static const struct w_string_desc t2 = { sizeof WSTR2, USB_DTYPE_STRING, {WSTR2}};
static const struct w_string_desc t3 = { sizeof WSTR3, USB_DTYPE_STRING, {WSTR3}};
static const struct w_string_desc t4 = { sizeof WSTR4, USB_DTYPE_STRING, {WSTR4}};

const struct usb_string_descriptor * const dtable[] = {
  (struct usb_string_descriptor *) & str_0,
  (struct usb_string_descriptor *) & t1,
  (struct usb_string_descriptor *) & t2,
  (struct usb_string_descriptor *) & t3,
  (struct usb_string_descriptor *) & t4,
};

#ifdef __clang__
void * __aeabi_memcpy (void * dest, const void * src, size_t n) {
  const char * s = (const char *) src;
  char       * d = (char       *) dest;
  for (uint32_t i=0; i<n; i++)  d[i] = s[i];
  return dest;
}
void * memcpy(void * dest, const void * src, size_t n) {
  return __aeabi_memcpy(dest, src, n);
}
#endif //__clang__
