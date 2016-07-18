#ifndef RENDERER_H
#define RENDERER_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "node.h"
#include "edge.h"



inline RGB get_color_layer(int layer_id){
    switch (layer_id)
    {
        case 0: return create_color(0,0,0);
        case 1: return create_color(0,0,1);
        case 2: return create_color(0,1,0);
        case 3: return create_color(0,1,1);
        case 4: return create_color(1,0,0);
        case 5: return create_color(1,0,1);
        case 6: return create_color(1,1,0);
        case 7: return create_color(1,1,1);
    }

}

inline void draw_edge(Edge e, float height)
{
    RGB color = get_color_layer( static_cast<int>(height) );
    glLineWidth(2.5);
    glColor3f(color.r, color.g, color.b);

    glBegin(GL_LINES);
    glVertex3f(e.source.pos.x(), e.source.pos.y(), height);
    glVertex3f(e.target.pos.x(), e.target.pos.y(), height);
    glEnd();

}

inline void draw_splitter(Node n, float z) {

    RGB color = get_color_layer( static_cast<int>(z) );
    float x = n.pos.x();
    float y = n.pos.y();

  glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.05 + x, -0.05 + y, z);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f( 0.05 + x, -0.05 + y, z);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f( x,  0.05 + y, z);
  glEnd();
}


inline void draw_onu(Node n, float z) {

    RGB color = get_color_layer( static_cast<int>(z) );
    float x = n.pos.x();
    float y = n.pos.y();


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

inline void draw_central_office(Node n, float z) {


   float x = n.pos.x();
   float y = n.pos.y();
    RGB color = get_color_layer( static_cast<int>(z) );

  int triangleAmount = 20; //# of triangles used to draw circle
  GLfloat radius = 0.025f; //radius
  GLfloat twicePi = 2.0f * 3.14159f;
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(color.r, color.g, color.b);
    glVertex3f(x, y, z); // center of circle
    for(int i = 0; i <= triangleAmount;i++) {
      glVertex3f(x + (radius * cos(i *  twicePi / triangleAmount)),
                 y + (radius * sin(i * twicePi / triangleAmount)),
                 z);
    }
  glEnd();
}




inline void draw_node(Node n, float height) {


    switch (n.type) {
        case CentralOffice:
            draw_central_office(n,height);
            break;

        case Splitter:
            draw_splitter(n,height);
            break;

        case ONU:
            draw_onu(n,height);
            break;

        default:
            draw_central_office(n,height);
            break;
    }
}


#endif // RENDERER_H
