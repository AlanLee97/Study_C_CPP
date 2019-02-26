#include <stdio.h>
int mian()
{
	int x, y;
	printf("请输入X：");
	scanf("%d", &x);
	if (x >= 10)
	{
		y = 3 * x - 11;
		printf("输出的Y值为：%d", y);
	}

	if ((x >= 1) && (x < 10))
	{
		y = 2 * x - 1;
		printf("输出的Y值为：%d", y);
	}
	else y = x;
	printf("输出的Y值为：%d", y);
	return 0;
}