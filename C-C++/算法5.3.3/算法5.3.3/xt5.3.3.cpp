#include<iostream>
using namespace std;

int isPrimer(int a) {
	int i = 0;
	for (i = 2; i <= a - 1; i++) {
		if (a%i == 0)
			return 0;
	}
	return 1;
}

void PrimerFunc(int n) {
	int i;
	if (isPrimer(n)) {
		cout << n;
	}
	else {
		for (i = 2;i <= n - 1;i++) {
			if (n%i == 0) {
				cout << "\t" << i;
				if (isPrimer(n / i)) {
					cout << "\t" << n / i ;
					break;
				}
				else {
					PrimerFunc(n / i);
				}
				break;
			}
		}
	}
}

int main()
{
	int n;
	cout << "请输入一个合数：";
	cin >> n;
	PrimerFunc(n);

	system("pause");
	return 0;
}