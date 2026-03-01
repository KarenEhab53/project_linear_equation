#ifndef CRAMERSOLVER_H
#define CRAMERSOLVER_H

#include "LinnearSystem.h"
#include <string>

class CramerSolver {
private:
    const LinearSystem& system;
public:
    CramerSolver(const LinearSystem& sys);
    void printMatrix() const;
    void printMatrixOfVariable(const std::string& var) const;
    void printDeterminant() const;
    void solve() const;
};

#endif