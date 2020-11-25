#pragma once
#include <stdio.h>

typedef struct
{
	DataType list[MaxSize];
	int size;
}SeqList;

//以下函数成功返回1,失败返回0

//初始化
void ListInit(SeqList* L)
{
	L->size = 0;
}

//返回列表长度
int ListLength(SeqList* L)
{
	return L->size;
}

//插入数据元素
int ListInsert(SeqList* L,int n,DataType x)
//在第n个结点之前插入数据元素x
{
	int i;
	if (L->size>=MaxSize)  //越界保护
	{
		printf("顺序表已满,无法插入!\n");
		return 0;
	}
	else if (n<0||n>L->size)  //插入范围控制
	{
		printf("插入位置参数不合法!\n");
		return 0;
	}
	else
	{
		//从后往前依次移动数据,为插入做准备
		for ( i = L->size; i > n; i--)
		{
			L->list[i] = L->list[i - 1];
		}
		//退出循环时,i=n
		L->list[i] = x;
		L->size++;
		return 1;
	}

}

//删除数据元素
int ListDelete(SeqList* L,int n,DataType* x)
//删除第n个结点,并将数据元素保存到x中带出
{
	int i;
	if (L->size<=0)
	{
		printf("顺序表已空无数据元素可删!\n");
		return 0;
	}
	else if (n<0||n>L->size-1)
	{
		printf("删除位置参数n不合法!\n");
		return 0;
	}
	else
	{
		*x = L->list[n];
		//从前向后依次前移
		for ( i = n+1; i < L->size; i++)
		{
			L->list[i - 1] = L->list[i];
		}
		L->size--;
		return 1;
	}
}


//取元素
int ListGet(SeqList L, int n, DataType* x)
//取第n个结点的数据域,并存于x中带出
{
	int i;
	if (n<0||n>L.size-1)
	{
		printf("取元素的参数不合法!\n");
		return 0;
	}
	else
	{
		*x = L.list[n];
		return 1;
	}
}

////寻找元素,并输出寻找数据为x的元素的编号(从0开始),找不到则返回-1
//int ListFind(SeqList L,int x)
//{
//	int i;
//	for ( i = 0; i < ListLength(L); i++)
//	{
//		if (L.list[i]==x)
//		{
//			return i;
//		}
//	}
//	return -1;
//}


////打印元素
//void ListPrint(SeqList L)
//{
//	int i;
//	DataType elem;
//	for ( i = 0; i < L.size; i++)
//	{
//		ListGet(L, i, &elem);
//		printf("第%d个元素为: %d\n", i + 1, elem);
//	}
//}

//逆置顺序表
void ListReverse(SeqList* L)
{
	DataType t;
	int i;
	int length = ListLength(L);
	for ( i = 0; i < length/2; i++)
	{
		t = L->list[i];
		L->list[i] = L->list[length - 1 - i];
		L->list[length - 1 - i] = t;
	}
}
