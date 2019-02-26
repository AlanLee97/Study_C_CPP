//ListNode.h
#include<iostream>
#include<malloc.h>
using namespace std;

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}ListNode;








/*
//头插法
void CreateListF(ListNode *&L, ElemType a[], int n) {
ListNode *s;
L = (ListNode *)malloc(sizeof(ListNode));
L->next = NULL;
for (int i = 0; i < n; i++) {
s = (ListNode *)malloc(sizeof(ListNode));
s->data = a[i];
s->next = L->next;
L->next = s;
}
}
*/

//尾插法
void CreateListR(ListNode *&L, ElemType a[], int n) {
	ListNode *r, *s;
	L = (ListNode *)malloc(sizeof(ListNode));
	r = L;
	for (int i = 0; i < n; i++) {
		s = (ListNode*)malloc(sizeof(ListNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}



void InitList(ListNode *&L) {
	L = (ListNode *)malloc(sizeof(ListNode));
	L->next = NULL;
}

/*
*过程：让pre 和 p 指向相邻的两个节点（初始时pre指向头节点，p指向首节点）
*当p不为空时循环
*释放节点pre，然后pre,p同步往后移一个结点
*循环结束后pre指向尾结点
*释放掉pre
*/
void DestoryList(ListNode *&L) {
	ListNode *pre = L, *p = L->next;
	while (p != NULL) {
		free(pre);		//释放节点pre
		pre = p;		//pre往后移一个结点
		p = pre->next;		//p同步往后移一个结点
	}
	free(pre);
}

bool ListEmpty(ListNode *L) {
	return(L->next == NULL);
}

void DispList(ListNode *L) {
	ListNode *p = L->next;		//p指向首节点
	while (p != NULL) {
		cout << p->data << " ";		//输出p指向的数据域
		p = p->next;		//p指向下一个节点
	}
	cout << "\n";
}

int ListLength(ListNode *L) {
	int counter_Node = 0;		//用来统计节点的个数
	ListNode *p = L;		//指针p指向头节点L
	while (p != NULL) {
		counter_Node++;
		p = p->next;		//p指向下一个节点
	}
	return counter_Node;
}


bool GetElem(ListNode *L, int i, ElemType &e) {
	int counter_Node = 0;		//用来统计遍历过的节点的个数
	ListNode *p = L;
	if (i <= 0) return false;		//判断要获取的元素是否在范围内
	while (counter_Node < i && p != NULL) {
		counter_Node++;
		p = p->next;		//p指向下一个节点
	}
	if (p == NULL) return false;
	else {
		e = p->data;		//把p指向的数据域给e
		return true;
	}
}

/*
*在单链表L中从头开始找第一个至于与e相等的节点，若存在，则返回逻辑序号，
*否则返回0
*/
int LocateElem(ListNode *L, ElemType e) {
	int i = 1;		//用于表示首节点的序号
	ListNode *p = L->next;		//指针p指向首节点
	while (p != NULL && p->data != e) {		//当指针p不为空和p的数据域不为空的时候循环
		p = p->next;		//p指向下一个节点
		i++;
	}
	if (p == NULL) return 0;
	else return i;
}

bool ListInsert(ListNode *&L, int i, ElemType e) {
	int j = 0;		//用于表示头结点的位置
	ListNode *p = L, *s;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;		//p节点向后移一位
	}
	if (p == NULL) return false;
	else {
		s = (ListNode *)malloc(sizeof(ListNode));
		s->data = e;		//把要插入的节点e的放到s指向的数据域里
		s->next = p->next;
		p->next = s;
		return true;
	}

}

bool ListDelete(ListNode *&L, int i, ElemType e) {
	int j = 0;		//记录头节点
	ListNode *p = L, *q;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL) {		//查找第i-1个节点
		j++;
		p = p->next;
	}
	if (p == NULL) return false;
	else {
		q = p->next;		//q指向第i个节点
		if (q == NULL) {
			return false;
		}
		e = q->data;		//将要删除的数据放到e中，待作其他用途，例如输出它
		p->next = q->next;		//p指针指向下下个节点
		free(q);
		return true;
	}

}


/*
*ListElem表示LA中的元素
*judgeElem表示获取到LB中的元素
*/
//判断jugdeElem是否与表L中的每个ListElem元素相同
//相同返回true   否则返回false
bool isEqual(ListNode *L, int ListElem, int judgeElem) {

	for (int i = 0; i < ListLength(L); i++) {
		GetElem(L, i, ListElem);
		if (judgeElem == ListElem) {
			return true;
		}
	}
	return false;
}



void ListReverse(ListNode *&L) {
	ListNode *temp;
	for (int i = ListLength(L) - 1, j = 0; i >= ListLength(L) / 2; i--,j++) {
		

	}
}

