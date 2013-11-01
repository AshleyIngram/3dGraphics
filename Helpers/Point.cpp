#include "Point.h"
#include "Vector.h"

Point::Point(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point::Point(float input[3])
{
    this->x = input[0];
    this->y = input[1];
    this->z = input[2];
}

float* Point::toArray()
{
    _returnVal[0] = x;
    _returnVal[1] = y;
    _returnVal[2] = z;
    return _returnVal;
}

std::ostream& operator<<(std::ostream& out, Point x)
{
    //Overload the cout operator (<<) for pretty printing
    out << "[" << x.x << ", " << x.y << ", " << x.z << "]";
    
    return out;
}

Point Point::operator +(Point p)
{
    Point rp = Point();
    rp.x = this->x + p.x;
    rp.y = this->y + p.y;
    rp.z = this->z + p.z;

    return rp;
}

Point::operator Vector()
{
    return Vector(this->x, this->y, this->z);
}
