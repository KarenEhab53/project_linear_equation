#include "Parser.h"
#include "LinnearSystem.h"
#include "CramerSolver.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    LinearSystem system;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        system.addEquation(Parser::parse(line));
    }

    CramerSolver cramer(system);
    string cmd;

    while (cin >> cmd) {
        if (cmd == "quit") break;

        else if (cmd == "num_vars") cout << system.numVariables() << endl;
        else if (cmd == "equation") { int i; cin >> i; system.printEquation(i); }
        else if (cmd == "column") { string var; cin >> var; system.printColumn(var); }
        else if (cmd == "add") { int i, j; cin >> i >> j; system.add(i, j).print(); }
        else if (cmd == "subtract") { int i, j; cin >> i >> j; system.subtract(i, j).print(); }
        else if (cmd == "substitute") { string var; int i, j; cin >> var >> i >> j; system.substitute(var, i, j).print(); }
        else if (cmd == "D") { string var; if (cin.peek() != '\n') cin >> var; if (var.empty()) cramer.printMatrix(); else cramer.printMatrixOfVariable(var); }
        else if (cmd == "D_value") cramer.printDeterminant();
        else if (cmd == "solve") cramer.solve();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}