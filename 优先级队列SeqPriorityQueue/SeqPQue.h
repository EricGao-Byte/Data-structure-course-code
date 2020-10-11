#pragma once
//  **顺序优先级队列**
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct
{
	int priority;  //优先级,数值越小优先级越高
	ElemType elem;  //其他内容
}DataType;

const int MaxQueueSize = 100;
typedef struct
{
	DataType queue[MaxQueueSize];
	int size;  //元素个数
}SeqPQueue;

//初始化
void QueueInit(SeqPQueue* Q)
{
	Q->size = 0;  //定义初始元素个数
}

//非空否
int QueueNotEmpty(SeqPQueue Q)
//空返回0,非空返回1
{
	if (Q.size <= 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//入队列
int QueueAppend(SeqPQueue* Q, DataType x)
//在队列Q的队尾插入数据元素x,成功返回1,失败返回0
{
	if (Q->size >= MaxQueueSize)
	{
		printf("队列已满,无法插入!\n");
		return 0;
	}
	else
	{
		Q->queue[Q->size] = x;  //数据元素x插入队尾
		Q->size++;  //队列元素个数+1
		return 1;
	}
}

//出队列
int QueueDelete(SeqPQueue* Q, DataType* x)
//把队列头部数据元素删除并由参数x带回,成功返回1,失败返回0
//出队列先遍历找到优先级最高的元素,并带回
//然后把后面的元素依次前移一个单位
{
	if (Q->size <= 0)  //队列为空
	{
		printf("队列已空,无法删除!\n");
		return 0;
	}

	//遍历找到优先级最高的元素
	DataType min = Q->queue[0];  //默认第一个元素为优先级最高的元素
	int minIndex = 0;
	int i;
	for ( i = 1; i < Q->size; i++)
	{
		if (Q->queue[i].priority<min.priority)
		{
			min = Q->queue[i];
			minIndex = i;
		}
	}
	*x = Q->queue[minIndex];
	//数据元素依次前移
	for ( i = minIndex; i < Q->size-1; i++)
	{
		Q->queue[i] = Q->queue[i + 1];
	}
	Q->size--;  //队列元素个数-1
}

