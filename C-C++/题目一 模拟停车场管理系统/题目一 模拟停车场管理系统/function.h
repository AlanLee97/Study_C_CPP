//function.h

#pragma once
#include <iostream>
#include "Car.h"
#include "SqList.h"
#include "SqQueue.h"
#define MAXPARK 7				//停车场位置的数量
#define QMAX 3					//排队最大数量

using namespace std;


//1.菜单1：小车进站
void inCar(LElemType &c, SqList *L) {
	cout << "\n==>输入需要停车的位置：";
	cin >> c.position;
	cout << "\n";

	cout << "==>输入车牌号码：";
	cin >> c.carNum;
	cout << "\n";

	cout << "==>输入到达时间：";
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

//将输入的信息更新到停车场
void updateInfo(LElemType &c, SqList *L, int i) {
	L->data[i].position = c.position;
	L->data[i].carNum = c.carNum;
	L->data[i].arriveTime = c.arriveTime;
}

//重载updateInfo函数，用于出站后更新车位信息
void updateInfo(LElemType &c, SqList *L, int i, int leaveTime) {
	//将当前到达时间传给outcar结构体变量，用于计算停车时间
	L->outcar[i].inTime = L->data[i].arriveTime;

	//将当前离开时间传给outcar结构体变量，用于计算停车时间
	L->outcar[i].outTime = leaveTime;

	L->data[i].carNum = 0;			//出站后将停车位置的车牌号码置为0，方便后续判断停车场情况
	L->data[i].arriveTime = 0;		//出站后将停车位置的到达时间置为0，方便后续判断停车场情况
}

//2.菜单2：出站
int getCarNum = 0;					//保存车牌号码
void outCar(LElemType &c, SqList *L, socElemType &soc) {
	int leaveTime = 0;
	int i = 0;

	cout << "==>输入出库的车牌号码：";
	cin >> c.carNum;
	getCarNum = c.carNum;			//保存车牌号码
	cout << "\n";

	cout << "==>输入出站时间：";
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

	cout << "\n---车牌号为" << getCarNum << "的车辆出站成功，请到缴费处交费。\n";
}

//3.菜单3：交费
void carCharge(SqList *L, socElemType &soc) {
	int stopTime = 0;				//停留时间

	//停留时间stopTime =  outTime - inTime
	stopTime = L->outcar[getCarNum - 1].outTime - L->outcar[getCarNum - 1].inTime;

	//收费：时间计算到分钟，每小时停车费3元。即 50分钱 / 分钟
	int charge = stopTime * 50;
	cout << "---您停车共" << stopTime << "分钟\n";
	cout << "---请交停车费";
	cout << charge;
	cout << "分钱";
	cout << "\n---出入平安，祝您一路顺风！欢迎再次光临本停车场！";
}


//初始化进站通道排队队列信息
int once = 1;					//控制语句次数的变量
void initInQ(SqQueue *&sq, SqList *L) {
	if (once == 1) {
		InitSqQueue(sq);		//只执行一次这条语句，只让sq初始化一次就好
	}
	once = 0;

	bool flag = (SqQueueEmpty(sq));
	if (flag) {
		cout << "\n---当前进站通道中无车辆排队";
	}
}

//初始化出站通道排队队列信息
int once2 = 1;					//控制语句次数的变量
void initOutQ(SqQueue *&sq, SqList *L) {
	if (once2 == 1) {
		InitSqQueue(sq);		//只执行一次这条语句，只让sq初始化一次就好
	}
	once2 = 0;

	bool flag = (SqQueueEmpty(sq));
	if (flag) {
		cout << "\n---当前出站通道中无车辆排队";
	}
}

//初始化停车场信息
void initParkInfo(LElemType arr[]) {
	int parkNum[MAXPARK] = { 110, 111, 112, 113, 114, 115, 116 };
	int carNo[MAXPARK] = { 1, 2, 3, 4, 5, 6, 7 };

	//初始化7个停车位置为110，111，...，116；车牌号码和到达时间为0，即空车位
	for (int i = 0, j = 110; i < MAXSIZE; i++, j++) {
		arr[i].position = j;
		arr[i].carNum = 0;
		arr[i].arriveTime = 0;
	}

	//*初始化停着6辆车
	for (int k = 0; k < MAXPARK - 1; k++) {
		arr[k].position = parkNum[k];
		arr[k].carNum = carNo[k];
		arr[k].arriveTime = 1220;			//假设初始到达时间都为1220
	}
}

//判断车库是否已满
bool isFullPark(SqList *L) {
	//当最后一个车位的车牌号不为0时为车库已满
	bool flag = (L->data[MAXPARK - 1].carNum != 0);
	if (flag) {
		return true;
	}
	else
	{
		return false;
	}
}

//显示停车场信息
void showInfo(LElemType a[]) {
	initParkInfo(a);	//初始化停车场信息			
}

//显示停车场空位信息
void showEmptyPark(SqList *L) {
	cout << "\n---当前空车位有：";
	for (int i = 0; i < MAXPARK; i++) {

		//判断条件为车牌号码和到达时间都不为0
		bool flag = (L->data[i].carNum != 0 && L->data[i].arriveTime != 0);
		if (!flag) {
			cout << L->data[i].position << " ";			//输出当前空的车位
		}
	}
}

