#include "GLCylinder.h"
#include <math.h>
#include <iostream>

GLCylinder::GLCylinder()
{
}

void GLCylinder::render()
{
    int segments = 100;
        
    light();
        
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < segments; i++)
    {
        float angle =  M_PI * i * 2.0 / segments;
        float nextAngle = M_PI * (i + 1) * 2 / segments;
        
        float s1 = sin(angle) * 0.5;
        float s2 = sin(nextAngle) * 0.5;
        float c1 = cos(angle) * 0.5;
        float c2 = cos(nextAngle) * 0.5;
        
        Point p1 = Point(s1, c1, 0);
        Point p2 = Point(s2, c2, 0);
        Point p3 = Point(s1, c1, 0.7);
        Point p4 = Point(s2, c2, 0.7);
        
        p1 = rotate(p1);
        p2 = rotate(p2);
        p3 = rotate(p3);
        p4 = rotate(p4);
        
        // Top triangle
        glColor3f(0.0, 1.0, 0.0);
        glNormal3fv(p1.toArray());
        glVertex3fv(p1.toArray());
        
        glNormal3fv(p4.toArray());
        glVertex3fv(p4.toArray());
        
        glNormal3fv(p3.toArray());
        glVertex3fv(p3.toArray());
        
        // Bottom triangle
        glColor3f(1.0, 0.0, 0.0);
        glNormal3fv(p1.toArray());
        glVertex3fv(p1.toArray());
        
        glNormal3fv(p2.toArray());
        glVertex3fv(p2.toArray());
        
        glNormal3fv(p4.toArray());
        glVertex3fv(p4.toArray());
        /*glVertex3f(s1, c1, 0.0);
        glVertex3f(s2, c2, 1.0);
        glVertex3f(s1, c1, 1.0);*/
    }
    glEnd();
}

void GLCylinder::texture()
{
}

GLCylinder::~GLCylinder()
{
} 

