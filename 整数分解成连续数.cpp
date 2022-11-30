#include<stdio.h>
int main()
{
	printf("输入要分解的数字:");
	int n,i=0,j,k,s,count=0;
	scanf("%d",&n);
	while(1)
	{
		i++;
		j=1;
		while(1)
		{
			j++;
			s=i*j+j*(j-1)/2;
			if(s<=n)
			{	
				if(s==n)
				{
					for(k=i;k<=i+j-1;k++)
						printf("%d ",k);
					printf("\n");
					count++;	
				}	
			}else break;
		}
		if(i>n/2)break;
	}
	if(count==0)printf("NONE");
	return 0;
} 
