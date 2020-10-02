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
}SLNode;

//��ʼ��
void ListInit(SLNode** head)
{
	//����ͷ���,��headָ����
	if ((*head = (SLNode*)malloc(sizeof(SLNode))) == NULL)
	{
		printf("����ͷ�ڵ�ռ�ʧ��!\n");
		exit(1);
	}
	//����ָ��ָ��NULL
	(*head)->next = NULL;
}

//�����
int ListLength(SLNode* head)
{
	SLNode* p;
	p = head;
	int size = 0;
	while (p->next!=NULL)
	{
		p = p->next;
		size++;
	}
	return size;
}

//����Ԫ��
int ListInsert(SLNode* head, int n, DataType x)
//��ͷ�ڵ�ĵ������n�����ǰ����һ���������Ԫ��x�Ľ��
{
	SLNode* p, * q;
	int i;
	p = head;
	i = -1;
	while (p->next!=NULL&&i<n-1)
		//����ָ���i-1�����
	{
		p = p->next;
		i++;
	}
	if (i!=n-1)
	{
		printf("����Ԫ�ص�λ�ò�������!\n");
		return 1;
	}
	//�������ռ�
	if ((q = (SLNode*)malloc(sizeof(SLNode))) == NULL)
	{
		printf("���������Ŀռ�ʧ��!\n");
		exit(1);
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

//ɾ��Ԫ��
int ListDelete(SLNode* head, int n, DataType* x)
//ɾ����ͷ�ڵ㵥����ĵ�n�����(nΪ�����±�),ɾ������������x����
{
	SLNode* p, * s;
	int i;
	p = head;
	i = -1;
	while (p->next!=NULL&&p->next->next!=NULL&&i<n-1)
		//����ָ���i-1�����
	{
		p = p->next;
		i++;
	}
	if (i!=n-1)
	{
		printf("ɾ��Ԫ��λ�ò�������!\n");
		return 0;
	}

	s = p->next;
	*x = s->data;
	p->next = s->next;
	free(s);
	return 1;
}

//ȡԪ��
int ListGet(SLNode* head, int n, DataType* x)
{
	int i;
	SLNode* p;
	p = head;
	i = -1;
	while (p->next!=NULL&&i<n)
	{
		p = p->next;
		i++;
	}
	if (i!=n)
	{
		printf("ȡԪ��λ�ò�������!\n");
		return 0;
	}
	*x = p->data;
	return 1;
}

//��������
void ListDestroy(SLNode** head)
{
	SLNode* p, * p1;
	p = *head;
	while (p!=NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}
