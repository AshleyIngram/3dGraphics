#ifndef _HEIGHT_SURFACE_H
#define _HEIGHT_SURFACE_H 1

#include "Point.h"
#include "Surface.h"

class HeightSurface : public Surface
{
	public:
		virtual void setProperty(Point p, int i);
};

#endif