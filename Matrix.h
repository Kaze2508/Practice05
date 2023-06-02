#pragma once
#include <iostream>

class Matrix 
{
private:
    int row, column;
    int** p;
public:
    Matrix();
    Matrix(int d, int c);
    Matrix(const Matrix& mt);
    ~Matrix();
    void input();
    void output();
    bool prime(int n);
    void listPrime();
    bool perfet(int n);
    int count_perfet();
};