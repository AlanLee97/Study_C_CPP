#include <stdio.h>
int a, b, c;
int max()
{
	int max;
	if (a<b)
	{
		max = b;
		if (b<c)
		{
			max = c;
		}
	}
	else if (a<c)
	{
		max = c;
	}
	else max = a;

	return max;

/*  //�㷨��
	int temp;
 	scanf("%d%d%d",&a,&b,&c);
	temp=(a>b)?a:b;
	t=(temp>c)?temp:c;
	return t;*/

}

int main()
{
	int m;
	scanf("%d%d%d", &a, &b, &c);
	m = max();
	printf("���ֵΪ��%d", m);
	system("pause");
	return 0;
}
