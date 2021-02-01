#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "worker.h"

class Ui_MainWindow;

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow (QWidget *parent = 0);
    ~MainWindow ();
  protected:
  public slots:
    void StartStop ();
    void refresh   (QImage*);
    void Export    ();
  private:
    Ui_MainWindow * ui;
    Worker          worker;
    bool            started;
};

#endif // MAINWINDOW_H
