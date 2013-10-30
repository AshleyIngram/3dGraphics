#include "ApplicationController.h"
#include <iostream>

using namespace std;

ApplicationController::ApplicationController(GLPolygonWindow* window, Scene* scene)
{
    this->window = window;
    this->scene = scene;
    
    // Hook up quit event
    connect(window->actionQuit, SIGNAL(triggered()), QCoreApplication::instance(), SLOT(quit()));   
}

ApplicationController::~ApplicationController() 
{
    delete this->scene;
}
