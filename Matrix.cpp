#include "Matrix.h"
#include <iostream>

Matrix::Matrix() 
{
    sd = 0;
    sc = 0;
    p = nullptr;
}

Matrix::Matrix(int d, int c)
{
    sd = d;
    sc = c;
    p = new int* [sd];
    for (int i = 0; i < sd; i++) 
    {
        p[i] = new int[sc];
    }
}

Matrix::Matrix(const Matrix& mt) 
{
    sd = mt.sd;
    sc = mt.sc;
    p = new int* [sd];
    for (int i = 0; i < sd; i++) 
    {
        p[i] = new int[sc];
        for (int j = 0; j < sc; j++) 
        {
            p[i][j] = mt.p[i][j];
        }
    }
}

Matrix::~Matrix() 
{
    for (int i = 0; i < sd; i++) 
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
    int dem = 0;
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            if (perfet(p[i][j])) dem++;
        }
    }
    return dem;
}