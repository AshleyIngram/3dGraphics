#include "Snowflake.h"
#include "ColouredSurface.h"
#include <iostream>

Snowflake::Snowflake(Point p) : Bone(getSphere())
{
	this->position = p;
	this->initialPosition = p;
}

void Snowflake::nextFrame()
{
	// Move the position by a given speed
	this->position.y -= 0.01;
}

void Snowflake::render()
{
	nextFrame();
	glPushMatrix();
		glTranslatef(this->position.x, this->position.y, this->position.z);
		this->shape->render();
	glPopMatrix();

	if (this->position.y < -1)
	{
		this->position = initialPosition;
	}
}

Shape* Snowflake::getSphere()
{
	Sphere* s = new Sphere(0.01, Point(0, 0, 0));
	ColouredSurface* white = new ColouredSurface(1, 1, 1);
	s->setSurface(white);
	return s;
}