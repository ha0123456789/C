#include<stdio.h>
void strcopy(char *str1,const char *str2)
{
	while(*str1++=*str2++);
}
int main()
{
	char str1[10],str2[10];
	printf(" ‰»Îstr1£∫");
	gets(str1);
	printf(" ‰»Îstr2£∫");
	gets(str2);
	strcopy(str1,str2);
	printf("str1=%s\n",str1);
	return 0;
} 
