#include <QGLWidget>
#include <math.h>
#include "GL2D.h"
#include <iostream>

GLPolygon::GLPolygon(int vertices)
{
    this->vertices = vertices;
    x = 0;
    y = 0;
    angle = 0;
}

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
            
            // Angle to render at
            float angle = ((float)this->angle/100);
            
            // How far to pan on the horizontally
            float px = ((float)this->x/100);
            
            // How far to pan vertically
            float py = ((float)this->y/100);
            
            double x = (0.75 * sin(angleDelta * i + angle)) + px;
            double y = (0.75 * cos(angleDelta * i + angle)) + py;
            
            // Render vertex
            glVertex2f(x, y);
        }
        
    glEnd();
}