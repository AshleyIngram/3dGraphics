#include "Snowflake.h"
#include "ColouredSurface.h"
#include <iostream>
#include <math.h>
#include <sys/time.h>
#include "Circle.h"

Snowflake::Snowflake(Point p, Terrain* t) : Bone(getSphere())
{
	this->position = p;
	this->terrain = t;
}

Snowflake::Snowflake(Terrain* t) : Bone(getSphere())
{
	this->terrain = t;
	this->position = getRandomPosition(false);
}

void Snowflake::nextFrame()
{
	if (this->position.y < -0.63)
	{
		this->terrain->setCollision(this->position.x, this->position.z);
		this->position = getRandomPosition();
	}
	else
	{
		// Move the position by a given speed
		this->position.y -= 0.01;
	}
}

void Snowflake::render()
{
	nextFrame();
	glPushMatrix();
		float x = this->position.x + (sin(this->position.y * 2) / 20);
		glTranslatef(x, this->position.y, this->position.z);
		this->shape->render();
	glPopMatrix();
}

Shape* Snowflake::getSphere()
{
	// Sphere* s = new Sphere(0.01, Point(0, 0, 0), 10);
	Circle* s = new Circle(0.01, Point(0, 0, 0), 10);
	ColouredSurface* white = new ColouredSurface(1, 1, 1);
	s->setSurface(white);
	return s;

}
Point Snowflake::getRandomPosition(bool reseed)
{
	if (reseed == true)
		srand(clock());

	// Random distribution horizontally
    float hStart = (float)(rand() % 200) / 100 - 1;

    // Random distribution vertically (up to a full screen above)
    float vStart = 1 + (float)(rand() % 200 + 1) / 100;

    // Random between 1 and -1 for depth
    float dStart = (float)(rand() % 200) / 100 - 1;

    return Point(hStart, vStart, dStart);
}