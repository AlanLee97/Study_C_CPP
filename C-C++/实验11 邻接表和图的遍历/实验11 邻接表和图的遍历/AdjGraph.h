#pragma once
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "LinkQueue.h"
#define INF 32767	//INF表示∞
#define MAXV  20  // 最大顶点个数
using namespace std;

typedef char InfoType;

//邻接表 边节点类型
typedef struct ANode
{
	int adjvex;		//该边的邻接点编号
	struct ANode *nextarc;		//下一条边的指针
	int weight;		//边的相关信息
}ArcNode;

//邻接表 头节点类型
typedef struct VNode
{
	InfoType info;		//顶点信息
	ArcNode *firstarc;		//指向第一条边
}VNode;

//图邻接表类型
typedef struct
{
	VNode adjlist[MAXV];		//邻接表的头结点数组
	int n, e;		//n为顶点数、e为边数
}AdjGraph;

void CreateAdj(AdjGraph *&G, int A[N][N], char V[N], int n, int e)	//n为顶点数、e为边数
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

//----------------------------------深度遍历 
//(强)连通图深度优先遍历（Deepth First Search）算法 

int visited[MAXV] = { 0 };      //全局数组，初始时所有元素为0，表示尚未访问过
void DFS(AdjGraph *G, int v)	//v是初始点
{
	ArcNode *p;
	visited[v] = 1;  //置为1，表示已访问
	cout << v;		//输出被访问的顶点的编号
	p = G->adjlist[v].firstarc;	//p指向顶点v的第一个邻接点
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0) {	//若p->adjvex的顶点未被访问，就递归访问它
			DFS(G, p->adjvex);
		}
		p = p->nextarc;		//p指向顶点v的下一个邻接点
	}
}

/*/非(强)连通图的深度优先遍历算法
void DFS1(AdjGraph *G)
{


}
*/
//----------------------------------广度遍历
//(强)连通图的广度优先遍历（Breadth First Search）算法 

void BFS(AdjGraph *G, int v)
{
	int w, i;
	ArcNode *p;
	LiQueue *qu;
	InitQueue(qu);
	visited[v] = 1;
	printf("%d", v); //输出v编码和顶点信息
	enQueue(qu, v);
	while (!QueueEmpty(qu))   //只要队列不为空 
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

/*/非(强)连通图的广度优先遍历算法 
void BFS1(AdjGraph *G)
{



}

*/

