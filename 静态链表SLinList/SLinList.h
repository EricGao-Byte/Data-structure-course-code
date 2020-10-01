#pragma once
#include <stdio.h>
typedef int dataType;
typedef struct
{
	dataType data;  //数据域
	int cur;  //游标
}component;

const int MaxSize = 6;

//创建备用链表,备用链表的作用是回收数组中未使用或之前使用过（目前未使用）的存储空间，留待后期使用。
//事实上,创建备用链表的过程就是创建链表的过程
void SLinListReserve(component* array)
{
	for (int i = 0; i < MaxSize; i++)
	{
		array[i].cur = i + 1;  //将每一个数组分量链接到一起
		array[i].data = 0;
	}
	array[MaxSize - 1].cur = 0;  //链表最后一个节点的游标值为0
}

//提取分配空间,并返回申请空间的下标
int SLinListMalloc(component* array)
//若备用链表非空,则返回分配的节点下标,否则返回0(当且仅当分配到最后一个节点时,该节点的游标值为0)
{
	int i = array[0].cur;
	if (array[0].cur)
	{
		array[0].cur = array[i].cur;
	}
	return i;
}

//初始化静态数组
int SLinListInit(component* array)
{
	SLinListReserve(array);  //链接备用链表
	//从备用链表中拿出一个分量作为链表的头节点,返回的是这个分量的下标
	int body = SLinListMalloc(array);  //头节点位置
	int tempBody = 0;
	int i = 0;
	//建立首元节点
	array[body].data = 1;
	array[body].cur = 0;
	//声明一个变量,将它当指针使用,指向链表的最后一个结点,当前和首元结点重合
	tempBody = body;
	//初始化一段静态链表
	for (i = 2; i < 4; i++)
	{
		int j = SLinListMalloc(array);  //从备用链表中拿出空闲的分量
		array[j].data = i;  //初始化新的到的空间结点
		array[tempBody].cur = j;  //将新的到的结点链接到数据链表的尾部
		tempBody = j;
	}
	array[tempBody].cur = 0;  //新的链表最后一个结点指针设置为0
	return body;  //返回头节点位置
}

//插入元素,将x插入为第n个结点
void SLinListInsert(component* array, int body, int n, dataType x)
{
	int tempBody = body;
	int i = 0, insert = 0;
	//找到插入位置的上一个结点的位置
	for (i = 1; i < n; i++)
	{
		tempBody = array[tempBody].cur;
	}
	insert = SLinListMalloc(array);  //申请空间
	array[insert].data = x;

	array[insert].cur = array[tempBody].cur;  //新插入结点的游标等于其直接前驱结点的游标
	array[tempBody].cur = insert;  //前驱结点的游标等于插入结点的下标
}

//删除元素,针对无头节点的情况,针对有删除头节点的情况建议增加一个空白head结点
int SLinListDelete(component* array, int body, dataType n)
//删除数据为n个结点,返回删除结点后静态链表头节点的位置
{
	void SLinListFree(component * array, int n);
	int tempBody = body;
	int del = 0;
	int newBody = 0;
	//寻找被删除结点的位置
	while (array[tempBody].data != n)
	{
		tempBody = array[tempBody].cur;
		if (tempBody == 0)  //为0表示链表遍历结束了也没找到结点
		{
			printf("链表中无此数据!!\n");
			return NULL;
		}
	}
	//运行到此,证明找到了结点
	del = tempBody;
	tempBody = body;
	//删除首元结点的特殊情况
	if (del = body)
	{
		newBody = array[del].cur;
		SLinListFree(array, del);
		return newBody;
	}
	else
	{
		//找到该结点的上一个结点
		while (array[tempBody].cur != del)
		{
			tempBody = array[tempBody].cur;  //遍历
		}

		//将被删除结点的游标直接给被删除结点的上一个结点
		array[tempBody].cur = array[del].cur;
		SLinListFree(array, del);
		return body;
	}
}

//查找链表元素
//查找数据为n的结点的位置
int SLinListFind(component* array, int body, dataType n)
{
	int tempBody = body;
	//当游标值为0时,表示链表结束
	while (array[tempBody].cur != 0)
	{
		if (array[tempBody].data == n)
		{
			return tempBody;
		}
		tempBody = array[tempBody].cur;
	}
	//判断最后一个结点是否符合要求
	if (array[tempBody].data == n)
	{
		return tempBody;
	}
	return -1;  //表示没有找到元素
}

//修改数据
void SLinListModify(component* array, int body, dataType oldData, dataType newData)
{
	int n = SLinListFind(array, body, oldData);
	if (n == -1)
	{
		printf("无更改元素!!\n");
		return;
	}
	array[n].data = newData;
}

//备用链表回收空间的函数，其中array为存储数据的数组，k表示未使用节点所在数组的下标
void SLinListFree(component* array, int n)
{
	array[n].cur = array[0].cur;
	array[0].cur = n;
}

//打印静态数组
void SLinListDisplay(component* array, int body)
{
	int tempBody = body;  //tempBody用作遍历变量
	while (array[tempBody].cur)
	{
		printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
		tempBody = array[tempBody].cur;
	}
	printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
}