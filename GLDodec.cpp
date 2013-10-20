#include <vector>
#include "GLDodec.h"

GLDodec::GLDodec()
{
    float vertexArray[][3] = 
    {
        { -0.309, 0.809, 0.0 }, 
        { -0.5, 0.5, 0.5 },
        { 0.0, 0.309, 0.809 },
        { 0.5, 0.5, 0.5 },
        { 0.309, 0.809, 0.0 },
        { 0.809, 0.0, 0.309 },
        { 0.809, 0.0, -0.309 },
        { 0.5, 0.5, -0.5 },
        { 0.0, -0.309, 0.809 },
        { 0.5, -0.5, 0.5 },
        { -0.809, 0.0, 0.309 },
        { -0.5, -0.5, 0.5 },
        { -0.5, 0.5, -0.5 },
        { -0.809, 0.0, -0.309 },
        { 0.0, 0.309, -0.809 },
        { 0.309, -0.809, 0.0 },
        { -0.309, -0.809, 0.0 },
        { -0.5, -0.5, -0.5 },
        { 0.0, -0.309, -0.809 }, 
        { 0.5, -0.5, -0.5 }
    };
    
    int edgesArray[][2] =
    {
        { 3, 4 }, { 0, 4 }, { 0, 1 },
        { 1, 2 }, { 2, 3 }, { 3, 5 },
        { 5, 6 }, { 6, 7}, { 4, 7 },
        { 2, 8 }, { 8, 9 }, { 5, 9 },
        { 10, 11 }, { 8, 11 }, { 1, 10 }, 
        { 10, 13 }, { 0, 12 }, { 12, 13 },
        { 7, 14 }, { 12, 14 }, { 11, 16 },
        { 15, 16 }, { 9, 15 }, { 15, 19 }, 
        { 6, 19 }, { 18, 19 }, { 14, 18 },
        { 13, 17 }, { 17, 18 }, { 16, 17 }
    };
    
    int trianglesArray[] = 
    {
        0, 3, 4,
        0, 1, 3,
        1, 2, 3,
        5, 4, 3,
        5, 6, 4,
        6, 7, 4,
        9, 2, 8, 
        9, 5, 2,
        5, 3, 2,
        8, 10, 11,
        8, 2, 10,
        2, 1, 10,
        1, 13, 10,
        1, 0, 13,
        0, 12, 13,
        4, 12, 0,
        4, 7, 12,
        7, 14, 12,
        16, 8, 11,
        16, 15, 8,
        15, 9, 8,
        19, 9, 15, 
        19, 6, 9,
        6, 5, 9,
        14, 19, 18,
        14, 7, 19,
        7, 6, 19,
        12, 17, 13,
        12, 14, 17, 
        14, 18, 17,
        13, 11, 10,
        13, 17, 11,
        17, 16, 11,
        15, 18, 19,
        15, 16, 18,
        16, 17, 18
    };
    
    std::vector<std::vector<float> > vertices(20);
    for (int i = 0; i < 20; i++)
    {
       vertices[i].assign(vertexArray[i], vertexArray[i]+3);
    }
     
    std::vector<std::vector<int> > edges(30);
    for (int i = 0; i < 30; i++)
    {
       edges[i].assign(edgesArray[i], edgesArray[i]+2);
    }
    
    std::vector<int> triangles(trianglesArray, trianglesArray + 108);
     
    this->edges = edges;
    this->vertices = vertices;
    this->triangles = triangles;
}
