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
	bool rightSubTreeVisited;		//�ǵݹ�������ʱ�� 
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


//***************  ����������  ***************************** 
//****************����һ�����ŷ���ʾ������****************** 
void CreateBTNode(BTNode *&b, char *str)
{
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//�����Ķ�������ʼʱΪ��
	ch = str[j];
	while (ch != '\0')   //strδɨ����ʱѭ��
	{
		switch (ch)
		{
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;	   //Ϊ���ӽڵ�
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;     //Ϊ���ӽڵ��ҽڵ�
		default:
			p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)    	//pΪ�������ĸ��ڵ�
				b = p;
			else    		//�ѽ������������ڵ�
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
//******************���������������н�������������������봮���硰ABD G   CE  F  ��**************** 
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


//***************  ��ʾ������  *****************************
//************����һ��������ʾ�����򣬵ݹ���ʾ************** 
void DispBTNode(BTNode *b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTNode(b->lchild);//�ݹ鴦��������
			if (b->rchild != NULL)
				printf(",");
			DispBTNode(b->rchild);//�ݹ鴦��������
			printf(")");
		}
	}
}
//****************���������Կո��ʾ�����򣬵ݹ���ʾ******** 
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








//****************�ݹ����**************** 
//������� ,BTNode (*Visit)(ElemType e)
void PreOrder(BTNode *b) {
	if (b != NULL) {
		cout << b->data << " ";
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

//������� 
void InOrder(BTNode *b) {
	if (b != NULL) {
		InOrder(b->lchild);
		cout << b->data << " ";
		InOrder(b->rchild);
	}
}

//������� 
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








//****************�ǵݹ����**************** 
//����ǵݹ����
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

//����ǵݹ����
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

//����ǵݹ����
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

