#include <QApplication>
#include "./mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  RenderEngine grapher;

  QSurfaceFormat format;
  format.setProfile(QSurfaceFormat::CompatibilityProfile);
  format.setVersion(4,2);
  format.setSamples(4);
  format.setSwapInterval(1);
  //grapher.setFormat(format);
  grapher.show();
  return a.exec();
}
