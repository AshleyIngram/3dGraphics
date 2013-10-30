#ifndef _QUAD_H
#define _QUAD_H 1

#include "Point.h"

class Quad
{
	public:
		inline Quad(Point p1, Point p2, Point p3, Point p4)
		{
			this->p1 = p1;
			this->p2 = p2;
			this->p3 = p3;
			this->p4 = p4;
		}

		Point p1;
		Point p2;
		Point p3;
		Point p4;
};
#endif