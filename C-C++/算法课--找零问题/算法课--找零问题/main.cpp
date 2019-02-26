#include<iostream>
using namespace std;


int main()
{
	void func(int n);
	int size;
	cout << "请输入一个面额：";
	cin >> size;
	func(size);

	cout << endl << endl;
	system("pause");
	return 0;
}

void func(int n) {
	//假设输入n = 368;
	double bai = n / 100;//百位
	double shi1 = (n % 100);//68 十位数
	double shi2 = (int)shi1 / 10;//6 十位
	double ge = (int)shi1 % 10;// 8 个位
	double temp = 0;


		cout << "找回: " << endl
			<< " " << bai << " 张 100 元";
		
		if (shi1 >= 50) {//shi1 = 68
			cout << " \n 1 张 50 元 \n ";

			temp = shi1 - ge - 50;//temp = 10
			temp = temp / 10;//temp = 1
			cout << temp << " 张 10 元";
		}
		else {
			cout << " \n " << shi2 << " 张 10 元" << endl;
		}

		if (ge >= 2) {
			if (ge >= 5) {
				cout << " \n 1 张 5 元";
				ge = ge - 5;//ge = 3
				if (ge >= 2) {
					ge = ge - 2;
					if (ge == 2) {
						cout << " \n 2 张 2 元 \n ";
					}
					else {
						cout << " \n 1 张 2 元 \n " << ge << " 张 1 元";
					}
					
				}
				
			}
		}
}
