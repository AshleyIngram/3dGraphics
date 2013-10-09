#include <QWidget>
#include <QMouseEvent>
#include "GLPolygonWidget.h"
#include "IGLPolygon.h"
#include "GLPolygonWindow.h"
#include <iostream>

GLPolygonWidget::GLPolygonWidget(QWidget* parent, IGLPolygon* polygon) 
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
    // Map from x/y to between -1 and 1
    float x = mx / ((float)this->width()/2) - 1;
    float y = my / ((float)this->height()/2) - 1;
    
    // Multiply by 100 (we're modifying the dial, not the widget directly)
    x *= 100;
    y *= 100;
    
    // Invert the y axis
    y *= -1;

    GLPolygonWindow* window = (GLPolygonWindow*)parent;
    window->horizontalSlider->setValue(x);
    window->verticalSlider->setValue(y);
    ((GLPolygonWindow*)parent)->resetInterface();
}

// Rotate the PolygonWidget by a specified amount
void GLPolygonWidget::rotateWidget(int amount)
{
    GLPolygonWindow* window = (GLPolygonWindow*)parent;
    window->angleDial->setValue(amount % window->angleDial->maximum());
}

// Render the Polygon Widget
void GLPolygonWidget::render()
{
    GLPolygonWidget::paintGL();
}
