#include <iostream>
#include "SqString.h"
using namespace std;

SqString sqStr, matchStr;	//������������main����������ʼ��

int main()
{
	SqString encrypt(SqString p);			//��������
	SqString Unencrypt(SqString q);			//��������
	SqString p, q;
	char inputStr[MaxSize];					//���������ַ���
	char sqChar[MaxSize] = "abcdefghijklmnopqrstuvwxyz";		//˳���ַ���
	char matchChar[MaxSize] = "ngzqtcobmuhelkpdawxfyivrsj";		//ӳ���ַ���
	strAssign(sqStr, sqChar);
	strAssign(matchStr, matchChar);
	cout << "������Ҫ���ܵ��ַ�����" << endl;
	cin >> inputStr;
	strAssign(p, inputStr);
	cout << "��������ַ���Ϊ:" << endl;
	DispStr(p);
	q = encrypt(p);
	cout << "���ܺ���ַ���Ϊ:" << endl;
	DispStr(q);
	p = Unencrypt(q);
	cout << "���ܺ���ַ���Ϊ:" << endl;
	DispStr(p);

	system("pause");
	return 0;
}


SqString encrypt(SqString p){
	int i = 0, j = 0;
	SqString q;		//���ռ��ܶ�Ӧ���ַ�
	for (i = 0; i <= p.length; i++) {
		j = 0;
		while (p.data[i] != sqStr.data[j] && j < sqStr.length) {
			j++;	//��j���ƶ�Ӧӳ��λ�õ��ַ�
		}
		if (j >= sqStr.length)
			q.data[i] = p.data[i];
		else
			q.data[i] = matchStr.data[j];	//��ӳ����ַ������ַ���q������
	}
	q.length = p.length;
	return q;
}

SqString Unencrypt(SqString q){
	int i = 0, j;
	SqString p;		//���ս��ܶ�Ӧ���ַ�
	for (i = 0; i <= q.length; i++) {
		j = 0;
		while (q.data[i] != matchStr.data[j] && j < matchStr.length) {
			j++;	//��j���ƶ�Ӧ����λ�õ��ַ�
		}
		if (j >= matchStr.length)
			p.data[i] = q.data[i];
		else
			p.data[i] = sqStr.data[j];		//�����ܵ��ַ������ַ���q������
	}
	p.length = q.length;
	return p;
}

