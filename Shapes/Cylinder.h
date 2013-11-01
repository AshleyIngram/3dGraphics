#ifndef _GL_CYLINDER_H
#define _GL_CYLINDER_H 1

#include "Shape.h"
#include "Vector.h"

class Cylinder : public Shape
{
    public:               
        Cylinder();
        Cylinder(Point p);
        Cylinder(float radius, float height, Point p);
        Cylinder(float radius, float height);
                
    protected:
    	float height;
        float radius;
        void setGeometry();
};
#endif
