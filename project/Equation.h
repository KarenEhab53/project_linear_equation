#ifndef EQUATION_H
#define EQUATION_H

#include <map>
#include <string>

class Equation {
private:
    std::map<std::string, float> terms;
    float constant;

public:
    Equation();

    void setCoefficient(const std::string& var, float value);
    float getCoefficient(const std::string& var) const;

    void setConstant(float c);
    float getConstant() const;

    std::map<std::string, float> getAll() const;

    void print() const;

    Equation add(const Equation& other) const;
    Equation subtract(const Equation& other) const;
    Equation substitute(const std::string& var, const Equation& other) const;
};

#endif