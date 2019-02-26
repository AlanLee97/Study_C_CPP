#include <stdio.h>
#include <iostream>
#include <math.h>
#define N 50
using namespace std;

void GameTable(int k, int array[][N]);
void print(int k, int array[][N]);         //输出二维数组 
int main()
{
	int k;
	int array[N][N];
	printf("设参赛选手的人数为n（n=2^k），请输入k 的值：");
	do
	{
		cin >> k;
		if (k != 0)
		{
			GameTable(k, array);
			print(k, array);
		}
		else
			printf("您输入的数据有误,请重新输入");
	} while (k != 0);
	system("pause");
}
void GameTable(int k, int array[][N])//数组下标从1开始
{
	int i, j, s, t;
	int n = 1;
	for (i = 1;i <= k;i++)
		n *= 2;                       //求总人数
	for (i = 1;i <= n;i++)
		array[1][i] = i;                  //第一行排1-8
	int m = 1;                          //用来控制每一次填表时i行j列的起始填充位置
	for (s = 1;s <= k;s++)                 //s指对称赋值的总循环次数，即分成几大步进行制作日程表
	{
		n = n / 2;
		for (t = 1;t <= n;t++)              //t指明内部对称赋值的循环次数
			for (i = m + 1;i <= 2 * m;i++)
				for (j = m + 1;j <= 2 * m;j++)
				{
					array[i][j + (t - 1)*m * 2] = array[i - m][j + (t - 1)*m * 2 - m];       //右上角等于左上角的值
					array[i][j + (t - 1)*m * 2 - m] = array[i - m][j + (t - 1)*m * 2];       //左下角等于右上角的值
				}
		m *= 2;
	}

}
void print(int k, int array[][N])
{
	int i, j;
	int num = pow(2, k);
	printf("%d人的循环赛日程表如下\n", num);
	for (i = 1;i <= num;i++)                           //输出二维数组 
	{
		for (j = 1;j <= num;j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}