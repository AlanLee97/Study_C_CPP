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

//***************  ����������  ***************************** 
//****************����һ�����ŷ���ʾ������****************** 
void CreateBTNode(BTNode *&b, char *str)
{
	BTNode *St[MaxSize], *p;//St������Ϊ˳��ջ
	int top = -1;
	int k, j = 0;	//j��������str
	char ch;
	b = NULL;		//��ʼʱ ������Ϊ��
	ch = str[j];	//��ʼʱ����һ���ַ���ch
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
			p = (BTNode *)malloc(sizeof(BTNode));//����p���
			p->data = ch;
			p->lchild = p->rchild = NULL;	//������������������Ϊ��
			if (b == NULL) {	//����δ���������
				b = p;		//��p��Ϊ�����
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
	if (b != NULL) {
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL) {	
			cout << "(";	//�����Һ��ӽ��ʱ�����
			DispBTNode(b->lchild);		//�������
			if (b->rchild != NULL) {	//���Һ��Ӳ�Ϊ��
				cout << ",";		//�������,
			}
			DispBTNode(b->rchild);		//����Һ���
			cout << ")";	//��� ��
		}
	}



}
//****************���������Կո��ʾ�����򣬵ݹ���ʾ******** 
void DispBinTree(BTNode *T)
{
	if (T != NULL) {
		cout << T->data;
	}


}



