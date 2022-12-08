#include<stdio.h>
int main()
{
    int a[]={1,5,65,23,45,53,65,21,65,434,112,45,43};
    int length=sizeof(a)/sizeof(a[0]);
    int i,j;
    for(i=0;i<length;i++)
    {
        for(j=0;j<length-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<length;i++)
        printf("%-4d",a[i]);
    return 0;
}