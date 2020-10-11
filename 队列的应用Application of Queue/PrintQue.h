#pragma once
//  **��ӡ����ʾ��**
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

//��ӡ���ݽṹ��
typedef struct
{
	int id;  //��ӡ��������
	char* text;  //Ҫ��ӡ������
}PrintData;
typedef PrintData DataType;
typedef struct qnode
{
	DataType data;
	struct qnode* next;
}Task;

//��ӡ���нṹ��
typedef struct
{
	Task* rear;  //��βָ��
	Task* front;  //��ͷָ��
}Queue;

//��ʼ��
void InitTaskManager(Queue* TaskManager)
{
	TaskManager->rear = NULL;
	TaskManager->front = NULL;
}

//�ǿշ�
int TaskNotEmpty(Queue* TaskManager)
//�շ���0,�ǿշ���1
{
	if (TaskManager->front==NULL)  //��ͷΪ����Ϊ��
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//�����
void AppendPrintTask(Queue* TaskManager,int tid,char* text)
//���µĴ�ӡ������뵽���ж�β
//��ӡ���������ӡ�����ʶ�ź�Ҫ��ӡ������text
{
	Task* p;
	if ((p=(Task*)malloc(sizeof(Task)))==NULL)
	{
		printf("�����ӡ���пռ�ʧ��!\n");
		exit(1);
	}
	if ((p->data.text = (char*)malloc(strlen(text) * sizeof(Task) + 1)) == NULL)
	{
		printf("�����ӡ�ı��ռ�ʧ��!\n");
		exit(1);
	}
	p->data.id = tid;
	p->next = NULL;
	if (TaskManager->rear!=NULL)  //rearָ��ǿ�ʱ,�ڶ�β����½��
	{
		TaskManager->rear->next = p;
	}
	TaskManager->rear = p;
	if (TaskManager->front==NULL)
	{
		TaskManager->front = p;  //����ԭ��Ϊ��ʱ�޸Ķ�ͷָ����������
	}
}

//������
int PrintFirstTask(Queue* TaskManager)
//ȡ��taskmanager�ĵ�һ����ӡ������д�ӡ
//����������Ӵ�ӡ����ɾ��
{
	Task* p;
	if (TaskNotEmpty(TaskManager) == 0)  //����Ϊ��
	{
		printf("�����ѿ�,�޷���ӡ!\n");
		return 0;
	}
	else
	{
		p = TaskManager->front;
		//���д�ӡ����
		printf("��ӡ����idΪ: %d\n", p->data.id);
		printf("��ӡ����Ϊ: %s\n", p->data.text);
	}
	//ɾ����һ����ӡ����
	TaskManager->front = TaskManager->front->next;
	//�������ѿ�,�򽫶�βָ��ָ���ָ��
	if (TaskManager->front==NULL)
	{
		TaskManager->rear = NULL;
	}
	free(p);
	return 1;
}

//�����ǰ�����е����д�ӡ����
void PrintAllTask(Queue* TaskManager)
{
	Task* p = TaskManager->front;
	while (p!=NULL)
	{
		printf("��ӡ����idΪ: %d\n", p->data.id);
		printf("��ӡ����Ϊ: %s\n", p->data.text);
		p = p->next;
	}
}

//��մ�ӡ����
void ClearPrintTask(Queue* TaskManager)
{
	Task* p, * p1;
	p = TaskManager->front;
	while (p!=NULL)
	{
		p1 = p;
		p = p->next;
		free(p1->data.text);
		free(p1);
	}
	TaskManager->front = NULL;
	TaskManager->rear = NULL;
}