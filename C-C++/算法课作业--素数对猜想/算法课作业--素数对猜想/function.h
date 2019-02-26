//function.h

#pragma once
#include <iostream>
using namespace std;
#define MAX 20

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

//执行操作的函数
void function(int n) {
	int i, j;
	int arr[MAX];							//存放素数的数组
	for (i = 2, j = 0; i < n; i++) {		//遍历2到n之间的数有几个是素数
		if (isPrime(i)) {					//判断是否为素数
			arr[j] = i;						//如果是素数，将该数放入数组
			j++;							//控制数组下标增加
		}
	}

	int count = 0;							//记录素数对的个数
	for (i = 0; i < j; i++) {
		if (arr[i + 1] - arr[i] == 2) {		//相邻且差为2的素数对
			count++;
		}
	}
	cout << count;
}

