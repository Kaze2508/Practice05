#pragma once
#include <iostream>

class MONEY
{
private:
    int dollars;
    int cents;
public:
    MONEY();
    MONEY(int d, int c);
    ~MONEY();
    int getDollars();
    int getCents();
    void setDollars(int d);
    void setCents(int c);
    friend std::istream& operator>>(std::istream& in, MONEY& m);
    friend std::ostream& operator<<(std::ostream& out, const MONEY& m);
    long convertToVND(double rate);
    MONEY& operator++();
    MONEY operator++(int);
};