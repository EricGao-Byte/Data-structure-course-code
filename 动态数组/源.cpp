#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int* Make1DArray(int n)
//创建一个含有n个元素的动态数组
{
	int* a, i;
	//动态申请n个int类型的内存空间,由指针a指向首地址
	if ((a = (int*)calloc(n, sizeof(int))) == NULL)
	{
		printf("申请一维动态数组空间失败!\n");
		exit(1);
	}
	return a;
}

void Delete1DArray(int* a)
{
	free(a);
}

int** Make2DArray(int row, int col)
//创建row行,clo列的动态二位数组,函数返回其首地址
{
	int** a;
	int i;
	//申请row个int*类型,由a指示
	if ((a = (int**)calloc(row, sizeof(int*))) == NULL)
	{
		printf("申请二维数组列空间失败!\n");
		exit(1);
	}
	//循环row次,每次申请col个int类型的内存空间,由a[i]指示
	for ( i = 0; i < row; i++)
	{
		if ((a[i] = (int*)calloc(col, sizeof(int))) == NULL)
		{
			printf("申请二维动态数组行空间失败!\n");
			exit(1);
		}
	}
	return a;
}

void Delete2DArray(int** a, int row)
//释放二维动态a的内存空间,row为数组的行数
{
	int i;
	for ( i = 0; i < row; i++)
	{
		free(a[i]);  //释放二位数组各行空间
	}
	free(a);
}



int main()
{
	////  **一维动态数组测试**
	//int* a, n = 10, i;
	//a = Make1DArray(n);
	//for ( i = 0; i < n; i++)
	//{
	//	a[i] = i + 1;  //赋值
	//}
	//for ( i = 0; i < n; i++)
	//{
	//	printf("%d  ", a[i]);  //显示数组元素
	//}
	//free(a);  //动态释放指针a所指向的n个内存空间

	//  **二维动态数组测试**
	int i, j, c;
	int row = 3, col = 4, **a;
	a = Make2DArray(row, col);
	c = 1;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			a[i][j] = c;  //数组元素赋值
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