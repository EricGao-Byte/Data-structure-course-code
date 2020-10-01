#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "SLinList.h"

int main()
{
    component array[MaxSize];
    int body = SLinListInit(array);
    int selectAdd;
    printf("静态链表为：\n");
    SLinListDisplay(array, body);
    printf("在第3的位置上插入元素4:\n");
    SLinListInsert(array, body, 3, 4);
    SLinListDisplay(array, body);
    printf("删除数据域为1的结点:\n");
    body = SLinListDelete(array, body, 1);
    SLinListDisplay(array, body);
    printf("查找数据域为4的结点的位置:\n");
    selectAdd = SLinListFind(array, body, 4);
    printf("%d\n", selectAdd);
    printf("将结点数据域为4改为5:\n");
    SLinListModify(array, body, 4, 5);
    SLinListDisplay(array, body);
    return 0;
}