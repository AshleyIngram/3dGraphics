#include <vector>
#include "GLIcosa.h"

GLIcosa::GLIcosa()
{
    float vertexArray[][3] = 
    {
        { -0.5, 0.0, 0.809 },
        { 0.5, 0.0, 0.809 },
        { 0.0, 0.809, 0.5 },
        { 0.809, 0.5, 0.0 },
        { 0.0, 0.809, -0.5 },
        { -0.809, 0.5, 0.0 },
        { 0.0, -0.809, 0.5 },
        { 0.809, -0.5, 0.0 },
        { 0.5, 0.0, -0.809 },
        { -0.5, 0.0, -0.809 },
        { -0.809, -0.5, 0.0 },
        { 0.0, -0.809, -0.5 }
    };
    
    int edgesArray[][2] =
    {
        { 0, 1 }, { 1, 2 }, { 0, 2 },
        { 1, 3 }, { 2, 3 }, { 3, 4 },
        { 2, 4 }, { 4, 5 }, { 2, 5 },
        { 0, 5 }, { 0, 6 }, { 1, 6 },
        { 1, 7 }, { 3, 7 }, { 3, 8 },
        { 4, 8 }, { 4, 9 }, { 5, 9 }, 
        { 5, 10 }, { 0, 10 }, { 6, 7 },
        { 7, 8 }, { 8, 9 }, { 9, 10 }, 
        { 6, 10 }, { 6, 11 }, { 7, 11 },
        { 8, 11 }, { 9, 11 }, { 10, 11 }
    };
    
    int trianglesArray[] = 
    {
        0, 1, 2,
        1, 3, 2,
        3, 4, 2,
        4, 5, 2,
        5, 0, 2,
        1, 0, 6,
        3, 1, 7,
        4, 3, 8,
        5, 4, 9,
        0, 5, 10,
        6, 7, 1,
        7, 8, 3,
        8, 9, 4,
        9, 10, 5,
        10, 6, 0,
        7, 6, 11,
        8, 7, 11,
        9, 8, 11,
        10, 9, 11,
        6, 10, 11
    };
    
    std::vector<std::vector<float> > vertices(12);
    for (int i = 0; i < 12; i++)
    {
       vertices[i].assign(vertexArray[i], vertexArray[i]+3);
    }
     
    std::vector<std::vector<int> > edges(30);
    for (int i = 0; i < 30; i++)
    {
       edges[i].assign(edgesArray[i], edgesArray[i]+2);
    }
    
    std::vector<int> triangles(trianglesArray, trianglesArray + 60);
     
    this->edges = edges;
    this->vertices = vertices;
    this->triangles = triangles;
}
