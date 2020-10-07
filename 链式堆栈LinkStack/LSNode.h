#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct snode
{
	DataType data;
	struct snode* next;
}LSNode;

//初始化
void StackInit(LSNode** head)
{
	if ((*head=(LSNode*)malloc(sizeof(LSNode)))==NULL)
	{
		printf("申请头节点空间失败!\n");
		exit(1);
	}
	(*head)->next = NULL;
}

//非空否
int StackNotEmpty(LSNode* head)
//判断链式堆栈是否非空,为空返回0,非空返回1
{
	if (head->next==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//入栈
void StackPush(LSNode* head, DataType x)
//把数据元素值x存入链式堆栈S中
//由于不存在不能插入元素的情况,因此为函数为void类型
{
	LSNode* p;
	if ((p = (LSNode*)malloc(sizeof(LSNode))) == NULL)
	{
		printf("申请入栈元素空间失败!\n");
		exit(1);
	}
	p->data = x;
	p->next = head->next;
	head->next = p;
}

//出栈
int StackPop(LSNode* head, DataType* x)
//取出链式堆栈S的栈顶数据元素值由参数x带回,出栈成功返回1,失败返回0
{
	LSNode* p;
	p = head->next;
	if (head->next==NULL)
	{
		printf("堆栈已空出错!\n");
		return 0;
	}
	head->next = p->next;
	*x = p->data;
	free(p);
	return 1;
}

//取栈顶数据元素
int StackTop(LSNode* head, DataType* x)
//取顺序栈顶S当前栈顶元素值由x带回,成功返回1,失败返回0
{
	LSNode* p;
	p = head->next;
	if (head->next==NULL)
	{
		printf("堆栈已空出错!\n");
		return 0;
	}
	else
	{
		*x = p->data;
		return 1;
	}
}

//撤销动态申请空间
void Destroy(LSNode** head)
{
	LSNode* p, * p1;
	p = (*head);
	while (p!=NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}