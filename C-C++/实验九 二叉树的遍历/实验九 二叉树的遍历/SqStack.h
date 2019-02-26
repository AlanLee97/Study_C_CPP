///*
#pragma once
#include <malloc.h>
#include <iostream>

#define MaxSize 50
using namespace std;

typedef BTNode* SElemType;
typedef struct {
	int top;
	SElemType data[MaxSize];
}SqStack;



void InitStack(SqStack *&s) {
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}

bool Push(SqStack *&s, SElemType e) {
	if (s->top == MaxSize - 1) {
		return false;
	}
	else {
		s->top++;
		s->data[s->top] = e;
		return true;
	}
}

bool Pop(SqStack *&s, SElemType &e) {
	if (s->top == -1) {
		return false;
	}
	else {
		e = s->data[s->top];
		s->top--;
		return true;
	}
}

bool SqStackEmpty(SqStack *s) {
	return s->top == -1;
}

bool GetTop(SqStack *s, BTNode *&b) {
	if (s->top == -1) return false;
	b = s->data[s->top];
	s->top--;
	return true;
}

//*/

















