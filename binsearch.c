#include<stdio.h>

#define SIZE 10
/* program 9: Binary search*/
/*Name: Himani Mittal
Rollno- 1
BCA 3rd sem Section B*/

int main()
{
	int arr[SIZE], index=0, lb=0, ub=SIZE, mid=0, item=0, loc=-1;
	/* arr is the sorted array. 
	index is used for looping.
	lb is the lower bound of currently considered array.
	ub is the upper bound of the currectly considered array.
	mid is (lb+ub)/2
	item is the value to be searched
	loc is the calcultaed location. it is zero if element not found.*/
	
	printf("\n Enter a sorted array of %d elements",SIZE);
	for( index = 0; index < SIZE; index++ )
	{
		scanf("%d",&arr[index]);
	}
	
	printf("\n The input array is :\n");
	for( index = 0; index < SIZE; index++ )
	{
		printf("%d\t%d\n",arr[index],index+1);
	}
	
	printf("\n Enter the item to search");
	scanf("%d", &item);
	
	lb=0;
	ub=SIZE-1;
	loc = -1;
	while(lb<=ub)
	{
		mid= (lb+ub)/2;
		
		/* compare the element at index mid with item*/
		if(item == arr[mid])
		{
			loc = mid+1; break;
		}
		else if ( arr[mid]< item)
		{
			lb= mid+1;
					}
		else /* when element at mid is greater*/ 
		{
			ub = mid-1;
			
		}
	}
	if(loc ==-1) printf("\n element not found in the array\n");
	else printf("\n elemnt found at location %d",loc);
	
	return 0;
}
