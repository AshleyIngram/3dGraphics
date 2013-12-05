#include "Tree.h"
#include "Cylinder.h"
#include "ColouredSurface.h"
#include "Branch.h"
#include <iostream>
#include <sstream>
#include <string>
#include "Sphere.h"

Tree::Tree(int seasons) : Bone(getRoot())
{
	this->seasons = seasons;

	if (seasons == 0)
	{
		return;
	}

	ColouredSurface* brown = new ColouredSurface(0.33, 0.21, 0.04);
	this->shape->setSurface(brown);

	/*for (int i = 0; i < 4; i++)
	{
		float x = 0.0;
		float y = 0.1;
		if (i % 2 == 0)
			y = -y;

		float z = 0.2;
		Cylinder* c = new Cylinder(0.02, 0.4, Point(x, y, z));
		Branch* b = new Branch(c, seasons-1);
		if (i % 2 == 0)
			b->setJointOffset(0, -0.04, 0);
		else
			b->setJointOffset(0, 0.04, 0);

		if (i % 2 == 0)
			b->setRotation(50, 0, 0);
		else
			b->setRotation(-50, 0, 0);

		std::stringstream ss;
		ss << i; 
		std::string key = "Branch" + ss.str();
		this->addChild(key, b);
	}*/
}

Shape* Tree::getRoot()
{
	return new Cylinder(0.05, 0.5, Point(0, 0, 0));
	// return new Cylinder(0.00, 0.0, Point(0, 0, 0));
}

void Tree::render()
{
	// Render self
	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		this->shape->render();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 0.2, 0);
		growBranch(seasons-1, -50, 0.2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 0.2, 0);
		growBranch(seasons-1, 200, 0.2);
	glPopMatrix();
}

void Tree::growBranch(int s, int rotation, int size)
{
	if (s == 0)
	{
		return;
	}
	
	glPushMatrix();
		// Rotate canvas around parent, to position correctly
		// glTranslatef(0, 0.4, 0);
		glRotatef(rotation, 1, 0, 0);
		// glTranslatef(0, -0.4, 0);
		drawCylinder(0.025, 0.2, rotation);
		glTranslatef(0.0, 0, 0.05);

		// Sphere sph = Sphere(0.02, Point(0, 0, 0));
		// sph.render();
		//growBranch(s-1, -10, 0.4);
		//glTranslatef(0, 0, -(size/2));
		//glPopMatrix();

		growBranch(s-1, -20, 0.4);
		glTranslatef(0, 0, -(size/2));

		growBranch(s-1, 20, 0.4);
		glTranslatef(0, 0, -(size/2));

		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
		// glRotatef(-30, 0, 1, 0);
		// growTwig();
	glPopMatrix();
	// glPopMatrix();
}

void Tree::growTwig(int rotation)
{
	drawCylinder(0.01, 0.2, rotation);
}

void Tree::drawCylinder(float r, float size, int rotation)
{
	// Construct the actual shape
	Shape shape = Cylinder(r, size, Point(0, 0, 0));
	ColouredSurface brown = ColouredSurface(0.33, 0.21, 0.04);
	shape.setSurface(&brown);

	// glRotatef(rotation, 1, 0, 0);
	glPushMatrix();
		glTranslatef(0, 0, (size/2));
		shape.render();
}
