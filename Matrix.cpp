#include "Matrix.h"
#include <iostream>

Matrix::Matrix() 
{
    sd = 0;
    sc = 0;
    p = nullptr;
}
Matrix(int d, int c) {
    sd = d;
    sc = c;
    p = new int* [sd];
    for (int i = 0; i < sd; i++) {
        p[i] = new int[sc];
    }
}
Matrix(const Matrix& mt) {
    sd = mt.sd;
    sc = mt.sc;
    p = new int* [sd];
    for (int i = 0; i < sd; i++) {
        p[i] = new int[sc];
        for (int j = 0; j < sc; j++) {
            p[i][j] = mt.p[i][j];
        }
    }
}
~Matrix() {
    for (int i = 0; i < sd; i++) {
        delete[] p[i];
    }
    delete[] p;
}
void nhap() {
    cout << "Nhap so dong: ";
    cin >> sd;
    cout << "Nhap so cot: ";
    cin >> sc;
    p = new int* [sd];
    for (int i = 0; i < sd; i++) {
        p[i] = new int[sc];
        for (int j = 0; j < sc; j++) {
            cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            cin >> p[i][j];
        }
    }
}
void xuat() {
    for (int i = 0; i < sd; i++) {
        for (int j = 0; j < sc; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void lietKeSoNguyenTo() {
    cout << "Cac so nguyen to trong ma tran: ";
    for (int i = 0; i < sd; i++) {
        for (int j = 0; j < sc; j++) {
            if (laSoNguyenTo(p[i][j])) cout << p[i][j] << " ";
        }
    }
    cout << endl;
}
bool laSoChinhPhuong(int n) {
    int x = sqrt(n);
    return x * x == n;
}
int demSoChinhPhuong() {
    int dem = 0;
    for (int i = 0; i < sd; i++) {
        for (int j = 0; j < sc; j++) {
            if (laSoChinhPhuong(p[i][j])) dem++;
        }
    }
    return dem;
}