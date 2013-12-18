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

Matrix Matrix::operator*(Matrix input)
{
    float result[4][4] =
    {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    };

    std::vector<std::vector<float> > input_f = input.getFloats();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            float sum = 0.0;

            for (int k = 0; k < 4; k++)
            {
                sum = sum + _matrix[i][k] * input_f[k][j];
            }

            result[i][j] = sum;
        }
    }

    return Matrix(result);
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

Matrix Matrix::getOrtho(float left, float right, float bottom, float top, float zNear, float zFar)
{
    float values[4][4] =
    {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 1.0 }
    };

    values[0][0] = (float)2 / (right - left);
    values[1][1] = (float)2 / (top - bottom);
    values[2][2] = (float)-2 / (zFar - zNear);
    values[0][3] = (float)-((right + left) / (right - left));
    values[1][3] = (float)-((top + bottom) / (top - bottom));
    values[2][3] = (float)-((zFar + zNear) / (zFar - zNear));

    return Matrix(values);
}

Matrix Matrix::getLookAt(Vector eye, Vector centre, Vector up)
{
    Vector f = (centre - eye).normalize();
    Vector s = (f * up).normalize();
    Vector u = (s * f).normalize();

    float values[4][4] = 
    {
        { s.x, s.y, s.z, 0 },
        { u.x, u.y, u.z, 0 },
        { -f.x, -f.y, -f.z, 0 },
        { 0, 0, 0, 1 }
    };

    return Matrix(values);
}

Matrix Matrix::zeroes()
{
    float values[4][4] = 
    {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    };

    return Matrix(values);
}

Matrix Matrix::ones()
{
    float values[4][4] =
    {
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 }
    };

    return Matrix(values);
}

std::vector<std::vector<float> > Matrix::getFloats()
{
    std::vector<std::vector<float> > values = std::vector<std::vector<float> >();
    values.resize(4);
    
    for (int i = 0; i < 4; i++)
    {
        values[i].resize(4);

        for (int j = 0; j < 4; j++)
        {
            values[i][j] = _matrix[i][j];
        }
    }

    return values;
}