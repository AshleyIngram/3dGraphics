#ifndef _TREE_OBJ_H
#define _TREE_OBJ_H 1

#include "Shape.h"
#include "Bone.h"

class Tree : public Bone
{
    public:
        Tree(int seasons);

    private:
    	static Shape* getRoot();
    	void growBranch(int s, int rotation, int size);
    	void growTwig(int rotation);
    	virtual void render();
    	void drawCylinder(float radius, float height, int rotation);
    	int seasons;
};
#endif