#ifndef _BONE_H
#define _BONE_H 1

#include "Renderable.h"

class Bone
{
    public:               
        void render();
        
    protected:
        Renderable* shape;
        std::vector<Bone*> Children;
		
		// TODO: Define what a surface is
		Surface* surface;
};
#endif
