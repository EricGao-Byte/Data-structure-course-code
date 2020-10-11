#include <stdio.h>
#include <stdlib.h>
#include "SeqPQue.h"

//  **��ʵ��Ϊ����ϵͳ�Ľ��̹���ʵ��**
//  **ÿ������������ź����ȼ������������***
//  **task.dat�д���˷�����̷�����������**

int main()
{
	SeqPQueue myPQueue;
	FILE* fp;
	DataType task;
	int i;
	//if ((fp=fopen(&fp,"task.dat","r"))==NULL)  //�����ļ�ָ��
	//{
	//	printf("���ܴ��ļ�task.dat!\n");
	//	exit(0);
	//}	

	//visual studio��ȡ�ļ�����ʹ�ú���fopen_s
	fopen_s(&fp, "task.dat", "r");
	if (fp==NULL)  //�����ļ�ָ��
	{
		printf("���ܴ��ļ�task.dat!\n");
		exit(0);
	}
	QueueInit(&myPQueue);
	while (!feof(fp))  //���ļ�û�ж�ȡ��eof��־ʱ
	{
		fscanf_s(fp, "%d %d", &task.elem, &task.priority);  //�����ļ��ĸ�ʽ������
		QueueAppend(&myPQueue, task);  //�����ݶ������
	}
	i = 1;
	printf("���  �����  ���ȼ�\n");
	while (QueueNotEmpty(myPQueue))  //������
	{
		QueueDelete(&myPQueue, &task);
		//�����ʽ����
		printf("%d  %d  %d\n", i, task.elem, task.priority);
		i++;
	}
	return 0;
}
