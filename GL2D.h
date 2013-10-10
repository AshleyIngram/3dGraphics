#ifndef _GL_2D_H
#define _GL_2D_H 1

#include "GLPolygon.h"

class GL2D : GLPolygon 
{
    public:       
        int vertices;
        int x;
        int y;
        int angle;
        
        GLPolygon(int vertices = 3);
        void render();
};
#endif