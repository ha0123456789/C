#include"ku.h"
int i,k=1,sumpeople=0;
int main()
{
	system("color F0");
	system("mode con cols=60 lines=40");
	char account[15],password[15];
	printf("\t\t    ѧ���ɼ�������Ϣϵͳ\n");
	int r,s=0;
	for(r=0;r<5;r++)
	{
		printf("���������Ա�˺ţ���ֻ����λ��ᣩ��");
		scanf("%s",account);
		printf("�������˺����룺");/*�˺ţ�12345�����룺67890*/
		scanf("%s",password);
		if(strcmp("12345",account)==0&&strcmp("67890",password)==0)		
		{
			s=1;
			break;
		}else printf("�˺Ż��������������\n");
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
				default:printf("������󣬷��ز˵�\n");
						system("pause");
						system("CLS");
			}
			if(flag)break;
		}
		system("CLS");
		printf("\t\t    ѧ���ɼ�������Ϣϵͳ\n");
		printf("�����˳�ѧ���ɼ�������Ϣϵͳ\n"); 
	}else{
		printf("��¼ʧ��\n");
		system("pause");
	}
	return 0;	
} 
