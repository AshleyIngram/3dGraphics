#ifndef _SPHERE_H
#define _SPHERE_H 1

#include "Shape.h"
#include "Vector.h"
#include <vector>

class Sphere : public Shape
{
    public:               
        Sphere();
        Sphere(Point origin);
        Sphere(float radius);
        Sphere(float radius, Point origin);
        ~Sphere();

    protected:
    	float radius;
    	void setGeometry();
};

#endif