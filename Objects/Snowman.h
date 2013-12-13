#ifndef _H_SNOWMAN
#define _H_SNOWMAN 1
#include "Bone.h"
#include "ColouredSurface.h"

class Snowman : public Bone
{
	public:
		Snowman(Point origin);
		virtual void render();
		~Snowman();

	private:
		static Shape* getRoot();
};

#endif