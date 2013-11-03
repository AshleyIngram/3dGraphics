#include "ApplicationController.h"
#include <iostream>

using namespace std;

ApplicationController::ApplicationController(GLPolygonWindow* window, Scene* scene)
{
    this->window = window;
    this->scene = scene;
    
    // Hook up quit event
    connect(window->actionQuit, SIGNAL(triggered()), QCoreApplication::instance(), SLOT(quit()));

    // Start the timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16.67);   
}

void ApplicationController::nextFrame()
{
	// Tell OpenGL to redraw
	window->resetInterface();
}

ApplicationController::~ApplicationController() 
{
    delete this->scene;
}
