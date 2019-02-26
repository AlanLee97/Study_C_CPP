#include<stdio.h>
#define pi 3.14159
//求圆周长、圆面积、圆球表面积、圆球体积、圆柱体积
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
	printf("圆的周长为：%4.2f\n", l);


	float s=CircleArea();
	printf("圆的面积为：%4.2f\n", s);

	float bsa=BallSurfaceArea();
	printf("圆球的表面积为：%4.2f\n", bsa);

	float bsv=BallSurfaceVolume();
	printf("圆球的体积为：%4.2f\n", bsv);

	float cyv=CylinderVolume();
	printf("圆柱的体积为：%4.2f\n", cyv);


	system("pause");
}
