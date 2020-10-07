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

//��ʼ��
void ListInit(DCLNode** head)
{
	//����ͷ���,��headָ����
	if ((*head = (DCLNode*)malloc(sizeof(DCLNode))) == NULL)
	{
		printf("����ͷ�ڵ�ռ�ʧ��!\n");
		exit(1);
	}
	//����ָ��ָ��NULL
	(*head)->next = *head;
	(*head)->prior = *head;
}

//�����
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

//����Ԫ��
int ListInsert(DCLNode* head, int n, DataType x)
//��ͷ�ڵ�ĵ������n�����ǰ����һ���������Ԫ��x�Ľ��
{
	DCLNode* p, * q;
	int i;
	p = head;
	i = -1;
	while (p->next != head && i < n - 1)
		//����ָ���n�����
	{
		p = p->next;
		i++;
	}
	if (i != n - 1)
	{
		printf("����Ԫ�ص�λ�ò�������!\n");
		return 1;
	}
	//�������ռ�
	if ((q = (DCLNode*)malloc(sizeof(DCLNode))) == NULL)
	{
		printf("���������Ŀռ�ʧ��!\n");
		exit(1);
	}
	q->data = x;
	q->next = p->next;
	q->prior = p;
	p->next->prior = q;
	p->next = q;
	return 1;
}

//ɾ��Ԫ��
int ListDelete(DCLNode* head, int n, DataType* x)
//ɾ����ͷ�ڵ㵥����ĵ�n�����(nΪ�����±�),ɾ������������x����
{
	DCLNode* p;
	int i;
	p = head;
	i = -1;
	while (p->next != head && p->next->next != head && i < n)
		//����ָ���n�����
	{
		p = p->next;
		i++;
	}
	if (i != n)
	{
		printf("ɾ��Ԫ��λ�ò�������!\n");
		return 0;
	}
	*x = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return 1;
}

//ȡԪ��
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
		printf("ȡԪ��λ�ò�������!\n");
		return 0;
	}
	*x = p->data;
	return 1;
}

//Ѱ��Ԫ��
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


//��������
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
