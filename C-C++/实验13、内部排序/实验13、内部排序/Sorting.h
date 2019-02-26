#pragma once
#include <iostream>
using namespace std;

typedef int KeyType;
typedef char InfoType;

typedef struct {
	KeyType key;
	InfoType data;
}RecType;

//���������㷨Ҫ�õ�������
void CreateSort(RecType R[], KeyType a[], int len) {
	for (int i = 0; i < len; i++) {
		R[i].key = a[i];
		R[i].data = 'a';
	}
}

//������ź��������
void DispSort(RecType R[], int len) {
	for (int i = 0; i < len; i++) {
		cout << R[i].key << " ";
	}
}


//1.ֱ�Ӳ�������
void insertSort(RecType R[], int n) {
	int i = 0, j, k;
	RecType temp;
	temp = R[i];
	for (i = 1, k = 1; i < n; i++, k++) {
		if (R[i].key < R[i - 1].key) {				//ǰ������Ⱥ������Сʱ
			temp = R[i];							//����������ŵ�temp��
			j = i - 1;								//��¼ǰһ��λ��
			while (j >= 0 && temp.key < R[j].key) {
				R[j + 1] = R[j];					//������
				j--;
			}
			R[j + 1] = temp;
		}
		cout << "\n��" << k << "��ֱ�Ӳ�������";
		DispSort(R, n);
	}
}

//2.ϣ������
void ShellSort(RecType R[], int n) {
	int i, j, d, k = 1;
	RecType temp;
	d = n / 2;									//��������ֵ
	while (d > 0) {
		for (i = d; i < n; i++) {
			temp = R[i];						//��R[i]��ֵ������ʱ������
			j = i - d;							//�����±�����Ӧ�ı任
			while (j >= 0 && temp.key < R[j].key) {
				R[j + d] = R[j];				//��R[j]��ֵ���ǵ�R[j + d]��
				j = j - d;						//�����±�����Ӧ�ı任
			}
			R[j + d] = temp;					//��temp�е�ֵ�ŵ�R[j + d]��
		}
		d = d / 2;								//��С����
		cout << "\n��" << k++ << "��ϣ����������";
		DispSort(R, n);
	}
}

//3.1 ð������
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
		cout << "\n��" << k++ << "��ð������";
		DispSort(R, n);
	}
}

//3.2 �Ż���ð������
void BubbleSort1(RecType R[], int n) {
	int i, j, k = 1;
	bool exchange;
	RecType temp;
	for (i = 0; i < n - 1; i++) {
		exchange = false;							//��һ������ǰexchange��Ϊ��
		for (j = n - 1; j > i; j--) {
			if (R[j].key < R[j - 1].key) {
				temp.key = R[j].key;
				R[j].key = R[j - 1].key;
				R[j - 1].key = temp.key;
				exchange = true;					//������ʱ��exchange��Ϊ��
			}
		}
		if (!exchange) {							//û�з�������ʱ������ѭ��
			return;
		}
		cout << "\n��" << k++ << "���Ż�ð������";
		DispSort(R, n);
	}
}


int partion(RecType R[], int s, int t) {
	int i = s;
	int j = t;
	static int n = t + 1;							//�������ĳ���
	RecType temp = R[i];							//����һ�������ֵ��temp����Ϊ����
	while (i < j) {
		//����ĩβ���±� j ��ǰ�ƶ�
		while (j > i && R[j].key >= temp.key) {		//temp.keyΪ����
			j--;
		}
		R[i] = R[j];								//R[j]��ֵ����R[i]��ֵ

		//����ǰ����±� i �����ƶ�
		while (i < j && R[i].key <= temp.key) {		//temp.keyΪ����
			i++;
		}
		R[j] = R[i];								//R[j]��ֵ����R[i]��ֵ

	}
	R[i] = temp;									//�Ƚ���֮��temp��ֵ�ŵ�R[i]��λ��
	cout << "\n��" << temp.key  << "Ϊ���ᣬ����[" << s + 1 << " - "<< t + 1 << "]���䣺";
	DispSort(R, n);
	return i;
}

//4.��������
int k = 1;
void QuickSort(RecType R[], int s, int t) {
	int i;
	if (s < t) {									//���������ٴ�������Ԫ�ص����
		i = partion(R, s, t);
		QuickSort(R, s, i - 1);						//����������еݹ�����
		QuickSort(R, i + 1, t);						//����������еݹ�����
	}
}

//5.��ѡ������
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
		cout << "\n��" << k++ << "�ˣ�";
		cout << "ѡ��[" << k1++ << "-" << n 
			<< "]����С�ļ�¼�ŵ�" << k2++ << "��";
		DispSort(R, n);
	}
}
