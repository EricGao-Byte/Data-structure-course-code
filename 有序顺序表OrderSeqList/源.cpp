typedef int DataType;
const int MaxSize = 100;
#include "OSeqList.h"

int main()
{
	OSeqList mylist;
	ListInit(&mylist);
	int i;
	for ( i = 0; i < 10; i++)
	{
		ListInsert(&mylist, i + 1);
		i++;
	}
	ListPrint(mylist);
	ListInsert(&mylist, 8);
	return 0;
}