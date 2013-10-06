#include <QGLWidget>
#include <math.h>
#include "GLPolygon.h"
#include <iostream>

GLPolygon::GLPolygon(int vertices)
{
    this->vertices = vertices;
    x = 0;
    y = 0;
    angle = 0;
}

// Draw a shape consisting of an arbitary number of vertices
void GLPolygon::render()
{
    const float PI = 3.14159;
    float angleDelta = (2 * PI) / vertices;
    
    glBegin(GL_POLYGON);        
        for (int i = 0; i < vertices; i++)
        {
            // Set colour
            if (i % 3 == 0)
            {
                glColor3f(1.0, 0.0, 0.0);
            }
            else if (i % 2 == 0)
            {
                glColor3f(0.0, 1.0, 0.0);
            }
            else 
            {
                glColor3f(0.0, 0.0, 1.0);
            }
                        
            double x = (0.75 * sin(angleDelta * i + this->angle)) + this->x;
            double y = (0.75 * cos(angleDelta * i + this->angle)) + this->y;
            
            // Render vertex
            glVertex2f(x, y);
        }
        
    glEnd();
}
