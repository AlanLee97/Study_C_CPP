#include<stdio.h> 

int j, i[5];//用来表示4个运算符
int sign;//累加运算时的符号
int result = 5;//保存运算式的结果
int count = 0;//计数器，统计符合条件的方案
int num[6] = { 5,5,5,5,5,5 };//保存操作数
float left, right;//上一步结果，下一步结果
char oper[5] = { ' ','+','-','*','/' };//运算符
void play();

int main()
{

	/*printf("请输入5个数：");
	for (j = 1;j <= 5;j++)
	scanf_s("%d", &num[j]);
	printf("请输入结果：");
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
