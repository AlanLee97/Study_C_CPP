#include <malloc.h>
#include <stdio.h> 
#include <iostream>
//#include "SqStack.h"

#define MaxSize 50 
using namespace std;

typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
	bool rightSubTreeVisited;		//非递归后序遍历时用 
}BTNode;

///*
typedef struct {
	int top;
	BTNode * data[MaxSize];
}SqStack;



void InitStack(SqStack *&s) {
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}

bool Push(SqStack *&s, BTNode *b) {
	if (s->top == MaxSize - 1) {
		return false;
	}
	else {
		s->top++;
		s->data[s->top] = b;
		return true;
	}
}

bool Pop(SqStack *&s, BTNode *&b) {
	if (s->top == -1) {
		return false;
	}
	else {
		b = s->data[s->top];
		s->top--;
		return true;
	}
}

bool SqStackEmpty(SqStack *s) {
	return s->top == -1;
}

bool GetTop(SqStack *s, BTNode *&b) {
	if (s->top == -1) return false;
	b = s->data[s->top];
	s->top--;
	return true;
}
//*/
int SqStackLength(SqStack *&s) {
	return s->top - 1;
}


//***************  构建二叉树  ***************************** 
//****************方法一：括号法表示二叉树****************** 
void CreateBTNode(BTNode *&b, char *str)
{
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//建立的二叉树初始时为空
	ch = str[j];
	while (ch != '\0')   //str未扫描完时循环
	{
		switch (ch)
		{
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;	   //为左孩子节点
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;     //为孩子节点右节点
		default:
			p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)    	//p为二叉树的根节点
				b = p;
			else    		//已建立二叉树根节点
			{
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
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTNode(b->lchild);//递归处理左子树
			if (b->rchild != NULL)
				printf(",");
			DispBTNode(b->rchild);//递归处理右子树
			printf(")");
		}
	}
}
//****************方法二：以空格表示，先序，递归显示******** 
void DispBinTree(BTNode *T)
{
	if (T == NULL) printf(" ");
	else
	{
		printf("%c", T->data);
		DispBinTree(T->lchild);
		DispBinTree(T->rchild);
	}
}

void Visit(BTNode *b) {
	cout << b->data << " ";
}








//****************递归遍历**************** 
//先序遍历 ,BTNode (*Visit)(ElemType e)
void PreOrder(BTNode *b) {
	if (b != NULL) {
		cout << b->data << " ";
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

//中序遍历 
void InOrder(BTNode *b) {
	if (b != NULL) {
		InOrder(b->lchild);
		cout << b->data << " ";
		InOrder(b->rchild);
	}
}

//后序遍历 
void PostOrder(BTNode *b) {
	if (b != NULL) {
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		cout << b->data << " ";
	}
}









void PreOrderTraverse() {

}

void InOrderTraverse() {

}

void PostOrderTraverse() {

}








//****************非递归遍历**************** 
//先序非递归遍历
void nonRecurPreOrder(BTNode *b) {
	SqStack *St;
	InitStack(St);
	BTNode *p = b;

	while (p || !SqStackEmpty(St)) {
		if (p) {
			cout << p->data << " ";
			Push(St, p);
			p = p->lchild;
		}
		else {
			Pop(St,p);
			p = p->rchild;
		}
	}
}

//中序非递归遍历
void nonRecurInOrder(BTNode *b) {
	SqStack *St;
	InitStack(St);
	BTNode *p = b;

	while (p || !SqStackEmpty(St)) {
		if (p) {

			Push(St, p);
			p = p->lchild;
		}
		else {
			Pop(St, p);
			cout << p->data << " ";
			p = p->rchild;
		}
	}
}

//后序非递归遍历
///*
bool nonRecurPostOrder(BTNode *b) {
	SqStack *St;
	InitStack(St);
	BTNode *p = b;
	
	while (p || !SqStackEmpty(St)) {
		while (p) {
			
			Push(St, p);
			p = p->lchild;
		}
		
		Pop(St, p);
		while (p->rightSubTreeVisited == true) {
			cout << p->data << " ";
			if (!SqStackEmpty(St)) {
				Pop(St, p);
			}
			else {
				return true;
			}
		} 
		p->rightSubTreeVisited = true;
		Push(St, p);
		p = p->rchild;
	}
}
//*/

