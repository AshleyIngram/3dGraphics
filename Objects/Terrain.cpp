#include "Terrain.h"
#include "Point.h"
#include "Quad.h"
#include <iostream>
#include <math.h>
#include "Cylinder.h"

Terrain::Terrain()
{
	this->size = 75;
	this->map.resize(this->size);
	for (int i = 0; i < this->size; i++)
	{
		this->map[i].resize(this->size);
	}

	for (int i = 0; i <= size-1; i++)
	{
		for (int j = 0; j <= size-1; j++)
		{
			float x = ((float)2 / (size - 1) * i) - 1;
			float y = ((float)2 / (size - 1) * j) - 1;
			float z = (float)getDepth(i, j) / 100;
			map[i][j] = Point(x, z, y);
		}
	}

	setRenderPoints();
}

void Terrain::setRenderPoints()
{
	quads = std::vector<Quad>();

	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			Point p1 = map[i][j];
			Point p2 = map[i][j+1];
			Point p3 = map[i+1][j];
			Point p4 = map[i+1][j+1];

			/*Vector n1 = Vector(p1.x, p1.y, 1);
			Vector n2 = Vector(p2.x, p2.y, 1);
			Vector n3 = Vector(p3.x, p3.y, 1);
			Vector n4 = Vector(p4.x, p4.y, 1);*/
			Vector n1 = getNormal(i, j).normalize();
			Vector n2 = getNormal(i, j+1).normalize();
			Vector n3 = getNormal(i+1, j).normalize();
			Vector n4 = getNormal(i+1, j+1).normalize();

			Vertex v1 = Vertex(p1.x, p1.y, p1.z, n1);
			Vertex v2 = Vertex(p2.x, p2.y, p2.z, n2);
			Vertex v3 = Vertex(p3.x, p3.y, p3.z, n3);
			Vertex v4 = Vertex(p4.x, p4.y, p4.z, n4);

			Quad q = Quad(v1, v2, v4, v3);
			quads.push_back(q);
		}
	}
}

Vector Terrain::getNormal(int i, int j) 
{
	if (i == 0 || i == size-1 || j == 0 || j == size-1)
	{
		return Vector(0, 0, 1);
	}

	// Used for Central Differencing... doesn't really work because the size
	// differences aren't enough... 
	// float x = ((float)map[i-1][j].y - map[i+1][j].y) / 2;
	// float y = ((float)map[i][j-1].y - map[i][j+1].y) / 2;

	// return Vector(x, 1, y);

	// So flat shade instead
	Vector v1 = map[i][j];
	Vector v4 = map[i-1][j];
	Vector v2 = map[i][j+1];

	Vector a = Vector(v2.x - v1.x, v2.y - v1.y, v2.z - v1.z);
	Vector b = Vector(v4.x - v1.x, v4.y - v1.y, v4.z - v1.z);
	Vector n = a * b;
	return n;
}

void Terrain::render()
{
	// Fixed lighting for snow.
    /*glShadeModel(GL_FLAT);
    glDisable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);
    
    static const GLfloat black[4] = { 0.0, 0.0, 0.0, 1.0 };
    static const GLfloat white_light[4] = { 1.0, 1.0, 1.0, 1.0 };
    static const GLfloat grey[4] = { 0.3, 0.3, 0.3, 1.0 };
    static const float lightPosition[] = { -192, -358, 0, 0 };
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT1, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, black);

    Shape::render();

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT1);
    glEnable(GL_LIGHT0);*/

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	Shape::render();
	glDisable(GL_LIGHTING);
}

int Terrain::getDepth(float x, float y)
{
	return -65;
}

void Terrain::setCollision(float x, float y)
{
	// Precision. D:
	double dx = (double)round(x * 1000) / 1000;
	double dy = (double)round(y * 1000) / 1000;

	// Find the position in the map for the x and y
	float mapX = (((dx + 1) * size) / 2) - 1;
	float mapY = (((dy + 1) * size) / 2) - 1;

	// Stop overflows
	if (mapX <= -1)
		mapX = 0;
	if (mapY <= -1)
		mapY = 0;

	increasePoint(mapX, mapY, 40);
	setRenderPoints();
}

void Terrain::increasePoint(int i, int j, int spread)
{
	float depth = map[i][j].y;

	if (spread == 0)
	{
		map[i][j].y += 0.1;
		return;
	}

	if (i != size-1)
	{
		float adjacentDepth = map[i+1][j].y;
		if (depth - adjacentDepth > 0.02)
		{
			return increasePoint(i+1, j, spread-1);
		}
	}

	if (i != 0)
	{
		float adjacentDepth = map[i-1][j].y;
		if (depth - adjacentDepth > 0.02)
		{
			return increasePoint(i-1, j, spread-1);
		}
	}

	if (j != size-1)
	{
		float adjacentDepth = map[i][j+1].y;
		if (depth - adjacentDepth > 0.02)
		{
			return increasePoint(i, j+1, spread-1);
		}
	}

	if (j != 0)
	{
		float adjacentDepth = map[i][j-1].y;
		if (depth - adjacentDepth > 0.02)
		{
			return increasePoint(i, j-1, spread-1);
		}
	}

	map[i][j].y += 0.01;
}