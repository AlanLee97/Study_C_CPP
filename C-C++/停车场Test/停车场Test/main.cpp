#include <iostream>
#include<iomanip>
#include"LinkQueue.h"
#include"SqList.h"
using namespace std;
int main(int argc, char** argv)
{
	LinkQuNode *q1, *q2, *q3;
	SqList *L;
	InitQueue(q1);InitQueue(q2);InitQueue(q3);InitList(L);
	int i = 0;
	ElemType e;
	ElemType1 e1, e2, e3;
	int X3[] = { 111,112,113,114,115,116 };
	int X4[] = { 1,2,3,4,5,6,7 };
	sp  X5[7];
	for (int j = 0; j < 6; j++) {
		X5[j].site = X3[j];
		X5[j].digit = X4[j];
		X5[j].time = 0;
	}
	CreateList(L, X5, 6);

	cout << " ======此停车场最多可停放7辆汽车======" << endl << endl;
	while (i != 4) {
		cout << "当前已停放" << ListLength(L) << "辆汽车~" << endl;
		DispList(L);
		cout << "您可以选择：" << endl << endl;
		cout << " 1:入站" << " " << "2:出站" << " " << "3:出库汽车计费" << " " << "4:退出系统" << endl << endl;
		cout << "请选择:";
		cin >> i;
		switch (i) {
		case 1:
			if (ListLength(L) == 7) {
				if (QueueLength(q1) == 3)  cout << "停车场已满" << endl << endl;
				else if (QueueLength(q1) != 3) {
					cout << "     目前停车场已满，还请在通道内等待~" << endl << endl;
					Gettt1(e);
					e1 = e.digit;
					EnQueue(q1, e1);
				}
			}
			else {
				cout << "当前已被使用的车位有：";
				for (int x = 0; x < ListLength(L); x++) {
					for (int y = 0; y < 7; y++) {
						if (L->data[x].site == X1[y])  cout << X1[y] << " ";
					}
				}

				cout << endl << "请输入入站汽车的相关信息：" << endl;
				Get1(e);
				ListInsert(L, ListLength(L) + 1, e);
			}
			cout << "当前停放的车辆有：" << endl;
			DispList(L);
			if (!QueueEmpty(q1)) {
				cout << "当前候车区停放的车辆有：" << endl;
				DispQueue(q1);
			}
			else cout << "当前候车区暂无车辆~" << endl;
			if (!QueueEmpty(q2)) {
				cout << "当前等待结算离开的车辆有：" << endl;
				DispQueue(q2);
			}
			else cout << "当前暂无等待结算离开的车辆~" << endl;
			break;
		case 2:
			if (QueueLength(q2) == 3)  cout << "目前等待结算的车辆太多了~待其出库后您方可出站~！" << endl;
			else {
				if (ListEmpty(L)) { cout << " 没生意啊好心酸TvT~" << endl; }
				else {
					cout << endl << "请输入要出站的车的车牌号:";
					ElemType i1;
					cin >> i1.num;
					if (ListDelete(L, LocateElem(L, i1), e)) {
						cout << "车牌号为" << e.num << "的汽车已驶入结算区~" << endl;
						e2 = e.num;
						EnQueue(q2, e2);
						e3 = e.time;
						EnQueue(q3, e3);
						if (!QueueEmpty(q1)) {
							DeQueue(q1, e1);
							Getn1(e, e1);
							cout << "车牌为" << e.num << "的车辆现可以入库~！还请确定入库时间：" << endl;
							Gett(e);
							ListInsert(L, ListLength(L) + 1, e);
						}
						else {
							for (int x = 0; x < 7; x++) {
								if (x1[x] == e.place) {
									x1[x] = 0;
									break;
								}
							}
						}
					}
					else cout << "不存在此车辆,请重新输入~~" << endl;
					if (!ListEmpty(L))
						cout << "当前停放的车辆有：" << endl;
					DispList(L);
				}
			}
		}
		if (!QueueEmpty(q1)) {
			cout << "当前候车区停放的车辆有：" << endl;
			DispQueue(q1);
		}
		else cout << "当前候车区暂无车辆~" << endl;
		if (!QueueEmpty(q2)) {
			cout << "当前等待结算离开的车辆有：" << endl;
			DispQueue(q2);
		}
		else cout << "当前暂无等待结算离开的车辆~" << endl;
		break;

		case 3:
			if (QueueEmpty(q2))  cout << "当前暂无等待结算离开的车辆~" << endl;
			else {
				DeQueue(q2, e2);
				cout << "车牌为" << e2 << "的车辆现进行费用结算~！还请输入当前时间：";
				DeQueue(q3, e3);
				Gettt(e3);
				cout << "车牌号为" << e2 << "的汽车已驶出停车场~~~!" << endl;
				for (int x = 0; x < 13; x++) {
					if (x2[x] == e2) {
						x2[x] = 0;
						break;
					}
				}
			}
			if (!QueueEmpty(q1)) {
				cout << "当前候车区停放的车辆有：" << endl;
				DispQueue(q1);
			}
			else  cout << "当前候车区暂无车辆~" << endl;
			if (!QueueEmpty(q2)) {
				cout << "当前等待结算离开的车辆有：" << endl;
				DispQueue(q2);
			}
			else  cout << "当前暂无等待结算离开的车辆~" << endl;
			break;
		case 4:
			cout << endl << "     slyarh竭诚为您服务，欢迎下次再来~" << endl;
			DestroyList(L);
			DestroyQueue(q1);
			DestroyQueue(q2);
			DestroyQueue(q3);
			break;
		default:
			cout << "您的输入有误，请检查后重新输入~" << endl;
	}
}
return 0;
}


