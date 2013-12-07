#ifndef _SNOWFLAKE_H
#define _SNOWFLAKE_H 1

#include "Sphere.h"
#include "Bone.h"

class Snowflake : public Bone
{
	public:
		Snowflake(Point p);
		virtual void render();
		virtual void nextFrame(); 
	private:
		static Shape* getSphere();
		Point position;
		Point initialPosition;

};
#endif