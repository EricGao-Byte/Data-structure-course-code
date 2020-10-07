#pragma once
//  **顺序循环队列**
#include <stdio.h>
typedef struct
{
	DataType queue[MaxQueueSize];
	int rear;  //队尾指针
	int front;  //队头指针
	int count;  //计数器,记录队列中元素的个数
}SeqCQue;

//初始化
void QueueInit(SeqCQue* Q)
{
	Q->rear = 0;  //定义初始队尾指针下标值
	Q->front = 0;  //定义初始队头指针下标值
	Q->count = 0;  //定义初始计数器值
}

//非空否
int QueueNotEmpty(SeqCQue Q)
//空返回0,非空返回1
{
	if (Q.count==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//入队列
int QueueAppend(SeqCQue* Q, DataType x)
//在队列Q的队尾插入数据元素x,成功返回1,失败返回0
{
	if (Q->count > 0 && Q->rear == Q->front)
	{
		printf("队列已满,无法插入!\n");
		return 0;
	}
	else
	{
		Q->queue[Q->rear] = x;  //数据元素x插入队尾
		Q->rear = (Q->rear + 1) % MaxQueueSize;  //队尾指示器+1,当队尾越过MaxQueSize时,整除操作使得下标重置为0
		Q->count++;  //队列元素个数+1
		return 1;
	}
}

//出队列
int QueueDelete(SeqCQue* Q, DataType* x)
//把队列头部数据元素删除并由参数x带回,成功返回1,失败返回0
{
	if (Q->count==0)  //队列为空
	{
		printf("队列已空,无法删除!\n");
		return 0;
	}
	*x = Q->queue[Q->front];
	Q->front=(Q->front+1)%MaxQueueSize;  //队头指示器+1,当队尾越过MaxQueSize时,整除操作使得下标重置为0
	Q->count--;  //队列元素个数-1
	return 1;
}

//取队头数据元素
int QueueGet(SeqCQue* Q, DataType* x)
//取出队头的数据元素并由参数x带回,成功返回1,失败返回0
{
	if (Q->count==0)  //队列为空
	{
		printf("队列已空,无法取出!\n");
		return 0;
	}
	else
	{
		*x = Q->queue[Q->front];
		return 1;
	}
}

