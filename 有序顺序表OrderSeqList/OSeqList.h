#pragma once
#include <stdio.h>

typedef struct
{
	DataType list[MaxSize];
	int size;
}OSeqList;
//有序顺序表,在此处表中的元素从小到大排列

// 以下函数成功返回1, 失败返回0

//初始化
void ListInit(OSeqList* L)
{
	L->size = 0;
}

//返回列表长度
int ListLength(OSeqList* L)
{
	return L->size;
}

//插入数据元素
int ListInsert(OSeqList* L, DataType x)
//将数据元素x插入有序顺序表的适当位置
{
	int ListInsertFind(OSeqList* L, DataType x);
	int i, n;
	n = ListInsertFind(L, x);  //寻找x的位置
	if (L->size >= MaxSize)  //越界保护
	{
		printf("顺序表已满,无法插入!\n");
		return 0;
	}
	else if (n<0 || n>L->size)  //插入范围控制
	{
		printf("插入位置参数不合法!\n");
		return 0;
	}
	else
	{
		//从后往前依次移动数据,为插入做准备
		for (i = L->size; i > n; i--)
		{
			L->list[i] = L->list[i - 1];
		}
		//退出循环时,i=n
		L->list[i] = x;
		L->size++;
		return 1;
	}
}

//寻找数据元素x在表中的位置
int ListFind(OSeqList* L, DataType x)
//使用二分法寻找数据元素并返回编号,找不到则返回-1
{
	int low = 0;
	int high = ListLength(L) - 1;
	while (low<=high)
	{
		int mid = (low + high) / 2;
		DataType midVal = L->list[mid];
		if (midVal<x)
		{
			low = mid + 1;
		}
		else if (midVal>x)
		{
			high = mid - 1;
		}
		else
		{
			return mid;  //返回寻找到的元素的编号
		}
	}
	return -1;
}

//删除数据元素
int ListDelete(OSeqList* L, int n, DataType* x)
//删除第n个结点,并将数据元素保存到x中带出
{
	int i;
	if (L->size <= 0)
	{
		printf("顺序表已空无数据元素可删!\n");
		return 0;
	}
	else if (n<0 || n>L->size - 1)
	{
		printf("删除位置参数n不合法!\n");
		return 0;
	}
	else
	{
		*x = L->list[n];
		//从前向后依次前移
		for (i = n + 1; i < L->size; i++)
		{
			L->list[i - 1] = L->list[i];
		}
		L->size--;
		return 1;
	}
}

//寻找元素x在表中的的插入位置
int ListInsertFind(OSeqList* L, DataType x)
{
	int low = 0;
	int high = ListLength(L) - 1;
	if (high==-1)  //为空表
	{
		return 0;
	}
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int midPre = mid - 1;
		int midAft = mid + 1;
		DataType midVal = L->list[mid];
		DataType midPreVal = L->list[midPre];
		DataType midAftVal = L->list[midAft];
		if (midPre<0&&midVal>x)
		{
			return mid;
		}
		else if (midAft>ListLength(L)-1&&midVal<x)
		{
			return midAft;
		}
		else if (midVal==x)
		{
			return mid;
		}
		else if (midVal>x&&midPreVal<x)
		{
			return mid;
		}
		else if (midVal<x&&midAftVal>x)
		{
			return midAft;
		}
		if (midVal < x)
		{
			low = mid + 1;
		}
		else if (midVal > x)
		{
			high = mid - 1;
		}
	}
	return -1;
}

// 取元素
int ListGet(OSeqList L, int n, DataType * x)
//取第n个结点的数据域,并存于x中带出
{
	int i;
	if (n<0 || n>L.size - 1)
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

//打印元素
void ListPrint(OSeqList L)
{
	int i;
	DataType elem;
	for (i = 0; i < L.size; i++)
	{
		ListGet(L, i, &elem);
		printf("第%d个元素为: %d\n", i + 1, elem);
	}
}