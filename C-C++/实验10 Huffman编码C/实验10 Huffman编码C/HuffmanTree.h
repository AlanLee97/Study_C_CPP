#pragma once
#include <malloc.h>
#include <stdio.h> 
#define N 20 //NҪ����n  

typedef struct
{
	char data;		//�ڵ�ֵ
	int weight;    //Ȩֵ��
	int parent, lchild, rchild;
}HTNode; //Huffman���Ľ������

typedef struct
{
	char cd[N];  //��ŵ�ǰ�ڵ�Ĺ�������
	int start;   //��Ź���������cd�е���ʼλ��
}HCode;	//���������������� 

		/**********************************************************
		* �������ܣ�������������ht�������ж������Ĺ�����������
		* ���������n: Ҷ�ӽ��ĸ���
		* ���������ht: ������Ĺ����������飬ÿ��Ԫ�غ�5����data/weight/parent/lchild/rchild��
		* �� �� ֵ����
		**********************************************************/
void CreateHT(HTNode ht[], int n, int w[])
{
	int i, k, lnode, rnode;
	double min1, min2;
	for (i = 0; i < 2 * n - 1; i++) {
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;	//���н���������ó�ֵΪ-1
		if (i < n){					
			ht[i].weight = w[i];	//��weight��Ȩֵ
		}
		
	}
	//for (i = n; i < (2 * n - 1) - 1 ; i++)   //���鱾���룩�������������n-1����� �������аɣ�
	for (i = n; i < (2 * n - 1) ; i++) {	//�������������n�����  ��������
		min1 = min2 = 32767;
		lnode = rnode = -1;		//lnode �� rnodeΪ��СȨ�ص���������λ��
		for (k = 0; k <= i - 1; k++) {		//��ht[0... i -1 ]����Ȩֵ��С���������
			if (ht[k].parent == -1) {	//ֻ����δ����������Ľ���в���
				if (ht[k].weight < min1) {
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2) {
					min2 = ht[k].weight;
					rnode = k;
				}
			}
			
		}
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
		ht[lnode].parent = i;
		ht[rnode].parent = i;
	}

}

/**********************************************************
* �������ܣ�����������
* ���������n: Ҷ�ӽ��ĸ���
*			ht: ��������
* ���������hcd: �����������������飬ÿ��Ԫ��������(cd/start)
* �� �� ֵ����
**********************************************************/
void CreateHCode(HTNode ht[], HCode hcd[], char a[], int n)		//���� 
{
	int i = 0, f = 0, c = 0;
	HCode hc;
	/*
	int aLength = sizeof(a) / sizeof(char);
	for (int j = 0; j < aLength; j++) {
		hc.cd[j] = a[j];
	}*/


	for (i = 0; i < n; i++) {
		hc.start = n;
		c = i;
		f = ht[i].parent;
		while (f != -1)
		{
			if (ht[f].lchild == c) {
				hc.cd[hc.start--] = '0';
			}
			else
			{
				hc.cd[hc.start--] = '1';
			}
			c = f;
			f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}


}

/***********************************************************************
* �������ܣ����������룺���ɸ�����Code����һ���Ӹ���㵽Ҷ�ӵĹ���
* ���������n: Ҷ�ӽ��ĸ���
*           Code����Ҫ������ַ���
*           ht����������
* ���������DeCode: �������
* �� �� ֵ���ɹ����뷵��true
**********************************************************/
bool EnHCode(char Code[], HTNode ht[], char DeCode[], int n)//CodeҪ����룬DeCode�����������ַ���
{
	int i = 0; //ȡCode��ѭ������ 
	int m = 2 * n - 2;
	int CodeNum = 0;	//���浱ǰ����õ�������� 





	if (m != 2 * n - 2)
		return false;
	DeCode[CodeNum] = '\0';
	return true;
}

