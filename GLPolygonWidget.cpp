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

GLPolygonWidget::GLPolygonWidget(QWidget* parent, Scene* scene) 
{
    this->parent = parent;
    this->scene = scene;
    this->rotateStartPoint = Point(0, 0, 0);
    this->rotateBy = Point(0, 0, 0);
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
    
    // Tree
    Bone* tree = new ChristmasTree(5);
    scene->addShape("Tree", tree);

    int numSnowflakes = 100;

    // Create a snowflake
    for (int i = 0; i < numSnowflakes; i++)
    {
        // Evenly distribute horizontally
        float hStart = (((float)2/numSnowflakes) * (i + 1)) - 1;

        // Random distribution vertically (up to a full screen above)
        float vStart = 1 + (float)(rand() % 200 + 1) / 100;

        // Random between 1 and -1 for depth
        float dStart = (float)(rand() % 200) / 100 - 1;

        Bone* snowflake = new Snowflake(Point(hStart, vStart, dStart));
        std::stringstream ss;
        ss << i;
        scene->addShape("Snowflake" + ss.str(), snowflake);
    }
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
