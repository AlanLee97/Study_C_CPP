#include <stdio.h>
int main()
{
	int x, y;
	printf("Enter x£º");
	scanf("%d", &x);
	if (x<1)
	{
		y = x;
		printf("%d", y);
	}

	else if (x<10)
	{
		y = 2 * x - 1;
		printf("%d", y);
	}

	else
	{
		y = 3 * x - 11;
		printf("%d", y);
	}

	return 0;
}