#pragma once
#ifndef _OneArray
#define _OneArray
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

class OneArray
{
private:
	int n;
	int* a;
public:
	~OneArray();
	OneArray();
	OneArray(int);
	OneArray(int, int);
	OneArray(const OneArray&);
	int GetCount();
	int* GetA();
	friend std::istream& operator>>(std::istream&, OneArray&);
	friend std::ostream& operator<<(std::ostream&, const OneArray&);
	OneArray& operator=(const OneArray&);
	bool prime(int);
	void listPrime();
	bool SquareCheck(int);
	int CountSquare();
	bool PerfectCheck(int);
	int SumPerfect();
	int Inverse(int);
	bool Symme(int);
	double MediumSymme();
	bool OddCheck();
	int SmallestEven();
	void sortAsc();
	void sortDesc();
	void deleteAt(int);
	void insertAt(int, int);
	int search(int);
	void generate();
	void writeToFile(std::string);
	void readFromFile(std::string);
};
#endif