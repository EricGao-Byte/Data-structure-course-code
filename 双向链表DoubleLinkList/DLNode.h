#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int DataType;
const int MaxSize = 100;
typedef struct Node
{
	DataType data;
	struct Node* next;
	struct Node* prior;
}DLNode;

//初始化
void ListInit(DLNode** head)
{
	//申请头结点,将head指向它
	if ((*head = (DLNode*)malloc(sizeof(DLNode))) == NULL)
	{
		printf("申请头节点空间失败!\n");
		exit(1);
	}
	//结束指针指向NULL
	(*head)->next = NULL;
	(*head)->prior = NULL;
}

//求表长度
int ListLength(DLNode* head)
{
	DLNode* p;
	p = head;
	int size = 0;
	while (p->next != NULL)
	{
		p = p->next;
		size++;
	}
	return size;
}

//插入元素
int ListInsert(DLNode* head, int n, DataType x)
//带头节点的单链表第n个结点前插入一个存放数据元素x的结点
{
	DLNode* p, * q;
	int i;
	p = head;
	i = -1;
	while (p->next != NULL && i < n-1 )
		//最终指向第n个结点
	{
		p = p->next;
		i++;
	}
	if (i != n-1 )
	{
		printf("插入元素的位置参数有误!\n");
		return 1;
	}
	//申请插入空间
	if ((q = (DLNode*)malloc(sizeof(DLNode))) == NULL)
	{
		printf("申请插入结点的空间失败!\n");
		exit(1);
	}
	q->data = x;
	q->next = NULL;
	q->prior = p;
	p->next = q;
	return 1;
}

//删除元素
int ListDelete(DLNode* head, int n, DataType* x)
//删除带头节点单链表的第n个结点(n为数组下标),删除结点的数据由x带回
{
	DLNode* p;
	int i;
	p = head;
	i = -1;
	while (p->next != NULL && p->next->next != NULL && i < n )
		//最终指向第n个结点
	{
		p = p->next;
		i++;
	}
	if (i != n )
	{
		printf("删除元素位置参数错误!\n");
		return 0;
	}
	*x = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return 1;
}

//取元素
int ListGet(DLNode* head, int n, DataType* x)
{
	int i;
	DLNode* p;
	p = head;
	i = -1;
	while (p->next != NULL && i < n)
	{
		p = p->next;
		i++;
	}
	if (i != n)
	{
		printf("取元素位置参数错误!\n");
		return 0;
	}
	*x = p->data;
	return 1;
}

//寻找元素
DataType ListFind(DLNode* head, DataType x)
{
	int i;
	DLNode* p = head;
	for (i = 0; i < ListLength(p); i++)
	{
		if (p->data == x)
		{
			return i;
		}
	}
	return -1;
}


//销毁链表
void ListDestroy(DLNode** head)
{
	DLNode* p, * p1;
	p = *head;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}
