#include<iostream>
using namespace std;


int main()
{
	int fun(int n);
	fun(5);

	system("pause");
	return 0;
}

int fun(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return fun(n * fun(n - 1));
	}
}
