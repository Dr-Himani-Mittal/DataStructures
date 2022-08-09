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
	
    insertAtBeg(0);
    insertAtBeg(1);
    //delAtBeg();
    
    //printf("\nreturned from insertAtBeg(0);");
	insertAtBeg(1);
	//printf("\nreturned from insertAtBeg(1);");
	insertAtBeg(2);
	//printf("\nreturned from insertAtBeg(2);");
	insertAtEnd(20);
	insertAtLoc(30, 3);
		insertAtLoc(200, 6);
		delAtLoc(6);
	delAtLoc(3);
delAtLoc(1);
	//delAtBeg();
//delAtBeg();

//delAtEnd();
	
	/*insertAtSortedOrder(1);
	insertAtSortedOrder(100);
	insertAtSortedOrder(2);
	insertAtSortedOrder(20);
	insertAtSortedOrder(0);
	insertAtSortedOrder(300);
	
	delAtSortedOrder(20);
	delAtSortedOrder(300);
	*/return 0;
}

int insertAtBeg(int item)
{
	struct node *ptr, *pptr, *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= item;
	if(START == NULL) 
	{
	   printf("\nthis is the first element in the list \n");
	   START= temp;
       temp->next = START;
       traverse();
       return 0;
    }
	// to update the pointer of last node in the list to start pointer.   
	ptr=START->next;pptr=START;
	while(ptr != START)
	{
		printf("a");
		pptr= ptr; ptr=ptr->next;
	}
	temp->next = START;
	START= temp; 
	pptr->next=START;
	
	traverse();
	return 0;
}

int insertAtEnd(int item)
{
	struct node *pptr, *ptr;
	struct node *temp = (struct node*) malloc(sizeof(struct node));
    if(START == NULL) {
	insertAtBeg(item); return 0;}
	temp->info= item;
	temp->next=START;
	pptr=START; ptr=START->next;
	do
	{
		pptr=ptr; ptr=ptr->next;
	}while(ptr!=START);
	pptr->next=temp;
	traverse();
	return 0;
}

int insertAtLoc(int item, int loc)
{
	struct node *pptr, *ptr;
	int index=1; int last=0;
	
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->info= item;
	if(loc==1 || START ==NULL) {
	insertAtBeg(item); return 0;}
	pptr=START; ptr=pptr->next;
	while(ptr->next!=START)
	{
		if(ptr->next->next == START) {last =1; break;}
		if(index+1>= loc)break;
		pptr=ptr; ptr=ptr->next; index++;
	}
	if(last ==0)
	{
	
	temp->next = pptr->next;
	pptr->next= temp;
	traverse();
	return 0;
}
else {insertAtEnd(item); return 0;}

}



int traverse()
{
	struct node *temp=START;
	if(START == NULL) {
		printf("\n list is empty"); return 0;
	}
	printf("\n\n\nthe list is: START (%u)->", START);
	do 
	{
		printf("\n(%u -> info- %d  next- %u)->",temp, temp->info, temp->next);
		temp=temp->next;		
	}
	while(temp!=START);
	printf("START %d \n\n",START);
	return 0;
}


int delAtBeg()
{
	struct node *temp,*ptr, *pptr;
	if(START == NULL) {
	printf("\n the l;ist is empty"); return 0;}
	
	temp= START;
	if(temp ==temp->next) 
		{
			printf("\n the single elemnt in list being deleted \n %u -%u",temp, temp->next); START= NULL;
		}
	else 
		{
		pptr=START; ptr=START->next;
		do
		{
			printf("%d", pptr->info);
			pptr=ptr; ptr=ptr->next;
		}while(ptr!=START);
		pptr->next=temp->next;
		START= temp->next;	
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
	if(START->next == START){ delAtBeg(); return 0;
	}
	pptr=START; ptr=START->next;
	while(ptr->next!=START)
	{
		pptr=ptr; ptr=ptr->next;
	}
	temp =pptr->next;
	pptr->next = START;
	free(temp);
	traverse();
	return 0;
}

int delAtLoc(int loc)
{
	struct node *pptr, *ptr;
	int index=1;int last=0;
	
	struct node *temp;
	if(START == NULL) {
	printf("\nthe l;ist is empty"); return 0;}
	
	if(loc==1) { delAtBeg(); return 0;}
	
	pptr=START; ptr=pptr->next;
	while(ptr->next!=NULL)
	{
		if(ptr->next->next == START) {last =1; break;}
		if(index+1>= loc)break;
		pptr=ptr; ptr=ptr->next; index++;
	}
	if(last ==0)
	{
	temp = pptr->next;
	pptr->next= temp->next;
}
else {
	delAtEnd();
}
	traverse();
	return 0;
}

