#include <iostream>
using namespace std;

int main()
{
	int searchNum = 0;
	int arr[] = { 10,13,18,36,39,58,67,99,100,210 };

	cout << "\n当前数组为：";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n请输入要查找的数字：";
	cin >> searchNum;
	void binarySearch(int a[], int searchNum);
	binarySearch(arr, searchNum);

	system("pause");
	return 0;
}

void binarySearch(int a[], int searchNum) {
	int low = 0;
	int arrLength = sizeof(a) / sizeof(int);
	int high = arrLength - 1;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (searchNum == a[mid]) {
			cout << "\n该数在数组中的第" << mid + 1 << "位。\n";
			break;
		}
		if (searchNum > a[mid]) {
			low = mid + 1;
		}
		if (searchNum < a[mid]) {
			high = mid - 1;
		}

	}

}
