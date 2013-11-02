#include "Bone.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

Bone::Bone(Shape* shape)
{
	this->shape = shape;
	this->xRotate = 0;
	this->yRotate = 0;
	this->zRotate = 0;
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

void Bone::render()
{
	glPushMatrix();
	
	Point origin = this->getOrigin();

	glTranslatef(origin.x, origin.y, origin.z);	
	glRotatef(xRotate, 1, 0, 0);
	glRotatef(yRotate, 0, 1, 0);
	glRotatef(zRotate, 0, 0, 1);

	// First render our shape
	this->shape->render();

	// Then render all our children bones
	map<string, Bone*>::iterator i;
	for (i = children.begin(); i != children.end(); i++)
	{
		i->second->render();
	}
	glPopMatrix();
}