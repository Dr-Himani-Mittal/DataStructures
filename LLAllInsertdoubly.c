#include<stdio.h>
#include<malloc.h>
// program to insert at begining or at a location or in the end doubly ll
struct node 
{
	int info;
	struct node *next;	
	struct node *prev;
};

struct node *START=NULL;

int main()
{
	printf("\n inserting 0 in the list");
 insertAtBeg(0);
 printf("\n inserting 1 in the list");
	insertAtBeg(1);
	printf("\n inserting 2 in the list");
	insertAtBeg(2);
	printf("\n inserting 20 in the end of list");
	insertAtEnd(20);
	printf("\n inserting 30 in the loc 3 of the list");
	insertAtLoc(30, 3);
	printf("\n deleting 30 in the list");
	delAtLoc(3);
	printf("\n deleting 1st element in the list");
	delAtBeg();
	printf("\n deleting last element in the list");
delAtEnd();
	/*
	insertAtSortedOrder(1);
	insertAtSortedOrder(100);
	insertAtSortedOrder(2);
	insertAtSortedOrder(20);
	insertAtSortedOrder(0);
	insertAtSortedOrder(300);
	
	delAtSortedOrder(20);
	delAtSortedOrder(300);
	*/
	return 0;
}

int insertAtBeg(int item)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= item;
	if(START == NULL) 
	{
	printf("\nthis is the first sleemnt in the list \n");
	temp->next = START;
	temp->prev = NULL;
	START= temp;
		traverse();

	return 0;

}
	temp->next = START;
	printf("a");
	temp->prev = NULL;
	printf("a");
	START->prev = temp;
	printf("a");
	START= temp;
	printf("a");
	traverse();
	printf("a");
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
	
	temp->prev= pptr;
	
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
	temp->prev = pptr;
	pptr->next= temp;
	
	temp->next->prev = temp;
	
	traverse();
	return 0;
}

/*
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
*/
int traverse()
{
	struct node *temp=START;
	printf("\nthe list is: START %u->",START);
	while(temp!=NULL)
	{
		printf("prev = %u, info = %d, next = %u -> ",temp->prev, temp->info, temp->next);
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
	if(START!= NULL) {
		START->prev = NULL;
	}
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
	
	temp->next->prev = pptr;
	traverse();
	return 0;
}
/*
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
/*
	return 0;
}
*/
