#ifndef _SURFACE_H
#define _SURFACE_H 1

#include <QGLWidget>
#include "Point.h"

class Surface 
{
	public:
		virtual void setProperty(Point p, int i) = 0;
};

#endif