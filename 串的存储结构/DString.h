#pragma once
#define _CRT_SECURE_NO_WARNINGS
//  **动态字符数组**
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
	char* str;
	int maxLength;
	int length;
}DString;

//初始化
void Init(DString* S, int max, char* string)
//使用用户输入的string和max来初始化动态字符数组的最大长度和内容
{
	int i;
	if ((S->str = (char*)malloc(sizeof(char) * max)) == NULL)
	{
		printf("申请动态字符数组空间失败!\n");
		exit(1);
	}
	S->maxLength = max;
	S->length = strlen(string);
	//赋值
	for ( i = 0; i < S->length; i++)
	{
		S->str[i] = string[i];
	}
}

//插入子串
int Insert(DString* S, int pos, DString T)
//将子串T插入到S串中的pos位置,成功返回1,失败返回0
{
	int i;
	if (pos<0)
	{
		printf("参数pos不合法!\n");
		return 0;
	}
	else
	{
		if (S->length+T.length>S->maxLength)
		{
			//重新申请空间
			realloc(S->str, (S->length + T.length) * sizeof(char));
			if (S->str==NULL)
			{
				printf("插入子串需要重新申请空间失败!\n");
				exit(1);
			}
			S->maxLength = S->length + T.length;
		}
		//从后往前依次后移元素,为子串腾出空间
		for ( i = S->length-1; i >= pos; i--)
		{
			S->str[i + T.length] = S->str[i];  //依次后移T.length长度;
		}
		//从pos往后插入子串
		for ( i = 0; i < T.length; i++)
		{
			S->str[i + pos] = T.str[i];
		}
		S->length += T.length;
		return 1;
	}
}

//删除子串
int Delete(DString* S, int pos, int len)
//删除S串中pos位置开始的长度为len的子串,删除成功返回1,失败返回0
{
	int i;
	char* p;
	if (S->length<=0)
	{
		printf("动态数组无元素可删!\n");
		return 0;
	}
	else if(pos<0||len<0||pos+len>S->length)
	{
		printf("删除子串的位置参数pos和参数len有误!\n");
		return 0;
	}
	else
	{
		//从pos开始依次前移len个位置
		for ( i = 0; i <= len; i++)
		{
			S->str[i + pos] = S->str[i + pos + len];
		}
		S->length = S->length - len;
		return 1;
	}
}

//取子串
int SubString(DString* S, int pos, int len, DString* Sub)
//取S中pos开始,长度为len的子串,由Sub带回,成功返回1,失败返回0
{
	int i;
	if (pos<0||len<0||pos+len>S->length)
	{
		printf("取子串的位置参数pos和参数len有误!\n");
		return 0;
	}
	else if(len>Sub->maxLength)
	{
		//子串空间不足,重新申请
		realloc(Sub->str, (len * sizeof(char)));
		if (Sub->str==NULL)
		{
			printf("重新申请子串空间失败!\n");
			exit(1);
		}
		Sub->maxLength = len;
	}
	//赋值
	for (i = 0; i < len; i++)
	{
		Sub->str[i] = S->str[i + pos];
	}
	Sub->length = len;
	return 1;
}

//撤销
void Destroy(DString* S)
{
	free(S->str);
	S->length = S->maxLength = 0;
}

//打印
void Print(DString S)
{
	int i;
	if (S.length<=0)
	{
		printf("动态数组为空!\n");
	}
	else
	{
		for ( i = 0; i < S.length; i++)
		{
			printf("%c", S.str[i]);
		}
		printf("\n");
	}
}
