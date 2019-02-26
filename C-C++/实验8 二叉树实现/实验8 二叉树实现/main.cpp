#include <malloc.h>
#include <stdio.h> 
#include <iostream>
#include "BiTree.h"
using namespace std;

//LeafNodes��Ҷ�ӽ��ĸ��� 
int leaves = 0;
int LeafNodes(BTNode *b)
{
	
	if (b != NULL) {
		if (b->lchild == NULL && b->rchild == NULL) {
			leaves++;
		}
		LeafNodes(b->lchild);
		LeafNodes(b->rchild);
	}
	return leaves;
}


int main(int argc, char** argv) {

	BTNode *T;
	char str[] = "A(B(D(,G)),C(E,F))";
	char str1[] = "A(B(D,),C(E(,G),F(H,I)))";

	//******���������**********	
	//����һ�����ű�ʾ��������ݹ� 
	CreateBTNode(T, str);
	printf("������str��");
	DispBTNode(T);
	

	/*���������ո�����ݹ飬��������봮���硰ABD G   CE  F  ��
	CreateBiTree(T);
	printf("��������");
	DispBinTree(T);
	*/
	
	leaves = 0;
	printf("\n������str��Ҷ�ӽ�����Ϊ��%d\n\n", LeafNodes(T));
	

	//******str1****** 
	CreateBTNode(T, str1);
	printf("������str1��");
	DispBTNode(T);
	leaves = 0;
	printf("\nstr1��������Ҷ�ӽ�����Ϊ��%d\n\n", LeafNodes(T));
	//*/
	cout << endl;
	system("pause");
	return 0;
}
