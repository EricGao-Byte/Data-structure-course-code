//  **迷宫问题**
//  描述:利用递归算法和堆栈找出起始点到终点的路径
#include <stdio.h>

typedef struct
{
	int x;
	int y;
}Point;

int* mazeSolveByRecur(int arr[][10], Point cur, Point end, int path[])
//利用递归算法求解迷宫问题
{

	return path;
}

int next(int arr[][10], Point cur, Point end)
//确定下一步要走的方向
{
	if ((cur.x = end.x) && (cur.y == end.y))
	{
		return 1;
	}
	else
	{
		//东南西北按顺序走
		arr[cur.x][cur.y] = 2;
		if (arr[cur.x+1][cur.y]==0)  //东
		{
			Point t;
			t.x = cur.x + 1;
			t.y = cur.y;
			if (next(arr, t, end))
			{
				return 1;
			}
		}
		if (arr[cur.x][cur.y+1]==0)  //南
		{
			Point t;
			t.x = cur.x;
			t.y = cur.y + 1;
			if (next(arr,t,end))
			{
				return 1;
			}
		}
		if (arr[cur.x][cur.y-1]==0)  //西
		{
			Point t;
			t.x = cur.x;
			t.y = cur.y + 1;
			if (next(arr,t,end))
			{
				return 1;
			}
		}
		if (arr[cur.x-1][cur.y]==0)  //北
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
	return 0;  //东南西北都走不通则返回0
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
				printf("■");
			}
			else if(arr[i][j]==2)
			{
				printf("*");
			}
			else
			{
				printf("□");
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