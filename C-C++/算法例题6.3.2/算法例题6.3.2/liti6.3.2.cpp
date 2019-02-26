#include <stdio.h>
#include <iostream>
#include <math.h>
#define N 50
using namespace std;

void GameTable(int k, int array[][N]);
void print(int k, int array[][N]);         //�����ά���� 
int main()
{
	int k;
	int array[N][N];
	printf("�����ѡ�ֵ�����Ϊn��n=2^k����������k ��ֵ��");
	do
	{
		cin >> k;
		if (k != 0)
		{
			GameTable(k, array);
			print(k, array);
		}
		else
			printf("���������������,����������");
	} while (k != 0);
	system("pause");
}
void GameTable(int k, int array[][N])//�����±��1��ʼ
{
	int i, j, s, t;
	int n = 1;
	for (i = 1;i <= k;i++)
		n *= 2;                       //��������
	for (i = 1;i <= n;i++)
		array[1][i] = i;                  //��һ����1-8
	int m = 1;                          //��������ÿһ�����ʱi��j�е���ʼ���λ��
	for (s = 1;s <= k;s++)                 //sָ�ԳƸ�ֵ����ѭ�����������ֳɼ��󲽽��������ճ̱�
	{
		n = n / 2;
		for (t = 1;t <= n;t++)              //tָ���ڲ��ԳƸ�ֵ��ѭ������
			for (i = m + 1;i <= 2 * m;i++)
				for (j = m + 1;j <= 2 * m;j++)
				{
					array[i][j + (t - 1)*m * 2] = array[i - m][j + (t - 1)*m * 2 - m];       //���Ͻǵ������Ͻǵ�ֵ
					array[i][j + (t - 1)*m * 2 - m] = array[i - m][j + (t - 1)*m * 2];       //���½ǵ������Ͻǵ�ֵ
				}
		m *= 2;
	}

}
void print(int k, int array[][N])
{
	int i, j;
	int num = pow(2, k);
	printf("%d�˵�ѭ�����ճ̱�����\n", num);
	for (i = 1;i <= num;i++)                           //�����ά���� 
	{
		for (j = 1;j <= num;j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}