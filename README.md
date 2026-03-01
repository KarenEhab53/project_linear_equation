Linear Equation Solver (C++ OOP)
Description

This project solves systems of linear equations using Object-Oriented Programming in C++.
It supports equation operations, determinant calculation, and solving using Cramer's Rule.

Features

Parse and normalize equations
Add, subtract, and substitute equations
Print coefficient matrix
Compute determinant
Solve system using Cramer’s Rule
Command-based interface

Input Format:
First line: number of equations
Next lines: equations
Enter commands until quit

Test Cases
Test 1 – Basic 3×3 System
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3=13
solve
expected :
x1=3
x2=2
x3=1

Test 2 – Number of Variables
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3+x4=13
num_vars
Expected Output
4

Test 3 – Print Equation
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3=13
equation 2
Expected Output
1x1+2x2+1x3=8

Test 4 – Column of Variable
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3=13
column x2
Expected Output
3
2
1

Test 5 – Add Equations
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3=13
add 1 3
Expected Output
5x1+4x2+6x3=29

Test 6 – Subtract Equations
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3=13
subtract 3 1
Expected Output
1x1-2x2-2x3=-3

Test 7 – Coefficient Matrix
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3=13
D
Expected Output
2 3 4
1 2 1
3 1 2

Test 8 – Cramer Matrix for Variable
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3=13
D x2
Expected Output
2 16 4
1 8 1
3 13 2

Test 9 – Determinant Value
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3=13
D_value
Expected Output
-11

Authors:
Karen Ehab 
Semon Benyamiean 
Afaf Tawfiq
