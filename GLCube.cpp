#include <QGLWidget>
#include <math.h>
#include "IGLPolygon.h"
#include "GLCube.h"
#include <iostream>

GLCube::GLCube() { }

// Draw a cube from lines
void GLCube::render()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(1, 0, 0); 
    glRotatef(30, 1, 1, 0);
    glBegin(GL_LINES);      
        glVertex3f(-0.5, -0.5, -0.5); glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5); glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5); glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5); glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5); glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, 0.5); glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5); glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, -0.5); glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0.5, -0.5, -0.5); glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5); glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5); glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, -0.5); glVertex3f(0.5, -0.5, -0.5);
    glEnd();
    glPopMatrix();
}
