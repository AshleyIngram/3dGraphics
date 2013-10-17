#ifndef _GL_POLYGON_H
#define _GL_POLYGON_H 1

#include <vector>
#include <QGLWidget>

using namespace std;

class GLPolygon
{
	public:
		void render();
		void rotate(int degrees);
		
		// TODO: Add getters and setters
		vector<vector<float> > vertices;
		vector<vector<int> > edges;
		vector<int> triangles;
		GLenum mode;
		int xRotate;
		int yRotate;
		int zRotate;
};
#endif
