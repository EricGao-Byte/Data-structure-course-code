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

	//串长度
	//原型int strlen(char* str);
	printf("len(s1)=%d\n", strlen(s1));
	printf("len(s2)=%d\n", strlen(s2));
	
	//复制
	//原型char* strcpy(char* str1,char* str2)
	strcpy(s4, s2);
	printf("cp s2 to s4 = %s\n", s4);

	//比较
	//原型int strcmp(char* str1,char* str2)
	result = strcmp(s2, s3);  //s2>s3
	printf("s2 cmp s3 = %d\n", result);
	result = strcmp(s2, s2);  //s2==s2
	printf("s2 cmp s2 = %d\n", result);
	result = strcmp(s3, s2);  //s3<s2
	printf("s3 cmp s2 = %d\n", result);

	//字符定位
	//char* strchr(char* str,char ch)
	p = strchr(s1, 's');  //p指向字符s位置
	printf("p = %s\n", p);

	//子串查找
	//char* strstr(char* s1,char* s2)
	p = strstr(s1, s3);  //p指向s1中字符s所在位置
	printf("s3 in s1 = %s\n", p);  

	//连接
	//char* strcat(str* s1,str* s2)
	strcat(s2, s3);
	printf("s2 cat s3 = %s\n", s2);

	//名和姓对换问题
	//一般情况: 名在前 姓在后
	//某些情况: 姓在前, 名在后(中间加逗号)
	//编写程序转化一般情况->特殊情况

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
	strcpy(newName, p+1);  //指向姓位置
	strcat(newName, ",");
	strcat(newName, name);
	*p = ' ';  //恢复原字符串为开始的样子
}