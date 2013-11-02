#ifndef _BONE_H
#define _BONE_H 1

#include <map>
#include <string>
#include "Shape.h"
#include "Point.h"

class Bone
{
    public:
    	Bone(Shape* shape);      
        void render();
        void addChild(std::string key, Bone* shape);
        void removeChild(std::string key);
        void setOrigin(Point origin);
        void setRotation(float x, float y, float z);
        Point getOrigin();
                
    protected:
        Shape* shape;
        std::map<std::string, Bone*> children;
        Point rotatePoint(Point p, float x, float y, float z);
        float xRotate;
        float yRotate;
        float zRotate;
};
#endif