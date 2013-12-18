#include "Vertex.h"

Vertex::Vertex(float x, float y, float z, Vector n) : Point(x, y, z) 
{
	this->normal = n;
}

Vertex::Vertex(Point p, Vector n) : Point(p.x, p.y, p.z)
{
	this->normal = n;
}

Vertex::Vertex() : Point() {};