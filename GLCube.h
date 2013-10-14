#ifndef _GL_CUBE_POLYGON_H
#define _GL_CUBE_POLYGON_H 1

#include "GLPolygon.h"

class GLCube : public GLPolygon
{
    public:               
        void render();
        GLCube();
        float vertices[8][3];
        int edges[12][2];
        int triangles[36];
        GLenum mode;
};
#endif
