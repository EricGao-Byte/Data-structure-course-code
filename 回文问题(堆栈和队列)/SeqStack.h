#pragma once
#include <stdio.h>
typedef struct
{
	DataType stack[MaxStackSize];
	int top;  //栈顶位置,也就是栈顶元素的下标
}SeqStack;

//初始化
void StackInit(SeqStack* S)
{
	S->top = -1;  //初始化栈顶下标
}

//非空否
int StackNotEmpty(SeqStack S)
//为空则返回0,非空则返回1
{
	if (S.top < 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//入栈
int StackPush(SeqStack* S, DataType x)
//把数据元素值x存入顺序堆栈S中,入栈成功返回1,失败返回0
{
	if (S->top>=MaxStackSize-1)
	{
		printf("堆栈已满无法插入!\n");
		return 0;
	}
	else
	{
		S->stack[S->top+1] = x;
		S->top++;
		return 1;
	}
}

//出栈
int StackPop(SeqStack* S, DataType* x)
//取出顺序堆栈S的栈顶数据元素值由参数x带回,出栈成功返回1,失败返回0
{
	if (S->top<0)
	{
		printf("堆栈已空无数据元素出栈!\n");
		return 0;
	}
	else
	{
		*x = S->stack[S->top];
		S->top--;
		return 1;
	}
}

//取栈顶数据元素
int StackTop(SeqStack S, DataType* x)
//取顺序栈顶S当前栈顶元素值由x带回,成功返回1,失败返回0
{
	if (S.top<0)
	{
		printf("堆栈已空!\n");
		return 0;
	}
	else
	{
		*x = S.stack[S.top];
		return 1;
	}
}