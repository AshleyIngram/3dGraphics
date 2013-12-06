#include "Tree.h"
#include "Cylinder.h"
#include "ColouredSurface.h"
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

	for (int i = 0; i < 360; i++)
	{
		if (i%180 == 0)
		{
			glPushMatrix();
			glTranslatef(0, 0.2, 0);
			glRotatef(i, 0, 1, 0);
			growBranch(seasons-1, 200, 0.2);
			glPopMatrix();
		}
	}

	/*
	glPushMatrix();
		glTranslatef(0, 0.2, 0);
		growBranch(seasons-1, -50, 0.2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 0.2, 0);
		growBranch(seasons-1, 200, 0.2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 0.2, 0);
		glRotatef(90, 0, 1, 0);
		growBranch(seasons-1, 200, 0.2);
	glPopMatrix();
	*/
}

void Tree::growBranch(int s, int rotation, int size)
{
	if (s == 0)
	{
		return;
	}
	
	glPushMatrix();
		// Rotate canvas around parent, to position correctly
		glRotatef(rotation, 1, 0, 0);
		drawCylinder(0.025, 0.2, rotation);
		glTranslatef(0.0, 0, 0.05);

		growBranch(s-1, -20, 0.4);
		glTranslatef(0, 0, -(size/2));

		growBranch(s-1, 20, 0.4);
		glTranslatef(0, 0, -(size/2));

		// Pop the transforms applied in growBranch
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
		// glRotatef(-30, 0, 1, 0);
		// growTwig();
	glPopMatrix();
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

	// Translate to the end of the shape
	glPushMatrix();
		glTranslatef(0, 0, (size/2));
		shape.render();
}