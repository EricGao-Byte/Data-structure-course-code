#include <stdio.h>
// **直接排序**
// 算法思想:
//			从前往后依次将数组中的元素插入到数组前的恰当位置
typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;

void InsertSort(DataType a[], int n)
//对长度为n的数组元素进行排序
{
	int i, j;
	DataType temp;
	for ( i = 1; i < n; i++)
	{
		for ( j = 0; j < i; j++)
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

int main()
{
	DataType a[] = { 64,5,7,89,6,24 };
	int n = 6;
	InsertSort(a, n);
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i].key);
	}
	return 0;
}