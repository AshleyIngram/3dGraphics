#ifndef _XMASTREE_OBJ_H
#define _XMASTREE_OBJ_H 1

#include "Shape.h"
#include "Bone.h"

class ChristmasTree : public Bone
{
    public:
        ChristmasTree(int seasons, Point origin);
        ChristmasTree(int seasons, Point origin, int initialRotation);
        ChristmasTree(int seasons, Point origin, int initialRotation, uint seed);

    private:
    	static Shape* getRoot();
    	void growBranch(int s, int rotation, int size);
    	void growTwig(int rotation);
    	virtual void render();
    	void drawCylinder(float radius, float height, int rotation);
    	int seasons;
    	uint seed;
    	int initialRotation;
        Point origin;
};
#endif