#ifndef _BONE_H
#define _BONE_H 1

#include <map>
#include <string>
#include "Shape.h"
#include "Point.h"
#include "Matrix.h"

class Bone
{
    public:
    	Bone(Shape* shape);      
        virtual void render();
        void addChild(std::string key, Bone* shape);
        void removeChild(std::string key);
        void setOrigin(Point origin);
        void setRotation(float x, float y, float z);
        Point getOrigin();
        void setJointOffset(float x, float y, float z);
        void setJointOffset(Point p);
        void animate();
        virtual void nextFrame();
        void setAnimation(Point start, Point end, int rate, int delay);
        Shape* shape;
                
    protected:
        std::map<std::string, Bone*> children;
        Point rotatePoint(Point p, float x, float y, float z);
        float xRotate;
        float yRotate;
        float zRotate;
        Point jointOffset;
        Point animationStart;
        Point animationStop;
        int animationRate;
        bool animateForward;
        int animationFrame;
        Point currentFrame;
        bool firstFrame;
        int frameDelay;
};
#endif