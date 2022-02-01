#include <emscripten/bind.h>
#include <emscripten.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>
#include "sudoku.h"
#include "canvas.h"

static void CallBack () {
  EM_ASM ({
    ReplotPass ();
  });
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
  CallBack();
}

static ImageWrap * image = nullptr;

/*********************************************************************************/

void Init () {
  if (image) { delete image; image = nullptr; }
  image = new ImageWrap ();
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
void Arrow (const int n) {
  ARROWS a = static_cast<ARROWS>(n);
  if (image) image->Arrow(a);
}
void Number (const int n) {
  if (image) image->Number (n);
}

emscripten::val fg_data () {
  return emscripten::val (emscripten::typed_memory_view (image->getSize(), image->getData()));
}
EMSCRIPTEN_BINDINGS (my_bind) {
  emscripten::function ("Init",        Init);
  emscripten::function ("fg_data",     fg_data);
  emscripten::function ("Enter",       Enter);
  emscripten::function ("Escape",      Escape);
  emscripten::function ("Backspace",   Backspace);
  emscripten::function ("Arrow",       Arrow);
  emscripten::function ("Number",      Number);
  emscripten::function ("Save",        Save);
}
