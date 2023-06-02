#pragma once
#include <iostream>

class SquareMatrix 
{
private:
    int n;
    int** p;
public:
    SquareMatrix();
    SquareMatrix(int n);
    SquareMatrix(const SquareMatrix& mt);
    ~SquareMatrix();
    void input();
    void output();
    void list_odd();
    void count3();
    bool negative_check();
    bool even_find(int& x);
    void sort();
};