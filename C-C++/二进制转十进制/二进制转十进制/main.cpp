#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int arrBinary[4] = {1,0,0,1};
	int decNum = 0;//��Ŷ����Ƶı���
	int length = sizeof(arrBinary) / sizeof(int);
	cout << "��ǰ�Ķ�������Ϊ��";
	for (int i = 0; i < length; i++) {
		cout << arrBinary[i] << " ";
	}

	//��������ת��Ϊʮ����
	for (int i = 0; i < length; i++) {
		if (arrBinary[i] != 0) {
			decNum += pow(2, i);
		}
	}
	cout << "\nת��Ϊʮ���Ƶ���λ��" << decNum;

	cout << endl;
	system("pause");
	return 0;
}
