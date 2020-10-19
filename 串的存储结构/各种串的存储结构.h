#pragma once
const int MaxSize = 100;
typedef struct
{
	char str[MaxSize];
	int length;
}String;  //静态数组结构


//通常采用动态数组
typedef struct
{
	char* str;
	int maxLength;
	int length;
}DString;  //动态数组结构,长度由用户自定义


typedef struct Node
{
	char str;
	struct Node* next;
}SCharNode;  //单字符结点链,利用率很小

const int BlockSize = 100;
typedef struct Node
{
	char str[BlockSize];
	struct Node* next;
}NCharNode;  //块链,size比较大时利用率较大
