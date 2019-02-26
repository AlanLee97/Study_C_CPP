//main.cpp
/*
* ����ȫ����Visual Studio 2017�б�д�����гɹ�
* �ҰѴ�����ֲ��DEV�У�Ҳ���Գɹ���������
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
	int menu = 0;						//�˵����
	stCar parkPos[MAXPARK];				//�洢����������
	LElemType car, carInQ, carOutQ;		//�洢������Ϣ�Ľṹ�����
	socElemType car1;					//�洢��վ��վʱ��Ľṹ�����
	SqList *listPark;					//ͣ�������Ա�
	SqQueue *inQueue, *outQueue;		//���ӡ����ӵı���
	
	cout << "ͣ�����ǿ�ͣ��" << MAXPARK << "��С������������" << endl;
	cout << "��λ��λ��Ϊ��110,111,112,113,114,115,116" << endl;
	cout << "\n��ʼʱ��ͣ��6������";
	cout << "\n---��ǰͣ����ͣ�ŵĳ�����ϢΪ��\n";
	showInfo(parkPos);							//��ʼ������ʾͣ������Ϣ
	CreateList(listPark, parkPos, MAXPARK);		//����ͣ�������Ա�
	DispList(listPark);							//��ʾ��ǰͣ����ͣ�ŵĳ�����Ϣ

	do {
		//��վ�ŶӵȺ�
		initInQ(inQueue, listPark);
		
		//��վ�ŶӵȺ�
		initOutQ(outQueue, listPark);

		//�˵�
		cout << "\n\n========= �˵� ==========\n"
			<< "\t1.��վ\n"
			<< "\t2.��վ\n"
			<< "\t3.���������Ʒ�\n"
			<< "\t4.�˳�ϵͳ\n"
			<< "========================="
			<< endl;
		menu:cout << "\n==>������˵���ţ�";
		cin >> menu;
	
			switch (menu) {
			case 1:
				showEmptyPark(listPark);								//��ʾͣ������λ��Ϣ
				//�жϳ����Ƿ���
				if (!isFullPark(listPark)) {
					cout << "\n\n===========����д�����Ϣ===========\n";
					inCar(car, listPark);								//1.�˵�1��С����վ
					cout << "\n---��ǰͣ�ŵĳ���Ϊ��\n";
					DispList(listPark);									//��ʾͣ������Ϣ
				}
				else
				{
					if (SqQueueLength(inQueue) >= QMAX) {
						cout << "---�Ŷ�ͨ����������Ѱ������ͣ������";
					}
					else {
						cout << "\n---��������������д���������Ϣ���ŶӵȺ�";
						stCarInQ(carInQ);								//�Ŷӽ������
						enSqQueue(inQueue, carInQ);						//��carInQ�ŵ�����inQueue��

						cout << "\n---��ǰ�ŶӵȺ�ĳ���Ϊ��\n";
						DisplaySqQueue(inQueue, SqQueueLength(inQueue));//��ʾ��ǰ�ŶӵȺ�ĳ���
					}
				}
				break;
			case 2:
				cout << "\n\n===========����д������Ϣ===========\n";
				outCar(car, listPark, car1);							//2.�˵�2��:С����վ
				cout << "\n---��ǰͣ�ŵĳ���Ϊ��\n";
				DispList(listPark);										//��ʾͣ������Ϣ

				if (SqQueueLength(outQueue) >= QMAX) {
					cout << "---��վ�Ŷ�ͨ�����������Ժ�����Ŷӡ�";
				}
				else
				{
					cout << "---��ǰ���ɷѴ��Ŷӽ���";
					stCarOutQ(carOutQ, car);							//�Ŷӳ�����
					enSqQueue(outQueue, carOutQ);						//��carOutQ�ŵ�����outQueue��
					cout << "\n---��ǰ�ŶӵȺ�ĳ���Ϊ��\n";
					DisplaySqQueue2(outQueue, SqQueueLength(outQueue)); //��ʾ��ǰ�ŶӵȺ�ĳ���
				}
				break;
			case 3:
				carCharge(listPark, car1);								//3.�˵�3������
				break;
			case 4:
				//exit(0);												//4.�˵�4���˳�ϵͳ
				break;
			default:
				cout << "\n����˵��������������룡" << endl;
				goto menu;
				break;
			}
	} while (menu != 4);
	
	//����
	DestorySqQueue(inQueue);
	DestorySqQueue(outQueue);
	Destroy(listPark);

	//Visual Studio 2017 ����Ҫ���������ͣ���д��ڣ���������������Ҫ�����
	system("pause");		
	return 0;
}

