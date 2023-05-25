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
	OneArray(int = 0, int = 0);
	OneArray(const OneArray&);
	int GetCount();
	int* GetA();
	friend std::istream& operator>>(std::istream&, OneArray&);
	friend std::ostream& operator<<(std::ostream&, const OneArray&);
	OneArray & operator=(const OneArray&);
};
#endif