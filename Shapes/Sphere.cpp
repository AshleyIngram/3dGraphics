#include <math.h>
#include "Sphere.h"
#include <iostream>

Sphere::Sphere() : Shape()
{
    this->radius = 0.5;
    this->quality = 100;
    this->setGeometry();
}

Sphere::Sphere(Point origin) : Shape(origin) 
{
    this->radius = 0.5;
    this->quality = 100;
    this->setGeometry();
}

Sphere::Sphere(float radius) : Shape() 
{
    this->radius = radius;
    this->setGeometry();
    this->quality = 100;
}

Sphere::Sphere(float radius, Point origin) : Shape(origin)
{
    this->radius = radius;
    this->quality = 100;
    this->setGeometry();
}

Sphere::Sphere(float radius, Point origin, float quality) : Shape(origin)
{
    this->radius = radius;
    this->quality = quality;
    this->setGeometry();
}

void Sphere::setGeometry()
{
    int lats = quality;
    int longs = quality;
    float r = this->radius;
    
    for(int i = 0; i <= lats; i++) 
    {
        double lat1 = (M_PI * 0.5) + i * (M_PI / lats);
        double sin1 = sin(lat1);
        double cos1 = cos(lat1);

        double lat2 = (double)(M_PI * 0.5) + (i + 1) * (double)(M_PI / lats);
        double sin2 = sin(lat2);
        double cos2 = cos(lat2);

        for(int j = 0; j <= longs; j++) 
        {
            double lng1 = j * ((double)(2 * M_PI) / (double)longs);
            double lng2 = (j + 1) * ((double)(2 * M_PI) / (double)longs);
            
            // Generate Points
            Point p1 = Point(r * cos1 * cos(lng1), r * cos1 * sin(lng1), r * sin1);
            Point p2 = Point(r * cos1 * cos(lng2), r * cos1 * sin(lng2), r * sin1);
            Point p3 = Point(r * cos2 * cos(lng2), r * cos2 * sin(lng2), r * sin2);      
            Point p4 = Point(r * cos2 * cos(lng1), r * cos2 * sin(lng1), r * sin2);
            
            Quad quad = Quad(p1, p2, p3, p4);
            quads.push_back(quad);            
       }
   }
}