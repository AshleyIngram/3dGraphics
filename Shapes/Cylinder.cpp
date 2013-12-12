#include "Cylinder.h"
#include <math.h>
#include <iostream>

Cylinder::Cylinder() : Shape()
{
    this->radius = 0.5;
    this->height = 0.5;
    this->quality = 100;
    this->setGeometry();
}

Cylinder::Cylinder(Point p) : Shape(p)
{
    this->radius = 0.5;
    this->height = 0.5;
    this->quality = 100;
    this->setGeometry();
}

Cylinder::Cylinder(float radius, float height, Point p) : Shape(p)
{
    this->radius = radius;
    this->height = height;
    this->quality = 100;
    this->setGeometry();
}

Cylinder::Cylinder(float radius, float height) : Shape()
{
    this->radius = radius;
    this->height = height;
    this->quality = 100;
    this->setGeometry();
}

Cylinder::Cylinder(float radius, float height, Point p, int quality) : Shape(p)
{
    this->radius = radius;
    this->height = height;
    this->quality = quality;
    this->setGeometry();
}

void Cylinder::setGeometry()
{
    int segments = quality;
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
        Vector n1 = Vector(p1.x, p1.y, p1.z).normalize();
        Vertex v1 = Vertex(p1.x, p1.y, p1.z, n1);

        Point p2 = Point(s2, c2, -(height / 2));        
        Vector n2 = Vector(p2.x, p2.y, p2.z).normalize();
        Vertex v2 = Vertex(p2.x, p2.y, p2.z, n2);

        Point p3 = Point(s1, c1, height / 2);   
        Vector n3 = Vector(p3.x, p3.y, p3.z).normalize();
        Vertex v3 = Vertex(p3.x, p3.y, p3.z, n3);

        Point p4 = Point(s2, c2, height / 2);
        Vector n4 = Vector(p4.x, p4.y, p4.z).normalize();
        Vertex v4 = Vertex(p4.x, p4.y, p4.z, n4);   

        Quad quad = Quad(v1, v3, v4, v2);
        quads.push_back(quad);
    }
    
    Vector bottomNormal = Vector(0, 0, -(height/2)).normalize();
    Vector topNormal = Vector(0, 0, height/2).normalize();

    Vertex bottomStart = Vertex(0, 0, -(height/2), bottomNormal);
    Vertex topStart = Vertex(0, 0, height / 2, topNormal);
    
    for (int i = 0; i < segments; i++)
    {       
        float angle =  M_PI * i * 2.0 / segments;
        float nextAngle = M_PI * (i + 1) * 2 / segments;
    
        float x1 = sin(angle) * r;
        float y1 = cos(angle) * r;
        float x2 = sin(nextAngle) * r;
        float y2 = cos(nextAngle) * r;
        
        Vertex t2 = Vertex(x1, y1, height / 2, topNormal);
        Vertex t3 = Vertex(x2, y2, height / 2, topNormal);
        
        Vertex b2 = Vertex(x1, y1, -(height / 2), bottomNormal);
        Vertex b3 = Vertex(x2, y2, -(height / 2), bottomNormal);

        Triangle tri1 = Triangle(topStart, t2, t3);
        Triangle tri2 = Triangle(bottomStart, b2, b3);
    
        triangles.push_back(tri1);
        triangles.push_back(tri2);
    }
}
