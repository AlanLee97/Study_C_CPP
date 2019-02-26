#pragma once
#include <iostream>
#include <stdio.h>
#include <iomanip>
#define MAXV 5
#define INF 32767
using namespace std;

typedef char InfoType;
typedef struct {
	int no;//������
	InfoType info;//������Ϣ
}VertexType;

typedef struct {
	VertexType vexs[MAXV];//��Ŷ�����Ϣ
	int edges[MAXV][MAXV];//�ڽӾ���
	int n;//������
	int e;//����
}MatGraph;


void initMatrix(MatGraph &G, int A[MAXV][MAXV], InfoType *v, int n, int e) {
	G.n = n;
	G.e = e;
	for (int i = 0; i < n; i++) {
		G.vexs[i].no = i;
		G.vexs[i].info = v[i];
		for (int j = 0; j < n; j++) {
			G.edges[i][j] = A[i][j];
		}
	}
}

void DispMGraph(MatGraph G) {
	for (int i = 0; i < G.n; i++) {
		for (int j = 0; j < G.n; j++) {
			cout << setw(6) << G.edges[i][j];
			if (j == G.n - 1) {
				cout << "\n";
			}
		}
	}
}

















