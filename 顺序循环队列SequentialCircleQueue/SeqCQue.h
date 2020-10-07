#pragma once
//  **˳��ѭ������**
#include <stdio.h>
typedef struct
{
	DataType queue[MaxQueueSize];
	int rear;  //��βָ��
	int front;  //��ͷָ��
	int count;  //������,��¼������Ԫ�صĸ���
}SeqCQue;

//��ʼ��
void QueueInit(SeqCQue* Q)
{
	Q->rear = 0;  //�����ʼ��βָ���±�ֵ
	Q->front = 0;  //�����ʼ��ͷָ���±�ֵ
	Q->count = 0;  //�����ʼ������ֵ
}

//�ǿշ�
int QueueNotEmpty(SeqCQue Q)
//�շ���0,�ǿշ���1
{
	if (Q.count==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//�����
int QueueAppend(SeqCQue* Q, DataType x)
//�ڶ���Q�Ķ�β��������Ԫ��x,�ɹ�����1,ʧ�ܷ���0
{
	if (Q->count > 0 && Q->rear == Q->front)
	{
		printf("��������,�޷�����!\n");
		return 0;
	}
	else
	{
		Q->queue[Q->rear] = x;  //����Ԫ��x�����β
		Q->rear = (Q->rear + 1) % MaxQueueSize;  //��βָʾ��+1,����βԽ��MaxQueSizeʱ,��������ʹ���±�����Ϊ0
		Q->count++;  //����Ԫ�ظ���+1
		return 1;
	}
}

//������
int QueueDelete(SeqCQue* Q, DataType* x)
//�Ѷ���ͷ������Ԫ��ɾ�����ɲ���x����,�ɹ�����1,ʧ�ܷ���0
{
	if (Q->count==0)  //����Ϊ��
	{
		printf("�����ѿ�,�޷�ɾ��!\n");
		return 0;
	}
	*x = Q->queue[Q->front];
	Q->front=(Q->front+1)%MaxQueueSize;  //��ͷָʾ��+1,����βԽ��MaxQueSizeʱ,��������ʹ���±�����Ϊ0
	Q->count--;  //����Ԫ�ظ���-1
	return 1;
}

//ȡ��ͷ����Ԫ��
int QueueGet(SeqCQue* Q, DataType* x)
//ȡ����ͷ������Ԫ�ز��ɲ���x����,�ɹ�����1,ʧ�ܷ���0
{
	if (Q->count==0)  //����Ϊ��
	{
		printf("�����ѿ�,�޷�ȡ��!\n");
		return 0;
	}
	else
	{
		*x = Q->queue[Q->front];
		return 1;
	}
}

