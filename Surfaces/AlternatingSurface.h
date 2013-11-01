#ifndef _ALTERNATING_SURFACE_H
#define _ALTERNATING_SURFACE_H 1

#include "Point.h"
#include "Surface.h"

class AlternatingSurface : public Surface
{
	virtual void setProperty(Point p, int i);
};

#endif