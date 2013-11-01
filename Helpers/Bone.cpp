#include "Bone.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

Bone::Bone(Shape* shape)
{
	this->shape = shape;
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
	shape->setRotation(x, y, z);

	map<string, Bone*>::iterator i;
	for (i = children.begin(); i != children.end(); i++)
	{
		Point oldOrigin = i->second->getOrigin();
		Point newOrigin = rotatePoint(oldOrigin, x, y, z);
		i->second->setOrigin(Point(newOrigin.x, newOrigin.y, 0));
	}
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
	// First render our shape
	this->shape->render();

	// Then render all our children bones
	map<string, Bone*>::iterator i;
	for (i = children.begin(); i != children.end(); i++)
	{
		i->second->render();
	}
}