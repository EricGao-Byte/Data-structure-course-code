#pragma once
typedef struct
{
	VerT vertex;  //保存最小生成树每条边的弧头顶点数据
	int weight;
}MinSpanTree;

void Prim(AdjMGraph G, MinSpanTree closeVertex[])
//利用Prim算法建立带权图G的最小生成树closeVertex
{
	VerT x;
	int n = G.Vertices.size, minCost;
	int* lowCost = (int*)malloc(sizeof(int) * n);  //生成lowCost数组空间
	int i, j, k;
	for (i = 1; i < n; i++)  //初始化lowCost矩阵
	{
		lowCost[i] = G.edge[0][1];
	}
	//从顶点0出发构造最小生成树
	ListGet(G.Vertices, 0, &x);  //取顶点0
	closeVertex[0].vertex = x;  //保存顶点0
	lowCost[0] = -1;  //标记顶点0
	for (i = 1; i < n; i++)
	{
		//寻找当前最小权值的边所对应的弧头顶点k
		minCost = MaxWeight;  //MaxWeight为定义的最大权值
		for (j = 0; j < n; j++)
		{
			if (lowCost[j] < minCost && lowCost[j]>0)
			{
				minCost = lowCost[j];
				k = j;
			}
		}
		//取出当前最小权值边所对应的顶点k并存入最小生成树
		ListGet(G.Vertices, k, &x);
		closeVertex[i].vertex = x;
		closeVertex[i].weight = minCost;
		lowCost[k] = -1;  //标记k顶点为-1
		//根据加入集合U的顶点k修改lowCost中的数值
		for (j = 1; j < n; j++)
		{
			//如果新加入的顶点距离小于原距离,则更新lowCost数组
			if (G.edge[k][j] < lowCost[j])
			{
				lowCost[j] = G.edge[k][j];
			}
		}
	}
}
