#include <stdio.h>
// **ѡ������**
//  �㷨˼��:
//			��ǰ����ÿ��ѡ����������С��Ԫ�ضѷ��������ǰ��
typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;

void SelectSort(DataType a[], int n)
//�Ժ���n��Ԫ�ص�����a����ѡ������
{
	int i, j;
	DataType t;
	int min;  //ÿ����СԪ���±�
	for (j = 0; j < n; j++)
	{
		min = j;
		//ѡ����СԪ��
		for (i = j; i < n; i++)
		{
			if (a[i].key < a[min].key)
			{
				min = i;
			}
		}
		//��СԪ����ĩβ����
		t = a[min];
		a[min] = a[j];
		a[j] = t;
	}
}

int main()
{
	DataType a[] = { 65,34,25,87,12,38,56,46,14,77,92,23 };
	int n = 12;
	SelectSort(a, n);
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i].key);
	}
	return 0;
}