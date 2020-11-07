#pragma once
//	**哈夫曼树(Huffman Tree)**
//	描述:
//	哈夫曼树是一种带权二叉树,树的每个叶节点都带有权值
//	二叉树的带权路径长度=每个叶节点的路径长度*每个叶节点的权值 并求和
#include <malloc.h>

//双亲结点的仿真指针构造的哈夫曼树
typedef struct Node
{
	int weight;  //权值
	int flag;  //标记
	int parent;  //双亲结点下标
	int rightChild;  //右孩子下标
	int leftChild;  //左孩子下标
}HuffmanNode;  //哈夫曼树的结点结构

typedef struct
{
	int bit[MaxBit];  //数组
	int start;  //编码的初始下标
	int weight;  //字符的权重
}Code;  //哈夫曼编码的结构

void Huffman(int weight[], int n, HuffmanNode hufftree[])
//建立结点个数为n,权值数组为weight的哈夫曼树hufftree
{
	int i, j, m1, m2, x1, x2;
	//哈夫曼树hufftree初始化,n个叶节点的二叉树共有2n-1个结点
	for ( i = 0; i < 2*n-1; i++)
	{
		if (i<n)
		{
			hufftree[i].weight = weight[i];
		}
		else
		{
			hufftree[i].weight = 0;
		}
		hufftree[i].parent = -1;
		hufftree[i].flag = 0;
		hufftree[i].leftChild = -1;
		hufftree[i].rightChild = -1;
	}
	//构造哈夫曼树hufftree的n-1个非叶结点
	for ( i = 0; i < n-1; i++)
	{
		m1 = m2 = MaxValue;
		x1 = x2 = 0;
		//找出权值最小和次小的子树
		for ( j = 0; j < n+i; j++)
		{
			if (hufftree[j].weight < m1 && hufftree[j].flag == 0)
			{
				m2 = m1;
				x2 = x1;
				m1 = hufftree[j].weight;
				x1 = j;
			}
			else if ((hufftree[j].weight < m2||hufftree[j].weight==m1) && hufftree[j].flag == 0)
			{
				m2 = hufftree[j].weight;
				x2 = j;
			}
		}
		//找出两颗权值最小和次小的子树合并为一颗子树
		hufftree[x1].parent = n + i;
		hufftree[x2].parent = n + i;
		hufftree[x1].flag = 1;
		hufftree[x2].flag = 1;
		hufftree[n + i].weight = hufftree[x1].weight + hufftree[x2].weight;
		hufftree[n + i].leftChild = x1;
		hufftree[n + i].rightChild = x2;
	}
}

//由n个结点的哈夫曼树hufftree构造哈夫曼编码haffcode
void HuffmanCode(HuffmanNode hufftree[], int n, Code huffcode[])
{
	Code* cd = (Code*)malloc(sizeof(Code));
	int i, j, child, parent;
	//求n个叶结点的哈夫曼编码
	for ( i = 0; i < n; i++)
	{
		cd->start = n - 1;  //不等长的编码最后一位位n-1
		cd->weight = hufftree[i].weight;  //取得编码对应的权值并赋值
		child = i;
		parent = hufftree[child].parent;
		//由叶节点向上直到根节点
		while (parent!=-1)
		{
			if (hufftree[parent].leftChild == child)
			{
				cd->bit[cd->start] = 0;  //左孩子分支编码0
			}
			else
			{
				cd->bit[cd->start] = 1;  //右孩子分支编码1
			}
			cd->start--;
			child = parent;
			parent = hufftree[child].parent;
		}
		for ( j = cd->start+1; j < n; j++)
		{
			huffcode[i].bit[j] = cd->bit[j];  //保存每个叶节点的哈夫曼编码
		}
		huffcode[i].start = cd->start + 1;  //保存结点编码的起始位置
		huffcode[i].weight = cd->weight;  //保存编码对应的权重
	}
}