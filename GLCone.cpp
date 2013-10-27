#include "GLCone.h"
#include <math.h>
#include <iostream>

GLCone::GLCone()
{
}

void GLCone::render()
{
    int segments = 100;
    float height = 1.5;
        
    light();
    
    // Generate the top point
    Point top = Point(0, 0, height / 2);
    Vector topNormal = Vector(0, 0, height / 2).normalize();
    
    glBegin(GL_TRIANGLES);
    
    for (int i = 0; i < segments; i++)
    {
        float angle = (M_PI * 2 * i) / segments;
        float nextAngle = (M_PI * 2 * (i + 1)) / segments;
        float x1 = 0.5 * sin(angle);
        float y1 = 0.5 * cos(angle);
        float x2 = 0.5 * sin(nextAngle);
        float y2 = 0.5 * cos(nextAngle);
        
        Point p1 = Point(x1, y1, -(height / 2));
        Point p2 = Point(x2, y2, -(height / 2));
        
        p1 = rotate(p1);
        p2 = rotate(p2);
        
        Vector n1 = Vector(p1.x, p1.y, p1.z).normalize();
        Vector n2 = Vector(p2.x, p2.y, p2.z).normalize();
        
        if (i % 3 == 0)
        {
            glColor3f(1.0, 0.0, 0.0);
        }
        else if (i % 3 == 1)
        {
            glColor3f(0.0, 1.0, 0.0);
        }
        if (i % 3 == 2)
        {
            glColor3f(0.0, 0.0, 1.0);
        }
        
        glNormal3fv(topNormal.toArray());
        glVertex3fv(top.toArray());
        glNormal3fv(n1.toArray());
        glVertex3fv(p1.toArray());
        glNormal3fv(n2.toArray());
        glVertex3fv(p2.toArray());
    }
    
   
    Point bottomStart = Point(0, 0, -(height / 2));
    bottomStart = rotate(bottomStart);
    
    for (int i = 0; i < segments; i++)
    {       
        float angle =  M_PI * i * 2.0 / segments;
        float nextAngle = M_PI * (i + 1) * 2 / segments;
    
        float x1 = sin(angle) * 0.5;
        float y1 = cos(angle) * 0.5;
        float x2 = sin(nextAngle) * 0.5;
        float y2 = cos(nextAngle) * 0.5;
        
        Point b2 = Point(x1, y1, -(height / 2));
        Point b3 = Point(x2, y2, -(height / 2));
        
        Vector n1 = ((Vector)bottomStart).normalize();
        Vector n2 = ((Vector)b2).normalize();
        Vector n3 = ((Vector)b3).normalize();
    
        b2 = rotate(b2);
        b3 = rotate(b3);
  
        glVertex3fv(b2.toArray());
        glVertex3fv(b3.toArray());
        glVertex3fv(bottomStart.toArray());
    }
    
    glEnd();
}
