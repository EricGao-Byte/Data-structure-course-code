#include "SeqList.h"

int main()
{
	SeqList mylist;
	int i, x;
	ListInit(&mylist);
	for ( i = 0; i < 10; i++)
	{
		ListInsert(&mylist, i, i + 1);
	}
	ListDelete(&mylist, 4, &x);

	ListPrint(mylist);
	return 0;
}