#pragma once
//  **������**
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Node
{
	DataType data;  //������
	struct Node* leftChild;  //������ָ��
	struct Node* rightChild;  //������ָ��
}BiTreeNode;


//��ʼ��
void InitTree(BiTreeNode** root)
{
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

//�������������
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
		printf("����������������ʧ��!\n");
		exit(1);
	}

}
//�������������

//ɾ��������

//ɾ��������

//����������
