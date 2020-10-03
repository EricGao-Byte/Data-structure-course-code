#include <stdio.h>
typedef struct Student
{
	int number;
	char name[10];
	char sex[3];
	int age;
}StudentType;
typedef StudentType DataType;
const int MaxSize = 100;
#include "SeqList.h"

int main()
{
	//����2-1
	//SeqList mylist;
	//int i, x;
	//ListInit(&mylist);
	//for ( i = 0; i < 10; i++)
	//{
	//	ListInsert(&mylist, i, i + 1);
	//}
	//ListDelete(&mylist, 4, &x);

	//ListPrint(mylist);


	//����2-2
	SeqList mylist;
	int i;
	StudentType x[4] = 
		{ {1,"����","��",20},
		{2,"����","��",22},
		{3,"����","Ů",24},
		{4,"�߳�","Ů",199} };
	StudentType student;
	ListInit(&mylist);
	for ( i = 0; i < 4; i++)
	{
		ListInsert(&mylist, i, x[i]);
	}
	StudentType t;
	for ( i = 0; i < ListLength(&mylist); i++)
	{
		ListGet(mylist, i, &t);
		printf("%d %s %s %d\n", t.number, t.name, t.sex, t.age);
	}
	ListReverse(&mylist);
	for (i = 0; i < ListLength(&mylist); i++)
	{
		ListGet(mylist, i, &t);
		printf("%d %s %s %d\n", t.number, t.name, t.sex, t.age);
	}
	return 0;
}