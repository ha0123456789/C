#include<stdio.h>
int main()
{
	int n1,n2,i=0,j,k,l,count=0,z=1;
	printf("����������:");
	scanf("%d",&n1);
	int a[n1][n1];
	printf("�������:\n");
	for(;i<n1;i++)
		for(j=0;j<n1;j++)
			scanf("%d",&a[i][j]);
	printf("��������ҵľ������:");
	scanf("%d",&n2);
	int b[n2][n2];
	printf("��������ҵľ���:\n");
	for(count=0,i=0;i<n2;i++)
		for(j=0;j<n2;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<=n1-n2;i++)
	{
		for(j=0;j<=n1-n2;j++)
		{
			for(count=1,k=0;k<n2;k++)
			{
				for(l=0;l<n2;l++)
				{
					if(a[i+k][j+l]!=b[k][l])
						count=0;
				}
			}
			if(count)
			{
				printf("��ʼ�ص���%d��%d��",i,j);
				z=0;
			}
		}
	}
	if(z)printf("-1");
	return 0;
 } 
