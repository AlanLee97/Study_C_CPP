#include<iostream>
using namespace std;

int func(int n, int m) {
	if (m == 1 || n == 1) return 1;
	if (m > n) return func(n, n);
	if (m == n) return 1 + func(n, m - 1);
	if (n > m) return func(n - m, m) + func(n, m - 1);
}

int main()
{
	int n, sum;
	cout << "������һ������";
	cin >> n;
	sum = func(n, n);
	cout << "����" << sum << "����" << endl;

	system("pause");
	return 0;
}
