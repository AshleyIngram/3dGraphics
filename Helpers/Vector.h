#ifndef _VECTOR_H
#define _VECTOR_H 1

#include "Point.h"

class Vector
{
    public:
        Vector();
        Vector(float x, float y, float z);
        Vector(float x, float y, float z, float w);
        Vector(Point p1, Point p2);
        
        Vector operator*(Vector input);
        Vector operator-(Vector input);
        friend std::ostream& operator<<(std::ostream& out, const Vector x);
        
        Vector normalize();
        float* toArray();
        float length();
        
        float x;
        float y;
        float z;
        float w;

        operator float* () const {return (float*) this;}
        operator const float* () const {return (const float*) this;}
        
    private:
        float _returnArray[3];
};
#endif
