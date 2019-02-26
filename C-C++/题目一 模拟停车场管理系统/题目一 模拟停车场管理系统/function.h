//function.h

#pragma once
#include <iostream>
#include "Car.h"
#include "SqList.h"
#include "SqQueue.h"
#define MAXPARK 7				//ͣ����λ�õ�����
#define QMAX 3					//�Ŷ��������

using namespace std;


//1.�˵�1��С����վ
void inCar(LElemType &c, SqList *L) {
	cout << "\n==>������Ҫͣ����λ�ã�";
	cin >> c.position;
	cout << "\n";

	cout << "==>���복�ƺ��룺";
	cin >> c.carNum;
	cout << "\n";

	cout << "==>���뵽��ʱ�䣺";
	cin >> c.arriveTime;
	cout << "\n";

	void updateInfo(LElemType &c, SqList *L, int i);
	int i = 0;
	switch (c.position)
	{
	case 110:
		i = 0;
		updateInfo(c, L, i);
		break;
	case 111:
		i = 1;
		updateInfo(c, L, i);
		break;
	case 112:
		i = 2;
		updateInfo(c, L, i);
		break;
	case 113:
		i = 3;
		updateInfo(c, L, i);
		break;
	case 114:
		i = 4;
		updateInfo(c, L, i);
		break;
	case 115:
		i = 5;
		updateInfo(c, L, i);
		break;
	case 116:
		i = 6;
		updateInfo(c, L, i);
		break;
	default:
		break;
	}
}

//���������Ϣ���µ�ͣ����
void updateInfo(LElemType &c, SqList *L, int i) {
	L->data[i].position = c.position;
	L->data[i].carNum = c.carNum;
	L->data[i].arriveTime = c.arriveTime;
}

//����updateInfo���������ڳ�վ����³�λ��Ϣ
void updateInfo(LElemType &c, SqList *L, int i, int leaveTime) {
	//����ǰ����ʱ�䴫��outcar�ṹ����������ڼ���ͣ��ʱ��
	L->outcar[i].inTime = L->data[i].arriveTime;

	//����ǰ�뿪ʱ�䴫��outcar�ṹ����������ڼ���ͣ��ʱ��
	L->outcar[i].outTime = leaveTime;

	L->data[i].carNum = 0;			//��վ��ͣ��λ�õĳ��ƺ�����Ϊ0����������ж�ͣ�������
	L->data[i].arriveTime = 0;		//��վ��ͣ��λ�õĵ���ʱ����Ϊ0����������ж�ͣ�������
}

//2.�˵�2����վ
int getCarNum = 0;					//���泵�ƺ���
void outCar(LElemType &c, SqList *L, socElemType &soc) {
	int leaveTime = 0;
	int i = 0;

	cout << "==>�������ĳ��ƺ��룺";
	cin >> c.carNum;
	getCarNum = c.carNum;			//���泵�ƺ���
	cout << "\n";

	cout << "==>�����վʱ�䣺";
	cin >> leaveTime;
	cout << "\n";

	switch (c.carNum)
	{
	case 1:
		i = c.carNum - 1;
		updateInfo(c, L, i, leaveTime);
		break;
	case 2:
		i = c.carNum - 1;
		updateInfo(c, L, i, leaveTime);
		break;
	case 3:
		i = c.carNum - 1;
		updateInfo(c, L, i, leaveTime);
		break;
	case 4:
		i = c.carNum - 1;
		updateInfo(c, L, i, leaveTime);
		break;
	case 5:
		i = c.carNum - 1;
		updateInfo(c, L, i, leaveTime);
		break;
	case 6:
		i = c.carNum - 1;
		updateInfo(c, L, i, leaveTime);
		break;
	case 7:
		i = c.carNum - 1;
		updateInfo(c, L, i, leaveTime);
		break;
	default:
		break;
	}

	cout << "\n---���ƺ�Ϊ" << getCarNum << "�ĳ�����վ�ɹ����뵽�ɷѴ����ѡ�\n";
}

//3.�˵�3������
void carCharge(SqList *L, socElemType &soc) {
	int stopTime = 0;				//ͣ��ʱ��

	//ͣ��ʱ��stopTime =  outTime - inTime
	stopTime = L->outcar[getCarNum - 1].outTime - L->outcar[getCarNum - 1].inTime;

	//�շѣ�ʱ����㵽���ӣ�ÿСʱͣ����3Ԫ���� 50��Ǯ / ����
	int charge = stopTime * 50;
	cout << "---��ͣ����" << stopTime << "����\n";
	cout << "---�뽻ͣ����";
	cout << charge;
	cout << "��Ǯ";
	cout << "\n---����ƽ����ף��һ·˳�磡��ӭ�ٴι��ٱ�ͣ������";
}


//��ʼ����վͨ���ŶӶ�����Ϣ
int once = 1;					//�����������ı���
void initInQ(SqQueue *&sq, SqList *L) {
	if (once == 1) {
		InitSqQueue(sq);		//ִֻ��һ��������䣬ֻ��sq��ʼ��һ�ξͺ�
	}
	once = 0;

	bool flag = (SqQueueEmpty(sq));
	if (flag) {
		cout << "\n---��ǰ��վͨ�����޳����Ŷ�";
	}
}

//��ʼ����վͨ���ŶӶ�����Ϣ
int once2 = 1;					//�����������ı���
void initOutQ(SqQueue *&sq, SqList *L) {
	if (once2 == 1) {
		InitSqQueue(sq);		//ִֻ��һ��������䣬ֻ��sq��ʼ��һ�ξͺ�
	}
	once2 = 0;

	bool flag = (SqQueueEmpty(sq));
	if (flag) {
		cout << "\n---��ǰ��վͨ�����޳����Ŷ�";
	}
}

//��ʼ��ͣ������Ϣ
void initParkInfo(LElemType arr[]) {
	int parkNum[MAXPARK] = { 110, 111, 112, 113, 114, 115, 116 };
	int carNo[MAXPARK] = { 1, 2, 3, 4, 5, 6, 7 };

	//��ʼ��7��ͣ��λ��Ϊ110��111��...��116�����ƺ���͵���ʱ��Ϊ0�����ճ�λ
	for (int i = 0, j = 110; i < MAXSIZE; i++, j++) {
		arr[i].position = j;
		arr[i].carNum = 0;
		arr[i].arriveTime = 0;
	}

	//*��ʼ��ͣ��6����
	for (int k = 0; k < MAXPARK - 1; k++) {
		arr[k].position = parkNum[k];
		arr[k].carNum = carNo[k];
		arr[k].arriveTime = 1220;			//�����ʼ����ʱ�䶼Ϊ1220
	}
}

//�жϳ����Ƿ�����
bool isFullPark(SqList *L) {
	//�����һ����λ�ĳ��ƺŲ�Ϊ0ʱΪ��������
	bool flag = (L->data[MAXPARK - 1].carNum != 0);
	if (flag) {
		return true;
	}
	else
	{
		return false;
	}
}

//��ʾͣ������Ϣ
void showInfo(LElemType a[]) {
	initParkInfo(a);	//��ʼ��ͣ������Ϣ			
}

//��ʾͣ������λ��Ϣ
void showEmptyPark(SqList *L) {
	cout << "\n---��ǰ�ճ�λ�У�";
	for (int i = 0; i < MAXPARK; i++) {

		//�ж�����Ϊ���ƺ���͵���ʱ�䶼��Ϊ0
		bool flag = (L->data[i].carNum != 0 && L->data[i].arriveTime != 0);
		if (!flag) {
			cout << L->data[i].position << " ";			//�����ǰ�յĳ�λ
		}
	}
}

