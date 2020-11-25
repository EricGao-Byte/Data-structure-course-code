#pragma once
typedef struct
{
	SeqList Vertices;  //存放顶点的顺序表
	int edge[MaxVertices][MaxVertices];  //存放邻接矩阵
	int numOfEdges;  //边的条数
}AdjMGraph;  //图的结构体定义

void InitAdjMGraph(AdjMGraph* G, int n)
{
	int i, j;
	//初始化临界矩阵,对角线上为0,其他元素为无穷大MaxWeight
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				G->edge[i][j] = 0;
			}
			else
			{
				G->edge[i][j] = MaxWeight;  //MaxWeight为定义的无穷大权值
			}
		}
	}
	G->numOfEdges = 0;
	ListInit(&G->Vertices);  //顺序表初始化
}

void InsertVertex(AdjMGraph* G, DataType vertex)
//向图G中插入顶点vertex
{
	ListInsert(&G->Vertices, G->Vertices.size, vertex);  //在顺序表尾插入
}

void InsertEdge(AdjMGraph* G, int v1, int v2, int weight)
//在图G中插入边<v1,v2>,权值为weight
{
	if (v1 < 0 || v1 >= G->Vertices.size || v2 < 0 || v2 >= G->Vertices.size)
		//越界检测
	{
		printf("参数v1或v2越界出错!\n");
		return;
	}
	else
	{
		//插入边
		G->edge[v1][v2] = weight;
		G->numOfEdges++;
	}
}

void DeleteEdge(AdjMGraph* G, int v1, int v2)
//在图G中删除边<v1,v2>
{
	if (v1 < 0 || v1 >= G->Vertices.size || v2 < 0 || v2 >= G->Vertices.size)
	{
		printf("参数v1或v2出错!\n");
		return;
	}
	else if (G->edge[v1][v2] == MaxWeight || v1 == v2)
	{
		printf("该边不存在!\n");
		return;
	}
	else
	{
		G->edge[v1][v2] = MaxWeight;
		G->numOfEdges--;
	}
}

int GetFirstVex(AdjMGraph G, int v)
//在图G中寻找序号为v的顶点的第一个邻接顶点
//如果这样的邻接顶点存在,则返回该顶点的序号,否则返回-1
{
	int col;
	if (v < 0 || v >= G.Vertices.size)
	{
		printf("参数v1越界出错!\n");
		return -1;
	}
	for (col = 0; col < G.Vertices.size; col++)
	{
		if (G.edge[v][col] > 0 && G.edge[v][col] < MaxWeight)
		{
			return col;
		}
	}
	return -1;
}

int GetNextVex(AdjMGraph G, int v1, int v2)
//在图G中寻找v1顶点的邻接顶点v2的下一个邻接矩阵
//如果这样的邻接顶点存在,则返回该邻接顶点的序号,否则返回-1
//v1和v2都是相应顶点的序号
{
	int col;
	if (v1<0 || v1>G.Vertices.size || v2 < 0 || v2 >= G.Vertices.size)
	{
		printf("参数v1和v2越界出错!\n");
		return -1;
	}
	for (col = v2 + 1; col < G.Vertices.size; col++)
	{
		if (G.edge[v1][v2] > 0 && G.edge[v1][col] < MaxWeight)
		{
			return col;
		}
	}
	return -1;
}

