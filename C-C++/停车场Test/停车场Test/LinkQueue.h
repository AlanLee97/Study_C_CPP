#pragma once
#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
typedef int ElemType1;
typedef struct qnode
{
	ElemType1 data;
	struct qnode*next;
}DataNode;
typedef struct {
	DataNode *front;
	DataNode *rear;
}LinkQuNode;
void InitQueue(LinkQuNode *&q)
{
	q = (LinkQuNode *)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
void DestroyQueue(LinkQuNode *&q)
{
	DataNode *pre = q->front, *p;
	if (pre != NULL)
	{
		p = pre->next;
		while (p != NULL)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(q);
}
bool QueueEmpty(LinkQuNode *q)
{
	return(q->rear == NULL);
}
void EnQueue(LinkQuNode *&q, ElemType1 e)
{
	DataNode *p;
	p = (DataNode *)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}
bool DeQueue(LinkQuNode *&q, ElemType1 &e)
{
	DataNode *t;
	if (q->rear == NULL)
		return false;
	t = q->front;
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}
int QueueLength(LinkQuNode *q)
{
	int length = 0;
	if (QueueEmpty(q))
		return length;
	else if (!QueueEmpty(q))
	{
		DataNode *p;
		p = q->front;
		while (p) {
			length++;
			p = p->next;
		}
		return length;
	}
}
void DispQueue(LinkQuNode *q)
{
	DataNode *t = q->front;
	while (t != NULL)
	{
		printf("³µÅÆºÅ£º%d\n", t->data);
		t = t->next;

	}
}