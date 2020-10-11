#pragma once
//  **打印队列示例**
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

//打印内容结构体
typedef struct
{
	int id;  //打印的任务编号
	char* text;  //要打印的内容
}PrintData;
typedef PrintData DataType;
typedef struct qnode
{
	DataType data;
	struct qnode* next;
}Task;

//打印队列结构体
typedef struct
{
	Task* rear;  //队尾指针
	Task* front;  //队头指针
}Queue;

//初始化
void InitTaskManager(Queue* TaskManager)
{
	TaskManager->rear = NULL;
	TaskManager->front = NULL;
}

//非空否
int TaskNotEmpty(Queue* TaskManager)
//空返回0,非空返回1
{
	if (TaskManager->front==NULL)  //队头为空则为空
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//入队列
void AppendPrintTask(Queue* TaskManager,int tid,char* text)
//将新的打印任务加入到队列队尾
//打印任务包括打印任务标识号和要打印的内容text
{
	Task* p;
	if ((p=(Task*)malloc(sizeof(Task)))==NULL)
	{
		printf("申请打印队列空间失败!\n");
		exit(1);
	}
	if ((p->data.text = (char*)malloc(strlen(text) * sizeof(Task) + 1)) == NULL)
	{
		printf("申请打印文本空间失败!\n");
		exit(1);
	}
	p->data.id = tid;
	p->next = NULL;
	if (TaskManager->rear!=NULL)  //rear指向非空时,在队尾添加新结点
	{
		TaskManager->rear->next = p;
	}
	TaskManager->rear = p;
	if (TaskManager->front==NULL)
	{
		TaskManager->front = p;  //队列原先为空时修改队头指针的特殊情况
	}
}

//出队列
int PrintFirstTask(Queue* TaskManager)
//取出taskmanager的第一个打印任务进行打印
//并将该任务从打印队列删除
{
	Task* p;
	if (TaskNotEmpty(TaskManager) == 0)  //队列为空
	{
		printf("队列已空,无法打印!\n");
		return 0;
	}
	else
	{
		p = TaskManager->front;
		//进行打印操作
		printf("打印任务id为: %d\n", p->data.id);
		printf("打印内容为: %s\n", p->data.text);
	}
	//删除第一个打印任务
	TaskManager->front = TaskManager->front->next;
	//若队列已空,则将队尾指针指向空指针
	if (TaskManager->front==NULL)
	{
		TaskManager->rear = NULL;
	}
	free(p);
	return 1;
}

//输出当前队列中的所有打印任务
void PrintAllTask(Queue* TaskManager)
{
	Task* p = TaskManager->front;
	while (p!=NULL)
	{
		printf("打印任务id为: %d\n", p->data.id);
		printf("打印内容为: %s\n", p->data.text);
		p = p->next;
	}
}

//清空打印队列
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