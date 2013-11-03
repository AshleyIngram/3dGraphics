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
#include "Pelvis.h"
#include "TexturedSurface.h"

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

    Shape* rootShape = new Cylinder(0, 0, Point(0, 0, 0));
    Pelvis* root = new Pelvis(rootShape);

    Shape* pelvis = new Cylinder(0.08, 0.15, Point(0.3, 0, 0));
    pelvis->setSurface(blue);
    Bone* bPelvis = new Bone(pelvis);
    pelvis->setRotation(90, 0, 0);

    root->addChild("Pelvis", bPelvis);
    
    Shape* chest = new Cylinder(0.08, 0.1, Point(0, 0.125, 0));
    chest->setSurface(green);
    Bone* bChest = new Bone(chest);
    chest->setRotation(90, 0, 0);

    Shape* head = new Sphere(0.08, Point(0, 0.13, 0));

    TexturedSurface* headTex = new TexturedSurface("./face.jpg");
    head->setTexture(headTex);
    Bone* bHead = new Bone(head);
    head->setRotation(90, 0, 0);

    Shape* upperLeftArm = new Cylinder(0.02, 0.08, Point(-0.1, 0, 0));
    upperLeftArm->setSurface(red);
    upperLeftArm->setRotation(90, 0, 0);
    Bone* ula = new Bone(upperLeftArm);
    ula->setJointOffset(0, -0.04, 0);

    Shape* upperLeftArmJoint = new Sphere(0.04, Point(-0.1, 0, 0));
    upperLeftArmJoint->setSurface(blue);
    upperLeftArmJoint->setRotation(90, 0, 0);
    Bone* ulaj = new Bone(upperLeftArmJoint);

    Shape* lowerLeftArm = new Cylinder(0.02, 0.08, Point(0, -0.08, 0));
    lowerLeftArm->setSurface(green);
    lowerLeftArm->setRotation(90, 0, 0);
    Bone* lla = new Bone(lowerLeftArm);
    lla->setJointOffset(0, -0.04, 0);

    Shape* lowerLeftArmJoint = new Sphere(0.03, Point(0, -0.08, 0));
    lowerLeftArmJoint->setSurface(blue);
    lowerLeftArmJoint->setRotation(90, 0, 0);
    Bone* llaj = new Bone(lowerLeftArmJoint);

    Shape* upperRightArm = new Cylinder(0.02, 0.08, Point(0.1, 0, 0));
    upperRightArm->setSurface(red);
    upperRightArm->setRotation(90, 0, 0);
    Bone* ura = new Bone(upperRightArm);
    ura->setJointOffset(0, -0.04, 0);

    Shape* upperRightArmJoint = new Sphere(0.04, Point(0.1, 0, 0));
    upperRightArmJoint->setSurface(blue);
    upperRightArmJoint->setRotation(90, 0, 0);
    Bone* uraj = new Bone(upperRightArmJoint);

    Shape* lowerRightArm = new Cylinder(0.02, 0.08, Point(0, -0.08, 0));
    lowerRightArm->setSurface(green);
    lowerRightArm->setRotation(90, 0, 0);
    Bone* lra = new Bone(lowerRightArm);
    lra->setJointOffset(0, -0.04, 0);

    Shape* lowerRightArmJoint = new Sphere(0.03, Point(0, -0.08, 0));
    lowerRightArmJoint->setSurface(blue);
    lowerRightArmJoint->setRotation(90, 0, 0);
    Bone* lraj = new Bone(lowerRightArmJoint);

    Shape* upperLeftLeg = new Cylinder(0.03, 0.09, Point(-0.04, -0.07, 0));
    upperLeftLeg->setSurface(red);
    upperLeftLeg->setRotation(90, 0, 0);
    Bone* ull = new Bone(upperLeftLeg);
    ull->setJointOffset(0, -0.04, 0);

    Shape* lowerLeftLeg = new Cylinder(0.03, 0.09, Point(0, -0.1, 0));
    lowerLeftLeg->setSurface(blue);
    lowerLeftLeg->setRotation(90, 0, 0);
    Bone* lll = new Bone(lowerLeftLeg);
    lll->setJointOffset(0, -0.02, 0);

    Shape* lowerLeftLegJoint = new Sphere(0.03, Point(0, -0.1, 0));
    lowerLeftLegJoint->setSurface(green);
    Bone* lllj = new Bone(lowerLeftLegJoint);

    Shape* upperRightLeg = new Cylinder(0.03, 0.09, Point(0.04, -0.07, 0));
    upperRightLeg->setSurface(red);
    upperRightLeg->setRotation(90, 0, 0);
    Bone* url = new Bone(upperRightLeg);
    url->setJointOffset(0, -0.04, 0);

    Shape* lowerRightLeg = new Cylinder(0.03, 0.09, Point(0, -0.1, 0));
    lowerRightLeg->setSurface(blue);
    lowerRightLeg->setRotation(90, 0, 0);
    Bone* lrl = new Bone(lowerRightLeg);
    lrl->setJointOffset(0, -0.02, 0);

    Shape* lowerRightLegJoint = new Sphere(0.03, Point(0, -0.1, 0));
    lowerRightLegJoint->setSurface(green);
    Bone* lrlj = new Bone(lowerRightLegJoint);

    bPelvis->addChild("Chest", bChest);
    bPelvis->addChild("LeftLeg", ull);
    bPelvis->addChild("RightLeg", url);
    
    bChest->addChild("Head", bHead);
    bChest->addChild("UpperRightArm", ura);
    bChest->addChild("UpperLeftArm", ula);
    bChest->addChild("LeftShoulder", ulaj);
    bChest->addChild("RightShoulder", uraj);

    ula->addChild("LowerArm", lla);
    ula->addChild("Elbow", llaj);

    ura->addChild("LowerArm", lra);
    ura->addChild("Elbow", lraj);

    ull->addChild("LowerLeg", lll);
    ull->addChild("Knee", lllj);

    url->addChild("LowerLeg", lrl);
    url->addChild("Knee", lrlj);

    ura->setAnimation(Point(10, 0, 0), Point(-90, 0, 0), 45, 0);
    lra->setRotation(-45, 0, 0);
    
    ula->setAnimation(Point(10, 0, 0), Point(-90, 0, 0), 45, 45);
    lla->setRotation(-45, 0, 0);

    ull->setAnimation(Point(10, 0, 0), Point(-90, 0, 0), 45, 0);
    lll->setRotation(45, 0, 0);

    url->setAnimation(Point(10, 0, 0), Point(-90, 0, 0), 45, 45);
    // lrl->setAnimation(Point(45, 0, 0), Point(-90, 0, 0), 90, 90);
    lrl->setRotation(45, 0, 0);

    bPelvis->setRotation(0, 180, 0);
    return root;
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

    scene->addShape("Arrow1", arrow1);
    scene->addShape("Arrow2", arrow2);
    scene->addShape("Arrow3", arrow3);


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
    // Create man
    Bone* man = createMan();
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
