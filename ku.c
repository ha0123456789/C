#include"ku.h"
void menu(void)
{
	printf("\t\t    ѧ���ɼ�������Ϣϵͳ\n");
	printf("\t\t\t    �˵�\n"); 
	printf("��1��¼��\t��2�����\t��3��ɾ��\t��4���޸�\n��5������\t��6����ѯ\t��7����ʾ\t��8�����\n��9������\t��10������\t(11)�˳�\n�������");
}
void add(node **last)
{		
	while(1)
	{
		int people;
		printf("����Ҫ¼���������"); 
		scanf("%d",&people);
		sumpeople+=people;
		for(i=0;i<people;i++)
		{
			printf("������ѧ�������Ա���ɼ���");
			node *p=(node*)malloc(sizeof(node));
			(*last)->next=p;
			p->next=NULL;
			scanf("%s%s%s%lf",p->num,p->name,p->gender,&p->grade);
			*last=p;
		}
		k=0;
		while(1)
		{
			printf("�Ƿ����¼�루0/1����");
			scanf("%d",&i);
			if(i==0)
			{	
				k=1;
				break;	
			} else	if(i==1)break;
					else printf("�������������\n"); 					
		}
		if(k)break;
	}
	system("CLS");
}
void delet(node *head)
{
	if(head->next==NULL)
	{
		printf("��δ¼����Ϣ\n");
		system("pause");
	}else{
		printf("��ѡ��������ʽ��1ѧ�ţ�2���֣���"); 
		while(1)
		{
			scanf("%d",&i);
			if(i==1)
			{ 
				printf("������Ҫɾ����ѧ��ѧ�ţ�");		 
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
						printf("������Ҫɾ����ѧ�����֣�");
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
					} else printf("������������ԣ�");
		}
				if(k)
				{
					printf("�޸�����Ϣ\n");
					system("pause");
				}else{
					sumpeople--;
					printf("ɾ���ɹ�\n");
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
	printf("��Ϣ�����\n");
	system("pause");
	system("CLS");
}
void insert(node *head)
{
	if(head->next==NULL)
	{
		printf("��δ¼����Ϣ\n");
		system("pause");
	}else{
		node *p=head,*inserte=(node*)malloc(sizeof(node));
		printf("��ѡ��ο�λ��������ʽ��1ѧ�ţ�2���֣���");
		while(1)
		{
			scanf("%d",&i);
			if(i==1)
			{ 
				char insertnum[10];
				printf("������ѧ�ţ�"); 
				scanf("%s",insertnum);
				printf("��ѡ�����λ�ã�1ǰ��ӣ�2����ӣ���");
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
							} else	printf("������������ԣ�");
				}
				break;
			} else  if(i==2)
					{
						printf("���������֣�"); 
						char insertname[10];
						scanf("%s",insertname);
						printf("��ѡ�����λ�ã�1ǰ��ӣ�2����ӣ���");
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
									} else	printf("������������ԣ�");	
						} 
						break;
					}else printf("�������������");
				}
		if(k)
		{
			printf("�޸�����Ϣ\n");
			system("pause");
		}else{
			sumpeople++;
			printf("������ѧ�������Ա���ɼ���");
			scanf("%s%s%s%lf",inserte->num,inserte->name,inserte->gender,&inserte->grade);
			printf("��ӳɹ�\n");
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
		printf("��δ¼����Ϣ\n");
		system("pause");
	}else{
		printf("��ѡ����޸���Ϣ������ʽ��1ѧ�ţ�2���֣���");
		node *p=head->next;
		while(1)
		{ 
			scanf("%d",&i);
			if(i==1)
			{
				char modifynum[10];
				printf("������ѧ�ţ�");
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
						printf("���������֣�");
						scanf("%s",modifyname);
						for(;p!=NULL;p=p->next)
							if(strcmp(modifyname,p->name)==0)
							{
								k=0;
								break;
							}
						break;
					}else printf("������������ԣ�"); 
		}
		if(k)
		{
			printf("�޸�����Ϣ\n");
			system("pause");
		}else{
			printf("ѧ��������ɼ��޸�Ϊ��");
			scanf("%s%s%s%lf",p->num,p->name,p->gender,&p->grade);
			printf("�޸ĳɹ�\n");
			system("pause");
			k=1;
		}
	}
	system("CLS");
}
void sort(node *head)
{
	node *p=head;
	printf("��ѡ������ʽ��1�ɼ���2���֣�");
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
				}else printf("������������ԣ�"); 
	}	
}
void namesort(node *head)
{
	if(head->next==NULL)
	{
		printf("��δ¼����Ϣ\n");
		system("pause");
	}else{
		node *p=head->next,*q=NULL;
		printf("��ѡ��˳��1��A��Z��2��Z��A����");
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
					}else printf("������������ԣ�");
		}
	}
	printf("����ɹ�\n"); 
	system("pause");
	system("CLS");	
}
void gradesort(node *head)
{
	if(head->next==NULL)
	{
		printf("��δ¼����Ϣ\n");
		system("pause");
	}else{
		node *p=head->next,*q=NULL;
		printf("��ѡ��˳��1�Ӹߵ��ͣ�2�ӵ͵��ߣ���");
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
					}else printf("������������ԣ�");
		}
	}
	printf("����ɹ�\n"); 
	system("pause");
	system("CLS");	
}
void search(node *head)
{
	if(head->next==NULL)
		printf("��δ¼����Ϣ\n");
	else{
		printf("��ѡ���������Ϣ������ʽ��1ѧ�ţ�2���֣���");	
		node *p=head->next;
		while(1)
		{
			scanf("%d",&i);
			if(i==1)
			{ 
				char deletenum[10];
				printf("������ѧ�ţ�"); 
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
						printf("���������֣�"); 
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
					}else printf("������������ԣ�"); 
			}
		if(k)printf("�޸�����Ϣ\n");
		else{
			printf("ѧ��\t\t����\t\t�Ա�\t\t�ɼ�\n");
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
		printf("��δ¼����Ϣ\n");	
	else{
		printf("ѧ��\t����\t�Ա�\t�ɼ�\n");
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
	if(!fp)printf("��ʧ��\n"); 
	else{
		fprintf(fp,"%d\n",sumpeople);
		node *p=head->next;
		while(p)
		{
			fprintf(fp,"%s\t%s\t%s\t%f\n",p->num,p->name,p->gender,p->grade);
			p=p->next;
		}
		printf("����ɹ�\n");
		fp=NULL;
	}
	fclose(fp);
	system("pause");
	system("CLS");
}
void read(node *head,node **last)
{
	FILE *fp=fopen("students management information system.txt","r+");
	if(!fp)printf("��ʧ��\n"); 
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
		printf("����ɹ�\n");
		fp=NULL;
	}
	fclose(fp);
	system("pause");
	system("CLS");
}
