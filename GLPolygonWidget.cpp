#include <QWidget>
#include <QMouseEvent>
#include "GLPolygonWidget.h"
#include "GLPolygon.h"
#include "GLPolygonWindow.h"
#include <iostream>

GLPolygonWidget::GLPolygonWidget(QWidget* parent, GLPolygon* polygon) 
{
    this->parent = parent;
    this->polygon = polygon;
}

// Initial OpenGL setup
void GLPolygonWidget::initializeGL()
{
    // Set default colour
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
    glClear(GL_COLOR_BUFFER_BIT);

    // Render child polygon    
    polygon->render();
    
    // Flush to render
    glFlush();
}

// TODO: These events would be neater in the controller (throwing custom signals)

// Event handler for clicking on the widget
void GLPolygonWidget::mousePressEvent(QMouseEvent* event)
{
    handleMouseEvent(event);
}

// Event handler for moving the mouse
void GLPolygonWidget::mouseMoveEvent(QMouseEvent* event)
{
    handleMouseEvent(event);
}

// Private method to reduce code duplication between mouse click/drag
void GLPolygonWidget::handleMouseEvent(QMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        moveWidget(event->x(), event->y());
    }
    else if (event->buttons() == Qt::RightButton)
    {
        rotateWidget(event->x());
    }
}

// Move a widget to position mx, my on the screen
void GLPolygonWidget::moveWidget(int mx, int my)
{
    // TODO: Defer to individual polygon
}

// Rotate the PolygonWidget by a specified amount
void GLPolygonWidget::rotateWidget(int amount)
{   
    // TODO: Defer to individual polygon
}

// Render the Polygon Widget
void GLPolygonWidget::render()
{
    GLPolygonWidget::paintGL();
}
