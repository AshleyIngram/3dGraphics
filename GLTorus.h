#ifndef _GL_TORUS_POLYGON_H
#define _GL_TORUS_POLYGON_H 1

#include "GLPolygon.h"
#include "Vector.h"
#include <QImage>
#include <vector>

class GLTorus : public GLPolygon
{
    public:               
        GLTorus();
        ~GLTorus();
        
        void render();
        
    protected:
        void light();
        void texture();
        Vector calculateSurfaceNormal(Point p1, Point p2, Point p3);
        std::vector<float> getTextureCoords(Point p);
        
    private:
        QImage* textureImg;
        void setNormal(Point p);
};
#endif
