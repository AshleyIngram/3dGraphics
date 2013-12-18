#include "Scene.h"
#include "GL/gl.h"
#include <iostream>
#include <QtGlobal>
using namespace std;

Scene::Scene(Camera* camera)
{
	this->bones = map<string, Bone*>();
	this->camera = camera;
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

void Scene::setShader(QGLShaderProgram* shader)
{
	this->shader = shader;
}

QMatrix4x4 floatToQMatrix(float matrix_f[16])
{
	// Convert to the right major-order
	qreal matrix_qr[16] = {
		matrix_f[0], matrix_f[4], matrix_f[8], matrix_f[12],
		matrix_f[1], matrix_f[5], matrix_f[9], matrix_f[13],
		matrix_f[2], matrix_f[6], matrix_f[10], matrix_f[14],
		matrix_f[3], matrix_f[7], matrix_f[11], matrix_f[15]
	};

	return QMatrix4x4(matrix_qr);
}

QMatrix4x4 vectorToQMatrix(vector<vector<float> > matrix_v)
{
	qreal matrix_qr[16];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix_qr[i * j] = matrix_v[i][j];
		}
	}

	return QMatrix4x4(matrix_qr);
}

Vector QVectorToVector(QVector4D v)
{
	float x = (float)v.x();
	float y = (float)v.y();
	float z = (float)v.z();
	float w = (float)v.w();
	return Vector(x, y, z, w);
}

void Scene::renderScene()
{
	
	typedef map<string, Bone*>::iterator mapi;

	for (mapi i = bones.begin(); i != bones.end(); i++)
	{
		i->second->render();
	}
}

void Scene::render()
{
	QMatrix4x4 lightProjectionMatrix;
	QMatrix4x4 lightModelViewMatrix;
	GLfloat lightPosition[4] = { 0, 0, -1.0, 0.0 };

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Create the shadow map texture
	GLuint shadowMapTexture;
	glGenTextures(1, &shadowMapTexture);
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 512, 612, 0,
				 GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	// Compute the matrices for light and camera
    glPushMatrix();
    	glLoadIdentity();
    	GLfloat cameraProjection_f[16];
    	glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjection_f);

    	glLoadIdentity();
    	camera->moveCamera();
    	GLfloat cameraView_f[16];
    	glGetFloatv(GL_MODELVIEW_MATRIX, cameraView_f);

    	glLoadIdentity();
    	GLfloat lightProjection_f[16];
    	glGetFloatv(GL_MODELVIEW_MATRIX, lightProjection_f);
    	lightProjectionMatrix = floatToQMatrix(lightProjection_f);

    	glLoadIdentity();
    	gluLookAt(lightPosition[0], lightPosition[1], lightPosition[2], 0, 0, 0, 0, 1, 0);
    	GLfloat lightView_f[16];
    	glGetFloatv(GL_MODELVIEW_MATRIX, lightView_f);
    	lightModelViewMatrix = floatToQMatrix(lightView_f);
    glPopMatrix();

	// First render pass from the lights point of view
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(lightProjection_f);

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(lightView_f);

	glViewport(0, 0, 512, 612);

	// Disable colour
	glColorMask(0, 0, 0, 0);

	// Cull the front-faces for rounding error
	glCullFace(GL_FRONT);

	// Render and store
	renderScene();
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, 512, 612);

	// Set everything back to normal
	glCullFace(GL_BACK);
	glColorMask(1, 1, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT);

	// Second render pass from the point of view of the camera
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(cameraProjection_f);

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(cameraView_f);

    renderScene();

    // Bias matrix (to switch to the correct co-ords)
	static QMatrix4x4 biasMatrix(0.5f, 0.0f, 0.0f, 0.0f,
								0.0f, 0.5f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.5f, 0.0f,
								0.5f, 0.5f, 0.5f, 1.0f);

	// Transpose the bias (from row to column major)
	biasMatrix = biasMatrix.transposed();

	QMatrix4x4 textureMatrix = biasMatrix * lightProjectionMatrix * lightModelViewMatrix;
	shader->setUniformValueArray("depthMVP", &textureMatrix, 1);
	
	// Free texture memory
	glDeleteTextures(1, &shadowMapTexture);
}

map<string, Bone*> Scene::getBones()
{
	return bones;
}