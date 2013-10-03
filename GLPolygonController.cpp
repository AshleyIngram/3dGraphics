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

void GLPolygonController::verticesChanged(int newValue)
{
    polygon->vertices = newValue;        
    window->resetInterface();
}

void GLPolygonController::horizontalChanged(int x)
{
    polygon->x = x;
    window->resetInterface();
}

void GLPolygonController::verticalChanged(int y)
{
    polygon->y = y;
    window->resetInterface();
}

void GLPolygonController::angleChanged(int angle)
{
    polygon->angle = angle;
    window->resetInterface();
}

void GLPolygonController::nextFrame()
{
    QDial* dial = window->angleDial;
    dial->setValue(dial->value() + 1);
    window->resetInterface();
}
