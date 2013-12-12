#ifndef _H_VERTEX
#define _H_VERTEX 1
#include "Point.h"
#include "Vector.h"

class Vertex : public Point
{
	public:
		Vertex(float x, float y, float z, Vector n);
		Vertex();
		Vector normal;
};
#endif