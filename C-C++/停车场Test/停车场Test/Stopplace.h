#pragma once
#pragma once
#include <iostream>
using namespace std;
typedef struct
{
	int site;
	int digit;
	int time;
}sp;
int X1[7] = { 111,112,113,114,115,116 };
int X2[13] = { 1,2,3,4,5,6 };
void Ip1(sp &e) {
	cout << "停车位置：";
	cin >> e.site;
	if ((e.site > 117 || e.site < 111)) {
		cout << "该停车位不存在，请输入111-117的数字" << endl;
		Ip1(e);
	}
	else {
		for (int x = 0; x < 7; x++) {
			if (X1[x] == e.site) {
				cout << "该停车位已被占用" << endl;
				Ip1(e);
			}
		}
	}
}
void Ip2(sp &e) {
	cout << "车牌号码：";
	cin >> e.digit;
	for (int x = 0; x < 13; x++) {
		if (X2[x] == e.digit) {
			cout << "该车辆已存在，请重新输入" << endl;
			Ip2(e);
		}
	}
}
void Ip3(sp &e) {
	cout << "停车时间：";
	cin >> e.time;
	if (e.time > 2359) {
		cout << "时间出现错误，请重新输入" << endl;
		Ip3(e);
	}
}
void Ip4(sp &e, int i) {
	e.digit = i;
}
void Ip5(sp &e) {
	Ip2(e);
	for (int x = 0; x < 13; x++) {
		if (X2[x] == 0) {
			X2[x] = e.digit;
			break;
		}
	}
}
void Ip6(sp &e) {
	Ip1(e);
	Ip2(e);
	Ip3(e);
	for (int x = 0; x < 7; x++) {
		if (X1[x] == 0) {
			X1[x] = e.site;
			break;
		}
	}
	for (int x = 0; x < 13; x++) {
		if (X2[x] == 0) {
			X2[x] = e.digit;
			break;
		}
	}
}
void Op(sp &e)
{
	cout << "停车位置：" << e.site << " " << "车牌号码：" << e.digit << " " << "到达时间：" << e.time << endl;
}
void Ip7(int i)
{
	int j;
	cin >> j;
	if (j < i) {
		cout << "时间出现错误，请重新输入" << endl;
		Ip7(i);
	}
	else {
		cout << "本次停车费用为：" << 0.05*(j - i) << "元" << endl;
	}
