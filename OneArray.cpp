#include "OneArray.h"

OneArray::~OneArray()
{
	n = 0;
	delete[]a;
	a = NULL;
	std::cout << "Cleared one array\n";
}

OneArray::OneArray()
{
	n = 0;
	a = NULL;
}

OneArray::OneArray(int n)
{
	while (n <= 0)
	{
		std::cout << "Re-input n > 0: ";
		std::cin >> n;
	}
	this->n = n;
	a = new int[this->n];
	for (int i = 0; i < this->n; i++)
		a[i] = 0;
}

OneArray::OneArray(int n, int m)
{
	if (n == 0)
	{
		this->a = 0;
		a = NULL;
	}
	else
	{
		while (n <= 0)
		{
			std::cout << "Re-input n>0: ";
			std::cin >> n;
		}
		this->n = n;
		a = new int[this->n];
		for (int i = 0; i < this->n; i++)
			a[i] = m;
	}
}

OneArray::OneArray(const OneArray& m)
{
	n = m.n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = m.a[i];
}

int OneArray::GetCount()
{
	return n;
}

int* OneArray::GetA()
{
	return a;
}

std::istream& operator>>(std::istream& is, OneArray& m)
{
	if (m.a != NULL)
		m.~OneArray();
	do
	{
		std::cout << "Input n>0: ";
		is >> m.n;
	} while (m.n <= 0);
	m.a = new int[m.n];
	for (int i = 0; i < m.n; i++)
	{
		std::cout << "a[" << i << "] = ";
		is >> m.a[i];
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const OneArray& m)
{
	if (m.a == NULL)
		os << "Empty";
	else
		for (int i = 0; i < m.n; i++)
			os << m.a[i] << "\t";
	return os;
}

OneArray& OneArray::operator=(const OneArray& m)
{
	n = m.n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = m.a[i];
	return *this;
}