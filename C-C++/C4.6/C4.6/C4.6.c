#include<stdio.h>
/* 有一个函数如下：
        {  x         (  x<1  )
　	  y={   2x-1     ( 1<=x<10 )             
        {  3x-11     ( x>=10 )
 写一程序，输入x 输出y值
 */

int main()
{
	int x,y;
	printf("请输入x的值：");
	scanf("%d", &x);
	if (x < 1)
	{
		y = x;
	}
	else if (x > 10)
	{
		y = 3 * x - 11;
	}
	else y = 2 * x - 1;

	printf("y的值为：%d", y);

	system("pause");
	return 0;
}
