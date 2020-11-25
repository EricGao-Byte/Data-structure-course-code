#include <stdio.h>
#include <malloc.h>

typedef char DataType;
typedef char VerT;
const int MaxWeight = 10000;
const int MaxSize = 10;
const int MaxVertices = 10;

#include "SeqList.h"

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"


#include "Prim.h"

int main()
{
	AdjMGraph g;
	char a[] = { 'A','B','C','D','E','F','G' };
	RowColWeight rcw[] = 
	{ 
		{0,1,50},{1,0,50},
		{0,2,60},{2,0,60},
		{1,3,65},{3,1,65},
		{1,4,40},{4,1,40},
		{2,3,52},{3,2,52},
		{2,6,45},{6,2,45},
		{3,4,50},{4,3,50},
		{3,5,30},{3,2,30},
		{3,6,42},{6,3,42},
		{4,5,70},{5,4,70} 
	};
	int n = 7, e = 20, i;
	MinSpanTree closeVertex[7];
	CreatGraph(&g, a, n, rcw, e);  //创建图
	Prim(g, closeVertex);
	printf("初始顶点为 %c\n", closeVertex[0].vertex);
	for ( i = 1; i < n; i++)
	{
		printf("顶点 = %c  边的权值 = %d\n", closeVertex[i].vertex, closeVertex[i].weight);
	}
	return 0;
}
