#include "Cone.h"
#include <math.h>
#include <iostream>

Cone::Cone() : Shape()
{
    this->radius = 0.5;
    this->height = 0.5;
    this->setGeometry();
}

Cone::Cone(Point p) : Shape(p)
{
    this->radius = 0.5;
    this->height = 0.5;
    this->setGeometry();
}

Cone::Cone(float radius, float height, Point p) : Shape(p)
{
    this->radius = radius;
    this->height = height;
    this->setGeometry();
}

Cone::Cone(float radius, float height) : Shape()
{
    this->radius = radius;
    this->height = height;
    this->setGeometry();
}

void Cone::setGeometry()
{
    int segments = 100;

    // Top point
    Point top = Point(0, 0, height / 2);

    for (int i = 0; i < segments; i++)
    {
        float angle = (M_PI * 2 * i) / segments;
        float nextAngle = (M_PI * 2 * (i + 1)) / segments;
        float x1 = 0.5 * sin(angle);
        float y1 = 0.5 * cos(angle);
        float x2 = 0.5 * sin(nextAngle);
        float y2 = 0.5 * cos(nextAngle);
        
        Point p1 = Point(x1, y1, -(height / 2));
        Point p2 = Point(x2, y2, -(height / 2));
        
        Triangle tri = Triangle(top, p1, p2);
        triangles.push_back(tri);
    }
    
    Point bottomStart = Point(0, 0, -(height / 2));
    
    for (int i = 0; i < segments; i++)
    {       
        float angle =  M_PI * i * 2.0 / segments;
        float nextAngle = M_PI * (i + 1) * 2 / segments;
    
        float x1 = sin(angle) * 0.5;
        float y1 = cos(angle) * 0.5;
        float x2 = sin(nextAngle) * 0.5;
        float y2 = cos(nextAngle) * 0.5;
        
        Point b2 = Point(x1, y1, -(height / 2));
        Point b3 = Point(x2, y2, -(height / 2));
    
        Triangle tri = Triangle(b2, b3, bottomStart);
        triangles.push_back(tri);
    }
}
