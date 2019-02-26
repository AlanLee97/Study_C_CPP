#include <iostream>
#include "SqString.h"
using namespace std;

SqString sqStr, matchStr;	//这两个变量在main函数中作初始化

int main()
{
	SqString encrypt(SqString p);			//函数声明
	SqString Unencrypt(SqString q);			//函数声明
	SqString p, q;
	char inputStr[MaxSize];					//存放输入的字符串
	char sqChar[MaxSize] = "abcdefghijklmnopqrstuvwxyz";		//顺序字符串
	char matchChar[MaxSize] = "ngzqtcobmuhelkpdawxfyivrsj";		//映射字符串
	strAssign(sqStr, sqChar);
	strAssign(matchStr, matchChar);
	cout << "请输入要加密的字符串：" << endl;
	cin >> inputStr;
	strAssign(p, inputStr);
	cout << "你输入的字符串为:" << endl;
	DispStr(p);
	q = encrypt(p);
	cout << "加密后的字符串为:" << endl;
	DispStr(q);
	p = Unencrypt(q);
	cout << "解密后的字符串为:" << endl;
	DispStr(p);

	system("pause");
	return 0;
}


SqString encrypt(SqString p){
	int i = 0, j = 0;
	SqString q;		//接收加密对应的字符
	for (i = 0; i <= p.length; i++) {
		j = 0;
		while (p.data[i] != sqStr.data[j] && j < sqStr.length) {
			j++;	//用j控制对应映射位置的字符
		}
		if (j >= sqStr.length)
			q.data[i] = p.data[i];
		else
			q.data[i] = matchStr.data[j];	//将映射的字符赋给字符串q的数据
	}
	q.length = p.length;
	return q;
}

SqString Unencrypt(SqString q){
	int i = 0, j;
	SqString p;		//接收解密对应的字符
	for (i = 0; i <= q.length; i++) {
		j = 0;
		while (q.data[i] != matchStr.data[j] && j < matchStr.length) {
			j++;	//用j控制对应解密位置的字符
		}
		if (j >= matchStr.length)
			p.data[i] = q.data[i];
		else
			p.data[i] = sqStr.data[j];		//将解密的字符赋给字符串q的数据
	}
	p.length = q.length;
	return p;
}

