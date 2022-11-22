#include<stdio.h>
#include<string.h>
void delet(char *a);
int main()
{
	char a[20];
	printf("ÇëÊäÈë×Ö·û´®£º"); 
	gets(a);
	delet(a);
	printf("É¾³ý´óÐ´×ÖÄ¸£º%s",a);
	return 0;	
}
void delet(char *a)
{
	int i=0,j=0;
	char b[20];
	while(a[i])
		if(a[i]>95)
			b[j++]=a[i++];
		else i++;	
	b[j+1]='\0';
	strcpy(a,b);
} 
