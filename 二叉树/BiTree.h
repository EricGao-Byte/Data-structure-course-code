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
//初始化建立二叉树的头结点
{
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

//插入左子树结点
//若当前结点curr非空,则在curr的左子树插入元素为x的新节点
//原curr所指结点的左子树成为新插入结点的左子树
//若插入成功,则返回新插入结点的指针,否则返回空指针
BiTreeNode* InsertLeftNode(BiTreeNode* curr, DataType x)
{
	BiTreeNode* s;
	if (curr == NULL)
	{
		return NULL;
	}
	if ((s = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL)
	{
		printf("申请插入左子树结点失败!\n");
		exit(1);
	}
	s->data = x;
	s->leftChild = curr->leftChild;  //新插入的s结点的左子树为t结点
	s->rightChild = NULL;
	curr->leftChild = s;  //新插入的s结点成为curr的左子树
	return curr->leftChild;
}
//插入右子树结点
//若当前结点curr非空,则在curr的右子树插入元素为x的新节点
//原curr所指结点的右子树成为新插入结点的右子树
//若插入成功,则返回新插入结点的指针,否则返回空指针
BiTreeNode* InsertRightNode(BiTreeNode* curr, DataType x)
{
	BiTreeNode* s;
	if (curr == NULL)
	{
		return NULL;
	}
	if ((s = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL)
	{
		printf("申请插入左子树结点失败!\n");
		exit(1);
	}
	s->data = x;
	s->rightChild = curr->rightChild;  //新插入的s结点的右子树为t结点
	s->leftChild = NULL;
	curr->rightChild = s;  //新插入的s结点成为curr的右子树
	return curr->rightChild;
}

//删除左子树
//若curr非空,则删除curr所指结点的左子树
//若删除成功,则返回删除结点的双亲结点指针,否则返回空指针
BiTreeNode* DeleteLeftTree(BiTreeNode* curr)
{
	void DestroyTree(BiTreeNode * *root);
	if (curr==NULL||curr->leftChild==NULL)
	{
		return NULL;
	}
	DestroyTree(&curr->leftChild);
	curr->leftChild = NULL;
	return curr;
}

//删除右子树
//若curr非空,则删除curr所指结点的右子树
//若删除成功,则返回删除结点的双亲结点指针,否则返回空指针
BiTreeNode* DeleteRightTree(BiTreeNode* curr)
{
	void DestroyTree(BiTreeNode * *root);
	if (curr == NULL || curr->rightChild == NULL)
	{
		return NULL;
	}
	DestroyTree(&curr->rightChild);
	curr->rightChild = NULL;
	return curr;
}

//遍历二叉树
void PreOrderTree(BiTreeNode* root, void visit(DataType item))
//前序遍历二叉树(中->左->右),访问操作为visit()函数
{
	if (root != NULL)
	{
		visit(root->data);
		PreOrderTree(root->leftChild, visit);
		PreOrderTree(root->rightChild, visit);
	}
}
void InOrderTree(BiTreeNode* root, void visit(DataType item))
//中遍历二叉树(左->中->右),访问操作为visit()函数
{
	if (root!=NULL)
	{
		InOrderTree(root->leftChild, visit);
		visit(root->data);
		InOrderTree(root->rightChild, visit);
	}
}
void PostOrderTree(BiTreeNode* root, void visit(DataType item))
//后序遍历二叉树(左->右->中),访问操作为visit()函数
{
	if (root != NULL)
	{
		PostOrderTree(root->leftChild, visit);
		PostOrderTree(root->rightChild, visit);
		visit(root->data);
	}
}

//打印二叉树
void PrintBiTree(BiTreeNode* root, int n)
//逆时针旋转90°打印二叉树root,n为缩进层数,初始值为0
{
	int i;
	if (root==NULL)  //递归出口
	{
		return;
	}
	PrintBiTree(root->rightChild,n + 1);  //遍历打印右子树
	//访问根节点
	for ( i = 0; i < n-1; i++)  //打印缩进
	{
		printf("  ");
	}
	if (n>0)
	{
		printf("---");
		printf("%c\n", root->data);
	}
	PrintBiTree(root->leftChild, n + 1);  //遍历打印左子树
}

//查找数据元素
BiTreeNode* SearchBiTree(BiTreeNode* root, DataType x)
//查找数据元素x是否在二叉树root中
//查找到则返回该结点指针,未查找到则返回空指针
{
	BiTreeNode* find = NULL;  //初始标记为查找失败
	if (root!=NULL)
	{
		if (root->data==x)
		{
			find = root;  //标记查找成功
		}
		else
		{
			find = SearchBiTree(root->leftChild, x);  //进入左子树查找
			if (find==NULL)
			{
				find = SearchBiTree(root->rightChild, x);  //进入右子树查找
			}
		}
	}
	return find;
}
//撤销二叉树
void DestroyTree(BiTreeNode** root)
{
	if ((*root)!=NULL&&(*root)->leftChild!=NULL)
	{
		DestroyTree(&(*root)->leftChild);
	}
	if ((*root)!=NULL&&(*root)->rightChild!=NULL)
	{
		DestroyTree(&(*root)->rightChild);
	}
	free(*root);
}