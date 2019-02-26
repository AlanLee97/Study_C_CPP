#include<stdio.h>
void search(int max[], int min[], int c[])
{
	int i;
	for (i = 1;i<10;i++)
	{
		if (c[i]>max[1])
		{
			max[1] = c[i];
			max[0] = i;
		}
		if (c[i]<min[1])
		{
			min[1] = c[i];
			min[0] = i;
		}
	}
}
void swap(int max[], int min[], int a[])
{
	int temp;
	temp = a[9];

	if (min[1] == temp)
	{
		temp = max[1];
		a[max[0]] = a[0];
		a[0] = a[9];
		a[9] = temp;
	}
	else
	{
		temp = a[9];
		a[9] = max[1];
		a[max[0]] = temp;
		temp = a[0];
		a[0] = min[1];
		a[min[0]] = temp;
	}
}

int main()
{
	int max[2] = { 0 }, min[2] = { 0 }, a[10], i;
	for (i = 0;i<10;i++)
	{
		printf("请输入第%d个值", i + 1);
		scanf("%d", &a[i]);
		fflush(stdin);
		printf("\n");
		max[1] = min[1] = a[0];
		search(max, min, a);
		swap(max, min, a);
		for (i = 0;i<10;i++)
		{
			printf("%d", a[i]);
		}

	}
	return 0;
}

