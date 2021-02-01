#include "main.h"

int main (int argc, char *argv[]) {
  // QApplication::setStyle("plastique");
  QApplication a (argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
