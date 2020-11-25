#pragma once
typedef struct
{
	SeqList Vertices;  //��Ŷ����˳���
	int edge[MaxVertices][MaxVertices];  //����ڽӾ���
	int numOfEdges;  //�ߵ�����
}AdjMGraph;  //ͼ�Ľṹ�嶨��

void InitAdjMGraph(AdjMGraph* G, int n)
{
	int i, j;
	//��ʼ���ٽ����,�Խ�����Ϊ0,����Ԫ��Ϊ�����MaxWeight
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
				G->edge[i][j] = MaxWeight;  //MaxWeightΪ����������Ȩֵ
			}
		}
	}
	G->numOfEdges = 0;
	ListInit(&G->Vertices);  //˳����ʼ��
}

void InsertVertex(AdjMGraph* G, DataType vertex)
//��ͼG�в��붥��vertex
{
	ListInsert(&G->Vertices, G->Vertices.size, vertex);  //��˳���β����
}

void InsertEdge(AdjMGraph* G, int v1, int v2, int weight)
//��ͼG�в����<v1,v2>,ȨֵΪweight
{
	if (v1 < 0 || v1 >= G->Vertices.size || v2 < 0 || v2 >= G->Vertices.size)
		//Խ����
	{
		printf("����v1��v2Խ�����!\n");
		return;
	}
	else
	{
		//�����
		G->edge[v1][v2] = weight;
		G->numOfEdges++;
	}
}

void DeleteEdge(AdjMGraph* G, int v1, int v2)
//��ͼG��ɾ����<v1,v2>
{
	if (v1 < 0 || v1 >= G->Vertices.size || v2 < 0 || v2 >= G->Vertices.size)
	{
		printf("����v1��v2����!\n");
		return;
	}
	else if (G->edge[v1][v2] == MaxWeight || v1 == v2)
	{
		printf("�ñ߲�����!\n");
		return;
	}
	else
	{
		G->edge[v1][v2] = MaxWeight;
		G->numOfEdges--;
	}
}

int GetFirstVex(AdjMGraph G, int v)
//��ͼG��Ѱ�����Ϊv�Ķ���ĵ�һ���ڽӶ���
//����������ڽӶ������,�򷵻ظö�������,���򷵻�-1
{
	int col;
	if (v < 0 || v >= G.Vertices.size)
	{
		printf("����v1Խ�����!\n");
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
//��ͼG��Ѱ��v1������ڽӶ���v2����һ���ڽӾ���
//����������ڽӶ������,�򷵻ظ��ڽӶ�������,���򷵻�-1
//v1��v2������Ӧ��������
{
	int col;
	if (v1<0 || v1>G.Vertices.size || v2 < 0 || v2 >= G.Vertices.size)
	{
		printf("����v1��v2Խ�����!\n");
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

