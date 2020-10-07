typedef struct
{
	int number;
	int cipher;
}DataType;
#include "CSLNode.h"

void ListDeleteAfter(CSLNode* p)
{
	//ɾ��pָ��ָ�������һ�����
	CSLNode* q = p->next;
	p->next = p->next->next;
	free(p);
}

void JesephRing(CSLNode* head, int m)
//�Դ�ͷ��㵥ѭ������head,��ʼֵΪm��Լɪ�����⺯��
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