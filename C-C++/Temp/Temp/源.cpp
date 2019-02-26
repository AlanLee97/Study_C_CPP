#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 22,32,21,12,45,52,11,19,10,90 };
	int temp;
	int length = sizeof(arr) / sizeof(int);
	for (int i = 0; i < length - 1 - i; i++) {
		temp = arr[i];
		arr[i] = arr[length - 1 - i];
		arr[length - 1 - i] = temp;
	}





	/*
	int length = sizeof(arr) / sizeof(int);
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	}
	*/

	for (int i = 0; i < length - 1; i++) {
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}