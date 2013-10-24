#include <math.h>
#include "GLTorus.h"
#include <iostream>

GLTorus::GLTorus()
{
    this->textureImg = NULL;
}

Point calculatePoint(double s, double t, int sides, int rings)
{
    const float PI2 = M_PI * 2;
    
    // TODO: normals are these minus constants?
    double x = (0.1 * cos(s * PI2 / (double)sides) + 0.5) * cos(t * PI2 / (double)rings);
    double y = (0.1 * cos(s * PI2 / (double)sides) + 0.5) * sin(t * PI2 / (double)rings);
    double z = sin(s * PI2 / sides) * 0.1;
                
    return Point(x, y, z);
}

void GLTorus::render()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(1.0, 0.0, 0.0);
    light();

    int sides = 100;
    int rings = 100;
    const float PI2 = M_PI * 2;
    
     for (int j = 0; j < rings; j++)
     {
         
        glBegin(mode);
        for (int i = 0; i < sides; i++)
         {
               Point p1 = calculatePoint(i, j, sides, rings);
                Point p2 = calculatePoint(i, j + 1, sides, rings);
                Point p3 = calculatePoint(i + 1, j + 1, sides, rings);
                Point p4 = calculatePoint(i + 1, j, sides, rings);
                
                p1 = rotate(p1);
                p2 = rotate(p2);
                p3 = rotate(p3);
                p4 = rotate(p4);
                
                setNormal(p1);
                glVertex3fv(p1.toArray());
                
                setNormal(p2);
                glVertex3fv(p2.toArray());
                
                setNormal(p3);
                glVertex3fv(p3.toArray());
                
                setNormal(p4);
                glVertex3fv(p4.toArray());
        }
        
        glEnd();
    }
    glPopMatrix();
}

Vector GLTorus::calculateSurfaceNormal(Point p1, Point p2, Point p3)
{
    // Use surface normals
    Vector u = Vector(p1, p2);          
    Vector v = Vector(p2, p3);

    Vector n = u * v;
    return n.normalize();
}

void GLTorus::setNormal(Point p)
{
    Vector v = (Vector)p;
    glNormal3fv(v.normalize().toArray());
}

void GLTorus::light()
{
    // 0 is alternating colour mode
    if (colourMode != 0)
    { 
        glEnable(GL_LIGHTING);
        
        if (colourMode == 1)
        {
            glShadeModel(GL_FLAT);
        }
        else if (colourMode == 2)
        {
            glShadeModel(GL_SMOOTH);
        }
        
        glEnable(GL_LIGHT0);
        
        static const GLfloat black[4] = { 0.0, 0.0, 0.0, 1.0 };
        static const GLfloat white[4] = { 1.0, 1.0, 1.0, 1.0 };
        static const GLfloat grey[4] = { 0.3, 0.3, 0.3, 1.0 };
        static const float lightPosition[] = { -100, 100, 0, 1 };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
        glLightfv(GL_LIGHT0, GL_SPECULAR, black);
    }
    else
    {
        // Disable in case lighting was already enabled
        glDisable(GL_LIGHTING);
    }
}


void GLTorus::texture()
{
}

std::vector<float> GLTorus::getTextureCoords(Point p)
{
    return std::vector<float>();
}

GLTorus::~GLTorus()
{
}
