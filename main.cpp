#include <iostream>
#include "BigInt.h"

using namespace std;

int main()
{
	BigInt b = "111";	

	//liczy silni� z b
	cout << endl << "wynik: " << b.BigFactorial() << endl;

	system("pause");
	return 0;
}