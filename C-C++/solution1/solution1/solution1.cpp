#include<iostream>
using namespace std;
//����5Ԫ/ֻ   ĸ��3Ԫ/ֻ   С��1Ԫ/3ֻ
//��3�ּ����ж���ֻ
//�㷨������
//��3�ּ��ĸ���Ϊö�ٶ���
//��3�ּ���������Ǯ��Ϊ�ж���������ٸ��ּ��ĸ�����

int main()
{
	//enum chickenType{cock,hen,chick};
	//����5Ԫ/ֻ   ĸ��3Ԫ/ֻ   С��1Ԫ/3ֻ
	//chickenType recp;
	
	int x, y, z;
	for (x = 0; x <= 20; x++) {

		for (y = 0; y <= 34; y++) {

			for (z = 0; z <= 100; z++) {
				double totalMoney = 5 * x + 3 * y + z / 3;	//Ǯ������
				int totalChicken = x + y + z;					//��������
				bool judge = (totalMoney == 100) && (totalChicken == 100) && (z % 3 ==0);
				if (judge) {
				cout << "����������" << x 
					 << "\tĸ��������" << y
					 << "\tС��������" << z << "\n\n";
				}
				
			}
		}

	}












	system("pause");
	return 0;
}