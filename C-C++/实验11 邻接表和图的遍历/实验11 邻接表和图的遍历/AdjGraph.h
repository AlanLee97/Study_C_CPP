#pragma once
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "LinkQueue.h"
#define INF 32767	//INF��ʾ��
#define MAXV  20  // ��󶥵����
using namespace std;

typedef char InfoType;

//�ڽӱ� �߽ڵ�����
typedef struct ANode
{
	int adjvex;		//�ñߵ��ڽӵ���
	struct ANode *nextarc;		//��һ���ߵ�ָ��
	int weight;		//�ߵ������Ϣ
}ArcNode;

//�ڽӱ� ͷ�ڵ�����
typedef struct VNode
{
	InfoType info;		//������Ϣ
	ArcNode *firstarc;		//ָ���һ����
}VNode;

//ͼ�ڽӱ�����
typedef struct
{
	VNode adjlist[MAXV];		//�ڽӱ��ͷ�������
	int n, e;		//nΪ��������eΪ����
}AdjGraph;

void CreateAdj(AdjGraph *&G, int A[N][N], char V[N], int n, int e)	//nΪ��������eΪ����
{
	int i, j;
	ArcNode *p;
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++) {
		G->adjlist[i].firstarc = NULL;
	}

	for (i = 0; i < n; i++) {
		for (j = n - 1; j >= 0; j--) {
			if (A[i][j] != 0 && A[i][j] != INF) {
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->n = n;
	G->e = e;
}

void DispAdj(AdjGraph *G)
{
	int i;
	ArcNode *p;
	for (i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		cout << setw(3) << i;
		while (p != NULL) {
			cout << setw(3) << p->adjvex << "[" << p->weight << "]->";
			p = p->nextarc;
		}
		cout << "^\n";
	}
}

//----------------------------------��ȱ��� 
//(ǿ)��ͨͼ������ȱ�����Deepth First Search���㷨 

int visited[MAXV] = { 0 };      //ȫ�����飬��ʼʱ����Ԫ��Ϊ0����ʾ��δ���ʹ�
void DFS(AdjGraph *G, int v)	//v�ǳ�ʼ��
{
	ArcNode *p;
	visited[v] = 1;  //��Ϊ1����ʾ�ѷ���
	cout << v;		//��������ʵĶ���ı��
	p = G->adjlist[v].firstarc;	//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0) {	//��p->adjvex�Ķ���δ�����ʣ��͵ݹ������
			DFS(G, p->adjvex);
		}
		p = p->nextarc;		//pָ�򶥵�v����һ���ڽӵ�
	}
}

/*/��(ǿ)��ͨͼ��������ȱ����㷨
void DFS1(AdjGraph *G)
{


}
*/
//----------------------------------��ȱ���
//(ǿ)��ͨͼ�Ĺ�����ȱ�����Breadth First Search���㷨 

void BFS(AdjGraph *G, int v)
{
	int w, i;
	ArcNode *p;
	LiQueue *qu;
	InitQueue(qu);
	visited[v] = 1;
	printf("%d", v); //���v����Ͷ�����Ϣ
	enQueue(qu, v);
	while (!QueueEmpty(qu))   //ֻҪ���в�Ϊ�� 
	{
		deQueue(qu, w);
		p = G->adjlist[w].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("%d", p->adjvex);
				visited[p->adjvex] = 1;
				enQueue(qu, p->adjvex);
			}
			p = p->nextarc;
		}
	}
}

/*/��(ǿ)��ͨͼ�Ĺ�����ȱ����㷨 
void BFS1(AdjGraph *G)
{



}

*/

