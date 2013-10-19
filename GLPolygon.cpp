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
    
    /*
    glRotatef(this->xRotate, 1, 0, 0);
    glRotatef(this->yRotate, 0, 1, 0);
    glRotatef(this->zRotate, 0, 0, 1);
    */
    
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

Point GLPolygon::rotate(Point p)
{
    Point point = Matrix::getZRotationMatrix(this->zRotate) * &p;
    return point;
}
