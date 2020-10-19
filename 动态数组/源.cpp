#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int* Make1DArray(int n)
//����һ������n��Ԫ�صĶ�̬����
{
	int* a, i;
	//��̬����n��int���͵��ڴ�ռ�,��ָ��aָ���׵�ַ
	if ((a = (int*)calloc(n, sizeof(int))) == NULL)
	{
		printf("����һά��̬����ռ�ʧ��!\n");
		exit(1);
	}
	return a;
}

void Delete1DArray(int* a)
{
	free(a);
}

int** Make2DArray(int row, int col)
//����row��,clo�еĶ�̬��λ����,�����������׵�ַ
{
	int** a;
	int i;
	//����row��int*����,��aָʾ
	if ((a = (int**)calloc(row, sizeof(int*))) == NULL)
	{
		printf("�����ά�����пռ�ʧ��!\n");
		exit(1);
	}
	//ѭ��row��,ÿ������col��int���͵��ڴ�ռ�,��a[i]ָʾ
	for ( i = 0; i < row; i++)
	{
		if ((a[i] = (int*)calloc(col, sizeof(int))) == NULL)
		{
			printf("�����ά��̬�����пռ�ʧ��!\n");
			exit(1);
		}
	}
	return a;
}

void Delete2DArray(int** a, int row)
//�ͷŶ�ά��̬a���ڴ�ռ�,rowΪ���������
{
	int i;
	for ( i = 0; i < row; i++)
	{
		free(a[i]);  //�ͷŶ�λ������пռ�
	}
	free(a);
}



int main()
{
	////  **һά��̬�������**
	//int* a, n = 10, i;
	//a = Make1DArray(n);
	//for ( i = 0; i < n; i++)
	//{
	//	a[i] = i + 1;  //��ֵ
	//}
	//for ( i = 0; i < n; i++)
	//{
	//	printf("%d  ", a[i]);  //��ʾ����Ԫ��
	//}
	//free(a);  //��̬�ͷ�ָ��a��ָ���n���ڴ�ռ�

	//  **��ά��̬�������**
	int i, j, c;
	int row = 3, col = 4, **a;
	a = Make2DArray(row, col);
	c = 1;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			a[i][j] = c;  //����Ԫ�ظ�ֵ
			c++;
		}
	}
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	Delete2DArray(a,row);
}