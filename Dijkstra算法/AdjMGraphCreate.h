typedef struct
{
	int row;
	int col;
	int weight;
}RowColWeight;

void CreatGraph(AdjMGraph* G, DataType V[], int n, RowColWeight E[], int e)
//在图G中插入n个顶点信息V和e条边信息E
{
	int i, k;
	InitAdjMGraph(G, n);
	for ( i = 0; i < n; i++)
	{
		InsertVertex(G, V[i]);
	}
	for ( k = 0; k < e; k++)
	{
		InsertEdge(G, E[k].row, E[k].col, E[k].weight);
	}
}