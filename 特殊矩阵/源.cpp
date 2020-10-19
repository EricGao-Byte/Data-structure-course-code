//  **特殊矩阵**
//  我们称有许多值相同的元素或许多零元素,并且零元素或相同元素排列十分规律的称为特殊矩阵
#include <stdio.h>

void Add(int a[], int b[], int c[], int n)
//n阶对称矩阵C=A+B,其中矩阵采用压缩存储
{
	int i;
	for ( i = 0; i < n*(n+1)/2-1; i++)
	{
		c[i] = a[i] + b[i];  //逐位相加
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
				k = i * (i - 1) / 2 + j - 1;  //计算元素下标
			}
			else
			{
				k = j * (j - 1) / 2 + i - 1;  //计算隐含元素下标
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