#include <stdio.h>
// **堆排序**
// 算法思想:
//			1. 创建堆(二叉树->一维数组)
//			2. 调整堆为最大堆
//			3. 对最大堆进行排序
typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;

void CreatHeap(DataType a[], int n, int h)
//调整非叶节点a[h]使之满足最大堆,n为数组n的元素个数
{
	int i, j, flag;
	DataType temp;
	i = h;
	j = 2 * i + 1;  //非叶节点的左子树
	temp = a[i];
	flag = 0;
	//沿左右孩子中值较大者重复向下筛选
	while (j < n && flag != 1)
	{
		//寻找左右孩子结点中较大者,j为其下标
		if (j<n-1&&a[j].key<a[j+1].key)
		{
			j++;
		}
		if (temp.key>a[j].key)  //结束条件
		{
			flag = 1;  //标记结束筛选条件
		}
		else
		{
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	a[i] = temp;
}

void InitCreatHeap(DataType a[], int n)
//把数组元素a[0]-a[n-1]初始化创建为最大堆
{
	int i;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		CreatHeap(a, n, i);
	}
}

void HeapSort(DataType a[], int n)
//用堆排序对数组元素a[0]-a[n-1]进行排序
{
	int i;
	DataType temp;
	InitCreatHeap(a, n);  //初始化创建最大堆
	for (i = n - 1; i > 0; i--)  //当前最大堆个数每次递减1
	{
		//把堆顶a[0]元素和当前最大堆的最后一个元素交换
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		CreatHeap(a, i, 0);  //调整根节点满足最大堆
	}
}

int main()
{
	DataType a[] = { 65,34,25,87,12,38,56,46,14,77,92,23 };
	int n = 12;
	HeapSort(a, n);
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i].key);
	}
	return 0;
}