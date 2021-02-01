#include <QDesktopWidget>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
/*
#undef  qDebug
#define qDebug(p, ...)
*/
MainWindow::MainWindow (QWidget *parent)
  : QMainWindow (parent), worker() {
  ui  = new Ui_MainWindow;
  ui->setupUi (this);
  setWindowTitle ("Simulace");
  setWindowIcon  (QIcon(":ico"));
  started = false;
//setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//connect (ui->,      SIGNAL (),       this, SLOT ());
  connect (ui->actionScreenshot, SIGNAL(triggered(bool)), this, SLOT(Export()));
  connect (ui->actionExit,       SIGNAL(triggered(bool)), this, SLOT(close()));
  connect (ui->widget,      SIGNAL(keyboard(QKeyEvent*,bool)), &worker, SLOT(keyboard(QKeyEvent*,bool)));
  connect (ui->startButton, SIGNAL(clicked(bool)),     this, SLOT(StartStop()));
  connect (&worker,         SIGNAL(newImage(QImage*)), this, SLOT(refresh(QImage*)));
  ui->widget->setFocus();
}

MainWindow::~MainWindow () {
  delete ui;
}

void MainWindow::StartStop() {
  if (started) {
    started = false;
    ui->startButton->setText ("Start");
    if (worker.isRunning()) worker.terminate();
  } else {
    started = true;
    ui->startButton->setText ("Stop");
    worker.start ();
  }
  ui->widget->setFocus();
}
void MainWindow::refresh (QImage * img) {
  // qDebug ("refresh");
  ui->widget->setPixmap (* img);
}
void MainWindow::Export() {
  QString outFile = QFileDialog::getSaveFileName(this,
     tr("Export Image"), ".", tr("Image Files (*.png)"));
  if (outFile.isEmpty()) return;
  QImage * pimg = worker.getImage();
  pimg->save (outFile);
}
