#include <iostream>
#include <malloc.h>
using namespace std;

void sort(int *a,int len) {		//�����㷨���Ӵ�С����
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - i - 1; j++) {
			int temp = 0;
			if (a[j] < a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void func(int a[],int n) {//n������Ԫ�ظ���
	
	int total_sequence = n * (n - 1) / 2;						//����total_sequence��������
	int *result, *max;											//����ָ����������ڴ����������ӵĽ��
	result = (int *)malloc(total_sequence * sizeof(int));		//������̬����result������total_sequence���ڴ�ռ�
	max = (int *)malloc(total_sequence * sizeof(int));			//������̬����max,��ÿһ�˵����ֵ�ŵ�max������
	
	int i, j, sum = a[0];										//sum��ʼʱΪ�����һ��ֵ
	for (i = 0; i < n - 1; i++) {								//���������
		for (j = i + 1; j < n ; j++) {//n = 6
			sum += a[j];										//��sum����ÿһ����ӵ�ֵ
			result[j] = sum;									//��ÿһ�˱����ֵ����result[]��

			if (j == i + 1) {									//����������ʾ���ֻ���һ��
				cout << "\n��" << (i + 1)
					<< "����ӵ�ֵΪ��";
			}
			cout << result[j] << " ";							//���ÿһ�˵Ľ��
		}
		sum = a[i + 1];											//��sum���¸�ֵ��ֵΪ��i�˵ĵ�һ��ֵ
		cout << "\n";
		sort(result, total_sequence);							//��result����Ӵ�С����,����total_sequence��������
		max[i] = result[0];										//��ÿһ�˵����ֵ�ŵ�max������
		
	}

	sort(max, total_sequence);									//��max����Ӵ�С����,ȡ��max�е����ֵ
	cout << "\n������ǣ�" << max[0];


	free(result);	//�ͷ��ڴ�ռ�
	free(max);
}

int main()
{
	
	int a[] = { -2, 11, -4, 13, -5, -2 };
	int len = sizeof(a) / sizeof(int);			//���鳤��
	
	func(a,len);
	cout << endl;
	system("pause");
	return 0;
}

