#include <QDesktopWidget>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
/*
#undef  qDebug
#define qDebug(p, ...)
*/
MainWindow::MainWindow (QWidget *parent)
  : QMainWindow (parent), sudoku(true), canvas(sudoku, 800, 600) {
  ui  = new Ui_MainWindow;
  ui->setupUi (this);
  setWindowTitle ("Sudoku");
  setWindowIcon  (QIcon(":ico"));
//setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//
  connect (ui->actionExport, SIGNAL(triggered(bool)), this, SLOT(Export()));
  connect (ui->actionClose,  SIGNAL(triggered(bool)), this, SLOT(close()));
  connect (ui->widget, SIGNAL(pressed(int)), this, SLOT(keyAction(int)));
  ui->widget->setFocus();
  canvas.drawings();
  ShowImage ();
}

MainWindow::~MainWindow () {
  delete ui;
}
void MainWindow::ShowImage () {
  int x, y;
  const uint8_t * data = canvas.getData (x, y);
  QImage img (x, y, QImage::Format_ARGB32);
  uint32_t * pdata = reinterpret_cast<uint32_t*>(img.bits());
  const int len = x * y;
  for (int n=0; n<len; n++) {
    const int xi = n / 8;
    const int xn = n % 8;
    uint8_t  pix = data [xi];
    if (pix & (1 << xn)) pdata [n] = 0xFF00FF00;
    else                 pdata [n] = 0xFF000000;
  }
  ui->widget->setPixmap (img);
}
void MainWindow::Export () {
  QString outFile = QFileDialog::getSaveFileName(this,
     tr("Export Image"), ".", tr("Image Files (*.png)"));
  if (outFile.isEmpty()) return;
  int x, y;
  const uint8_t * data = canvas.getData (x, y);
  QImage img (x, y, QImage::Format_ARGB32);
  uint32_t * pdata = reinterpret_cast<uint32_t*>(img.bits());
  const int len = x * y;
  for (int n=0; n<len; n++) {
    const int xi = n / 8;
    const int xn = n % 8;
    uint8_t  pix = data [xi];
    if (pix & (1 << xn)) pdata [n] = 0xFF00FF00;
    else                 pdata [n] = 0xFF000000;
  }
  img.save(outFile);
}
void MainWindow::keyAction (int n) {
  if ((n >= '1') and (n <= '9')) {
    canvas.number (n - '0');
    ShowImage();
    return;
  }
  const Qt::Key k = (Qt::Key) n;
  ARROWS arr = NO_KEY;
  switch (k) {
    case Qt::Key_Escape :
      canvas.drawings ();
      ShowImage();
      return;
    case Qt::Key_Enter  :
    case Qt::Key_Return :
      canvas.enter ();
      ShowImage();
      return;
    case Qt::Key_Backspace :
      canvas.backup ();
      ShowImage();
      return;
    case Qt::Key_Insert :
      sudoku.save ();
      return;
    case Qt::Key_Up     : arr = ARROW_UP;    break;
    case Qt::Key_Down   : arr = ARROW_DOWN;  break;
    case Qt::Key_Left   : arr = ARROW_LEFT;  break;
    case Qt::Key_Right  : arr = ARROW_RIGHT; break;
    default: break;
  }
  if (arr != NO_KEY) {
    canvas.arrow (arr);
    ShowImage();
    return;
  }
  // printf("key: %08X\n", n); // unexpected
}
