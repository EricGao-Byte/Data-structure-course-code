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

//��ʼ��
void ListInit(CSLNode** head)
{
	//����ͷ���,��headָ����
	if ((*head = (CSLNode*)malloc(sizeof(CSLNode))) == NULL)
	{
		printf("����ͷ�ڵ�ռ�ʧ��!\n");
		exit(1);
	}
	//����ָ��ָ������Ҳ����head
	(*head)->next = *head;
}

//�����
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

//����Ԫ��
int ListInsert(CSLNode* head, int n, DataType x)
//��ͷ�ڵ�ĵ������n�����ǰ����һ���������Ԫ��x�Ľ��
{
	CSLNode* p, * q;
	int i;
	p = head;
	i = -1;
	while (p->next != head && i < n - 1)
		//����ָ���i-1�����
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
	if ((q = (CSLNode*)malloc(sizeof(CSLNode))) == NULL)
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
int ListDelete(CSLNode* head, int n, DataType* x)
//ɾ����ͷ�ڵ㵥����ĵ�n�����(nΪ�����±�),ɾ������������x����
{
	CSLNode* p, * s;
	int i;
	p = head;
	i = -1;
	while (p->next != head && p->next->next != head && i < n - 1)
		//����ָ���i-1�����
	{
		p = p->next;
		i++;
	}
	if (i != n - 1)
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
		printf("ȡԪ��λ�ò�������!\n");
		return 0;
	}
	*x = p->data;
	return 1;
}

//�����Ƿ�ǿ�,Ϊ���򷵻�0
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
////Ѱ��Ԫ��
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


//��������
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
