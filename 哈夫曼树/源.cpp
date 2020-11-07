#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MaxValue 10000  //定义无穷大权重
const int MaxBit = 5;
#include "HuffmanTree.h"

typedef struct
{
	int weight;
	int flag;
	int parent;
}HuffNode;
typedef HuffNode DataType
#include "BiTree.h"

#include "HuffTree.h"

int main()
{
	int i, j, n = 4;
	int weight[] = { 3,4,5,6 };
	HuffmanNode* myHuffTree = (HuffmanNode*)malloc(sizeof(HuffmanNode) * (2 * n - 1));
	Code* myHuffCode = (Code*)malloc(sizeof(Code) * n);
	Huffman(weight, n, myHuffTree);
	HuffmanCode(myHuffTree, n, myHuffCode);
	//输出每个结点的哈夫曼编码
	for ( i = 0; i < n; i++)
	{
		printf("Weight = %d  Code = ", myHuffCode[i].weight);
		for ( j = myHuffCode[i].start; j < n; j++)
		{
			printf("%d", myHuffCode[i].bit[j]);
		}
		printf("\n");
	}
	return 0;
}