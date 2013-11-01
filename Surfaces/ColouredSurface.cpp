#include "ColouredSurface.h"
#include <iostream>

ColouredSurface::ColouredSurface(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

ColouredSurface::ColouredSurface(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void ColouredSurface::setProperty(Point p, int i)
{
	glColor4f(r, g, b, a);
}