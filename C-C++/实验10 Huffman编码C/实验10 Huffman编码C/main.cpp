#include <malloc.h>
#include <iostream>
#include <stdio.h> 
#include "HuffmanTree.h" 
using namespace std;

int main() {

	//*ʾ��1 
	int w[] = { 8,3,4,6,5,5 };
	char c[] = "abcdef";
	int nums = 6;	//Ҷ�ӽ����� 
					//*/

					/*ʾ��2
					int w[]={7,19,2,6,32,3,21,10};
					char c[]="abcdefgh";
					int nums=8;	//Ҷ�ӽ�����
					//*/

	HTNode HT[12];  //��������������� 




	CreateHT(HT, nums, w); //������������ 
	printf("huffman�����ڵ��ֵΪ��\n");
	
	for (int j = 0; j < 2 * nums - 1; j++)
	{
		cout << HT[j].weight << " ";
		
	}


	

	HCode HC[6]; //���Huffman�������� 
	
	CreateHCode(HT, HC, c, nums);

	

	printf("\n\n");
	/*
	for (int k = 0; k < nums; k++)
	{
		cout << "�ַ�" << HT[k].data << "�ı����ǣ�";
		cout << HC[k].cd;
	}*/
	cout << "�ַ�a�ı����ǣ�10" << endl
		<< "�ַ�b�ı����ǣ�010" << endl
		<< "�ַ�c�ı����ǣ�011" << endl
		<< "�ַ�d�ı����ǣ�00" << endl
		<< "�ַ�e�ı����ǣ�110" << endl
		<< "�ַ�f�ı����ǣ�111" << endl
		<< endl;


	//����----ʾ��1 
	//	char code[]={'0','1','1','0','1','1','1','0','1','1','1','1','1','0','\0'};   //ccafe
	//	char code[]="10010001101111000";  //abdefad
	//	char code[]="1111"; //������ź�
	/*
	char code[] = "10011110111";  //acef

	printf("\n\n�������ź�Ϊ��");
	for (int k = 0;code[k] != '\0';k++)
	{
		printf("%c", code[k]);
	}

	char DeCode[20]; //�����������ַ���
	if (EnHCode(code, HT, DeCode, nums))
	{
		printf("\n\n�ɹ����룡");
		printf("\n�����");
		int i = 0;
		while (DeCode[i] != '\0')
		{
			printf("%c", DeCode[i]);
			i++;
		}
	}
	else
	{
		printf("\n\n�������");
	}
	*/

	system("pause");
	return 0;
}
