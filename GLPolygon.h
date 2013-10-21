#ifndef _GL_POLYGON_H
#define _GL_POLYGON_H 1

#include <vector>
#include <QGLWidget>
#include "Point.h"

using namespace std;

class GLPolygon
{
	public:
		virtual void render();
		void rotate(int degrees);
		
		// TODO: Add getters and setters
		vector<vector<float> > vertices;
		vector<vector<int> > edges;
		vector<int> triangles;
		GLenum mode;
		int xRotate;
		int yRotate;
		int zRotate;
		// TODO: this should be an enum
		int colourMode;
		
    protected:
        void renderLines();
        void renderTriangles();
        void renderPoints();
        void interpolateColour(int val, int length);
        Point rotate(Point p);
};
#endif
