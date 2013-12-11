#ifndef _SNOWFLAKE_H
#define _SNOWFLAKE_H 1

#include "Sphere.h"
#include "Bone.h"
#include "Terrain.h"

class Snowflake : public Bone
{
	public:
		Snowflake(Point p, Terrain* t);
		Snowflake(Terrain* t);
		virtual void render();
		virtual void nextFrame(); 

	private:
		static Shape* getSphere();
		Point getRandomPosition(bool reseed = true);
		Point position;
		Terrain* terrain;

};
#endif