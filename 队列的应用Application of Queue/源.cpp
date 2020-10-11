#include "PrintQue.h"
//  **打印队列演示**

int main()
{
	char ch = '0';
	int tid = 0;
	char* text = (char*)"打印的内容";  //强制类型转换
	Queue Q;
	InitTaskManager(&Q);
	//菜单
	while (ch!='q')
	{
		printf("1 加入\n");
		printf("2 完成\n");
		printf("3 输出\n");
		printf("4 清空\n");
		printf("q 退出\n");
		printf("请输入编号: ");
		ch = getchar();
		getchar();  //吸收换行符
		switch (ch)
		{
		case '1':
			tid = tid + 1;
			AppendPrintTask(&Q, tid, text);
			break;
		case '2':
			PrintFirstTask(&Q);
			break;
		case '3':
			PrintAllTask(&Q);
			break;
		case '4':
			ClearPrintTask(&Q);
			break;
		case 'q':
			return 0;
		default:
			printf("输入的编号有误!\n");
			break;
		}
	}
	return 0;
}