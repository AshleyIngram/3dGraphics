#include <QWidget>
#include <QMouseEvent>
#include "GLPolygonWidget.h"
#include "GLPolygonWindow.h"
#include <iostream>
#include "Cone.h"
#include "Sphere.h"
#include "Cylinder.h"

GLPolygonWidget::GLPolygonWidget(QWidget* parent, Scene* scene) 
{
    this->parent = parent;
    this->scene = scene;

    Shape* s = new Cone(0.2, 0.2, Point(-0.5, 0.5, 0));
    this->scene->addShape("Cone", s);
    s->rotateX(50);

    Shape* s2 = new Sphere(0.2, Point(0.5, 0.5, 0.5));
    this->scene->addShape("Sphere", s2);

    Shape* c = new Cylinder(Point(-0.5, -0.5, -0.5));
    this->scene->addShape("Cylinder", c);
    c->rotateX(40);
    c->rotateY(100);
    c->rotateZ(80);
}

// Initial OpenGL setup
void GLPolygonWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.3, 0.3, 0.3, 0.0);
}

// Resize the viewport
void GLPolygonWidget::resizeGL(int w, int h)
{       
    glViewport(0, 0, w, h);
}

// Repaint OpenGL widgets
void GLPolygonWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Render child polygon 
    scene->render();
    
    // Flush to render
    glFlush();
}

// Render the Polygon Widget
void GLPolygonWidget::render()
{
    GLPolygonWidget::paintGL();
}