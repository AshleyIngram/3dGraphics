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

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			float x = ((float)2 / (size - 1) * i) - 1;
			float y = ((float)2 / (size - 1) * j) - 1;
			float z = (float)getDepth(i, j) / 100;
			map[i][j] = Point(x, z, y);
		}
	}

	this->setRenderPoints();

}

void Terrain::addBoundaryPoints(Point p1, Point p2, Point p3, Point p4)
{
	Vector nullVector = Vector(0, 0, 0, 0);
	
	Vertex v1 = Vertex(p1, nullVector);
	Vertex v2 = Vertex(p2, nullVector);
	Vertex v3 = Vertex(p3, nullVector);
	Vertex v4 = Vertex(p4, nullVector);

	Quad q = Quad(v1, v3, v4, v2);
	quads.push_back(q);
}

void Terrain::setRenderPoints()
{
	// Clear the points from last time
	quads = std::vector<Quad>();

	Vector nullVector = Vector(0, 0, 0, 0);

	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			Point p1 = map[i][j];
			Point p2 = map[i][j+1];
			Point p3 = map[i+1][j];
			Point p4 = map[i+1][j+1];

			Vector n1 = getNormal(i, j).normalize();
			Vector n2 = getNormal(i, j+1).normalize();
			Vector n3 = getNormal(i+1, j).normalize();
			Vector n4 = getNormal(i+1, j+1).normalize();

			Vertex v1 = Vertex(p1, n1);
			Vertex v2 = Vertex(p2, n2);
			Vertex v3 = Vertex(p3, n3);
			Vertex v4 = Vertex(p4, n4);

			Quad q = Quad(v1, v2, v4, v3);
			quads.push_back(q);

			// render the bottom plane
			Point b1 = map[i][j];
			b1.y = -0.75;
			Vertex pb1 = Vertex(b1, nullVector);

			Point b2 = map[i][j+1];
			b2.y = -0.75;
			Vertex pb2 = Vertex(b2, nullVector);

			Point b3 = map[i+1][j];
			b3.y = -0.75;
			Vertex pb3 = Vertex(b3, nullVector);
			
			Point b4 = map[i+1][j+1];
			b4.y = -0.75;
			Vertex pb4 = Vertex(b4, nullVector);

			Quad q2 = Quad(pb1, pb2, pb4, pb3);
			quads.push_back(q2);
		}
	}

	// Around the boundary
	{
		Point p1 = map[0][0];
		Point p2 = map[0][0];
		p2.y = -0.75;

		Point p3 = map[0][size-1];
		Point p4 = map[0][size-1];
		p4.y = -0.75;

		addBoundaryPoints(p1, p2, p3, p4);
	}
	{
		Point p1 = map[0][0];
		Point p2 = map[0][0];
		p2.y = -0.75;

		Point p3 = map[size-1][0];
		Point p4 = map[size-1][0];
		p4.y = -0.75;

		addBoundaryPoints(p1, p2, p3, p4);
	}
	{
		Point p1 = map[size-1][size-1];
		Point p2 = map[size-1][size-1];
		p2.y = -0.75;

		Point p3 = map[0][size-1];
		Point p4 = map[0][size-1];
		p4.y = -0.75;

		addBoundaryPoints(p1, p2, p3, p4);
	}
	{
		Point p1 = map[size-1][size-1];
		Point p2 = map[size-1][size-1];
		p2.y = -0.75;

		Point p3 = map[size-1][0];
		Point p4 = map[size-1][0];
		p4.y = -0.75;
		
		addBoundaryPoints(p1, p2, p3, p4);
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