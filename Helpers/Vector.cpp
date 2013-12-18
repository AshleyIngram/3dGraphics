#include "Vector.h"
#include <math.h>

Vector::Vector()
{
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Vector::Vector(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(Point p1, Point p2)
{
    this->x = p2.x - p1.x;
    this->y = p2.y - p1.y;
    this->z = p2.z - p1.z;
}

Vector::Vector(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vector Vector::operator*(Vector input)
{
    // Calculate the Cross Product
    Vector ret = Vector();
    
    ret.x = (this->y * input.z) - (this->z * input.y);
    ret.y = (this->z * input.x) - (this->x * input.z);
    ret.z = (this->x * input.y) - (this->y * input.x);
    
    return ret;
}

Vector Vector::operator-(Vector input)
{
    Vector ret = Vector();

    ret.x = this->x - input.x;
    ret.y = this->y - input.y;
    ret.z = this->z - input.z;

    return ret;
}

float Vector::length()
{
    float sumSquare = (x * x) + (y * y) + (z * z);
    return sqrt(sumSquare);
}

Vector Vector::normalize()
{
    float v_length = length();
    Vector n = Vector(x / v_length, y / v_length, z / v_length);
    return n;
}

std::ostream& operator<<(std::ostream& out, Vector x)
{
    //Overload the cout operator (<<) for pretty printing
    out << "[" << x.x << ", " << x.y << ", " << x.z << "]";
    
    return out;
}

float* Vector::toArray()
{
    _returnArray[0] = x;
    _returnArray[1] = y;
    _returnArray[2] = z;
    return _returnArray;
}
