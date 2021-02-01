#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QImage>
#include <QTimer>
#include <QKeyEvent>

class Worker : public QThread {
  Q_OBJECT
  public:
    Worker();
    virtual ~Worker();
    QImage * getImage () {
      return & image;
    }
  signals:
    void newImage (QImage *);
  public slots:
    void update ();
    void keyboard (QKeyEvent * event, bool pressed);
  protected:
    void run ();
  private:
    const unsigned m_w, m_h;
    QImage image;
    QTimer timer;
};

#endif // WORKER_H
