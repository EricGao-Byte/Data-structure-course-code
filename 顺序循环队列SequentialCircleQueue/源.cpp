
typedef int DataType;
const int MaxQueueSize = 10;
#include "SeqCQue.h"

int main()
{
	SeqCQue myQueue;
	QueueInit(&myQueue);
	int i;
	printf("插入三个元素\n");
	for (i = 0; i < 3; i++)
	{
		QueueAppend(&myQueue, i + 1);
	}
	printf("取出两次队列元素,结果为:\n");
	DataType x;
	for (i = 0; i < 2; i++)
	{
		QueueDelete(&myQueue, &x);
		printf("%d  ", x);
	}
	printf("\n队尾插入两次: \n");
	for (i = 0; i < 2; i++)
	{
		QueueAppend(&myQueue, i + 1);
	}
	printf("取出队列所有元素,结果为: \n");
	for (i = 0; i < 3; i++)
	{
		QueueDelete(&myQueue, &x);
		printf("%d  ", x);
	}
	return 0;
}