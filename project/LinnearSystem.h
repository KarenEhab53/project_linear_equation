#ifndef LINEARSYSTEM_H
#define LINEARSYSTEM_H

#include "Equation.h"
#include <vector>
#include <string>

class LinearSystem {
private:
    std::vector<Equation> equations;

public:
    void addEquation(const Equation& eq);

    int numVariables() const;

    void printEquation(int i) const;
    void printColumn(const std::string& var) const;

    Equation add(int i, int j) const;
    Equation subtract(int i, int j) const;
    Equation substitute(const std::string& var, int i, int j) const;

    std::vector<Equation> getEquations() const;
    std::vector<std::string> getVariables() const;
};

#endif