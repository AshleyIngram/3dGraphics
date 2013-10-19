#include <math.h>
#include "Matrix.h"

Matrix::Matrix(float input[4][4])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            this->_matrix[i][j] = input[i][j];
        }
    }
}

Point Matrix::operator*(Point* input)
{
    float coords[3] = {0, 0, 0};

    for (int i = 0; i < 3; ++i)
    {
        float val = this->_matrix[i][0] * input->x + this->_matrix[i][1] * input->y + this->_matrix[i][2] * input->z;
        
        coords[i] = val; 
    }

    return Point(coords);
}

Matrix Matrix::getXRotationMatrix(int degrees)
{
    float radians = (float)degrees * (M_PI / 180);
    
    float values[4][4] = 
    {
        { 1.0, 0.0, 0.0, 0.0 },
        { 0.0, cos(radians), sin(radians), 0.0 },
        { 0.0, -sin(radians), cos(radians), 0.0 },
        { 0.0, 0.0, 0.0, 1.0 }
    };
    
    return Matrix(values);
}

Matrix Matrix::getYRotationMatrix(int degrees)
{
    float radians = (float)degrees * (M_PI / 180);
    
    float values[4][4] = 
    {
        { cos(radians), 0.0, -sin(radians), 0.0 },
        { 0.0, 1.0, 0.0, 0.0 },
        { sin(radians), 0.0, cos(radians), 0.0 },
        { 0.0, 0.0, 0.0, 1.0 }
    };
    
    return Matrix(values);
}

Matrix Matrix::getZRotationMatrix(int degrees)
{
    float radians = (float)degrees * (M_PI / 180);
    
    float values[4][4] = 
    {
        { cos(radians), sin(radians), 0.0, 0.0 },
        { -sin(radians), cos(radians), 0.0, 0.0 },
        { 0.0, 0.0, 1.0, 0.0 },
        { 0.0, 0.0, 0.0, 1.0 }
    };
    
    return Matrix(values);
}
