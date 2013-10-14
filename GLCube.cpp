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
        
     this->triangles = 
     {
         0, 1, 3,    0, 3, 2,    0, 1, 4,    1, 4, 5, 
         0, 2, 4,    2, 6, 4,    5, 4, 6,    5, 6, 7, 
         2, 3, 7,    2, 7, 6,    1, 5, 7,    1, 7, 3
     };
     
     this->mode = GL_TRIANGLES;
}

// Draw a cube from lines
void GLCube::render()
{
    // HACK: Remove this when vertices and edges are vectors on GLPolygon
    GLCube* self = (GLCube*) this;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(1, 0, 0); 
    glRotatef(30, 1, 1, 0);
    
    if (self->mode == GL_LINES) 
    {
        glBegin(GL_LINES);
            for (int edge = 0; edge < 12; edge++)
            {
                glVertex3fv(self->vertices[self->edges[edge][0]]);
                glVertex3fv(self->vertices[self->edges[edge][1]]);
            }
        glEnd();
    }
    else
    {
        // Assume triangles
        glBegin(self->mode);
            for (int triangle = 0; triangle < 12; triangle++)
            { 
                float a = self->vertices[self->triangles[triangle]][0];
                float b = self->vertices[self->triangles[triangle]][1];
                float c = self->vertices[self->triangles[triangle]][2];
                
                std::cout << "(" << a << ", " << b << ", " << c << ")" << std::endl;
                
                glVertex3f(a, b, c);
            }
        glEnd();
    }
    
    glPopMatrix();
}
