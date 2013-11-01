#ifndef _MATRIX_H
#define _MATRIX_H 1

#include "Point.h"

class Matrix
{
    public:
        Matrix(float input[4][4]);
        Point operator*(Point* input);
        static Matrix getZRotationMatrix(int degrees);
        static Matrix getXRotationMatrix(int degrees);
        static Matrix getYRotationMatrix(int degrees);

    private:
        float _matrix[4][4];
};
#endif
