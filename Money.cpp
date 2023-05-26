#include "Money.h"
#include <iostream>

MONEY::MONEY()
{
    dollars = 0;
    cents = 0;
}

MONEY::MONEY(int d, int c)
{
    dollars = d;
    cents = c;
}

MONEY::~MONEY()
{
    std::cout << "Clear money!" << std::endl;
}

int MONEY::getDollars()
{
    return dollars;
}

int MONEY::getCents()
{
    return cents;
}

void MONEY::setDollars(int d)
{
    dollars = d;
}

void MONEY::setCents(int c)
{
    cents = c;
}

std::istream& operator>>(std::istream& in, MONEY& m)
{
    in >> m.dollars >> m.cents;
    return in;
}

std::ostream& operator<<(std::ostream& out, const MONEY& m)
{
    out << m.dollars << " dollars " << m.cents << " cents";
    return out;
}

long MONEY::convertToVND(double rate)
{
    long vnd = (dollars * 100 + cents) * rate / 100;
    return vnd;
}

MONEY& MONEY::operator++()
{
    cents++;
    if (cents == 100)
    {
        cents = 0;
        dollars++;
    }
    return *this;
}

MONEY MONEY::operator++(int)
{
    MONEY temp(dollars, cents);
    cents++;
    if (cents == 100)
    {
        cents = 0;
        dollars++;
    }
    return temp;
}