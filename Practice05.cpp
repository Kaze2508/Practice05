#include <iostream>
#include "OneArray.h"
#include "Matrix.h"
#include "SquareMatrix.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[])
{
    OneArray *m1 = new OneArray, m2(5), m3(3, 7);
    std::cout << "Array 1: " << *m1 << "\nArray 2: " << m2 << "\nArray 3: " << m3 << std::endl;
    std::cout << "Re - input array 1: \n";
    std::cin >> *m1;
    std::cout<<m1->GetCount()<<std::endl;
    std::cout << "Array 1: " << *m1 << std::endl;

    OneArray m4(*m1), m5, m6, m7;
    m5 = m6 = *m1;
    std::cout << m3.GetCount()<<std::endl;

    std::cout << "Array 4: " << m4 << std::endl;
    std::cout << "Array 5: " << m5 << std::endl;
    std::cout << "Array 6: " << m6 << std::endl;
    std::cout << "Array 7: " << m7 << std::endl;
    delete m1;
    std::cout << "Clear array 1\n";
    std::cout << "Array 4: " << m4 << std::endl;
    std::cout << "Array 5: " << m5 << std::endl;
    std::cout << "Array 6: " << m6 << std::endl;
    std::cout << "Array 7: " << m7 << std::endl;
    return 0;
}