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
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= 0;
	temp->next= NULL;
	START = temp;
	
	
 insertAtBeg(0);
	insertAtBeg(1);
	insertAtBeg(2);
	insertAtEnd(20);
	insertAtLoc(30, 3);
	delAtLoc(3);
	delAtBeg();
delAtEnd();
	/*
	insertAtSortedOrder(1);
	insertAtSortedOrder(100);
	insertAtSortedOrder(2);
	insertAtSortedOrder(20);
	insertAtSortedOrder(0);
	insertAtSortedOrder(300);
	
	delAtSortedOrder(20);
	delAtSortedOrder(300);*/
	return 0;
}

int insertAtBeg(int item)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= item;
	if(START->next == NULL) printf("\nthis is the first sleemnt inthe list \n");
	temp->next = START->next;
	START->next= temp;
	
	START->info= (START->info)+1;
	traverse();
	return 0;
}

int insertAtEnd(int item)
{
	struct node *pptr, *ptr;
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= item;
	temp->next=NULL;
	pptr=ptr=START->next;
	while(ptr!=NULL)
	{
		pptr=ptr; ptr=ptr->next;
	}
	pptr->next=temp;
	
	START->info= (START->info)+1;
	traverse();
	return 0;
}

int insertAtLoc(int item, int loc)
{
	struct node *pptr, *ptr;
	int index=1;
	
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= item;
	if(loc==1 || START->next ==NULL) {
	insertAtBeg(item); return 0;}
	pptr=START->next; ptr=pptr->next;
	while(ptr->next!=NULL)
	{
		if(index+1>= loc)break;
		pptr=ptr; ptr=ptr->next; index++;
	}
	temp->next = pptr->next;
	pptr->next= temp;
	
	START->info= (START->info)+1;
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
	struct node *temp=START; int first=1;
	printf("\nthe list is: START->");
	while(temp!=NULL)
	{
		if(first==1) {
			printf("HEADER %d ->",temp->info); first=0;
		}
		else
		{
		printf("%d -> ",temp->info);
	}
		temp=temp->next;		
	}
	printf("NULL\n");
	return 0;
}


int delAtBeg()
{
	struct node *temp;
	if(START->next == NULL) {
	printf("\nthe list is empty"); return 0;}
	
	temp= START->next;
	START->next= temp->next;
	
	START->info= (START->info) - 1;
	
	free(temp);
	traverse();
	return 0;
}

int delAtEnd()
{
	struct node *pptr, *ptr;
	struct node *temp;
	if(START->next == NULL) {
	printf("\nthe list is empty"); return 0;}
	if(START->next->next == NULL){ delAtBeg(); return 0;
	}
	pptr=START->next; ptr=START->next->next;
	while(ptr->next!=NULL)
	{
		pptr=ptr; ptr=ptr->next;
	}
	temp =pptr->next;
	pptr->next = NULL;
	
	START->info= (START->info)-1;
	
	free(temp);
	traverse();
	return 0;
}

int delAtLoc(int loc)
{
	struct node *pptr, *ptr;
	int index=1;
	
	struct node *temp;
	if(START->next == NULL) {
	printf("\nthe list is empty"); return 0;}
	
	if(loc==1) { delAtBeg(); return 0;}
	
	pptr=START->next; ptr=pptr->next;
	while(ptr->next!=NULL)
	{
		if(index+1>= loc)break;
		pptr=ptr; ptr=ptr->next; index++;
	}
	temp = pptr->next;
	pptr->next= temp->next;
	START->info= (START->info)-1;
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
}*/

