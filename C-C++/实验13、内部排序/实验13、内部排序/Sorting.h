#pragma once
#include <iostream>
using namespace std;

typedef int KeyType;
typedef char InfoType;

typedef struct {
	KeyType key;
	InfoType data;
}RecType;

//创建排序算法要用到的数组
void CreateSort(RecType R[], KeyType a[], int len) {
	for (int i = 0; i < len; i++) {
		R[i].key = a[i];
		R[i].data = 'a';
	}
}

//输出已排好序的数组
void DispSort(RecType R[], int len) {
	for (int i = 0; i < len; i++) {
		cout << R[i].key << " ";
	}
}


//1.直接插入排序
void insertSort(RecType R[], int n) {
	int i = 0, j, k;
	RecType temp;
	temp = R[i];
	for (i = 1, k = 1; i < n; i++, k++) {
		if (R[i].key < R[i - 1].key) {				//前面的数比后面的数小时
			temp = R[i];							//将后面的数放到temp中
			j = i - 1;								//记录前一个位置
			while (j >= 0 && temp.key < R[j].key) {
				R[j + 1] = R[j];					//往后移
				j--;
			}
			R[j + 1] = temp;
		}
		cout << "\n第" << k << "趟直接插入排序：";
		DispSort(R, n);
	}
}

//2.希尔排序
void ShellSort(RecType R[], int n) {
	int i, j, d, k = 1;
	RecType temp;
	d = n / 2;									//增量赋初值
	while (d > 0) {
		for (i = d; i < n; i++) {
			temp = R[i];						//将R[i]的值放在临时变量中
			j = i - d;							//数组下标做相应的变换
			while (j >= 0 && temp.key < R[j].key) {
				R[j + d] = R[j];				//将R[j]的值覆盖到R[j + d]中
				j = j - d;						//数组下标做相应的变换
			}
			R[j + d] = temp;					//将temp中的值放到R[j + d]中
		}
		d = d / 2;								//减小增量
		cout << "\n第" << k++ << "趟希尔插入排序：";
		DispSort(R, n);
	}
}

//3.1 冒泡排序
void BubbleSort(RecType R[], int n) {
	int i, j, k = 1;
	RecType temp;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (R[j].key < R[j - 1].key) {
				temp.key = R[j].key;
				R[j].key = R[j - 1].key;
				R[j - 1].key = temp.key;
			}
		}
		cout << "\n第" << k++ << "趟冒泡排序：";
		DispSort(R, n);
	}
}

//3.2 优化的冒泡排序
void BubbleSort1(RecType R[], int n) {
	int i, j, k = 1;
	bool exchange;
	RecType temp;
	for (i = 0; i < n - 1; i++) {
		exchange = false;							//第一趟排序前exchange置为假
		for (j = n - 1; j > i; j--) {
			if (R[j].key < R[j - 1].key) {
				temp.key = R[j].key;
				R[j].key = R[j - 1].key;
				R[j - 1].key = temp.key;
				exchange = true;					//有排序时，exchange置为真
			}
		}
		if (!exchange) {							//没有发生交换时，结束循环
			return;
		}
		cout << "\n第" << k++ << "趟优化冒泡排序：";
		DispSort(R, n);
	}
}


int partion(RecType R[], int s, int t) {
	int i = s;
	int j = t;
	static int n = t + 1;							//获得数组的长度
	RecType temp = R[i];							//将第一个数组的值给temp，作为枢轴
	while (i < j) {
		//控制末尾的下标 j 往前移动
		while (j > i && R[j].key >= temp.key) {		//temp.key为枢轴
			j--;
		}
		R[i] = R[j];								//R[j]的值覆盖R[i]的值

		//控制前面的下标 i 往后移动
		while (i < j && R[i].key <= temp.key) {		//temp.key为枢轴
			i++;
		}
		R[j] = R[i];								//R[j]的值覆盖R[i]的值

	}
	R[i] = temp;									//比较完之后将temp的值放到R[i]的位置
	cout << "\n以" << temp.key  << "为枢轴，划分[" << s + 1 << " - "<< t + 1 << "]区间：";
	DispSort(R, n);
	return i;
}

//4.快速排序
int k = 1;
void QuickSort(RecType R[], int s, int t) {
	int i;
	if (s < t) {									//区间内至少存在两个元素的情况
		i = partion(R, s, t);
		QuickSort(R, s, i - 1);						//对左区间进行递归排序
		QuickSort(R, i + 1, t);						//对右区间进行递归排序
	}
}

//5.简单选择排序
void SelectSort(RecType R[], int n) {
	int i, j, m, k = 1, k1 = 1, k2 = 1;
	RecType temp;
	for (i = 0; i < n - 1; i++) {
		m = i;
		for (j = i + 1; j < n; j++) {
			if (R[j].key < R[m].key) {
				m = j;
			}
		}
		if (m != i) {
			temp.key = R[i].key;
			R[i].key = R[m].key;
			R[m].key = temp.key;
		}
		cout << "\n第" << k++ << "趟：";
		cout << "选择[" << k1++ << "-" << n 
			<< "]中最小的记录放到" << k2++ << "：";
		DispSort(R, n);
	}
}
