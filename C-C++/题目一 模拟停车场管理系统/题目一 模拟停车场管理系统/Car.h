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

//输出车辆信息1
void dispStCar(LElemType sc) {
	cout << "停车位置：" << sc.position << " ";
	cout << "，车牌号码："  << sc.carNum << " ";
	cout << "，到达时间：" << sc.arriveTime << " ";
	cout << endl;
}

//输出车辆信息2
void dispStCar2(LElemType sc) {
	cout << "---车牌号码：" << sc.carNum << " 的车辆正在排队交费 ";
	
	cout << endl;
}

//排队进入队列
void stCarInQ(stCar &c) {
	
	c.position = 0;
	cout << "\n";

	cout << "==>输入车牌号码：";
	cin >> c.carNum;
	cout << "\n";

	c.arriveTime = 0;
	cout << "\n";
}

//排队出队列
void stCarOutQ(stCar &c, LElemType le) {
	c.carNum = le.carNum;
}
















