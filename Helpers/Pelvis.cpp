#include "Pelvis.h"
#include "Matrix.h"
#include <iostream>
#include "Sphere.h"

using namespace std;

Pelvis::Pelvis(Shape* shape) : Bone(shape)
{
}

void Pelvis::nextFrame()
{
	float x = currentFrame.x;
	float y = currentFrame.y + 1;
	float z = currentFrame.z;

	currentFrame = Point(x, y, z);
}

void Pelvis::render()
{
	glPushMatrix();
	glRotatef(1, 0, 1, 0);
	Bone::render();
	glPopMatrix();
}