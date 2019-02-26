//SqQueue.h

#pragma once
#include <iostream>
#include <malloc.h>
#include "Car.h"
#define MAXSIZE 7
using namespace std;

typedef stCar SqElemType;
typedef struct {
	SqElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitSqQueue(SqQueue *&Sq) {
	Sq = (SqQueue *)malloc(sizeof(SqQueue));
	Sq->front = Sq->rear = -1;		//��ʼʱ����ͷ��β����Ϊ -1
}

void DestorySqQueue(SqQueue *&Sq) {
	free(Sq);
}

bool SqQueueEmpty(SqQueue *&Sq) {
	return Sq->front == Sq->rear;		//��ͷ���ڶ�βʱ������Ϊ��
}

bool SqQueueFull(SqQueue *Sq) {
	return Sq->rear == MAXSIZE - 1;		//��β������������±�ʱ������Ϊ��
}

bool enSqQueue(SqQueue *Sq, SqElemType e) {
	if (SqQueueFull(Sq)) return false;
	Sq->rear++;							//Ԫ�ؽ��ӣ��Ƚ�βָ��rear+1

										//Ȼ���Ҫ���ӵ�Ԫ��e��ֵ�����е�data�����е�Sq->rear��λ����
	Sq->data[Sq->rear] = e;
	return true;
}

bool deSqQueue(SqQueue *Sq, SqElemType &e) {
	if (SqQueueEmpty(Sq)) return false;
	Sq->front++;				//Ԫ�س��ӣ�����ͷָ��front+1
	e = Sq->data[Sq->front];	//������Ԫ�ط���e�У��Ա���
	return true;
}


//����arrLen����Ϊ�˿����������ѭ���ĳ���
void DisplaySqQueue(SqQueue *sq, int arrLen) {
	for (int i = 0; i < arrLen; i++) {		//�������У������е�Ԫ�����
		dispStCar(sq->data[i]);
	}
}

void DisplaySqQueue2(SqQueue *sq, int arrLen) {
	for (int i = 0; i < arrLen; i++) {		//�������У������е�Ԫ�����
		dispStCar2(sq->data[i]);
	}
}

int SqQueueLength(SqQueue *Sq) {
	return Sq->rear + 1;		//���еĳ��ȵ��ڶ�βָ��rear+1
}
