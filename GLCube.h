#ifndef _GL_CUBE_POLYGON_H
#define _GL_CUBE_POLYGON_H 1

#include "IGLPolygon.h"

class GLCube : public IGLPolygon
{
    public:       
        int vertices;
        
        void render();
        
        GLCube();
};
#endif
