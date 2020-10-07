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
}DCLNode;

//初始化
void ListInit(DCLNode** head)
{
	//申请头结点,将head指向它
	if ((*head = (DCLNode*)malloc(sizeof(DCLNode))) == NULL)
	{
		printf("申请头节点空间失败!\n");
		exit(1);
	}
	//结束指针指向NULL
	(*head)->next = *head;
	(*head)->prior = *head;
}

//求表长度
int ListLength(DCLNode* head)
{
	DCLNode* p;
	p = head;
	int size = 0;
	while (p->next != head)
	{
		p = p->next;
		size++;
	}
	return size;
}

//插入元素
int ListInsert(DCLNode* head, int n, DataType x)
//带头节点的单链表第n个结点前插入一个存放数据元素x的结点
{
	DCLNode* p, * q;
	int i;
	p = head;
	i = -1;
	while (p->next != head && i < n - 1)
		//最终指向第n个结点
	{
		p = p->next;
		i++;
	}
	if (i != n - 1)
	{
		printf("插入元素的位置参数有误!\n");
		return 1;
	}
	//申请插入空间
	if ((q = (DCLNode*)malloc(sizeof(DCLNode))) == NULL)
	{
		printf("申请插入结点的空间失败!\n");
		exit(1);
	}
	q->data = x;
	q->next = p->next;
	q->prior = p;
	p->next->prior = q;
	p->next = q;
	return 1;
}

//删除元素
int ListDelete(DCLNode* head, int n, DataType* x)
//删除带头节点单链表的第n个结点(n为数组下标),删除结点的数据由x带回
{
	DCLNode* p;
	int i;
	p = head;
	i = -1;
	while (p->next != head && p->next->next != head && i < n)
		//最终指向第n个结点
	{
		p = p->next;
		i++;
	}
	if (i != n)
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
int ListGet(DCLNode* head, int n, DataType* x)
{
	int i;
	DCLNode* p;
	p = head;
	i = -1;
	while (p->next != head && i < n)
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
DataType ListFind(DCLNode* head, DataType x)
{
	int i;
	DCLNode* p = head;
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
void ListDestroy(DCLNode** head)
{
	DCLNode* p, * p1;
	p = *head;
	while (p != *head)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	free(p);
	*head = NULL;
}
