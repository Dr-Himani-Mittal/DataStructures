#include<stdio.h>
#include<malloc.h>
// program to insert at begining or at a location or in the end
struct node 
{
	int info;
	struct node *next;	
};

struct node *START=NULL;

int main()
{
 /*insertAtBeg(0);
	insertAtBeg(1);
	insertAtBeg(2);
	insertAtEnd(20);
	insertAtLoc(30, 3);
	delAtLoc(3);
	delAtBeg();
delAtEnd();*/
	
	insertAtSortedOrder(1);
	insertAtSortedOrder(100);
	insertAtSortedOrder(2);
	insertAtSortedOrder(20);
	insertAtSortedOrder(0);
	insertAtSortedOrder(300);
	
	delAtSortedOrder(20);
	delAtSortedOrder(300);
	return 0;
}

int insertAtBeg(int item)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= item;
	if(START == NULL) printf("\nthis is the first sleemnt inthe list \n");
	temp->next = START;
	START= temp;
	traverse();
	return 0;
}

int insertAtEnd(int item)
{
	struct node *pptr, *ptr;
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= item;
	temp->next=NULL;
	pptr=ptr=START;
	while(ptr!=NULL)
	{
		pptr=ptr; ptr=ptr->next;
	}
	pptr->next=temp;
	traverse();
	return 0;
}

int insertAtLoc(int item, int loc)
{
	struct node *pptr, *ptr;
	int index=1;
	
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= item;
	if(loc==1 || START ==NULL) {
	insertAtBeg(item); return 0;}
	pptr=START; ptr=pptr->next;
	while(ptr->next!=NULL)
	{
		if(index+1>= loc)break;
		pptr=ptr; ptr=ptr->next; index++;
	}
	temp->next = pptr->next;
	pptr->next= temp;
	traverse();
	return 0;
}


int insertAtSortedOrder(int item)
{
	struct node *pptr, *ptr;
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= item;
	if((START ==NULL) || (item < START->info)) { 
	insertAtBeg(item); return 0;}
	pptr=START; ptr=pptr->next;
	while(ptr!=NULL)
	{
		if(item < ptr->info)break;
		pptr=ptr; ptr=ptr->next; 
	}
	temp->next = pptr->next;
	pptr->next= temp;
	traverse();

	return 0;
}

int traverse()
{
	struct node *temp=START;
	printf("\nthe list is: START->");
	while(temp!=NULL)
	{
		printf("%d -> ",temp->info);
		temp=temp->next;		
	}
	printf("NULL\n");
	return 0;
}


int delAtBeg()
{
	struct node *temp;
	if(START == NULL) {
	printf("\nthe l;ist is empty"); return 0;}
	
	temp= START;
	START= temp->next;
	free(temp);
	traverse();
	return 0;
}

int delAtEnd()
{
	struct node *pptr, *ptr;
	struct node *temp;
	if(START == NULL) {
	printf("\nthe l;ist is empty"); return 0;}
	if(START->next == NULL){ delAtBeg(); return 0;
	}
	pptr=START; ptr=START->next;
	while(ptr->next!=NULL)
	{
		pptr=ptr; ptr=ptr->next;
	}
	temp =pptr->next;
	pptr->next = NULL;
	free(temp);
	traverse();
	return 0;
}

int delAtLoc(int loc)
{
	struct node *pptr, *ptr;
	int index=1;
	
	struct node *temp;
	if(START == NULL) {
	printf("\nthe l;ist is empty"); return 0;}
	
	if(loc==1) { delAtBeg(); return 0;}
	
	pptr=START; ptr=pptr->next;
	while(ptr->next!=NULL)
	{
		if(index+1>= loc)break;
		pptr=ptr; ptr=ptr->next; index++;
	}
	temp = pptr->next;
	pptr->next= temp->next;
	traverse();
	return 0;
}

int delAtSortedOrder(int item)
{
	struct node *ptr;
	struct node *temp;
	int loc=1;
	
	if(START == NULL) {
	printf("\nthe l;ist is empty"); return 0;}
	
	ptr=START;
	while(ptr!=NULL)
	{
		if(item == ptr->info)break;
		ptr=ptr->next;loc=loc+1; 
	}
	delAtLoc(loc);
	/*traverse();*/

	return 0;
}

