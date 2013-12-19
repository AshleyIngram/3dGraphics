#include "Snowflake.h"
#include "ColouredSurface.h"
#include <iostream>
#include <math.h>
#include <sys/time.h>
#include "Circle.h"

Snowflake::Snowflake(Point p, Terrain* t, Camera* camera) : Bone(getCircle())
{
	this->position = p;
	this->terrain = t;
	this->camera = camera;
}

Snowflake::Snowflake(Terrain* t, Camera* camera) : Bone(getCircle())
{
	this->terrain = t;
	this->position = getRandomPosition(false);
	this->camera = camera;
}

void Snowflake::nextFrame()
{
	if (this->position.y < -0.63)
	{
		this->terrain->setCollision(this->position.x, this->position.z);

		// The particle has reached the end of its lifetime. Rather than kill it
		// and have to add a new one to the scene (and have the memory overhead)
		// this one can just respawn randomly again (giving the same effect)
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
		glRotatef(-camera->totalY, 1, 0, 0);
    	glRotatef(-camera->totalX, 0, 1, 0);
		this->shape->render();

		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		this->shape->render();
		glPopMatrix();

		glPushMatrix();
		glRotatef(90, 1, 0, 0);
		this->shape->render();
		glPopMatrix();
	glPopMatrix();
}

Shape* Snowflake::getCircle()
{
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
    float vStart = (1 + (float)(rand() % 200 + 1) / 100) + 1;

    if (reseed == false)
    {
    	// First iteration... make it a bit more uniform
    	float toAdd = (float)(rand() % 200 + 1) / 100;
    	vStart += toAdd;
    }

    // Random between 1 and -1 for depth
    float dStart = (float)(rand() % 200) / 100 - 1;

    return Point(hStart, vStart, dStart);
}