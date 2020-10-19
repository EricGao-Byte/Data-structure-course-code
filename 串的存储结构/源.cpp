#include "DString.h"

int main()
{
	DString myString;
	char s1[] = "i am a student";
	int maxStringSize;
	maxStringSize = 20;
	Init(&myString, maxStringSize, s1);
	printf("s1=");
	Print(myString);

	char s2[] = "teacher";
	DString myString2;
	Init(&myString2, maxStringSize, s2);
	printf("s2=");
	Print(myString2);
	Insert(&myString, 6, myString2);
	Print(myString);
	Delete(&myString, 6, 7);
	Print(myString);
	SubString(&myString, 7, 7,&myString2);
	Print(myString2);
	Destroy(&myString);
	Destroy(&myString2);
	return 0;
}
