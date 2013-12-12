#include "Shape.h"
#include "Matrix.h"
#include "AlternatingSurface.h"
#include "Bone.h"
#include <iostream>

using namespace std;

Shape::Shape()
{
	// Default to the centre of the canvas
	this->origin = Point(0, 0, 0);

	// Default to empty arrays of Triangles and Quads
	this->triangles = vector<Triangle>();
	this->quads = vector<Quad>();

	// Default to the only surface we have at the moment
	this->surface = new AlternatingSurface();
	this->hasTexture = false;
}

Shape::Shape(Point origin)
{
	this->origin = origin;
	this->triangles = vector<Triangle>();
	this->quads = vector<Quad>();
	this->surface = new AlternatingSurface();
}

void Shape::render()
{
	if (hasTexture)
	{
		GLuint texture = ((TexturedSurface*)this->surface)->getTexture();
		
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);

	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}

	// First triangles...
	glBegin(GL_TRIANGLES);
	for (uint i = 0; i < this->triangles.size()*3; i+=3)
	{
		Triangle tri = this->triangles[i/3];

		this->renderPoint(tri.p1, i);
		this->renderPoint(tri.p2, i+1);
		this->renderPoint(tri.p3, i+2);
	}
	glEnd();

	// Then quads.
	glBegin(GL_QUADS);
	for(uint i = 0; i < this->quads.size()*4; i+=4)
	{
		Quad quad = this->quads[i/4];

		// offset by the points we've already rendered
		int index = i + (this->triangles.size() * 3);

		this->renderPoint(quad.p1, index);
		this->renderPoint(quad.p2, index+1);
		this->renderPoint(quad.p3, index+2);
		this->renderPoint(quad.p4, index+3);		
	}
	glEnd();
}

void Shape::renderPoint(Vertex p, int i)
{
	this->surface->setProperty(p, i);
	glNormal3fv(p.normal.toArray());
	glVertex3fv(p.toArray());
}

void Shape::rotate()
{
	/*
	// First for triangles
	for (uint i = 0; i < this->triangles.size(); i++)
	{
		Triangle tri = this->triangles[i];
		tri.p1 = this->rotate(tri.p1);
		tri.p2 = this->rotate(tri.p2);
		tri.p3 = this->rotate(tri.p3);
		this->triangles[i] = tri;
	}

	// Then for quads
	for (uint i = 0; i < this->quads.size(); i++)
	{
		Quad quad = this->quads[i];
		quad.p1 = this->rotate(quad.p1);
		quad.p2 = this->rotate(quad.p2);
		quad.p3 = this->rotate(quad.p3);
		quad.p4 = this->rotate(quad.p4);

		this->quads[i] = quad;
	}
	*/
}

Point Shape::rotate(Point p)
{
	Point point = Matrix::getZRotationMatrix(this->zRotate) * &p;
    point = Matrix::getXRotationMatrix(this->xRotate) * &point;    
    point = Matrix::getYRotationMatrix(this->yRotate) * &point;
    return point;
}

void Shape::setRotation(float x, float y, float z)
{
	this->xRotate = x;
	this->yRotate = y;
	this->zRotate = z;
	this->rotate();
}

void Shape::rotateX(float x)
{
	this->xRotate = x;
	this->rotate();
}

void Shape::rotateY(float y)
{
	this->yRotate = y;
	this->rotate();
}

void Shape::rotateZ(float z)
{
	this->zRotate = z;
	this->rotate();
}

float Shape::getXRotation()
{
	return xRotate;
}

float Shape::getYRotation()
{
	return yRotate;
}

float Shape::getZRotation()
{
	return zRotate;
}

void Shape::setOrigin(float x, float y, float z)
{
	this->origin = Point(x, y, z);
}

void Shape::setOrigin(Point p)
{
	this->origin = p;
}

Point Shape::getOrigin()
{
	return this->origin;
}
		
void Shape::setSurface(Surface* surface)
{
	this->hasTexture = false;
	this->surface = surface;
}

void Shape::setTexture(TexturedSurface* surface)
{
	this->hasTexture = true;
	this->surface = surface;
}

Shape::operator Bone()
{
	return Bone(this);
}
