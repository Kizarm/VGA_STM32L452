#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>

class ImageView : public QWidget {
    Q_OBJECT
  public:
    ImageView(QWidget*);
    virtual ~ImageView();
    
    void setPixmap (const QImage & p);
  signals:
    void pressed       (int);
  protected:
    void paintEvent    ( QPaintEvent  * event ) override;
    void keyPressEvent ( QKeyEvent    * event ) override;

  private:
    QRect   rect;
    QImage  pm;
};

#endif // IMAGEVIEW_H
