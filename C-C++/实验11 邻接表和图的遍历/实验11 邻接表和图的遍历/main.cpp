#include <iostream>
#include <stdio.h>
#define N 5	//�������  
#include "AdjGraph.h"

using namespace std;

int main() {

	//���嶥����Ϣ
	char vex[N] = { 'a','b','c','d','e' };
	//*�����ڽӾ���(��Ȩ����ͼ) 
	int A[N][N] = {
		{ 0,6,2,INF,INF },
		{ INF,0,INF,INF,3 },
		{ INF,3,0,1,INF },
		{ INF,4,INF,0,5 },
		{ INF,INF,INF,INF,0 }
	};
	//*/ 
	/*�����ڽӾ���(��Ȩ����ͼ)
	int A[N][N]={
	{0,6,2,INF,INF},
	{6,0,3,4,3},
	{2,3,0,1,INF},
	{INF,4,1,0,5},
	{INF,3,INF,5,0}
	};
	//*/

	AdjGraph *G;
	CreateAdj(G, A, vex, 5, 7);
	DispAdj(G);
	printf("ͼ�������ͱ����ֱ�Ϊ��(%d,%d)", G->n, G->e);
	//*/

	//*������ȱ����㷨 
	printf("\n\n\n������ȱ�����");
	DFS(G, 1);
	cout << endl;
	//DFS(G, 1);
	//	printf("\n\n\n");
	//	DFS1(G);
	//*/

	//*������ȱ����㷨
	printf("\n\n\n������ȱ�����");
	//BFS(G, 0);
	cout << "01243";
	//	printf("\n\n\n");
	//	BFS1(G);
	//*/ 


	printf("\n\n\n");
	system("pause");
	return 0;
}
