#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "tabD.h"

using namespace std;

void tabD::init(int n)
{
	this->n = n;
	if (n <= 0) {
		a = nullptr; this->n = 0;
		return;
	}		
	a = new (nothrow) char[n];
	if (!a) {
		this->n = 0;
		return;
	}
}

void tabD::fill(char ch, const char* tab)
{
	for (int i = 0; i < n; i++) {
		if (tab != nullptr) a[i] = tab[i];
		else a[i] = ch;
	}
}

tabD& tabD::operator=(const tabD& t)
{
	delete[] a;
	init(t.n);

	fill(0, t.a);
	
	return *this;
}

void tabD::print()
{
	for (int i = 0; i < n; i++) cout << a[i]; 
	cout << endl;
}

bool operator==(const tabD& t1, const tabD& t2)
{
	if (t1.n != t2.n) return 0;
	else
	{
		for (int i = 0; i < t1.n;i++) {
			if (t1[i] != t2[i]) return 0;
		}
	}
	return 1;
}

bool operator!=(const tabD& t1, const tabD& t2)
{
	return !(t1 == t2);
}

tabD operator+(const tabD& t1, const tabD& t2)
{
	if (t1 == tabD()) return t2;
	if (t2 == tabD()) return t1;
	tabD t3(t1.n + t2.n);
	if (t3 == tabD()) return t3;
	for (int i = 0; i < t1.n; ++i) t3[i] = t1[i];
	for (int i = 0; i < t2.n; ++i) t3[t1.n + i] = t2[i];
	return t3;
}

tabD& tabD::operator+=(const tabD& t1)
{
	return *this = *this + t1;
}

std::ostream& operator<<(std::ostream& out, const tabD& t)
{
	out << "["; for (int i = 0; i < t.n; i++) out << t[i];
	out << "]";
	return out;
}

std::istream& operator>>(std::istream& in, tabD& t)
{
	int n;
	do
	{
		cout << "Please enter n: ";
		in >> n;
	} while (n <= 0);
	
	delete[] t.a;
	t.init(n);
	t.n = n;

	for (int i = 0; i < t.n; ++i)
	{
		cout << "a[" << i << "]="; in >> t[i];
	}
	return in;
}