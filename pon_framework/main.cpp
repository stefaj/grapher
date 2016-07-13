#include <QApplication>
#include "./renderengine.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  RenderEngine pon;
  QSurfaceFormat format;
  format.setProfile(QSurfaceFormat::CompatibilityProfile);
  format.setVersion(4,2);
  format.setSamples(4);
  format.setSwapInterval(1);
  pon.setFormat(format);
  pon.show();
  return a.exec();
}
