#pragma once
//  **队列**
#include <stdio.h>
typedef struct
{
	DataType queue[MaxQueueSize];
	int rear;  //队尾指针
	int front;  //队头指针;
}Queue;

//初始化
void QueueInit(Queue* Q)
{
	Q->rear = 0;  //定义初始队尾指针下标值
	Q->front = 0;  //定义初始队头指针下标值
}

//非空否
int QueueNotEmpty(Queue* Q)
//空返回0,非空返回1
{
	if (Q->rear == Q->front)  //队头和队尾重合则为空
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//入队列
int QueueAppend(Queue* Q, DataType x)
//在队列Q的队尾插入数据元素x,成功返回1,失败返回0
{
	if (Q->rear>=MaxQueueSize)
	{
		printf("队列已满,无法插入!\n");
		return 0;
	}
	Q->queue[Q->rear] = x;
	Q->rear++;
	return 1;
}

//出队列
int QueueDelete(Queue* Q, DataType* x)
//把队列头部数据元素删除并由参数x带回,成功返回1,失败返回0
{
	if (QueueNotEmpty(Q)==0)  //队列为空
	{
		printf("队列已空,无法删除!\n");
		return 0;
	}
	*x = Q->queue[Q->front];
	Q->front++;
	return 1;
}

//取队头数据元素
int QueueGet(Queue* Q, DataType* x)
//取出队头的数据元素并由参数x带回,成功返回1,失败返回0
{
	if (QueueNotEmpty(Q)==0)  //队列为空
	{
		printf("队列已空,无法取出!\n");
		return 0;
	}
	*x = Q->queue[Q->front];
	return 1;
}