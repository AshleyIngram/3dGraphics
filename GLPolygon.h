#ifndef _GL_POLYGON_H
#define _GL_POLYGON_H 1

#include "IGLPolygon.h"

class GLPolygon : public IGLPolygon
{
    public:       
        int vertices;
        
        void render();
        
        GLPolygon(int vertices = 3);
};
#endif
