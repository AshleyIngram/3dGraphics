#include <QWidget>
#include <QMouseEvent>
#include "GLPolygonWidget.h"
#include "GLPolygonWindow.h"
#include <iostream>
#include "Cone.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "ColouredSurface.h"
#include "Bone.h"
#include "Person.h"
#include "TexturedSurface.h"
#include "Arrow.h"

GLPolygonWidget::GLPolygonWidget(QWidget* parent, Scene* scene) 
{
    this->parent = parent;
    this->scene = scene;
    this->rotateStartPoint = Point(0, 0, 0);
    this->rotateBy = Point(0, 0, 0);

    // Arrow 1
    ColouredSurface* red = new ColouredSurface(1, 0, 0);
    Bone* arrow1 = new Arrow(red, Point(90, 0, 0));

    // Arrow 2
    ColouredSurface* green = new ColouredSurface(0, 1, 0);
    Bone* arrow2 = new Arrow(green, Point(0, 90, 0));

    // Arrow 3
    ColouredSurface* blue = new ColouredSurface(0, 0, 1);
    Bone* arrow3 = new Arrow(blue, Point(0, 0, 90));

    scene->addShape("Arrow1", arrow1);
    scene->addShape("Arrow2", arrow2);
    scene->addShape("Arrow3", arrow3);
}

void GLPolygonWidget::mouseClickEvent(QMouseEvent* e)
{
    this->rotateStartPoint = Point(e->x(), e->y(), 0);
}

void GLPolygonWidget::mouseMoveEvent(QMouseEvent* e)
{
    rotateBy = Point(rotateStartPoint.x - e->x(), rotateStartPoint.y - e->y(), 0);
    rotateStartPoint = Point(e->x(), e->y(), 0);
    update();
}

// Initial OpenGL setup
void GLPolygonWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.3, 0.3, 0.3, 0.0);
    // Create man
    Bone* man = new Person();
    scene->addShape("RunningMan", man);
}

// Resize the viewport
void GLPolygonWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glOrtho(-1, 1, -1, 1, -1, 1);       
    glViewport(0, 0, w, h);
}

// Repaint OpenGL widgets
void GLPolygonWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Render child polygon
    glMatrixMode(GL_MODELVIEW);

    glRotatef(rotateBy.y, 0, 1, 0);
    glRotatef(rotateBy.x, 0, 0, 1);
    rotateBy = Point();
    scene->render();
    
    // Flush to render
    glFlush();
}

// Render the Polygon Widget
void GLPolygonWidget::render()
{
    GLPolygonWidget::paintGL();
}
