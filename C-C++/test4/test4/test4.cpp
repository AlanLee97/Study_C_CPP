#include<iostream>
using namespace std;

/*
* ��101��150֮�������
* ������ֻ�ܱ�1������������
*/

int main()
{
	int i, j, count = 0;
	for (i = 101; i <= 150; i++) {
		for (j = 2; j < i; j++) {//����i����2��i-1֮�����
			if (i % j == 0) count++;//�������1���������ܱ�����������
		}
		if (count == 0)//ֻҪ��һ������������j,count�Ͳ�Ϊ0������������
			cout << i << " " << endl;
		count = 0;
	}
	system("pause");
	return 0;
}