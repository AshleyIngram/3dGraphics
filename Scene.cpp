#include "Scene.h"
using namespace std;

Scene::Scene()
{
	this->shapes = map<string, Shape>();
}

void Scene::addShape(string key, Shape shape)
{
	shapes[key] = shape;
}

void Scene::removeShape(string key)
{
	map<string, Shape>::iterator it;
	it = shapes.find(key);
	shapes.erase(it);
}

void Scene::render()
{
	typedef map<string, Shape>::iterator mapi;

	for(mapi i = shapes.begin(); i != shapes.end(); i++) 
	{
		i->second.render();
	}
}