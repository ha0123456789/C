#include"ku.h"
void menu(void)
{
	printf("\t\t    学生成绩管理信息系统\n");
	printf("\t\t\t    菜单\n"); 
	printf("（1）录入\t（2）添加\t（3）删除\t（4）修改\n（5）排序\t（6）查询\t（7）显示\t（8）清空\n（9）保存\t（10）读入\t(11)退出\n输入命令：");
}
void add(node **last)
{		
	while(1)
	{
		int people;
		printf("输入要录入的人数："); 
		scanf("%d",&people);
		sumpeople+=people;
		for(i=0;i<people;i++)
		{
			printf("请输入学号姓名性别与成绩：");
			node *p=(node*)malloc(sizeof(node));
			(*last)->next=p;
			p->next=NULL;
			scanf("%s%s%s%lf",p->num,p->name,p->gender,&p->grade);
			*last=p;
		}
		k=0;
		while(1)
		{
			printf("是否继续录入（0/1）：");
			scanf("%d",&i);
			if(i==0)
			{	
				k=1;
				break;	
			} else	if(i==1)break;
					else printf("输入错误，请重试\n"); 					
		}
		if(k)break;
	}
	system("CLS");
}
void delet(node *head)
{
	if(head->next==NULL)
	{
		printf("尚未录入信息\n");
		system("pause");
	}else{
		printf("请选择搜索方式（1学号，2名字）："); 
		while(1)
		{
			scanf("%d",&i);
			if(i==1)
			{ 
				printf("请输入要删除的学生学号：");		 
				char deletenum[10];
				scanf("%s",deletenum);
				node *p,*prep;
				p=prep=head->next;
				if(strcmp(deletenum,head->next->num)==0)
				{
					node *p=head->next;
					head->next=head->next->next;
					k=0;
				}else{
					while(p!=NULL)
					{
						if(strcmp(deletenum,p->num)==0)
						{
							prep->next=p->next;
							k=0;
						}
					prep=p;
					p=p->next;
					}
				}
				break;
			} else  if(i==2)
					{
						printf("请输入要删除的学生名字：");
						char deletename[10];
						k=1;
						scanf("%s",deletename);
						node *p,*prep;
						p=prep=head->next;
						if(strcmp(deletename,head->next->name)==0)
						{
							head->next=head->next->next;
							k=0;
							free(head->next); 
						}else{
							while(p!=NULL)
							{
								if(strcmp(deletename,p->name)==0)
								{
									prep->next=p->next;
									k=0;
									free(p);
									break;
								}
								prep=p;
								p=p->next;
							}
						}
						break;
					} else printf("输入错误，请重试：");
		}
				if(k)
				{
					printf("无该生信息\n");
					system("pause");
				}else{
					sumpeople--;
					printf("删除成功\n");
					system("pause");
					k=1;
				} 
			}
	system("CLS");
}
void clear(node **head,node **last)
{
	sumpeople=0; 
	(*head)->next=NULL;
	*last=*head;
	printf("信息已清空\n");
	system("pause");
	system("CLS");
}
void insert(node *head)
{
	if(head->next==NULL)
	{
		printf("尚未录入信息\n");
		system("pause");
	}else{
		node *p=head,*inserte=(node*)malloc(sizeof(node));
		printf("请选择参考位置搜索方式（1学号，2名字）：");
		while(1)
		{
			scanf("%d",&i);
			if(i==1)
			{ 
				char insertnum[10];
				printf("请输入学号："); 
				scanf("%s",insertnum);
				printf("请选择添加位置（1前添加，2后添加）：");
				while(1)
				{ 
					scanf("%d",&i);
					if(i==2)
					{
						while(p!=NULL)
						{
							if(strcmp(insertnum,p->num)==0)
							{				
								k=0;
								inserte->next=p->next;
								p->next=inserte;
								break;
							}
							p=p->next;
						}
						break;
					} else  if(i==1)
							{
								node *prep=p;
								while(p!=NULL)
								{
									if(strcmp(insertnum,p->num)==0)
									{				
										k=0;
										prep->next=inserte;
										inserte->next=p;
										break;
									}
									prep=p;
									p=p->next;
								}
								break;
							} else	printf("输入错误，请重试：");
				}
				break;
			} else  if(i==2)
					{
						printf("请输入名字："); 
						char insertname[10];
						scanf("%s",insertname);
						printf("请选择添加位置（1前添加，2后添加）：");
						while(1)
						{ 
							if(i==2)
							{
								scanf("%d",&i);
								while(p!=NULL)
								{
									if(strcmp(insertname,p->name)==0)
									{				
										k=0;
										inserte->next=p->next;
										p->next=inserte;
										break;
									}
									p=p->next;
								}
								break;
							} else  if(i==1)
									{
										node *prep=p;
										while(p!=NULL)
										{
											if(strcmp(insertname,p->name)==0)
											{				
												k=0;
												prep->next=inserte;
												inserte->next=p;
												break;
											}
											prep=p;
											p=p->next;
										}
										break;
									} else	printf("输入错误，请重试：");	
						} 
						break;
					}else printf("输入错误，请重试");
				}
		if(k)
		{
			printf("无该生信息\n");
			system("pause");
		}else{
			sumpeople++;
			printf("请输入学号姓名性别与成绩：");
			scanf("%s%s%s%lf",inserte->num,inserte->name,inserte->gender,&inserte->grade);
			printf("添加成功\n");
			system("pause");
			k=1;
		}
	}			
	system("CLS");	
}
void modify(node *head)
{
	if(head->next==NULL)
	{
		printf("尚未录入信息\n");
		system("pause");
	}else{
		printf("请选择待修改信息搜索方式（1学号，2名字）：");
		node *p=head->next;
		while(1)
		{ 
			scanf("%d",&i);
			if(i==1)
			{
				char modifynum[10];
				printf("请输入学号：");
				scanf("%s",modifynum);
				for(;p!=NULL;p=p->next)
					if(strcmp(modifynum,p->num)==0)
					{
						k=0;
						break;
					}
				break;
			} else  if(i==2)
					{
						char modifyname[10];
						printf("请输入名字：");
						scanf("%s",modifyname);
						for(;p!=NULL;p=p->next)
							if(strcmp(modifyname,p->name)==0)
							{
								k=0;
								break;
							}
						break;
					}else printf("输入错误，请重试："); 
		}
		if(k)
		{
			printf("无该生信息\n");
			system("pause");
		}else{
			printf("学号姓名与成绩修改为：");
			scanf("%s%s%s%lf",p->num,p->name,p->gender,&p->grade);
			printf("修改成功\n");
			system("pause");
			k=1;
		}
	}
	system("CLS");
}
void sort(node *head)
{
	node *p=head;
	printf("请选择排序方式（1成绩，2名字）");
	while(1)
	{
		scanf("%d",&i);
		if(i==1)
		{
			gradesort(p);
			break;
		} else  if(i==2)
				{
					namesort(p); 
					break;
				}else printf("输入错误，请重试："); 
	}	
}
void namesort(node *head)
{
	if(head->next==NULL)
	{
		printf("尚未录入信息\n");
		system("pause");
	}else{
		node *p=head->next,*q=NULL;
		printf("请选择顺序（1从A到Z，2从Z到A）：");
		while(1)
		{
			scanf("%d",&i);
			if(i==2)
			{
				node *max=NULL;
				for(;p!=NULL;p=p->next)
				{
					for(q=p,max=q;q!=NULL;q=q->next)
						if(strcmp(max->name,q->name)<0)max=q;
					node *temp=(node*)malloc(sizeof(node));
					if(strcmp(max->name,p->name)>0)
					{	
						strcpy(temp->num,max->num);strcpy(max->num,p->num);strcpy(p->num,temp->num);
						strcpy(temp->name,max->name);strcpy(max->name,p->name);strcpy(p->name,temp->name);
						strcpy(temp->gender,max->gender);strcpy(max->gender,p->gender);strcpy(p->gender,temp->gender);
						temp->grade=max->grade;max->grade=p->grade;p->grade=temp->grade;
					}
				}
				break; 
			} else  if(i==1)
					{
						node *min=NULL;
						for(;p!=NULL;p=p->next)
						{
							for(q=p,min=q;q!=NULL;q=q->next)
								if(strcmp(min->name,q->name)>0)min=q;
							node *temp=(node*)malloc(sizeof(node));
							if(strcmp(min->name,p->name)<0)
							{	
								strcpy(temp->num,min->num);strcpy(min->num,p->num);strcpy(p->num,temp->num);
								strcpy(temp->name,min->name);strcpy(min->name,p->name);strcpy(p->name,temp->name);
								strcpy(temp->gender,min->gender);strcpy(min->gender,p->gender);strcpy(p->gender,temp->gender);
								temp->grade=min->grade;min->grade=p->grade;p->grade=temp->grade;
							}
						}
						break;
					}else printf("输入错误，请重试：");
		}
	}
	printf("排序成功\n"); 
	system("pause");
	system("CLS");	
}
void gradesort(node *head)
{
	if(head->next==NULL)
	{
		printf("尚未录入信息\n");
		system("pause");
	}else{
		node *p=head->next,*q=NULL;
		printf("请选择顺序（1从高到低，2从低到高）：");
		while(1)
		{
			scanf("%d",&i);
			if(i==1)
			{
				node *max=NULL;
				for(;p!=NULL;p=p->next)
				{
					for(q=p,max=q;q!=NULL;q=q->next)
						if(max->grade<=q->grade)max=q;
					node *temp=(node*)malloc(sizeof(node));
					if(max->grade!=p->grade)
					{	
						strcpy(temp->num,max->num);strcpy(max->num,p->num);strcpy(p->num,temp->num);
						strcpy(temp->name,max->name);strcpy(max->name,p->name);strcpy(p->name,temp->name);
						strcpy(temp->gender,max->gender);strcpy(max->gender,p->gender);strcpy(p->gender,temp->gender);
						temp->grade=max->grade;max->grade=p->grade;p->grade=temp->grade;
					}
				}
				break; 
			} else  if(i==2)
					{
						node *min=NULL;
						for(;p!=NULL;p=p->next)
						{
							for(q=p,min=q;q!=NULL;q=q->next)
								if(min->grade>=q->grade)min=q;
							node *temp=(node*)malloc(sizeof(node));
							if(min->grade!=p->grade)
							{	
								strcpy(temp->num,min->num);strcpy(min->num,p->num);strcpy(p->num,temp->num);
								strcpy(temp->name,min->name);strcpy(min->name,p->name);strcpy(p->name,temp->name);
								strcpy(temp->gender,min->gender);strcpy(min->gender,p->gender);strcpy(p->gender,temp->gender);
								temp->grade=min->grade;min->grade=p->grade;p->grade=temp->grade;
							}
						}
						break;
					}else printf("输入错误，请重试：");
		}
	}
	printf("排序成功\n"); 
	system("pause");
	system("CLS");	
}
void search(node *head)
{
	if(head->next==NULL)
		printf("尚未录入信息\n");
	else{
		printf("请选择待查找信息搜索方式（1学号，2名字）：");	
		node *p=head->next;
		while(1)
		{
			scanf("%d",&i);
			if(i==1)
			{ 
				char deletenum[10];
				printf("请输入学号："); 
				scanf("%s",deletenum);
				while(p!=NULL)
				{
					if(strcmp(deletenum,p->num)==0)
					{				
						k=0;
						break;
					}
					p=p->next;
				}
				break;
			} else  if(i==2)
					{
						char deletename[10];
						printf("请输入名字："); 
						scanf("%s",deletename);
						while(p!=NULL)
						{
							if(strcmp(deletename,p->name)==0)
							{				
								k=0;
								break;
							}
							p=p->next;
						}
						break;
					}else printf("输入错误，请重试："); 
			}
		if(k)printf("无该生信息\n");
		else{
			printf("学号\t\t姓名\t\t性别\t\t成绩\n");
			printf("%s\t\t%s\t\t%s\t\t%f\n",p->num,p->name,p->gender,p->grade); 
			k=1;
		}
	}
	system("pause");
	system("CLS"); 
}
void display(node *head)
{
	node *p=head->next;
	if(head->next==NULL)
		printf("尚未录入信息\n");	
	else{
		printf("学号\t姓名\t性别\t成绩\n");
		while(p!=NULL)
		{
			printf("%s\t%s\t%s\t%f\n",p->num,p->name,p->gender,p->grade); 
			p=p->next;
		}
	}
	system("pause");
	system("CLS"); 
}
void store(node *head)
{
	FILE *fp=fopen("students management information system.txt","w+");
	if(!fp)printf("打开失败\n"); 
	else{
		fprintf(fp,"%d\n",sumpeople);
		node *p=head->next;
		while(p)
		{
			fprintf(fp,"%s\t%s\t%s\t%f\n",p->num,p->name,p->gender,p->grade);
			p=p->next;
		}
		printf("保存成功\n");
		fp=NULL;
	}
	fclose(fp);
	system("pause");
	system("CLS");
}
void read(node *head,node **last)
{
	FILE *fp=fopen("students management information system.txt","r+");
	if(!fp)printf("打开失败\n"); 
	else{
		if(sumpeople==0)
		{
			fscanf(fp,"%d",&sumpeople);
			for(i=0;i<sumpeople;i++)
			{
				node *p1=(node*)malloc(sizeof(node));
				(*last)->next=p1;
				p1->next=NULL;
				*last=p1;
			}
			node *p=head->next;
			while(p)
			{
				fscanf(fp,"%s%s%s%lf",p->num,p->name,p->gender,&p->grade);
				p=p->next;
			}
		}else{
			int temp;
			fscanf(fp,"%d",&temp);
			node *storelast=*last;
			for(i=0;i<temp;i++)
			{
				node *p1=(node*)malloc(sizeof(node));
				(*last)->next=p1;
				p1->next=NULL;
				*last=p1;
			}
			node *p=storelast->next;
			while(p)
			{
				fscanf(fp,"%s%s%s%lf",p->num,p->name,p->gender,&p->grade);
				p=p->next;
			}
			sumpeople+=temp;
		}
		printf("读入成功\n");
		fp=NULL;
	}
	fclose(fp);
	system("pause");
	system("CLS");
}
