#ifndef _SCENE_H
#define _SCENE_H 1

#include "Bone.h"
#include <string>
#include <map>

class Scene
{
	public:
		Scene();

		void addShape(std::string key, Bone* bone);
		void removeShape(std::string key);
		void render();

	protected:
		std::map<std::string, Bone*> bones;
};

#endif