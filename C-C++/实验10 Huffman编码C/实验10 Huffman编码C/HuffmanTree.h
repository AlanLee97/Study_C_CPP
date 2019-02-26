#pragma once
#include <malloc.h>
#include <stdio.h> 
#define N 20 //N要大于n  

typedef struct
{
	char data;		//节点值
	int weight;    //权值域
	int parent, lchild, rchild;
}HTNode; //Huffman树的结点类型

typedef struct
{
	char cd[N];  //存放当前节点的哈夫曼码
	int start;   //存放哈夫曼码在cd中的起始位置
}HCode;	//哈夫曼编码结点类型 

		/**********************************************************
		* 函数功能：构建哈夫曼树ht：按最有二叉树的构建方法构建
		* 输入参数：n: 叶子结点的个数
		* 输出参数：ht: 建立起的哈夫曼树数组，每个元素含5个域（data/weight/parent/lchild/rchild）
		* 返 回 值：无
		**********************************************************/
void CreateHT(HTNode ht[], int n, int w[])
{
	int i, k, lnode, rnode;
	double min1, min2;
	for (i = 0; i < 2 * n - 1; i++) {
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;	//所有结点的相关域置初值为-1
		if (i < n){					
			ht[i].weight = w[i];	//给weight赋权值
		}
		
	}
	//for (i = n; i < (2 * n - 1) - 1 ; i++)   //（书本代码）构造哈夫曼树的n-1个结点 这样不行吧？
	for (i = n; i < (2 * n - 1) ; i++) {	//构造哈夫曼树的n个结点  这样就行
		min1 = min2 = 32767;
		lnode = rnode = -1;		//lnode 和 rnode为最小权重的两个结点的位置
		for (k = 0; k <= i - 1; k++) {		//在ht[0... i -1 ]中找权值最小的两个结点
			if (ht[k].parent == -1) {	//只在尚未构造二叉树的结点中查找
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
* 函数功能：哈夫曼编码
* 输入参数：n: 叶子结点的个数
*			ht: 哈夫曼树
* 输出参数：hcd: 保存哈夫曼编码的数组，每个元素两个域(cd/start)
* 返 回 值：无
**********************************************************/
void CreateHCode(HTNode ht[], HCode hcd[], char a[], int n)		//编码 
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
* 函数功能：哈夫曼译码：按由给定的Code走了一条从根结点到叶子的过程
* 输入参数：n: 叶子结点的个数
*           Code：需要译码的字符串
*           ht：哈夫曼树
* 输出参数：DeCode: 译码输出
* 返 回 值：成功译码返回true
**********************************************************/
bool EnHCode(char Code[], HTNode ht[], char DeCode[], int n)//Code要译的码，DeCode保存译码后的字符串
{
	int i = 0; //取Code的循环变量 
	int m = 2 * n - 2;
	int CodeNum = 0;	//保存当前已译好的码的数量 





	if (m != 2 * n - 2)
		return false;
	DeCode[CodeNum] = '\0';
	return true;
}

