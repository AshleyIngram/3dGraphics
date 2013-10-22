#include <vector>
#include <math.h>
#include "GLSphere.h"
#include <iostream>

GLSphere::GLSphere()
{
}

void GLSphere::render()
{
    int lats = 50;
    int longs = 50;
    float r = 0.5;
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);
    glColor3f(1.0, 0.0, 0.0);
    
    for(int i = 0; i <= lats; i++) 
    {
        // double lat1 = M_PI * (-0.5 + (double) (i - 1) / lats);
        double lat1 = (double)(M_PI * -2) + i * (double)(M_PI / lats);
        double sin1  = sin(lat1);
        double cos1 =  cos(lat1);

        // double lat2 = M_PI * (-0.5 + (double) i / lats);
        double lat2 = (double)(M_PI * -2) + i + 1 * (double)(M_PI / lats);
        double sin2 = sin(lat2);
        double cos2 = cos(lat2);

        glBegin(GL_QUADS);
        for(int j = 0; j <= longs; j++) 
        {
            // double lng = 2 * M_PI * (double) (j - 1) / longs;
            double lng1 = j * ((2 * M_PI) / longs);
            double lng2 = (j + 1) * ((2 * M_PI) / longs);
            // double x = cos(lng);
            // double y = sin(lng);
            
            // interpolateColour(i+j, lats+longs);
            if ((i + j) % 3 == 0)
            {
                glColor3f(1.0, 0.0, 0.0);
            }
            else if ((i + j) % 3 == 1)
            {
                glColor3f(0.0, 1.0, 0.0);
            }
            if ((i + j) % 3 == 2)
            {
                glColor3f(0.0, 0.0, 1.0);
            }
            
            /*glNormal3f(r * x * cos1, r * y * cos1, sin1);
            glVertex3f(r * x * cos1, r * y * cos1, sin1);
            
            glNormal3f(r * x * cos2, r * y * cos2, sin2);
            glVertex3f(r * x * cos2, r * y * cos2, sin2);*/
            
            Point p1 = Point(r * cos1 * cos(lng1), r * cos1 * sin(lng1), r * sin1);
            
            p1 = rotate(p1);
            glNormal3fv(p1.toArray());
            glVertex3fv(p1.toArray());
            
            Point p2 = Point(r * cos1 * cos(lng2), r * cos1 * sin(lng2), r * sin1);
            p2 = rotate(p2);
            glNormal3fv(p2.toArray());
            glVertex3fv(p2.toArray());
            
            Point p3 = Point(r * cos2 * cos(lng2), r * cos2 * sin(lng2), r * sin2);
            p3 = rotate(p3);
            glNormal3fv(p3.toArray());
            glVertex3fv(p3.toArray());
            
            Point p4 = Point(r * cos2 * cos(lng1), r * cos2 * sin(lng1), r * sin2);
            p4 = rotate(p4);
            glNormal3fv(p4.toArray());
            glVertex3fv(p4.toArray());
       }
       glEnd();
   }
    
   glPopMatrix();   
}
