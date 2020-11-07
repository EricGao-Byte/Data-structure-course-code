#pragma once
//	**��������(Huffman Tree)**
//	����:
//	����������һ�ִ�Ȩ������,����ÿ��Ҷ�ڵ㶼����Ȩֵ
//	�������Ĵ�Ȩ·������=ÿ��Ҷ�ڵ��·������*ÿ��Ҷ�ڵ��Ȩֵ �����
#include <malloc.h>

//˫�׽��ķ���ָ�빹��Ĺ�������
typedef struct Node
{
	int weight;  //Ȩֵ
	int flag;  //���
	int parent;  //˫�׽���±�
	int rightChild;  //�Һ����±�
	int leftChild;  //�����±�
}HuffmanNode;  //���������Ľ��ṹ

typedef struct
{
	int bit[MaxBit];  //����
	int start;  //����ĳ�ʼ�±�
	int weight;  //�ַ���Ȩ��
}Code;  //����������Ľṹ

void Huffman(int weight[], int n, HuffmanNode hufftree[])
//����������Ϊn,Ȩֵ����Ϊweight�Ĺ�������hufftree
{
	int i, j, m1, m2, x1, x2;
	//��������hufftree��ʼ��,n��Ҷ�ڵ�Ķ���������2n-1�����
	for ( i = 0; i < 2*n-1; i++)
	{
		if (i<n)
		{
			hufftree[i].weight = weight[i];
		}
		else
		{
			hufftree[i].weight = 0;
		}
		hufftree[i].parent = -1;
		hufftree[i].flag = 0;
		hufftree[i].leftChild = -1;
		hufftree[i].rightChild = -1;
	}
	//�����������hufftree��n-1����Ҷ���
	for ( i = 0; i < n-1; i++)
	{
		m1 = m2 = MaxValue;
		x1 = x2 = 0;
		//�ҳ�Ȩֵ��С�ʹ�С������
		for ( j = 0; j < n+i; j++)
		{
			if (hufftree[j].weight < m1 && hufftree[j].flag == 0)
			{
				m2 = m1;
				x2 = x1;
				m1 = hufftree[j].weight;
				x1 = j;
			}
			else if ((hufftree[j].weight < m2||hufftree[j].weight==m1) && hufftree[j].flag == 0)
			{
				m2 = hufftree[j].weight;
				x2 = j;
			}
		}
		//�ҳ�����Ȩֵ��С�ʹ�С�������ϲ�Ϊһ������
		hufftree[x1].parent = n + i;
		hufftree[x2].parent = n + i;
		hufftree[x1].flag = 1;
		hufftree[x2].flag = 1;
		hufftree[n + i].weight = hufftree[x1].weight + hufftree[x2].weight;
		hufftree[n + i].leftChild = x1;
		hufftree[n + i].rightChild = x2;
	}
}

//��n�����Ĺ�������hufftree�������������haffcode
void HuffmanCode(HuffmanNode hufftree[], int n, Code huffcode[])
{
	Code* cd = (Code*)malloc(sizeof(Code));
	int i, j, child, parent;
	//��n��Ҷ���Ĺ���������
	for ( i = 0; i < n; i++)
	{
		cd->start = n - 1;  //���ȳ��ı������һλλn-1
		cd->weight = hufftree[i].weight;  //ȡ�ñ����Ӧ��Ȩֵ����ֵ
		child = i;
		parent = hufftree[child].parent;
		//��Ҷ�ڵ�����ֱ�����ڵ�
		while (parent!=-1)
		{
			if (hufftree[parent].leftChild == child)
			{
				cd->bit[cd->start] = 0;  //���ӷ�֧����0
			}
			else
			{
				cd->bit[cd->start] = 1;  //�Һ��ӷ�֧����1
			}
			cd->start--;
			child = parent;
			parent = hufftree[child].parent;
		}
		for ( j = cd->start+1; j < n; j++)
		{
			huffcode[i].bit[j] = cd->bit[j];  //����ÿ��Ҷ�ڵ�Ĺ���������
		}
		huffcode[i].start = cd->start + 1;  //������������ʼλ��
		huffcode[i].weight = cd->weight;  //��������Ӧ��Ȩ��
	}
}