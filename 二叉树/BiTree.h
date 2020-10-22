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
//��ʼ��������������ͷ���
{
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

//�������������
//����ǰ���curr�ǿ�,����curr������������Ԫ��Ϊx���½ڵ�
//ԭcurr��ָ������������Ϊ�²������������
//������ɹ�,�򷵻��²������ָ��,���򷵻ؿ�ָ��
BiTreeNode* InsertLeftNode(BiTreeNode* curr, DataType x)
{
	BiTreeNode* s;
	if (curr == NULL)
	{
		return NULL;
	}
	if ((s = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL)
	{
		printf("����������������ʧ��!\n");
		exit(1);
	}
	s->data = x;
	s->leftChild = curr->leftChild;  //�²����s����������Ϊt���
	s->rightChild = NULL;
	curr->leftChild = s;  //�²����s����Ϊcurr��������
	return curr->leftChild;
}
//�������������
//����ǰ���curr�ǿ�,����curr������������Ԫ��Ϊx���½ڵ�
//ԭcurr��ָ������������Ϊ�²������������
//������ɹ�,�򷵻��²������ָ��,���򷵻ؿ�ָ��
BiTreeNode* InsertRightNode(BiTreeNode* curr, DataType x)
{
	BiTreeNode* s;
	if (curr == NULL)
	{
		return NULL;
	}
	if ((s = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL)
	{
		printf("����������������ʧ��!\n");
		exit(1);
	}
	s->data = x;
	s->rightChild = curr->rightChild;  //�²����s����������Ϊt���
	s->leftChild = NULL;
	curr->rightChild = s;  //�²����s����Ϊcurr��������
	return curr->rightChild;
}

//ɾ��������
//��curr�ǿ�,��ɾ��curr��ָ����������
//��ɾ���ɹ�,�򷵻�ɾ������˫�׽��ָ��,���򷵻ؿ�ָ��
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

//ɾ��������
//��curr�ǿ�,��ɾ��curr��ָ����������
//��ɾ���ɹ�,�򷵻�ɾ������˫�׽��ָ��,���򷵻ؿ�ָ��
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

//����������
void PreOrderTree(BiTreeNode* root, void visit(DataType item))
//ǰ�����������(��->��->��),���ʲ���Ϊvisit()����
{
	if (root != NULL)
	{
		visit(root->data);
		PreOrderTree(root->leftChild, visit);
		PreOrderTree(root->rightChild, visit);
	}
}
void InOrderTree(BiTreeNode* root, void visit(DataType item))
//�б���������(��->��->��),���ʲ���Ϊvisit()����
{
	if (root!=NULL)
	{
		InOrderTree(root->leftChild, visit);
		visit(root->data);
		InOrderTree(root->rightChild, visit);
	}
}
void PostOrderTree(BiTreeNode* root, void visit(DataType item))
//�������������(��->��->��),���ʲ���Ϊvisit()����
{
	if (root != NULL)
	{
		PostOrderTree(root->leftChild, visit);
		PostOrderTree(root->rightChild, visit);
		visit(root->data);
	}
}

//��ӡ������
void PrintBiTree(BiTreeNode* root, int n)
//��ʱ����ת90���ӡ������root,nΪ��������,��ʼֵΪ0
{
	int i;
	if (root==NULL)  //�ݹ����
	{
		return;
	}
	PrintBiTree(root->rightChild,n + 1);  //������ӡ������
	//���ʸ��ڵ�
	for ( i = 0; i < n-1; i++)  //��ӡ����
	{
		printf("  ");
	}
	if (n>0)
	{
		printf("---");
		printf("%c\n", root->data);
	}
	PrintBiTree(root->leftChild, n + 1);  //������ӡ������
}

//��������Ԫ��
BiTreeNode* SearchBiTree(BiTreeNode* root, DataType x)
//��������Ԫ��x�Ƿ��ڶ�����root��
//���ҵ��򷵻ظý��ָ��,δ���ҵ��򷵻ؿ�ָ��
{
	BiTreeNode* find = NULL;  //��ʼ���Ϊ����ʧ��
	if (root!=NULL)
	{
		if (root->data==x)
		{
			find = root;  //��ǲ��ҳɹ�
		}
		else
		{
			find = SearchBiTree(root->leftChild, x);  //��������������
			if (find==NULL)
			{
				find = SearchBiTree(root->rightChild, x);  //��������������
			}
		}
	}
	return find;
}
//����������
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