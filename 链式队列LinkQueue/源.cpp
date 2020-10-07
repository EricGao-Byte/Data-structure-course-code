typedef int DataType;
#include "LQueue.h"

int main()
{
	LQueue myQueue;
	QueueInit(&myQueue);
	int i;
	for (i = 0; i < 3; i++)
	{
		QueueAppend(&myQueue, i + 1);
	}
	printf("ȡ�����ζ���Ԫ��,���Ϊ:\n");
	DataType x;
	for (i = 0; i < 2; i++)
	{
		QueueDelete(&myQueue, &x);
		printf("%d  ", x);
	}
	printf("\n��β��������: \n");
	for (i = 0; i < 2; i++)
	{
		QueueAppend(&myQueue, i + 1);
	}
	printf("ȡ����������Ԫ��,���Ϊ: \n");
	for (i = 0; i < 3; i++)
	{
		QueueDelete(&myQueue, &x);
		printf("%d  ", x);
	}
	return 0;
}