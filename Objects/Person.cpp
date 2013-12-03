#include "Person.h"
#include <iostream>
#include "Sphere.h"
#include "Point.h"
#include "Cylinder.h"
#include "ColouredSurface.h"

using namespace std;

Person::Person() : Bone(getRoot())
{
	ColouredSurface* red = new ColouredSurface(1, 0, 0);
    ColouredSurface* green = new ColouredSurface(0, 1, 0);
    ColouredSurface* blue = new ColouredSurface(0, 0, 1);

    Shape* pelvis = new Cylinder(0.08, 0.15, Point(0.3, 0, 0));
    pelvis->setSurface(blue);
    Bone* bPelvis = new Bone(pelvis);
    pelvis->setRotation(90, 0, 0);

    this->addChild("Pelvis", bPelvis);
    
    Shape* chest = new Cylinder(0.08, 0.1, Point(0, 0.125, 0));
    chest->setSurface(green);
    Bone* bChest = new Bone(chest);
    chest->setRotation(90, 0, 0);

    Shape* head = new Sphere(0.08, Point(0, 0.13, 0));

    TexturedSurface* headTex = new TexturedSurface("./face.jpg");
    head->setTexture(headTex);
    Bone* bHead = new Bone(head);
    head->setRotation(90, 0, 0);

    Shape* upperLeftArm = new Cylinder(0.02, 0.08, Point(-0.1, 0, 0));
    upperLeftArm->setSurface(red);
    upperLeftArm->setRotation(90, 0, 0);
    Bone* ula = new Bone(upperLeftArm);
    ula->setJointOffset(0, -0.04, 0);

    Shape* upperLeftArmJoint = new Sphere(0.04, Point(-0.1, 0, 0));
    upperLeftArmJoint->setSurface(blue);
    upperLeftArmJoint->setRotation(90, 0, 0);
    Bone* ulaj = new Bone(upperLeftArmJoint);

    Shape* lowerLeftArm = new Cylinder(0.02, 0.08, Point(0, -0.08, 0));
    lowerLeftArm->setSurface(green);
    lowerLeftArm->setRotation(90, 0, 0);
    Bone* lla = new Bone(lowerLeftArm);
    lla->setJointOffset(0, -0.04, 0);

    Shape* lowerLeftArmJoint = new Sphere(0.03, Point(0, -0.08, 0));
    lowerLeftArmJoint->setSurface(blue);
    lowerLeftArmJoint->setRotation(90, 0, 0);
    Bone* llaj = new Bone(lowerLeftArmJoint);

    Shape* upperRightArm = new Cylinder(0.02, 0.08, Point(0.1, 0, 0));
    upperRightArm->setSurface(red);
    upperRightArm->setRotation(90, 0, 0);
    Bone* ura = new Bone(upperRightArm);
    ura->setJointOffset(0, -0.04, 0);

    Shape* upperRightArmJoint = new Sphere(0.04, Point(0.1, 0, 0));
    upperRightArmJoint->setSurface(blue);
    upperRightArmJoint->setRotation(90, 0, 0);
    Bone* uraj = new Bone(upperRightArmJoint);

    Shape* lowerRightArm = new Cylinder(0.02, 0.08, Point(0, -0.08, 0));
    lowerRightArm->setSurface(green);
    lowerRightArm->setRotation(90, 0, 0);
    Bone* lra = new Bone(lowerRightArm);
    lra->setJointOffset(0, -0.04, 0);

    Shape* lowerRightArmJoint = new Sphere(0.03, Point(0, -0.08, 0));
    lowerRightArmJoint->setSurface(blue);
    lowerRightArmJoint->setRotation(90, 0, 0);
    Bone* lraj = new Bone(lowerRightArmJoint);

    Shape* upperLeftLeg = new Cylinder(0.03, 0.09, Point(-0.04, -0.07, 0));
    upperLeftLeg->setSurface(red);
    upperLeftLeg->setRotation(90, 0, 0);
    Bone* ull = new Bone(upperLeftLeg);
    ull->setJointOffset(0, -0.04, 0);

    Shape* lowerLeftLeg = new Cylinder(0.03, 0.09, Point(0, -0.1, 0));
    lowerLeftLeg->setSurface(blue);
    lowerLeftLeg->setRotation(90, 0, 0);
    Bone* lll = new Bone(lowerLeftLeg);
    lll->setJointOffset(0, -0.02, 0);

    Shape* lowerLeftLegJoint = new Sphere(0.03, Point(0, -0.1, 0));
    lowerLeftLegJoint->setSurface(green);
    Bone* lllj = new Bone(lowerLeftLegJoint);

    Shape* upperRightLeg = new Cylinder(0.03, 0.09, Point(0.04, -0.07, 0));
    upperRightLeg->setSurface(red);
    upperRightLeg->setRotation(90, 0, 0);
    Bone* url = new Bone(upperRightLeg);
    url->setJointOffset(0, -0.04, 0);

    Shape* lowerRightLeg = new Cylinder(0.03, 0.09, Point(0, -0.1, 0));
    lowerRightLeg->setSurface(blue);
    lowerRightLeg->setRotation(90, 0, 0);
    Bone* lrl = new Bone(lowerRightLeg);
    lrl->setJointOffset(0, -0.02, 0);

    Shape* lowerRightLegJoint = new Sphere(0.03, Point(0, -0.1, 0));
    lowerRightLegJoint->setSurface(green);
    Bone* lrlj = new Bone(lowerRightLegJoint);

    bPelvis->addChild("Chest", bChest);
    bPelvis->addChild("LeftLeg", ull);
    bPelvis->addChild("RightLeg", url);
    
    bChest->addChild("Head", bHead);
    bChest->addChild("UpperRightArm", ura);
    bChest->addChild("UpperLeftArm", ula);
    bChest->addChild("LeftShoulder", ulaj);
    bChest->addChild("RightShoulder", uraj);

    ula->addChild("LowerArm", lla);
    ula->addChild("Elbow", llaj);

    ura->addChild("LowerArm", lra);
    ura->addChild("Elbow", lraj);

    ull->addChild("LowerLeg", lll);
    ull->addChild("Knee", lllj);

    url->addChild("LowerLeg", lrl);
    url->addChild("Knee", lrlj);

    ura->setAnimation(Point(10, 0, 0), Point(-90, 0, 0), 45, 0);
    lra->setRotation(-45, 0, 0);
    
    ula->setAnimation(Point(10, 0, 0), Point(-90, 0, 0), 45, 45);
    lla->setRotation(-45, 0, 0);

    ull->setAnimation(Point(10, 0, 0), Point(-90, 0, 0), 45, 0);
    lll->setRotation(45, 0, 0);

    url->setAnimation(Point(10, 0, 0), Point(-90, 0, 0), 45, 45);
    // lrl->setAnimation(Point(45, 0, 0), Point(-90, 0, 0), 90, 90);
    lrl->setRotation(45, 0, 0);

    bPelvis->setRotation(0, 180, 0);
}

Shape* Person::getRoot()
{
	return new Cylinder(0, 0, Point(0, 0, 0));
}

void Person::nextFrame()
{
	float x = currentFrame.x;
	float y = currentFrame.y + 1;
	float z = currentFrame.z;

	currentFrame = Point(x, y, z);
}

void Person::render()
{
	glPushMatrix();
	glRotatef(1, 0, 1, 0);
	Bone::render();
	glPopMatrix();
}