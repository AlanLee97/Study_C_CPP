#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#define R 8
#define C 8
#define Maxsize 100
using namespace std;

typedef int ElemType;
typedef struct {
	int r;		//�к�
	int c;		//�к�
	ElemType d;		//Ԫ��ֵ
}TupNode;

typedef struct {
	int rows;		//����
	int cols;		//����
	int nums;		//����Ԫ�ظ���
	TupNode data[Maxsize];	//�����Ԫ�������
}TSMatrix;




void createMatrix(TSMatrix &t, ElemType A[R][C]) {
	int i, j;
	t.rows = R;
	t.cols = C;
	t.nums = 0;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (A[i][j] != 0) {
				t.data[t.nums].r = i;
				t.data[t.nums].c = j;
				t.data[t.nums].d = A[i][j];
				t.nums++;
			}
		}
	}
}

/*
bool Value(TSMatrix &t, ElemType x, int i, int j) {
	int k = 0;
	int k1;
	if (i >= t.rows || j >= t.cols) return false;
	while (k < t.nums && i > t.data[k].r) k++;
	while (k < t.nums && i == t.data[k].r && j > t.data[k].c)
		k++;
	if (t.data[k].r == i && t.data[k].c == j)
		t.data[k].d = x;
	else
	{
		for (k1 = t.nums - 1; k1 >= k; k1--) {
			t.data[k1 + 1].r = t.data[k1].r;
			t.data[k1 + 1].c = t.data[k1].c;
			t.data[k1 + 1].d = t.data[k1].d;
		}
		t.data[k].r = i;
		t.data[k].c = j;
		t.data[k].d = x;
		t.nums++;
	}
	return true;
}


bool Assign(TSMatrix t, ElemType &x, int i, int j) {
	int k = 0;
	if (i >= t.rows || j >= t.cols) {
		return false;
	}
	while (k < t.nums && i > t.data[k].r) k++;
	while (k < t.nums && i == t.data[k].c == j) {
		k++;
	}
	if (t.data[k].r == i && t.data[k].c == j)
		x = t.data[k].d;
	else {
		x = 0;
	}
	return true;
}
*/

void DispMatrix(TSMatrix TM)		//������� 
{
	int row = TM.rows;
	int col = TM.cols;
	int num = TM.nums;

	bool flag = true;
	int z = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0;j < col; j++)
		{
			for (int z = 0;z < num; z++)
			{
				if (TM.data[z].r == i && TM.data[z].c == j)
				{
					cout << setw(4) << TM.data[z].d;
					flag = false;
				}
			}
			if (flag == true)
			{
				printf("%4d", 0);
			}
			else
			{
				flag = true;
			}
		}
		printf("\n");
	}
}

void DispTupMat(TSMatrix t)    //�����Ԫ��
{
	int i;
	if (t.nums <= 0) return;
	cout << "\t" << t.rows
		<< "\t" << t.cols
		<< "\t" << t.nums << endl;
	
	cout << "\n----------------------------\n";
	for (i = 0;i < t.nums; i++)
		cout << "\t" << t.data[i].r
		<< "\t" << t.data[i].c
		<< "\t" << t.data[i].d << endl;
}

void TranTat(TSMatrix t, TSMatrix &tb)	//ת��  ת�ú�ŵ�tb������
{
	int i = 0, tbElemNum = 0, valueNum = 0;		//valueNum
	tb.rows = t.cols;
	tb.cols = t.rows;
	tb.nums = t.nums;

	if (t.nums != 0) {
		for (valueNum = 0; valueNum < t.cols; valueNum++) {
			for (i = 0; i < t.nums; i++) {
				if (t.data[i].c == valueNum) {
					tb.data[tbElemNum].r = t.data[i].c;
					tb.data[tbElemNum].c = t.data[i].r;
					tb.data[tbElemNum].d = t.data[i].d;
					tbElemNum++;
				}
			}
		}
	}




}


//����ת���㷨�������A��ÿһ�еķ�0Ԫ�ظ���
//����������������num[ ]��cpot[ ] ��
//num[col]��ͳ��A�е�col���з�0Ԫ�صĸ�����
//cpot[col]��ָʾA�е�һ����0Ԫ����b.data�е�ǡ��λ�á�
//cpot[1]=0
//cpot[col]=cpot[col-1]+num[col-1]       2�Qcol�QA.cols
void  FastTransMatrix(TSMatrix a, TSMatrix &b)
{
	b.rows = a.cols;
	b.cols = a.rows;
	b.nums = a.nums;
	if (b.nums)
	{
		int col;
		int num[1000], cpot[1000];
		for (col = 1; col <= a.cols; ++col)
			num[col] = 0;                 //num����ĳ�ʼ��  
		for (int t = 1; t <= a.nums; ++t)
			++num[a.data[t].c];         //��M��ÿһ�к��еķ���Ԫ����  
		cpot[1] = 1;
		for (col = 2; col <= a.cols; ++col)
			cpot[col] = cpot[col - 1] + num[col - 1]; //��cpot����  
		int q;
		for (int p = 1; p <= a.nums; ++p)
		{
			col = a.data[p].c;
			q = cpot[col];
			b.data[q].r = a.data[p].c;
			b.data[q].c = a.data[p].r;
			b.data[q].d = a.data[p].d;
			++cpot[col];
		}
	} 
}


