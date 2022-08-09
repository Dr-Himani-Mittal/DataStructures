#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *START=NULL;

int main()
{
	char choice='y';
	int data, item, FOUND =0, loc=1;
	struct node *temp;
				
	printf("\n Press y to add element and n to print the list and quit\n");
		fflush(stdin);
	    choice =getchar(); 
		fflush(stdin);
	    
	while(1)
	{
		if(choice=='y'||choice == 'Y')
	    {
	    	// add element to list
	    	printf("\n enter the data to add\n");
	    	scanf("%d",&data);
	    	temp = (struct node*)malloc(sizeof(struct node));
            temp->data = data;
			temp->next= START;
			START= temp;	
			  	
		//}
		//else
		//{
			// traverse
			printf("\n the list so far is: ");
			temp=START;
			while(temp != NULL)
			{
				printf("%d->",temp->data);
				temp=temp->next;
			}
			printf("NULL\n");
		}
		else
		{
		
			break;
		}
		printf("\n Press y to add element and n to print the list and quit\n");
		fflush(stdin);
	    choice =getchar(); fflush(stdin);
	    
	} // search an elemnt in the list.
	
	printf("\n enter the element to search:");
	scanf("%d",&item);
	
	temp=START;
	while(temp != NULL)
	{
		if(temp->data == item){ FOUND =1;break;} 
		loc=loc+1;
		temp=temp->next;
	}
	if(FOUND == 1) printf("\nItem found at loc=%d ",loc);
	else printf("NOT FOUND");
	
}
