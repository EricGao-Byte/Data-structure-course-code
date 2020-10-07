#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

const int MaxSize = 100;
typedef struct Node
{
	DataType data;
	struct Node* next;
}CSLNode;

//初始化
void ListInit(CSLNode** head)
{
	//申请头结点,将head指向它
	if ((*head = (CSLNode*)malloc(sizeof(CSLNode))) == NULL)
	{
		printf("申请头节点空间失败!\n");
		exit(1);
	}
	//结束指针指向自身也就是head
	(*head)->next = *head;
}

//求表长度
int ListLength(CSLNode* head)
{
	CSLNode* p;
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
int ListInsert(CSLNode* head, int n, DataType x)
//带头节点的单链表第n个结点前插入一个存放数据元素x的结点
{
	CSLNode* p, * q;
	int i;
	p = head;
	i = -1;
	while (p->next != head && i < n - 1)
		//最终指向第i-1个结点
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
	if ((q = (CSLNode*)malloc(sizeof(CSLNode))) == NULL)
	{
		printf("申请插入结点的空间失败!\n");
		exit(1);
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

//删除元素
int ListDelete(CSLNode* head, int n, DataType* x)
//删除带头节点单链表的第n个结点(n为数组下标),删除结点的数据由x带回
{
	CSLNode* p, * s;
	int i;
	p = head;
	i = -1;
	while (p->next != head && p->next->next != head && i < n - 1)
		//最终指向第i-1个结点
	{
		p = p->next;
		i++;
	}
	if (i != n - 1)
	{
		printf("删除元素位置参数错误!\n");
		return 0;
	}

	s = p->next;
	*x = s->data;
	p->next = s->next;
	free(s);
	return 1;
}

//取元素
int ListGet(CSLNode* head, int n, DataType* x)
{
	int i;
	CSLNode* p;
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

//链表是否非空,为空则返回0
int ListNotEmpty(CSLNode* head)
{
	if (head->next==head)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
////寻找元素
//DataType ListFind(CSLNode* head, DataType x)
//{
//	int i;
//	CSLNode* p = head;
//	for (i = -1; i < ListLength(p); i++)
//	{
//		if (p->data == x)
//		{
//			return i;
//		}
//	}
//	return -1;
//}


//销毁链表
void ListDestroy(CSLNode** head)
{
	CSLNode* p, * p1;
	p = (*head)->next;
	while (p != *head)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	free(p);
	*head = NULL;
}
