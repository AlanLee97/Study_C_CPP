#include<iostream>
using namespace std;
//公鸡5元/只   母鸡3元/只   小鸡1元/3只
//问3种鸡各有多少只
//算法分析：
//以3种鸡的个数为枚举对象
//以3种鸡的种数和钱数为判断条件，穷举各种鸡的个数。

int main()
{
	//enum chickenType{cock,hen,chick};
	//公鸡5元/只   母鸡3元/只   小鸡1元/3只
	//chickenType recp;
	
	int x, y, z;
	for (x = 0; x <= 20; x++) {

		for (y = 0; y <= 34; y++) {

			for (z = 0; z <= 100; z++) {
				double totalMoney = 5 * x + 3 * y + z / 3;	//钱的总数
				int totalChicken = x + y + z;					//鸡的总数
				bool judge = (totalMoney == 100) && (totalChicken == 100) && (z % 3 ==0);
				if (judge) {
				cout << "公鸡数量：" << x 
					 << "\t母鸡数量：" << y
					 << "\t小鸡数量：" << z << "\n\n";
				}
				
			}
		}

	}












	system("pause");
	return 0;
}