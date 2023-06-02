#pragma once
#include <iostream>

class Matrix 
{
private:
    int row, column;
    int** p;
public:
    Matrix();
    Matrix(int row, int column);
    Matrix(const Matrix& mt);
    ~Matrix();
    void input();
    void output();
    bool prime(int n);
    void listPrime();
    bool perfet(int n);
    int count_perfet();
    int sumPerfect(int k);
    bool Sym(int n);
    double mediumSym(int k);
    void sortK(int k);
};