#include "BigInt.h"
BigInt& BigInt::operator=(const BigInt& b)
{
	static_cast<tabD&>(*this) = b;

	return *this;
}

char add_digits(char z1, char z2, int& move)
{
	int p = 10;
	int k = (z1 - '0') + (z2 - '0') + move;
	char ch = k % p + '0';
	move = k / p;
	return ch;
}

int multiply_digits(int a, int b, int& r) //	z1 - multiplicand;	by a one-digit number
{
	int p = 10;
	int k = (a - '0') * (b - '0') + r;
	r = k / p;
	return k - r*p;
}

BigInt operator*(const BigInt& b1, const BigInt& b2)
{
	int n2 = b2.size();
	int n1 = b1.size();
	int move = 0;
	// els <=> elements

	BigInt **aux;
	BigInt *ww;
	BigInt w = '0';
	BigInt aux1 = '0';
	///987*23 = 7*23 + 10*  8*23 + 10^2*  9*23

	aux = new BigInt*[n1*n2];
	ww = new BigInt[n1];

	for (int i = 0; i < n1; i++) {
		aux[i] = new BigInt[n2];
		ww[i] = '0';
	}
	for (int i = n1 - 1; i >= 0; i--) {
		move = 0;
		for (int j = n2 - 1; j >= 0; j--) {
			aux[i][j] = '0' + multiply_digits(b1[i], b2[j], move);
			for (int k = 0; k < (n1 - 1) + (n2 - 1) - i - j; k++) {
				(tabD&)aux[i][j] = (tabD&)aux[i][j] + '0';
			}
			///cout << i << " " << j << aux[i][j];
			ww[i] += aux[i][j];
		}
		if (move != 0)
		{
			aux1 = move + '0';
			for (int k = 0; k < (n1 - 1) + (n2 - 1) - i + 1; k++) {
				(tabD&)aux1 = (tabD&)aux1 + '0';
			}
			///cout << "aux1: " << aux1;
			ww[i] += aux1;
			///cout << "ww[" << i << "]: " << ww[i];
		}
		w += ww[i];
	}
	return w;
}

BigInt operator+(const BigInt& b1, const BigInt& b2)
{
	BigInt b;

	int move = 0;
	int i1 = b1.size() - 1;
	int i2 = b2.size() - 1;

	while (i1 >= 0 && i2 >= 0)
	{
		char ch = add_digits(b1[i1], b2[i2], move);
		(tabD&)b = ch + (tabD&)b;
		i1--; i2--;
	}
	while (i1 >= 0) {
		char ch = add_digits(b1[i1], '0', move);
		(tabD&)b = ch + (tabD&)b;
		i1--;
	}
	while (i2 >= 0) {
		char ch = add_digits('0', b2[i2], move);
		(tabD&)b = ch + (tabD&)b;
		i2--;
	}
	if (move) {
		char ch = move + '0';
		(tabD&)b = ch + (tabD&)b;
	}
	return b;
}

bool operator<(const BigInt& b1, const BigInt& b2)	// b1 < b2 ?
{
	int a = 0;
	if (b1.size() < b2.size()) return 1;
	if (b2.size() < b1.size()) return 0;

	for (int i = 0; i < b1.size(); i++) {
		if (b1[i] > b2[i]) return 0;
		else if (b1[i] < b2[i]) return 1;
		if (b1[i] == b2[i]) a++;
	}

	if (a == b1.size()) return 0;
	return 1;
}

bool operator==(const BigInt& b1, const BigInt& b2)
{
	int a = 0;
	if (b1.size() != b2.size()) return 0;

	for (int i = 0; i < b1.size(); i++) {
		if (b1[i] != b2[i]) return 0;
	}
	return 1;
}

BigInt multi(const BigInt& b1, const BigInt& b2)
{
	BigInt aux = '0';
	for (BigInt i = '0'; i < b2; i += '1')
	{
		aux += b1;
	}
	return aux;
}

BigInt BigInt::BigFactorial_old()
{
	BigInt aux = '1';

	for (BigInt i = '1'; i <= *this; i += '1')
	{
		aux = multi(aux, i);
		//cout << "w8 m8: " << i;
		//system("cls");
	}
	return aux;
}

BigInt BigInt::BigFactorial()
{
	BigInt aux = '1';

	for (BigInt i = '1'; i <= *this; i += '1')
	{
		aux = aux * i;
		cout << i;
	}
	return aux;
}

istream& operator>>(istream& in, BigInt& b)
{

	char buf[200];
	cout << "Podaj poprawna liczbe w postaci napisu (tylko cyfry):";
	in >> buf;
	// ewentualna weryfikacja poprawnoœci wprowadzonych znaków
	b = BigInt(buf);
	return in;
}
ostream& operator<<(ostream& out, const BigInt& b)
{
	out << (tabD&)b << " " << endl;
	return out;
}