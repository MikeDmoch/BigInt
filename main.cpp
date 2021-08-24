#include <iostream>
#include "BigInt.h"

using namespace std;

int main()
{
	BigInt b = "111";	

	//liczy silniê z b
	cout << endl << "wynik: " << b.BigFactorial() << endl;

	system("pause");
	return 0;
}