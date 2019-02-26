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
//ͷ�巨
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

//β�巨
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
*���̣���pre �� p ָ�����ڵ������ڵ㣨��ʼʱpreָ��ͷ�ڵ㣬pָ���׽ڵ㣩
*��p��Ϊ��ʱѭ��
*�ͷŽڵ�pre��Ȼ��pre,pͬ��������һ�����
*ѭ��������preָ��β���
*�ͷŵ�pre
*/
void DestoryList(ListNode *&L) {
	ListNode *pre = L, *p = L->next;
	while (p != NULL) {
		free(pre);		//�ͷŽڵ�pre
		pre = p;		//pre������һ�����
		p = pre->next;		//pͬ��������һ�����
	}
	free(pre);
}

bool ListEmpty(ListNode *L) {
	return(L->next == NULL);
}

void DispList(ListNode *L) {
	ListNode *p = L->next;		//pָ���׽ڵ�
	while (p != NULL) {
		cout << p->data << " ";		//���pָ���������
		p = p->next;		//pָ����һ���ڵ�
	}
	cout << "\n";
}

int ListLength(ListNode *L) {
	int counter_Node = 0;		//����ͳ�ƽڵ�ĸ���
	ListNode *p = L;		//ָ��pָ��ͷ�ڵ�L
	while (p != NULL) {
		counter_Node++;
		p = p->next;		//pָ����һ���ڵ�
	}
	return counter_Node;
}


bool GetElem(ListNode *L, int i, ElemType &e) {
	int counter_Node = 0;		//����ͳ�Ʊ������Ľڵ�ĸ���
	ListNode *p = L;
	if (i <= 0) return false;		//�ж�Ҫ��ȡ��Ԫ���Ƿ��ڷ�Χ��
	while (counter_Node < i && p != NULL) {
		counter_Node++;
		p = p->next;		//pָ����һ���ڵ�
	}
	if (p == NULL) return false;
	else {
		e = p->data;		//��pָ����������e
		return true;
	}
}

/*
*�ڵ�����L�д�ͷ��ʼ�ҵ�һ��������e��ȵĽڵ㣬�����ڣ��򷵻��߼���ţ�
*���򷵻�0
*/
int LocateElem(ListNode *L, ElemType e) {
	int i = 1;		//���ڱ�ʾ�׽ڵ�����
	ListNode *p = L->next;		//ָ��pָ���׽ڵ�
	while (p != NULL && p->data != e) {		//��ָ��p��Ϊ�պ�p��������Ϊ�յ�ʱ��ѭ��
		p = p->next;		//pָ����һ���ڵ�
		i++;
	}
	if (p == NULL) return 0;
	else return i;
}

bool ListInsert(ListNode *&L, int i, ElemType e) {
	int j = 0;		//���ڱ�ʾͷ����λ��
	ListNode *p = L, *s;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;		//p�ڵ������һλ
	}
	if (p == NULL) return false;
	else {
		s = (ListNode *)malloc(sizeof(ListNode));
		s->data = e;		//��Ҫ����Ľڵ�e�ķŵ�sָ�����������
		s->next = p->next;
		p->next = s;
		return true;
	}

}

bool ListDelete(ListNode *&L, int i, ElemType e) {
	int j = 0;		//��¼ͷ�ڵ�
	ListNode *p = L, *q;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL) {		//���ҵ�i-1���ڵ�
		j++;
		p = p->next;
	}
	if (p == NULL) return false;
	else {
		q = p->next;		//qָ���i���ڵ�
		if (q == NULL) {
			return false;
		}
		e = q->data;		//��Ҫɾ�������ݷŵ�e�У�����������;�����������
		p->next = q->next;		//pָ��ָ�����¸��ڵ�
		free(q);
		return true;
	}

}


/*
*ListElem��ʾLA�е�Ԫ��
*judgeElem��ʾ��ȡ��LB�е�Ԫ��
*/
//�ж�jugdeElem�Ƿ����L�е�ÿ��ListElemԪ����ͬ
//��ͬ����true   ���򷵻�false
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

