#pragma once
const int MaxSize = 100;
typedef struct
{
	char str[MaxSize];
	int length;
}String;  //��̬����ṹ


//ͨ�����ö�̬����
typedef struct
{
	char* str;
	int maxLength;
	int length;
}DString;  //��̬����ṹ,�������û��Զ���


typedef struct Node
{
	char str;
	struct Node* next;
}SCharNode;  //���ַ������,�����ʺ�С

const int BlockSize = 100;
typedef struct Node
{
	char str[BlockSize];
	struct Node* next;
}NCharNode;  //����,size�Ƚϴ�ʱ�����ʽϴ�
