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
    // head1->setRotation(p.x, p.y, p.z);
    Bone* bHead1 = new Bone(head1);

    Shape* head2 = new Cone(0.02, 0.02, Point(0, 0, -0.45));
    head2->setSurface(surface);

    // The bottom arrow needs to rotate the other way - this works for 90 degrees ;)
    head2->setRotation(0, 180, 0);
    Bone* bHead2 = new Bone(head2);

    bShaft->addChild("TopArrowHead", bHead1);
    bShaft->addChild("BottomArrowHead", bHead2);

    bShaft->setRotation(p.x, p.y, p.z);

    return bShaft;
}

Bone* createMan()
{
    ColouredSurface* red = new ColouredSurface(1, 0, 0);
    ColouredSurface* green = new ColouredSurface(0, 1, 0);
    ColouredSurface* blue = new ColouredSurface(0, 0, 1);

    Shape* pelvis = new Cylinder(0.1, 0.15, Point(0.3, 0, 0));
    pelvis->setSurface(blue);
    Bone* bPelvis = new Bone(pelvis);
    pelvis->setRotation(90, 0, 0);

    Shape* chest = new Cylinder(0.1, 0.1, Point(0, 0.125, 0));
    chest->setSurface(green);
    Bone* bChest = new Bone(chest);
    chest->setRotation(90, 0, 0);

    Shape* head = new Sphere(0.08, Point(0, 0.13, 0));
    head->setSurface(blue);
    Bone* bHead = new Bone(head);
    head->setRotation(90, 0, 0);

    Shape* upperLeftArm = new Cylinder(0.02, 0.08, Point(-0.12, 0, 0));
    upperLeftArm->setSurface(red);
    upperLeftArm->setRotation(90, 0, 0);
    Bone* ula = new Bone(upperLeftArm);

    Shape* lowerLeftArm = new Cylinder(0.02, 0.08, Point(0, -0.08, 0));
    lowerLeftArm->setSurface(green);
    lowerLeftArm->setRotation(90, 0, 0);
    Bone* lla = new Bone(lowerLeftArm);

    Shape* upperRightArm = new Cylinder(0.02, 0.08, Point(0.12, 0, 0));
    upperRightArm->setSurface(red);
    upperRightArm->setRotation(90, 0, 0);
    Bone* ura = new Bone(upperRightArm);

    Shape* lowerRightArm = new Cylinder(0.02, 0.08, Point(0, -0.08, 0));
    lowerRightArm->setSurface(green);
    lowerRightArm->setRotation(90, 0, 0);
    Bone* lra = new Bone(lowerRightArm);

    bPelvis->addChild("Chest", bChest);
    
    bChest->addChild("Head", bHead);
    bChest->addChild("UpperRightArm", ura);
    bChest->addChild("UpperLeftArm", ula);

    ula->addChild("LowerArm", lla);
    ura->addChild("LowerArm", lra);

    ura->setRotation(90, 0, 0);

    return bPelvis;
}

GLPolygonWidget::GLPolygonWidget(QWidget* parent, Scene* scene) 
{
    this->parent = parent;
    this->scene = scene;
    this->rotateStartPoint = Point(0, 0, 0);
    this->rotateBy = Point(0, 0, 0);

    // Arrow 1
    ColouredSurface* red = new ColouredSurface(1, 0, 0);
    Bone* arrow1 = createArrow(red, Point(90, 0, 0));

    // Arrow 2
    ColouredSurface* green = new ColouredSurface(0, 1, 0);
    Bone* arrow2 = createArrow(green, Point(0, 90, 0));

    // Arrow 3
    ColouredSurface* blue = new ColouredSurface(0, 0, 1);
    Bone* arrow3 = createArrow(blue, Point(0, 0, 90));

    // Create man
    Bone* man = createMan();

    scene->addShape("Arrow1", arrow1);
    scene->addShape("Arrow2", arrow2);
    scene->addShape("Arrow3", arrow3);
    scene->addShape("RunningMan", man);

    // glRotatef(-90, 0.0, 1.0, 0.0);
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
