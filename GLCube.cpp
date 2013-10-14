#include <QGLWidget>
#include <math.h>
#include "GLCube.h"
#include <iostream>

GLCube::GLCube() 
{
     this->vertices = 
        {
            { -0.5, -0.5, -0.5 }, { -0.5, -0.5, 0.5 }, 
            { -0.5, 0.5, -0.5 },  { -0.5, 0.5, 0.5 }, 
            { 0.5, -0.5, -0.5 }, { 0.5, -0.5, 0.5 },
            { 0.5, 0.5, -0.5 }, { 0.5, 0.5, 0.5 }
        };
        
     this->edges = 
        {
            { 0, 1 }, { 1, 3 }, { 3, 2 }, { 2, 0 },
            { 0, 4 }, { 1, 5 }, { 3, 7 }, { 2, 6 },
            { 4, 6 }, { 6, 7 }, { 7, 5 }, { 5, 4 }
        };
}

// Draw a cube from lines
void GLPolygon::render()
{
    // HACK: Remove this when vertices and edges are vectors on GLPolygon
    GLCube* self = (GLCube*) this;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(1, 0, 0); 
    glRotatef(30, 1, 1, 0);
    glBegin(GL_LINES);
        for (int edge = 0; edge < 12; edge++)
        {
            glVertex3fv(self->vertices[self->edges[edge][0]]);
            glVertex3fv(self->vertices[self->edges[edge][1]]);
        }
    glEnd();
    glPopMatrix();
}
