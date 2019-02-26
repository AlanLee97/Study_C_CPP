#include<iostream>
using namespace std;

char str[100];

int main()
{
	void fun(char str[], int n);
	int count = 0;
	while (1) {
		cin >> str[count];
		if (str[count] == '#') break;
		count++;
	}
	fun(str, count - 1);
	system("pause");
	return 0;
}

void fun(char str[], int n) {
	if (n != -1) {
		cout << str[n];
		fun(str, n - 1);
	}
}
