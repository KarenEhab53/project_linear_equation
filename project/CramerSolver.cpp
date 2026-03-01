#include "CramerSolver.h"
#include "MatrixSolver.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

CramerSolver::CramerSolver(const LinearSystem& sys) : system(sys) {}

void CramerSolver::printMatrix() const {
    const auto& eqs = system.getEquations();
    const auto& vars = system.getVariables();
    for (auto& eq : eqs) {
        for (auto& v : vars)
            cout << eq.getCoefficient(v) << " ";
        cout << endl;
    }
}

void CramerSolver::printMatrixOfVariable(const string& var) const {
    const auto& eqs = system.getEquations();
    const auto& vars = system.getVariables();

    int idx = -1;
    for (int i = 0; i < vars.size(); i++)
        if (vars[i] == var) idx = i;
    if (idx == -1) return;

    for (auto& eq : eqs) {
        for (int j = 0; j < vars.size(); j++) {
            if (j == idx) cout << eq.getConstant() << " ";
            else cout << eq.getCoefficient(vars[j]) << " ";
        }
        cout << endl;
    }
}

void CramerSolver::printDeterminant() const {
    const auto& eqs = system.getEquations();
    const auto& vars = system.getVariables();
    int n = vars.size();

    vector<vector<float>> mat(n, vector<float>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = eqs[i].getCoefficient(vars[j]);

    cout << Matrix::determinant(mat) << endl;
}

void CramerSolver::solve() const {
    const auto& eqs = system.getEquations();
    const auto& vars = system.getVariables();
    int n = vars.size();

    vector<vector<float>> mat(n, vector<float>(n));
    vector<float> constants(n);
    for (int i = 0; i < n; i++) {
        constants[i] = eqs[i].getConstant();
        for (int j = 0; j < n; j++)
            mat[i][j] = eqs[i].getCoefficient(vars[j]);
    }

    float D = Matrix::determinant(mat);
    if (fabs(D) < 1e-6) {
        cout << "No Solution" << endl;
        return;
    }

    for (int j = 0; j < n; j++) {
        vector<vector<float>> temp = mat;
        for (int i = 0; i < n; i++)
            temp[i][j] = constants[i];
        float Dj = Matrix::determinant(temp);
        cout << vars[j] << "=" << Dj / D << endl;
    }
}