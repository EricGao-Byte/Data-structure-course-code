#pragma once
#include <stdio.h>
typedef int dataType;
typedef struct
{
	dataType data;  //������
	int cur;  //�α�
}component;

const int MaxSize = 6;

//������������,��������������ǻ���������δʹ�û�֮ǰʹ�ù���Ŀǰδʹ�ã��Ĵ洢�ռ䣬��������ʹ�á�
//��ʵ��,������������Ĺ��̾��Ǵ�������Ĺ���
void SLinListReserve(component* array)
{
	for (int i = 0; i < MaxSize; i++)
	{
		array[i].cur = i + 1;  //��ÿһ������������ӵ�һ��
		array[i].data = 0;
	}
	array[MaxSize - 1].cur = 0;  //�������һ���ڵ���α�ֵΪ0
}

//��ȡ����ռ�,����������ռ���±�
int SLinListMalloc(component* array)
//����������ǿ�,�򷵻ط���Ľڵ��±�,���򷵻�0(���ҽ������䵽���һ���ڵ�ʱ,�ýڵ���α�ֵΪ0)
{
	int i = array[0].cur;
	if (array[0].cur)
	{
		array[0].cur = array[i].cur;
	}
	return i;
}

//��ʼ����̬����
int SLinListInit(component* array)
{
	SLinListReserve(array);  //���ӱ�������
	//�ӱ����������ó�һ��������Ϊ�����ͷ�ڵ�,���ص�������������±�
	int body = SLinListMalloc(array);  //ͷ�ڵ�λ��
	int tempBody = 0;
	int i = 0;
	//������Ԫ�ڵ�
	array[body].data = 1;
	array[body].cur = 0;
	//����һ������,������ָ��ʹ��,ָ����������һ�����,��ǰ����Ԫ����غ�
	tempBody = body;
	//��ʼ��һ�ξ�̬����
	for (i = 2; i < 4; i++)
	{
		int j = SLinListMalloc(array);  //�ӱ����������ó����еķ���
		array[j].data = i;  //��ʼ���µĵ��Ŀռ���
		array[tempBody].cur = j;  //���µĵ��Ľ�����ӵ����������β��
		tempBody = j;
	}
	array[tempBody].cur = 0;  //�µ��������һ�����ָ������Ϊ0
	return body;  //����ͷ�ڵ�λ��
}

//����Ԫ��,��x����Ϊ��n�����
void SLinListInsert(component* array, int body, int n, dataType x)
{
	int tempBody = body;
	int i = 0, insert = 0;
	//�ҵ�����λ�õ���һ������λ��
	for (i = 1; i < n; i++)
	{
		tempBody = array[tempBody].cur;
	}
	insert = SLinListMalloc(array);  //����ռ�
	array[insert].data = x;

	array[insert].cur = array[tempBody].cur;  //�²�������α������ֱ��ǰ�������α�
	array[tempBody].cur = insert;  //ǰ�������α���ڲ�������±�
}

//ɾ��Ԫ��,�����ͷ�ڵ�����,�����ɾ��ͷ�ڵ�������������һ���հ�head���
int SLinListDelete(component* array, int body, dataType n)
//ɾ������Ϊn�����,����ɾ������̬����ͷ�ڵ��λ��
{
	void SLinListFree(component * array, int n);
	int tempBody = body;
	int del = 0;
	int newBody = 0;
	//Ѱ�ұ�ɾ������λ��
	while (array[tempBody].data != n)
	{
		tempBody = array[tempBody].cur;
		if (tempBody == 0)  //Ϊ0��ʾ�������������Ҳû�ҵ����
		{
			printf("�������޴�����!!\n");
			return NULL;
		}
	}
	//���е���,֤���ҵ��˽��
	del = tempBody;
	tempBody = body;
	//ɾ����Ԫ�����������
	if (del = body)
	{
		newBody = array[del].cur;
		SLinListFree(array, del);
		return newBody;
	}
	else
	{
		//�ҵ��ý�����һ�����
		while (array[tempBody].cur != del)
		{
			tempBody = array[tempBody].cur;  //����
		}

		//����ɾ�������α�ֱ�Ӹ���ɾ��������һ�����
		array[tempBody].cur = array[del].cur;
		SLinListFree(array, del);
		return body;
	}
}

//��������Ԫ��
//��������Ϊn�Ľ���λ��
int SLinListFind(component* array, int body, dataType n)
{
	int tempBody = body;
	//���α�ֵΪ0ʱ,��ʾ�������
	while (array[tempBody].cur != 0)
	{
		if (array[tempBody].data == n)
		{
			return tempBody;
		}
		tempBody = array[tempBody].cur;
	}
	//�ж����һ������Ƿ����Ҫ��
	if (array[tempBody].data == n)
	{
		return tempBody;
	}
	return -1;  //��ʾû���ҵ�Ԫ��
}

//�޸�����
void SLinListModify(component* array, int body, dataType oldData, dataType newData)
{
	int n = SLinListFind(array, body, oldData);
	if (n == -1)
	{
		printf("�޸���Ԫ��!!\n");
		return;
	}
	array[n].data = newData;
}

//����������տռ�ĺ���������arrayΪ�洢���ݵ����飬k��ʾδʹ�ýڵ�����������±�
void SLinListFree(component* array, int n)
{
	array[n].cur = array[0].cur;
	array[0].cur = n;
}

//��ӡ��̬����
void SLinListDisplay(component* array, int body)
{
	int tempBody = body;  //tempBody������������
	while (array[tempBody].cur)
	{
		printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
		tempBody = array[tempBody].cur;
	}
	printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
}