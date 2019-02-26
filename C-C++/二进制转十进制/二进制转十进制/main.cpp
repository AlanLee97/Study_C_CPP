#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int arrBinary[4] = {1,0,0,1};
	int decNum = 0;//存放二进制的变量
	int length = sizeof(arrBinary) / sizeof(int);
	cout << "当前的二进制数为：";
	for (int i = 0; i < length; i++) {
		cout << arrBinary[i] << " ";
	}

	//将二进制转换为十进制
	for (int i = 0; i < length; i++) {
		if (arrBinary[i] != 0) {
			decNum += pow(2, i);
		}
	}
	cout << "\n转换为十进制的数位：" << decNum;

	cout << endl;
	system("pause");
	return 0;
}
