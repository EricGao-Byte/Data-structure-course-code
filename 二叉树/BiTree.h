#pragma once
//  **二叉树**
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Node
{
	DataType data;  //数据域
	struct Node* leftChild;  //左子树指针
	struct Node* rightChild;  //右子树指针
}BiTreeNode;


//初始化
void InitTree(BiTreeNode** root)
{
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

//插入左子树结点
BiTreeNode* InsertLeftNode(BiTreeNode* curr, DataType x)
{
	BiTreeNode* s, * t;
	if (curr == NULL)
	{
		return NULL;
	}
	t = curr->leftChild;
	if ((s = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL)
	{
		printf("申请插入左子树结点失败!\n");
		exit(1);
	}

}
//插入右子树结点

//删除左子树

//删除右子树

//撤销二叉树
