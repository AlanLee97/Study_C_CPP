#include <stdio.h>
int mian()
{
	int x, y;
	printf("������X��");
	scanf("%d", &x);
	if (x >= 10)
	{
		y = 3 * x - 11;
		printf("�����YֵΪ��%d", y);
	}

	if ((x >= 1) && (x < 10))
	{
		y = 2 * x - 1;
		printf("�����YֵΪ��%d", y);
	}
	else y = x;
	printf("�����YֵΪ��%d", y);
	return 0;
}