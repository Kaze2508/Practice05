#include "SquareMatrix.h"
#include <iostream>

SquareMatrix::SquareMatrix() : n(0), p(nullptr) {}

SquareMatrix::SquareMatrix(int n) : n(n) 
{
    p = new int* [n];
    for (int i = 0; i < n; i++)
        p[i] = new int[n];
}

SquareMatrix::SquareMatrix(const SquareMatrix& mt) : n(mt.n) 
{
    p = new int* [n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[n];
        for (int j = 0; j < n; j++)
            p[i][j] = mt.p[i][j];
    }
}

SquareMatrix::~SquareMatrix() 
{
    for (int i = 0; i < n; i++)
        delete[] p[i];
    delete[] p;
}

void SquareMatrix::input() 
{
    std::cout << "Input element: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> p[i][j];
}

void SquareMatrix::output() 
{
    std::cout << "Matrix:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
            std::cout << p[i][j] << ' ';
        std::cout << std::endl;
    }
}

void SquareMatrix::list_odd() 
{
    std::cout << "Odd elements: ";
    for (int i = 0; i < n; i++)
        if (p[i][i] % 2 == 1)
            std::cout << p[i][i] << ' ';
    std::cout << std::endl;
}

void SquareMatrix::count3() 
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (p[i][n - i - 1] % 10 == 3)
            count++;
    std::cout << "Number of elements satistfied: " << count << std::endl;
}

bool SquareMatrix::negative_check() 
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (p[i][j] < 0)
                return true;
    return false;
}

bool SquareMatrix::even_find(int& x) 
{
    for (int i = n - 1; i > 0; i--)
        for (int j = n - i - 1; j >= 0; j--)
            if (p[i][j] % 2 == 0) 
            {
                x = p[i][j];
                return true;
            }
    return false;
}

void SquareMatrix::sort() 
{
    for (int k = 0; k < n - 1; k++)
        for (int l = k + 1; l < n; l++)
            if (p[k][n - k - 1] < p[l][n - l - 1]) 
            {
                int temp = p[k][n - k - 1];
                p[k][n - k - 1] = p[l][n - l - 1];
                p[l][n - l - 1] = temp;
            }
}