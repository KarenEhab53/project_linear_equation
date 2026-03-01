#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
public:
    static float determinant(const std::vector<std::vector<float>>& mat);
};

#endif