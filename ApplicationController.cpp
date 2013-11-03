#include "ApplicationController.h"
#include <iostream>

using namespace std;

ApplicationController::ApplicationController(GLPolygonWindow* window, Scene* scene)
{
    this->window = window;
    this->scene = scene;
    
    // Hook up quit event
    connect(window->actionQuit, SIGNAL(triggered()), QCoreApplication::instance(), SLOT(quit()));

    // Turn on/off animation
    connect(window->isAnimating, SIGNAL(toggled(bool)), this, SLOT(setAnimation(bool)));

    // Start the timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16.67);
}

void ApplicationController::setAnimation(bool animate)
{
	isAnimating = animate;
}

void ApplicationController::nextFrame()
{
	// Tell OpenGL to redraw
	if (isAnimating) 
	{
		window->resetInterface();
	}
}

ApplicationController::~ApplicationController() 
{
    delete this->scene;
}
