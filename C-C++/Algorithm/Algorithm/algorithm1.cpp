#include<iostream>
using namespace std;
//����5Ԫ/ֻ   ĸ��3Ԫ/ֻ   С��1Ԫ/3ֻ
//��3�ּ����ж���ֻ
//�㷨������
//��3�ּ��ĸ���Ϊö�ٶ���
//��3�ּ���������Ǯ��Ϊ�ж���������ٸ��ּ��ĸ�����


int main()
{
	enum Chicken{cock,hen,chick};
	int x, y, z;
	

	for (x = 0;x <= 20;x++) {
		for (y = 0;y <= 34;y++) {
			for (z = 0;z <= 100;z++) {

				int totalChicken = x + y + z;					//��������
				double totalMoney = 5 * x + 3 * y + z / 3;		//Ǯ������
				bool judge = (totalChicken == 100) && (totalMoney == 100)
					&& (z % 3 == 0);	//�ж�����

				if (judge) {
					for (int i = cock; i <= chick; i++) {
						switch (i) {
							case cock: cout << "����������" << x ; break;
							case hen: cout << "\tĸ��������" << y; break;
							case chick: cout << "\tС��������" << z << endl << endl; break;
							default: break;
						}
					}
				}

			}
		}
	}

	system("pause");
	return 0;
}