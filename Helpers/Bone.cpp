#include "Bone.h"
#include "Matrix.h"
#include <iostream>
#include "Sphere.h"

using namespace std;

Bone::Bone(Shape* shape)
{
	this->shape = shape;
	this->xRotate = 0;
	this->yRotate = 0;
	this->zRotate = 0;
	jointOffset = Point(0, 0, 0);

	animationStart = Point(0, 0, 0);
	animationStop = Point(0, 0, 0);
	animationRate = 0;
	animationFrame = 0;
	animateForward = true;
	currentFrame = Point(0, 0, 0);
	firstFrame = true;
}

void Bone::addChild(string key, Bone* bone)
{
	this->children[key] = bone;
}

void Bone::removeChild(string key)
{
	map<string, Bone*>::iterator it;
	it = children.find(key);
	children.erase(it);
}

void Bone::setOrigin(Point origin)
{
	shape->setOrigin(origin);
}

Point Bone::getOrigin()
{
	return shape->getOrigin();
}

void Bone::setRotation(float x, float y, float z)
{
	this->xRotate = x;
	this->yRotate = y;
	this->zRotate = z;
}

Point Bone::rotatePoint(Point p, float x, float y, float z)
{
	Point point = Matrix::getZRotationMatrix(z) * &p;
    point = Matrix::getXRotationMatrix(x) * &point;    
    point = Matrix::getYRotationMatrix(y) * &point;
    return point;
}

void Bone::setJointOffset(float x, float y, float z)
{
	setJointOffset(Point(x, y, z));
}

void Bone::setJointOffset(Point p)
{
	jointOffset = p;
}

void Bone::setAnimation(Point start, Point end, int rate, int delay)
{
	animationStart = start;
	animationStop = end;
	animationRate = rate;
	frameDelay = delay;
}

void Bone::nextFrame()
{
	if (animationRate == 0) { return; }
	if (animationFrame < frameDelay)
	{
		animationFrame++;
		return;
	}


	if ((animationFrame % animationRate == 0) && !firstFrame)
	{
		// Invert the direction
		animateForward = !animateForward;
	}

	firstFrame = false;

	Point step = (animationStop - animationStart) / animationRate;

	if (!animateForward)
	{
		step = step * -1;
	}

	currentFrame = currentFrame + step;
	animationFrame++;

	map<string, Bone*>::iterator i;
	for (i = children.begin(); i != children.end(); i++)
	{
		i->second->nextFrame();
	}
}

void Bone::animate()
{
	glRotatef(currentFrame.x, 1, 0, 0);
	glRotatef(currentFrame.y, 0, 1, 0);
	glRotatef(currentFrame.z, 0, 0, 1);
}

void Bone::render()
{
	glPushMatrix();
	
	Point origin = this->getOrigin();

	glTranslatef(origin.x, origin.y, origin.z);
	glRotatef(xRotate, 1, 0, 0);
	glRotatef(yRotate, 0, 1, 0);
	glRotatef(zRotate, 0, 0, 1);

	nextFrame();
	animate();

	glPushMatrix();
	glTranslatef(jointOffset.x, jointOffset.y, jointOffset.z);

	// First render our shape
	this->shape->render();
	glPopMatrix();
	/*Sphere s = Sphere(0.01, Point(0, 0, 0));
	s.render();*/
	// Then render all our children bones
	map<string, Bone*>::iterator i;
	for (i = children.begin(); i != children.end(); i++)
	{
		i->second->render();
	}
	glPopMatrix();
}