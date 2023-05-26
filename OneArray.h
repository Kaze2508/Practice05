#pragma once
#ifndef _OneArray
#define _OneArray
#include <iostream>

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
	void copy(const OneArray&);
	OneArray(const OneArray&);
	int GetCount();
	int* GetA();
	friend std::istream& operator>>(std::istream&, OneArray&);
	friend std::ostream& operator<<(std::ostream&, const OneArray&);
	OneArray& operator=(const OneArray&);
};
#endif