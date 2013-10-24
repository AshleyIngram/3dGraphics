#include <math.h>
#include "GLTorus.h"
#include <iostream>

GLTorus::GLTorus()
{
    this->textureImg = NULL;
}

void GLTorus::render()
{
    glColor3f(1.0, 0.0, 0.0);

    int numSides = 10;
    int numRings = 10;
    const float PI2 = M_PI * 2;
    
    glBegin(GL_QUADS);
    for (int i = 0; i < numSides; i++)
    {
        for (int j = 1; j <= numRings; j++)
        {
            for (int k = 1; k >= 0; k--)
            {
                double s = (i + k) % numc + 0.5;
                double t = j % numt;
                
                double s2 = (i + k) % numc + 0.5;
                double t2 = j-1 % numt;
                
                // 1 = size of shape (basically)
                // 0.3 * cos... = width of outer circle (therefore size of hole)
                double x = (1 + 0.3 * cos(s * PI2 / numc)) * cos(t * PI2 / numt) * 0.5;
                double y = (1 + 0.3 * cos(s * PI2 / numc)) * sin(t * PI2 / numt) * 0.5;
                double z = 0.1 * sin(s * PI2 / numc) * 0.5;
                
                double x2 = (1 + 0.3 * cos(s2 * PI2 / numc)) * cos(t2 * PI2 / numt) * 0.5;
                double y2 = (1 + 0.3 * cos(s2 * PI2 / numc)) * sin(t2 * PI2 / numt) * 0.5;
                double z2 = 0.1 * sin(s2 * PI2 / numc) * 0.5;
                
                
                Point p = Point(x, y, z);
                p = rotate(p);
                
                Point p2 = Point(x2, y2, z2);
                p2 = rotate(p2);
                
                glVertex3fv(p2.toArray());
                glVertex3fv(p.toArray());
            }
        }     
        glEnd();
    }
}

Vector GLTorus::calculateSurfaceNormal(Point p1, Point p2, Point p3)
{
    return Vector();
}

void GLTorus::setNormal(Point p)
{
}

void GLTorus::light()
{
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
