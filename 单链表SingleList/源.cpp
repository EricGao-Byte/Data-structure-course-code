#include "SLNode.h"

int main()
{
	SLNode* head;
	int i, x;
	ListInit(&head);
	for ( i = 0; i < 10; i++)
	{
		ListInsert(head, i, i + 1);
	}
	ListDelete(head, 4, &x);
	for ( i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x);
		printf("第%d个元素为 %d\n", i + 1, x);
	}
	ListDestroy(&head);
	return 0;
}