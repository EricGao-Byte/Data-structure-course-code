// **��������**
// ��������: ʹ�ö�ջ�Ͷ���ʵ�ֶ�һ���ַ��ж��Ƿ�Ϊ���Ĵ�
#include <stdio.h>
#include <string.h>

const int MaxStackSize = 100;
typedef char DataType;
#include "SeqStack.h"
const int MaxQueueSize = 100;
#include "Queue.h"
#include "LStack.h"
#include "LQueue.h"

int isPalindromeByStack(char s[])
//�ֱ��ǰ����ʹӺ���ǰ��ȡ�ַ�����,����˳������ջ��,����Ԫ��һ����һ����ջ�Ƚ��Ƿ����,ֻҪ��һ�������,�Ͳ�����Ĵ�.ȫ���ַ���ջ�Ҷ������Ϊ���Ĵ�
//��Ϊ���Ĵ�����0,Ϊ���Ĵ�����1
{
	int i;
	int strLen = strlen(s);
	SeqStack myStack1,myStack2;
	StackInit(&myStack1);
	StackInit(&myStack2);
	//��ǰ�����ȡ����,����ջ
	for ( i = 0; i < strLen; i++)
	{
		StackPush(&myStack1, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//�Ӻ���ǰ��ȡ����,����ջ
	for (i = strLen - 1; i >= 0; i--)
	{
		StackPush(&myStack2, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//׷λ��ջ�Ƚ�
	//��һ������ȼ���Ϊ���Ĵ�,��ֹͣѭ��,����0
	char cmp1,cmp2;
	while (StackNotEmpty(myStack1))
	{
		StackPop(&myStack1, &cmp1);
		StackPop(&myStack2, &cmp2);
		if (cmp1 != cmp2)
		{
			return 0;
		}
	}
	return 1;
}

int isPalindromeByQueue(char s[])
//�ֱ��ǰ����ʹӺ���ǰ��ȡ�ַ�����,����˳����������,����Ԫ��һ����һ�������бȽ��Ƿ����,ֻҪ��һ�������,�Ͳ�����Ĵ�.ȫ���ַ���ջ�Ҷ������Ϊ���Ĵ�
//��Ϊ���Ĵ�����0,Ϊ���Ĵ�����1
{
	int i;
	int strLen = strlen(s);
	Queue myQue1, myQue2;
	QueueInit(&myQue1);
	QueueInit(&myQue2);
	//��ǰ�����ȡ����,�������
	for (i = 0; i < strLen; i++)
	{
		QueueAppend(&myQue1, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//�Ӻ���ǰ��ȡ����,�������
	for (i = strLen - 1; i >= 0; i--)
	{
		QueueAppend(&myQue2, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//׷λ�����бȽ�
	//��һ������ȼ���Ϊ���Ĵ�,��ֹͣѭ��,����0
	char cmp1, cmp2;
	while (QueueNotEmpty(&myQue1))
	{
		QueueDelete(&myQue1, &cmp1);
		QueueDelete(&myQue2, &cmp2);
		if (cmp1 != cmp2)
		{
			return 0;
		}
	}
	return 1;
}

int isPalindromeByStackAndQueue(char s[])
//�ֱ��ǰ����ʹӺ���ǰ��ȡ�ַ�����,����˳����������,����Ԫ��һ����һ�������бȽ��Ƿ����,ֻҪ��һ�������,�Ͳ�����Ĵ�.ȫ���ַ���ջ�Ҷ������Ϊ���Ĵ�
//��Ϊ���Ĵ�����0,Ϊ���Ĵ�����1
{
	int i;
	int strLen = strlen(s);
	SeqStack myStack1, myStack2;
	StackInit(&myStack1);
	StackInit(&myStack2);
	Queue myQue1, myQue2;
	QueueInit(&myQue1);
	QueueInit(&myQue2);
	//��ǰ�����ȡ����,�������
	for (i = 0; i < strLen; i++)
	{
		StackPush(&myStack1, s[i]);
		QueueAppend(&myQue1, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//�Ӻ���ǰ��ȡ����,�������
	for (i = strLen - 1; i >= 0; i--)
	{
		StackPush(&myStack2, s[i]);
		QueueAppend(&myQue2, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//׷λ�����бȽ�
	//��һ������ȼ���Ϊ���Ĵ�,��ֹͣѭ��,����0
	char cmp1, cmp2;
	while (QueueNotEmpty(&myQue1))
	{
		StackPop(&myStack1, &cmp1);
		StackPop(&myStack2, &cmp2);
		if (cmp1 != cmp2)
		{
			return 0;
		}
		QueueDelete(&myQue1, &cmp1);
		QueueDelete(&myQue2, &cmp2);
		if (cmp1 != cmp2)
		{
			return 0;
		}
	}
	return 1;
}

int isPalindromeByLStack(char s[])
//����ʽ��ջ�жϻ��Ĵ�,���ǻ��Ĵ�����0,�ǻ��Ĵ�����1
{
	//����������ջ
	int i;
	LSNode* myLStack;
	LStackInit(&myLStack);
	int strLen = strlen(s);
	for (i = 0; i < strLen; i++)
	{
		LStackPush(myLStack, s[i]);
	}
	//��ǰ���������ͳ���ջԪ�����αȽ�
	char cmp;
	for (i = 0; i < strLen; i++)
	{
		LStackPop(myLStack, &cmp);
		if (s[i] != cmp)
		{
			return 0;
		}
	}
	return 1;
}

int isPalindromeByLQueue(char s[])
//����ʽ�����жϻ��Ĵ�,���ǻ��Ĵ�����0,�ǻ��Ĵ�����1
{
	//������������
	int i;
	LQueue myLQueue;
	LQueueInit(&myLQueue);
	int strLen = strlen(s);
	for ( i = 0; i < strLen; i++)
	{
		LQueueAppend(&myLQueue, s[i]);
	}
	//�Ӻ���ǰ������ͳ�����Ԫ�����αȽ�
	char cmp;
	for (i = strLen - 1; i >= 0; i--)
	{
		LQueueDelete(&myLQueue, &cmp);
		if (s[i]!=cmp)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	//  ��ջ����
	printf("��ջ����\n");
	char s1[] = "abcdedcba";
	char s2[] = "abcdedbba";
	if (isPalindromeByStack(s1))
	{
		printf("s1Ϊ���Ĵ�\n");
	}
	else
	{
		printf("s1Ϊ�����Ĵ�\n");
	}	
	if (isPalindromeByStack(s2))
	{
		printf("s2Ϊ���Ĵ�\n");
	}
	else
	{
		printf("s2Ϊ�����Ĵ�\n");
	}

	//  ���в���
	printf("���в���\n");
	if (isPalindromeByQueue(s1))
	{
		printf("s1Ϊ���Ĵ�\n");
	}
	else
	{
		printf("s1Ϊ�����Ĵ�\n");
	}
	if (isPalindromeByQueue(s2))
	{
		printf("s2Ϊ���Ĵ�\n");
	}
	else
	{
		printf("s2Ϊ�����Ĵ�\n");
	}	

	//��ʽ��ջ
	printf("��ʽ��ջ����\n");
	if (isPalindromeByLStack(s1))
	{
		printf("s1Ϊ���Ĵ�\n");
	}
	else
	{
		printf("s1Ϊ�����Ĵ�\n");
	}
	if (isPalindromeByLStack(s2))
	{
		printf("s2Ϊ���Ĵ�\n");
	}
	else
	{
		printf("s2Ϊ�����Ĵ�\n");
	}

	//��ʽ����
	printf("��ʽ���в���\n");
	if (isPalindromeByLQueue(s1))
	{
		printf("s1Ϊ���Ĵ�\n");
	}
	else
	{
		printf("s1Ϊ�����Ĵ�\n");
	}
	if (isPalindromeByLQueue(s2))
	{
		printf("s2Ϊ���Ĵ�\n");
	}
	else
	{
		printf("s2Ϊ�����Ĵ�\n");
	}




	return 0;
}
