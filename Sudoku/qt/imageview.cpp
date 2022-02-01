#include "imageview.h"

ImageView::ImageView(QWidget * p) : QWidget(p) {

}

ImageView::~ImageView() {

}
void ImageView::setPixmap (const QImage & p) {
  pm = p;
  QPoint tl (0,0);
  QSize  sz = pm.size();
  resize (sz);
  rect = QRect (tl, sz);
  update();
}
void ImageView::paintEvent (QPaintEvent * ) {
  QPainter painter(this);
  painter.drawImage(rect, pm);
}
void ImageView::keyPressEvent (QKeyEvent * event) {
  emit pressed (event->key());
  QWidget::keyPressEvent (event);
}
