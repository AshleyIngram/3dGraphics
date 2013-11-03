#include "Scene.h"
using namespace std;

Scene::Scene()
{
	this->bones = map<string, Bone*>();
}

void Scene::addShape(string key, Bone* shape)
{
	bones[key] = shape;
}

void Scene::removeShape(string key)
{
	map<string, Bone*>::iterator it;
	it = bones.find(key);
	bones.erase(it);
}

void Scene::render()
{
	typedef map<string, Bone*>::iterator mapi;

	for(mapi i = bones.begin(); i != bones.end(); i++) 
	{
		i->second->render();
	}
}

map<string, Bone*> Scene::getBones()
{
	return bones;
}