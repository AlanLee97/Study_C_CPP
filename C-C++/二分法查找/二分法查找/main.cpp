#include <iostream>
using namespace std;

int main()
{
	int searchNum = 0;
	int arr[] = { 10,13,18,36,39,58,67,99,100,210 };

	cout << "\n��ǰ����Ϊ��";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n������Ҫ���ҵ����֣�";
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
			cout << "\n�����������еĵ�" << mid + 1 << "λ��\n";
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
