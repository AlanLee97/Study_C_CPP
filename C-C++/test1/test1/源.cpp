#include<iostream>
using namespace std;
/*
  实现将数组中的数字交换的功能
  第一个与最后一个交换，第二个与倒数第二个交换，第三个与倒数第三个交换，以此类推
*/
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

	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}



/*//方法一：
int length = sizeof(arr) / sizeof(int);
int i, j;
for (i = 0, j = length - 1; i < j; i++, j--) {
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
*/