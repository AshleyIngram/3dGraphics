#include "GLPolygon.h"
#include "Matrix.h"
#include <iostream>

void GLPolygon::render()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    // Set initial colour. We can reset it later if need be
    glColor3f(1.0, 0.0, 0.0);
    
    if (this->mode == GL_LINES) 
    {
        renderLines();
    }
    else if (this->mode == GL_POINTS)
    {
        renderPoints();
    }
    else
    {   
        // Assume triangles
        renderTriangles();
    }
    
    glPopMatrix();
}

void GLPolygon::renderLines()
{
    glBegin(GL_LINES);
        for (int edge = 0; edge < edges.size(); edge++)
        {
            Point point1 = Point(&this->vertices[this->edges[edge][0]][0]);
            Point point2 = Point(&this->vertices[this->edges[edge][1]][0]);
            
            // rotate points
            point1 = rotate(point1);
            point2 = rotate(point2);
            
            glVertex3fv(point1.toArray());
            glVertex3fv(point2.toArray());
        }
    glEnd();
}

void GLPolygon::renderPoints()
{
    glBegin(GL_POINTS);
        for (int vertex = 0; vertex < vertices.size(); vertex++)
        {
            Point point = Point(&this->vertices[vertex][0]);
            point = rotate(point);
            
            glVertex3fv(point.toArray());
        }
    glEnd();
}

void GLPolygon::renderTriangles()
{
    glBegin(this->mode);
        for (int i = 0; i < triangles.size(); i++)
        {   
            if (this->colourMode == 0)
            {
                interpolateColour(i, triangles.size());
            }
            else
            {
                glColor3f(255, 0, 0);
            }
            
            Point point = Point(&this->vertices[this->triangles[i]][0]);
            point = rotate(point);
            
            glVertex3fv(point.toArray());             
        }
    glEnd();
}

// interpolate the colour based on the position in the array
void GLPolygon::interpolateColour(int i, int length)
{
    int triangle = (i / 3) + 1;
    int numTriangles = length / 3;
    
    int value = (255 / numTriangles) * triangle;
    // Divide through to get the float
    float glValue = (float)value/255;
    
    glColor3f(glValue, 0, 0);
}

Vector GLPolygon::calculateSurfaceNormal(Point p1, Point p2, Point p3)
{
    // Use surface normals
    Vector u = Vector(p1, p2);          
    Vector v = Vector(p2, p3);

    Vector n = u * v;
    return n.normalize();
}

void GLPolygon::light()
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

Point GLPolygon::rotate(Point p)
{
    Point point = Matrix::getZRotationMatrix(this->zRotate) * &p;
    point = Matrix::getXRotationMatrix(this->xRotate) * &point;    
    point = Matrix::getYRotationMatrix(this->yRotate) * &point;
    return point;
}
