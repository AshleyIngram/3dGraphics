#ifndef _SHAPE_H
#define _SHAPE_H 1

#include <vector>
#include "Point.h"
#include "Surface.h"
#include "Triangle.h"
#include "Quad.h"

class Shape
{
	public:
		Shape();
		Shape(Point origin);

		void render();
		void rotate();		
		void setRotation(float x, float y, float z);
		void rotateX(float x);
		void rotateY(float y);
		void rotateZ(float z);
		float getZRotation();
		float getXRotation();
		float getYRotation();
		void setOrigin(float x, float y, float z);
		void setOrigin(Point p);
		void setSurface(Surface* surface);

	protected:
		Point rotate(Point p);
		void renderPoint(Point p, int i);

		std::vector<Triangle> triangles;
		std::vector<Quad> quads;
		Point origin;
		Surface* surface;
		
	private:
		float xRotate;
		float yRotate;
		float zRotate;
}; 
#endif