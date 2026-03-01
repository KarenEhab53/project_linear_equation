#include "MatrixSolver.h"
#include <vector>
#include <cmath>
using namespace std;

float Matrix::determinant(const vector<vector<float>>& mat) {
    int n = mat.size();
    if (n == 1) return mat[0][0];
    if (n == 2) return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    float det = 0;
    for (int p = 0; p < n; p++) {
        vector<vector<float>> subMat(n - 1, vector<float>(n - 1));
        for (int i = 1; i < n; i++) {
            int colIndex = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                subMat[i - 1][colIndex] = mat[i][j];
                colIndex++;
            }
        }
        det += mat[0][p] * pow(-1, p) * determinant(subMat);
    }
    return det;
}