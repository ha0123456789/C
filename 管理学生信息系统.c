#include"ku.h"
int i,k=1,sumpeople=0;
int main()
{
	system("color F0");
	system("mode con cols=60 lines=40");
	char account[15],password[15];
	printf("\t\t    学生成绩管理信息系统\n");
	int r,s=0;
	for(r=0;r<5;r++)
	{
		printf("请输入管理员账号（您只有五次机会）：");
		scanf("%s",account);
		printf("请输入账号密码：");/*账号：12345；密码：67890*/
		scanf("%s",password);
		if(strcmp("12345",account)==0&&strcmp("67890",password)==0)		
		{
			s=1;
			break;
		}else printf("账号或密码错误，请重试\n");
	}
	system("CLS");
	if(s)
	{
		node *head,*last,*p=(node*)malloc(sizeof(node));
		head=last=p;
		p->next=NULL;
		while(1)
		{
			menu(); 
			int order,flag=0;
			scanf("%d", &order);
			switch(order)
			{
				case 1 :add(&last);
					   	break;
				case 2 :insert(head);
						break;
				case 3 :delet(head);
						break;
				case 4 :modify(head);
						break;
				case 5 :sort(head);
						break;
				case 6 :search(head);
						break;
				case 7 :display(head);
						break;
				case 8 :clear(&head,&last);
						break; 
				case 9 :store(head);
						break;
				case 10:read(head,&last);
						break;	
				case 11:flag=1;
						break;		
				default:printf("输入错误，返回菜单\n");
						system("pause");
						system("CLS");
			}
			if(flag)break;
		}
		system("CLS");
		printf("\t\t    学生成绩管理信息系统\n");
		printf("您已退出学生成绩管理信息系统\n"); 
	}else{
		printf("登录失败\n");
		system("pause");
	}
	return 0;	
} 
