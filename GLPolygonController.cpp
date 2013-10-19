#include "GLPolygonController.h"
#include "GLTetra.h"
#include "GLCube.h"
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
    
    connect(window->shapeChoice, SIGNAL(currentIndexChanged(int)), this, SLOT(shapeChange(int)));
    
    connect(window->modeChoice, SIGNAL(currentIndexChanged(int)), this, SLOT(modeChange(int)));
    
    connect(window->colourChoice, SIGNAL(currentIndexChanged(int)), this, SLOT(colourChange(int)));
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

void GLPolygonController::modeChange(int mode)
{
    this->polygon->mode = modeFromInt(mode);
    window->resetInterface();
}

void GLPolygonController::shapeChange(int shape)
{
    GLPolygon newPolygon;

    switch(shape)
    {
        case (0):
            newPolygon = GLTetra();
            break;
        case (1):
            newPolygon = GLCube();
            break;
    } 
    
    newPolygon.mode = this->polygon->mode;
    newPolygon.colourMode = this->polygon->colourMode;
    newPolygon.xRotate = this->polygon->xRotate;
    newPolygon.yRotate = this->polygon->yRotate;
    newPolygon.zRotate = this->polygon->zRotate;
    
    *this->polygon = newPolygon;
    
    window->resetInterface();
}

void GLPolygonController::colourChange(int colourMode)
{
    // TODO: This is gross. It should be a constant or something, rather than just delegating across
    polygon->colourMode = colourMode;
    window->resetInterface();
}

GLenum GLPolygonController::modeFromInt(int val)
{
    if (val == 0)
        return GL_TRIANGLES;
    if (val == 1)
        return GL_LINES;
    if (val == 2)
        return GL_POINTS;
}
