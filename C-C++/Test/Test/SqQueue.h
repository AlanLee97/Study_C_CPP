#include <iostream>
#include<string>
#include <malloc.h>
using namespace std;

typedef string Elemtype;
typedef struct data1
{
	struct data1 *next;
	Elemtype data;
}DataNode;
typedef struct
{
	DataNode *front;
	DataNode *rear;
}LinkQuNode;

void initQueue(LinkQuNode *&q)
{
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
void enQueue(LinkQuNode *&q, Elemtype i)
{
	DataNode *u = (DataNode*)malloc(sizeof(DataNode));
	u->data = i;
	if (q->front = q->rear)
		q->front = q->rear = u;
	else
	{
		q->rear->next = u;
		q->rear = u;
	}
}
Elemtype deQueue(LinkQuNode *q)
{
	DataNode *i = q->front;
	q->front = q->front->next;
	Elemtype m = q->front->data;
	free(i);
	return m;
}
void DisplayQueue(LinkQuNode *q)
{
	DataNode *i = q->front;
	while (i != NULL)
	{
		cout << i->data;
		i = i->next;
	}
}
void DestroyQueue(LinkQuNode *q)
{
	DataNode *i = q->front, *u = q->front->next;
	free(q);
	while (u != NULL)
	{
		free(i);
		i = u;
		u = u->next;
	}
	free(i);
}
