#include<stdio.h>


int main()
{
	char c1 = 'C', c2 = 'h', c3 = 'i', c4 = 'n', c5 = 'a';

	printf("ԭ����Ϊ��%c%c%c%c%c\n", c1, c2, c3, c4, c5);
	c1 = c1 + 4;
	c2 = c2 + 4;
	c3 = c3 + 4;
	c4 = c4 + 4;
	c5 = c5 + 4;


	printf("�����������Ϊ��\n");
	printf("������printf������ӡ�����ģ�\n");
	printf("%c%c%c%c%c", c1,c2,c3,c4,c5);

	printf("\n������putchar������ӡ�����ģ�\n");
	putchar(c1);
	putchar(c2);
	putchar(c3);
	putchar(c4);
	putchar(c5);


	system("pause");
	return 0;
}