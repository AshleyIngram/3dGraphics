#ifndef _SCENE_H
#define _SCENE_H 1

#include "Bone.h"
#include "Camera.h"
#include <string>
#include <map>
#include <QGLShaderProgram>

class Scene
{
	public:
		Scene(Camera* camera);

		void addShape(std::string key, Bone* bone);
		void removeShape(std::string key);
		void render(bool shaderEnabled);
		void setShader(QGLShaderProgram* shader);

		std::map<std::string, Bone*> getBones();
		Camera* camera;

	protected:
		std::map<std::string, Bone*> bones;
		QGLShaderProgram* shader;
		void renderScene();
};

#endif