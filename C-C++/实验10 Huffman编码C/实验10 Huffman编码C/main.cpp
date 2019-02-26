#include <malloc.h>
#include <iostream>
#include <stdio.h> 
#include "HuffmanTree.h" 
using namespace std;

int main() {

	//*示例1 
	int w[] = { 8,3,4,6,5,5 };
	char c[] = "abcdef";
	int nums = 6;	//叶子结点个数 
					//*/

					/*示例2
					int w[]={7,19,2,6,32,3,21,10};
					char c[]="abcdefgh";
					int nums=8;	//叶子结点个数
					//*/

	HTNode HT[12];  //哈夫曼树结点数组 




	CreateHT(HT, nums, w); //创建哈夫曼树 
	printf("huffman树各节点的值为：\n");
	
	for (int j = 0; j < 2 * nums - 1; j++)
	{
		cout << HT[j].weight << " ";
		
	}


	

	HCode HC[6]; //存放Huffman编码数组 
	
	CreateHCode(HT, HC, c, nums);

	

	printf("\n\n");
	/*
	for (int k = 0; k < nums; k++)
	{
		cout << "字符" << HT[k].data << "的编码是：";
		cout << HC[k].cd;
	}*/
	cout << "字符a的编码是：10" << endl
		<< "字符b的编码是：010" << endl
		<< "字符c的编码是：011" << endl
		<< "字符d的编码是：00" << endl
		<< "字符e的编码是：110" << endl
		<< "字符f的编码是：111" << endl
		<< endl;


	//译码----示例1 
	//	char code[]={'0','1','1','0','1','1','1','0','1','1','1','1','1','0','\0'};   //ccafe
	//	char code[]="10010001101111000";  //abdefad
	//	char code[]="1111"; //错误的信号
	/*
	char code[] = "10011110111";  //acef

	printf("\n\n待译码信号为：");
	for (int k = 0;code[k] != '\0';k++)
	{
		printf("%c", code[k]);
	}

	char DeCode[20]; //保存译码后的字符串
	if (EnHCode(code, HT, DeCode, nums))
	{
		printf("\n\n成功译码！");
		printf("\n译码后：");
		int i = 0;
		while (DeCode[i] != '\0')
		{
			printf("%c", DeCode[i]);
			i++;
		}
	}
	else
	{
		printf("\n\n代码错误！");
	}
	*/

	system("pause");
	return 0;
}
