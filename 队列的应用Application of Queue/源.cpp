#include "PrintQue.h"
//  **��ӡ������ʾ**

int main()
{
	char ch = '0';
	int tid = 0;
	char* text = (char*)"��ӡ������";  //ǿ������ת��
	Queue Q;
	InitTaskManager(&Q);
	//�˵�
	while (ch!='q')
	{
		printf("1 ����\n");
		printf("2 ���\n");
		printf("3 ���\n");
		printf("4 ���\n");
		printf("q �˳�\n");
		printf("��������: ");
		ch = getchar();
		getchar();  //���ջ��з�
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
			printf("����ı������!\n");
			break;
		}
	}
	return 0;
}