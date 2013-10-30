#ifndef _SHAPE_H
#define _SHAPE_H 1

#include <vector>
#include "Point.h"
#include "Surface.h"
#include "Triangle.h"
#include "Quad.h"

using namespace std;

class Shape
{
	public:
		Shape();
		Shape(Point origin);

		void render();
		void rotate();		
		void setRotation(float x, float y, float z);
		void setOrigin(float x, float y, float z);
		void setOrigin(Point p);
		void setSurface(Surface surface);

	protected:
		Point rotate(Point p);
		void render(Point p, int i);

		vector<Triangle> triangles;
		vector<Quad> quads;
		Point origin;

		// TODO: What is a surface?
		Surface surface;
		
	private:
		float xRotate;
		float yRotate;
		float zRotate;
};
#endif