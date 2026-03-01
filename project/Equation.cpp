#include "Equation.h"
#include <iostream>
#include <iomanip>
using namespace std;

Equation::Equation() : constant(0) {}

void Equation::setCoefficient(const string& var, float value) {
    terms[var] = value;
}

float Equation::getCoefficient(const string& var) const {
    auto it = terms.find(var);
    if (it != terms.end()) return it->second;
    return 0.0f;
}

void Equation::setConstant(float c) {
    constant = c;
}

float Equation::getConstant() const {
    return constant;
}

map<string, float> Equation::getAll() const {
    return terms;
}

void Equation::print() const {
    bool first = true;
    for (auto& [var, coef] : terms) {
        if (!first && coef >= 0) cout << "+";
        if (coef == -1) cout << "-";
        else if (!(coef == 1 && coef != -1)) cout << coef;
        cout << var;
        first = false;
    }
    cout << "=" << constant << endl;
}

Equation Equation::add(const Equation& other) const {
    Equation res = *this;
    for (auto& [var, coef] : other.terms)
        res.terms[var] += coef;
    res.constant += other.constant;
    return res;
}

Equation Equation::subtract(const Equation& other) const {
    Equation res = *this;
    for (auto& [var, coef] : other.terms)
        res.terms[var] -= coef;
    res.constant -= other.constant;
    return res;
}

Equation Equation::substitute(const string& var, const Equation& other) const {
    Equation res;
    float coef = getCoefficient(var);
    for (auto& [v, c] : terms)
        if (v != var) res.terms[v] = c;
    for (auto& [v, c] : other.terms)
        res.terms[v] += coef * c;
    res.constant = constant + coef * other.constant;
    return res;
}