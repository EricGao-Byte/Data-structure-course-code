#pragma once
#include <stdio.h>

typedef struct
{
	DataType list[MaxSize];
	int size;
}OSeqList;
//����˳���,�ڴ˴����е�Ԫ�ش�С��������

// ���º����ɹ�����1, ʧ�ܷ���0

//��ʼ��
void ListInit(OSeqList* L)
{
	L->size = 0;
}

//�����б���
int ListLength(OSeqList* L)
{
	return L->size;
}

//��������Ԫ��
int ListInsert(OSeqList* L, DataType x)
//������Ԫ��x��������˳�����ʵ�λ��
{
	int ListInsertFind(OSeqList* L, DataType x);
	int i, n;
	n = ListInsertFind(L, x);  //Ѱ��x��λ��
	if (L->size >= MaxSize)  //Խ�籣��
	{
		printf("˳�������,�޷�����!\n");
		return 0;
	}
	else if (n<0 || n>L->size)  //���뷶Χ����
	{
		printf("����λ�ò������Ϸ�!\n");
		return 0;
	}
	else
	{
		//�Ӻ���ǰ�����ƶ�����,Ϊ������׼��
		for (i = L->size; i > n; i--)
		{
			L->list[i] = L->list[i - 1];
		}
		//�˳�ѭ��ʱ,i=n
		L->list[i] = x;
		L->size++;
		return 1;
	}
}

//Ѱ������Ԫ��x�ڱ��е�λ��
int ListFind(OSeqList* L, DataType x)
//ʹ�ö��ַ�Ѱ������Ԫ�ز����ر��,�Ҳ����򷵻�-1
{
	int low = 0;
	int high = ListLength(L) - 1;
	while (low<=high)
	{
		int mid = (low + high) / 2;
		DataType midVal = L->list[mid];
		if (midVal<x)
		{
			low = mid + 1;
		}
		else if (midVal>x)
		{
			high = mid - 1;
		}
		else
		{
			return mid;  //����Ѱ�ҵ���Ԫ�صı��
		}
	}
	return -1;
}

//ɾ������Ԫ��
int ListDelete(OSeqList* L, int n, DataType* x)
//ɾ����n�����,��������Ԫ�ر��浽x�д���
{
	int i;
	if (L->size <= 0)
	{
		printf("˳����ѿ�������Ԫ�ؿ�ɾ!\n");
		return 0;
	}
	else if (n<0 || n>L->size - 1)
	{
		printf("ɾ��λ�ò���n���Ϸ�!\n");
		return 0;
	}
	else
	{
		*x = L->list[n];
		//��ǰ�������ǰ��
		for (i = n + 1; i < L->size; i++)
		{
			L->list[i - 1] = L->list[i];
		}
		L->size--;
		return 1;
	}
}

//Ѱ��Ԫ��x�ڱ��еĵĲ���λ��
int ListInsertFind(OSeqList* L, DataType x)
{
	int low = 0;
	int high = ListLength(L) - 1;
	if (high==-1)  //Ϊ�ձ�
	{
		return 0;
	}
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int midPre = mid - 1;
		int midAft = mid + 1;
		DataType midVal = L->list[mid];
		DataType midPreVal = L->list[midPre];
		DataType midAftVal = L->list[midAft];
		if (midPre<0&&midVal>x)
		{
			return mid;
		}
		else if (midAft>ListLength(L)-1&&midVal<x)
		{
			return midAft;
		}
		else if (midVal==x)
		{
			return mid;
		}
		else if (midVal>x&&midPreVal<x)
		{
			return mid;
		}
		else if (midVal<x&&midAftVal>x)
		{
			return midAft;
		}
		if (midVal < x)
		{
			low = mid + 1;
		}
		else if (midVal > x)
		{
			high = mid - 1;
		}
	}
	return -1;
}

// ȡԪ��
int ListGet(OSeqList L, int n, DataType * x)
//ȡ��n������������,������x�д���
{
	int i;
	if (n<0 || n>L.size - 1)
	{
		printf("ȡԪ�صĲ������Ϸ�!\n");
		return 0;
	}
	else
	{
		*x = L.list[n];
		return 1;
	}
}

//��ӡԪ��
void ListPrint(OSeqList L)
{
	int i;
	DataType elem;
	for (i = 0; i < L.size; i++)
	{
		ListGet(L, i, &elem);
		printf("��%d��Ԫ��Ϊ: %d\n", i + 1, elem);
	}
}