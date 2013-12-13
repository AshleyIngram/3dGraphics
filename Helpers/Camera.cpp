#include "Camera.h"
#include "GL/gl.h"
#include <iostream>

float Camera::getX()
{
	return x;
}

float Camera::getY()
{
	return y;
}

float Camera::getZ()
{
	return z;
}

void Camera::setX(float v)
{
	this->x = v;
	totalX += v;
}

void Camera::setY(float v)
{
	this->y = v;
	totalY += v;
}

void Camera::setZ(float v)
{
	this->z = v;
	totalZ += v;
}

void Camera::moveCamera()
{
    glRotatef(y, 1, 0, 0);
    glRotatef(x, 0, 1, 0);
}