#include "GLPolygon.h"
#include "Point.h"
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
            Point point2 = Point(&this->vertices[this->edges[edge][0]][1]);
            
            // rotate points
            point1 = Matrix::getZRotationMatrix(this->zRotate) * &point1;
            point2 = Matrix::getZRotationMatrix(this->zRotate) * &point2;
            
            std::cout << "(" << 
                point1.toArray()[0] << ", " <<
                point1.toArray()[1] << ", " <<
                point1.toArray()[2] << ")"
                << std::endl;
                
            std::cout << "(" << 
                point2.toArray()[0] << ", " <<
                point2.toArray()[1] << ", " <<
                point2.toArray()[2] << ")"
                << std::endl;
            
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
            glVertex3fv(&this->vertices[vertex][0]);
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
            
            glVertex3fv(&this->vertices[this->triangles[i]][0]);             
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
