//  **�Թ�����**
//  ����:���õݹ��㷨�Ͷ�ջ�ҳ���ʼ�㵽�յ��·��
#include <stdio.h>

typedef struct
{
	int x;
	int y;
}Point;

int* mazeSolveByRecur(int arr[][10], Point cur, Point end, int path[])
//���õݹ��㷨����Թ�����
{

	return path;
}

int next(int arr[][10], Point cur, Point end)
//ȷ����һ��Ҫ�ߵķ���
{
	if ((cur.x = end.x) && (cur.y == end.y))
	{
		return 1;
	}
	else
	{
		//����������˳����
		arr[cur.x][cur.y] = 2;
		if (arr[cur.x+1][cur.y]==0)  //��
		{
			Point t;
			t.x = cur.x + 1;
			t.y = cur.y;
			if (next(arr, t, end))
			{
				return 1;
			}
		}
		if (arr[cur.x][cur.y+1]==0)  //��
		{
			Point t;
			t.x = cur.x;
			t.y = cur.y + 1;
			if (next(arr,t,end))
			{
				return 1;
			}
		}
		if (arr[cur.x][cur.y-1]==0)  //��
		{
			Point t;
			t.x = cur.x;
			t.y = cur.y + 1;
			if (next(arr,t,end))
			{
				return 1;
			}
		}
		if (arr[cur.x-1][cur.y]==0)  //��
		{
			Point t;
			t.x = cur.x;
			t.y = cur.y + 1;
			if (next(arr,t,end))
			{
				return 1;
			}
		}
	}
	arr[cur.x][cur.y] = 1;
	return 0;  //�����������߲�ͨ�򷵻�0
}

void PrintPath(int arr[][10])
{
	int i, j;
	for ( i = 0; i < 10; i++)
	{
		for ( j = 0; j < 10; j++)
		{
			if (arr[i][j]==-1)
			{
				printf("��");
			}
			else if(arr[i][j]==2)
			{
				printf("*");
			}
			else
			{
				printf("��");
			}
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int maze[10][10] = { {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,0,0,-1,0,0,0,-1,0,-1},
		{-1,0,0,-1,0,0,0,-1,0,-1},
		{-1,0,0,0,0,-1,-1,0,0,-1},
		{-1,0,-1,-1,-1,0,0,0,0,-1},
		{-1,0,0,0,-1,0,0,0,0,-1},
		{-1,0,-1,0,0,0,-1,0,0,-1},
		{-1,0,-1,-1,-1,0,-1,-1,0,-1},
		{-1,-1,0,0,0,0,0,0,0,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} };
	PrintPath(maze);
	//Point cur, end;
	//cur.x = 1, cur.y = 1;
	//end.x = 8, end.y = 8;
	//next(maze, cur, end);
	return 0;
}