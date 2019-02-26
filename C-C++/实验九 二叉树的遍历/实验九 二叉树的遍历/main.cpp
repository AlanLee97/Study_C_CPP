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
	cout << "当前生成的二叉树为：";
	DispBTNode(T);

	///*
	cout << "\n\n========================递归遍历二叉树========================" << endl;
	cout << "\n\n先序递归遍历二叉树：";
	PreOrder(T);
	cout << "\n\n中序递归遍历二叉树：";
	InOrder(T);
	cout << "\n\n后序递归遍历二叉树：";
	PostOrder(T);

	cout << "\n\n=======================非递归遍历二叉树=======================" << endl;
	cout << "\n\n先序非递归遍历二叉树：";
	nonRecurPreOrder(T);
	cout << "\n\n中序非递归遍历二叉树：";
	nonRecurInOrder(T);
	cout << "\n\n后序非递归遍历二叉树：";
	nonRecurPostOrder(T);
	//*/

	cout << "\n\n=======================输出大于C的结点=======================";
	cout << endl;
	cout << "先序：";
	getNodePreOrder(T);
	int nodeLength = sizeof(node) / sizeof(char);
	for (int i = 0; node[i] != '\0'; i++) {
		DispLargeThanC(node[i]);
	}

	///*
	cout << "\n中序：";
	index = 0;
	getNodeInOrder(T);
	for (int i = 0; node[i] != '\0'; i++) {
		DispLargeThanC(node[i]);
	}

	cout << "\n后序：";
	index = 0;
	getNodePostOrder(T);
	for (int i = 0; node[i] != '\0'; i++) {
		DispLargeThanC(node[i]);
	}
	//*/




	cout << "\n\n=======================输出小于D的结点=======================";
	cout << endl;
	cout << "看看现在数组里有多少个字符：" << node << endl;
	cout << "先序：";
	getNodePreOrder(T);
	for (int i = 0; node[i] != '\0'; i++) {
		DispLessThanD(node[i]);
	}

	///*
	cout << "\n中序：";
	index = 0;
	getNodeInOrder(T);
	for (int i = 0; i < 7; i++) {
		DispLessThanD(node[i]);
	}

	cout << "\n后序：";
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
//LeafNodes求叶子结点的个数，递归实现 
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
//NonRecurLeafNodes求叶子结点的个数，非递归实现
int NonRecurLeafNodes(BTNode *b)
{
	BTNode *p = b;
	int count = 0;

	BTNode *StackTreeNode[MaxSize]; //非递归，用栈实现 
	int top = -1;  //栈顶指针 

	while (p != NULL || top != -1)
	{
		if (p)
		{
			//			printf("%c",p->data);
			//判断p是否为叶子结点
			if (p->lchild == NULL && p->rchild == NULL)
				count++;
			//进入左子树 
			top++;
			StackTreeNode[top] = p;
			p = p->lchild;
		}
		else
		{
			//出栈
			p = StackTreeNode[top];  //取栈顶元素 
			top--;
			//进入右子树
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

	//******构造二叉树**********	
	//*方法一：括号表示法，先序递归 
	CreateBTNode(T, str);
	printf("二叉树str：");
	DispBTNode(T);
	//*/

	/*方法二：空格，先序递归，需键盘输入串，如“ABD G   CE  F  ”
	CreateBiTree(T);
	printf("二叉树：");
	DispBinTree(T);
	//*/

	//printf("\n二叉树str的叶子结点个数为：%d\n\n", LeafNodes(T));

	/*
	//******str1****** 
	CreateBTNode(T, str1);
	printf("二叉树str1：");
	DispBTNode(T);
	printf("\nstr1二叉树的叶子结点个数为：%d\n\n", LeafNodes(T));
	//*/ 
/*
	return 0;
}
*/