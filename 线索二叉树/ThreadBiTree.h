//  **����������**
//  ����:
//	������Ϊ0ʱ,��ָ��ָ�����ӽ��;������Ϊ1ʱ,��ָ��ָ�����ǰ�����
//	������Ϊ0ʱ,��ָ��ָ���Һ��ӽ��;������Ϊ1ʱ,��ָ��ָ����ĺ������
//	�������������������ʹ�ö������˷�������ָ���ܹ�����������
//	��ʹ�ö���������Ѱ��������ֻ�ܴӸ���Ҷ
//	������˫������������ǰ����ʹӺ���ǰ����
#pragma once
typedef struct Node
{
	DataType data;  //������
	int leftThread;  //������
	struct Node* leftChild;  //��ָ��
	int rightThread;  //������
	struct Node* rightChild;  //��ָ��
}ThreadBiNode;

//����������������
void InThread(ThreadBiNode* current, ThreadBiNode** pre)
//currentΪ��ǰ���ָ��,preΪ��ǰ����ǰ��ָ��
{

}
//��������������������tree

//