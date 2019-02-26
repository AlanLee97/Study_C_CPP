#include<iostream>
#define N 10
using namespace std;
int main() {
	int i = 0 , j = 0;
	int a[N] = { 32,43,1,12,3,44,52,23,666,321};
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}