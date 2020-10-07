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

//��ʼ��
void ListInit(DLNode** head)
{
	//����ͷ���,��headָ����
	if ((*head = (DLNode*)malloc(sizeof(DLNode))) == NULL)
	{
		printf("����ͷ�ڵ�ռ�ʧ��!\n");
		exit(1);
	}
	//����ָ��ָ��NULL
	(*head)->next = NULL;
	(*head)->prior = NULL;
}

//�����
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

//����Ԫ��
int ListInsert(DLNode* head, int n, DataType x)
//��ͷ�ڵ�ĵ������n�����ǰ����һ���������Ԫ��x�Ľ��
{
	DLNode* p, * q;
	int i;
	p = head;
	i = -1;
	while (p->next != NULL && i < n-1 )
		//����ָ���n�����
	{
		p = p->next;
		i++;
	}
	if (i != n-1 )
	{
		printf("����Ԫ�ص�λ�ò�������!\n");
		return 1;
	}
	//�������ռ�
	if ((q = (DLNode*)malloc(sizeof(DLNode))) == NULL)
	{
		printf("���������Ŀռ�ʧ��!\n");
		exit(1);
	}
	q->data = x;
	q->next = NULL;
	q->prior = p;
	p->next = q;
	return 1;
}

//ɾ��Ԫ��
int ListDelete(DLNode* head, int n, DataType* x)
//ɾ����ͷ�ڵ㵥����ĵ�n�����(nΪ�����±�),ɾ������������x����
{
	DLNode* p;
	int i;
	p = head;
	i = -1;
	while (p->next != NULL && p->next->next != NULL && i < n )
		//����ָ���n�����
	{
		p = p->next;
		i++;
	}
	if (i != n )
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
		printf("ȡԪ��λ�ò�������!\n");
		return 0;
	}
	*x = p->data;
	return 1;
}

//Ѱ��Ԫ��
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


//��������
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
