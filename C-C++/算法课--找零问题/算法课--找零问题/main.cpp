#include<iostream>
using namespace std;


int main()
{
	void func(int n);
	int size;
	cout << "������һ����";
	cin >> size;
	func(size);

	cout << endl << endl;
	system("pause");
	return 0;
}

void func(int n) {
	//��������n = 368;
	double bai = n / 100;//��λ
	double shi1 = (n % 100);//68 ʮλ��
	double shi2 = (int)shi1 / 10;//6 ʮλ
	double ge = (int)shi1 % 10;// 8 ��λ
	double temp = 0;


		cout << "�һ�: " << endl
			<< " " << bai << " �� 100 Ԫ";
		
		if (shi1 >= 50) {//shi1 = 68
			cout << " \n 1 �� 50 Ԫ \n ";

			temp = shi1 - ge - 50;//temp = 10
			temp = temp / 10;//temp = 1
			cout << temp << " �� 10 Ԫ";
		}
		else {
			cout << " \n " << shi2 << " �� 10 Ԫ" << endl;
		}

		if (ge >= 2) {
			if (ge >= 5) {
				cout << " \n 1 �� 5 Ԫ";
				ge = ge - 5;//ge = 3
				if (ge >= 2) {
					ge = ge - 2;
					if (ge == 2) {
						cout << " \n 2 �� 2 Ԫ \n ";
					}
					else {
						cout << " \n 1 �� 2 Ԫ \n " << ge << " �� 1 Ԫ";
					}
					
				}
				
			}
		}
}
