#ifndef _PELVIS_H
#define _PELVIS_H 1

#include "Shape.h"
#include "Bone.h"

class Person : public Bone
{
    public:
        Person();
        virtual void nextFrame();
        virtual void render();

    private:
    	static Shape* getRoot();
};
#endif