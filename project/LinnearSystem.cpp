#include "LinnearSystem.h"
#include <iostream>
#include <set>
using namespace std;

void LinearSystem::addEquation(const Equation& eq) {
    equations.push_back(eq);
}

vector<Equation> LinearSystem::getEquations() const {
    return equations;
}

int LinearSystem::numVariables() const {
    set<string> vars;
    for (auto& eq : equations)
        for (auto& t : eq.getAll())
            vars.insert(t.first);
    return vars.size();
}

vector<string> LinearSystem::getVariables() const {
    set<string> vars;
    for (auto& eq : equations)
        for (auto& t : eq.getAll())
            vars.insert(t.first);
    return vector<string>(vars.begin(), vars.end());
}

void LinearSystem::printEquation(int i) const {
    equations[i - 1].print();
}

void LinearSystem::printColumn(const string& var) const {
    for (auto& eq : equations)
        cout << eq.getCoefficient(var) << endl;
}

Equation LinearSystem::add(int i, int j) const {
    return equations[i - 1].add(equations[j - 1]);
}

Equation LinearSystem::subtract(int i, int j) const {
    return equations[i - 1].subtract(equations[j - 1]);
}

Equation LinearSystem::substitute(const string& var, int i, int j) const {
    return equations[i - 1].substitute(var, equations[j - 1]);
}