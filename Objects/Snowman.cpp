#include "Snowman.h"
#include "Sphere.h"
#include "Cone.h"
#include "Cylinder.h"
#include "ColouredSurface.h"

Snowman::Snowman(Point origin) : Bone(getRoot())
{
	this->shape->setOrigin(origin);

	ColouredSurface* white = new ColouredSurface(1, 1, 1);
	ColouredSurface* orange = new ColouredSurface(0.92, 0.53, 0.12);
	ColouredSurface* black = new ColouredSurface(0, 0, 0);

	Shape* head = new Sphere(0.1, Point(0, -(this->shape->getOrigin().y / 2), 0));
	head->setSurface(white);

	Shape* nose = new Cone(0.02, 0.04, Point(0.1, 0, 0));
	nose->setSurface(orange);
	Bone* bNose = new Bone(nose);
	bNose->setRotation(0, 90, 0);

	Shape* hatBase = new Cylinder(0.1, 0.01, Point(0, 0.1, 0));
	hatBase->setSurface(black);
	Bone* bHatBase = new Bone(hatBase);
	bHatBase->setRotation(90, 0, 0);

	Shape* hatTop = new Cylinder(0.07, 0.1, Point(0, 0, -0.05));
	hatTop->setSurface(black);
	Bone* bHatTop = new Bone(hatTop);
	bHatTop->setRotation(0, 0, 0);

	Shape* lEye = new Sphere(0.01, Point(0.09, 0.04, 0.04));
	lEye->setSurface(black);
	Bone* bLEye = new Bone(lEye);

	Shape* rEye = new Sphere(0.01, Point(0.09, 0.04, -0.04));
	rEye->setSurface(black);
	Bone* bREye = new Bone(rEye);

	Bone* bHead = new Bone(head);
	bHead->addChild("Nose", bNose);
	bHead->addChild("Left Eye", bLEye);
	bHead->addChild("Right Eye", bREye);
	bHatBase->addChild("Top", bHatTop);
	bHead->addChild("HatBase", bHatBase);
	this->addChild("Head", bHead);
}

Shape* Snowman::getRoot()
{
	Shape* body = new Sphere(0.15, Point(0,0,0));
	ColouredSurface* white = new ColouredSurface(1, 1, 1);
	body->setSurface(white);
	return body;
}

void Snowman::render()
{
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	Bone::render();
	glDisable(GL_LIGHTING);
}