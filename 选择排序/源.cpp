#include <stdio.h>
// **选择排序**
//  算法思想:
//			从前到后每次选择数组中最小的元素堆放在数组的前面
typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;

void SelectSort(DataType a[], int n)
//对含有n个元素的数组a进行选择排序
{
	int i, j;
	DataType t;
	int min;  //每轮最小元素下标
	for (j = 0; j < n; j++)
	{
		min = j;
		//选出最小元素
		for (i = j; i < n; i++)
		{
			if (a[i].key < a[min].key)
			{
				min = i;
			}
		}
		//最小元素与末尾交换
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