#ifndef _GL_POLYGON_H
#define _GL_POLYGON_H 1

#include <vector>
#include <QGLWidget>

using namespace std;

class GLPolygon
{
	public:
		void render();
		
		vector<vector<float> > vertices;
		vector<vector<int> > edges;
		vector<int> triangles;
		GLenum mode;
};
#endif
