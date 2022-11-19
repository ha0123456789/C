#ifndef _KU_H
#define _KU_H 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char num[10],name[10],gender[10];
	double grade;
	struct node *next;
}node;
void menu(void);
void add(node **last);
void delet(node *head);
void clear(node **head,node **last);
void modify(node *head);
void sort(node *head); 
void gradesort(node *head); 
void namesort(node *head); 
void search(node *head);
void display(node *head);
void insert(node *head);
void store(node *head);
void read(node *head,node **last);
extern int i,k,sumpeople;
#endif
