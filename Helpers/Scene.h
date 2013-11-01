#ifndef _SCENE_H
#define _SCENE_H 1

#include "Shape.h"
#include <string>
#include <map>

class Scene
{
	public:
		Scene();

		void addShape(std::string key, Shape* shape);
		void removeShape(std::string key);
		void render();

	protected:
		std::map<std::string, Shape*> shapes;
};

#endif