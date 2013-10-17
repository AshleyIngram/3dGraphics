#include "GLPolygonController.h"
#include <iostream>
using namespace std;

GLPolygonController::GLPolygonController(GLPolygonWindow* window, GLPolygon* polygon)
{
    this->window = window;
    this->polygon = polygon;
    
    // Hook up quit event
    connect(window->actionQuit, SIGNAL(triggered()), QCoreApplication::instance(), SLOT(quit()));   
    
    // Rotation sliders
    connect(window->xSlider, SIGNAL(valueChanged(int)), this, SLOT(xChanged(int)));
    
    connect(window->ySlider, SIGNAL(valueChanged(int)), this, SLOT(yChanged(int)));
    
    connect(window->zSlider, SIGNAL(valueChanged(int)), this, SLOT(zChanged(int)));
}

void GLPolygonController::xChanged(int newValue)
{
    polygon->xRotate = newValue;
    window->resetInterface();
}

void GLPolygonController::yChanged(int newValue)
{
    polygon->yRotate = newValue;
    window->resetInterface();
}

void GLPolygonController::zChanged(int newValue)
{
    polygon->zRotate = newValue;
    window->resetInterface();
}
