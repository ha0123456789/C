#include<stdio.h>
#include<malloc.h>
int main()
{
	printf("输入数组:");
	int n,i,j,target,*a=NULL,k=1;
	a=(int*)malloc(n*sizeof(int));
	char ch;
	for(n=1;;n++)
	{
		scanf("%d",&a[n]);
		if(ch=getchar()=='\n')break;
	}
	printf("输入目标:");
	scanf("%d",&target);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]+a[j]==target)
			{
				printf("[%d,%d] ",i,j);
				k=0; 
			}	
	if(k!=0)printf("未找到"); 
	free(a);
	return 0;
} 
