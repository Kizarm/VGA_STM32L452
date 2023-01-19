#include "libwasm.h"
#include "sudoku.h"
#include "canvas.h"

////////////////////////////////////////////////////////////////////////////////////
extern "C" {
  extern void __wasm_call_ctors();
  extern char __data_end;
  extern char __heap_base;
  extern char __global_base;
  extern char __memory_base;
  extern char __table_base;
  extern void IMPORT(ReplotPass)(const uint8_t * ptr, const int len);
  extern void EXPORT(init)      (const int memlen);
  extern void EXPORT(InitImage) ();
  extern void EXPORT(Save)      ();
  extern void EXPORT(Enter)     ();
  extern void EXPORT(Escape)    ();
  extern void EXPORT(Backspace) ();
  extern void EXPORT(Delete)    ();
  extern void EXPORT(End)       ();
  extern void EXPORT(Arrow)     (const int);
  extern void EXPORT(Number)    (const int);
};
void init (const int memlen) {
  _HEAP_MAX = reinterpret_cast<char*> (memlen);   // před prvním voláním malloc() - může být i v konstruktorech
  __wasm_call_ctors();                            // nutné volání statických konstruktorů pokud máme statické třídy
}
class ImageWrap {
  const int  width, height, screen_size;
  uint32_t * idata;
  
  Sudoku sudoku;
  Canvas canvas;
  public:
    ImageWrap ();
    ~ImageWrap ();
    uint8_t * getData () const { return reinterpret_cast<uint8_t*>(idata); };
    size_t    getSize () const { return (screen_size * sizeof(uint32_t)); };
    void      Enter   () {
      canvas.enter();
      ShowImg ();
    }
    void      Escape ()  {
      canvas.drawings ();
      ShowImg ();
    }
    void      Backspace () {
      canvas.backup ();
      ShowImg ();
    }
    void      Delete () {
      canvas.set_new ();
      ShowImg ();
    }
    void      End    () {
      canvas.solve ();
      ShowImg ();
    }
    void      Save   () {
      sudoku.save ();
    }
    void      Arrow  (const ARROWS a) {
      canvas.arrow (a);
      ShowImg ();
    }
    void      Number (const int n) {
      canvas.number (n);
      ShowImg ();
    }
  protected:
    void      ShowImg ();
};
ImageWrap::ImageWrap() : width(800), height(600), screen_size(width * height),
  sudoku (), canvas (sudoku, width, height) {
  idata = new uint32_t [screen_size];
}
ImageWrap::~ImageWrap() {
  delete [] idata;
  idata = nullptr;
}
void ImageWrap::ShowImg() {
  int x, y;
  const uint8_t * data = canvas.getData (x, y);
  uint32_t * pdata = reinterpret_cast<uint32_t*>(idata);
  const int len = x * y;
  for (int n=0; n<len; n++) {
    const int xi = n / 8;
    const int xn = n % 8;
    uint8_t  pix = data [xi];
    if (pix & (1 << xn)) pdata [n] = 0xFF00FF00u;
    else                 pdata [n] = 0xFF000000u;
  }
  ReplotPass(getData(), getSize());
}

static ImageWrap * image = nullptr;

/*********************************************************************************/

void InitImage () {
  if (image) { delete image; image = nullptr; }
  image = new ImageWrap ();
  // printf("ptr = %p\n", image);
};
void Save () {
  if (image) image->Save();
}
void Enter () {
  if (image) image->Enter();
}
void Escape () {
  if (image) image->Escape();
}
void Backspace () {
  if (image) image->Backspace();
}
void Delete () {
  if (image) image->Delete();
}
void End () {
  if (image) image->End();
}
void Arrow (const int n) {
  ARROWS a = static_cast<ARROWS>(n);
  if (image) image->Arrow(a);
}
void Number (const int n) {
  if (image) image->Number (n);
}

