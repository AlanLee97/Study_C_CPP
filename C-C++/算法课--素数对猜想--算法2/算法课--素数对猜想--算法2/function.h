//function.h

#pragma once
#include <iostream>
using namespace std;
#define MAX 200

//判断是否为素数
bool isPrime(int n) {
	bool prime = true;
	for (int i = 2; i < n; i++) {			//让n除以2到n - 1的数
		if (n % i == 0) {					//如果n 被其中一个数整除
			prime = false;					//那么n不是素数
			break;
		}
	}
	return prime;
}


int x = -1;									//数组下标							
int count = 0;								//记录素数对的个数

//递归函数
int primeCouple(int arr[], int len) {
	x++;									//数组下标
	if (arr[x + 1] - arr[x] == 2) {			//当相邻的素数之差为2
		::count++;							//统计素数对的个数
	}
	if (x == len - 1) {						//递归出口
		return 0;
	}
	else {
		return (primeCouple(arr, len));		//递归调用
	}
}

//执行操作的函数
void function(int n) {
	int i, j = 0;
	int arr[MAX];							//存放素数的数组
	for (i = 2; i < n; i++) {				//遍历2到n之间的数有几个是素数
		if (isPrime(i)) {					//判断是否为素数
			arr[j] = i;						//如果是素数，将该数放入数组
			j++;							//控制数组下标增加
		}
	}

	int len = 0;
	len = sizeof(arr) / sizeof(int);		//数组实际长度
	primeCouple(arr, len);					//递归调用primeCouple()求素数对的个数
	cout << ::count;
}



