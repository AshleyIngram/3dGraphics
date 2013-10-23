#ifndef _GL_SPHERE_POLYGON_H
#define _GL_SPHERE_POLYGON_H 1

#include "GLPolygon.h"
#include "Vector.h"
#include <QImage>
#include <vector>

class GLSphere : public GLPolygon
{
    public:               
        GLSphere();
        ~GLSphere();
        
        void render();
        
    protected:
        void light();
        void texture();
        Vector calculateSurfaceNormal(Point p1, Point p2, Point p3);
        std::vector<float> getTextureCoords(Point p);
        
    private:
        QImage* textureImg;
        void setNormal(Point p);
        Vector surfaceNormal;
};
#endif
