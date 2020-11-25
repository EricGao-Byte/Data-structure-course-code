#include <stdio.h>
// **��������**

typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;

void QuickSort(DataType a[], int low,int high)
//������Ԫ��a[low]-a[high]���п�������
{
	int i = low, j = high;
	DataType temp = a[low];
	while (i<j)
	{
		while (i < j && temp.key <= a[j].key)  //���������ɨ��
		{
			j--;
		}
		if (i<j)
		{
			a[i] = a[j];
			i++;
		}
		while (i < j && a[i].key < temp.key)  //���������ɨ��
		{
			i++;
			
		}
		if (i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = temp;
	if (low<i)
	{
		QuickSort(a, low, i - 1);  //������Ӽ��Ͻ��еݹ�
	}
	if (i<high)
	{
		QuickSort(a, j + 1, high);  //���Ҷ��Ӽ��Ͻ��еݹ�
	}
}

int main()
{
	DataType a[] = { 65,34,25,87,12,38,56,46,14,77,92,23 };
	int low = 0, high = 11;
	int n = 12;
	QuickSort(a, low, high);
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i].key);
	}
	return 0;
}