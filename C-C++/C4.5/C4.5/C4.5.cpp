#include<stdio.h>
#include<math.h>
#define m 1000
/*从键盘输入一个小于1000的正整数，要求输出它的平
方根（如平方根不是整数，则输出其整数部分）。要求
在输入数据后先对其检查是否为小于1000的正数。若不
是，则要求从新输入。*/
int main()
{
	int a, b;
	printf("请输入一个小于1000的整数：");
	scanf("%d", &a);
	while (a > m)
	{
		printf("你输入的数大于1000。\n请重新输入：");
		scanf("%d", &a);
	}
	b = sqrt(a);
	printf("%d的平方根整数部分是%d", a, b);
	
	return 0;
}
