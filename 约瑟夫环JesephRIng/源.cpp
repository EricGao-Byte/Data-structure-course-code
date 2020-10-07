typedef struct
{
	int number;
	int cipher;
}DataType;
#include "CSLNode.h"

void ListDeleteAfter(CSLNode* p)
{
	//删除p指针指向结点的下一个结点
	CSLNode* q = p->next;
	p->next = p->next->next;
	free(p);
}

void JesephRing(CSLNode* head, int m)
//对带头结点单循环链表head,初始值为m的约瑟夫环问题函数
{
	CSLNode* pre, * curr;
	int i;
	pre = head;
	curr = head->next;
	while (ListNotEmpty(head)==1)
	{
		for (i = 1; i < m; i++)
		{
			pre = curr;
			curr = curr->next;
			if (curr==head)
			{
				pre = curr;
				curr = curr->next;
			}
		}
		printf("%d  ", curr->data.number);
		m = curr->data.cipher;
		curr = curr->next;
		if (curr==head)
		{
			curr = curr->next;
		}
		ListDeleteAfter(pre);
	}
}

int main()
{
	DataType test[7] = { {1,3},{2,1},{3,7},{4,2},{5,4},{6,8},{7,4} };
	int n = 7, m = 20, i;
	CSLNode* head;
	ListInit(&head);
	for ( i = 1; i <= n; i++)
	{
		ListInsert(head, i, test[i - 1]);
	}
	JesephRing(head, m);
	return 0;
}