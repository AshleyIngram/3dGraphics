#include <QWidget>
#include "GLPolygonWidget.h"
#include "GLPolygon.h"
#include <iostream>

GLPolygonWidget::GLPolygonWidget(QWidget* parent, GLPolygon* polygon) 
{
    this->parent = parent;
    this->polygon = polygon;
}

void GLPolygonWidget::initializeGL()
{
    // Set default colour
    glClearColor(0.3, 0.3, 0.3, 0.0);
}

void GLPolygonWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLPolygonWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Render child polygon    
    polygon->render();
    
    // Flush to render
    glFlush();
}

void GLPolygonWidget::render()
{
    GLPolygonWidget::paintGL();
}
