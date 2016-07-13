#include "renderengine.h"

RenderEngine::RenderEngine(QWidget * parent) : QOpenGLWidget(parent) {

}

void RenderEngine::draw_splitter(float x, float y, float z) {
  glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.05 + x, -0.05 + y, z);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f( 0.05 + x, -0.05 + y, z);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f( x,  0.05 + y, z);
  glEnd();
}

void RenderEngine::draw_onu(float x, float y, float z) {
  glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.05 + x, -0.05 + y, z);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f( x -0.05, 0.05 + y, z);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f( x + 0.05, y - 0.05, z);
  glEnd();

  glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.05 + x, 0.05 + y, z);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f( x -0.05, 0.05 + y, z);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f( x + 0.05, y - 0.05, z);
  glEnd();
}

void RenderEngine::draw_central_office(float x, float y, float z) {
  int triangleAmount = 20; //# of triangles used to draw circle
  GLfloat radius = 0.025f; //radius
  GLfloat twicePi = 2.0f * 3.14159f;
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(x, y, z); // center of circle
    for(int i = 0; i <= triangleAmount;i++) {
      glVertex3f(x + (radius * cos(i *  twicePi / triangleAmount)),
                 y + (radius * sin(i * twicePi / triangleAmount)),
                 z);
    }
  glEnd();
}

void RenderEngine::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(1.0, 1.0, 1.0, 1);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);
}

void RenderEngine::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90, (float)w / h, 0.01, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
}

void RenderEngine::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  draw_splitter(0, 0, 0);
  draw_onu(0.2, .2, 0);
  draw_central_office(0.5, 0.5, 0);

  glLineWidth(2.5);
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex3f(.5, .5, 0);
  glVertex3f(0.0, 0.0, 0.0);
  glEnd();
}

RenderEngine::~RenderEngine() {

}
