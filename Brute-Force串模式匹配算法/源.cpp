#include <stdio.h>
#include "DString.h"

int BFIndex(DString S, int start, DString T)
//��������S��start��ʼ���Ӵ�T,�ɹ�����T����S�����ַ�λ��,ʧ�ܷ���-1
{
	int i = start, j = 0, v;
	while (i<S.length&&j<T.length)
	{
		if (S.str[i] == T.str[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j==T.length)
	{
		v = i - T.length;
	}
	else
	{
		v = -1;
	}
	return v;
}

int main()
{
	DString myString1, myString2;
	int max1 = 29, max2 = 9;
	int pos = 0;
	Init(&myString1, max1, (char*)"Data Structure Data Structure");
	Init(&myString2, max2, (char*)"Structure");
	//��һ�β���
	pos = BFIndex(myString1, pos, myString2);
	printf("%d", pos);
	//�ڶ��β���
	pos = BFIndex(myString1, pos + 1, myString2);
	printf("%d", pos);
	return 0;
}