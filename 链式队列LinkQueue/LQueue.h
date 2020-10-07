#pragma once
//  **链式队列**
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct qnode
{
	DataType data;
	struct qnode* next;
}LQNode;

typedef struct
{
	LQNode* rear;  //队尾指针
	LQNode* front;  //队头指针
}LQueue;

//初始化
void QueueInit(LQueue* Q)
{
	Q->rear = NULL;
	Q->front = NULL;
}

//非空否
int QueueNotEmpty(LQueue* Q)
//空返回0,非空返回1
{
	if (Q->front==NULL)  //队头为空则为空
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//入队列
void QueueAppend(LQueue* Q, DataType x)
//在队列Q的队尾插入数据元素x
{
	LQNode* p;
	if ((p=(LQNode*)malloc(sizeof(LQNode)))==NULL)
	{
		exit(1);
	}
	p->data = x;
	p->next = NULL;
	if (Q->rear!=NULL)  //rear指向非空时,在队尾添加新结点
	{
		Q->rear->next = p;
	}
	Q->rear = p;
	if (Q->front==NULL)
	{
		Q->front = p;  //队列原先为空时修改队头指针的特殊情况
	}
}

//出队列
int QueueDelete(LQueue* Q, DataType* x)
//把队列头部数据元素删除并由参数x带回,成功返回1,失败返回0
{
	LQNode* p;
	if (QueueNotEmpty(Q) == 0)  //队列为空
	{
		printf("队列已空,无法删除!\n");
		return 0;
	}
	else
	{
		*x = Q->front->data;
		p = Q->front;
		Q->front = Q->front->next;
		if (Q->front==NULL)
		{
			Q->rear = NULL;
		}
		free(p);
		return 1;
	}
}

//取队头数据元素
int QueueGet(LQueue* Q, DataType* x)
//取出队头的数据元素并由参数x带回,成功返回1,失败返回0
{
	if (QueueNotEmpty(Q) == 0)  //队列为空
	{
		printf("队列已空,无法取出!\n");
		return 0;
	}
	else
	{
		*x = Q->front->data;
		return 1;
	}
}

//撤销动态申请空间
void Destroy(LQueue* Q)
{
	LQNode* p, * p1;
	p = Q->front;
	while (p!=NULL)
	{
		p1 = p;
		p = p->next;
		free(p);
	}
	Q->front = NULL;
	Q->rear = NULL;
}