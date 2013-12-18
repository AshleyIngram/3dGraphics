#ifndef _MATRIX_H
#define _MATRIX_H 1

#include "Point.h"
#include "Vector.h"
#include <vector>

class Matrix
{
    public:
        Matrix(float input[4][4]);
        
        Point operator*(Point* input);
        Matrix operator*(Matrix input);

        std::vector<std::vector<float> > getFloats();

        static Matrix getZRotationMatrix(int degrees);
        static Matrix getXRotationMatrix(int degrees);
        static Matrix getYRotationMatrix(int degrees);

        static Matrix ones();
        static Matrix zeroes();

        static Matrix getOrtho(float left, 
        					   float right,
        					   float bottom, 
        					   float top, 
        					   float zNear, 
        					   float zFar);

        static Matrix getLookAt(Vector eye, Vector centre, Vector up);

    private:
        float _matrix[4][4];
};
#endif
