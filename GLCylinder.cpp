#include "GLCylinder.h"
#include <math.h>
#include <iostream>

GLCylinder::GLCylinder()
{
}

void GLCylinder::render()
{
    int segments = 100;
    float height = 1;
        
    light();
    std::vector<Point> points = std::vector<Point>();
        
    glBegin(mode);
    for (int i = 0; i < segments; i++)
    {
        float angle =  M_PI * i * 2.0 / segments;
        float nextAngle = M_PI * (i + 1) * 2 / segments;
        
        float s1 = sin(angle) * 0.5;
        float s2 = sin(nextAngle) * 0.5;
        float c1 = cos(angle) * 0.5;
        float c2 = cos(nextAngle) * 0.5;
        
        Point p1 = Point(s1, c1, -(height / 2));       
        Point p2 = Point(s2, c2, -(height / 2));        
        Point p3 = Point(s1, c1, height / 2);        
        Point p4 = Point(s2, c2, height / 2);
                
        p1 = rotate(p1);
        p2 = rotate(p2);
        p3 = rotate(p3);
        p4 = rotate(p4);
        
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        
        Vector n1 = Vector(p1.x, p1.y, 0).normalize();
        Vector n2 = Vector(p2.x, p2.y, 0).normalize();
        Vector n3 = Vector(p3.x, p3.y, 0).normalize();
        Vector n4 = Vector(p4.x, p4.y, 0).normalize();
        
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
        
        glNormal3fv(n1.toArray());
        glVertex3fv(p1.toArray());
        glNormal3fv(n3.toArray());
        glVertex3fv(p3.toArray());
        glNormal3fv(n4.toArray());
        glVertex3fv(p4.toArray());
        glNormal3fv(n2.toArray());
        glVertex3fv(p2.toArray());
    }
       
    glEnd();
    
    glBegin(GL_TRIANGLES);
    
        Point bottomStart = Point(0, 0, -(height / 2));
        Point topStart = Point(0, 0, height / 2);
        
        bottomStart = rotate(bottomStart);
        topStart = rotate(topStart);
        
        for (int i = 0; i < segments; i++)
        {       
            float angle =  M_PI * i * 2.0 / segments;
            float nextAngle = M_PI * (i + 1) * 2 / segments;
        
            float x1 = sin(angle) * 0.5;
            float y1 = cos(angle) * 0.5;
            float x2 = sin(nextAngle) * 0.5;
            float y2 = cos(nextAngle) * 0.5;
            
            Point t2 = Point(x1, y1, height / 2);
            Point t3 = Point(x2, y2, height / 2);
            
            Point b2 = Point(x1, y1, -(height / 2));
            Point b3 = Point(x2, y2, -(height / 2));
        
            t2 = rotate(t2);
            t3 = rotate(t3);
            b2 = rotate(b2);
            b3 = rotate(b3);
        
            glVertex3fv(topStart.toArray());
            glVertex3fv(t2.toArray());
            glVertex3fv(t3.toArray());
            
            glVertex3fv(b2.toArray());
            glVertex3fv(b3.toArray());
            glVertex3fv(bottomStart.toArray());
        }
    
    glEnd();
}
