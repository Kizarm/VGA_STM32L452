#include "worker.h"
#include "PMD85v2A.h"

static PMD85v2A pmd;

Worker::Worker () : QThread(), m_w (288), m_h (256), timer(nullptr) {
  const QSize sz (m_w, m_h);
  image = QImage (sz, QImage::Format_ARGB32);
  pmd.Init();
  connect (&timer,  SIGNAL(timeout()), this, SLOT(update()));
  timer.start (100);
}

Worker::~Worker() {
  if (timer.isActive()) {
    timer.stop();
  }
  if (isRunning()) {
    terminate();
    wait();
  }
}
void Worker::update() {
  uint32_t * iptr = reinterpret_cast<uint32_t*> (image.bits());
  uint8_t  * dptr = pmd.Base() + 0xC000;
  for (unsigned y=0; y<m_h; y++) {
    for (unsigned x=0; x<m_w; x++) {
      const unsigned iidx = y * m_w + x;
      const unsigned dbdx = y * 64 + (x / 6);
      const uint8_t  dmsk = (1u <<   (x % 6));
      if (dptr [dbdx] & dmsk) iptr [iidx] = 0xFF00FF00;
      else                    iptr [iidx] = 0xFF000000;
    }
  }
  emit newImage (&image);
}

void Worker::run() {
  pmd.Reset();
  while (true) {
    unsigned n = 20;
    while (--n) pmd.Step();
    usleep (10);
  }
}
// tohle asi nebude u fyzicke klavesnice nutne
static SDL_SCAN_CODES remap (const Qt::Key key) {
  switch (key) {
    case Qt::Key_Exclam:      return SDL_SCANCODE_1;
    case Qt::Key_At:          return SDL_SCANCODE_2;
    case Qt::Key_NumberSign:  return SDL_SCANCODE_3;
    case Qt::Key_Dollar:      return SDL_SCANCODE_4;
    case Qt::Key_Percent:     return SDL_SCANCODE_5;
    case Qt::Key_AsciiCircum: return SDL_SCANCODE_6;
    case Qt::Key_Ampersand:   return SDL_SCANCODE_7;
    case Qt::Key_Asterisk:    return SDL_SCANCODE_8;
    case Qt::Key_ParenLeft:   return SDL_SCANCODE_9;
    case Qt::Key_ParenRight:  return SDL_SCANCODE_0;
    case Qt::Key_Underscore:  return SDL_SCANCODE_MINUS;
    case Qt::Key_Plus:        return SDL_SCANCODE_EQUALS;
    case Qt::Key_BraceLeft:   return SDL_SCANCODE_LEFTBRACKET;
    case Qt::Key_Bar:         return SDL_SCANCODE_BACKSLASH;
    case Qt::Key_BraceRight:  return SDL_SCANCODE_RIGHTBRACKET;
    case Qt::Key_Colon:       return SDL_SCANCODE_SEMICOLON;
    case Qt::Key_QuoteDbl:    return SDL_SCANCODE_APOSTROPHE;
    case Qt::Key_Less:        return SDL_SCANCODE_PERIOD;
    case Qt::Key_Greater:     return SDL_SCANCODE_COMMA;
    case Qt::Key_Question:    return SDL_SCANCODE_SLASH;
    /*
    case Qt:::               return 
    */
    default:                return SDL_ZERO_CODE;
  }
}

void Worker::keyboard (QKeyEvent * event, bool pressed) {
  // qDebug ("Key 0x%08X %s", event->key(), pressed ? "pressed" : "released");
  const SDL_SCAN_CODES sd_code = remap (static_cast<Qt::Key>(event->key()));
  if (sd_code == SDL_ZERO_CODE) {
    const SDL_SCAN_CODES code = static_cast<SDL_SCAN_CODES> (event->key());
    pmd.Keyboard (   code, pressed);
  } else {
    pmd.Keyboard (sd_code, pressed);
  }
}
