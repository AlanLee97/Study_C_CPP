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
	Sq->front = Sq->rear = -1;		//初始时将队头队尾都置为 -1
}

void DestorySqQueue(SqQueue *&Sq) {
	free(Sq);
}

bool SqQueueEmpty(SqQueue *&Sq) {
	return Sq->front == Sq->rear;		//队头等于队尾时，队列为空
}

bool SqQueueFull(SqQueue *Sq) {
	return Sq->rear == MAXSIZE - 1;		//队尾等于数组最大下标时，队列为满
}

bool enSqQueue(SqQueue *Sq, SqElemType e) {
	if (SqQueueFull(Sq)) return false;
	Sq->rear++;							//元素进队，先将尾指针rear+1

										//然后把要进队的元素e赋值给队列的data数组中的Sq->rear的位置中
	Sq->data[Sq->rear] = e;
	return true;
}

bool deSqQueue(SqQueue *Sq, SqElemType &e) {
	if (SqQueueEmpty(Sq)) return false;
	Sq->front++;				//元素出队，将队头指针front+1
	e = Sq->data[Sq->front];	//将出队元素放在e中，以备用
	return true;
}


//参数arrLen，是为了控制下面这个循环的长度
void DisplaySqQueue(SqQueue *sq, int arrLen) {
	for (int i = 0; i < arrLen; i++) {		//遍历队列，将队列的元素输出
		dispStCar(sq->data[i]);
	}
}

void DisplaySqQueue2(SqQueue *sq, int arrLen) {
	for (int i = 0; i < arrLen; i++) {		//遍历队列，将队列的元素输出
		dispStCar2(sq->data[i]);
	}
}

int SqQueueLength(SqQueue *Sq) {
	return Sq->rear + 1;		//队列的长度等于队尾指针rear+1
}
