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
    float r = this->radius;

    // Top point
    Vector topNormal = Vector(0, 0, height / 2);
    Vertex top = Vertex(0, 0, height / 2, topNormal);

    for (int i = 0; i < segments; i++)
    {
        float angle = (M_PI * 2 * i) / segments;
        float nextAngle = (M_PI * 2 * (i + 1)) / segments;
        float x1 = sin(angle) * r;
        float y1 = cos(angle) * r;
        float x2 = sin(nextAngle) * r;
        float y2 = cos(nextAngle) * r;
        
        Point p1 = Point(x1, y1, -(height / 2));
        Point p2 = Point(x2, y2, -(height / 2));

        Vector n1 = Vector(p1.x, p1.y, p1.z).normalize();
        Vector n2 = Vector(p2.x, p2.y, p2.z).normalize();

        Vertex v1 = Vertex(p1.x, p1.y, p1.z, n1);
        Vertex v2 = Vertex(p2.x, p2.y, p2.z, n2);
        
        Triangle tri = Triangle(top, v1, v2);
        triangles.push_back(tri);
    }
    
    Vector bottomNormal = Vector(0, 0, -(height/2)).normalize();
    Vertex bottomStart = Vertex(0, 0, -(height / 2), bottomNormal);
    
    for (int i = 0; i < segments; i++)
    {       
        float angle =  M_PI * i * 2.0 / segments;
        float nextAngle = M_PI * (i + 1) * 2 / segments;
    
        float x1 = sin(angle) * r;
        float y1 = cos(angle) * r;
        float x2 = sin(nextAngle) * r;
        float y2 = cos(nextAngle) * r;
        
        Vertex b2 = Vertex(x1, y1, -(height / 2), bottomNormal);
        Vertex b3 = Vertex(x2, y2, -(height / 2), bottomNormal);
    
        Triangle tri = Triangle(b2, b3, bottomStart);
        triangles.push_back(tri);
    }
}
