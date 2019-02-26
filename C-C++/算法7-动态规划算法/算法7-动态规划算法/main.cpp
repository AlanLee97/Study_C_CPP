#include <iostream>
#include <malloc.h>
using namespace std;

void sort(int *a,int len) {		//排序算法，从大到小排序
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - i - 1; j++) {
			int temp = 0;
			if (a[j] < a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void func(int a[],int n) {//n是数组元素个数
	
	int total_sequence = n * (n - 1) / 2;						//共有total_sequence个子序列
	int *result, *max;											//声明指针变量，用于存放子序列相加的结果
	result = (int *)malloc(total_sequence * sizeof(int));		//建立动态数组result，分配total_sequence个内存空间
	max = (int *)malloc(total_sequence * sizeof(int));			//建立动态数组max,将每一趟的最大值放到max数组中
	
	int i, j, sum = a[0];										//sum初始时为数组第一个值
	for (i = 0; i < n - 1; i++) {								//子序列相加
		for (j = i + 1; j < n ; j++) {//n = 6
			sum += a[j];										//用sum保存每一趟相加的值
			result[j] = sum;									//将每一趟保存的值放入result[]中

			if (j == i + 1) {									//控制这条提示语句只输出一次
				cout << "\n第" << (i + 1)
					<< "趟相加的值为：";
			}
			cout << result[j] << " ";							//输出每一趟的结果
		}
		sum = a[i + 1];											//给sum重新赋值，值为第i趟的第一个值
		cout << "\n";
		sort(result, total_sequence);							//对result数组从大到小排序,共有total_sequence个子序列
		max[i] = result[0];										//将每一趟的最大值放到max数组中
		
	}

	sort(max, total_sequence);									//对max数组从大到小排序,取出max中的最大值
	cout << "\n最大数是：" << max[0];


	free(result);	//释放内存空间
	free(max);
}

int main()
{
	
	int a[] = { -2, 11, -4, 13, -5, -2 };
	int len = sizeof(a) / sizeof(int);			//数组长度
	
	func(a,len);
	cout << endl;
	system("pause");
	return 0;
}

