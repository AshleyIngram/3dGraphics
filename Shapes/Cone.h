#ifndef _CONE_H
#define _CONE_H 1

#include "Shape.h"

class Cone : public Shape
{
    public:               
        Cone();
        Cone(Point p);
        Cone(float radius, float height, Point p);
        Cone(float radius, float height);
                
    protected:
        float height;
        float radius;
        void setGeometry();
};
#endif
