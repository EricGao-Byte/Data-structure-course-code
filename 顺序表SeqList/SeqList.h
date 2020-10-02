#pragma once
#include <stdio.h>
typedef int DataType;
const int MaxSize = 100;
typedef struct
{
	DataType list[MaxSize];
	int size;
}SeqList;

//���º����ɹ�����1,ʧ�ܷ���0

//��ʼ��
void ListInit(SeqList* L)
{
	L->size = 0;
}

//�����б���
int ListLength(SeqList L)
{
	return L.size;
}

//��������Ԫ��
int ListInsert(SeqList* L,int n,DataType x)
//�ڵ�n�����֮ǰ��������Ԫ��x
{
	int i;
	if (L->size>=MaxSize)  //Խ�籣��
	{
		printf("˳�������,�޷�����!\n");
		return 0;
	}
	else if (n<0||n>L->size)  //���뷶Χ����
	{
		printf("����λ�ò������Ϸ�!\n");
		return 0;
	}
	else
	{
		//�Ӻ���ǰ�����ƶ�����,Ϊ������׼��
		for ( i = L->size; i > n; i--)
		{
			L->list[i] = L->list[i - 1];
		}
		//�˳�ѭ��ʱ,i=n
		L->list[i] = x;
		L->size++;
		return 1;
	}

}

//ɾ������Ԫ��
int ListDelete(SeqList* L,int n,DataType* x)
//ɾ����n�����,��������Ԫ�ر��浽x�д���
{
	int i;
	if (L->size<=0)
	{
		printf("˳����ѿ�������Ԫ�ؿ�ɾ!\n");
		return 0;
	}
	else if (n<0||n>L->size-1)
	{
		printf("ɾ��λ�ò���n���Ϸ�!\n");
		return 0;
	}
	else
	{
		*x = L->list[n];
		//��ǰ�������ǰ��
		for ( i = n+1; i < L->size; i++)
		{
			L->list[i - 1] = L->list[i];
		}
		L->size--;
		return 1;
	}
}

//ȡԪ��
int ListGet(SeqList L, int n, DataType* x)
//ȡ��n������������,������x�д���
{
	int i;
	if (n<0||n>L.size-1)
	{
		printf("ȡԪ�صĲ������Ϸ�!\n");
		return 0;
	}
	else
	{
		*x = L.list[n];
		return 1;
	}
}

//��ӡԪ��
void ListPrint(SeqList L)
{
	int i;
	DataType elem;
	for ( i = 0; i < L.size; i++)
	{
		ListGet(L, i, &elem);
		printf("��%d��Ԫ��Ϊ: %d\n", i + 1, elem);
	}
}
