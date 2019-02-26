#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
using namespace std;

void disp(deque<int> &dq) {
	deque<int>::iterator it;
	for (it = dq.begin(); it != dq.end(); it++) {
		cout << *it << " ";
	}
}

void vectorF() {
	vector<int> vecInt;
	int i;
	cout << "��ʼʱvector�Ĵ�С�ǣ�" << vecInt.size() << endl;
	for (i = 0; i < 5; i++) {
		vecInt.push_back(i);
	}
	cout << "��չ��vector�Ĵ�С�ǣ�" << vecInt.size() << endl;


	cout << "���������е� 5 ��ֵ" << endl;
	for (i = 0; i < 5; i++) {
		cout << "vecInt [" << i << "] = " << vecInt[i] << endl;
	}


	cout << "ʹ�õ����� iterator ����ֵ" << endl;
	vector<int>::iterator v = vecInt.begin();
	while (v != vecInt.end()){
		cout << "v��ֵ��" << *v << endl;
		v++;
	}
}

void dequeF() {
	deque<int> dq;
	cout << "\n ��ͷ����1 ��";
	dq.push_front(1);

	cout << "\n ��β����2 ��";
	dq.push_back(2);

	cout << "\n ��ͷ����3 ��";
	dq.push_front(3);

	cout << "\n ��β����4 ��";
	dq.push_back(4);
	disp(dq);

	cout << "\n ��ͷɾ��һ��Ԫ�� ��";
	dq.pop_front();

	cout << "\n ��βɾ��һ��Ԫ�� ��";
	dq.pop_back();
	disp(dq);
}

void listF() {
	list<int> li;
	list<int>::iterator i, start, end;

	li.push_back(5);
	li.push_back(2);
	li.push_back(4);
	li.push_back(1);
	li.push_back(3);
	li.push_back(8);
	li.push_back(6);
	li.push_back(7);

	cout << "li:";
	for (i = li.begin(); i != li.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	i = li.begin();					//��һ��Ԫ��
	start = ++li.begin();			//�ڶ���Ԫ��
	end = --li.end();				//�����ڶ���Ԫ��
	li.insert(i, start, end);		//���ڶ���Ԫ�ص������ڶ���Ԫ�ز��뵽 i ��ǰ��
	cout << "insert(i, start, end): " << endl;
	cout << "li:";
	for (i = li.begin(); i != li.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
}

void stackF() {
	int temp;
	int len;
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	len = st.size();
	cout << "ջ�Ĵ�СΪ��" << len;
	
	cout << endl;
	while (!st.empty()) {
		temp = st.top();
		st.pop();
		cout << temp << " ";
	}
}

void queueF() {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	cout << "q�ĳ��ȣ�" << q.size() << endl;
	cout << "\n��βԪ�أ�" << q.back();
	cout << "\n��ͷԪ�أ�" << q.front();

	cout << endl;
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	

}
