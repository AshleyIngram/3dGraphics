#ifndef _POINT_H
#define _POINT_H 1
class Point
{
    public:
        Point(float x, float y, float z);
        Point(float input[3]);
    
        float x;
        float y;
        float z;
        
        float* toArray();
};
#endif
