#include <stdio.h>
// **ϣ������**
// �㷨˼��:
//			ÿ��ѭ��,��ÿһ�Կ��Ϊһ����������������������
//			ѭ��ֱ������Ϊ1Ϊֹ
typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;

//ֱ������
void InsertSort(DataType a[], int n)
//�Գ���Ϊn������Ԫ�ؽ�������
{
	int i, j;
	DataType temp;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[i].key < a[j].key)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

//ϣ������
void ShellSort(DataType a[], int n, int d[], int numOfD)
//��ϣ�����������a��Ԫ�ؽ�������,dΪ��������,numOfDΪ��������
{
	int i, j, k, m;
	DataType temp;
	int span;  //ÿ��ѭ��������
	for ( m = 0; m < numOfD; m++)
	{
		span = d[m];
		for ( k = 0; k < span; k++)
		{
			//����Ϊֱ������,����Ϊ�˴�������span
			for (i = k; i < n-span; i+=span)
			{
				for (j = 0; j < i; j++)
				{
					if (a[i].key < a[j].key)
					{
						temp = a[i];
						a[i]= a[j];
						a[j] = temp;
					}
				}
			}
		}
	}
}

int main()
{
	DataType a[] = { 65,34,25,87,12,38,56,46,14,77,92,23 };
	int n = 12;
	int d[] = { 6,3,1 };
	int numOfD = 3;
	ShellSort(a, n, d, numOfD);
	int i;
	for ( i = 0; i < n; i++)
	{
		printf("%d ", a[i].key);
	}
	return 0;
}