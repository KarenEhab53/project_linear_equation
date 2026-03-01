#ifndef PARSER_H
#define PARSER_H

#include "Equation.h"
#include <string>

class Parser {
public:
    static Equation parse(string line);
};

#endif