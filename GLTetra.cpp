#include <QGLWidget>
#include <math.h>
#include "GLTetra.h"
#include <iostream>

GLTetra::GLTetra() 
{
     float verticesArray[][3] =
        {
            { 0.5, 0.5, -0.5 }, { -0.5, -0.5, -0.5 },
            { 0.5, -0.5, 0.5 }, { -0.5, 0.5, 0.5 }
        };
        
     int edgesArray[][2] = 
        {
            { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 2 }, { 1, 3 }, { 2, 3 }
        };
        
     int trianglesArray[] = 
     {
        1, 2, 3, // face 0
        3, 0, 1, // face 1
        3, 2, 0, // face 2
        1, 0, 2 // face 3
     };
     
     std::vector<std::vector<float> > vertices(4);
     for (int i = 0; i < 4; i++)
     {
        vertices[i].assign(verticesArray[i], verticesArray[i]+3);
     }
          
     std::vector<std::vector<int> > edges(6);
     for (int i = 0; i < 6; i++)
     {
        edges[i].assign(edgesArray[i], edgesArray[i]+2);
     }
     
     std::vector<int> triangles(trianglesArray, trianglesArray + 12);
     
     this->edges = edges;
     this->vertices = vertices;
     this->triangles = triangles;
}
