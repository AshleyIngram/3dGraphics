#include <string>
#include <vector>

// TODO: Use a template
class Matrix
{
    public:
        // Matrix(std::string filepath);
        Matrix(unsigned rows, unsigned cols);
        Matrix(double** input, unsigned rowsize, unsigned colsize);
        Matrix(vector<vector<double>> input);

        Matrix operator *(Matrix* b);
        std::string toString();
        double** toArray();
        
    private:
        std::vector<std::vector<double>> matrix;
};