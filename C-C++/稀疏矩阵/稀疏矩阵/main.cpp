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
	printf("��ʼ����Ϊ��\n");
	DispMatrix(MM);
	printf("�������Ԫ��˳���Ϊ��\n");
	DispTupMat(MM);

	printf("\n\n");



	TSMatrix T;
	//TranTat(MM, T);
	FastTransMatrix(MM,T); 
	printf("ת�ú����Ϊ��\n");
	DispMatrix(T);
	printf("\nת�ú����Ԫ��˳���Ϊ��\n");
	DispTupMat(T);


	system("pause");
	return 0;
}