#include "GLPolygonController.h"
#include <iostream>
using namespace std;

GLPolygonController::GLPolygonController(GLPolygonWindow* window, IGLPolygon* polygon)
{
    this->window = window;
    this->polygon = polygon;
    
    
    // Hook up quit event
    connect(window->actionQuit, SIGNAL(triggered()), QCoreApplication::instance(), SLOT(quit()));   
}

// Event handler for when the number of vertices has changed
void GLPolygonController::verticesChanged(int newValue)
{
    polygon->vertices = newValue;        
    window->resetInterface();
}

// Event handler for when the horizontal position slider is changed
void GLPolygonController::horizontalChanged(int x)
{
    polygon->x = (float)x / 100;
    window->resetInterface();
}

// Event handler for when the vertical position slider is changed
void GLPolygonController::verticalChanged(int y)
{
    polygon->y = (float)y / 100;
    window->resetInterface();
}

// Event handler for when the angle dial is changed
void GLPolygonController::angleChanged(int angle)
{
    polygon->angle = (float)angle / 100;
    window->resetInterface();
}

// Event handler for the timer for rotation animation
void GLPolygonController::nextFrame()
{
    QDial* dial = window->angleDial;
    int newVal = (dial->value() + 1) % dial->maximum();
    dial->setValue(newVal);
    window->resetInterface();
}
