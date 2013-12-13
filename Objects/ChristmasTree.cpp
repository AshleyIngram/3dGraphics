#include "ChristmasTree.h"
#include "Cylinder.h"
#include "ColouredSurface.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h> 
#include "Sphere.h"

ChristmasTree::ChristmasTree(int seasons, Point origin) : Bone(getRoot())
{
	this->seasons = seasons;

	if (seasons == 0)
	{
		return;
	}

	ColouredSurface* brown = new ColouredSurface(0.33, 0.21, 0.04);
	this->shape->setSurface(brown);
	this->origin = origin;
	this->seed = (rand() % 100) + 1;
	this->initialRotation = 130;
}

ChristmasTree::ChristmasTree(int seasons, Point origin, int initialRotation) : Bone(getRoot())
{
	this->seasons = seasons;

	if (seasons == 0)
	{
		return;
	}

	ColouredSurface* brown = new ColouredSurface(0.33, 0.21, 0.04);
	this->shape->setSurface(brown);
	this->origin = origin;
	this->seed = (rand() % 100) + 1;
	this->initialRotation = initialRotation;
}

ChristmasTree::ChristmasTree(int seasons, Point origin, int initialRotation, uint seed) : Bone(getRoot())
{
	this->seasons = seasons;

	if (seasons == 0)
	{
		return;
	}

	ColouredSurface* brown = new ColouredSurface(0.33, 0.21, 0.04);
	this->shape->setSurface(brown);
	this->origin = origin;
	this->seed = seed;
	this->initialRotation = initialRotation;
}

Shape* ChristmasTree::getRoot()
{
	return new Cylinder(0.05, 1.3, Point(0, 0, 0));
}

void ChristmasTree::render()
{
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glPushMatrix();
	glScalef(0.7, 0.7, 0.7);
	glTranslatef(origin.x, origin.y, origin.z);

	srand(seed);
	// Render self
	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		this->shape->render();
	glPopMatrix();

	for (int i = 0; i < 360; i++)
	{
		if (i%90 == 0)
		{
			for (int j = 0; j < 3; j++)
			{
				glPushMatrix();
				glTranslatef(0, 0.3 * j, 0);
				glRotatef(i, 0, 1, 0);

				// subtract j, giving the 'pyramid' style shape
				growBranch(seasons-(1 + j/2), initialRotation, 0.2);
				glPopMatrix();
			}
		}
	}

	// Grow a branch on top so the tree isn't balding.
	glPushMatrix();
	glTranslatef(0, 0.2, 0);
	// glRotatef(0, 0, 1, 0);
	growBranch(seasons-1, 270, 0.2);
	glPopMatrix();
	glPopMatrix();
	glDisable(GL_LIGHTING);
}

void ChristmasTree::growBranch(int s, int rotation, int size)
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

		double r = r = ((double) rand() / (RAND_MAX));
		
		// 30% chance of bauble
		if (s == 1 && r < 0.4)
		{
			// Add a bauble on end branches
			Shape bauble = Sphere(0.02, Point(0, 0, 0), 10);
			ColouredSurface red = ColouredSurface(1, 0, 0);
			bauble.setSurface(&red);
			glPushMatrix();
				glTranslatef(0, 0.03, 0);
				bauble.render();
			glPopMatrix();
		}

		growBranch(s-1, -20, 0.4);
		glTranslatef(0, 0, -(size/2));

		growBranch(s-1, 20, 0.4);
		glTranslatef(0, 0, -(size/2));

		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		growBranch(s-1, -20, 0.4);
		glPopMatrix();

		glPushMatrix();
		glRotatef(-90, 0, 1, 0);
		growBranch(s-1, -20, 0.4);
		glPopMatrix();

		// Pop the transforms applied in growBranch
		glPopMatrix();

	glPopMatrix();
}

void ChristmasTree::growTwig(int rotation)
{
	drawCylinder(0.01, 0.2, rotation);
}

void ChristmasTree::drawCylinder(float r, float size, int rotation)
{
	// Construct the actual shape
	Shape shape = Cylinder(r, size, Point(0, 0, 0), 10);
	ColouredSurface green = ColouredSurface(0.0, 0.392, 0.0);
	shape.setSurface(&green);

	// Translate to the end of the shape
	glPushMatrix();
		glTranslatef(0, 0, (size/2));
		shape.render();
}