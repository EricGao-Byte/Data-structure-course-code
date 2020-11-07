//  **线索二叉树**
//  描述:
//	左线索为0时,左指针指向左孩子结点;左线索为1时,左指针指向结点的前驱结点
//	右线索为0时,右指针指向右孩子结点;右线索为1时,右指针指向结点的后驱结点
//	线索二叉树的这种设计使得二叉树浪费下来的指针能够被利用起来
//	这使得二叉树的搜寻方向不再是只能从根到叶
//	可以像双向链表那样从前往后和从后往前遍历
#pragma once
typedef struct Node
{
	DataType data;  //数据域
	int leftThread;  //左线索
	struct Node* leftChild;  //左指针
	int rightThread;  //右线索
	struct Node* rightChild;  //右指针
}ThreadBiNode;

//中序线索化二叉树
void InThread(ThreadBiNode* current, ThreadBiNode** pre)
//current为当前结点指针,pre为当前结点的前驱指针
{

}
//创建中序线索化二叉树tree

//