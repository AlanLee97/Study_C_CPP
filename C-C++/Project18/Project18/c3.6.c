#include<stdio.h>


int main()
{
	char c1 = 'C', c2 = 'h', c3 = 'i', c4 = 'n', c5 = 'a';

	printf("原密码为：%c%c%c%c%c\n", c1, c2, c3, c4, c5);
	c1 = c1 + 4;
	c2 = c2 + 4;
	c3 = c3 + 4;
	c4 = c4 + 4;
	c5 = c5 + 4;


	printf("翻译过的密码为：\n");
	printf("这是用printf函数打印出来的：\n");
	printf("%c%c%c%c%c", c1,c2,c3,c4,c5);

	printf("\n这是用putchar函数打印出来的：\n");
	putchar(c1);
	putchar(c2);
	putchar(c3);
	putchar(c4);
	putchar(c5);


	system("pause");
	return 0;
}