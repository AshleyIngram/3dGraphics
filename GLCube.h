#ifndef _GL_CUBE_POLYGON_H
#define _GL_CUBE_POLYGON_H 1

#include "GLPolygon.h"

class GLCube : public GLPolygon
{
    public:               
        void render();
        GLCube();
        int vertices[8][3];
        int edges[12][2];
};
#endif
