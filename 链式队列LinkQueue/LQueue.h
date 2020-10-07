#pragma once
//  **��ʽ����**
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
	LQNode* rear;  //��βָ��
	LQNode* front;  //��ͷָ��
}LQueue;

//��ʼ��
void QueueInit(LQueue* Q)
{
	Q->rear = NULL;
	Q->front = NULL;
}

//�ǿշ�
int QueueNotEmpty(LQueue* Q)
//�շ���0,�ǿշ���1
{
	if (Q->front==NULL)  //��ͷΪ����Ϊ��
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//�����
void QueueAppend(LQueue* Q, DataType x)
//�ڶ���Q�Ķ�β��������Ԫ��x
{
	LQNode* p;
	if ((p=(LQNode*)malloc(sizeof(LQNode)))==NULL)
	{
		exit(1);
	}
	p->data = x;
	p->next = NULL;
	if (Q->rear!=NULL)  //rearָ��ǿ�ʱ,�ڶ�β����½��
	{
		Q->rear->next = p;
	}
	Q->rear = p;
	if (Q->front==NULL)
	{
		Q->front = p;  //����ԭ��Ϊ��ʱ�޸Ķ�ͷָ����������
	}
}

//������
int QueueDelete(LQueue* Q, DataType* x)
//�Ѷ���ͷ������Ԫ��ɾ�����ɲ���x����,�ɹ�����1,ʧ�ܷ���0
{
	LQNode* p;
	if (QueueNotEmpty(Q) == 0)  //����Ϊ��
	{
		printf("�����ѿ�,�޷�ɾ��!\n");
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

//ȡ��ͷ����Ԫ��
int QueueGet(LQueue* Q, DataType* x)
//ȡ����ͷ������Ԫ�ز��ɲ���x����,�ɹ�����1,ʧ�ܷ���0
{
	if (QueueNotEmpty(Q) == 0)  //����Ϊ��
	{
		printf("�����ѿ�,�޷�ȡ��!\n");
		return 0;
	}
	else
	{
		*x = Q->front->data;
		return 1;
	}
}

//������̬����ռ�
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