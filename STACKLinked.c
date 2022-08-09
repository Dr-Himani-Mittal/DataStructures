#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *next;
};
struct node *TOP=NULL;


int push(int item)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	if(temp == NULL) {
		printf("Memory is full"); return -1;
	}
	temp->info = item;
	temp->next= TOP;
	TOP = temp;
	display();
	return 0;
}

int pop()
{
	struct node *temp;
	int ele;
	if(TOP == NULL){
		printf("Underflow"); return -1;
	}
	temp = TOP;
	TOP = temp->next;
	ele= temp->info;
	free(temp);
	display();
	return ele;
}

int peek()
{
	int ele;
	if(TOP == NULL){
		printf("Underflow"); return -1;
	}
	ele= TOP->info;
	return ele;
}

int display()
{
	struct node *temp = TOP;
	printf("\nthe stack is:\n");
	while(temp != NULL)
	{
		printf("|%d|", temp->info);
		temp = temp->next;
	}
	printf("\n\n");
}

int main()
{
	push(2);
	printf("%d is poped",pop());
	
	push(3);
	push(4);
	printf("%d is peeked", peek());
}
