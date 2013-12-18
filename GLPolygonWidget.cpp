#include <QWidget>
#include <QMouseEvent>
#include "GLPolygonWidget.h"
#include "GLPolygonWindow.h"
#include <iostream>
#include "Cone.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "ColouredSurface.h"
#include "Bone.h"
#include "Person.h"
#include "TexturedSurface.h"
#include "Arrow.h"
#include "ChristmasTree.h"
#include "Snowflake.h"
#include <sstream>
#include "Terrain.h"
#include <math.h>
#include "Snowman.h"
#include "HeightSurface.h"

#include <QGLShader>
#include "GL/gl.h"
#include <fstream>

GLPolygonWidget::GLPolygonWidget(QWidget* parent, Scene* scene) 
{
    this->parent = parent;
    this->scene = scene;
    this->rotateStartPoint = Point(0, 0, 0);
    this->rotateBy = Point(0, 0, 0);
    this->camera = scene->camera;
    this->enableShader = false;
}

void GLPolygonWidget::mouseClickEvent(QMouseEvent* e)
{
    this->rotateStartPoint = Point(0, 0, 0);
}

void GLPolygonWidget::mouseMoveEvent(QMouseEvent* e)
{
    rotateBy = Point(rotateStartPoint.x - e->x(), rotateStartPoint.y - e->y(), 0);
    rotateStartPoint = Point(e->x(), e->y(), 0);
    update();
}

void GLPolygonWidget::loadShader()
{
    // Get shader code from file
    std::ifstream shaderFile;
    shaderFile.open("Shaders/ShadowShader.glsl");
    std::string shaderCode((std::istreambuf_iterator<char>(shaderFile)), std::istreambuf_iterator<char>());
    shaderFile.close();

    QGLShader frag_shader(QGLShader::Fragment);
    frag_shader.compileSourceCode(shaderCode.c_str());

    std::ifstream vertexShader;
    vertexShader.open("Shaders/ShadowVertexShader.glsl");
    std::string vert_shaderCode((std::istreambuf_iterator<char>(vertexShader)), std::istreambuf_iterator<char>());
    shaderFile.close();

    QGLShader vert_shader(QGLShader::Vertex);
    vert_shader.compileSourceCode(vert_shaderCode.c_str());

    QGLShaderProgram* program = new QGLShaderProgram(context(), this);
    program->addShader(&frag_shader);
    program->addShader(&vert_shader);
    program->link();
    program->bind();
    this->shader = program;
}


// Initial OpenGL setup
void GLPolygonWidget::initializeGL()
{
    loadShader();
    this->scene->setShader(shader);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.3, 0.3, 0.3, 0.0);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    
    static const GLfloat black[4] = { 0.0, 0.0, 0.0, 1.0 };
    static const GLfloat white_light[4] = { 1.0, 1.0, 1.0, 1.0 };
    static const GLfloat grey[4] = { 0.4, 0.4, 0.4, 1.0 };
    static const float lightPosition[] = { -100, 100, 0, 1 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);

    // Tree
    Bone* tree = new ChristmasTree(5, Point(0.5, -0.27, 0));
    scene->addShape("Tree", tree);

    // Terrain
    Terrain* terrainShape = new Terrain();
    Surface* white = new ColouredSurface(1, 1, 1);
    Surface* green = new ColouredSurface(0, 1, 0);
    terrainShape->setSurface(new HeightSurface());
    Bone* terrain = new Bone(terrainShape);
    scene->addShape("Terrain", terrain);

    int numSnowflakes = 2000;

    // Create a snowflake
    for (int i = 0; i < numSnowflakes; i++)
    {
        Bone* snowflake = new Snowflake(terrainShape, camera);
        std::stringstream ss;
        ss << i;
        scene->addShape("Snowflake" + ss.str(), snowflake);
    }

    // Snowman
    Bone* snowman = new Snowman(Point(-0.5, -0.5, 0));
    scene->addShape("Snowman", snowman);
}

// Resize the viewport
void GLPolygonWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-fmax(1, (double)w/h), fmax(1, (double)w/h), -fmax(1, (double)h/w), fmax(1, (double)h/w), -1, 2);
    glViewport(0, 0, w, h);
}

// Repaint OpenGL widgets
void GLPolygonWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (this->enableShader)
    {
        this->shader->bind();
    }
    else
    {
        this->shader->release();
    }

    // Render child polygon
    glMatrixMode(GL_MODELVIEW);
    camera->setX(rotateBy.x);
    camera->setY(rotateBy.y);
    scene->render(this->enableShader);
    camera->setX(0);
    camera->setY(0);
    rotateBy = Point();

    // Flush to render
    glFlush();
}

// Render the Polygon Widget
void GLPolygonWidget::render()
{
    GLPolygonWidget::paintGL();
}
