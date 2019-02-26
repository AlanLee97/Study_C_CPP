//main.cpp
/*
* 代码全部在Visual Studio 2017中编写并运行成功
* 我把代码移植在DEV中，也可以成功编译运行
*/

#include <iostream>
#include "SqList.h"
#include "SqQueue.h"
#include "Car.h"
#include "function.h"
#define M 3
#define MAXPARK 7
using namespace std;

typedef stOutCar socElemType;

int main()
{
	int menu = 0;						//菜单编号
	stCar parkPos[MAXPARK];				//存储车辆的数组
	LElemType car, carInQ, carOutQ;		//存储车辆信息的结构体变量
	socElemType car1;					//存储进站出站时间的结构体变量
	SqList *listPark;					//停车场线性表
	SqQueue *inQueue, *outQueue;		//进队、出队的变量
	
	cout << "停车场是可停放" << MAXPARK << "辆小车的狭长车道" << endl;
	cout << "车位的位置为：110,111,112,113,114,115,116" << endl;
	cout << "\n初始时，停了6辆车。";
	cout << "\n---当前停车场停放的车辆信息为：\n";
	showInfo(parkPos);							//初始化并显示停车场信息
	CreateList(listPark, parkPos, MAXPARK);		//创建停车场线性表
	DispList(listPark);							//显示当前停车场停放的车辆信息

	do {
		//进站排队等候
		initInQ(inQueue, listPark);
		
		//出站排队等候
		initOutQ(outQueue, listPark);

		//菜单
		cout << "\n\n========= 菜单 ==========\n"
			<< "\t1.入站\n"
			<< "\t2.出站\n"
			<< "\t3.出库汽车计费\n"
			<< "\t4.退出系统\n"
			<< "========================="
			<< endl;
		menu:cout << "\n==>请输入菜单编号：";
		cin >> menu;
	
			switch (menu) {
			case 1:
				showEmptyPark(listPark);								//显示停车场空位信息
				//判断车库是否满
				if (!isFullPark(listPark)) {
					cout << "\n\n===========请填写入库信息===========\n";
					inCar(car, listPark);								//1.菜单1：小车进站
					cout << "\n---当前停放的车辆为：\n";
					DispList(listPark);									//显示停车场信息
				}
				else
				{
					if (SqQueueLength(inQueue) >= QMAX) {
						cout << "---排队通道已满，请寻找其他停车场。";
					}
					else {
						cout << "\n---车库已满，请填写您的相关信息，排队等候。";
						stCarInQ(carInQ);								//排队进入队列
						enSqQueue(inQueue, carInQ);						//将carInQ放到队列inQueue中

						cout << "\n---当前排队等候的车辆为：\n";
						DisplaySqQueue(inQueue, SqQueueLength(inQueue));//显示当前排队等候的车辆
					}
				}
				break;
			case 2:
				cout << "\n\n===========请填写出库信息===========\n";
				outCar(car, listPark, car1);							//2.菜单2：:小车出站
				cout << "\n---当前停放的车辆为：\n";
				DispList(listPark);										//显示停车场信息

				if (SqQueueLength(outQueue) >= QMAX) {
					cout << "---出站排队通道已满，请稍候过来排队。";
				}
				else
				{
					cout << "---请前往缴费处排队交费";
					stCarOutQ(carOutQ, car);							//排队出队列
					enSqQueue(outQueue, carOutQ);						//将carOutQ放到队列outQueue中
					cout << "\n---当前排队等候的车辆为：\n";
					DisplaySqQueue2(outQueue, SqQueueLength(outQueue)); //显示当前排队等候的车辆
				}
				break;
			case 3:
				carCharge(listPark, car1);								//3.菜单3：交费
				break;
			case 4:
				//exit(0);												//4.菜单4：退出系统
				break;
			default:
				cout << "\n输入菜单错误，请重新输入！" << endl;
				goto menu;
				break;
			}
	} while (menu != 4);
	
	//销毁
	DestorySqQueue(inQueue);
	DestorySqQueue(outQueue);
	Destroy(listPark);

	//Visual Studio 2017 中需要此语句来暂停运行窗口，其他编译器不需要此语句
	system("pause");		
	return 0;
}

