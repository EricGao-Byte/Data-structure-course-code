
typedef int DataType;
const int MaxStackSize = 100;

#include "SeqStack.h"

int main()
{
	SeqStack myStack;
	int i, x;
	StackInit(&myStack);
	for ( i = 0; i < 10; i++)
	{
		StackPush(&myStack, i + 1);
	}
	StackTop(myStack, &x);
	printf("ջ��Ԫ��Ϊ: %d\n", x);
	printf("��ջ˳������: \n");
	while (StackNotEmpty(myStack))
	{
		StackPop(&myStack, &x);
		printf("%d  ", x);
	}
	return 0;
}