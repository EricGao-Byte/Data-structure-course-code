typedef int DataType;
#include "LSNode.h"

int main()
{
	LSNode* myStack;
	int i, x;
	StackInit(&myStack);
	for (i = 0; i < 10; i++)
	{
		StackPush(myStack, i + 1);
	}
	StackTop(myStack, &x);
	printf("栈顶元素为: %d\n", x);
	printf("出栈顺序如下: \n");
	while (StackNotEmpty(myStack))
	{
		StackPop(myStack, &x);
		printf("%d  ", x);
	}
	return 0;
}