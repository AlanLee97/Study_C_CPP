#include<iostream>
using namespace std;
//公鸡5元/只   母鸡3元/只   小鸡1元/3只
//问3种鸡各有多少只
//算法分析：
//以3种鸡的个数为枚举对象
//以3种鸡的种数和钱数为判断条件，穷举各种鸡的个数。


int main()
{
	enum Chicken{cock,hen,chick};
	int x, y, z;
	

	for (x = 0;x <= 20;x++) {
		for (y = 0;y <= 34;y++) {
			for (z = 0;z <= 100;z++) {

				int totalChicken = x + y + z;					//鸡的总数
				double totalMoney = 5 * x + 3 * y + z / 3;		//钱的总数
				bool judge = (totalChicken == 100) && (totalMoney == 100)
					&& (z % 3 == 0);	//判定条件

				if (judge) {
					for (int i = cock; i <= chick; i++) {
						switch (i) {
							case cock: cout << "公鸡数量：" << x ; break;
							case hen: cout << "\t母鸡数量：" << y; break;
							case chick: cout << "\t小鸡数量：" << z << endl << endl; break;
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