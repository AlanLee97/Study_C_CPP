//function.h

#pragma once
#include <iostream>
using namespace std;
#define MAX 20

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

//ִ�в����ĺ���
void function(int n) {
	int i, j;
	int arr[MAX];							//�������������
	for (i = 2, j = 0; i < n; i++) {		//����2��n֮������м���������
		if (isPrime(i)) {					//�ж��Ƿ�Ϊ����
			arr[j] = i;						//�������������������������
			j++;							//���������±�����
		}
	}

	int count = 0;							//��¼�����Եĸ���
	for (i = 0; i < j; i++) {
		if (arr[i + 1] - arr[i] == 2) {		//�����Ҳ�Ϊ2��������
			count++;
		}
	}
	cout << count;
}

