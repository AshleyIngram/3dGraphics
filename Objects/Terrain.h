#ifndef _H_TERRAIN
#define _H_TERRAIN 1
#include "Shape.h"
#include "Point.h"
#include <vector>

class Terrain : public Shape
{
	public:
		Terrain();
		void setCollision(float x, float y);
		virtual void render();

	protected:
		int getDepth(float x, float y);
		void setRenderPoints();
		void increasePoint(int i, int j, int spread);
		Vector getNormal(int i, int j);
		int size;
		std::vector<std::vector<Point> > map;
};
#endif