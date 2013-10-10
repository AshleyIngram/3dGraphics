#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(unsigned rows, unsigned cols)
{
    matrix = vector<vector<double>>();

    if (rows == 0 || cols == 0)
    {
        throw exception("Matrix cannot have 0 rows or columns");
    }

    matrix.resize(rows);

    for (int i = 0; i < rows; ++i)
    {
        vector<double> column = vector<double>();
        column.resize(cols);
        matrix[i] = column;
    }
}

Matrix::Matrix(double** input, unsigned rowsize, unsigned colsize)
{
    matrix = vector<vector<double>>();

    for (int i = 0; i < rowsize; ++i)
    {
        matrix[i] = vector<double>();

        for (int j = 0; j < colsize; j++)
        {
            matrix[i][j] = input[i][j];
        }
    }
}

Matrix::Matrix(vector<vector<double>> input)
{
    this->matrix = input;
}

double** Matrix::toArray()
{
    double** returnValue;

    for (int i = 0; i < matrix.size-1; ++i)
    {
        for (int j = 0; j < matrix[i].size-1; ++j)
        {
            returnValue[i][j] = matrix[i][j];
        }
    }

    return returnValue;
}

string Matrix::toString()
{
}

Matrix Matrix::operator*(Matrix* b)
{
}