#include <malloc.h>
#include <stdio.h> 
#include <iostream>
#include "BiTree.h" 

using namespace std;

int index = 0;
ElemType node[MaxSize];
void getNodePreOrder(BTNode *b) {
	if (b != NULL) {
		node[index] = b->data;
		index++;
		getNodePreOrder(b->lchild);
		getNodePreOrder(b->rchild);
	}
}

//*
void getNodeInOrder(BTNode *b) {
	if (b != NULL) {
		getNodeInOrder(b->lchild);
		node[index] = b->data;
		index++;
		getNodeInOrder(b->rchild);
	}
}
//*/



///*
void getNodePostOrder(BTNode *b) {

	if (b != NULL) {
		getNodePostOrder(b->lchild);
		getNodePostOrder(b->rchild);
		node[index] = b->data;
		index++;
	}

}//*/


void DispLargeThanC(ElemType e) {
	
	if (e > 'C') {
		cout << e << " ";
	}
	else
	{
		cout << "*" << " ";
	}
}

void DispLessThanD(ElemType e) {
	if (e < 'D') {
		cout << e << " ";
	}
	else
	{
		e = '*';
		cout << e << " ";
	}
}




int main() {

	BTNode *T;
	char str[] = "A(B(D(,G)),C(E,F))";
	CreateBTNode(T,str);
	cout << "��ǰ���ɵĶ�����Ϊ��";
	DispBTNode(T);

	///*
	cout << "\n\n========================�ݹ����������========================" << endl;
	cout << "\n\n����ݹ������������";
	PreOrder(T);
	cout << "\n\n����ݹ������������";
	InOrder(T);
	cout << "\n\n����ݹ������������";
	PostOrder(T);

	cout << "\n\n=======================�ǵݹ����������=======================" << endl;
	cout << "\n\n����ǵݹ������������";
	nonRecurPreOrder(T);
	cout << "\n\n����ǵݹ������������";
	nonRecurInOrder(T);
	cout << "\n\n����ǵݹ������������";
	nonRecurPostOrder(T);
	//*/

	cout << "\n\n=======================�������C�Ľ��=======================";
	cout << endl;
	cout << "����";
	getNodePreOrder(T);
	int nodeLength = sizeof(node) / sizeof(char);
	for (int i = 0; node[i] != '\0'; i++) {
		DispLargeThanC(node[i]);
	}

	///*
	cout << "\n����";
	index = 0;
	getNodeInOrder(T);
	for (int i = 0; node[i] != '\0'; i++) {
		DispLargeThanC(node[i]);
	}

	cout << "\n����";
	index = 0;
	getNodePostOrder(T);
	for (int i = 0; node[i] != '\0'; i++) {
		DispLargeThanC(node[i]);
	}
	//*/




	cout << "\n\n=======================���С��D�Ľ��=======================";
	cout << endl;
	cout << "���������������ж��ٸ��ַ���" << node << endl;
	cout << "����";
	getNodePreOrder(T);
	for (int i = 0; node[i] != '\0'; i++) {
		DispLessThanD(node[i]);
	}

	///*
	cout << "\n����";
	index = 0;
	getNodeInOrder(T);
	for (int i = 0; i < 7; i++) {
		DispLessThanD(node[i]);
	}

	cout << "\n����";
	index = 0;
	getNodePostOrder(T);
	for (int i = 0; i < 7; i++) {
		DispLessThanD(node[i]);
	}
	//*/


	cout << endl;
	system("pause");
	return 0;
}






























/*
//LeafNodes��Ҷ�ӽ��ĸ������ݹ�ʵ�� 
int LeafNodes(BTNode *b)
{
	int num1, num2;
	if (b == NULL)
		return 0;
	else if (b->lchild == NULL && b->rchild == NULL)
		return 1;
	else
	{
		//		num1=LeafNodes(b->lchild);
		//		num2=LeafNodes(b->rchild);
		//		return (num1+num2);

		return  LeafNodes(b->lchild) + LeafNodes(b->rchild);
	}
}
*/

/*
//NonRecurLeafNodes��Ҷ�ӽ��ĸ������ǵݹ�ʵ��
int NonRecurLeafNodes(BTNode *b)
{
	BTNode *p = b;
	int count = 0;

	BTNode *StackTreeNode[MaxSize]; //�ǵݹ飬��ջʵ�� 
	int top = -1;  //ջ��ָ�� 

	while (p != NULL || top != -1)
	{
		if (p)
		{
			//			printf("%c",p->data);
			//�ж�p�Ƿ�ΪҶ�ӽ��
			if (p->lchild == NULL && p->rchild == NULL)
				count++;
			//���������� 
			top++;
			StackTreeNode[top] = p;
			p = p->lchild;
		}
		else
		{
			//��ջ
			p = StackTreeNode[top];  //ȡջ��Ԫ�� 
			top--;
			//����������
			p = p->rchild;
		}
	}
	return count;
}
*/

/*
int main() {

	BTNode *T;
	char str[] = "A(B(D(,G)),C(E,F))";
	char str1[] = "A(B(D,),C(E(,G),F(H,I)))";

	//******���������**********	
	//*����һ�����ű�ʾ��������ݹ� 
	CreateBTNode(T, str);
	printf("������str��");
	DispBTNode(T);
	//*/

	/*���������ո�����ݹ飬��������봮���硰ABD G   CE  F  ��
	CreateBiTree(T);
	printf("��������");
	DispBinTree(T);
	//*/

	//printf("\n������str��Ҷ�ӽ�����Ϊ��%d\n\n", LeafNodes(T));

	/*
	//******str1****** 
	CreateBTNode(T, str1);
	printf("������str1��");
	DispBTNode(T);
	printf("\nstr1��������Ҷ�ӽ�����Ϊ��%d\n\n", LeafNodes(T));
	//*/ 
/*
	return 0;
}
*/