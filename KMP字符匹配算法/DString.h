#pragma once
#define _CRT_SECURE_NO_WARNINGS
//  **��̬�ַ�����**
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

//��ʼ��
void Init(DString* S, int max, char* string)
//ʹ���û������string��max����ʼ����̬�ַ��������󳤶Ⱥ�����
{
	int i;
	if ((S->str = (char*)malloc(sizeof(char) * max)) == NULL)
	{
		printf("���붯̬�ַ�����ռ�ʧ��!\n");
		exit(1);
	}
	S->maxLength = max;
	S->length = strlen(string);
	//��ֵ
	for ( i = 0; i < S->length; i++)
	{
		S->str[i] = string[i];
	}
}

//�����Ӵ�
int Insert(DString* S, int pos, DString T)
//���Ӵ�T���뵽S���е�posλ��,�ɹ�����1,ʧ�ܷ���0
{
	int i;
	if (pos<0)
	{
		printf("����pos���Ϸ�!\n");
		return 0;
	}
	else
	{
		if (S->length+T.length>S->maxLength)
		{
			//��������ռ�
			realloc(S->str, (S->length + T.length) * sizeof(char));
			if (S->str==NULL)
			{
				printf("�����Ӵ���Ҫ��������ռ�ʧ��!\n");
				exit(1);
			}
			S->maxLength = S->length + T.length;
		}
		//�Ӻ���ǰ���κ���Ԫ��,Ϊ�Ӵ��ڳ��ռ�
		for ( i = S->length-1; i >= pos; i--)
		{
			S->str[i + T.length] = S->str[i];  //���κ���T.length����;
		}
		//��pos��������Ӵ�
		for ( i = 0; i < T.length; i++)
		{
			S->str[i + pos] = T.str[i];
		}
		S->length += T.length;
		return 1;
	}
}

//ɾ���Ӵ�
int Delete(DString* S, int pos, int len)
//ɾ��S����posλ�ÿ�ʼ�ĳ���Ϊlen���Ӵ�,ɾ���ɹ�����1,ʧ�ܷ���0
{
	int i;
	char* p;
	if (S->length<=0)
	{
		printf("��̬������Ԫ�ؿ�ɾ!\n");
		return 0;
	}
	else if(pos<0||len<0||pos+len>S->length)
	{
		printf("ɾ���Ӵ���λ�ò���pos�Ͳ���len����!\n");
		return 0;
	}
	else
	{
		//��pos��ʼ����ǰ��len��λ��
		for ( i = 0; i <= len; i++)
		{
			S->str[i + pos] = S->str[i + pos + len];
		}
		S->length = S->length - len;
		return 1;
	}
}

//ȡ�Ӵ�
int SubString(DString* S, int pos, int len, DString* Sub)
//ȡS��pos��ʼ,����Ϊlen���Ӵ�,��Sub����,�ɹ�����1,ʧ�ܷ���0
{
	int i;
	if (pos<0||len<0||pos+len>S->length)
	{
		printf("ȡ�Ӵ���λ�ò���pos�Ͳ���len����!\n");
		return 0;
	}
	else if(len>Sub->maxLength)
	{
		//�Ӵ��ռ䲻��,��������
		realloc(Sub->str, (len * sizeof(char)));
		if (Sub->str==NULL)
		{
			printf("���������Ӵ��ռ�ʧ��!\n");
			exit(1);
		}
		Sub->maxLength = len;
	}
	//��ֵ
	for (i = 0; i < len; i++)
	{
		Sub->str[i] = S->str[i + pos];
	}
	Sub->length = len;
	return 1;
}

//����
void Destroy(DString* S)
{
	free(S->str);
	S->length = S->maxLength = 0;
}

//��ӡ
void Print(DString S)
{
	int i;
	if (S.length<=0)
	{
		printf("��̬����Ϊ��!\n");
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
