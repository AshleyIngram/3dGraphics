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

Bone* createArrow(Surface* surface, Point p)
{
    Shape* shaft = new Cylinder(0.01, 0.9, Point(0, 0, 0));
    shaft->setSurface(surface);
    Bone* bShaft = new Bone(shaft);
    
    Shape* head1 = new Cone(0.02, 0.02, Point(0, 0, 0.45));
    head1->setSurface(surface);
    head1->setRotation(p.x, p.y, p.z);
    Bone* bHead1 = new Bone(head1);

    Shape* head2 = new Cone(0.02, 0.02, Point(0, 0, -0.45));
    head2->setSurface(surface);

    // The bottom arrow needs to rotate the other way - this works for 90 degrees ;)
    head2->setRotation(p.x * 3, p.y * 3, p.z * 3);
    Bone* bHead2 = new Bone(head2);

    bShaft->addChild("TopArrowHead", bHead1);
    bShaft->addChild("BottomArrowHead", bHead2);

    bShaft->setRotation(p.x, p.y, p.z);

    return bShaft;
}

GLPolygonWidget::GLPolygonWidget(QWidget* parent, Scene* scene) 
{
    this->parent = parent;
    this->scene = scene;

    // Arrow 1
    ColouredSurface* red = new ColouredSurface(1, 0, 0);
    Bone* arrow1 = createArrow(red, Point(90, 0, 0));

    // Arrow 2
    ColouredSurface* green = new ColouredSurface(0, 1, 0);
    Bone* arrow2 = createArrow(green, Point(0, 90, 0));

    // Arrow 3
    ColouredSurface* blue = new ColouredSurface(0, 0, 1);
    Bone* arrow3 = createArrow(blue, Point(0, 0, 90));

    scene->addShape("Arrow1", arrow1);
    scene->addShape("Arrow2", arrow2);
    scene->addShape("Arrow3", arrow3);

    glRotatef(-90, 0.0, 1.0, 0.0);
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