#ifndef _QUAD_H
#define _QUAD_H 1

#include "Vertex.h"

class Quad
{
	public:
		inline Quad(Vertex p1, Vertex p2, Vertex p3, Vertex p4)
		{
			this->p1 = p1;
			this->p2 = p2;
			this->p3 = p3;
			this->p4 = p4;
		}

		Vertex p1;
		Vertex p2;
		Vertex p3;
		Vertex p4;
};
#endif