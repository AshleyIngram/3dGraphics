#ifndef _POINT_H
#define _POINT_H 1

#include <ostream>
class Point
{
    public:
        Point(float x, float y, float z);
        Point(float input[3]);
    
        float x;
        float y;
        float z;
        
        float* toArray();
        friend std::ostream& operator<<(std::ostream& out, const Point x);
     private:
        float _returnVal[3];
};
#endif
