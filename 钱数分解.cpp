#include<stdio.h>
int Fun(int *n,int q)
{
	int z;
	z=*n/q;
	*n%=q;
	return z;
}
int main()
{
	int n,i,a[]={10,5,2,1},b[4]={0};
	printf("����Ǯ��:");
	scanf("%d",&n);
	for(i=0;i<4;i++)
	{
		b[i]=Fun(&n,a[i]);
		if(b[i]!=0)printf("%d��%dԪ ",b[i],a[i]);
	}
	return 0;
}
