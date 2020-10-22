#include <stdio.h>
#include <stdlib.h>


typedef char DataType;
#include "BiTree.h"

int main()
{
	BiTreeNode* root, * p;
	InitTree(&root);
	p = InsertLeftNode(root, 'A');
	p = InsertLeftNode(p, 'B');
	p = InsertLeftNode(p, 'D');
	p = InsertRightNode(p, 'G');
	p = InsertRightNode(root->leftChild, 'C');
	InsertLeftNode(p, 'E');
	InsertRightNode(p, 'F');
	PrintBiTree(root, 8);
	return 0;
}