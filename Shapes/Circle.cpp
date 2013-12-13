#include "Circle.h"
#include <math.h>
#include <iostream>

Circle::Circle()
{
	this->radius = 0.5;
	this->quality = 10;
	this->origin = Point(0, 0, 0);
	this->setGeometry();
}

Circle::Circle(Point origin)
{
	this->radius = 0.5;
	this->quality = 10;
	this->origin = origin;
	this->setGeometry();
}

Circle::Circle(float radius)
{
	this->radius = radius;
	this->quality = 10;
	this->origin = Point(0, 0, 0);
	this->setGeometry();
}

Circle::Circle(float radius, Point origin)
{
	this->radius = radius;
	this->origin = origin;
	this->quality = 10;
	this->setGeometry();
}

Circle::Circle(float radius, Point origin, float quality)
{
	this->radius = radius;
	this->origin = origin;
	this->quality = quality;
	this->setGeometry();
}

void Circle::setGeometry()
{
	double PI_2 = M_PI * 2;

	for (int i = 0; i <= quality; i++)
	{
		Point p = Point(cos(i * PI_2 / quality) * radius, sin(i * PI_2 / quality) * radius, 0);
		points.push_back(p);
	}
}

void Circle::render()
{
	glBegin(GL_TRIANGLE_FAN);
		this->surface->setProperty(origin, 0);
		glVertex2f(origin.x, origin.y);
		for (int i = 0; i < points.size(); i++)
		{
			Point p = points[i];
			this->surface->setProperty(p, i);
			glVertex2f(p.x, p.y);
		}
	glEnd();
}