#include <malloc.h>
#include <stdio.h> 
#include <iostream>
#include "BiTree.h"
using namespace std;

//LeafNodes求叶子结点的个数 
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

	//******构造二叉树**********	
	//方法一：括号表示法，先序递归 
	CreateBTNode(T, str);
	printf("二叉树str：");
	DispBTNode(T);
	

	/*方法二：空格，先序递归，需键盘输入串，如“ABD G   CE  F  ”
	CreateBiTree(T);
	printf("二叉树：");
	DispBinTree(T);
	*/
	
	leaves = 0;
	printf("\n二叉树str的叶子结点个数为：%d\n\n", LeafNodes(T));
	

	//******str1****** 
	CreateBTNode(T, str1);
	printf("二叉树str1：");
	DispBTNode(T);
	leaves = 0;
	printf("\nstr1二叉树的叶子结点个数为：%d\n\n", LeafNodes(T));
	//*/
	cout << endl;
	system("pause");
	return 0;
}
