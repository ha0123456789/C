#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prior;    
}node;
int main()
{
    node *head=(node*)malloc(sizeof(node));
    node *end=head;
    head->prior=NULL;
    printf("输入要录入的个数：");
    int num,wei,count=1;
    scanf("%d",&num);
    for(;num>0;num--)
    {
        node *p=(node*)malloc(sizeof(node));
        p->next=NULL;
        end->next=p;
        p->prior=end;
        end=p;
        printf("输入数据：");
        scanf("%d",&p->data);
    }
    printf("输入要查找的位数：");
    scanf("%d",&wei);
    node *p=head->next;
    while(p)
    {
        if(wei==count)  
        {
            printf("本位为%d",p->data);
            if(p->prior&&p->prior!=head)printf(",上一位为%d",p->prior->data);
            if(p->next)printf(",下一位为%d",p->next->data);
            printf("\n");
            break;
        }
        p=p->next;
        count++;
    }
    printf("最后结果：\n");
    p=head->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return 0;
}