#ifndef _GL_SPHERE_POLYGON_H
#define _GL_SPHERE_POLYGON_H 1

#include "GLPolygon.h"
#include <QImage>

class GLSphere : public GLPolygon
{
    public:               
        GLSphere();
        ~GLSphere();
        
        void render();
        
    protected:
        void light();
        void texture();
        
    private:
        QImage* textureImg;
};
#endif
