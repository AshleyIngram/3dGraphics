#ifndef _TRIANGLE_H
#define _TRIANGLE_H 1

#include "Vertex.h"

class Triangle
{
	public:
		inline Triangle(Vertex p1, Vertex p2, Vertex p3)
		{
			this->p1 = p1;
			this->p2 = p2;
			this->p3 = p3;
		}

		Vertex p1;
		Vertex p2;
		Vertex p3;
};
#endif