#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "i am a student";
	char s2[20] = "teacher";
	char s3[] = "student";
	int result;
	char s4[20] = "", * p;
	printf("s1=%s\n", s1);
	printf("s2=%s\n", s2);
	printf("s3=%s\n", s3);
	printf("s4=%s\n", s4);

	//������
	//ԭ��int strlen(char* str);
	printf("len(s1)=%d\n", strlen(s1));
	printf("len(s2)=%d\n", strlen(s2));
	
	//����
	//ԭ��char* strcpy(char* str1,char* str2)
	strcpy(s4, s2);
	printf("cp s2 to s4 = %s\n", s4);

	//�Ƚ�
	//ԭ��int strcmp(char* str1,char* str2)
	result = strcmp(s2, s3);  //s2>s3
	printf("s2 cmp s3 = %d\n", result);
	result = strcmp(s2, s2);  //s2==s2
	printf("s2 cmp s2 = %d\n", result);
	result = strcmp(s3, s2);  //s3<s2
	printf("s3 cmp s2 = %d\n", result);

	//�ַ���λ
	//char* strchr(char* str,char ch)
	p = strchr(s1, 's');  //pָ���ַ�sλ��
	printf("p = %s\n", p);

	//�Ӵ�����
	//char* strstr(char* s1,char* s2)
	p = strstr(s1, s3);  //pָ��s1���ַ�s����λ��
	printf("s3 in s1 = %s\n", p);  

	//����
	//char* strcat(str* s1,str* s2)
	strcat(s2, s3);
	printf("s2 cat s3 = %s\n", s2);

	//�����նԻ�����
	//һ�����: ����ǰ ���ں�
	//ĳЩ���: ����ǰ, ���ں�(�м�Ӷ���)
	//��д����ת��һ�����->�������

	void ReverseName(char* name, char* newName);
	char name[] = "Eric Deamn";
	char newName[30];
	ReverseName(name, newName);
	printf("name = %s\nnewName = %s", name, newName);

	return 0;
}

void ReverseName(char* name, char* newName)
{
	char* p;
	p = strchr(name, ' ');
	*p = '\0';
	strcpy(newName, p+1);  //ָ����λ��
	strcat(newName, ",");
	strcat(newName, name);
	*p = ' ';  //�ָ�ԭ�ַ���Ϊ��ʼ������
}