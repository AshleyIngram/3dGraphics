#include <QGLWidget>
#include <math.h>
#include "IGLPolygon.h"
#include "GLCube.h"
#include <iostream>

GLCube::GLCube() { }

// Draw a cube from lines
void GLCube::render()
{
    glBegin(GL_LINES);
        glVertex3f(-0.5, -0.5, -0.5); glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5); glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5); glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5); glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5); glVertex3f( 0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, 0.5); glVertex3f( 0.5, -0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5); glVertex3f( 0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, -0.5); glVertex3f( 0.5, 0.5, -0.5);
        glVertex3f( 0.5, -0.5, -0.5); glVertex3f( 0.5, -0.5, 0.5);
        glVertex3f( 0.5, -0.5, 0.5); glVertex3f( 0.5, 0.5, 0.5);
        glVertex3f( 0.5, 0.5, 0.5); glVertex3f( 0.5, 0.5, -0.5);
        glVertex3f( 0.5, 0.5, -0.5); glVertex3f( 0.5, -0.5, -0.5);
    glEnd();
}
