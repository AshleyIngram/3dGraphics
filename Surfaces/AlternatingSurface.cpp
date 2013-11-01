#include "AlternatingSurface.h"
#include <iostream>

void AlternatingSurface::setProperty(Point p, int i)
{
	// By the 4-colour theorem this is enough to colour any
	// plane without having 2 adjacent regions the same
	if(i % 4 == 0)
	{
		glColor3f(1.0, 0.0, 0.0);
	}
	else if (i % 3 == 0)
	{
		glColor3f(0.0, 1.0, 0.0);
	}
	else if (i % 2 == 0)
	{
		glColor3f(0.0, 0.0, 1.0);
	}
	else
	{
		glColor3f(1.0, 1.0, 0.0);
	}
}