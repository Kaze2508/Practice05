#include "OneArray.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

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

bool OneArray::prime(int x)
{
	if (x < 2)
	{
		return false;
	}
	else
	{
		for (int i = 2; i <= sqrt((float)x); i++)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void OneArray::listPrime() 
{
	std::cout << "The prime numbers in the array are: ";
	for (int i = 0; i < n; i++) {
		if (prime(a[i])) 
		{
			std::cout << a[i] << " ";
		}
	}
}

bool OneArray::SquareCheck(int x) 
{
	int y = sqrt(x);
	return y * y == x;
}

int OneArray::CountSquare() 
{
	int count = 0;
	for (int i = 0; i < n; i++) 
	{
		if (SquareCheck(a[i])) 
		{
			count++;
		}
	}
	return count;
}

bool OneArray::PerfectCheck(int x) 
{
	int sum = 0;
	for (int i = 1; i < x; i++) 
	{
		if (x % i == 0) 
		{
			sum += i;
		}
	}
	return sum == x;
}

int OneArray::SumPerfect() 
{
	int sum = 0;
	for (int i = 0; i < n; i++) 
	{
		if (PerfectCheck(a[i])) 
		{
			sum += a[i];
		}
	}
	return sum;
}

int OneArray::Inverse(int x) 
{
	int y = 0; 
	while (x > 0) 
	{
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

bool OneArray::Symme(int x) 
{
	return Inverse(x) == x;
}
 
double OneArray::MediumSymme() 
{
	double sum = 0.0;
	int count = 0;
	for (int i = 0; i < n; i++) 
	{
		if (Symme(a[i])) 
		{
			sum += a[i];
			count++;
		}
	}
	if (count > 0) 
	{
		return sum / count;
	}
	else 
	{
		return -1.0;
	}
}

bool OneArray::OddCheck() 
{
	for (int i = 0; i < n; i++) 
	{
		if (a[i] % 2 == 0) 
		{
			return false; 
		}
	}
	return true;
}

int OneArray::SmallestEven() 
{
	int min = INT_MAX;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] % 2 == 0 && a[i] < min) 
		{
			min = a[i];
		}
	}
	return min;
}

void OneArray::sortAsc() 
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (a[i] > a[j]) 
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void OneArray::sortDesc() 
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (a[i] < a[j]) 
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void OneArray::deleteAt(int pos) 
{
	if (pos < 0 || pos >= n) 
	{
		std::cout << "Invalid position" << std::endl;
		return;
	}
	for (int i = pos; i < n - 1; i++) 
	{
		a[i] = a[i + 1];
	}
	n--;
}

void OneArray::insertAt(int pos, int val) 
{
	if (pos < 0 || pos > n) 
	{
		std::cout << "Invalid position" << std::endl;
		return;
	}
	n++;
	int* newArr = new int[n];
	for (int i = 0; i < pos; i++) 
	{
		newArr[i] = a[i];
	}
	newArr[pos] = val;
	for (int i = pos + 1; i < n; i++) 
	{
		newArr[i] = a[i - 1];
	}
	delete[] a;
	a = newArr;
}

int OneArray::search(int val) 
{
	for (int i = 0; i < n; i++) 
	{
		if (a[i] == val) 
		{
			return i;
		}
	}
	return -1;
}

void OneArray::generate() 
{
	srand(time(0));
	for (int i = 0; i < n; i++) 
	{
		a[i] = rand() % 100;
	}
}

void OneArray::writeToFile(std::string filename) 
{
	std::ofstream fout(filename);
	if (fout.is_open()) 
	{
		fout << n << std::endl;
		for (int i = 0; i < n; i++) 
		{
			fout << a[i] << " ";
		}
		fout << std::endl;
		fout.close();
	}
	else 
	{
		std::cout << "Cannot open file " << filename << std::endl;
	}
}

void OneArray::readFromFile(std::string filename) 
{
	std::ifstream fin(filename);
	if (fin.is_open()) 
	{
		int newSize;
		fin >> newSize;
		delete[] a;
		n = newSize;
		a = new int[n];
		for (int i = 0; i < n; i++) 
		{
			fin >> a[i];
		}
		fin.close();
	}
	else 
	{
		std::cout << "Cannot open file " << filename << std::endl;
	}
}