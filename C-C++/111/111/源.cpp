#include<stdio.h> 

int j, i[5];//������ʾ4�������
int sign;//�ۼ�����ʱ�ķ���
int result = 5;//��������ʽ�Ľ��
int count = 0;//��������ͳ�Ʒ��������ķ���
int num[6] = { 5,5,5,5,5,5 };//���������
float left, right;//��һ���������һ�����
char oper[5] = { ' ','+','-','*','/' };//�����
void play();

int main()
{

	/*printf("������5������");
	for (j = 1;j <= 5;j++)
	scanf_s("%d", &num[j]);
	printf("����������");
	scanf_s("%d", &result);*/
	play();

	return 0;
}


void play()
{
	if (p==3) {
		left = 0;
		right = num[1];
		sign = 1;
		for (j = 1;j <= 4;j++)
		{
			switch (oper[i[j]])
			{
			case '+':
				left = left + sign * right;
				sign = 1;
				right = num[j + 1];
				break;
			case '-':
				left = left + sign * right;
				sign = -1;
				right = num[j + 1];
				break;
			case '*':
				right = right * num[j + 1];
				break;
			case '/':
				right = right / num[j + 1];
				break;
			}
		}
		if (left + sign * right == result)
		{
			count++;
			printf("%3d:", count);
			for (j = 1;j <= 4;j++)
				printf("%d%c", num[j], oper[i[j]]);
			printf("%d=%d\n", num[5], result);
	}
	else
	{
		for (int p;p<4;p++) 
		{

		}
	}
}
