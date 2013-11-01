#ifndef _COLOURED_SURFACE_H
#define _COLOURED_SURFACE_H 1

#include "Point.h"
#include "Surface.h"

class ColouredSurface : public Surface
{
	public:
		ColouredSurface(float r, float g, float b, float a);
		ColouredSurface(float r, float g, float b);
		virtual void setProperty(Point p, int i);

	protected:
		float r;
		float g;
		float b;
		float a;
};

#endif