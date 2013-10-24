#ifndef _GL_CYLINDER_POLYGON_H
#define _GL_CYLINDER_POLYGON_H 1

#include "GLPolygon.h"
#include "Vector.h"
#include <QImage>
#include <vector>

class GLCylinder : public GLPolygon
{
    public:               
        GLCylinder();
        ~GLCylinder();
        
        void render();
        
    protected:
        void texture();
        Vector calculateSurfaceNormal(Point p1, Point p2, Point p3);
        std::vector<float> getTextureCoords(Point p);
};
#endif
