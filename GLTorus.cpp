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

    double x = (1 + 0.3 * cos(s * PI2 / sides)) * cos(t * PI2 / rings) * 0.5;
    double y = (1 + 0.3 * cos(s * PI2 / sides)) * sin(t * PI2 / rings) * 0.5;
    double z = 0.1 * sin(s * PI2 / sides) * 0.5;
                
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
    int rings = 40;
    const float PI2 = M_PI * 2;
    
    for (int i = 0; i < sides; i++)
    {
        glBegin(mode);
        for (int j = 1; j <= rings; j++)
        {
            for (int k = 2; k >= 0; k--)
            {
                double s = (i + k) % sides;
                double t = (j + k) % rings;
                
                double s2 = (i + k) % sides;
                double t2 = ((j - 1) + k) % rings;
                
                Point p = calculatePoint(s, t, sides, rings);
                Point p2 = calculatePoint(s2, t2, sides, rings);
                
                p = rotate(p);
                p2 = rotate(p2);
                
                setNormal(p2);
                glVertex3fv(p2.toArray());
                
                setNormal(p);
                glVertex3fv(p.toArray());
            }
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
