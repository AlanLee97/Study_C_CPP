//function.h

#pragma once
#include <iostream>
using namespace std;
#define MAX 200

//�ж��Ƿ�Ϊ����
bool isPrime(int n) {
	bool prime = true;
	for (int i = 2; i < n; i++) {			//��n����2��n - 1����
		if (n % i == 0) {					//���n ������һ��������
			prime = false;					//��ôn��������
			break;
		}
	}
	return prime;
}


int x = -1;									//�����±�							
int count = 0;								//��¼�����Եĸ���

//�ݹ麯��
int primeCouple(int arr[], int len) {
	x++;									//�����±�
	if (arr[x + 1] - arr[x] == 2) {			//�����ڵ�����֮��Ϊ2
		::count++;							//ͳ�������Եĸ���
	}
	if (x == len - 1) {						//�ݹ����
		return 0;
	}
	else {
		return (primeCouple(arr, len));		//�ݹ����
	}
}

//ִ�в����ĺ���
void function(int n) {
	int i, j = 0;
	int arr[MAX];							//�������������
	for (i = 2; i < n; i++) {				//����2��n֮������м���������
		if (isPrime(i)) {					//�ж��Ƿ�Ϊ����
			arr[j] = i;						//�������������������������
			j++;							//���������±�����
		}
	}

	int len = 0;
	len = sizeof(arr) / sizeof(int);		//����ʵ�ʳ���
	primeCouple(arr, len);					//�ݹ����primeCouple()�������Եĸ���
	cout << ::count;
}



