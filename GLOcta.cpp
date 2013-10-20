#include <vector>
#include "GLOcta.h"

GLOcta::GLOcta()
{
    float vertexArray[][3] = 
    {
        { 0.0, 0.0, 0.5 },
        { 0.5, 0.0, 0.0 },
        { 0.0, 0.0, -0.5 },
        { -0.5, 0.0, 0.0 },
        { 0.0, 0.5, 0.0 },
        { 0.0, -0.5, 0.0 }
    };
    
    int edgesArray[][2] =
    {
        { 0, 1 }, { 1, 2 }, { 2, 3 },
        { 3, 0 }, { 0, 4 }, { 1, 4 },
        { 2, 4 }, { 3, 4 }, { 0, 5 },
        { 1, 5 }, { 2, 5 }, { 3, 5 }
    };
    
    int trianglesArray[] = 
    {
        0, 1, 4, 
        1, 2, 4, 
        
        2, 3, 4, 
        3, 0, 4, 
        
        1, 0, 5,
        2, 1, 5,
        
        3, 2, 5,
        0, 3, 5
    };
    
    std::vector<std::vector<float> > vertices(6);
    for (int i = 0; i < 6; i++)
    {
       vertices[i].assign(vertexArray[i], vertexArray[i]+3);
    }
     
    std::vector<std::vector<int> > edges(12);
    for (int i = 0; i < 12; i++)
    {
       edges[i].assign(edgesArray[i], edgesArray[i]+2);
    }
    
    std::vector<int> triangles(trianglesArray, trianglesArray + 24);
     
    this->edges = edges;
    this->vertices = vertices;
    this->triangles = triangles;
}
