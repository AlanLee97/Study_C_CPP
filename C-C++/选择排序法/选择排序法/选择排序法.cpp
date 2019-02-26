#include<iostream>
//#define N 10
using namespace std;
int temp;

int main()
{
	int a[] = { 22,12,321,11,0,213,654,76,4,34 };
	int N = sizeof(a) / sizeof(int);  //获取数组的长度
	for (int i = 0; i < N ; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << a[i] << "," ;
	 }
	cout << endl;
	system("pause");
	return 0;
}
