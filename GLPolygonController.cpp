#include "GLPolygonController.h"
#include <iostream>
using namespace std;

GLPolygonController::GLPolygonController(GLPolygonWindow* window, GLPolygon* polygon)
{
    this->window = window;
    this->polygon = polygon;
    
    
    // Hook up quit event
    connect(window->actionQuit, SIGNAL(triggered()), QCoreApplication::instance(), SLOT(quit()));
    
    // Hook up slider to increase number of vertices
    connect(window->verticesSlider, SIGNAL(valueChanged(int)), this, SLOT(verticesChanged(int)));
    
    // Hook up slider to pan the polygon up and down
    connect(window->verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(verticalChanged(int)));
        
    // Hook up the slider to pan the polygon left and right
    connect(window->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(horizontalChanged(int)));
        
    // Hook up the dial to rotate the polygon
    connect(window->angleDial, SIGNAL(valueChanged(int)), this, SLOT(angleChanged(int)));
        
    // Set the timer to animate polygon rotation
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16.67);     
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
