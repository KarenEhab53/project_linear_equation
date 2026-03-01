#include "Parser.h"
#include <sstream>
#include <cstdlib>
#include <cctype>

Equation Parser::parse(const std::string& line) {
    Equation eq;
    size_t pos = line.find('=');
    std::string lhs = line.substr(0, pos);
    std::string rhs = line.substr(pos + 1);
    eq.setConstant(std::atof(rhs.c_str()));

    std::string token;
    char op = '+';
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs[i] == '+' || lhs[i] == '-') {
            op = lhs[i];
        }
        else {
            size_t j = i;
            while (j < lhs.size() && lhs[j] != '+' && lhs[j] != '-') j++;
            token = lhs.substr(i, j - i);

            float coef = 1.0f;
            std::string var;
            size_t k = 0;
            while (k < token.size() && (isdigit(token[k]) || token[k] == '.')) k++;
            if (k > 0) coef = std::atof(token.substr(0, k).c_str());
            var = token.substr(k);
            if (op == '-') coef *= -1;

            eq.setCoefficient(var, eq.getCoefficient(var) + coef);
            i = j - 1;
        }
    }

    return eq;
}