//Car.h

#pragma once
#include<iostream>
using namespace std;

typedef struct{
	int position;
	int carNum;
	int arriveTime;
}stCar;
typedef stCar LElemType;

typedef struct {
	int inTime;
	int outTime;
}stOutCar;
typedef stOutCar socElemType;

//���������Ϣ1
void dispStCar(LElemType sc) {
	cout << "ͣ��λ�ã�" << sc.position << " ";
	cout << "�����ƺ��룺"  << sc.carNum << " ";
	cout << "������ʱ�䣺" << sc.arriveTime << " ";
	cout << endl;
}

//���������Ϣ2
void dispStCar2(LElemType sc) {
	cout << "---���ƺ��룺" << sc.carNum << " �ĳ��������Ŷӽ��� ";
	
	cout << endl;
}

//�Ŷӽ������
void stCarInQ(stCar &c) {
	
	c.position = 0;
	cout << "\n";

	cout << "==>���복�ƺ��룺";
	cin >> c.carNum;
	cout << "\n";

	c.arriveTime = 0;
	cout << "\n";
}

//�Ŷӳ�����
void stCarOutQ(stCar &c, LElemType le) {
	c.carNum = le.carNum;
}
















