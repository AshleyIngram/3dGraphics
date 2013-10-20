#include <QGLWidget>
#include <math.h>
#include "GLCube.h"
#include <iostream>
#include <vector>

GLCube::GLCube() 
{
     float verticesArray[][3] = 
        {
            { -0.5, -0.5, -0.5 }, { -0.5, -0.5, 0.5 }, 
            { -0.5, 0.5, -0.5 },  { -0.5, 0.5, 0.5 }, 
            { 0.5, -0.5, -0.5 }, { 0.5, -0.5, 0.5 },
            { 0.5, 0.5, -0.5 }, { 0.5, 0.5, 0.5 }
        };
        
     int edgesArray[][2] = 
        {
            { 0, 1 }, { 1, 3 }, { 3, 2 }, { 2, 0 },
            { 0, 4 }, { 1, 5 }, { 3, 7 }, { 2, 6 },
            { 4, 6 }, { 6, 7 }, { 7, 5 }, { 5, 4 }
        };
        
     int trianglesArray[] = 
     {
         0, 1, 3, 
         0, 3, 2, 
         
         0, 1, 4, 
         1, 4, 5, 
         
         0, 2, 4,
         2, 6, 4,
         
         5, 4, 6,
         5, 6, 7,
         
         2, 3, 7,
         2, 7, 6,
         
         1, 5, 7,
         1, 7, 3 
     };
          
     std::vector<std::vector<float> > vertices(8);
     for (int i = 0; i < 8; i++)
     {
        vertices[i].assign(verticesArray[i], verticesArray[i]+3);
     }
     
     std::vector<std::vector<int> > edges(12);
     for (int i = 0; i < 12; i++)
     {
        edges[i].assign(edgesArray[i], edgesArray[i]+2);
     }
     
     std::vector<int> triangles(trianglesArray, trianglesArray + 36);
     
     this->edges = edges;
     this->vertices = vertices;
     this->triangles = triangles;
}
