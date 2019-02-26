#include <stdio.h>
#include <iostream>
using namespace std;

void f1() {
	static int si = 1;
	cout << "1f1: " << si << endl;
	si += 5;
	cout << "2f1: " << si << endl;
}

void f2() {
	int i = 1;
	cout << "1f2: " << i << endl;
	i += 5;
	cout << "2f2: " << i << endl;
}


int main()
{
	f1();
	f2();
	cout << "======================" << endl << endl;
	f1();
	f2();

	cout << endl;
	system("pause");
	return 0;
}




