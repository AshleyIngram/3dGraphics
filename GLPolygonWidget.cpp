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
#include "ChristmasTree.h"
#include "Snowflake.h"
#include <sstream>
#include "Terrain.h"
#include <math.h>
#include "Snowman.h"
#include "HeightSurface.h"

GLPolygonWidget::GLPolygonWidget(QWidget* parent, Scene* scene) 
{
    this->parent = parent;
    this->scene = scene;
    this->rotateStartPoint = Point(0, 0, 0);
    this->rotateBy = Point(0, 0, 0);
}

void GLPolygonWidget::mouseClickEvent(QMouseEvent* e)
{
    this->rotateStartPoint = Point(0, 0, 0);
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

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    
    static const GLfloat black[4] = { 0.0, 0.0, 0.0, 1.0 };
    static const GLfloat white_light[4] = { 1.0, 1.0, 1.0, 1.0 };
    static const GLfloat grey[4] = { 0.4, 0.4, 0.4, 1.0 };
    static const float lightPosition[] = { -100, 100, 0, 1 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);

    // Tree
    Bone* tree = new ChristmasTree(5, Point(0.5, -0.27, 0));
    scene->addShape("Tree", tree);

    // Terrain
    Terrain* terrainShape = new Terrain();
    Surface* white = new ColouredSurface(1, 1, 1);
    Surface* green = new ColouredSurface(0, 1, 0);
    terrainShape->setSurface(new HeightSurface());
    Bone* terrain = new Bone(terrainShape);
    scene->addShape("Terrain", terrain);

    int numSnowflakes = 2000;

    // Create a snowflake
    for (int i = 0; i < numSnowflakes; i++)
    {
        Bone* snowflake = new Snowflake(terrainShape);
        std::stringstream ss;
        ss << i;
        scene->addShape("Snowflake" + ss.str(), snowflake);
    }

    // Snowman
    Bone* snowman = new Snowman(Point(-0.5, -0.5, 0));
    scene->addShape("Snowman", snowman);
}

// Resize the viewport
void GLPolygonWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    // glOrtho(-1, 1, -1, 1, -1, 1);
    glLoadIdentity();
    glOrtho(-fmax(1, (double)w/h), fmax(1, (double)w/h), -fmax(1, (double)h/w), fmax(1, (double)h/w), -1, 2);
    glViewport(0, 0, w, h);
}

// Repaint OpenGL widgets
void GLPolygonWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Render child polygon
    glMatrixMode(GL_MODELVIEW);

    glRotatef(rotateBy.y, 1, 0, 0);
    glRotatef(rotateBy.x, 0, 1, 0);
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
