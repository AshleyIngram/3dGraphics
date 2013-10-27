#ifndef _GL_CONE_POLYGON_H
#define _GL_CONE_POLYGON_H 1

#include "GLPolygon.h"
#include "Vector.h"
#include <QImage>
#include <vector>

class GLCone : public GLPolygon
{
    public:               
        GLCone();
        ~GLCone();
        
        void render();
        
    protected:
        void texture();
        std::vector<float> getTextureCoords(Point p);
        
    private:
        QImage* textureImg;
        void setNormal(Point p);
        Vector surfaceNormal;
};
#endif
