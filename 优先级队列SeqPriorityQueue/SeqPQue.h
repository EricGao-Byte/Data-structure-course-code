#pragma once
//  **˳�����ȼ�����**
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct
{
	int priority;  //���ȼ�,��ֵԽС���ȼ�Խ��
	ElemType elem;  //��������
}DataType;

const int MaxQueueSize = 100;
typedef struct
{
	DataType queue[MaxQueueSize];
	int size;  //Ԫ�ظ���
}SeqPQueue;

//��ʼ��
void QueueInit(SeqPQueue* Q)
{
	Q->size = 0;  //�����ʼԪ�ظ���
}

//�ǿշ�
int QueueNotEmpty(SeqPQueue Q)
//�շ���0,�ǿշ���1
{
	if (Q.size <= 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//�����
int QueueAppend(SeqPQueue* Q, DataType x)
//�ڶ���Q�Ķ�β��������Ԫ��x,�ɹ�����1,ʧ�ܷ���0
{
	if (Q->size >= MaxQueueSize)
	{
		printf("��������,�޷�����!\n");
		return 0;
	}
	else
	{
		Q->queue[Q->size] = x;  //����Ԫ��x�����β
		Q->size++;  //����Ԫ�ظ���+1
		return 1;
	}
}

//������
int QueueDelete(SeqPQueue* Q, DataType* x)
//�Ѷ���ͷ������Ԫ��ɾ�����ɲ���x����,�ɹ�����1,ʧ�ܷ���0
//�������ȱ����ҵ����ȼ���ߵ�Ԫ��,������
//Ȼ��Ѻ����Ԫ������ǰ��һ����λ
{
	if (Q->size <= 0)  //����Ϊ��
	{
		printf("�����ѿ�,�޷�ɾ��!\n");
		return 0;
	}

	//�����ҵ����ȼ���ߵ�Ԫ��
	DataType min = Q->queue[0];  //Ĭ�ϵ�һ��Ԫ��Ϊ���ȼ���ߵ�Ԫ��
	int minIndex = 0;
	int i;
	for ( i = 1; i < Q->size; i++)
	{
		if (Q->queue[i].priority<min.priority)
		{
			min = Q->queue[i];
			minIndex = i;
		}
	}
	*x = Q->queue[minIndex];
	//����Ԫ������ǰ��
	for ( i = minIndex; i < Q->size-1; i++)
	{
		Q->queue[i] = Q->queue[i + 1];
	}
	Q->size--;  //����Ԫ�ظ���-1
}

