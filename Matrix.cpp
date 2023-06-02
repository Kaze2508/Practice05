#include "Matrix.h"
#include <iostream>

Matrix::Matrix() 
{
    row = 0;
    column = 0;
    p = nullptr;
}

Matrix::Matrix(int row, int column)
{
    row = row;
    column = column;
    p = new int* [row];
    for (int i = 0; i < row; i++) 
    {
        p[i] = new int[column];
    }
}

Matrix::Matrix(const Matrix& mt) 
{
    row = mt.row;
    column = mt.column;
    p = new int* [row];
    for (int i = 0; i < row; i++) 
    {
        p[i] = new int[column];
        for (int j = 0; j < column; j++) 
        {
            p[i][j] = mt.p[i][j];
        }
    }
}

Matrix::~Matrix() 
{
    for (int i = 0; i < row; i++) 
    {
        delete[] p[i];
    }
    delete[] p;
}

void Matrix::input() 
{
    std::cout << "Input row: ";
    std::cin >> row;
    std::cout << "Input column: ";
    std::cin >> column;
    p = new int* [row];
    for (int i = 0; i < row; i++) 
    {
        p[i] = new int[column];
        for (int j = 0; j < column; j++) 
        {
            std::cout << "Input element [" << i << "][" << j << "]: ";
            std::cin >> p[i][j];
        }
    }
}

void Matrix::output() 
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            std::cout << p[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Matrix::prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= sqrt((float)n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void Matrix::listPrime() 
{
    std::cout << "Primes: ";
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            if (prime(p[i][j])) std::cout << p[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

bool Matrix::perfet(int n) 
{
    int x = sqrt(n);
    return x * x == n;
}

int Matrix::count_perfet() 
{
    int count = 0;
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            if (perfet(p[i][j])) count++;
        }
    }
    return count;
}

int Matrix::sumPerfect(int k) 
{
    int sum = 0;
    for (int j = 0; j < column; j++) 
    {
        if (perfet(p[k][j])) sum += p[k][j];
    }
    return sum;
}

bool Matrix::Sym(int n) 
{
    int m = n;
    int inverse = 0;
    while (m > 0) {
        inverse = inverse * 10 + m % 10;
        m /= 10;
    }
    return inverse == n;
}

double Matrix::mediumSym(int k) 
{
    double sum = 0;
    int count = 0;
    for (int i = 0; i < row; i++) 
    {
        if (Sym(p[i][k])) 
        {
            sum += p[i][k];
            count++;
        }
    }
    return count == 0 ? 0 : sum / count;
}

void Matrix::sortK(int k) 
{
    for (int i = 0; i < column - 1; i++) 
    {
        for (int j = i + 1; j < column; j++) 
        {
            if (p[k][i] > p[k][j]) 
            {
                int temp = p[k][i];
                p[k][i] = p[k][j];
                p[k][j] = temp;
            }
        }
    }
}