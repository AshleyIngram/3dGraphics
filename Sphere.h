#ifndef _SPHERE_H
#define _SPHERE_H 1

#include "Shape.h"
#include "Vector.h"
#include <QImage>
#include <vector>

public class Sphere : Shape
{
    public:               
        Sphere();
        Sphere(Point origin);
        ~Sphere();
        
		void render();
        
    protected:
        void texture();
        std::vector<float> getTextureCoords(Point p);
        
    private:
        QImage* textureImg;
        void setNormal(Point p);
        Vector surfaceNormal;

};

#endif