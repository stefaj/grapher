#include "mainwindow.h"
#include "layer.h"
#include "node.h"
#include "edge.h"

RenderEngine::RenderEngine(QWidget * parent) : QOpenGLWidget(parent) {

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
  gluLookAt(2, 2, 2, 0, 0, 0, 0, 0, 1); // side view
   //gluLookAt(0, 0, 2, 0, 0, 0, 0, 1, 0); // inverted ? top view
}

void RenderEngine::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //draw_splitter(0, 0, 0);
  //draw_onu(0.2, .2, 0);
  Layer phys = Layer("Physical",0);
  Layer log = Layer("Logical", 1);

  // Physical
  Node n1 = create_node(-0.5,0.5);
  Node n2 = create_node(0.5, 0.5);
  Node n3 = create_node(-0.5, -0.5);
  Node n4 = create_node(0.5, -0.5);

  Edge e1 = create_edge(n1,n3);
  Edge e2 = create_edge(n3,n4);
  Edge e3 = create_edge(n4,n2);
  Edge e4 = create_edge(n2,n1);

  phys.add_node(n1);
  phys.add_node(n2);
  phys.add_node(n3);
  phys.add_node(n4);

  phys.add_edge(e1);
  phys.add_edge(e2);
  phys.add_edge(e3);
  phys.add_edge(e4);

  Edge l1 = create_edge(n1,n2);
  Edge l2 = create_edge(n1,n3);
  Edge l3 = create_edge(n1,n4);
  Edge l4 = create_edge(n2,n3);
  Edge l5 = create_edge(n2,n4);
  Edge l6 = create_edge(n3,n4);
  log.add_edge(l1);
  log.add_edge(l2);
  log.add_edge(l3);
  log.add_edge(l4);
  log.add_edge(l5);
  log.add_edge(l6);
  log.add_node(n1);
  log.add_node(n2);
  log.add_node(n3);
  log.add_node(n4);

  phys.draw();
  log.draw();

}

RenderEngine::~RenderEngine() {

}
