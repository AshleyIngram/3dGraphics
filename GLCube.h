#ifndef _GL_CUBE_POLYGON_H
#define _GL_CUBE_POLYGON_H 1

#include "GLPolygon.h"

class GLCube : public GLPolygon
{
    public:       
        int vertices;
        
        void render();
        
        GLCube();
};
#endif
