#pragma once
#include <iostream>
#include "MGraph.h"
#define INF 32767
using namespace std;

void Prim(MatGraph g, int v) {
	int lowcost[MAXV];//lowcost[i] ��ʾ����i��i �� V��U����U�����ж������С��
	int closest[MAXV];//�Ӷ���i��U����С���۵Ķ�����closest[i] ��ʾ��
	int MIN;
	int i, j, k;
	for (i = 0; i < g.n; i++) {
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}

	for (i = 1; i < g.n; i++) {
		MIN = INF;
		for (j = 0; j < g.n; j++) {
			if (lowcost[j] != 0 && lowcost[j] < MIN) {
				MIN = lowcost[j];
				k = j;
			}
		}
		cout << "��" << closest[k] << "," << k << "ȨΪ��" << MIN << endl;
		lowcost[k] = 0;
		for (j = 0; j < g.n; j++) {
			if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j]) {
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
		}
	}	
}







