#pragma once
#include <malloc.h>
#include <stdio.h> 
#include <iostream>

#define MaxSize 50 
using namespace std;

typedef char ElemType;
typedef struct node
{
	ElemType  data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

//***************  构建二叉树  ***************************** 
//****************方法一：括号法表示二叉树****************** 
void CreateBTNode(BTNode *&b, char *str)
{
	BTNode *St[MaxSize], *p;//St数组作为顺序栈
	int top = -1;
	int k, j = 0;	//j用来遍历str
	char ch;
	b = NULL;		//初始时 二叉链为空
	ch = str[j];	//初始时将第一个字符给ch
	while (ch != '\0') {
		switch (ch)
		{
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case  ',':
			k = 2;
			break;
		default:
			p = (BTNode *)malloc(sizeof(BTNode));//创建p结点
			p->data = ch;
			p->lchild = p->rchild = NULL;	//创建结点后将左右子树置为空
			if (b == NULL) {	//若还未创建根结点
				b = p;		//将p作为根结点
			}
			else {
				switch (k)
				{
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				}
			}
			break;
		}
		j++;
		ch = str[j];
	}

}
//******************方法二：先序序列建立二叉链表，需键盘输入串，如“ABD G   CE  F  ”**************** 
bool CreateBiTree(BTNode *&T)
{
	char ch;
	cin >> ch;
	if (ch == ' ') T = NULL;
	else
	{
		if (!(T = (BTNode *)malloc(sizeof(BTNode)))) return false;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return true;
}


//***************  显示二叉树  *****************************
//************方法一：括弧表示，先序，递归显示************** 
void DispBTNode(BTNode *b)
{
	if (b != NULL) {
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL) {	
			cout << "(";	//有左右孩子结点时输出（
			DispBTNode(b->lchild);		//输出左孩子
			if (b->rchild != NULL) {	//若右孩子不为空
				cout << ",";		//输出逗号,
			}
			DispBTNode(b->rchild);		//输出右孩子
			cout << ")";	//输出 ）
		}
	}



}
//****************方法二：以空格表示，先序，递归显示******** 
void DispBinTree(BTNode *T)
{
	if (T != NULL) {
		cout << T->data;
	}


}



