#include <stdio.h>
#include "DString.h"

int KMPIndex_1(DString S, int start, DString T,int next[])
//查找主串S从start开始的子串T,成功则返回T在S中的首字符下标,失败返回-1
//数组next中存放有模式串T的next[j]值
{
	int i = start, j = 0, v;
	while (i<S.length&&j<T.length)
	{
		if (j == -1 || S.str[i] == T.str[i])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j==T.length)
	{
		v = i - T.length;
	}
	else
	{
		v = -1;
	}
	return v;
}

int KMPIndex_2(DString S, int start, DString T, int next[])
{
	int i = start, j = 0, v;
	while (i < S.length && j < T.length)
	{
		if (j == -1 || S.str[i] == T.str[i])
		{
			i++;
			j++;
		}
		else if (j == 0)
		{
			i++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == T.length)
	{
		v = i - T.length;
	}
	else
	{
		v = -1;
	}
	return v;
}

void GetNext(DString T, int next[])
//求子串T的next[j]值并存于数组next中
{
	int j = 1, k = 0;
	next[0] = -1;
	next[1] = 0;
	while (j<T.length-1)
	{
		if (T.str[j] == T.str[k])
		{
			next[j + 1] = k + 1;
			j++;
			k++;
		}
		else if(k==0)
		{
			next[j + 1] = 0;
			j++;
		}
		else
		{
			k = next[k];
		}
	}
}