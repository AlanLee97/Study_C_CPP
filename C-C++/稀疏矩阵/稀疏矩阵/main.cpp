#include <iostream>
#include "sqMatrix.h"
using namespace std;


int main()
{
	ElemType a[8][8] = { 
		{ 0,0,-3,0,0,0,0,0 },
		{ 0,0,0,0,0,0,37,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,24,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,15,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,88,0 },
		{ 0,0,0,0,0,0,0,0 },
	};
	TSMatrix MM;
	createMatrix(MM, a);
	printf("初始矩阵为：\n");
	DispMatrix(MM);
	printf("矩阵的三元组顺序表为：\n");
	DispTupMat(MM);

	printf("\n\n");



	TSMatrix T;
	//TranTat(MM, T);
	FastTransMatrix(MM,T); 
	printf("转置后矩阵为：\n");
	DispMatrix(T);
	printf("\n转置后的三元组顺序表为：\n");
	DispTupMat(T);


	system("pause");
	return 0;
}