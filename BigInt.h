#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "tabD.h"

using namespace std;

class BigInt : public tabD
{
	

public:
	/// constructors are the same, admittedly
	BigInt(){};
	BigInt(char s) :tabD(s) {};
	BigInt(const char* s) :tabD(s ? strlen(s) : 0 , s) {};
	BigInt(const BigInt& b) :tabD(b){};

	BigInt BigFactorial();
	BigInt BigFactorial_old();

	friend BigInt operator+(const BigInt& b1, const BigInt& b2);
	friend BigInt operator*(const BigInt& b1, const BigInt& b2);
	BigInt& operator=(const BigInt& b);
	BigInt& operator+=(const BigInt& b) { return *this = (*this + b); }
	BigInt operator++(int k) { BigInt old(*this); *this = (*this + '1'); return old; }

	///logic
	friend bool operator<(const BigInt& b1, const BigInt& b2);
	friend bool operator<=(const BigInt& b1, const BigInt& b2) { if (b1 < b2 || b1 == b2) return 1; return 0; }
	friend bool operator==(const BigInt& b1, const BigInt& b2);

	/// in/out
	friend istream& operator>>(istream& in, BigInt& b);
	friend ostream& operator<<(ostream& out, const BigInt& b);

	~BigInt() {};
};