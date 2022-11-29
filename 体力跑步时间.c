#include<stdio.h>
#include<assert.h>
int main()
{
    int time=0,t;
    int energy=10000;
    while(energy)
    {
        for(t=0;t<60;t++)
        {
            if(energy)
            {
                energy-=10;
                time++;
            }else break;    
        }
        if(!energy)break;
        energy+=300;
        time+=60;
    }
    printf("%d",time);
    return 0;
}