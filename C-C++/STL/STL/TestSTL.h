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
	cout << "初始时vector的大小是：" << vecInt.size() << endl;
	for (i = 0; i < 5; i++) {
		vecInt.push_back(i);
	}
	cout << "扩展后vector的大小是：" << vecInt.size() << endl;


	cout << "访问向量中的 5 个值" << endl;
	for (i = 0; i < 5; i++) {
		cout << "vecInt [" << i << "] = " << vecInt[i] << endl;
	}


	cout << "使用迭代器 iterator 访问值" << endl;
	vector<int>::iterator v = vecInt.begin();
	while (v != vecInt.end()){
		cout << "v的值：" << *v << endl;
		v++;
	}
}

void dequeF() {
	deque<int> dq;
	cout << "\n 对头插入1 ：";
	dq.push_front(1);

	cout << "\n 对尾插入2 ：";
	dq.push_back(2);

	cout << "\n 对头插入3 ：";
	dq.push_front(3);

	cout << "\n 对尾插入4 ：";
	dq.push_back(4);
	disp(dq);

	cout << "\n 对头删除一个元素 ：";
	dq.pop_front();

	cout << "\n 对尾删除一个元素 ：";
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

	i = li.begin();					//第一个元素
	start = ++li.begin();			//第二个元素
	end = --li.end();				//倒数第二个元素
	li.insert(i, start, end);		//将第二个元素到倒数第二个元素插入到 i 的前面
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
	cout << "栈的大小为：" << len;
	
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

	cout << "q的长度：" << q.size() << endl;
	cout << "\n队尾元素：" << q.back();
	cout << "\n队头元素：" << q.front();

	cout << endl;
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	

}
