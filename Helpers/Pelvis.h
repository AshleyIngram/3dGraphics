#ifndef _PELVIS_H
#define _PELVIS_H 1

#include <map>
#include <string>
#include "Shape.h"
#include "Point.h"
#include "Matrix.h"
#include "Bone.h"

class Pelvis : public Bone
{
    public:
        Pelvis(Shape* shape);
        virtual void nextFrame();
        virtual void render();
};
#endif