#ifndef _RENDERABLE_H
#define _RENDERABLE_H 1

#include "Point.h"

class Renderable
{
	public:
		void render();
		void rotate();		
		void setRotation(float x, float y, float z);
		void setOrigin(float x, float y);
	
	protected:
		std::vector<Triangle> Triangles = std::vector<Triangle>();
		std::vector<Quad> Quads = std::vector<Quad>();
		Point origin = Point();
		
	private:
		float xRotate;
		float yRotate;
		float zRotate;
};
#endif