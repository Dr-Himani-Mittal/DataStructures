#include <stdio.h>
#include<conio.h>

#define MAXSIZE 5

int STACK[MAXSIZE];
int TOP=-1;
int min=0;

int push(int element)
{
	// element is the value to be inserted in the stack
	// top can be accessed globaly
	// function return s a value of -1 when it is unsucessfull in making a insertion.
	// otherwise it reurns 0
	
	if(TOP == MAXSIZE-1)
	{
		printf("\n STACK IS FULL\n"); return -1;
	}
	TOP ++;
	if(TOP == 0)
	{
		STACK[TOP]=element;
		min= element;
	}
	
	else if(element < min)
	{
		STACK[TOP] = (2 * element) - min;
		min = element;
	}
	else
	{
	STACK[TOP] = element;
}
	return 0;
}


int pop()
{
	// reutrn value is the elemnt removed from the stack.
	// top is globally accessible.
	// function reutrn a special value of -999 when stackj is empty \
	// otherwise it returns the topmost value on the stack.
	int ele;
	int retireved = 0;
	if (TOP == -1)
	{
		printf("\n STACK IS EMPTY\n"); return -999;
	}
	
	ele= STACK[TOP];
	TOP--;
	
	if (ele < min)
	{
		retireved = min;
		min = (2* min) - ele;
		ele = retireved;
	}
	printf("\n the top is :%d",TOP);
	return ele;
	
}


int getmin()
{
	return min;
}
int peek()
{
	// reutrn value is the elemnt removed from the stack.
	// top is globally accessible.
	// function reutrn a special value of -999 when stackj is empty \
	// otherwise it reads the topmost value on the stack.
	int ele;
	if (TOP == -1)
	{
		printf("\n STACK IS EMPTY\n"); return -999;
	}
	ele= STACK[TOP];
	return ele;
}


int main()
{
	char choice; int item,i;
	 while(1)
	 {
	 	printf("\n Enter your choice: 1: Push 2: Pop 3: Peek 4: Exit\n");
	 	
	 	fflush(stdin); choice= getchar(); fflush(stdin);
	 	switch(choice)
	 	{
	 		case '1': 
			 { printf("\n enter the value to push into the stack");
			   scanf("%d", &item);
			
			   push(item);     printf("minimum value is :%d", min);break;
	     	}
	 		case '2': {
				printf("\nThe value removed from stack is: %d\n",pop());
			    printf("minimum value is :%d", min);   
			 break;
		     }    
	 		case '3': {  printf("\nThe top mosy value on stack is: %d\n",peek());
				break;
			 }
	 		default: exit(0);break;
		 }
		 printf("\n the staus of the stack is:");
		 if(TOP == -1) printf("EMPTY\n");
		 for(i=TOP; i>=0; i--) 
		 printf("|%d|",STACK[i]);
	 }
	 
	 return 100;
}
