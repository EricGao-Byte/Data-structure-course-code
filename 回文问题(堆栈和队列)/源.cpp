// **回文问题**
// 问题描述: 使用堆栈和队列实现对一串字符判断是否为回文串
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
//分别从前往后和从后往前读取字符数组,并按顺序存入堆栈中,而后元素一个接一个出栈比较是否相等,只要有一个不相等,就不会回文串.全部字符出栈且都相等则为回文串
//不为回文串返回0,为回文串返回1
{
	int i;
	int strLen = strlen(s);
	SeqStack myStack1,myStack2;
	StackInit(&myStack1);
	StackInit(&myStack2);
	//从前往后读取数组,并入栈
	for ( i = 0; i < strLen; i++)
	{
		StackPush(&myStack1, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//从后往前读取数组,并入栈
	for (i = strLen - 1; i >= 0; i--)
	{
		StackPush(&myStack2, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//追位出栈比较
	//有一个不相等即不为回文串,就停止循环,返回0
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
//分别从前往后和从后往前读取字符数组,并按顺序存入队列中,而后元素一个接一个出队列比较是否相等,只要有一个不相等,就不会回文串.全部字符出栈且都相等则为回文串
//不为回文串返回0,为回文串返回1
{
	int i;
	int strLen = strlen(s);
	Queue myQue1, myQue2;
	QueueInit(&myQue1);
	QueueInit(&myQue2);
	//从前往后读取数组,并入队列
	for (i = 0; i < strLen; i++)
	{
		QueueAppend(&myQue1, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//从后往前读取数组,并入队列
	for (i = strLen - 1; i >= 0; i--)
	{
		QueueAppend(&myQue2, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//追位出队列比较
	//有一个不相等即不为回文串,就停止循环,返回0
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
//分别从前往后和从后往前读取字符数组,并按顺序存入队列中,而后元素一个接一个出队列比较是否相等,只要有一个不相等,就不会回文串.全部字符出栈且都相等则为回文串
//不为回文串返回0,为回文串返回1
{
	int i;
	int strLen = strlen(s);
	SeqStack myStack1, myStack2;
	StackInit(&myStack1);
	StackInit(&myStack2);
	Queue myQue1, myQue2;
	QueueInit(&myQue1);
	QueueInit(&myQue2);
	//从前往后读取数组,并入队列
	for (i = 0; i < strLen; i++)
	{
		StackPush(&myStack1, s[i]);
		QueueAppend(&myQue1, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//从后往前读取数组,并入队列
	for (i = strLen - 1; i >= 0; i--)
	{
		StackPush(&myStack2, s[i]);
		QueueAppend(&myQue2, s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
	//追位出队列比较
	//有一个不相等即不为回文串,就停止循环,返回0
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
//用链式堆栈判断回文串,不是回文串返回0,是回文串返回1
{
	//将数组读入堆栈
	int i;
	LSNode* myLStack;
	LStackInit(&myLStack);
	int strLen = strlen(s);
	for (i = 0; i < strLen; i++)
	{
		LStackPush(myLStack, s[i]);
	}
	//从前往后读数组和出堆栈元素依次比较
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
//用链式队列判断回文串,不是回文串返回0,是回文串返回1
{
	//将数组读入队列
	int i;
	LQueue myLQueue;
	LQueueInit(&myLQueue);
	int strLen = strlen(s);
	for ( i = 0; i < strLen; i++)
	{
		LQueueAppend(&myLQueue, s[i]);
	}
	//从后往前读数组和出队列元素依次比较
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
	//  堆栈测试
	printf("堆栈测试\n");
	char s1[] = "abcdedcba";
	char s2[] = "abcdedbba";
	if (isPalindromeByStack(s1))
	{
		printf("s1为回文串\n");
	}
	else
	{
		printf("s1为不回文串\n");
	}	
	if (isPalindromeByStack(s2))
	{
		printf("s2为回文串\n");
	}
	else
	{
		printf("s2为不回文串\n");
	}

	//  队列测试
	printf("队列测试\n");
	if (isPalindromeByQueue(s1))
	{
		printf("s1为回文串\n");
	}
	else
	{
		printf("s1为不回文串\n");
	}
	if (isPalindromeByQueue(s2))
	{
		printf("s2为回文串\n");
	}
	else
	{
		printf("s2为不回文串\n");
	}	

	//链式堆栈
	printf("链式堆栈测试\n");
	if (isPalindromeByLStack(s1))
	{
		printf("s1为回文串\n");
	}
	else
	{
		printf("s1为不回文串\n");
	}
	if (isPalindromeByLStack(s2))
	{
		printf("s2为回文串\n");
	}
	else
	{
		printf("s2为不回文串\n");
	}

	//链式队列
	printf("链式队列测试\n");
	if (isPalindromeByLQueue(s1))
	{
		printf("s1为回文串\n");
	}
	else
	{
		printf("s1为不回文串\n");
	}
	if (isPalindromeByLQueue(s2))
	{
		printf("s2为回文串\n");
	}
	else
	{
		printf("s2为不回文串\n");
	}




	return 0;
}
