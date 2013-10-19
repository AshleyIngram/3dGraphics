#include "Point.h"

Point::Point(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(float input[3])
{
    this->x = input[0];
    this->y = input[1];
    this->z = input[2];
}

float* Point::toArray()
{
    float returnVal[3] = { x, y, z };
    return returnVal;
}
