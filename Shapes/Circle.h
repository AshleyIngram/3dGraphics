#ifndef _CIRCLE_H
#define _CIRCLE_H 1

#include "Shape.h"
#include "Vector.h"
#include <vector>

class Circle : public Shape
{
    public:               
        Circle();
        Circle(Point origin);
        Circle(float radius);
        Circle(float radius, Point origin);
        Circle(float radius, Point origin, float quality);

        virtual void render();

    protected:
    	float radius;
    	void setGeometry();
    	float quality;
        std::vector<Point> points;
};

#endif