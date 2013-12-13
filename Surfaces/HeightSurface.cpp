#include "HeightSurface.h"
#include <iostream>

void HeightSurface::setProperty(Point p, int i)
{
	if (p.y < -0.64)
	{
		glColor3f(0, 1, 0);
	}
	else
	{
		glColor3f(1, 1, 1);
	}
}