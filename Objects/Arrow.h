#ifndef _ARROW_H
#define _ARROW_H 1

#include "Bone.h"
#include "Shape.h"
#include "Surface.h"
#include "Point.h"

class Arrow : public Bone
{
	public:
		Arrow(Surface* surface, Point p);
	private:
		static Shape* getRoot();
};
#endif