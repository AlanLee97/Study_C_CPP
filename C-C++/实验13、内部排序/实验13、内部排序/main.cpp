#include <iostream>
#include "Sorting.h"
#define N 50
using namespace std;

KeyType a[] = { 49, 38, 65, 97, 76, 13, 27,49 };
RecType R[N];
int len = sizeof(a) / sizeof(KeyType);
int main()
{
	//cout << len;
	cout << "初始关键字：";
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	

	//1.直接插入排序法
	cout << "1.直接插入排序法：";
	CreateSort(R, a, len);
	insertSort(R, len);
	cout << "\n-----直接插入排序后的结果：";
	DispSort(R, len);
	cout << "\n\n";

	//2.希尔排序（分组插入排序方法）
	cout << "2.希尔排序：";
	CreateSort(R, a, len);
	ShellSort(R, len);
	cout << "\n-----希尔排序后的结果：";
	DispSort(R, len);
	cout << "\n\n";

	//3.1 冒泡排序
	cout << "3.1 冒泡排序：";
	CreateSort(R, a, len);
	BubbleSort(R, len);
	cout << "\n-----冒泡排序后的结果：";
	DispSort(R, len);
	cout << "\n\n";

	//3.2 优化的冒泡排序
	cout << "3.2 优化的冒泡排序：";
	CreateSort(R, a, len);
	BubbleSort1(R, len);
	cout << "\n-----优化冒泡排序后的结果：";
	DispSort(R, len);
	cout << "\n\n";

	//4.快速排序法
	cout << "4.快速排序法：";
	CreateSort(R, a, len);
	QuickSort(R, 0, len - 1);
	cout << "\n-----快速排序后的结果：";
	DispSort(R, len);
	cout << "\n\n";


	//5.简单选择排序
	cout << "5.简单选择排序：";
	CreateSort(R, a, len);
	SelectSort(R, len);
	cout << "\n-----简单选择排序后的结果：";
	DispSort(R, len);
	cout << "\n\n";


	cout << endl;
	system("pause");
	return 0;
}