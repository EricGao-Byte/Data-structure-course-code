#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct snode
{
	DataType data;
	struct snode* next;
}LSNode;

//��ʼ��
void StackInit(LSNode** head)
{
	if ((*head=(LSNode*)malloc(sizeof(LSNode)))==NULL)
	{
		printf("����ͷ�ڵ�ռ�ʧ��!\n");
		exit(1);
	}
	(*head)->next = NULL;
}

//�ǿշ�
int StackNotEmpty(LSNode* head)
//�ж���ʽ��ջ�Ƿ�ǿ�,Ϊ�շ���0,�ǿշ���1
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

//��ջ
void StackPush(LSNode* head, DataType x)
//������Ԫ��ֵx������ʽ��ջS��
//���ڲ����ڲ��ܲ���Ԫ�ص����,���Ϊ����Ϊvoid����
{
	LSNode* p;
	if ((p = (LSNode*)malloc(sizeof(LSNode))) == NULL)
	{
		printf("������ջԪ�ؿռ�ʧ��!\n");
		exit(1);
	}
	p->data = x;
	p->next = head->next;
	head->next = p;
}

//��ջ
int StackPop(LSNode* head, DataType* x)
//ȡ����ʽ��ջS��ջ������Ԫ��ֵ�ɲ���x����,��ջ�ɹ�����1,ʧ�ܷ���0
{
	LSNode* p;
	p = head->next;
	if (head->next==NULL)
	{
		printf("��ջ�ѿճ���!\n");
		return 0;
	}
	head->next = p->next;
	*x = p->data;
	free(p);
	return 1;
}

//ȡջ������Ԫ��
int StackTop(LSNode* head, DataType* x)
//ȡ˳��ջ��S��ǰջ��Ԫ��ֵ��x����,�ɹ�����1,ʧ�ܷ���0
{
	LSNode* p;
	p = head->next;
	if (head->next==NULL)
	{
		printf("��ջ�ѿճ���!\n");
		return 0;
	}
	else
	{
		*x = p->data;
		return 1;
	}
}

//������̬����ռ�
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