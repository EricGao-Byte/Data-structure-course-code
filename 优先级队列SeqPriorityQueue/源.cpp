#include <stdio.h>
#include <stdlib.h>
#include "SeqPQue.h"

//  **本实例为操作系统的进程管理实例**
//  **每个进程由任务号和优先级号两部分组成***
//  **task.dat中存放了仿真进程服务请求数据**

int main()
{
	SeqPQueue myPQueue;
	FILE* fp;
	DataType task;
	int i;
	//if ((fp=fopen(&fp,"task.dat","r"))==NULL)  //申请文件指针
	//{
	//	printf("不能打开文件task.dat!\n");
	//	exit(0);
	//}	

	//visual studio读取文件必须使用函数fopen_s
	fopen_s(&fp, "task.dat", "r");
	if (fp==NULL)  //申请文件指针
	{
		printf("不能打开文件task.dat!\n");
		exit(0);
	}
	QueueInit(&myPQueue);
	while (!feof(fp))  //当文件没有读取到eof标志时
	{
		fscanf_s(fp, "%d %d", &task.elem, &task.priority);  //按照文件的格式读数据
		QueueAppend(&myPQueue, task);  //将数据读入队列
	}
	i = 1;
	printf("序号  任务号  优先级\n");
	while (QueueNotEmpty(myPQueue))  //出队列
	{
		QueueDelete(&myPQueue, &task);
		//输出格式控制
		printf("%d  %d  %d\n", i, task.elem, task.priority);
		i++;
	}
	return 0;
}
