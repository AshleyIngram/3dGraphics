#ifndef _TRIANGLE_H
#define _TRIANGLE_H 1

#include "Point.h"

class Triangle
{
	public:
		inline Triangle(Point p1, Point p2, Point p3)
		{
			this->p1 = p1;
			this->p2 = p2;
			this->p3 = p3;
		}

		Point p1;
		Point p2;
		Point p3;
};
#endif