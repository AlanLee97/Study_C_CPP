#include<iostream>
using namespace std;

/*
* 求101到150之间的质数
* 质数：只能被1和它本身整除
*/

int main()
{
	int i, j, count = 0;
	for (i = 101; i <= 150; i++) {
		for (j = 2; j < i; j++) {//计算i除以2到i-1之间的数
			if (i % j == 0) count++;//计算除了1和它本身能被整除的数。
		}
		if (count == 0)//只要有一个以上能整除j,count就不为0，即不是质数
			cout << i << " " << endl;
		count = 0;
	}
	system("pause");
	return 0;
}