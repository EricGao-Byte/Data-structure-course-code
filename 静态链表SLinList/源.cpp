#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "SLinList.h"

int main()
{
    component array[MaxSize];
    int body = SLinListInit(array);
    int selectAdd;
    printf("��̬����Ϊ��\n");
    SLinListDisplay(array, body);
    printf("�ڵ�3��λ���ϲ���Ԫ��4:\n");
    SLinListInsert(array, body, 3, 4);
    SLinListDisplay(array, body);
    printf("ɾ��������Ϊ1�Ľ��:\n");
    body = SLinListDelete(array, body, 1);
    SLinListDisplay(array, body);
    printf("����������Ϊ4�Ľ���λ��:\n");
    selectAdd = SLinListFind(array, body, 4);
    printf("%d\n", selectAdd);
    printf("�����������Ϊ4��Ϊ5:\n");
    SLinListModify(array, body, 4, 5);
    SLinListDisplay(array, body);
    return 0;
}