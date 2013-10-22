#ifndef _GL_SPHERE_POLYGON_H
#define _GL_SPHERE_POLYGON_H 1

#include "GLPolygon.h"

class GLSphere : public GLPolygon
{
    public:               
        GLSphere();
        
        void render();
};
#endif
