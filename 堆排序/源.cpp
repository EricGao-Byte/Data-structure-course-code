#include <stdio.h>
// **������**
// �㷨˼��:
//			1. ������(������->һά����)
//			2. ������Ϊ����
//			3. �����ѽ�������
typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;

void CreatHeap(DataType a[], int n, int h)
//������Ҷ�ڵ�a[h]ʹ֮��������,nΪ����n��Ԫ�ظ���
{
	int i, j, flag;
	DataType temp;
	i = h;
	j = 2 * i + 1;  //��Ҷ�ڵ��������
	temp = a[i];
	flag = 0;
	//�����Һ�����ֵ�ϴ����ظ�����ɸѡ
	while (j < n && flag != 1)
	{
		//Ѱ�����Һ��ӽ���нϴ���,jΪ���±�
		if (j<n-1&&a[j].key<a[j+1].key)
		{
			j++;
		}
		if (temp.key>a[j].key)  //��������
		{
			flag = 1;  //��ǽ���ɸѡ����
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
//������Ԫ��a[0]-a[n-1]��ʼ������Ϊ����
{
	int i;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		CreatHeap(a, n, i);
	}
}

void HeapSort(DataType a[], int n)
//�ö����������Ԫ��a[0]-a[n-1]��������
{
	int i;
	DataType temp;
	InitCreatHeap(a, n);  //��ʼ����������
	for (i = n - 1; i > 0; i--)  //��ǰ���Ѹ���ÿ�εݼ�1
	{
		//�ѶѶ�a[0]Ԫ�غ͵�ǰ���ѵ����һ��Ԫ�ؽ���
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		CreatHeap(a, i, 0);  //�������ڵ���������
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