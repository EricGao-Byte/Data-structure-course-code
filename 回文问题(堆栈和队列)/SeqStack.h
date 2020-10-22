#pragma once
#include <stdio.h>
typedef struct
{
	DataType stack[MaxStackSize];
	int top;  //ջ��λ��,Ҳ����ջ��Ԫ�ص��±�
}SeqStack;

//��ʼ��
void StackInit(SeqStack* S)
{
	S->top = -1;  //��ʼ��ջ���±�
}

//�ǿշ�
int StackNotEmpty(SeqStack S)
//Ϊ���򷵻�0,�ǿ��򷵻�1
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

//��ջ
int StackPush(SeqStack* S, DataType x)
//������Ԫ��ֵx����˳���ջS��,��ջ�ɹ�����1,ʧ�ܷ���0
{
	if (S->top>=MaxStackSize-1)
	{
		printf("��ջ�����޷�����!\n");
		return 0;
	}
	else
	{
		S->stack[S->top+1] = x;
		S->top++;
		return 1;
	}
}

//��ջ
int StackPop(SeqStack* S, DataType* x)
//ȡ��˳���ջS��ջ������Ԫ��ֵ�ɲ���x����,��ջ�ɹ�����1,ʧ�ܷ���0
{
	if (S->top<0)
	{
		printf("��ջ�ѿ�������Ԫ�س�ջ!\n");
		return 0;
	}
	else
	{
		*x = S->stack[S->top];
		S->top--;
		return 1;
	}
}

//ȡջ������Ԫ��
int StackTop(SeqStack S, DataType* x)
//ȡ˳��ջ��S��ǰջ��Ԫ��ֵ��x����,�ɹ�����1,ʧ�ܷ���0
{
	if (S.top<0)
	{
		printf("��ջ�ѿ�!\n");
		return 0;
	}
	else
	{
		*x = S.stack[S.top];
		return 1;
	}
}