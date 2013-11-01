#include "Cylinder.h"
#include <math.h>
#include <iostream>

Cylinder::Cylinder() : Shape()
{
    this->radius = 0.5;
    this->height = 0.5;
    this->setGeometry();
}

Cylinder::Cylinder(Point p) : Shape(p)
{
    this->radius = 0.5;
    this->height = 0.5;
    this->setGeometry();
}

Cylinder::Cylinder(float radius, float height, Point p) : Shape(p)
{
    this->radius = radius;
    this->height = height;
    this->setGeometry();
}

Cylinder::Cylinder(float radius, float height) : Shape()
{
    this->radius = radius;
    this->height = height;
    this->setGeometry();
}

void Cylinder::setGeometry()
{
    int segments = 100;
    float r = this->radius;

    for (int i = 0; i < segments; i++)
    {
        float angle =  M_PI * i * 2.0 / segments;
        float nextAngle = M_PI * (i + 1) * 2 / segments;
        
        float s1 = sin(angle) * r;
        float s2 = sin(nextAngle) * r;
        float c1 = cos(angle) * r;
        float c2 = cos(nextAngle) * r;
        
        Point p1 = Point(s1, c1, -(height / 2));       
        Point p2 = Point(s2, c2, -(height / 2));        
        Point p3 = Point(s1, c1, height / 2);        
        Point p4 = Point(s2, c2, height / 2);
                
        Quad quad = Quad(p1, p3, p4, p2);
        quads.push_back(quad);
    }
    
    Point bottomStart = Point(0, 0, -(height / 2));
    Point topStart = Point(0, 0, height / 2);
    
    for (int i = 0; i < segments; i++)
    {       
        float angle =  M_PI * i * 2.0 / segments;
        float nextAngle = M_PI * (i + 1) * 2 / segments;
    
        float x1 = sin(angle) * r;
        float y1 = cos(angle) * r;
        float x2 = sin(nextAngle) * r;
        float y2 = cos(nextAngle) * r;
        
        Point t2 = Point(x1, y1, height / 2);
        Point t3 = Point(x2, y2, height / 2);
        
        Point b2 = Point(x1, y1, -(height / 2));
        Point b3 = Point(x2, y2, -(height / 2));

        Triangle tri1 = Triangle(topStart, t2, t3);
        Triangle tri2 = Triangle(bottomStart, b2, b3);
    
        triangles.push_back(tri1);
        triangles.push_back(tri2);
    }
}
