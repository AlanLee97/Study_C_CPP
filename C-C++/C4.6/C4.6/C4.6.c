#include<stdio.h>
/* ��һ���������£�
        {  x         (  x<1  )
��	  y={   2x-1     ( 1<=x<10 )             
        {  3x-11     ( x>=10 )
 дһ��������x ���yֵ
 */

int main()
{
	int x,y;
	printf("������x��ֵ��");
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

	printf("y��ֵΪ��%d", y);

	system("pause");
	return 0;
}
