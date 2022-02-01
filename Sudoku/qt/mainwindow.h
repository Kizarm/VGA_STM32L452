#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imageview.h"
#include "canvas.h"
#include "sudoku.h"

class Ui_MainWindow;

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow  (QWidget *parent = 0);
    ~MainWindow ();
  protected:
    void ShowImage ();
  public slots:
    void keyAction (int n);
    void Export ();
  private:
    Ui_MainWindow * ui;
    Sudoku   sudoku;
    Canvas   canvas;
};

#endif // MAINWINDOW_H
