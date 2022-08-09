#include<stdio.h>

#define SIZE 10
#define false 0
#define true 1

int main()
{
	int arr[SIZE], index, item, n, FOUND=false;
    
	printf("\n Enter the number of elements in the array\n");
	scanf("%d", &n);
	if(n>SIZE) 
	{
     	printf("n cannot be larger than SIZE=%d", SIZE);
		 return -1;	
    }
    
    printf("\n Enter the array elemets\n");
    for( index = 0 ; index < n ; index++ )
    {
    	scanf("%d",&arr[index]);
	}
		
	printf("\n Enter the number to be searched\n");
	scanf("%d", &item);
	
	for( index = 0 ; index < n ; index++ )
    {
    	if ( item == arr[index]) 
		{ 
			FOUND = true;
			break;
		}
	}
	
	if (FOUND ==true)
	{
		printf("\n element found at loc = %d", index+1);
	}
	else
	{
		printf("\n element not found");
	}
	return 0;
}
