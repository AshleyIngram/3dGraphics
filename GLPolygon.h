#ifndef _GL_POLYGON_H
#define _GL_POLYGON_H 1

class GLPolygon 
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
