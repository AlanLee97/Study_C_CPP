#include<stdio.h>
#define pi 3.14159
//��Բ�ܳ���Բ�����Բ��������Բ�������Բ�����
//r=1.5  h=3
float r = 1.5;
int h = 3;

float Circlelength()  //
{
	return(2 * pi * r);
}

float CircleArea()
{
	return(pi*r*r);
}

float BallSurfaceArea()
{
	return(4 * pi * r * r);
}

float BallSurfaceVolume()
{
	return((4/3) * pi * r * r * r);
}

float CylinderVolume()
{
	return(pi * r * r * h);
}

int main()
{
	float l=Circlelength();
	printf("Բ���ܳ�Ϊ��%4.2f\n", l);


	float s=CircleArea();
	printf("Բ�����Ϊ��%4.2f\n", s);

	float bsa=BallSurfaceArea();
	printf("Բ��ı����Ϊ��%4.2f\n", bsa);

	float bsv=BallSurfaceVolume();
	printf("Բ������Ϊ��%4.2f\n", bsv);

	float cyv=CylinderVolume();
	printf("Բ�������Ϊ��%4.2f\n", cyv);


	system("pause");
}
