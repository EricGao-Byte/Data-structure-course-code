#include <stdio.h>
// **希尔排序**
// 算法思想:
//			每次循环,对每一对跨度为一个增量的两个数进行排序
//			循环直到增量为1为止
typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;

//直接排序
void InsertSort(DataType a[], int n)
//对长度为n的数组元素进行排序
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

//希尔排序
void ShellSort(DataType a[], int n, int d[], int numOfD)
//用希尔排序对数组a的元素进行排列,d为增量数组,numOfD为增量个数
{
	int i, j, k, m;
	DataType temp;
	int span;  //每次循环的增量
	for ( m = 0; m < numOfD; m++)
	{
		span = d[m];
		for ( k = 0; k < span; k++)
		{
			//组内为直接排序,区别为此处是增加span
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