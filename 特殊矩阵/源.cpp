//  **�������**
//  ���ǳ������ֵ��ͬ��Ԫ�ػ������Ԫ��,������Ԫ�ػ���ͬԪ������ʮ�ֹ��ɵĳ�Ϊ�������
#include <stdio.h>

void Add(int a[], int b[], int c[], int n)
//n�׶Գƾ���C=A+B,���о������ѹ���洢
{
	int i;
	for ( i = 0; i < n*(n+1)/2-1; i++)
	{
		c[i] = a[i] + b[i];  //��λ���
	}
}

void Print(int a[], int n)
{
	int i, j, k;
	for ( i = 0; i <= n; i++)
	{
		for ( j = 0; j <= n; j++)
		{
			if (i >= j)
			{
				k = i * (i - 1) / 2 + j - 1;  //����Ԫ���±�
			}
			else
			{
				k = j * (j - 1) / 2 + i - 1;  //��������Ԫ���±�
			}
			printf("%d   ", a[k]);
		}
		printf("\n");
	}
}

int main()
{
	int a[] = { 1,2,4,3,5,6 };
	int b[] = { 10,20,40,30,50,60 };
	int c[6];
	int n = 3;
	Add(a, b, c, n);
	Print(c, n);
}