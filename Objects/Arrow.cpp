#include "Arrow.h"
#include "Cone.h"
#include "Cylinder.h"

Arrow::Arrow(Surface* surface, Point p) : Bone(getRoot())
{
	this->shape->setSurface(surface);

    Shape* head1 = new Cone(0.02, 0.02, Point(0, 0, 0.45));
    head1->setSurface(surface);
    // head1->setRotation(p.x, p.y, p.z);
    Bone* bHead1 = new Bone(head1);

    Shape* head2 = new Cone(0.02, 0.02, Point(0, 0, -0.45));
    head2->setSurface(surface);

    // The bottom arrow needs to rotate the other way - this works for 90 degrees ;)
    head2->setRotation(0, 180, 0);
    Bone* bHead2 = new Bone(head2);

    this->addChild("TopArrowHead", bHead1);
    this->addChild("BottomArrowHead", bHead2);

    this->setRotation(p.x, p.y, p.z);
}

Shape* Arrow::getRoot()
{
	Shape* shaft = new Cylinder(0.01, 0.9, Point(0, 0, 0));
    return shaft;
}