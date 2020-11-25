#pragma once
typedef struct
{
	VerT vertex;  //������С������ÿ���ߵĻ�ͷ��������
	int weight;
}MinSpanTree;

void Prim(AdjMGraph G, MinSpanTree closeVertex[])
//����Prim�㷨������ȨͼG����С������closeVertex
{
	VerT x;
	int n = G.Vertices.size, minCost;
	int* lowCost = (int*)malloc(sizeof(int) * n);  //����lowCost����ռ�
	int i, j, k;
	for (i = 1; i < n; i++)  //��ʼ��lowCost����
	{
		lowCost[i] = G.edge[0][1];
	}
	//�Ӷ���0����������С������
	ListGet(G.Vertices, 0, &x);  //ȡ����0
	closeVertex[0].vertex = x;  //���涥��0
	lowCost[0] = -1;  //��Ƕ���0
	for (i = 1; i < n; i++)
	{
		//Ѱ�ҵ�ǰ��СȨֵ�ı�����Ӧ�Ļ�ͷ����k
		minCost = MaxWeight;  //MaxWeightΪ��������Ȩֵ
		for (j = 0; j < n; j++)
		{
			if (lowCost[j] < minCost && lowCost[j]>0)
			{
				minCost = lowCost[j];
				k = j;
			}
		}
		//ȡ����ǰ��СȨֵ������Ӧ�Ķ���k��������С������
		ListGet(G.Vertices, k, &x);
		closeVertex[i].vertex = x;
		closeVertex[i].weight = minCost;
		lowCost[k] = -1;  //���k����Ϊ-1
		//���ݼ��뼯��U�Ķ���k�޸�lowCost�е���ֵ
		for (j = 1; j < n; j++)
		{
			//����¼���Ķ������С��ԭ����,�����lowCost����
			if (G.edge[k][j] < lowCost[j])
			{
				lowCost[j] = G.edge[k][j];
			}
		}
	}
}
