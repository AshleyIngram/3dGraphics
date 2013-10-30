#ifndef _BONE_H
#define _BONE_H 1

#include "Shape.h"

class Bone
{
    public:               
        void render();
        
    protected:
        Shape* shape;
        std::vector<Bone*> Children;
};
#endif
