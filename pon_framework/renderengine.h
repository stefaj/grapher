#ifndef RENDERENGINE_H
#define RENDERENGINE_H
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

class RenderEngine : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
  public:
    explicit RenderEngine(QWidget * parent = 0);
    ~RenderEngine();

  protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
  private:
    void draw_splitter(float x, float y, float z);
    void draw_onu(float x, float y, float z);
    void draw_central_office(float x, float y, float z);

};

#endif // RENDERENGINE_H
