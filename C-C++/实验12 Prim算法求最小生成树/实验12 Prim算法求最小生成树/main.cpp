#include <iostream>
#include "MGraph.h"
#include "Prim_MiniSpanTree.h"
using namespace std;


int main()
{
	InfoType v[] = { 'A','B','C','D','E' };//顶点信息
	int A[5][5] = {
		{   0,   8, INF,   4, INF},
		{   8,   0,   7,   5,  12},
		{ INF,   7,   0,  11,   6},
		{   4,   5,  11,   0,   3},
		{ INF,  12,   6,   3,   0}
	};//初始矩阵

	MatGraph G;
	initMatrix(G, A, v, 5, 8);
	cout << "初始邻接矩阵为：" << endl;
	DispMGraph(G);

	cout << "\n\n从编号0构造的最小生成树：\n";
	Prim(G, 0);
	cout << "\n\n从编号1构造的最小生成树：\n";
	Prim(G, 1);

	system("pause");
	return 0;
}